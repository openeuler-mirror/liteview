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

#include "third_party/blink/renderer/platform/scheduler/test/fuzzer/simple_thread_impl.h"

#include "third_party/blink/renderer/platform/scheduler/test/fuzzer/thread_manager.h"
#include "third_party/blink/renderer/platform/scheduler/test/fuzzer/thread_pool_manager.h"

namespace base {
namespace sequence_manager {

SimpleThreadImpl::SimpleThreadImpl(ThreadPoolManager* thread_pool_manager, base::TimeTicks initial_time, ThreadCallback callback)
    : SimpleThread("TestThread")
    , thread_pool_manager_(thread_pool_manager)
    , initial_time_(initial_time)
    , callback_(std::move(callback))
{
    DCHECK(thread_pool_manager_);
}

void SimpleThreadImpl::Run()
{
    std::unique_ptr<ThreadManager> thread_manager = std::make_unique<ThreadManager>(initial_time_, thread_pool_manager_->processor());
    thread_manager_ = thread_manager.get();
    std::move(callback_).Run(thread_manager_);
    thread_can_shutdown_.Wait();
}

SimpleThreadImpl::~SimpleThreadImpl()
{
    thread_can_shutdown_.Signal();
    Join();
}

} // namespace sequence_manager
} // namespace base
