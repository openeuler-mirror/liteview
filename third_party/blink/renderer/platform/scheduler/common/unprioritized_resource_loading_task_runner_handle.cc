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

#include "third_party/blink/renderer/platform/scheduler/common/unprioritized_resource_loading_task_runner_handle.h"

#include "base/memory/ptr_util.h"

namespace blink {
namespace scheduler {

std::unique_ptr<UnprioritizedResourceLoadingTaskRunnerHandle> UnprioritizedResourceLoadingTaskRunnerHandle::WrapTaskRunner(
    scoped_refptr<base::SingleThreadTaskRunner> task_runner)
{
    DCHECK(task_runner);
    return base::WrapUnique(new UnprioritizedResourceLoadingTaskRunnerHandle(std::move(task_runner)));
}

UnprioritizedResourceLoadingTaskRunnerHandle::UnprioritizedResourceLoadingTaskRunnerHandle(scoped_refptr<base::SingleThreadTaskRunner> task_runner)
    : task_runner_(std::move(task_runner))
{
}

scoped_refptr<base::SingleThreadTaskRunner> UnprioritizedResourceLoadingTaskRunnerHandle::GetTaskRunner() const
{
    return task_runner_;
}

void UnprioritizedResourceLoadingTaskRunnerHandle::DidChangeRequestPriority(net::RequestPriority priority)
{
}

} // namespace scheduler
} // namespace blink
