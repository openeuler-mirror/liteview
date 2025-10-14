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

#ifndef SRC_BASE64_H_
#define SRC_BASE64_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "util.h"

#include <cmath>
#include <cstddef>
#include <cstdint>

namespace node {
//// Base 64 ////

enum class Base64Mode { NORMAL, URL };

static inline constexpr size_t base64_encoded_size(size_t size, Base64Mode mode = Base64Mode::NORMAL)
{
    return mode == Base64Mode::NORMAL ? ((size + 2) / 3 * 4) : static_cast<size_t>(std::ceil(static_cast<double>(size * 4) / 3));
}

// Doesn't check for padding at the end.  Can be 1-2 bytes over.
static inline constexpr size_t base64_decoded_size_fast(size_t size)
{
    // 1-byte input cannot be decoded
    return size > 1 ? (size / 4) * 3 + (size % 4 + 1) / 2 : 0;
}

//inline uint32_t ReadUint32BE(const unsigned char* p);
inline uint32_t ReadUint32BE(const unsigned char* p)
{
    return static_cast<uint32_t>(p[0] << 24U) | static_cast<uint32_t>(p[1] << 16U) | static_cast<uint32_t>(p[2] << 8U) | static_cast<uint32_t>(p[3]);
}

template <typename TypeName> size_t base64_decoded_size(const TypeName* src, size_t size);

template <typename TypeName> size_t base64_decode(char* const dst, const size_t dstlen, const TypeName* const src, const size_t srclen);

inline size_t base64_encode(const char* src, size_t slen, char* dst, size_t dlen, Base64Mode mode = Base64Mode::NORMAL);
} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_BASE64_H_
