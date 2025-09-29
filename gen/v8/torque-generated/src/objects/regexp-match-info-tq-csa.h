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

#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_REGEXP_MATCH_INFO_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_REGEXP_MATCH_INFO_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=28&c=1
int31_t GetStartOfCaptureIndex_0(compiler::CodeAssemblerState* state_, int31_t p_captureIndex);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=8&c=3
TNode<Smi> Method_RegExpMatchInfo_GetStartOfCapture_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RegExpMatchInfo> p_this, int31_t p_captureIndex);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=13&c=3
TNode<Smi> Method_RegExpMatchInfo_GetEndOfCapture_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RegExpMatchInfo> p_this, int31_t p_captureIndex);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/regexp-match-info.tq?l=18&c=3
TNode<Smi> Method_RegExpMatchInfo_NumberOfCaptures_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<RegExpMatchInfo> p_this);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_REGEXP_MATCH_INFO_TQ_CSA_H_
