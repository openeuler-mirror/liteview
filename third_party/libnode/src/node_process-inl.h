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

#ifndef SRC_NODE_PROCESS_INL_H_
#define SRC_NODE_PROCESS_INL_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "node_process.h"
#include "v8.h"
#include "debug_utils-inl.h"

namespace node {

// Call process.emitWarning(str), fmt is a snprintf() format string
template <typename... Args> inline v8::Maybe<bool> ProcessEmitWarning(Environment* env, const char* fmt, Args&&... args)
{
    std::string warning = SPrintF(fmt, std::forward<Args>(args)...);

    return ProcessEmitWarningGeneric(env, warning.c_str());
}

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_NODE_PROCESS_INL_H_
