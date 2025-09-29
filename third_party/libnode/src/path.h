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

#ifndef SRC_PATH_H_
#define SRC_PATH_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include <string>
#include <vector>

namespace node {

class Environment;

bool IsPathSeparator(const char c) noexcept;

std::string NormalizeString(const std::string_view path, bool allowAboveRoot, const std::string_view separator);

std::string PathResolve(Environment* env, const std::vector<std::string_view>& args);
} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_PATH_H_
