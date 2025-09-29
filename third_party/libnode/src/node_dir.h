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

#ifndef SRC_NODE_DIR_H_
#define SRC_NODE_DIR_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "node_file.h"

namespace node {

namespace fs_dir {

// Needed to propagate `uv_dir_t`.
class DirHandle : public AsyncWrap {
public:
    static DirHandle* New(Environment* env, uv_dir_t* dir);
    ~DirHandle() override;

    static void New(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void Read(const v8::FunctionCallbackInfo<v8::Value>& args);
    static void Close(const v8::FunctionCallbackInfo<v8::Value>& args);

    inline uv_dir_t* dir()
    {
        return dir_;
    }

    void MemoryInfo(MemoryTracker* tracker) const override;
    SET_MEMORY_INFO_NAME(DirHandle)
    SET_SELF_SIZE(DirHandle)

    DirHandle(const DirHandle&) = delete;
    DirHandle& operator=(const DirHandle&) = delete;
    DirHandle(const DirHandle&&) = delete;
    DirHandle& operator=(const DirHandle&&) = delete;

private:
    DirHandle(Environment* env, v8::Local<v8::Object> obj, uv_dir_t* dir);

    // Synchronous close that emits a warning
    void GCClose();

    uv_dir_t* dir_;
    // Multiple entries are read through a single libuv call.
    std::vector<uv_dirent_t> dirents_;
    bool closing_ = false;
    bool closed_ = false;
};

} // namespace fs_dir

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_NODE_DIR_H_
