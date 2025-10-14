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

// © 2020 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html#License

#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING

#include "intltest.h"
#include "unicode/unistr.h"
#include "units_router.h"

class UnitsRouterTest : public IntlTest {
public:
    UnitsRouterTest()
    {
    }

    void runIndexedTest(int32_t index, UBool exec, const char*& name, char* par = NULL) override;

    void testBasic();
};

extern IntlTest* createUnitsRouterTest()
{
    return new UnitsRouterTest();
}

void UnitsRouterTest::runIndexedTest(int32_t index, UBool exec, const char*& name, char* /*par*/)
{
    if (exec) {
        logln("TestSuite UnitsRouterTest: ");
    }
    TESTCASE_AUTO_BEGIN;
    TESTCASE_AUTO(testBasic);
    TESTCASE_AUTO_END;
}

void UnitsRouterTest::testBasic()
{
    IcuTestErrorCode status(*this, "UnitsRouter testBasic");
}

#endif /* #if !UCONFIG_NO_FORMATTING */
