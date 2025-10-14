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

#include "third_party/blink/renderer/modules/peerconnection/rtc_encoded_audio_receiver_source_optimizer.h"
#include "third_party/blink/renderer/platform/heap/cross_thread_persistent.h"
#include "third_party/blink/renderer/platform/scheduler/public/post_cross_thread_task.h"
#include "third_party/blink/renderer/platform/wtf/cross_thread_functional.h"

namespace blink {

RtcEncodedAudioReceiverSourceOptimizer::RtcEncodedAudioReceiverSourceOptimizer(
    UnderlyingSourceSetter set_underlying_source, WTF::CrossThreadOnceClosure disconnect_callback)
    : set_underlying_source_(std::move(set_underlying_source))
    , disconnect_callback_(std::move(disconnect_callback))
{
}

UnderlyingSourceBase* RtcEncodedAudioReceiverSourceOptimizer::PerformInProcessOptimization(ScriptState* script_state)
{
    ExecutionContext* context = ExecutionContext::From(script_state);

    scoped_refptr<base::SingleThreadTaskRunner> current_runner = context->GetTaskRunner(TaskType::kInternalMediaRealTime);

    auto* new_source = MakeGarbageCollected<RTCEncodedAudioUnderlyingSource>(script_state, std::move(disconnect_callback_),
        /*is_receiver=*/true);

    set_underlying_source_.Run(WrapCrossThreadPersistent(new_source), std::move(current_runner));

    return new_source;
}

} // namespace blink
