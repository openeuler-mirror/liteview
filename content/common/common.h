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

#ifdef _WIN32
#include "base/win/scoped_gdi_object.h"
#endif

class SkBitmap;

namespace gfx {
class Point;
}

namespace content {

void printFuncName(const char* name, bool needPrint, bool needBreak);

#ifdef _WIN32
base::win::ScopedHICON IconUtil_CreateCursorFromSkBitmap(
    const SkBitmap& bitmap,
    const gfx::Point& hotspot);
#endif

}