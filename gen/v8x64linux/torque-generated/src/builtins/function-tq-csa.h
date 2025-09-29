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

#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_FUNCTION_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_FUNCTION_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/function.tq?l=28&c=1
void CheckAccessor_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<DescriptorArray> p_array, int32_t p_index, TNode<Name> p_name,
    compiler::CodeAssemblerLabel* label_Slow);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/function.tq?l=36&c=3
TNode<AccessorInfo> Cast_AccessorInfo_1(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<MaybeObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/function.tq?l=74&c=14
TorqueStructReference_Map_0 NativeContextSlot_NativeContext_Map_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<IntPtrT> p_index);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/function.tq?l=87&c=13
TNode<FixedArray> NewFixedArray_ArgumentsIterator_0(compiler::CodeAssemblerState* state_, TNode<IntPtrT> p_length, TorqueStructArgumentsIterator_0 p_it);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_FUNCTION_TQ_CSA_H_
