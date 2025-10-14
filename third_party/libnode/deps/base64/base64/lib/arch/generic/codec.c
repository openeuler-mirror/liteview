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
#include <string.h>

#include "../../../include/libbase64.h"
#include "../../tables/tables.h"
#include "../../codecs.h"
#include "../../config.h"
#include "../../env.h"

#if BASE64_WORDSIZE == 32
#include "32/enc_loop.c"
#elif BASE64_WORDSIZE == 64
#include "64/enc_loop.c"
#endif

#if BASE64_WORDSIZE >= 32
#include "32/dec_loop.c"
#endif

BASE64_ENC_FUNCTION(plain)
{
#include "enc_head.c"
#if BASE64_WORDSIZE == 32
    enc_loop_generic_32(&s, &slen, &o, &olen);
#elif BASE64_WORDSIZE == 64
    enc_loop_generic_64(&s, &slen, &o, &olen);
#endif
#include "enc_tail.c"
}

BASE64_DEC_FUNCTION(plain)
{
#include "dec_head.c"
#if BASE64_WORDSIZE >= 32
    dec_loop_generic_32(&s, &slen, &o, &olen);
#endif
#include "dec_tail.c"
}
