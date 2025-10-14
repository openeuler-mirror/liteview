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


#ifndef content_renderer_AssociatedInterfaceProviderImpl_h
#define content_renderer_AssociatedInterfaceProviderImpl_h

#include "third_party/blink/public/mojom/associated_interfaces/associated_interfaces.mojom.h"
#include "content/browser/LocalFrameHostImpl.h"
#include "content/browser/BackForwardCacheControllerHostImpl.h"
#include "content/browser/LocalMainFrameHostImpl.h"
#include "content/browser/BroadcastChannelProviderImpl.h"
#include "mojo/public/cpp/bindings/associated_receiver.h"

namespace content {

class WebLocalFrameClientImpl;

class AssociatedInterfaceProviderImpl : public blink::mojom::AssociatedInterfaceProvider {
public:
    AssociatedInterfaceProviderImpl(WebLocalFrameClientImpl* frameClient);

    void GetAssociatedInterface(const std::string& name, ::mojo::PendingAssociatedReceiver<blink::mojom::AssociatedInterface> receiver) override;

private:
    //mojo::AssociatedReceiver<::blink::mojom::blink::LocalFrameHost> m_localFrameHostReceiver;
    //mojo::AssociatedReceiver<::blink::mojom::blink::BackForwardCacheControllerHost> m_backForwardCacheControllerHostReceiver;
    //mojo::AssociatedReceiver<::blink::mojom::blink::LocalMainFrameHost> m_localMainFrameHostReceiver;
    //mojo::AssociatedReceiver<::blink::mojom::blink::BroadcastChannelProvider> m_broadcastChannelProviderReceiver;    

    WebLocalFrameClientImpl* m_frameClient;
};

}

#endif // content_renderer_AssociatedInterfaceProviderImpl_h