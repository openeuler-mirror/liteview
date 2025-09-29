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

#include "runtime_agent.h"

#include "env-inl.h"
#include "inspector_agent.h"

namespace node {
namespace inspector {
namespace protocol {

RuntimeAgent::RuntimeAgent()
    : notify_when_waiting_for_disconnect_(false)
    , enabled_(false)
    , is_waiting_for_debugger_(false)
{
}

void RuntimeAgent::Wire(UberDispatcher* dispatcher)
{
    frontend_ = std::make_unique<NodeRuntime::Frontend>(dispatcher->channel());
    NodeRuntime::Dispatcher::wire(dispatcher, this);
}

DispatchResponse RuntimeAgent::notifyWhenWaitingForDisconnect(bool enabled)
{
    notify_when_waiting_for_disconnect_ = enabled;
    return DispatchResponse::OK();
}

DispatchResponse RuntimeAgent::enable()
{
    enabled_ = true;
    if (is_waiting_for_debugger_) {
        frontend_->waitingForDebugger();
    }
    return DispatchResponse::OK();
}

DispatchResponse RuntimeAgent::disable()
{
    enabled_ = false;
    return DispatchResponse::OK();
}

void RuntimeAgent::setWaitingForDebugger()
{
    is_waiting_for_debugger_ = true;
    if (enabled_) {
        frontend_->waitingForDebugger();
    }
}

void RuntimeAgent::unsetWaitingForDebugger()
{
    is_waiting_for_debugger_ = false;
}

bool RuntimeAgent::notifyWaitingForDisconnect()
{
    if (notify_when_waiting_for_disconnect_) {
        frontend_->waitingForDisconnect();
        return true;
    }
    return false;
}
} // namespace protocol
} // namespace inspector
} // namespace node
