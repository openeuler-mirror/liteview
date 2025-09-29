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

// © 2019 and later: Unicode, Inc. and others.
// License & terms of use: http://www.unicode.org/copyright.html

#ifndef I18N_ICU_FUZZ_LOCALE_UTIL_H_
#define I18N_ICU_FUZZ_LOCALE_UTIL_H_

#include <string>

// Takes uint8_t data from fuzzer, and makes a zero terminated string.
std::string MakeZeroTerminatedInput(const uint8_t* data, int32_t size);

#endif // I18N_ICU_FUZZ_LOCALE_UTIL_H_
