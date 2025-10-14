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

#include "src/objects/js-atomics-synchronization-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=5&c=1
bool IsJSSynchronizationPrimitive_NonInline(HeapObject o) { return o.IsJSSynchronizationPrimitive(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSSynchronizationPrimitive<JSSynchronizationPrimitive, JSObject>::JSSynchronizationPrimitiveVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSSynchronizationPrimitiveVerify(JSSynchronizationPrimitive::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=11&c=1
bool IsJSAtomicsMutex_NonInline(HeapObject o) { return o.IsJSAtomicsMutex(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSAtomicsMutex<JSAtomicsMutex, JSSynchronizationPrimitive>::JSAtomicsMutexVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSAtomicsMutexVerify(JSAtomicsMutex::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-atomics-synchronization.tq?l=18&c=1
bool IsJSAtomicsCondition_NonInline(HeapObject o) { return o.IsJSAtomicsCondition(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSAtomicsCondition<JSAtomicsCondition, JSSynchronizationPrimitive>::JSAtomicsConditionVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSAtomicsConditionVerify(JSAtomicsCondition::cast(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
