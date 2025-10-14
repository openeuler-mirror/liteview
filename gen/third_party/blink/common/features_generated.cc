// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/features_generated.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5
#include "third_party/blink/public/common/features_generated.h"

namespace blink {
namespace features {

BASE_FEATURE(kAdInterestGroupAPI, "AdInterestGroupAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kAutofillShadowDOM, "AutofillShadowDOM", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBackfaceVisibilityInterop, "BackfaceVisibilityInterop", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBackForwardCacheSendNotRestoredReasons, "BackForwardCacheSendNotRestoredReasons", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBatchFetchRequests, "BatchFetchRequests", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kBlockingFocusWithoutUserActivation, "BlockingFocusWithoutUserActivation", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kClearIdentityInCanMakePaymentEvent, "ClearIdentityInCanMakePaymentEvent", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kClientHintsMetaEquivDelegateCH, "ClientHintsMetaEquivDelegateCH", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kClientHintsMetaHTTPEquivAcceptCH, "ClientHintsMetaHTTPEquivAcceptCH", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kClientHintThirdPartyDelegation, "ClientHintThirdPartyDelegation", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kClipboardCustomFormats, "ClipboardCustomFormats", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCLSScrollAnchoring, "CLSScrollAnchoring", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kComputePressure, "ComputePressure", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kCSSOverflowForReplacedElements, "CSSOverflowForReplacedElements", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kCssSelectorFragmentAnchor, "CssSelectorFragmentAnchor", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDeferredShaping, "DeferredShaping", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDesktopPWAsSubApps, "DesktopPWAsSubApps", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kDocumentTransition, "DocumentTransition", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEditContext, "EditContext", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kElementSuperRareData, "ElementSuperRareData", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kEventPath, "EventPath", base::FEATURE_ENABLED_BY_DEFAULT);

const base::FeatureState kFileHandlingAPIValue =
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_WIN)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_MAC)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_LINUX)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif

BASE_FEATURE(kFileHandlingAPI, "FileHandlingAPI", kFileHandlingAPIValue);

BASE_FEATURE(kFixedElementsDontOverscroll, "FixedElementsDontOverscroll", base::FEATURE_ENABLED_BY_DEFAULT);

const base::FeatureState kFontAccessValue =
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_DISABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_WIN)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_MAC)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_LINUX)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
base::FEATURE_ENABLED_BY_DEFAULT;
#endif
BASE_FEATURE(kFontAccess, "FontAccess", kFontAccessValue);

BASE_FEATURE(kFormRelAttribute, "FormRelAttribute", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLParamElementUrlSupport, "HTMLParamElementUrlSupport", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kHTMLPopupAttribute, "HTMLPopupAttribute", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kLangAttributeAwareSvgText, "LangAttributeAwareSvgText", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLayoutNG, "LayoutNG", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLayoutNGDelayScrollOffsetClamping, "LayoutNGDelayScrollOffsetClamping", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kLayoutNGPrinting, "LayoutNGPrinting", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kManagedConfiguration, "ManagedConfiguration", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMediaSourceInWorkers, "MediaSourceInWorkers", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kMediaSourceInWorkersUsingHandle, "MediaSourceInWorkersUsingHandle", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kNavigationId, "NavigationId", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kOffsetParentNewSpecBehavior, "OffsetParentNewSpecBehavior", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kParakeet, "Parakeet", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPermissionsPolicyUnload, "PermissionsPolicyUnload", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPortals, "Portals", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPrefersColorSchemeClientHintHeader, "PrefersColorSchemeClientHintHeader", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPrefersReducedMotionClientHintHeader, "PrefersReducedMotionClientHintHeader", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPrefixedStorageInfo, "PrefixedStorageInfo", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kPrerender2, "Prerender2", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kPrivateNetworkAccessPermissionPrompt, "PrivateNetworkAccessPermissionPrompt", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kQuickIntensiveWakeUpThrottlingAfterLoading, "QuickIntensiveWakeUpThrottlingAfterLoading", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kReduceUserAgentMinorVersion, "ReduceUserAgentMinorVersion", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kReduceUserAgentPlatformOsCpu, "ReduceUserAgentPlatformOsCpu", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSanitizerAPI, "SanitizerAPI", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kSanitizerAPIv0, "SanitizerAPIv0", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kScrollUpdateOptimizations, "ScrollUpdateOptimizations", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSkipTouchEventFilter, "SkipTouchEventFilter", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kSoftNavigationHeuristics, "SoftNavigationHeuristics", base::FEATURE_DISABLED_BY_DEFAULT);

const base::FeatureState kSpeculationRulesPrefetchProxyValue =
#if BUILDFLAG(IS_ANDROID)
    base::FEATURE_ENABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_WIN)
base::FEATURE_DISABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_CHROMEOS_ASH)
base::FEATURE_DISABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_CHROMEOS_LACROS)
base::FEATURE_DISABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_MAC)
base::FEATURE_DISABLED_BY_DEFAULT;
#endif
#if BUILDFLAG(IS_LINUX)
base::FEATURE_DISABLED_BY_DEFAULT;
#endif
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
base::FEATURE_DISABLED_BY_DEFAULT;
#endif

BASE_FEATURE(kSpeculationRulesPrefetchProxy, "SpeculationRulesPrefetchProxy", kSpeculationRulesPrefetchProxyValue);

BASE_FEATURE(kStorageAccessAPIForOriginExtension, "StorageAccessAPIForOriginExtension", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kStorageBuckets, "StorageBuckets", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kTextFragmentAnchor, "TextFragmentAnchor", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframes, "ThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframes", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kUserAgentClientHint, "UserAgentClientHint", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kReduceUserAgent, "ReduceUserAgent", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kVariableCOLRV1, "VariableCOLRV1", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kViewportHeightClientHintHeader, "ViewportHeightClientHintHeader", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWebAppEnableDarkMode, "WebAppEnableDarkMode", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAppEnableLaunchHandler, "WebAppEnableLaunchHandler", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWebAppEnableTranslations, "WebAppEnableTranslations", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWindowDefaultStatus, "WindowDefaultStatus", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kWindowOpenNewPopupBehavior, "WindowOpenNewPopupBehavior", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWindowPlacement, "WindowPlacement", base::FEATURE_ENABLED_BY_DEFAULT);

BASE_FEATURE(kWindowPlacementFullscreenOnScreensChange, "WindowPlacementFullscreenOnScreensChange", base::FEATURE_DISABLED_BY_DEFAULT);

BASE_FEATURE(kZeroCopyTabCapture, "ZeroCopyTabCapture", base::FEATURE_DISABLED_BY_DEFAULT);
} // namespace features
} // namespace blink
