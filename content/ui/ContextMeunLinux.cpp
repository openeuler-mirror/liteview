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

#if defined(OS_LINUX)

#include "content/ui/ContextMeun.h"
#include "linux/linuxgdi.h"
#include <gtk/gtk.h>
#include <array>
#include <atomic>

namespace {

struct CallbackContext {
    content::ContextMenu* instance;
    int action;
};

}

namespace content {

ContextMenu::ContextMenu()
{
}

void ContextMenu::onMenuItemClick(GtkWidget* widget, gpointer data)
{
    CallbackContext* ctx = (CallbackContext*)data;
    ContextMenu* self = ctx->instance;
    if (!self || !self->m_webview) {
        delete ctx;
        return;
    }

    switch (ctx->action) {
    case kMbMenuSelectedTextId:
        ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self] {
            self->m_webview->getWebView()->FocusedFrame()->ExecuteCommand("Copy");
        });
        break;
    case kMbMenuPasteId:
        ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self] {
            self->m_webview->getWebView()->FocusedFrame()->ExecuteCommand("Paste");
        });
        break;
    default:
        break;
    }
    delete ctx;
}

GtkWidget* ContextMenu::createGTKmenu(int blinkSupportedFlag)
{
    GtkWidget* menu = gtk_menu_new();

    for (const auto& [id, label] : kMenuItems) {
        if (!canShowItem(blinkSupportedFlag, (mbMenuItemId)id))
            continue;

        GtkWidget* item = gtk_menu_item_new_with_label(label);
        const CallbackContext* ctx = new CallbackContext { this, id };
        g_signal_connect(item, "activate", G_CALLBACK(onMenuItemClick), (gpointer)ctx);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);
    }

    gtk_widget_show_all(menu);
    return menu;
}

void ContextMenu::showMenuOnUiThread(UINT blinkSupportedFlag)
{
    blinkSupportedFlag = blinkSupportedFlag | kMbMenuGoForwardId | kMbMenuGoBackId | kMbMenuReloadId;
    CHECK(ThreadCall::isUiThread());
    if (!m_webview)
        return;

    if (!dispatchMbCallback(blinkSupportedFlag))
        return;

    const HWND hWnd = m_webview->getHostWnd();
    GdkWindow* gdkWindow = nullptr;
    if (!hWnd)
        return;
    
    HwndLinux* window = (HwndLinux*)hWnd;
    GtkWidget* windowWidget = window->getRootWindow();
    gdkWindow = gtk_widget_get_window(windowWidget);

    POINT screenPt = { 0 };
    ::GetCursorPos(&screenPt);
    POINT clientPt = screenPt;
    ::ScreenToClient(hWnd, &clientPt);

    // todo(mb): 后续可能要考虑缩放问题
    const GdkRectangle rect = { clientPt.x, clientPt.y, 1, 1 };

    GtkWidget* menu = createGTKmenu(blinkSupportedFlag);
    GdkEvent* triggerEvent = HwndLinux::getLastMousePressEvent();
    bool isEventNew = false;
    if (!triggerEvent) {
        isEventNew = true;
        GdkDisplay* display = gdk_display_get_default();
        GdkSeat* seat = gdk_display_get_default_seat(display);
        GdkDevice* pointer = gdk_seat_get_pointer(seat);
        GdkWindow* rootWin = gdk_display_get_default_group(display);
        gdkWindow = rootWin;

        triggerEvent = gdk_event_new(GDK_BUTTON_PRESS);
        triggerEvent->button.device = pointer; // 解决 GdkSeat 报错
        triggerEvent->button.window = rootWin;
        triggerEvent->button.button = 3; // 右键
        triggerEvent->button.x_root = clientPt.x;
        triggerEvent->button.y_root = clientPt.y;
    }

    gtk_menu_popup_at_rect(
        GTK_MENU(menu),
        gdkWindow,
        &rect,
        GDK_GRAVITY_SOUTH_WEST,
        GDK_GRAVITY_NORTH_WEST,
        triggerEvent);

    if (isEventNew)
        gdk_event_free(triggerEvent);
}

void ContextMenu::show(const blink::UntrustworthyContextMenuParams& data, int64_t frameId)
{
    if (!m_webview || !m_webview->isContextMenuEnable())
        return;

    if (data.has_image_contents) {
        m_imagePos = gfx::Point(data.x, data.y);
    }

    const UINT blinkSupportedFlag = calcBlinkSupportedFlag(data);
    bool expected = false;
    if (!m_isOpening.compare_exchange_strong(expected, true))
        return;

    m_data = data;
    m_frameId = frameId;

    asyncCallUiThread([this, blinkSupportedFlag] {
        showMenuOnUiThread(blinkSupportedFlag);
        m_isOpening.store(false, std::memory_order_release);
    });
}

}

#endif // OS_LINUX