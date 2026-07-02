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

#ifndef content_ui_ContextMeun_h
#define content_ui_ContextMeun_h

#include "content/browser/MbWebview.h"
#include "content/common/ThreadCall.h"
#include "third_party/blink/public/common/context_menu_data/untrustworthy_context_menu_params.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/renderer/core/exported/web_view_impl.h"
#include "third_party/blink/renderer/platform/wtf/threading_primitives.h"
#include <windows.h>
#if defined(OS_LINUX)
#include "base/memory/singleton.h"
#include "linux/linuxgdi.h"
#endif // OS_LINUX

namespace content {

extern uint32_t g_contextMenuItemMask;
extern /*constexpr*/ std::array<std::pair<int, const char*>, 12> kMenuItems;

#define kContextMenuClassName L"MbContextMenu"
//extern WebPageImpl* g_saveImageingWebPage;

// 本类是个单例，所有webview共用一个菜单
class ContextMenu {
public:
    ContextMenu();
    ~ContextMenu();

    static ContextMenu* get();

    void setCurrentWebview(MbWebView* webview) { m_webview = webview; }
    MbWebView* getCurrentWebview() const { return m_webview; }

    void initImpl();
    bool registerClass();

    void asyncCallUiThread(std::function<void()>&& func)
    {
        ThreadCall::callUiThreadAsync(MB_FROM_HERE, std::move(func));
    }

    void show(const blink::UntrustworthyContextMenuParams& data, int64_t frameId);
    static bool canShowItem(UINT actionFlags, mbMenuItemId id);

    void appendMenuText(UINT actionFlags);
    void appendMenuTextZhcn(UINT actionFlags);
    void appendMenuTextEn(UINT actionFlags);

    void onCommand(UINT itemID);

    static LRESULT CALLBACK wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

    void onPaint(HWND hWnd, HDC hdc);

    bool dispatchMbCallback(const UINT blinkSupportedFlag);
private:
    static void blinkContextMenuParamsConvert(const blink::UntrustworthyContextMenuParams& inParams, mbContextMenuParams* outParams);
    void executeMenuCommand(MbWebView* webview, UINT itemID);
    blink::UntrustworthyContextMenuParams m_data;

    gfx::Point m_imagePos;

#if defined(OS_WIN)
    HWND m_hWnd;
    HMENU m_popMenu;

    int m_lastX;
    int m_lastY;

    WTF::RecursiveMutex m_mutex;
#else
    static void onMenuItemClick(GtkWidget* widget, gpointer data);
    GtkWidget* createGTKmenu(int blinkSupportedFlag);

    std::atomic<bool> m_isOpening = false;
#endif // OS_WIN
    void showMenuOnUiThread(UINT blinkSupportedFlag);
    UINT calcBlinkSupportedFlag(const blink::UntrustworthyContextMenuParams& data);

    MbWebView* m_webview = nullptr;
    int64_t m_frameId;

    static ContextMenu* m_inst;
public:
    static volatile long m_isDestroyed;
};

} // content

#if 0 // defined(OS_LINUX)

typedef struct _GtkWidget GtkWidget;

namespace content {

// 目前就使用这种方式跨平台
class ContextMenu {
public:
    ContextMenu(const ContextMenu&) = delete;
    ContextMenu& operator=(const ContextMenu&) = delete;

    static ContextMenu* getInstance();

    static ContextMenu* get() 
    {
        return getInstance();
    }

    void setCurrentWebview(MbWebView* webview) { m_webview = webview; }

    MbWebView* getCurrentWebview() const { return m_webview; }

    void show(const blink::UntrustworthyContextMenuParams& data, int64_t frameId);

private:
    friend struct base::DefaultSingletonTraits<ContextMenu>;

    ContextMenu();
    ~ContextMenu() = default; // 目前的实现使用 gtk 窗口的 menu 组件, 不持有资源

    static void onMenuItemClick(GtkWidget* widget, gpointer data);
    GtkWidget* createGTKmenu(int blinkSupportedFlag);
    void showMenuOnUiThread(int blinkSupportedFlag);

    MbWebView* m_webview = nullptr;
    blink::UntrustworthyContextMenuParams m_data;
    int64_t m_frameId = 0;
    std::atomic<bool> m_isOpening = false;

    GtkWidget* m_windowlessBgWidget = nullptr;
};

}
#endif // OS_LINUX

#endif // content_browser_ContextMeun_h