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

#ifndef SRC_DIAGNOSTICFILENAME_INL_H_
#define SRC_DIAGNOSTICFILENAME_INL_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "node_internals.h"
namespace node {

class Environment;

inline DiagnosticFilename::DiagnosticFilename(Environment* env, const char* prefix, const char* ext)
    : filename_(MakeFilename(env->thread_id(), prefix, ext))
{
}

inline DiagnosticFilename::DiagnosticFilename(uint64_t thread_id, const char* prefix, const char* ext)
    : filename_(MakeFilename(thread_id, prefix, ext))
{
}

inline const char* DiagnosticFilename::operator*() const
{
    return filename_.c_str();
}

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_DIAGNOSTICFILENAME_INL_H_
