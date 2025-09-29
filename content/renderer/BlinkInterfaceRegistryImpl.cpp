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


#include "content/renderer/BlinkInterfaceRegistryImpl.h"
#include "content/renderer/WebLocalFrameClientImpl.h"

namespace content {

BlinkInterfaceRegistryImpl::BlinkInterfaceRegistryImpl(WebLocalFrameClientImpl* frameClient)
{
    m_frameClient = frameClient;
}

BlinkInterfaceRegistryImpl::~BlinkInterfaceRegistryImpl() { }

// blink::InterfaceRegistry override.
void BlinkInterfaceRegistryImpl::AddInterface(const char* name, const blink::InterfaceFactory& factory, scoped_refptr<base::SingleThreadTaskRunner> task_runner)
{
    //         std::string output("BlinkInterfaceRegistryImpl::AddInterface not impl: ");
    //         output += name;
    //         output += "\n";
    //         OutputDebugStringA(output.c_str());
}

void BlinkInterfaceRegistryImpl::AddAssociatedInterface(const char* name, const blink::AssociatedInterfaceFactory& factory)
{
    //         std::string output("BlinkInterfaceRegistryImpl::AddAssociatedInterface not impl: ");
    //         output += name;
    //         output += "\n";
    //         OutputDebugStringA(output.c_str());

    std::string nameStr(name);
    if ("blink.mojom.LocalFrame" == nameStr) {
        mojo::PendingReceiver<blink::mojom::blink::LocalFrame> localFrameRecv = m_frameClient->m_localFrameRemote.BindNewEndpointAndPassReceiver();
        factory.Run(localFrameRecv.PassHandle());
    }
}

}