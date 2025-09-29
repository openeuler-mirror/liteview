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

#ifndef ActivatingLoaderCheck_h
#define ActivatingLoaderCheck_h

#include <set>
#include <windows.h>

namespace mbnet {

class ActivatingObjCheck {
public:
    ActivatingObjCheck();
    ~ActivatingObjCheck();

    static ActivatingObjCheck* inst();

    void shutdown();
    void destroy();

    void add(intptr_t obj);
    void remove(intptr_t obj);
    bool isActivating(intptr_t obj);
    bool isActivatingLocked(intptr_t obj);
    void unlock();

    void doGarbageCollected(bool forceGC);

    void testPrint();

    int genId();

private:
    std::set<intptr_t>* m_activatingObjs;
    CRITICAL_SECTION m_mutex;
    int m_newestId;

    static ActivatingObjCheck* m_inst;
};

} // net

#endif // ActivatingLoaderCheck_h