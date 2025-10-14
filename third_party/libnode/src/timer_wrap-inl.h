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

#ifndef SRC_TIMER_WRAP_INL_H_
#define SRC_TIMER_WRAP_INL_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "timer_wrap.h"

#include <utility>

#include "env.h"
#include "uv.h"

namespace node {

template <typename... Args>
inline TimerWrap::TimerWrap(Environment* env, Args&&... args)
    : env_(env)
    , fn_(std::forward<Args>(args)...)
{
    uv_timer_init(env->event_loop(), &timer_);
    timer_.data = this;
}

template <typename... Args> inline TimerWrapHandle::TimerWrapHandle(Environment* env, Args&&... args)
{
    timer_ = new TimerWrap(env, std::forward<Args>(args)...);
    env->AddCleanupHook(CleanupHook, this);
}

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_TIMER_WRAP_INL_H_
