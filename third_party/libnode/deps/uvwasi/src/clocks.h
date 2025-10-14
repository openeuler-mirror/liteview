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

#ifndef __UVWASI_CLOCKS_H__
#define __UVWASI_CLOCKS_H__

#include "wasi_types.h"

uvwasi_errno_t uvwasi__clock_gettime_realtime(uvwasi_timestamp_t* time);
uvwasi_errno_t uvwasi__clock_gettime_process_cputime(uvwasi_timestamp_t* time);
uvwasi_errno_t uvwasi__clock_gettime_thread_cputime(uvwasi_timestamp_t* time);

uvwasi_errno_t uvwasi__clock_getres_process_cputime(uvwasi_timestamp_t* time);
uvwasi_errno_t uvwasi__clock_getres_thread_cputime(uvwasi_timestamp_t* time);

#endif /* __UVWASI_CLOCKS_H__ */
