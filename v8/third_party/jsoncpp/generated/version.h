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

// DO NOT EDIT. This file (and "version") is a template used by the build system
// (either CMake or Meson) to generate a "version.h" header file.
#ifndef JSON_VERSION_H_INCLUDED
#define JSON_VERSION_H_INCLUDED

#define JSONCPP_VERSION_STRING "1.9.0"
#define JSONCPP_VERSION_MAJOR 1
#define JSONCPP_VERSION_MINOR 9
#define JSONCPP_VERSION_PATCH 0
#define JSONCPP_VERSION_QUALIFIER
#define JSONCPP_VERSION_HEXA ((JSONCPP_VERSION_MAJOR << 24) | (JSONCPP_VERSION_MINOR << 16) | (JSONCPP_VERSION_PATCH << 8))

#ifdef JSONCPP_USING_SECURE_MEMORY
#undef JSONCPP_USING_SECURE_MEMORY
#endif
#define JSONCPP_USING_SECURE_MEMORY 0
// If non-zero, the library zeroes any memory that it has allocated before
// it frees its memory.

#endif // JSON_VERSION_H_INCLUDED
