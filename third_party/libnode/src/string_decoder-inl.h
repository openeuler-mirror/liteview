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

#ifndef SRC_STRING_DECODER_INL_H_
#define SRC_STRING_DECODER_INL_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "string_decoder.h"

namespace node {

void StringDecoder::SetEncoding(enum encoding encoding)
{
    state_[kBufferedBytes] = 0;
    state_[kMissingBytes] = 0;
    state_[kEncodingField] = encoding;
}

enum encoding StringDecoder::Encoding() const
{
    return static_cast<enum encoding>(state_[kEncodingField]);
}

unsigned StringDecoder::BufferedBytes() const
{
    return state_[kBufferedBytes];
}

unsigned StringDecoder::MissingBytes() const
{
    return state_[kMissingBytes];
}

char* StringDecoder::IncompleteCharacterBuffer()
{
    return reinterpret_cast<char*>(state_ + kIncompleteCharactersStart);
}

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_STRING_DECODER_INL_H_
