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

#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_SLICE_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_SLICE_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-slice.tq?l=6&c=1
TNode<JSArray> HandleSimpleArgumentsSlice_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<JSArgumentsObject> p_args,
    TNode<Smi> p_start, TNode<Smi> p_count, compiler::CodeAssemblerLabel* label_Bailout);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-slice.tq?l=30&c=1
TNode<JSArray> HandleFastAliasedSloppyArgumentsSlice_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<JSArgumentsObject> p_args,
    TNode<Smi> p_start, TNode<Smi> p_count, compiler::CodeAssemblerLabel* label_Bailout);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-slice.tq?l=86&c=1
TNode<JSArray> HandleFastSlice_0(compiler::CodeAssemblerState* state_, TNode<NativeContext> p_context, TNode<Object> p_o, TNode<Number> p_startNumber,
    TNode<Number> p_countNumber, compiler::CodeAssemblerLabel* label_Bailout);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-slice.tq?l=64&c=24
TNode<Object> UnsafeCast_JSReceiver_OR_Undefined_OR_Null_OR_False_OR_True_OR_Symbol_OR_String_OR_BigInt_OR_HeapNumber_OR_Smi_OR_TheHole_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-slice.tq?l=106&c=7
TNode<JSArgumentsObject> Cast_JSStrictArgumentsObject_1(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-slice.tq?l=109&c=7
TNode<JSArgumentsObject> Cast_JSSloppyArgumentsObject_1(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_SLICE_TQ_CSA_H_
