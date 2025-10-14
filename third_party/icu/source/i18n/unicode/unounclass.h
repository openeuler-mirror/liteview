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

// © 2022 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html

#ifndef __UNOUNCLASS_H__
#define __UNOUNCLASS_H__

#include "unicode/utypes.h"

#if U_SHOW_CPLUSPLUS_API

#if !UCONFIG_NO_FORMATTING

#include "unicode/uversion.h"

U_NAMESPACE_BEGIN

#ifndef U_HIDE_DRAFT_API

/**
 * Represents all the grammatical noun classes that are supported by CLDR.
 *
 * @draft ICU 71.
 */
enum NounClass {
    OTHER = 0,
    NEUTER = 1,
    FEMININE = 2,
    MASCULINE = 3,
    ANIMATE = 4,
    INANIMATE = 5,
    PERSONAL = 6,
    COMMON = 7,
};

#endif // U_HIDE_DRAFT_API

U_NAMESPACE_END

#endif /* #if !UCONFIG_NO_FORMATTING */

#endif /* U_SHOW_CPLUSPLUS_API */

#endif // __UNOUNCLASS_H__
