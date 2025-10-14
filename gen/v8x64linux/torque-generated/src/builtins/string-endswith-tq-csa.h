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

#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_STRING_ENDSWITH_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_STRING_ENDSWITH_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/string-endswith.tq?l=35&c=1
TNode<BoolT> IsSubstringAt_0(compiler::CodeAssemblerState* state_, TNode<String> p_string, TNode<String> p_searchStr, TNode<IntPtrT> p_start);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/string-endswith.tq?l=36&c=10
TNode<BoolT> TwoStringsToSlices_bool_IsSubstringAtFunctor_0(
    compiler::CodeAssemblerState* state_, TNode<String> p_s1, TNode<String> p_s2, TorqueStructIsSubstringAtFunctor_0 p_f);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/string-endswith.tq?l=32&c=10
TNode<BoolT> IsSubstringAt_char8_char8_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char8_ConstReference_char8_0 p_string,
    TorqueStructSlice_char8_ConstReference_char8_0 p_searchStr, TNode<IntPtrT> p_start);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/string-endswith.tq?l=32&c=10
TNode<BoolT> IsSubstringAt_char8_char16_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char8_ConstReference_char8_0 p_string,
    TorqueStructSlice_char16_ConstReference_char16_0 p_searchStr, TNode<IntPtrT> p_start);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/string-endswith.tq?l=32&c=10
TNode<BoolT> IsSubstringAt_char16_char8_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char16_ConstReference_char16_0 p_string,
    TorqueStructSlice_char8_ConstReference_char8_0 p_searchStr, TNode<IntPtrT> p_start);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/string-endswith.tq?l=32&c=10
TNode<BoolT> IsSubstringAt_char16_char16_0(compiler::CodeAssemblerState* state_, TorqueStructSlice_char16_ConstReference_char16_0 p_string,
    TorqueStructSlice_char16_ConstReference_char16_0 p_searchStr, TNode<IntPtrT> p_start);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_STRING_ENDSWITH_TQ_CSA_H_
