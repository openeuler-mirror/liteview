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

#include "src/objects/turbofan-types-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=12&c=1
bool IsTurbofanType_NonInline(HeapObject o) { return o.IsTurbofanType(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTurbofanType<TurbofanType, HeapObject>::TurbofanTypeVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TurbofanTypeVerify(TurbofanType::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=59&c=1
bool IsTurbofanBitsetType_NonInline(HeapObject o) { return o.IsTurbofanBitsetType(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTurbofanBitsetType<TurbofanBitsetType, TurbofanType>::TurbofanBitsetTypeVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TurbofanBitsetTypeVerify(TurbofanBitsetType::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=65&c=1
bool IsTurbofanUnionType_NonInline(HeapObject o) { return o.IsTurbofanUnionType(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTurbofanUnionType<TurbofanUnionType, TurbofanType>::TurbofanUnionTypeVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TurbofanUnionTypeVerify(TurbofanUnionType::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=71&c=1
bool IsTurbofanRangeType_NonInline(HeapObject o) { return o.IsTurbofanRangeType(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTurbofanRangeType<TurbofanRangeType, TurbofanType>::TurbofanRangeTypeVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TurbofanRangeTypeVerify(TurbofanRangeType::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=77&c=1
bool IsTurbofanHeapConstantType_NonInline(HeapObject o) { return o.IsTurbofanHeapConstantType(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTurbofanHeapConstantType<TurbofanHeapConstantType, TurbofanType>::TurbofanHeapConstantTypeVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TurbofanHeapConstantTypeVerify(TurbofanHeapConstantType::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/turbofan-types.tq?l=82&c=1
bool IsTurbofanOtherNumberConstantType_NonInline(HeapObject o) { return o.IsTurbofanOtherNumberConstantType(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTurbofanOtherNumberConstantType<TurbofanOtherNumberConstantType, TurbofanType>::TurbofanOtherNumberConstantTypeVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TurbofanOtherNumberConstantTypeVerify(TurbofanOtherNumberConstantType::cast(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
