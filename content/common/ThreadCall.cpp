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


#include "content/common/ThreadCall.h"

#include "content/browser/SharedTimerWin.h"
#include "content/renderer/RenderThreadImpl.h"
#include "content/common/LiveIdDetect.h"
#include "base/run_loop.h"
#include "v8/include/libplatform/libplatform.h"
#ifdef _WIN32
#include "third_party/libuv/include/uv.h"
#endif // _WIN32

base::RunLoop* g_mainThreadRunLoop = nullptr;

namespace content {

ThreadCall* ThreadCall::m_inst = nullptr;
uv_loop_t* ThreadCall::m_uiUvLoop = nullptr;
uv_loop_t* ThreadCall::m_blinkUvLoop = nullptr;
v8::Platform* ThreadCall::m_UiV8Platform = nullptr;

ThreadCall::ThreadCall()
{

}

void ThreadCall::init(const mbSettings* settings)
{
    m_inst = new ThreadCall();
    g_mainThreadRunLoop = new base::RunLoop();
    m_inst->m_uiThreadId = ::GetCurrentThreadId();
    m_inst->m_uiThreadTask = base::ThreadTaskRunnerHandle::Get();
}

void ThreadCall::initializeWebKit()
{
#ifdef _WIN32
    m_blinkUvLoop = new uv_loop_t();
    uv_loop_init(m_blinkUvLoop);
#endif
}

void ThreadCall::callBlinkThreadAsyncWithValid(const TraceLocation& caller, mbWebView webviewHandle, std::function<void(MbWebView* webview)>&& closure)
{
    int64_t id = (int64_t)webviewHandle;
    std::function<void(MbWebView* webview)>* closureDummy = new std::function<void(MbWebView* webview)>(std::move(closure));

    callBlinkThreadAsync(caller, [id, closureDummy] {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(id);
        if (webview)
            (*closureDummy)(webview);
        delete closureDummy;
    });
}

void ThreadCall::callBlinkThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    RenderThreadImpl::get()->getTaskRunner()->PostNonNestableTask(caller, base::BindOnce([] (std::function<void(void)>&& closure){
        (closure)();
    }, std::move(closure)));
}

void ThreadCall::callBlinkThreadAsyncWithValidDelayed(const TraceLocation& caller, mbWebView webviewHandle, size_t millisecond, std::function<void(MbWebView* webview)>&& closure)
{
    int64_t id = (int64_t)webviewHandle;
    std::function<void(MbWebView* webview)>* closureDummy = new std::function<void(MbWebView* webview)>(std::move(closure));

    RenderThreadImpl::get()->getTaskRunner()->PostDelayedTask(caller, base::BindOnce([](std::function<void(MbWebView* webview)>* closure, int64_t id) {
        MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(id);
        if (webview)
            (*closure)(webview);
        delete closure;
    }, closureDummy, id), base::Milliseconds(millisecond));
}

void ThreadCall::callBlinkThreadDelayed(const TraceLocation& caller, std::function<void(void)>&& closure, size_t millisecond)
{
    RenderThreadImpl::get()->getTaskRunner()->PostDelayedTask(caller, base::BindOnce([](std::function<void(void)>&& closure) {
        (closure)();
    }, std::move(closure)), base::Milliseconds(millisecond));
}

void ThreadCall::callUiThreadDelayed(const TraceLocation& caller, std::function<void(void)>&& closure, size_t millisecond)
{
    m_inst->m_uiThreadTask->PostDelayedTask(caller, base::BindOnce([](std::function<void(void)>&& closure) {
        (closure)();
    }, std::move(closure)), base::Milliseconds(millisecond));
}

void ThreadCall::callUiThreadAsync(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    m_inst->m_uiThreadTask->PostNonNestableTask(caller, base::BindOnce([](std::function<void(void)>&& closure) {
        (closure)();
    }, std::move(closure)));
}

typedef void (*CoreMainTask)(void* data);
struct TaskAsyncData {
    CoreMainTask call;
    void* data;
    void* dataEx;
    BOOL evt;
    void* ret;
    DWORD fromThreadId;
    DWORD toThreadId;
    DWORD destroyThreadId;
    TraceLocation caller;
};

TaskAsyncData* cretaeAsyncData(const TraceLocation& caller, DWORD toThreadId, void* dataEx, DWORD destroyThreadId)
{
    TaskAsyncData* asyncData = new TaskAsyncData();
    asyncData->evt = FALSE;
    asyncData->dataEx = dataEx;
    asyncData->fromThreadId = ::GetCurrentThreadId();
    asyncData->toThreadId = toThreadId;
    asyncData->destroyThreadId = destroyThreadId;
    asyncData->caller = caller;

    return asyncData;
}

void ThreadCall::callThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure, scoped_refptr<base::SingleThreadTaskRunner> runner)
{
    TaskAsyncData* asyncData = cretaeAsyncData(caller, RenderThreadImpl::get()->GetBlinkThreadId(), &closure, ::GetCurrentThreadId());

    runner->PostNonNestableTask(caller, base::BindOnce([](
        std::function<void(void)>&& closure, TaskAsyncData* asyncData) {
        (closure)();
        asyncData->evt = TRUE;
    }, std::move(closure), base::Unretained(asyncData)));

    waitForCallThreadAsync(asyncData);
    delete asyncData;
}

void ThreadCall::callUiThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    if (isUiThread()) {
        closure();
        return;
    }    
    callThreadSync(caller, std::move(closure), m_inst->m_uiThreadTask);
}

void ThreadCall::callBlinkThreadSync(const TraceLocation& caller, std::function<void(void)>&& closure)
{
    if (isBlinkThread()) {
        closure();
        return;
    }
    callThreadSync(caller, std::move(closure), RenderThreadImpl::get()->getTaskRunner());
}

void* ThreadCall::waitForCallThreadAsync(TaskAsyncData* asyncData)
{
    bool firstPost = false;
    void* ret = asyncData->ret;
    while (!asyncData->evt) {
        ::Sleep(1);

        // 有npapi插件的时候，createwebview会死等，然后主窗口又可能会发消息给npapi窗口，造成死锁
        MSG msg;
        if (::PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE) != FALSE) {
            ::TranslateMessage(&msg);
            ::DispatchMessageW(&msg);
        }

        if (!firstPost)
            ::PostThreadMessageW(::GetCurrentThreadId(), WM_NULL, 0, 0);
        firstPost = true;
    }

    return ret;
}

bool ThreadCall::isBlinkThread()
{
    return RenderThreadImpl::get()->isCurrentThread();
}

bool ThreadCall::isUiThread()
{
    if (!m_inst)
        return true;
    return m_inst->m_uiThreadId == ::GetCurrentThreadId();
}

void ThreadCall::wake()
{

}

void ThreadCall::onThreadIdle(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate)
{
#ifdef _WIN32
    bool more = (0 != uv_run(loop, UV_RUN_NOWAIT));
    if (platform) {
        v8::platform::PumpMessageLoop(platform, isolate);
    }
    base::SingleThreadTaskRunner::GetCurrentDefault()->PostDelayedTask(FROM_HERE, base::BindOnce(onThreadIdle, loop, platform, isolate), base::Microseconds(500));
#endif
}

void ThreadCall::runUiThreadMessageLoop(uv_loop_t* loop, v8::Platform* platform, v8::Isolate* isolate)
{
#if defined(OS_WIN)
    content::stopSharedTimer();
#endif
    if (loop) {
        m_uiUvLoop = loop;
        m_UiV8Platform = platform;
        m_inst->m_uiThreadTask->PostDelayedTask(FROM_HERE, base::BindOnce(onThreadIdle, loop, platform, isolate), base::Microseconds(500)); // 暂时先轮询，以后改成根据libuv定时器和iocp触发
    }

    g_mainThreadRunLoop->Run();
}

void ThreadCall::runBlinkThreadNode(uv_loop_t* loop, v8::Isolate* isolate)
{
    RenderThreadImpl::get()->getTaskRunner()->PostDelayedTask(FROM_HERE, base::BindOnce(onThreadIdle, loop, nullptr, isolate), base::Microseconds(500));
}

bool ThreadCall::isInitUiThread()
{
    return !!g_mainThreadRunLoop;
}

void ThreadCall::exitUiThreadMessageLoop()
{
    g_mainThreadRunLoop->Quit();
}

}

extern "C" bool ThreadCallIsUiThread()
{
    return content::ThreadCall::isUiThread();
}
