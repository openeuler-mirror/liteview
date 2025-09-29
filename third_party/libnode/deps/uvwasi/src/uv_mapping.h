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

#ifndef __UVWASI_UV_MAPPING_H__
#define __UVWASI_UV_MAPPING_H__

#include "uv.h"
#include "wasi_types.h"

#define NANOS_PER_SEC 1000000000

uvwasi_errno_t uvwasi__translate_uv_error(int err);
int uvwasi__translate_to_uv_signal(uvwasi_signal_t sig);
uvwasi_timestamp_t uvwasi__timespec_to_timestamp(const uv_timespec_t* ts);
uvwasi_filetype_t uvwasi__stat_to_filetype(const uv_stat_t* stat);
void uvwasi__stat_to_filestat(const uv_stat_t* stat, uvwasi_filestat_t* fs);
uvwasi_errno_t uvwasi__get_filetype_by_fd(uv_file fd, uvwasi_filetype_t* type);

#endif /* __UVWASI_UV_MAPPING_H__ */
