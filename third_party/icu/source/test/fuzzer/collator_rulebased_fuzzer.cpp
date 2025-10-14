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

#include <cstring>

#include "fuzzer_utils.h"
#include "unicode/coll.h"
#include "unicode/localpointer.h"
#include "unicode/locid.h"
#include "unicode/tblcoll.h"

IcuEnvironment* env = new IcuEnvironment();

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    UErrorCode status = U_ZERO_ERROR;

    size_t unistr_size = size / 2;
    std::unique_ptr<char16_t[]> fuzzbuff(new char16_t[unistr_size]);
    std::memcpy(fuzzbuff.get(), data, unistr_size * 2);
    icu::UnicodeString fuzzstr(false, fuzzbuff.get(), unistr_size);

    icu::LocalPointer<icu::RuleBasedCollator> col1(new icu::RuleBasedCollator(fuzzstr, status));

    return 0;
}
