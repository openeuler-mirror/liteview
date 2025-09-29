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

namespace content {
uint32_t g_contextMenuItemMask = kMbMenuSelectedTextId | kMbMenuPasteId;
}

namespace {
using content::ContextMenu;
using content::ThreadCall;

struct CallbackContext {
    ContextMenu* instance;
    int action;
};

constexpr std::array<std::pair<int, const char*>, 2> k_menuItems = {
    { { kMbMenuSelectedTextId, "复制" }, { kMbMenuPasteId, "粘贴" } }
};

void asyncCallUiThread(std::function<void()>&& func)
{
    ThreadCall::callUiThreadAsync(MB_FROM_HERE, std::move(func));
}

int calcBlinkSupportedFlag(const blink::UntrustworthyContextMenuParams& data)
{
    int flag = 0;
    if ((!data.selection_text.empty())) {
        flag |= kMbMenuSelectedTextId;
    }

    if (data.is_editable) {
        flag |= kMbMenuPasteId;
    }

    return flag;
}

bool canShowItem(int blinkSupportedFlag, int id)
{
    return (blinkSupportedFlag & id) && (content::g_contextMenuItemMask & id);
}
}

namespace content {

void clearMbWebViewInContextMenuIfNeeded(MbWebView* webview)
{
    if (ContextMenu::get()->getCurrentWebview() == webview) {
        ContextMenu::get()->setCurrentWebview(nullptr);
    }
}

ContextMenu* ContextMenu::getInstance()
{
    return base::Singleton<ContextMenu>::get();
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

    for (const auto& [id, label] : k_menuItems) {
        if (!canShowItem(blinkSupportedFlag, id)) {
            continue;
        }

        GtkWidget* item = gtk_menu_item_new_with_label(label);
        const CallbackContext* ctx = new CallbackContext { this, id };
        g_signal_connect(item, "activate", G_CALLBACK(onMenuItemClick), (gpointer)ctx);
        gtk_menu_shell_append(GTK_MENU_SHELL(menu), item);
    }

    gtk_widget_show_all(menu);
    return menu;
}

void ContextMenu::showMenuOnUiThread(int blinkSupportedFlag)
{
    CHECK(ThreadCall::isUiThread());

    const HWND hWnd = m_webview->getHostWnd();
    HwndLinux* window = (HwndLinux*)hWnd;
    GtkWidget* windowWidget = window->getRootWindow();
    GdkWindow* gdkWindow = gtk_widget_get_window(windowWidget);

    POINT screenPt = { 0 };
    ::GetCursorPos(&screenPt);
    POINT clientPt = screenPt;
    ::ScreenToClient(hWnd, &clientPt);

    // todo(mb): 后续可能要考虑缩放问题
    const GdkRectangle rect = { clientPt.x, clientPt.y, 1, 1 };

    GtkWidget* menu = createGTKmenu(blinkSupportedFlag);

    gtk_menu_popup_at_rect(
        GTK_MENU(menu),
        gdkWindow,
        &rect,
        GDK_GRAVITY_SOUTH_WEST,
        GDK_GRAVITY_NORTH_WEST,
        window->getLastMousePressEvent());
}

void ContextMenu::show(const blink::UntrustworthyContextMenuParams& data, int64_t frameId)
{
    if (!m_webview || !m_webview->isContextMenuEnable())
        return;

    const int blinkSupportedFlag = calcBlinkSupportedFlag(data);

    if (0 == blinkSupportedFlag)
        return;

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