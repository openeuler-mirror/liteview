// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/origin_trials.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5
#include "third_party/blink/public/common/origin_trials/origin_trials.h"

#include <array>
#include <iterator>

#include "base/containers/contains.h"
#include "base/ranges/algorithm.h"
#include "build/build_config.h"
#include "build/buildflag.h"
#include "build/chromeos_buildflags.h"
#include "third_party/blink/public/common/origin_trials/origin_trial_feature.h"

// For testing. See OriginTrialsSampleAPIInvalidOS.
#define BUILDFLAG_INTERNAL_IS_INVALID() (0)

namespace blink {

namespace {

static constexpr size_t kMaxFeaturesPerTrial = 6;
static constexpr struct TrialToFeature {
    const char* trial_name;
    unsigned feature_count;
    std::array<OriginTrialFeature, kMaxFeaturesPerTrial> features;
} kTrialToFeaturesMap[] = {
    { "AccessibilityAriaTouchPassthrough", 1,
        {
            OriginTrialFeature::kAccessibilityAriaTouchPassthrough,
        } },
    { "AdInterestGroupAPI", 1,
        {
            OriginTrialFeature::kAdInterestGroupAPI,
        } },
    { "AnonymousIframeOriginTrial", 1,
        {
            OriginTrialFeature::kAnonymousIframe,
        } },
    { "PrivacySandboxAdsAPIs", 6,
        {
            OriginTrialFeature::kAttributionReporting,
            OriginTrialFeature::kFencedFrames,
            OriginTrialFeature::kFledge,
            OriginTrialFeature::kPrivacySandboxAdsAPIs,
            OriginTrialFeature::kSharedStorageAPI,
            OriginTrialFeature::kTopicsAPI,
        } },
    { "AutoDarkMode", 1,
        {
            OriginTrialFeature::kAutoDarkMode,
        } },
    { "BackForwardCacheExperimentHTTPHeader", 1,
        {
            OriginTrialFeature::kBackForwardCacheExperimentHTTPHeader,
        } },
    { "BackForwardCacheNotRestoredReasons", 1,
        {
            OriginTrialFeature::kBackForwardCacheNotRestoredReasons,
        } },
    { "BeforeMatchEvent", 1,
        {
            OriginTrialFeature::kBeforeMatchEvent,
        } },
    { "CacheStorageCodeCacheHint", 1,
        {
            OriginTrialFeature::kCacheStorageCodeCacheHint,
        } },
    { "IdentityInCanMakePaymentEventFeature", 1,
        {
            OriginTrialFeature::kClearIdentityInCanMakePaymentEvent,
        } },
    { "ComputePressure", 1,
        {
            OriginTrialFeature::kComputePressure,
        } },
    { "ConditionalFocus", 1,
        {
            OriginTrialFeature::kConditionalFocus,
        } },
    { "CrossOriginOpenerPolicyReporting", 1,
        {
            OriginTrialFeature::kCrossOriginOpenerPolicyReporting,
        } },
    { "DeviceAttributes", 1,
        {
            OriginTrialFeature::kDeviceAttributes,
        } },
    { "DigitalGoodsV2", 1,
        {
            OriginTrialFeature::kDigitalGoods,
        } },
    { "DisableDifferentOriginSubframeDialogSuppression", 1,
        {
            OriginTrialFeature::kDisableDifferentOriginSubframeDialogSuppression,
        } },
    { "DisableHardwareNoiseSuppression", 1,
        {
            OriginTrialFeature::kDisableHardwareNoiseSuppression,
        } },
    { "DocumentPolicyNegotiation", 1,
        {
            OriginTrialFeature::kDocumentPolicyNegotiation,
        } },
    { "EarlyHintsPreloadForNavigation", 1,
        {
            OriginTrialFeature::kEarlyHintsPreloadForNavigationOptIn,
        } },
    { "FileHandling", 1,
        {
            OriginTrialFeature::kFileHandling,
        } },
    { "Focusgroup", 1,
        {
            OriginTrialFeature::kFocusgroup,
        } },
    { "HrefTranslate", 1,
        {
            OriginTrialFeature::kHrefTranslate,
        } },
    { "HTMLPopupAttribute", 1,
        {
            OriginTrialFeature::kHTMLPopupAttribute,
        } },
    { "MediaSourceExtensionsForWebCodecs", 1,
        {
            OriginTrialFeature::kMediaSourceExtensionsForWebCodecs,
        } },
    { "MediaSourceInWorkers", 1,
        {
            OriginTrialFeature::kMediaSourceInWorkers,
        } },
    { "NotificationTriggers", 1,
        {
            OriginTrialFeature::kNotificationTriggers,
        } },
    { "Frobulate", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPI,
        } },
    { "FrobulateDeprecation", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPIDeprecation,
        } },
    { "FrobulateExpiryGracePeriod", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriod,
        } },
    { "FrobulateExpiryGracePeriodThirdParty", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriodThirdParty,
        } },
    { "FrobulateImplied", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPIImplied,
        } },
    { "FrobulateInvalidOS", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS,
        } },
    { "FrobulateNavigation", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPINavigation,
        } },
    { "FrobulatePersistentExpiryGracePeriod", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPIPersistentExpiryGracePeriod,
        } },
    { "FrobulatePersistent", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPIPersistentFeature,
        } },
    { "FrobulateThirdParty", 1,
        {
            OriginTrialFeature::kOriginTrialsSampleAPIThirdParty,
        } },
    { "PageFreezeOptIn", 1,
        {
            OriginTrialFeature::kPageFreezeOptIn,
        } },
    { "PageFreezeOptOut", 1,
        {
            OriginTrialFeature::kPageFreezeOptOut,
        } },
    { "Parakeet", 1,
        {
            OriginTrialFeature::kParakeet,
        } },
    { "PartitionedCookies", 1,
        {
            OriginTrialFeature::kPartitionedCookies,
        } },
    { "PendingBeaconAPI", 1,
        {
            OriginTrialFeature::kPendingBeaconAPI,
        } },
    { "PerMethodCanMakePaymentQuota", 1,
        {
            OriginTrialFeature::kPerMethodCanMakePaymentQuota,
        } },
    { "PermissionsPolicyUnload", 1,
        {
            OriginTrialFeature::kPermissionsPolicyUnload,
        } },
    { "PNaCl", 1,
        {
            OriginTrialFeature::kPNaCl,
        } },
    { "PointerLockOptions", 1,
        {
            OriginTrialFeature::kPointerLockOptions,
        } },
    { "Portals", 1,
        {
            OriginTrialFeature::kPortals,
        } },
    { "Prerender2RelatedFeatures__DONOTUSE", 1,
        {
            OriginTrialFeature::kPrerender2RelatedFeatures,
        } },
    { "PrivateNetworkAccessNonSecureContextsAllowed", 1,
        {
            OriginTrialFeature::kPrivateNetworkAccessNonSecureContextsAllowed,
        } },
    { "RtcAudioJitterBufferMaxPackets", 1,
        {
            OriginTrialFeature::kRtcAudioJitterBufferMaxPackets,
        } },
    { "RTCQuicTransport", 2,
        {
            OriginTrialFeature::kRTCIceTransportExtension,
            OriginTrialFeature::kRTCQuicTransport,
        } },
    { "RTCInsertableStreams", 1,
        {
            OriginTrialFeature::kRTCInsertableStreams,
        } },
    { "RTCStatsRelativePacketArrivalDelay", 1,
        {
            OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay,
        } },
    { "SecurePaymentConfirmationOptOut", 1,
        {
            OriginTrialFeature::kSecurePaymentConfirmationOptOut,
        } },
    { "SendFullUserAgentAfterReduction", 1,
        {
            OriginTrialFeature::kSendFullUserAgentAfterReduction,
        } },
    { "SignatureBasedIntegrity", 1,
        {
            OriginTrialFeature::kSignatureBasedIntegrity,
        } },
    { "SkipAd", 1,
        {
            OriginTrialFeature::kSkipAd,
        } },
    { "SpeculationRules__DONOTUSE", 1,
        {
            OriginTrialFeature::kSpeculationRules,
        } },
    { "SpeculationRulesPrefetch", 1,
        {
            OriginTrialFeature::kSpeculationRulesPrefetchProxy,
        } },
    { "StorageFoundationAPI", 1,
        {
            OriginTrialFeature::kStorageFoundationAPI,
        } },
    { "TextFragmentIdentifiers", 1,
        {
            OriginTrialFeature::kTextFragmentIdentifiers,
        } },
    { "ForceTouchEventFeatureDetectionForInspector", 1,
        {
            OriginTrialFeature::kTouchEventFeatureDetection,
        } },
    { "TrustTokens", 1,
        {
            OriginTrialFeature::kTrustTokens,
        } },
    { "U2FSecurityKeyAPI", 1,
        {
            OriginTrialFeature::kU2FSecurityKeyAPI,
        } },
    { "UnrestrictedSharedArrayBuffer", 1,
        {
            OriginTrialFeature::kUnrestrictedSharedArrayBuffer,
        } },
    { "UserAgentReduction", 1,
        {
            OriginTrialFeature::kUserAgentReduction,
        } },
    { "WebAppDarkMode", 1,
        {
            OriginTrialFeature::kWebAppDarkMode,
        } },
    { "Launch Handler", 1,
        {
            OriginTrialFeature::kWebAppLaunchHandler,
        } },
    { "WebAppLaunchQueue", 1,
        {
            OriginTrialFeature::kWebAppLaunchQueue,
        } },
    { "WebAppUrlHandling", 1,
        {
            OriginTrialFeature::kWebAppUrlHandling,
        } },
    { "WebAppWindowControlsOverlay", 1,
        {
            OriginTrialFeature::kWebAppWindowControlsOverlay,
        } },
    { "WebAssemblyExceptions", 1,
        {
            OriginTrialFeature::kWebAssemblyExceptions,
        } },
    { "WebCodecs", 1,
        {
            OriginTrialFeature::kWebCodecs,
        } },
    { "WebGPU", 1,
        {
            OriginTrialFeature::kWebGPU,
        } },
    { "WebPaymentAPICSP", 1,
        {
            OriginTrialFeature::kWebPaymentAPICSP,
        } },
    { "WebTransportCustomCertificates", 1,
        {
            OriginTrialFeature::kWebTransportCustomCertificates,
        } },
    { "WebXRDepth", 1,
        {
            OriginTrialFeature::kWebXRDepth,
        } },
    { "WebXRImageTracking", 1,
        {
            OriginTrialFeature::kWebXRImageTracking,
        } },
    { "WebXRPlaneDetection", 1,
        {
            OriginTrialFeature::kWebXRPlaneDetection,
        } },
    // For testing
    { "This trial does not exist", 1, { OriginTrialFeature::kNonExisting } },
};

} // namespace

bool origin_trials::IsTrialValid(base::StringPiece trial_name) { return base::Contains(kTrialToFeaturesMap, trial_name, &TrialToFeature::trial_name); }

bool origin_trials::IsTrialEnabledForInsecureContext(base::StringPiece trial_name)
{
    static const char* const kEnabledForInsecureContext[] = {
        "DisableDifferentOriginSubframeDialogSuppression",
        "FrobulateDeprecation",
        "PrivateNetworkAccessNonSecureContextsAllowed",
    };
    return base::Contains(kEnabledForInsecureContext, trial_name);
}

bool origin_trials::IsTrialEnabledForThirdPartyOrigins(base::StringPiece trial_name)
{
    static const char* const kEnabledForThirdPartyOrigins[] = {
        "AnonymousIframeOriginTrial",
        "PrivacySandboxAdsAPIs",
        "IdentityInCanMakePaymentEventFeature",
        "CrossOriginOpenerPolicyReporting",
        "DeviceAttributes",
        "FrobulateExpiryGracePeriodThirdParty",
        "FrobulateThirdParty",
        "PartitionedCookies",
        "PendingBeaconAPI",
        "SecurePaymentConfirmationOptOut",
        "SendFullUserAgentAfterReduction",
        "TrustTokens",
        "UserAgentReduction",
        "WebPaymentAPICSP",
    };
    return base::Contains(kEnabledForThirdPartyOrigins, trial_name);
}

OriginTrialType origin_trials::GetTrialType(OriginTrialFeature feature)
{
    switch (feature) {
    case OriginTrialFeature::kClearIdentityInCanMakePaymentEvent:
        return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kDisableDifferentOriginSubframeDialogSuppression:
        return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
        return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kPrivateNetworkAccessNonSecureContextsAllowed:
        return OriginTrialType::kDeprecation;
    case OriginTrialFeature::kU2FSecurityKeyAPI:
        return OriginTrialType::kDeprecation;
    default:
        return OriginTrialType::kDefault;
    }
}
base::span<const OriginTrialFeature> origin_trials::FeaturesForTrial(base::StringPiece trial_name)
{
    // auto it = base::ranges::find(kTrialToFeaturesMap, trial_name, &TrialToFeature::trial_name);
    // DCHECK(it != std::end(kTrialToFeaturesMap));
    // return base::span<const OriginTrialFeature>(it->features.begin(), (size_t)(it->feature_count));
    *(int*)1 = 1;

    for (size_t i = 0; i < sizeof(kTrialToFeaturesMap) / sizeof(TrialToFeature); ++i) {
        if (kTrialToFeaturesMap[i].trial_name == trial_name) {
            std::array<OriginTrialFeature, kMaxFeaturesPerTrial>::const_iterator it = kTrialToFeaturesMap[i].features.begin();
            return base::span<const OriginTrialFeature>(&(*it), (kTrialToFeaturesMap[i].feature_count));
        }
    }
    DCHECK(false);
    return base::span<const OriginTrialFeature>();
}

base::span<const OriginTrialFeature> origin_trials::GetImpliedFeatures(OriginTrialFeature feature)
{
    if (feature == OriginTrialFeature::kFledge) {
        static constexpr OriginTrialFeature implied_features[] = {
            OriginTrialFeature::kAdInterestGroupAPI,
        };
        return implied_features;
    }
    if (feature == OriginTrialFeature::kParakeet) {
        static constexpr OriginTrialFeature implied_features[] = {
            OriginTrialFeature::kAdInterestGroupAPI,
        };
        return implied_features;
    }
    if (feature == OriginTrialFeature::kOriginTrialsSampleAPI) {
        static constexpr OriginTrialFeature implied_features[] = {
            OriginTrialFeature::kOriginTrialsSampleAPIImplied,
        };
        return implied_features;
    }
    if (feature == OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS) {
        static constexpr OriginTrialFeature implied_features[] = {
            OriginTrialFeature::kOriginTrialsSampleAPIImplied,
        };
        return implied_features;
    }
    if (feature == OriginTrialFeature::kSpeculationRulesPrefetchProxy) {
        static constexpr OriginTrialFeature implied_features[] = {
            OriginTrialFeature::kSpeculationRules,
        };
        return implied_features;
    }
    if (feature == OriginTrialFeature::kWebAppLaunchHandler) {
        static constexpr OriginTrialFeature implied_features[] = {
            OriginTrialFeature::kWebAppLaunchQueue,
        };
        return implied_features;
    }
    if (feature == OriginTrialFeature::kFileHandling) {
        static constexpr OriginTrialFeature implied_features[] = {
            OriginTrialFeature::kWebAppLaunchQueue,
        };
        return implied_features;
    }
    return {};
}

bool origin_trials::FeatureEnabledForOS(OriginTrialFeature feature)
{
    switch (feature) {
    case OriginTrialFeature::kAccessibilityAriaTouchPassthrough:
        return true;
    case OriginTrialFeature::kAdInterestGroupAPI:
        return true;
    case OriginTrialFeature::kAnonymousIframe:
        return true;
    case OriginTrialFeature::kAttributionReporting:
        return true;
    case OriginTrialFeature::kAutoDarkMode:
        return true;
    case OriginTrialFeature::kBackForwardCacheExperimentHTTPHeader:
        return true;
    case OriginTrialFeature::kBackForwardCacheNotRestoredReasons:
        return true;
    case OriginTrialFeature::kBeforeMatchEvent:
        return true;
    case OriginTrialFeature::kCacheStorageCodeCacheHint:
        return true;
    case OriginTrialFeature::kClearIdentityInCanMakePaymentEvent:
        return true;
    case OriginTrialFeature::kComputePressure:
        return true;
    case OriginTrialFeature::kConditionalFocus:
        return true;
    case OriginTrialFeature::kCrossOriginOpenerPolicyReporting:
        return true;
    case OriginTrialFeature::kDeviceAttributes:
#if BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kDigitalGoods:
#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kDisableDifferentOriginSubframeDialogSuppression:
        return true;
    case OriginTrialFeature::kDisableHardwareNoiseSuppression:
        return true;
    case OriginTrialFeature::kDocumentPolicyNegotiation:
        return true;
    case OriginTrialFeature::kEarlyHintsPreloadForNavigationOptIn:
        return true;
    case OriginTrialFeature::kFencedFrames:
        return true;
    case OriginTrialFeature::kFileHandling:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kFledge:
        return true;
    case OriginTrialFeature::kFocusgroup:
        return true;
    case OriginTrialFeature::kHrefTranslate:
        return true;
    case OriginTrialFeature::kHTMLPopupAttribute:
        return true;
    case OriginTrialFeature::kMediaSourceExtensionsForWebCodecs:
        return true;
    case OriginTrialFeature::kMediaSourceInWorkers:
        return true;
    case OriginTrialFeature::kNotificationTriggers:
        return true;
    case OriginTrialFeature::kOriginTrialsSampleAPI:
        return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIDeprecation:
        return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriod:
        return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriodThirdParty:
        return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIImplied:
        return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS:
#if BUILDFLAG(IS_INVALID)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kOriginTrialsSampleAPINavigation:
        return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIPersistentExpiryGracePeriod:
        return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIPersistentFeature:
        return true;
    case OriginTrialFeature::kOriginTrialsSampleAPIThirdParty:
        return true;
    case OriginTrialFeature::kPageFreezeOptIn:
        return true;
    case OriginTrialFeature::kPageFreezeOptOut:
        return true;
    case OriginTrialFeature::kParakeet:
        return true;
    case OriginTrialFeature::kPartitionedCookies:
        return true;
    case OriginTrialFeature::kPendingBeaconAPI:
        return true;
    case OriginTrialFeature::kPerMethodCanMakePaymentQuota:
        return true;
    case OriginTrialFeature::kPermissionsPolicyUnload:
        return true;
    case OriginTrialFeature::kPNaCl:
        return true;
    case OriginTrialFeature::kPointerLockOptions:
        return true;
    case OriginTrialFeature::kPortals:
#if BUILDFLAG(IS_ANDROID)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kPrerender2RelatedFeatures:
        return true;
    case OriginTrialFeature::kPrivacySandboxAdsAPIs:
        return true;
    case OriginTrialFeature::kPrivateNetworkAccessNonSecureContextsAllowed:
        return true;
    case OriginTrialFeature::kRtcAudioJitterBufferMaxPackets:
        return true;
    case OriginTrialFeature::kRTCIceTransportExtension:
        return true;
    case OriginTrialFeature::kRTCInsertableStreams:
        return true;
    case OriginTrialFeature::kRTCQuicTransport:
        return true;
    case OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay:
        return true;
    case OriginTrialFeature::kSecurePaymentConfirmationOptOut:
        return true;
    case OriginTrialFeature::kSendFullUserAgentAfterReduction:
        return true;
    case OriginTrialFeature::kSharedStorageAPI:
        return true;
    case OriginTrialFeature::kSignatureBasedIntegrity:
        return true;
    case OriginTrialFeature::kSkipAd:
        return true;
    case OriginTrialFeature::kSpeculationRules:
        return true;
    case OriginTrialFeature::kSpeculationRulesPrefetchProxy:
        return true;
    case OriginTrialFeature::kStorageFoundationAPI:
        return true;
    case OriginTrialFeature::kTextFragmentIdentifiers:
        return true;
    case OriginTrialFeature::kTopicsAPI:
        return true;
    case OriginTrialFeature::kTouchEventFeatureDetection:
        return true;
    case OriginTrialFeature::kTrustTokens:
        return true;
    case OriginTrialFeature::kU2FSecurityKeyAPI:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kUnrestrictedSharedArrayBuffer:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kUserAgentReduction:
#if BUILDFLAG(IS_ANDROID) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_FUCHSIA) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_WIN)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kWebAppDarkMode:
        return true;
    case OriginTrialFeature::kWebAppLaunchHandler:
        return true;
    case OriginTrialFeature::kWebAppLaunchQueue:
        return true;
    case OriginTrialFeature::kWebAppUrlHandling:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kWebAppWindowControlsOverlay:
#if BUILDFLAG(IS_WIN) || BUILDFLAG(IS_MAC) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
        return true;
#else
        return false;
#endif
    case OriginTrialFeature::kWebAssemblyExceptions:
        return true;
    case OriginTrialFeature::kWebCodecs:
        return true;
    case OriginTrialFeature::kWebGPU:
        return true;
    case OriginTrialFeature::kWebPaymentAPICSP:
        return true;
    case OriginTrialFeature::kWebTransportCustomCertificates:
        return true;
    case OriginTrialFeature::kWebXRDepth:
        return true;
    case OriginTrialFeature::kWebXRImageTracking:
        return true;
    case OriginTrialFeature::kWebXRPlaneDetection:
        return true;
    // For testing
    case OriginTrialFeature::kNonExisting:
        return true;
    }
    return false;
}

} // namespace blink
