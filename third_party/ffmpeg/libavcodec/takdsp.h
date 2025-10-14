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

#ifndef AVCODEC_TAKDSP_H
#define AVCODEC_TAKDSP_H

#include <stdint.h>

typedef struct TAKDSPContext {
    void (*decorrelate_ls)(int32_t *p1, int32_t *p2, int length);
    void (*decorrelate_sr)(int32_t *p1, int32_t *p2, int length);
    void (*decorrelate_sm)(int32_t *p1, int32_t *p2, int length);
    void (*decorrelate_sf)(int32_t *p1, int32_t *p2, int length, int dshift, int dfactor);
} TAKDSPContext;

void ff_takdsp_init(TAKDSPContext *c);
void ff_takdsp_init_x86(TAKDSPContext *c);

#endif /* AVCODEC_TAKDSP_H */
