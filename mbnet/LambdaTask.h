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

#ifndef net_LambdaTask_h
#define net_LambdaTask_h

#include "third_party/WebKit/public/platform/WebThread.h"
#include "third_party/WebKit/public/platform/WebTraceLocation.h"
#include "third_party/WebKit/public/platform/Platform.h"
#include <wtf/MainThread.h>
#include <functional>

namespace net {

class LambdaTask : public blink::WebThread::Task {
public:
    LambdaTask(std::function<void()>&& func)
        : m_func(func) {}
    virtual ~LambdaTask() override {}

    virtual void run() override { m_func(); }

    static void asyncCall(std::function<void()>&& func)
    {
        blink::Platform::current()->currentThread()->postTask(FROM_HERE, new LambdaTask(std::move(func)));
    }

private:
    std::function<void()> m_func;
};

}

#endif // net_LambdaTask_h