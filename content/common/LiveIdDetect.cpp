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


#include "content/common/LiveIdDetect.h"

namespace common {

LiveIdDetect* LiveIdDetect::m_inst = nullptr;
LiveIdDetect* LiveIdDetect::m_mbwebviewIds = nullptr;

LiveIdDetect::LiveIdDetect()
{
    m_idGen = 0;
    ::InitializeCriticalSection(&m_lock);
}

int64_t LiveIdDetect::constructed(void* ptr)
{
    if (isActivating(ptr))
        DebugBreak();

    ::EnterCriticalSection(&m_lock);
    int64_t id = ++m_idGen;
    m_liveSelf.insert(std::pair<int64_t, void*>(id, ptr));

    std::map<void*, int64_t> ::const_iterator it = m_ptrToIdMaps.find(ptr);
    if (it != m_ptrToIdMaps.end())
        DebugBreak();
    m_ptrToIdMaps.insert(std::pair<void*, int64_t>(ptr, id));
    ::LeaveCriticalSection(&m_lock);
    return id;
}

void LiveIdDetect::deconstructed(int64_t id)
{
    ::EnterCriticalSection(&m_lock);
    std::map<int64_t, void*> ::const_iterator it = m_liveSelf.find(id);
    if (it == m_liveSelf.end()) {
        ::LeaveCriticalSection(&m_lock);
        return;
    }
    void* ptr = it->second;
    m_liveSelf.erase(it);

    std::map<void*, int64_t> ::const_iterator it2 = m_ptrToIdMaps.find(ptr);
    if (it2 == m_ptrToIdMaps.end())
        DebugBreak();
    m_ptrToIdMaps.erase(it2);
    ::LeaveCriticalSection(&m_lock);
}

void* LiveIdDetect::getPtr(int64_t id)
{
    ::EnterCriticalSection(&m_lock);
    std::map<int64_t, void*>::const_iterator it = m_liveSelf.find(id);
    if (it == m_liveSelf.end()) {
        ::LeaveCriticalSection(&m_lock);
        return nullptr;
    }
    void* ptr = it->second;
    ::LeaveCriticalSection(&m_lock);

    return ptr;
}

void* LiveIdDetect::getPtrLocked(int64_t id)
{
    ::EnterCriticalSection(&m_lock);
    std::map<int64_t, void*>::const_iterator it = m_liveSelf.find(id);
    if (it == m_liveSelf.end()) {
        ::LeaveCriticalSection(&m_lock);
        return nullptr;
    }
    void* ptr = it->second;

    return ptr;
}

int64_t LiveIdDetect::getIdLocked(void* ptr)
{
    int64_t id = -1;
    ::EnterCriticalSection(&m_lock);
    std::map<void*, int64_t> ::const_iterator it = m_ptrToIdMaps.find(ptr);

    if (it == m_ptrToIdMaps.end())
        ::LeaveCriticalSection(&m_lock);
    else
        id = it->second;

    return id;
}

void LiveIdDetect::unlock(int64_t id, void*)
{
    ::LeaveCriticalSection(&m_lock);
}

LiveIdDetect* LiveIdDetect::get()
{
    if (!m_inst)
        m_inst = new LiveIdDetect();
    return m_inst;
}

// 单独为MbWebviews开个，否则
// 合成线程的MbWebView::delayDoMouseMsgInCompositorThread和blink线程的ResourceLoader-》ReceiverImplBase::ReceiverImplBase
// 会死锁
LiveIdDetect* LiveIdDetect::getMbWebviewIds()
{
    if (!m_mbwebviewIds)
        m_mbwebviewIds = new LiveIdDetect();
    return m_mbwebviewIds;
}

bool LiveIdDetect::isLive(int64_t id)
{
    ::EnterCriticalSection(&m_lock);
    std::map<int64_t, void*> ::const_iterator it = m_liveSelf.find(id);
    bool b = it != m_liveSelf.end();
    ::LeaveCriticalSection(&m_lock);
    return b;
}

bool LiveIdDetect::isActivating(void* ptr)
{
    bool b = false;
    ::EnterCriticalSection(&m_lock);

    std::map<void*, int64_t> ::const_iterator it = m_ptrToIdMaps.find(ptr);
    b = it != m_ptrToIdMaps.end();

    ::LeaveCriticalSection(&m_lock);
    return b;
}

}