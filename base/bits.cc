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


#include "base/bits.h"

namespace base {
namespace bits {

uint32_t vs__builtin_ctz(uint32_t x)
{
    uint32_t n = 0;
    if (x == 0)
        return 32;
    if ((x & 0x0000FFFF) == 0) {
        n += 16;
        x >>= 16;
    }
    if ((x & 0x000000FF) == 0) {
        n += 8;
        x >>= 8;
    }
    if ((x & 0x0000000F) == 0) {
        n += 4;
        x >>= 4;
    }
    if ((x & 0x00000003) == 0) {
        n += 2;
        x >>= 2;
    }
    if ((x & 0x00000001) == 0) {
        n += 1;
    }
    return n;
}

uint32_t vs__builtin_ctzll(uint64_t x)
{
    if (x == 0) {
        return 64;
    }
    uint32_t cnt = 0;
    while ((x & 1) == 0) {
        cnt++;
        x >>= 1;
    }
    return cnt;
}

uint32_t vs__builtin_clzll(uint64_t x)
{
    uint32_t n = 0;
    if (x == 0) {
        return 64;
    }
    if (x <= 0x00000000FFFFFFFFULL) {
        n += 32;
        x <<= 32;
    }
    if (x <= 0x0000FFFFFFFFFFFFULL) {
        n += 16;
        x <<= 16;
    }
    if (x <= 0x00FFFFFFFFFFFFFFULL) {
        n += 8;
        x <<= 8;
    }
    if (x <= 0x0FFFFFFFFFFFFFFFULL) {
        n += 4;
        x <<= 4;
    }
    if (x <= 0x3FFFFFFFFFFFFFFFULL) {
        n += 2;
        x <<= 2;
    }
    if (x <= 0x7FFFFFFFFFFFFFFFULL) {
        n += 1;
    }
    return n;
}

uint32_t vs__builtin_clz(uint32_t x)
{
    if (x == 0)
        return 32;

    int n = 0;
    if (x <= 0x0000FFFF) {
        n += 16;
        x <<= 16;
    }
    if (x <= 0x00FFFFFF) {
        n += 8;
        x <<= 8;
    }
    if (x <= 0x0FFFFFFF) {
        n += 4;
        x <<= 4;
    }
    if (x <= 0x3FFFFFFF) {
        n += 2;
        x <<= 2;
    }
    if (x <= 0x7FFFFFFF) {
        n += 1;
    }

    return n;
}

}
}