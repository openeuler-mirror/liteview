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

#include "quiche/common/platform/api/quiche_stack_trace.h"

#include <cstdint>

#include "absl/base/attributes.h"
#include "absl/base/optimization.h"
#include "absl/strings/str_cat.h"
#include "quiche/common/platform/api/quiche_test.h"

namespace quiche {
namespace test {
namespace {

bool ShouldRunTest()
{
#if defined(ABSL_HAVE_ATTRIBUTE_NOINLINE)
    return QuicheShouldRunStackTraceTest();
#else
    // If QuicheDesignatedStackTraceTestFunction gets inlined, the test will
    // inevitably fail, since the function won't be on the stack trace.  Disable
    // the test in that scenario.
    return false;
#endif
}

ABSL_ATTRIBUTE_NOINLINE std::string QuicheDesignatedStackTraceTestFunction()
{
    std::string result = QuicheStackTrace();
    ABSL_BLOCK_TAIL_CALL_OPTIMIZATION();
    return result;
}

TEST(QuicheStackTraceTest, GetStackTrace)
{
    if (!ShouldRunTest()) {
        return;
    }

    std::string stacktrace = QuicheDesignatedStackTraceTestFunction();
    EXPECT_THAT(stacktrace, testing::HasSubstr("QuicheDesignatedStackTraceTestFunction"));
}

} // namespace
} // namespace test
} // namespace quiche
