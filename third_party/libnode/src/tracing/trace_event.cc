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

#include "tracing/trace_event.h"
#include "node.h"

namespace node {
namespace tracing {

Agent* g_agent = nullptr;
v8::TracingController* g_controller = nullptr;

void TraceEventHelper::SetAgent(Agent* agent)
{
    if (agent) {
        g_agent = agent;
        g_controller = agent->GetTracingController();
    } else {
        g_agent = nullptr;
        g_controller = nullptr;
    }
}

Agent* TraceEventHelper::GetAgent()
{
    return g_agent;
}

v8::TracingController* TraceEventHelper::GetTracingController()
{
    return g_controller;
}

void TraceEventHelper::SetTracingController(v8::TracingController* controller)
{
    g_controller = controller;
}

} // namespace tracing

v8::TracingController* GetTracingController()
{
    return tracing::TraceEventHelper::GetTracingController();
}

void SetTracingController(v8::TracingController* controller)
{
    tracing::TraceEventHelper::SetTracingController(controller);
}

} // namespace node
