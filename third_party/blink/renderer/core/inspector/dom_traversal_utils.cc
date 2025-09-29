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

#include "third_party/blink/renderer/core/inspector/dom_traversal_utils.h"

#include "third_party/blink/renderer/core/dom/flat_tree_traversal.h"
#include "third_party/blink/renderer/core/dom/node.h"
#include "third_party/blink/renderer/core/dom/shadow_root.h"

namespace blink {
namespace dom_traversal_utils {

Node* FirstChild(const Node& node, bool include_user_agent_shadow_tree)
{
    DCHECK(include_user_agent_shadow_tree || !node.IsInUserAgentShadowRoot());
    if (!include_user_agent_shadow_tree) {
        ShadowRoot* shadow_root = node.GetShadowRoot();
        if (shadow_root && shadow_root->GetType() == ShadowRootType::kUserAgent)
            return node.firstChild();
    }
    return FlatTreeTraversal::FirstChild(node);
}

// static
bool HasChildren(const Node& node, bool include_user_agent_shadow_tree)
{
    return FirstChild(node, include_user_agent_shadow_tree);
}

// static
Node* NextSibling(const Node& node, bool include_user_agent_shadow_tree)
{
    DCHECK(include_user_agent_shadow_tree || !node.IsInUserAgentShadowRoot());
    if (!include_user_agent_shadow_tree) {
        if (node.ParentElementShadowRoot() && node.ParentElementShadowRoot()->GetType() == ShadowRootType::kUserAgent) {
            return node.nextSibling();
        }
    }
    return FlatTreeTraversal::NextSibling(node);
}

} // namespace dom_traversal_utils
} // namespace blink
