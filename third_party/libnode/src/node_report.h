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

#ifndef SRC_NODE_REPORT_H_
#define SRC_NODE_REPORT_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "node.h"
#include "node_buffer.h"
#include "uv.h"
#include "util.h"

#ifndef _WIN32
#include <sys/types.h>
#include <unistd.h>
#endif

#include <iomanip>
#include <sstream>

namespace node {
namespace report {
// Function declarations - utility functions in src/node_report_utils.cc
void WalkHandle(uv_handle_t* h, void* arg);

template <typename T> std::string ValueToHexString(T value)
{
    std::stringstream hex;

    hex << "0x" << std::setfill('0') << std::setw(sizeof(T) * 2) << std::hex << value;
    return hex.str();
}

// Function declarations - export functions in src/node_report_module.cc
void WriteReport(const v8::FunctionCallbackInfo<v8::Value>& info);
void GetReport(const v8::FunctionCallbackInfo<v8::Value>& info);

} // namespace report
} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_NODE_REPORT_H_
