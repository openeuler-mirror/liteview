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


#include "base/memory/direct_mem_mgr.h"
#include "base/memory/aligned_memory.h"
#include "base/system/sys_info.h"
#include "base/bits.h"

namespace base {

DirectMemMgr::DirectMemMgr()
{
    id_gen_ = 0;
}

DirectMemMgr::~DirectMemMgr()
{
}

DirectMemMgr::Item::~Item()
{
    if (addr)
        AlignedFree(addr);
}

uintptr_t DirectMemMgr::NewMemory(size_t size, void** ptr)
{
    AutoLock locker(lock_);
    uintptr_t handle = ++id_gen_;

    Item* item = new Item();
    *ptr = AlignedAlloc(size, 32/*kMapMinimumAlignment*/);;

    item->addr = *ptr;
    item->size = size;
    item->ref = 1;

    handle_map_.insert(std::pair<uintptr_t, Item*>(handle, item));
    return handle;
}

void* DirectMemMgr::MapView(uintptr_t handle, size_t* size)
{
    AutoLock locker(lock_);
    std::unordered_map<uintptr_t, Item*>::const_iterator it = handle_map_.find(handle);
    if (it == handle_map_.end())
        return nullptr;

    Item* item = it->second;
    *size = item->size;
    item->ref++; // this is importance
    return item->addr;
}

static bool IsInAddrScope(uintptr_t begin, size_t len, uintptr_t addr, size_t size)
{
    uintptr_t aligned_begin = (uintptr_t)bits::AlignDown((const uint8_t*)begin, (uint64_t)(SysInfo::VMAllocationGranularity()));
    return (aligned_begin == (uintptr_t)addr && (uintptr_t)begin + len == (uintptr_t)addr + size);
}

bool DirectMemMgr::Unmap(void* addr, size_t size)
{
    AutoLock locker(lock_);
    std::unordered_map<uintptr_t, Item*>::const_iterator it = handle_map_.begin();
    for (; it != handle_map_.end(); ++it) {
        Item* item = it->second;
        if (IsInAddrScope((uintptr_t)item->addr, item->size, (uintptr_t)addr, size)) {
            item->ref--;
            if (item->ref == 0) {
                delete item;
                handle_map_.erase(it);
            }
            return true;
        }
    }
    return false;
}

uintptr_t DirectMemMgr::Duplicate(uintptr_t handle)
{
    AutoLock locker(lock_);
    std::unordered_map<uintptr_t, Item*> ::const_iterator it = handle_map_.find(handle);
    if (it == handle_map_.end())
        return 0;
    Item* item = it->second;
    item->ref++;
    return handle;
}

void DirectMemMgr::Free(uintptr_t handle)
{
    AutoLock locker(lock_);
    std::unordered_map<uintptr_t, Item*> ::const_iterator it = handle_map_.find(handle);
    if (it == handle_map_.end())
        return;
    Item* item = it->second;
    item->ref--;
    if (item->ref == 0) {
        delete item;
        handle_map_.erase(it);
    }
}

}