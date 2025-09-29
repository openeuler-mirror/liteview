// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "skia/ext/fontmgr_default.h"

#include "third_party/skia/include/core/SkFontMgr.h"
#include "third_party/skia/include/ports/SkFontConfigInterface.h"
#include "third_party/skia/include/ports/SkFontMgr_FontConfigInterface.h"
#include "third_party/skia/include/ports/SkFontMgr_directory.h"

namespace skia {

SK_API sk_sp<SkFontMgr> CreateDefaultSkFontMgr()
{
//     sk_sp<SkFontConfigInterface> fci(SkFontConfigInterface::RefGlobal());
//     return fci ? SkFontMgr_New_FCI(std::move(fci)) : nullptr;

    std::string fonts;
#if 0 // if defined(__arm__) || defined(_M_ARM) || defined(__aarch64__)
    // ARM 架构的代码
    fonts = "/usr/share/fonts/open-chinese-fonts";
    fonts += "|";
    fonts += "google-noto-cjk";
#else
    fonts = "/usr/share/fonts";
#endif
    return SkFontMgr_New_Custom_Directory(fonts.c_str());
}

} // namespace skia