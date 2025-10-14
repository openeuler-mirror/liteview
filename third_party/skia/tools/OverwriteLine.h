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

#ifndef OverwriteLine_DEFINED
#define OverwriteLine_DEFINED

// Print this string to reset and clear your current terminal line.
static const char* kSkOverwriteLine =
#ifdef SK_BUILD_FOR_WIN
    "\r                                                                               \r"
#elif defined(SK_BUILD_FOR_IOS)
    "\r"
#else
    "\r\033[K"
#endif
    ;

#endif // OverwriteLine_DEFINED
