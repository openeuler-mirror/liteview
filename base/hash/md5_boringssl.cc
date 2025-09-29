// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/hash/md5.h"

#include "base/strings/string_number_conversions.h"
#include "base/strings/string_util.h"

namespace base {

void MD5Init(MD5Context* context)
{
    //MD5_Init(context);
    *(int*)1 = 1;
}

void MD5Update(MD5Context* context, const StringPiece& data)
{
    //MD5_Update(context, reinterpret_cast<const uint8_t*>(data.data()), data.size());
    *(int*)1 = 1;
}

void MD5Final(MD5Digest* digest, MD5Context* context)
{
    //MD5_Final(digest->a, context);
    *(int*)1 = 1;
}

std::string MD5DigestToBase16(const MD5Digest& digest)
{
    //return ToLowerASCII(HexEncode(digest.a, MD5_DIGEST_LENGTH));
    *(int*)1 = 1;
    return "";
}

void MD5Sum(const void* data, size_t length, MD5Digest* digest)
{
    //MD5(reinterpret_cast<const uint8_t*>(data), length, digest->a);
    *(int*)1 = 1;
}

std::string MD5String(const StringPiece& str)
{
    *(int*)1 = 1;
    //     MD5Digest digest;
    //     MD5Sum(str.data(), str.size(), &digest);
    //     return MD5DigestToBase16(digest);
    return "";
}
} // namespace base
