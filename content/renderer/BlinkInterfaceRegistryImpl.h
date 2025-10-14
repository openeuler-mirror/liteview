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


#ifndef content_renderer_BlinkInterfaceRegistryImpl_h
#define content_renderer_BlinkInterfaceRegistryImpl_h

#include "third_party/blink/public/mojom/reporting/reporting.mojom-blink.h"
#include "third_party/blink/public/platform/interface_registry.h"

namespace content {

class WebLocalFrameClientImpl;

class BlinkInterfaceRegistryImpl : public blink::InterfaceRegistry {
public:
    BlinkInterfaceRegistryImpl(WebLocalFrameClientImpl* frameClient);
    ~BlinkInterfaceRegistryImpl();

    // blink::InterfaceRegistry override.
    void AddInterface(const char* name, const blink::InterfaceFactory& factory, scoped_refptr<base::SingleThreadTaskRunner> task_runner) override;

    void AddAssociatedInterface(const char* name, const blink::AssociatedInterfaceFactory& factory) override;

private:
    WebLocalFrameClientImpl* m_frameClient;
    //     const base::WeakPtr<service_manager::BinderRegistry> interface_registry_;
    //     const base::WeakPtr<blink::AssociatedInterfaceRegistry> associated_interface_registry_;
    //
    //     DISALLOW_COPY_AND_ASSIGN(BlinkInterfaceRegistryImpl);
};

}

#endif // content_renderer_BlinkInterfaceRegistryImpl_h