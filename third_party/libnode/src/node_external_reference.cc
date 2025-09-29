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

#include "node_external_reference.h"
#include <cinttypes>
#include <vector>
#include "base_object-inl.h"
#include "util.h"

namespace node {

const std::vector<intptr_t>& ExternalReferenceRegistry::external_references()
{
    if (!is_finalized_) {
        external_references_.push_back(reinterpret_cast<intptr_t>(nullptr));
        is_finalized_ = true;
    }

    return external_references_;
}

ExternalReferenceRegistry::ExternalReferenceRegistry()
{
    this->Register(BaseObject::LazilyInitializedJSTemplateConstructor);

#define V(modname) _register_external_reference_##modname(this);
    EXTERNAL_REFERENCE_BINDING_LIST(V)
#undef V
    // TODO(joyeecheung): collect more external references here.
}

} // namespace node
