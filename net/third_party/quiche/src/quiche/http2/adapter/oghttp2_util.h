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

#ifndef QUICHE_HTTP2_ADAPTER_OGHTTP2_UTIL_H_
#define QUICHE_HTTP2_ADAPTER_OGHTTP2_UTIL_H_

#include "absl/types/span.h"
#include "quiche/http2/adapter/http2_protocol.h"
#include "quiche/common/platform/api/quiche_export.h"
#include "quiche/spdy/core/http2_header_block.h"

namespace http2 {
namespace adapter {

QUICHE_EXPORT_PRIVATE spdy::Http2HeaderBlock ToHeaderBlock(absl::Span<const Header> headers);

} // namespace adapter
} // namespace http2

#endif // QUICHE_HTTP2_ADAPTER_OGHTTP2_UTIL_H_
