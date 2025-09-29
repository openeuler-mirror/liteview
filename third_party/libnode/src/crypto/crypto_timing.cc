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

#include "crypto/crypto_timing.h"
#include "crypto/crypto_util.h"
#include "env-inl.h"
#include "node_errors.h"
#include "v8.h"
#include "node.h"

#include <openssl/crypto.h>

namespace node {

using v8::FunctionCallbackInfo;
using v8::Local;
using v8::Object;
using v8::Value;

namespace crypto {
namespace Timing {
void TimingSafeEqual(const FunctionCallbackInfo<Value>& args)
{
    // Moving the type checking into JS leads to test failures, most likely due
    // to V8 inlining certain parts of the wrapper. Therefore, keep them in C++.
    // Refs: https://github.com/nodejs/node/issues/34073.
    Environment* env = Environment::GetCurrent(args);
    if (!IsAnyBufferSource(args[0])) {
        THROW_ERR_INVALID_ARG_TYPE(env,
            "The \"buf1\" argument must be an instance of "
            "ArrayBuffer, Buffer, TypedArray, or DataView.");
        return;
    }
    if (!IsAnyBufferSource(args[1])) {
        THROW_ERR_INVALID_ARG_TYPE(env,
            "The \"buf2\" argument must be an instance of "
            "ArrayBuffer, Buffer, TypedArray, or DataView.");
        return;
    }

    ArrayBufferOrViewContents<char> buf1(args[0]);
    ArrayBufferOrViewContents<char> buf2(args[1]);

    if (buf1.size() != buf2.size()) {
        THROW_ERR_CRYPTO_TIMING_SAFE_EQUAL_LENGTH(env);
        return;
    }

    return args.GetReturnValue().Set(CRYPTO_memcmp(buf1.data(), buf2.data(), buf1.size()) == 0);
}

void Initialize(Environment* env, Local<Object> target)
{
    SetMethodNoSideEffect(env->context(), target, "timingSafeEqual", TimingSafeEqual);
}
void RegisterExternalReferences(ExternalReferenceRegistry* registry)
{
    registry->Register(TimingSafeEqual);
}
} // namespace Timing

} // namespace crypto
} // namespace node
