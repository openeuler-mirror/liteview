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

#ifndef common_ThreadCall_h
#define common_ThreadCall_h

#include "api/core/mb.h"
#include "base/location.h"
#include <functional>

#define MB_FROM_HERE FROM_HERE

namespace common {

using TraceLocation = ::base::Location;

class ThreadCall {
public:
    static void init(const mbSettings* settings);
    static void initTaskQueue();

    static void callBlinkThreadAsyncWithValid(const TraceLocation& caller, mbWebView webView, std::function<void(mb::MbWebView* webview)>&& closure);
    static void callBlinkThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callBlinkThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callUiThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callUiThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure);
    static void callMediaThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure);

    static void setThreadIdle(mbThreadCallback callback, void* param1, void* param2);
    static void setBlinkThreadInited(mbThreadCallback callback, void* param1, void* param2);

    static void postNodeCoreThreadTask(const TraceLocation& caller, std::function<void(void)>&& closure);

    static void shutdown();

    static void exitUiMessageLoop();
    static void exitBlinkMessageLoop();
    static void blinkMessageLoop(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate);
    static void uiMessageLoop();

    static DWORD getUiThreadId() { return m_uiThreadId; }
    static DWORD getBlinkThreadId() { return m_blinkThreadId; }

    static uv_loop_t* getBlinkLoop() { return m_blinkLoop; }

    static bool isBlinkThread();
    static bool isUiThread();

    static void wake();
    static bool runNoWait(DWORD threadId);
    static bool runUntilIdle(DWORD threadId);

    static void setThreadName(const char* szThreadName);
};

}

#endif
