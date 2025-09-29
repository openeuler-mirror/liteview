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

#include "src/objects/js-promise-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/js-promise.tq?l=13&c=1
bool IsJSPromise_NonInline(HeapObject o) { return o.IsJSPromise(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSPromise<JSPromise, JSObjectWithEmbedderSlots>::JSPromiseVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSPromiseVerify(JSPromise::cast(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
