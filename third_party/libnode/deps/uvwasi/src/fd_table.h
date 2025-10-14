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

#ifndef __UVWASI_FD_TABLE_H__
#define __UVWASI_FD_TABLE_H__

#include <stdint.h>
#include "uv.h"
#include "wasi_types.h"

struct uvwasi_s;
struct uvwasi_options_s;

struct uvwasi_fd_wrap_t {
    uvwasi_fd_t id;
    uv_file fd;
    uv_tcp_t* sock;
    char* path;
    char* real_path;
    char* normalized_path;
    uvwasi_filetype_t type;
    uvwasi_rights_t rights_base;
    uvwasi_rights_t rights_inheriting;
    int preopen;
    uv_mutex_t mutex;
};

struct uvwasi_fd_table_t {
    struct uvwasi_fd_wrap_t** fds;
    uint32_t size;
    uint32_t used;
    uv_rwlock_t rwlock;
};

uvwasi_errno_t uvwasi_fd_table_init(struct uvwasi_s* uvwasi, const struct uvwasi_options_s* options);
void uvwasi_fd_table_free(struct uvwasi_s* uvwasi, struct uvwasi_fd_table_t* table);
uvwasi_errno_t uvwasi_fd_table_insert(struct uvwasi_s* uvwasi, struct uvwasi_fd_table_t* table, uv_file fd, uv_tcp_t* sock, const char* mapped_path,
    const char* real_path, uvwasi_filetype_t type, uvwasi_rights_t rights_base, uvwasi_rights_t rights_inheriting, int preopen, struct uvwasi_fd_wrap_t** wrap);
uvwasi_errno_t uvwasi_fd_table_insert_preopen(
    struct uvwasi_s* uvwasi, struct uvwasi_fd_table_t* table, const uv_file fd, const char* path, const char* real_path);
uvwasi_errno_t uvwasi_fd_table_insert_preopen_socket(struct uvwasi_s* uvwasi, struct uvwasi_fd_table_t* table, uv_tcp_t* sock);
uvwasi_errno_t uvwasi_fd_table_get(
    struct uvwasi_fd_table_t* table, const uvwasi_fd_t id, struct uvwasi_fd_wrap_t** wrap, uvwasi_rights_t rights_base, uvwasi_rights_t rights_inheriting);
uvwasi_errno_t uvwasi_fd_table_get_nolock(
    struct uvwasi_fd_table_t* table, const uvwasi_fd_t id, struct uvwasi_fd_wrap_t** wrap, uvwasi_rights_t rights_base, uvwasi_rights_t rights_inheriting);
uvwasi_errno_t uvwasi_fd_table_remove_nolock(struct uvwasi_s* uvwasi, struct uvwasi_fd_table_t* table, const uvwasi_fd_t id);
uvwasi_errno_t uvwasi_fd_table_renumber(struct uvwasi_s* uvwasi, struct uvwasi_fd_table_t* table, const uvwasi_fd_t dst, const uvwasi_fd_t src);
uvwasi_errno_t uvwasi_fd_table_lock(struct uvwasi_fd_table_t* table);
uvwasi_errno_t uvwasi_fd_table_unlock(struct uvwasi_fd_table_t* table);

#endif /* __UVWASI_FD_TABLE_H__ */
