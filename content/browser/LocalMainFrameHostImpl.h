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


#ifndef content_browser_LocalMainFrameHostImpl_h
#define content_browser_LocalMainFrameHostImpl_h

#include "third_party/blink/public/mojom/frame/frame.mojom-blink.h"
#include "third_party/blink/public/mojom/frame/text_autosizer_page_info.mojom-blink-forward.h"
#include "third_party/blink/public/mojom/frame/text_autosizer_page_info.mojom-blink.h"
#include "third_party/blink/public/mojom/window_features/window_features.mojom-blink.h"
#include "content/common/common.h"

namespace content {

class WebLocalFrameClientImpl;

class LocalMainFrameHostImpl : public ::blink::mojom::blink::LocalMainFrameHost {
public:
    LocalMainFrameHostImpl(WebLocalFrameClientImpl* frameClient)
    {
        m_frameClient = frameClient;
    }

    virtual void ScaleFactorChanged(float scale) override
    {
        printFuncName(__FUNCTION__, true, false);
    }

    virtual void ContentsPreferredSizeChanged(const ::gfx::Size& pref_size) override
    {
        printFuncName(__FUNCTION__, true, false);
    }

    virtual void TextAutosizerPageInfoChanged(::blink::mojom::blink::TextAutosizerPageInfoPtr page_info) override
    {
        printFuncName(__FUNCTION__, true, false);
    }

    virtual void FocusPage() override
    {
        printFuncName(__FUNCTION__, true, false);
    }

    virtual void TakeFocus(bool reverse)override
    {
        printFuncName(__FUNCTION__, true, false);
    }

    virtual void UpdateTargetURL(const ::blink::KURL& url, UpdateTargetURLCallback callback) override
    {
        printFuncName(__FUNCTION__, true, false);
    }

    virtual void RequestClose() override;

    virtual void ShowCreatedWindow(const ::blink::LocalFrameToken& opener_frame_token, ::ui::mojom::blink::WindowOpenDisposition disposition,
        ::blink::mojom::blink::WindowFeaturesPtr window_features, bool opened_by_user_gesture, ShowCreatedWindowCallback callback)
        override
    {
        printFuncName(__FUNCTION__, true, false);
    }

    virtual void SetWindowRect(const ::gfx::Rect& bounds, SetWindowRectCallback callback) override
    {
        printFuncName(__FUNCTION__, true, false);
    }

    virtual void DidFirstVisuallyNonEmptyPaint() override;

    virtual void DidAccessInitialMainDocument() override
    {
        printFuncName(__FUNCTION__, true, false);
    }

private:
    WebLocalFrameClientImpl* m_frameClient = nullptr;
};

}

#endif