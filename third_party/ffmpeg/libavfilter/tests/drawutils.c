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

#include <stdio.h>

#include "libavutil/pixdesc.h"
#include "libavfilter/drawutils.h"

int main(void)
{
    enum AVPixelFormat f;
    const AVPixFmtDescriptor *desc;
    FFDrawContext draw;
    FFDrawColor color;
    int r, i;

    for (f = 0; av_pix_fmt_desc_get(f); f++) {
        desc = av_pix_fmt_desc_get(f);
        if (!desc->name)
            continue;
        printf("Testing %s...%*s", desc->name,
               (int)(16 - strlen(desc->name)), "");
        r = ff_draw_init(&draw, f, 0);
        if (r < 0) {
            char buf[128];
            av_strerror(r, buf, sizeof(buf));
            printf("no: %s\n", buf);
            continue;
        }
        ff_draw_color(&draw, &color, (uint8_t[]) { 1, 0, 0, 1 });
        for (i = 0; i < sizeof(color); i++)
            if (((uint8_t *)&color)[i] != 128)
                break;
        if (i == sizeof(color)) {
            printf("fallback color\n");
            continue;
        }
        printf("ok\n");
    }
    return 0;
}
