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

#include "quiche/http2/adapter/noop_header_validator.h"

#include "absl/strings/escaping.h"
#include "quiche/common/platform/api/quiche_logging.h"

namespace http2 {
namespace adapter {

HeaderValidatorBase::HeaderStatus NoopHeaderValidator::ValidateSingleHeader(absl::string_view key, absl::string_view value)
{
    if (key == ":status") {
        status_ = std::string(value);
    }
    return HEADER_OK;
}

bool NoopHeaderValidator::FinishHeaderBlock(HeaderType /* type */) { return true; }

} // namespace adapter
} // namespace http2
