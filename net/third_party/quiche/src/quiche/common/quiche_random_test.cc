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

#include "quiche/common/quiche_random.h"

#include "quiche/common/platform/api/quiche_test.h"

namespace quiche {
namespace {

TEST(QuicheRandom, RandBytes)
{
    unsigned char buf1[16];
    unsigned char buf2[16];
    memset(buf1, 0xaf, sizeof(buf1));
    memset(buf2, 0xaf, sizeof(buf2));
    ASSERT_EQ(0, memcmp(buf1, buf2, sizeof(buf1)));

    auto rng = QuicheRandom::GetInstance();
    rng->RandBytes(buf1, sizeof(buf1));
    EXPECT_NE(0, memcmp(buf1, buf2, sizeof(buf1)));
}

TEST(QuicheRandom, RandUint64)
{
    auto rng = QuicheRandom::GetInstance();
    uint64_t value1 = rng->RandUint64();
    uint64_t value2 = rng->RandUint64();
    EXPECT_NE(value1, value2);
}

TEST(QuicheRandom, InsecureRandBytes)
{
    unsigned char buf1[16];
    unsigned char buf2[16];
    memset(buf1, 0xaf, sizeof(buf1));
    memset(buf2, 0xaf, sizeof(buf2));
    ASSERT_EQ(0, memcmp(buf1, buf2, sizeof(buf1)));

    auto rng = QuicheRandom::GetInstance();
    rng->InsecureRandBytes(buf1, sizeof(buf1));
    EXPECT_NE(0, memcmp(buf1, buf2, sizeof(buf1)));
}

TEST(QuicheRandom, InsecureRandUint64)
{
    auto rng = QuicheRandom::GetInstance();
    uint64_t value1 = rng->InsecureRandUint64();
    uint64_t value2 = rng->InsecureRandUint64();
    EXPECT_NE(value1, value2);
}

} // namespace
} // namespace quiche
