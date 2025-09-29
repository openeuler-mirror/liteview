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
 * libxml.h: internal header only used during the compilation of libxml
 *
 * See COPYRIGHT for the status of this software
 *
 * Author: breese@users.sourceforge.net
 */

#ifndef __XML_LIBXML_H__
#define __XML_LIBXML_H__

/*
 * These macros must be defined before including system headers.
 * Do not add any #include directives above this block.
 */
#ifndef NO_LARGEFILE_SOURCE
#ifndef _LARGEFILE_SOURCE
#define _LARGEFILE_SOURCE
#endif
#ifndef _FILE_OFFSET_BITS
#define _FILE_OFFSET_BITS 64
#endif
#endif

/*
 * Currently supported platforms use either autoconf or
 * copy to config.h own "preset" configuration file.
 * As result ifdef HAVE_CONFIG_H is omitted here.
 */
#ifdef _WIN32
#include "win32/config.h"
#include "third_party/libxml/win32/include/libxml/xmlversion.h"
#else
#include "config.h"
#include "third_party/libxml/linux/include/libxml/xmlversion.h"
#endif

#ifndef SYSCONFDIR
#define SYSCONFDIR "/etc"
#endif

#if defined(__Lynx__)
#include <stdio.h> /* pull definition of size_t */
#include <varargs.h>
int snprintf(char*, size_t, const char*, ...);
int vfprintf(FILE*, const char*, va_list);
#endif

#ifndef WITH_TRIO
#include <stdio.h>
#else
/**
 * TRIO_REPLACE_STDIO:
 *
 * This macro is defined if the trio string formatting functions are to
 * be used instead of the default stdio ones.
 */
#define TRIO_REPLACE_STDIO
#include "trio.h"
#endif

#if defined(__clang__) || (defined(__GNUC__) && (__GNUC__ >= 8))
#define ATTRIBUTE_NO_SANITIZE(arg) __attribute__((no_sanitize(arg)))
#else
#define ATTRIBUTE_NO_SANITIZE(arg)
#endif

#if !defined(PIC) && !defined(NOLIBTOOL) && !defined(LIBXML_STATIC)
#define LIBXML_STATIC
#endif
#endif /* ! __XML_LIBXML_H__ */
