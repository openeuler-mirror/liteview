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

#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_SCHEDULER_MAIN_THREAD_USE_CASE_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_SCHEDULER_MAIN_THREAD_USE_CASE_H_

namespace blink {
namespace scheduler {

// Keep RendererScheduler::UseCaseToString in sync with this enum.
// This enum is used for histograms and should not be renumbered.
enum class UseCase {
    // No active use case detected.
    kNone = 0,
    // A continuous gesture (e.g., scroll, pinch) which is being driven by the
    // compositor thread.
    kCompositorGesture = 1,
    // An unspecified touch gesture which is being handled by the main thread.
    // Note that since we don't have a full view of the use case, we should be
    // careful to prioritize all work equally.
    kMainThreadCustomInputHandling = 2,
    // A continuous gesture (e.g., scroll, pinch) which is being driven by the
    // compositor thread but also observed by the main thread. An example is
    // synchronized scrolling where a scroll listener on the main thread changes
    // page layout based on the current scroll position.
    kSynchronizedGesture = 3,
    // A gesture has recently started and we are about to run main thread touch
    // listeners to find out the actual gesture type. To minimize touch latency,
    // only input handling work should run in this state.
    kTouchstart = 4,
    // A page is loading, and we've seen first contentful paint.
    kLoading = 5,
    // A continuous gesture (e.g., scroll) which is being handled by the main
    // thread.
    kMainThreadGesture = 6,
    // A page is loading but we've not had a first contentful paint yet.
    kEarlyLoading = 7,
    kFirstUseCase = kNone,

    // Must be the last entry.
    kCount = 8,
};

} // namespace scheduler
} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_PLATFORM_SCHEDULER_MAIN_THREAD_USE_CASE_H_
