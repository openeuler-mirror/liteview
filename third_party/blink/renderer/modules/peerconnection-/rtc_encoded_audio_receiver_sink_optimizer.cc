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

#include "third_party/blink/renderer/modules/peerconnection/rtc_encoded_audio_receiver_sink_optimizer.h"
#include "third_party/blink/renderer/platform/heap/cross_thread_persistent.h"
#include "third_party/blink/renderer/platform/scheduler/public/post_cross_thread_task.h"
#include "third_party/blink/renderer/platform/wtf/cross_thread_functional.h"

namespace blink {

RtcEncodedAudioReceiverSinkOptimizer::RtcEncodedAudioReceiverSinkOptimizer(
    UnderlyingSinkSetter set_underlying_sink, scoped_refptr<blink::RTCEncodedAudioStreamTransformer::Broker> transformer)
    : set_underlying_sink_(std::move(set_underlying_sink))
    , transformer_(std::move(transformer))
{
}

UnderlyingSinkBase* RtcEncodedAudioReceiverSinkOptimizer::PerformInProcessOptimization(ScriptState* script_state)
{
    auto* new_sink = MakeGarbageCollected<RTCEncodedAudioUnderlyingSink>(script_state, std::move(transformer_));

    std::move(set_underlying_sink_).Run(WrapCrossThreadPersistent(new_sink));

    return new_sink;
}

} // namespace blink
