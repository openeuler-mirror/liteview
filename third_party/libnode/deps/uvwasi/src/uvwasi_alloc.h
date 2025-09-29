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

#ifndef __UVWASI_ALLOC_H__
#define __UVWASI_ALLOC_H__

#include "uvwasi.h"

void* uvwasi__malloc(const uvwasi_t* uvwasi, size_t size);
void uvwasi__free(const uvwasi_t* uvwasi, void* ptr);
void* uvwasi__calloc(const uvwasi_t* uvwasi, size_t nmemb, size_t size);
void* uvwasi__realloc(const uvwasi_t* uvwasi, void* ptr, size_t size);

#endif
