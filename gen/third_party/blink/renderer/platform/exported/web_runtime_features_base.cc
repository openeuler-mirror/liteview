// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/web_runtime_features_base.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/public/platform/web_runtime_features_base.h"

#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

namespace blink {

// static
void WebRuntimeFeaturesBase::EnableAccessibilityAriaVirtualContent(bool enable) { RuntimeEnabledFeatures::SetAccessibilityAriaVirtualContentEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAccessibilityAriaVirtualContentEnabled() { return RuntimeEnabledFeatures::AccessibilityAriaVirtualContentEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableAccessibilityExposeHTMLElement(bool enable) { RuntimeEnabledFeatures::SetAccessibilityExposeHTMLElementEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAccessibilityExposeHTMLElementEnabled() { return RuntimeEnabledFeatures::AccessibilityExposeHTMLElementEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableAccessibilityExposeIgnoredNodes(bool enable) { RuntimeEnabledFeatures::SetAccessibilityExposeIgnoredNodesEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAccessibilityExposeIgnoredNodesEnabled() { return RuntimeEnabledFeatures::AccessibilityExposeIgnoredNodesEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableAccessibilityPageZoom(bool enable) { RuntimeEnabledFeatures::SetAccessibilityPageZoomEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAccessibilityPageZoomEnabled() { return RuntimeEnabledFeatures::AccessibilityPageZoomEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableAccessibilityUseAXPositionForDocumentMarkers(bool enable)
{
    RuntimeEnabledFeatures::SetAccessibilityUseAXPositionForDocumentMarkersEnabled(enable);
}

// static
bool WebRuntimeFeaturesBase::IsAccessibilityUseAXPositionForDocumentMarkersEnabled() { return RuntimeEnabledFeatures::AccessibilityUseAXPositionForDocumentMarkersEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableAdTagging(bool enable) { RuntimeEnabledFeatures::SetAdTaggingEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAdTaggingEnabled() { return RuntimeEnabledFeatures::AdTaggingEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableAndroidDownloadableFontsMatching(bool enable) { RuntimeEnabledFeatures::SetAndroidDownloadableFontsMatchingEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAndroidDownloadableFontsMatchingEnabled() { return RuntimeEnabledFeatures::AndroidDownloadableFontsMatchingEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableAnonymousIframe(bool enable) { RuntimeEnabledFeatures::SetAnonymousIframeEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAnonymousIframeEnabled() { return RuntimeEnabledFeatures::AnonymousIframeEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableAOMAriaRelationshipProperties(bool enable) { RuntimeEnabledFeatures::SetAOMAriaRelationshipPropertiesEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAOMAriaRelationshipPropertiesEnabled() { return RuntimeEnabledFeatures::AOMAriaRelationshipPropertiesEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableAutoDisableAccessibilityV2(bool enable) { RuntimeEnabledFeatures::SetAutoDisableAccessibilityV2Enabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAutoDisableAccessibilityV2Enabled() { return RuntimeEnabledFeatures::AutoDisableAccessibilityV2Enabled(); }

// static
void WebRuntimeFeaturesBase::EnableAutomationControlled(bool enable) { RuntimeEnabledFeatures::SetAutomationControlledEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAutomationControlledEnabled() { return RuntimeEnabledFeatures::AutomationControlledEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableAutoplayIgnoresWebAudio(bool enable) { RuntimeEnabledFeatures::SetAutoplayIgnoresWebAudioEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsAutoplayIgnoresWebAudioEnabled() { return RuntimeEnabledFeatures::AutoplayIgnoresWebAudioEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableBackForwardCache(bool enable) { RuntimeEnabledFeatures::SetBackForwardCacheEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsBackForwardCacheEnabled() { return RuntimeEnabledFeatures::BackForwardCacheEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableBackForwardCacheNotRestoredReasons(bool enable) { RuntimeEnabledFeatures::SetBackForwardCacheNotRestoredReasonsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsBackForwardCacheNotRestoredReasonsEnabled() { return RuntimeEnabledFeatures::BackForwardCacheNotRestoredReasonsEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableBackgroundFetch(bool enable) { RuntimeEnabledFeatures::SetBackgroundFetchEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsBackgroundFetchEnabled() { return RuntimeEnabledFeatures::BackgroundFetchEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableBrowserVerifiedUserActivationKeyboard(bool enable) { RuntimeEnabledFeatures::SetBrowserVerifiedUserActivationKeyboardEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsBrowserVerifiedUserActivationKeyboardEnabled() { return RuntimeEnabledFeatures::BrowserVerifiedUserActivationKeyboardEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableBrowserVerifiedUserActivationMouse(bool enable) { RuntimeEnabledFeatures::SetBrowserVerifiedUserActivationMouseEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsBrowserVerifiedUserActivationMouseEnabled() { return RuntimeEnabledFeatures::BrowserVerifiedUserActivationMouseEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableCanvas2dImageChromium(bool enable) { RuntimeEnabledFeatures::SetCanvas2dImageChromiumEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsCanvas2dImageChromiumEnabled() { return RuntimeEnabledFeatures::Canvas2dImageChromiumEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableClearIdentityInCanMakePaymentEvent(bool enable) { RuntimeEnabledFeatures::SetClearIdentityInCanMakePaymentEventEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsClearIdentityInCanMakePaymentEventEnabled() { return RuntimeEnabledFeatures::ClearIdentityInCanMakePaymentEventEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableCompositeBGColorAnimation(bool enable) { RuntimeEnabledFeatures::SetCompositeBGColorAnimationEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsCompositeBGColorAnimationEnabled() { return RuntimeEnabledFeatures::CompositeBGColorAnimationEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableCompositedSelectionUpdate(bool enable) { RuntimeEnabledFeatures::SetCompositedSelectionUpdateEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsCompositedSelectionUpdateEnabled() { return RuntimeEnabledFeatures::CompositedSelectionUpdateEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableConsolidatedMovementXY(bool enable) { RuntimeEnabledFeatures::SetConsolidatedMovementXYEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsConsolidatedMovementXYEnabled() { return RuntimeEnabledFeatures::ConsolidatedMovementXYEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableCooperativeScheduling(bool enable) { RuntimeEnabledFeatures::SetCooperativeSchedulingEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsCooperativeSchedulingEnabled() { return RuntimeEnabledFeatures::CooperativeSchedulingEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableDatabase(bool enable) { RuntimeEnabledFeatures::SetDatabaseEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDatabaseEnabled() { return RuntimeEnabledFeatures::DatabaseEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableDecodeJpeg420ImagesToYUV(bool enable) { RuntimeEnabledFeatures::SetDecodeJpeg420ImagesToYUVEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDecodeJpeg420ImagesToYUVEnabled() { return RuntimeEnabledFeatures::DecodeJpeg420ImagesToYUVEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableDecodeLossyWebPImagesToYUV(bool enable) { RuntimeEnabledFeatures::SetDecodeLossyWebPImagesToYUVEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDecodeLossyWebPImagesToYUVEnabled() { return RuntimeEnabledFeatures::DecodeLossyWebPImagesToYUVEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableDevicePosture(bool enable) { RuntimeEnabledFeatures::SetDevicePostureEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDevicePostureEnabled() { return RuntimeEnabledFeatures::DevicePostureEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableDigitalGoods(bool enable) { RuntimeEnabledFeatures::SetDigitalGoodsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDigitalGoodsEnabled() { return RuntimeEnabledFeatures::DigitalGoodsEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableDirectSockets(bool enable) { RuntimeEnabledFeatures::SetDirectSocketsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDirectSocketsEnabled() { return RuntimeEnabledFeatures::DirectSocketsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableDisplayCutoutAPI(bool enable) { RuntimeEnabledFeatures::SetDisplayCutoutAPIEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDisplayCutoutAPIEnabled() { return RuntimeEnabledFeatures::DisplayCutoutAPIEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableDocumentPictureInPictureAPI(bool enable) { RuntimeEnabledFeatures::SetDocumentPictureInPictureAPIEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDocumentPictureInPictureAPIEnabled() { return RuntimeEnabledFeatures::DocumentPictureInPictureAPIEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableDocumentPolicy(bool enable) { RuntimeEnabledFeatures::SetDocumentPolicyEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDocumentPolicyEnabled() { return RuntimeEnabledFeatures::DocumentPolicyEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableDocumentPolicyNegotiation(bool enable) { RuntimeEnabledFeatures::SetDocumentPolicyNegotiationEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsDocumentPolicyNegotiationEnabled() { return RuntimeEnabledFeatures::DocumentPolicyNegotiationEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableEventPath(bool enable) { RuntimeEnabledFeatures::SetEventPathEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsEventPathEnabled() { return RuntimeEnabledFeatures::EventPathEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableFedCm(bool enable) { RuntimeEnabledFeatures::SetFedCmEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsFedCmEnabled() { return RuntimeEnabledFeatures::FedCmEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableFedCmIdpSigninStatus(bool enable) { RuntimeEnabledFeatures::SetFedCmIdpSigninStatusEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsFedCmIdpSigninStatusEnabled() { return RuntimeEnabledFeatures::FedCmIdpSigninStatusEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableFedCmIdpSignout(bool enable) { RuntimeEnabledFeatures::SetFedCmIdpSignoutEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsFedCmIdpSignoutEnabled() { return RuntimeEnabledFeatures::FedCmIdpSignoutEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableFedCmIframeSupport(bool enable) { RuntimeEnabledFeatures::SetFedCmIframeSupportEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsFedCmIframeSupportEnabled() { return RuntimeEnabledFeatures::FedCmIframeSupportEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableFedCmMultipleIdentityProviders(bool enable) { RuntimeEnabledFeatures::SetFedCmMultipleIdentityProvidersEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsFedCmMultipleIdentityProvidersEnabled() { return RuntimeEnabledFeatures::FedCmMultipleIdentityProvidersEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableFencedFrames(bool enable) { RuntimeEnabledFeatures::SetFencedFramesEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsFencedFramesEnabled() { return RuntimeEnabledFeatures::FencedFramesEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableFileSystem(bool enable) { RuntimeEnabledFeatures::SetFileSystemEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsFileSystemEnabled() { return RuntimeEnabledFeatures::FileSystemEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableFileSystemSyncAccessHandleAsyncInterfaceOverride(bool enable)
{
    RuntimeEnabledFeatures::SetFileSystemSyncAccessHandleAsyncInterfaceOverrideEnabled(enable);
}

// static
bool WebRuntimeFeaturesBase::IsFileSystemSyncAccessHandleAsyncInterfaceOverrideEnabled()
{
    return RuntimeEnabledFeatures::FileSystemSyncAccessHandleAsyncInterfaceOverrideEnabled();
}

// static
void WebRuntimeFeaturesBase::EnableForcedColors(bool enable) { RuntimeEnabledFeatures::SetForcedColorsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsForcedColorsEnabled() { return RuntimeEnabledFeatures::ForcedColorsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableFractionalScrollOffsets(bool enable) { RuntimeEnabledFeatures::SetFractionalScrollOffsetsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsFractionalScrollOffsetsEnabled() { return RuntimeEnabledFeatures::FractionalScrollOffsetsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableGetDisplayMedia(bool enable) { RuntimeEnabledFeatures::SetGetDisplayMediaEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsGetDisplayMediaEnabled() { return RuntimeEnabledFeatures::GetDisplayMediaEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableGetDisplayMediaSet(bool enable) { RuntimeEnabledFeatures::SetGetDisplayMediaSetEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsGetDisplayMediaSetEnabled() { return RuntimeEnabledFeatures::GetDisplayMediaSetEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableGetDisplayMediaSetAutoSelectAllScreens(bool enable) { RuntimeEnabledFeatures::SetGetDisplayMediaSetAutoSelectAllScreensEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsGetDisplayMediaSetAutoSelectAllScreensEnabled() { return RuntimeEnabledFeatures::GetDisplayMediaSetAutoSelectAllScreensEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableIdleDetection(bool enable) { RuntimeEnabledFeatures::SetIdleDetectionEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsIdleDetectionEnabled() { return RuntimeEnabledFeatures::IdleDetectionEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableImplicitRootScroller(bool enable) { RuntimeEnabledFeatures::SetImplicitRootScrollerEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsImplicitRootScrollerEnabled() { return RuntimeEnabledFeatures::ImplicitRootScrollerEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableInstalledApp(bool enable) { RuntimeEnabledFeatures::SetInstalledAppEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsInstalledAppEnabled() { return RuntimeEnabledFeatures::InstalledAppEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableLazyFrameLoading(bool enable) { RuntimeEnabledFeatures::SetLazyFrameLoadingEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsLazyFrameLoadingEnabled() { return RuntimeEnabledFeatures::LazyFrameLoadingEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableLazyFrameVisibleLoadTimeMetrics(bool enable) { RuntimeEnabledFeatures::SetLazyFrameVisibleLoadTimeMetricsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsLazyFrameVisibleLoadTimeMetricsEnabled() { return RuntimeEnabledFeatures::LazyFrameVisibleLoadTimeMetricsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableLazyImageLoading(bool enable) { RuntimeEnabledFeatures::SetLazyImageLoadingEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsLazyImageLoadingEnabled() { return RuntimeEnabledFeatures::LazyImageLoadingEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableLazyImageVisibleLoadTimeMetrics(bool enable) { RuntimeEnabledFeatures::SetLazyImageVisibleLoadTimeMetricsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsLazyImageVisibleLoadTimeMetricsEnabled() { return RuntimeEnabledFeatures::LazyImageVisibleLoadTimeMetricsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableLazyInitializeMediaControls(bool enable) { RuntimeEnabledFeatures::SetLazyInitializeMediaControlsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsLazyInitializeMediaControlsEnabled() { return RuntimeEnabledFeatures::LazyInitializeMediaControlsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableMediaCastOverlayButton(bool enable) { RuntimeEnabledFeatures::SetMediaCastOverlayButtonEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsMediaCastOverlayButtonEnabled() { return RuntimeEnabledFeatures::MediaCastOverlayButtonEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableMediaControlsExpandGesture(bool enable) { RuntimeEnabledFeatures::SetMediaControlsExpandGestureEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsMediaControlsExpandGestureEnabled() { return RuntimeEnabledFeatures::MediaControlsExpandGestureEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableMediaControlsOverlayPlayButton(bool enable) { RuntimeEnabledFeatures::SetMediaControlsOverlayPlayButtonEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsMediaControlsOverlayPlayButtonEnabled() { return RuntimeEnabledFeatures::MediaControlsOverlayPlayButtonEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableMediaEngagementBypassAutoplayPolicies(bool enable) { RuntimeEnabledFeatures::SetMediaEngagementBypassAutoplayPoliciesEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsMediaEngagementBypassAutoplayPoliciesEnabled() { return RuntimeEnabledFeatures::MediaEngagementBypassAutoplayPoliciesEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableMediaSession(bool enable) { RuntimeEnabledFeatures::SetMediaSessionEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsMediaSessionEnabled() { return RuntimeEnabledFeatures::MediaSessionEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableMediaSessionWebRTC(bool enable) { RuntimeEnabledFeatures::SetMediaSessionWebRTCEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsMediaSessionWebRTCEnabled() { return RuntimeEnabledFeatures::MediaSessionWebRTCEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableMouseSubframeNoImplicitCapture(bool enable) { RuntimeEnabledFeatures::SetMouseSubframeNoImplicitCaptureEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsMouseSubframeNoImplicitCaptureEnabled() { return RuntimeEnabledFeatures::MouseSubframeNoImplicitCaptureEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableNetInfoDownlinkMax(bool enable) { RuntimeEnabledFeatures::SetNetInfoDownlinkMaxEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsNetInfoDownlinkMaxEnabled() { return RuntimeEnabledFeatures::NetInfoDownlinkMaxEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableNeverSlowMode(bool enable) { RuntimeEnabledFeatures::SetNeverSlowModeEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsNeverSlowModeEnabled() { return RuntimeEnabledFeatures::NeverSlowModeEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableNotificationContentImage(bool enable) { RuntimeEnabledFeatures::SetNotificationContentImageEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsNotificationContentImageEnabled() { return RuntimeEnabledFeatures::NotificationContentImageEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableNotifications(bool enable) { RuntimeEnabledFeatures::SetNotificationsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsNotificationsEnabled() { return RuntimeEnabledFeatures::NotificationsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePaymentApp(bool enable) { RuntimeEnabledFeatures::SetPaymentAppEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPaymentAppEnabled() { return RuntimeEnabledFeatures::PaymentAppEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePaymentRequest(bool enable) { RuntimeEnabledFeatures::SetPaymentRequestEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPaymentRequestEnabled() { return RuntimeEnabledFeatures::PaymentRequestEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePendingBeaconAPI(bool enable) { RuntimeEnabledFeatures::SetPendingBeaconAPIEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPendingBeaconAPIEnabled() { return RuntimeEnabledFeatures::PendingBeaconAPIEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnablePercentBasedScrolling(bool enable) { RuntimeEnabledFeatures::SetPercentBasedScrollingEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPercentBasedScrollingEnabled() { return RuntimeEnabledFeatures::PercentBasedScrollingEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePerformanceManagerInstrumentation(bool enable) { RuntimeEnabledFeatures::SetPerformanceManagerInstrumentationEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPerformanceManagerInstrumentationEnabled() { return RuntimeEnabledFeatures::PerformanceManagerInstrumentationEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePeriodicBackgroundSync(bool enable) { RuntimeEnabledFeatures::SetPeriodicBackgroundSyncEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPeriodicBackgroundSyncEnabled() { return RuntimeEnabledFeatures::PeriodicBackgroundSyncEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePermissions(bool enable) { RuntimeEnabledFeatures::SetPermissionsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPermissionsEnabled() { return RuntimeEnabledFeatures::PermissionsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePictureInPicture(bool enable) { RuntimeEnabledFeatures::SetPictureInPictureEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPictureInPictureEnabled() { return RuntimeEnabledFeatures::PictureInPictureEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePictureInPictureAPI(bool enable) { RuntimeEnabledFeatures::SetPictureInPictureAPIEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPictureInPictureAPIEnabled() { return RuntimeEnabledFeatures::PictureInPictureAPIEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePointerLockOptions(bool enable) { RuntimeEnabledFeatures::SetPointerLockOptionsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPointerLockOptionsEnabled() { return RuntimeEnabledFeatures::PointerLockOptionsEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnablePortals(bool enable) { RuntimeEnabledFeatures::SetPortalsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPortalsEnabled() { return RuntimeEnabledFeatures::PortalsEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnablePreciseMemoryInfo(bool enable) { RuntimeEnabledFeatures::SetPreciseMemoryInfoEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPreciseMemoryInfoEnabled() { return RuntimeEnabledFeatures::PreciseMemoryInfoEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePrefixedStorageInfo(bool enable) { RuntimeEnabledFeatures::SetPrefixedStorageInfoEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPrefixedStorageInfoEnabled() { return RuntimeEnabledFeatures::PrefixedStorageInfoEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePrerender2RelatedFeatures(bool enable) { RuntimeEnabledFeatures::SetPrerender2RelatedFeaturesEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPrerender2RelatedFeaturesEnabled() { return RuntimeEnabledFeatures::Prerender2RelatedFeaturesEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnablePresentation(bool enable) { RuntimeEnabledFeatures::SetPresentationEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPresentationEnabled() { return RuntimeEnabledFeatures::PresentationEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePushMessaging(bool enable) { RuntimeEnabledFeatures::SetPushMessagingEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPushMessagingEnabled() { return RuntimeEnabledFeatures::PushMessagingEnabled(); }

// static
void WebRuntimeFeaturesBase::EnablePushMessagingSubscriptionChange(bool enable) { RuntimeEnabledFeatures::SetPushMessagingSubscriptionChangeEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsPushMessagingSubscriptionChangeEnabled() { return RuntimeEnabledFeatures::PushMessagingSubscriptionChangeEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableRemotePlayback(bool enable) { RuntimeEnabledFeatures::SetRemotePlaybackEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsRemotePlaybackEnabled() { return RuntimeEnabledFeatures::RemotePlaybackEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableRemoveMobileViewportDoubleTap(bool enable) { RuntimeEnabledFeatures::SetRemoveMobileViewportDoubleTapEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsRemoveMobileViewportDoubleTapEnabled() { return RuntimeEnabledFeatures::RemoveMobileViewportDoubleTapEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableRestrictGamepadAccess(bool enable) { RuntimeEnabledFeatures::SetRestrictGamepadAccessEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsRestrictGamepadAccessEnabled() { return RuntimeEnabledFeatures::RestrictGamepadAccessEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableScriptedSpeechRecognition(bool enable) { RuntimeEnabledFeatures::SetScriptedSpeechRecognitionEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsScriptedSpeechRecognitionEnabled() { return RuntimeEnabledFeatures::ScriptedSpeechRecognitionEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableScriptedSpeechSynthesis(bool enable) { RuntimeEnabledFeatures::SetScriptedSpeechSynthesisEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsScriptedSpeechSynthesisEnabled() { return RuntimeEnabledFeatures::ScriptedSpeechSynthesisEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableSecurePaymentConfirmation(bool enable) { RuntimeEnabledFeatures::SetSecurePaymentConfirmationEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSecurePaymentConfirmationEnabled() { return RuntimeEnabledFeatures::SecurePaymentConfirmationEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableSecurePaymentConfirmationDebug(bool enable) { RuntimeEnabledFeatures::SetSecurePaymentConfirmationDebugEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSecurePaymentConfirmationDebugEnabled() { return RuntimeEnabledFeatures::SecurePaymentConfirmationDebugEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableSendBeaconThrowForBlobWithNonSimpleType(bool enable) { RuntimeEnabledFeatures::SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSendBeaconThrowForBlobWithNonSimpleTypeEnabled() { return RuntimeEnabledFeatures::SendBeaconThrowForBlobWithNonSimpleTypeEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableSensorExtraClasses(bool enable) { RuntimeEnabledFeatures::SetSensorExtraClassesEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSensorExtraClassesEnabled() { return RuntimeEnabledFeatures::SensorExtraClassesEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableSharedArrayBuffer(bool enable) { RuntimeEnabledFeatures::SetSharedArrayBufferEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSharedArrayBufferEnabled() { return RuntimeEnabledFeatures::SharedArrayBufferEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableSharedArrayBufferOnDesktop(bool enable) { RuntimeEnabledFeatures::SetSharedArrayBufferOnDesktopEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSharedArrayBufferOnDesktopEnabled() { return RuntimeEnabledFeatures::SharedArrayBufferOnDesktopEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableSharedArrayBufferUnrestrictedAccessAllowed(bool enable) { RuntimeEnabledFeatures::SetSharedArrayBufferUnrestrictedAccessAllowedEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSharedArrayBufferUnrestrictedAccessAllowedEnabled() { return RuntimeEnabledFeatures::SharedArrayBufferUnrestrictedAccessAllowedEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableSharedAutofill(bool enable) { RuntimeEnabledFeatures::SetSharedAutofillEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSharedAutofillEnabled() { return RuntimeEnabledFeatures::SharedAutofillEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableSharedStorageAPI(bool enable) { RuntimeEnabledFeatures::SetSharedStorageAPIEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSharedStorageAPIEnabled() { return RuntimeEnabledFeatures::SharedStorageAPIEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableSharedWorker(bool enable) { RuntimeEnabledFeatures::SetSharedWorkerEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsSharedWorkerEnabled() { return RuntimeEnabledFeatures::SharedWorkerEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableStorageAccessAPIForOriginExtension(bool enable) { RuntimeEnabledFeatures::SetStorageAccessAPIForOriginExtensionEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsStorageAccessAPIForOriginExtensionEnabled() { return RuntimeEnabledFeatures::StorageAccessAPIForOriginExtensionEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableTextFragmentIdentifiers(bool enable) { RuntimeEnabledFeatures::SetTextFragmentIdentifiersEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsTextFragmentIdentifiersEnabled() { return RuntimeEnabledFeatures::TextFragmentIdentifiersEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableTimerThrottlingForBackgroundTabs(bool enable) { RuntimeEnabledFeatures::SetTimerThrottlingForBackgroundTabsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsTimerThrottlingForBackgroundTabsEnabled() { return RuntimeEnabledFeatures::TimerThrottlingForBackgroundTabsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableTopicsAPI(bool enable) { RuntimeEnabledFeatures::SetTopicsAPIEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsTopicsAPIEnabled() { return RuntimeEnabledFeatures::TopicsAPIEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableTouchDragAndContextMenu(bool enable) { RuntimeEnabledFeatures::SetTouchDragAndContextMenuEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsTouchDragAndContextMenuEnabled() { return RuntimeEnabledFeatures::TouchDragAndContextMenuEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableTouchEventFeatureDetection(bool enable) { RuntimeEnabledFeatures::SetTouchEventFeatureDetectionEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsTouchEventFeatureDetectionEnabled() { return RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableTrustTokens(bool enable) { RuntimeEnabledFeatures::SetTrustTokensEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsTrustTokensEnabled() { return RuntimeEnabledFeatures::TrustTokensEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableTrustTokensAlwaysAllowIssuance(bool enable) { RuntimeEnabledFeatures::SetTrustTokensAlwaysAllowIssuanceEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsTrustTokensAlwaysAllowIssuanceEnabled() { return RuntimeEnabledFeatures::TrustTokensAlwaysAllowIssuanceEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableUserActivationSameOriginVisibility(bool enable) { RuntimeEnabledFeatures::SetUserActivationSameOriginVisibilityEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsUserActivationSameOriginVisibilityEnabled() { return RuntimeEnabledFeatures::UserActivationSameOriginVisibilityEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableV8IdleTasks(bool enable) { RuntimeEnabledFeatures::SetV8IdleTasksEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsV8IdleTasksEnabled() { return RuntimeEnabledFeatures::V8IdleTasksEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableVideoPlaybackQuality(bool enable) { RuntimeEnabledFeatures::SetVideoPlaybackQualityEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsVideoPlaybackQualityEnabled() { return RuntimeEnabledFeatures::VideoPlaybackQualityEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableVideoWakeLockOptimisationHiddenMuted(bool enable) { RuntimeEnabledFeatures::SetVideoWakeLockOptimisationHiddenMutedEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsVideoWakeLockOptimisationHiddenMutedEnabled() { return RuntimeEnabledFeatures::VideoWakeLockOptimisationHiddenMutedEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebAuthenticationRemoteDesktopSupport(bool enable) { RuntimeEnabledFeatures::SetWebAuthenticationRemoteDesktopSupportEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebAuthenticationRemoteDesktopSupportEnabled() { return RuntimeEnabledFeatures::WebAuthenticationRemoteDesktopSupportEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebBluetooth(bool enable) { RuntimeEnabledFeatures::SetWebBluetoothEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebBluetoothEnabled() { return RuntimeEnabledFeatures::WebBluetoothEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebBluetoothGetDevices(bool enable) { RuntimeEnabledFeatures::SetWebBluetoothGetDevicesEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebBluetoothGetDevicesEnabled() { return RuntimeEnabledFeatures::WebBluetoothGetDevicesEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebBluetoothWatchAdvertisements(bool enable) { RuntimeEnabledFeatures::SetWebBluetoothWatchAdvertisementsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebBluetoothWatchAdvertisementsEnabled() { return RuntimeEnabledFeatures::WebBluetoothWatchAdvertisementsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebGLDeveloperExtensions(bool enable) { RuntimeEnabledFeatures::SetWebGLDeveloperExtensionsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebGLDeveloperExtensionsEnabled() { return RuntimeEnabledFeatures::WebGLDeveloperExtensionsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebGLDraftExtensions(bool enable) { RuntimeEnabledFeatures::SetWebGLDraftExtensionsEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebGLDraftExtensionsEnabled() { return RuntimeEnabledFeatures::WebGLDraftExtensionsEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebGLImageChromium(bool enable) { RuntimeEnabledFeatures::SetWebGLImageChromiumEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebGLImageChromiumEnabled() { return RuntimeEnabledFeatures::WebGLImageChromiumEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebGPU(bool enable) { RuntimeEnabledFeatures::SetWebGPUEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebGPUEnabled() { return RuntimeEnabledFeatures::WebGPUEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableWebGPUDeveloperFeatures(bool enable) { RuntimeEnabledFeatures::SetWebGPUDeveloperFeaturesEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebGPUDeveloperFeaturesEnabled() { return RuntimeEnabledFeatures::WebGPUDeveloperFeaturesEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebHIDOnServiceWorkers(bool enable) { RuntimeEnabledFeatures::SetWebHIDOnServiceWorkersEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebHIDOnServiceWorkersEnabled() { return RuntimeEnabledFeatures::WebHIDOnServiceWorkersEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebNFC(bool enable) { RuntimeEnabledFeatures::SetWebNFCEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebNFCEnabled() { return RuntimeEnabledFeatures::WebNFCEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebOTP(bool enable) { RuntimeEnabledFeatures::SetWebOTPEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebOTPEnabled() { return RuntimeEnabledFeatures::WebOTPEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebOTPAssertionFeaturePolicy(bool enable) { RuntimeEnabledFeatures::SetWebOTPAssertionFeaturePolicyEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebOTPAssertionFeaturePolicyEnabled() { return RuntimeEnabledFeatures::WebOTPAssertionFeaturePolicyEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebPaymentAPICSP(bool enable) { RuntimeEnabledFeatures::SetWebPaymentAPICSPEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebPaymentAPICSPEnabled() { return RuntimeEnabledFeatures::WebPaymentAPICSPEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableWebShare(bool enable) { RuntimeEnabledFeatures::SetWebShareEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebShareEnabled() { return RuntimeEnabledFeatures::WebShareEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebUSB(bool enable) { RuntimeEnabledFeatures::SetWebUSBEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebUSBEnabled() { return RuntimeEnabledFeatures::WebUSBEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebUSBOnServiceWorkers(bool enable) { RuntimeEnabledFeatures::SetWebUSBOnServiceWorkersEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebUSBOnServiceWorkersEnabled() { return RuntimeEnabledFeatures::WebUSBOnServiceWorkersEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebXR(bool enable) { RuntimeEnabledFeatures::SetWebXREnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXREnabled() { return RuntimeEnabledFeatures::WebXREnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebXRARModule(bool enable) { RuntimeEnabledFeatures::SetWebXRARModuleEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXRARModuleEnabled() { return RuntimeEnabledFeatures::WebXRARModuleEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebXRCameraAccess(bool enable) { RuntimeEnabledFeatures::SetWebXRCameraAccessEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXRCameraAccessEnabled() { return RuntimeEnabledFeatures::WebXRCameraAccessEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebXRDepth(bool enable) { RuntimeEnabledFeatures::SetWebXRDepthEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXRDepthEnabled() { return RuntimeEnabledFeatures::WebXRDepthEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableWebXRHandInput(bool enable) { RuntimeEnabledFeatures::SetWebXRHandInputEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXRHandInputEnabled() { return RuntimeEnabledFeatures::WebXRHandInputEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebXRHitTest(bool enable) { RuntimeEnabledFeatures::SetWebXRHitTestEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXRHitTestEnabled() { return RuntimeEnabledFeatures::WebXRHitTestEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebXRImageTracking(bool enable) { RuntimeEnabledFeatures::SetWebXRImageTrackingEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXRImageTrackingEnabled() { return RuntimeEnabledFeatures::WebXRImageTrackingEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableWebXRLightEstimation(bool enable) { RuntimeEnabledFeatures::SetWebXRLightEstimationEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXRLightEstimationEnabled() { return RuntimeEnabledFeatures::WebXRLightEstimationEnabled(); }

// static
void WebRuntimeFeaturesBase::EnableWebXRPlaneDetection(bool enable) { RuntimeEnabledFeatures::SetWebXRPlaneDetectionEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXRPlaneDetectionEnabled() { return RuntimeEnabledFeatures::WebXRPlaneDetectionEnabledByRuntimeFlag(); }

// static
void WebRuntimeFeaturesBase::EnableWebXRViewportScale(bool enable) { RuntimeEnabledFeatures::SetWebXRViewportScaleEnabled(enable); }

// static
bool WebRuntimeFeaturesBase::IsWebXRViewportScaleEnabled() { return RuntimeEnabledFeatures::WebXRViewportScaleEnabled(); }

} // namespace blink
