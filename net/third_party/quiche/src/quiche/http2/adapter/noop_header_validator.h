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

#ifndef QUICHE_HTTP2_ADAPTER_NOOP_HEADER_VALIDATOR_H_
#define QUICHE_HTTP2_ADAPTER_NOOP_HEADER_VALIDATOR_H_

#include "absl/strings/string_view.h"
#include "quiche/http2/adapter/header_validator_base.h"
#include "quiche/common/platform/api/quiche_export.h"

namespace http2 {
namespace adapter {

// A validator that does not actually perform any validation.
class QUICHE_EXPORT_PRIVATE NoopHeaderValidator : public HeaderValidatorBase {
public:
    NoopHeaderValidator() = default;

    HeaderStatus ValidateSingleHeader(absl::string_view key, absl::string_view value) override;

    bool FinishHeaderBlock(HeaderType type) override;
};

} // namespace adapter
} // namespace http2

#endif // QUICHE_HTTP2_ADAPTER_NOOP_HEADER_VALIDATOR_H_
