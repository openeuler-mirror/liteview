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

#include "env-inl.h"
#include "node_binding.h"
#include "util.h"

namespace node {

using v8::Context;
using v8::Local;
using v8::Object;
using v8::Value;

namespace symbols {

static void Initialize(Local<Object> target, Local<Value> unused, Local<Context> context, void* priv)
{
    Environment* env = Environment::GetCurrent(context);
#define V(PropertyName, StringValue) target->Set(env->context(), env->PropertyName()->Description(env->isolate()), env->PropertyName()).Check();
    PER_ISOLATE_SYMBOL_PROPERTIES(V)
#undef V
}

} // namespace symbols
} // namespace node

NODE_BINDING_CONTEXT_AWARE_INTERNAL(symbols, node::symbols::Initialize)
