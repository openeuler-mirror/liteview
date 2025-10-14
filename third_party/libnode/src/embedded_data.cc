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

#include "embedded_data.h"
#include <vector>

namespace node {
std::string ToOctalString(const uint8_t ch)
{
    // We can print most printable characters directly. The exceptions are '\'
    // (escape characters), " (would end the string), and ? (trigraphs). The
    // latter may be overly conservative: we compile with C++17 which doesn't
    // support trigraphs.
    if (ch >= ' ' && ch <= '~' && ch != '\\' && ch != '"' && ch != '?') {
        return std::string(1, static_cast<char>(ch));
    }
    // All other characters are blindly output as octal.
    const char c0 = '0' + ((ch >> 6) & 7);
    const char c1 = '0' + ((ch >> 3) & 7);
    const char c2 = '0' + (ch & 7);
    return std::string("\\") + c0 + c1 + c2;
}

std::vector<std::string> GetOctalTable()
{
    size_t size = 1 << 8;
    std::vector<std::string> code_table(size);
    for (size_t i = 0; i < size; ++i) {
        code_table[i] = ToOctalString(static_cast<uint8_t>(i));
    }
    return code_table;
}

const std::string& GetOctalCode(uint8_t index)
{
    static std::vector<std::string> table = GetOctalTable();
    return table[index];
}
} // namespace node
