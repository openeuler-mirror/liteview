//
// Copyright (c) 2025 Institute of Software, Chinese Academy of Sciences (ISCAS)
// LiteView is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
//          http://license.coscl.org.cn/MulanPSL2
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// See the Mulan PSL v2 for more details.
//


#include "api/download/SimpleDownload.h"

#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "api/download/DownloadUtil.h"
#include "mbnet/WebURLLoaderManager.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "base/files/file.h"
#include "base/files/file_util.h"
#include "base/threading/thread.h"
#include "base/atomic_sequence_num.h"
#include <process.h>
#include <shlwapi.h>
#include <commdlg.h>
#ifdef OS_LINUX
#include <gtk/gtk.h>
#endif

namespace download {

base::AtomicSequenceNumber g_nextDownloadId;

size_t c16len(const char16_t* s)
{
    const char16_t* s_orig = s;
    while (*s) {
        ++s;
    }
    return s - s_orig;
}

int SimpleDownload::getDialogCount()
{
    return m_dialogCount;
}

void SimpleDownload::onDataRecv(void* param, mbNetJob job, const char* data, int length)
{
    SimpleDownload* self = (SimpleDownload*)param;
    self->onDataRecvImpl(job, data, length);
}

void SimpleDownload::onDataFinish(void* param, mbNetJob job, mbLoadingResult result)
{
    SimpleDownload* self = (SimpleDownload*)param;
    self->onDataFinishImpl(job, result);
}

int SimpleDownload::m_dialogCount = 0;

SimpleDownload::SimpleDownload(mbWebView mbView, size_t expectedContentLength, const char* url, const char* mime, const char* disposition, mbNetJob job,
    mbNetJobDataBind* dataBind, mbDownloadBind* callbackBind)
{
    m_totalSize = expectedContentLength;
    m_url = url;
    m_mime = mime;
    m_contentDisposition = disposition;
    m_handleOfSave = nullptr;
    m_mbView = mbView;
    m_hadCallDataFinish = false;
    m_loadingResult = (mbLoadingResult)-1;

    m_thread = mbnet::WebURLLoaderManager::sharedInstance()->getIoThread(mbnet::WebURLLoaderManager::kIoThreadTypeRes);

    dataBind->param = this;
    dataBind->recvCallback = onDataRecv;
    dataBind->finishCallback = onDataFinish;

    memset(&m_callbackBind, 0, sizeof(mbDownloadBind));

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)m_mbView);
    m_saveTempFullPath = webview->getDownloadDirPath();

    char temp[150] = { 0 };
    sprintf(temp, "%p_%p_%p.tmp", &mbView, &expectedContentLength, g_nextDownloadId.GetNext());
    m_saveTempFullPath = m_saveTempFullPath.AppendASCII(temp);

    if (callbackBind)
        m_callbackBind = *callbackBind;
}

SimpleDownload::~SimpleDownload()
{
    if (m_cacheData)
        delete m_cacheData;
    m_cacheData = nullptr;
}

SimpleDownload* SimpleDownload::create(mbWebView webView, const WCHAR* savePath, const mbDialogOptions* dialogOpt, const mbDownloadOptions* downloadOpt,
    size_t expectedContentLength, const char* url, const char* mime, const char* disposition, mbNetJob job, mbNetJobDataBind* dataBind,
    mbDownloadBind* callbackBind)
{
    if (m_dialogCount > 0)
        return nullptr;

    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webView);
    base::FilePath saveTempFullPath = webview->getDownloadDirPath();

    if (!base::PathExists(saveTempFullPath)) {
        base::File::Error error;
        if (!base::CreateDirectoryAndGetError(saveTempFullPath, &error)) {
            std::string temp = "CreateDirectoryAndGetError fail:";
            temp += saveTempFullPath.AsUTF8Unsafe();
            temp += "\n";
            OutputDebugStringA(temp.c_str());
            return nullptr;
        }
    }

    SimpleDownload* self = new SimpleDownload(webView, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);

    if (dialogOpt && dialogOpt->magic == 'mbdo' && dialogOpt->defaultPath)
        self->dialogOpt.defaultPath = dialogOpt->defaultPath;

    if (savePath) {
        webview->setIsMouseKeyMessageEnable(true);

        std::vector<WCHAR>* fileResult = nullptr;
        size_t pathLen = c16len((const char16_t*)savePath);
        if (pathLen == 0) {
            delete self;
            return nullptr;
        }

        fileResult = new std::vector<WCHAR>();
        fileResult->resize(MAX_PATH * 2);

        memcpy(fileResult->data(), savePath, pathLen * sizeof(WCHAR));

        if (!(downloadOpt && downloadOpt->magic == 'mbdo' && downloadOpt->saveAsPathAndName)) {
            std::u16string defaultSaveName = getSaveName(self->m_contentDisposition, self->m_url);
            PathAppendW((LPWSTR)(fileResult->data()), (LPCWSTR)(defaultSaveName.c_str()));
        }
        
        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self] { self->startSave(true); });

        self->m_saveFullPathLock.Acquire();
        self->m_saveFullPath = (const char16_t*)fileResult->data();
        self->m_saveFullPathLock.Release();
        delete fileResult;
    } else {
        base::subtle::Barrier_AtomicIncrement(&m_dialogCount, 1);

        unsigned int threadIdentifier = 0;
        HANDLE hHandle = reinterpret_cast<HANDLE>(_beginthreadex(0, 0, SimpleDownload::dialogThread, self, 0, &threadIdentifier));
        ::CloseHandle(hHandle);
    }

    return self;
}

bool SimpleDownload::canSave()
{
    if (m_hadCallDataFinish && (MB_LOADING_FAILED == m_loadingResult || MB_LOADING_CANCELED == m_loadingResult))
        return false;
    return true;
}

base::FilePath changeStrToFilePath(const std::u16string& str)
{
#ifdef OS_LINUX
    return base::FilePath(base::UTF16ToUTF8(str));
#else
    return base::FilePath::FromUTF16Unsafe(base::StringPiece16(str));
#endif
}

void SimpleDownload::onBeginSaveCallback()
{
    base::AutoLock locker(m_saveFullPathLock);
    if (!m_callbackBind.beginSaveCallback)
        return;

    base::FilePath savePath = changeStrToFilePath(m_saveFullPath);
    std::string savePathStr = base::UTF16ToUTF8(m_saveFullPath);
    // ����ص���ı�洢��·��������
    mbStringPtr newPath = m_callbackBind.beginSaveCallback(m_callbackBind.param, savePathStr.c_str(), base::PathExists(savePath));
    if (!newPath || mbGetStringLen(newPath) == 0)
        return;

    m_saveFullPath.clear();
    if (!base::UTF8ToUTF16(mbGetString(newPath), mbGetStringLen(newPath), &m_saveFullPath)) {
        m_loadingResult = MB_LOADING_FAILED;

        if (m_callbackBind.finishCallback)
            m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);
        return;
    }
}

// ����Ƿ�������������У��ͼӸ�����
base::FilePath checkAndRenameSaveFullPath(const base::FilePath& path)
{
    if (!base::PathExists(path))
        return path;

    time_t currentTime;
    time(&currentTime);
    struct tm* timeInfo = localtime(&currentTime);
    char timeString[20]; // �㹻��� "YYYY-MM-DD HH:MM:SS\0"

    static int s_count = 1;
    strftime(timeString, sizeof(timeString), "%Y-%m-%d-%H-%M-%S", timeInfo);
    char temp[150];
    snprintf(temp, sizeof(temp), "[%s](%d)", timeString, s_count++);

    base::FilePath newPath = path.InsertBeforeExtensionASCII(base::StringPiece(temp));
    if (!base::PathExists(newPath))
        return newPath;

    return path;
}

void SimpleDownload::endSaveInIoThread(const base::FilePath& saveFullPath, const scoped_refptr<base::SequencedTaskRunner>& runner)
{
    if (m_handleOfSave && (base::File*)(-1) != m_handleOfSave) {
        m_handleOfSave->Close();
        delete m_handleOfSave;
    }
    m_handleOfSave = (base::File*)(-1);

    base::FilePath savePathDir = saveFullPath.DirName();
    base::CreateDirectory(savePathDir);

    base::FilePath savePath = checkAndRenameSaveFullPath(saveFullPath);

    if (!base::internal::MoveUnsafe(m_saveTempFullPath, savePath)) {
        bool b = base::CopyFile(m_saveTempFullPath, savePath);
        m_loadingResult = MB_LOADING_FAILED;
    }
    base::DeleteFile(m_saveTempFullPath);

    runner->PostTask(FROM_HERE, base::BindOnce([](SimpleDownload* self) {
        if (self->m_callbackBind.finishCallback)
            self->m_callbackBind.finishCallback(self->m_callbackBind.param, nullptr, self->m_loadingResult);

        content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self] { delete self; });
    }, base::Unretained(this)));
}

// ���������ڻ�û�յ���ȷ���ļ�����ʱ��Ϳ�ʼ���أ��������ص�����Ҳ���ȴ���temp·����
void SimpleDownload::doSave()
{
    if (nullptr == m_handleOfSave) {
        onBeginSaveCallback();

        std::string output = "SimpleDownload::doSave, ";

        base::File* hFile = new base::File(m_saveTempFullPath, base::File::FLAG_WRITE | base::File::FLAG_CREATE_ALWAYS);
        if (!hFile || !hFile->IsValid()) {
            output += "fail:";
            output += m_saveTempFullPath.AsUTF8Unsafe();
            output += "\n";
            OutputDebugStringA(output.c_str());

            if (hFile)
                delete hFile;
            m_loadingResult = MB_LOADING_FAILED;

            if (m_callbackBind.finishCallback)
                m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);
            return;
        }
        m_handleOfSave = hFile;

        output += "ok:";
        output += m_saveTempFullPath.AsUTF8Unsafe();
        output += "\n";
        OutputDebugStringA(output.c_str());

        if (m_callbackBind.saveNameCallback) {
            base::AutoLock locker(m_saveFullPathLock);
            m_callbackBind.saveNameCallback(m_callbackBind.param, (const WCHAR*)m_saveFullPath.c_str());
        }
    }

    if (!m_handleOfSave || (base::File*)(-1) == m_handleOfSave) {
        m_handleOfSave = (base::File*)(-1);
        CHECK(MB_LOADING_FAILED == m_loadingResult);
        OutputDebugStringA("SimpleDownload::doSave, m_handleOfSave fail\n");
        return;
    }

#ifdef OS_LINUX
//     char* output = (char*)malloc(0x1000);
//     sprintf(output, "SimpleDownload::doSave: %p %d, %d, %s\n", m_callbackBind.recvCallback, canSave(), m_cacheData.size(),
//         base::UTF16ToUTF8(m_saveFullPath).c_str());
//     OutputDebugStringA(output);
//     free(output);
#endif
    if (m_callbackBind.recvCallback && canSave() && m_cacheData && 0 != m_cacheData->size())
        m_callbackBind.recvCallback(m_callbackBind.param, nullptr, m_cacheData->data(), (int)m_cacheData->size());

    if (m_cacheData) {
        if (0 != m_cacheData->size()) {
            std::vector<char>* cacheData = m_cacheData;
            m_thread->task_runner()->PostTask(FROM_HERE, base::BindOnce([](std::vector<char>* cacheData, base::File* handleOfSave) {
                std::optional<size_t> size = handleOfSave->WriteAtCurrentPos(cacheData->data(), (DWORD)cacheData->size());
                
                char* output = (char*)malloc(0x100);
                sprintf(output, "WriteAtCurrentPos: %p %p\n", 
                    cacheData->size(),
                    size.has_value() ? size.value() : -1);
                OutputDebugStringA(output);
                free(output);

                delete cacheData;
            }, base::Unretained(cacheData), base::Unretained(m_handleOfSave)));
        } else 
            delete m_cacheData;
        m_cacheData = nullptr;
    }

    // ��ʱ���������ˣ����ضԻ���û�򿪣������������˻�û����startSave
    if (!m_hadCallDataFinish || m_dialogCount > 0 || !m_hasStartSave)
        return;

    // ���سɹ�
    m_saveFullPathLock.Acquire();
    base::FilePath saveFullPath = changeStrToFilePath(m_saveFullPath);
    m_saveFullPathLock.Release();

    const scoped_refptr<base::SequencedTaskRunner>& currentRunner = base::SequencedTaskRunner::GetCurrentDefault();
    m_thread->task_runner()->PostTask(FROM_HERE, base::BindOnce([](
        SimpleDownload* self, const base::FilePath& saveFullPath, const scoped_refptr<base::SequencedTaskRunner>& runner) {
            self->endSaveInIoThread(saveFullPath, std::move(runner));
    }, base::Unretained(this), saveFullPath, std::move(currentRunner)));
}

void SimpleDownload::startSave(/*std::vector<WCHAR>* path*/bool ok)
{
    if (/*!path || 0 == path->size()*/!ok) {
        m_loadingResult = MB_LOADING_FAILED;
        if (m_callbackBind.finishCallback)
            m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);
        return;
    }

    m_hasStartSave = true;
    doSave();
}

void SimpleDownload::onDataRecvImpl(mbNetJob job, const char* data, int length)
{
    if (0 == length)
        return;

    if ((mbLoadingResult)-1 == m_loadingResult) { // ����mbNetCancelRequest��Ȼ�ᷴ�����뱾����
        if (!m_cacheData)
            m_cacheData = new std::vector<char>();

        size_t oldSize = m_cacheData->size();
        m_cacheData->resize(oldSize + length);
        memcpy(&m_cacheData->at(oldSize), data, length);

        m_downloadedSize += length;

        doSave();
    }

    if (MB_LOADING_FAILED == m_loadingResult)
        mbNetCancelRequest(job);
}

void SimpleDownload::onDataFinishImpl(mbNetJob job, mbLoadingResult result)
{
    m_hadCallDataFinish = true;
    m_loadingResult = result;
    doSave();
}

#ifdef OS_LINUX
// ���� "�ļ�����Ϊ" �Ի���
static gchar* showSaveAsDialog(GtkWindow* parent, const std::string& defaultSaveName, const std::string& defaultPath)
{
    GtkWidget* dialog = nullptr;
    gchar* filename = nullptr;

    dialog = gtk_file_chooser_dialog_new(
        "File save as",
        parent,
        GTK_FILE_CHOOSER_ACTION_SAVE, // �ؼ�������Ϊģʽ
        "cancel", GTK_RESPONSE_CANCEL,
        "save", GTK_RESPONSE_OK,
        NULL
    );
    printf("showSaveAsDialog: [%s], [%s]\n", defaultPath.c_str(), defaultSaveName.c_str());

    if (!defaultSaveName.empty())
        gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), defaultSaveName.c_str());
    if (!defaultPath.empty())
        gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(dialog), defaultPath.c_str());

    // ����ļ��Ѵ��ڣ���ʾȷ�ϸ���
    gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(dialog), TRUE);

    GtkFileFilter* filter = nullptr;

    // ����ֻ��������Ϊ .txt
    //filter = gtk_file_filter_new();
    //gtk_file_filter_set_name(filter, "�ı��ĵ� (*.txt)");
    //gtk_file_filter_add_pattern(filter, "*.txt");
    //gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);

    // �����ļ�
    filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "all file(*.*)");
    gtk_file_filter_add_pattern(filter, "*");
    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), filter);

    // ���жԻ���
    if (gtk_dialog_run(GTK_DIALOG(dialog)) == GTK_RESPONSE_OK) {
        filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));
    }

    gtk_widget_destroy(dialog);

    return filename;
}
#endif

unsigned int SimpleDownload::dialogThread(void* param)
{
    SimpleDownload* self = (SimpleDownload*)param;
    mbWebView mbWebview = self->m_mbView;
    OPENFILENAMEW ofn = { 0 };

    std::u16string defaultSaveName = getSaveName(self->m_contentDisposition, self->m_url);
    if (defaultSaveName.size() > 150)
        defaultSaveName = defaultSaveName.substr(0, 150);

    std::vector<WCHAR>* fileResult = new std::vector<WCHAR>();
    fileResult->resize(4 * MAX_PATH + 1);
    memset(fileResult->data(), 0, fileResult->size() * 2);
#ifdef OS_LINUX
    content::ThreadCall::callUiThreadSync(MB_FROM_HERE, [self, mbWebview, &defaultSaveName, &fileResult] {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)mbWebview);
    if (!webview) {
        delete fileResult;
        fileResult = nullptr;
        return;
    }
    webview->setIsMouseKeyMessageEnable(false);
    gchar* saveName = showSaveAsDialog(nullptr, base::UTF16ToUTF8(base::StringPiece16(defaultSaveName.c_str(), defaultSaveName.size())), self->dialogOpt.defaultPath);
    webview->setIsMouseKeyMessageEnable(true);

    if (!saveName) {
        delete fileResult;
        fileResult = nullptr;
    } else {
        std::u16string output;
        base::UTF8ToUTF16(saveName, strlen(saveName), &output);
        size_t size = fileResult->size() > output.size() ? output.size() : fileResult->size() - 1;
        memcpy(fileResult->data(), output.c_str(), output.size() * 2);

        printf("SimpleDownload::dialogThread 1: %s\n", saveName);
        g_free(saveName);
        printf("SimpleDownload::dialogThread 2\n");
    }
        });
    //std::u16string test(u"/home/weolar/Desktop/test/1.zip");
    //memcpy(fileResult->data(), test.c_str(), test.size() * 2);
    printf("SimpleDownload::dialogThread 3\n");
#else
    wcscpy(fileResult->data(), (const WCHAR*)defaultSaveName.c_str());

    HWND hwndOwner = nullptr;
    content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)mbWebview);
    if (webview)
        hwndOwner = webview->getHostWnd();

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = hwndOwner;
    ofn.lpstrFile = (LPWSTR)(fileResult->data());
    ofn.nMaxFile = MAX_PATH;
    ofn.lpstrFilter = L"All\0*.*\0\0";
    ofn.nFilterIndex = 1;
    ofn.lpstrFileTitle = NULL;
    ofn.nMaxFileTitle = 0;
    ofn.lpstrInitialDir = base::UTF8ToWide(self->dialogOpt.defaultPath).c_str();
    ofn.Flags = OFN_SHOWHELP | OFN_OVERWRITEPROMPT;

    if (!GetSaveFileNameW(&ofn)) {
        delete fileResult;
        fileResult = nullptr;
    }

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [mbWebview] {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)mbWebview);
        if (!webview)
            return;
        webview->setIsMouseKeyMessageEnable(true);
    });
#endif

    self->m_saveFullPathLock.Acquire();
    if (fileResult)
        self->m_saveFullPath = (const char16_t*)fileResult->data();
    self->m_saveFullPathLock.Release();

    bool ok = !!fileResult;
    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self, ok] { self->startSave(ok); });

    if (fileResult)
        delete fileResult;

    base::subtle::Barrier_AtomicIncrement(&m_dialogCount, -1);

    return 0;
}

}