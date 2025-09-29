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


#ifndef MbInternalApi_h
#define MbInternalApi_h

#include "mbvip/core/mb.h"

// 不知道为啥，如果在mb内部直接调用mbXXX api，在某些linux下会报错，导出表被改了
void mbDestroyWebViewImpl(mbWebView webviewHandle);
void mbShowWindowImpl(mbWebView webviewHandle, BOOL b);
BOOL mbFireMouseEventImpl(mbWebView webviewHandle, unsigned int message, int x, int y, unsigned int flags);
BOOL mbFireKeyPressEventImpl(mbWebView webviewHandle, unsigned int charCode, unsigned int flags, BOOL isSystemKey);
BOOL mbFireKeyUpEventImpl(mbWebView webviewHandle, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey);
BOOL mbFireKeyDownEventImpl(mbWebView webviewHandle, unsigned int virtualKeyCode, unsigned int flags, BOOL isSystemKey);
BOOL mbFireMouseWheelEventImpl(mbWebView webviewHandle, int x, int y, int wheelDelta, unsigned int flags);
BOOL mbFireWindowsMessageImpl(mbWebView webviewHandle, HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam, LRESULT* result);

using FN_OutputDebugString = void(__cdecl*)(const char* str);
extern FN_OutputDebugString g_outputDebugString;
extern bool g_isDownloadVersion2;

#endif // MbInternalApi_h