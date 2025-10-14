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


#ifndef content_renderer_PlatformEventHandler_h
#define content_renderer_PlatformEventHandler_h

#include "content/common/common.h"
#include "third_party/blink/public/common/input/web_keyboard_event.h"
#include "third_party/blink/public/common/input/web_input_event.h"
#include "third_party/blink/public/platform/web_vector.h"
#include "third_party/blink/public/web/web_draggable_region.h"

#include "third_party/blink/public/mojom/input/touch_event.mojom-blink.h"
#include "third_party/blink/public/mojom/input/input_handler.mojom.h"
#include "third_party/blink/public/mojom/input/input_handler.mojom-blink.h"

#include "mojo/public/cpp/bindings/remote.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include "ui/gfx/geometry/point.h"
#include "ui/gfx/geometry/point_f.h"
#include "ui/gfx/geometry/rect.h"
#include "base/timer/timer.h"
#include <windows.h>

namespace blink {
class WebViewImpl;
class WebWidget;
class WebTouchEvent;
class WebTouchPoint;
}

namespace content {

class RenderWidgetHostImpl;

// class TouchEmulator {
// public:
//     TouchEmulator(blink::WebWidget* webWidget);
// 
//     void handleMouseDown(HWND hWnd, blink::WebTouchEvent* touchEvent, blink::WebTouchPoint* touchPoint);
//     void handleMouseUp(HWND hWnd, blink::WebTouchEvent* touchEvent, blink::WebTouchPoint* touchPoint);
//     void handleMouseMove(HWND hWnd, blink::WebTouchEvent* touchEvent, blink::WebTouchPoint* touchPoint);
// 
// private:
//     void gestureShowPressTimer(blink::TimerBase*);
//     void gestureLongPressTimer(blink::TimerBase*);
// 
//     blink::WebWidget* m_webWidget;
// 
//     blink::Timer<TouchEmulator> m_gestureShowPressTimer;
//     blink::Timer<TouchEmulator> m_gestureLongPressTimer;
//     bool m_isLongPress; // 长按后为true，直到抬起手指
//     bool m_isPressState;
//     bool m_isScrollState;
// 
//     gfx::Point m_lastTouchDownPoint;
//     bool m_isValidLastTouchDownPoint;
// };

class PlatformEventHandler
    : public blink::mojom::blink::WidgetInputHandlerHost {
public:
    PlatformEventHandler(int64_t webviewid, blink::WebWidget* webWidget, blink::WebViewImpl* webViewImpl);
    ~PlatformEventHandler();
    void destroy();

    // WidgetInputHandlerHost
    void SetTouchActionFromMain(::cc::TouchAction touch_action) override { printFuncName(__FUNCTION__, false, false); }
    void SetPanAction(blink::mojom::blink::PanAction pan_action) override { printFuncName(__FUNCTION__, false, false); }
    void DidOverscroll(blink::mojom::blink::DidOverscrollParamsPtr params) override { printFuncName(__FUNCTION__, false, false); }
    void DidStartScrollingViewport() override { printFuncName(__FUNCTION__, false, false); }
    void ImeCancelComposition() override { printFuncName(__FUNCTION__, false, false); }
    void ImeCompositionRangeChanged(const ::gfx::Range& range, const WTF::Vector<::gfx::Rect>& bounds) override { printFuncName(__FUNCTION__, false, false); }
    void SetMouseCapture(bool capture) override { printFuncName(__FUNCTION__, false, false); }
    void RequestMouseLock(bool from_user_gesture, bool unadjusted_movement, blink::mojom::blink::WidgetInputHandlerHost::RequestMouseLockCallback callback) override
    {
        printFuncName(__FUNCTION__, false, true);
    }
    //----

    static blink::WebKeyboardEvent buildKeyboardEvent(blink::WebInputEvent::Type type, UINT message, WPARAM wParam, LPARAM lParam);

    struct MouseEvtInfo {
        bool isNeedSetFocus;
        bool isWillDestroy;
        blink::WebVector<blink::WebDraggableRegion> draggableRegion;
        RenderWidgetHostImpl* renderWidgetHost = nullptr;
    };
    LRESULT fireMouseEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, const MouseEvtInfo& info, BOOL* bHandle);
    LRESULT fireWheelEvent(HWND hWnd, WPARAM wParam, LPARAM lParam);
    void fireCaptureChangedEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireTouchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireRealTouchEvent(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    void fireRealTouchEventTest(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
    
    void checkMouseLeave();

    bool fireMouseUpEventIfNeeded(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, const MouseEvtInfo& info, BOOL* bHandle);
    void buildMousePosInfo(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, bool* handle, gfx::Point* pos, gfx::Point* globalPos);

    void setIsDraggableNodeMousedown();

    void setTouchSimulateEnabled(bool b) { m_enableTouchSimulate = b; }
    void setSystemTouchEnabled(bool b) { m_enableSystemTouch = b; }

    void setHwndRenderOffset(const gfx::Point& offset) { m_offset = offset; }
    gfx::Point getHwndRenderOffset() const { return m_offset; }

    void setDispatchDirectlyToWidget() { m_isDispatchDirectlyToWidget = true; }

    static bool isDraggableRegionNcHitTest(HWND hWnd, const gfx::Point& pos, const blink::WebVector<blink::WebDraggableRegion>& draggableRegion);

    void fireInputEventToCompositingThread(const blink::WebInputEvent& evt);
private:
    void fireWheelEventOnCompositorThread(int x, int y, bool shiftKey, bool ctrlKey, float delta, float deltaX, float deltaY, int modifiers);

    friend class RenderWidgetHostImpl;
    
    bool m_isDraggableRegionNcHitTest;
    bool m_postMouseLeave;
    bool m_mouseInWindow;
    bool m_isAlert;
    bool m_isDraggableNodeMousedown;
    bool m_isLeftMousedown;
    int64_t m_webviewid;
    int64_t m_lastTimeMouseDown;
    gfx::Point m_offset;
    gfx::Point m_lastPosMouseDown;
    gfx::Point m_lastPosMouseMove;
    gfx::Rect m_lastPosForDrag;
    blink::WebViewImpl* m_webViewImpl;
    blink::WebWidget* m_webWidget;
    bool m_enableTouchSimulate;
    bool m_enableSystemTouch;

    bool m_isDispatchDirectlyToWidget = false;

    base::Lock m_lock;

    //TouchEmulator m_touchEmulator;

    gfx::PointF m_lastTouchDownPoint;
    bool m_isValidLastTouchDownPoint;

    HWND m_hWnd;
    std::unique_ptr<base::RepeatingTimer> m_checkMouseLeaveTimer;

    mojo::Remote<::blink::mojom::blink::WidgetInputHandler> m_blinkWidgetInputHandler;
    mojo::Receiver<::blink::mojom::blink::WidgetInputHandlerHost> m_hostReceiver{ this };

    base::WeakPtrFactory<PlatformEventHandler> m_weakPtr{ this };
};

} // content

#endif // content_renderer_PlatformEventHandler_h