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

#ifndef patch_code_std_condition_variable_h
#define patch_code_std_condition_variable_h

#include "sync_xp.h"
#include "std_mutex_xp.h"

class std_condition_variable { // class for waiting for conditions
public:
    std_condition_variable() { InitializeConditionVariableXp(&m_condVar); }

    ~std_condition_variable() { }

    std_condition_variable(const std_condition_variable&) = delete;
    std_condition_variable& operator=(const std_condition_variable&) = delete;

    void notify_one()
    { // wake up one waiter
        WakeConditionVariableXp(&m_condVar);
    }

    void notify_all()
    { // wake up all waiters
        WakeConditionVariableXp(&m_condVar);
    }

    void wait(std::unique_lock<std_mutex>& lock)
    { // wait for signal
        // Nothing to do to comply with LWG-2135 because std::mutex lock/unlock are nothrow
        SleepConditionVariableCS(&m_condVar, (PCRITICAL_SECTION)lock.mutex()->getLock(), (DWORD)-1);
    }

private:
    CONDITION_VARIABLE m_condVar;
};

#endif // patch_code_std_condition_variable_h