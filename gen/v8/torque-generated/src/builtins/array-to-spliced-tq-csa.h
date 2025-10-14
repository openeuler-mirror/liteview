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

#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_TO_SPLICED_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_TO_SPLICED_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=8&c=1
TNode<JSArray> CopyFastPackedArrayForToSpliced_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, ElementsKind p_kind, TNode<JSArray> p_array,
    TNode<Smi> p_newLenSmi, TNode<Smi> p_actualStartSmi, TNode<Smi> p_insertCountSmi, TNode<Smi> p_actualDeleteCountSmi);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=51&c=1
TNode<JSArray> TryFastArrayToSpliced_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSReceiver> p_o,
    TNode<Number> p_originalLenNumber, TNode<Number> p_newLenNumber, TNode<Number> p_actualStartNumber, TNode<Smi> p_insertCount, TNode<Number> p_actualDeleteCountNumber,
    compiler::CodeAssemblerLabel* label_Slow);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=110&c=1
TNode<JSArray> GenericArrayToSpliced_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TorqueStructArguments p_args, TNode<JSReceiver> p_o, TNode<Number> p_newLen,
    TNode<Number> p_actualStart, TNode<Number> p_actualDeleteCount);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=100&c=5
void InsertArgumentsIntoFastPackedArray_FixedArray_JSAny_0(
    compiler::CodeAssemblerState* state_, TNode<JSArray> p_dst, TNode<Smi> p_dstStart, TorqueStructArguments p_args, IntegerLiteral p_argsStart, TNode<Smi> p_insertCount);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/array-to-spliced.tq?l=103&c=5
void InsertArgumentsIntoFastPackedArray_FixedDoubleArray_Number_0(
    compiler::CodeAssemblerState* state_, TNode<JSArray> p_dst, TNode<Smi> p_dstStart, TorqueStructArguments p_args, IntegerLiteral p_argsStart, TNode<Smi> p_insertCount);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_ARRAY_TO_SPLICED_TQ_CSA_H_
