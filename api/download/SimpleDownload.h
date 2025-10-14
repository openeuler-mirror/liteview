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


#ifndef mbvip_download_SimpleDownload_h
#define mbvip_download_SimpleDownload_h

#include "content/common/ThreadCall.h"
//#include "mbvip/common/LiveIdDetect.h"
//#include "wke/wkedefine.h"
#include <vector>
#include <process.h>
#include <shlwapi.h>

namespace base {
class File;
}

namespace download {

class SimpleDownload {
public:
    static SimpleDownload* create(mbWebView webView,
        const WCHAR* savePath,
        const mbDialogOptions* dialogOpt,
        const mbDownloadOptions* downloadOpt,
        size_t expectedContentLength,
        const char* url,
        const char* mime,
        const char* disposition,
        mbNetJob job,
        mbNetJobDataBind* dataBind,
        mbDownloadBind* callbackBind);

    ~SimpleDownload();

    static unsigned int WINAPI dialogThread(void* param);

    static int getDialogCount();
private:
    SimpleDownload(mbWebView mbView,
        size_t expectedContentLength,
        const char* url,
        const char* mime,
        const char* disposition,
        mbNetJob job,
        mbNetJobDataBind* dataBind,
        mbDownloadBind* callbackBind);

    void startSave(std::vector<WCHAR>* path);
    void startSaveImpl();
    bool canSave();
    void onBeginSaveCallback();

//     static void WKE_CALL_TYPE onSimpleDownloadWillRedirectCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr oldRequest, wkeWebUrlRequestPtr request, wkeWebUrlResponsePtr redirectResponse);
//     static void WKE_CALL_TYPE onSimpleDownloadDidReceiveResponseCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, wkeWebUrlResponsePtr response);
//     static void WKE_CALL_TYPE onSimpleDownloadDidReceiveDataCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, const char* data, int dataLength);
//     static void WKE_CALL_TYPE onSimpleDownloadDidFailCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, const utf8* error);
//     static void WKE_CALL_TYPE onSimpleDownloadDidFinishLoadingCallback(wkeWebView webView, void* param, wkeWebUrlRequestPtr request, double finishTime);
    static void MB_CALL_TYPE onDataRecv(void* param, mbNetJob job, const char* data, int length);
    static void MB_CALL_TYPE onDataFinish(void* param, mbNetJob job, mbLoadingResult result);

    void onDataRecvImpl(mbNetJob job, const char* data, int length);
    void onDataFinishImpl(mbNetJob job, mbLoadingResult result);

    static int m_dialogCount;

    std::string m_url;
    std::string m_mime;
    std::string m_contentDisposition;
    std::u16string m_savePath;

    base::File* m_handleOfSave;
    size_t m_totalSize;
    size_t m_downloadedSize;

    mbWebView m_mbView;

    std::vector<char> m_cacheData;
    bool m_hasFinish;
    mbLoadingResult m_loadingResult;

    struct DialogOptions {
        std::string title;
        std::string defaultPath;
        std::string buttonLabel;
    };
    DialogOptions dialogOpt;

    mbDownloadBind m_callbackBind;
};

}

#endif // download_SimpleDownload_h