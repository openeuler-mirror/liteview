// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// vector_icons.h.template is used to generate vector_icons.h. Edit the former
// rather than the latter.

#ifndef UI_VIEWS_VECTOR_ICONS_H_
#define UI_VIEWS_VECTOR_ICONS_H_

#include "ui/views/views_export.h"

namespace gfx {
struct VectorIcon;
}

#define VECTOR_ICON_TEMPLATE_H(icon_name) VIEWS_EXPORT extern const gfx::VectorIcon icon_name;

namespace views {

VECTOR_ICON_TEMPLATE_H(kCheckboxActiveIcon)
VECTOR_ICON_TEMPLATE_H(kCheckboxNormalIcon)
VECTOR_ICON_TEMPLATE_H(kCloseIcon)
VECTOR_ICON_TEMPLATE_H(kDragGeneralSelectionIcon)
VECTOR_ICON_TEMPLATE_H(kDragImageSelectionIcon)
VECTOR_ICON_TEMPLATE_H(kIcCloseIcon)
VECTOR_ICON_TEMPLATE_H(kInfoIcon)
VECTOR_ICON_TEMPLATE_H(kLaunchIcon)
VECTOR_ICON_TEMPLATE_H(kLinuxHighDensityIcon)
VECTOR_ICON_TEMPLATE_H(kLinuxLowDensityIcon)
VECTOR_ICON_TEMPLATE_H(kMenuCheckIcon)
VECTOR_ICON_TEMPLATE_H(kMenuDropArrowIcon)
VECTOR_ICON_TEMPLATE_H(kMenuRadioEmptyIcon)
VECTOR_ICON_TEMPLATE_H(kMenuRadioSelectedIcon)
VECTOR_ICON_TEMPLATE_H(kNewIncognitoWindowIcon)
VECTOR_ICON_TEMPLATE_H(kNewTabIcon)
VECTOR_ICON_TEMPLATE_H(kNewWindowIcon)
VECTOR_ICON_TEMPLATE_H(kOpenIcon)
VECTOR_ICON_TEMPLATE_H(kOptionsIcon)
VECTOR_ICON_TEMPLATE_H(kPinIcon)
VECTOR_ICON_TEMPLATE_H(kRadioButtonActiveIcon)
VECTOR_ICON_TEMPLATE_H(kRadioButtonNormalIcon)
VECTOR_ICON_TEMPLATE_H(kUninstallIcon)
VECTOR_ICON_TEMPLATE_H(kUnpinIcon)

}

#undef VECTOR_ICON_TEMPLATE_H

#endif // UI_VIEWS_VECTOR_ICONS_H_
