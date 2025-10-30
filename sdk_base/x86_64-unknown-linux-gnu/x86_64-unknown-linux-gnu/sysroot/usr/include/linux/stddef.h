/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */

#include <stdint.h>

#ifndef sysroot_usr_include_linux_stddef_h
#define sysroot_usr_include_linux_stddef_h

#ifndef __always_inline
#define __always_inline __inline__
#endif

#ifndef _WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#define _WCHAR_T_DEFINED
#endif

// Define offsetof macro
#ifndef offsetof
#if defined(_MSC_VER) && !defined(_CRT_USE_BUILTIN_OFFSETOF)
#ifdef __cplusplus
#define offsetof(s,m) ((size_t)&reinterpret_cast<char const volatile&>((((s*)0)->m)))
#else
#define offsetof(s,m) ((size_t)&(((s*)0)->m))
#endif
#else
#define offsetof(s,m) __builtin_offsetof(s,m)
#endif
#endif // offsetof

#ifndef NULL
#ifdef __cplusplus
#define NULL	0
#else
#define NULL	((void *)0)
#endif
#endif

#if __cplusplus >= 201103L
//namespace std {
typedef double max_align_t;	// most aligned type
//}
#endif

#endif // sysroot_usr_include_linux_stddef_h