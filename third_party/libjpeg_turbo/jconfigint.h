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

/* libjpeg-turbo build number */
#define BUILD ""

/* Compiler's inline keyword */
#undef inline

/* How to obtain function inlining. */
#ifndef INLINE
#if defined(__GNUC__)
#define INLINE inline __attribute__((always_inline))
#elif defined(_MSC_VER)
#define INLINE __forceinline
#else
#define INLINE
#endif
#endif

/* How to obtain thread-local storage */
#if defined(_MSC_VER) && (defined(_WIN32) || defined(_WIN64))
#define THREAD_LOCAL __declspec(thread)
#else
#define THREAD_LOCAL __thread
#endif

/* Define to the full name of this package. */
#define PACKAGE_NAME "libjpeg-turbo"

/* Version number of package */
#define VERSION "2.1.4"

/* The size of `size_t', as computed by sizeof. */
#include <stdint.h>
#if __WORDSIZE == 64 || defined(_WIN64)
#define SIZEOF_SIZE_T 8
#else
#define SIZEOF_SIZE_T 4
#endif

/* Define if your compiler has __builtin_ctzl() and sizeof(unsigned long) == sizeof(size_t). */
#if defined(__GNUC__)
#define HAVE_BUILTIN_CTZL
#endif

/* Define to 1 if you have the <intrin.h> header file. */
#if defined(_MSC_VER)
#define HAVE_INTRIN_H 1
#endif

#if defined(_MSC_VER) && defined(HAVE_INTRIN_H)
#if (SIZEOF_SIZE_T == 8)
#define HAVEBITSCANFORWARD64
#elif (SIZEOF_SIZE_T == 4)
#define HAVEBITSCANFORWARD
#endif
#endif

#if defined(__has_attribute)
#if __has_attribute(fallthrough)
#define FALLTHROUGH __attribute__((fallthrough));
#else
#define FALLTHROUGH
#endif
#else
#define FALLTHROUGH
#endif
