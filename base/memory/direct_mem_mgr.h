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


#ifndef base_memory_direct_mem_mgr_h
#define base_memory_direct_mem_mgr_h

#include "base/synchronization/lock.h"
#include <unordered_map>
#include <stdint.h>

namespace base {

class DirectMemMgr {
public:
    DirectMemMgr();
    ~DirectMemMgr();

    struct Item {
        void* addr = nullptr;
        size_t size = 0;
        int ref = 0;

        ~Item();
    };

    static DirectMemMgr* Get()
    {
        if (!inst_)
            inst_ = new DirectMemMgr();
        return inst_;
    }

    uintptr_t NewMemory(size_t size, void** ptr);

    void* MapView(uintptr_t handle, size_t* size);

    bool Unmap(void* addr, size_t size);

    uintptr_t Duplicate(uintptr_t handle);

    void Free(uintptr_t handle);

private:
    uintptr_t id_gen_;
    std::unordered_map<uintptr_t, Item*> handle_map_;
    Lock lock_;
    static DirectMemMgr* inst_;
};

}

#endif // base_memory_direct_mem_mgr_h