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

#ifndef QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_THREAD_IMPL_H_
#define QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_THREAD_IMPL_H_

#include <string>
#include <thread> // NOLINT: only used outside of google3

#include "absl/types/optional.h"
#include "quiche/common/platform/api/quiche_export.h"

class QUICHE_NO_EXPORT QuicheThreadImpl {
public:
    QuicheThreadImpl(const std::string&) { }
    virtual ~QuicheThreadImpl() { }

    virtual void Run() = 0;

    void Start()
    {
        thread_.emplace([this]() { Run(); });
    }
    void Join() { thread_->join(); }

private:
    absl::optional<std::thread> thread_;
};

#endif // QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_THREAD_IMPL_H_
