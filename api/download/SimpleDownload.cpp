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


#include "mbvip/download/SimpleDownload.h"

#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "mbvip/download/DownloadUtil.h"
#include "base/strings/string_util.h"
#include "base/strings/utf_string_conversions.h"
#include "base/files/file.h"
#include "base/files/file_util.h"
#include <process.h>
#include <shlwapi.h>
#include <commdlg.h>

namespace download {

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

// void SimpleDownload::onSimpleDownloadWillRedirectCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr oldRequest, wkeWebUrlRequestPtr request, wkeWebUrlResponsePtr redirectResponse)
// {
// }
// 
// void SimpleDownload::onSimpleDownloadDidReceiveResponseCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, wkeWebUrlResponsePtr response)
// {
//     SimpleDownload* self = (SimpleDownload*)param;
//     __int64 expectedContentLength = wkeNetGetExpectedContentLength(response);
//     if (expectedContentLength > 0x00ffffff) {
//         self->m_handleOfSave = nullptr;
//         return;
//     }
// 
//     self->m_totalSize = (size_t)expectedContentLength; // may be -1
//     self->m_downloadedSize = 0;
// }
// 
// void SimpleDownload::onSimpleDownloadDidReceiveDataCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, const char* data, int dataLength)
// {
//     SimpleDownload* self = (SimpleDownload*)param;
// 
// //     HANDLE hFile = self->m_handleOfSave;
// //     if (!hFile || INVALID_HANDLE_VALUE == hFile)
// //         return;
// // 
// //     DWORD numberOfBytesWrite = 0;
// //     BOOL b = ::WriteFile(hFile, data, dataLength, &numberOfBytesWrite, nullptr);
// //     if (!b) {
// //         ::CloseHandle(hFile);
// //         self->m_handleOfSave = nullptr;
// //         return;
// //     }
//     if (!self->m_handleOfSave)
//         return;
// 
//     DWORD numberOfBytesWrite = self->m_handleOfSave->WriteAtCurrentPos(data, dataLength);
// 
//     self->m_handleOfSave->Close();
//     delete self->m_handleOfSave;
// 
//     self->m_downloadedSize += numberOfBytesWrite;
// }
// 
// void SimpleDownload::onSimpleDownloadDidFailCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, const utf8* error)
// {
//     SimpleDownload* self = (SimpleDownload*)param;
//     if (self->m_handleOfSave)
//         delete self->m_handleOfSave;
//     self->m_handleOfSave = nullptr;
// 
//     delete self;
// }
// 
// void SimpleDownload::onSimpleDownloadDidFinishLoadingCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, double finishTime)
// {
//     SimpleDownload* self = (SimpleDownload*)param;
//     if (self->m_handleOfSave)
//         delete self->m_handleOfSave;
//     self->m_handleOfSave = nullptr;
//     self->m_totalSize = self->m_downloadedSize;
// 
//     delete self;
// }

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

SimpleDownload::SimpleDownload(mbWebView mbView,
    size_t expectedContentLength,
    const char* url,
    const char* mime,
    const char* disposition,
    mbNetJob job,
    mbNetJobDataBind* dataBind,
    mbDownloadBind* callbackBind)
{
    m_totalSize = expectedContentLength;
    m_url = url;
    m_mime = mime;
    m_contentDisposition = disposition;
    m_handleOfSave = nullptr;
    m_mbView = mbView;
    m_hasFinish = false;
    m_loadingResult = (mbLoadingResult)-1;

    dataBind->param = this;
    dataBind->recvCallback = onDataRecv;
    dataBind->finishCallback = onDataFinish;

    m_callbackBind.param = nullptr;
    m_callbackBind.recvCallback = nullptr;
    m_callbackBind.finishCallback = nullptr;
    m_callbackBind.saveNameCallback = nullptr;

    if (callbackBind)
        m_callbackBind = *callbackBind;
}

SimpleDownload::~SimpleDownload()
{

}

SimpleDownload* SimpleDownload::create(mbWebView webView,
    const WCHAR* savePath,
    const mbDialogOptions* dialogOpt,
    const mbDownloadOptions* downloadOpt,
    size_t expectedContentLength,
    const char* url,
    const char* mime,
    const char* disposition,
    mbNetJob job,
    mbNetJobDataBind* dataBind,
    mbDownloadBind* callbackBind)
{
    if (m_dialogCount > 0)
        return nullptr;

    SimpleDownload* self = new SimpleDownload(webView, expectedContentLength, url, mime, disposition, job, dataBind, callbackBind);

    if (dialogOpt && dialogOpt->magic == 'mbdo' && dialogOpt->defaultPath)
        self->dialogOpt.defaultPath = dialogOpt->defaultPath;

    if (savePath) {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)webView);
        webview->setIsMouseKeyMessageEnable(true);

        std::vector<WCHAR>* fileResult = nullptr;
        size_t pathLen = c16len((const char16_t*)savePath);
        if (pathLen > 0) {
            fileResult = new std::vector<WCHAR>();
            fileResult->resize(MAX_PATH * 2);

            memcpy(fileResult->data(), savePath, pathLen * sizeof(WCHAR));

            if (!(downloadOpt && downloadOpt->magic == 'mbdo' && downloadOpt->saveAsPathAndName)) {
                std::u16string defaultSaveName = getSaveName(self->m_contentDisposition, self->m_url);
                PathAppendW((LPWSTR)(fileResult->data()), (LPCWSTR)(defaultSaveName.c_str()));
            }
        }

        content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self, fileResult] {
            self->startSave(fileResult);
        });
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
    if (m_hasFinish && (MB_LOADING_FAILED == m_loadingResult || MB_LOADING_CANCELED == m_loadingResult))
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
    if (!m_callbackBind.beginSaveCallback)
        return;

    base::FilePath savePath = changeStrToFilePath(m_savePath);
    std::string savePathStr = base::UTF16ToUTF8(m_savePath);
    mbStringPtr newPath = m_callbackBind.beginSaveCallback(m_callbackBind.param, savePathStr.c_str(), base::PathExists(savePath));
    if (!newPath || mbGetStringLen(newPath) == 0)
        return;

    m_savePath.clear();
    if (!base::UTF8ToUTF16(mbGetString(newPath), mbGetStringLen(newPath), &m_savePath)) {
        m_loadingResult = MB_LOADING_FAILED;

        if (m_callbackBind.finishCallback)
            m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);
        return;
    }
}

void SimpleDownload::startSaveImpl()
{
    if (!m_handleOfSave && !m_savePath.empty()) {
        onBeginSaveCallback();

        base::File* hFile = new base::File(changeStrToFilePath(m_savePath), base::File::FLAG_WRITE | base::File::FLAG_CREATE_ALWAYS);
        if (!hFile || !hFile->IsValid()) {
            std::string output = "SimpleDownload::startSaveImpl fail";
            output += base::UTF16ToUTF8(m_savePath);
            output += "\n";
            OutputDebugStringA(output.c_str());

            m_savePath.clear();

            m_loadingResult = MB_LOADING_FAILED;

            if (m_callbackBind.finishCallback)
                m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);
            return;
        }
        m_handleOfSave = hFile;

        if (m_callbackBind.saveNameCallback)
            m_callbackBind.saveNameCallback(m_callbackBind.param, (const WCHAR*)m_savePath.c_str());
    }

    if (!m_handleOfSave) {
        OutputDebugStringA("SimpleDownload::startSaveImpl, m_handleOfSave fail\n");
        return;
    }

#ifdef OS_LINUX
    char* output = (char*)malloc(0x1000);
    sprintf(output, "SimpleDownload::startSaveImpl: %p %d, %d, %s\n", m_callbackBind.recvCallback, canSave(), m_cacheData.size(), base::UTF16ToUTF8(m_savePath).c_str());
    OutputDebugStringA(output);
    free(output);
#endif
    if (m_callbackBind.recvCallback && canSave() && 0 != m_cacheData.size())
        m_callbackBind.recvCallback(m_callbackBind.param, nullptr, &m_cacheData[0], (int)m_cacheData.size());

    //BOOL b = FALSE;
    //DWORD numberOfBytesWrite = 0;
    if (0 != m_cacheData.size()) {
        m_handleOfSave->WriteAtCurrentPos(&m_cacheData[0], (DWORD)m_cacheData.size());
        //b = ::WriteFile(m_handleOfSave, &m_cacheData[0], (DWORD)m_cacheData.size(), &numberOfBytesWrite, nullptr);
    }
    m_cacheData.clear();

    if (!m_hasFinish)
        return;

    m_handleOfSave->Close();
    delete m_handleOfSave;
    m_handleOfSave = nullptr;

    if (m_callbackBind.finishCallback)
        m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);

    SimpleDownload* self = this;
    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self] {
        delete self;
    });
}

void SimpleDownload::startSave(std::vector<WCHAR>* path)
{
    if (!path || 0 == path->size()) {
        m_loadingResult = (mbLoadingResult)-1;
        if (m_callbackBind.finishCallback)
            m_callbackBind.finishCallback(m_callbackBind.param, nullptr, m_loadingResult);
        return;
    }
    m_savePath = (const char16_t*)path->data();
    delete path;

    startSaveImpl();
}

void SimpleDownload::onDataRecvImpl(mbNetJob job, const char* data, int length)
{
    if (0 == length)
        return;

    size_t oldSize = m_cacheData.size();
    m_cacheData.resize(oldSize + length);
    memcpy(&m_cacheData[oldSize], data, length);

    m_downloadedSize += length;

    startSaveImpl();

    if (MB_LOADING_FAILED == m_loadingResult)
        mbNetCancelRequest(job);
}

void SimpleDownload::onDataFinishImpl(mbNetJob job, mbLoadingResult result)
{
    m_hasFinish = true;
    m_loadingResult = result;
    startSaveImpl();
}

unsigned int SimpleDownload::dialogThread(void* param)
{
#ifdef OS_LINUX
    __debugbreak();
#else
    SimpleDownload* self = (SimpleDownload*)param;

    OPENFILENAMEW ofn = { 0 };
    std::vector<WCHAR>* fileResult = new std::vector<WCHAR>();
    fileResult->resize(4 * MAX_PATH + 1);

    std::u16string defaultSaveName = getSaveName(self->m_contentDisposition, self->m_url);
    if (defaultSaveName.size() > 150)
        defaultSaveName = defaultSaveName.substr(0, 150);
    wcscpy(fileResult->data(), (const WCHAR*)defaultSaveName.c_str());

    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = nullptr;
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

    mbWebView mbWebview = self->m_mbView;

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [mbWebview] {
        content::MbWebView* webview = (content::MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr((int64_t)mbWebview);
        if (!webview)
            return;
        webview->setIsMouseKeyMessageEnable(true);
    });

    content::ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self, fileResult] {
        self->startSave(fileResult);
    });

    InterlockedDecrement((long*)&m_dialogCount);
    base::subtle::Barrier_AtomicIncrement(&m_dialogCount, -1);
#endif
    return 0;
}

}