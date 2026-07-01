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


#include "content/browser/LocalMainFrameHostImpl.h"

#include "content/browser/MbWebview.h"
#include "content/renderer/WebLocalFrameClientImpl.h"
#include "content/common/ThreadCall.h"
#include "content/common/LiveIdDetect.h"
#include "base/task/sequenced_task_runner.h"

void mbDestroyWebViewImpl(mbWebView webviewHandle);

namespace content {

void LocalMainFrameHostImpl::DidFirstVisuallyNonEmptyPaint()
{
    if (m_frameClient)
        m_frameClient->onLoadingSucceeded();
}

void LocalMainFrameHostImpl::RequestClose()
{
    if (!m_frameClient)
        return;
    int64_t id = m_frameClient->getMbwebviewId();
    mbDestroyWebViewImpl(id);
}

void LocalMainFrameHostImpl::UpdateTargetURL(const ::blink::KURL& url, UpdateTargetURLCallback callback)
{
    base::SequencedTaskRunner::GetCurrentDefault()->PostTask(FROM_HERE, base::BindOnce([](UpdateTargetURLCallback callback) {
        std::move(callback).Run();
    }, std::move(callback)));

    if (!m_frameClient)
        return;
    int64_t id = m_frameClient->getMbwebviewId();
    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(id);
    if (!webview || !webview->getClosure().m_MouseOverUrlChangedCallback)
        return;
    
    std::string urlStr = url.GetString().Utf8();
    
    ThreadCall::callUiThreadAsync(MB_FROM_HERE, [id, urlStr]() {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(id);
        if (webview && webview->getClosure().m_MouseOverUrlChangedCallback) {
            webview->getClosure().m_MouseOverUrlChangedCallback(id, webview->getClosure().m_MouseOverUrlChangedParam, urlStr.c_str());
        }
    });
}

}
