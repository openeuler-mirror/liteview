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

#ifndef __UVWASI_PATH_RESOLVER_H__
#define __UVWASI_PATH_RESOLVER_H__

#include "fd_table.h"
#include "uvwasi.h"

uvwasi_errno_t uvwasi__normalize_path(const char* path, uvwasi_size_t path_len, char* normalized_path, uvwasi_size_t normalized_len);

uvwasi_errno_t uvwasi__resolve_path(
    const uvwasi_t* uvwasi, const struct uvwasi_fd_wrap_t* fd, const char* path, uvwasi_size_t path_len, char** resolved_path, uvwasi_lookupflags_t flags);

#endif /* __UVWASI_PATH_RESOLVER_H__ */
