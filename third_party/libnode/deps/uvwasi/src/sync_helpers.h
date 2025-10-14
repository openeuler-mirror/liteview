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

#ifndef __UVWASI_SYNC_HELPERS_H__
#define __UVWASI_SYNC_HELPERS_H__

struct uvwasi_s;

typedef struct shutdown_data_s {
    int status;
    int done;
} shutdown_data_t;

typedef struct recv_data_s {
    char* base;
    size_t len;
    ssize_t nread;
    int done;
} recv_data_t;

int free_handle_sync(struct uvwasi_s* uvwasi, uv_handle_t* handle);

int shutdown_stream_sync(struct uvwasi_s* uvwasi, uv_stream_t* stream, shutdown_data_t* shutdown_data);

int read_stream_sync(struct uvwasi_s* uvwasi, uv_stream_t* stream, recv_data_t* recv_data);
#endif /* __UVWASI_SYNC_HELPERS_H__ */
