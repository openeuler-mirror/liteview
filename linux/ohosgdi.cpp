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


#if defined(OS_OHOS)
#include "linux/ohosgdi.h"
#include "content/common/StringUtil.h"
#include "content/common/ThreadCall.h"

#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/kits/animator/animator.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/innerkits/common/graphic_startup.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/innerkits/common/task_manager.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/kits/components/root_view.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/kits/components/ui_button.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/kits/components/ui_image_view.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/kits/components/ui_label.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/kits/font/ui_font.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/kits/window/window.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/test/framework/common/ui_text_language.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/innerkits/font/ui_font_bitmap.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/utils/interfaces/kits/gfx_utils/graphic_log.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/utils/interfaces/innerkits/graphic_config.h"

#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <utility>
#include <sys/types.h>
#include <unistd.h>
#include <map>

std::map<int, WNDCLASSEXW*>* HwndOhos::s_wndClassMap = nullptr;
std::set<HWND>* HwndOhos::s_hwnds = nullptr;
pthread_mutex_t HwndOhos::s_hwndMutex;

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

    void updata(const int* state)
    {

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

    pthread_mutex_t m_mutex;
    static CrossThreadUiState* m_inst;
};

void CrossThreadUiStateUpdata()
{
    CrossThreadUiState::get()->updata(nullptr);
}

CrossThreadUiState* CrossThreadUiState::m_inst = nullptr;

HwndOhos::HwndOhos()
{
    m_window = nullptr;
    m_wndProc = nullptr;
    m_userdata = nullptr;
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
}

HwndOhos::~HwndOhos()
{
    pthread_mutex_destroy(&m_propsMutex);
}

void HwndOhos::clearSurface()
{

}

BOOL PostMessageW(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    HwndOhos* self = (HwndOhos*)hWnd;

    if (Msg == WM_SYSCOMMAND && wParam == SC_MOVE | HTCAPTION) {
//         GdkEventButton* evt = CrossThreadUiState::get()->getGdkEventButton();
//         if (evt)
//             gtk_window_begin_move_drag(GTK_WINDOW(self->m_window), evt->button, evt->x_root, evt->y_root, evt->time);
        return TRUE;
    }
    return FALSE;
}
//////////////////////////////////////////////////////////////////////////
// cairo_surface_t* LinuxGdiCreateSurfaceByHwnd(HWND hwnd, int w, int h)
// {
//     HwndOhos* self = (HwndOhos*)hwnd;
//     cairo_surface_t* surface = cairo_image_surface_create(CAIRO_FORMAT_ARGB32, w, h);
//     unsigned char* byteData = cairo_image_surface_get_data(surface);
//     return surface;
// }

//////////////////////////////////////////////////////////////////////////

LONG SetWindowLongW(HWND hwnd, int nIndex, LONG dwNewLong)
{
    if (GWLP_USERDATA == nIndex) {
        HwndOhos* self = (HwndOhos*)hwnd;
        //self->m_wndProc;
        self->m_userdata = (LPVOID)dwNewLong;
    } else {
        printf("SetWindowLongW\n");
    }
    return 0;
}

LONG GetWindowLongW(HWND hwnd, int nIndex)
{
    HwndOhos* self = (HwndOhos*)hwnd;
    if (!self)
        return 0;

    if (GWL_EXSTYLE == nIndex)
        return self->m_styleex;
    else if (GWL_STYLE == nIndex)
        return self->m_style;
    else
        printf("GetWindowLongW fail\n");

    return 0;
}

BOOL SetPropW(HWND hwnd, LPCWSTR lpString, HANDLE hData)
{
    if (!lpString)
        return FALSE;

    unsigned int hash = content::hashStringW(lpString);
    HwndOhos* self = (HwndOhos*)hwnd;
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

HANDLE GetPropW(HWND hwnd, LPCWSTR lpString)
{
    HANDLE ret = nullptr;
    unsigned int hash = content::hashStringW(lpString);
    HwndOhos* self = (HwndOhos*)hwnd;

    pthread_mutex_lock(&self->m_propsMutex);
    std::map<unsigned int, void*>::iterator it = self->m_props.find(hash);
    if (it != self->m_props.end())
        ret = it->second;    
    pthread_mutex_unlock(&self->m_propsMutex);

    return ret;
}

LRESULT DefWindowProcW(HWND hwnd, UINT Msg, WPARAM wParam, LPARAM lParam)
{
    return 0;
}

class UIWebview : public OHOS::UIView {
public:
    UIWebview(HwndOhos* hwnd)
    {
        m_hwnd = hwnd;

        m_imageInfo.header.colorMode = OHOS::ARGB8888;
        m_imageInfo.header.version = 0;
        m_imageInfo.header.compressMode = 0;
        m_imageInfo.header.reserved = 0;
        m_imageInfo.header.width = 0;
        m_imageInfo.header.height = 0;
        m_imageInfo.dataSize = 0;
        m_imageInfo.data = nullptr;
        m_imageInfo.userData = nullptr;
    }

    ~UIWebview()
    {
        if (m_image)
            delete m_image;

        if (m_imageInfo.data)
            free((void*)m_imageInfo.data);
    }

    void resize(uint16_t w, uint16_t h)
    {
        m_imageInfo.header.width = w;
        m_imageInfo.header.height = h;

        if (m_imageInfo.data)
            free((void*)m_imageInfo.data);

        m_imageInfo.dataSize = w * h * 4;
        m_imageInfo.data = (const uint8_t*)malloc(m_imageInfo.dataSize);
    }

private:
    void OnDraw(OHOS::BufferInfo& gfxDstBuffer, const OHOS::Rect& invalidatedArea) override
    {
        OHOS::UIView::OnDraw(gfxDstBuffer, invalidatedArea);

        if (0 == m_imageInfo.header.width * m_imageInfo.header.height)
            return;

        if (!m_image) {
            m_image = new OHOS::Image();
            m_image->SetSrc(&m_imageInfo);
        }

        if (!IsWindow((HWND)m_hwnd))
            return;
        CrossThreadUiState::get()->updata(nullptr);

        OHOS::Rect clientRc = this->GetRect();
        int width = clientRc.GetWidth();
        int height = clientRc.GetHeight();

        m_hwnd->m_wndProc(m_hwnd, WM_SIZE, 0, MAKELPARAM(width, height));

        PAINTSTRUCT paintStrct = { 0 };
        paintStrct.hdc = (HDC)m_imageInfo.data;
        paintStrct.fErase = TRUE;
        paintStrct.rcPaint.left = 0;
        paintStrct.rcPaint.top = 0;
        paintStrct.rcPaint.right = width;
        paintStrct.rcPaint.bottom = height;
        paintStrct.fRestore = FALSE;
        paintStrct.fIncUpdate = FALSE;

        m_hwnd->m_msgPtr = &paintStrct;
        m_hwnd->m_wndProc(m_hwnd, WM_PAINT, (WPARAM)m_imageInfo.data, 0); // -> MbWebView::onPaint
        m_hwnd->m_msgPtr = nullptr;

        OHOS::Rect rc;
        rc.Resize(m_imageInfo.header.width, m_imageInfo.header.height);
        m_image->DrawImage(gfxDstBuffer, rc, rc, OHOS::Style(), 255);
    }

    OHOS::ImageInfo m_imageInfo;
    OHOS::Image* m_image = nullptr;
    HwndOhos* m_hwnd = nullptr;
};

//  W:\opencode\OpenHarmony-v3.1-Release\foundation\graphic\ui\interfaces\kits\common\image.h:SetSrc(const ImageInfo* src);

static OHOS::Window* createDefaultWindow(OHOS::RootView* rootView, int x, int y)
{
    if (!rootView)
        return nullptr;

    OHOS::WindowConfig config = {};
    config.rect = rootView->GetRect();
    config.rect.SetPosition(x, y);
    OHOS::Window* window = OHOS::Window::CreateWindow(config);
    if (window != nullptr) {
        window->BindRootView(rootView);
        window->Show();
    } else {
        GRAPHIC_LOGE("Create window false!");
    }
    return window;
}

HWND CreateWindowExW(DWORD dwExStyle, LPCWSTR lpClassName, LPCWSTR lpWindowName, DWORD dwStyle, int X, int Y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
    char output[100] = { 0 };
    sprintf(output, "CreateWindowExW s_hwnds:%p\n", HwndOhos::s_hwnds);
    OutputDebugStringA(output);

    if (!HwndOhos::s_hwnds) {
        HwndOhos::s_hwnds = new std::set<HWND>();
        pthread_mutexattr_t attr;
        pthread_mutexattr_init(&attr);
        pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
        pthread_mutex_init(&HwndOhos::s_hwndMutex, &attr);
    }

    if ((dwStyle & WS_CHILD) != 0)
        DebugBreak();

    if (nWidth == -1)
        nWidth = 800;
    if (nHeight == -1)
        nHeight = 600;

    HwndOhos* self = new HwndOhos();
    self->m_autoHandleClose = true;
    self->m_hWnd = self;
    self->m_userdata = lpParam;

    self->m_style = dwStyle;
    self->m_styleex = dwExStyle;

    unsigned int hash = content::hashStringW(lpClassName);
    std::map<int, WNDCLASSEXW *>::iterator it = HwndOhos::s_wndClassMap->find(hash);
    if (it == HwndOhos::s_wndClassMap->end())
        DebugBreak();
    self->m_wndProc = it->second->lpfnWndProc;

    OHOS::RootView* rootView = OHOS::RootView::GetWindowRootView();
    rootView->SetWidth(nWidth);
    rootView->SetHeight(nHeight);
    rootView->SetPosition(0, 0);
    rootView->SetStyle(OHOS::STYLE_BACKGROUND_COLOR, OHOS::Color::Olive().full);

    UIWebview* webview = new UIWebview(self);
    self->m_UIWebview = webview;
    webview->resize(nWidth, nHeight);
    rootView->Add(webview);

    self->m_window = createDefaultWindow(rootView, 0, 0);
    //rootView->SetOnClickListener(OnClickListener * onClickListener);

    CREATESTRUCTW createStruct = { 0 };
    createStruct.lpCreateParams = lpParam;
    self->m_wndProc(self, WM_CREATE, 0, (LPARAM)&createStruct);
   
    sprintf(output, "CreateWindowExW::::2 %d, %d\n", nWidth, nHeight);
    OutputDebugStringA(output);

    pthread_mutex_lock(&HwndOhos::s_hwndMutex);
    HwndOhos::s_hwnds->insert(self); // TODO: delete
    pthread_mutex_unlock(&HwndOhos::s_hwndMutex);

    //gtkMessageBox("const char* txt");

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self] {
        self->m_wndProc(self, WM_SIZE, 0, 0); // -> MbWebView::onResize
        self->m_window->Show();
    });
    return self;
}

HWND LinuxGdiBindWindowByGtk(void* rootWindow, void* drawingArea, BOOL isGl, DWORD dwExStyle, LPCWSTR lpClassName, DWORD dwStyle, int nWidth, int nHeight, LPVOID lpParam)
{
    printf("LinuxGdiBindWindowByGtk fail\n");
    *(int*)1 = 1;
    return nullptr;
}

BOOL GetClassInfoExW(HINSTANCE hInstance, LPCWSTR lpszClass, LPWNDCLASSEXW lpwcx)
{
    CHECK(content::ThreadCall::isUiThread());
    printf("GetClassInfoExW\n");
    return FALSE;
}

BOOL InvalidateRect(HWND hWnd, CONST RECT* lpRect, BOOL bErase)
{
    HwndOhos* self = (HwndOhos*)hWnd;
    RECT* rc = new RECT(*lpRect);
    auto cb = [self, rc]() {
        do {
            if (!HwndOhos::s_hwnds)
                break;
            pthread_mutex_lock(&HwndOhos::s_hwndMutex);
            std::set<HWND>::const_iterator it = HwndOhos::s_hwnds->find((HWND)self);
            pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
            if (it == HwndOhos::s_hwnds->end())
                break;

            if (self->m_window && self->m_window->GetRootView()) {
                self->m_window->GetRootView()->Invalidate();
            }
        } while (false);

        delete rc;
    };

    if (content::ThreadCall::isUiThread())
        cb();
    else
        content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, std::move(cb));
    return TRUE;
}

BOOL GetMessageW(MSG* lpMsg, HWND hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax)
{
    usleep(1000);
    OHOS::TaskManager::GetInstance()->TaskHandler();
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
    HwndOhos* self = (HwndOhos*)hWnd;
    *lpPaint = *(LPPAINTSTRUCT)self->m_msgPtr;
    return lpPaint->hdc;
}

BOOL EndPaint(HWND hWnd, CONST PAINTSTRUCT* lpPaint)
{
    return TRUE;
}

BOOL ShowWindow(HWND hWnd, int nCmdShow)
{
    HwndOhos* self = (HwndOhos*)hWnd;
    CHECK(content::ThreadCall::isUiThread());

    if (SW_SHOW == nCmdShow || SW_SHOWNORMAL == nCmdShow || SW_SHOWNOACTIVATE == nCmdShow || SW_MAXIMIZE == nCmdShow) {
        self->m_window->Show();
//         if (SW_MAXIMIZE == nCmdShow)
//             gtk_window_maximize(GTK_WINDOW(self->m_window));
    } else if (SW_MINIMIZE == nCmdShow) {
        //gtk_window_iconify(GTK_WINDOW(self->m_window));
    } else {
        self->m_window->Hide();
    }
    return TRUE;
}

BOOL SetWindowPos(HWND hWnd, HWND hWndInsertAfter, int x, int y, int cx, int cy, UINT uFlags)
{
    CHECK(content::ThreadCall::isUiThread());
    HwndOhos* self = (HwndOhos*)hWnd;
    if (!self->m_window)
        return FALSE;

    if (!(uFlags & SWP_NOSIZE)) {
//         if (state & GDK_WINDOW_STATE_MAXIMIZED) {
//             gtk_window_unmaximize(GTK_WINDOW(self->m_window));
//         }
// 
//         if (state & GDK_WINDOW_STATE_ICONIFIED) {
//             gtk_window_deiconify(GTK_WINDOW(self->m_window));
//         }
        self->m_UIWebview->resize(cx, cy);
        self->m_window->Resize(cx, cy);
    }
    if (!(uFlags & SWP_NOMOVE)) {
        self->m_window->MoveTo(x, y);
    }

    return TRUE;
}

BOOL GetClientRect(HWND hWnd, LPRECT lpRect)
{
    CHECK(content::ThreadCall::isUiThread());
    HwndOhos* self = (HwndOhos*)hWnd;
    if (!self->m_window)
        return FALSE;

    OHOS::Rect rc = self->m_window->GetRect();

    lpRect->left = 0;
    lpRect->top = 0;
    lpRect->right = rc.GetRight();
    lpRect->bottom = rc.GetBottom();

    return TRUE;
}

BOOL GetWindowRect(HWND hWnd, LPRECT lpRect)
{
    CHECK(content::ThreadCall::isUiThread());
    HwndOhos* self = (HwndOhos*)hWnd;

    OHOS::Rect rc = self->m_window->GetRect();
    lpRect->left = rc.GetLeft();
    lpRect->right = rc.GetRight();
    lpRect->top = rc.GetTop();
    lpRect->bottom = rc.GetBottom();

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
    if (!HwndOhos::s_wndClassMap)
        HwndOhos::s_wndClassMap = new std::map<int, WNDCLASSEXW*>();

    WNDCLASSEXW* wndClassCopy = new WNDCLASSEXW();
    wndClassCopy->lpfnWndProc = wndClass->lpfnWndProc;

    unsigned int hash = content::hashStringW(wndClass->lpszClassName);
    std::map<int, WNDCLASSEXW*>::iterator it = HwndOhos::s_wndClassMap->find(hash);
    if (it != HwndOhos::s_wndClassMap->end())
        return 0;

    HwndOhos::s_wndClassMap->insert(std::pair<int, WNDCLASSEXW*>(hash, wndClassCopy));

    return 0;
}

BOOL IsWindow(HWND hWnd)
{
    pthread_mutex_lock(&HwndOhos::s_hwndMutex);
    if (!HwndOhos::s_hwnds) {
        HwndOhos::s_hwnds = new std::set<HWND>();
        pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
        return FALSE;
    }
    std::set<HWND>::const_iterator it = HwndOhos::s_hwnds->find(hWnd);
    bool b = it != HwndOhos::s_hwnds->end();
    pthread_mutex_unlock(&HwndOhos::s_hwndMutex);

    return b;
}

DWORD GetWindowThreadProcessId(HWND hWnd, LPDWORD lpdwProcessId)
{
    pthread_mutex_lock(&HwndOhos::s_hwndMutex);
    HwndOhos* self = (HwndOhos*)hWnd;
    std::set<HWND>::const_iterator it = HwndOhos::s_hwnds->find(hWnd);
    bool b = it != HwndOhos::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
        return 0;
    }
    DWORD threadId = self->m_threadId;
    pthread_mutex_unlock(&HwndOhos::s_hwndMutex);

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
    printf("ScreenToClient fail\n");
    *(int*)1 = 1;
    pthread_mutex_lock(&HwndOhos::s_hwndMutex);

//     HwndOhos* self = (HwndOhos*)hWnd;
// 
//     std::set<HWND>::const_iterator it = HwndOhos::s_hwnds->find(hWnd);
//     bool b = it != HwndOhos::s_hwnds->end();
//     if (!b) {
//         pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
//         return FALSE;
//     }
// 
//     if (content::ThreadCall::isUiThread()) {
//         gtk_window_get_position(GTK_WINDOW(self->m_window), &self->m_rootX, &self->m_rootY);
//     }
// 
//     lpPoint->x -= self->m_rootX;
//     lpPoint->y -= self->m_rootY;
// 
//     pthread_mutex_unlock(&HwndOhos::s_hwndMutex);

    return TRUE;
}

BOOL ClientToScreen(HWND hWnd, POINT* lpPoint)
{
    printf("ClientToScreen fail\n");
    *(int*)1 = 1;
    pthread_mutex_lock(&HwndOhos::s_hwndMutex);

//     HwndOhos* self = (HwndOhos*)hWnd;
// 
//     std::set<HWND>::const_iterator it = HwndOhos::s_hwnds->find(hWnd);
//     bool b = it != HwndOhos::s_hwnds->end();
//     if (!b) {
//         pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
//         return FALSE;
//     }
// 
//     if (content::ThreadCall::isUiThread()) {
//         gtk_window_get_position(GTK_WINDOW(self->m_window), &self->m_rootX, &self->m_rootY);
//     }
// 
//     lpPoint->x += self->m_rootX;
//     lpPoint->y += self->m_rootY;

    pthread_mutex_unlock(&HwndOhos::s_hwndMutex);

    return TRUE;
}

void HwndOhos::destroy(HWND hWnd, bool forceDelete)
{
    pthread_mutex_lock(&HwndOhos::s_hwndMutex);
    HwndOhos* self = (HwndOhos*)hWnd;
    std::set<HWND>::const_iterator it = HwndOhos::s_hwnds->find(hWnd);
    bool b = it != HwndOhos::s_hwnds->end();
    if (!b) {
        pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
        return;
    }
    if (!self->m_window) {
        pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
        return;
    }
    OHOS::RootView* window = self->m_window->GetRootView();
    if (!window) {
        pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
        return;
    }
    // 如果是外部接管gtk窗口的生命周期，那这里要手动析构
    if (self->m_autoHandleClose || forceDelete) {
        delete self;
    } else {
        self->m_isDestroying = true;
    }
    HwndOhos::s_hwnds->erase(it);
    pthread_mutex_unlock(&HwndOhos::s_hwndMutex);

    // m_autoHandleClose是非LinuxGdiBindWindowByGtk模式才有。在LinuxGdiBindWindowByGtk模式下，外部exe来关闭窗口
    if (window && self->m_autoHandleClose) {
        OutputDebugStringA("HwndOhos::destroy ok\n");
        OHOS::RootView::DestoryWindowRootView(window);
    }
}

BOOL DestroyWindow(HWND hWnd)
{
    HwndOhos::destroy(hWnd, false);
    return TRUE;
}

BOOL SetWindowTextW(HWND hWnd, LPCWSTR lpString)
{
//     pthread_mutex_lock(&HwndOhos::s_hwndMutex);
//     HwndOhos* self = (HwndOhos*)hWnd;
//     std::set<HWND>::const_iterator it = HwndOhos::s_hwnds->find(hWnd);
//     bool b = it != HwndOhos::s_hwnds->end();
//     if (!b) {
//         pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
//         return FALSE;
//     }
// 
//     std::string titleU8 = content::utf16ToUtf8(lpString);
//     gtk_window_set_title(GTK_WINDOW(self->m_window), titleU8.c_str());
//     printf("SetWindowTextW:: %p\n", self->m_window);
// 
//     pthread_mutex_unlock(&HwndOhos::s_hwndMutex);

    return TRUE;
}

HCURSOR linuxSetCursor(HWND hWnd, HCURSOR hCursor)
{
//     if (!hCursor)
//         return nullptr;
// 
//     GdkCursor* cursor = (GdkCursor*)(hCursor);
// 
//     pthread_mutex_lock(&HwndOhos::s_hwndMutex);
//     HwndOhos* self = (HwndOhos*)hWnd;
//     std::set<HWND>::const_iterator it = HwndOhos::s_hwnds->find(hWnd);
//     bool b = it != HwndOhos::s_hwnds->end();
//     if (!b) {
//         pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
//         return nullptr;
//     }
// 
//     GdkWindow* window = gtk_widget_get_window(self->m_window);
//     gdk_window_set_cursor(window, cursor);
//     g_object_unref(cursor);
// 
//     pthread_mutex_unlock(&HwndOhos::s_hwndMutex);

    return nullptr;
}

HCURSOR LoadCursorW(HINSTANCE hInstance, LPCWSTR lpCursorName)
{
    return NULL;
}

void* HwndToGtkWindow(HWND hwnd)
{
    if (!HwndOhos::s_hwnds || !hwnd)
        return nullptr;
    HwndOhos* self = (HwndOhos*)hwnd;

    pthread_mutex_lock(&HwndOhos::s_hwndMutex);
    std::set<HWND>::const_iterator it = HwndOhos::s_hwnds->find(hwnd);
    if (it == HwndOhos::s_hwnds->end()) {
        pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
        return nullptr;
    }

    void* gtkWindow = self->m_window;
    pthread_mutex_unlock(&HwndOhos::s_hwndMutex);
    return gtkWindow;
}

SHORT GetKeyState(int nVirtKey)
{
    return 0;
}

#endif // WIN32