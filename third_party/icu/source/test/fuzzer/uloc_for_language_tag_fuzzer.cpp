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

#include <string>

#include "locale_util.h"
#include "unicode/uloc.h"

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    // Full locale id.
    char locale_id[ULOC_FULLNAME_CAPACITY];
    int32_t locale_id_capacity = ULOC_FULLNAME_CAPACITY;

    const std::string input = MakeZeroTerminatedInput(data, size);

    UErrorCode status = U_ZERO_ERROR;
    uloc_forLanguageTag(input.c_str(), locale_id, locale_id_capacity, nullptr, &status);

    return 0;
}
