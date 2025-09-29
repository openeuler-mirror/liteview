// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/style/templates/computed_style_base.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_group_config.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/css_properties_ranking.json5
//   ../../third_party/blink/renderer/core/css/css_value_keywords.json5
//   ../../third_party/blink/renderer/core/style/computed_style_diff_functions.json5
//   ../../third_party/blink/renderer/core/style/computed_style_extra_fields.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5
#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_H_

#include "third_party/blink/renderer/core/core_export.h"
#include "third_party/blink/renderer/core/style/computed_style_constants.h"
#include "third_party/blink/renderer/core/style/data_ref.h"
#include "third_party/blink/renderer/core/style/member_copy.h"
#include "third_party/blink/renderer/core/style/computed_style_initial_values.h"
#include "cc/input/scroll_snap_data.h"
#include "third_party/blink/public/common/css/page_orientation.h"
#include "third_party/blink/public/common/css/page_size_type.h"
#include "third_party/blink/public/mojom/frame/color_scheme.mojom-blink.h"
#include "third_party/blink/public/mojom/scroll/scroll_enums.mojom-blink.h"
#include "third_party/blink/renderer/core/animation/css/css_animation_data.h"
#include "third_party/blink/renderer/core/animation/css/css_transition_data.h"
#include "third_party/blink/renderer/core/css/css_property_names.h"
#include "third_party/blink/renderer/core/css/style_auto_color.h"
#include "third_party/blink/renderer/core/css/style_color.h"
#include "third_party/blink/renderer/core/css_value_keywords.h"
#include "third_party/blink/renderer/core/layout/layout_theme.h"
#include "third_party/blink/renderer/core/scroll/scroll_customization.h"
#include "third_party/blink/renderer/core/style/applied_text_decoration_list.h"
#include "third_party/blink/renderer/core/style/basic_shapes.h"
#include "third_party/blink/renderer/core/style/clip_path_operation.h"
#include "third_party/blink/renderer/core/style/computed_grid_track_list.h"
#include "third_party/blink/renderer/core/style/content_data.h"
#include "third_party/blink/renderer/core/style/counter_directives.h"
#include "third_party/blink/renderer/core/style/cursor_list.h"
#include "third_party/blink/renderer/core/style/fill_layer.h"
#include "third_party/blink/renderer/core/style/grid_area.h"
#include "third_party/blink/renderer/core/style/grid_position.h"
#include "third_party/blink/renderer/core/style/grid_track_list.h"
#include "third_party/blink/renderer/core/style/list_style_type_data.h"
#include "third_party/blink/renderer/core/style/named_grid_lines_map.h"
#include "third_party/blink/renderer/core/style/nine_piece_image.h"
#include "third_party/blink/renderer/core/style/paint_images.h"
#include "third_party/blink/renderer/core/style/shadow_list.h"
#include "third_party/blink/renderer/core/style/shape_value.h"
#include "third_party/blink/renderer/core/style/style_aspect_ratio.h"
#include "third_party/blink/renderer/core/style/style_base_data.h"
#include "third_party/blink/renderer/core/style/style_content_alignment_data.h"
#include "third_party/blink/renderer/core/style/style_filter_data.h"
#include "third_party/blink/renderer/core/style/style_highlight_data.h"
#include "third_party/blink/renderer/core/style/style_hyphenate_limit_chars.h"
#include "third_party/blink/renderer/core/style/style_image.h"
#include "third_party/blink/renderer/core/style/style_inherited_variables.h"
#include "third_party/blink/renderer/core/style/style_initial_data.h"
#include "third_party/blink/renderer/core/style/style_initial_letter.h"
#include "third_party/blink/renderer/core/style/style_intrinsic_length.h"
#include "third_party/blink/renderer/core/style/style_non_inherited_variables.h"
#include "third_party/blink/renderer/core/style/style_offset_rotation.h"
#include "third_party/blink/renderer/core/style/style_overflow_clip_margin.h"
#include "third_party/blink/renderer/core/style/style_path.h"
#include "third_party/blink/renderer/core/style/style_reflection.h"
#include "third_party/blink/renderer/core/style/style_self_alignment_data.h"
#include "third_party/blink/renderer/core/style/style_svg_resource.h"
#include "third_party/blink/renderer/core/style/svg_dash_array.h"
#include "third_party/blink/renderer/core/style/svg_paint.h"
#include "third_party/blink/renderer/core/style/text_decoration_thickness.h"
#include "third_party/blink/renderer/core/style/text_size_adjust.h"
#include "third_party/blink/renderer/core/style/timeline_inset.h"
#include "third_party/blink/renderer/core/style/toggle_group_list.h"
#include "third_party/blink/renderer/core/style/toggle_root_list.h"
#include "third_party/blink/renderer/core/style/toggle_trigger_list.h"
#include "third_party/blink/renderer/core/style/transform_origin.h"
#include "third_party/blink/renderer/core/style/unzoomed_length.h"
#include "third_party/blink/renderer/platform/fonts/font.h"
#include "third_party/blink/renderer/platform/geometry/layout_unit.h"
#include "third_party/blink/renderer/platform/geometry/length.h"
#include "third_party/blink/renderer/platform/geometry/length_box.h"
#include "third_party/blink/renderer/platform/geometry/length_point.h"
#include "third_party/blink/renderer/platform/geometry/length_size.h"
#include "third_party/blink/renderer/platform/graphics/graphics_types.h"
#include "third_party/blink/renderer/platform/graphics/touch_action.h"
#include "third_party/blink/renderer/platform/text/quotes_data.h"
#include "third_party/blink/renderer/platform/text/tab_size.h"
#include "third_party/blink/renderer/platform/text/text_direction.h"
#include "third_party/blink/renderer/platform/text/unicode_bidi.h"
#include "third_party/blink/renderer/platform/text/writing_mode.h"
#include "third_party/blink/renderer/platform/theme_types.h"
#include "third_party/blink/renderer/platform/transforms/rotate_transform_operation.h"
#include "third_party/blink/renderer/platform/transforms/scale_transform_operation.h"
#include "third_party/blink/renderer/platform/transforms/transform_operations.h"
#include "third_party/blink/renderer/platform/transforms/translate_transform_operation.h"
#include "third_party/blink/renderer/platform/wtf/hash_set.h"
#include "third_party/blink/renderer/platform/wtf/text/atomic_string.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "third_party/blink/renderer/platform/wtf/vector.h"
#include "ui/gfx/geometry/size_f.h"
namespace blink {

// Forward declaration for diff functions.
class ComputedStyle;

// The generated portion of ComputedStyle. For more info, see the header comment
// in ComputedStyle.h.
//
// ComputedStyleBase is a generated class that stores data members or 'fields'
// used in ComputedStyle. These fields can represent CSS properties or internal
// style information.
//
// STORAGE:
//
// Fields are organised in a tree structure, where a node (called a 'group')
// stores a set of fields and a set of pointers to child nodes (called
// 'subgroups'). We can visualise the tree structure with ComputedStyleBase as
// the root node:
//
// ComputedStyleBase (fields: display, vertical-align, ...)
//  |- StyleSurroundData (fields: padding, border, ...)
//  |- StyleBoxData (fields: width, height, ...)
//  |- ...
//  |- StyleRareNonInheritedData (fields: box-shadow, text-overflow, ...)
//      |- StyleFlexibleBoxData (fields: flex-direction, flex-wrap, ...)
//      |- ...
//
// This design saves memory by allowing multiple ComputedStyleBases to share the
// same instance of a subgroup. For example, if a page never uses flex box
// properties, then every ComputedStyleBase can share the same instance of
// StyleFlexibleBoxData. Without this sharing, we would need to allocate a copy
// of all the flex box fields for every ComputedStyleBase. Similarly, when an
// element inherits from its parent, its ComputedStyleBase can simply share all
// of its subgroups with the parent's.
//
// INTERFACE:
//
// The functions generated for a field is determined by its 'template'. For
// example, a field with the 'keyword' template has only one setter, whereas an
// 'external' field has an extra setter that takes an rvalue reference. A list
// of the available templates can be found in css_properties.json5.
class ComputedStyleBase {
public:
    inline bool IndependentInheritedEqual(const ComputedStyleBase& o) const
    {
        return ((inherited_data_.Get() == o.inherited_data_.Get() || (inherited_data_->color_ == o.inherited_data_->color_)) && pointer_events_ == o.pointer_events_
            && text_transform_ == o.text_transform_ && visibility_ == o.visibility_ && border_collapse_ == o.border_collapse_ && box_direction_ == o.box_direction_
            && caption_side_ == o.caption_side_ && empty_cells_ == o.empty_cells_ && is_inert_ == o.is_inert_ && list_style_position_ == o.list_style_position_
            && rtl_ordering_ == o.rtl_ordering_

        );
    }

    inline bool NonIndependentInheritedEqual(const ComputedStyleBase& o) const
    {
        return ((inherited_data_.Get() == o.inherited_data_.Get()
                    || (inherited_data_->font_data_ == o.inherited_data_->font_data_ && inherited_data_->line_height_ == o.inherited_data_->line_height_
                        && inherited_data_->text_autosizing_multiplier_ == o.inherited_data_->text_autosizing_multiplier_
                        && inherited_data_->internal_visited_color_ == o.inherited_data_->internal_visited_color_
                        && inherited_data_->horizontal_border_spacing_ == o.inherited_data_->horizontal_border_spacing_
                        && inherited_data_->vertical_border_spacing_ == o.inherited_data_->vertical_border_spacing_
                        && inherited_data_->color_is_current_color_ == o.inherited_data_->color_is_current_color_
                        && inherited_data_->in_forced_colors_mode_ == o.inherited_data_->in_forced_colors_mode_
                        && inherited_data_->internal_visited_color_is_current_color_ == o.inherited_data_->internal_visited_color_is_current_color_))
            && rare_inherited_usage_less_than_64_percent_data_ == o.rare_inherited_usage_less_than_64_percent_data_
            && (svg_data_.Get() == o.svg_data_.Get()
                || (svg_data_->fill_data_ == o.svg_data_->fill_data_ && svg_data_->stroke_data_ == o.svg_data_->stroke_data_
                    && svg_data_->inherited_resources_data_ == o.svg_data_->inherited_resources_data_ && svg_data_->css_dominant_baseline_ == o.svg_data_->css_dominant_baseline_
                    && svg_data_->dominant_baseline_ == o.svg_data_->dominant_baseline_ && svg_data_->paint_order_ == o.svg_data_->paint_order_
                    && svg_data_->color_interpolation_ == o.svg_data_->color_interpolation_ && svg_data_->color_interpolation_filters_ == o.svg_data_->color_interpolation_filters_
                    && svg_data_->color_rendering_ == o.svg_data_->color_rendering_ && svg_data_->shape_rendering_ == o.svg_data_->shape_rendering_
                    && svg_data_->text_anchor_ == o.svg_data_->text_anchor_ && svg_data_->clip_rule_ == o.svg_data_->clip_rule_
                    && svg_data_->fill_rule_ == o.svg_data_->fill_rule_))
            && white_space_ == o.white_space_ && cursor_ == o.cursor_ && text_align_ == o.text_align_ && inside_link_ == o.inside_link_ && writing_mode_ == o.writing_mode_
            && direction_ == o.direction_ && has_simple_underline_ == o.has_simple_underline_
            && inside_fragmentation_context_with_nondeterministic_engine_ == o.inside_fragmentation_context_with_nondeterministic_engine_
            && print_color_adjust_ == o.print_color_adjust_

        );
    }

    inline bool InheritedVariablesEqual(const ComputedStyleBase& o) const
    {
        return ((inherited_data_.Get() == o.inherited_data_.Get() || (base::ValuesEquivalent(inherited_data_->inherited_variables_, o.inherited_data_->inherited_variables_)))

        );
    }

    inline bool InheritedEqual(const ComputedStyleBase& o) const { return IndependentInheritedEqual(o) && NonIndependentInheritedEqual(o); }

    inline bool NonInheritedEqual(const ComputedStyleBase& o) const
    {
        return (visual_data_ == o.visual_data_ && rare_non_inherited_usage_less_than_14_percent_data_ == o.rare_non_inherited_usage_less_than_14_percent_data_
            && (svg_data_.Get() == o.svg_data_.Get()
                || (svg_data_->misc_data_ == o.svg_data_->misc_data_ && svg_data_->geometry_data_ == o.svg_data_->geometry_data_ && svg_data_->stop_data_ == o.svg_data_->stop_data_
                    && base::ValuesEquivalent(svg_data_->masker_resource_, o.svg_data_->masker_resource_) && svg_data_->alignment_baseline_ == o.svg_data_->alignment_baseline_
                    && svg_data_->buffered_rendering_ == o.svg_data_->buffered_rendering_ && svg_data_->mask_type_ == o.svg_data_->mask_type_
                    && svg_data_->vector_effect_ == o.svg_data_->vector_effect_))
            && box_data_ == o.box_data_ && background_data_ == o.background_data_ && surround_data_ == o.surround_data_ && display_ == o.display_
            && original_display_ == o.original_display_ && break_after_ == o.break_after_ && break_before_ == o.break_before_ && scrollbar_gutter_ == o.scrollbar_gutter_
            && break_inside_ == o.break_inside_ && vertical_align_ == o.vertical_align_ && clear_ == o.clear_ && floating_ == o.floating_ && overflow_x_ == o.overflow_x_
            && overflow_y_ == o.overflow_y_ && position_ == o.position_ && unicode_bidi_ == o.unicode_bidi_ && content_visibility_ == o.content_visibility_
            && overflow_anchor_ == o.overflow_anchor_ && overscroll_behavior_x_ == o.overscroll_behavior_x_ && overscroll_behavior_y_ == o.overscroll_behavior_y_
            && viewport_unit_flags_ == o.viewport_unit_flags_ && has_author_background_ == o.has_author_background_ && has_author_border_ == o.has_author_border_
            && has_author_border_radius_ == o.has_author_border_radius_ && has_author_highlight_colors_ == o.has_author_highlight_colors_
            && has_explicit_inheritance_ == o.has_explicit_inheritance_ && origin_trial_test_property_ == o.origin_trial_test_property_ && scroll_snap_stop_ == o.scroll_snap_stop_
            && should_ignore_overflow_property_for_inline_block_baseline_ == o.should_ignore_overflow_property_for_inline_block_baseline_ && skips_contents_ == o.skips_contents_
            && table_layout_ == o.table_layout_ && transform_box_ == o.transform_box_

        );
    }

    inline bool InheritedDataShared(const ComputedStyleBase& o) const
    {
        return (inherited_data_.Get() == o.inherited_data_.Get() && rare_inherited_usage_less_than_64_percent_data_.Get() == o.rare_inherited_usage_less_than_64_percent_data_.Get()
            && (svg_data_.Get() == o.svg_data_.Get()
                || (svg_data_->fill_data_.Get() == o.svg_data_->fill_data_.Get() && svg_data_->stroke_data_.Get() == o.svg_data_->stroke_data_.Get()
                    && svg_data_->inherited_resources_data_.Get() == o.svg_data_->inherited_resources_data_.Get()
                    && svg_data_->css_dominant_baseline_ == o.svg_data_->css_dominant_baseline_ && svg_data_->dominant_baseline_ == o.svg_data_->dominant_baseline_
                    && svg_data_->paint_order_ == o.svg_data_->paint_order_ && svg_data_->color_interpolation_ == o.svg_data_->color_interpolation_
                    && svg_data_->color_interpolation_filters_ == o.svg_data_->color_interpolation_filters_ && svg_data_->color_rendering_ == o.svg_data_->color_rendering_
                    && svg_data_->shape_rendering_ == o.svg_data_->shape_rendering_ && svg_data_->text_anchor_ == o.svg_data_->text_anchor_
                    && svg_data_->clip_rule_ == o.svg_data_->clip_rule_ && svg_data_->fill_rule_ == o.svg_data_->fill_rule_))
            && white_space_ == o.white_space_ && cursor_ == o.cursor_ && pointer_events_ == o.pointer_events_ && text_align_ == o.text_align_
            && text_transform_ == o.text_transform_ && inside_link_ == o.inside_link_ && visibility_ == o.visibility_ && writing_mode_ == o.writing_mode_
            && border_collapse_ == o.border_collapse_ && box_direction_ == o.box_direction_ && caption_side_ == o.caption_side_ && color_scheme_forced_ == o.color_scheme_forced_
            && dark_color_scheme_ == o.dark_color_scheme_ && direction_ == o.direction_ && empty_cells_ == o.empty_cells_ && has_simple_underline_ == o.has_simple_underline_
            && inside_fragmentation_context_with_nondeterministic_engine_ == o.inside_fragmentation_context_with_nondeterministic_engine_
            && is_ensured_outside_flat_tree_ == o.is_ensured_outside_flat_tree_ && is_inert_ == o.is_inert_ && is_inside_list_element_ == o.is_inside_list_element_
            && list_style_position_ == o.list_style_position_ && print_color_adjust_ == o.print_color_adjust_ && rtl_ordering_ == o.rtl_ordering_

        );
    }

    enum IsAtShadowBoundary {
        kAtShadowBoundary,
        kNotAtShadowBoundary,
    };

    void InheritFrom(const ComputedStyleBase& other, IsAtShadowBoundary isAtShadowBoundary);
    void CopyNonInheritedFromCached(const ComputedStyleBase& other);

    // Copies the values of any independent inherited properties from the parent
    // style that are marked as inherited by this style.
    void PropagateIndependentInheritedProperties(const ComputedStyleBase& parentStyle);

    static bool ScrollAnchorDisablingPropertyChanged(const ComputedStyle& a, const ComputedStyle& b);
    static bool DiffNeedsReshapeAndFullLayoutAndPaintInvalidation(const ComputedStyle& a, const ComputedStyle& b);
    static bool DiffNeedsFullLayoutAndPaintInvalidation(const ComputedStyle& a, const ComputedStyle& b);
    static bool DiffNeedsFullLayoutAndPaintInvalidationDisplayTableType(const ComputedStyle& a, const ComputedStyle& b);
    static bool DiffNeedsFullLayoutAndPaintInvalidationDisplayListItem(const ComputedStyle& a, const ComputedStyle& b);
    static bool DiffNeedsFullLayout(const ComputedStyle& a, const ComputedStyle& b);
    static bool DiffNeedsPaintInvalidation(const ComputedStyle& a, const ComputedStyle& b);
    static bool DiffNeedsVisualRectUpdate(const ComputedStyle& a, const ComputedStyle& b);
    static bool UpdatePropertySpecificDifferencesZIndex(const ComputedStyle& a, const ComputedStyle& b);
    static bool DiffTransformData(const ComputedStyle& a, const ComputedStyle& b);
    static bool UpdatePropertySpecificDifferencesTransform(const ComputedStyle& a, const ComputedStyle& b);
    static bool UpdatePropertySpecificDifferencesOtherTransform(const ComputedStyle& a, const ComputedStyle& b);
    static bool UpdatePropertySpecificDifferencesOpacity(const ComputedStyle& a, const ComputedStyle& b);
    static bool UpdatePropertySpecificDifferencesFilter(const ComputedStyle& a, const ComputedStyle& b);
    static bool UpdatePropertySpecificDifferencesMask(const ComputedStyle& a, const ComputedStyle& b);
    static bool UpdatePropertySpecificDifferencesNeedsRecomputeVisualOverflow(const ComputedStyle& a, const ComputedStyle& b);
    static bool UpdatePropertySpecificDifferencesTextDecorationOrColor(const ComputedStyle& a, const ComputedStyle& b);

    // Fields.
    // TODO(sashab): Remove initialFoo() static methods and update callers to
    // use resetFoo(), which can be more efficient.

    // accent-color

    void SetAccentColor(const StyleAutoColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->accent_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->accent_color_ = v;
    }

    void SetAccentColor(StyleAutoColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->accent_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->accent_color_ = std::move(v);
    }
    inline void ResetAccentColor()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->accent_color_ = StyleAutoColor::AutoColor();
    }

    // AffectedByActive
    bool AffectedByActive() const { return static_cast<bool>(affected_by_active_); }

    void SetAffectedByActive() { affected_by_active_ = static_cast<unsigned>(true); }
    // AffectedByDrag
    bool AffectedByDrag() const { return static_cast<bool>(affected_by_drag_); }

    void SetAffectedByDrag() { affected_by_drag_ = static_cast<unsigned>(true); }
    // AffectedByFocusWithin
    bool AffectedByFocusWithin() const { return static_cast<bool>(affected_by_focus_within_); }

    void SetAffectedByFocusWithin() { affected_by_focus_within_ = static_cast<unsigned>(true); }
    // AffectedByHover
    bool AffectedByHover() const { return static_cast<bool>(affected_by_hover_); }

    void SetAffectedByHover() { affected_by_hover_ = static_cast<unsigned>(true); }
    // align-content
    const StyleContentAlignmentData& AlignContent() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_;
    }

    void SetAlignContent(const StyleContentAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_content_ = v;
    }

    void SetAlignContent(StyleContentAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_content_ = std::move(v);
    }
    inline void ResetAlignContent()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_content_
            = StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault);
    }

    // align-items
    const StyleSelfAlignmentData& AlignItems() const { return rare_non_inherited_usage_less_than_14_percent_data_->align_items_; }

    void SetAlignItems(const StyleSelfAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->align_items_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->align_items_ = v;
    }

    void SetAlignItems(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->align_items_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->align_items_ = std::move(v);
    }
    inline void ResetAlignItems()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->align_items_ = StyleSelfAlignmentData(ItemPosition::kNormal, OverflowAlignment::kDefault);
    }

    // align-self
    const StyleSelfAlignmentData& AlignSelf() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_;
    }

    void SetAlignSelf(const StyleSelfAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_self_ = v;
    }

    void SetAlignSelf(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_self_ = std::move(v);
    }
    inline void ResetAlignSelf()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_self_
            = StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault);
    }

    // -internal-align-self-block
    bool AlignSelfBlockCenter() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_self_block_center_);
    }

    void SetAlignSelfBlockCenter(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_self_block_center_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->align_self_block_center_
                = static_cast<unsigned>(v);
    }

    inline void ResetAlignSelfBlockCenter()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->align_self_block_center_
            = static_cast<unsigned>(false);
    }
    // alignment-baseline
    EAlignmentBaseline AlignmentBaseline() const { return static_cast<EAlignmentBaseline>(svg_data_->alignment_baseline_); }

    void SetAlignmentBaseline(EAlignmentBaseline v)
    {
        if (!(svg_data_->alignment_baseline_ == static_cast<unsigned>(v)))
            svg_data_.Access()->alignment_baseline_ = static_cast<unsigned>(v);
    }

    inline void ResetAlignmentBaseline() { svg_data_.Access()->alignment_baseline_ = static_cast<unsigned>(EAlignmentBaseline::kAuto); }
    // anchor-name
    const AtomicString& AnchorName() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_; }

    void SetAnchorName(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_name_ = v;
    }

    void SetAnchorName(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_name_ = std::move(v);
    }
    inline void ResetAnchorName()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_name_ = g_null_atom;
    }

    // anchor-scroll
    const AtomicString& AnchorScroll() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scroll_;
    }

    void SetAnchorScroll(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scroll_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_scroll_ = v;
    }

    void SetAnchorScroll(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scroll_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_scroll_ = std::move(v);
    }
    inline void ResetAnchorScroll()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_scroll_ = g_null_atom;
    }

    // Animations

    inline void ResetAnimations()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->animations_ = nullptr;
    }

    // appearance

    void SetAppearance(ControlPart v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->appearance_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->appearance_ = static_cast<unsigned>(v);
    }

    inline void ResetAppearance() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->appearance_ = static_cast<unsigned>(kNoControlPart); }
    // AppliedTextDecorations

    inline void ResetAppliedTextDecorations()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->applied_text_decorations_ = nullptr;
    }

    // aspect-ratio
    const StyleAspectRatio& AspectRatio() const { return box_data_->aspect_ratio_; }

    void SetAspectRatio(const StyleAspectRatio& v)
    {
        if (!(box_data_->aspect_ratio_ == v))
            box_data_.Access()->aspect_ratio_ = v;
    }

    void SetAspectRatio(StyleAspectRatio&& v)
    {
        if (!(box_data_->aspect_ratio_ == v))
            box_data_.Access()->aspect_ratio_ = std::move(v);
    }
    inline void ResetAspectRatio() { box_data_.Access()->aspect_ratio_ = StyleAspectRatio(EAspectRatioType::kAuto, gfx::SizeF()); }

    // backdrop-filter

    inline void ResetBackdropFilter()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->backdrop_filter_
            = MakeGarbageCollected<StyleFilterData>();
    }

    // backface-visibility
    EBackfaceVisibility BackfaceVisibility() const
    {
        return static_cast<EBackfaceVisibility>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_);
    }

    void SetBackfaceVisibility(EBackfaceVisibility v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->backface_visibility_
                = static_cast<unsigned>(v);
    }

    inline void ResetBackfaceVisibility()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->backface_visibility_
            = static_cast<unsigned>(EBackfaceVisibility::kVisible);
    }
    // Background

    inline void ResetBackground() { background_data_.Access()->background_ = FillLayer(EFillLayerType::kBackground, true); }

    // background-color

    void SetBackgroundColor(const StyleColor& v)
    {
        if (!(background_data_->background_color_ == v))
            background_data_.Access()->background_color_ = v;
    }

    void SetBackgroundColor(StyleColor&& v)
    {
        if (!(background_data_->background_color_ == v))
            background_data_.Access()->background_color_ = std::move(v);
    }
    inline void ResetBackgroundColor() { background_data_.Access()->background_color_ = StyleColor(Color::kTransparent); }

    // BaseData
    const scoped_refptr<StyleBaseData>& BaseData() const { return base_data_; }

    void SetBaseData(const scoped_refptr<StyleBaseData>& v) { base_data_ = v; }

    void SetBaseData(scoped_refptr<StyleBaseData>&& v) { base_data_ = std::move(v); }
    inline void ResetBaseData() { base_data_ = nullptr; }

    // baseline-shift
    const Length& BaselineShift() const { return svg_data_->misc_data_->baseline_shift_; }

    void SetBaselineShift(const Length& v)
    {
        if (!(svg_data_->misc_data_->baseline_shift_ == v))
            svg_data_.Access()->misc_data_.Access()->baseline_shift_ = v;
    }

    void SetBaselineShift(Length&& v)
    {
        if (!(svg_data_->misc_data_->baseline_shift_ == v))
            svg_data_.Access()->misc_data_.Access()->baseline_shift_ = std::move(v);
    }
    inline void ResetBaselineShift() { svg_data_.Access()->misc_data_.Access()->baseline_shift_ = Length::Fixed(); }

    // BaselineShiftType
    EBaselineShiftType BaselineShiftType() const { return static_cast<EBaselineShiftType>(svg_data_->misc_data_->baseline_shift_type_); }

    void SetBaselineShiftType(EBaselineShiftType v)
    {
        if (!(svg_data_->misc_data_->baseline_shift_type_ == static_cast<unsigned>(v)))
            svg_data_.Access()->misc_data_.Access()->baseline_shift_type_ = static_cast<unsigned>(v);
    }

    inline void ResetBaselineShiftType() { svg_data_.Access()->misc_data_.Access()->baseline_shift_type_ = static_cast<unsigned>(EBaselineShiftType::kLength); }
    // mix-blend-mode
    BlendMode GetBlendMode() const
    {
        return static_cast<BlendMode>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                          ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_);
    }

    void SetBlendMode(BlendMode v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->blend_mode_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->blend_mode_
                = static_cast<unsigned>(v);
    }

    inline void ResetBlendMode()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->blend_mode_
            = static_cast<unsigned>(BlendMode::kNormal);
    }
    // border-bottom-color

    void SetBorderBottomColor(const StyleColor& v)
    {
        if (!(surround_data_->border_bottom_color_ == v))
            surround_data_.Access()->border_bottom_color_ = v;
    }

    void SetBorderBottomColor(StyleColor&& v)
    {
        if (!(surround_data_->border_bottom_color_ == v))
            surround_data_.Access()->border_bottom_color_ = std::move(v);
    }
    inline void ResetBorderBottomColor() { surround_data_.Access()->border_bottom_color_ = StyleColor::CurrentColor(); }

    // border-bottom-left-radius
    const LengthSize& BorderBottomLeftRadius() const { return surround_data_->border_bottom_left_radius_; }

    void SetBorderBottomLeftRadius(const LengthSize& v)
    {
        if (!(surround_data_->border_bottom_left_radius_ == v))
            surround_data_.Access()->border_bottom_left_radius_ = v;
    }

    void SetBorderBottomLeftRadius(LengthSize&& v)
    {
        if (!(surround_data_->border_bottom_left_radius_ == v))
            surround_data_.Access()->border_bottom_left_radius_ = std::move(v);
    }
    inline void ResetBorderBottomLeftRadius() { surround_data_.Access()->border_bottom_left_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0)); }

    // border-bottom-right-radius
    const LengthSize& BorderBottomRightRadius() const { return surround_data_->border_bottom_right_radius_; }

    void SetBorderBottomRightRadius(const LengthSize& v)
    {
        if (!(surround_data_->border_bottom_right_radius_ == v))
            surround_data_.Access()->border_bottom_right_radius_ = v;
    }

    void SetBorderBottomRightRadius(LengthSize&& v)
    {
        if (!(surround_data_->border_bottom_right_radius_ == v))
            surround_data_.Access()->border_bottom_right_radius_ = std::move(v);
    }
    inline void ResetBorderBottomRightRadius() { surround_data_.Access()->border_bottom_right_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0)); }

    // border-bottom-style
    EBorderStyle BorderBottomStyle() const { return static_cast<EBorderStyle>(surround_data_->border_bottom_style_); }

    void SetBorderBottomStyle(EBorderStyle v)
    {
        if (!(surround_data_->border_bottom_style_ == static_cast<unsigned>(v)))
            surround_data_.Access()->border_bottom_style_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderBottomStyle() { surround_data_.Access()->border_bottom_style_ = static_cast<unsigned>(EBorderStyle::kNone); }
    // border-bottom-width

    void SetBorderBottomWidth(const LayoutUnit& v)
    {
        if (!(surround_data_->border_bottom_width_ == v))
            surround_data_.Access()->border_bottom_width_ = v;
    }

    void SetBorderBottomWidth(LayoutUnit&& v)
    {
        if (!(surround_data_->border_bottom_width_ == v))
            surround_data_.Access()->border_bottom_width_ = std::move(v);
    }
    inline void ResetBorderBottomWidth() { surround_data_.Access()->border_bottom_width_ = LayoutUnit(3); }

    // border-collapse
    EBorderCollapse BorderCollapse() const { return static_cast<EBorderCollapse>(border_collapse_); }

    void SetBorderCollapse(EBorderCollapse v) { border_collapse_ = static_cast<unsigned>(v); }

    inline void ResetBorderCollapse() { border_collapse_ = static_cast<unsigned>(EBorderCollapse::kSeparate); }
    // border-collapse
    bool BorderCollapseIsInherited() const { return static_cast<bool>(border_collapse_is_inherited_); }

    void SetBorderCollapseIsInherited(bool v) { border_collapse_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetBorderCollapseIsInherited() { border_collapse_is_inherited_ = static_cast<unsigned>(true); }
    // border-image
    const NinePieceImage& BorderImage() const { return surround_data_->border_image_; }

    void SetBorderImage(const NinePieceImage& v)
    {
        if (!(surround_data_->border_image_ == v))
            surround_data_.Access()->border_image_ = v;
    }

    void SetBorderImage(NinePieceImage&& v)
    {
        if (!(surround_data_->border_image_ == v))
            surround_data_.Access()->border_image_ = std::move(v);
    }
    inline void ResetBorderImage() { surround_data_.Access()->border_image_ = NinePieceImage(); }

    // border-left-color

    void SetBorderLeftColor(const StyleColor& v)
    {
        if (!(surround_data_->border_left_color_ == v))
            surround_data_.Access()->border_left_color_ = v;
    }

    void SetBorderLeftColor(StyleColor&& v)
    {
        if (!(surround_data_->border_left_color_ == v))
            surround_data_.Access()->border_left_color_ = std::move(v);
    }
    inline void ResetBorderLeftColor() { surround_data_.Access()->border_left_color_ = StyleColor::CurrentColor(); }

    // border-left-style
    EBorderStyle BorderLeftStyle() const { return static_cast<EBorderStyle>(surround_data_->border_left_style_); }

    void SetBorderLeftStyle(EBorderStyle v)
    {
        if (!(surround_data_->border_left_style_ == static_cast<unsigned>(v)))
            surround_data_.Access()->border_left_style_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderLeftStyle() { surround_data_.Access()->border_left_style_ = static_cast<unsigned>(EBorderStyle::kNone); }
    // border-left-width

    void SetBorderLeftWidth(const LayoutUnit& v)
    {
        if (!(surround_data_->border_left_width_ == v))
            surround_data_.Access()->border_left_width_ = v;
    }

    void SetBorderLeftWidth(LayoutUnit&& v)
    {
        if (!(surround_data_->border_left_width_ == v))
            surround_data_.Access()->border_left_width_ = std::move(v);
    }
    inline void ResetBorderLeftWidth() { surround_data_.Access()->border_left_width_ = LayoutUnit(3); }

    // border-right-color

    void SetBorderRightColor(const StyleColor& v)
    {
        if (!(surround_data_->border_right_color_ == v))
            surround_data_.Access()->border_right_color_ = v;
    }

    void SetBorderRightColor(StyleColor&& v)
    {
        if (!(surround_data_->border_right_color_ == v))
            surround_data_.Access()->border_right_color_ = std::move(v);
    }
    inline void ResetBorderRightColor() { surround_data_.Access()->border_right_color_ = StyleColor::CurrentColor(); }

    // border-right-style
    EBorderStyle BorderRightStyle() const { return static_cast<EBorderStyle>(surround_data_->border_right_style_); }

    void SetBorderRightStyle(EBorderStyle v)
    {
        if (!(surround_data_->border_right_style_ == static_cast<unsigned>(v)))
            surround_data_.Access()->border_right_style_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderRightStyle() { surround_data_.Access()->border_right_style_ = static_cast<unsigned>(EBorderStyle::kNone); }
    // border-right-width

    void SetBorderRightWidth(const LayoutUnit& v)
    {
        if (!(surround_data_->border_right_width_ == v))
            surround_data_.Access()->border_right_width_ = v;
    }

    void SetBorderRightWidth(LayoutUnit&& v)
    {
        if (!(surround_data_->border_right_width_ == v))
            surround_data_.Access()->border_right_width_ = std::move(v);
    }
    inline void ResetBorderRightWidth() { surround_data_.Access()->border_right_width_ = LayoutUnit(3); }

    // border-top-color

    void SetBorderTopColor(const StyleColor& v)
    {
        if (!(surround_data_->border_top_color_ == v))
            surround_data_.Access()->border_top_color_ = v;
    }

    void SetBorderTopColor(StyleColor&& v)
    {
        if (!(surround_data_->border_top_color_ == v))
            surround_data_.Access()->border_top_color_ = std::move(v);
    }
    inline void ResetBorderTopColor() { surround_data_.Access()->border_top_color_ = StyleColor::CurrentColor(); }

    // border-top-left-radius
    const LengthSize& BorderTopLeftRadius() const { return surround_data_->border_top_left_radius_; }

    void SetBorderTopLeftRadius(const LengthSize& v)
    {
        if (!(surround_data_->border_top_left_radius_ == v))
            surround_data_.Access()->border_top_left_radius_ = v;
    }

    void SetBorderTopLeftRadius(LengthSize&& v)
    {
        if (!(surround_data_->border_top_left_radius_ == v))
            surround_data_.Access()->border_top_left_radius_ = std::move(v);
    }
    inline void ResetBorderTopLeftRadius() { surround_data_.Access()->border_top_left_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0)); }

    // border-top-right-radius
    const LengthSize& BorderTopRightRadius() const { return surround_data_->border_top_right_radius_; }

    void SetBorderTopRightRadius(const LengthSize& v)
    {
        if (!(surround_data_->border_top_right_radius_ == v))
            surround_data_.Access()->border_top_right_radius_ = v;
    }

    void SetBorderTopRightRadius(LengthSize&& v)
    {
        if (!(surround_data_->border_top_right_radius_ == v))
            surround_data_.Access()->border_top_right_radius_ = std::move(v);
    }
    inline void ResetBorderTopRightRadius() { surround_data_.Access()->border_top_right_radius_ = LengthSize(Length::Fixed(0), Length::Fixed(0)); }

    // border-top-style
    EBorderStyle BorderTopStyle() const { return static_cast<EBorderStyle>(surround_data_->border_top_style_); }

    void SetBorderTopStyle(EBorderStyle v)
    {
        if (!(surround_data_->border_top_style_ == static_cast<unsigned>(v)))
            surround_data_.Access()->border_top_style_ = static_cast<unsigned>(v);
    }

    inline void ResetBorderTopStyle() { surround_data_.Access()->border_top_style_ = static_cast<unsigned>(EBorderStyle::kNone); }
    // border-top-width

    void SetBorderTopWidth(const LayoutUnit& v)
    {
        if (!(surround_data_->border_top_width_ == v))
            surround_data_.Access()->border_top_width_ = v;
    }

    void SetBorderTopWidth(LayoutUnit&& v)
    {
        if (!(surround_data_->border_top_width_ == v))
            surround_data_.Access()->border_top_width_ = std::move(v);
    }
    inline void ResetBorderTopWidth() { surround_data_.Access()->border_top_width_ = LayoutUnit(3); }

    // bottom
    const Length& Bottom() const { return surround_data_->bottom_; }

    void SetBottom(const Length& v)
    {
        if (!(surround_data_->bottom_ == v))
            surround_data_.Access()->bottom_ = v;
    }

    void SetBottom(Length&& v)
    {
        if (!(surround_data_->bottom_ == v))
            surround_data_.Access()->bottom_ = std::move(v);
    }
    inline void ResetBottom() { surround_data_.Access()->bottom_ = Length(); }

    // -webkit-box-align
    EBoxAlignment BoxAlign() const
    {
        return static_cast<EBoxAlignment>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_);
    }

    void SetBoxAlign(EBoxAlignment v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_align_ = static_cast<unsigned>(v);
    }

    inline void ResetBoxAlign()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_align_
            = static_cast<unsigned>(EBoxAlignment::kStretch);
    }
    // -webkit-box-decoration-break
    EBoxDecorationBreak BoxDecorationBreak() const { return static_cast<EBoxDecorationBreak>(box_data_->box_decoration_break_); }

    void SetBoxDecorationBreak(EBoxDecorationBreak v)
    {
        if (!(box_data_->box_decoration_break_ == static_cast<unsigned>(v)))
            box_data_.Access()->box_decoration_break_ = static_cast<unsigned>(v);
    }

    inline void ResetBoxDecorationBreak() { box_data_.Access()->box_decoration_break_ = static_cast<unsigned>(EBoxDecorationBreak::kSlice); }
    // -webkit-box-direction
    EBoxDirection BoxDirection() const { return static_cast<EBoxDirection>(box_direction_); }

    void SetBoxDirection(EBoxDirection v) { box_direction_ = static_cast<unsigned>(v); }

    inline void ResetBoxDirection() { box_direction_ = static_cast<unsigned>(EBoxDirection::kNormal); }
    // -webkit-box-direction
    bool BoxDirectionIsInherited() const { return static_cast<bool>(box_direction_is_inherited_); }

    void SetBoxDirectionIsInherited(bool v) { box_direction_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetBoxDirectionIsInherited() { box_direction_is_inherited_ = static_cast<unsigned>(true); }
    // -webkit-box-flex
    float BoxFlex() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_; }

    void SetBoxFlex(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_flex_ = v;
    }

    inline void ResetBoxFlex() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_flex_ = 0.0f; }
    // -webkit-box-ordinal-group
    unsigned BoxOrdinalGroup() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->box_ordinal_group_;
    }
    inline void ResetBoxOrdinalGroup()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->box_ordinal_group_
            = 1;
    }
    // -webkit-box-orient
    EBoxOrient BoxOrient() const
    {
        return static_cast<EBoxOrient>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_);
    }

    void SetBoxOrient(EBoxOrient v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_orient_ = static_cast<unsigned>(v);
    }

    inline void ResetBoxOrient()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_orient_
            = static_cast<unsigned>(EBoxOrient::kHorizontal);
    }
    // -webkit-box-pack
    EBoxPack BoxPack() const { return static_cast<EBoxPack>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_); }

    void SetBoxPack(EBoxPack v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_pack_ = static_cast<unsigned>(v);
    }

    inline void ResetBoxPack()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_pack_
            = static_cast<unsigned>(EBoxPack::kStart);
    }
    // -webkit-box-reflect
    StyleReflection* BoxReflect() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->box_reflect_.get();
    }

    void SetBoxReflect(scoped_refptr<StyleReflection> v)
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->box_reflect_
            = std::move(v);
    }

    // box-shadow
    ShadowList* BoxShadow() const { return rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_.get(); }

    void SetBoxShadow(scoped_refptr<ShadowList> v) { rare_non_inherited_usage_less_than_14_percent_data_.Access()->box_shadow_ = std::move(v); }

    // box-sizing
    EBoxSizing BoxSizing() const { return static_cast<EBoxSizing>(box_data_->box_sizing_); }

    void SetBoxSizing(EBoxSizing v)
    {
        if (!(box_data_->box_sizing_ == static_cast<unsigned>(v)))
            box_data_.Access()->box_sizing_ = static_cast<unsigned>(v);
    }

    inline void ResetBoxSizing() { box_data_.Access()->box_sizing_ = static_cast<unsigned>(EBoxSizing::kContentBox); }
    // break-after
    EBreakBetween BreakAfter() const { return static_cast<EBreakBetween>(break_after_); }

    void SetBreakAfter(EBreakBetween v) { break_after_ = static_cast<unsigned>(v); }

    inline void ResetBreakAfter() { break_after_ = static_cast<unsigned>(EBreakBetween::kAuto); }
    // break-before
    EBreakBetween BreakBefore() const { return static_cast<EBreakBetween>(break_before_); }

    void SetBreakBefore(EBreakBetween v) { break_before_ = static_cast<unsigned>(v); }

    inline void ResetBreakBefore() { break_before_ = static_cast<unsigned>(EBreakBetween::kAuto); }
    // break-inside
    EBreakInside BreakInside() const { return static_cast<EBreakInside>(break_inside_); }

    void SetBreakInside(EBreakInside v) { break_inside_ = static_cast<unsigned>(v); }

    inline void ResetBreakInside() { break_inside_ = static_cast<unsigned>(EBreakInside::kAuto); }
    // buffered-rendering
    EBufferedRendering BufferedRendering() const { return static_cast<EBufferedRendering>(svg_data_->buffered_rendering_); }

    void SetBufferedRendering(EBufferedRendering v)
    {
        if (!(svg_data_->buffered_rendering_ == static_cast<unsigned>(v)))
            svg_data_.Access()->buffered_rendering_ = static_cast<unsigned>(v);
    }

    inline void ResetBufferedRendering() { svg_data_.Access()->buffered_rendering_ = static_cast<unsigned>(EBufferedRendering::kAuto); }
    // CallbackSelectors
    const Vector<String>& CallbackSelectors() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_;
    }
    inline void ResetCallbackSelectors()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->callback_selectors_ = Vector<String>();
    }

    // stroke-linecap
    LineCap CapStyle() const { return static_cast<LineCap>(svg_data_->stroke_data_->cap_style_); }

    void SetCapStyle(LineCap v)
    {
        if (!(svg_data_->stroke_data_->cap_style_ == static_cast<unsigned>(v)))
            svg_data_.Access()->stroke_data_.Access()->cap_style_ = static_cast<unsigned>(v);
    }

    inline void ResetCapStyle() { svg_data_.Access()->stroke_data_.Access()->cap_style_ = static_cast<unsigned>(kButtCap); }
    // caption-side
    ECaptionSide CaptionSide() const { return static_cast<ECaptionSide>(caption_side_); }

    void SetCaptionSide(ECaptionSide v) { caption_side_ = static_cast<unsigned>(v); }

    inline void ResetCaptionSide() { caption_side_ = static_cast<unsigned>(ECaptionSide::kTop); }
    // caption-side
    bool CaptionSideIsInherited() const { return static_cast<bool>(caption_side_is_inherited_); }

    void SetCaptionSideIsInherited(bool v) { caption_side_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetCaptionSideIsInherited() { caption_side_is_inherited_ = static_cast<unsigned>(true); }
    // caret-color

    void SetCaretColor(const StyleAutoColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->caret_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->caret_color_ = v;
    }

    void SetCaretColor(StyleAutoColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->caret_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->caret_color_ = std::move(v);
    }
    inline void ResetCaretColor() { rare_inherited_usage_less_than_64_percent_data_.Access()->caret_color_ = StyleAutoColor::AutoColor(); }

    // ChildHasExplicitInheritance
    bool ChildHasExplicitInheritance() const { return static_cast<bool>(child_has_explicit_inheritance_); }

    void SetChildHasExplicitInheritance() const { child_has_explicit_inheritance_ = static_cast<unsigned>(true); }
    // clear

    void SetClear(EClear v) { clear_ = static_cast<unsigned>(v); }

    inline void ResetClear() { clear_ = static_cast<unsigned>(EClear::kNone); }
    // clip
    const LengthBox& Clip() const { return visual_data_->clip_; }
    inline void ResetClip() { visual_data_.Access()->clip_ = LengthBox(); }

    // clip-path

    inline void ResetClipPath()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->clip_path_
            = nullptr;
    }

    // clip-rule
    WindRule ClipRule() const { return static_cast<WindRule>(svg_data_->clip_rule_); }

    void SetClipRule(WindRule v)
    {
        if (!(svg_data_->clip_rule_ == static_cast<unsigned>(v)))
            svg_data_.Access()->clip_rule_ = static_cast<unsigned>(v);
    }

    inline void ResetClipRule() { svg_data_.Access()->clip_rule_ = static_cast<unsigned>(RULE_NONZERO); }
    // color

    void SetColor(const StyleColor& v)
    {
        if (!(inherited_data_->color_ == v))
            inherited_data_.Access()->color_ = v;
    }

    void SetColor(StyleColor&& v)
    {
        if (!(inherited_data_->color_ == v))
            inherited_data_.Access()->color_ = std::move(v);
    }
    inline void ResetColor() { inherited_data_.Access()->color_ = StyleColor(Color::kBlack); }

    // color-interpolation
    EColorInterpolation ColorInterpolation() const { return static_cast<EColorInterpolation>(svg_data_->color_interpolation_); }

    void SetColorInterpolation(EColorInterpolation v)
    {
        if (!(svg_data_->color_interpolation_ == static_cast<unsigned>(v)))
            svg_data_.Access()->color_interpolation_ = static_cast<unsigned>(v);
    }

    inline void ResetColorInterpolation() { svg_data_.Access()->color_interpolation_ = static_cast<unsigned>(EColorInterpolation::kSRGB); }
    // color-interpolation-filters
    EColorInterpolation ColorInterpolationFilters() const { return static_cast<EColorInterpolation>(svg_data_->color_interpolation_filters_); }

    void SetColorInterpolationFilters(EColorInterpolation v)
    {
        if (!(svg_data_->color_interpolation_filters_ == static_cast<unsigned>(v)))
            svg_data_.Access()->color_interpolation_filters_ = static_cast<unsigned>(v);
    }

    inline void ResetColorInterpolationFilters() { svg_data_.Access()->color_interpolation_filters_ = static_cast<unsigned>(EColorInterpolation::kLinearrgb); }
    // ColorIsCurrentColor

    void SetColorIsCurrentColor(bool v)
    {
        if (!(inherited_data_->color_is_current_color_ == static_cast<unsigned>(v)))
            inherited_data_.Access()->color_is_current_color_ = static_cast<unsigned>(v);
    }

    inline void ResetColorIsCurrentColor() { inherited_data_.Access()->color_is_current_color_ = static_cast<unsigned>(true); }
    // color

    void SetColorIsInherited(bool v) { color_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetColorIsInherited() { color_is_inherited_ = static_cast<unsigned>(true); }
    // color-rendering
    EColorRendering ColorRendering() const { return static_cast<EColorRendering>(svg_data_->color_rendering_); }

    void SetColorRendering(EColorRendering v)
    {
        if (!(svg_data_->color_rendering_ == static_cast<unsigned>(v)))
            svg_data_.Access()->color_rendering_ = static_cast<unsigned>(v);
    }

    inline void ResetColorRendering() { svg_data_.Access()->color_rendering_ = static_cast<unsigned>(EColorRendering::kAuto); }
    // color-scheme
    const Vector<AtomicString>& ColorScheme() const { return rare_inherited_usage_less_than_64_percent_data_->color_scheme_; }

    void SetColorScheme(const Vector<AtomicString>& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->color_scheme_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->color_scheme_ = v;
    }

    void SetColorScheme(Vector<AtomicString>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->color_scheme_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->color_scheme_ = std::move(v);
    }
    inline void ResetColorScheme() { rare_inherited_usage_less_than_64_percent_data_.Access()->color_scheme_ = Vector<AtomicString, 0>(); }

    // ColorSchemeForced
    bool ColorSchemeForced() const { return static_cast<bool>(color_scheme_forced_); }

    void SetColorSchemeForced(bool v) { color_scheme_forced_ = static_cast<unsigned>(v); }

    inline void ResetColorSchemeForced() { color_scheme_forced_ = static_cast<unsigned>(false); }
    // column-count
    unsigned short ColumnCount() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->column_count_;
    }
    inline void ResetColumnCount()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_count_
            = 1;
    }
    // column-fill
    EColumnFill GetColumnFill() const
    {
        return static_cast<EColumnFill>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_);
    }

    void SetColumnFill(EColumnFill v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_fill_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_fill_
                = static_cast<unsigned>(v);
    }

    inline void ResetColumnFill()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_fill_
            = static_cast<unsigned>(EColumnFill::kBalance);
    }
    // column-gap
    const absl::optional<Length>& ColumnGap() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->column_gap_;
    }

    void SetColumnGap(const absl::optional<Length>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_gap_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_gap_
                = v;
    }

    void SetColumnGap(absl::optional<Length>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_gap_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_gap_
                = std::move(v);
    }
    inline void ResetColumnGap()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_gap_
            = absl::nullopt;
    }

    // column-rule-color

    void SetColumnRuleColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_rule_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_rule_color_
                = v;
    }

    void SetColumnRuleColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_rule_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_rule_color_
                = std::move(v);
    }
    inline void ResetColumnRuleColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_rule_color_
            = StyleColor::CurrentColor();
    }

    // column-rule-style
    EBorderStyle ColumnRuleStyle() const
    {
        return static_cast<EBorderStyle>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                             ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_);
    }

    void SetColumnRuleStyle(EBorderStyle v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_rule_style_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_rule_style_
                = static_cast<unsigned>(v);
    }

    inline void ResetColumnRuleStyle()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_rule_style_
            = static_cast<unsigned>(EBorderStyle::kNone);
    }
    // column-rule-width

    inline void ResetColumnRuleWidth()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_rule_width_
            = LayoutUnit(3);
    }

    // column-span
    EColumnSpan GetColumnSpan() const
    {
        return static_cast<EColumnSpan>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                            ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_);
    }

    void SetColumnSpan(EColumnSpan v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_span_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_span_
                = static_cast<unsigned>(v);
    }

    inline void ResetColumnSpan()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_span_
            = static_cast<unsigned>(EColumnSpan::kNone);
    }
    // column-width
    float ColumnWidth() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->column_width_;
    }
    inline void ResetColumnWidth()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_width_
            = 0.0f;
    }
    // CompositablePaintAnimationChanged
    bool CompositablePaintAnimationChanged() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->compositable_paint_animation_changed_);
    }

    void SetCompositablePaintAnimationChanged(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->compositable_paint_animation_changed_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->compositable_paint_animation_changed_
                = static_cast<unsigned>(v);
    }

    inline void ResetCompositablePaintAnimationChanged()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->compositable_paint_animation_changed_
            = static_cast<unsigned>(false);
    }
    // contain
    unsigned Contain() const
    {
        return static_cast<unsigned>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                         ->rare_non_inherited_usage_less_than_100_percent_data_->contain_);
    }

    void SetContain(unsigned v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->contain_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->contain_
                = static_cast<unsigned>(v);
    }

    inline void ResetContain()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->contain_
            = static_cast<unsigned>(kContainsNone);
    }
    // contain-intrinsic-height
    const absl::optional<StyleIntrinsicLength>& ContainIntrinsicHeight() const { return box_data_->contain_intrinsic_height_; }

    void SetContainIntrinsicHeight(const absl::optional<StyleIntrinsicLength>& v)
    {
        if (!(box_data_->contain_intrinsic_height_ == v))
            box_data_.Access()->contain_intrinsic_height_ = v;
    }

    void SetContainIntrinsicHeight(absl::optional<StyleIntrinsicLength>&& v)
    {
        if (!(box_data_->contain_intrinsic_height_ == v))
            box_data_.Access()->contain_intrinsic_height_ = std::move(v);
    }
    inline void ResetContainIntrinsicHeight() { box_data_.Access()->contain_intrinsic_height_ = absl::optional<StyleIntrinsicLength>(); }

    // contain-intrinsic-width
    const absl::optional<StyleIntrinsicLength>& ContainIntrinsicWidth() const { return box_data_->contain_intrinsic_width_; }

    void SetContainIntrinsicWidth(const absl::optional<StyleIntrinsicLength>& v)
    {
        if (!(box_data_->contain_intrinsic_width_ == v))
            box_data_.Access()->contain_intrinsic_width_ = v;
    }

    void SetContainIntrinsicWidth(absl::optional<StyleIntrinsicLength>&& v)
    {
        if (!(box_data_->contain_intrinsic_width_ == v))
            box_data_.Access()->contain_intrinsic_width_ = std::move(v);
    }
    inline void ResetContainIntrinsicWidth() { box_data_.Access()->contain_intrinsic_width_ = absl::nullopt; }

    // container-name
    const Vector<AtomicString>& ContainerName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_;
    }

    void SetContainerName(const Vector<AtomicString>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->container_name_ = v;
    }

    void SetContainerName(Vector<AtomicString>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->container_name_ = std::move(v);
    }
    inline void ResetContainerName()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->container_name_ = Vector<AtomicString>();
    }

    // container-type
    unsigned ContainerType() const
    {
        return static_cast<unsigned>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_);
    }

    void SetContainerType(unsigned v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->container_type_
                = static_cast<unsigned>(v);
    }

    inline void ResetContainerType()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->container_type_
            = static_cast<unsigned>(kContainerTypeNormal);
    }
    // content

    inline void ResetContent() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->content_ = nullptr; }

    // content-visibility
    EContentVisibility ContentVisibility() const { return static_cast<EContentVisibility>(content_visibility_); }

    void SetContentVisibility(EContentVisibility v) { content_visibility_ = static_cast<unsigned>(v); }

    inline void ResetContentVisibility() { content_visibility_ = static_cast<unsigned>(EContentVisibility::kVisible); }
    // CounterDirectives

    inline void ResetCounterDirectives()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->counter_directives_ = nullptr;
    }

    // CssDominantBaseline
    EDominantBaseline CssDominantBaseline() const { return static_cast<EDominantBaseline>(svg_data_->css_dominant_baseline_); }

    void SetCssDominantBaseline(EDominantBaseline v)
    {
        if (!(svg_data_->css_dominant_baseline_ == static_cast<unsigned>(v)))
            svg_data_.Access()->css_dominant_baseline_ = static_cast<unsigned>(v);
    }

    inline void ResetCssDominantBaseline() { svg_data_.Access()->css_dominant_baseline_ = static_cast<unsigned>(EDominantBaseline::kAuto); }
    // cursor
    ECursor Cursor() const { return static_cast<ECursor>(cursor_); }

    void SetCursor(ECursor v) { cursor_ = static_cast<unsigned>(v); }

    inline void ResetCursor() { cursor_ = static_cast<unsigned>(ECursor::kAuto); }
    // CursorData

    inline void ResetCursorData()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->cursor_data_ = nullptr;
    }

    // CustomHighlightNames

    inline void ResetCustomHighlightNames()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->custom_highlight_names_ = nullptr;
    }

    // CustomStyleCallbackDependsOnFont
    bool CustomStyleCallbackDependsOnFont() const { return static_cast<bool>(custom_style_callback_depends_on_font_); }

    void SetCustomStyleCallbackDependsOnFont() { custom_style_callback_depends_on_font_ = static_cast<unsigned>(true); }
    // cx
    const Length& Cx() const { return svg_data_->geometry_data_->cx_; }

    void SetCx(const Length& v)
    {
        if (!(svg_data_->geometry_data_->cx_ == v))
            svg_data_.Access()->geometry_data_.Access()->cx_ = v;
    }

    void SetCx(Length&& v)
    {
        if (!(svg_data_->geometry_data_->cx_ == v))
            svg_data_.Access()->geometry_data_.Access()->cx_ = std::move(v);
    }
    inline void ResetCx() { svg_data_.Access()->geometry_data_.Access()->cx_ = Length::Fixed(); }

    // cy
    const Length& Cy() const { return svg_data_->geometry_data_->cy_; }

    void SetCy(const Length& v)
    {
        if (!(svg_data_->geometry_data_->cy_ == v))
            svg_data_.Access()->geometry_data_.Access()->cy_ = v;
    }

    void SetCy(Length&& v)
    {
        if (!(svg_data_->geometry_data_->cy_ == v))
            svg_data_.Access()->geometry_data_.Access()->cy_ = std::move(v);
    }
    inline void ResetCy() { svg_data_.Access()->geometry_data_.Access()->cy_ = Length::Fixed(); }

    // d
    StylePath* D() const { return svg_data_->geometry_data_->d_.get(); }

    void SetD(scoped_refptr<StylePath> v) { svg_data_.Access()->geometry_data_.Access()->d_ = std::move(v); }

    // DarkColorScheme
    bool DarkColorScheme() const { return static_cast<bool>(dark_color_scheme_); }

    void SetDarkColorScheme(bool v) { dark_color_scheme_ = static_cast<unsigned>(v); }

    inline void ResetDarkColorScheme() { dark_color_scheme_ = static_cast<unsigned>(false); }
    // DependsOnSizeContainerQueries
    bool DependsOnSizeContainerQueries() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_);
    }

    void SetDependsOnSizeContainerQueries(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->depends_on_size_container_queries_
                = static_cast<unsigned>(v);
    }

    inline void ResetDependsOnSizeContainerQueries()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->depends_on_size_container_queries_
            = static_cast<unsigned>(false);
    }
    // DependsOnStyleContainerQueries
    bool DependsOnStyleContainerQueries() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_style_container_queries_);
    }

    void SetDependsOnStyleContainerQueries(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_style_container_queries_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->depends_on_style_container_queries_
                = static_cast<unsigned>(v);
    }

    inline void ResetDependsOnStyleContainerQueries()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->depends_on_style_container_queries_
            = static_cast<unsigned>(false);
    }
    // direction
    TextDirection Direction() const { return static_cast<TextDirection>(direction_); }

    void SetDirection(TextDirection v) { direction_ = static_cast<unsigned>(v); }

    inline void ResetDirection() { direction_ = static_cast<unsigned>(TextDirection::kLtr); }
    // Display
    EDisplay Display() const { return static_cast<EDisplay>(display_); }

    void SetDisplay(EDisplay v) { display_ = static_cast<unsigned>(v); }

    inline void ResetDisplay() { display_ = static_cast<unsigned>(EDisplay::kInline); }
    // DisplayLayoutCustomName
    const AtomicString& DisplayLayoutCustomName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_;
    }

    void SetDisplayLayoutCustomName(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_name_ = v;
    }

    void SetDisplayLayoutCustomName(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_name_
                = std::move(v);
    }
    inline void ResetDisplayLayoutCustomName()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_name_ = g_null_atom;
    }

    // DisplayLayoutCustomParentName
    const AtomicString& DisplayLayoutCustomParentName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_;
    }

    void SetDisplayLayoutCustomParentName(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_parent_name_ = v;
    }

    void SetDisplayLayoutCustomParentName(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_parent_name_
                = std::move(v);
    }
    inline void ResetDisplayLayoutCustomParentName()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_parent_name_
            = g_null_atom;
    }

    // dominant-baseline
    EDominantBaseline DominantBaseline() const { return static_cast<EDominantBaseline>(svg_data_->dominant_baseline_); }

    void SetDominantBaseline(EDominantBaseline v)
    {
        if (!(svg_data_->dominant_baseline_ == static_cast<unsigned>(v)))
            svg_data_.Access()->dominant_baseline_ = static_cast<unsigned>(v);
    }

    inline void ResetDominantBaseline() { svg_data_.Access()->dominant_baseline_ = static_cast<unsigned>(EDominantBaseline::kAuto); }
    // app-region
    EDraggableRegionMode DraggableRegionMode() const
    {
        return static_cast<EDraggableRegionMode>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                     ->rare_non_inherited_usage_less_than_100_percent_data_->draggable_region_mode_);
    }

    void SetDraggableRegionMode(EDraggableRegionMode v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->draggable_region_mode_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->draggable_region_mode_
                = static_cast<unsigned>(v);
    }

    inline void ResetDraggableRegionMode()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->draggable_region_mode_
            = static_cast<unsigned>(EDraggableRegionMode::kNone);
    }
    // EffectiveAppearance
    ControlPart EffectiveAppearance() const
    {
        return static_cast<ControlPart>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_);
    }

    void SetEffectiveAppearance(ControlPart v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->effective_appearance_
                = static_cast<unsigned>(v);
    }

    inline void ResetEffectiveAppearance()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->effective_appearance_
            = static_cast<unsigned>(kNoControlPart);
    }
    // EffectiveTouchAction

    inline void ResetEffectiveTouchAction()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->effective_touch_action_
            = static_cast<unsigned>(TouchAction::kAuto);
    }
    // EffectiveZIndexZero
    bool EffectiveZIndexZero() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_);
    }

    void SetEffectiveZIndexZero(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->effective_z_index_zero_
                = static_cast<unsigned>(v);
    }

    inline void ResetEffectiveZIndexZero()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->effective_z_index_zero_
            = static_cast<unsigned>(false);
    }
    // EffectiveZoom
    float EffectiveZoom() const { return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_; }
    inline void ResetEffectiveZoom()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->effective_zoom_ = 1.0f;
    }
    // empty-cells
    EEmptyCells EmptyCells() const { return static_cast<EEmptyCells>(empty_cells_); }

    void SetEmptyCells(EEmptyCells v) { empty_cells_ = static_cast<unsigned>(v); }

    inline void ResetEmptyCells() { empty_cells_ = static_cast<unsigned>(EEmptyCells::kShow); }
    // empty-cells
    bool EmptyCellsIsInherited() const { return static_cast<bool>(empty_cells_is_inherited_); }

    void SetEmptyCellsIsInherited(bool v) { empty_cells_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetEmptyCellsIsInherited() { empty_cells_is_inherited_ = static_cast<unsigned>(true); }
    // fill-opacity
    float FillOpacity() const { return svg_data_->fill_data_->fill_opacity_; }

    void SetFillOpacity(float v)
    {
        if (!(svg_data_->fill_data_->fill_opacity_ == v))
            svg_data_.Access()->fill_data_.Access()->fill_opacity_ = v;
    }

    inline void ResetFillOpacity() { svg_data_.Access()->fill_data_.Access()->fill_opacity_ = 1; }
    // fill
    const SVGPaint& FillPaint() const { return svg_data_->fill_data_->fill_paint_; }

    void SetFillPaint(const SVGPaint& v)
    {
        if (!(svg_data_->fill_data_->fill_paint_ == v))
            svg_data_.Access()->fill_data_.Access()->fill_paint_ = v;
    }

    void SetFillPaint(SVGPaint&& v)
    {
        if (!(svg_data_->fill_data_->fill_paint_ == v))
            svg_data_.Access()->fill_data_.Access()->fill_paint_ = std::move(v);
    }
    inline void ResetFillPaint() { svg_data_.Access()->fill_data_.Access()->fill_paint_ = SVGPaint(Color::kBlack); }

    // fill-rule
    WindRule FillRule() const { return static_cast<WindRule>(svg_data_->fill_rule_); }

    void SetFillRule(WindRule v)
    {
        if (!(svg_data_->fill_rule_ == static_cast<unsigned>(v)))
            svg_data_.Access()->fill_rule_ = static_cast<unsigned>(v);
    }

    inline void ResetFillRule() { svg_data_.Access()->fill_rule_ = static_cast<unsigned>(RULE_NONZERO); }
    // filter

    inline void ResetFilter()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->filter_
            = MakeGarbageCollected<StyleFilterData>();
    }

    // FirstLineDependsOnSizeContainerQueries
    bool FirstLineDependsOnSizeContainerQueries() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->first_line_depends_on_size_container_queries_);
    }

    void SetFirstLineDependsOnSizeContainerQueries(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->first_line_depends_on_size_container_queries_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->first_line_depends_on_size_container_queries_
                = static_cast<unsigned>(v);
    }

    inline void ResetFirstLineDependsOnSizeContainerQueries()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->first_line_depends_on_size_container_queries_
            = static_cast<unsigned>(false);
    }
    // flex-basis
    const Length& FlexBasis() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_; }

    void SetFlexBasis(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_basis_ = v;
    }

    void SetFlexBasis(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_basis_ = std::move(v);
    }
    inline void ResetFlexBasis()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_basis_ = Length::Auto();
    }

    // flex-direction
    EFlexDirection FlexDirection() const { return static_cast<EFlexDirection>(rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_); }

    void SetFlexDirection(EFlexDirection v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->flex_direction_ = static_cast<unsigned>(v);
    }

    inline void ResetFlexDirection() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->flex_direction_ = static_cast<unsigned>(EFlexDirection::kRow); }
    // flex-grow
    float FlexGrow() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_; }

    void SetFlexGrow(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_grow_ = v;
    }

    inline void ResetFlexGrow() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_grow_ = 0.0f; }
    // flex-shrink
    float FlexShrink() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_; }

    void SetFlexShrink(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_shrink_ = v;
    }

    inline void ResetFlexShrink()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_shrink_ = 1.0f;
    }
    // flex-wrap
    EFlexWrap FlexWrap() const { return static_cast<EFlexWrap>(rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_); }

    void SetFlexWrap(EFlexWrap v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->flex_wrap_ = static_cast<unsigned>(v);
    }

    inline void ResetFlexWrap() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->flex_wrap_ = static_cast<unsigned>(EFlexWrap::kNowrap); }
    // float

    void SetFloating(EFloat v) { floating_ = static_cast<unsigned>(v); }

    inline void ResetFloating() { floating_ = static_cast<unsigned>(EFloat::kNone); }
    // flood-color
    const StyleColor& FloodColor() const { return svg_data_->misc_data_->flood_color_; }

    void SetFloodColor(const StyleColor& v)
    {
        if (!(svg_data_->misc_data_->flood_color_ == v))
            svg_data_.Access()->misc_data_.Access()->flood_color_ = v;
    }

    void SetFloodColor(StyleColor&& v)
    {
        if (!(svg_data_->misc_data_->flood_color_ == v))
            svg_data_.Access()->misc_data_.Access()->flood_color_ = std::move(v);
    }
    inline void ResetFloodColor() { svg_data_.Access()->misc_data_.Access()->flood_color_ = StyleColor(Color::kBlack); }

    // flood-opacity
    float FloodOpacity() const { return svg_data_->misc_data_->flood_opacity_; }

    void SetFloodOpacity(float v)
    {
        if (!(svg_data_->misc_data_->flood_opacity_ == v))
            svg_data_.Access()->misc_data_.Access()->flood_opacity_ = v;
    }

    inline void ResetFloodOpacity() { svg_data_.Access()->misc_data_.Access()->flood_opacity_ = 1; }
    // font

    inline void ResetFont() { inherited_data_.Access()->font_data_.Access()->font_ = Font(); }

    // forced-color-adjust
    EForcedColorAdjust ForcedColorAdjust() const { return static_cast<EForcedColorAdjust>(rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_); }

    void SetForcedColorAdjust(EForcedColorAdjust v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->forced_color_adjust_ = static_cast<unsigned>(v);
    }

    inline void ResetForcedColorAdjust() { rare_inherited_usage_less_than_64_percent_data_.Access()->forced_color_adjust_ = static_cast<unsigned>(EForcedColorAdjust::kAuto); }
    // grid-auto-columns
    const GridTrackList& GridAutoColumns() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->grid_auto_columns_;
    }

    void SetGridAutoColumns(const GridTrackList& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_auto_columns_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_auto_columns_
                = v;
    }

    void SetGridAutoColumns(GridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_auto_columns_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_auto_columns_
                = std::move(v);
    }
    inline void ResetGridAutoColumns()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_auto_columns_
            = GridTrackList(GridTrackSize(Length::Auto()));
    }

    // grid-auto-flow

    void SetGridAutoFlow(GridAutoFlow v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_auto_flow_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_auto_flow_
                = static_cast<unsigned>(v);
    }

    inline void ResetGridAutoFlow()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_auto_flow_
            = static_cast<unsigned>(kAutoFlowRow);
    }
    // grid-auto-rows
    const GridTrackList& GridAutoRows() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->grid_auto_rows_;
    }

    void SetGridAutoRows(const GridTrackList& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_auto_rows_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_auto_rows_
                = v;
    }

    void SetGridAutoRows(GridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_auto_rows_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_auto_rows_
                = std::move(v);
    }
    inline void ResetGridAutoRows()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_auto_rows_
            = GridTrackList(GridTrackSize(Length::Auto()));
    }

    // grid-column-end
    const GridPosition& GridColumnEnd() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->grid_column_end_;
    }

    void SetGridColumnEnd(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_column_end_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_column_end_
                = v;
    }

    void SetGridColumnEnd(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_column_end_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_column_end_
                = std::move(v);
    }
    inline void ResetGridColumnEnd()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_column_end_
            = GridPosition();
    }

    // grid-column-start
    const GridPosition& GridColumnStart() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->grid_column_start_;
    }

    void SetGridColumnStart(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_column_start_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_column_start_
                = v;
    }

    void SetGridColumnStart(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_column_start_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_column_start_
                = std::move(v);
    }
    inline void ResetGridColumnStart()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_column_start_
            = GridPosition();
    }

    // grid-row-end
    const GridPosition& GridRowEnd() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->grid_row_end_;
    }

    void SetGridRowEnd(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_row_end_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_row_end_
                = v;
    }

    void SetGridRowEnd(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_row_end_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_row_end_
                = std::move(v);
    }
    inline void ResetGridRowEnd()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_row_end_
            = GridPosition();
    }

    // grid-row-start
    const GridPosition& GridRowStart() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->grid_row_start_;
    }

    void SetGridRowStart(const GridPosition& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_row_start_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_row_start_
                = v;
    }

    void SetGridRowStart(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_row_start_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_row_start_
                = std::move(v);
    }
    inline void ResetGridRowStart()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_row_start_
            = GridPosition();
    }

    // grid-template-columns
    const ComputedGridTrackList& GridTemplateColumns() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_;
    }

    void SetGridTemplateColumns(const ComputedGridTrackList& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->grid_template_columns_
                = v;
    }

    void SetGridTemplateColumns(ComputedGridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->grid_template_columns_
                = std::move(v);
    }
    inline void ResetGridTemplateColumns()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->grid_data_.Access()->grid_template_columns_
            = ComputedGridTrackList();
    }

    // grid-template-rows
    const ComputedGridTrackList& GridTemplateRows() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_;
    }

    void SetGridTemplateRows(const ComputedGridTrackList& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->grid_data_.Access()->grid_template_rows_
                = v;
    }

    void SetGridTemplateRows(ComputedGridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->grid_data_.Access()->grid_template_rows_
                = std::move(v);
    }
    inline void ResetGridTemplateRows()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->grid_data_.Access()->grid_template_rows_
            = ComputedGridTrackList();
    }

    // HasAttrContent
    bool HasAttrContent() const { return static_cast<bool>(has_attr_content_); }

    void SetHasAttrContent() { has_attr_content_ = static_cast<unsigned>(true); }
    // HasAuthorBackground
    bool HasAuthorBackground() const { return static_cast<bool>(has_author_background_); }

    void SetHasAuthorBackground() { has_author_background_ = static_cast<unsigned>(true); }
    // HasAuthorBorder
    bool HasAuthorBorder() const { return static_cast<bool>(has_author_border_); }

    void SetHasAuthorBorder() { has_author_border_ = static_cast<unsigned>(true); }
    // HasAuthorBorderRadius
    bool HasAuthorBorderRadius() const { return static_cast<bool>(has_author_border_radius_); }

    void SetHasAuthorBorderRadius() { has_author_border_radius_ = static_cast<unsigned>(true); }
    // HasAuthorHighlightColors
    bool HasAuthorHighlightColors() const { return static_cast<bool>(has_author_highlight_colors_); }

    void SetHasAuthorHighlightColors() { has_author_highlight_colors_ = static_cast<unsigned>(true); }
    // HasAutoClip
    bool HasAutoClip() const { return static_cast<bool>(visual_data_->has_auto_clip_); }
    inline void ResetHasAutoClip() { visual_data_.Access()->has_auto_clip_ = static_cast<unsigned>(true); }
    // HasAutoColumnCount
    bool HasAutoColumnCount() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_);
    }
    inline void ResetHasAutoColumnCount()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_auto_column_count_
            = static_cast<unsigned>(true);
    }
    // HasAutoColumnWidth
    bool HasAutoColumnWidth() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_);
    }
    inline void ResetHasAutoColumnWidth()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_auto_column_width_
            = static_cast<unsigned>(true);
    }
    // HasAutoZIndex
    bool HasAutoZIndex() const { return static_cast<bool>(box_data_->has_auto_z_index_); }
    inline void ResetHasAutoZIndex() { box_data_.Access()->has_auto_z_index_ = static_cast<unsigned>(true); }
    // HasClipPath
    bool HasClipPath() const { return static_cast<bool>(visual_data_->has_clip_path_); }

    void SetHasClipPath(bool v)
    {
        if (!(visual_data_->has_clip_path_ == static_cast<unsigned>(v)))
            visual_data_.Access()->has_clip_path_ = static_cast<unsigned>(v);
    }

    inline void ResetHasClipPath() { visual_data_.Access()->has_clip_path_ = static_cast<unsigned>(false); }
    // HasContainerRelativeUnits
    bool HasContainerRelativeUnits() const { return static_cast<bool>(has_container_relative_units_); }

    void SetHasContainerRelativeUnits() { has_container_relative_units_ = static_cast<unsigned>(true); }
    // HasCurrentBackdropFilterAnimation
    bool HasCurrentBackdropFilterAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_backdrop_filter_animation_);
    }

    void SetHasCurrentBackdropFilterAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_backdrop_filter_animation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_backdrop_filter_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentBackdropFilterAnimation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_backdrop_filter_animation_
            = static_cast<unsigned>(false);
    }
    // HasCurrentBackgroundColorAnimation
    bool HasCurrentBackgroundColorAnimation() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_background_color_animation_);
    }

    void SetHasCurrentBackgroundColorAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_background_color_animation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_background_color_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentBackgroundColorAnimation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_background_color_animation_
            = static_cast<unsigned>(false);
    }
    // HasCurrentClipPathAnimation
    bool HasCurrentClipPathAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_clip_path_animation_);
    }

    void SetHasCurrentClipPathAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_clip_path_animation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_clip_path_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentClipPathAnimation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_clip_path_animation_
            = static_cast<unsigned>(false);
    }
    // HasCurrentFilterAnimation
    bool HasCurrentFilterAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_);
    }

    void SetHasCurrentFilterAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_filter_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentFilterAnimation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_filter_animation_
            = static_cast<unsigned>(false);
    }
    // HasCurrentOpacityAnimation
    bool HasCurrentOpacityAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_);
    }

    void SetHasCurrentOpacityAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_opacity_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentOpacityAnimation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_opacity_animation_
            = static_cast<unsigned>(false);
    }
    // HasCurrentRotateAnimation
    bool HasCurrentRotateAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_);
    }

    void SetHasCurrentRotateAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_rotate_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentRotateAnimation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_rotate_animation_
            = static_cast<unsigned>(false);
    }
    // HasCurrentScaleAnimation
    bool HasCurrentScaleAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_);
    }

    void SetHasCurrentScaleAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_scale_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentScaleAnimation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_scale_animation_
            = static_cast<unsigned>(false);
    }
    // HasCurrentTransformAnimation
    bool HasCurrentTransformAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_);
    }

    void SetHasCurrentTransformAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_transform_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentTransformAnimation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_transform_animation_
            = static_cast<unsigned>(false);
    }
    // HasCurrentTranslateAnimation
    bool HasCurrentTranslateAnimation() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_);
    }

    void SetHasCurrentTranslateAnimation(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_translate_animation_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasCurrentTranslateAnimation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_translate_animation_
            = static_cast<unsigned>(false);
    }
    // HasEmUnits
    bool HasEmUnits() const { return static_cast<bool>(has_em_units_); }

    void SetHasEmUnits() { has_em_units_ = static_cast<unsigned>(true); }
    // HasExplicitInheritance
    bool HasExplicitInheritance() const { return static_cast<bool>(has_explicit_inheritance_); }

    void SetHasExplicitInheritance() { has_explicit_inheritance_ = static_cast<unsigned>(true); }
    // HasExplicitOverflowXVisible
    bool HasExplicitOverflowXVisible() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_);
    }
    inline void ResetHasExplicitOverflowXVisible()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_explicit_overflow_x_visible_
            = static_cast<unsigned>(false);
    }
    // HasExplicitOverflowYVisible
    bool HasExplicitOverflowYVisible() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_);
    }
    inline void ResetHasExplicitOverflowYVisible()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_explicit_overflow_y_visible_
            = static_cast<unsigned>(false);
    }
    // HasGlyphRelativeUnits
    bool HasGlyphRelativeUnits() const { return static_cast<bool>(has_glyph_relative_units_); }

    void SetHasGlyphRelativeUnits() { has_glyph_relative_units_ = static_cast<unsigned>(true); }
    // HasLineHeightRelativeUnits
    bool HasLineHeightRelativeUnits() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_line_height_relative_units_);
    }

    void SetHasLineHeightRelativeUnits()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_line_height_relative_units_
                == static_cast<unsigned>(true)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_line_height_relative_units_
                = static_cast<unsigned>(true);
    }
    // -internal-empty-line-height
    bool HasLineIfEmpty() const
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_);
    }

    void SetHasLineIfEmpty(bool v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->has_line_if_empty_ = static_cast<unsigned>(v);
    }

    inline void ResetHasLineIfEmpty()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->has_line_if_empty_ = static_cast<unsigned>(false);
    }
    // HasNonUniversalHighlightPseudoStyles
    bool HasNonUniversalHighlightPseudoStyles() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_non_universal_highlight_pseudo_styles_);
    }

    void SetHasNonUniversalHighlightPseudoStyles(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_non_universal_highlight_pseudo_styles_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->has_non_universal_highlight_pseudo_styles_
                = static_cast<unsigned>(v);
    }

    inline void ResetHasNonUniversalHighlightPseudoStyles()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_non_universal_highlight_pseudo_styles_
            = static_cast<unsigned>(false);
    }
    // HasRemUnits
    bool HasRemUnits() const { return static_cast<bool>(has_rem_units_); }

    void SetHasRemUnits() { has_rem_units_ = static_cast<unsigned>(true); }
    // HasSimpleUnderline

    inline void ResetHasSimpleUnderline() { has_simple_underline_ = static_cast<unsigned>(false); }
    // HasVariableDeclaration
    bool HasVariableDeclaration() const { return static_cast<bool>(has_variable_declaration_); }

    void SetHasVariableDeclaration() { has_variable_declaration_ = static_cast<unsigned>(true); }
    // HasVariableReference
    bool HasVariableReference() const { return static_cast<bool>(has_variable_reference_); }

    void SetHasVariableReference() { has_variable_reference_ = static_cast<unsigned>(true); }
    // HasVariableReferenceFromNonInheritedProperty
    bool HasVariableReferenceFromNonInheritedProperty() const { return static_cast<bool>(has_variable_reference_from_non_inherited_property_); }

    void SetHasVariableReferenceFromNonInheritedProperty() { has_variable_reference_from_non_inherited_property_ = static_cast<unsigned>(true); }
    // height
    const Length& Height() const { return box_data_->height_; }

    void SetHeight(const Length& v)
    {
        if (!(box_data_->height_ == v))
            box_data_.Access()->height_ = v;
    }

    void SetHeight(Length&& v)
    {
        if (!(box_data_->height_ == v))
            box_data_.Access()->height_ = std::move(v);
    }
    inline void ResetHeight() { box_data_.Access()->height_ = Length(); }

    // -webkit-highlight
    const AtomicString& Highlight() const { return rare_inherited_usage_less_than_64_percent_data_->highlight_; }

    void SetHighlight(const AtomicString& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->highlight_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->highlight_ = v;
    }

    void SetHighlight(AtomicString&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->highlight_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->highlight_ = std::move(v);
    }
    inline void ResetHighlight() { rare_inherited_usage_less_than_64_percent_data_.Access()->highlight_ = g_null_atom; }

    // HighlightData
    const scoped_refptr<StyleHighlightData>& HighlightData() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_;
    }
    inline void ResetHighlightData()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->highlight_data_ = nullptr;
    }

    // -webkit-border-horizontal-spacing
    short HorizontalBorderSpacing() const { return inherited_data_->horizontal_border_spacing_; }

    void SetHorizontalBorderSpacing(short v)
    {
        if (!(inherited_data_->horizontal_border_spacing_ == v))
            inherited_data_.Access()->horizontal_border_spacing_ = v;
    }

    inline void ResetHorizontalBorderSpacing() { inherited_data_.Access()->horizontal_border_spacing_ = 0; }
    // hyphenate-limit-chars
    const StyleHyphenateLimitChars& HyphenateLimitChars() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_;
    }

    void SetHyphenateLimitChars(const StyleHyphenateLimitChars& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->hyphenate_limit_chars_ = v;
    }

    void SetHyphenateLimitChars(StyleHyphenateLimitChars&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->hyphenate_limit_chars_ = std::move(v);
    }
    inline void ResetHyphenateLimitChars()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->hyphenate_limit_chars_ = StyleHyphenateLimitChars();
    }

    // hyphenate-character
    const AtomicString& HyphenationString() const { return rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_; }

    void SetHyphenationString(const AtomicString& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->hyphenation_string_ = v;
    }

    void SetHyphenationString(AtomicString&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->hyphenation_string_ = std::move(v);
    }
    inline void ResetHyphenationString() { rare_inherited_usage_less_than_64_percent_data_.Access()->hyphenation_string_ = AtomicString(); }

    // hyphens
    Hyphens GetHyphens() const { return static_cast<Hyphens>(rare_inherited_usage_less_than_64_percent_data_->hyphens_); }

    void SetHyphens(Hyphens v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->hyphens_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->hyphens_ = static_cast<unsigned>(v);
    }

    inline void ResetHyphens() { rare_inherited_usage_less_than_64_percent_data_.Access()->hyphens_ = static_cast<unsigned>(Hyphens::kManual); }
    // image-rendering
    EImageRendering ImageRendering() const { return static_cast<EImageRendering>(rare_inherited_usage_less_than_64_percent_data_->image_rendering_); }

    void SetImageRendering(EImageRendering v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->image_rendering_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->image_rendering_ = static_cast<unsigned>(v);
    }

    inline void ResetImageRendering() { rare_inherited_usage_less_than_64_percent_data_.Access()->image_rendering_ = static_cast<unsigned>(EImageRendering::kAuto); }
    // ImplicitNamedGridColumnLines
    const NamedGridLinesMap& ImplicitNamedGridColumnLines() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_column_lines_;
    }

    void SetImplicitNamedGridColumnLines(const NamedGridLinesMap& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_column_lines_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->implicit_named_grid_column_lines_
                = v;
    }

    void SetImplicitNamedGridColumnLines(NamedGridLinesMap&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_column_lines_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->implicit_named_grid_column_lines_
                = std::move(v);
    }
    inline void ResetImplicitNamedGridColumnLines()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->implicit_named_grid_column_lines_
            = NamedGridLinesMap();
    }

    // ImplicitNamedGridRowLines
    const NamedGridLinesMap& ImplicitNamedGridRowLines() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_row_lines_;
    }

    void SetImplicitNamedGridRowLines(const NamedGridLinesMap& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_row_lines_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->implicit_named_grid_row_lines_
                = v;
    }

    void SetImplicitNamedGridRowLines(NamedGridLinesMap&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_row_lines_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->implicit_named_grid_row_lines_
                = std::move(v);
    }
    inline void ResetImplicitNamedGridRowLines()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->implicit_named_grid_row_lines_
            = NamedGridLinesMap();
    }

    // InForcedColorsMode
    bool InForcedColorsMode() const { return static_cast<bool>(inherited_data_->in_forced_colors_mode_); }

    void SetInForcedColorsMode(bool v)
    {
        if (!(inherited_data_->in_forced_colors_mode_ == static_cast<unsigned>(v)))
            inherited_data_.Access()->in_forced_colors_mode_ = static_cast<unsigned>(v);
    }

    inline void ResetInForcedColorsMode() { inherited_data_.Access()->in_forced_colors_mode_ = static_cast<unsigned>(false); }
    // InheritedVariables

    inline void ResetInheritedVariables() { inherited_data_.Access()->inherited_variables_ = nullptr; }

    // InitialData
    const scoped_refptr<StyleInitialData>& InitialData() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_;
    }
    inline void ResetInitialData()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->initial_data_ = nullptr;
    }

    // initial-letter
    const StyleInitialLetter& InitialLetter() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_;
    }

    void SetInitialLetter(const StyleInitialLetter& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->initial_letter_ = v;
    }

    void SetInitialLetter(StyleInitialLetter&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->initial_letter_ = std::move(v);
    }
    inline void ResetInitialLetter()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->initial_letter_ = StyleInitialLetter();
    }

    // InlineStyleLostCascade
    bool InlineStyleLostCascade() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_style_lost_cascade_);
    }

    void SetInlineStyleLostCascade(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->inline_style_lost_cascade_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->inline_style_lost_cascade_
                = static_cast<unsigned>(v);
    }

    inline void ResetInlineStyleLostCascade()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->inline_style_lost_cascade_
            = static_cast<unsigned>(false);
    }
    // InsideFragmentationContextWithNondeterministicEngine
    bool InsideFragmentationContextWithNondeterministicEngine() const { return static_cast<bool>(inside_fragmentation_context_with_nondeterministic_engine_); }

    void SetInsideFragmentationContextWithNondeterministicEngine(bool v) { inside_fragmentation_context_with_nondeterministic_engine_ = static_cast<unsigned>(v); }

    inline void ResetInsideFragmentationContextWithNondeterministicEngine() { inside_fragmentation_context_with_nondeterministic_engine_ = static_cast<unsigned>(false); }
    // InsideLink
    EInsideLink InsideLink() const { return static_cast<EInsideLink>(inside_link_); }

    void SetInsideLink(EInsideLink v) { inside_link_ = static_cast<unsigned>(v); }

    inline void ResetInsideLink() { inside_link_ = static_cast<unsigned>(EInsideLink::kNotInsideLink); }
    // -internal-forced-background-color

    void SetInternalForcedBackgroundColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_background_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->forced_colors_data_.Access()
                ->internal_forced_background_color_
                = v;
    }

    void SetInternalForcedBackgroundColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_background_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->forced_colors_data_.Access()
                ->internal_forced_background_color_
                = std::move(v);
    }
    inline void ResetInternalForcedBackgroundColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->forced_colors_data_.Access()
            ->internal_forced_background_color_
            = StyleColor(CSSValueID::kCanvas);
    }

    // -internal-forced-border-color

    void SetInternalForcedBorderColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_border_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->forced_colors_data_.Access()
                ->internal_forced_border_color_
                = v;
    }

    void SetInternalForcedBorderColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_border_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->forced_colors_data_.Access()
                ->internal_forced_border_color_
                = std::move(v);
    }
    inline void ResetInternalForcedBorderColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->forced_colors_data_.Access()
            ->internal_forced_border_color_
            = StyleColor::CurrentColor();
    }

    // -internal-forced-color

    void SetInternalForcedColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_forced_colors_data_.Access()
                ->internal_forced_color_
                = v;
    }

    void SetInternalForcedColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_forced_colors_data_.Access()
                ->internal_forced_color_
                = std::move(v);
    }
    inline void ResetInternalForcedColor()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_forced_colors_data_.Access()
            ->internal_forced_color_
            = StyleColor(CSSValueID::kCanvastext);
    }

    // -internal-forced-outline-color

    void SetInternalForcedOutlineColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_outline_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->forced_colors_data_.Access()
                ->internal_forced_outline_color_
                = v;
    }

    void SetInternalForcedOutlineColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_outline_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->forced_colors_data_.Access()
                ->internal_forced_outline_color_
                = std::move(v);
    }
    inline void ResetInternalForcedOutlineColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->forced_colors_data_.Access()
            ->internal_forced_outline_color_
            = StyleColor::CurrentColor();
    }

    // -internal-forced-visited-color

    inline void ResetInternalForcedVisitedColor()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_forced_colors_data_.Access()
            ->internal_forced_visited_color_
            = StyleColor(CSSValueID::kCanvastext);
    }

    // -internal-visited-background-color

    inline void ResetInternalVisitedBackgroundColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_background_color_
            = StyleColor(Color::kTransparent);
    }

    // -internal-visited-border-bottom-color

    inline void ResetInternalVisitedBorderBottomColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_border_bottom_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-border-left-color

    inline void ResetInternalVisitedBorderLeftColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_border_left_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-border-right-color

    inline void ResetInternalVisitedBorderRightColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_border_right_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-border-top-color

    inline void ResetInternalVisitedBorderTopColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_border_top_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-caret-color

    void SetInternalVisitedCaretColor(const StyleAutoColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_caret_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_visited_data_.Access()
                ->internal_visited_caret_color_
                = v;
    }

    void SetInternalVisitedCaretColor(StyleAutoColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_caret_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_visited_data_.Access()
                ->internal_visited_caret_color_
                = std::move(v);
    }
    inline void ResetInternalVisitedCaretColor()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_visited_data_.Access()
            ->internal_visited_caret_color_
            = StyleAutoColor::AutoColor();
    }

    // -internal-visited-color

    inline void ResetInternalVisitedColor() { inherited_data_.Access()->internal_visited_color_ = StyleColor(Color::kBlack); }

    // InternalVisitedColorIsCurrentColor

    void SetInternalVisitedColorIsCurrentColor(bool v)
    {
        if (!(inherited_data_->internal_visited_color_is_current_color_ == static_cast<unsigned>(v)))
            inherited_data_.Access()->internal_visited_color_is_current_color_ = static_cast<unsigned>(v);
    }

    inline void ResetInternalVisitedColorIsCurrentColor() { inherited_data_.Access()->internal_visited_color_is_current_color_ = static_cast<unsigned>(true); }
    // -internal-visited-column-rule-color

    inline void ResetInternalVisitedColumnRuleColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_column_rule_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-fill
    const SVGPaint& InternalVisitedFillPaint() const { return svg_data_->fill_data_->internal_visited_fill_paint_; }

    void SetInternalVisitedFillPaint(const SVGPaint& v)
    {
        if (!(svg_data_->fill_data_->internal_visited_fill_paint_ == v))
            svg_data_.Access()->fill_data_.Access()->internal_visited_fill_paint_ = v;
    }

    void SetInternalVisitedFillPaint(SVGPaint&& v)
    {
        if (!(svg_data_->fill_data_->internal_visited_fill_paint_ == v))
            svg_data_.Access()->fill_data_.Access()->internal_visited_fill_paint_ = std::move(v);
    }
    inline void ResetInternalVisitedFillPaint() { svg_data_.Access()->fill_data_.Access()->internal_visited_fill_paint_ = SVGPaint(Color::kBlack); }

    // -internal-visited-outline-color

    inline void ResetInternalVisitedOutlineColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_outline_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-stroke
    const SVGPaint& InternalVisitedStrokePaint() const { return svg_data_->stroke_data_->internal_visited_stroke_paint_; }

    void SetInternalVisitedStrokePaint(const SVGPaint& v)
    {
        if (!(svg_data_->stroke_data_->internal_visited_stroke_paint_ == v))
            svg_data_.Access()->stroke_data_.Access()->internal_visited_stroke_paint_ = v;
    }

    void SetInternalVisitedStrokePaint(SVGPaint&& v)
    {
        if (!(svg_data_->stroke_data_->internal_visited_stroke_paint_ == v))
            svg_data_.Access()->stroke_data_.Access()->internal_visited_stroke_paint_ = std::move(v);
    }
    inline void ResetInternalVisitedStrokePaint() { svg_data_.Access()->stroke_data_.Access()->internal_visited_stroke_paint_ = SVGPaint(); }

    // -internal-visited-text-decoration-color

    inline void ResetInternalVisitedTextDecorationColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_text_decoration_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-text-emphasis-color

    inline void ResetInternalVisitedTextEmphasisColor()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_visited_data_.Access()
            ->internal_visited_text_emphasis_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-text-fill-color

    inline void ResetInternalVisitedTextFillColor()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_visited_data_.Access()
            ->internal_visited_text_fill_color_
            = StyleColor::CurrentColor();
    }

    // -internal-visited-text-stroke-color

    inline void ResetInternalVisitedTextStrokeColor()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_visited_data_.Access()
            ->internal_visited_text_stroke_color_
            = StyleColor::CurrentColor();
    }

    // IsEnsuredInDisplayNone
    bool IsEnsuredInDisplayNone() const { return static_cast<bool>(is_ensured_in_display_none_); }

    void SetIsEnsuredInDisplayNone() { is_ensured_in_display_none_ = static_cast<unsigned>(true); }
    // IsEnsuredOutsideFlatTree
    bool IsEnsuredOutsideFlatTree() const { return static_cast<bool>(is_ensured_outside_flat_tree_); }

    void SetIsEnsuredOutsideFlatTree() { is_ensured_outside_flat_tree_ = static_cast<unsigned>(true); }
    // IsFlexOrGridItem
    bool IsFlexOrGridItem() const { return static_cast<bool>(is_flex_or_grid_item_); }

    void SetIsFlexOrGridItem() { is_flex_or_grid_item_ = static_cast<unsigned>(true); }
    // IsFlexOrGridOrCustomItem
    bool IsFlexOrGridOrCustomItem() const { return static_cast<bool>(is_flex_or_grid_or_custom_item_); }

    void SetIsFlexOrGridOrCustomItem() { is_flex_or_grid_or_custom_item_ = static_cast<unsigned>(true); }
    // IsInBlockifyingDisplay
    bool IsInBlockifyingDisplay() const { return static_cast<bool>(is_in_blockifying_display_); }

    void SetIsInBlockifyingDisplay() { is_in_blockifying_display_ = static_cast<unsigned>(true); }
    // IsInert
    bool IsInert() const { return static_cast<bool>(is_inert_); }

    void SetIsInert(bool v) { is_inert_ = static_cast<unsigned>(v); }

    inline void ResetIsInert() { is_inert_ = static_cast<unsigned>(false); }
    // IsInert
    bool IsInertIsInherited() const { return static_cast<bool>(is_inert_is_inherited_); }

    void SetIsInertIsInherited(bool v) { is_inert_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetIsInertIsInherited() { is_inert_is_inherited_ = static_cast<unsigned>(true); }
    // IsInsideListElement
    bool IsInsideListElement() const { return static_cast<bool>(is_inside_list_element_); }

    void SetIsInsideListElement() { is_inside_list_element_ = static_cast<unsigned>(true); }
    // IsLink
    bool IsLink() const { return static_cast<bool>(is_link_); }

    void SetIsLink() { is_link_ = static_cast<unsigned>(true); }
    // IsRunningBackdropFilterAnimationOnCompositor
    bool IsRunningBackdropFilterAnimationOnCompositor() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_backdrop_filter_animation_on_compositor_);
    }

    void SetIsRunningBackdropFilterAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_backdrop_filter_animation_on_compositor_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->is_running_backdrop_filter_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningBackdropFilterAnimationOnCompositor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->is_running_backdrop_filter_animation_on_compositor_
            = static_cast<unsigned>(false);
    }
    // IsRunningFilterAnimationOnCompositor
    bool IsRunningFilterAnimationOnCompositor() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_filter_animation_on_compositor_);
    }

    void SetIsRunningFilterAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_filter_animation_on_compositor_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->is_running_filter_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningFilterAnimationOnCompositor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->is_running_filter_animation_on_compositor_
            = static_cast<unsigned>(false);
    }
    // IsRunningOpacityAnimationOnCompositor
    bool IsRunningOpacityAnimationOnCompositor() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_opacity_animation_on_compositor_);
    }

    void SetIsRunningOpacityAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_opacity_animation_on_compositor_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->is_running_opacity_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningOpacityAnimationOnCompositor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->is_running_opacity_animation_on_compositor_
            = static_cast<unsigned>(false);
    }
    // IsRunningRotateAnimationOnCompositor
    bool IsRunningRotateAnimationOnCompositor() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_rotate_animation_on_compositor_);
    }

    void SetIsRunningRotateAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_rotate_animation_on_compositor_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->is_running_rotate_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningRotateAnimationOnCompositor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->is_running_rotate_animation_on_compositor_
            = static_cast<unsigned>(false);
    }
    // IsRunningScaleAnimationOnCompositor
    bool IsRunningScaleAnimationOnCompositor() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_scale_animation_on_compositor_);
    }

    void SetIsRunningScaleAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_scale_animation_on_compositor_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->is_running_scale_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningScaleAnimationOnCompositor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->is_running_scale_animation_on_compositor_
            = static_cast<unsigned>(false);
    }
    // IsRunningTransformAnimationOnCompositor
    bool IsRunningTransformAnimationOnCompositor() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_transform_animation_on_compositor_);
    }

    void SetIsRunningTransformAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_transform_animation_on_compositor_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->is_running_transform_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningTransformAnimationOnCompositor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->is_running_transform_animation_on_compositor_
            = static_cast<unsigned>(false);
    }
    // IsRunningTranslateAnimationOnCompositor
    bool IsRunningTranslateAnimationOnCompositor() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_translate_animation_on_compositor_);
    }

    void SetIsRunningTranslateAnimationOnCompositor(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_running_translate_animation_on_compositor_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->is_running_translate_animation_on_compositor_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsRunningTranslateAnimationOnCompositor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->is_running_translate_animation_on_compositor_
            = static_cast<unsigned>(false);
    }
    // IsSecondaryBodyElement
    bool IsSecondaryBodyElement() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_);
    }

    void SetIsSecondaryBodyElement()
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_
                == static_cast<unsigned>(true)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->is_secondary_body_element_
                = static_cast<unsigned>(true);
    }
    // IsStackingContextWithoutContainment
    bool IsStackingContextWithoutContainment() const { return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->is_stacking_context_without_containment_); }

    void SetIsStackingContextWithoutContainment(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->is_stacking_context_without_containment_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->is_stacking_context_without_containment_ = static_cast<unsigned>(v);
    }

    inline void ResetIsStackingContextWithoutContainment()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->is_stacking_context_without_containment_ = static_cast<unsigned>(false);
    }
    // isolation
    EIsolation Isolation() const
    {
        return static_cast<EIsolation>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                           ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_);
    }

    void SetIsolation(EIsolation v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->isolation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->isolation_
                = static_cast<unsigned>(v);
    }

    inline void ResetIsolation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->isolation_
            = static_cast<unsigned>(EIsolation::kAuto);
    }
    // stroke-linejoin
    LineJoin JoinStyle() const { return static_cast<LineJoin>(svg_data_->stroke_data_->join_style_); }

    void SetJoinStyle(LineJoin v)
    {
        if (!(svg_data_->stroke_data_->join_style_ == static_cast<unsigned>(v)))
            svg_data_.Access()->stroke_data_.Access()->join_style_ = static_cast<unsigned>(v);
    }

    inline void ResetJoinStyle() { svg_data_.Access()->stroke_data_.Access()->join_style_ = static_cast<unsigned>(kMiterJoin); }
    // justify-content
    const StyleContentAlignmentData& JustifyContent() const { return rare_non_inherited_usage_less_than_14_percent_data_->justify_content_; }

    void SetJustifyContent(const StyleContentAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->justify_content_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->justify_content_ = v;
    }

    void SetJustifyContent(StyleContentAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->justify_content_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->justify_content_ = std::move(v);
    }
    inline void ResetJustifyContent()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->justify_content_
            = StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault);
    }

    // justify-items
    const StyleSelfAlignmentData& JustifyItems() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->justify_items_;
    }

    void SetJustifyItems(const StyleSelfAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->justify_items_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->justify_items_
                = v;
    }

    void SetJustifyItems(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->justify_items_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->justify_items_
                = std::move(v);
    }
    inline void ResetJustifyItems()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->justify_items_
            = StyleSelfAlignmentData(ItemPosition::kLegacy, OverflowAlignment::kDefault);
    }

    // justify-self
    const StyleSelfAlignmentData& JustifySelf() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->justify_self_;
    }

    void SetJustifySelf(const StyleSelfAlignmentData& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->justify_self_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->justify_self_
                = v;
    }

    void SetJustifySelf(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->justify_self_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->justify_self_
                = std::move(v);
    }
    inline void ResetJustifySelf()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->justify_self_
            = StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault);
    }

    // left
    const Length& Left() const { return surround_data_->left_; }

    void SetLeft(const Length& v)
    {
        if (!(surround_data_->left_ == v))
            surround_data_.Access()->left_ = v;
    }

    void SetLeft(Length&& v)
    {
        if (!(surround_data_->left_ == v))
            surround_data_.Access()->left_ = std::move(v);
    }
    inline void ResetLeft() { surround_data_.Access()->left_ = Length(); }

    // lighting-color
    const StyleColor& LightingColor() const { return svg_data_->misc_data_->lighting_color_; }

    void SetLightingColor(const StyleColor& v)
    {
        if (!(svg_data_->misc_data_->lighting_color_ == v))
            svg_data_.Access()->misc_data_.Access()->lighting_color_ = v;
    }

    void SetLightingColor(StyleColor&& v)
    {
        if (!(svg_data_->misc_data_->lighting_color_ == v))
            svg_data_.Access()->misc_data_.Access()->lighting_color_ = std::move(v);
    }
    inline void ResetLightingColor() { svg_data_.Access()->misc_data_.Access()->lighting_color_ = StyleColor(Color::kWhite); }

    // -webkit-line-break
    LineBreak GetLineBreak() const { return static_cast<LineBreak>(rare_inherited_usage_less_than_64_percent_data_->line_break_); }

    void SetLineBreak(LineBreak v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->line_break_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->line_break_ = static_cast<unsigned>(v);
    }

    inline void ResetLineBreak() { rare_inherited_usage_less_than_64_percent_data_.Access()->line_break_ = static_cast<unsigned>(LineBreak::kAuto); }
    // -webkit-line-clamp
    const int& LineClamp() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->line_clamp_; }

    void SetLineClamp(const int& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->line_clamp_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->line_clamp_ = v;
    }

    void SetLineClamp(int&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->line_clamp_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->line_clamp_ = std::move(v);
    }
    inline void ResetLineClamp() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->line_clamp_ = 0; }

    // line-height

    void SetLineHeight(const Length& v)
    {
        if (!(inherited_data_->line_height_ == v))
            inherited_data_.Access()->line_height_ = v;
    }

    void SetLineHeight(Length&& v)
    {
        if (!(inherited_data_->line_height_ == v))
            inherited_data_.Access()->line_height_ = std::move(v);
    }
    inline void ResetLineHeight() { inherited_data_.Access()->line_height_ = Length::Percent(-100.0); }

    // line-height-step
    uint8_t LineHeightStep() const { return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->line_height_step_; }

    void SetLineHeightStep(uint8_t v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->line_height_step_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->line_height_step_ = v;
    }

    inline void ResetLineHeightStep()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->line_height_step_ = 0;
    }
    // list-style-image

    inline void ResetListStyleImage() { rare_inherited_usage_less_than_64_percent_data_.Access()->list_style_image_ = nullptr; }

    // list-style-position
    EListStylePosition ListStylePosition() const { return static_cast<EListStylePosition>(list_style_position_); }

    void SetListStylePosition(EListStylePosition v) { list_style_position_ = static_cast<unsigned>(v); }

    inline void ResetListStylePosition() { list_style_position_ = static_cast<unsigned>(EListStylePosition::kOutside); }
    // list-style-position
    bool ListStylePositionIsInherited() const { return static_cast<bool>(list_style_position_is_inherited_); }

    void SetListStylePositionIsInherited(bool v) { list_style_position_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetListStylePositionIsInherited() { list_style_position_is_inherited_ = static_cast<unsigned>(true); }
    // list-style-type
    const Persistent<ListStyleTypeData>& ListStyleType() const { return rare_inherited_usage_less_than_64_percent_data_->list_style_type_; }

    void SetListStyleType(const Persistent<ListStyleTypeData>& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->list_style_type_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->list_style_type_ = v;
    }

    void SetListStyleType(Persistent<ListStyleTypeData>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->list_style_type_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->list_style_type_ = std::move(v);
    }
    inline void ResetListStyleType() { rare_inherited_usage_less_than_64_percent_data_.Access()->list_style_type_ = ListStyleTypeData::CreateCounterStyle("disc", nullptr); }

    // margin-bottom
    const Length& MarginBottom() const { return surround_data_->margin_bottom_; }
    inline void ResetMarginBottom() { surround_data_.Access()->margin_bottom_ = Length::Fixed(); }

    // margin-left
    const Length& MarginLeft() const { return surround_data_->margin_left_; }
    inline void ResetMarginLeft() { surround_data_.Access()->margin_left_ = Length::Fixed(); }

    // margin-right
    const Length& MarginRight() const { return surround_data_->margin_right_; }
    inline void ResetMarginRight() { surround_data_.Access()->margin_right_ = Length::Fixed(); }

    // margin-top
    const Length& MarginTop() const { return surround_data_->margin_top_; }
    inline void ResetMarginTop() { surround_data_.Access()->margin_top_ = Length::Fixed(); }

    // marker-end
    StyleSVGResource* MarkerEndResource() const { return svg_data_->inherited_resources_data_->marker_end_resource_.get(); }

    void SetMarkerEndResource(scoped_refptr<StyleSVGResource> v) { svg_data_.Access()->inherited_resources_data_.Access()->marker_end_resource_ = std::move(v); }

    // marker-mid
    StyleSVGResource* MarkerMidResource() const { return svg_data_->inherited_resources_data_->marker_mid_resource_.get(); }

    void SetMarkerMidResource(scoped_refptr<StyleSVGResource> v) { svg_data_.Access()->inherited_resources_data_.Access()->marker_mid_resource_ = std::move(v); }

    // marker-start
    StyleSVGResource* MarkerStartResource() const { return svg_data_->inherited_resources_data_->marker_start_resource_.get(); }

    void SetMarkerStartResource(scoped_refptr<StyleSVGResource> v) { svg_data_.Access()->inherited_resources_data_.Access()->marker_start_resource_ = std::move(v); }

    // Mask

    inline void ResetMask()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->mask_
            = FillLayer(EFillLayerType::kMask, true);
    }

    // MaskBoxImage

    inline void ResetMaskBoxImage()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->mask_box_image_
            = NinePieceImage::MaskDefaults();
    }

    // mask-type
    EMaskType MaskType() const { return static_cast<EMaskType>(svg_data_->mask_type_); }

    void SetMaskType(EMaskType v)
    {
        if (!(svg_data_->mask_type_ == static_cast<unsigned>(v)))
            svg_data_.Access()->mask_type_ = static_cast<unsigned>(v);
    }

    inline void ResetMaskType() { svg_data_.Access()->mask_type_ = static_cast<unsigned>(EMaskType::kLuminance); }
    // mask
    StyleSVGResource* MaskerResource() const { return svg_data_->masker_resource_.get(); }

    void SetMaskerResource(scoped_refptr<StyleSVGResource> v) { svg_data_.Access()->masker_resource_ = std::move(v); }

    // MathBaseline
    const Length& GetMathBaseline() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_;
    }

    void SetMathBaseline(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_baseline_ = v;
    }

    void SetMathBaseline(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_baseline_
                = std::move(v);
    }
    inline void ResetMathBaseline()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_baseline_
            = Length();
    }

    // math-depth
    short MathDepth() const { return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_; }

    void SetMathDepth(short v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->math_depth_ = v;
    }

    inline void ResetMathDepth() { rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->math_depth_ = 0; }
    // MathFractionBarThickness
    const Length& GetMathFractionBarThickness() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_fraction_bar_thickness_;
    }

    void SetMathFractionBarThickness(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_fraction_bar_thickness_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->math_data_.Access()
                ->math_fraction_bar_thickness_
                = v;
    }

    void SetMathFractionBarThickness(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_fraction_bar_thickness_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->math_data_.Access()
                ->math_fraction_bar_thickness_
                = std::move(v);
    }
    inline void ResetMathFractionBarThickness()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->math_data_.Access()
            ->math_fraction_bar_thickness_
            = Length();
    }

    // MathLSpace
    const Length& GetMathLSpace() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_;
    }

    void SetMathLSpace(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_l_space_ = v;
    }

    void SetMathLSpace(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_l_space_
                = std::move(v);
    }
    inline void ResetMathLSpace()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_l_space_
            = Length();
    }

    // MathMaxSize
    const Length& GetMathMaxSize() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_;
    }

    void SetMathMaxSize(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_max_size_ = v;
    }

    void SetMathMaxSize(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_max_size_
                = std::move(v);
    }
    inline void ResetMathMaxSize()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_max_size_
            = Length();
    }

    // MathMinSize
    const Length& GetMathMinSize() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_;
    }

    void SetMathMinSize(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_min_size_ = v;
    }

    void SetMathMinSize(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_min_size_
                = std::move(v);
    }
    inline void ResetMathMinSize()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_min_size_
            = Length();
    }

    // MathPaddedDepth
    const Length& GetMathPaddedDepth() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_;
    }

    void SetMathPaddedDepth(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_padded_depth_
                = v;
    }

    void SetMathPaddedDepth(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_padded_depth_
                = std::move(v);
    }
    inline void ResetMathPaddedDepth()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_padded_depth_
            = Length();
    }

    // MathPaddedVOffset
    const Length& GetMathPaddedVOffset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_;
    }

    void SetMathPaddedVOffset(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->math_data_.Access()
                ->math_padded_v_offset_
                = v;
    }

    void SetMathPaddedVOffset(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->math_data_.Access()
                ->math_padded_v_offset_
                = std::move(v);
    }
    inline void ResetMathPaddedVOffset()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_padded_v_offset_
            = Length();
    }

    // MathRSpace
    const Length& GetMathRSpace() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_;
    }

    void SetMathRSpace(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_r_space_ = v;
    }

    void SetMathRSpace(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_r_space_
                = std::move(v);
    }
    inline void ResetMathRSpace()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_r_space_
            = Length();
    }

    // math-shift
    EMathShift MathShift() const { return static_cast<EMathShift>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_); }

    void SetMathShift(EMathShift v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->math_shift_ = static_cast<unsigned>(v);
    }

    inline void ResetMathShift()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->math_shift_
            = static_cast<unsigned>(EMathShift::kNormal);
    }
    // math-style
    EMathStyle MathStyle() const { return static_cast<EMathStyle>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_); }

    void SetMathStyle(EMathStyle v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->math_style_ = static_cast<unsigned>(v);
    }

    inline void ResetMathStyle()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->math_style_
            = static_cast<unsigned>(EMathStyle::kNormal);
    }
    // max-height
    const Length& MaxHeight() const { return box_data_->max_height_; }

    void SetMaxHeight(const Length& v)
    {
        if (!(box_data_->max_height_ == v))
            box_data_.Access()->max_height_ = v;
    }

    void SetMaxHeight(Length&& v)
    {
        if (!(box_data_->max_height_ == v))
            box_data_.Access()->max_height_ = std::move(v);
    }
    inline void ResetMaxHeight() { box_data_.Access()->max_height_ = Length::None(); }

    // max-width
    const Length& MaxWidth() const { return box_data_->max_width_; }

    void SetMaxWidth(const Length& v)
    {
        if (!(box_data_->max_width_ == v))
            box_data_.Access()->max_width_ = v;
    }

    void SetMaxWidth(Length&& v)
    {
        if (!(box_data_->max_width_ == v))
            box_data_.Access()->max_width_ = std::move(v);
    }
    inline void ResetMaxWidth() { box_data_.Access()->max_width_ = Length::None(); }

    // MayHaveMargin
    bool MayHaveMargin() const { return static_cast<bool>(surround_data_->may_have_margin_); }

    void SetMayHaveMargin()
    {
        if (!(surround_data_->may_have_margin_ == static_cast<unsigned>(true)))
            surround_data_.Access()->may_have_margin_ = static_cast<unsigned>(true);
    }
    // MayHavePadding
    bool MayHavePadding() const { return static_cast<bool>(surround_data_->may_have_padding_); }

    void SetMayHavePadding()
    {
        if (!(surround_data_->may_have_padding_ == static_cast<unsigned>(true)))
            surround_data_.Access()->may_have_padding_ = static_cast<unsigned>(true);
    }
    // min-height
    const Length& MinHeight() const { return box_data_->min_height_; }

    void SetMinHeight(const Length& v)
    {
        if (!(box_data_->min_height_ == v))
            box_data_.Access()->min_height_ = v;
    }

    void SetMinHeight(Length&& v)
    {
        if (!(box_data_->min_height_ == v))
            box_data_.Access()->min_height_ = std::move(v);
    }
    inline void ResetMinHeight() { box_data_.Access()->min_height_ = Length(); }

    // min-width
    const Length& MinWidth() const { return box_data_->min_width_; }

    void SetMinWidth(const Length& v)
    {
        if (!(box_data_->min_width_ == v))
            box_data_.Access()->min_width_ = v;
    }

    void SetMinWidth(Length&& v)
    {
        if (!(box_data_->min_width_ == v))
            box_data_.Access()->min_width_ = std::move(v);
    }
    inline void ResetMinWidth() { box_data_.Access()->min_width_ = Length(); }

    // NamedGridArea
    const NamedGridAreaMap& NamedGridArea() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_;
    }

    void SetNamedGridArea(const NamedGridAreaMap& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->grid_data_.Access()->named_grid_area_
                = v;
    }

    void SetNamedGridArea(NamedGridAreaMap&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->grid_data_.Access()->named_grid_area_
                = std::move(v);
    }
    inline void ResetNamedGridArea()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->grid_data_.Access()->named_grid_area_
            = NamedGridAreaMap();
    }

    // NamedGridAreaColumnCount
    wtf_size_t NamedGridAreaColumnCount() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_column_count_;
    }

    void SetNamedGridAreaColumnCount(wtf_size_t v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_column_count_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->named_grid_area_column_count_
                = v;
    }

    inline void ResetNamedGridAreaColumnCount()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->named_grid_area_column_count_
            = 0;
    }
    // NamedGridAreaRowCount
    wtf_size_t NamedGridAreaRowCount() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_row_count_;
    }

    void SetNamedGridAreaRowCount(wtf_size_t v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_row_count_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->named_grid_area_row_count_
                = v;
    }

    inline void ResetNamedGridAreaRowCount()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->named_grid_area_row_count_
            = 0;
    }
    // NonInheritedVariables

    inline void ResetNonInheritedVariables()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->non_inherited_variables_ = nullptr;
    }

    // object-fit
    EObjectFit GetObjectFit() const
    {
        return static_cast<EObjectFit>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_);
    }

    void SetObjectFit(EObjectFit v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->object_fit_ = static_cast<unsigned>(v);
    }

    inline void ResetObjectFit()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->object_fit_
            = static_cast<unsigned>(EObjectFit::kFill);
    }
    // object-position
    const LengthPoint& ObjectPosition() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->object_position_;
    }

    void SetObjectPosition(const LengthPoint& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->object_position_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->object_position_
                = v;
    }

    void SetObjectPosition(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->object_position_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->object_position_
                = std::move(v);
    }
    inline void ResetObjectPosition()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->object_position_
            = LengthPoint(Length::Percent(50.0), Length::Percent(50.0));
    }

    // object-view-box
    BasicShape* ObjectViewBox() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_.get();
    }

    void SetObjectViewBox(scoped_refptr<BasicShape> v)
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->object_view_box_ = std::move(v);
    }

    // offset-anchor
    const LengthPoint& OffsetAnchor() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->offset_anchor_;
    }

    void SetOffsetAnchor(const LengthPoint& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_anchor_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_anchor_
                = v;
    }

    void SetOffsetAnchor(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_anchor_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_anchor_
                = std::move(v);
    }
    inline void ResetOffsetAnchor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->offset_anchor_
            = LengthPoint(Length::Auto(), Length::Auto());
    }

    // offset-distance
    const Length& OffsetDistance() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->offset_distance_;
    }

    void SetOffsetDistance(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_distance_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_distance_
                = v;
    }

    void SetOffsetDistance(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_distance_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_distance_
                = std::move(v);
    }
    inline void ResetOffsetDistance()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->offset_distance_
            = Length::Fixed(0);
    }

    // offset-path
    BasicShape* OffsetPath() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->offset_path_.get();
    }

    void SetOffsetPath(scoped_refptr<BasicShape> v)
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->offset_path_
            = std::move(v);
    }

    // offset-position
    const LengthPoint& OffsetPosition() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->offset_position_;
    }

    void SetOffsetPosition(const LengthPoint& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_position_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_position_
                = v;
    }

    void SetOffsetPosition(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_position_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_position_
                = std::move(v);
    }
    inline void ResetOffsetPosition()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->offset_position_
            = LengthPoint(Length::Auto(), Length::Auto());
    }

    // offset-rotate
    const StyleOffsetRotation& OffsetRotate() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->offset_rotate_;
    }

    void SetOffsetRotate(const StyleOffsetRotation& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_rotate_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_rotate_
                = v;
    }

    void SetOffsetRotate(StyleOffsetRotation&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_rotate_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_rotate_
                = std::move(v);
    }
    inline void ResetOffsetRotate()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->offset_rotate_
            = StyleOffsetRotation(0, OffsetRotationType::kAuto);
    }

    // opacity
    float Opacity() const { return rare_non_inherited_usage_less_than_14_percent_data_->opacity_; }
    inline void ResetOpacity() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->opacity_ = 1.0; }
    // order
    int Order() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_; }
    inline void ResetOrder() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->order_ = 0; }
    // origin-trial-test-property
    EOriginTrialTestProperty OriginTrialTestProperty() const { return static_cast<EOriginTrialTestProperty>(origin_trial_test_property_); }

    void SetOriginTrialTestProperty(EOriginTrialTestProperty v) { origin_trial_test_property_ = static_cast<unsigned>(v); }

    inline void ResetOriginTrialTestProperty() { origin_trial_test_property_ = static_cast<unsigned>(EOriginTrialTestProperty::kNormal); }
    // OriginalDisplay
    EDisplay OriginalDisplay() const { return static_cast<EDisplay>(original_display_); }

    void SetOriginalDisplay(EDisplay v) { original_display_ = static_cast<unsigned>(v); }

    inline void ResetOriginalDisplay() { original_display_ = static_cast<unsigned>(EDisplay::kInline); }
    // orphans
    short Orphans() const { return rare_inherited_usage_less_than_64_percent_data_->orphans_; }
    inline void ResetOrphans() { rare_inherited_usage_less_than_64_percent_data_.Access()->orphans_ = 2; }
    // outline-color

    void SetOutlineColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->outline_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->outline_color_
                = v;
    }

    void SetOutlineColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->outline_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->outline_color_
                = std::move(v);
    }
    inline void ResetOutlineColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->outline_color_
            = StyleColor::CurrentColor();
    }

    // outline-offset
    const LayoutUnit& OutlineOffset() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_; }

    void SetOutlineOffset(const LayoutUnit& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_offset_ = v;
    }

    void SetOutlineOffset(LayoutUnit&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_offset_ = std::move(v);
    }
    inline void ResetOutlineOffset()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_offset_ = LayoutUnit(0);
    }

    // outline-style
    EBorderStyle OutlineStyle() const
    {
        return static_cast<EBorderStyle>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_);
    }

    void SetOutlineStyle(EBorderStyle v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_style_ = static_cast<unsigned>(v);
    }

    inline void ResetOutlineStyle()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_style_
            = static_cast<unsigned>(EBorderStyle::kNone);
    }
    // OutlineStyleIsAuto
    bool OutlineStyleIsAuto() const
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_);
    }

    void SetOutlineStyleIsAuto(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->outline_style_is_auto_
                = static_cast<unsigned>(v);
    }

    inline void ResetOutlineStyleIsAuto()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->outline_style_is_auto_
            = static_cast<unsigned>(false);
    }
    // outline-width

    inline void ResetOutlineWidth()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_width_ = LayoutUnit(3);
    }

    // overflow-anchor
    EOverflowAnchor OverflowAnchor() const { return static_cast<EOverflowAnchor>(overflow_anchor_); }

    void SetOverflowAnchor(EOverflowAnchor v) { overflow_anchor_ = static_cast<unsigned>(v); }

    inline void ResetOverflowAnchor() { overflow_anchor_ = static_cast<unsigned>(EOverflowAnchor::kAuto); }
    // overflow-clip-margin
    const absl::optional<StyleOverflowClipMargin>& OverflowClipMargin() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_;
    }

    void SetOverflowClipMargin(const absl::optional<StyleOverflowClipMargin>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->overflow_clip_margin_ = v;
    }

    void SetOverflowClipMargin(absl::optional<StyleOverflowClipMargin>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->overflow_clip_margin_ = std::move(v);
    }
    inline void ResetOverflowClipMargin()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->overflow_clip_margin_ = absl::nullopt;
    }

    // overflow-wrap
    EOverflowWrap OverflowWrap() const { return static_cast<EOverflowWrap>(rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_); }

    void SetOverflowWrap(EOverflowWrap v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->overflow_wrap_ = static_cast<unsigned>(v);
    }

    inline void ResetOverflowWrap() { rare_inherited_usage_less_than_64_percent_data_.Access()->overflow_wrap_ = static_cast<unsigned>(EOverflowWrap::kNormal); }
    // overflow-x
    EOverflow OverflowX() const { return static_cast<EOverflow>(overflow_x_); }

    void SetOverflowX(EOverflow v) { overflow_x_ = static_cast<unsigned>(v); }

    inline void ResetOverflowX() { overflow_x_ = static_cast<unsigned>(EOverflow::kVisible); }
    // overflow-y
    EOverflow OverflowY() const { return static_cast<EOverflow>(overflow_y_); }

    void SetOverflowY(EOverflow v) { overflow_y_ = static_cast<unsigned>(v); }

    inline void ResetOverflowY() { overflow_y_ = static_cast<unsigned>(EOverflow::kVisible); }
    // overscroll-behavior-x
    EOverscrollBehavior OverscrollBehaviorX() const { return static_cast<EOverscrollBehavior>(overscroll_behavior_x_); }

    void SetOverscrollBehaviorX(EOverscrollBehavior v) { overscroll_behavior_x_ = static_cast<unsigned>(v); }

    inline void ResetOverscrollBehaviorX() { overscroll_behavior_x_ = static_cast<unsigned>(EOverscrollBehavior::kAuto); }
    // overscroll-behavior-y
    EOverscrollBehavior OverscrollBehaviorY() const { return static_cast<EOverscrollBehavior>(overscroll_behavior_y_); }

    void SetOverscrollBehaviorY(EOverscrollBehavior v) { overscroll_behavior_y_ = static_cast<unsigned>(v); }

    inline void ResetOverscrollBehaviorY() { overscroll_behavior_y_ = static_cast<unsigned>(EOverscrollBehavior::kAuto); }
    // padding-bottom
    const Length& PaddingBottom() const { return surround_data_->padding_bottom_; }
    inline void ResetPaddingBottom() { surround_data_.Access()->padding_bottom_ = Length::Fixed(); }

    // padding-left
    const Length& PaddingLeft() const { return surround_data_->padding_left_; }
    inline void ResetPaddingLeft() { surround_data_.Access()->padding_left_ = Length::Fixed(); }

    // padding-right
    const Length& PaddingRight() const { return surround_data_->padding_right_; }
    inline void ResetPaddingRight() { surround_data_.Access()->padding_right_ = Length::Fixed(); }

    // padding-top
    const Length& PaddingTop() const { return surround_data_->padding_top_; }
    inline void ResetPaddingTop() { surround_data_.Access()->padding_top_ = Length::Fixed(); }

    // page
    const AtomicString& Page() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->page_;
    }

    void SetPage(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->page_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->page_
                = v;
    }

    void SetPage(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->page_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->page_
                = std::move(v);
    }
    inline void ResetPage()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->page_
            = AtomicString();
    }

    // page-orientation
    PageOrientation GetPageOrientation() const
    {
        return static_cast<PageOrientation>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->page_orientation_);
    }

    void SetPageOrientation(PageOrientation v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->page_orientation_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->page_orientation_
                = static_cast<unsigned>(v);
    }

    inline void ResetPageOrientation()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->page_orientation_
            = static_cast<unsigned>(PageOrientation::kUpright);
    }
    // PageSize
    const gfx::SizeF& PageSize() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_; }

    void SetPageSize(const gfx::SizeF& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_size_ = v;
    }

    void SetPageSize(gfx::SizeF&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_size_ = std::move(v);
    }
    inline void ResetPageSize()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_size_ = gfx::SizeF();
    }

    // PageSizeType
    PageSizeType GetPageSizeType() const
    {
        return static_cast<PageSizeType>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_);
    }

    void SetPageSizeType(PageSizeType v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_size_type_
                = static_cast<unsigned>(v);
    }

    inline void ResetPageSizeType()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_size_type_
            = static_cast<unsigned>(PageSizeType::kAuto);
    }
    // page-transition-tag
    const AtomicString& PageTransitionTag() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_transition_tag_;
    }

    void SetPageTransitionTag(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_transition_tag_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_transition_tag_ = v;
    }

    void SetPageTransitionTag(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_transition_tag_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_transition_tag_ = std::move(v);
    }
    inline void ResetPageTransitionTag()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_transition_tag_ = AtomicString();
    }

    // PaintImages

    inline void ResetPaintImages()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->paint_images_ = nullptr;
    }

    // paint-order
    EPaintOrder PaintOrder() const { return static_cast<EPaintOrder>(svg_data_->paint_order_); }

    void SetPaintOrder(EPaintOrder v)
    {
        if (!(svg_data_->paint_order_ == static_cast<unsigned>(v)))
            svg_data_.Access()->paint_order_ = static_cast<unsigned>(v);
    }

    inline void ResetPaintOrder() { svg_data_.Access()->paint_order_ = static_cast<unsigned>(kPaintOrderNormal); }
    // perspective
    float Perspective() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->perspective_;
    }

    void SetPerspective(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->perspective_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->perspective_
                = v;
    }

    inline void ResetPerspective()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->perspective_
            = -1.0;
    }
    // perspective-origin
    const LengthPoint& PerspectiveOrigin() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->perspective_origin_;
    }

    void SetPerspectiveOrigin(const LengthPoint& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->perspective_origin_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->perspective_origin_
                = v;
    }

    void SetPerspectiveOrigin(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->perspective_origin_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->perspective_origin_
                = std::move(v);
    }
    inline void ResetPerspectiveOrigin()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->perspective_origin_
            = LengthPoint(Length::Percent(50.0), Length::Percent(50.0));
    }

    // pointer-events

    void SetPointerEvents(EPointerEvents v) { pointer_events_ = static_cast<unsigned>(v); }

    inline void ResetPointerEvents() { pointer_events_ = static_cast<unsigned>(EPointerEvents::kAuto); }
    // pointer-events

    void SetPointerEventsIsInherited(bool v) { pointer_events_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetPointerEventsIsInherited() { pointer_events_is_inherited_ = static_cast<unsigned>(true); }
    // position

    void SetPosition(EPosition v) { position_ = static_cast<unsigned>(v); }

    inline void ResetPosition() { position_ = static_cast<unsigned>(EPosition::kStatic); }
    // position-fallback
    const AtomicString& PositionFallback() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_fallback_;
    }

    void SetPositionFallback(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_fallback_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->position_fallback_ = v;
    }

    void SetPositionFallback(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_fallback_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->position_fallback_ = std::move(v);
    }
    inline void ResetPositionFallback()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->position_fallback_ = g_null_atom;
    }

    // -webkit-print-color-adjust
    EPrintColorAdjust PrintColorAdjust() const { return static_cast<EPrintColorAdjust>(print_color_adjust_); }

    void SetPrintColorAdjust(EPrintColorAdjust v) { print_color_adjust_ = static_cast<unsigned>(v); }

    inline void ResetPrintColorAdjust() { print_color_adjust_ = static_cast<unsigned>(EPrintColorAdjust::kEconomy); }
    // PseudoArgument
    const AtomicString& PseudoArgument() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_;
    }

    void SetPseudoArgument(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->pseudo_argument_ = v;
    }

    void SetPseudoArgument(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->pseudo_argument_ = std::move(v);
    }
    inline void ResetPseudoArgument()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->pseudo_argument_ = g_null_atom;
    }

    // PseudoBits

    inline void ResetPseudoBits() { pseudo_bits_ = static_cast<unsigned>(kPseudoIdNone); }
    // quotes
    QuotesData* Quotes() const { return rare_inherited_usage_less_than_64_percent_data_->quotes_.get(); }

    void SetQuotes(scoped_refptr<QuotesData> v) { rare_inherited_usage_less_than_64_percent_data_.Access()->quotes_ = std::move(v); }

    // r
    const Length& R() const { return svg_data_->geometry_data_->r_; }

    void SetR(const Length& v)
    {
        if (!(svg_data_->geometry_data_->r_ == v))
            svg_data_.Access()->geometry_data_.Access()->r_ = v;
    }

    void SetR(Length&& v)
    {
        if (!(svg_data_->geometry_data_->r_ == v))
            svg_data_.Access()->geometry_data_.Access()->r_ = std::move(v);
    }
    inline void ResetR() { svg_data_.Access()->geometry_data_.Access()->r_ = Length::Fixed(); }

    // RequiresAcceleratedCompositingForExternalReasons
    bool RequiresAcceleratedCompositingForExternalReasons() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->requires_accelerated_compositing_for_external_reasons_);
    }

    void SetRequiresAcceleratedCompositingForExternalReasons(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->requires_accelerated_compositing_for_external_reasons_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->requires_accelerated_compositing_for_external_reasons_
                = static_cast<unsigned>(v);
    }

    inline void ResetRequiresAcceleratedCompositingForExternalReasons()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->requires_accelerated_compositing_for_external_reasons_
            = static_cast<unsigned>(false);
    }
    // resize

    void SetResize(EResize v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->resize_ = static_cast<unsigned>(v);
    }

    inline void ResetResize()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->resize_ = static_cast<unsigned>(EResize::kNone);
    }
    // image-orientation
    bool RespectImageOrientation() const
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->respect_image_orientation_);
    }

    void SetRespectImageOrientation(bool v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->respect_image_orientation_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->respect_image_orientation_
                = static_cast<unsigned>(v);
    }

    inline void ResetRespectImageOrientation()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->respect_image_orientation_
            = static_cast<unsigned>(true);
    }
    // right
    const Length& Right() const { return surround_data_->right_; }

    void SetRight(const Length& v)
    {
        if (!(surround_data_->right_ == v))
            surround_data_.Access()->right_ = v;
    }

    void SetRight(Length&& v)
    {
        if (!(surround_data_->right_ == v))
            surround_data_.Access()->right_ = std::move(v);
    }
    inline void ResetRight() { surround_data_.Access()->right_ = Length(); }

    // rotate
    RotateTransformOperation* Rotate() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->rotate_.get();
    }

    void SetRotate(scoped_refptr<RotateTransformOperation> v)
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->rotate_
            = std::move(v);
    }

    // row-gap
    const absl::optional<Length>& RowGap() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->row_gap_;
    }

    void SetRowGap(const absl::optional<Length>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->row_gap_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->row_gap_
                = v;
    }

    void SetRowGap(absl::optional<Length>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->row_gap_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->row_gap_
                = std::move(v);
    }
    inline void ResetRowGap()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->row_gap_
            = absl::nullopt;
    }

    // -webkit-rtl-ordering
    EOrder RtlOrdering() const { return static_cast<EOrder>(rtl_ordering_); }

    void SetRtlOrdering(EOrder v) { rtl_ordering_ = static_cast<unsigned>(v); }

    inline void ResetRtlOrdering() { rtl_ordering_ = static_cast<unsigned>(EOrder::kLogical); }
    // -webkit-rtl-ordering
    bool RtlOrderingIsInherited() const { return static_cast<bool>(rtl_ordering_is_inherited_); }

    void SetRtlOrderingIsInherited(bool v) { rtl_ordering_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetRtlOrderingIsInherited() { rtl_ordering_is_inherited_ = static_cast<unsigned>(true); }
    // -webkit-ruby-position
    RubyPosition GetRubyPosition() const
    {
        return static_cast<RubyPosition>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->ruby_position_);
    }

    void SetRubyPosition(RubyPosition v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->ruby_position_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->ruby_position_ = static_cast<unsigned>(v);
    }

    inline void ResetRubyPosition()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->ruby_position_
            = static_cast<unsigned>(RubyPosition::kBefore);
    }
    // rx
    const Length& Rx() const { return svg_data_->geometry_data_->rx_; }

    void SetRx(const Length& v)
    {
        if (!(svg_data_->geometry_data_->rx_ == v))
            svg_data_.Access()->geometry_data_.Access()->rx_ = v;
    }

    void SetRx(Length&& v)
    {
        if (!(svg_data_->geometry_data_->rx_ == v))
            svg_data_.Access()->geometry_data_.Access()->rx_ = std::move(v);
    }
    inline void ResetRx() { svg_data_.Access()->geometry_data_.Access()->rx_ = Length::Auto(); }

    // ry
    const Length& Ry() const { return svg_data_->geometry_data_->ry_; }

    void SetRy(const Length& v)
    {
        if (!(svg_data_->geometry_data_->ry_ == v))
            svg_data_.Access()->geometry_data_.Access()->ry_ = v;
    }

    void SetRy(Length&& v)
    {
        if (!(svg_data_->geometry_data_->ry_ == v))
            svg_data_.Access()->geometry_data_.Access()->ry_ = std::move(v);
    }
    inline void ResetRy() { svg_data_.Access()->geometry_data_.Access()->ry_ = Length::Auto(); }

    // scale
    ScaleTransformOperation* Scale() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->scale_.get();
    }

    void SetScale(scoped_refptr<ScaleTransformOperation> v)
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scale_
            = std::move(v);
    }

    // scroll-behavior
    mojom::blink::ScrollBehavior GetScrollBehavior() const
    {
        return static_cast<mojom::blink::ScrollBehavior>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                             ->rare_non_inherited_usage_less_than_100_percent_data_->scroll_behavior_);
    }

    void SetScrollBehavior(mojom::blink::ScrollBehavior v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_behavior_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_behavior_
                = static_cast<unsigned>(v);
    }

    inline void ResetScrollBehavior()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_behavior_
            = static_cast<unsigned>(mojom::blink::ScrollBehavior::kAuto);
    }
    // scroll-customization
    scroll_customization::ScrollDirection ScrollCustomization() const
    {
        return static_cast<scroll_customization::ScrollDirection>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_customization_);
    }

    void SetScrollCustomization(scroll_customization::ScrollDirection v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_customization_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_customization_
                = static_cast<unsigned>(v);
    }

    inline void ResetScrollCustomization()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_customization_
            = static_cast<unsigned>(scroll_customization::kScrollDirectionNone);
    }
    // scroll-margin-bottom
    float ScrollMarginBottom() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_; }

    void SetScrollMarginBottom(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_bottom_ = v;
    }

    inline void ResetScrollMarginBottom()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_bottom_ = 0.0f;
    }
    // scroll-margin-left
    float ScrollMarginLeft() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_; }

    void SetScrollMarginLeft(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_left_ = v;
    }

    inline void ResetScrollMarginLeft()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_left_ = 0.0f;
    }
    // scroll-margin-right
    float ScrollMarginRight() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_; }

    void SetScrollMarginRight(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_right_ = v;
    }

    inline void ResetScrollMarginRight()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_right_ = 0.0f;
    }
    // scroll-margin-top
    float ScrollMarginTop() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_; }

    void SetScrollMarginTop(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_top_ = v;
    }

    inline void ResetScrollMarginTop()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_top_ = 0.0f;
    }
    // scroll-padding-bottom
    const Length& ScrollPaddingBottom() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->scroll_padding_bottom_;
    }

    void SetScrollPaddingBottom(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_bottom_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_bottom_
                = v;
    }

    void SetScrollPaddingBottom(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_bottom_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_bottom_
                = std::move(v);
    }
    inline void ResetScrollPaddingBottom()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_padding_bottom_
            = Length();
    }

    // scroll-padding-left
    const Length& ScrollPaddingLeft() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->scroll_padding_left_;
    }

    void SetScrollPaddingLeft(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_left_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_left_
                = v;
    }

    void SetScrollPaddingLeft(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_left_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_left_
                = std::move(v);
    }
    inline void ResetScrollPaddingLeft()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_padding_left_
            = Length();
    }

    // scroll-padding-right
    const Length& ScrollPaddingRight() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->scroll_padding_right_;
    }

    void SetScrollPaddingRight(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_right_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_right_
                = v;
    }

    void SetScrollPaddingRight(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_right_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_right_
                = std::move(v);
    }
    inline void ResetScrollPaddingRight()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_padding_right_
            = Length();
    }

    // scroll-padding-top
    const Length& ScrollPaddingTop() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->scroll_padding_top_;
    }

    void SetScrollPaddingTop(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_top_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_top_
                = v;
    }

    void SetScrollPaddingTop(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_top_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_top_
                = std::move(v);
    }
    inline void ResetScrollPaddingTop()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_padding_top_
            = Length();
    }

    // scroll-snap-align
    const cc::ScrollSnapAlign& GetScrollSnapAlign() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->scroll_snap_align_;
    }

    void SetScrollSnapAlign(const cc::ScrollSnapAlign& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_snap_align_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_snap_align_
                = v;
    }

    void SetScrollSnapAlign(cc::ScrollSnapAlign&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_snap_align_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_snap_align_
                = std::move(v);
    }
    inline void ResetScrollSnapAlign()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_snap_align_
            = cc::ScrollSnapAlign();
    }

    // scroll-snap-stop
    EScrollSnapStop ScrollSnapStop() const { return static_cast<EScrollSnapStop>(scroll_snap_stop_); }

    void SetScrollSnapStop(EScrollSnapStop v) { scroll_snap_stop_ = static_cast<unsigned>(v); }

    inline void ResetScrollSnapStop() { scroll_snap_stop_ = static_cast<unsigned>(EScrollSnapStop::kNormal); }
    // scroll-snap-type
    const cc::ScrollSnapType& GetScrollSnapType() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->scroll_snap_type_;
    }

    void SetScrollSnapType(const cc::ScrollSnapType& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_snap_type_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_snap_type_
                = v;
    }

    void SetScrollSnapType(cc::ScrollSnapType&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_snap_type_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_snap_type_
                = std::move(v);
    }
    inline void ResetScrollSnapType()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_snap_type_
            = cc::ScrollSnapType();
    }

    // scroll-timeline-axis
    TimelineAxis ScrollTimelineAxis() const
    {
        return static_cast<TimelineAxis>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_axis_);
    }

    void SetScrollTimelineAxis(TimelineAxis v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_axis_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->scroll_timeline_axis_
                = static_cast<unsigned>(v);
    }

    inline void ResetScrollTimelineAxis()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->timeline_data_.Access()
            ->scroll_timeline_axis_
            = static_cast<unsigned>(TimelineAxis::kBlock);
    }
    // scroll-timeline-name
    const AtomicString& ScrollTimelineName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_name_;
    }

    void SetScrollTimelineName(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->scroll_timeline_name_
                = v;
    }

    void SetScrollTimelineName(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->scroll_timeline_name_
                = std::move(v);
    }
    inline void ResetScrollTimelineName()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->timeline_data_.Access()
            ->scroll_timeline_name_
            = g_null_atom;
    }

    // scrollbar-gutter
    unsigned ScrollbarGutter() const { return static_cast<unsigned>(scrollbar_gutter_); }

    void SetScrollbarGutter(unsigned v) { scrollbar_gutter_ = static_cast<unsigned>(v); }

    inline void ResetScrollbarGutter() { scrollbar_gutter_ = static_cast<unsigned>(kScrollbarGutterAuto); }
    // scrollbar-width
    EScrollbarWidth ScrollbarWidth() const
    {
        return static_cast<EScrollbarWidth>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_);
    }

    void SetScrollbarWidth(EScrollbarWidth v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scrollbar_width_
                = static_cast<unsigned>(v);
    }

    inline void ResetScrollbarWidth()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scrollbar_width_
            = static_cast<unsigned>(EScrollbarWidth::kAuto);
    }
    // shape-image-threshold
    float ShapeImageThreshold() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->shape_image_threshold_;
    }
    inline void ResetShapeImageThreshold()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->shape_image_threshold_
            = 0.0;
    }
    // shape-margin
    const Length& ShapeMargin() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->shape_margin_;
    }

    void SetShapeMargin(const Length& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->shape_margin_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->shape_margin_
                = v;
    }

    void SetShapeMargin(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->shape_margin_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->shape_margin_
                = std::move(v);
    }
    inline void ResetShapeMargin()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->shape_margin_
            = Length::Fixed(0);
    }

    // shape-outside

    void SetShapeOutside(const Persistent<ShapeValue>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->shape_outside_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->shape_outside_
                = v;
    }

    void SetShapeOutside(Persistent<ShapeValue>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->shape_outside_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->shape_outside_
                = std::move(v);
    }
    inline void ResetShapeOutside()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->shape_outside_
            = nullptr;
    }

    // shape-rendering
    EShapeRendering ShapeRendering() const { return static_cast<EShapeRendering>(svg_data_->shape_rendering_); }

    void SetShapeRendering(EShapeRendering v)
    {
        if (!(svg_data_->shape_rendering_ == static_cast<unsigned>(v)))
            svg_data_.Access()->shape_rendering_ = static_cast<unsigned>(v);
    }

    inline void ResetShapeRendering() { svg_data_.Access()->shape_rendering_ = static_cast<unsigned>(EShapeRendering::kAuto); }
    // ShouldIgnoreOverflowPropertyForInlineBlockBaseline
    bool ShouldIgnoreOverflowPropertyForInlineBlockBaseline() const { return static_cast<bool>(should_ignore_overflow_property_for_inline_block_baseline_); }

    void SetShouldIgnoreOverflowPropertyForInlineBlockBaseline() { should_ignore_overflow_property_for_inline_block_baseline_ = static_cast<unsigned>(true); }
    // SkipsContents
    bool SkipsContents() const { return static_cast<bool>(skips_contents_); }

    void SetSkipsContents() { skips_contents_ = static_cast<unsigned>(true); }
    // speak
    ESpeak Speak() const { return static_cast<ESpeak>(rare_inherited_usage_less_than_64_percent_data_->speak_); }

    void SetSpeak(ESpeak v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->speak_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->speak_ = static_cast<unsigned>(v);
    }

    inline void ResetSpeak() { rare_inherited_usage_less_than_64_percent_data_.Access()->speak_ = static_cast<unsigned>(ESpeak::kNormal); }
    // stop-color

    void SetStopColor(const StyleColor& v)
    {
        if (!(svg_data_->stop_data_->stop_color_ == v))
            svg_data_.Access()->stop_data_.Access()->stop_color_ = v;
    }

    void SetStopColor(StyleColor&& v)
    {
        if (!(svg_data_->stop_data_->stop_color_ == v))
            svg_data_.Access()->stop_data_.Access()->stop_color_ = std::move(v);
    }
    inline void ResetStopColor() { svg_data_.Access()->stop_data_.Access()->stop_color_ = StyleColor(Color::kBlack); }

    // stop-opacity
    float StopOpacity() const { return svg_data_->stop_data_->stop_opacity_; }

    void SetStopOpacity(float v)
    {
        if (!(svg_data_->stop_data_->stop_opacity_ == v))
            svg_data_.Access()->stop_data_.Access()->stop_opacity_ = v;
    }

    inline void ResetStopOpacity() { svg_data_.Access()->stop_data_.Access()->stop_opacity_ = 1; }
    // stroke-dasharray
    SVGDashArray* StrokeDashArray() const { return svg_data_->stroke_data_->stroke_dash_array_.get(); }

    void SetStrokeDashArray(scoped_refptr<SVGDashArray> v) { svg_data_.Access()->stroke_data_.Access()->stroke_dash_array_ = std::move(v); }

    // stroke-dashoffset
    const Length& StrokeDashOffset() const { return svg_data_->stroke_data_->stroke_dash_offset_; }

    void SetStrokeDashOffset(const Length& v)
    {
        if (!(svg_data_->stroke_data_->stroke_dash_offset_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_dash_offset_ = v;
    }

    void SetStrokeDashOffset(Length&& v)
    {
        if (!(svg_data_->stroke_data_->stroke_dash_offset_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_dash_offset_ = std::move(v);
    }
    inline void ResetStrokeDashOffset() { svg_data_.Access()->stroke_data_.Access()->stroke_dash_offset_ = Length::Fixed(); }

    // stroke-miterlimit
    float StrokeMiterLimit() const { return svg_data_->stroke_data_->stroke_miter_limit_; }

    void SetStrokeMiterLimit(float v)
    {
        if (!(svg_data_->stroke_data_->stroke_miter_limit_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_miter_limit_ = v;
    }

    inline void ResetStrokeMiterLimit() { svg_data_.Access()->stroke_data_.Access()->stroke_miter_limit_ = 4; }
    // stroke-opacity
    float StrokeOpacity() const { return svg_data_->stroke_data_->stroke_opacity_; }

    void SetStrokeOpacity(float v)
    {
        if (!(svg_data_->stroke_data_->stroke_opacity_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_opacity_ = v;
    }

    inline void ResetStrokeOpacity() { svg_data_.Access()->stroke_data_.Access()->stroke_opacity_ = 1; }
    // stroke
    const SVGPaint& StrokePaint() const { return svg_data_->stroke_data_->stroke_paint_; }

    void SetStrokePaint(const SVGPaint& v)
    {
        if (!(svg_data_->stroke_data_->stroke_paint_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_paint_ = v;
    }

    void SetStrokePaint(SVGPaint&& v)
    {
        if (!(svg_data_->stroke_data_->stroke_paint_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_paint_ = std::move(v);
    }
    inline void ResetStrokePaint() { svg_data_.Access()->stroke_data_.Access()->stroke_paint_ = SVGPaint(); }

    // stroke-width
    const UnzoomedLength& StrokeWidth() const { return svg_data_->stroke_data_->stroke_width_; }

    void SetStrokeWidth(const UnzoomedLength& v)
    {
        if (!(svg_data_->stroke_data_->stroke_width_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_width_ = v;
    }

    void SetStrokeWidth(UnzoomedLength&& v)
    {
        if (!(svg_data_->stroke_data_->stroke_width_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_width_ = std::move(v);
    }
    inline void ResetStrokeWidth() { svg_data_.Access()->stroke_data_.Access()->stroke_width_ = UnzoomedLength(Length::Fixed(1)); }

    // StyleType

    inline void ResetStyleType() { style_type_ = static_cast<unsigned>(PseudoId::kPseudoIdNone); }
    // SubtreeIsSticky
    bool SubtreeIsSticky() const
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_);
    }

    void SetSubtreeIsSticky(bool v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->subtree_is_sticky_ = static_cast<unsigned>(v);
    }

    inline void ResetSubtreeIsSticky()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->subtree_is_sticky_ = static_cast<unsigned>(false);
    }
    // SubtreeWillChangeContents
    bool SubtreeWillChangeContents() const
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_);
    }

    void SetSubtreeWillChangeContents(bool v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->subtree_will_change_contents_
                = static_cast<unsigned>(v);
    }

    inline void ResetSubtreeWillChangeContents()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->subtree_will_change_contents_
            = static_cast<unsigned>(false);
    }
    // tab-size
    const TabSize& GetTabSize() const { return rare_inherited_usage_less_than_64_percent_data_->tab_size_; }
    inline void ResetTabSize() { rare_inherited_usage_less_than_64_percent_data_.Access()->tab_size_ = TabSize(8); }

    // table-layout
    ETableLayout TableLayout() const { return static_cast<ETableLayout>(table_layout_); }

    void SetTableLayout(ETableLayout v) { table_layout_ = static_cast<unsigned>(v); }

    inline void ResetTableLayout() { table_layout_ = static_cast<unsigned>(ETableLayout::kAuto); }
    // -webkit-tap-highlight-color
    const StyleColor& TapHighlightColor() const { return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_; }

    void SetTapHighlightColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->tap_highlight_color_ = v;
    }

    void SetTapHighlightColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->tap_highlight_color_ = std::move(v);
    }
    inline void ResetTapHighlightColor()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->tap_highlight_color_
            = StyleColor(LayoutTheme::TapHighlightColor());
    }

    // text-align
    ETextAlign GetTextAlign() const { return static_cast<ETextAlign>(text_align_); }

    void SetTextAlign(ETextAlign v) { text_align_ = static_cast<unsigned>(v); }

    inline void ResetTextAlign() { text_align_ = static_cast<unsigned>(ETextAlign::kStart); }
    // text-align-last
    ETextAlignLast TextAlignLast() const { return static_cast<ETextAlignLast>(rare_inherited_usage_less_than_64_percent_data_->text_align_last_); }

    void SetTextAlignLast(ETextAlignLast v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_align_last_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_align_last_ = static_cast<unsigned>(v);
    }

    inline void ResetTextAlignLast() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_align_last_ = static_cast<unsigned>(ETextAlignLast::kAuto); }
    // text-anchor
    ETextAnchor TextAnchor() const { return static_cast<ETextAnchor>(svg_data_->text_anchor_); }

    void SetTextAnchor(ETextAnchor v)
    {
        if (!(svg_data_->text_anchor_ == static_cast<unsigned>(v)))
            svg_data_.Access()->text_anchor_ = static_cast<unsigned>(v);
    }

    inline void ResetTextAnchor() { svg_data_.Access()->text_anchor_ = static_cast<unsigned>(ETextAnchor::kStart); }
    // TextAutosizingMultiplier
    float TextAutosizingMultiplier() const { return inherited_data_->text_autosizing_multiplier_; }
    inline void ResetTextAutosizingMultiplier() { inherited_data_.Access()->text_autosizing_multiplier_ = 1.0; }
    // text-combine-upright
    ETextCombine TextCombine() const { return static_cast<ETextCombine>(rare_inherited_usage_less_than_64_percent_data_->text_combine_); }

    void SetTextCombine(ETextCombine v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_combine_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_combine_ = static_cast<unsigned>(v);
    }

    inline void ResetTextCombine() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_combine_ = static_cast<unsigned>(ETextCombine::kNone); }
    // text-decoration-color

    void SetTextDecorationColor(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->text_decoration_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->text_decoration_color_
                = v;
    }

    void SetTextDecorationColor(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->text_decoration_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->text_decoration_color_
                = std::move(v);
    }
    inline void ResetTextDecorationColor()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->text_decoration_color_
            = StyleColor::CurrentColor();
    }

    // text-decoration-line
    TextDecorationLine GetTextDecorationLine() const { return static_cast<TextDecorationLine>(visual_data_->text_decoration_line_); }

    void SetTextDecorationLine(TextDecorationLine v)
    {
        if (!(visual_data_->text_decoration_line_ == static_cast<unsigned>(v)))
            visual_data_.Access()->text_decoration_line_ = static_cast<unsigned>(v);
    }

    inline void ResetTextDecorationLine() { visual_data_.Access()->text_decoration_line_ = static_cast<unsigned>(TextDecorationLine::kNone); }
    // text-decoration-skip-ink
    ETextDecorationSkipInk TextDecorationSkipInk() const { return static_cast<ETextDecorationSkipInk>(rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_); }

    void SetTextDecorationSkipInk(ETextDecorationSkipInk v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_decoration_skip_ink_ = static_cast<unsigned>(v);
    }

    inline void ResetTextDecorationSkipInk()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->text_decoration_skip_ink_ = static_cast<unsigned>(ETextDecorationSkipInk::kAuto);
    }
    // text-decoration-style
    ETextDecorationStyle TextDecorationStyle() const
    {
        return static_cast<ETextDecorationStyle>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                     ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_);
    }

    void SetTextDecorationStyle(ETextDecorationStyle v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->text_decoration_style_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->text_decoration_style_
                = static_cast<unsigned>(v);
    }

    inline void ResetTextDecorationStyle()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->text_decoration_style_
            = static_cast<unsigned>(ETextDecorationStyle::kSolid);
    }
    // text-decoration-thickness
    const TextDecorationThickness& GetTextDecorationThickness() const { return rare_inherited_usage_less_than_64_percent_data_->text_decoration_thickness_; }

    void SetTextDecorationThickness(const TextDecorationThickness& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_decoration_thickness_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_decoration_thickness_ = v;
    }

    void SetTextDecorationThickness(TextDecorationThickness&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_decoration_thickness_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_decoration_thickness_ = std::move(v);
    }
    inline void ResetTextDecorationThickness() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_decoration_thickness_ = TextDecorationThickness(Length::Auto()); }

    // text-emphasis-color

    void SetTextEmphasisColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_emphasis_color_ = v;
    }

    void SetTextEmphasisColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_emphasis_color_ = std::move(v);
    }
    inline void ResetTextEmphasisColor() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_emphasis_color_ = StyleColor::CurrentColor(); }

    // TextEmphasisCustomMark
    const AtomicString& TextEmphasisCustomMark() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_;
    }

    void SetTextEmphasisCustomMark(const AtomicString& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_custom_mark_ = v;
    }

    void SetTextEmphasisCustomMark(AtomicString&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_custom_mark_ = std::move(v);
    }
    inline void ResetTextEmphasisCustomMark()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_custom_mark_ = AtomicString();
    }

    // TextEmphasisFill
    TextEmphasisFill GetTextEmphasisFill() const
    {
        return static_cast<TextEmphasisFill>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_);
    }

    void SetTextEmphasisFill(TextEmphasisFill v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_fill_ = static_cast<unsigned>(v);
    }

    inline void ResetTextEmphasisFill()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_fill_
            = static_cast<unsigned>(TextEmphasisFill::kFilled);
    }
    // TextEmphasisMark

    inline void ResetTextEmphasisMark()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_mark_
            = static_cast<unsigned>(TextEmphasisMark::kNone);
    }
    // text-emphasis-position
    TextEmphasisPosition GetTextEmphasisPosition() const { return static_cast<TextEmphasisPosition>(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_); }

    void SetTextEmphasisPosition(TextEmphasisPosition v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_emphasis_position_ = static_cast<unsigned>(v);
    }

    inline void ResetTextEmphasisPosition()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->text_emphasis_position_ = static_cast<unsigned>(TextEmphasisPosition::kOverRight);
    }
    // -webkit-text-fill-color

    void SetTextFillColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_fill_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_fill_color_ = v;
    }

    void SetTextFillColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_fill_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_fill_color_ = std::move(v);
    }
    inline void ResetTextFillColor() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_fill_color_ = StyleColor::CurrentColor(); }

    // text-indent
    const Length& TextIndent() const { return rare_inherited_usage_less_than_64_percent_data_->text_indent_; }

    void SetTextIndent(const Length& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_indent_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_indent_ = v;
    }

    void SetTextIndent(Length&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_indent_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_indent_ = std::move(v);
    }
    inline void ResetTextIndent() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_indent_ = Length::Fixed(); }

    // text-orientation
    ETextOrientation GetTextOrientation() const { return static_cast<ETextOrientation>(rare_inherited_usage_less_than_64_percent_data_->text_orientation_); }

    void SetTextOrientation(ETextOrientation v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_orientation_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_orientation_ = static_cast<unsigned>(v);
    }

    inline void ResetTextOrientation() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_orientation_ = static_cast<unsigned>(ETextOrientation::kMixed); }
    // text-overflow
    ETextOverflow TextOverflow() const { return static_cast<ETextOverflow>(rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_); }

    void SetTextOverflow(ETextOverflow v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->text_overflow_ = static_cast<unsigned>(v);
    }

    inline void ResetTextOverflow() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->text_overflow_ = static_cast<unsigned>(ETextOverflow::kClip); }
    // -webkit-text-security
    ETextSecurity TextSecurity() const { return static_cast<ETextSecurity>(rare_inherited_usage_less_than_64_percent_data_->text_security_); }

    void SetTextSecurity(ETextSecurity v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_security_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_security_ = static_cast<unsigned>(v);
    }

    inline void ResetTextSecurity() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_security_ = static_cast<unsigned>(ETextSecurity::kNone); }
    // text-shadow
    ShadowList* TextShadow() const { return rare_inherited_usage_less_than_64_percent_data_->text_shadow_.get(); }

    void SetTextShadow(scoped_refptr<ShadowList> v) { rare_inherited_usage_less_than_64_percent_data_.Access()->text_shadow_ = std::move(v); }

    // text-size-adjust
    const TextSizeAdjust& GetTextSizeAdjust() const { return rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_; }

    void SetTextSizeAdjust(const TextSizeAdjust& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_size_adjust_ = v;
    }

    void SetTextSizeAdjust(TextSizeAdjust&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_size_adjust_ = std::move(v);
    }
    inline void ResetTextSizeAdjust() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_size_adjust_ = TextSizeAdjust::AdjustAuto(); }

    // -webkit-text-stroke-color

    void SetTextStrokeColor(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_stroke_color_ = v;
    }

    void SetTextStrokeColor(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_stroke_color_ = std::move(v);
    }
    inline void ResetTextStrokeColor() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_stroke_color_ = StyleColor::CurrentColor(); }

    // -webkit-text-stroke-width
    float TextStrokeWidth() const { return rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_; }

    void SetTextStrokeWidth(float v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_stroke_width_ = v;
    }

    inline void ResetTextStrokeWidth() { rare_inherited_usage_less_than_64_percent_data_.Access()->text_stroke_width_ = 0; }
    // text-transform
    ETextTransform TextTransform() const { return static_cast<ETextTransform>(text_transform_); }

    void SetTextTransform(ETextTransform v) { text_transform_ = static_cast<unsigned>(v); }

    inline void ResetTextTransform() { text_transform_ = static_cast<unsigned>(ETextTransform::kNone); }
    // text-transform
    bool TextTransformIsInherited() const { return static_cast<bool>(text_transform_is_inherited_); }

    void SetTextTransformIsInherited(bool v) { text_transform_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetTextTransformIsInherited() { text_transform_is_inherited_ = static_cast<unsigned>(true); }
    // text-underline-offset
    const Length& TextUnderlineOffset() const { return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_; }

    void SetTextUnderlineOffset(const Length& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->text_underline_offset_ = v;
    }

    void SetTextUnderlineOffset(Length&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->text_underline_offset_ = std::move(v);
    }
    inline void ResetTextUnderlineOffset()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->text_underline_offset_ = Length();
    }

    // text-underline-position
    unsigned TextUnderlinePosition() const { return static_cast<unsigned>(rare_inherited_usage_less_than_64_percent_data_->text_underline_position_); }

    void SetTextUnderlinePosition(unsigned v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_underline_position_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_underline_position_ = static_cast<unsigned>(v);
    }

    inline void ResetTextUnderlinePosition()
    {
        rare_inherited_usage_less_than_64_percent_data_.Access()->text_underline_position_ = static_cast<unsigned>(kTextUnderlinePositionAuto);
    }
    // toggle-group
    ToggleGroupList* ToggleGroup() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_group_.get();
    }

    void SetToggleGroup(scoped_refptr<ToggleGroupList> v)
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->toggle_group_ = std::move(v);
    }

    // toggle-root
    ToggleRootList* ToggleRoot() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_root_.get(); }

    void SetToggleRoot(scoped_refptr<ToggleRootList> v)
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->toggle_root_ = std::move(v);
    }

    // toggle-trigger
    ToggleTriggerList* ToggleTrigger() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_trigger_.get();
    }

    void SetToggleTrigger(scoped_refptr<ToggleTriggerList> v)
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->toggle_trigger_ = std::move(v);
    }

    // toggle-visibility
    const AtomicString& ToggleVisibility() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_visibility_;
    }

    void SetToggleVisibility(const AtomicString& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_visibility_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->toggle_visibility_ = v;
    }

    void SetToggleVisibility(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_visibility_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->toggle_visibility_ = std::move(v);
    }
    inline void ResetToggleVisibility()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->toggle_visibility_ = g_null_atom;
    }

    // top
    const Length& Top() const { return surround_data_->top_; }

    void SetTop(const Length& v)
    {
        if (!(surround_data_->top_ == v))
            surround_data_.Access()->top_ = v;
    }

    void SetTop(Length&& v)
    {
        if (!(surround_data_->top_ == v))
            surround_data_.Access()->top_ = std::move(v);
    }
    inline void ResetTop() { surround_data_.Access()->top_ = Length(); }

    // touch-action
    TouchAction GetTouchAction() const
    {
        return static_cast<TouchAction>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_);
    }

    void SetTouchAction(TouchAction v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->touch_action_ = static_cast<unsigned>(v);
    }

    inline void ResetTouchAction()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->touch_action_
            = static_cast<unsigned>(TouchAction::kAuto);
    }
    // transform
    const TransformOperations& Transform() const { return rare_non_inherited_usage_less_than_14_percent_data_->transform_; }

    void SetTransform(const TransformOperations& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_ = v;
    }

    void SetTransform(TransformOperations&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_ = std::move(v);
    }
    inline void ResetTransform() { rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_ = EmptyTransformOperations(); }

    // transform-box
    ETransformBox TransformBox() const { return static_cast<ETransformBox>(transform_box_); }

    void SetTransformBox(ETransformBox v) { transform_box_ = static_cast<unsigned>(v); }

    inline void ResetTransformBox() { transform_box_ = static_cast<unsigned>(ETransformBox::kViewBox); }
    // transform-origin
    const TransformOrigin& GetTransformOrigin() const { return rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_; }

    void SetTransformOrigin(const TransformOrigin& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_origin_ = v;
    }

    void SetTransformOrigin(TransformOrigin&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_origin_ = std::move(v);
    }
    inline void ResetTransformOrigin()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_origin_ = TransformOrigin(Length::Percent(50.0), Length::Percent(50.0), 0);
    }

    // transform-style
    ETransformStyle3D TransformStyle3D() const
    {
        return static_cast<ETransformStyle3D>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                  ->rare_non_inherited_usage_less_than_100_percent_data_->transform_style_3d_);
    }

    void SetTransformStyle3D(ETransformStyle3D v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->transform_style_3d_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->transform_style_3d_
                = static_cast<unsigned>(v);
    }

    inline void ResetTransformStyle3D()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->transform_style_3d_
            = static_cast<unsigned>(ETransformStyle3D::kFlat);
    }
    // Transitions

    inline void ResetTransitions()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->transitions_ = nullptr;
    }

    // translate
    TranslateTransformOperation* Translate() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->translate_.get();
    }

    void SetTranslate(scoped_refptr<TranslateTransformOperation> v)
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->translate_
            = std::move(v);
    }

    // unicode-bidi
    UnicodeBidi GetUnicodeBidi() const { return static_cast<UnicodeBidi>(unicode_bidi_); }

    void SetUnicodeBidi(UnicodeBidi v) { unicode_bidi_ = static_cast<unsigned>(v); }

    inline void ResetUnicodeBidi() { unicode_bidi_ = static_cast<unsigned>(UnicodeBidi::kNormal); }
    // -webkit-user-drag
    EUserDrag UserDrag() const
    {
        return static_cast<EUserDrag>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                          ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_);
    }

    void SetUserDrag(EUserDrag v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->user_drag_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->user_drag_
                = static_cast<unsigned>(v);
    }

    inline void ResetUserDrag()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->user_drag_
            = static_cast<unsigned>(EUserDrag::kAuto);
    }
    // -webkit-user-modify

    void SetUserModify(EUserModify v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->user_modify_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->user_modify_ = static_cast<unsigned>(v);
    }

    inline void ResetUserModify() { rare_inherited_usage_less_than_64_percent_data_.Access()->user_modify_ = static_cast<unsigned>(EUserModify::kReadOnly); }
    // user-select

    void SetUserSelect(EUserSelect v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->user_select_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->user_select_ = static_cast<unsigned>(v);
    }

    inline void ResetUserSelect() { rare_inherited_usage_less_than_64_percent_data_.Access()->user_select_ = static_cast<unsigned>(EUserSelect::kAuto); }
    // vector-effect
    EVectorEffect VectorEffect() const { return static_cast<EVectorEffect>(svg_data_->vector_effect_); }

    void SetVectorEffect(EVectorEffect v)
    {
        if (!(svg_data_->vector_effect_ == static_cast<unsigned>(v)))
            svg_data_.Access()->vector_effect_ = static_cast<unsigned>(v);
    }

    inline void ResetVectorEffect() { svg_data_.Access()->vector_effect_ = static_cast<unsigned>(EVectorEffect::kNone); }
    // VerticalAlign

    inline void ResetVerticalAlign() { vertical_align_ = static_cast<unsigned>(static_cast<unsigned>(EVerticalAlign::kBaseline)); }
    // VerticalAlignLength
    const Length& GetVerticalAlignLength() const { return box_data_->vertical_align_length_; }
    inline void ResetVerticalAlignLength() { box_data_.Access()->vertical_align_length_ = Length(); }

    // -webkit-border-vertical-spacing
    short VerticalBorderSpacing() const { return inherited_data_->vertical_border_spacing_; }

    void SetVerticalBorderSpacing(short v)
    {
        if (!(inherited_data_->vertical_border_spacing_ == v))
            inherited_data_.Access()->vertical_border_spacing_ = v;
    }

    inline void ResetVerticalBorderSpacing() { inherited_data_.Access()->vertical_border_spacing_ = 0; }
    // view-timeline-axis
    const Vector<TimelineAxis>& ViewTimelineAxis() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_;
    }

    void SetViewTimelineAxis(const Vector<TimelineAxis>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->view_timeline_axis_
                = v;
    }

    void SetViewTimelineAxis(Vector<TimelineAxis>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->view_timeline_axis_
                = std::move(v);
    }
    inline void ResetViewTimelineAxis()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->timeline_data_.Access()->view_timeline_axis_
            = Vector<TimelineAxis>();
    }

    // view-timeline-inset
    const Vector<TimelineInset>& ViewTimelineInset() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_;
    }

    void SetViewTimelineInset(const Vector<TimelineInset>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->view_timeline_inset_
                = v;
    }

    void SetViewTimelineInset(Vector<TimelineInset>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->view_timeline_inset_
                = std::move(v);
    }
    inline void ResetViewTimelineInset()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->timeline_data_.Access()
            ->view_timeline_inset_
            = Vector<TimelineInset>();
    }

    // view-timeline-name
    const Vector<AtomicString>& ViewTimelineName() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_;
    }

    void SetViewTimelineName(const Vector<AtomicString>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->view_timeline_name_
                = v;
    }

    void SetViewTimelineName(Vector<AtomicString>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->view_timeline_name_
                = std::move(v);
    }
    inline void ResetViewTimelineName()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->timeline_data_.Access()->view_timeline_name_
            = Vector<AtomicString>();
    }

    // ViewportUnitFlags
    unsigned ViewportUnitFlags() const { return static_cast<unsigned>(viewport_unit_flags_); }

    void SetViewportUnitFlags(unsigned v) { viewport_unit_flags_ = static_cast<unsigned>(v); }

    inline void ResetViewportUnitFlags() { viewport_unit_flags_ = static_cast<unsigned>(0); }
    // visibility
    EVisibility Visibility() const { return static_cast<EVisibility>(visibility_); }

    void SetVisibility(EVisibility v) { visibility_ = static_cast<unsigned>(v); }

    inline void ResetVisibility() { visibility_ = static_cast<unsigned>(EVisibility::kVisible); }
    // visibility
    bool VisibilityIsInherited() const { return static_cast<bool>(visibility_is_inherited_); }

    void SetVisibilityIsInherited(bool v) { visibility_is_inherited_ = static_cast<unsigned>(v); }

    inline void ResetVisibilityIsInherited() { visibility_is_inherited_ = static_cast<unsigned>(true); }
    // white-space
    EWhiteSpace WhiteSpace() const { return static_cast<EWhiteSpace>(white_space_); }

    void SetWhiteSpace(EWhiteSpace v) { white_space_ = static_cast<unsigned>(v); }

    inline void ResetWhiteSpace() { white_space_ = static_cast<unsigned>(EWhiteSpace::kNormal); }
    // widows
    short Widows() const { return rare_inherited_usage_less_than_64_percent_data_->widows_; }
    inline void ResetWidows() { rare_inherited_usage_less_than_64_percent_data_.Access()->widows_ = 2; }
    // width
    const Length& Width() const { return box_data_->width_; }

    void SetWidth(const Length& v)
    {
        if (!(box_data_->width_ == v))
            box_data_.Access()->width_ = v;
    }

    void SetWidth(Length&& v)
    {
        if (!(box_data_->width_ == v))
            box_data_.Access()->width_ = std::move(v);
    }
    inline void ResetWidth() { box_data_.Access()->width_ = Length(); }

    // WillChangeContents
    bool WillChangeContents() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_contents_);
    }

    void SetWillChangeContents(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_contents_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->will_change_data_.Access()
                ->will_change_contents_
                = static_cast<unsigned>(v);
    }

    inline void ResetWillChangeContents()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->will_change_data_.Access()
            ->will_change_contents_
            = static_cast<unsigned>(false);
    }
    // WillChangeProperties
    const Vector<CSSPropertyID>& WillChangeProperties() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_properties_;
    }

    void SetWillChangeProperties(const Vector<CSSPropertyID>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_properties_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->will_change_data_.Access()
                ->will_change_properties_
                = v;
    }

    void SetWillChangeProperties(Vector<CSSPropertyID>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_properties_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->will_change_data_.Access()
                ->will_change_properties_
                = std::move(v);
    }
    inline void ResetWillChangeProperties()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->will_change_data_.Access()
            ->will_change_properties_
            = Vector<CSSPropertyID>();
    }

    // WillChangeScrollPosition
    bool WillChangeScrollPosition() const
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_scroll_position_);
    }

    void SetWillChangeScrollPosition(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_scroll_position_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->will_change_data_.Access()
                ->will_change_scroll_position_
                = static_cast<unsigned>(v);
    }

    inline void ResetWillChangeScrollPosition()
    {
        rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->will_change_data_.Access()
            ->will_change_scroll_position_
            = static_cast<unsigned>(false);
    }
    // word-break
    EWordBreak WordBreak() const { return static_cast<EWordBreak>(rare_inherited_usage_less_than_64_percent_data_->word_break_); }

    void SetWordBreak(EWordBreak v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->word_break_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->word_break_ = static_cast<unsigned>(v);
    }

    inline void ResetWordBreak() { rare_inherited_usage_less_than_64_percent_data_.Access()->word_break_ = static_cast<unsigned>(EWordBreak::kNormal); }
    // writing-mode
    WritingMode GetWritingMode() const { return static_cast<WritingMode>(writing_mode_); }

    void SetWritingMode(WritingMode v) { writing_mode_ = static_cast<unsigned>(v); }

    inline void ResetWritingMode() { writing_mode_ = static_cast<unsigned>(WritingMode::kHorizontalTb); }
    // x
    const Length& X() const { return svg_data_->geometry_data_->x_; }

    void SetX(const Length& v)
    {
        if (!(svg_data_->geometry_data_->x_ == v))
            svg_data_.Access()->geometry_data_.Access()->x_ = v;
    }

    void SetX(Length&& v)
    {
        if (!(svg_data_->geometry_data_->x_ == v))
            svg_data_.Access()->geometry_data_.Access()->x_ = std::move(v);
    }
    inline void ResetX() { svg_data_.Access()->geometry_data_.Access()->x_ = Length::Fixed(); }

    // y
    const Length& Y() const { return svg_data_->geometry_data_->y_; }

    void SetY(const Length& v)
    {
        if (!(svg_data_->geometry_data_->y_ == v))
            svg_data_.Access()->geometry_data_.Access()->y_ = v;
    }

    void SetY(Length&& v)
    {
        if (!(svg_data_->geometry_data_->y_ == v))
            svg_data_.Access()->geometry_data_.Access()->y_ = std::move(v);
    }
    inline void ResetY() { svg_data_.Access()->geometry_data_.Access()->y_ = Length::Fixed(); }

    // z-index
    int ZIndex() const { return box_data_->z_index_; }
    inline void ResetZIndex() { box_data_.Access()->z_index_ = 0; }
    // zoom
    float Zoom() const { return visual_data_->zoom_; }

    void SetZoom(float v)
    {
        if (!(visual_data_->zoom_ == v))
            visual_data_.Access()->zoom_ = v;
    }

    inline void ResetZoom() { visual_data_.Access()->zoom_ = 1.0; }

#if DCHECK_IS_ON()
    enum class DebugField {
        accent_color_,
        affected_by_active_,
        affected_by_drag_,
        affected_by_focus_within_,
        affected_by_hover_,
        align_content_,
        align_items_,
        align_self_,
        align_self_block_center_,
        alignment_baseline_,
        anchor_name_,
        anchor_scroll_,
        animations_,
        appearance_,
        applied_text_decorations_,
        aspect_ratio_,
        backdrop_filter_,
        backface_visibility_,
        background_,
        background_color_,
        base_data_,
        baseline_shift_,
        baseline_shift_type_,
        blend_mode_,
        border_bottom_color_,
        border_bottom_left_radius_,
        border_bottom_right_radius_,
        border_bottom_style_,
        border_bottom_width_,
        border_collapse_,
        border_collapse_is_inherited_,
        border_image_,
        border_left_color_,
        border_left_style_,
        border_left_width_,
        border_right_color_,
        border_right_style_,
        border_right_width_,
        border_top_color_,
        border_top_left_radius_,
        border_top_right_radius_,
        border_top_style_,
        border_top_width_,
        bottom_,
        box_align_,
        box_decoration_break_,
        box_direction_,
        box_direction_is_inherited_,
        box_flex_,
        box_ordinal_group_,
        box_orient_,
        box_pack_,
        box_reflect_,
        box_shadow_,
        box_sizing_,
        break_after_,
        break_before_,
        break_inside_,
        buffered_rendering_,
        callback_selectors_,
        cap_style_,
        caption_side_,
        caption_side_is_inherited_,
        caret_color_,
        child_has_explicit_inheritance_,
        clear_,
        clip_,
        clip_path_,
        clip_rule_,
        color_,
        color_interpolation_,
        color_interpolation_filters_,
        color_is_current_color_,
        color_is_inherited_,
        color_rendering_,
        color_scheme_,
        color_scheme_forced_,
        column_count_,
        column_fill_,
        column_gap_,
        column_rule_color_,
        column_rule_style_,
        column_rule_width_,
        column_span_,
        column_width_,
        compositable_paint_animation_changed_,
        contain_,
        contain_intrinsic_height_,
        contain_intrinsic_width_,
        container_name_,
        container_type_,
        content_,
        content_visibility_,
        counter_directives_,
        css_dominant_baseline_,
        cursor_,
        cursor_data_,
        custom_highlight_names_,
        custom_style_callback_depends_on_font_,
        cx_,
        cy_,
        d_,
        dark_color_scheme_,
        depends_on_size_container_queries_,
        depends_on_style_container_queries_,
        direction_,
        display_,
        display_layout_custom_name_,
        display_layout_custom_parent_name_,
        dominant_baseline_,
        draggable_region_mode_,
        effective_appearance_,
        effective_touch_action_,
        effective_z_index_zero_,
        effective_zoom_,
        empty_cells_,
        empty_cells_is_inherited_,
        fill_opacity_,
        fill_paint_,
        fill_rule_,
        filter_,
        first_line_depends_on_size_container_queries_,
        flex_basis_,
        flex_direction_,
        flex_grow_,
        flex_shrink_,
        flex_wrap_,
        floating_,
        flood_color_,
        flood_opacity_,
        font_,
        forced_color_adjust_,
        grid_auto_columns_,
        grid_auto_flow_,
        grid_auto_rows_,
        grid_column_end_,
        grid_column_start_,
        grid_row_end_,
        grid_row_start_,
        grid_template_columns_,
        grid_template_rows_,
        has_attr_content_,
        has_author_background_,
        has_author_border_,
        has_author_border_radius_,
        has_author_highlight_colors_,
        has_auto_clip_,
        has_auto_column_count_,
        has_auto_column_width_,
        has_auto_z_index_,
        has_clip_path_,
        has_container_relative_units_,
        has_current_backdrop_filter_animation_,
        has_current_background_color_animation_,
        has_current_clip_path_animation_,
        has_current_filter_animation_,
        has_current_opacity_animation_,
        has_current_rotate_animation_,
        has_current_scale_animation_,
        has_current_transform_animation_,
        has_current_translate_animation_,
        has_em_units_,
        has_explicit_inheritance_,
        has_explicit_overflow_x_visible_,
        has_explicit_overflow_y_visible_,
        has_glyph_relative_units_,
        has_line_height_relative_units_,
        has_line_if_empty_,
        has_non_universal_highlight_pseudo_styles_,
        has_rem_units_,
        has_simple_underline_,
        has_variable_declaration_,
        has_variable_reference_,
        has_variable_reference_from_non_inherited_property_,
        height_,
        highlight_,
        highlight_data_,
        horizontal_border_spacing_,
        hyphenate_limit_chars_,
        hyphenation_string_,
        hyphens_,
        image_rendering_,
        implicit_named_grid_column_lines_,
        implicit_named_grid_row_lines_,
        in_forced_colors_mode_,
        inherited_variables_,
        initial_data_,
        initial_letter_,
        inline_style_lost_cascade_,
        inside_fragmentation_context_with_nondeterministic_engine_,
        inside_link_,
        internal_forced_background_color_,
        internal_forced_border_color_,
        internal_forced_color_,
        internal_forced_outline_color_,
        internal_forced_visited_color_,
        internal_visited_background_color_,
        internal_visited_border_bottom_color_,
        internal_visited_border_left_color_,
        internal_visited_border_right_color_,
        internal_visited_border_top_color_,
        internal_visited_caret_color_,
        internal_visited_color_,
        internal_visited_color_is_current_color_,
        internal_visited_column_rule_color_,
        internal_visited_fill_paint_,
        internal_visited_outline_color_,
        internal_visited_stroke_paint_,
        internal_visited_text_decoration_color_,
        internal_visited_text_emphasis_color_,
        internal_visited_text_fill_color_,
        internal_visited_text_stroke_color_,
        is_ensured_in_display_none_,
        is_ensured_outside_flat_tree_,
        is_flex_or_grid_item_,
        is_flex_or_grid_or_custom_item_,
        is_in_blockifying_display_,
        is_inert_,
        is_inert_is_inherited_,
        is_inside_list_element_,
        is_link_,
        is_running_backdrop_filter_animation_on_compositor_,
        is_running_filter_animation_on_compositor_,
        is_running_opacity_animation_on_compositor_,
        is_running_rotate_animation_on_compositor_,
        is_running_scale_animation_on_compositor_,
        is_running_transform_animation_on_compositor_,
        is_running_translate_animation_on_compositor_,
        is_secondary_body_element_,
        is_stacking_context_without_containment_,
        isolation_,
        join_style_,
        justify_content_,
        justify_items_,
        justify_self_,
        left_,
        lighting_color_,
        line_break_,
        line_clamp_,
        line_height_,
        line_height_step_,
        list_style_image_,
        list_style_position_,
        list_style_position_is_inherited_,
        list_style_type_,
        margin_bottom_,
        margin_left_,
        margin_right_,
        margin_top_,
        marker_end_resource_,
        marker_mid_resource_,
        marker_start_resource_,
        mask_,
        mask_box_image_,
        mask_type_,
        masker_resource_,
        math_baseline_,
        math_depth_,
        math_fraction_bar_thickness_,
        math_l_space_,
        math_max_size_,
        math_min_size_,
        math_padded_depth_,
        math_padded_v_offset_,
        math_r_space_,
        math_shift_,
        math_style_,
        max_height_,
        max_width_,
        may_have_margin_,
        may_have_padding_,
        min_height_,
        min_width_,
        named_grid_area_,
        named_grid_area_column_count_,
        named_grid_area_row_count_,
        non_inherited_variables_,
        object_fit_,
        object_position_,
        object_view_box_,
        offset_anchor_,
        offset_distance_,
        offset_path_,
        offset_position_,
        offset_rotate_,
        opacity_,
        order_,
        origin_trial_test_property_,
        original_display_,
        orphans_,
        outline_color_,
        outline_offset_,
        outline_style_,
        outline_style_is_auto_,
        outline_width_,
        overflow_anchor_,
        overflow_clip_margin_,
        overflow_wrap_,
        overflow_x_,
        overflow_y_,
        overscroll_behavior_x_,
        overscroll_behavior_y_,
        padding_bottom_,
        padding_left_,
        padding_right_,
        padding_top_,
        page_,
        page_orientation_,
        page_size_,
        page_size_type_,
        page_transition_tag_,
        paint_images_,
        paint_order_,
        perspective_,
        perspective_origin_,
        pointer_events_,
        pointer_events_is_inherited_,
        position_,
        position_fallback_,
        print_color_adjust_,
        pseudo_argument_,
        pseudo_bits_,
        quotes_,
        r_,
        requires_accelerated_compositing_for_external_reasons_,
        resize_,
        respect_image_orientation_,
        right_,
        rotate_,
        row_gap_,
        rtl_ordering_,
        rtl_ordering_is_inherited_,
        ruby_position_,
        rx_,
        ry_,
        scale_,
        scroll_behavior_,
        scroll_customization_,
        scroll_margin_bottom_,
        scroll_margin_left_,
        scroll_margin_right_,
        scroll_margin_top_,
        scroll_padding_bottom_,
        scroll_padding_left_,
        scroll_padding_right_,
        scroll_padding_top_,
        scroll_snap_align_,
        scroll_snap_stop_,
        scroll_snap_type_,
        scroll_timeline_axis_,
        scroll_timeline_name_,
        scrollbar_gutter_,
        scrollbar_width_,
        shape_image_threshold_,
        shape_margin_,
        shape_outside_,
        shape_rendering_,
        should_ignore_overflow_property_for_inline_block_baseline_,
        skips_contents_,
        speak_,
        stop_color_,
        stop_opacity_,
        stroke_dash_array_,
        stroke_dash_offset_,
        stroke_miter_limit_,
        stroke_opacity_,
        stroke_paint_,
        stroke_width_,
        style_type_,
        subtree_is_sticky_,
        subtree_will_change_contents_,
        tab_size_,
        table_layout_,
        tap_highlight_color_,
        text_align_,
        text_align_last_,
        text_anchor_,
        text_autosizing_multiplier_,
        text_combine_,
        text_decoration_color_,
        text_decoration_line_,
        text_decoration_skip_ink_,
        text_decoration_style_,
        text_decoration_thickness_,
        text_emphasis_color_,
        text_emphasis_custom_mark_,
        text_emphasis_fill_,
        text_emphasis_mark_,
        text_emphasis_position_,
        text_fill_color_,
        text_indent_,
        text_orientation_,
        text_overflow_,
        text_security_,
        text_shadow_,
        text_size_adjust_,
        text_stroke_color_,
        text_stroke_width_,
        text_transform_,
        text_transform_is_inherited_,
        text_underline_offset_,
        text_underline_position_,
        toggle_group_,
        toggle_root_,
        toggle_trigger_,
        toggle_visibility_,
        top_,
        touch_action_,
        transform_,
        transform_box_,
        transform_origin_,
        transform_style_3d_,
        transitions_,
        translate_,
        unicode_bidi_,
        user_drag_,
        user_modify_,
        user_select_,
        vector_effect_,
        vertical_align_,
        vertical_align_length_,
        vertical_border_spacing_,
        view_timeline_axis_,
        view_timeline_inset_,
        view_timeline_name_,
        viewport_unit_flags_,
        visibility_,
        visibility_is_inherited_,
        white_space_,
        widows_,
        width_,
        will_change_contents_,
        will_change_properties_,
        will_change_scroll_position_,
        word_break_,
        writing_mode_,
        x_,
        y_,
        z_index_,
        zoom_,
    };

    CORE_EXPORT static String DebugFieldToString(DebugField);

    // Returns a list of all fields that differ between |this| and |o|.
    CORE_EXPORT Vector<DebugField> DebugDiffFields(const ComputedStyleBase& o) const;
#endif // DCHECK_IS_ON()

private:
    class StyleFontData : public RefCounted<StyleFontData> {
    public:
        static scoped_refptr<StyleFontData> Create() { return base::AdoptRef(new StyleFontData); }
        scoped_refptr<StyleFontData> Copy() const { return base::AdoptRef(new StyleFontData(*this)); }

        bool operator==(const StyleFontData& other) const { return (font_ == other.font_); }
        bool operator!=(const StyleFontData& other) const { return !(*this == other); }

        Font font_;

    private:
        StyleFontData();
        CORE_EXPORT StyleFontData(const StyleFontData&);
    };

    class StyleInheritedData : public RefCounted<StyleInheritedData> {
    public:
        static scoped_refptr<StyleInheritedData> Create() { return base::AdoptRef(new StyleInheritedData); }
        scoped_refptr<StyleInheritedData> Copy() const { return base::AdoptRef(new StyleInheritedData(*this)); }

        bool operator==(const StyleInheritedData& other) const
        {
            return (font_data_ == other.font_data_ && base::ValuesEquivalent(inherited_variables_, other.inherited_variables_) && line_height_ == other.line_height_
                && text_autosizing_multiplier_ == other.text_autosizing_multiplier_ && color_ == other.color_ && internal_visited_color_ == other.internal_visited_color_
                && horizontal_border_spacing_ == other.horizontal_border_spacing_ && vertical_border_spacing_ == other.vertical_border_spacing_
                && color_is_current_color_ == other.color_is_current_color_ && in_forced_colors_mode_ == other.in_forced_colors_mode_
                && internal_visited_color_is_current_color_ == other.internal_visited_color_is_current_color_);
        }
        bool operator!=(const StyleInheritedData& other) const { return !(*this == other); }

        DataRef<StyleFontData> font_data_;
        scoped_refptr<StyleInheritedVariables> inherited_variables_;
        Length line_height_;
        float text_autosizing_multiplier_;
        StyleColor color_;
        StyleColor internal_visited_color_;
        short horizontal_border_spacing_;
        short vertical_border_spacing_;
        unsigned color_is_current_color_ : 1; // bool
        unsigned in_forced_colors_mode_ : 1; // bool
        unsigned internal_visited_color_is_current_color_ : 1; // bool

    private:
        StyleInheritedData();
        CORE_EXPORT StyleInheritedData(const StyleInheritedData&);
    };

    class StyleInheritedForcedColorsData : public RefCounted<StyleInheritedForcedColorsData> {
    public:
        static scoped_refptr<StyleInheritedForcedColorsData> Create() { return base::AdoptRef(new StyleInheritedForcedColorsData); }
        scoped_refptr<StyleInheritedForcedColorsData> Copy() const { return base::AdoptRef(new StyleInheritedForcedColorsData(*this)); }

        bool operator==(const StyleInheritedForcedColorsData& other) const
        {
            return (internal_forced_color_ == other.internal_forced_color_ && internal_forced_visited_color_ == other.internal_forced_visited_color_);
        }
        bool operator!=(const StyleInheritedForcedColorsData& other) const { return !(*this == other); }

        StyleColor internal_forced_color_;
        StyleColor internal_forced_visited_color_;

    private:
        StyleInheritedForcedColorsData();
        CORE_EXPORT StyleInheritedForcedColorsData(const StyleInheritedForcedColorsData&);
    };

    class StyleInheritedVisitedData : public RefCounted<StyleInheritedVisitedData> {
    public:
        static scoped_refptr<StyleInheritedVisitedData> Create() { return base::AdoptRef(new StyleInheritedVisitedData); }
        scoped_refptr<StyleInheritedVisitedData> Copy() const { return base::AdoptRef(new StyleInheritedVisitedData(*this)); }

        bool operator==(const StyleInheritedVisitedData& other) const
        {
            return (internal_visited_text_emphasis_color_ == other.internal_visited_text_emphasis_color_
                && internal_visited_text_fill_color_ == other.internal_visited_text_fill_color_ && internal_visited_text_stroke_color_ == other.internal_visited_text_stroke_color_
                && internal_visited_caret_color_ == other.internal_visited_caret_color_);
        }
        bool operator!=(const StyleInheritedVisitedData& other) const { return !(*this == other); }

        StyleColor internal_visited_text_emphasis_color_;
        StyleColor internal_visited_text_fill_color_;
        StyleColor internal_visited_text_stroke_color_;
        StyleAutoColor internal_visited_caret_color_;

    private:
        StyleInheritedVisitedData();
        CORE_EXPORT StyleInheritedVisitedData(const StyleInheritedVisitedData&);
    };

    class StyleRareInheritedUsageLessThan64PercentSubData : public RefCounted<StyleRareInheritedUsageLessThan64PercentSubData> {
    public:
        static scoped_refptr<StyleRareInheritedUsageLessThan64PercentSubData> Create() { return base::AdoptRef(new StyleRareInheritedUsageLessThan64PercentSubData); }
        scoped_refptr<StyleRareInheritedUsageLessThan64PercentSubData> Copy() const { return base::AdoptRef(new StyleRareInheritedUsageLessThan64PercentSubData(*this)); }

        bool operator==(const StyleRareInheritedUsageLessThan64PercentSubData& other) const
        {
            return (inherited_forced_colors_data_ == other.inherited_forced_colors_data_ && inherited_visited_data_ == other.inherited_visited_data_
                && text_emphasis_custom_mark_ == other.text_emphasis_custom_mark_ && base::ValuesEquivalent(applied_text_decorations_, other.applied_text_decorations_)
                && base::ValuesEquivalent(highlight_data_, other.highlight_data_) && base::ValuesEquivalent(initial_data_, other.initial_data_)
                && base::ValuesEquivalent(cursor_data_, other.cursor_data_) && effective_zoom_ == other.effective_zoom_ && accent_color_ == other.accent_color_
                && hyphenate_limit_chars_ == other.hyphenate_limit_chars_ && line_height_step_ == other.line_height_step_
                && effective_touch_action_ == other.effective_touch_action_ && text_emphasis_mark_ == other.text_emphasis_mark_ && has_line_if_empty_ == other.has_line_if_empty_
                && subtree_is_sticky_ == other.subtree_is_sticky_ && subtree_will_change_contents_ == other.subtree_will_change_contents_
                && text_emphasis_fill_ == other.text_emphasis_fill_);
        }
        bool operator!=(const StyleRareInheritedUsageLessThan64PercentSubData& other) const { return !(*this == other); }

        DataRef<StyleInheritedForcedColorsData> inherited_forced_colors_data_;
        DataRef<StyleInheritedVisitedData> inherited_visited_data_;
        AtomicString text_emphasis_custom_mark_;
        scoped_refptr<AppliedTextDecorationList> applied_text_decorations_;
        scoped_refptr<StyleHighlightData> highlight_data_;
        scoped_refptr<StyleInitialData> initial_data_;
        Persistent<CursorList> cursor_data_;
        float effective_zoom_;
        StyleAutoColor accent_color_;
        StyleHyphenateLimitChars hyphenate_limit_chars_;
        uint8_t line_height_step_;
        unsigned effective_touch_action_ : 8; // TouchAction
        unsigned text_emphasis_mark_ : 3; // TextEmphasisMark
        unsigned has_line_if_empty_ : 1; // bool
        unsigned subtree_is_sticky_ : 1; // bool
        unsigned subtree_will_change_contents_ : 1; // bool
        unsigned text_emphasis_fill_ : 1; // TextEmphasisFill

    private:
        StyleRareInheritedUsageLessThan64PercentSubData();
        CORE_EXPORT StyleRareInheritedUsageLessThan64PercentSubData(const StyleRareInheritedUsageLessThan64PercentSubData&);
    };

    class StyleRareInheritedUsageLessThan100PercentData : public RefCounted<StyleRareInheritedUsageLessThan100PercentData> {
    public:
        static scoped_refptr<StyleRareInheritedUsageLessThan100PercentData> Create() { return base::AdoptRef(new StyleRareInheritedUsageLessThan100PercentData); }
        scoped_refptr<StyleRareInheritedUsageLessThan100PercentData> Copy() const { return base::AdoptRef(new StyleRareInheritedUsageLessThan100PercentData(*this)); }

        bool operator==(const StyleRareInheritedUsageLessThan100PercentData& other) const
        {
            return (text_underline_offset_ == other.text_underline_offset_ && tap_highlight_color_ == other.tap_highlight_color_ && math_depth_ == other.math_depth_
                && math_shift_ == other.math_shift_ && math_style_ == other.math_style_ && respect_image_orientation_ == other.respect_image_orientation_
                && ruby_position_ == other.ruby_position_);
        }
        bool operator!=(const StyleRareInheritedUsageLessThan100PercentData& other) const { return !(*this == other); }

        Length text_underline_offset_;
        StyleColor tap_highlight_color_;
        short math_depth_;
        unsigned math_shift_ : 1; // EMathShift
        unsigned math_style_ : 1; // EMathStyle
        unsigned respect_image_orientation_ : 1; // bool
        unsigned ruby_position_ : 1; // RubyPosition

    private:
        StyleRareInheritedUsageLessThan100PercentData();
        CORE_EXPORT StyleRareInheritedUsageLessThan100PercentData(const StyleRareInheritedUsageLessThan100PercentData&);
    };

    class StyleRareInheritedUsageLessThan64PercentData : public RefCounted<StyleRareInheritedUsageLessThan64PercentData> {
    public:
        static scoped_refptr<StyleRareInheritedUsageLessThan64PercentData> Create() { return base::AdoptRef(new StyleRareInheritedUsageLessThan64PercentData); }
        scoped_refptr<StyleRareInheritedUsageLessThan64PercentData> Copy() const { return base::AdoptRef(new StyleRareInheritedUsageLessThan64PercentData(*this)); }

        bool operator==(const StyleRareInheritedUsageLessThan64PercentData& other) const
        {
            return (rare_inherited_usage_less_than_64_percent_sub_data_ == other.rare_inherited_usage_less_than_64_percent_sub_data_
                && rare_inherited_usage_less_than_100_percent_data_ == other.rare_inherited_usage_less_than_100_percent_data_ && color_scheme_ == other.color_scheme_
                && hyphenation_string_ == other.hyphenation_string_ && highlight_ == other.highlight_ && base::ValuesEquivalent(quotes_, other.quotes_)
                && base::ValuesEquivalent(text_shadow_, other.text_shadow_) && base::ValuesEquivalent(list_style_image_, other.list_style_image_)
                && base::ValuesEquivalent(list_style_type_, other.list_style_type_) && text_decoration_thickness_ == other.text_decoration_thickness_
                && text_indent_ == other.text_indent_ && text_size_adjust_ == other.text_size_adjust_ && tab_size_ == other.tab_size_
                && text_stroke_width_ == other.text_stroke_width_ && text_emphasis_color_ == other.text_emphasis_color_ && text_fill_color_ == other.text_fill_color_
                && text_stroke_color_ == other.text_stroke_color_ && caret_color_ == other.caret_color_ && orphans_ == other.orphans_ && widows_ == other.widows_
                && text_underline_position_ == other.text_underline_position_ && image_rendering_ == other.image_rendering_ && line_break_ == other.line_break_
                && speak_ == other.speak_ && text_align_last_ == other.text_align_last_ && forced_color_adjust_ == other.forced_color_adjust_ && hyphens_ == other.hyphens_
                && overflow_wrap_ == other.overflow_wrap_ && text_emphasis_position_ == other.text_emphasis_position_ && text_orientation_ == other.text_orientation_
                && text_security_ == other.text_security_ && user_modify_ == other.user_modify_ && user_select_ == other.user_select_ && word_break_ == other.word_break_
                && text_combine_ == other.text_combine_ && text_decoration_skip_ink_ == other.text_decoration_skip_ink_);
        }
        bool operator!=(const StyleRareInheritedUsageLessThan64PercentData& other) const { return !(*this == other); }

        DataRef<StyleRareInheritedUsageLessThan64PercentSubData> rare_inherited_usage_less_than_64_percent_sub_data_;
        DataRef<StyleRareInheritedUsageLessThan100PercentData> rare_inherited_usage_less_than_100_percent_data_;
        Vector<AtomicString> color_scheme_;
        AtomicString hyphenation_string_;
        AtomicString highlight_;
        scoped_refptr<QuotesData> quotes_;
        scoped_refptr<ShadowList> text_shadow_;
        Persistent<StyleImage> list_style_image_;
        Persistent<ListStyleTypeData> list_style_type_;
        TextDecorationThickness text_decoration_thickness_;
        Length text_indent_;
        TextSizeAdjust text_size_adjust_;
        TabSize tab_size_;
        float text_stroke_width_;
        StyleColor text_emphasis_color_;
        StyleColor text_fill_color_;
        StyleColor text_stroke_color_;
        StyleAutoColor caret_color_;
        short orphans_;
        short widows_;
        unsigned text_underline_position_ : 4; // unsigned
        unsigned image_rendering_ : 3; // EImageRendering
        unsigned line_break_ : 3; // LineBreak
        unsigned speak_ : 3; // ESpeak
        unsigned text_align_last_ : 3; // ETextAlignLast
        unsigned forced_color_adjust_ : 2; // EForcedColorAdjust
        unsigned hyphens_ : 2; // Hyphens
        unsigned overflow_wrap_ : 2; // EOverflowWrap
        unsigned text_emphasis_position_ : 2; // TextEmphasisPosition
        unsigned text_orientation_ : 2; // ETextOrientation
        unsigned text_security_ : 2; // ETextSecurity
        unsigned user_modify_ : 2; // EUserModify
        unsigned user_select_ : 2; // EUserSelect
        unsigned word_break_ : 2; // EWordBreak
        unsigned text_combine_ : 1; // ETextCombine
        unsigned text_decoration_skip_ink_ : 1; // ETextDecorationSkipInk

    private:
        StyleRareInheritedUsageLessThan64PercentData();
        CORE_EXPORT StyleRareInheritedUsageLessThan64PercentData(const StyleRareInheritedUsageLessThan64PercentData&);
    };

    class StyleVisualData : public RefCounted<StyleVisualData> {
    public:
        static scoped_refptr<StyleVisualData> Create() { return base::AdoptRef(new StyleVisualData); }
        scoped_refptr<StyleVisualData> Copy() const { return base::AdoptRef(new StyleVisualData(*this)); }

        bool operator==(const StyleVisualData& other) const
        {
            return (clip_ == other.clip_ && zoom_ == other.zoom_ && text_decoration_line_ == other.text_decoration_line_ && has_auto_clip_ == other.has_auto_clip_
                && has_clip_path_ == other.has_clip_path_);
        }
        bool operator!=(const StyleVisualData& other) const { return !(*this == other); }

        LengthBox clip_;
        float zoom_;
        unsigned text_decoration_line_ : 6; // TextDecorationLine
        unsigned has_auto_clip_ : 1; // bool
        unsigned has_clip_path_ : 1; // bool

    private:
        StyleVisualData();
        CORE_EXPORT StyleVisualData(const StyleVisualData&);
    };

    class StyleRareNonInheritedUsageLessThan100PercentData : public RefCounted<StyleRareNonInheritedUsageLessThan100PercentData> {
    public:
        static scoped_refptr<StyleRareNonInheritedUsageLessThan100PercentData> Create() { return base::AdoptRef(new StyleRareNonInheritedUsageLessThan100PercentData); }
        scoped_refptr<StyleRareNonInheritedUsageLessThan100PercentData> Copy() const { return base::AdoptRef(new StyleRareNonInheritedUsageLessThan100PercentData(*this)); }

        bool operator==(const StyleRareNonInheritedUsageLessThan100PercentData& other) const
        {
            return (grid_auto_columns_ == other.grid_auto_columns_ && grid_auto_rows_ == other.grid_auto_rows_ && grid_column_end_ == other.grid_column_end_
                && grid_column_start_ == other.grid_column_start_ && grid_row_end_ == other.grid_row_end_ && grid_row_start_ == other.grid_row_start_ && page_ == other.page_
                && base::ValuesEquivalent(clip_path_, other.clip_path_) && base::ValuesEquivalent(offset_path_, other.offset_path_)
                && base::ValuesEquivalent(rotate_, other.rotate_) && base::ValuesEquivalent(scale_, other.scale_) && base::ValuesEquivalent(translate_, other.translate_)
                && base::ValuesEquivalent(box_reflect_, other.box_reflect_) && base::ValuesEquivalent(backdrop_filter_, other.backdrop_filter_)
                && base::ValuesEquivalent(shape_outside_, other.shape_outside_) && column_gap_ == other.column_gap_ && row_gap_ == other.row_gap_
                && offset_rotate_ == other.offset_rotate_ && object_position_ == other.object_position_ && offset_anchor_ == other.offset_anchor_
                && offset_position_ == other.offset_position_ && perspective_origin_ == other.perspective_origin_ && offset_distance_ == other.offset_distance_
                && scroll_padding_bottom_ == other.scroll_padding_bottom_ && scroll_padding_left_ == other.scroll_padding_left_
                && scroll_padding_right_ == other.scroll_padding_right_ && scroll_padding_top_ == other.scroll_padding_top_ && shape_margin_ == other.shape_margin_
                && column_width_ == other.column_width_ && perspective_ == other.perspective_ && shape_image_threshold_ == other.shape_image_threshold_
                && scroll_snap_type_ == other.scroll_snap_type_ && scroll_snap_align_ == other.scroll_snap_align_ && column_rule_color_ == other.column_rule_color_
                && outline_color_ == other.outline_color_ && text_decoration_color_ == other.text_decoration_color_ && column_rule_width_ == other.column_rule_width_
                && box_ordinal_group_ == other.box_ordinal_group_ && column_count_ == other.column_count_ && justify_items_ == other.justify_items_
                && justify_self_ == other.justify_self_ && blend_mode_ == other.blend_mode_ && contain_ == other.contain_ && column_rule_style_ == other.column_rule_style_
                && grid_auto_flow_ == other.grid_auto_flow_ && text_decoration_style_ == other.text_decoration_style_ && draggable_region_mode_ == other.draggable_region_mode_
                && page_orientation_ == other.page_orientation_ && scroll_behavior_ == other.scroll_behavior_ && user_drag_ == other.user_drag_
                && column_fill_ == other.column_fill_ && column_span_ == other.column_span_ && isolation_ == other.isolation_ && transform_style_3d_ == other.transform_style_3d_);
        }
        bool operator!=(const StyleRareNonInheritedUsageLessThan100PercentData& other) const { return !(*this == other); }

        GridTrackList grid_auto_columns_;
        GridTrackList grid_auto_rows_;
        GridPosition grid_column_end_;
        GridPosition grid_column_start_;
        GridPosition grid_row_end_;
        GridPosition grid_row_start_;
        AtomicString page_;
        scoped_refptr<ClipPathOperation> clip_path_;
        scoped_refptr<BasicShape> offset_path_;
        scoped_refptr<RotateTransformOperation> rotate_;
        scoped_refptr<ScaleTransformOperation> scale_;
        scoped_refptr<TranslateTransformOperation> translate_;
        scoped_refptr<StyleReflection> box_reflect_;
        Persistent<StyleFilterData> backdrop_filter_;
        Persistent<ShapeValue> shape_outside_;
        absl::optional<Length> column_gap_;
        absl::optional<Length> row_gap_;
        StyleOffsetRotation offset_rotate_;
        LengthPoint object_position_;
        LengthPoint offset_anchor_;
        LengthPoint offset_position_;
        LengthPoint perspective_origin_;
        Length offset_distance_;
        Length scroll_padding_bottom_;
        Length scroll_padding_left_;
        Length scroll_padding_right_;
        Length scroll_padding_top_;
        Length shape_margin_;
        float column_width_;
        float perspective_;
        float shape_image_threshold_;
        cc::ScrollSnapType scroll_snap_type_;
        cc::ScrollSnapAlign scroll_snap_align_;
        StyleColor column_rule_color_;
        StyleColor outline_color_;
        StyleColor text_decoration_color_;
        LayoutUnit column_rule_width_;
        unsigned box_ordinal_group_;
        unsigned short column_count_;
        StyleSelfAlignmentData justify_items_;
        StyleSelfAlignmentData justify_self_;
        unsigned blend_mode_ : 5; // BlendMode
        unsigned contain_ : 5; // unsigned
        unsigned column_rule_style_ : 4; // EBorderStyle
        unsigned grid_auto_flow_ : 4; // GridAutoFlow
        unsigned text_decoration_style_ : 3; // ETextDecorationStyle
        unsigned draggable_region_mode_ : 2; // EDraggableRegionMode
        unsigned page_orientation_ : 2; // PageOrientation
        unsigned scroll_behavior_ : 2; // mojom::blink::ScrollBehavior
        unsigned user_drag_ : 2; // EUserDrag
        unsigned column_fill_ : 1; // EColumnFill
        unsigned column_span_ : 1; // EColumnSpan
        unsigned isolation_ : 1; // EIsolation
        unsigned transform_style_3d_ : 1; // ETransformStyle3D

    private:
        StyleRareNonInheritedUsageLessThan100PercentData();
        CORE_EXPORT StyleRareNonInheritedUsageLessThan100PercentData(const StyleRareNonInheritedUsageLessThan100PercentData&);
    };

    class StyleRareNonInheritedUsageLessThan22PercentData : public RefCounted<StyleRareNonInheritedUsageLessThan22PercentData> {
    public:
        static scoped_refptr<StyleRareNonInheritedUsageLessThan22PercentData> Create() { return base::AdoptRef(new StyleRareNonInheritedUsageLessThan22PercentData); }
        scoped_refptr<StyleRareNonInheritedUsageLessThan22PercentData> Copy() const { return base::AdoptRef(new StyleRareNonInheritedUsageLessThan22PercentData(*this)); }

        bool operator==(const StyleRareNonInheritedUsageLessThan22PercentData& other) const
        {
            return (rare_non_inherited_usage_less_than_100_percent_data_ == other.rare_non_inherited_usage_less_than_100_percent_data_
                && base::ValuesEquivalent(filter_, other.filter_) && flex_basis_ == other.flex_basis_ && flex_grow_ == other.flex_grow_ && flex_shrink_ == other.flex_shrink_
                && box_flex_ == other.box_flex_ && outline_offset_ == other.outline_offset_ && outline_width_ == other.outline_width_ && order_ == other.order_
                && line_clamp_ == other.line_clamp_ && align_self_ == other.align_self_ && align_content_ == other.align_content_ && touch_action_ == other.touch_action_
                && outline_style_ == other.outline_style_ && box_align_ == other.box_align_ && object_fit_ == other.object_fit_ && resize_ == other.resize_
                && box_pack_ == other.box_pack_ && backface_visibility_ == other.backface_visibility_ && box_orient_ == other.box_orient_);
        }
        bool operator!=(const StyleRareNonInheritedUsageLessThan22PercentData& other) const { return !(*this == other); }

        DataRef<StyleRareNonInheritedUsageLessThan100PercentData> rare_non_inherited_usage_less_than_100_percent_data_;
        Persistent<StyleFilterData> filter_;
        Length flex_basis_;
        float flex_grow_;
        float flex_shrink_;
        float box_flex_;
        LayoutUnit outline_offset_;
        LayoutUnit outline_width_;
        int order_;
        int line_clamp_;
        StyleSelfAlignmentData align_self_;
        StyleContentAlignmentData align_content_;
        unsigned touch_action_ : 8; // TouchAction
        unsigned outline_style_ : 4; // EBorderStyle
        unsigned box_align_ : 3; // EBoxAlignment
        unsigned object_fit_ : 3; // EObjectFit
        unsigned resize_ : 3; // EResize
        unsigned box_pack_ : 2; // EBoxPack
        unsigned backface_visibility_ : 1; // EBackfaceVisibility
        unsigned box_orient_ : 1; // EBoxOrient

    private:
        StyleRareNonInheritedUsageLessThan22PercentData();
        CORE_EXPORT StyleRareNonInheritedUsageLessThan22PercentData(const StyleRareNonInheritedUsageLessThan22PercentData&);
    };

    class StyleGridData : public RefCounted<StyleGridData> {
    public:
        static scoped_refptr<StyleGridData> Create() { return base::AdoptRef(new StyleGridData); }
        scoped_refptr<StyleGridData> Copy() const { return base::AdoptRef(new StyleGridData(*this)); }

        bool operator==(const StyleGridData& other) const
        {
            return (grid_template_columns_ == other.grid_template_columns_ && grid_template_rows_ == other.grid_template_rows_
                && implicit_named_grid_column_lines_ == other.implicit_named_grid_column_lines_ && implicit_named_grid_row_lines_ == other.implicit_named_grid_row_lines_
                && named_grid_area_ == other.named_grid_area_ && named_grid_area_row_count_ == other.named_grid_area_row_count_
                && named_grid_area_column_count_ == other.named_grid_area_column_count_);
        }
        bool operator!=(const StyleGridData& other) const { return !(*this == other); }

        ComputedGridTrackList grid_template_columns_;
        ComputedGridTrackList grid_template_rows_;
        NamedGridLinesMap implicit_named_grid_column_lines_;
        NamedGridLinesMap implicit_named_grid_row_lines_;
        NamedGridAreaMap named_grid_area_;
        wtf_size_t named_grid_area_row_count_;
        wtf_size_t named_grid_area_column_count_;

    private:
        StyleGridData();
        CORE_EXPORT StyleGridData(const StyleGridData&);
    };

    class StyleForcedColorsData : public RefCounted<StyleForcedColorsData> {
    public:
        static scoped_refptr<StyleForcedColorsData> Create() { return base::AdoptRef(new StyleForcedColorsData); }
        scoped_refptr<StyleForcedColorsData> Copy() const { return base::AdoptRef(new StyleForcedColorsData(*this)); }

        bool operator==(const StyleForcedColorsData& other) const
        {
            return (internal_forced_background_color_ == other.internal_forced_background_color_ && internal_forced_border_color_ == other.internal_forced_border_color_
                && internal_forced_outline_color_ == other.internal_forced_outline_color_);
        }
        bool operator!=(const StyleForcedColorsData& other) const { return !(*this == other); }

        StyleColor internal_forced_background_color_;
        StyleColor internal_forced_border_color_;
        StyleColor internal_forced_outline_color_;

    private:
        StyleForcedColorsData();
        CORE_EXPORT StyleForcedColorsData(const StyleForcedColorsData&);
    };

    class StyleVisitedData : public RefCounted<StyleVisitedData> {
    public:
        static scoped_refptr<StyleVisitedData> Create() { return base::AdoptRef(new StyleVisitedData); }
        scoped_refptr<StyleVisitedData> Copy() const { return base::AdoptRef(new StyleVisitedData(*this)); }

        bool operator==(const StyleVisitedData& other) const
        {
            return (internal_visited_background_color_ == other.internal_visited_background_color_
                && internal_visited_border_bottom_color_ == other.internal_visited_border_bottom_color_
                && internal_visited_border_left_color_ == other.internal_visited_border_left_color_
                && internal_visited_border_right_color_ == other.internal_visited_border_right_color_
                && internal_visited_border_top_color_ == other.internal_visited_border_top_color_
                && internal_visited_column_rule_color_ == other.internal_visited_column_rule_color_ && internal_visited_outline_color_ == other.internal_visited_outline_color_
                && internal_visited_text_decoration_color_ == other.internal_visited_text_decoration_color_);
        }
        bool operator!=(const StyleVisitedData& other) const { return !(*this == other); }

        StyleColor internal_visited_background_color_;
        StyleColor internal_visited_border_bottom_color_;
        StyleColor internal_visited_border_left_color_;
        StyleColor internal_visited_border_right_color_;
        StyleColor internal_visited_border_top_color_;
        StyleColor internal_visited_column_rule_color_;
        StyleColor internal_visited_outline_color_;
        StyleColor internal_visited_text_decoration_color_;

    private:
        StyleVisitedData();
        CORE_EXPORT StyleVisitedData(const StyleVisitedData&);
    };

    class StyleTimelineData : public RefCounted<StyleTimelineData> {
    public:
        static scoped_refptr<StyleTimelineData> Create() { return base::AdoptRef(new StyleTimelineData); }
        scoped_refptr<StyleTimelineData> Copy() const { return base::AdoptRef(new StyleTimelineData(*this)); }

        bool operator==(const StyleTimelineData& other) const
        {
            return (view_timeline_name_ == other.view_timeline_name_ && view_timeline_axis_ == other.view_timeline_axis_ && view_timeline_inset_ == other.view_timeline_inset_
                && scroll_timeline_name_ == other.scroll_timeline_name_ && scroll_timeline_axis_ == other.scroll_timeline_axis_);
        }
        bool operator!=(const StyleTimelineData& other) const { return !(*this == other); }

        Vector<AtomicString> view_timeline_name_;
        Vector<TimelineAxis> view_timeline_axis_;
        Vector<TimelineInset> view_timeline_inset_;
        AtomicString scroll_timeline_name_;
        unsigned scroll_timeline_axis_ : 2; // TimelineAxis

    private:
        StyleTimelineData();
        CORE_EXPORT StyleTimelineData(const StyleTimelineData&);
    };

    class StyleWillChangeData : public RefCounted<StyleWillChangeData> {
    public:
        static scoped_refptr<StyleWillChangeData> Create() { return base::AdoptRef(new StyleWillChangeData); }
        scoped_refptr<StyleWillChangeData> Copy() const { return base::AdoptRef(new StyleWillChangeData(*this)); }

        bool operator==(const StyleWillChangeData& other) const
        {
            return (will_change_properties_ == other.will_change_properties_ && will_change_contents_ == other.will_change_contents_
                && will_change_scroll_position_ == other.will_change_scroll_position_);
        }
        bool operator!=(const StyleWillChangeData& other) const { return !(*this == other); }

        Vector<CSSPropertyID> will_change_properties_;
        unsigned will_change_contents_ : 1; // bool
        unsigned will_change_scroll_position_ : 1; // bool

    private:
        StyleWillChangeData();
        CORE_EXPORT StyleWillChangeData(const StyleWillChangeData&);
    };

    class StyleMathData : public RefCounted<StyleMathData> {
    public:
        static scoped_refptr<StyleMathData> Create() { return base::AdoptRef(new StyleMathData); }
        scoped_refptr<StyleMathData> Copy() const { return base::AdoptRef(new StyleMathData(*this)); }

        bool operator==(const StyleMathData& other) const
        {
            return (math_baseline_ == other.math_baseline_ && math_fraction_bar_thickness_ == other.math_fraction_bar_thickness_ && math_l_space_ == other.math_l_space_
                && math_r_space_ == other.math_r_space_ && math_padded_v_offset_ == other.math_padded_v_offset_ && math_padded_depth_ == other.math_padded_depth_
                && math_min_size_ == other.math_min_size_ && math_max_size_ == other.math_max_size_);
        }
        bool operator!=(const StyleMathData& other) const { return !(*this == other); }

        Length math_baseline_;
        Length math_fraction_bar_thickness_;
        Length math_l_space_;
        Length math_r_space_;
        Length math_padded_v_offset_;
        Length math_padded_depth_;
        Length math_min_size_;
        Length math_max_size_;

    private:
        StyleMathData();
        CORE_EXPORT StyleMathData(const StyleMathData&);
    };

    class StyleRareNonInheritedUsageLessThan14PercentSubData : public RefCounted<StyleRareNonInheritedUsageLessThan14PercentSubData> {
    public:
        static scoped_refptr<StyleRareNonInheritedUsageLessThan14PercentSubData> Create() { return base::AdoptRef(new StyleRareNonInheritedUsageLessThan14PercentSubData); }
        scoped_refptr<StyleRareNonInheritedUsageLessThan14PercentSubData> Copy() const { return base::AdoptRef(new StyleRareNonInheritedUsageLessThan14PercentSubData(*this)); }

        bool operator==(const StyleRareNonInheritedUsageLessThan14PercentSubData& other) const
        {
            return (grid_data_ == other.grid_data_ && forced_colors_data_ == other.forced_colors_data_ && visited_data_ == other.visited_data_
                && timeline_data_ == other.timeline_data_ && will_change_data_ == other.will_change_data_ && math_data_ == other.math_data_
                && container_name_ == other.container_name_ && anchor_name_ == other.anchor_name_ && anchor_scroll_ == other.anchor_scroll_
                && page_transition_tag_ == other.page_transition_tag_ && position_fallback_ == other.position_fallback_ && toggle_visibility_ == other.toggle_visibility_
                && display_layout_custom_name_ == other.display_layout_custom_name_ && display_layout_custom_parent_name_ == other.display_layout_custom_parent_name_
                && pseudo_argument_ == other.pseudo_argument_ && base::ValuesEquivalent(object_view_box_, other.object_view_box_)
                && base::ValuesEquivalent(toggle_group_, other.toggle_group_) && base::ValuesEquivalent(toggle_root_, other.toggle_root_)
                && base::ValuesEquivalent(toggle_trigger_, other.toggle_trigger_) && base::ValuesEquivalent(custom_highlight_names_, other.custom_highlight_names_)
                && base::ValuesEquivalent(counter_directives_, other.counter_directives_) && base::ValuesEquivalent(animations_, other.animations_)
                && base::ValuesEquivalent(transitions_, other.transitions_) && base::ValuesEquivalent(non_inherited_variables_, other.non_inherited_variables_)
                && callback_selectors_ == other.callback_selectors_ && mask_ == other.mask_ && mask_box_image_ == other.mask_box_image_
                && overflow_clip_margin_ == other.overflow_clip_margin_ && initial_letter_ == other.initial_letter_ && page_size_ == other.page_size_
                && scroll_margin_bottom_ == other.scroll_margin_bottom_ && scroll_margin_left_ == other.scroll_margin_left_ && scroll_margin_right_ == other.scroll_margin_right_
                && scroll_margin_top_ == other.scroll_margin_top_ && effective_appearance_ == other.effective_appearance_ && scroll_customization_ == other.scroll_customization_
                && container_type_ == other.container_type_ && page_size_type_ == other.page_size_type_ && scrollbar_width_ == other.scrollbar_width_
                && align_self_block_center_ == other.align_self_block_center_ && compositable_paint_animation_changed_ == other.compositable_paint_animation_changed_
                && depends_on_size_container_queries_ == other.depends_on_size_container_queries_
                && depends_on_style_container_queries_ == other.depends_on_style_container_queries_ && effective_z_index_zero_ == other.effective_z_index_zero_
                && first_line_depends_on_size_container_queries_ == other.first_line_depends_on_size_container_queries_ && has_auto_column_count_ == other.has_auto_column_count_
                && has_auto_column_width_ == other.has_auto_column_width_ && has_current_backdrop_filter_animation_ == other.has_current_backdrop_filter_animation_
                && has_current_background_color_animation_ == other.has_current_background_color_animation_
                && has_current_clip_path_animation_ == other.has_current_clip_path_animation_ && has_current_filter_animation_ == other.has_current_filter_animation_
                && has_current_opacity_animation_ == other.has_current_opacity_animation_ && has_current_rotate_animation_ == other.has_current_rotate_animation_
                && has_current_scale_animation_ == other.has_current_scale_animation_ && has_current_transform_animation_ == other.has_current_transform_animation_
                && has_current_translate_animation_ == other.has_current_translate_animation_ && has_explicit_overflow_x_visible_ == other.has_explicit_overflow_x_visible_
                && has_explicit_overflow_y_visible_ == other.has_explicit_overflow_y_visible_ && is_secondary_body_element_ == other.is_secondary_body_element_
                && outline_style_is_auto_ == other.outline_style_is_auto_
                && requires_accelerated_compositing_for_external_reasons_ == other.requires_accelerated_compositing_for_external_reasons_);
        }
        bool operator!=(const StyleRareNonInheritedUsageLessThan14PercentSubData& other) const { return !(*this == other); }

        DataRef<StyleGridData> grid_data_;
        DataRef<StyleForcedColorsData> forced_colors_data_;
        DataRef<StyleVisitedData> visited_data_;
        DataRef<StyleTimelineData> timeline_data_;
        DataRef<StyleWillChangeData> will_change_data_;
        DataRef<StyleMathData> math_data_;
        Vector<AtomicString> container_name_;
        AtomicString anchor_name_;
        AtomicString anchor_scroll_;
        AtomicString page_transition_tag_;
        AtomicString position_fallback_;
        AtomicString toggle_visibility_;
        AtomicString display_layout_custom_name_;
        AtomicString display_layout_custom_parent_name_;
        AtomicString pseudo_argument_;
        scoped_refptr<BasicShape> object_view_box_;
        scoped_refptr<ToggleGroupList> toggle_group_;
        scoped_refptr<ToggleRootList> toggle_root_;
        scoped_refptr<ToggleTriggerList> toggle_trigger_;
        std::unique_ptr<HashSet<AtomicString>> custom_highlight_names_;
        std::unique_ptr<CounterDirectiveMap> counter_directives_;
        std::unique_ptr<CSSAnimationData> animations_;
        std::unique_ptr<CSSTransitionData> transitions_;
        std::unique_ptr<PaintImages> paint_images_;
        std::unique_ptr<StyleNonInheritedVariables> non_inherited_variables_;
        Vector<String> callback_selectors_;
        FillLayer mask_;
        NinePieceImage mask_box_image_;
        absl::optional<StyleOverflowClipMargin> overflow_clip_margin_;
        StyleInitialLetter initial_letter_;
        gfx::SizeF page_size_;
        float scroll_margin_bottom_;
        float scroll_margin_left_;
        float scroll_margin_right_;
        float scroll_margin_top_;
        unsigned effective_appearance_ : 5; // ControlPart
        unsigned scroll_customization_ : 4; // scroll_customization::ScrollDirection
        unsigned container_type_ : 2; // unsigned
        unsigned page_size_type_ : 2; // PageSizeType
        unsigned scrollbar_width_ : 2; // EScrollbarWidth
        unsigned align_self_block_center_ : 1; // bool
        unsigned compositable_paint_animation_changed_ : 1; // bool
        unsigned depends_on_size_container_queries_ : 1; // bool
        unsigned depends_on_style_container_queries_ : 1; // bool
        unsigned effective_z_index_zero_ : 1; // bool
        unsigned first_line_depends_on_size_container_queries_ : 1; // bool
        unsigned has_auto_column_count_ : 1; // bool
        unsigned has_auto_column_width_ : 1; // bool
        unsigned has_current_backdrop_filter_animation_ : 1; // bool
        unsigned has_current_background_color_animation_ : 1; // bool
        unsigned has_current_clip_path_animation_ : 1; // bool
        unsigned has_current_filter_animation_ : 1; // bool
        unsigned has_current_opacity_animation_ : 1; // bool
        unsigned has_current_rotate_animation_ : 1; // bool
        unsigned has_current_scale_animation_ : 1; // bool
        unsigned has_current_transform_animation_ : 1; // bool
        unsigned has_current_translate_animation_ : 1; // bool
        unsigned has_explicit_overflow_x_visible_ : 1; // bool
        unsigned has_explicit_overflow_y_visible_ : 1; // bool
        unsigned has_line_height_relative_units_ : 1; // bool
        unsigned has_non_universal_highlight_pseudo_styles_ : 1; // bool
        unsigned inline_style_lost_cascade_ : 1; // bool
        unsigned is_running_backdrop_filter_animation_on_compositor_ : 1; // bool
        unsigned is_running_filter_animation_on_compositor_ : 1; // bool
        unsigned is_running_opacity_animation_on_compositor_ : 1; // bool
        unsigned is_running_rotate_animation_on_compositor_ : 1; // bool
        unsigned is_running_scale_animation_on_compositor_ : 1; // bool
        unsigned is_running_transform_animation_on_compositor_ : 1; // bool
        unsigned is_running_translate_animation_on_compositor_ : 1; // bool
        unsigned is_secondary_body_element_ : 1; // bool
        unsigned outline_style_is_auto_ : 1; // bool
        unsigned requires_accelerated_compositing_for_external_reasons_ : 1; // bool

    private:
        StyleRareNonInheritedUsageLessThan14PercentSubData();
        CORE_EXPORT StyleRareNonInheritedUsageLessThan14PercentSubData(const StyleRareNonInheritedUsageLessThan14PercentSubData&);
    };

    class StyleRareNonInheritedUsageLessThan14PercentData : public RefCounted<StyleRareNonInheritedUsageLessThan14PercentData> {
    public:
        static scoped_refptr<StyleRareNonInheritedUsageLessThan14PercentData> Create() { return base::AdoptRef(new StyleRareNonInheritedUsageLessThan14PercentData); }
        scoped_refptr<StyleRareNonInheritedUsageLessThan14PercentData> Copy() const { return base::AdoptRef(new StyleRareNonInheritedUsageLessThan14PercentData(*this)); }

        bool operator==(const StyleRareNonInheritedUsageLessThan14PercentData& other) const
        {
            return (rare_non_inherited_usage_less_than_22_percent_data_ == other.rare_non_inherited_usage_less_than_22_percent_data_
                && rare_non_inherited_usage_less_than_14_percent_sub_data_ == other.rare_non_inherited_usage_less_than_14_percent_sub_data_ && transform_ == other.transform_
                && base::ValuesEquivalent(box_shadow_, other.box_shadow_) && base::ValuesEquivalent(content_, other.content_) && transform_origin_ == other.transform_origin_
                && opacity_ == other.opacity_ && align_items_ == other.align_items_ && justify_content_ == other.justify_content_ && appearance_ == other.appearance_
                && flex_direction_ == other.flex_direction_ && flex_wrap_ == other.flex_wrap_
                && is_stacking_context_without_containment_ == other.is_stacking_context_without_containment_ && text_overflow_ == other.text_overflow_);
        }
        bool operator!=(const StyleRareNonInheritedUsageLessThan14PercentData& other) const { return !(*this == other); }

        DataRef<StyleRareNonInheritedUsageLessThan22PercentData> rare_non_inherited_usage_less_than_22_percent_data_;
        DataRef<StyleRareNonInheritedUsageLessThan14PercentSubData> rare_non_inherited_usage_less_than_14_percent_sub_data_;
        TransformOperations transform_;
        scoped_refptr<ShadowList> box_shadow_;
        Persistent<ContentData> content_;
        TransformOrigin transform_origin_;
        float opacity_;
        StyleSelfAlignmentData align_items_;
        StyleContentAlignmentData justify_content_;
        unsigned appearance_ : 5; // ControlPart
        unsigned flex_direction_ : 2; // EFlexDirection
        unsigned flex_wrap_ : 2; // EFlexWrap
        unsigned is_stacking_context_without_containment_ : 1; // bool
        unsigned text_overflow_ : 1; // ETextOverflow

    private:
        StyleRareNonInheritedUsageLessThan14PercentData();
        CORE_EXPORT StyleRareNonInheritedUsageLessThan14PercentData(const StyleRareNonInheritedUsageLessThan14PercentData&);
    };

    class StyleMiscData : public RefCounted<StyleMiscData> {
    public:
        static scoped_refptr<StyleMiscData> Create() { return base::AdoptRef(new StyleMiscData); }
        scoped_refptr<StyleMiscData> Copy() const { return base::AdoptRef(new StyleMiscData(*this)); }

        bool operator==(const StyleMiscData& other) const
        {
            return (baseline_shift_ == other.baseline_shift_ && flood_opacity_ == other.flood_opacity_ && flood_color_ == other.flood_color_
                && lighting_color_ == other.lighting_color_ && baseline_shift_type_ == other.baseline_shift_type_);
        }
        bool operator!=(const StyleMiscData& other) const { return !(*this == other); }

        Length baseline_shift_;
        float flood_opacity_;
        StyleColor flood_color_;
        StyleColor lighting_color_;
        unsigned baseline_shift_type_ : 2; // EBaselineShiftType

    private:
        StyleMiscData();
        CORE_EXPORT StyleMiscData(const StyleMiscData&);
    };

    class StyleGeometryData : public RefCounted<StyleGeometryData> {
    public:
        static scoped_refptr<StyleGeometryData> Create() { return base::AdoptRef(new StyleGeometryData); }
        scoped_refptr<StyleGeometryData> Copy() const { return base::AdoptRef(new StyleGeometryData(*this)); }

        bool operator==(const StyleGeometryData& other) const
        {
            return (base::ValuesEquivalent(d_, other.d_) && cx_ == other.cx_ && cy_ == other.cy_ && r_ == other.r_ && rx_ == other.rx_ && ry_ == other.ry_ && x_ == other.x_
                && y_ == other.y_);
        }
        bool operator!=(const StyleGeometryData& other) const { return !(*this == other); }

        scoped_refptr<StylePath> d_;
        Length cx_;
        Length cy_;
        Length r_;
        Length rx_;
        Length ry_;
        Length x_;
        Length y_;

    private:
        StyleGeometryData();
        CORE_EXPORT StyleGeometryData(const StyleGeometryData&);
    };

    class StyleFillData : public RefCounted<StyleFillData> {
    public:
        static scoped_refptr<StyleFillData> Create() { return base::AdoptRef(new StyleFillData); }
        scoped_refptr<StyleFillData> Copy() const { return base::AdoptRef(new StyleFillData(*this)); }

        bool operator==(const StyleFillData& other) const
        {
            return (fill_paint_ == other.fill_paint_ && internal_visited_fill_paint_ == other.internal_visited_fill_paint_ && fill_opacity_ == other.fill_opacity_);
        }
        bool operator!=(const StyleFillData& other) const { return !(*this == other); }

        SVGPaint fill_paint_;
        SVGPaint internal_visited_fill_paint_;
        float fill_opacity_;

    private:
        StyleFillData();
        CORE_EXPORT StyleFillData(const StyleFillData&);
    };

    class StyleStrokeData : public RefCounted<StyleStrokeData> {
    public:
        static scoped_refptr<StyleStrokeData> Create() { return base::AdoptRef(new StyleStrokeData); }
        scoped_refptr<StyleStrokeData> Copy() const { return base::AdoptRef(new StyleStrokeData(*this)); }

        bool operator==(const StyleStrokeData& other) const
        {
            return (base::ValuesEquivalent(stroke_dash_array_, other.stroke_dash_array_) && internal_visited_stroke_paint_ == other.internal_visited_stroke_paint_
                && stroke_paint_ == other.stroke_paint_ && stroke_dash_offset_ == other.stroke_dash_offset_ && stroke_width_ == other.stroke_width_
                && stroke_miter_limit_ == other.stroke_miter_limit_ && stroke_opacity_ == other.stroke_opacity_ && cap_style_ == other.cap_style_
                && join_style_ == other.join_style_);
        }
        bool operator!=(const StyleStrokeData& other) const { return !(*this == other); }

        scoped_refptr<SVGDashArray> stroke_dash_array_;
        SVGPaint internal_visited_stroke_paint_;
        SVGPaint stroke_paint_;
        Length stroke_dash_offset_;
        UnzoomedLength stroke_width_;
        float stroke_miter_limit_;
        float stroke_opacity_;
        unsigned cap_style_ : 2; // LineCap
        unsigned join_style_ : 2; // LineJoin

    private:
        StyleStrokeData();
        CORE_EXPORT StyleStrokeData(const StyleStrokeData&);
    };

    class StyleInheritedResourcesData : public RefCounted<StyleInheritedResourcesData> {
    public:
        static scoped_refptr<StyleInheritedResourcesData> Create() { return base::AdoptRef(new StyleInheritedResourcesData); }
        scoped_refptr<StyleInheritedResourcesData> Copy() const { return base::AdoptRef(new StyleInheritedResourcesData(*this)); }

        bool operator==(const StyleInheritedResourcesData& other) const
        {
            return (base::ValuesEquivalent(marker_end_resource_, other.marker_end_resource_) && base::ValuesEquivalent(marker_mid_resource_, other.marker_mid_resource_)
                && base::ValuesEquivalent(marker_start_resource_, other.marker_start_resource_));
        }
        bool operator!=(const StyleInheritedResourcesData& other) const { return !(*this == other); }

        scoped_refptr<StyleSVGResource> marker_end_resource_;
        scoped_refptr<StyleSVGResource> marker_mid_resource_;
        scoped_refptr<StyleSVGResource> marker_start_resource_;

    private:
        StyleInheritedResourcesData();
        CORE_EXPORT StyleInheritedResourcesData(const StyleInheritedResourcesData&);
    };

    class StyleStopData : public RefCounted<StyleStopData> {
    public:
        static scoped_refptr<StyleStopData> Create() { return base::AdoptRef(new StyleStopData); }
        scoped_refptr<StyleStopData> Copy() const { return base::AdoptRef(new StyleStopData(*this)); }

        bool operator==(const StyleStopData& other) const { return (stop_opacity_ == other.stop_opacity_ && stop_color_ == other.stop_color_); }
        bool operator!=(const StyleStopData& other) const { return !(*this == other); }

        float stop_opacity_;
        StyleColor stop_color_;

    private:
        StyleStopData();
        CORE_EXPORT StyleStopData(const StyleStopData&);
    };

    class StyleSVGData : public RefCounted<StyleSVGData> {
    public:
        static scoped_refptr<StyleSVGData> Create() { return base::AdoptRef(new StyleSVGData); }
        scoped_refptr<StyleSVGData> Copy() const { return base::AdoptRef(new StyleSVGData(*this)); }

        bool operator==(const StyleSVGData& other) const
        {
            return (misc_data_ == other.misc_data_ && geometry_data_ == other.geometry_data_ && fill_data_ == other.fill_data_ && stroke_data_ == other.stroke_data_
                && inherited_resources_data_ == other.inherited_resources_data_ && stop_data_ == other.stop_data_
                && base::ValuesEquivalent(masker_resource_, other.masker_resource_) && alignment_baseline_ == other.alignment_baseline_
                && css_dominant_baseline_ == other.css_dominant_baseline_ && dominant_baseline_ == other.dominant_baseline_ && paint_order_ == other.paint_order_
                && buffered_rendering_ == other.buffered_rendering_ && color_interpolation_ == other.color_interpolation_
                && color_interpolation_filters_ == other.color_interpolation_filters_ && color_rendering_ == other.color_rendering_ && shape_rendering_ == other.shape_rendering_
                && text_anchor_ == other.text_anchor_ && clip_rule_ == other.clip_rule_ && fill_rule_ == other.fill_rule_ && mask_type_ == other.mask_type_
                && vector_effect_ == other.vector_effect_);
        }
        bool operator!=(const StyleSVGData& other) const { return !(*this == other); }

        DataRef<StyleMiscData> misc_data_;
        DataRef<StyleGeometryData> geometry_data_;
        DataRef<StyleFillData> fill_data_;
        DataRef<StyleStrokeData> stroke_data_;
        DataRef<StyleInheritedResourcesData> inherited_resources_data_;
        DataRef<StyleStopData> stop_data_;
        scoped_refptr<StyleSVGResource> masker_resource_;
        unsigned alignment_baseline_ : 4; // EAlignmentBaseline
        unsigned css_dominant_baseline_ : 4; // EDominantBaseline
        unsigned dominant_baseline_ : 4; // EDominantBaseline
        unsigned paint_order_ : 3; // EPaintOrder
        unsigned buffered_rendering_ : 2; // EBufferedRendering
        unsigned color_interpolation_ : 2; // EColorInterpolation
        unsigned color_interpolation_filters_ : 2; // EColorInterpolation
        unsigned color_rendering_ : 2; // EColorRendering
        unsigned shape_rendering_ : 2; // EShapeRendering
        unsigned text_anchor_ : 2; // ETextAnchor
        unsigned clip_rule_ : 1; // WindRule
        unsigned fill_rule_ : 1; // WindRule
        unsigned mask_type_ : 1; // EMaskType
        unsigned vector_effect_ : 1; // EVectorEffect

    private:
        StyleSVGData();
        CORE_EXPORT StyleSVGData(const StyleSVGData&);
    };

    class StyleBoxData : public RefCounted<StyleBoxData> {
    public:
        static scoped_refptr<StyleBoxData> Create() { return base::AdoptRef(new StyleBoxData); }
        scoped_refptr<StyleBoxData> Copy() const { return base::AdoptRef(new StyleBoxData(*this)); }

        bool operator==(const StyleBoxData& other) const
        {
            return (aspect_ratio_ == other.aspect_ratio_ && contain_intrinsic_height_ == other.contain_intrinsic_height_
                && contain_intrinsic_width_ == other.contain_intrinsic_width_ && height_ == other.height_ && max_height_ == other.max_height_ && max_width_ == other.max_width_
                && min_height_ == other.min_height_ && min_width_ == other.min_width_ && width_ == other.width_ && vertical_align_length_ == other.vertical_align_length_
                && z_index_ == other.z_index_ && box_decoration_break_ == other.box_decoration_break_ && box_sizing_ == other.box_sizing_
                && has_auto_z_index_ == other.has_auto_z_index_);
        }
        bool operator!=(const StyleBoxData& other) const { return !(*this == other); }

        StyleAspectRatio aspect_ratio_;
        absl::optional<StyleIntrinsicLength> contain_intrinsic_height_;
        absl::optional<StyleIntrinsicLength> contain_intrinsic_width_;
        Length height_;
        Length max_height_;
        Length max_width_;
        Length min_height_;
        Length min_width_;
        Length width_;
        Length vertical_align_length_;
        int z_index_;
        unsigned box_decoration_break_ : 1; // EBoxDecorationBreak
        unsigned box_sizing_ : 1; // EBoxSizing
        unsigned has_auto_z_index_ : 1; // bool

    private:
        StyleBoxData();
        CORE_EXPORT StyleBoxData(const StyleBoxData&);
    };

    class StyleBackgroundData : public RefCounted<StyleBackgroundData> {
    public:
        static scoped_refptr<StyleBackgroundData> Create() { return base::AdoptRef(new StyleBackgroundData); }
        scoped_refptr<StyleBackgroundData> Copy() const { return base::AdoptRef(new StyleBackgroundData(*this)); }

        bool operator==(const StyleBackgroundData& other) const { return (background_ == other.background_ && background_color_ == other.background_color_); }
        bool operator!=(const StyleBackgroundData& other) const { return !(*this == other); }

        FillLayer background_;
        StyleColor background_color_;

    private:
        StyleBackgroundData();
        CORE_EXPORT StyleBackgroundData(const StyleBackgroundData&);
    };

    class StyleSurroundData : public RefCounted<StyleSurroundData> {
    public:
        static scoped_refptr<StyleSurroundData> Create() { return base::AdoptRef(new StyleSurroundData); }
        scoped_refptr<StyleSurroundData> Copy() const { return base::AdoptRef(new StyleSurroundData(*this)); }

        bool operator==(const StyleSurroundData& other) const
        {
            return (border_image_ == other.border_image_ && border_bottom_left_radius_ == other.border_bottom_left_radius_
                && border_bottom_right_radius_ == other.border_bottom_right_radius_ && border_top_left_radius_ == other.border_top_left_radius_
                && border_top_right_radius_ == other.border_top_right_radius_ && bottom_ == other.bottom_ && left_ == other.left_ && margin_bottom_ == other.margin_bottom_
                && margin_left_ == other.margin_left_ && margin_right_ == other.margin_right_ && margin_top_ == other.margin_top_ && padding_bottom_ == other.padding_bottom_
                && padding_left_ == other.padding_left_ && padding_right_ == other.padding_right_ && padding_top_ == other.padding_top_ && right_ == other.right_
                && top_ == other.top_ && border_bottom_color_ == other.border_bottom_color_ && border_left_color_ == other.border_left_color_
                && border_right_color_ == other.border_right_color_ && border_top_color_ == other.border_top_color_ && border_bottom_width_ == other.border_bottom_width_
                && border_left_width_ == other.border_left_width_ && border_right_width_ == other.border_right_width_ && border_top_width_ == other.border_top_width_
                && border_bottom_style_ == other.border_bottom_style_ && border_left_style_ == other.border_left_style_ && border_right_style_ == other.border_right_style_
                && border_top_style_ == other.border_top_style_);
        }
        bool operator!=(const StyleSurroundData& other) const { return !(*this == other); }

        NinePieceImage border_image_;
        LengthSize border_bottom_left_radius_;
        LengthSize border_bottom_right_radius_;
        LengthSize border_top_left_radius_;
        LengthSize border_top_right_radius_;
        Length bottom_;
        Length left_;
        Length margin_bottom_;
        Length margin_left_;
        Length margin_right_;
        Length margin_top_;
        Length padding_bottom_;
        Length padding_left_;
        Length padding_right_;
        Length padding_top_;
        Length right_;
        Length top_;
        StyleColor border_bottom_color_;
        StyleColor border_left_color_;
        StyleColor border_right_color_;
        StyleColor border_top_color_;
        LayoutUnit border_bottom_width_;
        LayoutUnit border_left_width_;
        LayoutUnit border_right_width_;
        LayoutUnit border_top_width_;
        unsigned border_bottom_style_ : 4; // EBorderStyle
        unsigned border_left_style_ : 4; // EBorderStyle
        unsigned border_right_style_ : 4; // EBorderStyle
        unsigned border_top_style_ : 4; // EBorderStyle
        unsigned may_have_margin_ : 1; // bool
        unsigned may_have_padding_ : 1; // bool

    private:
        StyleSurroundData();
        CORE_EXPORT StyleSurroundData(const StyleSurroundData&);
    };

protected:
    // Constructor and destructor are protected so that only the parent class ComputedStyle
    // can instantiate this class.
    ComputedStyleBase();

    // accent-color
    const StyleAutoColor& AccentColorInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->accent_color_;
    }
    void SetAccentColorInternal(StyleAutoColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->accent_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->accent_color_ = std::move(v);
    }
    StyleAutoColor& MutableAccentColorInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->accent_color_;
    }
    // AffectedByActive

    // AffectedByDrag

    // AffectedByFocusWithin

    // AffectedByHover

    // align-content

    void SetAlignContentInternal(StyleContentAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_content_ = std::move(v);
    }
    StyleContentAlignmentData& MutableAlignContentInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_content_;
    }
    // align-items

    void SetAlignItemsInternal(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->align_items_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->align_items_ = std::move(v);
    }
    StyleSelfAlignmentData& MutableAlignItemsInternal() { return rare_non_inherited_usage_less_than_14_percent_data_.Access()->align_items_; }
    // align-self

    void SetAlignSelfInternal(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_self_ = std::move(v);
    }
    StyleSelfAlignmentData& MutableAlignSelfInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->align_self_;
    }
    // -internal-align-self-block

    bool MutableAlignSelfBlockCenterInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->align_self_block_center_);
    }
    // alignment-baseline

    EAlignmentBaseline MutableAlignmentBaselineInternal() { return static_cast<EAlignmentBaseline>(svg_data_.Access()->alignment_baseline_); }
    // anchor-name

    void SetAnchorNameInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_name_ = std::move(v);
    }
    AtomicString& MutableAnchorNameInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_name_;
    }
    // anchor-scroll

    void SetAnchorScrollInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scroll_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_scroll_ = std::move(v);
    }
    AtomicString& MutableAnchorScrollInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->anchor_scroll_;
    }
    // Animations
    const std::unique_ptr<CSSAnimationData>& AnimationsInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_;
    }

    void SetAnimationsInternal(std::unique_ptr<CSSAnimationData>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->animations_ = std::move(v);
    }
    std::unique_ptr<CSSAnimationData>& MutableAnimationsInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->animations_;
    }
    // appearance
    ControlPart AppearanceInternal() const { return static_cast<ControlPart>(rare_non_inherited_usage_less_than_14_percent_data_->appearance_); }
    ControlPart MutableAppearanceInternal() { return static_cast<ControlPart>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->appearance_); }
    // AppliedTextDecorations
    const scoped_refptr<AppliedTextDecorationList>& AppliedTextDecorationsInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->applied_text_decorations_;
    }

    void SetAppliedTextDecorationsInternal(scoped_refptr<AppliedTextDecorationList>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->applied_text_decorations_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->applied_text_decorations_ = std::move(v);
    }
    scoped_refptr<AppliedTextDecorationList>& MutableAppliedTextDecorationsInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->applied_text_decorations_;
    }
    // aspect-ratio

    void SetAspectRatioInternal(StyleAspectRatio&& v)
    {
        if (!(box_data_->aspect_ratio_ == v))
            box_data_.Access()->aspect_ratio_ = std::move(v);
    }
    StyleAspectRatio& MutableAspectRatioInternal() { return box_data_.Access()->aspect_ratio_; }
    // backdrop-filter
    const Persistent<StyleFilterData>& BackdropFilterInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->backdrop_filter_;
    }

    void SetBackdropFilterInternal(Persistent<StyleFilterData>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->backdrop_filter_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->backdrop_filter_
                = std::move(v);
    }
    Persistent<StyleFilterData>& MutableBackdropFilterInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->backdrop_filter_;
    }
    // backface-visibility

    EBackfaceVisibility MutableBackfaceVisibilityInternal()
    {
        return static_cast<EBackfaceVisibility>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->backface_visibility_);
    }
    // Background
    const FillLayer& BackgroundInternal() const { return background_data_->background_; }

    void SetBackgroundInternal(const FillLayer& v)
    {
        if (!(background_data_->background_ == v))
            background_data_.Access()->background_ = v;
    }

    void SetBackgroundInternal(FillLayer&& v)
    {
        if (!(background_data_->background_ == v))
            background_data_.Access()->background_ = std::move(v);
    }
    FillLayer& MutableBackgroundInternal() { return background_data_.Access()->background_; }
    // background-color
    const StyleColor& BackgroundColorInternal() const { return background_data_->background_color_; }
    void SetBackgroundColorInternal(StyleColor&& v)
    {
        if (!(background_data_->background_color_ == v))
            background_data_.Access()->background_color_ = std::move(v);
    }
    StyleColor& MutableBackgroundColorInternal() { return background_data_.Access()->background_color_; }
    // BaseData

    void SetBaseDataInternal(scoped_refptr<StyleBaseData>&& v) { base_data_ = std::move(v); }
    scoped_refptr<StyleBaseData>& MutableBaseDataInternal() { return base_data_; }
    // baseline-shift

    void SetBaselineShiftInternal(Length&& v)
    {
        if (!(svg_data_->misc_data_->baseline_shift_ == v))
            svg_data_.Access()->misc_data_.Access()->baseline_shift_ = std::move(v);
    }
    Length& MutableBaselineShiftInternal() { return svg_data_.Access()->misc_data_.Access()->baseline_shift_; }
    // BaselineShiftType

    EBaselineShiftType MutableBaselineShiftTypeInternal() { return static_cast<EBaselineShiftType>(svg_data_.Access()->misc_data_.Access()->baseline_shift_type_); }
    // mix-blend-mode

    BlendMode MutableBlendModeInternal()
    {
        return static_cast<BlendMode>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                          ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                          ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                          ->blend_mode_);
    }
    // border-bottom-color
    const StyleColor& BorderBottomColorInternal() const { return surround_data_->border_bottom_color_; }
    void SetBorderBottomColorInternal(StyleColor&& v)
    {
        if (!(surround_data_->border_bottom_color_ == v))
            surround_data_.Access()->border_bottom_color_ = std::move(v);
    }
    StyleColor& MutableBorderBottomColorInternal() { return surround_data_.Access()->border_bottom_color_; }
    // border-bottom-left-radius

    void SetBorderBottomLeftRadiusInternal(LengthSize&& v)
    {
        if (!(surround_data_->border_bottom_left_radius_ == v))
            surround_data_.Access()->border_bottom_left_radius_ = std::move(v);
    }
    LengthSize& MutableBorderBottomLeftRadiusInternal() { return surround_data_.Access()->border_bottom_left_radius_; }
    // border-bottom-right-radius

    void SetBorderBottomRightRadiusInternal(LengthSize&& v)
    {
        if (!(surround_data_->border_bottom_right_radius_ == v))
            surround_data_.Access()->border_bottom_right_radius_ = std::move(v);
    }
    LengthSize& MutableBorderBottomRightRadiusInternal() { return surround_data_.Access()->border_bottom_right_radius_; }
    // border-bottom-style

    EBorderStyle MutableBorderBottomStyleInternal() { return static_cast<EBorderStyle>(surround_data_.Access()->border_bottom_style_); }
    // border-bottom-width
    const LayoutUnit& BorderBottomWidthInternal() const { return surround_data_->border_bottom_width_; }
    void SetBorderBottomWidthInternal(LayoutUnit&& v)
    {
        if (!(surround_data_->border_bottom_width_ == v))
            surround_data_.Access()->border_bottom_width_ = std::move(v);
    }
    LayoutUnit& MutableBorderBottomWidthInternal() { return surround_data_.Access()->border_bottom_width_; }
    // border-collapse

    EBorderCollapse MutableBorderCollapseInternal() { return static_cast<EBorderCollapse>(border_collapse_); }
    // border-collapse

    bool MutableBorderCollapseIsInheritedInternal() { return static_cast<bool>(border_collapse_is_inherited_); }
    // border-image

    void SetBorderImageInternal(NinePieceImage&& v)
    {
        if (!(surround_data_->border_image_ == v))
            surround_data_.Access()->border_image_ = std::move(v);
    }
    NinePieceImage& MutableBorderImageInternal() { return surround_data_.Access()->border_image_; }
    // border-left-color
    const StyleColor& BorderLeftColorInternal() const { return surround_data_->border_left_color_; }
    void SetBorderLeftColorInternal(StyleColor&& v)
    {
        if (!(surround_data_->border_left_color_ == v))
            surround_data_.Access()->border_left_color_ = std::move(v);
    }
    StyleColor& MutableBorderLeftColorInternal() { return surround_data_.Access()->border_left_color_; }
    // border-left-style

    EBorderStyle MutableBorderLeftStyleInternal() { return static_cast<EBorderStyle>(surround_data_.Access()->border_left_style_); }
    // border-left-width
    const LayoutUnit& BorderLeftWidthInternal() const { return surround_data_->border_left_width_; }
    void SetBorderLeftWidthInternal(LayoutUnit&& v)
    {
        if (!(surround_data_->border_left_width_ == v))
            surround_data_.Access()->border_left_width_ = std::move(v);
    }
    LayoutUnit& MutableBorderLeftWidthInternal() { return surround_data_.Access()->border_left_width_; }
    // border-right-color
    const StyleColor& BorderRightColorInternal() const { return surround_data_->border_right_color_; }
    void SetBorderRightColorInternal(StyleColor&& v)
    {
        if (!(surround_data_->border_right_color_ == v))
            surround_data_.Access()->border_right_color_ = std::move(v);
    }
    StyleColor& MutableBorderRightColorInternal() { return surround_data_.Access()->border_right_color_; }
    // border-right-style

    EBorderStyle MutableBorderRightStyleInternal() { return static_cast<EBorderStyle>(surround_data_.Access()->border_right_style_); }
    // border-right-width
    const LayoutUnit& BorderRightWidthInternal() const { return surround_data_->border_right_width_; }
    void SetBorderRightWidthInternal(LayoutUnit&& v)
    {
        if (!(surround_data_->border_right_width_ == v))
            surround_data_.Access()->border_right_width_ = std::move(v);
    }
    LayoutUnit& MutableBorderRightWidthInternal() { return surround_data_.Access()->border_right_width_; }
    // border-top-color
    const StyleColor& BorderTopColorInternal() const { return surround_data_->border_top_color_; }
    void SetBorderTopColorInternal(StyleColor&& v)
    {
        if (!(surround_data_->border_top_color_ == v))
            surround_data_.Access()->border_top_color_ = std::move(v);
    }
    StyleColor& MutableBorderTopColorInternal() { return surround_data_.Access()->border_top_color_; }
    // border-top-left-radius

    void SetBorderTopLeftRadiusInternal(LengthSize&& v)
    {
        if (!(surround_data_->border_top_left_radius_ == v))
            surround_data_.Access()->border_top_left_radius_ = std::move(v);
    }
    LengthSize& MutableBorderTopLeftRadiusInternal() { return surround_data_.Access()->border_top_left_radius_; }
    // border-top-right-radius

    void SetBorderTopRightRadiusInternal(LengthSize&& v)
    {
        if (!(surround_data_->border_top_right_radius_ == v))
            surround_data_.Access()->border_top_right_radius_ = std::move(v);
    }
    LengthSize& MutableBorderTopRightRadiusInternal() { return surround_data_.Access()->border_top_right_radius_; }
    // border-top-style

    EBorderStyle MutableBorderTopStyleInternal() { return static_cast<EBorderStyle>(surround_data_.Access()->border_top_style_); }
    // border-top-width
    const LayoutUnit& BorderTopWidthInternal() const { return surround_data_->border_top_width_; }
    void SetBorderTopWidthInternal(LayoutUnit&& v)
    {
        if (!(surround_data_->border_top_width_ == v))
            surround_data_.Access()->border_top_width_ = std::move(v);
    }
    LayoutUnit& MutableBorderTopWidthInternal() { return surround_data_.Access()->border_top_width_; }
    // bottom

    void SetBottomInternal(Length&& v)
    {
        if (!(surround_data_->bottom_ == v))
            surround_data_.Access()->bottom_ = std::move(v);
    }
    Length& MutableBottomInternal() { return surround_data_.Access()->bottom_; }
    // -webkit-box-align

    EBoxAlignment MutableBoxAlignInternal()
    {
        return static_cast<EBoxAlignment>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_align_);
    }
    // -webkit-box-decoration-break

    EBoxDecorationBreak MutableBoxDecorationBreakInternal() { return static_cast<EBoxDecorationBreak>(box_data_.Access()->box_decoration_break_); }
    // -webkit-box-direction

    EBoxDirection MutableBoxDirectionInternal() { return static_cast<EBoxDirection>(box_direction_); }
    // -webkit-box-direction

    bool MutableBoxDirectionIsInheritedInternal() { return static_cast<bool>(box_direction_is_inherited_); }
    // -webkit-box-flex

    float MutableBoxFlexInternal() { return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_flex_; }
    // -webkit-box-ordinal-group

    void SetBoxOrdinalGroupInternal(unsigned v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->box_ordinal_group_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->box_ordinal_group_
                = v;
    }

    unsigned MutableBoxOrdinalGroupInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->box_ordinal_group_;
    }
    // -webkit-box-orient

    EBoxOrient MutableBoxOrientInternal()
    {
        return static_cast<EBoxOrient>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_orient_);
    }
    // -webkit-box-pack

    EBoxPack MutableBoxPackInternal()
    {
        return static_cast<EBoxPack>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->box_pack_);
    }
    // box-sizing

    EBoxSizing MutableBoxSizingInternal() { return static_cast<EBoxSizing>(box_data_.Access()->box_sizing_); }
    // break-after

    EBreakBetween MutableBreakAfterInternal() { return static_cast<EBreakBetween>(break_after_); }
    // break-before

    EBreakBetween MutableBreakBeforeInternal() { return static_cast<EBreakBetween>(break_before_); }
    // break-inside

    EBreakInside MutableBreakInsideInternal() { return static_cast<EBreakInside>(break_inside_); }
    // buffered-rendering

    EBufferedRendering MutableBufferedRenderingInternal() { return static_cast<EBufferedRendering>(svg_data_.Access()->buffered_rendering_); }
    // CallbackSelectors

    void SetCallbackSelectorsInternal(const Vector<String>& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->callback_selectors_ = v;
    }

    void SetCallbackSelectorsInternal(Vector<String>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->callback_selectors_ = std::move(v);
    }
    Vector<String>& MutableCallbackSelectorsInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->callback_selectors_;
    }
    // stroke-linecap

    LineCap MutableCapStyleInternal() { return static_cast<LineCap>(svg_data_.Access()->stroke_data_.Access()->cap_style_); }
    // caption-side

    ECaptionSide MutableCaptionSideInternal() { return static_cast<ECaptionSide>(caption_side_); }
    // caption-side

    bool MutableCaptionSideIsInheritedInternal() { return static_cast<bool>(caption_side_is_inherited_); }
    // caret-color
    const StyleAutoColor& CaretColorInternal() const { return rare_inherited_usage_less_than_64_percent_data_->caret_color_; }
    void SetCaretColorInternal(StyleAutoColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->caret_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->caret_color_ = std::move(v);
    }
    StyleAutoColor& MutableCaretColorInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->caret_color_; }
    // ChildHasExplicitInheritance

    // clear
    EClear ClearInternal() const { return static_cast<EClear>(clear_); }
    EClear MutableClearInternal() { return static_cast<EClear>(clear_); }
    // clip

    void SetClipInternal(const LengthBox& v)
    {
        if (!(visual_data_->clip_ == v))
            visual_data_.Access()->clip_ = v;
    }

    void SetClipInternal(LengthBox&& v)
    {
        if (!(visual_data_->clip_ == v))
            visual_data_.Access()->clip_ = std::move(v);
    }
    LengthBox& MutableClipInternal() { return visual_data_.Access()->clip_; }
    // clip-path
    const scoped_refptr<ClipPathOperation>& ClipPathInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->clip_path_;
    }

    void SetClipPathInternal(scoped_refptr<ClipPathOperation>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->clip_path_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->clip_path_
                = std::move(v);
    }
    scoped_refptr<ClipPathOperation>& MutableClipPathInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->clip_path_;
    }
    // clip-rule

    WindRule MutableClipRuleInternal() { return static_cast<WindRule>(svg_data_.Access()->clip_rule_); }
    // color
    const StyleColor& ColorInternal() const { return inherited_data_->color_; }
    void SetColorInternal(StyleColor&& v)
    {
        if (!(inherited_data_->color_ == v))
            inherited_data_.Access()->color_ = std::move(v);
    }
    StyleColor& MutableColorInternal() { return inherited_data_.Access()->color_; }
    // color-interpolation

    EColorInterpolation MutableColorInterpolationInternal() { return static_cast<EColorInterpolation>(svg_data_.Access()->color_interpolation_); }
    // color-interpolation-filters

    EColorInterpolation MutableColorInterpolationFiltersInternal() { return static_cast<EColorInterpolation>(svg_data_.Access()->color_interpolation_filters_); }
    // ColorIsCurrentColor
    bool ColorIsCurrentColorInternal() const { return static_cast<bool>(inherited_data_->color_is_current_color_); }
    bool MutableColorIsCurrentColorInternal() { return static_cast<bool>(inherited_data_.Access()->color_is_current_color_); }
    // color
    bool ColorIsInheritedInternal() const { return static_cast<bool>(color_is_inherited_); }
    bool MutableColorIsInheritedInternal() { return static_cast<bool>(color_is_inherited_); }
    // color-rendering

    EColorRendering MutableColorRenderingInternal() { return static_cast<EColorRendering>(svg_data_.Access()->color_rendering_); }
    // color-scheme

    void SetColorSchemeInternal(Vector<AtomicString>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->color_scheme_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->color_scheme_ = std::move(v);
    }
    Vector<AtomicString>& MutableColorSchemeInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->color_scheme_; }
    // ColorSchemeForced

    bool MutableColorSchemeForcedInternal() { return static_cast<bool>(color_scheme_forced_); }
    // column-count

    void SetColumnCountInternal(unsigned short v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_count_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_count_
                = v;
    }

    unsigned short MutableColumnCountInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_count_;
    }
    // column-fill

    EColumnFill MutableColumnFillInternal()
    {
        return static_cast<EColumnFill>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                            ->column_fill_);
    }
    // column-gap

    void SetColumnGapInternal(absl::optional<Length>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_gap_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_gap_
                = std::move(v);
    }
    absl::optional<Length>& MutableColumnGapInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_gap_;
    }
    // column-rule-color
    const StyleColor& ColumnRuleColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->column_rule_color_;
    }
    void SetColumnRuleColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_rule_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_rule_color_
                = std::move(v);
    }
    StyleColor& MutableColumnRuleColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_rule_color_;
    }
    // column-rule-style

    EBorderStyle MutableColumnRuleStyleInternal()
    {
        return static_cast<EBorderStyle>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                             ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                             ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                             ->column_rule_style_);
    }
    // column-rule-width
    const LayoutUnit& ColumnRuleWidthInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->column_rule_width_;
    }

    void SetColumnRuleWidthInternal(const LayoutUnit& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_rule_width_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_rule_width_
                = v;
    }

    void SetColumnRuleWidthInternal(LayoutUnit&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_rule_width_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_rule_width_
                = std::move(v);
    }
    LayoutUnit& MutableColumnRuleWidthInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_rule_width_;
    }
    // column-span

    EColumnSpan MutableColumnSpanInternal()
    {
        return static_cast<EColumnSpan>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                            ->column_span_);
    }
    // column-width

    void SetColumnWidthInternal(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->column_width_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->column_width_
                = v;
    }

    float MutableColumnWidthInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->column_width_;
    }
    // CompositablePaintAnimationChanged

    bool MutableCompositablePaintAnimationChangedInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->compositable_paint_animation_changed_);
    }
    // contain

    unsigned MutableContainInternal()
    {
        return static_cast<unsigned>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                         ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                         ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                         ->contain_);
    }
    // contain-intrinsic-height

    void SetContainIntrinsicHeightInternal(absl::optional<StyleIntrinsicLength>&& v)
    {
        if (!(box_data_->contain_intrinsic_height_ == v))
            box_data_.Access()->contain_intrinsic_height_ = std::move(v);
    }
    absl::optional<StyleIntrinsicLength>& MutableContainIntrinsicHeightInternal() { return box_data_.Access()->contain_intrinsic_height_; }
    // contain-intrinsic-width

    void SetContainIntrinsicWidthInternal(absl::optional<StyleIntrinsicLength>&& v)
    {
        if (!(box_data_->contain_intrinsic_width_ == v))
            box_data_.Access()->contain_intrinsic_width_ = std::move(v);
    }
    absl::optional<StyleIntrinsicLength>& MutableContainIntrinsicWidthInternal() { return box_data_.Access()->contain_intrinsic_width_; }
    // container-name

    void SetContainerNameInternal(Vector<AtomicString>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->container_name_ = std::move(v);
    }
    Vector<AtomicString>& MutableContainerNameInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->container_name_;
    }
    // container-type

    unsigned MutableContainerTypeInternal()
    {
        return static_cast<unsigned>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->container_type_);
    }
    // content
    const Persistent<ContentData>& ContentInternal() const { return rare_non_inherited_usage_less_than_14_percent_data_->content_; }

    void SetContentInternal(Persistent<ContentData>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->content_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->content_ = std::move(v);
    }
    Persistent<ContentData>& MutableContentInternal() { return rare_non_inherited_usage_less_than_14_percent_data_.Access()->content_; }
    // content-visibility

    EContentVisibility MutableContentVisibilityInternal() { return static_cast<EContentVisibility>(content_visibility_); }
    // CounterDirectives
    const std::unique_ptr<CounterDirectiveMap>& CounterDirectivesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_;
    }

    void SetCounterDirectivesInternal(std::unique_ptr<CounterDirectiveMap>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->counter_directives_ = std::move(v);
    }
    std::unique_ptr<CounterDirectiveMap>& MutableCounterDirectivesInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->counter_directives_;
    }
    // CssDominantBaseline

    EDominantBaseline MutableCssDominantBaselineInternal() { return static_cast<EDominantBaseline>(svg_data_.Access()->css_dominant_baseline_); }
    // cursor

    ECursor MutableCursorInternal() { return static_cast<ECursor>(cursor_); }
    // CursorData
    const Persistent<CursorList>& CursorDataInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_;
    }

    void SetCursorDataInternal(Persistent<CursorList>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->cursor_data_ = std::move(v);
    }
    Persistent<CursorList>& MutableCursorDataInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->cursor_data_;
    }
    // CustomHighlightNames
    const std::unique_ptr<HashSet<AtomicString>>& CustomHighlightNamesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_;
    }

    void SetCustomHighlightNamesInternal(std::unique_ptr<HashSet<AtomicString>>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->custom_highlight_names_ = std::move(v);
    }
    std::unique_ptr<HashSet<AtomicString>>& MutableCustomHighlightNamesInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->custom_highlight_names_;
    }
    // CustomStyleCallbackDependsOnFont

    // cx

    void SetCxInternal(Length&& v)
    {
        if (!(svg_data_->geometry_data_->cx_ == v))
            svg_data_.Access()->geometry_data_.Access()->cx_ = std::move(v);
    }
    Length& MutableCxInternal() { return svg_data_.Access()->geometry_data_.Access()->cx_; }
    // cy

    void SetCyInternal(Length&& v)
    {
        if (!(svg_data_->geometry_data_->cy_ == v))
            svg_data_.Access()->geometry_data_.Access()->cy_ = std::move(v);
    }
    Length& MutableCyInternal() { return svg_data_.Access()->geometry_data_.Access()->cy_; }
    // DarkColorScheme

    bool MutableDarkColorSchemeInternal() { return static_cast<bool>(dark_color_scheme_); }
    // DependsOnSizeContainerQueries

    bool MutableDependsOnSizeContainerQueriesInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->depends_on_size_container_queries_);
    }
    // DependsOnStyleContainerQueries

    bool MutableDependsOnStyleContainerQueriesInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->depends_on_style_container_queries_);
    }
    // direction

    TextDirection MutableDirectionInternal() { return static_cast<TextDirection>(direction_); }
    // Display

    EDisplay MutableDisplayInternal() { return static_cast<EDisplay>(display_); }
    // DisplayLayoutCustomName

    void SetDisplayLayoutCustomNameInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_name_
                = std::move(v);
    }
    AtomicString& MutableDisplayLayoutCustomNameInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_name_;
    }
    // DisplayLayoutCustomParentName

    void SetDisplayLayoutCustomParentNameInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_parent_name_
                = std::move(v);
    }
    AtomicString& MutableDisplayLayoutCustomParentNameInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->display_layout_custom_parent_name_;
    }
    // dominant-baseline

    EDominantBaseline MutableDominantBaselineInternal() { return static_cast<EDominantBaseline>(svg_data_.Access()->dominant_baseline_); }
    // app-region

    EDraggableRegionMode MutableDraggableRegionModeInternal()
    {
        return static_cast<EDraggableRegionMode>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                                     ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                                     ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                                     ->draggable_region_mode_);
    }
    // EffectiveAppearance

    ControlPart MutableEffectiveAppearanceInternal()
    {
        return static_cast<ControlPart>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->effective_appearance_);
    }
    // EffectiveTouchAction
    TouchAction EffectiveTouchActionInternal() const
    {
        return static_cast<TouchAction>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_);
    }

    void SetEffectiveTouchActionInternal(TouchAction v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->effective_touch_action_
                = static_cast<unsigned>(v);
    }

    TouchAction MutableEffectiveTouchActionInternal()
    {
        return static_cast<TouchAction>(
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->effective_touch_action_);
    }
    // EffectiveZIndexZero

    bool MutableEffectiveZIndexZeroInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->effective_z_index_zero_);
    }
    // EffectiveZoom

    void SetEffectiveZoomInternal(float v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->effective_zoom_ = v;
    }

    float MutableEffectiveZoomInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->effective_zoom_;
    }
    // empty-cells

    EEmptyCells MutableEmptyCellsInternal() { return static_cast<EEmptyCells>(empty_cells_); }
    // empty-cells

    bool MutableEmptyCellsIsInheritedInternal() { return static_cast<bool>(empty_cells_is_inherited_); }
    // fill-opacity

    float MutableFillOpacityInternal() { return svg_data_.Access()->fill_data_.Access()->fill_opacity_; }
    // fill

    void SetFillPaintInternal(SVGPaint&& v)
    {
        if (!(svg_data_->fill_data_->fill_paint_ == v))
            svg_data_.Access()->fill_data_.Access()->fill_paint_ = std::move(v);
    }
    SVGPaint& MutableFillPaintInternal() { return svg_data_.Access()->fill_data_.Access()->fill_paint_; }
    // fill-rule

    WindRule MutableFillRuleInternal() { return static_cast<WindRule>(svg_data_.Access()->fill_rule_); }
    // filter
    const Persistent<StyleFilterData>& FilterInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_;
    }

    void SetFilterInternal(Persistent<StyleFilterData>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->filter_ = std::move(v);
    }
    Persistent<StyleFilterData>& MutableFilterInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->filter_;
    }
    // FirstLineDependsOnSizeContainerQueries

    bool MutableFirstLineDependsOnSizeContainerQueriesInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->first_line_depends_on_size_container_queries_);
    }
    // flex-basis

    void SetFlexBasisInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_basis_ = std::move(v);
    }
    Length& MutableFlexBasisInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_basis_;
    }
    // flex-direction

    EFlexDirection MutableFlexDirectionInternal() { return static_cast<EFlexDirection>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->flex_direction_); }
    // flex-grow

    float MutableFlexGrowInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_grow_;
    }
    // flex-shrink

    float MutableFlexShrinkInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->flex_shrink_;
    }
    // flex-wrap

    EFlexWrap MutableFlexWrapInternal() { return static_cast<EFlexWrap>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->flex_wrap_); }
    // float
    EFloat FloatingInternal() const { return static_cast<EFloat>(floating_); }
    EFloat MutableFloatingInternal() { return static_cast<EFloat>(floating_); }
    // flood-color

    void SetFloodColorInternal(StyleColor&& v)
    {
        if (!(svg_data_->misc_data_->flood_color_ == v))
            svg_data_.Access()->misc_data_.Access()->flood_color_ = std::move(v);
    }
    StyleColor& MutableFloodColorInternal() { return svg_data_.Access()->misc_data_.Access()->flood_color_; }
    // flood-opacity

    float MutableFloodOpacityInternal() { return svg_data_.Access()->misc_data_.Access()->flood_opacity_; }
    // font
    const Font& FontInternal() const { return inherited_data_->font_data_->font_; }

    void SetFontInternal(const Font& v)
    {
        if (!(inherited_data_->font_data_->font_ == v))
            inherited_data_.Access()->font_data_.Access()->font_ = v;
    }

    void SetFontInternal(Font&& v)
    {
        if (!(inherited_data_->font_data_->font_ == v))
            inherited_data_.Access()->font_data_.Access()->font_ = std::move(v);
    }
    Font& MutableFontInternal() { return inherited_data_.Access()->font_data_.Access()->font_; }
    // forced-color-adjust

    EForcedColorAdjust MutableForcedColorAdjustInternal()
    {
        return static_cast<EForcedColorAdjust>(rare_inherited_usage_less_than_64_percent_data_.Access()->forced_color_adjust_);
    }
    // grid-auto-columns

    void SetGridAutoColumnsInternal(GridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_auto_columns_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_auto_columns_
                = std::move(v);
    }
    GridTrackList& MutableGridAutoColumnsInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_auto_columns_;
    }
    // grid-auto-flow
    GridAutoFlow GridAutoFlowInternal() const
    {
        return static_cast<GridAutoFlow>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                             ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_);
    }
    GridAutoFlow MutableGridAutoFlowInternal()
    {
        return static_cast<GridAutoFlow>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                             ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                             ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                             ->grid_auto_flow_);
    }
    // grid-auto-rows

    void SetGridAutoRowsInternal(GridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_auto_rows_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_auto_rows_
                = std::move(v);
    }
    GridTrackList& MutableGridAutoRowsInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_auto_rows_;
    }
    // grid-column-end

    void SetGridColumnEndInternal(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_column_end_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_column_end_
                = std::move(v);
    }
    GridPosition& MutableGridColumnEndInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_column_end_;
    }
    // grid-column-start

    void SetGridColumnStartInternal(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_column_start_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_column_start_
                = std::move(v);
    }
    GridPosition& MutableGridColumnStartInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_column_start_;
    }
    // grid-row-end

    void SetGridRowEndInternal(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_row_end_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_row_end_
                = std::move(v);
    }
    GridPosition& MutableGridRowEndInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_row_end_;
    }
    // grid-row-start

    void SetGridRowStartInternal(GridPosition&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->grid_row_start_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->grid_row_start_
                = std::move(v);
    }
    GridPosition& MutableGridRowStartInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->grid_row_start_;
    }
    // grid-template-columns

    void SetGridTemplateColumnsInternal(ComputedGridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->grid_template_columns_
                = std::move(v);
    }
    ComputedGridTrackList& MutableGridTemplateColumnsInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->grid_template_columns_;
    }
    // grid-template-rows

    void SetGridTemplateRowsInternal(ComputedGridTrackList&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->grid_data_.Access()->grid_template_rows_
                = std::move(v);
    }
    ComputedGridTrackList& MutableGridTemplateRowsInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->grid_template_rows_;
    }
    // HasAttrContent

    // HasAuthorBackground

    // HasAuthorBorder

    // HasAuthorBorderRadius

    // HasAuthorHighlightColors

    // HasAutoClip

    void SetHasAutoClipInternal(bool v)
    {
        if (!(visual_data_->has_auto_clip_ == static_cast<unsigned>(v)))
            visual_data_.Access()->has_auto_clip_ = static_cast<unsigned>(v);
    }

    bool MutableHasAutoClipInternal() { return static_cast<bool>(visual_data_.Access()->has_auto_clip_); }
    // HasAutoColumnCount

    void SetHasAutoColumnCountInternal(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_auto_column_count_
                = static_cast<unsigned>(v);
    }

    bool MutableHasAutoColumnCountInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_auto_column_count_);
    }
    // HasAutoColumnWidth

    void SetHasAutoColumnWidthInternal(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_ == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_auto_column_width_
                = static_cast<unsigned>(v);
    }

    bool MutableHasAutoColumnWidthInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_auto_column_width_);
    }
    // HasAutoZIndex

    void SetHasAutoZIndexInternal(bool v)
    {
        if (!(box_data_->has_auto_z_index_ == static_cast<unsigned>(v)))
            box_data_.Access()->has_auto_z_index_ = static_cast<unsigned>(v);
    }

    bool MutableHasAutoZIndexInternal() { return static_cast<bool>(box_data_.Access()->has_auto_z_index_); }
    // HasClipPath

    bool MutableHasClipPathInternal() { return static_cast<bool>(visual_data_.Access()->has_clip_path_); }
    // HasContainerRelativeUnits

    // HasCurrentBackdropFilterAnimation

    bool MutableHasCurrentBackdropFilterAnimationInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_backdrop_filter_animation_);
    }
    // HasCurrentBackgroundColorAnimation

    bool MutableHasCurrentBackgroundColorAnimationInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->has_current_background_color_animation_);
    }
    // HasCurrentClipPathAnimation

    bool MutableHasCurrentClipPathAnimationInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_clip_path_animation_);
    }
    // HasCurrentFilterAnimation

    bool MutableHasCurrentFilterAnimationInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_filter_animation_);
    }
    // HasCurrentOpacityAnimation

    bool MutableHasCurrentOpacityAnimationInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_opacity_animation_);
    }
    // HasCurrentRotateAnimation

    bool MutableHasCurrentRotateAnimationInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_rotate_animation_);
    }
    // HasCurrentScaleAnimation

    bool MutableHasCurrentScaleAnimationInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_scale_animation_);
    }
    // HasCurrentTransformAnimation

    bool MutableHasCurrentTransformAnimationInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_transform_animation_);
    }
    // HasCurrentTranslateAnimation

    bool MutableHasCurrentTranslateAnimationInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_current_translate_animation_);
    }
    // HasEmUnits

    // HasExplicitInheritance

    // HasExplicitOverflowXVisible

    void SetHasExplicitOverflowXVisibleInternal(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_explicit_overflow_x_visible_
                = static_cast<unsigned>(v);
    }

    bool MutableHasExplicitOverflowXVisibleInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_explicit_overflow_x_visible_);
    }
    // HasExplicitOverflowYVisible

    void SetHasExplicitOverflowYVisibleInternal(bool v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_
                == static_cast<unsigned>(v)))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_explicit_overflow_y_visible_
                = static_cast<unsigned>(v);
    }

    bool MutableHasExplicitOverflowYVisibleInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->has_explicit_overflow_y_visible_);
    }
    // HasGlyphRelativeUnits

    // HasLineHeightRelativeUnits

    // -internal-empty-line-height

    bool MutableHasLineIfEmptyInternal()
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->has_line_if_empty_);
    }
    // HasNonUniversalHighlightPseudoStyles

    bool MutableHasNonUniversalHighlightPseudoStylesInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->has_non_universal_highlight_pseudo_styles_);
    }
    // HasRemUnits

    // HasSimpleUnderline
    bool HasSimpleUnderlineInternal() const { return static_cast<bool>(has_simple_underline_); }

    void SetHasSimpleUnderlineInternal(bool v) { has_simple_underline_ = static_cast<unsigned>(v); }

    bool MutableHasSimpleUnderlineInternal() { return static_cast<bool>(has_simple_underline_); }
    // HasVariableDeclaration

    // HasVariableReference

    // HasVariableReferenceFromNonInheritedProperty

    // height

    void SetHeightInternal(Length&& v)
    {
        if (!(box_data_->height_ == v))
            box_data_.Access()->height_ = std::move(v);
    }
    Length& MutableHeightInternal() { return box_data_.Access()->height_; }
    // -webkit-highlight

    void SetHighlightInternal(AtomicString&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->highlight_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->highlight_ = std::move(v);
    }
    AtomicString& MutableHighlightInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->highlight_; }
    // HighlightData

    void SetHighlightDataInternal(scoped_refptr<StyleHighlightData>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->highlight_data_ = std::move(v);
    }
    scoped_refptr<StyleHighlightData>& MutableHighlightDataInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->highlight_data_;
    }
    // -webkit-border-horizontal-spacing

    short MutableHorizontalBorderSpacingInternal() { return inherited_data_.Access()->horizontal_border_spacing_; }
    // hyphenate-limit-chars

    void SetHyphenateLimitCharsInternal(StyleHyphenateLimitChars&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->hyphenate_limit_chars_ = std::move(v);
    }
    StyleHyphenateLimitChars& MutableHyphenateLimitCharsInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->hyphenate_limit_chars_;
    }
    // hyphenate-character

    void SetHyphenationStringInternal(AtomicString&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->hyphenation_string_ = std::move(v);
    }
    AtomicString& MutableHyphenationStringInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->hyphenation_string_; }
    // hyphens

    Hyphens MutableHyphensInternal() { return static_cast<Hyphens>(rare_inherited_usage_less_than_64_percent_data_.Access()->hyphens_); }
    // image-rendering

    EImageRendering MutableImageRenderingInternal() { return static_cast<EImageRendering>(rare_inherited_usage_less_than_64_percent_data_.Access()->image_rendering_); }
    // ImplicitNamedGridColumnLines

    void SetImplicitNamedGridColumnLinesInternal(NamedGridLinesMap&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_column_lines_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->implicit_named_grid_column_lines_
                = std::move(v);
    }
    NamedGridLinesMap& MutableImplicitNamedGridColumnLinesInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->implicit_named_grid_column_lines_;
    }
    // ImplicitNamedGridRowLines

    void SetImplicitNamedGridRowLinesInternal(NamedGridLinesMap&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_row_lines_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->grid_data_.Access()
                ->implicit_named_grid_row_lines_
                = std::move(v);
    }
    NamedGridLinesMap& MutableImplicitNamedGridRowLinesInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->implicit_named_grid_row_lines_;
    }
    // InForcedColorsMode

    bool MutableInForcedColorsModeInternal() { return static_cast<bool>(inherited_data_.Access()->in_forced_colors_mode_); }
    // InheritedVariables
    const scoped_refptr<StyleInheritedVariables>& InheritedVariablesInternal() const { return inherited_data_->inherited_variables_; }

    void SetInheritedVariablesInternal(scoped_refptr<StyleInheritedVariables>&& v)
    {
        if (!(inherited_data_->inherited_variables_ == v))
            inherited_data_.Access()->inherited_variables_ = std::move(v);
    }
    scoped_refptr<StyleInheritedVariables>& MutableInheritedVariablesInternal() { return inherited_data_.Access()->inherited_variables_; }
    // InitialData

    void SetInitialDataInternal(scoped_refptr<StyleInitialData>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->initial_data_ = std::move(v);
    }
    scoped_refptr<StyleInitialData>& MutableInitialDataInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->initial_data_;
    }
    // initial-letter

    void SetInitialLetterInternal(StyleInitialLetter&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->initial_letter_ = std::move(v);
    }
    StyleInitialLetter& MutableInitialLetterInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->initial_letter_;
    }
    // InlineStyleLostCascade

    bool MutableInlineStyleLostCascadeInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->inline_style_lost_cascade_);
    }
    // InsideFragmentationContextWithNondeterministicEngine

    bool MutableInsideFragmentationContextWithNondeterministicEngineInternal() { return static_cast<bool>(inside_fragmentation_context_with_nondeterministic_engine_); }
    // InsideLink

    EInsideLink MutableInsideLinkInternal() { return static_cast<EInsideLink>(inside_link_); }
    // -internal-forced-background-color
    const StyleColor& InternalForcedBackgroundColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_background_color_;
    }
    void SetInternalForcedBackgroundColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_background_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->forced_colors_data_.Access()
                ->internal_forced_background_color_
                = std::move(v);
    }
    StyleColor& MutableInternalForcedBackgroundColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->forced_colors_data_.Access()
            ->internal_forced_background_color_;
    }
    // -internal-forced-border-color
    const StyleColor& InternalForcedBorderColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_border_color_;
    }
    void SetInternalForcedBorderColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_border_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->forced_colors_data_.Access()
                ->internal_forced_border_color_
                = std::move(v);
    }
    StyleColor& MutableInternalForcedBorderColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->forced_colors_data_.Access()
            ->internal_forced_border_color_;
    }
    // -internal-forced-color
    const StyleColor& InternalForcedColorInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_color_;
    }
    void SetInternalForcedColorInternal(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_forced_colors_data_.Access()
                ->internal_forced_color_
                = std::move(v);
    }
    StyleColor& MutableInternalForcedColorInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_forced_colors_data_.Access()
            ->internal_forced_color_;
    }
    // -internal-forced-outline-color
    const StyleColor& InternalForcedOutlineColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_outline_color_;
    }
    void SetInternalForcedOutlineColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_outline_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->forced_colors_data_.Access()
                ->internal_forced_outline_color_
                = std::move(v);
    }
    StyleColor& MutableInternalForcedOutlineColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->forced_colors_data_.Access()
            ->internal_forced_outline_color_;
    }
    // -internal-forced-visited-color
    const StyleColor& InternalForcedVisitedColorInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_visited_color_;
    }

    void SetInternalForcedVisitedColorInternal(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_visited_color_
                == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_forced_colors_data_.Access()
                ->internal_forced_visited_color_
                = v;
    }

    void SetInternalForcedVisitedColorInternal(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_visited_color_
                == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_forced_colors_data_.Access()
                ->internal_forced_visited_color_
                = std::move(v);
    }
    StyleColor& MutableInternalForcedVisitedColorInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_forced_colors_data_.Access()
            ->internal_forced_visited_color_;
    }
    // -internal-visited-background-color
    const StyleColor& InternalVisitedBackgroundColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_background_color_;
    }

    void SetInternalVisitedBackgroundColorInternal(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_background_color_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_background_color_
                = v;
    }

    void SetInternalVisitedBackgroundColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_background_color_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_background_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedBackgroundColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_background_color_;
    }
    // -internal-visited-border-bottom-color
    const StyleColor& InternalVisitedBorderBottomColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_bottom_color_;
    }

    void SetInternalVisitedBorderBottomColorInternal(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_bottom_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_border_bottom_color_
                = v;
    }

    void SetInternalVisitedBorderBottomColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_bottom_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_border_bottom_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedBorderBottomColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_border_bottom_color_;
    }
    // -internal-visited-border-left-color
    const StyleColor& InternalVisitedBorderLeftColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_left_color_;
    }

    void SetInternalVisitedBorderLeftColorInternal(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_left_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_border_left_color_
                = v;
    }

    void SetInternalVisitedBorderLeftColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_left_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_border_left_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedBorderLeftColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_border_left_color_;
    }
    // -internal-visited-border-right-color
    const StyleColor& InternalVisitedBorderRightColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_right_color_;
    }

    void SetInternalVisitedBorderRightColorInternal(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_right_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_border_right_color_
                = v;
    }

    void SetInternalVisitedBorderRightColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_right_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_border_right_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedBorderRightColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_border_right_color_;
    }
    // -internal-visited-border-top-color
    const StyleColor& InternalVisitedBorderTopColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_top_color_;
    }

    void SetInternalVisitedBorderTopColorInternal(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_top_color_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_border_top_color_
                = v;
    }

    void SetInternalVisitedBorderTopColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_top_color_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_border_top_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedBorderTopColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_border_top_color_;
    }
    // -internal-visited-caret-color
    const StyleAutoColor& InternalVisitedCaretColorInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_caret_color_;
    }
    void SetInternalVisitedCaretColorInternal(StyleAutoColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_caret_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_visited_data_.Access()
                ->internal_visited_caret_color_
                = std::move(v);
    }
    StyleAutoColor& MutableInternalVisitedCaretColorInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_visited_data_.Access()
            ->internal_visited_caret_color_;
    }
    // -internal-visited-color
    const StyleColor& InternalVisitedColorInternal() const { return inherited_data_->internal_visited_color_; }

    void SetInternalVisitedColorInternal(const StyleColor& v)
    {
        if (!(inherited_data_->internal_visited_color_ == v))
            inherited_data_.Access()->internal_visited_color_ = v;
    }

    void SetInternalVisitedColorInternal(StyleColor&& v)
    {
        if (!(inherited_data_->internal_visited_color_ == v))
            inherited_data_.Access()->internal_visited_color_ = std::move(v);
    }
    StyleColor& MutableInternalVisitedColorInternal() { return inherited_data_.Access()->internal_visited_color_; }
    // InternalVisitedColorIsCurrentColor
    bool InternalVisitedColorIsCurrentColorInternal() const { return static_cast<bool>(inherited_data_->internal_visited_color_is_current_color_); }
    bool MutableInternalVisitedColorIsCurrentColorInternal() { return static_cast<bool>(inherited_data_.Access()->internal_visited_color_is_current_color_); }
    // -internal-visited-column-rule-color
    const StyleColor& InternalVisitedColumnRuleColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_column_rule_color_;
    }

    void SetInternalVisitedColumnRuleColorInternal(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_column_rule_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_column_rule_color_
                = v;
    }

    void SetInternalVisitedColumnRuleColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_column_rule_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_column_rule_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedColumnRuleColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_column_rule_color_;
    }
    // -internal-visited-fill

    void SetInternalVisitedFillPaintInternal(SVGPaint&& v)
    {
        if (!(svg_data_->fill_data_->internal_visited_fill_paint_ == v))
            svg_data_.Access()->fill_data_.Access()->internal_visited_fill_paint_ = std::move(v);
    }
    SVGPaint& MutableInternalVisitedFillPaintInternal() { return svg_data_.Access()->fill_data_.Access()->internal_visited_fill_paint_; }
    // -internal-visited-outline-color
    const StyleColor& InternalVisitedOutlineColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_outline_color_;
    }

    void SetInternalVisitedOutlineColorInternal(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_outline_color_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_outline_color_
                = v;
    }

    void SetInternalVisitedOutlineColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_outline_color_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_outline_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedOutlineColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_outline_color_;
    }
    // -internal-visited-stroke

    void SetInternalVisitedStrokePaintInternal(SVGPaint&& v)
    {
        if (!(svg_data_->stroke_data_->internal_visited_stroke_paint_ == v))
            svg_data_.Access()->stroke_data_.Access()->internal_visited_stroke_paint_ = std::move(v);
    }
    SVGPaint& MutableInternalVisitedStrokePaintInternal() { return svg_data_.Access()->stroke_data_.Access()->internal_visited_stroke_paint_; }
    // -internal-visited-text-decoration-color
    const StyleColor& InternalVisitedTextDecorationColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_text_decoration_color_;
    }

    void SetInternalVisitedTextDecorationColorInternal(const StyleColor& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_text_decoration_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_text_decoration_color_
                = v;
    }

    void SetInternalVisitedTextDecorationColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_text_decoration_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->visited_data_.Access()
                ->internal_visited_text_decoration_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedTextDecorationColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->visited_data_.Access()
            ->internal_visited_text_decoration_color_;
    }
    // -internal-visited-text-emphasis-color
    const StyleColor& InternalVisitedTextEmphasisColorInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_emphasis_color_;
    }

    void SetInternalVisitedTextEmphasisColorInternal(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_emphasis_color_
                == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_visited_data_.Access()
                ->internal_visited_text_emphasis_color_
                = v;
    }

    void SetInternalVisitedTextEmphasisColorInternal(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_emphasis_color_
                == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_visited_data_.Access()
                ->internal_visited_text_emphasis_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedTextEmphasisColorInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_visited_data_.Access()
            ->internal_visited_text_emphasis_color_;
    }
    // -internal-visited-text-fill-color
    const StyleColor& InternalVisitedTextFillColorInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_fill_color_;
    }

    void SetInternalVisitedTextFillColorInternal(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_fill_color_
                == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_visited_data_.Access()
                ->internal_visited_text_fill_color_
                = v;
    }

    void SetInternalVisitedTextFillColorInternal(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_fill_color_
                == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_visited_data_.Access()
                ->internal_visited_text_fill_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedTextFillColorInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_visited_data_.Access()
            ->internal_visited_text_fill_color_;
    }
    // -internal-visited-text-stroke-color
    const StyleColor& InternalVisitedTextStrokeColorInternal() const
    {
        return rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_stroke_color_;
    }

    void SetInternalVisitedTextStrokeColorInternal(const StyleColor& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_stroke_color_
                == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_visited_data_.Access()
                ->internal_visited_text_stroke_color_
                = v;
    }

    void SetInternalVisitedTextStrokeColorInternal(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_stroke_color_
                == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()
                ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
                ->inherited_visited_data_.Access()
                ->internal_visited_text_stroke_color_
                = std::move(v);
    }
    StyleColor& MutableInternalVisitedTextStrokeColorInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()
            ->rare_inherited_usage_less_than_64_percent_sub_data_.Access()
            ->inherited_visited_data_.Access()
            ->internal_visited_text_stroke_color_;
    }
    // IsEnsuredInDisplayNone

    // IsEnsuredOutsideFlatTree

    // IsFlexOrGridItem

    // IsFlexOrGridOrCustomItem

    // IsInBlockifyingDisplay

    // IsInert

    bool MutableIsInertInternal() { return static_cast<bool>(is_inert_); }
    // IsInert

    bool MutableIsInertIsInheritedInternal() { return static_cast<bool>(is_inert_is_inherited_); }
    // IsInsideListElement

    // IsLink

    // IsRunningBackdropFilterAnimationOnCompositor

    bool MutableIsRunningBackdropFilterAnimationOnCompositorInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->is_running_backdrop_filter_animation_on_compositor_);
    }
    // IsRunningFilterAnimationOnCompositor

    bool MutableIsRunningFilterAnimationOnCompositorInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->is_running_filter_animation_on_compositor_);
    }
    // IsRunningOpacityAnimationOnCompositor

    bool MutableIsRunningOpacityAnimationOnCompositorInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->is_running_opacity_animation_on_compositor_);
    }
    // IsRunningRotateAnimationOnCompositor

    bool MutableIsRunningRotateAnimationOnCompositorInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->is_running_rotate_animation_on_compositor_);
    }
    // IsRunningScaleAnimationOnCompositor

    bool MutableIsRunningScaleAnimationOnCompositorInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->is_running_scale_animation_on_compositor_);
    }
    // IsRunningTransformAnimationOnCompositor

    bool MutableIsRunningTransformAnimationOnCompositorInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->is_running_transform_animation_on_compositor_);
    }
    // IsRunningTranslateAnimationOnCompositor

    bool MutableIsRunningTranslateAnimationOnCompositorInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->is_running_translate_animation_on_compositor_);
    }
    // IsSecondaryBodyElement

    // IsStackingContextWithoutContainment

    bool MutableIsStackingContextWithoutContainmentInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->is_stacking_context_without_containment_);
    }
    // isolation

    EIsolation MutableIsolationInternal()
    {
        return static_cast<EIsolation>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                           ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                           ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                           ->isolation_);
    }
    // stroke-linejoin

    LineJoin MutableJoinStyleInternal() { return static_cast<LineJoin>(svg_data_.Access()->stroke_data_.Access()->join_style_); }
    // justify-content

    void SetJustifyContentInternal(StyleContentAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->justify_content_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->justify_content_ = std::move(v);
    }
    StyleContentAlignmentData& MutableJustifyContentInternal() { return rare_non_inherited_usage_less_than_14_percent_data_.Access()->justify_content_; }
    // justify-items

    void SetJustifyItemsInternal(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->justify_items_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->justify_items_
                = std::move(v);
    }
    StyleSelfAlignmentData& MutableJustifyItemsInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->justify_items_;
    }
    // justify-self

    void SetJustifySelfInternal(StyleSelfAlignmentData&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->justify_self_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->justify_self_
                = std::move(v);
    }
    StyleSelfAlignmentData& MutableJustifySelfInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->justify_self_;
    }
    // left

    void SetLeftInternal(Length&& v)
    {
        if (!(surround_data_->left_ == v))
            surround_data_.Access()->left_ = std::move(v);
    }
    Length& MutableLeftInternal() { return surround_data_.Access()->left_; }
    // lighting-color

    void SetLightingColorInternal(StyleColor&& v)
    {
        if (!(svg_data_->misc_data_->lighting_color_ == v))
            svg_data_.Access()->misc_data_.Access()->lighting_color_ = std::move(v);
    }
    StyleColor& MutableLightingColorInternal() { return svg_data_.Access()->misc_data_.Access()->lighting_color_; }
    // -webkit-line-break

    LineBreak MutableLineBreakInternal() { return static_cast<LineBreak>(rare_inherited_usage_less_than_64_percent_data_.Access()->line_break_); }
    // -webkit-line-clamp

    void SetLineClampInternal(int&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->line_clamp_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->line_clamp_ = std::move(v);
    }
    int& MutableLineClampInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->line_clamp_;
    }
    // line-height
    const Length& LineHeightInternal() const { return inherited_data_->line_height_; }
    void SetLineHeightInternal(Length&& v)
    {
        if (!(inherited_data_->line_height_ == v))
            inherited_data_.Access()->line_height_ = std::move(v);
    }
    Length& MutableLineHeightInternal() { return inherited_data_.Access()->line_height_; }
    // line-height-step

    uint8_t MutableLineHeightStepInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->line_height_step_;
    }
    // list-style-image
    const Persistent<StyleImage>& ListStyleImageInternal() const { return rare_inherited_usage_less_than_64_percent_data_->list_style_image_; }

    void SetListStyleImageInternal(Persistent<StyleImage>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->list_style_image_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->list_style_image_ = std::move(v);
    }
    Persistent<StyleImage>& MutableListStyleImageInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->list_style_image_; }
    // list-style-position

    EListStylePosition MutableListStylePositionInternal() { return static_cast<EListStylePosition>(list_style_position_); }
    // list-style-position

    bool MutableListStylePositionIsInheritedInternal() { return static_cast<bool>(list_style_position_is_inherited_); }
    // list-style-type

    void SetListStyleTypeInternal(Persistent<ListStyleTypeData>&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->list_style_type_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->list_style_type_ = std::move(v);
    }
    Persistent<ListStyleTypeData>& MutableListStyleTypeInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->list_style_type_; }
    // margin-bottom

    void SetMarginBottomInternal(const Length& v)
    {
        if (!(surround_data_->margin_bottom_ == v))
            surround_data_.Access()->margin_bottom_ = v;
    }

    void SetMarginBottomInternal(Length&& v)
    {
        if (!(surround_data_->margin_bottom_ == v))
            surround_data_.Access()->margin_bottom_ = std::move(v);
    }
    Length& MutableMarginBottomInternal() { return surround_data_.Access()->margin_bottom_; }
    // margin-left

    void SetMarginLeftInternal(const Length& v)
    {
        if (!(surround_data_->margin_left_ == v))
            surround_data_.Access()->margin_left_ = v;
    }

    void SetMarginLeftInternal(Length&& v)
    {
        if (!(surround_data_->margin_left_ == v))
            surround_data_.Access()->margin_left_ = std::move(v);
    }
    Length& MutableMarginLeftInternal() { return surround_data_.Access()->margin_left_; }
    // margin-right

    void SetMarginRightInternal(const Length& v)
    {
        if (!(surround_data_->margin_right_ == v))
            surround_data_.Access()->margin_right_ = v;
    }

    void SetMarginRightInternal(Length&& v)
    {
        if (!(surround_data_->margin_right_ == v))
            surround_data_.Access()->margin_right_ = std::move(v);
    }
    Length& MutableMarginRightInternal() { return surround_data_.Access()->margin_right_; }
    // margin-top

    void SetMarginTopInternal(const Length& v)
    {
        if (!(surround_data_->margin_top_ == v))
            surround_data_.Access()->margin_top_ = v;
    }

    void SetMarginTopInternal(Length&& v)
    {
        if (!(surround_data_->margin_top_ == v))
            surround_data_.Access()->margin_top_ = std::move(v);
    }
    Length& MutableMarginTopInternal() { return surround_data_.Access()->margin_top_; }
    // Mask
    const FillLayer& MaskInternal() const { return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_; }

    void SetMaskInternal(const FillLayer& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->mask_ = v;
    }

    void SetMaskInternal(FillLayer&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->mask_ = std::move(v);
    }
    FillLayer& MutableMaskInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->mask_;
    }
    // MaskBoxImage
    const NinePieceImage& MaskBoxImageInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_;
    }

    void SetMaskBoxImageInternal(const NinePieceImage& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->mask_box_image_ = v;
    }

    void SetMaskBoxImageInternal(NinePieceImage&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->mask_box_image_ = std::move(v);
    }
    NinePieceImage& MutableMaskBoxImageInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->mask_box_image_;
    }
    // mask-type

    EMaskType MutableMaskTypeInternal() { return static_cast<EMaskType>(svg_data_.Access()->mask_type_); }
    // MathBaseline

    void SetMathBaselineInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_baseline_
                = std::move(v);
    }
    Length& MutableMathBaselineInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_baseline_;
    }
    // math-depth

    short MutableMathDepthInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->math_depth_; }
    // MathFractionBarThickness

    void SetMathFractionBarThicknessInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_fraction_bar_thickness_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->math_data_.Access()
                ->math_fraction_bar_thickness_
                = std::move(v);
    }
    Length& MutableMathFractionBarThicknessInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->math_data_.Access()
            ->math_fraction_bar_thickness_;
    }
    // MathLSpace

    void SetMathLSpaceInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_l_space_
                = std::move(v);
    }
    Length& MutableMathLSpaceInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_l_space_;
    }
    // MathMaxSize

    void SetMathMaxSizeInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_max_size_
                = std::move(v);
    }
    Length& MutableMathMaxSizeInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_max_size_;
    }
    // MathMinSize

    void SetMathMinSizeInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_min_size_
                = std::move(v);
    }
    Length& MutableMathMinSizeInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_min_size_;
    }
    // MathPaddedDepth

    void SetMathPaddedDepthInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_padded_depth_
                = std::move(v);
    }
    Length& MutableMathPaddedDepthInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->math_data_.Access()
            ->math_padded_depth_;
    }
    // MathPaddedVOffset

    void SetMathPaddedVOffsetInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->math_data_.Access()
                ->math_padded_v_offset_
                = std::move(v);
    }
    Length& MutableMathPaddedVOffsetInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->math_data_.Access()
            ->math_padded_v_offset_;
    }
    // MathRSpace

    void SetMathRSpaceInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_r_space_
                = std::move(v);
    }
    Length& MutableMathRSpaceInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->math_data_.Access()->math_r_space_;
    }
    // math-shift

    EMathShift MutableMathShiftInternal()
    {
        return static_cast<EMathShift>(rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->math_shift_);
    }
    // math-style

    EMathStyle MutableMathStyleInternal()
    {
        return static_cast<EMathStyle>(rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->math_style_);
    }
    // max-height

    void SetMaxHeightInternal(Length&& v)
    {
        if (!(box_data_->max_height_ == v))
            box_data_.Access()->max_height_ = std::move(v);
    }
    Length& MutableMaxHeightInternal() { return box_data_.Access()->max_height_; }
    // max-width

    void SetMaxWidthInternal(Length&& v)
    {
        if (!(box_data_->max_width_ == v))
            box_data_.Access()->max_width_ = std::move(v);
    }
    Length& MutableMaxWidthInternal() { return box_data_.Access()->max_width_; }
    // MayHaveMargin

    // MayHavePadding

    // min-height

    void SetMinHeightInternal(Length&& v)
    {
        if (!(box_data_->min_height_ == v))
            box_data_.Access()->min_height_ = std::move(v);
    }
    Length& MutableMinHeightInternal() { return box_data_.Access()->min_height_; }
    // min-width

    void SetMinWidthInternal(Length&& v)
    {
        if (!(box_data_->min_width_ == v))
            box_data_.Access()->min_width_ = std::move(v);
    }
    Length& MutableMinWidthInternal() { return box_data_.Access()->min_width_; }
    // NamedGridArea

    void SetNamedGridAreaInternal(NamedGridAreaMap&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->grid_data_.Access()->named_grid_area_
                = std::move(v);
    }
    NamedGridAreaMap& MutableNamedGridAreaInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->named_grid_area_;
    }
    // NamedGridAreaColumnCount

    wtf_size_t MutableNamedGridAreaColumnCountInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->named_grid_area_column_count_;
    }
    // NamedGridAreaRowCount

    wtf_size_t MutableNamedGridAreaRowCountInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->grid_data_.Access()
            ->named_grid_area_row_count_;
    }
    // NonInheritedVariables
    const std::unique_ptr<StyleNonInheritedVariables>& NonInheritedVariablesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_;
    }

    void SetNonInheritedVariablesInternal(std::unique_ptr<StyleNonInheritedVariables>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->non_inherited_variables_ = std::move(v);
    }
    std::unique_ptr<StyleNonInheritedVariables>& MutableNonInheritedVariablesInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->non_inherited_variables_;
    }
    // object-fit

    EObjectFit MutableObjectFitInternal()
    {
        return static_cast<EObjectFit>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->object_fit_);
    }
    // object-position

    void SetObjectPositionInternal(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->object_position_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->object_position_
                = std::move(v);
    }
    LengthPoint& MutableObjectPositionInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->object_position_;
    }
    // offset-anchor

    void SetOffsetAnchorInternal(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_anchor_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_anchor_
                = std::move(v);
    }
    LengthPoint& MutableOffsetAnchorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->offset_anchor_;
    }
    // offset-distance

    void SetOffsetDistanceInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_distance_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_distance_
                = std::move(v);
    }
    Length& MutableOffsetDistanceInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->offset_distance_;
    }
    // offset-position

    void SetOffsetPositionInternal(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_position_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_position_
                = std::move(v);
    }
    LengthPoint& MutableOffsetPositionInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->offset_position_;
    }
    // offset-rotate

    void SetOffsetRotateInternal(StyleOffsetRotation&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->offset_rotate_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->offset_rotate_
                = std::move(v);
    }
    StyleOffsetRotation& MutableOffsetRotateInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->offset_rotate_;
    }
    // opacity

    void SetOpacityInternal(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->opacity_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->opacity_ = v;
    }

    float MutableOpacityInternal() { return rare_non_inherited_usage_less_than_14_percent_data_.Access()->opacity_; }
    // order

    void SetOrderInternal(int v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->order_ = v;
    }

    int MutableOrderInternal() { return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->order_; }
    // origin-trial-test-property

    EOriginTrialTestProperty MutableOriginTrialTestPropertyInternal() { return static_cast<EOriginTrialTestProperty>(origin_trial_test_property_); }
    // OriginalDisplay

    EDisplay MutableOriginalDisplayInternal() { return static_cast<EDisplay>(original_display_); }
    // orphans

    void SetOrphansInternal(short v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->orphans_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->orphans_ = v;
    }

    short MutableOrphansInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->orphans_; }
    // outline-color
    const StyleColor& OutlineColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->outline_color_;
    }
    void SetOutlineColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->outline_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->outline_color_
                = std::move(v);
    }
    StyleColor& MutableOutlineColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->outline_color_;
    }
    // outline-offset

    void SetOutlineOffsetInternal(LayoutUnit&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_offset_ = std::move(v);
    }
    LayoutUnit& MutableOutlineOffsetInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_offset_;
    }
    // outline-style

    EBorderStyle MutableOutlineStyleInternal()
    {
        return static_cast<EBorderStyle>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_style_);
    }
    // OutlineStyleIsAuto

    bool MutableOutlineStyleIsAutoInternal()
    {
        return static_cast<bool>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->outline_style_is_auto_);
    }
    // outline-width
    const LayoutUnit& OutlineWidthInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_;
    }

    void SetOutlineWidthInternal(const LayoutUnit& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_width_ = v;
    }

    void SetOutlineWidthInternal(LayoutUnit&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_width_ = std::move(v);
    }
    LayoutUnit& MutableOutlineWidthInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->outline_width_;
    }
    // overflow-anchor

    EOverflowAnchor MutableOverflowAnchorInternal() { return static_cast<EOverflowAnchor>(overflow_anchor_); }
    // overflow-clip-margin

    void SetOverflowClipMarginInternal(absl::optional<StyleOverflowClipMargin>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->overflow_clip_margin_ = std::move(v);
    }
    absl::optional<StyleOverflowClipMargin>& MutableOverflowClipMarginInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->overflow_clip_margin_;
    }
    // overflow-wrap

    EOverflowWrap MutableOverflowWrapInternal() { return static_cast<EOverflowWrap>(rare_inherited_usage_less_than_64_percent_data_.Access()->overflow_wrap_); }
    // overflow-x

    EOverflow MutableOverflowXInternal() { return static_cast<EOverflow>(overflow_x_); }
    // overflow-y

    EOverflow MutableOverflowYInternal() { return static_cast<EOverflow>(overflow_y_); }
    // overscroll-behavior-x

    EOverscrollBehavior MutableOverscrollBehaviorXInternal() { return static_cast<EOverscrollBehavior>(overscroll_behavior_x_); }
    // overscroll-behavior-y

    EOverscrollBehavior MutableOverscrollBehaviorYInternal() { return static_cast<EOverscrollBehavior>(overscroll_behavior_y_); }
    // padding-bottom

    void SetPaddingBottomInternal(const Length& v)
    {
        if (!(surround_data_->padding_bottom_ == v))
            surround_data_.Access()->padding_bottom_ = v;
    }

    void SetPaddingBottomInternal(Length&& v)
    {
        if (!(surround_data_->padding_bottom_ == v))
            surround_data_.Access()->padding_bottom_ = std::move(v);
    }
    Length& MutablePaddingBottomInternal() { return surround_data_.Access()->padding_bottom_; }
    // padding-left

    void SetPaddingLeftInternal(const Length& v)
    {
        if (!(surround_data_->padding_left_ == v))
            surround_data_.Access()->padding_left_ = v;
    }

    void SetPaddingLeftInternal(Length&& v)
    {
        if (!(surround_data_->padding_left_ == v))
            surround_data_.Access()->padding_left_ = std::move(v);
    }
    Length& MutablePaddingLeftInternal() { return surround_data_.Access()->padding_left_; }
    // padding-right

    void SetPaddingRightInternal(const Length& v)
    {
        if (!(surround_data_->padding_right_ == v))
            surround_data_.Access()->padding_right_ = v;
    }

    void SetPaddingRightInternal(Length&& v)
    {
        if (!(surround_data_->padding_right_ == v))
            surround_data_.Access()->padding_right_ = std::move(v);
    }
    Length& MutablePaddingRightInternal() { return surround_data_.Access()->padding_right_; }
    // padding-top

    void SetPaddingTopInternal(const Length& v)
    {
        if (!(surround_data_->padding_top_ == v))
            surround_data_.Access()->padding_top_ = v;
    }

    void SetPaddingTopInternal(Length&& v)
    {
        if (!(surround_data_->padding_top_ == v))
            surround_data_.Access()->padding_top_ = std::move(v);
    }
    Length& MutablePaddingTopInternal() { return surround_data_.Access()->padding_top_; }
    // page

    void SetPageInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->page_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->page_
                = std::move(v);
    }
    AtomicString& MutablePageInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->page_;
    }
    // page-orientation

    PageOrientation MutablePageOrientationInternal()
    {
        return static_cast<PageOrientation>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                                ->page_orientation_);
    }
    // PageSize

    void SetPageSizeInternal(gfx::SizeF&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_size_ = std::move(v);
    }
    gfx::SizeF& MutablePageSizeInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_size_;
    }
    // PageSizeType

    PageSizeType MutablePageSizeTypeInternal()
    {
        return static_cast<PageSizeType>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_size_type_);
    }
    // page-transition-tag

    void SetPageTransitionTagInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_transition_tag_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_transition_tag_ = std::move(v);
    }
    AtomicString& MutablePageTransitionTagInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->page_transition_tag_;
    }
    // PaintImages
    const std::unique_ptr<PaintImages>& PaintImagesInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->paint_images_;
    }

    void SetPaintImagesInternal(std::unique_ptr<PaintImages>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->paint_images_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->paint_images_ = std::move(v);
    }
    std::unique_ptr<PaintImages>& MutablePaintImagesInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->paint_images_;
    }
    // paint-order

    EPaintOrder MutablePaintOrderInternal() { return static_cast<EPaintOrder>(svg_data_.Access()->paint_order_); }
    // perspective

    float MutablePerspectiveInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->perspective_;
    }
    // perspective-origin

    void SetPerspectiveOriginInternal(LengthPoint&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->perspective_origin_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->perspective_origin_
                = std::move(v);
    }
    LengthPoint& MutablePerspectiveOriginInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->perspective_origin_;
    }
    // pointer-events
    EPointerEvents PointerEventsInternal() const { return static_cast<EPointerEvents>(pointer_events_); }
    EPointerEvents MutablePointerEventsInternal() { return static_cast<EPointerEvents>(pointer_events_); }
    // pointer-events
    bool PointerEventsIsInheritedInternal() const { return static_cast<bool>(pointer_events_is_inherited_); }
    bool MutablePointerEventsIsInheritedInternal() { return static_cast<bool>(pointer_events_is_inherited_); }
    // position
    EPosition PositionInternal() const { return static_cast<EPosition>(position_); }
    EPosition MutablePositionInternal() { return static_cast<EPosition>(position_); }
    // position-fallback

    void SetPositionFallbackInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_fallback_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->position_fallback_ = std::move(v);
    }
    AtomicString& MutablePositionFallbackInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->position_fallback_;
    }
    // -webkit-print-color-adjust

    EPrintColorAdjust MutablePrintColorAdjustInternal() { return static_cast<EPrintColorAdjust>(print_color_adjust_); }
    // PseudoArgument

    void SetPseudoArgumentInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->pseudo_argument_ = std::move(v);
    }
    AtomicString& MutablePseudoArgumentInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->pseudo_argument_;
    }
    // PseudoBits
    unsigned PseudoBitsInternal() const { return static_cast<unsigned>(pseudo_bits_); }

    void SetPseudoBitsInternal(unsigned v) { pseudo_bits_ = static_cast<unsigned>(v); }

    unsigned MutablePseudoBitsInternal() { return static_cast<unsigned>(pseudo_bits_); }
    // r

    void SetRInternal(Length&& v)
    {
        if (!(svg_data_->geometry_data_->r_ == v))
            svg_data_.Access()->geometry_data_.Access()->r_ = std::move(v);
    }
    Length& MutableRInternal() { return svg_data_.Access()->geometry_data_.Access()->r_; }
    // RequiresAcceleratedCompositingForExternalReasons

    bool MutableRequiresAcceleratedCompositingForExternalReasonsInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->requires_accelerated_compositing_for_external_reasons_);
    }
    // resize
    EResize ResizeInternal() const
    {
        return static_cast<EResize>(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_);
    }
    EResize MutableResizeInternal()
    {
        return static_cast<EResize>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->resize_);
    }
    // image-orientation

    bool MutableRespectImageOrientationInternal()
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->respect_image_orientation_);
    }
    // right

    void SetRightInternal(Length&& v)
    {
        if (!(surround_data_->right_ == v))
            surround_data_.Access()->right_ = std::move(v);
    }
    Length& MutableRightInternal() { return surround_data_.Access()->right_; }
    // row-gap

    void SetRowGapInternal(absl::optional<Length>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->row_gap_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->row_gap_
                = std::move(v);
    }
    absl::optional<Length>& MutableRowGapInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->row_gap_;
    }
    // -webkit-rtl-ordering

    EOrder MutableRtlOrderingInternal() { return static_cast<EOrder>(rtl_ordering_); }
    // -webkit-rtl-ordering

    bool MutableRtlOrderingIsInheritedInternal() { return static_cast<bool>(rtl_ordering_is_inherited_); }
    // -webkit-ruby-position

    RubyPosition MutableRubyPositionInternal()
    {
        return static_cast<RubyPosition>(rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->ruby_position_);
    }
    // rx

    void SetRxInternal(Length&& v)
    {
        if (!(svg_data_->geometry_data_->rx_ == v))
            svg_data_.Access()->geometry_data_.Access()->rx_ = std::move(v);
    }
    Length& MutableRxInternal() { return svg_data_.Access()->geometry_data_.Access()->rx_; }
    // ry

    void SetRyInternal(Length&& v)
    {
        if (!(svg_data_->geometry_data_->ry_ == v))
            svg_data_.Access()->geometry_data_.Access()->ry_ = std::move(v);
    }
    Length& MutableRyInternal() { return svg_data_.Access()->geometry_data_.Access()->ry_; }
    // scroll-behavior

    mojom::blink::ScrollBehavior MutableScrollBehaviorInternal()
    {
        return static_cast<mojom::blink::ScrollBehavior>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                                             ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                                             ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                                             ->scroll_behavior_);
    }
    // scroll-customization

    scroll_customization::ScrollDirection MutableScrollCustomizationInternal()
    {
        return static_cast<scroll_customization::ScrollDirection>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_customization_);
    }
    // scroll-margin-bottom

    float MutableScrollMarginBottomInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_bottom_;
    }
    // scroll-margin-left

    float MutableScrollMarginLeftInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_left_;
    }
    // scroll-margin-right

    float MutableScrollMarginRightInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_right_;
    }
    // scroll-margin-top

    float MutableScrollMarginTopInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scroll_margin_top_;
    }
    // scroll-padding-bottom

    void SetScrollPaddingBottomInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_bottom_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_bottom_
                = std::move(v);
    }
    Length& MutableScrollPaddingBottomInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_padding_bottom_;
    }
    // scroll-padding-left

    void SetScrollPaddingLeftInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_left_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_left_
                = std::move(v);
    }
    Length& MutableScrollPaddingLeftInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_padding_left_;
    }
    // scroll-padding-right

    void SetScrollPaddingRightInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_right_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_right_
                = std::move(v);
    }
    Length& MutableScrollPaddingRightInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_padding_right_;
    }
    // scroll-padding-top

    void SetScrollPaddingTopInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_padding_top_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_padding_top_
                = std::move(v);
    }
    Length& MutableScrollPaddingTopInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_padding_top_;
    }
    // scroll-snap-align

    void SetScrollSnapAlignInternal(cc::ScrollSnapAlign&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_snap_align_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_snap_align_
                = std::move(v);
    }
    cc::ScrollSnapAlign& MutableScrollSnapAlignInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_snap_align_;
    }
    // scroll-snap-stop

    EScrollSnapStop MutableScrollSnapStopInternal() { return static_cast<EScrollSnapStop>(scroll_snap_stop_); }
    // scroll-snap-type

    void SetScrollSnapTypeInternal(cc::ScrollSnapType&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->scroll_snap_type_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->scroll_snap_type_
                = std::move(v);
    }
    cc::ScrollSnapType& MutableScrollSnapTypeInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->scroll_snap_type_;
    }
    // scroll-timeline-axis

    TimelineAxis MutableScrollTimelineAxisInternal()
    {
        return static_cast<TimelineAxis>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                             ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                             ->timeline_data_.Access()
                                             ->scroll_timeline_axis_);
    }
    // scroll-timeline-name

    void SetScrollTimelineNameInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->scroll_timeline_name_
                = std::move(v);
    }
    AtomicString& MutableScrollTimelineNameInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->timeline_data_.Access()
            ->scroll_timeline_name_;
    }
    // scrollbar-gutter

    unsigned MutableScrollbarGutterInternal() { return static_cast<unsigned>(scrollbar_gutter_); }
    // scrollbar-width

    EScrollbarWidth MutableScrollbarWidthInternal()
    {
        return static_cast<EScrollbarWidth>(
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->scrollbar_width_);
    }
    // shape-image-threshold

    void SetShapeImageThresholdInternal(float v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->shape_image_threshold_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->shape_image_threshold_
                = v;
    }

    float MutableShapeImageThresholdInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->shape_image_threshold_;
    }
    // shape-margin

    void SetShapeMarginInternal(Length&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->shape_margin_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->shape_margin_
                = std::move(v);
    }
    Length& MutableShapeMarginInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->shape_margin_;
    }
    // shape-outside
    const Persistent<ShapeValue>& ShapeOutsideInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->shape_outside_;
    }

    void SetShapeOutsideInternal(Persistent<ShapeValue>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->shape_outside_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->shape_outside_
                = std::move(v);
    }
    Persistent<ShapeValue>& MutableShapeOutsideInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->shape_outside_;
    }
    // shape-rendering

    EShapeRendering MutableShapeRenderingInternal() { return static_cast<EShapeRendering>(svg_data_.Access()->shape_rendering_); }
    // ShouldIgnoreOverflowPropertyForInlineBlockBaseline

    // SkipsContents

    // speak

    ESpeak MutableSpeakInternal() { return static_cast<ESpeak>(rare_inherited_usage_less_than_64_percent_data_.Access()->speak_); }
    // stop-color
    const StyleColor& StopColorInternal() const { return svg_data_->stop_data_->stop_color_; }
    void SetStopColorInternal(StyleColor&& v)
    {
        if (!(svg_data_->stop_data_->stop_color_ == v))
            svg_data_.Access()->stop_data_.Access()->stop_color_ = std::move(v);
    }
    StyleColor& MutableStopColorInternal() { return svg_data_.Access()->stop_data_.Access()->stop_color_; }
    // stop-opacity

    float MutableStopOpacityInternal() { return svg_data_.Access()->stop_data_.Access()->stop_opacity_; }
    // stroke-dashoffset

    void SetStrokeDashOffsetInternal(Length&& v)
    {
        if (!(svg_data_->stroke_data_->stroke_dash_offset_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_dash_offset_ = std::move(v);
    }
    Length& MutableStrokeDashOffsetInternal() { return svg_data_.Access()->stroke_data_.Access()->stroke_dash_offset_; }
    // stroke-miterlimit

    float MutableStrokeMiterLimitInternal() { return svg_data_.Access()->stroke_data_.Access()->stroke_miter_limit_; }
    // stroke-opacity

    float MutableStrokeOpacityInternal() { return svg_data_.Access()->stroke_data_.Access()->stroke_opacity_; }
    // stroke

    void SetStrokePaintInternal(SVGPaint&& v)
    {
        if (!(svg_data_->stroke_data_->stroke_paint_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_paint_ = std::move(v);
    }
    SVGPaint& MutableStrokePaintInternal() { return svg_data_.Access()->stroke_data_.Access()->stroke_paint_; }
    // stroke-width

    void SetStrokeWidthInternal(UnzoomedLength&& v)
    {
        if (!(svg_data_->stroke_data_->stroke_width_ == v))
            svg_data_.Access()->stroke_data_.Access()->stroke_width_ = std::move(v);
    }
    UnzoomedLength& MutableStrokeWidthInternal() { return svg_data_.Access()->stroke_data_.Access()->stroke_width_; }
    // StyleType
    unsigned StyleTypeInternal() const { return static_cast<unsigned>(style_type_); }

    void SetStyleTypeInternal(unsigned v) { style_type_ = static_cast<unsigned>(v); }

    unsigned MutableStyleTypeInternal() { return static_cast<unsigned>(style_type_); }
    // SubtreeIsSticky

    bool MutableSubtreeIsStickyInternal()
    {
        return static_cast<bool>(rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->subtree_is_sticky_);
    }
    // SubtreeWillChangeContents

    bool MutableSubtreeWillChangeContentsInternal()
    {
        return static_cast<bool>(
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->subtree_will_change_contents_);
    }
    // tab-size

    void SetTabSizeInternal(const TabSize& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->tab_size_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->tab_size_ = v;
    }

    void SetTabSizeInternal(TabSize&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->tab_size_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->tab_size_ = std::move(v);
    }
    TabSize& MutableTabSizeInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->tab_size_; }
    // table-layout

    ETableLayout MutableTableLayoutInternal() { return static_cast<ETableLayout>(table_layout_); }
    // -webkit-tap-highlight-color

    void SetTapHighlightColorInternal(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->tap_highlight_color_ = std::move(v);
    }
    StyleColor& MutableTapHighlightColorInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->tap_highlight_color_;
    }
    // text-align

    ETextAlign MutableTextAlignInternal() { return static_cast<ETextAlign>(text_align_); }
    // text-align-last

    ETextAlignLast MutableTextAlignLastInternal() { return static_cast<ETextAlignLast>(rare_inherited_usage_less_than_64_percent_data_.Access()->text_align_last_); }
    // text-anchor

    ETextAnchor MutableTextAnchorInternal() { return static_cast<ETextAnchor>(svg_data_.Access()->text_anchor_); }
    // TextAutosizingMultiplier

    void SetTextAutosizingMultiplierInternal(float v)
    {
        if (!(inherited_data_->text_autosizing_multiplier_ == v))
            inherited_data_.Access()->text_autosizing_multiplier_ = v;
    }

    float MutableTextAutosizingMultiplierInternal() { return inherited_data_.Access()->text_autosizing_multiplier_; }
    // text-combine-upright

    ETextCombine MutableTextCombineInternal() { return static_cast<ETextCombine>(rare_inherited_usage_less_than_64_percent_data_.Access()->text_combine_); }
    // text-decoration-color
    const StyleColor& TextDecorationColorInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
            ->text_decoration_color_;
    }
    void SetTextDecorationColorInternal(StyleColor&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    ->text_decoration_color_
                == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                ->text_decoration_color_
                = std::move(v);
    }
    StyleColor& MutableTextDecorationColorInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
            ->text_decoration_color_;
    }
    // text-decoration-line

    // text-decoration-skip-ink

    ETextDecorationSkipInk MutableTextDecorationSkipInkInternal()
    {
        return static_cast<ETextDecorationSkipInk>(rare_inherited_usage_less_than_64_percent_data_.Access()->text_decoration_skip_ink_);
    }
    // text-decoration-style

    ETextDecorationStyle MutableTextDecorationStyleInternal()
    {
        return static_cast<ETextDecorationStyle>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                                     ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                                     ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                                     ->text_decoration_style_);
    }
    // text-decoration-thickness

    void SetTextDecorationThicknessInternal(TextDecorationThickness&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_decoration_thickness_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_decoration_thickness_ = std::move(v);
    }
    TextDecorationThickness& MutableTextDecorationThicknessInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->text_decoration_thickness_; }
    // text-emphasis-color
    const StyleColor& TextEmphasisColorInternal() const { return rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_; }
    void SetTextEmphasisColorInternal(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_emphasis_color_ = std::move(v);
    }
    StyleColor& MutableTextEmphasisColorInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->text_emphasis_color_; }
    // TextEmphasisCustomMark

    void SetTextEmphasisCustomMarkInternal(AtomicString&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_custom_mark_ = std::move(v);
    }
    AtomicString& MutableTextEmphasisCustomMarkInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_custom_mark_;
    }
    // TextEmphasisFill

    TextEmphasisFill MutableTextEmphasisFillInternal()
    {
        return static_cast<TextEmphasisFill>(
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_fill_);
    }
    // TextEmphasisMark
    TextEmphasisMark TextEmphasisMarkInternal() const
    {
        return static_cast<TextEmphasisMark>(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_);
    }

    void SetTextEmphasisMarkInternal(TextEmphasisMark v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_ == static_cast<unsigned>(v)))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_mark_ = static_cast<unsigned>(v);
    }

    TextEmphasisMark MutableTextEmphasisMarkInternal()
    {
        return static_cast<TextEmphasisMark>(
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_64_percent_sub_data_.Access()->text_emphasis_mark_);
    }
    // text-emphasis-position

    TextEmphasisPosition MutableTextEmphasisPositionInternal()
    {
        return static_cast<TextEmphasisPosition>(rare_inherited_usage_less_than_64_percent_data_.Access()->text_emphasis_position_);
    }
    // -webkit-text-fill-color
    const StyleColor& TextFillColorInternal() const { return rare_inherited_usage_less_than_64_percent_data_->text_fill_color_; }
    void SetTextFillColorInternal(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_fill_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_fill_color_ = std::move(v);
    }
    StyleColor& MutableTextFillColorInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->text_fill_color_; }
    // text-indent

    void SetTextIndentInternal(Length&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_indent_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_indent_ = std::move(v);
    }
    Length& MutableTextIndentInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->text_indent_; }
    // text-orientation

    ETextOrientation MutableTextOrientationInternal() { return static_cast<ETextOrientation>(rare_inherited_usage_less_than_64_percent_data_.Access()->text_orientation_); }
    // text-overflow

    ETextOverflow MutableTextOverflowInternal() { return static_cast<ETextOverflow>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->text_overflow_); }
    // -webkit-text-security

    ETextSecurity MutableTextSecurityInternal() { return static_cast<ETextSecurity>(rare_inherited_usage_less_than_64_percent_data_.Access()->text_security_); }
    // text-size-adjust

    void SetTextSizeAdjustInternal(TextSizeAdjust&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_size_adjust_ = std::move(v);
    }
    TextSizeAdjust& MutableTextSizeAdjustInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->text_size_adjust_; }
    // -webkit-text-stroke-color
    const StyleColor& TextStrokeColorInternal() const { return rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_; }
    void SetTextStrokeColorInternal(StyleColor&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->text_stroke_color_ = std::move(v);
    }
    StyleColor& MutableTextStrokeColorInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->text_stroke_color_; }
    // -webkit-text-stroke-width

    float MutableTextStrokeWidthInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->text_stroke_width_; }
    // text-transform

    ETextTransform MutableTextTransformInternal() { return static_cast<ETextTransform>(text_transform_); }
    // text-transform

    bool MutableTextTransformIsInheritedInternal() { return static_cast<bool>(text_transform_is_inherited_); }
    // text-underline-offset

    void SetTextUnderlineOffsetInternal(Length&& v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->text_underline_offset_ = std::move(v);
    }
    Length& MutableTextUnderlineOffsetInternal()
    {
        return rare_inherited_usage_less_than_64_percent_data_.Access()->rare_inherited_usage_less_than_100_percent_data_.Access()->text_underline_offset_;
    }
    // text-underline-position

    unsigned MutableTextUnderlinePositionInternal() { return static_cast<unsigned>(rare_inherited_usage_less_than_64_percent_data_.Access()->text_underline_position_); }
    // toggle-visibility

    void SetToggleVisibilityInternal(AtomicString&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_visibility_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->toggle_visibility_ = std::move(v);
    }
    AtomicString& MutableToggleVisibilityInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->toggle_visibility_;
    }
    // top

    void SetTopInternal(Length&& v)
    {
        if (!(surround_data_->top_ == v))
            surround_data_.Access()->top_ = std::move(v);
    }
    Length& MutableTopInternal() { return surround_data_.Access()->top_; }
    // touch-action

    TouchAction MutableTouchActionInternal()
    {
        return static_cast<TouchAction>(rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_22_percent_data_.Access()->touch_action_);
    }
    // transform

    void SetTransformInternal(TransformOperations&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_ = std::move(v);
    }
    TransformOperations& MutableTransformInternal() { return rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_; }
    // transform-box

    ETransformBox MutableTransformBoxInternal() { return static_cast<ETransformBox>(transform_box_); }
    // transform-origin

    void SetTransformOriginInternal(TransformOrigin&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_origin_ = std::move(v);
    }
    TransformOrigin& MutableTransformOriginInternal() { return rare_non_inherited_usage_less_than_14_percent_data_.Access()->transform_origin_; }
    // transform-style

    ETransformStyle3D MutableTransformStyle3DInternal()
    {
        return static_cast<ETransformStyle3D>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                                  ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                                  ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                                  ->transform_style_3d_);
    }
    // Transitions
    const std::unique_ptr<CSSTransitionData>& TransitionsInternal() const
    {
        return rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_;
    }

    void SetTransitionsInternal(std::unique_ptr<CSSTransitionData>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->transitions_ = std::move(v);
    }
    std::unique_ptr<CSSTransitionData>& MutableTransitionsInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()->transitions_;
    }
    // unicode-bidi

    UnicodeBidi MutableUnicodeBidiInternal() { return static_cast<UnicodeBidi>(unicode_bidi_); }
    // -webkit-user-drag

    EUserDrag MutableUserDragInternal()
    {
        return static_cast<EUserDrag>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                          ->rare_non_inherited_usage_less_than_22_percent_data_.Access()
                                          ->rare_non_inherited_usage_less_than_100_percent_data_.Access()
                                          ->user_drag_);
    }
    // -webkit-user-modify
    EUserModify UserModifyInternal() const { return static_cast<EUserModify>(rare_inherited_usage_less_than_64_percent_data_->user_modify_); }
    EUserModify MutableUserModifyInternal() { return static_cast<EUserModify>(rare_inherited_usage_less_than_64_percent_data_.Access()->user_modify_); }
    // user-select
    EUserSelect UserSelectInternal() const { return static_cast<EUserSelect>(rare_inherited_usage_less_than_64_percent_data_->user_select_); }
    EUserSelect MutableUserSelectInternal() { return static_cast<EUserSelect>(rare_inherited_usage_less_than_64_percent_data_.Access()->user_select_); }
    // vector-effect

    EVectorEffect MutableVectorEffectInternal() { return static_cast<EVectorEffect>(svg_data_.Access()->vector_effect_); }
    // VerticalAlign
    unsigned VerticalAlignInternal() const { return static_cast<unsigned>(vertical_align_); }

    void SetVerticalAlignInternal(unsigned v) { vertical_align_ = static_cast<unsigned>(v); }

    unsigned MutableVerticalAlignInternal() { return static_cast<unsigned>(vertical_align_); }
    // VerticalAlignLength

    void SetVerticalAlignLengthInternal(const Length& v)
    {
        if (!(box_data_->vertical_align_length_ == v))
            box_data_.Access()->vertical_align_length_ = v;
    }

    void SetVerticalAlignLengthInternal(Length&& v)
    {
        if (!(box_data_->vertical_align_length_ == v))
            box_data_.Access()->vertical_align_length_ = std::move(v);
    }
    Length& MutableVerticalAlignLengthInternal() { return box_data_.Access()->vertical_align_length_; }
    // -webkit-border-vertical-spacing

    short MutableVerticalBorderSpacingInternal() { return inherited_data_.Access()->vertical_border_spacing_; }
    // view-timeline-axis

    void SetViewTimelineAxisInternal(Vector<TimelineAxis>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->view_timeline_axis_
                = std::move(v);
    }
    Vector<TimelineAxis>& MutableViewTimelineAxisInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->timeline_data_.Access()
            ->view_timeline_axis_;
    }
    // view-timeline-inset

    void SetViewTimelineInsetInternal(Vector<TimelineInset>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->view_timeline_inset_
                = std::move(v);
    }
    Vector<TimelineInset>& MutableViewTimelineInsetInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->timeline_data_.Access()
            ->view_timeline_inset_;
    }
    // view-timeline-name

    void SetViewTimelineNameInternal(Vector<AtomicString>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->timeline_data_.Access()
                ->view_timeline_name_
                = std::move(v);
    }
    Vector<AtomicString>& MutableViewTimelineNameInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->timeline_data_.Access()
            ->view_timeline_name_;
    }
    // ViewportUnitFlags

    unsigned MutableViewportUnitFlagsInternal() { return static_cast<unsigned>(viewport_unit_flags_); }
    // visibility

    EVisibility MutableVisibilityInternal() { return static_cast<EVisibility>(visibility_); }
    // visibility

    bool MutableVisibilityIsInheritedInternal() { return static_cast<bool>(visibility_is_inherited_); }
    // white-space

    // widows

    void SetWidowsInternal(short v)
    {
        if (!(rare_inherited_usage_less_than_64_percent_data_->widows_ == v))
            rare_inherited_usage_less_than_64_percent_data_.Access()->widows_ = v;
    }

    short MutableWidowsInternal() { return rare_inherited_usage_less_than_64_percent_data_.Access()->widows_; }
    // width

    void SetWidthInternal(Length&& v)
    {
        if (!(box_data_->width_ == v))
            box_data_.Access()->width_ = std::move(v);
    }
    Length& MutableWidthInternal() { return box_data_.Access()->width_; }
    // WillChangeContents

    bool MutableWillChangeContentsInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->will_change_data_.Access()
                                     ->will_change_contents_);
    }
    // WillChangeProperties

    void SetWillChangePropertiesInternal(Vector<CSSPropertyID>&& v)
    {
        if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_properties_ == v))
            rare_non_inherited_usage_less_than_14_percent_data_.Access()
                ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                ->will_change_data_.Access()
                ->will_change_properties_
                = std::move(v);
    }
    Vector<CSSPropertyID>& MutableWillChangePropertiesInternal()
    {
        return rare_non_inherited_usage_less_than_14_percent_data_.Access()
            ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
            ->will_change_data_.Access()
            ->will_change_properties_;
    }
    // WillChangeScrollPosition

    bool MutableWillChangeScrollPositionInternal()
    {
        return static_cast<bool>(rare_non_inherited_usage_less_than_14_percent_data_.Access()
                                     ->rare_non_inherited_usage_less_than_14_percent_sub_data_.Access()
                                     ->will_change_data_.Access()
                                     ->will_change_scroll_position_);
    }
    // word-break

    EWordBreak MutableWordBreakInternal() { return static_cast<EWordBreak>(rare_inherited_usage_less_than_64_percent_data_.Access()->word_break_); }
    // writing-mode

    WritingMode MutableWritingModeInternal() { return static_cast<WritingMode>(writing_mode_); }
    // x

    void SetXInternal(Length&& v)
    {
        if (!(svg_data_->geometry_data_->x_ == v))
            svg_data_.Access()->geometry_data_.Access()->x_ = std::move(v);
    }
    Length& MutableXInternal() { return svg_data_.Access()->geometry_data_.Access()->x_; }
    // y

    void SetYInternal(Length&& v)
    {
        if (!(svg_data_->geometry_data_->y_ == v))
            svg_data_.Access()->geometry_data_.Access()->y_ = std::move(v);
    }
    Length& MutableYInternal() { return svg_data_.Access()->geometry_data_.Access()->y_; }
    // z-index

    void SetZIndexInternal(int v)
    {
        if (!(box_data_->z_index_ == v))
            box_data_.Access()->z_index_ = v;
    }

    int MutableZIndexInternal() { return box_data_.Access()->z_index_; }
    // zoom

    float MutableZoomInternal() { return visual_data_.Access()->zoom_; }

    ~ComputedStyleBase() = default;

private:
    // Storage.
    DataRef<StyleInheritedData> inherited_data_;
    DataRef<StyleRareInheritedUsageLessThan64PercentData> rare_inherited_usage_less_than_64_percent_data_;
    DataRef<StyleVisualData> visual_data_;
    DataRef<StyleRareNonInheritedUsageLessThan14PercentData> rare_non_inherited_usage_less_than_14_percent_data_;
    DataRef<StyleSVGData> svg_data_;
    DataRef<StyleBoxData> box_data_;
    DataRef<StyleBackgroundData> background_data_;
    DataRef<StyleSurroundData> surround_data_;

    scoped_refptr<StyleBaseData> base_data_;
    unsigned pseudo_bits_ : 12; // unsigned
    unsigned white_space_ : 7; // EWhiteSpace
    unsigned cursor_ : 6; // ECursor
    unsigned style_type_ : 6; // unsigned
    unsigned affected_by_active_ : 1; // bool
    unsigned display_ : 5; // EDisplay
    unsigned original_display_ : 5; // EDisplay
    unsigned break_after_ : 4; // EBreakBetween
    unsigned break_before_ : 4; // EBreakBetween
    unsigned pointer_events_ : 4; // EPointerEvents
    unsigned scrollbar_gutter_ : 4; // unsigned
    unsigned text_align_ : 4; // ETextAlign
    unsigned break_inside_ : 2; // EBreakInside
    unsigned vertical_align_ : 4; // unsigned
    unsigned clear_ : 3; // EClear
    unsigned floating_ : 3; // EFloat
    unsigned overflow_x_ : 3; // EOverflow
    unsigned overflow_y_ : 3; // EOverflow
    unsigned position_ : 3; // EPosition
    unsigned text_transform_ : 3; // ETextTransform
    unsigned unicode_bidi_ : 3; // UnicodeBidi
    unsigned content_visibility_ : 2; // EContentVisibility
    unsigned inside_link_ : 2; // EInsideLink
    unsigned overflow_anchor_ : 2; // EOverflowAnchor
    unsigned affected_by_drag_ : 1; // bool
    unsigned overscroll_behavior_x_ : 2; // EOverscrollBehavior
    unsigned overscroll_behavior_y_ : 2; // EOverscrollBehavior
    unsigned viewport_unit_flags_ : 2; // unsigned
    unsigned visibility_ : 2; // EVisibility
    unsigned writing_mode_ : 2; // WritingMode
    unsigned affected_by_focus_within_ : 1; // bool
    unsigned affected_by_hover_ : 1; // bool
    unsigned border_collapse_ : 1; // EBorderCollapse
    unsigned border_collapse_is_inherited_ : 1; // bool
    unsigned box_direction_ : 1; // EBoxDirection
    unsigned box_direction_is_inherited_ : 1; // bool
    unsigned caption_side_ : 1; // ECaptionSide
    unsigned caption_side_is_inherited_ : 1; // bool
    mutable unsigned child_has_explicit_inheritance_ : 1; // bool
    unsigned color_is_inherited_ : 1; // bool
    unsigned color_scheme_forced_ : 1; // bool
    unsigned custom_style_callback_depends_on_font_ : 1; // bool
    unsigned dark_color_scheme_ : 1; // bool
    unsigned direction_ : 1; // TextDirection
    unsigned empty_cells_ : 1; // EEmptyCells
    unsigned empty_cells_is_inherited_ : 1; // bool
    unsigned has_attr_content_ : 1; // bool
    unsigned has_author_background_ : 1; // bool
    unsigned has_author_border_ : 1; // bool
    unsigned has_author_border_radius_ : 1; // bool
    unsigned has_author_highlight_colors_ : 1; // bool
    unsigned has_container_relative_units_ : 1; // bool
    unsigned has_em_units_ : 1; // bool
    unsigned has_explicit_inheritance_ : 1; // bool
    unsigned has_glyph_relative_units_ : 1; // bool
    unsigned has_rem_units_ : 1; // bool
    unsigned has_simple_underline_ : 1; // bool
    unsigned has_variable_declaration_ : 1; // bool
    unsigned has_variable_reference_ : 1; // bool
    unsigned has_variable_reference_from_non_inherited_property_ : 1; // bool
    unsigned inside_fragmentation_context_with_nondeterministic_engine_ : 1; // bool
    unsigned is_ensured_in_display_none_ : 1; // bool
    unsigned is_ensured_outside_flat_tree_ : 1; // bool
    unsigned is_flex_or_grid_item_ : 1; // bool
    unsigned is_flex_or_grid_or_custom_item_ : 1; // bool
    unsigned is_in_blockifying_display_ : 1; // bool
    unsigned is_inert_ : 1; // bool
    unsigned is_inert_is_inherited_ : 1; // bool
    unsigned is_inside_list_element_ : 1; // bool
    unsigned is_link_ : 1; // bool
    unsigned list_style_position_ : 1; // EListStylePosition
    unsigned list_style_position_is_inherited_ : 1; // bool
    unsigned origin_trial_test_property_ : 1; // EOriginTrialTestProperty
    unsigned pointer_events_is_inherited_ : 1; // bool
    unsigned print_color_adjust_ : 1; // EPrintColorAdjust
    unsigned rtl_ordering_ : 1; // EOrder
    unsigned rtl_ordering_is_inherited_ : 1; // bool
    unsigned scroll_snap_stop_ : 1; // EScrollSnapStop
    unsigned should_ignore_overflow_property_for_inline_block_baseline_ : 1; // bool
    unsigned skips_contents_ : 1; // bool
    unsigned table_layout_ : 1; // ETableLayout
    unsigned text_transform_is_inherited_ : 1; // bool
    unsigned transform_box_ : 1; // ETransformBox
    unsigned visibility_is_inherited_ : 1; // bool
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_STYLE_COMPUTED_STYLE_BASE_H_
