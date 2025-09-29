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

#include "quiche/spdy/core/http2_header_storage.h"

#include "quiche/common/platform/api/quiche_test.h"

namespace spdy {
namespace test {

TEST(JoinTest, JoinEmpty)
{
    std::vector<absl::string_view> empty;
    absl::string_view separator = ", ";
    char buf[10] = "";
    size_t written = Join(buf, empty, separator);
    EXPECT_EQ(0u, written);
}

TEST(JoinTest, JoinOne)
{
    std::vector<absl::string_view> v = { "one" };
    absl::string_view separator = ", ";
    char buf[15];
    size_t written = Join(buf, v, separator);
    EXPECT_EQ(3u, written);
    EXPECT_EQ("one", absl::string_view(buf, written));
}

TEST(JoinTest, JoinMultiple)
{
    std::vector<absl::string_view> v = { "one", "two", "three" };
    absl::string_view separator = ", ";
    char buf[15];
    size_t written = Join(buf, v, separator);
    EXPECT_EQ(15u, written);
    EXPECT_EQ("one, two, three", absl::string_view(buf, written));
}

} // namespace test
} // namespace spdy
