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
 * Adds a mutex implementation based on c++ mutex to harfbuzz.
 */
#include <mutex>

using hb_mutex_impl_t = std::mutex;
#define HB_MUTEX_IMPL_INIT UNUSED
#define hb_mutex_impl_init(M)                                                                                                                                  \
    HB_STMT_START                                                                                                                                              \
    {                                                                                                                                                          \
        new (M) hb_mutex_impl_t;                                                                                                                               \
    }                                                                                                                                                          \
    HB_STMT_END
#define hb_mutex_impl_lock(M) (M)->lock()
#define hb_mutex_impl_unlock(M) (M)->unlock()
#define hb_mutex_impl_finish(M)                                                                                                                                \
    HB_STMT_START                                                                                                                                              \
    {                                                                                                                                                          \
        (M)->~hb_mutex_impl_t();                                                                                                                               \
    }                                                                                                                                                          \
    HB_STMT_END
