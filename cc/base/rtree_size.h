// Copyright 2015 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CC_BASE_RTREE_SIZE_H_
#define CC_BASE_RTREE_SIZE_H_

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

// The following description and most of the implementation is borrowed from
// Skia's SkRTree implementation.
//
// An R-Tree implementation. In short, it is a balanced n-ary tree containing a
// hierarchy of bounding rectangles.
//
// It only supports bulk-loading, i.e. creation from a batch of bounding
// rectangles. This performs a bottom-up bulk load using the STR
// (sort-tile-recursive) algorithm.
//
// Things to do: Experiment with other bulk-load algorithms (in particular the
// Hilbert pack variant, which groups rects by position on the Hilbert curve, is
// probably worth a look). There also exist top-down bulk load variants
// (VAMSplit, TopDownGreedy, etc).
//
// For more details see:
//
//  Beckmann, N.; Kriegel, H. P.; Schneider, R.; Seeger, B. (1990).
//  "The R*-tree: an efficient and robust access method for points and
//  rectangles"
class RTreeSize {
public:
    RTreeSize();
    RTreeSize(const RTreeSize&) = delete;
    ~RTreeSize();

    RTreeSize& operator=(const RTreeSize&) = delete;

    // Constructs the rtree from a given container of gfx::Rects. Queries using
    // Search will then return indices into this container.
    template <typename Container> inline void Build(const Container& items);

    // Build helper that takes a container, a function used to get gfx::Rect
    // from each item, and a function used to get the payload for each item. That
    // is, "bounds_getter(items, i);" should return a gfx::Rect representing the
    // bounds of ith item, and "payload_getter(items, i);" should return the
    // payload (aka T) of ith item.
    template <typename Container, typename BoundsFunctor, typename PayloadFunctor>
    inline void Build(const Container& items, const BoundsFunctor& bounds_getter, const PayloadFunctor& payload_getter);

    // If false, this rtree does not have valid bounds and:
    //  - GetBoundsOrDie will CHECK.
    //  - Search* will have degraded performance.
    bool has_valid_bounds() const
    {
        return has_valid_bounds_;
    }

    // Given a query rect, returns elements that intersect the rect. Elements are
    // returned in the order they appeared in the initial container.
    void Search(const gfx::Rect& query, std::vector<size_t>* results, std::vector<gfx::Rect>* rects = nullptr) const;

    // Given a query rect, returns non-owning pointers to elements that intersect
    // the rect. Elements are returned in the order they appeared in the initial
    // container.
    void SearchRefs(const gfx::Rect& query, std::vector<const size_t*>* results) const;

    // Returns the total bounds of all items in this rtree.
    // if !has_valid_bounds() this function will CHECK.
    gfx::Rect GetBoundsOrDie() const;

    // Returns respective bounds of all items in this rtree in the order of items.
    // Production code except tracing should not use this method.
    std::map<size_t, gfx::Rect> GetAllBoundsForTracing() const;

    void Reset();

private:
    // These values were empirically determined to produce reasonable performance
    // in most cases.
    static constexpr int kMinChildren = 6;
    static constexpr int kMaxChildren = 11;

    struct Node;

    struct Branch {
        // When the node level is 0, then the node is a leaf and the branch has a
        // valid index pointing to an element in the vector that was used to build
        // this rtree. When the level is not 0, it's an internal node and it has a
        // valid subtree pointer.
        raw_ptr<Node> subtree = nullptr;
        size_t payload = 0;

        gfx::Rect bounds;

        Branch();
        Branch(size_t payload, const gfx::Rect& bounds);
    };

    struct Node {
        uint16_t num_children = 0u;
        uint16_t level = 0u;
        Branch children[kMaxChildren];

        Node(uint16_t level);
    };

#ifndef NO_RBI
public:
    struct FlatBranch {
        int subtree_pos;
        size_t payload;
        gfx::Rect bounds;
    };

    struct FlatNode {
        uint16_t num_children = 0u;
        uint16_t level = 0u;
        FlatBranch children[kMaxChildren];

        FlatNode(uint16_t level);
    };

    struct FlatHead {
        size_t size;
        size_t num_data_elements = 0u;
        bool has_valid_bounds = true;
        size_t node_num = 0;
        FlatBranch root;
    };
    int FindSubtreePos(const Node* node) const;

    Node* GetSubtree(int pos);

    FlatHead* Serialize() const;

    void Deserialize(FlatHead* head);
private:
#endif
    void SearchRecursive(Node* root, const gfx::Rect& query, std::vector<size_t>* results, std::vector<gfx::Rect>* rects = nullptr) const;
    void SearchRefsRecursive(Node* root, const gfx::Rect& query, std::vector<const size_t*>* results) const;

    // The following two functions are slow fallback versions of SearchRecursive
    // and SearchRefsRecursive for when !has_valid_bounds().
    void SearchRecursiveFallback(Node* root, const gfx::Rect& query, std::vector<size_t>* results, std::vector<gfx::Rect>* rects = nullptr) const;
    void SearchRefsRecursiveFallback(Node* root, const gfx::Rect& query, std::vector<const size_t*>* results) const;

    // Consumes the input array.
    Branch BuildRecursive(std::vector<Branch>* branches, int level);
    Node* AllocateNodeAtLevel(int level);

    void GetAllBoundsRecursive(Node* root, std::map<size_t, gfx::Rect>* results) const;

    // This is the count of data elements (rather than total nodes in the tree)
    size_t num_data_elements_ = 0u;
    std::vector<Node> nodes_;
    Branch root_;

    // If false, the rtree encountered overflow does not have reliable bounds.
    bool has_valid_bounds_ = true;
};

template <typename Container> inline 
void RTreeSize::Build(const Container& items)
{
    Build(items, 
        [](const Container& items, size_t index) { 
            return items[index]; 
        },
        [](const Container& items, size_t index) { 
            return index; 
        }
    );
}

template <typename Container, typename BoundsFunctor, typename PayloadFunctor> inline
void RTreeSize::Build(const Container& items, const BoundsFunctor& bounds_getter, const PayloadFunctor& payload_getter)
{
    DCHECK_EQ(0u, num_data_elements_);

    std::vector<Branch> branches;
    branches.reserve(items.size());

    for (size_t i = 0; i < items.size(); i++) {
        const gfx::Rect& bounds = bounds_getter(items, i);
        if (bounds.IsEmpty())
            continue;
        branches.emplace_back(payload_getter(items, i), bounds);
    }

    num_data_elements_ = branches.size();
    if (num_data_elements_ == 1u) {
        nodes_.reserve(1);
        Node* node = AllocateNodeAtLevel(0);
        root_.subtree = node;
        root_.bounds = branches[0].bounds;
        node->num_children = 1;
        node->children[0] = std::move(branches[0]);
    } else if (num_data_elements_ > 1u) {
        // Determine a reasonable upper bound on the number of nodes to prevent
        // reallocations. This is basically (n**d - 1) / (n - 1), which is the
        // number of nodes in a complete tree with n branches at each node. In the
        // code n = |branch_count|, d = |depth|. However, we normally would have
        // kMaxChildren branch factor, but that can be broken if some children
        // don't have enough nodes. That can happen for at most kMinChildren nodes
        // (since otherwise, we'd create a new node).
        size_t branch_count = kMaxChildren;
        double depth = log(branches.size()) / log(branch_count);
        size_t node_count = static_cast<size_t>((std::pow(branch_count, depth) - 1) / (branch_count - 1)) + kMinChildren;
        nodes_.reserve(node_count);
        root_ = BuildRecursive(&branches, 0);
    }
    // We should've wasted at most kMinChildren nodes.
    DCHECK_LE(nodes_.capacity() - nodes_.size(), static_cast<size_t>(kMinChildren));
}

} // namespace cc

#endif // CC_BASE_RTREE_H_
