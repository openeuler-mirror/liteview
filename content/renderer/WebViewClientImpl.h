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


#ifndef content_renderer_WebViewClientImpl_h
#define content_renderer_WebViewClientImpl_h

#include "third_party/blink/public/web/web_view_client.h"

namespace content {

class MbWebView;

class WebViewClientImpl : public blink::WebViewClient {
public:
    WebViewClientImpl(MbWebView* mbwebview)
    {
        m_mbwebview = mbwebview;
    }

    ~WebViewClientImpl() override { }

    MbWebView* getMbwebview() const
    {
        return m_mbwebview;
    }

    void InvalidateContainer() override { }

    void DidAutoResize(const gfx::Size& new_size) override { }

    void DidFocus() override { }

    void OnDestruct() override { }

private:
    MbWebView* m_mbwebview;
};

}

#endif // content_renderer_WebViewClientImpl_h