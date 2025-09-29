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
 * CGA/EGA/VGA ROM data
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

/**
 * @file
 * CGA/EGA/VGA ROM data
 * @note fonts are in libavutil/xga_font_data.[ch]
 */

#ifndef AVCODEC_CGA_DATA_H
#define AVCODEC_CGA_DATA_H

#include <stdint.h>

extern const uint32_t ff_cga_palette[16];
extern const uint32_t ff_ega_palette[64];

/**
 * Draw CGA/EGA/VGA font to 8-bit pixel buffer
 *
 * @param dst Destination pixel buffer
 * @param linesize Linesize (pixels)
 * @param font Font table. We assume font width is always 8 pixels wide.
 * @param font_height Font height (pixels)
 * @param fg,bg Foreground and background palette index
 * @param ch Character to draw
 */
void ff_draw_pc_font(uint8_t *dst, int linesize, const uint8_t *font, int font_height, int ch, int fg, int bg);

#endif /* AVCODEC_CGA_DATA_H */
