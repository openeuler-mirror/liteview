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

#ifndef GLOG_CONFIG_H
#define GLOG_CONFIG_H

/* Namespace for Google classes */
#define GOOGLE_NAMESPACE google

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H

/* define if your compiler has __attribute__ */
#define HAVE___ATTRIBUTE__

/* define if symbolize support is available */
#define HAVE_SYMBOLIZE

/* The size of `void *', as computed by sizeof. */
#if defined(__LP64__)
#define SIZEOF_VOID_P 8
#else
#define SIZEOF_VOID_P 4
#endif

#ifdef GLOG_BAZEL_BUILD

/* TODO(rodrigoq): remove this workaround once bazel#3979 is resolved:
 * https://github.com/bazelbuild/bazel/issues/3979 */
#define _START_GOOGLE_NAMESPACE_ namespace GOOGLE_NAMESPACE {
#define _END_GOOGLE_NAMESPACE_ }

#else

/* Stops putting the code inside the Google namespace */
#define _END_GOOGLE_NAMESPACE_ }

/* Puts following code inside the Google namespace */
#define _START_GOOGLE_NAMESPACE_ namespace google {
#endif

#endif // GLOG_CONFIG_H
