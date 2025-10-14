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

#include "src/objects/module-inl.h"

#include "torque-generated/class-verifiers.h"
#include "src/objects/instance-type-inl.h"

namespace v8 {
namespace internal {

// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=5&c=1
bool IsModule_NonInline(HeapObject o) { return o.IsModule(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedModule<Module, HeapObject>::ModuleVerify(Isolate* isolate) { TorqueGeneratedClassVerifiers::ModuleVerify(Module::cast(*this), isolate); }

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=20&c=1
bool IsJSModuleNamespace_NonInline(HeapObject o) { return o.IsJSModuleNamespace(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedJSModuleNamespace<JSModuleNamespace, JSSpecialObject>::JSModuleNamespaceVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::JSModuleNamespaceVerify(JSModuleNamespace::cast(*this), isolate);
}

#endif // VERIFY_HEAP
// https://source.chromium.org/chromium/chromium/src/+/main:v8/src/objects/module.tq?l=24&c=1
bool IsScriptOrModule_NonInline(HeapObject o) { return o.IsScriptOrModule(); }

#ifdef VERIFY_HEAP

template <> void TorqueGeneratedScriptOrModule<ScriptOrModule, Struct>::ScriptOrModuleVerify(Isolate* isolate)
{
    TorqueGeneratedClassVerifiers::ScriptOrModuleVerify(ScriptOrModule::cast(*this), isolate);
}

#endif // VERIFY_HEAP
} // namespace internal
} // namespace v8
