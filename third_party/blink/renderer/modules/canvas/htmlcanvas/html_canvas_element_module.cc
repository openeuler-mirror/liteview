// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/modules/canvas/htmlcanvas/html_canvas_element_module.h"

#include "base/metrics/histogram_functions.h"
#include "third_party/blink/renderer/bindings/modules/v8/v8_canvas_context_creation_attributes_module.h"
#include "third_party/blink/renderer/core/dom/dom_node_ids.h"
#include "third_party/blink/renderer/core/html/canvas/canvas_rendering_context.h"
#include "third_party/blink/renderer/core/offscreencanvas/offscreen_canvas.h"
#include "third_party/blink/renderer/modules/canvas/htmlcanvas/canvas_context_creation_attributes_helpers.h"

namespace blink {

V8RenderingContext* HTMLCanvasElementModule::getContext(
    HTMLCanvasElement& canvas, const String& context_id, const CanvasContextCreationAttributesModule* attributes, ExceptionState& exception_state)
{
    if (canvas.IsOffscreenCanvasRegistered() && !canvas.LowLatencyEnabled()) {
        // The existence of canvas surfaceLayerBridge indicates that
        // HTMLCanvasElement.transferControlToOffscreen() has been called.
        exception_state.ThrowDOMException(DOMExceptionCode::kInvalidStateError,
            "Cannot get context from a canvas that "
            "has transferred its control to "
            "offscreen.");
        return nullptr;
    }

    // todo(mb): 临时, 暂时禁止几个网站使用 webgl 和 webgl2, 有报错
    if (context_id == "webgl" || context_id == "webgl2") {
        String url = canvas.GetDocument().Url().GetString();
        static const char* blacklist[] = {
            "bilibili.com",
            "iqiyi.com/v_",
            "v.qq.com",
            "v.youku.com",
            "gitee.com"
        };

        for (const char* blocked : blacklist) {
            if (url.Contains(blocked)) {
                exception_state.ThrowSecurityError(
                    "WebGL is disabled on this site: " + url);
                return nullptr;
            }
        }
    }

    CanvasContextCreationAttributesCore canvas_context_creation_attributes;
    if (!ToCanvasContextCreationAttributes(attributes, canvas_context_creation_attributes, exception_state)) {
        return nullptr;
    }
    CanvasRenderingContext* context = canvas.GetCanvasRenderingContext(context_id, canvas_context_creation_attributes);
    if (!context)
        return nullptr;
    return context->AsV8RenderingContext();
}

OffscreenCanvas* HTMLCanvasElementModule::transferControlToOffscreen(
    ExecutionContext* execution_context, HTMLCanvasElement& canvas, ExceptionState& exception_state)
{
    if (canvas.RenderingContext()) {
        exception_state.ThrowDOMException(DOMExceptionCode::kInvalidStateError, "Cannot transfer control from a canvas that has a rendering context.");
        return nullptr;
    }

    OffscreenCanvas* offscreen_canvas = nullptr;
    if (canvas.IsOffscreenCanvasRegistered()) {
        exception_state.ThrowDOMException(DOMExceptionCode::kInvalidStateError, "Cannot transfer control from a canvas for more than one time.");
    } else {
        canvas.CreateLayer();
        offscreen_canvas = TransferControlToOffscreenInternal(execution_context, canvas, exception_state);
    }

    base::UmaHistogramBoolean("Blink.OffscreenCanvas.TransferControlToOffscreen", !!offscreen_canvas);
    return offscreen_canvas;
}

OffscreenCanvas* HTMLCanvasElementModule::TransferControlToOffscreenInternal(
    ExecutionContext* execution_context, HTMLCanvasElement& canvas, ExceptionState& exception_state)
{
    OffscreenCanvas* offscreen_canvas = OffscreenCanvas::Create(execution_context, canvas.width(), canvas.height());
    offscreen_canvas->SetFilterQuality(canvas.FilterQuality());

    DOMNodeId canvas_id = DOMNodeIds::IdForNode(&canvas);
    canvas.RegisterPlaceholderCanvas(static_cast<int>(canvas_id));
    offscreen_canvas->SetPlaceholderCanvasId(canvas_id);

    SurfaceLayerBridge* bridge = canvas.SurfaceLayerBridge();
    if (bridge) {
        offscreen_canvas->SetFrameSinkId(bridge->GetFrameSinkId().client_id(), bridge->GetFrameSinkId().sink_id());
    }
    return offscreen_canvas;
}

} // namespace blink
