// Copyright 2015 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "media/mb/renderer_webmediaplayer_delegate.h"

#include <stdint.h>

#include "base/auto_reset.h"
#include "base/bind.h"
#include "base/logging.h"
#include "base/metrics/user_metrics_action.h"
#include "base/system/sys_info.h"
#include "base/threading/thread_task_runner_handle.h"
//#include "content/public/common/content_client.h"
//#include "content/public/renderer/content_renderer_client.h"
//#include "content/public/renderer/render_frame.h"
//#include "content/public/renderer/render_thread.h"
#include "media/base/media_content_type.h"
#include "third_party/blink/public/mojom/frame/user_activation_notification_type.mojom.h"
#include "third_party/blink/public/platform/web_fullscreen_video_status.h"
#include "third_party/blink/public/web/web_local_frame.h"
#include "third_party/blink/public/web/web_view.h"
#include "third_party/blink/public/web/web_view_observer.h"
#include "ui/gfx/geometry/size.h"

namespace {

void RecordAction(const base::UserMetricsAction& action) {
  //content::RenderThread::Get()->RecordAction(action);
}

}  // namespace

namespace media {

RendererWebMediaPlayerDelegate::RendererWebMediaPlayerDelegate(content::WebLocalFrameClientImpl* frameClientImpl) 
    :m_frameClientImpl(frameClientImpl) {

}

RendererWebMediaPlayerDelegate::~RendererWebMediaPlayerDelegate() {}

bool RendererWebMediaPlayerDelegate::IsFrameHidden() {
    //*(int*)1 = 1;
    return false;
}

int RendererWebMediaPlayerDelegate::AddObserver(Observer* observer) {
    *(int*)1 = 1;
    return 0;
}

void RendererWebMediaPlayerDelegate::RemoveObserver(int player_id) {
    *(int*)1 = 1;
}

void RendererWebMediaPlayerDelegate::DidMediaMetadataChange(int player_id,
    bool has_audio,
    bool has_video,
    MediaContentType media_content_type) {
    //*(int*)1 = 1;
}

void RendererWebMediaPlayerDelegate::DidPlay(int player_id) {
    //*(int*)1 = 1;
}

void RendererWebMediaPlayerDelegate::DidPause(int player_id,
                                              bool reached_end_of_stream) {
    //*(int*)1 = 1;
}

void RendererWebMediaPlayerDelegate::PlayerGone(int player_id) {
    *(int*)1 = 1;
}

void RendererWebMediaPlayerDelegate::SetIdle(int player_id, bool is_idle) {
    *(int*)1 = 1;
}

bool RendererWebMediaPlayerDelegate::IsIdle(int player_id) {
    *(int*)1 = 1;
    return false;
}

void RendererWebMediaPlayerDelegate::ClearStaleFlag(int player_id) {
    *(int*)1 = 1;
}

bool RendererWebMediaPlayerDelegate::IsStale(int player_id) {
    //*(int*)1 = 1;
    return false;
}

//void RendererWebMediaPlayerDelegate::OnPageVisibilityChanged(
//    blink::mojom::PageVisibilityState visibility_state) {
//    *(int*)1 = 1;
//}

void RendererWebMediaPlayerDelegate::SetIdleCleanupParamsForTesting(
    base::TimeDelta idle_timeout,
    base::TimeDelta idle_cleanup_interval,
    const base::TickClock* tick_clock,
    bool is_low_end) {
    *(int*)1 = 1;
}

bool RendererWebMediaPlayerDelegate::IsIdleCleanupTimerRunningForTesting()
    const {
    *(int*)1 = 1;
  return idle_cleanup_timer_.IsRunning();
}

void RendererWebMediaPlayerDelegate::SetFrameHiddenForTesting(bool is_hidden) {
    *(int*)1 = 1;
}

void RendererWebMediaPlayerDelegate::ScheduleUpdateTask() {
    *(int*)1 = 1;
}

void RendererWebMediaPlayerDelegate::UpdateTask() {
    *(int*)1 = 1;
}

void RendererWebMediaPlayerDelegate::CleanUpIdlePlayers(
    base::TimeDelta timeout) {
    *(int*)1 = 1;
}

//void RendererWebMediaPlayerDelegate::OnDestruct() {
//  // All WebMediaPlayer instances should have been destructed by this point.
//    *(int*)1 = 1;
//  delete this;
//}

}  // namespace media
