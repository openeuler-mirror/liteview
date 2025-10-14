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

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#include "../../../include/libbase64.h"
#include "../../tables/tables.h"
#include "../../codecs.h"
#include "config.h"
#include "../../env.h"

#if HAVE_AVX2
#include <immintrin.h>

// Only enable inline assembly on supported compilers and on 64-bit CPUs.
#ifndef BASE64_AVX2_USE_ASM
#if (defined(__GNUC__) || defined(__clang__)) && BASE64_WORDSIZE == 64
#define BASE64_AVX2_USE_ASM 1
#else
#define BASE64_AVX2_USE_ASM 0
#endif
#endif

#include "dec_reshuffle.c"
#include "dec_loop.c"

#if BASE64_AVX2_USE_ASM
#include "enc_loop_asm.c"
#else
#include "enc_translate.c"
#include "enc_reshuffle.c"
#include "enc_loop.c"
#endif

#endif // HAVE_AVX2

BASE64_ENC_FUNCTION(avx2)
{
#if HAVE_AVX2
#include "../generic/enc_head.c"
    enc_loop_avx2(&s, &slen, &o, &olen);
#include "../generic/enc_tail.c"
#else
    BASE64_ENC_STUB
#endif
}

BASE64_DEC_FUNCTION(avx2)
{
#if HAVE_AVX2
#include "../generic/dec_head.c"
    dec_loop_avx2(&s, &slen, &o, &olen);
#include "../generic/dec_tail.c"
#else
    BASE64_DEC_STUB
#endif
}
