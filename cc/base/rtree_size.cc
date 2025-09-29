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


#include "cc/base/rtree_size.h"

#include <stddef.h>
#include <stdint.h>

#include <algorithm>
#include <cmath>
#include <map>
#include <utility>
#include <vector>

#include "base/check_op.h"
#include "base/memory/raw_ptr.h"
#include "base/numerics/clamped_math.h"
#include "ui/gfx/geometry/rect.h"

namespace cc {

RTreeSize::Branch::Branch() = default;

RTreeSize::Branch::Branch(size_t payload, const gfx::Rect& bounds)
    : payload(std::move(payload))
    , bounds(bounds)
{
}

RTreeSize::RTreeSize() = default;

RTreeSize::~RTreeSize() = default;

RTreeSize::Node::Node(uint16_t level)
    : level(level)
{
}

RTreeSize::FlatNode::FlatNode(uint16_t level)
    : level(level)
{
}

int RTreeSize::FindSubtreePos(const Node* node) const
{
    for (size_t i = 0; i < nodes_.size(); ++i) {
        if (node == &nodes_[i])
            return (int)i;
    }
    return -1;
}

RTreeSize::Node* RTreeSize::GetSubtree(int pos)
{
    if (pos < 0 || pos >= (int)nodes_.size())
        return nullptr;

    return &nodes_[pos];
}

RTreeSize::FlatHead* RTreeSize::Serialize() const
{
    size_t size = sizeof(FlatHead) + nodes_.size() * sizeof(FlatNode);
    FlatHead* head = (FlatHead*)malloc(0x1000);
    head->size = size;
    head->has_valid_bounds = has_valid_bounds_;
    head->num_data_elements = num_data_elements_;
    head->root.bounds = root_.bounds;
    head->root.payload = root_.payload;
    head->root.subtree_pos = FindSubtreePos(root_.subtree.get());
    head->node_num = nodes_.size();

    FlatNode* pos = (FlatNode*)(head + 1);

    for (size_t i = 0; i < nodes_.size(); ++i, ++pos) {
        pos->num_children = nodes_[i].num_children;
        pos->level = nodes_[i].level;
        for (size_t j = 0; j < pos->num_children; ++j) {
            pos->children[j].bounds = nodes_[i].children[j].bounds;
            pos->children[j].payload = nodes_[i].children[j].payload;
            int subtree_pos = FindSubtreePos(nodes_[i].children[j].subtree.get());
            pos->children[j].subtree_pos = subtree_pos;
        }
    }
    return head;
}

void RTreeSize::Deserialize(FlatHead* head)
{
    size_t node_num = head->node_num;
    num_data_elements_ = head->num_data_elements;
    has_valid_bounds_ = head->has_valid_bounds;

    root_.bounds = head->root.bounds;
    root_.payload = head->root.payload;

    FlatNode* pos = (FlatNode*)(head + 1);
    nodes_.reserve(node_num);
    for (size_t i = 0; i < node_num; ++i, ++pos) {
        Node* node = AllocateNodeAtLevel(pos->level);
        node->num_children = pos->num_children;
    }
    root_.subtree = GetSubtree(head->root.subtree_pos);

    pos = (FlatNode*)(head + 1);
    for (size_t i = 0; i < node_num; ++i, ++pos) {
        Node* node = &nodes_[i];
        for (size_t j = 0; j < pos->num_children; ++j) {
            node->children[j].bounds = pos->children[j].bounds;
            node->children[j].payload = pos->children[j].payload;
            node->children[j].subtree = GetSubtree(pos->children[j].subtree_pos);
        }
    }
}

RTreeSize::Node* RTreeSize::AllocateNodeAtLevel(int level)
{
    // We don't allow reallocations, since that would invalidate references to
    // existing nodes, so verify that capacity > size.
    DCHECK_GT(nodes_.capacity(), nodes_.size());
    nodes_.emplace_back(level);
    return &nodes_.back();
}

RTreeSize::Branch RTreeSize::BuildRecursive(std::vector<Branch>* branches, int level)
{
    // Only one branch.  It will be the root.
    if (branches->size() == 1)
        return std::move((*branches)[0]);

    // TODO(vmpstr): Investigate if branches should be sorted in y.
    // The comment from Skia reads:
    // We might sort our branches here, but we expect Blink gives us a reasonable
    // x,y order. Skipping a call to sort (in Y) here resulted in a 17% win for
    // recording with negligible difference in playback speed.
    int remainder = static_cast<int>(branches->size() % kMaxChildren);

    if (remainder > 0) {
        // If the remainder isn't enough to fill a node, we'll add fewer nodes to
        // other branches.
        if (remainder >= kMinChildren)
            remainder = 0;
        else
            remainder = kMinChildren - remainder;
    }

    size_t current_branch = 0;

    size_t new_branch_index = 0;
    while (current_branch < branches->size()) {
        int increment_by = kMaxChildren;
        if (remainder != 0) {
            // if need be, omit some nodes to make up for remainder
            if (remainder <= kMaxChildren - kMinChildren) {
                increment_by -= remainder;
                remainder = 0;
            } else {
                increment_by = kMinChildren;
                remainder -= kMaxChildren - kMinChildren;
            }
        }
        Node* node = AllocateNodeAtLevel(level);
        node->num_children = 1;
        node->children[0] = (*branches)[current_branch];

        Branch branch;
        branch.bounds = (*branches)[current_branch].bounds;
        branch.subtree = node;
        ++current_branch;
        int x = branch.bounds.x();
        int y = branch.bounds.y();
        int right = branch.bounds.right();
        int bottom = branch.bounds.bottom();
        for (int k = 1; k < increment_by && current_branch < branches->size(); ++k) {
            // We use a custom union instead of gfx::Rect::Union here, since this
            // bypasses some empty checks and extra setters, which improves
            // performance.
            auto& bounds = (*branches)[current_branch].bounds;
            x = std::min(x, bounds.x());
            y = std::min(y, bounds.y());
            right = std::max(right, bounds.right());
            bottom = std::max(bottom, bounds.bottom());

            node->children[k] = (*branches)[current_branch];
            ++node->num_children;
            ++current_branch;
        }
        branch.bounds.SetRect(x, y, base::ClampSub(right, x), base::ClampSub(bottom, y));

        // If we had to clamp right/bottom values, we've overflowed.
        bool overflow = branch.bounds.right() != right || branch.bounds.bottom() != bottom;
        has_valid_bounds_ &= !overflow;

        DCHECK_LT(new_branch_index, current_branch);
        (*branches)[new_branch_index] = std::move(branch);
        ++new_branch_index;
    }
    branches->resize(new_branch_index);
    return BuildRecursive(branches, level + 1);
}

void RTreeSize::Search(const gfx::Rect& query, std::vector<size_t>* results, std::vector<gfx::Rect>* rects) const
{
    results->clear();
    if (num_data_elements_ == 0)
        return;
    if (!has_valid_bounds_) {
        SearchRecursiveFallback(root_.subtree.get(), query, results, rects);
    } else if (query.Intersects(root_.bounds)) {
        SearchRecursive(root_.subtree.get(), query, results, rects);
    }
}

void RTreeSize::SearchRefs(const gfx::Rect& query, std::vector<const size_t*>* results) const
{
    results->clear();
    if (num_data_elements_ == 0)
        return;
    if (!has_valid_bounds_) {
        SearchRefsRecursiveFallback(root_.subtree.get(), query, results);
    } else if (query.Intersects(root_.bounds)) {
        SearchRefsRecursive(root_.subtree.get(), query, results);
    }
}

void RTreeSize::SearchRecursive(Node* node, const gfx::Rect& query, std::vector<size_t>* results, std::vector<gfx::Rect>* rects) const
{
    for (uint16_t i = 0; i < node->num_children; ++i) {
        if (query.Intersects(node->children[i].bounds)) {
            if (node->level == 0) {
                results->push_back(node->children[i].payload);
                if (rects)
                    rects->push_back(node->children[i].bounds);
            } else {
                SearchRecursive(node->children[i].subtree.get(), query, results, rects);
            }
        }
    }
}

void RTreeSize::SearchRefsRecursive(Node* node, const gfx::Rect& query, std::vector<const size_t*>* results) const
{
    for (uint16_t i = 0; i < node->num_children; ++i) {
        if (query.Intersects(node->children[i].bounds)) {
            if (node->level == 0)
                results->push_back(&node->children[i].payload);
            else
                SearchRefsRecursive(node->children[i].subtree.get(), query, results);
        }
    }
}

// When !has_valid_bounds(), any non-leaf bounds may have overflowed and be
// invalid. Iterate over the entire tree, checking bounds at each leaf.
void RTreeSize::SearchRecursiveFallback(Node* node, const gfx::Rect& query, std::vector<size_t>* results, std::vector<gfx::Rect>* rects) const
{
    for (uint16_t i = 0; i < node->num_children; ++i) {
        if (node->level == 0) {
            if (query.Intersects(node->children[i].bounds)) {
                results->push_back(node->children[i].payload);
                if (rects)
                    rects->push_back(node->children[i].bounds);
            }
        } else {
            SearchRecursive(node->children[i].subtree.get(), query, results, rects);
        }
    }
}

void RTreeSize::SearchRefsRecursiveFallback(Node* node, const gfx::Rect& query, std::vector<const size_t*>* results) const
{
    for (uint16_t i = 0; i < node->num_children; ++i) {
        if (node->level == 0) {
            if (query.Intersects(node->children[i].bounds))
                results->push_back(&node->children[i].payload);
        } else {
            SearchRefsRecursive(node->children[i].subtree.get(), query, results);
        }
    }
}

gfx::Rect RTreeSize::GetBoundsOrDie() const
{
    CHECK(has_valid_bounds_);
    return root_.bounds;
}

std::map<size_t, gfx::Rect> RTreeSize::GetAllBoundsForTracing() const
{
    std::map<size_t, gfx::Rect> results;
    if (num_data_elements_ > 0)
        GetAllBoundsRecursive(root_.subtree.get(), &results);
    return results;
}

void RTreeSize::GetAllBoundsRecursive(Node* node, std::map<size_t, gfx::Rect>* results) const
{
    for (uint16_t i = 0; i < node->num_children; ++i) {
        if (node->level == 0)
            (*results)[node->children[i].payload] = node->children[i].bounds;
        else
            GetAllBoundsRecursive(node->children[i].subtree.get(), results);
    }
}

void RTreeSize::Reset()
{
    num_data_elements_ = 0;
    root_.subtree = nullptr;
    nodes_.clear();
    root_.bounds = gfx::Rect();
    has_valid_bounds_ = true;
}

} // namespace cc
