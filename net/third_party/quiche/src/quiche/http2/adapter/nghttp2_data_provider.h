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

#ifndef QUICHE_HTTP2_ADAPTER_NGHTTP2_DATA_PROVIDER_H_
#define QUICHE_HTTP2_ADAPTER_NGHTTP2_DATA_PROVIDER_H_

#include <cstdint>
#include <memory>

#include "quiche/http2/adapter/data_source.h"
#include "quiche/http2/adapter/nghttp2.h"

namespace http2 {
namespace adapter {
namespace callbacks {

// Assumes |source| is a DataFrameSource.
ssize_t DataFrameSourceReadCallback(
    nghttp2_session* /*session */, int32_t /* stream_id */, uint8_t* /* buf */, size_t length, uint32_t* data_flags, nghttp2_data_source* source, void* /* user_data */);

int DataFrameSourceSendCallback(
    nghttp2_session* /* session */, nghttp2_frame* /* frame */, const uint8_t* framehd, size_t length, nghttp2_data_source* source, void* /* user_data */);

} // namespace callbacks

// Transforms a DataFrameSource into a nghttp2_data_provider. Does not take
// ownership of |source|. Returns nullptr if |source| is nullptr.
std::unique_ptr<nghttp2_data_provider> MakeDataProvider(DataFrameSource* source);

} // namespace adapter
} // namespace http2

#endif // QUICHE_HTTP2_ADAPTER_NGHTTP2_DATA_PROVIDER_H_
