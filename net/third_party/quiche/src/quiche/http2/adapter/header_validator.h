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

#ifndef QUICHE_HTTP2_ADAPTER_HEADER_VALIDATOR_H_
#define QUICHE_HTTP2_ADAPTER_HEADER_VALIDATOR_H_

#include <string>
#include <vector>

#include "absl/strings/string_view.h"
#include "absl/types/optional.h"
#include "quiche/http2/adapter/header_validator_base.h"
#include "quiche/common/platform/api/quiche_export.h"

namespace http2 {
namespace adapter {

class QUICHE_EXPORT_PRIVATE HeaderValidator : public HeaderValidatorBase {
public:
    HeaderValidator() = default;

    void StartHeaderBlock() override;

    HeaderStatus ValidateSingleHeader(absl::string_view key, absl::string_view value) override;

    // Returns true if all required pseudoheaders and no extra pseudoheaders are
    // present for the given header type.
    bool FinishHeaderBlock(HeaderType type) override;

private:
    enum ContentLengthStatus {
        CONTENT_LENGTH_OK,
        CONTENT_LENGTH_SKIP, // Used to handle duplicate content length values.
        CONTENT_LENGTH_ERROR,
    };
    ContentLengthStatus HandleContentLength(absl::string_view value);
    bool ValidateAndSetAuthority(absl::string_view authority);

    std::vector<std::string> pseudo_headers_;
    absl::optional<std::string> authority_ = absl::nullopt;
    std::string method_;
    std::string path_;
};

} // namespace adapter
} // namespace http2

#endif // QUICHE_HTTP2_ADAPTER_HEADER_VALIDATOR_H_
