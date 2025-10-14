// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/base/ui_base_features.h"

#include <stdlib.h>

#include "base/feature_list.h"
#include "base/metrics/field_trial_params.h"
#include "build/build_config.h"

namespace switches {

// Screen width is useful for debugging. Shipping implementations should detect
// this.
const char kDeJellyScreenWidth[] = "de-jelly-screen-width";

// The default number of the BeginFrames to wait to activate a surface with
// dependencies.
const char kDeadlineToSynchronizeSurfaces[] = "deadline-to-synchronize-surfaces";

// Disables begin frame limiting in both cc scheduler and display scheduler.
// Also implies --disable-gpu-vsync (see //ui/gl/gl_switches.h).
const char kDisableFrameRateLimit[] = "disable-frame-rate-limit";

// Sets the number of max pending frames in the GL buffer queue to 1.
const char kDoubleBufferCompositing[] = "double-buffer-compositing";

// Experimental de-jelly support.
const char kEnableDeJelly[] = "enable-de-jelly";

// Enable compositing individual elements via hardware overlays when
// permitted by device.
// Setting the flag to "single-fullscreen" will try to promote a single
// fullscreen overlay and use it as main framebuffer where possible.
const char kEnableHardwareOverlays[] = "enable-hardware-overlays";

// Effectively disables pipelining of compositor frame production stages by
// waiting for each stage to finish before completing a frame.
const char kRunAllCompositorStagesBeforeDraw[] = "run-all-compositor-stages-before-draw";

// Adds a DebugBorderDrawQuad to the top of the root RenderPass showing the
// damage rect after surface aggregation. Note that when enabled this feature
// sets the entire output rect as damaged after adding the quad to highlight the
// real damage rect, which could hide damage rect problems.
const char kShowAggregatedDamage[] = "show-aggregated-damage";

// Modulates the debug compositor tint color so that damage and page flip
// updates are made clearly visible. This feature was useful in determining the
// root cause of https://b.corp.google.com/issues/183260320 . The tinting flag
// "tint-composited-content" must also be enabled for this flag to used.
const char kTintCompositedContentModulate[] = "tint-composited-content-modulate";

// Show debug borders for DC layers - red for overlays and blue for underlays.
// The debug borders are offset from the layer rect by a few pixels for clarity.
const char kShowDCLayerDebugBorders[] = "show-dc-layer-debug-borders";
} // switches

namespace features {

const char kPredictorNameLsq[] = "lsq";
const char kPredictorNameKalman[] = "kalman";
const char kPredictorNameLinearFirst[] = "linear_first";
const char kPredictorNameLinearSecond[] = "linear_second";
const char kPredictorNameLinearResampling[] = "linear_resampling";
const char kPredictorNameEmpty[] = "empty";

const char kFilterNameEmpty[] = "empty_filter";
const char kFilterNameOneEuro[] = "one_euro_filter";

const char kPredictionTypeTimeBased[] = "time";
const char kPredictionTypeFramesBased[] = "frames";
const char kPredictionTypeDefaultTime[] = "3.3";
const char kPredictionTypeDefaultFramesRatio[] = "0.5";

bool IsEyeDropperEnabled() { return base::FeatureList::IsEnabled(features::kEyeDropper); }

// Enables percent-based scrolling for mousewheel and keyboard initiated
// scrolls and impulse curve animations.
const enum base::FeatureState kWindowsScrollingPersonalityDefaultStatus = base::FEATURE_DISABLED_BY_DEFAULT;
static_assert(!BUILDFLAG(IS_MAC) || (BUILDFLAG(IS_MAC) && kWindowsScrollingPersonalityDefaultStatus == base::FEATURE_DISABLED_BY_DEFAULT),
    "Do not enable this on the Mac. The animation does not match the "
    "system scroll animation curve to such an extent that it makes "
    "Chromium stand out in a bad way.");
BASE_FEATURE(kWindowsScrollingPersonality, "WindowsScrollingPersonality", kWindowsScrollingPersonalityDefaultStatus);

bool IsPercentBasedScrollingEnabled() { return base::FeatureList::IsEnabled(features::kWindowsScrollingPersonality); }

BASE_FEATURE(kSwipeToMoveCursor, "SwipeToMoveCursor", base::FEATURE_DISABLED_BY_DEFAULT);

bool IsSwipeToMoveCursorEnabled()
{
    static const bool enabled =
#if BUILDFLAG(IS_ANDROID)
        base::android::BuildInfo::GetInstance()->sdk_int() >= base::android::SDK_VERSION_R;
#else
        base::FeatureList::IsEnabled(kSwipeToMoveCursor);
#endif
    return enabled;
}

bool IsTextBasedAudioDescriptionEnabled(void) { return true; }

bool IsUsingRawDraw(void) { return true; }

#if SK_SUPPORT_GPU != 1
bool IsUsingVulkan(void) { return false; }
#endif

}