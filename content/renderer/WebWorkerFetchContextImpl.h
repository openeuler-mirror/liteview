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


#ifndef content_renderer_WebWorkerFetchContextImpl_h
#define content_renderer_WebWorkerFetchContextImpl_h

#include "third_party/blink/public/platform/web_worker_fetch_context.h"

namespace mbnet {
class LoaderFactoryImpl;
}

namespace content {

class WebWorkerFetchContextImpl : public blink::WebWorkerFetchContext {
public:
    WebWorkerFetchContextImpl(const blink::WebSecurityOrigin& orig, int64_t mbwebviewId);
    ~WebWorkerFetchContextImpl() override;

    void SetTerminateSyncLoadEvent(base::WaitableEvent*) override;

    void InitializeOnWorkerThread(blink::AcceptLanguagesWatcher*) override;

    blink::WebURLLoaderFactory* GetURLLoaderFactory() override;

    std::unique_ptr<blink::WebURLLoaderFactory> WrapURLLoaderFactory(
        blink::CrossVariantMojoRemote<network::mojom::URLLoaderFactoryInterfaceBase> url_loader_factory) override;

    void WillSendRequest(blink::WebURLRequest&) override;

    net::SiteForCookies SiteForCookies(void) const override;

    absl::optional<blink::WebSecurityOrigin> TopFrameOrigin(void) const override;

    blink::WebString GetAcceptLanguages(void) const override;

    void SetIsOfflineMode(bool) override;

    blink::mojom::ControllerServiceWorkerMode GetControllerServiceWorkerMode(void) const override;

private:
    std::unique_ptr<mbnet::LoaderFactoryImpl> m_loaderFactoryImpl;
    blink::WebSecurityOrigin m_orig;
    int64_t m_mbwebviewId = 0;
};

}

#endif // content_renderer_WebWorkerFetchContextImpl_h
