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


#include "content/ui/ContextMeun.h"

namespace content {

ContextMenu::ContextMenu()
{
    m_popMenu = nullptr;
    m_hWnd = nullptr;
    m_webview = nullptr;
    m_isDestroyed = 0;

    ContextMenu* self = this;
    asyncCallUiThread([self] {
        self->initImpl();
    });
}

void ContextMenu::initImpl()
{
    if (m_hWnd)
        return;

    registerClass();
    m_hWnd = CreateWindowExW(WS_EX_TOOLWINDOW | WS_EX_NOACTIVATE, kContextMenuClassName, kContextMenuClassName, WS_POPUP, 0, 0, 1, 1, HWND_DESKTOP, NULL, nullptr, this);
    ::ShowWindow(m_hWnd, SW_HIDE);
    ::SetPropW(m_hWnd, kContextMenuClassName, (HANDLE)this);
    ::SetForegroundWindow(m_hWnd);
}

ContextMenu::~ContextMenu()
{
    m_mutex.lock();
    _InterlockedIncrement(&m_isDestroyed);

    ContextMenu* self = this;
    HWND hWnd = m_hWnd;
    HMENU popMenu = m_popMenu;
    asyncCallUiThread([hWnd, popMenu] {
        ::SetPropW(hWnd, kContextMenuClassName, (HANDLE)nullptr);
        ::DestroyWindow(hWnd);

        if (popMenu)
            ::DestroyMenu(popMenu);
    });
    m_mutex.unlock();
}

bool ContextMenu::registerClass()
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEXW);
    wcex.style = CS_HREDRAW | CS_VREDRAW | CS_DROPSHADOW;
    wcex.lpfnWndProc = wndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = nullptr;
    wcex.hIcon = nullptr;
    wcex.hCursor = LoadCursorW(0, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = 0;
    wcex.lpszClassName = kContextMenuClassName;
    wcex.hIconSm = nullptr;
    return !!RegisterClassExW(&wcex);
}

void ContextMenu::show(const blink::UntrustworthyContextMenuParams& data, int64_t frameId)
{
    if (!m_webview->isContextMenuEnable())
        return;
    ContextMenu* self = this;
    m_data = data;
    m_frameId = frameId;
    UINT blinkSupportedFlag = calcBlinkSupportedFlag(data);

    asyncCallUiThread([self, blinkSupportedFlag] {
        if (0 < ContextMenu::m_isDestroyed)
            return;
        self->showMenuOnUiThread(blinkSupportedFlag);
    });
}

void ContextMenu::appendMenuText(UINT blinkSupportedFlag)
{
    //         if (!wke::g_language.get())
    //             return appendMenuTextZhcn(blinkSupportedFlag);
    // 
    //         if (std::string::npos != wke::g_language->find("zh-cn"))
    //             return appendMenuTextZhcn(blinkSupportedFlag);

    for (const auto& [id, label] : kMenuItems) {
        if (!canShowItem(blinkSupportedFlag, (mbMenuItemId)id)) {
            continue;
        }

        ::AppendMenuA(m_popMenu, MF_STRING, id, label);
    }
}

void ContextMenu::appendMenuTextZhcn(UINT blinkSupportedFlag)
{
    if (canShowItem(blinkSupportedFlag, kMbMenuSelectedTextId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuSelectedTextId, L"复制");

    if (canShowItem(blinkSupportedFlag, kMbMenuCopyImageId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuCopyImageId, L"复制图片");
    if (canShowItem(blinkSupportedFlag, kMbMenuSaveImageId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuSaveImageId, L"图片另存为");

    if (canShowItem(blinkSupportedFlag, kMbMenuInspectElementAtId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuInspectElementAtId, L"检查");

    if (canShowItem(blinkSupportedFlag, kMbMenuCutId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuCutId, L"剪切");

    if (canShowItem(blinkSupportedFlag, kMbMenuPasteId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuPasteId, L"粘贴");

    if (canShowItem(blinkSupportedFlag, kMbMenuSelectedAllId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuSelectedAllId, L"全选");

    if (canShowItem(blinkSupportedFlag, kMbMenuUndoId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuUndoId, L"撤销");

    if (canShowItem(blinkSupportedFlag, kMbMenuGoForwardId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuGoForwardId, L"前进");

    if (canShowItem(blinkSupportedFlag, kMbMenuGoBackId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuGoBackId, L"后退");

    if (canShowItem(blinkSupportedFlag, kMbMenuReloadId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuReloadId, L"刷新");

    if (canShowItem(blinkSupportedFlag, kMbMenuPrintId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuPrintId, L"打印");
}

void ContextMenu::appendMenuTextEn(UINT blinkSupportedFlag)
{
    if (canShowItem(blinkSupportedFlag, kMbMenuSelectedTextId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuSelectedTextId, L"Copy");

    if (canShowItem(blinkSupportedFlag, kMbMenuCopyImageId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuCopyImageId, L"CopyImage");
    if (canShowItem(blinkSupportedFlag, kMbMenuSaveImageId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuSaveImageId, L"Save as..");

    if (canShowItem(blinkSupportedFlag, kMbMenuInspectElementAtId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuInspectElementAtId, L"InspectElementAt");

    if (canShowItem(blinkSupportedFlag, kMbMenuCutId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuCutId, L"Cut");

    if (canShowItem(blinkSupportedFlag, kMbMenuPasteId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuPasteId, L"Paste");

    if (canShowItem(blinkSupportedFlag, kMbMenuSelectedAllId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuSelectedAllId, L"SelectedAll");

    if (canShowItem(blinkSupportedFlag, kMbMenuUndoId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuUndoId, L"Undo");

    if (canShowItem(blinkSupportedFlag, kMbMenuGoForwardId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuGoForwardId, L"GoForward");

    if (canShowItem(blinkSupportedFlag, kMbMenuGoBackId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuGoBackId, L"GoBack");

    if (canShowItem(blinkSupportedFlag, kMbMenuReloadId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuReloadId, L"Reload");

    if (canShowItem(blinkSupportedFlag, kMbMenuPrintId))
        ::AppendMenuW(m_popMenu, MF_STRING, kMbMenuPrintId, L"Print");
}

void ContextMenu::showMenuOnUiThread(UINT blinkSupportedFlag)
{
    blinkSupportedFlag = blinkSupportedFlag | kMbMenuGoForwardId | kMbMenuGoBackId | kMbMenuReloadId;
    if (!m_webview)
        return;
    if (!dispatchMbCallback(blinkSupportedFlag))
        return;

    POINT screenPt = { 0 };
    ::GetCursorPos(&screenPt);

    POINT clientPt = screenPt;
    ::ScreenToClient(m_hWnd, &clientPt);

    if (m_popMenu)
        ::DestroyMenu(m_popMenu);
    m_popMenu = ::CreatePopupMenu();

    appendMenuText(blinkSupportedFlag);

    if (0 == ::GetMenuItemCount(m_popMenu)) {
        ::DestroyMenu(m_popMenu);
        m_popMenu = nullptr;
        return;
    }

    //::ShowWindow(m_hWnd, SW_SHOWMINNOACTIVE);
    //::SetForegroundWindow(m_hWnd);
    ::SetWindowPos(m_hWnd, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE | SWP_NOSIZE | SWP_NOREPOSITION | SWP_NOACTIVATE);

    UINT flags = TPM_RIGHTBUTTON | TPM_TOPALIGN | TPM_VERPOSANIMATION | TPM_HORIZONTAL | TPM_LEFTALIGN | TPM_HORPOSANIMATION;
    ::TrackPopupMenuEx(m_popMenu, flags, clientPt.x, clientPt.y, m_hWnd, 0);
}

LRESULT CALLBACK ContextMenu::wndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    PAINTSTRUCT ps;
    HDC hdc = nullptr;
    ContextMenu* self = (ContextMenu*)GetPropW(hWnd, kContextMenuClassName);

    switch (uMsg) {
        case WM_TIMER:
            //self->hide();
            break;

        case WM_PAINT:
            hdc = ::BeginPaint(hWnd, &ps);
            self->onPaint(hWnd, hdc);
            ::EndPaint(hWnd, &ps);
            break;
        case WM_COMMAND:
        {
            UINT itemID = LOWORD(wParam);
            ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self, itemID] {
                self->onCommand(itemID);
            });
        }
        break;
        case WM_CLOSE:
            break;
        case WM_EXITMENULOOP:
            //::ShowWindow(self->m_hWnd, SW_HIDE);
            break;
    }

    return ::DefWindowProcW(hWnd, uMsg, wParam, lParam);
}

void ContextMenu::onPaint(HWND hWnd, HDC hdc)
{

}

}