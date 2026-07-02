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


#if defined(OS_LINUX) && !defined(OS_OHOS)
#include "linux/linuxgdi.h"
#include "linux/linuxgl.h"
#include "linux/shadergl.h"
#include "base/cancelable_callback.h"
#include "content/common/StringUtil.h"
#include "content/common/ThreadCall.h"
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <sys/types.h>
#include <unistd.h>
#include <gtk/gtk.h>
#include <gdk/gdkkeysyms-compat.h>
#include <gtk/gtkglarea.h>
#include <map>
#include <malloc.h>

namespace {

gboolean onFocusIn(GtkWidget* widget, GdkEventFocus* event, gpointer data) 
{
    HwndLinux* self = (HwndLinux*)data;
    gtk_im_context_focus_in(self->m_imContext);
    return FALSE;
}

gboolean onPreeditStart(GtkWidget* widget, GdkEventFocus* event, gpointer data) 
{
    HwndLinux* self = (HwndLinux*)data;
    self->m_wndProc(self, WM_IME_STARTCOMPOSITION, 0, 0);
    return FALSE;
}

gboolean onImCommit(GtkWidget* widget, const gchar* str, gpointer data) 
{
    HwndLinux* self = (HwndLinux*)data;
    std::u16string u16Str = content::utf8ToUtf16(str);
    // todo(mb): 这里可能有 code point 问题, 比如 emoji? 不过 win 版也是这么做的
    for (char16_t ch : u16Str) {
        self->m_wndProc(self, WM_IME_CHAR, (WPARAM)ch, 0);
    }
    return FALSE;
}

gboolean onFocusOut(GtkWidget* widget, GdkEventFocus* event, gpointer data) 
{
    HwndLinux* self = (HwndLinux*)data;
    if (self->m_imContext)
        gtk_im_context_focus_out(self->m_imContext);
    return FALSE;
}

void onWindowMap(GtkWidget* widget, gpointer user_data)
{
    gint x = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(widget), "win_x"));
    gint y = GPOINTER_TO_INT(g_object_get_data(G_OBJECT(widget), "win_y"));

    gtk_window_move(GTK_WINDOW(widget), x, y);
}

class WindowMemoryShaper {
public:
    static WindowMemoryShaper* getInstance()
    {
        static WindowMemoryShaper* instance = new WindowMemoryShaper();
        return instance;
    }

    void requestTrim()
    {
        CHECK(content::ThreadCall::isUiThread());

        m_trimClosure.Cancel();
        m_trimClosure.Reset(base::BindOnce(&WindowMemoryShaper::scheduleIdleTrim, base::Unretained(this)));

        base::SingleThreadTaskRunner::GetCurrentDefault()->PostDelayedTask(
            FROM_HERE, 
            m_trimClosure.callback(), 
            base::Seconds(5));
    }

private:
    WindowMemoryShaper() = default;

    static gboolean runStaticTrim(gpointer data) {
        malloc_trim(0);
        return G_SOURCE_REMOVE; 
    }

    void scheduleIdleTrim() {
        g_idle_add(runStaticTrim, nullptr);
    }

    base::CancelableOnceClosure m_trimClosure;
};

void onGlAreaDestroy(GtkWidget* widget, gpointer data)
{
    WindowMemoryShaper::getInstance()->requestTrim();
}

}

std::map<int, WNDCLASSEXW*>* HwndLinux::s_wndClassMap = nullptr;
std::set<HWND>* HwndLinux::s_hwnds = nullptr;
pthread_mutex_t HwndLinux::s_hwndMutex;
GdkEvent* HwndLinux::s_lastMousePressEvent = nullptr;

class CrossThreadUiState {
public:
    POINT m_cursorPos;

    static CrossThreadUiState* get()
    {
        if (!m_inst)
            m_inst = new CrossThreadUiState();
        return m_inst;
    }

    CrossThreadUiState()
    {
        m_isCapsLock = false;
        m_isNumLock = false;
        m_isScrollLock = false;
        m_isShift = false;
        m_isCtrl = false;
        m_isAtl = false;
        m_cursorPos.x = 0;
        m_cursorPos.y = 0;
        pthread_mutex_init(&m_mutex, nullptr);
    }

    ~CrossThreadUiState()
    {
        pthread_mutex_destroy(&m_mutex);
    }

    void setCtrl(bool b) { m_isCtrl = b; }

    void setGdkEventButton(GdkEventButton* evt)
    {
        m_gdkEventButton = evt;
    }

    GdkEventButton* getGdkEventButton() const { return m_gdkEventButton; }

    void updata(const guint* state)
    {
        GdkDisplay* display = gdk_display_get_default();
        GdkSeat* deviceManager = gdk_display_get_default_seat(display);
        GdkDevice* device = gdk_seat_get_pointer(deviceManager);

        GdkKeymap* keymap = gdk_keymap_get_for_display(display);
        gboolean isCapsLock = gdk_keymap_get_caps_lock_state(keymap);
        gboolean isNumLock = gdk_keymap_get_num_lock_state(keymap);
        gboolean isScrollLock = gdk_keymap_get_scroll_lock_state(keymap);

        pthread_mutex_lock(&m_mutex);

        gdk_device_get_position(device, NULL, &m_cursorPos.x, &m_cursorPos.y);// 获取指针在屏幕上的绝对坐标

        bool isShift = false;
        bool isCtrl = false;
        bool isAtl = false;

        if (state) {
            isShift = !!(*state & GDK_SHIFT_MASK);
            isCtrl = !!(*state & GDK_CONTROL_MASK);
            isAtl = !!(*state & GDK_MOD1_MASK);
        }
//         GdkModifierType type = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_SHIFT_GROUP);
//         if (type & GDK_SHIFT_MASK)
//             isShift = true;
// 
//         type = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_DEFAULT_MOD_MASK);
//         if (type & GDK_CONTROL_MASK)
//             isCtrl = true;
// 
//         type = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_CONTEXT_MENU);
//         if (type & GDK_MOD1_MASK)
//             isAtl = true;

        if (isCtrl)
            printf("isCtrl !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");

        m_isCapsLock = isCapsLock;
        m_isNumLock = isNumLock;
        m_isScrollLock = isScrollLock;
        m_isShift = isShift;
        //m_isCtrl = isCtrl;
        m_isAtl = isAtl;

        pthread_mutex_unlock(&m_mutex);
    }

    void getState(bool* isCapsLock, bool* isNumLock, bool* isScrollLock, bool* isShift, bool* isCtrl, bool* isAtl)
    {
        pthread_mutex_lock(&m_mutex);
        if (isCapsLock)
            *isCapsLock = m_isCapsLock;
        if (isNumLock)
            *isNumLock = m_isNumLock;
        if (isScrollLock)
            *isScrollLock = m_isScrollLock;
        if (isShift)
            *isShift = m_isShift;
        if (isCtrl)
            *isCtrl = m_isCtrl;
        if (isAtl)
            *isAtl = m_isAtl;
        pthread_mutex_unlock(&m_mutex);
    }

private:
    bool m_isCapsLock;
    bool m_isNumLock;
    bool m_isScrollLock;
    bool m_isShift;
    bool m_isCtrl;
    bool m_isAtl;

    GdkEventButton* m_gdkEventButton = nullptr;

    pthread_mutex_t m_mutex;
    static CrossThreadUiState* m_inst;
};

void CrossThreadUiStateUpdata()
{
    CrossThreadUiState::get()->updata(nullptr);
}

CrossThreadUiState* CrossThreadUiState::m_inst = nullptr;

HwndLinux::HwndLinux()
{
    m_window = nullptr;
    m_drawingArea = nullptr;
    m_wndProc = nullptr;
    m_userdata = nullptr;
    m_surface = nullptr;
    m_style = 0;
    m_styleex = 0;
    m_rootX = 0;
    m_rootY = 0;
    m_isDestroying = false;
    m_threadId = ::GetCurrentThreadId();

    CrossThreadUiState::get()->updata(nullptr);

    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&m_propsMutex, &attr);
    pthread_mutex_init(&m_damageRectLock, &attr);
}

HwndLinux::~HwndLinux()
{
    if (m_glShader)
        delete m_glShader;
    pthread_mutex_destroy(&m_propsMutex);
    pthread_mutex_destroy(&m_damageRectLock);

    g_object_unref(m_imContext);
    m_imContext = NULL;
}

void HwndLinux::updataPosOnScreen()
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    gtk_window_get_position(GTK_WINDOW(m_window), &m_rootX, &m_rootY);
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
}

static gboolean testDraw(cairo_t* cr)
{
    //     int width, height;
    //     gtk_window_get_size(GTK_WINDOW(widget), &width, &height);

    cairo_set_source_rgb(cr, 0.3, 0.5, 1);
    cairo_rectangle(cr, 20.0, 20.0, 100.0, 100.0);
    cairo_fill(cr);
// 
//     cairo_set_source_rgb(cr, 0.6, 0.6, 0.6);
//     cairo_rectangle(cr, 150, 20, 100, 100);
//     cairo_fill(cr);
// 
//     cairo_set_source_rgb(cr, 0, 0.3, 0);
//     cairo_rectangle(cr, 20, 140, 100, 100);
//     cairo_fill(cr);
// 
//     cairo_set_source_rgb(cr, 1, 0, 0.5);
//     cairo_rectangle(cr, 150, 140, 100, 100);
//     cairo_fill(cr);

    return FALSE;
}

gboolean HwndLinux::onDraw(GtkWidget* widget, cairo_t* cr, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    if (!IsWindow((HWND)self))
        return TRUE;
    CrossThreadUiState::get()->updata(nullptr);

    int width = gtk_widget_get_allocated_width(widget);
    int height = gtk_widget_get_allocated_height(widget);

    self->m_wndProc(self, WM_SIZE, 0, MAKELPARAM(width, height));
    
    PAINTSTRUCT paintStrct = { 0 };
    paintStrct.hdc = (HDC)cr;
    paintStrct.fErase = TRUE;
    paintStrct.rcPaint.left = 0;
    paintStrct.rcPaint.top = 0;
    paintStrct.rcPaint.right = width;
    paintStrct.rcPaint.bottom = height;
    paintStrct.fRestore = FALSE;
    paintStrct.fIncUpdate = FALSE;

    self->m_msgPtr = &paintStrct;
    self->m_wndProc(self, WM_PAINT, (WPARAM)cr, 0); // -> MbWebView::onPaint
    self->m_msgPtr = nullptr;

//     static cairo_surface_t* g_surface = nullptr;
//     if (!g_surface)
//         g_surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 800, 600);
//     if (g_test_surface) {
//         printf("HwndLinux::onDraw 1\n");
//         cairo_t* memoryCr = cairo_create(g_test_surface);
// 
//         testDraw(memoryCr);
//         cairo_destroy(memoryCr);
// 
//         cairo_set_source_surface(cr, g_test_surface, 0, 0);
//     } else
//         printf("HwndLinux::onDraw 2\n");

    cairo_paint(cr);

    return FALSE;
}

// 先调用onDeleteEvent再onDestroy
gboolean HwndLinux::onDeleteEvent(GtkWidget* widget, GdkEvent* event, gpointer data)
{
    char output[100] = { 0 };
    sprintf(output, "HwndLinux::onDeleteEvent:%p\n", data);
    OutputDebugStringA(output);

    HwndLinux* self = (HwndLinux*)data;
    self->m_wndProc(self, WM_CLOSE, 0, 0);
    if (!self->m_isDestroying)
        return TRUE;
    return FALSE;
}

void HwndLinux::onDestroy(GtkWidget* widget, gpointer data)
{
    char output[100] = { 0 };
    sprintf(output, "HwndLinux::onDestroy:%p\n", data);
    OutputDebugStringA(output);

    HwndLinux* self = (HwndLinux*)data;
    if (!IsWindow((HWND)self))
        return;
    self->m_wndProc(self, WM_NCDESTROY, 0, 0);
    HwndLinux::destroy(self->m_hWnd, true);
}

gboolean HwndLinux::onConfigureEvent(GtkWidget* widget, GdkEventConfigure* evt, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    if (!IsWindow((HWND)self))
        return TRUE;
    //char output[100] = { 0 };
    //sprintf(output, "onConfigureEvent:%d, %d, %d\n", evt->type, evt->width, evt->height);
    //OutputDebugStringA(output);

    //         if (self->m_surface)
    //             cairo_surface_destroy(self->m_surface);
    // 
    //         self->m_surface = gdk_window_create_similar_surface(
    //             gtk_widget_get_window(widget),
    //             CAIRO_CONTENT_COLOR,
    //             gtk_widget_get_allocated_width(widget),
    //             gtk_widget_get_allocated_height(widget));
    // 
    //         /* Initialize the surface to white */
    //         self->clearSurface();
    return FALSE;
   
    //return TRUE; /* We've handled the configure event, no need for further processing. */
}

void HwndLinux::clearSurface(void)
{
    cairo_t* cr;
    cr = cairo_create(m_surface);
    cairo_set_source_rgb(cr, 1, 1, 1);
    cairo_paint(cr);
    cairo_destroy(cr);
}

static bool onBeginResizeDrag(HwndLinux* self, GdkEventButton* btnEvt, GdkEventMotion* motionEvt)
{
    if (!(self->m_style & WS_CAPTION)) // 如果不是无边框模式就不管了，让gtk自己去处理resize drag
        return false;

    POINT pt = { 0 };
    if (btnEvt)
        pt = { (int)btnEvt->x, (int)btnEvt->y };
    else
        pt = { (int)motionEvt->x, (int)motionEvt->y };
    ClientToScreen(self, &pt);
    LPARAM lParam = MAKELPARAM(pt.x, pt.y);

    LRESULT r = self->m_wndProc(self, WM_NCHITTEST, 0, lParam);

    GdkWindowEdge edge = (GdkWindowEdge)(-1);
    const char* name = nullptr;
    if (HTLEFT == r) {
        edge = GDK_WINDOW_EDGE_WEST;
        name = "w-resize";
    } else if (HTRIGHT == r) {
        edge = GDK_WINDOW_EDGE_EAST;
        name = "e-resize";
    } else if (HTTOP == r) {
        edge = GDK_WINDOW_EDGE_NORTH;
        name = "n-resize";
    } else if (HTBOTTOM == r) {
        edge = GDK_WINDOW_EDGE_SOUTH;
        name = "s-resize";
    } else if (HTTOPLEFT == r) {
        edge = GDK_WINDOW_EDGE_NORTH_WEST;
        name = "nw-resize";
    } else if (HTTOPRIGHT == r) {
        edge = GDK_WINDOW_EDGE_NORTH_EAST;
        name = "ne-resize";
    } else if (HTBOTTOMLEFT == r) {
        edge = GDK_WINDOW_EDGE_SOUTH_WEST;
        name = "sw-resize";
    } else if (HTBOTTOMRIGHT == r) {
        edge = GDK_WINDOW_EDGE_SOUTH_EAST;
        name = "se-resize";
    }

    if ((GdkWindowEdge)(-1) != edge) {
        if (motionEvt) {
            GdkCursor* cursor = gdk_cursor_new_from_name(gdk_display_get_default(), name);
            GdkWindow* window = gtk_widget_get_window(self->m_window);
            gdk_window_set_cursor(window, cursor);
            g_object_unref(cursor);
        }

        if (btnEvt)
            gtk_window_begin_resize_drag(GTK_WINDOW(self->m_window), edge, btnEvt->button, btnEvt->x_root, btnEvt->y_root, btnEvt->time);
        return true;
    }
    return false;
}

// 鼠标move事件
gboolean HwndLinux::onMotionNotifyEvent(GtkWidget* widget, GdkEventMotion* evt, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    if (!IsWindow((HWND)self))
        return TRUE;
    self->updataPosOnScreen();
    CrossThreadUiState::get()->updata(&evt->state);

    if (onBeginResizeDrag(self, nullptr, evt)) // 先确定是不是非客户区
        return FALSE;

    LPARAM lParam = MAKELPARAM((int)evt->x, (int)evt->y);
    WPARAM wParam = 0;

    if (evt->state & GDK_BUTTON1_MASK)
        wParam |= MK_LBUTTON;

    if (evt->state & GDK_BUTTON2_MASK)
        wParam |= MK_MBUTTON;

    if (evt->state & GDK_BUTTON3_MASK)
        wParam |= MK_RBUTTON;

    self->m_wndProc(self, WM_MOUSEMOVE, wParam, lParam);
    self->m_wndProc(self, WM_SETCURSOR, 0, 0);

    /* We've handled it, stop processing */
    return TRUE;
}

gboolean HwndLinux::onButtonReleaseEvent(GtkWidget* widget, GdkEventButton* event, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    if (!IsWindow((HWND)self))
        return TRUE;

    setLastMousePressEvent(nullptr);

    self->updataPosOnScreen();
    CrossThreadUiState::get()->updata(&event->state);

    LPARAM lParam = MAKELPARAM((int)event->x, (int)event->y);

    if (event->button == GDK_BUTTON_PRIMARY) { // 左键
        printf("onButtonReleaseEvent, GDK_BUTTON_PRIMARY\n");
        self->m_wndProc(self, WM_LBUTTONUP, 0, lParam);
    } else if (event->button == GDK_BUTTON_SECONDARY) { // 右键
        printf("onButtonReleaseEvent, GDK_BUTTON_SECONDARY\n");
        self->m_wndProc(self, WM_RBUTTONUP, 0, lParam);
    }

    return TRUE;
}

BOOL PostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    HwndLinux* self = (HwndLinux*)hWnd;

    if (Msg == WM_SYSCOMMAND && wParam == SC_MOVE | HTCAPTION) {
        GdkEventButton* evt = CrossThreadUiState::get()->getGdkEventButton();
        if (evt)
            gtk_window_begin_move_drag(GTK_WINDOW(self->m_window), evt->button, evt->x_root, evt->y_root, evt->time);
        return TRUE;
    }
    return FALSE;
}

gboolean HwndLinux::onButtonPressEvent(GtkWidget* widget, GdkEventButton* evt, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    if (!IsWindow((HWND)self))
        return TRUE;

    setLastMousePressEvent((GdkEvent*)evt);

    gtk_widget_grab_focus(widget);
    self->updataPosOnScreen();
    CrossThreadUiState::get()->updata(&evt->state);
    CrossThreadUiState::get()->setGdkEventButton(evt);

    LPARAM lParam = MAKELPARAM((int)evt->x, (int)evt->y);
    if (evt->button == GDK_BUTTON_PRIMARY) { // 左键按下
        if (onBeginResizeDrag(self, evt, nullptr))
            return FALSE;
        self->m_wndProc(self, WM_LBUTTONDOWN, 0, lParam);
    } else if (evt->button == GDK_BUTTON_SECONDARY) { // 右键按下
        OutputDebugStringA("onButtonPressEvent, GDK_BUTTON_SECONDARY\n");
        self->m_wndProc(self, WM_RBUTTONDOWN, 0, lParam);
    }
    CrossThreadUiState::get()->setGdkEventButton(nullptr);

    return FALSE; // We've handled the evt, stop processing
}

gboolean HwndLinux::onKeyRelease(GtkWidget* widget, GdkEventKey* evt, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    if (!IsWindow((HWND)self))
        return TRUE;
    int key = evt->keyval;
    printf("onKeyRelease, keyval = %x\n", key);

    switch (key) {
    case GDK_KEY_Control_L:
        CrossThreadUiState::get()->setCtrl(false);
    }

    if ((evt->state & GDK_CONTROL_MASK)) {
        CrossThreadUiState::get()->setCtrl(false);
    }

    self->m_wndProc(self, WM_KEYUP, (WPARAM)key, 0);

    return FALSE;
}

gboolean HwndLinux::onFocusOut(GtkWidget *widget, GdkEventFocus *event, gpointer data)
{
    HwndLinux *self = (HwndLinux *)data;
    if (!IsWindow((HWND)self))
        return TRUE;
    self->m_wndProc(self, WM_KILLFOCUS, 0, 0);
    return TRUE;
}

gboolean HwndLinux::onScroll(GtkWidget* widget, GdkEventScroll* event, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    if (!IsWindow((HWND)self))
        return TRUE;
    self->updataPosOnScreen();
    CrossThreadUiState::get()->updata(&event->state);

    WPARAM wParam = 0;
    LPARAM lParam = 0;

    int flags = 0;
    if (event->state & GDK_SHIFT_MASK)
        flags |= MK_SHIFT;
    if (event->state & GDK_CONTROL_MASK)
        flags |= MK_CONTROL;
    if (event->state & GDK_BUTTON1_MASK)
        flags |= MK_LBUTTON;
    if (event->state & GDK_BUTTON2_MASK)
        flags |= MK_MBUTTON;
    if (event->state & GDK_BUTTON3_MASK)
        flags |= MK_RBUTTON;
    if (event->state & GDK_MOD1_MASK)
        printf("alt is press\n");
    else
        printf("alt is not press\n");

    int delta = 0;

    if (event->direction == GDK_SCROLL_UP) { // 滑轮上滑
        delta = 120;
    } else if (event->direction == GDK_SCROLL_DOWN) { // 滑轮下滑
        delta = -120;
    }

    bool isCapsLock = false;
    bool isNumLock = false;
    bool isScrollLock = false;
    bool isShift = false;
    bool isCtrl = false;
    bool isAtl = false;
    CrossThreadUiState::get()->getState(&isCapsLock, &isNumLock, &isScrollLock, &isShift, &isCtrl, &isAtl);

    // ctrl: 14, atl:18, shift:11, none:10

    GdkDisplay* display = gdk_display_get_default();
    GdkKeymap* keymap = gdk_keymap_get_for_display(display);
    GdkModifierType type1 = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_DEFAULT_MOD_MASK);
    GdkModifierType type2 = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_PRIMARY_ACCELERATOR);
    GdkModifierType type3 = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_CONTEXT_MENU);
    GdkModifierType type4 = gdk_keymap_get_modifier_mask(keymap, GDK_MODIFIER_INTENT_MODIFY_SELECTION);

//     printf("type1:%d, type2:%d, type3:%d, type4:%d, state:%d, isCtrl: %d, flags:%d\n", 
//         type1, type2, type3, type4, event->state, isCtrl, flags);

    if (isCtrl)
      flags |= MK_CONTROL;

    wParam = MAKEWPARAM(flags, delta);
    lParam = MAKELPARAM(((int)event->x), ((int)event->y));

    self->m_wndProc(self, WM_MOUSEWHEEL, wParam, lParam);
    return FALSE;
}

//////////////////////////////////////////////////////////////////////////

cairo_surface_t* LinuxGdiCreateSurfaceByHwnd(HWND hWnd, int w, int h)
{
    HwndLinux* self = (HwndLinux*)hWnd;
    //GdkWindow* window = gtk_widget_get_window(self->m_drawingArea);
    //cairo_surface_t* surface = gdk_window_create_similar_surface(window, CAIRO_CONTENT_COLOR, w, h);
    cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, w, h);
    unsigned char* byteData = cairo_image_surface_get_data(surface);
    return surface;
}

//////////////////////////////////////////////////////////////////////////

LONG SetWindowLongW(HWND hWnd, int nIndex, LONG dwNewLong)
{
    if (GWLP_USERDATA == nIndex) {
        HwndLinux* self = (HwndLinux*)hWnd;
        //self->m_wndProc;
        self->m_userdata = (LPVOID)dwNewLong;
    } else {
        printf("SetWindowLongW\n");
    }
    return 0;
}

LONG GetWindowLongW(HWND hWnd, int nIndex)
{
    HwndLinux* self = (HwndLinux*)hWnd;
    if (!self)
        return 0;

    if (GWL_EXSTYLE == nIndex)
        return self->m_styleex & (~((DWORD)WS_EX_LAYERED)); // linux没有分层窗口
    else if (GWL_STYLE == nIndex)
        return self->m_style;
    else
        printf("GetWindowLongW fail\n");

    return 0;
}

BOOL SetPropW(HWND hWnd, LPCWSTR lpString, HANDLE hData)
{
    if (!lpString)
        return FALSE;

    unsigned int hash = content::hashStringW(lpString);
    HwndLinux* self = (HwndLinux*)hWnd;
    pthread_mutex_lock(&self->m_propsMutex);
    
    std::map<unsigned int, void *>::iterator it = self->m_props.find(hash);
    if (it != self->m_props.end()) {
        it->second = hData;
    } else {
        self->m_props.insert(std::pair<unsigned int, void *>(hash, hData));
    }
    pthread_mutex_unlock(&self->m_propsMutex);

    return TRUE;
}

HANDLE RemovePropW(HWND hWnd, LPCWSTR lpString)
{
    if (!lpString)
        return NULL;

    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux* self = (HwndLinux*)hWnd;
    if (HwndLinux::s_hwnds->find(hWnd) == HwndLinux::s_hwnds->end()) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return NULL;
    }
    
    unsigned int hash = content::hashStringW(lpString);
    HANDLE hData = NULL;
    pthread_mutex_lock(&self->m_propsMutex);

    std::map<unsigned int, void*>::iterator it = self->m_props.find(hash);
    if (it != self->m_props.end()) {
        hData = it->second;
        self->m_props.erase(it);
    }
    pthread_mutex_unlock(&self->m_propsMutex);
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return hData;
}

HANDLE GetPropW(HWND hWnd, LPCWSTR lpString)
{
    HANDLE ret = nullptr;
    unsigned int hash = content::hashStringW(lpString);
    HwndLinux* self = (HwndLinux*)hWnd;

    pthread_mutex_lock(&self->m_propsMutex);
    std::map<unsigned int, void*>::iterator it = self->m_props.find(hash);
    if (it != self->m_props.end())
        ret = it->second;    
    pthread_mutex_unlock(&self->m_propsMutex);

    return ret;
}

LRESULT DefWindowProcW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

BOOL g_isLinuxOpenglDraw = TRUE;

void SetLinuxOpenglDraw(BOOL b)
{
    g_isLinuxOpenglDraw = b;
}

BOOL IsLinuxOpenglDraw()
{
    return g_isLinuxOpenglDraw;
}

gboolean onRenderGlTextures(GtkGLArea* area, GdkGLContext* context, gpointer data);
void onRealizeGlTextures(GtkWidget* widget, gpointer data);
void onUnrealizeGlTextures(GtkWidget* widget, gpointer data);

// void on_size_changed(GtkWindow* window, gpointer data) 
// {
//     gint width = 0;
//     gint height = 0;
//     gtk_widget_get_size_request((GTK_WIDGET(window)), &width, &height);
// 
//     printf("on_size_changed: %d, %d\n", width, height);
// }
// 
// gboolean widget_size_allocate_cb(GtkWidget* widget, GtkAllocation* allocation, gpointer user_data)
// {
//     gint width = 0, height = 0;
// 
//     if (width > 0 && height > 0 && (allocation->width - width || allocation->height - height)) {
//         // g_printf("size changed:width-%d :height- %d: ", width, height);
//         width = allocation->width;
//         height = allocation->height;
//         // 在此，做一些操作...
//     }
//     if (G_UNLIKELY(width == 0 && height == 0)) {
//         width = allocation->width;
//         height = allocation->height;
//     }
// 
//     printf("widget_size_allocate_cb: %d, %d\n", width, height);
//     return FALSE;
// }

int drawBoxMain();

void gtkMessageBox(const char* txt);
void gtkSimpleWin();

void initLinuxGdi()
{
    if (!HwndLinux::s_hwnds)
        HwndLinux::s_hwnds = new std::set<HWND>();
}

HWND CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
    char output[100] = { 0 };
    sprintf(output, "CreateWindowExW s_hwnds:%p\n", HwndLinux::s_hwnds);
    OutputDebugStringA(output);

    if (!HwndLinux::s_hwnds) {
        HwndLinux::s_hwnds = new std::set<HWND>();
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&HwndLinux::s_hwndMutex, &attr);
    }

    //drawBoxMain();

    if ((dwStyle & WS_CHILD) != 0)
        DebugBreak();

    if (nWidth == -1)
        nWidth = 800;
    if (nHeight == -1)
        nHeight = 600;

    HwndLinux* self = new HwndLinux();
    self->m_autoHandleClose = true;
    self->m_hWnd = self;
    self->m_userdata = lpParam;

    self->m_style = dwStyle;
    self->m_styleex = dwExStyle;

    unsigned int hash = content::hashStringW(lpClassName);
    std::map<int, WNDCLASSEXW *>::iterator it = HwndLinux::s_wndClassMap->find(hash);
    if (it == HwndLinux::s_wndClassMap->end())
        DebugBreak();
    self->m_wndProc = it->second->lpfnWndProc;

    GtkWidget* windowWidget = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWindow* window = GTK_WINDOW(windowWidget);

    if (!(dwStyle & WS_CAPTION))
        gtk_window_set_decorated(window, FALSE);

    self->m_window = windowWidget;

    gtk_window_set_title(window, "Drawing Area");
    printf("gtk_window_set_title:: %p\n", window);

    gtk_window_set_default_size(window, nWidth, nHeight);
    const int kBorderWidth = 0;
    gtk_container_set_border_width(GTK_CONTAINER(windowWidget), kBorderWidth);

    GtkWidget* msgGtkWidget = NULL;
    if (!g_isLinuxOpenglDraw) {
        // 画个框子
        GtkWidget* frame = gtk_frame_new(NULL);
        gtk_frame_set_shadow_type(GTK_FRAME(frame), GTK_SHADOW_IN);
        gtk_container_add(GTK_CONTAINER(windowWidget), frame);

        GtkWidget* drawingArea = gtk_drawing_area_new();
        gtk_widget_set_size_request(drawingArea, nWidth, nHeight);
        gtk_container_add(GTK_CONTAINER(frame), drawingArea);

        g_signal_connect(drawingArea, "draw", G_CALLBACK(&HwndLinux::onDraw), self);

        //Ask to receive events the drawing area doesn't normally subscribe to. In particular, 
        //we need to ask for the button press and motion notify events that want to handle.
        gtk_widget_set_events(drawingArea, gtk_widget_get_events(drawingArea) | GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK | GDK_BUTTON_RELEASE_MASK | GDK_SCROLL_MASK);
        self->m_drawingArea = drawingArea;

        msgGtkWidget = drawingArea;
    } else {
        gtk_container_set_border_width(GTK_CONTAINER(window), kBorderWidth);
        GtkWidget* box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);

        g_object_set(box, "margin", 2, NULL);
        gtk_box_set_spacing(GTK_BOX(box), 2);
        gtk_container_add(GTK_CONTAINER(window), box);

        self->m_glArea = gtk_gl_area_new();
        gtk_box_pack_start(GTK_BOX(box), self->m_glArea, TRUE, TRUE, 0);

        gtk_widget_set_events(self->m_glArea, gtk_widget_get_events(self->m_glArea) | GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK | GDK_BUTTON_RELEASE_MASK | GDK_SCROLL_MASK);
        g_signal_connect(self->m_glArea, "realize", G_CALLBACK(onRealizeGlTextures), self);
        g_signal_connect(self->m_glArea, "render", G_CALLBACK(onRenderGlTextures), self);
        g_signal_connect(self->m_glArea, "unrealize", G_CALLBACK(onUnrealizeGlTextures), self);
        g_signal_connect(self->m_glArea, "destroy", G_CALLBACK(onGlAreaDestroy), NULL);

        msgGtkWidget = windowWidget;
    }

    // 将坐标数据挂在 window 上
    g_object_set_data(G_OBJECT(window), "win_x", GINT_TO_POINTER(X));
    g_object_set_data(G_OBJECT(window), "win_y", GINT_TO_POINTER(Y));

    g_signal_connect(window, "map", G_CALLBACK(onWindowMap), NULL);

    g_signal_connect(msgGtkWidget, "configure-event", G_CALLBACK(&HwndLinux::onConfigureEvent), self);
    g_signal_connect(msgGtkWidget, "motion-notify-event", G_CALLBACK(&HwndLinux::onMotionNotifyEvent), self);
    g_signal_connect(msgGtkWidget, "button-press-event", G_CALLBACK(&HwndLinux::onButtonPressEvent), self);
    g_signal_connect(msgGtkWidget, "button-release-event", G_CALLBACK(&HwndLinux::onButtonReleaseEvent), self);
    g_signal_connect(msgGtkWidget, "scroll-event", G_CALLBACK(&HwndLinux::onScroll), self);

    self->m_imContext = gtk_im_multicontext_new();

    g_signal_connect(self->m_imContext, "preedit-start", G_CALLBACK(onPreeditStart), self);
    g_signal_connect(self->m_imContext, "commit", G_CALLBACK(onImCommit), self);
    g_signal_connect(window, "focus-in-event", G_CALLBACK(onFocusIn), self);
    g_signal_connect(window, "focus-out-event", G_CALLBACK(onFocusOut), self);

    g_signal_connect(window, "destroy", G_CALLBACK(&HwndLinux::onDestroy), self);
    g_signal_connect(window, "delete-event", G_CALLBACK(&HwndLinux::onDeleteEvent), self);
    g_signal_connect(window, "key-press-event", G_CALLBACK(&HwndLinux::onKeyPress), self);
    g_signal_connect(window, "key-release-event", G_CALLBACK(&HwndLinux::onKeyRelease), self);

    CREATESTRUCTW createStruct = { 0 };
    createStruct.lpCreateParams = lpParam;
    self->m_wndProc(self, WM_CREATE, 0, (LPARAM)&createStruct);
   
    sprintf(output, "CreateWindowExW::::2 %d, %d, msgGtkWidget:%p\n", nWidth, nHeight, msgGtkWidget);
    OutputDebugStringA(output);

    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux::s_hwnds->insert(self); // TODO: delete
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    //gtkMessageBox("const char* txt");

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self] {
        //gtkSimpleWin();
        self->m_wndProc(self, WM_SIZE, 0, 0); // -> MbWebView::onResize
        gtk_widget_show_all(self->m_window);
    });
    return self;
}

HWND LinuxGdiBindWindowByGtk(void* rootWindow, void* drawingArea, BOOL isGl, DWORD dwExStyle, LPCWSTR lpClassName, DWORD dwStyle, int nWidth, int nHeight, LPVOID lpParam)
{
    SetLinuxOpenglDraw(isGl);

    if (!HwndLinux::s_hwnds) {
        HwndLinux::s_hwnds = new std::set<HWND>();
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&HwndLinux::s_hwndMutex, &attr);
    }

    if ((dwStyle & WS_CHILD) != 0)
        DebugBreak();

    if (nWidth == -1)
        nWidth = 1000;
    if (nHeight == -1)
        nHeight = 800;

    HwndLinux* self = new HwndLinux();
    self->m_autoHandleClose = false;
    self->m_hWnd = self;
    self->m_userdata = lpParam;

    self->m_style = dwStyle;
    self->m_styleex = dwExStyle;

    unsigned int hash = content::hashStringW(lpClassName);
    std::map<int, WNDCLASSEXW *>::iterator it = HwndLinux::s_wndClassMap->find(hash);
    if (it == HwndLinux::s_wndClassMap->end())
        DebugBreak();
    self->m_wndProc = it->second->lpfnWndProc;

    GtkWidget* msgGtkWidget = (GtkWidget*)drawingArea;
    if (!isGl) {
        gtk_widget_set_size_request((GtkWidget*)drawingArea, nWidth, nHeight);
        g_signal_connect(msgGtkWidget, "draw", G_CALLBACK(&HwndLinux::onDraw), self);

        self->m_drawingArea = (GtkWidget*)drawingArea;
    } else {
        self->m_glArea = (GtkWidget*)drawingArea;
        //msgGtkWidget = (GtkWidget*)rootWindow;
        msgGtkWidget = (GtkWidget*)drawingArea;

        //gtk_widget_set_events(self->m_glArea, gtk_widget_get_events(self->m_glArea) | GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK | GDK_BUTTON_RELEASE_MASK | GDK_SCROLL_MASK);
        g_signal_connect(self->m_glArea, "realize", G_CALLBACK(onRealizeGlTextures), self);
        g_signal_connect(self->m_glArea, "render", G_CALLBACK(onRenderGlTextures), self);
        g_signal_connect(self->m_glArea, "unrealize", G_CALLBACK(onUnrealizeGlTextures), self);
        g_signal_connect(self->m_glArea, "destroy", G_CALLBACK(onGlAreaDestroy), NULL);
    }
    printf("LinuxGdiBindWindowByGtk: %d, %d, %p\n", nWidth, nHeight, drawingArea);

    gtk_widget_set_events((GtkWidget*)drawingArea, gtk_widget_get_events((GtkWidget*)drawingArea) | GDK_BUTTON_PRESS_MASK | GDK_POINTER_MOTION_MASK | GDK_BUTTON_RELEASE_MASK | GDK_SCROLL_MASK);

    self->m_imContext = gtk_im_multicontext_new();

    g_signal_connect(self->m_imContext, "preedit-start", G_CALLBACK(onPreeditStart), self);
    g_signal_connect(self->m_imContext, "commit", G_CALLBACK(onImCommit), self);
    //g_signal_connect(rootWindow, "focus-in-event", G_CALLBACK(onFocusIn), self);
    //g_signal_connect(rootWindow, "focus-out-event", G_CALLBACK(onFocusOut), self);
    
    // 这种情况不需要绑定destroy事件了，因为rootWindow是最外层的窗口，而不是每个page的
    //g_signal_connect(GTK_WINDOW((GtkWidget*)rootWindow), "destroy", G_CALLBACK(&HwndLinux::onDestroy), self);
    //g_signal_connect(GTK_WINDOW((GtkWidget*)rootWindow), "delete-event", G_CALLBACK(&HwndLinux::onDeleteEvent), self);
    g_signal_connect(msgGtkWidget, "configure-event", G_CALLBACK(&HwndLinux::onConfigureEvent), self);
    g_signal_connect(msgGtkWidget, "motion-notify-event", G_CALLBACK(&HwndLinux::onMotionNotifyEvent), self);
    g_signal_connect(msgGtkWidget, "button-press-event", G_CALLBACK(&HwndLinux::onButtonPressEvent), self);
    g_signal_connect(msgGtkWidget, "button-release-event", G_CALLBACK(&HwndLinux::onButtonReleaseEvent), self);
    g_signal_connect(msgGtkWidget, "scroll-event", G_CALLBACK(&HwndLinux::onScroll), self);
    g_signal_connect(msgGtkWidget, "key-press-event", G_CALLBACK(&HwndLinux::onKeyPress), self);
    g_signal_connect(msgGtkWidget, "key-release-event", G_CALLBACK(&HwndLinux::onKeyRelease), self);
    g_signal_connect(msgGtkWidget, "focus-in-event", G_CALLBACK(onFocusIn), self);
    g_signal_connect(msgGtkWidget, "focus-out-event", G_CALLBACK(onFocusOut), self);
    g_signal_connect(msgGtkWidget, "focus-out-event", G_CALLBACK(&HwndLinux::onFocusOut), self);
    g_object_set(G_OBJECT(msgGtkWidget), "can-focus", TRUE, NULL);

    CREATESTRUCTW createStruct = { 0 };
    createStruct.lpCreateParams = lpParam;
    self->m_wndProc(self, WM_CREATE, 0, (LPARAM)&createStruct);
    self->m_window = (GtkWidget*)rootWindow;
    
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux::s_hwnds->insert(self); // TODO: delete
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return self;
}

BOOL GetClassInfoExW(HINSTANCE hInstance, LPCWSTR lpszClass, LPWNDCLASSEXW lpwcx)
{
    CHECK(content::ThreadCall::isUiThread());
    printf("GetClassInfoExW\n");
    return FALSE;
}

static bool rectContains(const RECT& a, const RECT& rect)
{
    return (rect.left >= a.left && rect.right <= a.right && rect.top >= a.top && rect.bottom <= a.bottom);
}

static bool rectArea(const RECT& rect)
{
    return (rect.right - rect.left) * (rect.bottom - rect.top);
}

// 辅助函数：求两个整数的最大值
static LONG maxLong(LONG a, LONG b)
{
    return (a > b) ? a : b;
}

// 辅助函数：求两个整数的最小值
static LONG minLong(LONG a, LONG b)
{
    return (a < b) ? a : b;
}

// 计算两个矩形重叠部分的矩形区域
static bool unionRects(const RECT* rect1, const RECT* rect2, RECT* overlapRect)
{
    if (rect1 == NULL || rect2 == NULL || overlapRect == NULL)
        return false;

    // 验证矩形是否有效（宽度和高度应该大于0）
    if (rect1->left >= rect1->right || rect1->top >= rect1->bottom ||
        rect2->left >= rect2->right || rect2->top >= rect2->bottom) {
        return false;
    }

    // 计算重叠矩形的边界
    overlapRect->left = maxLong(rect1->left, rect2->left);
    overlapRect->top = maxLong(rect1->top, rect2->top);
    overlapRect->right = minLong(rect1->right, rect2->right);
    overlapRect->bottom = minLong(rect1->bottom, rect2->bottom);

    // 检查是否存在重叠区域
    if (overlapRect->left >= overlapRect->right || overlapRect->top >= overlapRect->bottom) {
        return false;  // 没有重叠区域
    }

    return true;  // 成功获取重叠矩形
}

static void mergeDirtyRects(std::vector<RECT>* damageRects, const RECT& rect)
{
    for (size_t i = 0; i < damageRects->size(); ++i) {
        const RECT& r = damageRects->at(i);
        if (rectContains(r, rect))
            return;
        int sumOfArea = rectArea(r) + rectArea(rect);

        RECT unionRect;
        bool b = unionRects(&r, &rect, &unionRect);
        int unionRectArea = rectArea(unionRect);
        if (unionRectArea < sumOfArea) {
            (*damageRects)[i] = unionRect;
            return;
        }
    }
    damageRects->push_back(rect);
}

BOOL InvalidateRect(HWND hWnd, CONST RECT* lpRect, BOOL bErase)
{
    HwndLinux* self = (HwndLinux*)hWnd;
    if (!HwndLinux::s_hwnds)
        return FALSE;
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    if (it == HwndLinux::s_hwnds->end()) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return FALSE;
    }

    pthread_mutex_lock(&self->m_damageRectLock);
    ///self->m_damageRects.push_back(*lpRect);
    mergeDirtyRects(&self->m_damageRects, *lpRect);
    pthread_mutex_unlock(&self->m_damageRectLock);

    auto cb = [self]() {
        do {
            if (!HwndLinux::s_hwnds)
                break;
            pthread_mutex_lock(&HwndLinux::s_hwndMutex);
            std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find((HWND)self);
            pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
            if (it == HwndLinux::s_hwnds->end())
                break;

            self->m_isPostDamageRect = false;

            pthread_mutex_lock(&self->m_damageRectLock);
            std::vector<RECT> damageRects = self->m_damageRects;
            self->m_damageRects.clear();
            pthread_mutex_unlock(&self->m_damageRectLock);

            //printf("InvalidateRect~: %p\n", self);
            if (self->m_glArea) {
                gtk_gl_area_queue_render(GTK_GL_AREA(self->m_glArea));
            } else {
                for (size_t i = 0; i < damageRects.size(); ++i) {
                    RECT rc = damageRects[i];
                    gtk_widget_queue_draw_area(self->m_drawingArea, rc.left, rc.top, rc.right - rc.left, rc.bottom - rc.top);
                }
            }
        } while (false);
    };

    if (content::ThreadCall::isUiThread()) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        cb();
    } else {
        if (!self->m_isPostDamageRect) {
            self->m_isPostDamageRect = true;
            content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, std::move(cb));
        }
    }
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
    return TRUE;
}

#define MB_ICONQUESTION 0x00000020L
#define MB_ICONEXCLAMATION 0x00000030L
#define MB_ICONWARNING   MB_ICONEXCLAMATION
#define MB_ICONASTERISK 0x00000040L
#define MB_ABORTRETRYIGNORE 0x00000002L
#define MB_YESNOCANCEL 0x00000003L
#define MB_RETRYCANCEL 0x00000005L
#define MB_ABORTRETRYIGNORE 0x00000002L
#define MB_YESNOCANCEL 0x00000003L
#define MB_YESNO 0x00000004L
#define MB_RETRYCANCEL 0x00000005L
#define MB_SYSTEMMODAL 0x00001000L
#define MB_ICONINFORMATION          MB_ICONASTERISK
#define MB_TASKMODAL 0x00002000L
#define MB_TOPMOST 0x00040000L
#define MB_SETFOREGROUND 0x00010000L
#define MB_ICONHAND 0x00000010L
#define MB_ICONERROR                MB_ICONHAND

#define IDCANCEL 2
#define IDNO 7
#define IDCANCEL 2

// 转换 Windows 消息类型到 GTK 消息类型
static GtkMessageType convertToGtkMessageType(UINT uType)
{
    if (uType & MB_ICONHAND || uType & MB_ICONERROR) {
        return GTK_MESSAGE_ERROR;
    } else if (uType & MB_ICONQUESTION) {
        return GTK_MESSAGE_QUESTION;
    } else if (uType & MB_ICONEXCLAMATION || uType & MB_ICONWARNING) {
        return GTK_MESSAGE_WARNING;
    } else if (uType & MB_ICONASTERISK || uType & MB_ICONINFORMATION) {
        return GTK_MESSAGE_INFO;
    } else {
        // 默认根据按钮类型推断
        switch (uType & 0x0000000FL) {
            case MB_OKCANCEL:
            case MB_ABORTRETRYIGNORE:
            case MB_YESNOCANCEL:
            case MB_RETRYCANCEL:
                return GTK_MESSAGE_QUESTION;
            default:
                return GTK_MESSAGE_INFO;
        }
    }
}

// 转换 Windows 按钮类型到 GTK 按钮类型
static GtkButtonsType convertToGtkButtonsType(UINT uType)
{
    switch (uType & 0x0000000FL) {
        case MB_OK:
            return GTK_BUTTONS_OK;

        case MB_OKCANCEL:
            return GTK_BUTTONS_OK_CANCEL;

        case MB_ABORTRETRYIGNORE:
            // GTK 没有直接对应的按钮组合，使用自定义
            return GTK_BUTTONS_CLOSE;

        case MB_YESNOCANCEL:
            // GTK 没有直接对应的按钮组合，使用自定义
            return GTK_BUTTONS_CLOSE;

        case MB_YESNO:
            return GTK_BUTTONS_YES_NO;

        case MB_RETRYCANCEL:
            // GTK 没有直接对应的按钮组合，使用自定义
            return GTK_BUTTONS_CLOSE;

        default:
            return GTK_BUTTONS_OK;
    }
}

// 转换 GTK 响应到 Windows 返回值
static int convertFromGtkResponse(gint response)
{
    switch (response) {
        case GTK_RESPONSE_OK:
            return IDOK;

        case GTK_RESPONSE_CANCEL:
            return IDCANCEL;

        case GTK_RESPONSE_YES:
            return IDYES;

        case GTK_RESPONSE_NO:
            return IDNO;

        case GTK_RESPONSE_CLOSE:
        case GTK_RESPONSE_DELETE_EVENT:
            // 对于没有明确定义的按钮组合，返回取消
            return IDCANCEL;

        default:
            return IDOK;
    }
}

int MessageBoxImpl(HWND hWnd, std::string* lpText, std::string* lpCaption, UINT uType)
{
    GtkWidget* dialog = NULL;
    GtkWindow* parent = NULL;
    GtkMessageType msg_type;
    GtkButtonsType buttons_type;
    gint response;
    int result = IDOK;

    if (hWnd && HwndLinux::s_hwnds) {
        HwndLinux* self = (HwndLinux*)hWnd;
        pthread_mutex_lock(&HwndLinux::s_hwndMutex);
        std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find((HWND)self);
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        if (it != HwndLinux::s_hwnds->end()) {
            parent = GTK_WINDOW(self->m_window);
        }
    }

    // 转换消息类型和按钮类型
    msg_type = convertToGtkMessageType(uType);
    buttons_type = convertToGtkButtonsType(uType);

    // 创建对话框
    dialog = gtk_message_dialog_new(parent,
        (GtkDialogFlags)(GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT),
        msg_type,
        buttons_type,
        "%s", lpCaption ? lpCaption->c_str() : "");
    delete lpCaption;

    // 设置消息文本
    if (lpText) {
        gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(dialog), "%s", lpText->c_str());
        delete lpText;
    }

    // 设置窗口属性
    if (uType & MB_SYSTEMMODAL || uType & MB_TASKMODAL) {
        gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);
        gtk_window_set_keep_above(GTK_WINDOW(dialog), TRUE);
    }

    if (uType & MB_TOPMOST) {
        gtk_window_set_keep_above(GTK_WINDOW(dialog), TRUE);
    }

    if (uType & MB_SETFOREGROUND) {
        gtk_window_present(GTK_WINDOW(dialog));
    }

    // 显示对话框并获取响应
    response = gtk_dialog_run(GTK_DIALOG(dialog));
    result = convertFromGtkResponse(response);

    // 销毁对话框
    gtk_widget_destroy(dialog);

    return result;
}

int MessageBoxW(HWND hWnd, LPCWSTR lpText, LPCWSTR lpCaption, UINT uType)
{
    return MessageBoxA(hWnd, 
        lpText ? content::utf16ToUtf8(lpText).c_str() : "",
        lpCaption ? content::utf16ToUtf8(lpCaption).c_str() : "", uType);
}

int WINAPI MessageBoxA(HWND hWnd, LPCSTR lpText, LPCSTR lpCaption, UINT uType)
{
    int ret = -1111;
    int* retPtr = &ret;
    std::string* textStr = new std::string(lpText ? lpText : "");
    std::string* captionStr = new std::string(lpCaption ? lpCaption : "");

    auto cb = [retPtr, hWnd, textStr, captionStr, uType]() {
        *retPtr = MessageBoxImpl(hWnd, textStr, captionStr, uType);
    };

    if (content::ThreadCall::isUiThread()) {
        cb();
    } else {
        content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, std::move(cb));
        while (ret == -1111) {
            usleep(100);
        }
    }
    return ret;
}

BOOL GetMessageW(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
    usleep(1000);
    gtk_main_iteration();
    return TRUE;
}

BOOL TranslateMessage(CONST MSG* lpMsg)
{
    return TRUE;
}

LRESULT DispatchMessageW(CONST MSG* lpMsg)
{
    return 0;
}

BOOL PeekMessageW(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax, UINT wRemoveMsg)
{
    usleep(1000);
    printf("PeekMessageW\n");
    return TRUE;
}

HDC BeginPaint(HWND hWnd, LPPAINTSTRUCT lpPaint)
{
    HwndLinux* self = (HwndLinux*)hWnd;
    *lpPaint = *(LPPAINTSTRUCT)self->m_msgPtr;
    return lpPaint->hdc;
}

BOOL EndPaint(HWND hWnd, CONST PAINTSTRUCT* lpPaint)
{
    return TRUE;
}

BOOL ShowWindow(HWND hWnd, int nCmdShow)
{
    HwndLinux* self = (HwndLinux*)hWnd;
    if (!self)
        return FALSE;
    CHECK(content::ThreadCall::isUiThread());

    if (SW_SHOW == nCmdShow || SW_SHOWNORMAL == nCmdShow || SW_SHOWNOACTIVATE == nCmdShow || SW_MAXIMIZE == nCmdShow) {
        gtk_widget_show_all(self->m_window);

        if (SW_MAXIMIZE == nCmdShow)
            gtk_window_maximize(GTK_WINDOW(self->m_window));
        OutputDebugStringA("ShowWindow show\n");
    } else if (SW_MINIMIZE == nCmdShow) {
        gtk_window_iconify(GTK_WINDOW(self->m_window));
    } else {
        OutputDebugStringA("ShowWindow hide\n");
        gtk_widget_hide(self->m_window);
    }
    return TRUE;
}

BOOL SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int x, int y, int cx, int cy, UINT uFlags)
{
    CHECK(content::ThreadCall::isUiThread());
    HwndLinux* self = (HwndLinux*)hWnd;

    gtk_window_deiconify(GTK_WINDOW(self->m_window));

    if (!(uFlags & SWP_NOSIZE)) {
        GdkWindow* gdkWindow = gtk_widget_get_window(self->m_window);
        GdkWindowState state = gdk_window_get_state(gdkWindow);

        if (state & GDK_WINDOW_STATE_MAXIMIZED) {
            gtk_window_unmaximize(GTK_WINDOW(self->m_window));
        }

        if (state & GDK_WINDOW_STATE_ICONIFIED) {
            gtk_window_deiconify(GTK_WINDOW(self->m_window));
        }

        gtk_window_resize(GTK_WINDOW(self->m_window), cx, cy);
    }
    if (!(uFlags & SWP_NOMOVE)) {
        gtk_window_move(GTK_WINDOW(self->m_window), x, y);
    }

    return TRUE;
}

BOOL GetClientRect(HWND hWnd, LPRECT lpRect)
{
    CHECK(content::ThreadCall::isUiThread());
    HwndLinux* self = (HwndLinux*)hWnd;
    
    lpRect->left = 0;
    lpRect->top = 0;
    lpRect->right = gtk_widget_get_allocated_width(self->getDrawingAreaOrGl());
    lpRect->bottom = gtk_widget_get_allocated_height(self->getDrawingAreaOrGl());

    return TRUE;
}

BOOL GetWindowRect(HWND hWnd, LPRECT lpRect)
{
    CHECK(content::ThreadCall::isUiThread());
    HwndLinux* self = (HwndLinux*)hWnd;

    int width = 1, height = 1;
    gtk_window_get_size(GTK_WINDOW(self->m_window), &width, &height);

    return TRUE;
}

ATOM RegisterClassW(CONST WNDCLASSW* wndClass)
{
    OutputDebugStringA("RegisterClassW\n");
    return 0;
}

ATOM RegisterClassExW(CONST WNDCLASSEXW* wndClass)
{
    CHECK(content::ThreadCall::isUiThread());
    if (!HwndLinux::s_wndClassMap)
        HwndLinux::s_wndClassMap = new std::map<int, WNDCLASSEXW*>();

    WNDCLASSEXW* wndClassCopy = new WNDCLASSEXW();
    wndClassCopy->lpfnWndProc = wndClass->lpfnWndProc;

    unsigned int hash = content::hashStringW(wndClass->lpszClassName);
    std::map<int, WNDCLASSEXW*>::iterator it = HwndLinux::s_wndClassMap->find(hash);
    if (it != HwndLinux::s_wndClassMap->end())
        return 0;

    HwndLinux::s_wndClassMap->insert(std::pair<int, WNDCLASSEXW*>(hash, wndClassCopy));

    return 0;
}

BOOL IsWindow(HWND hWnd)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    if (!HwndLinux::s_hwnds) {
        HwndLinux::s_hwnds = new std::set<HWND>();
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return FALSE;
    }
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return b;
}

DWORD GetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux* self = (HwndLinux*)hWnd;
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return 0;
    }
    DWORD threadId = self->m_threadId;
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return threadId;
}

BOOL GetCursorPos(POINT* lpPoint)
{
    if (content::ThreadCall::isUiThread())
        CrossThreadUiState::get()->updata(nullptr);

    lpPoint->x = CrossThreadUiState::get()->m_cursorPos.x;
    lpPoint->y = CrossThreadUiState::get()->m_cursorPos.y;

    return TRUE;
}

BOOL ScreenToClient(HWND hWnd, LPPOINT lpPoint)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);

    HwndLinux* self = (HwndLinux*)hWnd;

    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return FALSE;
    }

    if (content::ThreadCall::isUiThread()) {
        gtk_window_get_position(GTK_WINDOW(self->m_window), &self->m_rootX, &self->m_rootY);
    }

    lpPoint->x -= self->m_rootX;
    lpPoint->y -= self->m_rootY;

    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return TRUE;
}

BOOL ClientToScreen(HWND hWnd, POINT* lpPoint)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);

    HwndLinux* self = (HwndLinux*)hWnd;

    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return FALSE;
    }

    if (content::ThreadCall::isUiThread()) {
        gtk_window_get_position(GTK_WINDOW(self->m_window), &self->m_rootX, &self->m_rootY);
    }

    lpPoint->x += self->m_rootX;
    lpPoint->y += self->m_rootY;

    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return TRUE;
}

// todo(mb): select 的定位具有特殊性, 该函数后续应该换个位置
BOOL ClientToScreenForSelect(HWND hWnd, POINT* lpPoint)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);

    HwndLinux* self = (HwndLinux*)hWnd;

    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return FALSE;
    }

    if (content::ThreadCall::isUiThread()) {
        gint x, y;
        // 与 Windows 不同, 在 Linux 下, mb 不是一个窗口, 而是一个 gtk widget
        // 这里计算坐标需要两步, 首先计算 mb 绘制区域相对于外部窗口的坐标, 再加上外部窗口相当于屏幕的坐标
        if (gtk_widget_translate_coordinates(self->getDrawingAreaOrGl(), self->m_window, 0, 0, &x, &y)) {
            gint winX, winY;
            gdk_window_get_origin(gtk_widget_get_window(self->m_window), &winX, &winY);

            self->m_rootX = x + winX;
            self->m_rootY = y + winY;
        }
    }

    lpPoint->x += self->m_rootX;
    lpPoint->y += self->m_rootY;

    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return TRUE;
}

void HwndLinux::destroy(HWND hWnd, bool forceDelete)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux* self = (HwndLinux*)hWnd;
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return;
    }

    GtkWidget* window = self->m_window;
    bool autoHandleClose = self->m_autoHandleClose;
    // 如果是外部接管gtk窗口的生命周期，那这里要手动析构
    //if (self->m_autoHandleClose || forceDelete) {
    //    delete self;
    //} else {
    //    self->m_isDestroying = true;
    //}
    // 目前外部的使用方式, 创建是 mbCreateWebViewBindGtkWindow
    // 销毁是 mbDestroyWebView + gtk_window_close, 
    // 此时只会设置 self->m_isDestroying = true, 无法销毁 HwndLinux 自身
    delete self;

    HwndLinux::s_hwnds->erase(it);
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    // m_autoHandleClose是非LinuxGdiBindWindowByGtk模式才有。在LinuxGdiBindWindowByGtk模式下，外部exe来关闭窗口
    if (window && autoHandleClose) {
        printf("HwndLinux::destroy ok: %p\n", window);
        //gtk_window_close(GTK_WINDOW(window));
        gtk_widget_destroy(window);
    }
}

BOOL DestroyWindow(HWND hWnd)
{
    HwndLinux::destroy(hWnd, false);
    return TRUE;
}

BOOL SetWindowTextW(HWND hWnd, LPCWSTR lpString)
{
    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux* self = (HwndLinux*)hWnd;
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return FALSE;
    }

    std::string titleU8 = content::utf16ToUtf8(lpString);
    gtk_window_set_title(GTK_WINDOW(self->m_window), titleU8.c_str());
    printf("SetWindowTextW:: %p\n", self->m_window);

    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return TRUE;
}

HCURSOR linuxSetCursor(HWND hWnd, HCURSOR hCursor)
{
    if (!hCursor)
        return nullptr;

    GdkCursor* cursor = (GdkCursor*)(hCursor);

    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    HwndLinux* self = (HwndLinux*)hWnd;
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    bool b = it != HwndLinux::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return nullptr;
    }

    GdkWindow* window = gtk_widget_get_window(self->m_window);
    //GdkWindow* window = gtk_widget_get_window(self->m_drawingArea);
    gdk_window_set_cursor(window, cursor);
    g_object_unref(cursor);

    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);

    return nullptr;
}

HCURSOR LoadCursorW(HINSTANCE hInstance, LPCWSTR lpCursorName)
{
    GdkDisplay* display = gdk_display_get_default();

    if (IDC_ARROW == lpCursorName)
        return gdk_cursor_new_for_display(display, GDK_ARROW);
    if (IDC_IBEAM == lpCursorName)
        return gdk_cursor_new_from_name(display, "text");
    if (IDC_APPSTARTING == lpCursorName)
        return gdk_cursor_new_from_name(display, "wait");
    if (IDC_CROSS == lpCursorName)
        return gdk_cursor_new_for_display(display, GDK_CROSS);
    if (IDC_SIZEALL == lpCursorName)
        return gdk_cursor_new_for_display(display, GDK_FLEUR);
    if (IDC_SIZEWE == lpCursorName)
        return gdk_cursor_new_from_name(display, "ew-resize");
    if (IDC_SIZENS == lpCursorName)
        return gdk_cursor_new_from_name(display, "ns-resize");
    if (IDC_HAND == lpCursorName)
        return gdk_cursor_new_from_name(display, "grab");
    if (IDC_WAIT == lpCursorName)
        return gdk_cursor_new_from_name(display, "wait");
    if (IDC_HELP == lpCursorName)
        return gdk_cursor_new_from_name(display, "help");
    if (IDC_SIZEALL == lpCursorName)
        return gdk_cursor_new_from_name(display, "move");
    if (IDC_NO == lpCursorName)
        return gdk_cursor_new_from_name(display, "not-allowed");  
    return NULL;
}

void* HwndToGtkWindow(HWND hWnd)
{
    if (!HwndLinux::s_hwnds || !hWnd)
        return nullptr;
    HwndLinux* self = (HwndLinux*)hWnd;

    pthread_mutex_lock(&HwndLinux::s_hwndMutex);
    std::set<HWND>::const_iterator it = HwndLinux::s_hwnds->find(hWnd);
    if (it == HwndLinux::s_hwnds->end()) {
        pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
        return nullptr;
    }

    void* gtkWindow = self->m_window;
    pthread_mutex_unlock(&HwndLinux::s_hwndMutex);
    return gtkWindow;
}

SHORT GetKeyState(int nVirtKey)
{
    bool isCapsLock = false;
    bool isNumLock = false;
    bool isScrollLock = false;
    bool isShift = false;
    bool isCtrl = false;
    bool isAtl = false;
    CrossThreadUiState::get()->getState(&isCapsLock, &isNumLock, &isScrollLock, &isShift, &isCtrl, &isAtl);
    if (isCtrl)
        printf("GetKeyState, isCtrl, nVirtKey:%d\n", nVirtKey);

    if (VK_SHIFT == nVirtKey) {
        return isShift ? 0x8000 : 0;
    } else if (VK_CONTROL == nVirtKey) {
        return isCtrl ? 0x8000 : 0;
    } else if (VK_MENU == nVirtKey) {
        return isAtl ? 0x8000 : 0;
    } else if (VK_CAPITAL == nVirtKey) {
        return isCapsLock ? 0x0001 : 0;
    } else if (VK_NUMLOCK == nVirtKey) {
        return isNumLock ? 0x0001 : 0;
    }

    printf("GetKeyState is not impl\n");
    __debugbreak();
    return 0;
}

gboolean HwndLinux::onKeyPress(GtkWidget* widget, GdkEventKey* event, gpointer data)
{
    HwndLinux* self = (HwndLinux*)data;
    if (!IsWindow((HWND)self))
        return TRUE;

    if (gtk_im_context_filter_keypress(self->m_imContext, event)) {
        return TRUE; // 输入法处理了这个按键
    }

    int key = event->keyval;
    switch (key) {
    case GDK_Up:
        key = VK_UP;
        break;
    case GDK_Left:
        key = VK_LEFT;
        break;
    case GDK_Right:
        key = VK_RIGHT;
        break;
    case GDK_Down:
        key = VK_DOWN;
        break;
    case GDK_Next:
        key = VK_NEXT;
        break;
    case GDK_Prior:
        key = VK_PRIOR;
        break;
    case GDK_Home:
        key = VK_HOME;
        break;
    case GDK_End:
        key = VK_END;
        break;
    case GDK_BackSpace:
        key = VK_BACK;
        break;
    case GDK_Tab:
        key = VK_TAB;
        break;
    case GDK_Back:
        key = VK_BACK;
        break;
    case GDK_Escape:
        key = VK_ESCAPE;
        break;
    case GDK_Return:
        key = VK_RETURN;
        break;
    case GDK_KEY_Control_L:
    case GDK_Control_R: // ctrl key
        CrossThreadUiState::get()->setCtrl(true);
        key = VK_CONTROL;
        break;
    case GDK_KP_0:
        key = '0';
        break;
    case GDK_KP_1:
        key = '1';
        break;
    case GDK_KP_2:
        key = '2';
        break;
    case GDK_KP_3:
        key = '3';
        break;
    case GDK_KP_4:
        key = '4';
        break;
    case GDK_KP_5:
        key = '5';
        break;
    case GDK_KP_6:
        key = '6';
        break;
    case GDK_KP_7:
        key = '7';
        break;
    case GDK_KP_8:
        key = '8';
        break;
    case GDK_KP_9:
        key = '9';
        break;
    case GDK_Num_Lock: // num key
    case GDK_Caps_Lock: // caps key
    case GDK_Shift_L: // shift key
    case GDK_Shift_R: // shift key
    case GDK_Super_L: // win key
    case GDK_Super_R: // win key
    case GDK_Alt_L: // atl key
    case GDK_Alt_R: // atl key
        return FALSE;
    case GDK_KP_Divide:
        key = '/';
        break;
    case GDK_KP_Multiply:
        key = '*';
        break;
    case GDK_KP_Subtract:
        key = '-';
        break;
    case GDK_KP_Add:
        key = '+';
        break;
    case GDK_KP_Decimal:
        key = '.';
        break;
    case GDK_KP_End:
        key = VK_END;
        break;
    case GDK_KP_Down:
        key = VK_DOWN;
        break;
        
    }

    if ((event->state & GDK_CONTROL_MASK) /*&& (event->keyval == GDK_KEY_c)*/) {
        CrossThreadUiState::get()->setCtrl(true);
    }

    printf("onKeyPress, keyval = %x\n", key);
    self->m_wndProc(self, WM_KEYDOWN, (WPARAM)key, 0);
    self->m_wndProc(self, WM_CHAR, (WPARAM)key, 0);

    return FALSE;
}

void HwndLinux::setLastMousePressEvent(GdkEvent* event) 
{
    if (s_lastMousePressEvent) {
        gdk_event_free(s_lastMousePressEvent);
        s_lastMousePressEvent = nullptr;
    }

    if (!event) {
        return;
    }

    s_lastMousePressEvent = gdk_event_copy(event);
}

// int main(int argc, char* argv[])
// {
//     gtk_init(&argc, &argv);
//     return 0;
// }

#endif // WIN32