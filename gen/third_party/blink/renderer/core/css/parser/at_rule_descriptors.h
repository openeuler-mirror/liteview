// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_

#include "base/notreached.h"
#include "third_party/blink/renderer/core/css/css_property_names.h"
#include "third_party/blink/renderer/platform/wtf/text/string_view.h"
#include <string.h>

namespace blink {

enum class AtRuleDescriptorID {
    Invalid = 0,
    AdditiveSymbols = 1,
    AscentOverride = 2,
    BasePalette = 3,
    DescentOverride = 4,
    End = 5,
    FontDisplay = 6,
    FontFamily = 7,
    FontFeatureSettings = 8,
    FontStretch = 9,
    FontStyle = 10,
    FontVariant = 11,
    FontWeight = 12,
    Inherits = 13,
    InitialValue = 14,
    Fallback = 15,
    LineGapOverride = 16,
    Negative = 17,
    OverrideColors = 18,
    Pad = 19,
    Prefix = 20,
    Range = 21,
    SizeAdjust = 22,
    Source = 23,
    SpeakAs = 24,
    Src = 25,
    Start = 26,
    Suffix = 27,
    Symbols = 28,
    Syntax = 29,
    System = 30,
    UnicodeRange = 31,
};

const int numAtRuleDescriptors = 32;

const char* getValueName(AtRuleDescriptorID);

AtRuleDescriptorID AsAtRuleDescriptorID(StringView string);

CSSPropertyID AtRuleDescriptorIDAsCSSPropertyID(AtRuleDescriptorID);
AtRuleDescriptorID CSSPropertyIDAsAtRuleDescriptor(CSSPropertyID id);

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_CSS_PARSER_AT_RULE_DESCRIPTORS_H_
