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

#ifndef QUICHE_HTTP2_ADAPTER_NGHTTP2_SESSION_H_
#define QUICHE_HTTP2_ADAPTER_NGHTTP2_SESSION_H_

#include <cstdint>

#include "quiche/http2/adapter/http2_session.h"
#include "quiche/http2/adapter/nghttp2.h"
#include "quiche/http2/adapter/nghttp2_util.h"
#include "quiche/common/platform/api/quiche_export.h"

namespace http2 {
namespace adapter {

// A C++ wrapper around common nghttp2_session operations.
class QUICHE_EXPORT_PRIVATE NgHttp2Session : public Http2Session {
public:
    // Does not take ownership of |options|.
    NgHttp2Session(Perspective perspective, nghttp2_session_callbacks_unique_ptr callbacks, const nghttp2_option* options, void* userdata);
    ~NgHttp2Session() override;

    int64_t ProcessBytes(absl::string_view bytes) override;

    int Consume(Http2StreamId stream_id, size_t num_bytes) override;

    bool want_read() const override;
    bool want_write() const override;
    int GetRemoteWindowSize() const override;

    nghttp2_session* raw_ptr() const { return session_.get(); }

private:
    nghttp2_session_unique_ptr session_;
    Perspective perspective_;
};

} // namespace adapter
} // namespace http2

#endif // QUICHE_HTTP2_ADAPTER_NGHTTP2_SESSION_H_
