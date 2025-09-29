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


#ifndef content_renderer_PolicyContainerHostImpl_h
#define content_renderer_PolicyContainerHostImpl_h

#include "gen/third_party/blink/public/mojom/frame/policy_container.mojom-blink.h"

namespace content {

class PolicyContainerHostImpl : public blink::mojom::blink::PolicyContainerHost {
public:
    PolicyContainerHostImpl() { }
    ~PolicyContainerHostImpl()
    {

    }

    void SetReferrerPolicy(::network::mojom::blink::ReferrerPolicy referrer_policy) override
    {
        //OutputDebugStringA("PolicyContainerHostImpl::SetReferrerPolicy not impl\n");
    }

    void AddContentSecurityPolicies(WTF::Vector<::network::mojom::blink::ContentSecurityPolicyPtr> content_security_policies) override
    {
        //OutputDebugStringA("PolicyContainerHostImpl::AddContentSecurityPolicies not impl\n");
    }

    void IssueKeepAliveHandle(::mojo::PendingReceiver<blink::mojom::blink::PolicyContainerHostKeepAliveHandle> receiver) override
    {
        //OutputDebugStringA("PolicyContainerHostImpl::IssueKeepAliveHandle not impl\n");
    }
};

}

#endif // content_renderer_PolicyContainerHostImpl_h