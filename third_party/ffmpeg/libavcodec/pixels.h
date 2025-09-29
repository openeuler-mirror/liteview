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

#ifndef AVCODEC_PIXELS_H
#define AVCODEC_PIXELS_H

#include <stddef.h>
#include <stdint.h>

/* pixel operations */
#define CALL_2X_PIXELS_MACRO(STATIC, a, b, n)        \
STATIC void a(uint8_t *block, const uint8_t *pixels, \
              ptrdiff_t line_size, int h)            \
{                                                    \
    b(block, pixels, line_size, h);                  \
    b(block + n, pixels + n, line_size, h);          \
}

#define CALL_2X_PIXELS(a, b, n) CALL_2X_PIXELS_MACRO(static, a, b, n)
#define CALL_2X_PIXELS_EXPORT(a, b, n) CALL_2X_PIXELS_MACRO(, a, b, n)

#endif /* AVCODEC_PIXELS_H */
