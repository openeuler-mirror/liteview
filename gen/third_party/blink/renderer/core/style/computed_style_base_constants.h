// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/style/templates/computed_style_base_constants.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_group_config.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/css_properties_ranking.json5
//   ../../third_party/blink/renderer/core/css/css_value_keywords.json5
//   ../../third_party/blink/renderer/core/style/computed_style_diff_functions.json5
//   ../../third_party/blink/renderer/core/style/computed_style_extra_fields.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_CONSTANTS_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_CONSTANTS_H_

namespace blink {

// TODO(sashab): Move these enums to their own namespace, or add a CSS prefix,
// for consistency and to prevent name conflicts.

enum class EAlignmentBaseline : unsigned {
    kBaseline,
    kMiddle,
    kAuto,
    kAlphabetic,
    kBeforeEdge,
    kAfterEdge,
    kCentral,
    kTextBeforeEdge,
    kTextAfterEdge,
    kIdeographic,
    kHanging,
    kMathematical,
};

enum class EBackfaceVisibility : unsigned {
    kHidden,
    kVisible,
};

enum class EBorderCollapse : unsigned {
    kCollapse,
    kSeparate,
};

enum class EBorderStyle : unsigned {
    kNone,
    kHidden,
    kInset,
    kGroove,
    kOutset,
    kRidge,
    kDotted,
    kDashed,
    kSolid,
    kDouble,
};

enum class EBoxAlignment : unsigned {
    kBaseline,
    kCenter,
    kStretch,
    kStart,
    kEnd,
};

enum class EBoxDecorationBreak : unsigned {
    kClone,
    kSlice,
};

enum class EBoxDirection : unsigned {
    kNormal,
    kReverse,
};

enum class EBoxOrient : unsigned {
    kHorizontal,
    kVertical,
};

enum class EBoxPack : unsigned {
    kCenter,
    kJustify,
    kStart,
    kEnd,
};

enum class EBoxSizing : unsigned {
    kBorderBox,
    kContentBox,
};

enum class EBreakBetween : unsigned {
    kLeft,
    kRight,
    kAuto,
    kAvoid,
    kColumn,
    kAvoidPage,
    kPage,
    kRecto,
    kVerso,
    kAvoidColumn,
};

enum class EBreakInside : unsigned {
    kAuto,
    kAvoid,
    kAvoidPage,
    kAvoidColumn,
};

enum class EBufferedRendering : unsigned {
    kAuto,
    kStatic,
    kDynamic,
};

enum class ECaptionSide : unsigned {
    kTop,
    kBottom,
};

enum class EClear : unsigned {
    kNone,
    kLeft,
    kRight,
    kInlineStart,
    kInlineEnd,
    kBoth,
};

enum class EColorInterpolation : unsigned {
    kAuto,
    kSRGB,
    kLinearrgb,
};

enum class EColorRendering : unsigned {
    kAuto,
    kOptimizespeed,
    kOptimizequality,
};

enum class EColumnFill : unsigned {
    kAuto,
    kBalance,
};

enum class EColumnSpan : unsigned {
    kNone,
    kAll,
};

enum class EContentVisibility : unsigned {
    kHidden,
    kAuto,
    kVisible,
};

enum class ECursor : unsigned {
    kNone,
    kCopy,
    kAuto,
    kCrosshair,
    kDefault,
    kPointer,
    kMove,
    kVerticalText,
    kCell,
    kContextMenu,
    kAlias,
    kProgress,
    kNoDrop,
    kNotAllowed,
    kZoomIn,
    kZoomOut,
    kEResize,
    kNeResize,
    kNwResize,
    kNResize,
    kSeResize,
    kSwResize,
    kSResize,
    kWResize,
    kEwResize,
    kNsResize,
    kNeswResize,
    kNwseResize,
    kColResize,
    kRowResize,
    kText,
    kWait,
    kHelp,
    kAllScroll,
    kGrab,
    kGrabbing,
};

enum class EDisplay : unsigned {
    kInline,
    kBlock,
    kListItem,
    kInlineBlock,
    kTable,
    kInlineTable,
    kTableRowGroup,
    kTableHeaderGroup,
    kTableFooterGroup,
    kTableRow,
    kTableColumnGroup,
    kTableColumn,
    kTableCell,
    kTableCaption,
    kWebkitBox,
    kWebkitInlineBox,
    kFlex,
    kInlineFlex,
    kGrid,
    kInlineGrid,
    kContents,
    kFlowRoot,
    kNone,
    kLayoutCustom,
    kInlineLayoutCustom,
    kMath,
    kBlockMath,
};

enum class EDominantBaseline : unsigned {
    kMiddle,
    kAuto,
    kAlphabetic,
    kCentral,
    kTextBeforeEdge,
    kTextAfterEdge,
    kIdeographic,
    kHanging,
    kMathematical,
    kUseScript,
    kNoChange,
    kResetSize,
};

enum class EDraggableRegionMode : unsigned {
    kNone,
    kDrag,
    kNoDrag,
};

enum class EEmptyCells : unsigned {
    kHide,
    kShow,
};

enum class EFlexDirection : unsigned {
    kRow,
    kRowReverse,
    kColumn,
    kColumnReverse,
};

enum class EFlexWrap : unsigned {
    kNowrap,
    kWrap,
    kWrapReverse,
};

enum class EFloat : unsigned {
    kNone,
    kLeft,
    kRight,
    kInlineStart,
    kInlineEnd,
};

enum class EForcedColorAdjust : unsigned {
    kNone,
    kAuto,
    kPreserveParentColor,
};

enum class EImageRendering : unsigned {
    kAuto,
    kOptimizespeed,
    kOptimizequality,
    kPixelated,
    kWebkitOptimizeContrast,
};

enum class EInsideLink : unsigned {
    kNotInsideLink,
    kInsideUnvisitedLink,
    kInsideVisitedLink,
};

enum class EIsolation : unsigned {
    kAuto,
    kIsolate,
};

enum class EListStylePosition : unsigned {
    kOutside,
    kInside,
};

enum class EMaskType : unsigned {
    kAlpha,
    kLuminance,
};

enum class EMathShift : unsigned {
    kNormal,
    kCompact,
};

enum class EMathStyle : unsigned {
    kNormal,
    kCompact,
};

enum class EObjectFit : unsigned {
    kNone,
    kContain,
    kCover,
    kFill,
    kScaleDown,
};

enum class EOrder : unsigned {
    kLogical,
    kVisual,
};

enum class EOriginTrialTestProperty : unsigned {
    kNone,
    kNormal,
};

enum class EOverflow : unsigned {
    kHidden,
    kAuto,
    kVisible,
    kOverlay,
    kScroll,
    kClip,
};

enum class EOverflowAnchor : unsigned {
    kNone,
    kAuto,
    kVisible,
};

enum class EOverflowWrap : unsigned {
    kNormal,
    kBreakWord,
    kAnywhere,
};

enum class EOverscrollBehavior : unsigned {
    kNone,
    kAuto,
    kContain,
};

enum class EPointerEvents : unsigned {
    kNone,
    kAll,
    kAuto,
    kVisible,
    kVisiblepainted,
    kVisiblefill,
    kVisiblestroke,
    kPainted,
    kFill,
    kStroke,
    kBoundingBox,
};

enum class EPosition : unsigned {
    kAbsolute,
    kFixed,
    kRelative,
    kStatic,
    kSticky,
};

enum class EPrintColorAdjust : unsigned {
    kEconomy,
    kExact,
};

enum class EResize : unsigned {
    kNone,
    kInline,
    kBlock,
    kBoth,
    kHorizontal,
    kVertical,
};

enum class EScrollSnapStop : unsigned {
    kNormal,
    kAlways,
};

enum class EScrollbarWidth : unsigned {
    kNone,
    kAuto,
    kThin,
};

enum class EShapeRendering : unsigned {
    kAuto,
    kOptimizespeed,
    kGeometricprecision,
    kCrispedges,
};

enum class ESpeak : unsigned {
    kNone,
    kNormal,
    kSpellOut,
    kDigits,
    kLiteralPunctuation,
    kNoPunctuation,
};

enum class ETableLayout : unsigned {
    kAuto,
    kFixed,
};

enum class ETextAlign : unsigned {
    kLeft,
    kRight,
    kCenter,
    kJustify,
    kWebkitLeft,
    kWebkitRight,
    kWebkitCenter,
    kStart,
    kEnd,
};

enum class ETextAlignLast : unsigned {
    kLeft,
    kRight,
    kCenter,
    kJustify,
    kAuto,
    kStart,
    kEnd,
};

enum class ETextAnchor : unsigned {
    kMiddle,
    kStart,
    kEnd,
};

enum class ETextCombine : unsigned {
    kNone,
    kAll,
};

enum class ETextDecorationSkipInk : unsigned {
    kNone,
    kAuto,
};

enum class ETextDecorationStyle : unsigned {
    kDotted,
    kDashed,
    kSolid,
    kDouble,
    kWavy,
};

enum class ETextOrientation : unsigned {
    kMixed,
    kSideways,
    kUpright,
};

enum class ETextOverflow : unsigned {
    kClip,
    kEllipsis,
};

enum class ETextSecurity : unsigned {
    kNone,
    kDisc,
    kCircle,
    kSquare,
};

enum class ETextTransform : unsigned {
    kNone,
    kCapitalize,
    kUppercase,
    kLowercase,
    kMathAuto,
};

enum class ETransformBox : unsigned {
    kFillBox,
    kViewBox,
};

enum class ETransformStyle3D : unsigned {
    kFlat,
    kPreserve3d,
};

enum class EUserDrag : unsigned {
    kNone,
    kAuto,
    kElement,
};

enum class EUserModify : unsigned {
    kReadOnly,
    kReadWrite,
    kReadWritePlaintextOnly,
};

enum class EUserSelect : unsigned {
    kNone,
    kAll,
    kAuto,
    kText,
};

enum class EVectorEffect : unsigned {
    kNone,
    kNonScalingStroke,
};

enum class EVisibility : unsigned {
    kHidden,
    kVisible,
    kCollapse,
};

enum class EWhiteSpace : unsigned {
    kNormal = 1,
    kPre = 2,
    kPreWrap = 4,
    kPreLine = 8,
    kNowrap = 16,
    kWebkitNowrap = 32,
    kBreakSpaces = 64,
};

static const int kEWhiteSpaceBits = 7;

inline EWhiteSpace operator|(EWhiteSpace a, EWhiteSpace b) { return static_cast<EWhiteSpace>(static_cast<unsigned>(a) | static_cast<unsigned>(b)); }
inline EWhiteSpace& operator|=(EWhiteSpace& a, EWhiteSpace b) { return a = a | b; }

inline EWhiteSpace operator^(EWhiteSpace a, EWhiteSpace b) { return static_cast<EWhiteSpace>(static_cast<unsigned>(a) ^ static_cast<unsigned>(b)); }
inline EWhiteSpace& operator^=(EWhiteSpace& a, EWhiteSpace b) { return a = a ^ b; }

inline EWhiteSpace operator&(EWhiteSpace a, EWhiteSpace b) { return static_cast<EWhiteSpace>(static_cast<unsigned>(a) & static_cast<unsigned>(b)); }
inline EWhiteSpace& operator&=(EWhiteSpace& a, EWhiteSpace b) { return a = a & b; }

inline EWhiteSpace operator~(EWhiteSpace x) { return static_cast<EWhiteSpace>(~static_cast<unsigned>(x)); }

enum class EWordBreak : unsigned {
    kNormal,
    kBreakAll,
    kKeepAll,
    kBreakWord,
};

enum class Hyphens : unsigned {
    kNone,
    kAuto,
    kManual,
};

enum class LineBreak : unsigned {
    kNormal,
    kAuto,
    kLoose,
    kStrict,
    kAfterWhiteSpace,
    kAnywhere,
};

enum class RubyPosition : unsigned {
    kAfter,
    kBefore,
};

enum class TextDecorationLine : unsigned {
    kNone = 0,
    kUnderline = 1,
    kOverline = 2,
    kLineThrough = 4,
    kBlink = 8,
    kSpellingError = 16,
    kGrammarError = 32,
};

static const int kTextDecorationLineBits = 6;

inline TextDecorationLine operator|(TextDecorationLine a, TextDecorationLine b) { return static_cast<TextDecorationLine>(static_cast<unsigned>(a) | static_cast<unsigned>(b)); }
inline TextDecorationLine& operator|=(TextDecorationLine& a, TextDecorationLine b) { return a = a | b; }

inline TextDecorationLine operator^(TextDecorationLine a, TextDecorationLine b) { return static_cast<TextDecorationLine>(static_cast<unsigned>(a) ^ static_cast<unsigned>(b)); }
inline TextDecorationLine& operator^=(TextDecorationLine& a, TextDecorationLine b) { return a = a ^ b; }

inline TextDecorationLine operator&(TextDecorationLine a, TextDecorationLine b) { return static_cast<TextDecorationLine>(static_cast<unsigned>(a) & static_cast<unsigned>(b)); }
inline TextDecorationLine& operator&=(TextDecorationLine& a, TextDecorationLine b) { return a = a & b; }

inline TextDecorationLine operator~(TextDecorationLine x) { return static_cast<TextDecorationLine>(~static_cast<unsigned>(x)); }

enum class TextEmphasisFill : unsigned {
    kFilled,
    kOpen,
};

enum class TextEmphasisMark : unsigned {
    kNone,
    kAuto,
    kDot,
    kCircle,
    kDoubleCircle,
    kTriangle,
    kSesame,
    kCustom,
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_CONSTANTS_H_
