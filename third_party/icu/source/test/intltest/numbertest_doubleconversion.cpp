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

// © 2017 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html

#include "unicode/utypes.h"

#if !UCONFIG_NO_FORMATTING

#include "numbertest.h"
#include "double-conversion.h"

using namespace double_conversion;

void DoubleConversionTest::runIndexedTest(int32_t index, UBool exec, const char*& name, char*)
{
    if (exec) {
        logln("TestSuite DoubleConversionTest: ");
    }
    TESTCASE_AUTO_BEGIN;
    TESTCASE_AUTO(testDoubleConversionApi);
    TESTCASE_AUTO_END;
}

void DoubleConversionTest::testDoubleConversionApi()
{
    double v = 87.65;
    char buffer[DoubleToStringConverter::kBase10MaximalLength + 1];
    bool sign;
    int32_t length;
    int32_t point;

    DoubleToStringConverter::DoubleToAscii(v, DoubleToStringConverter::DtoaMode::SHORTEST, 0, buffer, sizeof(buffer), &sign, &length, &point);

    UnicodeString result(buffer, length);
    assertEquals("Digits", u"8765", result);
    assertEquals("Scale", 2, point);
}

#endif /* #if !UCONFIG_NO_FORMATTING */
