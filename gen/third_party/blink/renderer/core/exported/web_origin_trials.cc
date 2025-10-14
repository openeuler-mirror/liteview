// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/web_origin_trials.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/public/web/web_origin_trials.h"

#include "third_party/blink/renderer/core/dom/document.h"
#include "third_party/blink/renderer/core/execution_context/execution_context.h"
#include "third_party/blink/public/common/origin_trials/origin_trial_feature.h"
#include "third_party/blink/public/common/origin_trials/origin_trials.h"
#include "third_party/blink/public/platform/web_string.h"
#include "third_party/blink/public/web/web_document.h"

namespace blink {

bool WebOriginTrials::isTrialEnabled(const WebDocument* web_document, const WebString& trial)
{
    if (!web_document)
        return false;
    if (!origin_trials::IsTrialValid(trial.Utf8()))
        return false;
    Document* document = *web_document;
    for (OriginTrialFeature feature : origin_trials::FeaturesForTrial(trial.Utf8())) {
        switch (feature) {
        case OriginTrialFeature::kAccessibilityAriaTouchPassthrough:
            if (!RuntimeEnabledFeatures::AccessibilityAriaTouchPassthroughEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kAdInterestGroupAPI:
            if (!RuntimeEnabledFeatures::AdInterestGroupAPIEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kAnonymousIframe:
            if (!RuntimeEnabledFeatures::AnonymousIframeEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kAttributionReporting:
            if (!RuntimeEnabledFeatures::AttributionReportingEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kAutoDarkMode:
            if (!RuntimeEnabledFeatures::AutoDarkModeEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kBackForwardCacheExperimentHTTPHeader:
            if (!RuntimeEnabledFeatures::BackForwardCacheExperimentHTTPHeaderEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kBackForwardCacheNotRestoredReasons:
            if (!RuntimeEnabledFeatures::BackForwardCacheNotRestoredReasonsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kBeforeMatchEvent:
            if (!RuntimeEnabledFeatures::BeforeMatchEventEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kCacheStorageCodeCacheHint:
            if (!RuntimeEnabledFeatures::CacheStorageCodeCacheHintEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kClearIdentityInCanMakePaymentEvent:
            if (!RuntimeEnabledFeatures::ClearIdentityInCanMakePaymentEventEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kComputePressure:
            if (!RuntimeEnabledFeatures::ComputePressureEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kConditionalFocus:
            if (!RuntimeEnabledFeatures::ConditionalFocusEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kCrossOriginOpenerPolicyReporting:
            if (!RuntimeEnabledFeatures::CrossOriginOpenerPolicyReportingEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kDeviceAttributes:
            if (!RuntimeEnabledFeatures::DeviceAttributesEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kDigitalGoods:
            if (!RuntimeEnabledFeatures::DigitalGoodsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kDisableDifferentOriginSubframeDialogSuppression:
            if (!RuntimeEnabledFeatures::DisableDifferentOriginSubframeDialogSuppressionEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kDisableHardwareNoiseSuppression:
            if (!RuntimeEnabledFeatures::DisableHardwareNoiseSuppressionEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kDocumentPolicyNegotiation:
            if (!RuntimeEnabledFeatures::DocumentPolicyNegotiationEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kEarlyHintsPreloadForNavigationOptIn:
            if (!RuntimeEnabledFeatures::EarlyHintsPreloadForNavigationOptInEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kFencedFrames:
            if (!RuntimeEnabledFeatures::FencedFramesEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kFileHandling:
            if (!RuntimeEnabledFeatures::FileHandlingEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kFledge:
            if (!RuntimeEnabledFeatures::FledgeEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kFocusgroup:
            if (!RuntimeEnabledFeatures::FocusgroupEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kHrefTranslate:
            if (!RuntimeEnabledFeatures::HrefTranslateEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kHTMLPopupAttribute:
            if (!RuntimeEnabledFeatures::HTMLPopupAttributeEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kMediaSourceExtensionsForWebCodecs:
            if (!RuntimeEnabledFeatures::MediaSourceExtensionsForWebCodecsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kMediaSourceInWorkers:
            if (!RuntimeEnabledFeatures::MediaSourceInWorkersEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kNotificationTriggers:
            if (!RuntimeEnabledFeatures::NotificationTriggersEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPI:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIDeprecationEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriod:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIExpiryGracePeriodEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriodThirdParty:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPIImplied:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIImpliedEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIInvalidOSEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPINavigation:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPINavigationEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPIPersistentExpiryGracePeriod:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPIPersistentFeature:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIPersistentFeatureEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kOriginTrialsSampleAPIThirdParty:
            if (!RuntimeEnabledFeatures::OriginTrialsSampleAPIThirdPartyEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPageFreezeOptIn:
            if (!RuntimeEnabledFeatures::PageFreezeOptInEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPageFreezeOptOut:
            if (!RuntimeEnabledFeatures::PageFreezeOptOutEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kParakeet:
            if (!RuntimeEnabledFeatures::ParakeetEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPartitionedCookies:
            if (!RuntimeEnabledFeatures::PartitionedCookiesEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPendingBeaconAPI:
            if (!RuntimeEnabledFeatures::PendingBeaconAPIEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPerMethodCanMakePaymentQuota:
            if (!RuntimeEnabledFeatures::PerMethodCanMakePaymentQuotaEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPermissionsPolicyUnload:
            if (!RuntimeEnabledFeatures::PermissionsPolicyUnloadEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPNaCl:
            if (!RuntimeEnabledFeatures::PNaClEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPointerLockOptions:
            if (!RuntimeEnabledFeatures::PointerLockOptionsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPortals:
            if (!RuntimeEnabledFeatures::PortalsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPrerender2RelatedFeatures:
            if (!RuntimeEnabledFeatures::Prerender2RelatedFeaturesEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPrivacySandboxAdsAPIs:
            if (!RuntimeEnabledFeatures::PrivacySandboxAdsAPIsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kPrivateNetworkAccessNonSecureContextsAllowed:
            if (!RuntimeEnabledFeatures::PrivateNetworkAccessNonSecureContextsAllowedEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kRtcAudioJitterBufferMaxPackets:
            if (!RuntimeEnabledFeatures::RtcAudioJitterBufferMaxPacketsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kRTCIceTransportExtension:
            if (!RuntimeEnabledFeatures::RTCIceTransportExtensionEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kRTCInsertableStreams:
            if (!RuntimeEnabledFeatures::RTCInsertableStreamsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kRTCQuicTransport:
            if (!RuntimeEnabledFeatures::RTCQuicTransportEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay:
            if (!RuntimeEnabledFeatures::RTCStatsRelativePacketArrivalDelayEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kSecurePaymentConfirmationOptOut:
            if (!RuntimeEnabledFeatures::SecurePaymentConfirmationOptOutEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kSendFullUserAgentAfterReduction:
            if (!RuntimeEnabledFeatures::SendFullUserAgentAfterReductionEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kSharedStorageAPI:
            if (!RuntimeEnabledFeatures::SharedStorageAPIEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kSignatureBasedIntegrity:
            if (!RuntimeEnabledFeatures::SignatureBasedIntegrityEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kSkipAd:
            if (!RuntimeEnabledFeatures::SkipAdEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kSpeculationRules:
            if (!RuntimeEnabledFeatures::SpeculationRulesEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kSpeculationRulesPrefetchProxy:
            if (!RuntimeEnabledFeatures::SpeculationRulesPrefetchProxyEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kStorageFoundationAPI:
            if (!RuntimeEnabledFeatures::StorageFoundationAPIEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kTextFragmentIdentifiers:
            if (!RuntimeEnabledFeatures::TextFragmentIdentifiersEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kTopicsAPI:
            if (!RuntimeEnabledFeatures::TopicsAPIEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kTouchEventFeatureDetection:
            if (!RuntimeEnabledFeatures::TouchEventFeatureDetectionEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kTrustTokens:
            if (!RuntimeEnabledFeatures::TrustTokensEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kU2FSecurityKeyAPI:
            if (!RuntimeEnabledFeatures::U2FSecurityKeyAPIEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kUnrestrictedSharedArrayBuffer:
            if (!RuntimeEnabledFeatures::UnrestrictedSharedArrayBufferEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kUserAgentReduction:
            if (!RuntimeEnabledFeatures::UserAgentReductionEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebAppDarkMode:
            if (!RuntimeEnabledFeatures::WebAppDarkModeEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebAppLaunchHandler:
            if (!RuntimeEnabledFeatures::WebAppLaunchHandlerEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebAppLaunchQueue:
            if (!RuntimeEnabledFeatures::WebAppLaunchQueueEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebAppUrlHandling:
            if (!RuntimeEnabledFeatures::WebAppUrlHandlingEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebAppWindowControlsOverlay:
            if (!RuntimeEnabledFeatures::WebAppWindowControlsOverlayEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebAssemblyExceptions:
            if (!RuntimeEnabledFeatures::WebAssemblyExceptionsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebCodecs:
            if (!RuntimeEnabledFeatures::WebCodecsEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebGPU:
            if (!RuntimeEnabledFeatures::WebGPUEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebPaymentAPICSP:
            if (!RuntimeEnabledFeatures::WebPaymentAPICSPEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebTransportCustomCertificates:
            if (!RuntimeEnabledFeatures::WebTransportCustomCertificatesEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebXRDepth:
            if (!RuntimeEnabledFeatures::WebXRDepthEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebXRImageTracking:
            if (!RuntimeEnabledFeatures::WebXRImageTrackingEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        case OriginTrialFeature::kWebXRPlaneDetection:
            if (!RuntimeEnabledFeatures::WebXRPlaneDetectionEnabled(document->GetExecutionContext())) {
                return false;
            }
            break;
        default:
            break;
        }
    }
    return true;
}

} // namespace blink
