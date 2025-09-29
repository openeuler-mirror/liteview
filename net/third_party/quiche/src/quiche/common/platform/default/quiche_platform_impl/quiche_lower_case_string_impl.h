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

#ifndef QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_LOWER_CASE_STRING_IMPL_H_
#define QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_LOWER_CASE_STRING_IMPL_H_

#include <string>

#include "absl/strings/ascii.h"
#include "absl/strings/string_view.h"
#include "quiche/common/platform/api/quiche_export.h"

namespace quiche {

class QUICHE_EXPORT_PRIVATE QuicheLowerCaseStringImpl {
public:
    QuicheLowerCaseStringImpl(absl::string_view str)
        : str_(absl::AsciiStrToLower(str))
    {
    }

    const std::string& get() const { return str_; }

private:
    std::string str_;
};

} // namespace quiche

#endif // QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_LOWER_CASE_STRING_IMPL_H_
