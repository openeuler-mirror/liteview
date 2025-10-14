// Copyright 2017 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// vector_icons.cc.template is used to generate vector_icons.cc. Edit the former
// rather than the latter.

#include "ui/message_center/vector_icons.h"

#include "components/vector_icons/cc_macros.h"
#include "ui/gfx/vector_icon_types.h"

#define DECLARE_VECTOR_COMMAND(x) using gfx::x;
DECLARE_VECTOR_COMMANDS

namespace message_center {

VECTOR_ICON_REP_TEMPLATE(kNotificationCloseButtonPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 20, 5.73f, LINE_TO, 18.27f, 4, LINE_TO, 12, 10.27f, LINE_TO, 5.73f, 4, LINE_TO, 4, 5.73f,
    LINE_TO, 10.27f, 12, LINE_TO, 4, 18.27f, LINE_TO, 5.73f, 20, LINE_TO, 12, 13.73f, LINE_TO, 18.27f, 20, LINE_TO, 20, 18.27f, LINE_TO, 13.73f, 12, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kNotificationCloseButton12Path, CANVAS_DIMENSIONS, 12, MOVE_TO, 10.5f, 2.36f, LINE_TO, 9.64f, 1.5f, LINE_TO, 6, 5.14f, LINE_TO, 2.36f, 1.5f, LINE_TO, 1.5f,
    2.36f, LINE_TO, 5.14f, 6, LINE_TO, 1.5f, 9.64f, LINE_TO, 2.36f, 10.5f, LINE_TO, 6, 6.86f, LINE_TO, 9.64f, 10.5f, LINE_TO, 10.5f, 9.64f, LINE_TO, 6.86f, 6, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotificationCloseButtonRepList, kNotificationCloseButtonIcon, { kNotificationCloseButtonPath, std::size(kNotificationCloseButtonPath) },
    { kNotificationCloseButton12Path, std::size(kNotificationCloseButton12Path) })
VECTOR_ICON_REP_TEMPLATE(kNotificationExpandLessPath, CANVAS_DIMENSIONS, 16, MOVE_TO, 2.62f, 13, LINE_TO, 8, 7.75f, LINE_TO, 13.33f, 13, LINE_TO, 15, 11.31f, R_LINE_TO, -7, -6.89f,
    R_LINE_TO, -7, 6.89f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotificationExpandLessRepList, kNotificationExpandLessIcon, { kNotificationExpandLessPath, std::size(kNotificationExpandLessPath) })
VECTOR_ICON_REP_TEMPLATE(kNotificationExpandMorePath, CANVAS_DIMENSIONS, 16, MOVE_TO, 2.62f, 3, LINE_TO, 8, 8.25f, LINE_TO, 13.33f, 3, LINE_TO, 15, 4.69f, R_LINE_TO, -7, 6.89f,
    R_LINE_TO, -7, -6.89f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotificationExpandMoreRepList, kNotificationExpandMoreIcon, { kNotificationExpandMorePath, std::size(kNotificationExpandMorePath) })
VECTOR_ICON_REP_TEMPLATE(kNotificationInlineReplyPath, CANVAS_DIMENSIONS, 96, MOVE_TO, 10.04f, 82, LINE_TO, 86, 48, LINE_TO, 10.04f, 14, LINE_TO, 10, 40.44f, LINE_TO, 64.29f, 48,
    LINE_TO, 10, 55.56f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotificationInlineReplyRepList, kNotificationInlineReplyIcon, { kNotificationInlineReplyPath, std::size(kNotificationInlineReplyPath) })
VECTOR_ICON_REP_TEMPLATE(kNotificationSettingsButtonPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 19.63f, 12.98f, CUBIC_TO, 19.68f, 12.66f, 19.71f, 12.33f, 19.71f, 12, CUBIC_TO, 19.71f,
    11.67f, 19.68f, 11.35f, 19.63f, 11.03f, LINE_TO, 21.81f, 9.37f, CUBIC_TO, 22, 9.22f, 22.06f, 8.95f, 21.93f, 8.73f, LINE_TO, 19.88f, 5.27f, CUBIC_TO, 19.75f, 5.05f, 19.48f,
    4.96f, 19.25f, 5.05f, LINE_TO, 16.69f, 6.06f, CUBIC_TO, 16.16f, 5.66f, 15.58f, 5.33f, 14.95f, 5.07f, LINE_TO, 14.57f, 2.42f, CUBIC_TO, 14.52f, 2.19f, 14.31f, 2, 14.05f, 2,
    LINE_TO, 9.94f, 2, CUBIC_TO, 9.68f, 2, 9.47f, 2.19f, 9.43f, 2.42f, LINE_TO, 9.05f, 5.07f, CUBIC_TO, 8.42f, 5.33f, 7.84f, 5.66f, 7.31f, 6.06f, LINE_TO, 4.75f, 5.05f, CUBIC_TO,
    4.52f, 4.97f, 4.25f, 5.05f, 4.12f, 5.27f, LINE_TO, 2.07f, 8.73f, CUBIC_TO, 1.94f, 8.95f, 2, 9.22f, 2.19f, 9.37f, LINE_TO, 4.36f, 11.03f, CUBIC_TO, 4.32f, 11.35f, 4.29f, 11.67f,
    4.29f, 12, CUBIC_TO, 4.29f, 12.33f, 4.32f, 12.66f, 4.36f, 12.98f, LINE_TO, 2.19f, 14.63f, CUBIC_TO, 2, 14.78f, 1.94f, 15.05f, 2.07f, 15.27f, LINE_TO, 4.12f, 18.74f, CUBIC_TO,
    4.25f, 18.95f, 4.52f, 19.04f, 4.75f, 18.95f, LINE_TO, 7.31f, 17.95f, CUBIC_TO, 7.84f, 18.34f, 8.42f, 18.68f, 9.05f, 18.93f, LINE_TO, 9.43f, 21.58f, CUBIC_TO, 9.47f, 21.82f,
    9.68f, 22, 9.94f, 22, LINE_TO, 14.05f, 22, CUBIC_TO, 14.31f, 22, 14.52f, 21.82f, 14.56f, 21.58f, LINE_TO, 14.95f, 18.93f, CUBIC_TO, 15.57f, 18.68f, 16.15f, 18.35f, 16.68f,
    17.95f, LINE_TO, 19.24f, 18.95f, CUBIC_TO, 19.47f, 19.04f, 19.74f, 18.95f, 19.87f, 18.74f, LINE_TO, 21.93f, 15.27f, CUBIC_TO, 22.05f, 15.06f, 22, 14.79f, 21.8f, 14.63f,
    LINE_TO, 19.63f, 12.98f, LINE_TO, 19.63f, 12.98f, CLOSE, MOVE_TO, 12, 15, CUBIC_TO, 10.34f, 15, 9, 13.66f, 9, 12, CUBIC_TO, 9, 10.34f, 10.34f, 9, 12, 9, CUBIC_TO, 13.66f, 9,
    15, 10.34f, 15, 12, CUBIC_TO, 15, 13.66f, 13.66f, 15, 12, 15, LINE_TO, 12, 15, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kNotificationSettingsButton12Path, CANVAS_DIMENSIONS, 12, MOVE_TO, 9.82f, 6.49f, CUBIC_TO, 9.84f, 6.33f, 9.85f, 6.17f, 9.85f, 6, CUBIC_TO, 9.85f, 5.84f,
    9.84f, 5.67f, 9.82f, 5.51f, LINE_TO, 10.9f, 4.68f, CUBIC_TO, 11, 4.61f, 11.03f, 4.47f, 10.97f, 4.37f, LINE_TO, 9.94f, 2.63f, CUBIC_TO, 9.87f, 2.53f, 9.74f, 2.48f, 9.62f, 2.53f,
    LINE_TO, 8.34f, 3.03f, CUBIC_TO, 8.08f, 2.83f, 7.79f, 2.66f, 7.48f, 2.54f, LINE_TO, 7.28f, 1.21f, CUBIC_TO, 7.26f, 1.09f, 7.15f, 1, 7.03f, 1, LINE_TO, 4.97f, 1, CUBIC_TO,
    4.84f, 1, 4.74f, 1.09f, 4.72f, 1.21f, LINE_TO, 4.52f, 2.54f, CUBIC_TO, 4.21f, 2.66f, 3.92f, 2.83f, 3.66f, 3.03f, LINE_TO, 2.38f, 2.53f, CUBIC_TO, 2.26f, 2.48f, 2.13f, 2.53f,
    2.06f, 2.63f, LINE_TO, 1.03f, 4.37f, CUBIC_TO, 0.97f, 4.47f, 1, 4.61f, 1.1f, 4.68f, LINE_TO, 2.18f, 5.51f, CUBIC_TO, 2.16f, 5.67f, 2.14f, 5.84f, 2.14f, 6, CUBIC_TO, 2.14f,
    6.17f, 2.16f, 6.33f, 2.18f, 6.49f, LINE_TO, 1.1f, 7.32f, CUBIC_TO, 1, 7.39f, 0.97f, 7.53f, 1.03f, 7.64f, LINE_TO, 2.06f, 9.37f, CUBIC_TO, 2.13f, 9.48f, 2.26f, 9.52f, 2.38f,
    9.48f, LINE_TO, 3.66f, 8.97f, CUBIC_TO, 3.92f, 9.17f, 4.21f, 9.34f, 4.52f, 9.47f, LINE_TO, 4.72f, 10.79f, CUBIC_TO, 4.74f, 10.91f, 4.84f, 11, 4.97f, 11, LINE_TO, 7.03f, 11,
    CUBIC_TO, 7.15f, 11, 7.26f, 10.91f, 7.28f, 10.79f, LINE_TO, 7.47f, 9.47f, CUBIC_TO, 7.79f, 9.34f, 8.08f, 9.17f, 8.34f, 8.97f, LINE_TO, 9.62f, 9.48f, CUBIC_TO, 9.74f, 9.52f,
    9.87f, 9.48f, 9.94f, 9.37f, LINE_TO, 10.96f, 7.64f, CUBIC_TO, 11.03f, 7.53f, 11, 7.39f, 10.9f, 7.32f, LINE_TO, 9.82f, 6.49f, LINE_TO, 9.82f, 6.49f, CLOSE, MOVE_TO, 6, 7.5f,
    CUBIC_TO, 5.17f, 7.5f, 4.5f, 6.83f, 4.5f, 6, CUBIC_TO, 4.5f, 5.17f, 5.17f, 4.5f, 6, 4.5f, CUBIC_TO, 6.83f, 4.5f, 7.5f, 5.17f, 7.5f, 6, CUBIC_TO, 7.5f, 6.83f, 6.83f, 7.5f, 6,
    7.5f, LINE_TO, 6, 7.5f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotificationSettingsButtonRepList, kNotificationSettingsButtonIcon, { kNotificationSettingsButtonPath, std::size(kNotificationSettingsButtonPath) },
    { kNotificationSettingsButton12Path, std::size(kNotificationSettingsButton12Path) })
VECTOR_ICON_REP_TEMPLATE(kNotificationSnoozeButtonPath, CANVAS_DIMENSIONS, 24, MOVE_TO, 12, 2, ARC_TO, 10, 10, 0, 1, 0, 12, 22, ARC_TO, 10, 10, 0, 0, 0, 12, 2, CLOSE, MOVE_TO, 12,
    20, R_ARC_TO, 8, 8, 0, 1, 1, 0, -16, R_ARC_TO, 8, 8, 0, 0, 1, 0, 16, CLOSE, MOVE_TO, 12.5f, 7, H_LINE_TO, 11, R_V_LINE_TO, 6, R_LINE_TO, 5.25f, 3.15f, R_LINE_TO, 0.75f, -1.23f,
    R_LINE_TO, -4.5f, -2.67f, CLOSE)
VECTOR_ICON_REP_TEMPLATE(kNotificationSnoozeButton12Path, CANVAS_DIMENSIONS, 12, MOVE_TO, 6, 1, R_ARC_TO, 5, 5, 0, 0, 0, -5, 5, R_ARC_TO, 5, 5, 0, 0, 0, 5, 5, R_ARC_TO, 5, 5, 0, 0,
    0, 5, -5, R_ARC_TO, 5, 5, 0, 0, 0, -5, -5, CLOSE, R_MOVE_TO, 0, 9, R_ARC_TO, 4, 4, 0, 1, 1, 0, -8, R_ARC_TO, 4, 4, 0, 0, 1, 0, 8, CLOSE, MOVE_TO, 6.25f, 3.5f, H_LINE_TO, 5.5f,
    R_V_LINE_TO, 3, R_LINE_TO, 2.63f, 1.57f, R_LINE_TO, 0.37f, -0.61f, R_LINE_TO, -2.25f, -1.34f, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kNotificationSnoozeButtonRepList, kNotificationSnoozeButtonIcon, { kNotificationSnoozeButtonPath, std::size(kNotificationSnoozeButtonPath) },
    { kNotificationSnoozeButton12Path, std::size(kNotificationSnoozeButton12Path) })
VECTOR_ICON_REP_TEMPLATE(kProductPath, CANVAS_DIMENSIONS, 96, MOVE_TO, 84.25f, 30.5f, CUBIC_TO, 77.85f, 17.3f, 63.6f, 8, 48, 8, R_CUBIC_TO, -12.4f, 0, -23.6f, 5.6f, -30.8f, 14.4f,
    R_LINE_TO, 13.2f, 22.8f, R_CUBIC_TO, 1.2f, -8.4f, 8.8f, -14.7f, 17.6f, -14.7f, R_H_LINE_TO, 36.25f, CLOSE, MOVE_TO, 48, 66, R_CUBIC_TO, -6.8f, 0, -12.4f, -3.6f, -15.6f, -9.2f,
    LINE_TO, 14.4f, 26, CUBIC_TO, 10.4f, 32.4f, 8, 40, 8, 48, R_CUBIC_TO, 0, 20, 14.4f, 36.4f, 33.6f, 39.6f, R_LINE_TO, 13.2f, -22.8f, R_CUBIC_TO, -2.4f, 0.8f, -4.4f, 1.2f, -6.8f,
    1.2f, CLOSE, R_MOVE_TO, 18, -18, R_CUBIC_TO, 0, -5.6f, -4, -11.8f, -8, -15, R_H_LINE_TO, 27.5f, R_CUBIC_TO, 1.6f, 4.4f, 2.5f, 10.2f, 2.5f, 15, R_CUBIC_TO, 0, 22, -18, 40, -40,
    40, R_H_LINE_TO, -2.4f, R_LINE_TO, 18, -31.2f, R_CUBIC_TO, 1.6f, -2.4f, 2.4f, -5.6f, 2.4f, -8.8f, CLOSE, MOVE_TO, 48, 62, R_CUBIC_TO, -7.73f, 0, -14, -6.27f, -14, -14,
    R_CUBIC_TO, 0, -7.73f, 6.27f, -14, 14, -14, R_CUBIC_TO, 7.73f, 0, 14, 6.27f, 14, 14, R_CUBIC_TO, 0, 7.73f, -6.27f, 14, -14, 14, CLOSE)
VECTOR_ICON_TEMPLATE_CC(kProductRepList, kProductIcon, { kProductPath, std::size(kProductPath) })

}
