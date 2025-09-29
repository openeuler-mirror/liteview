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

#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_MATCH_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_MATCH_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=22&c=1
TNode<Object> RegExpPrototypeMatchBody_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_regexp, TNode<String> p_string, bool p_isFastPath);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=123&c=1
TNode<Object> FastRegExpPrototypeMatchBody_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_receiver, TNode<String> p_string);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=128&c=1
TNode<Object> SlowRegExpPrototypeMatchBody_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_receiver, TNode<String> p_string);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/regexp-match.tq?l=25&c=12
TNode<BoolT> Is_FastJSRegExp_JSReceiver_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_o);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_REGEXP_MATCH_TQ_CSA_H_
