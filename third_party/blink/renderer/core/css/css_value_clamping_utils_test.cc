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

#include "third_party/blink/renderer/core/css/css_value_clamping_utils.h"

#include <limits>
#include "testing/gtest/include/gtest/gtest.h"

namespace blink {

TEST(CSSValueClampingTest, IsLengthNotClampedZeroValue)
{
    EXPECT_EQ(CSSValueClampingUtils::ClampLength(0.0), 0.0);
}

TEST(CSSValueClampingTest, IsLengthNotClampedPositiveFiniteValue)
{
    EXPECT_EQ(CSSValueClampingUtils::ClampLength(10.0), 10.0);
}

TEST(CSSValueClampingTest, IsLengthNotClampediNegativeFiniteValue)
{
    EXPECT_EQ(CSSValueClampingUtils::ClampLength(-10.0), -10.0);
}

TEST(CSSValueClampingTest, IsLengthClampedPositiveInfinity)
{
    EXPECT_EQ(CSSValueClampingUtils::ClampLength(std::numeric_limits<double>::infinity()), std::numeric_limits<double>::max());
}

TEST(CSSValueClampingTest, IsLengthClampedNaN)
{
    EXPECT_EQ(CSSValueClampingUtils::ClampLength(std::numeric_limits<double>::quiet_NaN()), std::numeric_limits<double>::max());
}

TEST(CSSValueClampingTest, IsLengthClampedNegativeInfinity)
{
    EXPECT_EQ(CSSValueClampingUtils::ClampLength(-std::numeric_limits<double>::infinity()), std::numeric_limits<double>::lowest());
}

} // namespace blink
