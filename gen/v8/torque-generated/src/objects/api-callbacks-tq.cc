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

#include "src/objects/api-callbacks-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=5&c=1
bool IsCallHandlerInfo_NonInline(HeapObject o) { return o.IsCallHandlerInfo(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedCallHandlerInfo<CallHandlerInfo, HeapObject>::CallHandlerInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::CallHandlerInfoVerify(CallHandlerInfo::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=21&c=1
bool IsInterceptorInfo_NonInline(HeapObject o) { return o.IsInterceptorInfo(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedInterceptorInfo<InterceptorInfo, Struct>::InterceptorInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::InterceptorInfoVerify(InterceptorInfo::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=33&c=1
bool IsAccessCheckInfo_NonInline(HeapObject o) { return o.IsAccessCheckInfo(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedAccessCheckInfo<AccessCheckInfo, Struct>::AccessCheckInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::AccessCheckInfoVerify(AccessCheckInfo::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/api-callbacks.tq?l=53&c=1
bool IsAccessorInfo_NonInline(HeapObject o) { return o.IsAccessorInfo(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedAccessorInfo<AccessorInfo, HeapObject>::AccessorInfoVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::AccessorInfoVerify(AccessorInfo::cast(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
