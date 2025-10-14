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

#ifndef __UVWASI_DEBUG_H__
#define __UVWASI_DEBUG_H__

#ifdef UVWASI_DEBUG_LOG
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif
#include <inttypes.h>
#define UVWASI_DEBUG(...)                                                                                                                                      \
    do {                                                                                                                                                       \
        fprintf(stderr, __VA_ARGS__);                                                                                                                          \
    } while (0)
#else
#define UVWASI_DEBUG(fmt, ...)
#endif

#endif /* __UVWASI_DEBUG_H__ */
