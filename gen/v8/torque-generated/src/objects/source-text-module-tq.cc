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

#include "src/objects/source-text-module-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=12&c=1
bool IsSourceTextModule_NonInline(HeapObject o) { return o.IsSourceTextModule(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedSourceTextModule<SourceTextModule, Module>::SourceTextModuleVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::SourceTextModuleVerify(SourceTextModule::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=50&c=1
bool IsModuleRequest_NonInline(HeapObject o) { return o.IsModuleRequest(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedModuleRequest<ModuleRequest, Struct>::ModuleRequestVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::ModuleRequestVerify(ModuleRequest::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/source-text-module.tq?l=61&c=1
bool IsSourceTextModuleInfoEntry_NonInline(HeapObject o) { return o.IsSourceTextModuleInfoEntry(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedSourceTextModuleInfoEntry<SourceTextModuleInfoEntry, Struct>::SourceTextModuleInfoEntryVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::SourceTextModuleInfoEntryVerify(SourceTextModuleInfoEntry::cast(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
