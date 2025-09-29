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

#include "tests/Test.h"

DEF_TEST(memory_calloc, reporter)
{
    const size_t kNum = 200;
    char* zeros = (char*)sk_calloc_throw(kNum * sizeof(char));

    for (size_t i = 0; i < kNum; i++) {
        REPORTER_ASSERT(reporter, 0 == zeros[i]);
    }
    sk_free(zeros);
}
