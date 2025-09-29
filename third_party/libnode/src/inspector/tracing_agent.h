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

#ifndef SRC_INSPECTOR_TRACING_AGENT_H_
#define SRC_INSPECTOR_TRACING_AGENT_H_

#include "node/inspector/protocol/NodeTracing.h"
#include "tracing/agent.h"
#include "v8.h"

namespace node {
class Environment;

namespace inspector {
class MainThreadHandle;

namespace protocol {

class TracingAgent : public NodeTracing::Backend {
public:
    explicit TracingAgent(Environment*, std::shared_ptr<MainThreadHandle>);
    ~TracingAgent() override;

    void Wire(UberDispatcher* dispatcher);

    DispatchResponse start(std::unique_ptr<protocol::NodeTracing::TraceConfig> traceConfig) override;
    DispatchResponse stop() override;
    DispatchResponse getCategories(std::unique_ptr<protocol::Array<String>>* categories) override;

private:
    Environment* env_;
    std::shared_ptr<MainThreadHandle> main_thread_;
    tracing::AgentWriterHandle trace_writer_;
    int frontend_object_id_ = 0;
    std::shared_ptr<NodeTracing::Frontend> frontend_;
};

} // namespace protocol
} // namespace inspector
} // namespace node

#endif // SRC_INSPECTOR_TRACING_AGENT_H_
