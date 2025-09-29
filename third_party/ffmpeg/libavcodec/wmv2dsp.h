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

#ifndef AVCODEC_WMV2DSP_H
#define AVCODEC_WMV2DSP_H

#include <stdint.h>

#include "qpeldsp.h"

typedef struct WMV2DSPContext {
    void (*idct_add)(uint8_t *dest, ptrdiff_t line_size, int16_t *block);
    void (*idct_put)(uint8_t *dest, ptrdiff_t line_size, int16_t *block);

    qpel_mc_func put_mspel_pixels_tab[8];

    int idct_perm;
} WMV2DSPContext;

void ff_wmv2dsp_init(WMV2DSPContext *c);
void ff_wmv2dsp_init_mips(WMV2DSPContext *c);

#endif /* AVCODEC_WMV2DSP_H */
