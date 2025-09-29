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
#ifndef __NUMPARSE_SCIENTIFIC_H__
#define __NUMPARSE_SCIENTIFIC_H__

#include "numparse_types.h"
#include "numparse_decimal.h"
#include "numparse_symbols.h"
#include "unicode/numberformatter.h"

using icu::number::impl::Grouper;

U_NAMESPACE_BEGIN namespace numparse
{
    namespace impl {

    class ScientificMatcher : public NumberParseMatcher, public UMemory {
    public:
        ScientificMatcher() = default; // WARNING: Leaves the object in an unusable state

        ScientificMatcher(const DecimalFormatSymbols& dfs, const Grouper& grouper);

        bool match(StringSegment& segment, ParsedNumber& result, UErrorCode& status) const override;

        bool smokeTest(const StringSegment& segment) const override;

        UnicodeString toString() const override;

    private:
        UnicodeString fExponentSeparatorString;
        DecimalMatcher fExponentMatcher;
        IgnorablesMatcher fIgnorablesMatcher;
        UnicodeString fCustomMinusSign;
        UnicodeString fCustomPlusSign;
    };

    } // namespace impl
} // namespace numparse
U_NAMESPACE_END

#endif //__NUMPARSE_SCIENTIFIC_H__
#endif /* #if !UCONFIG_NO_FORMATTING */
