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

#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ODDBALL_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ODDBALL_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=5&c=1
TNode<Oddball> Cast_Oddball_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=9&c=3
TNode<Float64T> LoadOddballToNumberRaw_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=9&c=3
void StoreOddballToNumberRaw_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<Float64T> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=10&c=3
TNode<String> LoadOddballToString_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=10&c=3
void StoreOddballToString_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=11&c=3
TNode<Number> LoadOddballToNumber_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=11&c=3
void StoreOddballToNumber_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<Number> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=12&c=3
TNode<String> LoadOddballTypeOf_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=12&c=3
void StoreOddballTypeOf_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=13&c=3
TNode<Smi> LoadOddballKind_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=13&c=3
void StoreOddballKind_0(compiler::CodeAssemblerState* state_, TNode<Oddball> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/oddball.tq?l=5&c=1
TNode<Oddball> DownCastForTorqueClass_Oddball_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_ODDBALL_TQ_CSA_H_
