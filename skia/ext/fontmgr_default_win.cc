// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "skia/ext/fontmgr_default.h"

#include "third_party/skia/include/core/SkFontMgr.h"
#include "third_party/skia/include/ports/SkTypeface_win.h"

namespace skia {

SK_API sk_sp<SkFontMgr> CreateDefaultSkFontMgr()
{
#ifdef SUPPORT_XP_CODE
    return SkFontMgr_New_GDI();
#else
    return SkFontMgr_New_DirectWrite();
#endif // SUPPORT_XP_CODE
}

} // namespace skia
