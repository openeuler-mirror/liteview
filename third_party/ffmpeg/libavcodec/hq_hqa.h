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
 * Canopus HQ/HQA decoder
 *
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

#ifndef AVCODEC_HQ_HQA_H
#define AVCODEC_HQ_HQA_H

#include <stdint.h>

#include "libavutil/mem_internal.h"

#include "avcodec.h"
#include "hq_hqadsp.h"
#include "vlc.h"

#define NUM_HQ_AC_ENTRIES 746
#define NUM_HQ_PROFILES   22
#define NUM_HQ_QUANTS     16

typedef struct HQContext {
    AVCodecContext *avctx;
    HQDSPContext hqhqadsp;

    VLC hq_ac_vlc;
    VLC hqa_cbp_vlc;
    DECLARE_ALIGNED(16, int16_t, block)[12][64];
} HQContext;

typedef struct HQProfile {
    const uint8_t *perm_tab;
    int width, height;
    int num_slices;
    int tab_w, tab_h;
} HQProfile;

extern const int32_t * const ff_hq_quants[16][2][4];
extern const HQProfile ff_hq_profile[NUM_HQ_PROFILES];

extern const uint8_t ff_hq_ac_skips[NUM_HQ_AC_ENTRIES];
extern const int16_t ff_hq_ac_syms [NUM_HQ_AC_ENTRIES];

int ff_hq_init_vlcs(HQContext *c);

#endif /* AVCODEC_HQ_HQA_H */
