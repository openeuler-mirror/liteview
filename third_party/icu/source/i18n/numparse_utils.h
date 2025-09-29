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
#ifndef __NUMPARSE_UTILS_H__
#define __NUMPARSE_UTILS_H__

#include "numparse_types.h"
#include "unicode/uniset.h"

U_NAMESPACE_BEGIN namespace numparse
{
    namespace impl {
    namespace utils {

    inline static void putLeadCodePoints(const UnicodeSet* input, UnicodeSet* output)
    {
        for (int32_t i = 0; i < input->getRangeCount(); i++) {
            output->add(input->getRangeStart(i), input->getRangeEnd(i));
        }
        // TODO: ANDY: How to iterate over the strings in ICU4C UnicodeSet?
    }

    inline static void putLeadCodePoint(const UnicodeString& input, UnicodeSet* output)
    {
        if (!input.isEmpty()) {
            output->add(input.char32At(0));
        }
    }

    inline static void copyCurrencyCode(UChar* dest, const UChar* src)
    {
        uprv_memcpy(dest, src, sizeof(UChar) * 3);
        dest[3] = 0;
    }

    } // namespace utils
    } // namespace impl
} // namespace numparse
U_NAMESPACE_END

#endif //__NUMPARSE_UTILS_H__
#endif /* #if !UCONFIG_NO_FORMATTING */
