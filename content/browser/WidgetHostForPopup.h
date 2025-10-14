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


#ifndef content_browser_WidgetHostForPopup_h
#define content_browser_WidgetHostForPopup_h

#include "third_party/blink/public/mojom/widget/platform_widget.mojom-blink.h"

namespace content {

class WidgetHostForPopup
    : public blink::mojom::blink::WidgetHost {
public:
    WidgetHostForPopup();
    ~WidgetHostForPopup();

    void SetCursor(const ::ui::Cursor& cursor) override;

    void UpdateTooltipUnderCursor(const ::WTF::String& tooltip_text, ::base::i18n::TextDirection text_direction_hint) override;

    void UpdateTooltipFromKeyboard(const ::WTF::String& tooltip_text, ::base::i18n::TextDirection text_direction_hint, const ::gfx::Rect& bounds) override;

    void ClearKeyboardTriggeredTooltip() override;

    void TextInputStateChanged(::ui::mojom::blink::TextInputStatePtr state) override;

    void SelectionBoundsChanged(
        const ::gfx::Rect& anchor_rect, 
        ::base::i18n::TextDirection anchor_dir, 
        const ::gfx::Rect& focus_rect,
        ::base::i18n::TextDirection focus_dir, 
        const ::gfx::Rect& bounding_box_rect, 
        bool is_anchor_first)
        override;

    void CreateFrameSink(
        ::mojo::PendingReceiver<::viz::mojom::blink::CompositorFrameSink> compositor_frame_sink_receiver,
        ::mojo::PendingRemote<::viz::mojom::blink::CompositorFrameSinkClient> compositor_frame_sink_client)
        override;

    void RegisterRenderFrameMetadataObserver(
        ::mojo::PendingReceiver<::cc::mojom::blink::RenderFrameMetadataObserverClient> render_frame_metadata_observer_client_receiver,
        ::mojo::PendingRemote<::cc::mojom::blink::RenderFrameMetadataObserver> render_frame_metadata_observer)
        override;
};

}

#endif // content_browser_WidgetHostForPopup_h
