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


#include "content/common/StringConversions.h"
#include "base/strings/utf_string_conversions.h"
#include "third_party/blink/public/platform/file_path_conversion.h"
#include <windows.h>

namespace content {

base::FilePath stringToFilePath(const WTF::String& str)
{
// #if defined(OS_WIN)
//     //std::u16string strW = base::UTF8ToUTF16(base::StringPiece(str.Utf8().c_str()));
//     return base::FilePath::FromUTF8Unsafe(str.Utf8().c_str());
// #else
//     return base::FilePath::FromUTF8Unsafe(str.Utf8().c_str());
// #endif
    return blink::StringToFilePath(str);
}

}

