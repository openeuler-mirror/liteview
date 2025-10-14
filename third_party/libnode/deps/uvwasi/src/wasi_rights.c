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

#include "uv.h"
#include "wasi_rights.h"
#include "wasi_types.h"

uvwasi_errno_t uvwasi__get_rights(uv_file fd, int flags, uvwasi_filetype_t type, uvwasi_rights_t* rights_base, uvwasi_rights_t* rights_inheriting)
{
    int read_or_write_only;

    if (type == UVWASI_FILETYPE_UNKNOWN)
        return UVWASI_EINVAL;

    switch (type) {
    case UVWASI_FILETYPE_REGULAR_FILE:
        *rights_base = UVWASI__RIGHTS_REGULAR_FILE_BASE;
        *rights_inheriting = UVWASI__RIGHTS_REGULAR_FILE_INHERITING;
        break;

    case UVWASI_FILETYPE_DIRECTORY:
        *rights_base = UVWASI__RIGHTS_DIRECTORY_BASE;
        *rights_inheriting = UVWASI__RIGHTS_DIRECTORY_INHERITING;
        break;

    case UVWASI_FILETYPE_SOCKET_STREAM:
    case UVWASI_FILETYPE_SOCKET_DGRAM:
        *rights_base = UVWASI__RIGHTS_SOCKET_BASE;
        *rights_inheriting = UVWASI__RIGHTS_SOCKET_INHERITING;
        break;

    case UVWASI_FILETYPE_CHARACTER_DEVICE:
        if (uv_guess_handle(fd) == UV_TTY) {
            *rights_base = UVWASI__RIGHTS_TTY_BASE;
            *rights_inheriting = UVWASI__RIGHTS_TTY_INHERITING;
        } else {
            *rights_base = UVWASI__RIGHTS_CHARACTER_DEVICE_BASE;
            *rights_inheriting = UVWASI__RIGHTS_CHARACTER_DEVICE_INHERITING;
        }
        break;

    case UVWASI_FILETYPE_BLOCK_DEVICE:
        *rights_base = UVWASI__RIGHTS_BLOCK_DEVICE_BASE;
        *rights_inheriting = UVWASI__RIGHTS_BLOCK_DEVICE_INHERITING;
        break;

    default:
        *rights_base = 0;
        *rights_inheriting = 0;
    }

    /* Disable read/write bits depending on access mode. */
    read_or_write_only = flags & (UV_FS_O_RDONLY | UV_FS_O_WRONLY | UV_FS_O_RDWR);

    if (read_or_write_only == UV_FS_O_RDONLY)
        *rights_base &= ~UVWASI_RIGHT_FD_WRITE;
    else if (read_or_write_only == UV_FS_O_WRONLY)
        *rights_base &= ~UVWASI_RIGHT_FD_READ;

    return UVWASI_ESUCCESS;
}
