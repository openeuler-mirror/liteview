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

// Allow implicit conversion from char16_t* to UnicodeString for this file:
// Helpful in toString methods and elsewhere.
#define UNISTR_FROM_STRING_EXPLICIT

#include "unicode/compactdecimalformat.h"
#include "number_mapper.h"
#include "number_decimfmtprops.h"

using namespace icu;

UOBJECT_DEFINE_RTTI_IMPLEMENTATION(CompactDecimalFormat)

CompactDecimalFormat* CompactDecimalFormat::createInstance(const Locale& inLocale, UNumberCompactStyle style, UErrorCode& status)
{
    return new CompactDecimalFormat(inLocale, style, status);
}

CompactDecimalFormat::CompactDecimalFormat(const Locale& inLocale, UNumberCompactStyle style, UErrorCode& status)
    : DecimalFormat(new DecimalFormatSymbols(inLocale, status), status)
{
    if (U_FAILURE(status))
        return;
    // Minimal properties: let the non-shim code path do most of the logic for us.
    fields->properties.compactStyle = style;
    fields->properties.groupingSize = -2; // do not forward grouping information
    fields->properties.minimumGroupingDigits = 2;
    touch(status);
}

CompactDecimalFormat::CompactDecimalFormat(const CompactDecimalFormat& source) = default;

CompactDecimalFormat::~CompactDecimalFormat() = default;

CompactDecimalFormat& CompactDecimalFormat::operator=(const CompactDecimalFormat& rhs)
{
    DecimalFormat::operator=(rhs);
    return *this;
}

CompactDecimalFormat* CompactDecimalFormat::clone() const
{
    return new CompactDecimalFormat(*this);
}

void CompactDecimalFormat::parse(const UnicodeString& /* text */, Formattable& /* result */, ParsePosition& /* parsePosition */) const
{
}

void CompactDecimalFormat::parse(const UnicodeString& /* text */, Formattable& /* result */, UErrorCode& status) const
{
    status = U_UNSUPPORTED_ERROR;
}

CurrencyAmount* CompactDecimalFormat::parseCurrency(const UnicodeString& /* text */, ParsePosition& /* pos */) const
{
    return nullptr;
}

#endif /* #if !UCONFIG_NO_FORMATTING */
