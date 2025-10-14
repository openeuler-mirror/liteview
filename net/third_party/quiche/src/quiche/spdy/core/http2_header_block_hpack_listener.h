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

#ifndef QUICHE_SPDY_CORE_HTTP2_HEADER_BLOCK_HPACK_LISTENER_H_
#define QUICHE_SPDY_CORE_HTTP2_HEADER_BLOCK_HPACK_LISTENER_H_

#include "absl/strings/string_view.h"
#include "quiche/http2/hpack/decoder/hpack_decoder_listener.h"
#include "quiche/common/platform/api/quiche_export.h"
#include "quiche/common/platform/api/quiche_logging.h"
#include "quiche/spdy/core/http2_header_block.h"

namespace spdy {

// This class simply gathers the key-value pairs emitted by an HpackDecoder in
// a Http2HeaderBlock.
class QUICHE_EXPORT_PRIVATE Http2HeaderBlockHpackListener : public http2::HpackDecoderListener {
public:
    Http2HeaderBlockHpackListener() { }

    void OnHeaderListStart() override
    {
        header_block_.clear();
        hpack_error_ = false;
    }

    void OnHeader(const std::string& name, const std::string& value) override { header_block_.AppendValueOrAddHeader(name, value); }

    void OnHeaderListEnd() override { }

    void OnHeaderErrorDetected(absl::string_view error_message) override
    {
        QUICHE_VLOG(1) << error_message;
        hpack_error_ = true;
    }

    Http2HeaderBlock release_header_block()
    {
        Http2HeaderBlock block = std::move(header_block_);
        header_block_ = {};
        return block;
    }
    bool hpack_error() const { return hpack_error_; }

private:
    Http2HeaderBlock header_block_;
    bool hpack_error_ = false;
};

} // namespace spdy

#endif // QUICHE_SPDY_CORE_HTTP2_HEADER_BLOCK_HPACK_LISTENER_H_
