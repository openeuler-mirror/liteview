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

#ifndef SRC_NODE_MAIN_INSTANCE_H_
#define SRC_NODE_MAIN_INSTANCE_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include <cstddef>
#include <memory>

#include "node.h"
#include "node_exit_code.h"
#include "util.h"
#include "uv.h"
#include "v8.h"

namespace node {

class ExternalReferenceRegistry;
struct EnvSerializeInfo;
struct SnapshotData;

// TODO(joyeecheung): align this with the Worker/WorkerThreadData class.
// We may be able to create an abstract class to reuse some of the routines.
class NodeMainInstance {
public:
    // Create a main instance that owns the isolate
    NodeMainInstance(const SnapshotData* snapshot_data, uv_loop_t* event_loop, MultiIsolatePlatform* platform, const std::vector<std::string>& args,
        const std::vector<std::string>& exec_args);
    ~NodeMainInstance();

    // Start running the Node.js instances, return the exit code when finished.
    ExitCode Run();
    void Run(ExitCode* exit_code, Environment* env);

    IsolateData* isolate_data()
    {
        return isolate_data_.get();
    }

    DeleteFnPtr<Environment, FreeEnvironment> CreateMainEnvironment(ExitCode* exit_code);

    NodeMainInstance(const NodeMainInstance&) = delete;
    NodeMainInstance& operator=(const NodeMainInstance&) = delete;
    NodeMainInstance(NodeMainInstance&&) = delete;
    NodeMainInstance& operator=(NodeMainInstance&&) = delete;

private:
    NodeMainInstance(v8::Isolate* isolate, uv_loop_t* event_loop, MultiIsolatePlatform* platform, const std::vector<std::string>& args,
        const std::vector<std::string>& exec_args);

    std::vector<std::string> args_;
    std::vector<std::string> exec_args_;
    std::unique_ptr<ArrayBufferAllocator> array_buffer_allocator_;
    v8::Isolate* isolate_;
    MultiIsolatePlatform* platform_;
    std::unique_ptr<IsolateData> isolate_data_;
    std::unique_ptr<v8::Isolate::CreateParams> isolate_params_;
    const SnapshotData* snapshot_data_ = nullptr;
};

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS
#endif // SRC_NODE_MAIN_INSTANCE_H_
