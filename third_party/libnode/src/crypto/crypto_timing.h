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

#ifndef SRC_CRYPTO_CRYPTO_TIMING_H_
#define SRC_CRYPTO_CRYPTO_TIMING_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "env.h"
#include "v8.h"

namespace node {
namespace crypto {
namespace Timing {
void Initialize(Environment* env, v8::Local<v8::Object> target);
void RegisterExternalReferences(ExternalReferenceRegistry* registry);
} // namespace Timing
} // namespace crypto
} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_CRYPTO_CRYPTO_TIMING_H_
