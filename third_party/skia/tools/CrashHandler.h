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

#ifndef CrashHandler_DEFINED
#define CrashHandler_DEFINED

// If possible (and not already done), and SK_CRASH_HANDLER is defined,
// register a handler for a stack trace when we crash.
//
// Currently this works on Linux and Mac and Windows.
// On Linux, our output is garbage compared to catchsegv.  Use catchsegv if possible.
void SetupCrashHandler();

#endif // CrashHandler_DEFINED
