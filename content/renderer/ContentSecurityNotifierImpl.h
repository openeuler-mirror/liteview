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


#ifndef content_renderer_ContentSecurityNotifierImpl_h
#define content_renderer_ContentSecurityNotifierImpl_h

#include "third_party/blink/public/mojom/loader/content_security_notifier.mojom-blink.h"

namespace content {

class ContentSecurityNotifierImpl : public blink::mojom::blink::ContentSecurityNotifier {
public:
    ContentSecurityNotifierImpl(int64_t webviewId)
    {

    }

    ~ContentSecurityNotifierImpl()
    {

    }

    void NotifyContentWithCertificateErrorsRan() override
    {
        //OutputDebugStringA("ContentSecurityNotifierImpl::NotifyContentWithCertificateErrorsRan\n");
    }

    void NotifyContentWithCertificateErrorsDisplayed() override
    {
        //OutputDebugStringA("ContentSecurityNotifierImpl::NotifyContentWithCertificateErrorsDisplayed\n");
    }

    void NotifyInsecureContentRan(const ::blink::KURL& origin, const ::blink::KURL& insecure_url) override
    {
        //OutputDebugStringA("ContentSecurityNotifierImpl::NotifyInsecureContentRan\n");
    }
};

}

#endif // content_renderer_ContentSecurityNotifierImpl_h