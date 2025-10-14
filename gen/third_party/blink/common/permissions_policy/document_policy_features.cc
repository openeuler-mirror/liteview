// Copyright 2020 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
#include "base/no_destructor.h"
#include "base/feature_list.h"
#include "third_party/blink/public/common/features.h"
#include "third_party/blink/public/common/permissions_policy/document_policy_features.h"
#include "third_party/blink/public/common/permissions_policy/policy_value.h"
#include "third_party/blink/public/mojom/permissions_policy/policy_value.mojom.h"
#include "third_party/blink/public/mojom/permissions_policy/document_policy_feature.mojom.h"
namespace blink {

const DocumentPolicyFeatureInfoMap& GetDocumentPolicyFeatureInfoMap()
{
    static const base::NoDestructor<DocumentPolicyFeatureInfoMap> feature_info_map([] {
        DocumentPolicyFeatureInfoMap map({
            { mojom::DocumentPolicyFeature::kDefault, { "*", PolicyValue::CreateBool(true) } },
            { mojom::DocumentPolicyFeature::kFontDisplay, { "font-display-late-swap", PolicyValue::CreateBool(true) } },
            { mojom::DocumentPolicyFeature::kLosslessImagesMaxBpp, { "lossless-images-max-bpp", PolicyValue::CreateMaxPolicyValue(mojom::PolicyValueType::kDecDouble) } },
            { mojom::DocumentPolicyFeature::kForceLoadAtTop, { "force-load-at-top", PolicyValue::CreateBool(false) } },
            { mojom::DocumentPolicyFeature::kLosslessImagesStrictMaxBpp,
                { "lossless-images-strict-max-bpp", PolicyValue::CreateMaxPolicyValue(mojom::PolicyValueType::kDecDouble) } },
            { mojom::DocumentPolicyFeature::kLossyImagesMaxBpp, { "lossy-images-max-bpp", PolicyValue::CreateMaxPolicyValue(mojom::PolicyValueType::kDecDouble) } },
            { mojom::DocumentPolicyFeature::kOversizedImages, { "oversized-images", PolicyValue::CreateMaxPolicyValue(mojom::PolicyValueType::kDecDouble) } },
            { mojom::DocumentPolicyFeature::kUnsizedMedia, { "unsized-media", PolicyValue::CreateBool(true) } },
            { mojom::DocumentPolicyFeature::kLayoutAnimations, { "layout-animations", PolicyValue::CreateBool(true) } },
            { mojom::DocumentPolicyFeature::kDocumentWrite, { "document-write", PolicyValue::CreateBool(true) } },
            { mojom::DocumentPolicyFeature::kSyncScript, { "sync-script", PolicyValue::CreateBool(true) } },
            { mojom::DocumentPolicyFeature::kJSProfiling, { "js-profiling", PolicyValue::CreateBool(false) } },
            { mojom::DocumentPolicyFeature::kSyncXHR, { "sync-xhr", PolicyValue::CreateBool(true) } },
            { mojom::DocumentPolicyFeature::kDocumentDomain, { "document-domain", PolicyValue::CreateBool(true) } },
        });
        if (base::FeatureList::IsEnabled(features::kDisableDocumentDomainByDefault)) {
            map.find(mojom::DocumentPolicyFeature::kDocumentDomain)->second.default_value = PolicyValue::CreateBool(false);
        }
        return map;
    }());
    return *feature_info_map;
}

const DocumentPolicyNameFeatureMap& GetDocumentPolicyNameFeatureMap()
{
    static const base::NoDestructor<DocumentPolicyNameFeatureMap> name_feature_map([] {
        DocumentPolicyNameFeatureMap map;
        for (const auto& entry : GetDocumentPolicyFeatureInfoMap())
            map.emplace(entry.second.feature_name, entry.first);
        return map;
    }());
    return *name_feature_map;
}

} // namespace blink
