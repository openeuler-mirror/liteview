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

#ifndef SRC_NODE_MEM_H_
#define SRC_NODE_MEM_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include <cstddef>

namespace node {
namespace mem {

// nghttp2 allows custom allocators that
// follow exactly the same structure and behavior, but
// use different struct names. To allow for code re-use,
// the NgLibMemoryManager template class can be used for both.

struct NgLibMemoryManagerBase {
    virtual void StopTrackingMemory(void* ptr) = 0;
};

template <typename Class, typename AllocatorStructName> class NgLibMemoryManager : public NgLibMemoryManagerBase {
public:
    // Class needs to provide these methods:
    // void CheckAllocatedSize(size_t previous_size) const;
    // void IncreaseAllocatedSize(size_t size);
    // void DecreaseAllocatedSize(size_t size);
    // Environment* env() const;

    AllocatorStructName MakeAllocator();

    void StopTrackingMemory(void* ptr) override;

private:
    static void* ReallocImpl(void* ptr, size_t size, void* user_data);
    static void* MallocImpl(size_t size, void* user_data);
    static void FreeImpl(void* ptr, void* user_data);
    static void* CallocImpl(size_t nmemb, size_t size, void* user_data);
};

} // namespace mem
} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_NODE_MEM_H_
