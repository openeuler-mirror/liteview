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

#ifndef SRC_NODE_BOB_INL_H_
#define SRC_NODE_BOB_INL_H_

#include "node_bob.h"

#include <functional>

namespace node {
namespace bob {

template <typename T> int SourceImpl<T>::Pull(Next<T> next, int options, T* data, size_t count, size_t max_count_hint)
{

    int status;
    if (eos_) {
        status = bob::Status::STATUS_EOS;
        std::move(next)(status, nullptr, 0, [](size_t len) {});
        return status;
    }

    status = DoPull(std::move(next), options, data, count, max_count_hint);

    if (status == bob::Status::STATUS_EOS)
        eos_ = true;

    return status;
}

} // namespace bob
} // namespace node

#endif // SRC_NODE_BOB_INL_H_
