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

#ifndef SRC_INSPECTOR_WORKER_AGENT_H_
#define SRC_INSPECTOR_WORKER_AGENT_H_

#include "node/inspector/protocol/NodeWorker.h"
#include "v8.h"

namespace node {
namespace inspector {
class WorkerManagerEventHandle;
class WorkerManager;

namespace protocol {
class NodeWorkers;

class WorkerAgent : public NodeWorker::Backend {
public:
    explicit WorkerAgent(std::weak_ptr<WorkerManager> manager);
    ~WorkerAgent() override = default;

    void Wire(UberDispatcher* dispatcher);

    DispatchResponse sendMessageToWorker(const String& message, const String& sessionId) override;

    DispatchResponse enable(bool waitForDebuggerOnStart) override;
    DispatchResponse disable() override;
    DispatchResponse detach(const String& sessionId) override;

private:
    std::shared_ptr<NodeWorker::Frontend> frontend_;
    std::weak_ptr<WorkerManager> manager_;
    std::unique_ptr<WorkerManagerEventHandle> event_handle_;
    std::shared_ptr<NodeWorkers> workers_;
};
} // namespace protocol
} // namespace inspector
} // namespace node

#endif // SRC_INSPECTOR_WORKER_AGENT_H_
