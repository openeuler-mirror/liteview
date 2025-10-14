// Copyright 2020 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#include "third_party/blink/public/common/permissions_policy/permissions_policy_features.h"

#include "base/no_destructor.h"
#include "base/feature_list.h"
#include "third_party/blink/public/common/features.h"
#include "third_party/blink/public/mojom/permissions_policy/permissions_policy_feature.mojom.h"

namespace blink {

const PermissionsPolicyFeatureList& GetPermissionsPolicyFeatureList()
{
    static const base::NoDestructor<PermissionsPolicyFeatureList> feature_list([] {
        PermissionsPolicyFeatureList map({
            { mojom::PermissionsPolicyFeature::kAccelerometer, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kAmbientLightSensor, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kAttributionReporting, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kAutoplay, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kBluetooth, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kBrowsingTopics, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kBrowsingTopicsBackwardCompatible, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kCamera, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintDPR, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintDeviceMemory, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintDownlink, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintECT, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintPrefersColorScheme, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintPrefersReducedMotion, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintRTT, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintSaveData, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kClientHintUA, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kClientHintUAArch, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintUABitness, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintUAPlatform, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kClientHintUAModel, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintUAMobile, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kClientHintUAFull, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintUAFullVersion, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintUAFullVersionList, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintUAPlatformVersion, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintUAWoW64, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintUAReduced, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintViewportHeight, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintViewportWidth, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClientHintWidth, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClipboardRead, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kClipboardWrite, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kCrossOriginIsolated, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kDirectSockets, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kDisplayCapture, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kDocumentDomain, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kEncryptedMedia, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kExecutionWhileOutOfViewport, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kExecutionWhileNotRendered, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kIdentityCredentialsGet, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kFocusWithoutUserActivation, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kFullscreen, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kFrobulate, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kGamepad, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kGeolocation, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kGyroscope, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kHid, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kIdleDetection, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kJoinAdInterestGroup, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kKeyboardMap, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kMagnetometer, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kMicrophone, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kMidiFeature, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kOTPCredentials, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kPayment, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kPictureInPicture, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kPublicKeyCredentialsGet, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kRunAdAuction, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kScreenWakeLock, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kSerial, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kSharedAutofill, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kSharedStorage, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kStorageAccessAPI, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kSyncXHR, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kTrustTokenRedemption, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kUsb, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kUnload, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kVerticalScroll, PermissionsPolicyFeatureDefault::EnableForAll },
            { mojom::PermissionsPolicyFeature::kWebShare, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kWebXr, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kWindowPlacement, PermissionsPolicyFeatureDefault::EnableForSelf },
            { mojom::PermissionsPolicyFeature::kLocalFonts, PermissionsPolicyFeatureDefault::EnableForSelf },
        });
        if (base::FeatureList::IsEnabled(features::kAdInterestGroupAPIRestrictedPolicyByDefault)) {
            map.find(mojom::PermissionsPolicyFeature::kJoinAdInterestGroup)->second = PermissionsPolicyFeatureDefault::EnableForSelf;
        }
        if (base::FeatureList::IsEnabled(features::kAdInterestGroupAPIRestrictedPolicyByDefault)) {
            map.find(mojom::PermissionsPolicyFeature::kRunAdAuction)->second = PermissionsPolicyFeatureDefault::EnableForSelf;
        }
        return map;
    }());
    return *feature_list;
}

} // namespace blink
