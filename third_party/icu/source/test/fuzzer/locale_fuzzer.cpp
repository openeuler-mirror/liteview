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

// Fuzzer for ICU Locales.

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <string>
#include <vector>

#include "unicode/locid.h"

namespace {

void ConsumeNBytes(const uint8_t** data, size_t* size, size_t N)
{
    *data += N;
    *size -= N;
}

uint8_t ConsumeUint8(const uint8_t** data, size_t* size)
{
    uint8_t tmp = 0;
    if (*size >= 1) {
        tmp = (*data)[0];
        ConsumeNBytes(data, size, 1);
    }
    return tmp;
}

std::string ConsumeSubstring(const uint8_t** data, size_t* size)
{
    const size_t request_size = ConsumeUint8(data, size);
    const char* substring_start = reinterpret_cast<const char*>(*data);
    const size_t substring_size = std::min(*size, request_size);
    ConsumeNBytes(data, size, substring_size);
    return std::string(substring_start, substring_size);
}

} // namespace

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
    const std::string language = ConsumeSubstring(&data, &size);
    const std::string country = ConsumeSubstring(&data, &size);
    const std::string variant = ConsumeSubstring(&data, &size);
    const std::string kv_pairs = ConsumeSubstring(&data, &size);
    icu::Locale locale(language.c_str(), country.c_str(), variant.c_str(), kv_pairs.c_str());
    return EXIT_SUCCESS;
}
