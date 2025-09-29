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

// Written in 2017 by Henrik Steffen Gaßmann henrik@gassmann.onl
//
// To the extent possible under law, the author(s) have dedicated all
// copyright and related and neighboring rights to this software to the
// public domain worldwide. This software is distributed without any warranty.
//
// You should have received a copy of the CC0 Public Domain Dedication
// along with this software. If not, see
//
//     http://creativecommons.org/publicdomain/zero/1.0/
//
////////////////////////////////////////////////////////////////////////////////

// ARM 64-Bit
#if defined(__aarch64__)
#error##arch=arm64##

// ARM 32-Bit
#elif defined(__arm__) || defined(_M_ARM)
#error##arch=arm##

// x86 64-Bit
#elif defined(__x86_64__) || defined(_M_X64)
#error##arch=x64##

// x86 32-Bit
#elif defined(__i386__) || defined(_M_IX86)
#error##arch=x86##

#else
#error##arch=unknown##
#endif
