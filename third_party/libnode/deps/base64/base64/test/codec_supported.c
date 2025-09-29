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

#include <string.h>

#include "../include/libbase64.h"

static char* _codecs[] = { "AVX2", "NEON32", "NEON64", "plain", "SSSE3", "SSE41", "SSE42", "AVX", "AVX512", NULL };

char** codecs = _codecs;

int codec_supported(int flags)
{
    // Check if given codec is supported by trying to decode a test string:
    char* a = "aGVsbG8=";
    char b[10];
    size_t outlen;

    return (base64_decode(a, strlen(a), b, &outlen, flags) != -1);
}
