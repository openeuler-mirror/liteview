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

#include <stdint.h>

#include "config.h"
#include "libavutil/attributes.h"
#include "libavutil/cpu.h"
#include "libavutil/x86/cpu.h"
#include "libavcodec/blockdsp.h"

void ff_clear_block_sse(int16_t *block);
void ff_clear_block_avx(int16_t *block);
void ff_clear_blocks_sse(int16_t *blocks);
void ff_clear_blocks_avx(int16_t *blocks);

av_cold void ff_blockdsp_init_x86(BlockDSPContext *c)
{
#if HAVE_X86ASM
    int cpu_flags = av_get_cpu_flags();

    if (EXTERNAL_SSE(cpu_flags)) {
        c->clear_block  = ff_clear_block_sse;
        c->clear_blocks = ff_clear_blocks_sse;
    }
    if (EXTERNAL_AVX_FAST(cpu_flags)) {
        c->clear_block  = ff_clear_block_avx;
        c->clear_blocks = ff_clear_blocks_avx;
    }
#endif /* HAVE_X86ASM */
}
