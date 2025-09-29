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

// © 2019 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html

#include <stddef.h>
#include <stdint.h>
#include <string.h>

#include "fuzzer_utils.h"
#include "unicode/regex.h"

IcuEnvironment* env = new IcuEnvironment();

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    UParseError pe = { 0 };
    UErrorCode status = U_ZERO_ERROR;

    URegularExpression* re = uregex_open(reinterpret_cast<const UChar*>(data), static_cast<int>(size) / sizeof(UChar), 0, &pe, &status);

    if (re)
        uregex_close(re);

    return 0;
}
