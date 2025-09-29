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

#ifndef V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_DATE_TIME_FORMAT_TQ_CSA_H_
#define V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_DATE_TIME_FORMAT_TQ_CSA_H_

#include "src/builtins/torque-csa-header-includes.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=23&c=1
TNode<JSDateTimeFormat> Cast_JSDateTimeFormat_0(compiler::CodeAssemblerState* state_, TNode<HeapObject> p_obj, compiler::CodeAssemblerLabel* label_CastError);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=24&c=3
TNode<String> LoadJSDateTimeFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=24&c=3
void StoreJSDateTimeFormatLocale_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<String> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=25&c=3
TNode<Foreign> LoadJSDateTimeFormatIcuLocale_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=25&c=3
void StoreJSDateTimeFormatIcuLocale_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<Foreign> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=26&c=3
TNode<Foreign> LoadJSDateTimeFormatIcuSimpleDateFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=26&c=3
void StoreJSDateTimeFormatIcuSimpleDateFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<Foreign> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=27&c=3
TNode<Foreign> LoadJSDateTimeFormatIcuDateIntervalFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=27&c=3
void StoreJSDateTimeFormatIcuDateIntervalFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<Foreign> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=28&c=3
TNode<HeapObject> LoadJSDateTimeFormatBoundFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=28&c=3
void StoreJSDateTimeFormatBoundFormat_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<HeapObject> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=29&c=3
TNode<Smi> LoadJSDateTimeFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=29&c=3
void StoreJSDateTimeFormatFlags_0(compiler::CodeAssemblerState* state_, TNode<JSDateTimeFormat> p_o, TNode<Smi> p_v);

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-date-time-format.tq?l=23&c=1
TNode<JSDateTimeFormat> DownCastForTorqueClass_JSDateTimeFormat_0(
    compiler::CodeAssemblerState* state_, TNode<HeapObject> p_o, compiler::CodeAssemblerLabel* label_CastError);

} // namespace internal
} // namespace v8

#endif // V8_GEN_TORQUE_GENERATED_SRC_OBJECTS_JS_DATE_TIME_FORMAT_TQ_CSA_H_
