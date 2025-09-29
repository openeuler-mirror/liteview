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

#include "src/objects/template-objects-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=5&c=1
bool IsCachedTemplateObject_NonInline(HeapObject o)
{
    return o.IsCachedTemplateObject();
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedCachedTemplateObject<CachedTemplateObject, Struct>::CachedTemplateObjectVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::CachedTemplateObjectVerify(CachedTemplateObject::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/template-objects.tq?l=11&c=1
bool IsTemplateObjectDescription_NonInline(HeapObject o)
{
    return o.IsTemplateObjectDescription();
}

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedTemplateObjectDescription<TemplateObjectDescription, Struct>::TemplateObjectDescriptionVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::TemplateObjectDescriptionVerify(TemplateObjectDescription::cast(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
