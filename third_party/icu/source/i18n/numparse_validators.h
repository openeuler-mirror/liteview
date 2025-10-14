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

// © 2018 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html

#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING
#ifndef __SOURCE_NUMPARSE_VALIDATORS_H__
#define __SOURCE_NUMPARSE_VALIDATORS_H__

#include "numparse_types.h"
#include "static_unicode_sets.h"

U_NAMESPACE_BEGIN namespace numparse
{
    namespace impl {

    class ValidationMatcher : public NumberParseMatcher {
    public:
        bool match(StringSegment&, ParsedNumber&, UErrorCode&) const U_OVERRIDE
        {
            // No-op
            return false;
        }

        bool smokeTest(const StringSegment&) const U_OVERRIDE
        {
            // No-op
            return false;
        }

        void postProcess(ParsedNumber& result) const U_OVERRIDE = 0;
    };

    class RequireAffixValidator : public ValidationMatcher, public UMemory {
    public:
        void postProcess(ParsedNumber& result) const U_OVERRIDE;

        UnicodeString toString() const U_OVERRIDE;
    };

    class RequireCurrencyValidator : public ValidationMatcher, public UMemory {
    public:
        void postProcess(ParsedNumber& result) const U_OVERRIDE;

        UnicodeString toString() const U_OVERRIDE;
    };

    class RequireDecimalSeparatorValidator : public ValidationMatcher, public UMemory {
    public:
        RequireDecimalSeparatorValidator() = default; // leaves instance in valid but undefined state

        RequireDecimalSeparatorValidator(bool patternHasDecimalSeparator);

        void postProcess(ParsedNumber& result) const U_OVERRIDE;

        UnicodeString toString() const U_OVERRIDE;

    private:
        bool fPatternHasDecimalSeparator;
    };

    class RequireNumberValidator : public ValidationMatcher, public UMemory {
    public:
        void postProcess(ParsedNumber& result) const U_OVERRIDE;

        UnicodeString toString() const U_OVERRIDE;
    };

    /**
     * Wraps a {@link Multiplier} for use in the number parsing pipeline.
     */
    class MultiplierParseHandler : public ValidationMatcher, public UMemory {
    public:
        MultiplierParseHandler() = default; // leaves instance in valid but undefined state

        MultiplierParseHandler(::icu::number::Scale multiplier);

        void postProcess(ParsedNumber& result) const U_OVERRIDE;

        UnicodeString toString() const U_OVERRIDE;

    private:
        ::icu::number::Scale fMultiplier;
    };

    } // namespace impl
} // namespace numparse
U_NAMESPACE_END

#endif //__SOURCE_NUMPARSE_VALIDATORS_H__
#endif /* #if !UCONFIG_NO_FORMATTING */
