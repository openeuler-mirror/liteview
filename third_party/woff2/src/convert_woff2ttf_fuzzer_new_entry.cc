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

#include <string>
#include <woff2/decode.h>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t data_size)
{
    // Decode using newer entry pattern.
    // Same pattern as woff2_decompress.
    std::string output(std::min(woff2::ComputeWOFF2FinalSize(data, data_size), woff2::kDefaultMaxSize), 0);
    woff2::WOFF2StringOut out(&output);
    woff2::ConvertWOFF2ToTTF(data, data_size, &out);
    return 0;
}
