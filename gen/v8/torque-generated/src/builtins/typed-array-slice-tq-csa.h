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

#ifndef V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TYPED_ARRAY_SLICE_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TYPED_ARRAY_SLICE_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-slice.tq?l=8&c=1
const char* kBuiltinNameSlice_0(compiler::CodeAssemblerState* state_);
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-slice.tq?l=13&c=1
void FastCopy_0(compiler::CodeAssemblerState* state_, TNode<JSTypedArray> p_src, TNode<JSTypedArray> p_dest, TNode<UintPtrT> p_k, TNode<UintPtrT> p_count,
    compiler::CodeAssemblerLabel* label_IfSlow);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/builtins/typed-array-slice.tq?l=62&c=1
void SlowCopy_0(
    compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSTypedArray> p_src, TNode<JSTypedArray> p_dest, TNode<UintPtrT> p_k, TNode<UintPtrT> p_final);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_BUILTINS_TYPED_ARRAY_SLICE_TQ_CSA_H_
