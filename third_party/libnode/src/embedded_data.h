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

#ifndef SRC_EMBEDDED_DATA_H_
#define SRC_EMBEDDED_DATA_H_

#include <cinttypes>
#include <string>

// This file must not depend on node.h or other code that depends on
// the full Node.js implementation because it is used during the
// compilation of the Node.js implementation itself (especially js2c).

namespace node {

const std::string& GetOctalCode(uint8_t index);

} // namespace node

#endif // SRC_EMBEDDED_DATA_H_
