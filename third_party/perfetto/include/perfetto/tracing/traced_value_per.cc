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
#include "third_party/perfetto/include/perfetto/tracing/traced_value.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

perfetto::TracedDictionary perfetto::TracedValue::WriteDictionary(void)
{
    *(int*)1 = 1;
    return perfetto::TracedDictionary();
}

void perfetto::TracedValue::WriteString(char const*, size_t)
{
    *(int*)1 = 1;
}
void perfetto::TracedValue::WriteString(const std::string&)
{
    *(int*)1 = 1;
}

// template <typename T>
// void perfetto::WriteIntoTracedValue<WTF::String const&>(perfetto::TracedValue, WTF::String const&)
//{
//   *(int*)1 = 1;
// }