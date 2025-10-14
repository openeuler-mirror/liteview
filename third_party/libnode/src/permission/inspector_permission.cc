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

#include "inspector_permission.h"

#include <string>

namespace node {

namespace permission {

// Currently, Inspector manage a single state
// Once denied, it's always denied
void InspectorPermission::Apply(Environment* env, const std::vector<std::string>& allow, PermissionScope scope)
{
    deny_all_ = true;
}

bool InspectorPermission::is_granted(PermissionScope perm, const std::string_view& param) const
{
    return deny_all_ == false;
}

} // namespace permission
} // namespace node
