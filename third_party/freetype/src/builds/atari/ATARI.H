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

#if defined( GXVALID_H_ )
#pragma warn -aus /* too many unevaluated variables in gxvalid */
#endif

#ifndef ATARI_H
#define ATARI_H

#pragma warn -stu

/* PureC doesn't like 32bit enumerations */

#ifndef FT_IMAGE_TAG
#define FT_IMAGE_TAG( value, _x1, _x2, _x3, _x4 ) value
#endif /* FT_IMAGE_TAG */

#ifndef FT_ENC_TAG
#define FT_ENC_TAG( value, a, b, c, d ) value
#endif /* FT_ENC_TAG */

#endif /* ATARI_H */
