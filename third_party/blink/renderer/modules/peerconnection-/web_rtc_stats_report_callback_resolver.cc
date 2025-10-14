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

#include "third_party/blink/renderer/modules/peerconnection/web_rtc_stats_report_callback_resolver.h"

#include "third_party/blink/renderer/bindings/core/v8/script_promise_resolver.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/renderer/platform/peerconnection/rtc_stats.h"

namespace blink {

void WebRTCStatsReportCallbackResolver(ScriptPromiseResolver* resolver, std::unique_ptr<RTCStatsReportPlatform> report)
{
    DCHECK(ExecutionContext::From(resolver->GetScriptState())->IsContextThread());
    resolver->Resolve(MakeGarbageCollected<RTCStatsReport>(std::move(report)));
}

} // namespace blink
