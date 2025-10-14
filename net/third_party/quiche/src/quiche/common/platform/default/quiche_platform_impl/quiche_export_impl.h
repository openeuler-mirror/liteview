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

#ifndef QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_EXPORT_IMPL_H_
#define QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_EXPORT_IMPL_H_

#include "absl/base/attributes.h"

// These macros are documented in: quiche/quic/platform/api/quic_export.h

#if defined(_WIN32)
#define QUICHE_EXPORT_IMPL __declspec(dllexport)
#elif ABSL_HAVE_ATTRIBUTE(visibility)
#define QUICHE_EXPORT_IMPL __attribute__((visibility("default")))
#else
#define QUICHE_EXPORT_IMPL
#endif

#define QUICHE_EXPORT_PRIVATE_IMPL QUICHE_EXPORT_IMPL
#define QUICHE_NO_EXPORT_IMPL QUICHE_EXPORT_IMPL

#endif // QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_EXPORT_IMPL_H_
