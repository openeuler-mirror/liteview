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


#include "content/renderer/WebWorkerFetchContextImpl.h"

#include "third_party/blink/public/platform/web_url_loader_factory.h"
#include "net/cookies/site_for_cookies.h"
#include "mbnet/LoaderFactoryImpl.h"
#include "mbnet/WebURLRequestExtraDataWrap.h"
#include <windows.h>

namespace blink {
class WebLocalFrame;
}

namespace content {

WebWorkerFetchContextImpl::WebWorkerFetchContextImpl(const blink::WebSecurityOrigin& orig, int64_t mbwebviewId)
{
    m_orig = blink::WebSecurityOrigin::CreateFromString(orig.ToString());
    m_mbwebviewId = mbwebviewId;
    m_loaderFactoryImpl.reset(new mbnet::LoaderFactoryImpl());
}

WebWorkerFetchContextImpl::~WebWorkerFetchContextImpl()
{
    m_loaderFactoryImpl.reset();
}

void WebWorkerFetchContextImpl::SetTerminateSyncLoadEvent(base::WaitableEvent* evt)
{
    m_loaderFactoryImpl->SetTerminateSyncLoadEvent(evt);
}

void WebWorkerFetchContextImpl::InitializeOnWorkerThread(blink::AcceptLanguagesWatcher*)
{
    OutputDebugStringA("WebWorkerFetchContextImpl::InitializeOnWorkerThread Not impl\n");
}

blink::WebURLLoaderFactory* WebWorkerFetchContextImpl::GetURLLoaderFactory()
{
    return m_loaderFactoryImpl.get();
}

std::unique_ptr<blink::WebURLLoaderFactory> WebWorkerFetchContextImpl::WrapURLLoaderFactory(
    blink::CrossVariantMojoRemote<network::mojom::URLLoaderFactoryInterfaceBase> url_loader_factory)
{
    std::unique_ptr<blink::WebURLLoaderFactory> loaderFactoryImpl;
    loaderFactoryImpl.reset(new mbnet::LoaderFactoryImpl());
    return std::move(loaderFactoryImpl);
}

void setRequestHead(blink::WebLocalFrame* webFrame, blink::WebURLRequest& request);

void WebWorkerFetchContextImpl::WillSendRequest(blink::WebURLRequest& req)
{
    scoped_refptr<mbnet::WebURLRequestExtraDataWrap> extraData = base::MakeRefCounted<mbnet::WebURLRequestExtraDataWrap>();
    extraData->mbwebviewId = m_mbwebviewId;
    req.SetURLRequestExtraData(extraData);

    setRequestHead(nullptr, req);
}

net::SiteForCookies WebWorkerFetchContextImpl::SiteForCookies(void) const
{
    return net::SiteForCookies();
}

absl::optional<blink::WebSecurityOrigin> WebWorkerFetchContextImpl::TopFrameOrigin(void) const
{
    return m_orig;
}

blink::WebString WebWorkerFetchContextImpl::GetAcceptLanguages(void) const
{
    return blink::WebString::FromASCII("zh-CN");
}

void WebWorkerFetchContextImpl::SetIsOfflineMode(bool)
{
    DebugBreak();
    return;
}

blink::mojom::ControllerServiceWorkerMode WebWorkerFetchContextImpl::GetControllerServiceWorkerMode(void) const
{
    return blink::mojom::ControllerServiceWorkerMode::kNoController;
}

}