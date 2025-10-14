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

/*
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "config.h"

#include "libavutil/cpu.h"
#include "libavcodec/arm/idct.h"

static const struct algo fdct_tab_arch[] = {
    { 0 }
};

static const struct algo idct_tab_arch[] = {
    { "SIMPLE-ARM",     ff_simple_idct_arm,     FF_IDCT_PERM_NONE },
    { "INT-ARM",        ff_j_rev_dct_arm,       FF_IDCT_PERM_LIBMPEG2 },
#if HAVE_ARMV5TE
    { "SIMPLE-ARMV5TE", ff_simple_idct_armv5te, FF_IDCT_PERM_NONE,      AV_CPU_FLAG_ARMV5TE },
#endif
#if HAVE_ARMV6
    { "SIMPLE-ARMV6",   ff_simple_idct_armv6,   FF_IDCT_PERM_LIBMPEG2,  AV_CPU_FLAG_ARMV6 },
#endif
#if HAVE_NEON
    { "SIMPLE-NEON",    ff_simple_idct_neon,    FF_IDCT_PERM_PARTTRANS, AV_CPU_FLAG_NEON },
#endif
    { 0 }
};
