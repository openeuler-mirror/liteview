// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   core/style/templates/computed_style_base.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/css/computed_style_field_aliases.json5
//   ../../third_party/blink/renderer/core/css/css_group_config.json5
//   ../../third_party/blink/renderer/core/css/css_properties.json5
//   ../../third_party/blink/renderer/core/css/css_properties_ranking.json5
//   ../../third_party/blink/renderer/core/css/css_value_keywords.json5
//   ../../third_party/blink/renderer/core/style/computed_style_diff_functions.json5
//   ../../third_party/blink/renderer/core/style/computed_style_extra_fields.json5
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "third_party/blink/renderer/core/style/computed_style.h"
#include "third_party/blink/renderer/core/style/computed_style_base.h"
#include "third_party/blink/renderer/platform/wtf/size_assertions.h"

namespace blink {

struct SameSizeVerifierForComputedStyleBase {
    void* data_refs[8];
    scoped_refptr<StyleBaseData> base_data_;
    unsigned bit_fields[5];
};

// If this fails, the packing algorithm in make_computed_style_base.py has
// failed to produce the optimal packed size. To fix, update the algorithm to
// ensure that the buckets are placed so that each takes up at most 1 word.
ASSERT_SIZE(ComputedStyleBase, SameSizeVerifierForComputedStyleBase);

// Constructor and destructor are protected so that only the parent class ComputedStyle
// can instantiate this class.
ComputedStyleBase::ComputedStyleBase()
    : base_data_(nullptr)
    , pseudo_bits_(static_cast<unsigned>(kPseudoIdNone))
    , white_space_(static_cast<unsigned>(EWhiteSpace::kNormal))
    , cursor_(static_cast<unsigned>(ECursor::kAuto))
    , style_type_(static_cast<unsigned>(PseudoId::kPseudoIdNone))
    , affected_by_active_(static_cast<unsigned>(false))
    , display_(static_cast<unsigned>(EDisplay::kInline))
    , original_display_(static_cast<unsigned>(EDisplay::kInline))
    , break_after_(static_cast<unsigned>(EBreakBetween::kAuto))
    , break_before_(static_cast<unsigned>(EBreakBetween::kAuto))
    , pointer_events_(static_cast<unsigned>(EPointerEvents::kAuto))
    , scrollbar_gutter_(static_cast<unsigned>(kScrollbarGutterAuto))
    , text_align_(static_cast<unsigned>(ETextAlign::kStart))
    , break_inside_(static_cast<unsigned>(EBreakInside::kAuto))
    , vertical_align_(static_cast<unsigned>(static_cast<unsigned>(EVerticalAlign::kBaseline)))
    , clear_(static_cast<unsigned>(EClear::kNone))
    , floating_(static_cast<unsigned>(EFloat::kNone))
    , overflow_x_(static_cast<unsigned>(EOverflow::kVisible))
    , overflow_y_(static_cast<unsigned>(EOverflow::kVisible))
    , position_(static_cast<unsigned>(EPosition::kStatic))
    , text_transform_(static_cast<unsigned>(ETextTransform::kNone))
    , unicode_bidi_(static_cast<unsigned>(UnicodeBidi::kNormal))
    , content_visibility_(static_cast<unsigned>(EContentVisibility::kVisible))
    , inside_link_(static_cast<unsigned>(EInsideLink::kNotInsideLink))
    , overflow_anchor_(static_cast<unsigned>(EOverflowAnchor::kAuto))
    , affected_by_drag_(static_cast<unsigned>(false))
    , overscroll_behavior_x_(static_cast<unsigned>(EOverscrollBehavior::kAuto))
    , overscroll_behavior_y_(static_cast<unsigned>(EOverscrollBehavior::kAuto))
    , viewport_unit_flags_(static_cast<unsigned>(0))
    , visibility_(static_cast<unsigned>(EVisibility::kVisible))
    , writing_mode_(static_cast<unsigned>(WritingMode::kHorizontalTb))
    , affected_by_focus_within_(static_cast<unsigned>(false))
    , affected_by_hover_(static_cast<unsigned>(false))
    , border_collapse_(static_cast<unsigned>(EBorderCollapse::kSeparate))
    , border_collapse_is_inherited_(static_cast<unsigned>(true))
    , box_direction_(static_cast<unsigned>(EBoxDirection::kNormal))
    , box_direction_is_inherited_(static_cast<unsigned>(true))
    , caption_side_(static_cast<unsigned>(ECaptionSide::kTop))
    , caption_side_is_inherited_(static_cast<unsigned>(true))
    , child_has_explicit_inheritance_(static_cast<unsigned>(false))
    , color_is_inherited_(static_cast<unsigned>(true))
    , color_scheme_forced_(static_cast<unsigned>(false))
    , custom_style_callback_depends_on_font_(static_cast<unsigned>(false))
    , dark_color_scheme_(static_cast<unsigned>(false))
    , direction_(static_cast<unsigned>(TextDirection::kLtr))
    , empty_cells_(static_cast<unsigned>(EEmptyCells::kShow))
    , empty_cells_is_inherited_(static_cast<unsigned>(true))
    , has_attr_content_(static_cast<unsigned>(false))
    , has_author_background_(static_cast<unsigned>(false))
    , has_author_border_(static_cast<unsigned>(false))
    , has_author_border_radius_(static_cast<unsigned>(false))
    , has_author_highlight_colors_(static_cast<unsigned>(false))
    , has_container_relative_units_(static_cast<unsigned>(false))
    , has_em_units_(static_cast<unsigned>(false))
    , has_explicit_inheritance_(static_cast<unsigned>(false))
    , has_glyph_relative_units_(static_cast<unsigned>(false))
    , has_rem_units_(static_cast<unsigned>(false))
    , has_simple_underline_(static_cast<unsigned>(false))
    , has_variable_declaration_(static_cast<unsigned>(false))
    , has_variable_reference_(static_cast<unsigned>(false))
    , has_variable_reference_from_non_inherited_property_(static_cast<unsigned>(false))
    , inside_fragmentation_context_with_nondeterministic_engine_(static_cast<unsigned>(false))
    , is_ensured_in_display_none_(static_cast<unsigned>(false))
    , is_ensured_outside_flat_tree_(static_cast<unsigned>(false))
    , is_flex_or_grid_item_(static_cast<unsigned>(false))
    , is_flex_or_grid_or_custom_item_(static_cast<unsigned>(false))
    , is_in_blockifying_display_(static_cast<unsigned>(false))
    , is_inert_(static_cast<unsigned>(false))
    , is_inert_is_inherited_(static_cast<unsigned>(true))
    , is_inside_list_element_(static_cast<unsigned>(false))
    , is_link_(static_cast<unsigned>(false))
    , list_style_position_(static_cast<unsigned>(EListStylePosition::kOutside))
    , list_style_position_is_inherited_(static_cast<unsigned>(true))
    , origin_trial_test_property_(static_cast<unsigned>(EOriginTrialTestProperty::kNormal))
    , pointer_events_is_inherited_(static_cast<unsigned>(true))
    , print_color_adjust_(static_cast<unsigned>(EPrintColorAdjust::kEconomy))
    , rtl_ordering_(static_cast<unsigned>(EOrder::kLogical))
    , rtl_ordering_is_inherited_(static_cast<unsigned>(true))
    , scroll_snap_stop_(static_cast<unsigned>(EScrollSnapStop::kNormal))
    , should_ignore_overflow_property_for_inline_block_baseline_(static_cast<unsigned>(false))
    , skips_contents_(static_cast<unsigned>(false))
    , table_layout_(static_cast<unsigned>(ETableLayout::kAuto))
    , text_transform_is_inherited_(static_cast<unsigned>(true))
    , transform_box_(static_cast<unsigned>(ETransformBox::kViewBox))
    , visibility_is_inherited_(static_cast<unsigned>(true))
{
    inherited_data_.Init();
    rare_inherited_usage_less_than_64_percent_data_.Init();
    visual_data_.Init();
    rare_non_inherited_usage_less_than_14_percent_data_.Init();
    svg_data_.Init();
    box_data_.Init();
    background_data_.Init();
    surround_data_.Init();
}

void ComputedStyleBase::InheritFrom(const ComputedStyleBase& other, IsAtShadowBoundary isAtShadowBoundary)
{
    inherited_data_ = other.inherited_data_;
    rare_inherited_usage_less_than_64_percent_data_ = other.rare_inherited_usage_less_than_64_percent_data_;
    if (svg_data_.Get() != other.svg_data_.Get()) {
        svg_data_.Access()->fill_data_ = other.svg_data_->fill_data_;
        svg_data_.Access()->stroke_data_ = other.svg_data_->stroke_data_;
        svg_data_.Access()->inherited_resources_data_ = other.svg_data_->inherited_resources_data_;
        svg_data_.Access()->css_dominant_baseline_ = other.svg_data_->css_dominant_baseline_;
        svg_data_.Access()->dominant_baseline_ = other.svg_data_->dominant_baseline_;
        svg_data_.Access()->paint_order_ = other.svg_data_->paint_order_;
        svg_data_.Access()->color_interpolation_ = other.svg_data_->color_interpolation_;
        svg_data_.Access()->color_interpolation_filters_ = other.svg_data_->color_interpolation_filters_;
        svg_data_.Access()->color_rendering_ = other.svg_data_->color_rendering_;
        svg_data_.Access()->shape_rendering_ = other.svg_data_->shape_rendering_;
        svg_data_.Access()->text_anchor_ = other.svg_data_->text_anchor_;
        svg_data_.Access()->clip_rule_ = other.svg_data_->clip_rule_;
        svg_data_.Access()->fill_rule_ = other.svg_data_->fill_rule_;
    }
    white_space_ = other.white_space_;
    cursor_ = other.cursor_;
    pointer_events_ = other.pointer_events_;
    text_align_ = other.text_align_;
    text_transform_ = other.text_transform_;
    inside_link_ = other.inside_link_;
    visibility_ = other.visibility_;
    writing_mode_ = other.writing_mode_;
    border_collapse_ = other.border_collapse_;
    box_direction_ = other.box_direction_;
    caption_side_ = other.caption_side_;
    color_scheme_forced_ = other.color_scheme_forced_;
    dark_color_scheme_ = other.dark_color_scheme_;
    direction_ = other.direction_;
    empty_cells_ = other.empty_cells_;
    has_simple_underline_ = other.has_simple_underline_;
    inside_fragmentation_context_with_nondeterministic_engine_ = other.inside_fragmentation_context_with_nondeterministic_engine_;
    is_ensured_outside_flat_tree_ = other.is_ensured_outside_flat_tree_;
    is_inert_ = other.is_inert_;
    is_inside_list_element_ = other.is_inside_list_element_;
    list_style_position_ = other.list_style_position_;
    print_color_adjust_ = other.print_color_adjust_;
    rtl_ordering_ = other.rtl_ordering_;
}

void ComputedStyleBase::CopyNonInheritedFromCached(const ComputedStyleBase& other)
{
    visual_data_ = other.visual_data_;
    rare_non_inherited_usage_less_than_14_percent_data_ = other.rare_non_inherited_usage_less_than_14_percent_data_;
    if (svg_data_.Get() != other.svg_data_.Get()) {
        svg_data_.Access()->misc_data_ = other.svg_data_->misc_data_;
        svg_data_.Access()->geometry_data_ = other.svg_data_->geometry_data_;
        svg_data_.Access()->stop_data_ = other.svg_data_->stop_data_;
        svg_data_.Access()->masker_resource_ = other.svg_data_->masker_resource_;
        svg_data_.Access()->alignment_baseline_ = other.svg_data_->alignment_baseline_;
        svg_data_.Access()->buffered_rendering_ = other.svg_data_->buffered_rendering_;
        svg_data_.Access()->mask_type_ = other.svg_data_->mask_type_;
        svg_data_.Access()->vector_effect_ = other.svg_data_->vector_effect_;
    }
    box_data_ = other.box_data_;
    background_data_ = other.background_data_;
    surround_data_ = other.surround_data_;
    display_ = other.display_;
    original_display_ = other.original_display_;
    break_after_ = other.break_after_;
    break_before_ = other.break_before_;
    scrollbar_gutter_ = other.scrollbar_gutter_;
    break_inside_ = other.break_inside_;
    vertical_align_ = other.vertical_align_;
    clear_ = other.clear_;
    floating_ = other.floating_;
    overflow_x_ = other.overflow_x_;
    overflow_y_ = other.overflow_y_;
    position_ = other.position_;
    unicode_bidi_ = other.unicode_bidi_;
    content_visibility_ = other.content_visibility_;
    overflow_anchor_ = other.overflow_anchor_;
    overscroll_behavior_x_ = other.overscroll_behavior_x_;
    overscroll_behavior_y_ = other.overscroll_behavior_y_;
    viewport_unit_flags_ = other.viewport_unit_flags_;
    border_collapse_is_inherited_ = other.border_collapse_is_inherited_;
    box_direction_is_inherited_ = other.box_direction_is_inherited_;
    caption_side_is_inherited_ = other.caption_side_is_inherited_;
    color_is_inherited_ = other.color_is_inherited_;
    custom_style_callback_depends_on_font_ = other.custom_style_callback_depends_on_font_;
    empty_cells_is_inherited_ = other.empty_cells_is_inherited_;
    has_author_background_ = other.has_author_background_;
    has_author_border_ = other.has_author_border_;
    has_author_border_radius_ = other.has_author_border_radius_;
    has_author_highlight_colors_ = other.has_author_highlight_colors_;
    has_container_relative_units_ = other.has_container_relative_units_;
    has_em_units_ = other.has_em_units_;
    has_explicit_inheritance_ = other.has_explicit_inheritance_;
    has_glyph_relative_units_ = other.has_glyph_relative_units_;
    has_rem_units_ = other.has_rem_units_;
    has_variable_declaration_ = other.has_variable_declaration_;
    has_variable_reference_ = other.has_variable_reference_;
    is_ensured_in_display_none_ = other.is_ensured_in_display_none_;
    is_flex_or_grid_item_ = other.is_flex_or_grid_item_;
    is_flex_or_grid_or_custom_item_ = other.is_flex_or_grid_or_custom_item_;
    is_in_blockifying_display_ = other.is_in_blockifying_display_;
    is_inert_is_inherited_ = other.is_inert_is_inherited_;
    list_style_position_is_inherited_ = other.list_style_position_is_inherited_;
    origin_trial_test_property_ = other.origin_trial_test_property_;
    pointer_events_is_inherited_ = other.pointer_events_is_inherited_;
    rtl_ordering_is_inherited_ = other.rtl_ordering_is_inherited_;
    scroll_snap_stop_ = other.scroll_snap_stop_;
    should_ignore_overflow_property_for_inline_block_baseline_ = other.should_ignore_overflow_property_for_inline_block_baseline_;
    skips_contents_ = other.skips_contents_;
    table_layout_ = other.table_layout_;
    text_transform_is_inherited_ = other.text_transform_is_inherited_;
    transform_box_ = other.transform_box_;
    visibility_is_inherited_ = other.visibility_is_inherited_;
}

void ComputedStyleBase::PropagateIndependentInheritedProperties(const ComputedStyleBase& parentStyle)
{
    if (ColorIsInheritedInternal())
        inherited_data_.Access()->color_ = parentStyle.inherited_data_->color_;
    if (PointerEventsIsInheritedInternal())
        pointer_events_ = parentStyle.pointer_events_;
    if (TextTransformIsInherited())
        text_transform_ = parentStyle.text_transform_;
    if (VisibilityIsInherited())
        visibility_ = parentStyle.visibility_;
    if (BorderCollapseIsInherited())
        border_collapse_ = parentStyle.border_collapse_;
    if (BoxDirectionIsInherited())
        box_direction_ = parentStyle.box_direction_;
    if (CaptionSideIsInherited())
        caption_side_ = parentStyle.caption_side_;
    if (EmptyCellsIsInherited())
        empty_cells_ = parentStyle.empty_cells_;
    if (IsInertIsInherited())
        is_inert_ = parentStyle.is_inert_;
    if (ListStylePositionIsInherited())
        list_style_position_ = parentStyle.list_style_position_;
    if (RtlOrderingIsInherited())
        rtl_ordering_ = parentStyle.rtl_ordering_;
}

bool ComputedStyleBase::ScrollAnchorDisablingPropertyChanged(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.box_data_.Get() != b.box_data_.Get()) {
        if (a.box_data_->width_ != b.box_data_->width_)
            return true;
        if (a.box_data_->min_width_ != b.box_data_->min_width_)
            return true;
        if (a.box_data_->max_width_ != b.box_data_->max_width_)
            return true;
        if (a.box_data_->height_ != b.box_data_->height_)
            return true;
        if (a.box_data_->min_height_ != b.box_data_->min_height_)
            return true;
        if (a.box_data_->max_height_ != b.box_data_->max_height_)
            return true;
        if (a.box_data_->contain_intrinsic_width_ != b.box_data_->contain_intrinsic_width_)
            return true;
        if (a.box_data_->contain_intrinsic_height_ != b.box_data_->contain_intrinsic_height_)
            return true;
    }
    if (a.surround_data_.Get() != b.surround_data_.Get()) {
        if (a.surround_data_->margin_top_ != b.surround_data_->margin_top_)
            return true;
        if (a.surround_data_->margin_left_ != b.surround_data_->margin_left_)
            return true;
        if (a.surround_data_->margin_right_ != b.surround_data_->margin_right_)
            return true;
        if (a.surround_data_->margin_bottom_ != b.surround_data_->margin_bottom_)
            return true;
        if (a.surround_data_->left_ != b.surround_data_->left_)
            return true;
        if (a.surround_data_->right_ != b.surround_data_->right_)
            return true;
        if (a.surround_data_->top_ != b.surround_data_->top_)
            return true;
        if (a.surround_data_->bottom_ != b.surround_data_->bottom_)
            return true;
        if (a.surround_data_->padding_top_ != b.surround_data_->padding_top_)
            return true;
        if (a.surround_data_->padding_left_ != b.surround_data_->padding_left_)
            return true;
        if (a.surround_data_->padding_right_ != b.surround_data_->padding_right_)
            return true;
        if (a.surround_data_->padding_bottom_ != b.surround_data_->padding_bottom_)
            return true;
    }
    if (a.GetPosition() != b.GetPosition())
        return true;

    return false;
}

bool ComputedStyleBase::DiffNeedsReshapeAndFullLayoutAndPaintInvalidation(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.inherited_data_.Get() != b.inherited_data_.Get()) {
        if (a.inherited_data_->font_data_.Get() != b.inherited_data_->font_data_.Get()) {
            if (a.inherited_data_->font_data_->font_ != b.inherited_data_->font_data_->font_)
                return true;
        }
    }
    if (a.TextTransform() != b.TextTransform())
        return true;
    if (a.WhiteSpace() != b.WhiteSpace())
        return true;
    if (a.Direction() != b.Direction())
        return true;
    if (a.RtlOrdering() != b.RtlOrdering())
        return true;
    if (a.GetUnicodeBidi() != b.GetUnicodeBidi())
        return true;

    return false;
}

bool ComputedStyleBase::DiffNeedsFullLayoutAndPaintInvalidation(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.inherited_data_.Get() != b.inherited_data_.Get()) {
        if (a.inherited_data_->line_height_ != b.inherited_data_->line_height_)
            return true;
        if (a.inherited_data_->horizontal_border_spacing_ != b.inherited_data_->horizontal_border_spacing_)
            return true;
        if (a.inherited_data_->vertical_border_spacing_ != b.inherited_data_->vertical_border_spacing_)
            return true;
        if (a.inherited_data_->text_autosizing_multiplier_ != b.inherited_data_->text_autosizing_multiplier_)
            return true;
    }
    if (a.rare_inherited_usage_less_than_64_percent_data_.Get() != b.rare_inherited_usage_less_than_64_percent_data_.Get()) {
        if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()
            != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()) {
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_)
                return true;
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_)
                return true;
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_)
                return true;
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_)
                return true;
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->line_height_step_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->line_height_step_)
                return true;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_.Get()
            != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_.Get()) {
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->respect_image_orientation_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->respect_image_orientation_)
                return true;
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->ruby_position_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->ruby_position_)
                return true;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->highlight_ != b.rare_inherited_usage_less_than_64_percent_data_->highlight_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_indent_ != b.rare_inherited_usage_less_than_64_percent_data_->text_indent_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_align_last_ != b.rare_inherited_usage_less_than_64_percent_data_->text_align_last_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->word_break_ != b.rare_inherited_usage_less_than_64_percent_data_->word_break_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_ != b.rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->line_break_ != b.rare_inherited_usage_less_than_64_percent_data_->line_break_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_security_ != b.rare_inherited_usage_less_than_64_percent_data_->text_security_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->hyphens_ != b.rare_inherited_usage_less_than_64_percent_data_->hyphens_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_ != b.rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_ != b.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_orientation_ != b.rare_inherited_usage_less_than_64_percent_data_->text_orientation_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_combine_ != b.rare_inherited_usage_less_than_64_percent_data_->text_combine_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->tab_size_ != b.rare_inherited_usage_less_than_64_percent_data_->tab_size_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_ != b.rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_)
            return true;
        if (!base::ValuesEquivalent(a.rare_inherited_usage_less_than_64_percent_data_->list_style_image_, b.rare_inherited_usage_less_than_64_percent_data_->list_style_image_))
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_ != b.rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_)
            return true;
        if (!a.TextShadowDataEquivalent(b))
            return true;
        if (!a.QuotesDataEquivalent(b))
            return true;
    }
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    .Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                       .Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->shape_margin_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->shape_margin_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->grid_auto_rows_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_rows_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->grid_auto_columns_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_columns_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->row_gap_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->grid_auto_flow_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_auto_flow_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->box_ordinal_group_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->box_ordinal_group_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->grid_row_start_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_start_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->grid_row_end_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_row_end_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->grid_column_start_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_start_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->grid_column_end_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->grid_column_end_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->column_gap_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_gap_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->column_width_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_width_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->column_count_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_count_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->column_fill_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_fill_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->column_span_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_span_)
                    return true;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->line_clamp_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->line_clamp_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_)
                return true;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_.Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_.Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_column_lines_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_
                           ->implicit_named_grid_column_lines_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_row_lines_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_row_lines_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_row_count_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_row_count_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_column_count_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_column_count_)
                    return true;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_)
                return true;
            if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_,
                    b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_))
                return true;
            if (a.DisplayLayoutCustomName() != b.DisplayLayoutCustomName())
                return true;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->appearance_ != b.rare_non_inherited_usage_less_than_14_percent_data_->appearance_)
            return true;
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_ != b.rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_)
            return true;
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_ != b.rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_)
            return true;
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_ != b.rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_)
            return true;
        if (!a.OpacityChangedStackingContext(b))
            return true;
    }
    if (a.svg_data_.Get() != b.svg_data_.Get()) {
        if (a.svg_data_->misc_data_.Get() != b.svg_data_->misc_data_.Get()) {
            if (a.svg_data_->misc_data_->baseline_shift_type_ != b.svg_data_->misc_data_->baseline_shift_type_)
                return true;
            if (a.svg_data_->misc_data_->baseline_shift_ != b.svg_data_->misc_data_->baseline_shift_)
                return true;
        }
        if (a.svg_data_->geometry_data_.Get() != b.svg_data_->geometry_data_.Get()) {
            if (a.svg_data_->geometry_data_->cx_ != b.svg_data_->geometry_data_->cx_)
                return true;
            if (a.svg_data_->geometry_data_->cy_ != b.svg_data_->geometry_data_->cy_)
                return true;
            if (!base::ValuesEquivalent(a.svg_data_->geometry_data_->d_, b.svg_data_->geometry_data_->d_))
                return true;
            if (a.svg_data_->geometry_data_->rx_ != b.svg_data_->geometry_data_->rx_)
                return true;
            if (a.svg_data_->geometry_data_->ry_ != b.svg_data_->geometry_data_->ry_)
                return true;
            if (a.svg_data_->geometry_data_->x_ != b.svg_data_->geometry_data_->x_)
                return true;
            if (a.svg_data_->geometry_data_->y_ != b.svg_data_->geometry_data_->y_)
                return true;
            if (a.svg_data_->geometry_data_->r_ != b.svg_data_->geometry_data_->r_)
                return true;
        }
        if (a.svg_data_->stroke_data_.Get() != b.svg_data_->stroke_data_.Get()) {
            if (a.svg_data_->stroke_data_->stroke_width_ != b.svg_data_->stroke_data_->stroke_width_)
                return true;
            if (a.svg_data_->stroke_data_->stroke_miter_limit_ != b.svg_data_->stroke_data_->stroke_miter_limit_)
                return true;
            if (a.svg_data_->stroke_data_->cap_style_ != b.svg_data_->stroke_data_->cap_style_)
                return true;
            if (a.svg_data_->stroke_data_->join_style_ != b.svg_data_->stroke_data_->join_style_)
                return true;
            if (a.HasStroke() != b.HasStroke())
                return true;
            if (a.HasDashArray() != b.HasDashArray())
                return true;
        }
        if (a.svg_data_->inherited_resources_data_.Get() != b.svg_data_->inherited_resources_data_.Get()) {
            if (!base::ValuesEquivalent(a.svg_data_->inherited_resources_data_->marker_end_resource_, b.svg_data_->inherited_resources_data_->marker_end_resource_))
                return true;
            if (!base::ValuesEquivalent(a.svg_data_->inherited_resources_data_->marker_mid_resource_, b.svg_data_->inherited_resources_data_->marker_mid_resource_))
                return true;
            if (!base::ValuesEquivalent(a.svg_data_->inherited_resources_data_->marker_start_resource_, b.svg_data_->inherited_resources_data_->marker_start_resource_))
                return true;
        }
        if (a.svg_data_->alignment_baseline_ != b.svg_data_->alignment_baseline_)
            return true;
        if (a.svg_data_->vector_effect_ != b.svg_data_->vector_effect_)
            return true;
        if (a.svg_data_->dominant_baseline_ != b.svg_data_->dominant_baseline_)
            return true;
        if (a.svg_data_->css_dominant_baseline_ != b.svg_data_->css_dominant_baseline_)
            return true;
        if (a.svg_data_->text_anchor_ != b.svg_data_->text_anchor_)
            return true;
    }
    if (a.box_data_.Get() != b.box_data_.Get()) {
        if (a.box_data_->box_decoration_break_ != b.box_data_->box_decoration_break_)
            return true;
    }
    if (a.surround_data_.Get() != b.surround_data_.Get()) {
        if (a.surround_data_->padding_top_ != b.surround_data_->padding_top_)
            return true;
        if (a.surround_data_->padding_left_ != b.surround_data_->padding_left_)
            return true;
        if (a.surround_data_->padding_right_ != b.surround_data_->padding_right_)
            return true;
        if (a.surround_data_->padding_bottom_ != b.surround_data_->padding_bottom_)
            return true;
        if (a.BorderLeftWidth() != b.BorderLeftWidth())
            return true;
        if (a.BorderTopWidth() != b.BorderTopWidth())
            return true;
        if (a.BorderBottomWidth() != b.BorderBottomWidth())
            return true;
        if (a.BorderRightWidth() != b.BorderRightWidth())
            return true;
    }
    if (a.HasPseudoElementStyle(kPseudoIdScrollbar) != b.HasPseudoElementStyle(kPseudoIdScrollbar))
        return true;
    if (a.BoxDirection() != b.BoxDirection())
        return true;
    if (a.GetTextAlign() != b.GetTextAlign())
        return true;
    if (a.GetWritingMode() != b.GetWritingMode())
        return true;
    if (a.OverflowX() != b.OverflowX())
        return true;
    if (a.OverflowY() != b.OverflowY())
        return true;
    if (a.Clear() != b.Clear())
        return true;
    if (a.Floating() != b.Floating())
        return true;
    if (a.OriginalDisplay() != b.OriginalDisplay())
        return true;

    return false;
}

bool ComputedStyleBase::DiffNeedsFullLayoutAndPaintInvalidationDisplayTableType(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.BorderCollapse() != b.BorderCollapse())
        return true;
    if (a.EmptyCells() != b.EmptyCells())
        return true;
    if (a.CaptionSide() != b.CaptionSide())
        return true;
    if (a.TableLayout() != b.TableLayout())
        return true;

    return false;
}

bool ComputedStyleBase::DiffNeedsFullLayoutAndPaintInvalidationDisplayListItem(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_inherited_usage_less_than_64_percent_data_.Get() != b.rare_inherited_usage_less_than_64_percent_data_.Get()) {
        if (!a.ListStyleTypeDataEquivalent(b))
            return true;
    }
    if (a.ListStylePosition() != b.ListStylePosition())
        return true;

    return false;
}

bool ComputedStyleBase::DiffNeedsFullLayout(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_inherited_usage_less_than_64_percent_data_.Get() != b.rare_inherited_usage_less_than_64_percent_data_.Get()) {
        if (a.rare_inherited_usage_less_than_64_percent_data_->orphans_ != b.rare_inherited_usage_less_than_64_percent_data_->orphans_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->widows_ != b.rare_inherited_usage_less_than_64_percent_data_->widows_)
            return true;
    }
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    .Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                       .Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->justify_items_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->justify_items_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->justify_self_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->justify_self_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->contain_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->contain_)
                    return true;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_)
                return true;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_self_block_center_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_self_block_center_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_)
                return true;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->align_items_ != b.rare_non_inherited_usage_less_than_14_percent_data_->align_items_)
            return true;
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->justify_content_ != b.rare_non_inherited_usage_less_than_14_percent_data_->justify_content_)
            return true;
    }
    if (a.box_data_.Get() != b.box_data_.Get()) {
        if (a.box_data_->width_ != b.box_data_->width_)
            return true;
        if (a.box_data_->min_width_ != b.box_data_->min_width_)
            return true;
        if (a.box_data_->max_width_ != b.box_data_->max_width_)
            return true;
        if (a.box_data_->height_ != b.box_data_->height_)
            return true;
        if (a.box_data_->min_height_ != b.box_data_->min_height_)
            return true;
        if (a.box_data_->max_height_ != b.box_data_->max_height_)
            return true;
        if (a.box_data_->vertical_align_length_ != b.box_data_->vertical_align_length_)
            return true;
        if (a.box_data_->box_sizing_ != b.box_data_->box_sizing_)
            return true;
        if (a.box_data_->contain_intrinsic_width_ != b.box_data_->contain_intrinsic_width_)
            return true;
        if (a.box_data_->contain_intrinsic_height_ != b.box_data_->contain_intrinsic_height_)
            return true;
        if (a.box_data_->aspect_ratio_ != b.box_data_->aspect_ratio_)
            return true;
    }
    if (a.content_visibility_ != b.content_visibility_)
        return true;
    if (a.scrollbar_gutter_ != b.scrollbar_gutter_)
        return true;
    if (a.break_after_ != b.break_after_)
        return true;
    if (a.break_before_ != b.break_before_)
        return true;
    if (a.break_inside_ != b.break_inside_)
        return true;
    if (a.VerticalAlign() != b.VerticalAlign())
        return true;
    if (a.GetPosition() != b.GetPosition())
        return true;
    if (a.SkipsContents() != b.SkipsContents())
        return true;

    return false;
}

bool ComputedStyleBase::DiffNeedsPaintInvalidation(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.inherited_data_.Get() != b.inherited_data_.Get()) {
        if (a.AccentColorResolved() != b.AccentColorResolved())
            return true;
    }
    if (a.rare_inherited_usage_less_than_64_percent_data_.Get() != b.rare_inherited_usage_less_than_64_percent_data_.Get()) {
        if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()
            != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()) {
            if (a.AccentColorResolved() != b.AccentColorResolved())
                return true;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->user_modify_ != b.rare_inherited_usage_less_than_64_percent_data_->user_modify_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->user_select_ != b.rare_inherited_usage_less_than_64_percent_data_->user_select_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->image_rendering_ != b.rare_inherited_usage_less_than_64_percent_data_->image_rendering_)
            return true;
        if (a.UsedColorScheme() != b.UsedColorScheme())
            return true;
    }
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    .Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                       .Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->column_rule_style_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_style_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->column_rule_width_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_width_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->column_rule_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->column_rule_color_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->user_drag_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->object_position_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->object_position_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->blend_mode_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->blend_mode_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->isolation_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->isolation_)
                    return true;
                if (!a.ShapeOutsideDataEquivalent(b))
                    return true;
                if (!a.ClipPathDataEquivalent(b))
                    return true;
                if (!a.OutlineVisuallyEqual(b))
                    return true;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_)
                return true;
            if (a.Resize() != b.Resize())
                return true;
            if (!a.OutlineVisuallyEqual(b))
                return true;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_.Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_.Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_column_rule_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_column_rule_color_)
                    return true;
                if (!a.InternalVisitedBorderLeftColorHasNotChanged(b))
                    return true;
                if (!a.InternalVisitedBorderRightColorHasNotChanged(b))
                    return true;
                if (!a.InternalVisitedBorderBottomColorHasNotChanged(b))
                    return true;
                if (!a.InternalVisitedBorderTopColorHasNotChanged(b))
                    return true;
                if (!a.InternalVisitedOutlineColorHasNotChanged(b))
                    return true;
            }
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scroll_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scroll_)
                return true;
            if (a.AnchorScroll() != b.AnchorScroll())
                return true;
            if (!a.OutlineVisuallyEqual(b))
                return true;
        }
        if (!a.BoxShadowDataEquivalent(b))
            return true;
    }
    if (a.svg_data_.Get() != b.svg_data_.Get()) {
        if (a.svg_data_->misc_data_.Get() != b.svg_data_->misc_data_.Get()) {
            if (a.svg_data_->misc_data_->flood_color_ != b.svg_data_->misc_data_->flood_color_)
                return true;
            if (a.svg_data_->misc_data_->flood_opacity_ != b.svg_data_->misc_data_->flood_opacity_)
                return true;
            if (a.svg_data_->misc_data_->lighting_color_ != b.svg_data_->misc_data_->lighting_color_)
                return true;
        }
        if (a.svg_data_->fill_data_.Get() != b.svg_data_->fill_data_.Get()) {
            if (a.svg_data_->fill_data_->fill_paint_ != b.svg_data_->fill_data_->fill_paint_)
                return true;
            if (a.svg_data_->fill_data_->fill_opacity_ != b.svg_data_->fill_data_->fill_opacity_)
                return true;
        }
        if (a.svg_data_->stroke_data_.Get() != b.svg_data_->stroke_data_.Get()) {
            if (a.svg_data_->stroke_data_->stroke_paint_ != b.svg_data_->stroke_data_->stroke_paint_)
                return true;
            if (a.svg_data_->stroke_data_->stroke_opacity_ != b.svg_data_->stroke_data_->stroke_opacity_)
                return true;
            if (a.svg_data_->stroke_data_->internal_visited_stroke_paint_ != b.svg_data_->stroke_data_->internal_visited_stroke_paint_)
                return true;
            if (a.svg_data_->stroke_data_->stroke_dash_offset_ != b.svg_data_->stroke_data_->stroke_dash_offset_)
                return true;
            if (!a.StrokeDashArrayDataEquivalent(b))
                return true;
        }
        if (a.svg_data_->stop_data_.Get() != b.svg_data_->stop_data_.Get()) {
            if (a.svg_data_->stop_data_->stop_color_ != b.svg_data_->stop_data_->stop_color_)
                return true;
            if (a.svg_data_->stop_data_->stop_opacity_ != b.svg_data_->stop_data_->stop_opacity_)
                return true;
        }
        if (!base::ValuesEquivalent(a.svg_data_->masker_resource_, b.svg_data_->masker_resource_))
            return true;
        if (a.svg_data_->mask_type_ != b.svg_data_->mask_type_)
            return true;
        if (a.svg_data_->shape_rendering_ != b.svg_data_->shape_rendering_)
            return true;
        if (a.svg_data_->clip_rule_ != b.svg_data_->clip_rule_)
            return true;
        if (a.svg_data_->fill_rule_ != b.svg_data_->fill_rule_)
            return true;
        if (a.svg_data_->color_interpolation_ != b.svg_data_->color_interpolation_)
            return true;
        if (a.svg_data_->color_interpolation_filters_ != b.svg_data_->color_interpolation_filters_)
            return true;
        if (a.svg_data_->paint_order_ != b.svg_data_->paint_order_)
            return true;
    }
    if (a.color_scheme_forced_ != b.color_scheme_forced_)
        return true;
    if (a.Visibility() != b.Visibility())
        return true;
    if (a.PrintColorAdjust() != b.PrintColorAdjust())
        return true;
    if (a.InsideLink() != b.InsideLink())
        return true;

    return false;
}

bool ComputedStyleBase::DiffNeedsVisualRectUpdate(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    .Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                       .Get()) {
                if (!a.ClipPathDataEquivalent(b))
                    return true;
            }
            if (a.Resize() != b.Resize())
                return true;
        }
    }
    if (a.Visibility() != b.Visibility())
        return true;

    return false;
}

bool ComputedStyleBase::UpdatePropertySpecificDifferencesZIndex(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.IsStackingContextWithoutContainment() != b.IsStackingContextWithoutContainment())
            return true;
    }
    if (a.box_data_.Get() != b.box_data_.Get()) {
        if (a.box_data_->z_index_ != b.box_data_->z_index_)
            return true;
    }

    return false;
}

bool ComputedStyleBase::DiffTransformData(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    .Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                       .Get()) {
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->translate_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->translate_))
                    return true;
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_))
                    return true;
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->scale_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->scale_))
                    return true;
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_))
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->offset_rotate_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->offset_position_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->offset_anchor_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->offset_distance_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_)
                    return true;
            }
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->transform_ != b.rare_non_inherited_usage_less_than_14_percent_data_->transform_)
            return true;
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_ != b.rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_)
            return true;
    }
    if (a.transform_box_ != b.transform_box_)
        return true;

    return false;
}

bool ComputedStyleBase::UpdatePropertySpecificDifferencesTransform(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->transform_ != b.rare_non_inherited_usage_less_than_14_percent_data_->transform_)
            return true;
    }

    return false;
}

bool ComputedStyleBase::UpdatePropertySpecificDifferencesOtherTransform(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    .Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                       .Get()) {
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->translate_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->translate_))
                    return true;
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->rotate_))
                    return true;
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->scale_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->scale_))
                    return true;
                if (!base::ValuesEquivalent(a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                                ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_,
                        b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                            ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_))
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->offset_rotate_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_rotate_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->offset_position_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_position_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->offset_anchor_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_anchor_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->offset_distance_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->offset_distance_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->perspective_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->perspective_origin_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->perspective_origin_)
                    return true;
                if (a.HasTransform() != b.HasTransform())
                    return true;
            }
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()) {
            if (a.HasTransform() != b.HasTransform())
                return true;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_ != b.rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_)
            return true;
        if (a.HasTransform() != b.HasTransform())
            return true;
    }
    if (a.transform_box_ != b.transform_box_)
        return true;

    return false;
}

bool ComputedStyleBase::UpdatePropertySpecificDifferencesOpacity(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->opacity_ != b.rare_non_inherited_usage_less_than_14_percent_data_->opacity_)
            return true;
    }

    return false;
}

bool ComputedStyleBase::UpdatePropertySpecificDifferencesFilter(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    .Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                       .Get()) {
                if (!a.ReflectionDataEquivalent(b))
                    return true;
            }
            if (!a.FilterDataEquivalent(b))
                return true;
        }
    }

    return false;
}

bool ComputedStyleBase::UpdatePropertySpecificDifferencesMask(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_)
                return true;
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_)
                return true;
        }
    }
    if (a.svg_data_.Get() != b.svg_data_.Get()) {
        if (!base::ValuesEquivalent(a.svg_data_->masker_resource_, b.svg_data_->masker_resource_))
            return true;
    }

    return false;
}

bool ComputedStyleBase::UpdatePropertySpecificDifferencesNeedsRecomputeVisualOverflow(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.rare_inherited_usage_less_than_64_percent_data_.Get() != b.rare_inherited_usage_less_than_64_percent_data_.Get()) {
        if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()
            != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()) {
            if (!a.TextDecorationVisualOverflowEqual(b))
                return true;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_.Get()
            != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_.Get()) {
            if (!a.TextDecorationVisualOverflowEqual(b))
                return true;
        }
        if (!a.TextDecorationVisualOverflowEqual(b))
            return true;
    }
    if (a.visual_data_.Get() != b.visual_data_.Get()) {
        if (!a.TextDecorationVisualOverflowEqual(b))
            return true;
    }
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    .Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                       .Get()) {
                if (!a.OutlineVisuallyEqual(b))
                    return true;
                if (!a.TextDecorationVisualOverflowEqual(b))
                    return true;
            }
            if (!a.OutlineVisuallyEqual(b))
                return true;
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()) {
            if (!a.OutlineVisuallyEqual(b))
                return true;
        }
        if (!a.BoxShadowDataEquivalent(b))
            return true;
    }
    if (a.surround_data_.Get() != b.surround_data_.Get()) {
        if (!a.BorderVisualOverflowEqual(b))
            return true;
    }

    return false;
}

bool ComputedStyleBase::UpdatePropertySpecificDifferencesTextDecorationOrColor(const ComputedStyle& a, const ComputedStyle& b)
{
    if (a.inherited_data_.Get() != b.inherited_data_.Get()) {
        if (a.inherited_data_->color_ != b.inherited_data_->color_)
            return true;
        if (a.inherited_data_->internal_visited_color_ != b.inherited_data_->internal_visited_color_)
            return true;
    }
    if (a.rare_inherited_usage_less_than_64_percent_data_.Get() != b.rare_inherited_usage_less_than_64_percent_data_.Get()) {
        if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()
            != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_.Get()) {
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_.Get()
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_.Get()) {
                if (a.InternalVisitedTextFillColor() != b.InternalVisitedTextFillColor())
                    return true;
                if (a.InternalVisitedTextStrokeColor() != b.InternalVisitedTextStrokeColor())
                    return true;
                if (a.InternalVisitedTextEmphasisColor() != b.InternalVisitedTextEmphasisColor())
                    return true;
                if (a.InternalVisitedCaretColor() != b.InternalVisitedCaretColor())
                    return true;
            }
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_)
                return true;
            if (!base::ValuesEquivalent(a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->applied_text_decorations_,
                    b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->applied_text_decorations_))
                return true;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_.Get()
            != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_.Get()) {
            if (a.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_
                != b.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_)
                return true;
        }
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_decoration_thickness_ != b.rare_inherited_usage_less_than_64_percent_data_->text_decoration_thickness_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_underline_position_ != b.rare_inherited_usage_less_than_64_percent_data_->text_underline_position_)
            return true;
        if (a.rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_ != b.rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_)
            return true;
        if (a.TextFillColor() != b.TextFillColor())
            return true;
        if (a.TextStrokeColor() != b.TextStrokeColor())
            return true;
        if (a.TextEmphasisColor() != b.TextEmphasisColor())
            return true;
        if (a.CaretColor() != b.CaretColor())
            return true;
    }
    if (a.visual_data_.Get() != b.visual_data_.Get()) {
        if (a.visual_data_->text_decoration_line_ != b.visual_data_->text_decoration_line_)
            return true;
    }
    if (a.rare_non_inherited_usage_less_than_14_percent_data_.Get() != b.rare_non_inherited_usage_less_than_14_percent_data_.Get()) {
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                    .Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                       .Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->text_decoration_style_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_style_)
                    return true;
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                        ->text_decoration_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                           ->rare_non_inherited_usage_less_than_100_percent_data_->text_decoration_color_)
                    return true;
            }
        }
        if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()
            != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_.Get()) {
            if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_.Get()
                != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_.Get()) {
                if (a.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                        ->internal_visited_text_decoration_color_
                    != b.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                           ->internal_visited_text_decoration_color_)
                    return true;
            }
        }
    }
    if (a.HasSimpleUnderlineInternal() != b.HasSimpleUnderlineInternal())
        return true;

    return false;
}

#if DCHECK_IS_ON()

String ComputedStyleBase::DebugFieldToString(DebugField field)
{
    switch (field) {
    case DebugField::accent_color_:
        return "accent_color_";
    case DebugField::affected_by_active_:
        return "affected_by_active_";
    case DebugField::affected_by_drag_:
        return "affected_by_drag_";
    case DebugField::affected_by_focus_within_:
        return "affected_by_focus_within_";
    case DebugField::affected_by_hover_:
        return "affected_by_hover_";
    case DebugField::align_content_:
        return "align_content_";
    case DebugField::align_items_:
        return "align_items_";
    case DebugField::align_self_:
        return "align_self_";
    case DebugField::align_self_block_center_:
        return "align_self_block_center_";
    case DebugField::alignment_baseline_:
        return "alignment_baseline_";
    case DebugField::anchor_name_:
        return "anchor_name_";
    case DebugField::anchor_scroll_:
        return "anchor_scroll_";
    case DebugField::animations_:
        return "animations_";
    case DebugField::appearance_:
        return "appearance_";
    case DebugField::applied_text_decorations_:
        return "applied_text_decorations_";
    case DebugField::aspect_ratio_:
        return "aspect_ratio_";
    case DebugField::backdrop_filter_:
        return "backdrop_filter_";
    case DebugField::backface_visibility_:
        return "backface_visibility_";
    case DebugField::background_:
        return "background_";
    case DebugField::background_color_:
        return "background_color_";
    case DebugField::base_data_:
        return "base_data_";
    case DebugField::baseline_shift_:
        return "baseline_shift_";
    case DebugField::baseline_shift_type_:
        return "baseline_shift_type_";
    case DebugField::blend_mode_:
        return "blend_mode_";
    case DebugField::border_bottom_color_:
        return "border_bottom_color_";
    case DebugField::border_bottom_left_radius_:
        return "border_bottom_left_radius_";
    case DebugField::border_bottom_right_radius_:
        return "border_bottom_right_radius_";
    case DebugField::border_bottom_style_:
        return "border_bottom_style_";
    case DebugField::border_bottom_width_:
        return "border_bottom_width_";
    case DebugField::border_collapse_:
        return "border_collapse_";
    case DebugField::border_collapse_is_inherited_:
        return "border_collapse_is_inherited_";
    case DebugField::border_image_:
        return "border_image_";
    case DebugField::border_left_color_:
        return "border_left_color_";
    case DebugField::border_left_style_:
        return "border_left_style_";
    case DebugField::border_left_width_:
        return "border_left_width_";
    case DebugField::border_right_color_:
        return "border_right_color_";
    case DebugField::border_right_style_:
        return "border_right_style_";
    case DebugField::border_right_width_:
        return "border_right_width_";
    case DebugField::border_top_color_:
        return "border_top_color_";
    case DebugField::border_top_left_radius_:
        return "border_top_left_radius_";
    case DebugField::border_top_right_radius_:
        return "border_top_right_radius_";
    case DebugField::border_top_style_:
        return "border_top_style_";
    case DebugField::border_top_width_:
        return "border_top_width_";
    case DebugField::bottom_:
        return "bottom_";
    case DebugField::box_align_:
        return "box_align_";
    case DebugField::box_decoration_break_:
        return "box_decoration_break_";
    case DebugField::box_direction_:
        return "box_direction_";
    case DebugField::box_direction_is_inherited_:
        return "box_direction_is_inherited_";
    case DebugField::box_flex_:
        return "box_flex_";
    case DebugField::box_ordinal_group_:
        return "box_ordinal_group_";
    case DebugField::box_orient_:
        return "box_orient_";
    case DebugField::box_pack_:
        return "box_pack_";
    case DebugField::box_reflect_:
        return "box_reflect_";
    case DebugField::box_shadow_:
        return "box_shadow_";
    case DebugField::box_sizing_:
        return "box_sizing_";
    case DebugField::break_after_:
        return "break_after_";
    case DebugField::break_before_:
        return "break_before_";
    case DebugField::break_inside_:
        return "break_inside_";
    case DebugField::buffered_rendering_:
        return "buffered_rendering_";
    case DebugField::callback_selectors_:
        return "callback_selectors_";
    case DebugField::cap_style_:
        return "cap_style_";
    case DebugField::caption_side_:
        return "caption_side_";
    case DebugField::caption_side_is_inherited_:
        return "caption_side_is_inherited_";
    case DebugField::caret_color_:
        return "caret_color_";
    case DebugField::child_has_explicit_inheritance_:
        return "child_has_explicit_inheritance_";
    case DebugField::clear_:
        return "clear_";
    case DebugField::clip_:
        return "clip_";
    case DebugField::clip_path_:
        return "clip_path_";
    case DebugField::clip_rule_:
        return "clip_rule_";
    case DebugField::color_:
        return "color_";
    case DebugField::color_interpolation_:
        return "color_interpolation_";
    case DebugField::color_interpolation_filters_:
        return "color_interpolation_filters_";
    case DebugField::color_is_current_color_:
        return "color_is_current_color_";
    case DebugField::color_is_inherited_:
        return "color_is_inherited_";
    case DebugField::color_rendering_:
        return "color_rendering_";
    case DebugField::color_scheme_:
        return "color_scheme_";
    case DebugField::color_scheme_forced_:
        return "color_scheme_forced_";
    case DebugField::column_count_:
        return "column_count_";
    case DebugField::column_fill_:
        return "column_fill_";
    case DebugField::column_gap_:
        return "column_gap_";
    case DebugField::column_rule_color_:
        return "column_rule_color_";
    case DebugField::column_rule_style_:
        return "column_rule_style_";
    case DebugField::column_rule_width_:
        return "column_rule_width_";
    case DebugField::column_span_:
        return "column_span_";
    case DebugField::column_width_:
        return "column_width_";
    case DebugField::compositable_paint_animation_changed_:
        return "compositable_paint_animation_changed_";
    case DebugField::contain_:
        return "contain_";
    case DebugField::contain_intrinsic_height_:
        return "contain_intrinsic_height_";
    case DebugField::contain_intrinsic_width_:
        return "contain_intrinsic_width_";
    case DebugField::container_name_:
        return "container_name_";
    case DebugField::container_type_:
        return "container_type_";
    case DebugField::content_:
        return "content_";
    case DebugField::content_visibility_:
        return "content_visibility_";
    case DebugField::counter_directives_:
        return "counter_directives_";
    case DebugField::css_dominant_baseline_:
        return "css_dominant_baseline_";
    case DebugField::cursor_:
        return "cursor_";
    case DebugField::cursor_data_:
        return "cursor_data_";
    case DebugField::custom_highlight_names_:
        return "custom_highlight_names_";
    case DebugField::custom_style_callback_depends_on_font_:
        return "custom_style_callback_depends_on_font_";
    case DebugField::cx_:
        return "cx_";
    case DebugField::cy_:
        return "cy_";
    case DebugField::d_:
        return "d_";
    case DebugField::dark_color_scheme_:
        return "dark_color_scheme_";
    case DebugField::depends_on_size_container_queries_:
        return "depends_on_size_container_queries_";
    case DebugField::depends_on_style_container_queries_:
        return "depends_on_style_container_queries_";
    case DebugField::direction_:
        return "direction_";
    case DebugField::display_:
        return "display_";
    case DebugField::display_layout_custom_name_:
        return "display_layout_custom_name_";
    case DebugField::display_layout_custom_parent_name_:
        return "display_layout_custom_parent_name_";
    case DebugField::dominant_baseline_:
        return "dominant_baseline_";
    case DebugField::draggable_region_mode_:
        return "draggable_region_mode_";
    case DebugField::effective_appearance_:
        return "effective_appearance_";
    case DebugField::effective_touch_action_:
        return "effective_touch_action_";
    case DebugField::effective_z_index_zero_:
        return "effective_z_index_zero_";
    case DebugField::effective_zoom_:
        return "effective_zoom_";
    case DebugField::empty_cells_:
        return "empty_cells_";
    case DebugField::empty_cells_is_inherited_:
        return "empty_cells_is_inherited_";
    case DebugField::fill_opacity_:
        return "fill_opacity_";
    case DebugField::fill_paint_:
        return "fill_paint_";
    case DebugField::fill_rule_:
        return "fill_rule_";
    case DebugField::filter_:
        return "filter_";
    case DebugField::first_line_depends_on_size_container_queries_:
        return "first_line_depends_on_size_container_queries_";
    case DebugField::flex_basis_:
        return "flex_basis_";
    case DebugField::flex_direction_:
        return "flex_direction_";
    case DebugField::flex_grow_:
        return "flex_grow_";
    case DebugField::flex_shrink_:
        return "flex_shrink_";
    case DebugField::flex_wrap_:
        return "flex_wrap_";
    case DebugField::floating_:
        return "floating_";
    case DebugField::flood_color_:
        return "flood_color_";
    case DebugField::flood_opacity_:
        return "flood_opacity_";
    case DebugField::font_:
        return "font_";
    case DebugField::forced_color_adjust_:
        return "forced_color_adjust_";
    case DebugField::grid_auto_columns_:
        return "grid_auto_columns_";
    case DebugField::grid_auto_flow_:
        return "grid_auto_flow_";
    case DebugField::grid_auto_rows_:
        return "grid_auto_rows_";
    case DebugField::grid_column_end_:
        return "grid_column_end_";
    case DebugField::grid_column_start_:
        return "grid_column_start_";
    case DebugField::grid_row_end_:
        return "grid_row_end_";
    case DebugField::grid_row_start_:
        return "grid_row_start_";
    case DebugField::grid_template_columns_:
        return "grid_template_columns_";
    case DebugField::grid_template_rows_:
        return "grid_template_rows_";
    case DebugField::has_attr_content_:
        return "has_attr_content_";
    case DebugField::has_author_background_:
        return "has_author_background_";
    case DebugField::has_author_border_:
        return "has_author_border_";
    case DebugField::has_author_border_radius_:
        return "has_author_border_radius_";
    case DebugField::has_author_highlight_colors_:
        return "has_author_highlight_colors_";
    case DebugField::has_auto_clip_:
        return "has_auto_clip_";
    case DebugField::has_auto_column_count_:
        return "has_auto_column_count_";
    case DebugField::has_auto_column_width_:
        return "has_auto_column_width_";
    case DebugField::has_auto_z_index_:
        return "has_auto_z_index_";
    case DebugField::has_clip_path_:
        return "has_clip_path_";
    case DebugField::has_container_relative_units_:
        return "has_container_relative_units_";
    case DebugField::has_current_backdrop_filter_animation_:
        return "has_current_backdrop_filter_animation_";
    case DebugField::has_current_background_color_animation_:
        return "has_current_background_color_animation_";
    case DebugField::has_current_clip_path_animation_:
        return "has_current_clip_path_animation_";
    case DebugField::has_current_filter_animation_:
        return "has_current_filter_animation_";
    case DebugField::has_current_opacity_animation_:
        return "has_current_opacity_animation_";
    case DebugField::has_current_rotate_animation_:
        return "has_current_rotate_animation_";
    case DebugField::has_current_scale_animation_:
        return "has_current_scale_animation_";
    case DebugField::has_current_transform_animation_:
        return "has_current_transform_animation_";
    case DebugField::has_current_translate_animation_:
        return "has_current_translate_animation_";
    case DebugField::has_em_units_:
        return "has_em_units_";
    case DebugField::has_explicit_inheritance_:
        return "has_explicit_inheritance_";
    case DebugField::has_explicit_overflow_x_visible_:
        return "has_explicit_overflow_x_visible_";
    case DebugField::has_explicit_overflow_y_visible_:
        return "has_explicit_overflow_y_visible_";
    case DebugField::has_glyph_relative_units_:
        return "has_glyph_relative_units_";
    case DebugField::has_line_height_relative_units_:
        return "has_line_height_relative_units_";
    case DebugField::has_line_if_empty_:
        return "has_line_if_empty_";
    case DebugField::has_non_universal_highlight_pseudo_styles_:
        return "has_non_universal_highlight_pseudo_styles_";
    case DebugField::has_rem_units_:
        return "has_rem_units_";
    case DebugField::has_simple_underline_:
        return "has_simple_underline_";
    case DebugField::has_variable_declaration_:
        return "has_variable_declaration_";
    case DebugField::has_variable_reference_:
        return "has_variable_reference_";
    case DebugField::has_variable_reference_from_non_inherited_property_:
        return "has_variable_reference_from_non_inherited_property_";
    case DebugField::height_:
        return "height_";
    case DebugField::highlight_:
        return "highlight_";
    case DebugField::highlight_data_:
        return "highlight_data_";
    case DebugField::horizontal_border_spacing_:
        return "horizontal_border_spacing_";
    case DebugField::hyphenate_limit_chars_:
        return "hyphenate_limit_chars_";
    case DebugField::hyphenation_string_:
        return "hyphenation_string_";
    case DebugField::hyphens_:
        return "hyphens_";
    case DebugField::image_rendering_:
        return "image_rendering_";
    case DebugField::implicit_named_grid_column_lines_:
        return "implicit_named_grid_column_lines_";
    case DebugField::implicit_named_grid_row_lines_:
        return "implicit_named_grid_row_lines_";
    case DebugField::in_forced_colors_mode_:
        return "in_forced_colors_mode_";
    case DebugField::inherited_variables_:
        return "inherited_variables_";
    case DebugField::initial_data_:
        return "initial_data_";
    case DebugField::initial_letter_:
        return "initial_letter_";
    case DebugField::inline_style_lost_cascade_:
        return "inline_style_lost_cascade_";
    case DebugField::inside_fragmentation_context_with_nondeterministic_engine_:
        return "inside_fragmentation_context_with_nondeterministic_engine_";
    case DebugField::inside_link_:
        return "inside_link_";
    case DebugField::internal_forced_background_color_:
        return "internal_forced_background_color_";
    case DebugField::internal_forced_border_color_:
        return "internal_forced_border_color_";
    case DebugField::internal_forced_color_:
        return "internal_forced_color_";
    case DebugField::internal_forced_outline_color_:
        return "internal_forced_outline_color_";
    case DebugField::internal_forced_visited_color_:
        return "internal_forced_visited_color_";
    case DebugField::internal_visited_background_color_:
        return "internal_visited_background_color_";
    case DebugField::internal_visited_border_bottom_color_:
        return "internal_visited_border_bottom_color_";
    case DebugField::internal_visited_border_left_color_:
        return "internal_visited_border_left_color_";
    case DebugField::internal_visited_border_right_color_:
        return "internal_visited_border_right_color_";
    case DebugField::internal_visited_border_top_color_:
        return "internal_visited_border_top_color_";
    case DebugField::internal_visited_caret_color_:
        return "internal_visited_caret_color_";
    case DebugField::internal_visited_color_:
        return "internal_visited_color_";
    case DebugField::internal_visited_color_is_current_color_:
        return "internal_visited_color_is_current_color_";
    case DebugField::internal_visited_column_rule_color_:
        return "internal_visited_column_rule_color_";
    case DebugField::internal_visited_fill_paint_:
        return "internal_visited_fill_paint_";
    case DebugField::internal_visited_outline_color_:
        return "internal_visited_outline_color_";
    case DebugField::internal_visited_stroke_paint_:
        return "internal_visited_stroke_paint_";
    case DebugField::internal_visited_text_decoration_color_:
        return "internal_visited_text_decoration_color_";
    case DebugField::internal_visited_text_emphasis_color_:
        return "internal_visited_text_emphasis_color_";
    case DebugField::internal_visited_text_fill_color_:
        return "internal_visited_text_fill_color_";
    case DebugField::internal_visited_text_stroke_color_:
        return "internal_visited_text_stroke_color_";
    case DebugField::is_ensured_in_display_none_:
        return "is_ensured_in_display_none_";
    case DebugField::is_ensured_outside_flat_tree_:
        return "is_ensured_outside_flat_tree_";
    case DebugField::is_flex_or_grid_item_:
        return "is_flex_or_grid_item_";
    case DebugField::is_flex_or_grid_or_custom_item_:
        return "is_flex_or_grid_or_custom_item_";
    case DebugField::is_in_blockifying_display_:
        return "is_in_blockifying_display_";
    case DebugField::is_inert_:
        return "is_inert_";
    case DebugField::is_inert_is_inherited_:
        return "is_inert_is_inherited_";
    case DebugField::is_inside_list_element_:
        return "is_inside_list_element_";
    case DebugField::is_link_:
        return "is_link_";
    case DebugField::is_running_backdrop_filter_animation_on_compositor_:
        return "is_running_backdrop_filter_animation_on_compositor_";
    case DebugField::is_running_filter_animation_on_compositor_:
        return "is_running_filter_animation_on_compositor_";
    case DebugField::is_running_opacity_animation_on_compositor_:
        return "is_running_opacity_animation_on_compositor_";
    case DebugField::is_running_rotate_animation_on_compositor_:
        return "is_running_rotate_animation_on_compositor_";
    case DebugField::is_running_scale_animation_on_compositor_:
        return "is_running_scale_animation_on_compositor_";
    case DebugField::is_running_transform_animation_on_compositor_:
        return "is_running_transform_animation_on_compositor_";
    case DebugField::is_running_translate_animation_on_compositor_:
        return "is_running_translate_animation_on_compositor_";
    case DebugField::is_secondary_body_element_:
        return "is_secondary_body_element_";
    case DebugField::is_stacking_context_without_containment_:
        return "is_stacking_context_without_containment_";
    case DebugField::isolation_:
        return "isolation_";
    case DebugField::join_style_:
        return "join_style_";
    case DebugField::justify_content_:
        return "justify_content_";
    case DebugField::justify_items_:
        return "justify_items_";
    case DebugField::justify_self_:
        return "justify_self_";
    case DebugField::left_:
        return "left_";
    case DebugField::lighting_color_:
        return "lighting_color_";
    case DebugField::line_break_:
        return "line_break_";
    case DebugField::line_clamp_:
        return "line_clamp_";
    case DebugField::line_height_:
        return "line_height_";
    case DebugField::line_height_step_:
        return "line_height_step_";
    case DebugField::list_style_image_:
        return "list_style_image_";
    case DebugField::list_style_position_:
        return "list_style_position_";
    case DebugField::list_style_position_is_inherited_:
        return "list_style_position_is_inherited_";
    case DebugField::list_style_type_:
        return "list_style_type_";
    case DebugField::margin_bottom_:
        return "margin_bottom_";
    case DebugField::margin_left_:
        return "margin_left_";
    case DebugField::margin_right_:
        return "margin_right_";
    case DebugField::margin_top_:
        return "margin_top_";
    case DebugField::marker_end_resource_:
        return "marker_end_resource_";
    case DebugField::marker_mid_resource_:
        return "marker_mid_resource_";
    case DebugField::marker_start_resource_:
        return "marker_start_resource_";
    case DebugField::mask_:
        return "mask_";
    case DebugField::mask_box_image_:
        return "mask_box_image_";
    case DebugField::mask_type_:
        return "mask_type_";
    case DebugField::masker_resource_:
        return "masker_resource_";
    case DebugField::math_baseline_:
        return "math_baseline_";
    case DebugField::math_depth_:
        return "math_depth_";
    case DebugField::math_fraction_bar_thickness_:
        return "math_fraction_bar_thickness_";
    case DebugField::math_l_space_:
        return "math_l_space_";
    case DebugField::math_max_size_:
        return "math_max_size_";
    case DebugField::math_min_size_:
        return "math_min_size_";
    case DebugField::math_padded_depth_:
        return "math_padded_depth_";
    case DebugField::math_padded_v_offset_:
        return "math_padded_v_offset_";
    case DebugField::math_r_space_:
        return "math_r_space_";
    case DebugField::math_shift_:
        return "math_shift_";
    case DebugField::math_style_:
        return "math_style_";
    case DebugField::max_height_:
        return "max_height_";
    case DebugField::max_width_:
        return "max_width_";
    case DebugField::may_have_margin_:
        return "may_have_margin_";
    case DebugField::may_have_padding_:
        return "may_have_padding_";
    case DebugField::min_height_:
        return "min_height_";
    case DebugField::min_width_:
        return "min_width_";
    case DebugField::named_grid_area_:
        return "named_grid_area_";
    case DebugField::named_grid_area_column_count_:
        return "named_grid_area_column_count_";
    case DebugField::named_grid_area_row_count_:
        return "named_grid_area_row_count_";
    case DebugField::non_inherited_variables_:
        return "non_inherited_variables_";
    case DebugField::object_fit_:
        return "object_fit_";
    case DebugField::object_position_:
        return "object_position_";
    case DebugField::object_view_box_:
        return "object_view_box_";
    case DebugField::offset_anchor_:
        return "offset_anchor_";
    case DebugField::offset_distance_:
        return "offset_distance_";
    case DebugField::offset_path_:
        return "offset_path_";
    case DebugField::offset_position_:
        return "offset_position_";
    case DebugField::offset_rotate_:
        return "offset_rotate_";
    case DebugField::opacity_:
        return "opacity_";
    case DebugField::order_:
        return "order_";
    case DebugField::origin_trial_test_property_:
        return "origin_trial_test_property_";
    case DebugField::original_display_:
        return "original_display_";
    case DebugField::orphans_:
        return "orphans_";
    case DebugField::outline_color_:
        return "outline_color_";
    case DebugField::outline_offset_:
        return "outline_offset_";
    case DebugField::outline_style_:
        return "outline_style_";
    case DebugField::outline_style_is_auto_:
        return "outline_style_is_auto_";
    case DebugField::outline_width_:
        return "outline_width_";
    case DebugField::overflow_anchor_:
        return "overflow_anchor_";
    case DebugField::overflow_clip_margin_:
        return "overflow_clip_margin_";
    case DebugField::overflow_wrap_:
        return "overflow_wrap_";
    case DebugField::overflow_x_:
        return "overflow_x_";
    case DebugField::overflow_y_:
        return "overflow_y_";
    case DebugField::overscroll_behavior_x_:
        return "overscroll_behavior_x_";
    case DebugField::overscroll_behavior_y_:
        return "overscroll_behavior_y_";
    case DebugField::padding_bottom_:
        return "padding_bottom_";
    case DebugField::padding_left_:
        return "padding_left_";
    case DebugField::padding_right_:
        return "padding_right_";
    case DebugField::padding_top_:
        return "padding_top_";
    case DebugField::page_:
        return "page_";
    case DebugField::page_orientation_:
        return "page_orientation_";
    case DebugField::page_size_:
        return "page_size_";
    case DebugField::page_size_type_:
        return "page_size_type_";
    case DebugField::page_transition_tag_:
        return "page_transition_tag_";
    case DebugField::paint_images_:
        return "paint_images_";
    case DebugField::paint_order_:
        return "paint_order_";
    case DebugField::perspective_:
        return "perspective_";
    case DebugField::perspective_origin_:
        return "perspective_origin_";
    case DebugField::pointer_events_:
        return "pointer_events_";
    case DebugField::pointer_events_is_inherited_:
        return "pointer_events_is_inherited_";
    case DebugField::position_:
        return "position_";
    case DebugField::position_fallback_:
        return "position_fallback_";
    case DebugField::print_color_adjust_:
        return "print_color_adjust_";
    case DebugField::pseudo_argument_:
        return "pseudo_argument_";
    case DebugField::pseudo_bits_:
        return "pseudo_bits_";
    case DebugField::quotes_:
        return "quotes_";
    case DebugField::r_:
        return "r_";
    case DebugField::requires_accelerated_compositing_for_external_reasons_:
        return "requires_accelerated_compositing_for_external_reasons_";
    case DebugField::resize_:
        return "resize_";
    case DebugField::respect_image_orientation_:
        return "respect_image_orientation_";
    case DebugField::right_:
        return "right_";
    case DebugField::rotate_:
        return "rotate_";
    case DebugField::row_gap_:
        return "row_gap_";
    case DebugField::rtl_ordering_:
        return "rtl_ordering_";
    case DebugField::rtl_ordering_is_inherited_:
        return "rtl_ordering_is_inherited_";
    case DebugField::ruby_position_:
        return "ruby_position_";
    case DebugField::rx_:
        return "rx_";
    case DebugField::ry_:
        return "ry_";
    case DebugField::scale_:
        return "scale_";
    case DebugField::scroll_behavior_:
        return "scroll_behavior_";
    case DebugField::scroll_customization_:
        return "scroll_customization_";
    case DebugField::scroll_margin_bottom_:
        return "scroll_margin_bottom_";
    case DebugField::scroll_margin_left_:
        return "scroll_margin_left_";
    case DebugField::scroll_margin_right_:
        return "scroll_margin_right_";
    case DebugField::scroll_margin_top_:
        return "scroll_margin_top_";
    case DebugField::scroll_padding_bottom_:
        return "scroll_padding_bottom_";
    case DebugField::scroll_padding_left_:
        return "scroll_padding_left_";
    case DebugField::scroll_padding_right_:
        return "scroll_padding_right_";
    case DebugField::scroll_padding_top_:
        return "scroll_padding_top_";
    case DebugField::scroll_snap_align_:
        return "scroll_snap_align_";
    case DebugField::scroll_snap_stop_:
        return "scroll_snap_stop_";
    case DebugField::scroll_snap_type_:
        return "scroll_snap_type_";
    case DebugField::scroll_timeline_axis_:
        return "scroll_timeline_axis_";
    case DebugField::scroll_timeline_name_:
        return "scroll_timeline_name_";
    case DebugField::scrollbar_gutter_:
        return "scrollbar_gutter_";
    case DebugField::scrollbar_width_:
        return "scrollbar_width_";
    case DebugField::shape_image_threshold_:
        return "shape_image_threshold_";
    case DebugField::shape_margin_:
        return "shape_margin_";
    case DebugField::shape_outside_:
        return "shape_outside_";
    case DebugField::shape_rendering_:
        return "shape_rendering_";
    case DebugField::should_ignore_overflow_property_for_inline_block_baseline_:
        return "should_ignore_overflow_property_for_inline_block_baseline_";
    case DebugField::skips_contents_:
        return "skips_contents_";
    case DebugField::speak_:
        return "speak_";
    case DebugField::stop_color_:
        return "stop_color_";
    case DebugField::stop_opacity_:
        return "stop_opacity_";
    case DebugField::stroke_dash_array_:
        return "stroke_dash_array_";
    case DebugField::stroke_dash_offset_:
        return "stroke_dash_offset_";
    case DebugField::stroke_miter_limit_:
        return "stroke_miter_limit_";
    case DebugField::stroke_opacity_:
        return "stroke_opacity_";
    case DebugField::stroke_paint_:
        return "stroke_paint_";
    case DebugField::stroke_width_:
        return "stroke_width_";
    case DebugField::style_type_:
        return "style_type_";
    case DebugField::subtree_is_sticky_:
        return "subtree_is_sticky_";
    case DebugField::subtree_will_change_contents_:
        return "subtree_will_change_contents_";
    case DebugField::tab_size_:
        return "tab_size_";
    case DebugField::table_layout_:
        return "table_layout_";
    case DebugField::tap_highlight_color_:
        return "tap_highlight_color_";
    case DebugField::text_align_:
        return "text_align_";
    case DebugField::text_align_last_:
        return "text_align_last_";
    case DebugField::text_anchor_:
        return "text_anchor_";
    case DebugField::text_autosizing_multiplier_:
        return "text_autosizing_multiplier_";
    case DebugField::text_combine_:
        return "text_combine_";
    case DebugField::text_decoration_color_:
        return "text_decoration_color_";
    case DebugField::text_decoration_line_:
        return "text_decoration_line_";
    case DebugField::text_decoration_skip_ink_:
        return "text_decoration_skip_ink_";
    case DebugField::text_decoration_style_:
        return "text_decoration_style_";
    case DebugField::text_decoration_thickness_:
        return "text_decoration_thickness_";
    case DebugField::text_emphasis_color_:
        return "text_emphasis_color_";
    case DebugField::text_emphasis_custom_mark_:
        return "text_emphasis_custom_mark_";
    case DebugField::text_emphasis_fill_:
        return "text_emphasis_fill_";
    case DebugField::text_emphasis_mark_:
        return "text_emphasis_mark_";
    case DebugField::text_emphasis_position_:
        return "text_emphasis_position_";
    case DebugField::text_fill_color_:
        return "text_fill_color_";
    case DebugField::text_indent_:
        return "text_indent_";
    case DebugField::text_orientation_:
        return "text_orientation_";
    case DebugField::text_overflow_:
        return "text_overflow_";
    case DebugField::text_security_:
        return "text_security_";
    case DebugField::text_shadow_:
        return "text_shadow_";
    case DebugField::text_size_adjust_:
        return "text_size_adjust_";
    case DebugField::text_stroke_color_:
        return "text_stroke_color_";
    case DebugField::text_stroke_width_:
        return "text_stroke_width_";
    case DebugField::text_transform_:
        return "text_transform_";
    case DebugField::text_transform_is_inherited_:
        return "text_transform_is_inherited_";
    case DebugField::text_underline_offset_:
        return "text_underline_offset_";
    case DebugField::text_underline_position_:
        return "text_underline_position_";
    case DebugField::toggle_group_:
        return "toggle_group_";
    case DebugField::toggle_root_:
        return "toggle_root_";
    case DebugField::toggle_trigger_:
        return "toggle_trigger_";
    case DebugField::toggle_visibility_:
        return "toggle_visibility_";
    case DebugField::top_:
        return "top_";
    case DebugField::touch_action_:
        return "touch_action_";
    case DebugField::transform_:
        return "transform_";
    case DebugField::transform_box_:
        return "transform_box_";
    case DebugField::transform_origin_:
        return "transform_origin_";
    case DebugField::transform_style_3d_:
        return "transform_style_3d_";
    case DebugField::transitions_:
        return "transitions_";
    case DebugField::translate_:
        return "translate_";
    case DebugField::unicode_bidi_:
        return "unicode_bidi_";
    case DebugField::user_drag_:
        return "user_drag_";
    case DebugField::user_modify_:
        return "user_modify_";
    case DebugField::user_select_:
        return "user_select_";
    case DebugField::vector_effect_:
        return "vector_effect_";
    case DebugField::vertical_align_:
        return "vertical_align_";
    case DebugField::vertical_align_length_:
        return "vertical_align_length_";
    case DebugField::vertical_border_spacing_:
        return "vertical_border_spacing_";
    case DebugField::view_timeline_axis_:
        return "view_timeline_axis_";
    case DebugField::view_timeline_inset_:
        return "view_timeline_inset_";
    case DebugField::view_timeline_name_:
        return "view_timeline_name_";
    case DebugField::viewport_unit_flags_:
        return "viewport_unit_flags_";
    case DebugField::visibility_:
        return "visibility_";
    case DebugField::visibility_is_inherited_:
        return "visibility_is_inherited_";
    case DebugField::white_space_:
        return "white_space_";
    case DebugField::widows_:
        return "widows_";
    case DebugField::width_:
        return "width_";
    case DebugField::will_change_contents_:
        return "will_change_contents_";
    case DebugField::will_change_properties_:
        return "will_change_properties_";
    case DebugField::will_change_scroll_position_:
        return "will_change_scroll_position_";
    case DebugField::word_break_:
        return "word_break_";
    case DebugField::writing_mode_:
        return "writing_mode_";
    case DebugField::x_:
        return "x_";
    case DebugField::y_:
        return "y_";
    case DebugField::z_index_:
        return "z_index_";
    case DebugField::zoom_:
        return "zoom_";
    }
}

Vector<ComputedStyleBase::DebugField> ComputedStyleBase::DebugDiffFields(const ComputedStyleBase& o) const
{
    Vector<DebugField> diff;
    // Group: font
    if (!(inherited_data_->font_data_->font_ == o.inherited_data_->font_data_->font_))
        diff.push_back(DebugField::font_);

    // Group: inherited
    if (!(base::ValuesEquivalent(inherited_data_->inherited_variables_, o.inherited_data_->inherited_variables_)))
        diff.push_back(DebugField::inherited_variables_);
    if (!(inherited_data_->line_height_ == o.inherited_data_->line_height_))
        diff.push_back(DebugField::line_height_);
    if (!(inherited_data_->text_autosizing_multiplier_ == o.inherited_data_->text_autosizing_multiplier_))
        diff.push_back(DebugField::text_autosizing_multiplier_);
    if (!(inherited_data_->color_ == o.inherited_data_->color_))
        diff.push_back(DebugField::color_);
    if (!(inherited_data_->internal_visited_color_ == o.inherited_data_->internal_visited_color_))
        diff.push_back(DebugField::internal_visited_color_);
    if (!(inherited_data_->horizontal_border_spacing_ == o.inherited_data_->horizontal_border_spacing_))
        diff.push_back(DebugField::horizontal_border_spacing_);
    if (!(inherited_data_->vertical_border_spacing_ == o.inherited_data_->vertical_border_spacing_))
        diff.push_back(DebugField::vertical_border_spacing_);
    if (!(inherited_data_->color_is_current_color_ == o.inherited_data_->color_is_current_color_))
        diff.push_back(DebugField::color_is_current_color_);
    if (!(inherited_data_->in_forced_colors_mode_ == o.inherited_data_->in_forced_colors_mode_))
        diff.push_back(DebugField::in_forced_colors_mode_);
    if (!(inherited_data_->internal_visited_color_is_current_color_ == o.inherited_data_->internal_visited_color_is_current_color_))
        diff.push_back(DebugField::internal_visited_color_is_current_color_);

    // Group: inherited_forced_colors
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_color_))
        diff.push_back(DebugField::internal_forced_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_->internal_forced_visited_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_forced_colors_data_
                   ->internal_forced_visited_color_))
        diff.push_back(DebugField::internal_forced_visited_color_);

    // Group: inherited_visited
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_emphasis_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                   ->internal_visited_text_emphasis_color_))
        diff.push_back(DebugField::internal_visited_text_emphasis_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_fill_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_fill_color_))
        diff.push_back(DebugField::internal_visited_text_fill_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_text_stroke_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_
                   ->internal_visited_text_stroke_color_))
        diff.push_back(DebugField::internal_visited_text_stroke_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_caret_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->inherited_visited_data_->internal_visited_caret_color_))
        diff.push_back(DebugField::internal_visited_caret_color_);

    // Group: rare-inherited-usage-less-than-64-percent-sub
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_custom_mark_))
        diff.push_back(DebugField::text_emphasis_custom_mark_);
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->applied_text_decorations_,
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->applied_text_decorations_)))
        diff.push_back(DebugField::applied_text_decorations_);
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_,
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->highlight_data_)))
        diff.push_back(DebugField::highlight_data_);
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_,
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->initial_data_)))
        diff.push_back(DebugField::initial_data_);
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_,
            o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->cursor_data_)))
        diff.push_back(DebugField::cursor_data_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_zoom_))
        diff.push_back(DebugField::effective_zoom_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->accent_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->accent_color_))
        diff.push_back(DebugField::accent_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->hyphenate_limit_chars_))
        diff.push_back(DebugField::hyphenate_limit_chars_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->line_height_step_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->line_height_step_))
        diff.push_back(DebugField::line_height_step_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->effective_touch_action_))
        diff.push_back(DebugField::effective_touch_action_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_mark_))
        diff.push_back(DebugField::text_emphasis_mark_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->has_line_if_empty_))
        diff.push_back(DebugField::has_line_if_empty_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_is_sticky_))
        diff.push_back(DebugField::subtree_is_sticky_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->subtree_will_change_contents_))
        diff.push_back(DebugField::subtree_will_change_contents_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_64_percent_sub_data_->text_emphasis_fill_))
        diff.push_back(DebugField::text_emphasis_fill_);

    // Group: rare-inherited-usage-less-than-100-percent
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->text_underline_offset_))
        diff.push_back(DebugField::text_underline_offset_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->tap_highlight_color_))
        diff.push_back(DebugField::tap_highlight_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_depth_))
        diff.push_back(DebugField::math_depth_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_shift_))
        diff.push_back(DebugField::math_shift_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->math_style_))
        diff.push_back(DebugField::math_style_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->respect_image_orientation_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->respect_image_orientation_))
        diff.push_back(DebugField::respect_image_orientation_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->ruby_position_
            == o.rare_inherited_usage_less_than_64_percent_data_->rare_inherited_usage_less_than_100_percent_data_->ruby_position_))
        diff.push_back(DebugField::ruby_position_);

    // Group: rare-inherited-usage-less-than-64-percent
    if (!(rare_inherited_usage_less_than_64_percent_data_->color_scheme_ == o.rare_inherited_usage_less_than_64_percent_data_->color_scheme_))
        diff.push_back(DebugField::color_scheme_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_ == o.rare_inherited_usage_less_than_64_percent_data_->hyphenation_string_))
        diff.push_back(DebugField::hyphenation_string_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->highlight_ == o.rare_inherited_usage_less_than_64_percent_data_->highlight_))
        diff.push_back(DebugField::highlight_);
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->quotes_, o.rare_inherited_usage_less_than_64_percent_data_->quotes_)))
        diff.push_back(DebugField::quotes_);
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->text_shadow_, o.rare_inherited_usage_less_than_64_percent_data_->text_shadow_)))
        diff.push_back(DebugField::text_shadow_);
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->list_style_image_, o.rare_inherited_usage_less_than_64_percent_data_->list_style_image_)))
        diff.push_back(DebugField::list_style_image_);
    if (!(base::ValuesEquivalent(rare_inherited_usage_less_than_64_percent_data_->list_style_type_, o.rare_inherited_usage_less_than_64_percent_data_->list_style_type_)))
        diff.push_back(DebugField::list_style_type_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_decoration_thickness_ == o.rare_inherited_usage_less_than_64_percent_data_->text_decoration_thickness_))
        diff.push_back(DebugField::text_decoration_thickness_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_indent_ == o.rare_inherited_usage_less_than_64_percent_data_->text_indent_))
        diff.push_back(DebugField::text_indent_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_ == o.rare_inherited_usage_less_than_64_percent_data_->text_size_adjust_))
        diff.push_back(DebugField::text_size_adjust_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->tab_size_ == o.rare_inherited_usage_less_than_64_percent_data_->tab_size_))
        diff.push_back(DebugField::tab_size_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_ == o.rare_inherited_usage_less_than_64_percent_data_->text_stroke_width_))
        diff.push_back(DebugField::text_stroke_width_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_ == o.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_color_))
        diff.push_back(DebugField::text_emphasis_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_fill_color_ == o.rare_inherited_usage_less_than_64_percent_data_->text_fill_color_))
        diff.push_back(DebugField::text_fill_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_ == o.rare_inherited_usage_less_than_64_percent_data_->text_stroke_color_))
        diff.push_back(DebugField::text_stroke_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->caret_color_ == o.rare_inherited_usage_less_than_64_percent_data_->caret_color_))
        diff.push_back(DebugField::caret_color_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->orphans_ == o.rare_inherited_usage_less_than_64_percent_data_->orphans_))
        diff.push_back(DebugField::orphans_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->widows_ == o.rare_inherited_usage_less_than_64_percent_data_->widows_))
        diff.push_back(DebugField::widows_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_underline_position_ == o.rare_inherited_usage_less_than_64_percent_data_->text_underline_position_))
        diff.push_back(DebugField::text_underline_position_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->image_rendering_ == o.rare_inherited_usage_less_than_64_percent_data_->image_rendering_))
        diff.push_back(DebugField::image_rendering_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->line_break_ == o.rare_inherited_usage_less_than_64_percent_data_->line_break_))
        diff.push_back(DebugField::line_break_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->speak_ == o.rare_inherited_usage_less_than_64_percent_data_->speak_))
        diff.push_back(DebugField::speak_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_align_last_ == o.rare_inherited_usage_less_than_64_percent_data_->text_align_last_))
        diff.push_back(DebugField::text_align_last_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_ == o.rare_inherited_usage_less_than_64_percent_data_->forced_color_adjust_))
        diff.push_back(DebugField::forced_color_adjust_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->hyphens_ == o.rare_inherited_usage_less_than_64_percent_data_->hyphens_))
        diff.push_back(DebugField::hyphens_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_ == o.rare_inherited_usage_less_than_64_percent_data_->overflow_wrap_))
        diff.push_back(DebugField::overflow_wrap_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_ == o.rare_inherited_usage_less_than_64_percent_data_->text_emphasis_position_))
        diff.push_back(DebugField::text_emphasis_position_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_orientation_ == o.rare_inherited_usage_less_than_64_percent_data_->text_orientation_))
        diff.push_back(DebugField::text_orientation_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_security_ == o.rare_inherited_usage_less_than_64_percent_data_->text_security_))
        diff.push_back(DebugField::text_security_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->user_modify_ == o.rare_inherited_usage_less_than_64_percent_data_->user_modify_))
        diff.push_back(DebugField::user_modify_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->user_select_ == o.rare_inherited_usage_less_than_64_percent_data_->user_select_))
        diff.push_back(DebugField::user_select_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->word_break_ == o.rare_inherited_usage_less_than_64_percent_data_->word_break_))
        diff.push_back(DebugField::word_break_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_combine_ == o.rare_inherited_usage_less_than_64_percent_data_->text_combine_))
        diff.push_back(DebugField::text_combine_);
    if (!(rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_ == o.rare_inherited_usage_less_than_64_percent_data_->text_decoration_skip_ink_))
        diff.push_back(DebugField::text_decoration_skip_ink_);

    // Group: visual
    if (!(visual_data_->clip_ == o.visual_data_->clip_))
        diff.push_back(DebugField::clip_);
    if (!(visual_data_->zoom_ == o.visual_data_->zoom_))
        diff.push_back(DebugField::zoom_);
    if (!(visual_data_->text_decoration_line_ == o.visual_data_->text_decoration_line_))
        diff.push_back(DebugField::text_decoration_line_);
    if (!(visual_data_->has_auto_clip_ == o.visual_data_->has_auto_clip_))
        diff.push_back(DebugField::has_auto_clip_);
    if (!(visual_data_->has_clip_path_ == o.visual_data_->has_clip_path_))
        diff.push_back(DebugField::has_clip_path_);

    // Group: rare-non-inherited-usage-less-than-100-percent
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->grid_auto_columns_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->grid_auto_columns_))
        diff.push_back(DebugField::grid_auto_columns_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->grid_auto_rows_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->grid_auto_rows_))
        diff.push_back(DebugField::grid_auto_rows_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->grid_column_end_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->grid_column_end_))
        diff.push_back(DebugField::grid_column_end_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->grid_column_start_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->grid_column_start_))
        diff.push_back(DebugField::grid_column_start_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->grid_row_end_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->grid_row_end_))
        diff.push_back(DebugField::grid_row_end_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->grid_row_start_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->grid_row_start_))
        diff.push_back(DebugField::grid_row_start_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->page_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->page_))
        diff.push_back(DebugField::page_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->clip_path_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->clip_path_)))
        diff.push_back(DebugField::clip_path_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->offset_path_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->offset_path_)))
        diff.push_back(DebugField::offset_path_);
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->rotate_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->rotate_)))
        diff.push_back(DebugField::rotate_);
    if (!(base::ValuesEquivalent(
            rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->scale_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->scale_)))
        diff.push_back(DebugField::scale_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->translate_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->translate_)))
        diff.push_back(DebugField::translate_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->box_reflect_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->box_reflect_)))
        diff.push_back(DebugField::box_reflect_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->backdrop_filter_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->backdrop_filter_)))
        diff.push_back(DebugField::backdrop_filter_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_
                                     ->rare_non_inherited_usage_less_than_100_percent_data_->shape_outside_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->shape_outside_)))
        diff.push_back(DebugField::shape_outside_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->column_gap_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->column_gap_))
        diff.push_back(DebugField::column_gap_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->row_gap_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->row_gap_))
        diff.push_back(DebugField::row_gap_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->offset_rotate_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->offset_rotate_))
        diff.push_back(DebugField::offset_rotate_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->object_position_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->object_position_))
        diff.push_back(DebugField::object_position_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->offset_anchor_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->offset_anchor_))
        diff.push_back(DebugField::offset_anchor_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->offset_position_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->offset_position_))
        diff.push_back(DebugField::offset_position_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->perspective_origin_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->perspective_origin_))
        diff.push_back(DebugField::perspective_origin_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->offset_distance_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->offset_distance_))
        diff.push_back(DebugField::offset_distance_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->scroll_padding_bottom_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->scroll_padding_bottom_))
        diff.push_back(DebugField::scroll_padding_bottom_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->scroll_padding_left_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->scroll_padding_left_))
        diff.push_back(DebugField::scroll_padding_left_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->scroll_padding_right_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->scroll_padding_right_))
        diff.push_back(DebugField::scroll_padding_right_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->scroll_padding_top_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->scroll_padding_top_))
        diff.push_back(DebugField::scroll_padding_top_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->shape_margin_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->shape_margin_))
        diff.push_back(DebugField::shape_margin_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->column_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->column_width_))
        diff.push_back(DebugField::column_width_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->perspective_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->perspective_))
        diff.push_back(DebugField::perspective_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->shape_image_threshold_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->shape_image_threshold_))
        diff.push_back(DebugField::shape_image_threshold_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->scroll_snap_type_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->scroll_snap_type_))
        diff.push_back(DebugField::scroll_snap_type_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->scroll_snap_align_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->scroll_snap_align_))
        diff.push_back(DebugField::scroll_snap_align_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->column_rule_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->column_rule_color_))
        diff.push_back(DebugField::column_rule_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->outline_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->outline_color_))
        diff.push_back(DebugField::outline_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->text_decoration_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->text_decoration_color_))
        diff.push_back(DebugField::text_decoration_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->column_rule_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->column_rule_width_))
        diff.push_back(DebugField::column_rule_width_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->box_ordinal_group_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->box_ordinal_group_))
        diff.push_back(DebugField::box_ordinal_group_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->column_count_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->column_count_))
        diff.push_back(DebugField::column_count_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->justify_items_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->justify_items_))
        diff.push_back(DebugField::justify_items_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->justify_self_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->justify_self_))
        diff.push_back(DebugField::justify_self_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->blend_mode_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->blend_mode_))
        diff.push_back(DebugField::blend_mode_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->contain_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->contain_))
        diff.push_back(DebugField::contain_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->column_rule_style_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->column_rule_style_))
        diff.push_back(DebugField::column_rule_style_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->grid_auto_flow_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->grid_auto_flow_))
        diff.push_back(DebugField::grid_auto_flow_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->text_decoration_style_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->text_decoration_style_))
        diff.push_back(DebugField::text_decoration_style_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->draggable_region_mode_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->draggable_region_mode_))
        diff.push_back(DebugField::draggable_region_mode_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->page_orientation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->page_orientation_))
        diff.push_back(DebugField::page_orientation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->scroll_behavior_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->scroll_behavior_))
        diff.push_back(DebugField::scroll_behavior_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->user_drag_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->user_drag_))
        diff.push_back(DebugField::user_drag_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->column_fill_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->column_fill_))
        diff.push_back(DebugField::column_fill_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->column_span_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->column_span_))
        diff.push_back(DebugField::column_span_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_->isolation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->isolation_))
        diff.push_back(DebugField::isolation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                ->transform_style_3d_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->rare_non_inherited_usage_less_than_100_percent_data_
                   ->transform_style_3d_))
        diff.push_back(DebugField::transform_style_3d_);

    // Group: rare-non-inherited-usage-less-than-22-percent
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->filter_)))
        diff.push_back(DebugField::filter_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_basis_))
        diff.push_back(DebugField::flex_basis_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_grow_))
        diff.push_back(DebugField::flex_grow_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->flex_shrink_))
        diff.push_back(DebugField::flex_shrink_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_flex_))
        diff.push_back(DebugField::box_flex_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_offset_))
        diff.push_back(DebugField::outline_offset_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_width_))
        diff.push_back(DebugField::outline_width_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->order_))
        diff.push_back(DebugField::order_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->line_clamp_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->line_clamp_))
        diff.push_back(DebugField::line_clamp_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_self_))
        diff.push_back(DebugField::align_self_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->align_content_))
        diff.push_back(DebugField::align_content_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->touch_action_))
        diff.push_back(DebugField::touch_action_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->outline_style_))
        diff.push_back(DebugField::outline_style_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_align_))
        diff.push_back(DebugField::box_align_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->object_fit_))
        diff.push_back(DebugField::object_fit_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->resize_))
        diff.push_back(DebugField::resize_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_pack_))
        diff.push_back(DebugField::box_pack_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->backface_visibility_))
        diff.push_back(DebugField::backface_visibility_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_22_percent_data_->box_orient_))
        diff.push_back(DebugField::box_orient_);

    // Group: grid
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_columns_))
        diff.push_back(DebugField::grid_template_columns_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->grid_template_rows_))
        diff.push_back(DebugField::grid_template_rows_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_column_lines_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_column_lines_))
        diff.push_back(DebugField::implicit_named_grid_column_lines_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_row_lines_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->implicit_named_grid_row_lines_))
        diff.push_back(DebugField::implicit_named_grid_row_lines_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_))
        diff.push_back(DebugField::named_grid_area_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_row_count_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_row_count_))
        diff.push_back(DebugField::named_grid_area_row_count_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_column_count_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->grid_data_->named_grid_area_column_count_))
        diff.push_back(DebugField::named_grid_area_column_count_);

    // Group: forced_colors
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_background_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_
                   ->internal_forced_background_color_))
        diff.push_back(DebugField::internal_forced_background_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_border_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_border_color_))
        diff.push_back(DebugField::internal_forced_border_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_outline_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->forced_colors_data_->internal_forced_outline_color_))
        diff.push_back(DebugField::internal_forced_outline_color_);

    // Group: visited
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_background_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_background_color_))
        diff.push_back(DebugField::internal_visited_background_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_bottom_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_border_bottom_color_))
        diff.push_back(DebugField::internal_visited_border_bottom_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_left_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_left_color_))
        diff.push_back(DebugField::internal_visited_border_left_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_right_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_right_color_))
        diff.push_back(DebugField::internal_visited_border_right_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_top_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_border_top_color_))
        diff.push_back(DebugField::internal_visited_border_top_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_column_rule_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_column_rule_color_))
        diff.push_back(DebugField::internal_visited_column_rule_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_outline_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_outline_color_))
        diff.push_back(DebugField::internal_visited_outline_color_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_->internal_visited_text_decoration_color_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->visited_data_
                   ->internal_visited_text_decoration_color_))
        diff.push_back(DebugField::internal_visited_text_decoration_color_);

    // Group: timeline
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_name_))
        diff.push_back(DebugField::view_timeline_name_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_axis_))
        diff.push_back(DebugField::view_timeline_axis_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->view_timeline_inset_))
        diff.push_back(DebugField::view_timeline_inset_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_name_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_name_))
        diff.push_back(DebugField::scroll_timeline_name_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_axis_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->timeline_data_->scroll_timeline_axis_))
        diff.push_back(DebugField::scroll_timeline_axis_);

    // Group: will-change
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_properties_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_properties_))
        diff.push_back(DebugField::will_change_properties_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_contents_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_contents_))
        diff.push_back(DebugField::will_change_contents_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_scroll_position_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->will_change_data_->will_change_scroll_position_))
        diff.push_back(DebugField::will_change_scroll_position_);

    // Group: math
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_baseline_))
        diff.push_back(DebugField::math_baseline_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_fraction_bar_thickness_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_fraction_bar_thickness_))
        diff.push_back(DebugField::math_fraction_bar_thickness_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_l_space_))
        diff.push_back(DebugField::math_l_space_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_r_space_))
        diff.push_back(DebugField::math_r_space_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_v_offset_))
        diff.push_back(DebugField::math_padded_v_offset_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_padded_depth_))
        diff.push_back(DebugField::math_padded_depth_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_min_size_))
        diff.push_back(DebugField::math_min_size_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->math_data_->math_max_size_))
        diff.push_back(DebugField::math_max_size_);

    // Group: rare-non-inherited-usage-less-than-14-percent-sub
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_name_))
        diff.push_back(DebugField::container_name_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_name_))
        diff.push_back(DebugField::anchor_name_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scroll_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->anchor_scroll_))
        diff.push_back(DebugField::anchor_scroll_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_transition_tag_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_transition_tag_))
        diff.push_back(DebugField::page_transition_tag_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_fallback_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->position_fallback_))
        diff.push_back(DebugField::position_fallback_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_visibility_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_visibility_))
        diff.push_back(DebugField::toggle_visibility_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_name_))
        diff.push_back(DebugField::display_layout_custom_name_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->display_layout_custom_parent_name_))
        diff.push_back(DebugField::display_layout_custom_parent_name_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->pseudo_argument_))
        diff.push_back(DebugField::pseudo_argument_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->object_view_box_)))
        diff.push_back(DebugField::object_view_box_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_group_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_group_)))
        diff.push_back(DebugField::toggle_group_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_root_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_root_)))
        diff.push_back(DebugField::toggle_root_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_trigger_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->toggle_trigger_)))
        diff.push_back(DebugField::toggle_trigger_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->custom_highlight_names_)))
        diff.push_back(DebugField::custom_highlight_names_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->counter_directives_)))
        diff.push_back(DebugField::counter_directives_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->animations_)))
        diff.push_back(DebugField::animations_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->transitions_)))
        diff.push_back(DebugField::transitions_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_,
            o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->non_inherited_variables_)))
        diff.push_back(DebugField::non_inherited_variables_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->callback_selectors_))
        diff.push_back(DebugField::callback_selectors_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_))
        diff.push_back(DebugField::mask_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->mask_box_image_))
        diff.push_back(DebugField::mask_box_image_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->overflow_clip_margin_))
        diff.push_back(DebugField::overflow_clip_margin_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->initial_letter_))
        diff.push_back(DebugField::initial_letter_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_))
        diff.push_back(DebugField::page_size_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_bottom_))
        diff.push_back(DebugField::scroll_margin_bottom_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_left_))
        diff.push_back(DebugField::scroll_margin_left_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_right_))
        diff.push_back(DebugField::scroll_margin_right_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_margin_top_))
        diff.push_back(DebugField::scroll_margin_top_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_appearance_))
        diff.push_back(DebugField::effective_appearance_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_customization_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scroll_customization_))
        diff.push_back(DebugField::scroll_customization_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->container_type_))
        diff.push_back(DebugField::container_type_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->page_size_type_))
        diff.push_back(DebugField::page_size_type_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->scrollbar_width_))
        diff.push_back(DebugField::scrollbar_width_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_self_block_center_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->align_self_block_center_))
        diff.push_back(DebugField::align_self_block_center_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->compositable_paint_animation_changed_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->compositable_paint_animation_changed_))
        diff.push_back(DebugField::compositable_paint_animation_changed_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_size_container_queries_))
        diff.push_back(DebugField::depends_on_size_container_queries_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_style_container_queries_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->depends_on_style_container_queries_))
        diff.push_back(DebugField::depends_on_style_container_queries_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->effective_z_index_zero_))
        diff.push_back(DebugField::effective_z_index_zero_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->first_line_depends_on_size_container_queries_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->first_line_depends_on_size_container_queries_))
        diff.push_back(DebugField::first_line_depends_on_size_container_queries_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_count_))
        diff.push_back(DebugField::has_auto_column_count_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_auto_column_width_))
        diff.push_back(DebugField::has_auto_column_width_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_backdrop_filter_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_backdrop_filter_animation_))
        diff.push_back(DebugField::has_current_backdrop_filter_animation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_background_color_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_background_color_animation_))
        diff.push_back(DebugField::has_current_background_color_animation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_clip_path_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_clip_path_animation_))
        diff.push_back(DebugField::has_current_clip_path_animation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_filter_animation_))
        diff.push_back(DebugField::has_current_filter_animation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_opacity_animation_))
        diff.push_back(DebugField::has_current_opacity_animation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_rotate_animation_))
        diff.push_back(DebugField::has_current_rotate_animation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_scale_animation_))
        diff.push_back(DebugField::has_current_scale_animation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_transform_animation_))
        diff.push_back(DebugField::has_current_transform_animation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_current_translate_animation_))
        diff.push_back(DebugField::has_current_translate_animation_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_x_visible_))
        diff.push_back(DebugField::has_explicit_overflow_x_visible_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->has_explicit_overflow_y_visible_))
        diff.push_back(DebugField::has_explicit_overflow_y_visible_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->is_secondary_body_element_))
        diff.push_back(DebugField::is_secondary_body_element_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->outline_style_is_auto_))
        diff.push_back(DebugField::outline_style_is_auto_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_->requires_accelerated_compositing_for_external_reasons_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->rare_non_inherited_usage_less_than_14_percent_sub_data_
                   ->requires_accelerated_compositing_for_external_reasons_))
        diff.push_back(DebugField::requires_accelerated_compositing_for_external_reasons_);

    // Group: rare-non-inherited-usage-less-than-14-percent
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_ == o.rare_non_inherited_usage_less_than_14_percent_data_->transform_))
        diff.push_back(DebugField::transform_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_, o.rare_non_inherited_usage_less_than_14_percent_data_->box_shadow_)))
        diff.push_back(DebugField::box_shadow_);
    if (!(base::ValuesEquivalent(rare_non_inherited_usage_less_than_14_percent_data_->content_, o.rare_non_inherited_usage_less_than_14_percent_data_->content_)))
        diff.push_back(DebugField::content_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_ == o.rare_non_inherited_usage_less_than_14_percent_data_->transform_origin_))
        diff.push_back(DebugField::transform_origin_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->opacity_ == o.rare_non_inherited_usage_less_than_14_percent_data_->opacity_))
        diff.push_back(DebugField::opacity_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->align_items_ == o.rare_non_inherited_usage_less_than_14_percent_data_->align_items_))
        diff.push_back(DebugField::align_items_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->justify_content_ == o.rare_non_inherited_usage_less_than_14_percent_data_->justify_content_))
        diff.push_back(DebugField::justify_content_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->appearance_ == o.rare_non_inherited_usage_less_than_14_percent_data_->appearance_))
        diff.push_back(DebugField::appearance_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_ == o.rare_non_inherited_usage_less_than_14_percent_data_->flex_direction_))
        diff.push_back(DebugField::flex_direction_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_ == o.rare_non_inherited_usage_less_than_14_percent_data_->flex_wrap_))
        diff.push_back(DebugField::flex_wrap_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->is_stacking_context_without_containment_
            == o.rare_non_inherited_usage_less_than_14_percent_data_->is_stacking_context_without_containment_))
        diff.push_back(DebugField::is_stacking_context_without_containment_);
    if (!(rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_ == o.rare_non_inherited_usage_less_than_14_percent_data_->text_overflow_))
        diff.push_back(DebugField::text_overflow_);

    // Group: misc
    if (!(svg_data_->misc_data_->baseline_shift_ == o.svg_data_->misc_data_->baseline_shift_))
        diff.push_back(DebugField::baseline_shift_);
    if (!(svg_data_->misc_data_->flood_opacity_ == o.svg_data_->misc_data_->flood_opacity_))
        diff.push_back(DebugField::flood_opacity_);
    if (!(svg_data_->misc_data_->flood_color_ == o.svg_data_->misc_data_->flood_color_))
        diff.push_back(DebugField::flood_color_);
    if (!(svg_data_->misc_data_->lighting_color_ == o.svg_data_->misc_data_->lighting_color_))
        diff.push_back(DebugField::lighting_color_);
    if (!(svg_data_->misc_data_->baseline_shift_type_ == o.svg_data_->misc_data_->baseline_shift_type_))
        diff.push_back(DebugField::baseline_shift_type_);

    // Group: geometry
    if (!(base::ValuesEquivalent(svg_data_->geometry_data_->d_, o.svg_data_->geometry_data_->d_)))
        diff.push_back(DebugField::d_);
    if (!(svg_data_->geometry_data_->cx_ == o.svg_data_->geometry_data_->cx_))
        diff.push_back(DebugField::cx_);
    if (!(svg_data_->geometry_data_->cy_ == o.svg_data_->geometry_data_->cy_))
        diff.push_back(DebugField::cy_);
    if (!(svg_data_->geometry_data_->r_ == o.svg_data_->geometry_data_->r_))
        diff.push_back(DebugField::r_);
    if (!(svg_data_->geometry_data_->rx_ == o.svg_data_->geometry_data_->rx_))
        diff.push_back(DebugField::rx_);
    if (!(svg_data_->geometry_data_->ry_ == o.svg_data_->geometry_data_->ry_))
        diff.push_back(DebugField::ry_);
    if (!(svg_data_->geometry_data_->x_ == o.svg_data_->geometry_data_->x_))
        diff.push_back(DebugField::x_);
    if (!(svg_data_->geometry_data_->y_ == o.svg_data_->geometry_data_->y_))
        diff.push_back(DebugField::y_);

    // Group: fill
    if (!(svg_data_->fill_data_->fill_paint_ == o.svg_data_->fill_data_->fill_paint_))
        diff.push_back(DebugField::fill_paint_);
    if (!(svg_data_->fill_data_->internal_visited_fill_paint_ == o.svg_data_->fill_data_->internal_visited_fill_paint_))
        diff.push_back(DebugField::internal_visited_fill_paint_);
    if (!(svg_data_->fill_data_->fill_opacity_ == o.svg_data_->fill_data_->fill_opacity_))
        diff.push_back(DebugField::fill_opacity_);

    // Group: stroke
    if (!(base::ValuesEquivalent(svg_data_->stroke_data_->stroke_dash_array_, o.svg_data_->stroke_data_->stroke_dash_array_)))
        diff.push_back(DebugField::stroke_dash_array_);
    if (!(svg_data_->stroke_data_->internal_visited_stroke_paint_ == o.svg_data_->stroke_data_->internal_visited_stroke_paint_))
        diff.push_back(DebugField::internal_visited_stroke_paint_);
    if (!(svg_data_->stroke_data_->stroke_paint_ == o.svg_data_->stroke_data_->stroke_paint_))
        diff.push_back(DebugField::stroke_paint_);
    if (!(svg_data_->stroke_data_->stroke_dash_offset_ == o.svg_data_->stroke_data_->stroke_dash_offset_))
        diff.push_back(DebugField::stroke_dash_offset_);
    if (!(svg_data_->stroke_data_->stroke_width_ == o.svg_data_->stroke_data_->stroke_width_))
        diff.push_back(DebugField::stroke_width_);
    if (!(svg_data_->stroke_data_->stroke_miter_limit_ == o.svg_data_->stroke_data_->stroke_miter_limit_))
        diff.push_back(DebugField::stroke_miter_limit_);
    if (!(svg_data_->stroke_data_->stroke_opacity_ == o.svg_data_->stroke_data_->stroke_opacity_))
        diff.push_back(DebugField::stroke_opacity_);
    if (!(svg_data_->stroke_data_->cap_style_ == o.svg_data_->stroke_data_->cap_style_))
        diff.push_back(DebugField::cap_style_);
    if (!(svg_data_->stroke_data_->join_style_ == o.svg_data_->stroke_data_->join_style_))
        diff.push_back(DebugField::join_style_);

    // Group: inherited_resources
    if (!(base::ValuesEquivalent(svg_data_->inherited_resources_data_->marker_end_resource_, o.svg_data_->inherited_resources_data_->marker_end_resource_)))
        diff.push_back(DebugField::marker_end_resource_);
    if (!(base::ValuesEquivalent(svg_data_->inherited_resources_data_->marker_mid_resource_, o.svg_data_->inherited_resources_data_->marker_mid_resource_)))
        diff.push_back(DebugField::marker_mid_resource_);
    if (!(base::ValuesEquivalent(svg_data_->inherited_resources_data_->marker_start_resource_, o.svg_data_->inherited_resources_data_->marker_start_resource_)))
        diff.push_back(DebugField::marker_start_resource_);

    // Group: stop
    if (!(svg_data_->stop_data_->stop_opacity_ == o.svg_data_->stop_data_->stop_opacity_))
        diff.push_back(DebugField::stop_opacity_);
    if (!(svg_data_->stop_data_->stop_color_ == o.svg_data_->stop_data_->stop_color_))
        diff.push_back(DebugField::stop_color_);

    // Group: svg
    if (!(base::ValuesEquivalent(svg_data_->masker_resource_, o.svg_data_->masker_resource_)))
        diff.push_back(DebugField::masker_resource_);
    if (!(svg_data_->alignment_baseline_ == o.svg_data_->alignment_baseline_))
        diff.push_back(DebugField::alignment_baseline_);
    if (!(svg_data_->css_dominant_baseline_ == o.svg_data_->css_dominant_baseline_))
        diff.push_back(DebugField::css_dominant_baseline_);
    if (!(svg_data_->dominant_baseline_ == o.svg_data_->dominant_baseline_))
        diff.push_back(DebugField::dominant_baseline_);
    if (!(svg_data_->paint_order_ == o.svg_data_->paint_order_))
        diff.push_back(DebugField::paint_order_);
    if (!(svg_data_->buffered_rendering_ == o.svg_data_->buffered_rendering_))
        diff.push_back(DebugField::buffered_rendering_);
    if (!(svg_data_->color_interpolation_ == o.svg_data_->color_interpolation_))
        diff.push_back(DebugField::color_interpolation_);
    if (!(svg_data_->color_interpolation_filters_ == o.svg_data_->color_interpolation_filters_))
        diff.push_back(DebugField::color_interpolation_filters_);
    if (!(svg_data_->color_rendering_ == o.svg_data_->color_rendering_))
        diff.push_back(DebugField::color_rendering_);
    if (!(svg_data_->shape_rendering_ == o.svg_data_->shape_rendering_))
        diff.push_back(DebugField::shape_rendering_);
    if (!(svg_data_->text_anchor_ == o.svg_data_->text_anchor_))
        diff.push_back(DebugField::text_anchor_);
    if (!(svg_data_->clip_rule_ == o.svg_data_->clip_rule_))
        diff.push_back(DebugField::clip_rule_);
    if (!(svg_data_->fill_rule_ == o.svg_data_->fill_rule_))
        diff.push_back(DebugField::fill_rule_);
    if (!(svg_data_->mask_type_ == o.svg_data_->mask_type_))
        diff.push_back(DebugField::mask_type_);
    if (!(svg_data_->vector_effect_ == o.svg_data_->vector_effect_))
        diff.push_back(DebugField::vector_effect_);

    // Group: box
    if (!(box_data_->aspect_ratio_ == o.box_data_->aspect_ratio_))
        diff.push_back(DebugField::aspect_ratio_);
    if (!(box_data_->contain_intrinsic_height_ == o.box_data_->contain_intrinsic_height_))
        diff.push_back(DebugField::contain_intrinsic_height_);
    if (!(box_data_->contain_intrinsic_width_ == o.box_data_->contain_intrinsic_width_))
        diff.push_back(DebugField::contain_intrinsic_width_);
    if (!(box_data_->height_ == o.box_data_->height_))
        diff.push_back(DebugField::height_);
    if (!(box_data_->max_height_ == o.box_data_->max_height_))
        diff.push_back(DebugField::max_height_);
    if (!(box_data_->max_width_ == o.box_data_->max_width_))
        diff.push_back(DebugField::max_width_);
    if (!(box_data_->min_height_ == o.box_data_->min_height_))
        diff.push_back(DebugField::min_height_);
    if (!(box_data_->min_width_ == o.box_data_->min_width_))
        diff.push_back(DebugField::min_width_);
    if (!(box_data_->width_ == o.box_data_->width_))
        diff.push_back(DebugField::width_);
    if (!(box_data_->vertical_align_length_ == o.box_data_->vertical_align_length_))
        diff.push_back(DebugField::vertical_align_length_);
    if (!(box_data_->z_index_ == o.box_data_->z_index_))
        diff.push_back(DebugField::z_index_);
    if (!(box_data_->box_decoration_break_ == o.box_data_->box_decoration_break_))
        diff.push_back(DebugField::box_decoration_break_);
    if (!(box_data_->box_sizing_ == o.box_data_->box_sizing_))
        diff.push_back(DebugField::box_sizing_);
    if (!(box_data_->has_auto_z_index_ == o.box_data_->has_auto_z_index_))
        diff.push_back(DebugField::has_auto_z_index_);

    // Group: background
    if (!(background_data_->background_ == o.background_data_->background_))
        diff.push_back(DebugField::background_);
    if (!(background_data_->background_color_ == o.background_data_->background_color_))
        diff.push_back(DebugField::background_color_);

    // Group: surround
    if (!(surround_data_->border_image_ == o.surround_data_->border_image_))
        diff.push_back(DebugField::border_image_);
    if (!(surround_data_->border_bottom_left_radius_ == o.surround_data_->border_bottom_left_radius_))
        diff.push_back(DebugField::border_bottom_left_radius_);
    if (!(surround_data_->border_bottom_right_radius_ == o.surround_data_->border_bottom_right_radius_))
        diff.push_back(DebugField::border_bottom_right_radius_);
    if (!(surround_data_->border_top_left_radius_ == o.surround_data_->border_top_left_radius_))
        diff.push_back(DebugField::border_top_left_radius_);
    if (!(surround_data_->border_top_right_radius_ == o.surround_data_->border_top_right_radius_))
        diff.push_back(DebugField::border_top_right_radius_);
    if (!(surround_data_->bottom_ == o.surround_data_->bottom_))
        diff.push_back(DebugField::bottom_);
    if (!(surround_data_->left_ == o.surround_data_->left_))
        diff.push_back(DebugField::left_);
    if (!(surround_data_->margin_bottom_ == o.surround_data_->margin_bottom_))
        diff.push_back(DebugField::margin_bottom_);
    if (!(surround_data_->margin_left_ == o.surround_data_->margin_left_))
        diff.push_back(DebugField::margin_left_);
    if (!(surround_data_->margin_right_ == o.surround_data_->margin_right_))
        diff.push_back(DebugField::margin_right_);
    if (!(surround_data_->margin_top_ == o.surround_data_->margin_top_))
        diff.push_back(DebugField::margin_top_);
    if (!(surround_data_->padding_bottom_ == o.surround_data_->padding_bottom_))
        diff.push_back(DebugField::padding_bottom_);
    if (!(surround_data_->padding_left_ == o.surround_data_->padding_left_))
        diff.push_back(DebugField::padding_left_);
    if (!(surround_data_->padding_right_ == o.surround_data_->padding_right_))
        diff.push_back(DebugField::padding_right_);
    if (!(surround_data_->padding_top_ == o.surround_data_->padding_top_))
        diff.push_back(DebugField::padding_top_);
    if (!(surround_data_->right_ == o.surround_data_->right_))
        diff.push_back(DebugField::right_);
    if (!(surround_data_->top_ == o.surround_data_->top_))
        diff.push_back(DebugField::top_);
    if (!(surround_data_->border_bottom_color_ == o.surround_data_->border_bottom_color_))
        diff.push_back(DebugField::border_bottom_color_);
    if (!(surround_data_->border_left_color_ == o.surround_data_->border_left_color_))
        diff.push_back(DebugField::border_left_color_);
    if (!(surround_data_->border_right_color_ == o.surround_data_->border_right_color_))
        diff.push_back(DebugField::border_right_color_);
    if (!(surround_data_->border_top_color_ == o.surround_data_->border_top_color_))
        diff.push_back(DebugField::border_top_color_);
    if (!(surround_data_->border_bottom_width_ == o.surround_data_->border_bottom_width_))
        diff.push_back(DebugField::border_bottom_width_);
    if (!(surround_data_->border_left_width_ == o.surround_data_->border_left_width_))
        diff.push_back(DebugField::border_left_width_);
    if (!(surround_data_->border_right_width_ == o.surround_data_->border_right_width_))
        diff.push_back(DebugField::border_right_width_);
    if (!(surround_data_->border_top_width_ == o.surround_data_->border_top_width_))
        diff.push_back(DebugField::border_top_width_);
    if (!(surround_data_->border_bottom_style_ == o.surround_data_->border_bottom_style_))
        diff.push_back(DebugField::border_bottom_style_);
    if (!(surround_data_->border_left_style_ == o.surround_data_->border_left_style_))
        diff.push_back(DebugField::border_left_style_);
    if (!(surround_data_->border_right_style_ == o.surround_data_->border_right_style_))
        diff.push_back(DebugField::border_right_style_);
    if (!(surround_data_->border_top_style_ == o.surround_data_->border_top_style_))
        diff.push_back(DebugField::border_top_style_);

    // Group: None
    if (!(white_space_ == o.white_space_))
        diff.push_back(DebugField::white_space_);
    if (!(cursor_ == o.cursor_))
        diff.push_back(DebugField::cursor_);
    if (!(display_ == o.display_))
        diff.push_back(DebugField::display_);
    if (!(original_display_ == o.original_display_))
        diff.push_back(DebugField::original_display_);
    if (!(break_after_ == o.break_after_))
        diff.push_back(DebugField::break_after_);
    if (!(break_before_ == o.break_before_))
        diff.push_back(DebugField::break_before_);
    if (!(pointer_events_ == o.pointer_events_))
        diff.push_back(DebugField::pointer_events_);
    if (!(scrollbar_gutter_ == o.scrollbar_gutter_))
        diff.push_back(DebugField::scrollbar_gutter_);
    if (!(text_align_ == o.text_align_))
        diff.push_back(DebugField::text_align_);
    if (!(break_inside_ == o.break_inside_))
        diff.push_back(DebugField::break_inside_);
    if (!(vertical_align_ == o.vertical_align_))
        diff.push_back(DebugField::vertical_align_);
    if (!(clear_ == o.clear_))
        diff.push_back(DebugField::clear_);
    if (!(floating_ == o.floating_))
        diff.push_back(DebugField::floating_);
    if (!(overflow_x_ == o.overflow_x_))
        diff.push_back(DebugField::overflow_x_);
    if (!(overflow_y_ == o.overflow_y_))
        diff.push_back(DebugField::overflow_y_);
    if (!(position_ == o.position_))
        diff.push_back(DebugField::position_);
    if (!(text_transform_ == o.text_transform_))
        diff.push_back(DebugField::text_transform_);
    if (!(unicode_bidi_ == o.unicode_bidi_))
        diff.push_back(DebugField::unicode_bidi_);
    if (!(content_visibility_ == o.content_visibility_))
        diff.push_back(DebugField::content_visibility_);
    if (!(inside_link_ == o.inside_link_))
        diff.push_back(DebugField::inside_link_);
    if (!(overflow_anchor_ == o.overflow_anchor_))
        diff.push_back(DebugField::overflow_anchor_);
    if (!(overscroll_behavior_x_ == o.overscroll_behavior_x_))
        diff.push_back(DebugField::overscroll_behavior_x_);
    if (!(overscroll_behavior_y_ == o.overscroll_behavior_y_))
        diff.push_back(DebugField::overscroll_behavior_y_);
    if (!(viewport_unit_flags_ == o.viewport_unit_flags_))
        diff.push_back(DebugField::viewport_unit_flags_);
    if (!(visibility_ == o.visibility_))
        diff.push_back(DebugField::visibility_);
    if (!(writing_mode_ == o.writing_mode_))
        diff.push_back(DebugField::writing_mode_);
    if (!(border_collapse_ == o.border_collapse_))
        diff.push_back(DebugField::border_collapse_);
    if (!(border_collapse_is_inherited_ == o.border_collapse_is_inherited_))
        diff.push_back(DebugField::border_collapse_is_inherited_);
    if (!(box_direction_ == o.box_direction_))
        diff.push_back(DebugField::box_direction_);
    if (!(box_direction_is_inherited_ == o.box_direction_is_inherited_))
        diff.push_back(DebugField::box_direction_is_inherited_);
    if (!(caption_side_ == o.caption_side_))
        diff.push_back(DebugField::caption_side_);
    if (!(caption_side_is_inherited_ == o.caption_side_is_inherited_))
        diff.push_back(DebugField::caption_side_is_inherited_);
    if (!(color_is_inherited_ == o.color_is_inherited_))
        diff.push_back(DebugField::color_is_inherited_);
    if (!(direction_ == o.direction_))
        diff.push_back(DebugField::direction_);
    if (!(empty_cells_ == o.empty_cells_))
        diff.push_back(DebugField::empty_cells_);
    if (!(empty_cells_is_inherited_ == o.empty_cells_is_inherited_))
        diff.push_back(DebugField::empty_cells_is_inherited_);
    if (!(has_author_background_ == o.has_author_background_))
        diff.push_back(DebugField::has_author_background_);
    if (!(has_author_border_ == o.has_author_border_))
        diff.push_back(DebugField::has_author_border_);
    if (!(has_author_border_radius_ == o.has_author_border_radius_))
        diff.push_back(DebugField::has_author_border_radius_);
    if (!(has_author_highlight_colors_ == o.has_author_highlight_colors_))
        diff.push_back(DebugField::has_author_highlight_colors_);
    if (!(has_explicit_inheritance_ == o.has_explicit_inheritance_))
        diff.push_back(DebugField::has_explicit_inheritance_);
    if (!(has_simple_underline_ == o.has_simple_underline_))
        diff.push_back(DebugField::has_simple_underline_);
    if (!(inside_fragmentation_context_with_nondeterministic_engine_ == o.inside_fragmentation_context_with_nondeterministic_engine_))
        diff.push_back(DebugField::inside_fragmentation_context_with_nondeterministic_engine_);
    if (!(is_inert_ == o.is_inert_))
        diff.push_back(DebugField::is_inert_);
    if (!(is_inert_is_inherited_ == o.is_inert_is_inherited_))
        diff.push_back(DebugField::is_inert_is_inherited_);
    if (!(list_style_position_ == o.list_style_position_))
        diff.push_back(DebugField::list_style_position_);
    if (!(list_style_position_is_inherited_ == o.list_style_position_is_inherited_))
        diff.push_back(DebugField::list_style_position_is_inherited_);
    if (!(origin_trial_test_property_ == o.origin_trial_test_property_))
        diff.push_back(DebugField::origin_trial_test_property_);
    if (!(pointer_events_is_inherited_ == o.pointer_events_is_inherited_))
        diff.push_back(DebugField::pointer_events_is_inherited_);
    if (!(print_color_adjust_ == o.print_color_adjust_))
        diff.push_back(DebugField::print_color_adjust_);
    if (!(rtl_ordering_ == o.rtl_ordering_))
        diff.push_back(DebugField::rtl_ordering_);
    if (!(rtl_ordering_is_inherited_ == o.rtl_ordering_is_inherited_))
        diff.push_back(DebugField::rtl_ordering_is_inherited_);
    if (!(scroll_snap_stop_ == o.scroll_snap_stop_))
        diff.push_back(DebugField::scroll_snap_stop_);
    if (!(should_ignore_overflow_property_for_inline_block_baseline_ == o.should_ignore_overflow_property_for_inline_block_baseline_))
        diff.push_back(DebugField::should_ignore_overflow_property_for_inline_block_baseline_);
    if (!(skips_contents_ == o.skips_contents_))
        diff.push_back(DebugField::skips_contents_);
    if (!(table_layout_ == o.table_layout_))
        diff.push_back(DebugField::table_layout_);
    if (!(text_transform_is_inherited_ == o.text_transform_is_inherited_))
        diff.push_back(DebugField::text_transform_is_inherited_);
    if (!(transform_box_ == o.transform_box_))
        diff.push_back(DebugField::transform_box_);
    if (!(visibility_is_inherited_ == o.visibility_is_inherited_))
        diff.push_back(DebugField::visibility_is_inherited_);

    return diff;
}

#endif // DCHECK_IS_ON()

ComputedStyleBase::StyleFontData::StyleFontData()
    : font_(Font())
{
}

ComputedStyleBase::StyleFontData::StyleFontData(const StyleFontData& other)
    : font_(other.font_)
{
}

ComputedStyleBase::StyleInheritedData::StyleInheritedData()
    : inherited_variables_(nullptr)
    , line_height_(Length::Percent(-100.0))
    , text_autosizing_multiplier_(1.0)
    , color_(StyleColor(Color::kBlack))
    , internal_visited_color_(StyleColor(Color::kBlack))
    , horizontal_border_spacing_(0)
    , vertical_border_spacing_(0)
    , color_is_current_color_(static_cast<unsigned>(true))
    , in_forced_colors_mode_(static_cast<unsigned>(false))
    , internal_visited_color_is_current_color_(static_cast<unsigned>(true))
{
    font_data_.Init();
}

ComputedStyleBase::StyleInheritedData::StyleInheritedData(const StyleInheritedData& other)
    : font_data_(other.font_data_)
    , inherited_variables_(MemberCopy(other.inherited_variables_))
    , line_height_(other.line_height_)
    , text_autosizing_multiplier_(other.text_autosizing_multiplier_)
    , color_(other.color_)
    , internal_visited_color_(other.internal_visited_color_)
    , horizontal_border_spacing_(other.horizontal_border_spacing_)
    , vertical_border_spacing_(other.vertical_border_spacing_)
    , color_is_current_color_(other.color_is_current_color_)
    , in_forced_colors_mode_(other.in_forced_colors_mode_)
    , internal_visited_color_is_current_color_(other.internal_visited_color_is_current_color_)
{
}

ComputedStyleBase::StyleInheritedForcedColorsData::StyleInheritedForcedColorsData()
    : internal_forced_color_(StyleColor(CSSValueID::kCanvastext))
    , internal_forced_visited_color_(StyleColor(CSSValueID::kCanvastext))
{
}

ComputedStyleBase::StyleInheritedForcedColorsData::StyleInheritedForcedColorsData(const StyleInheritedForcedColorsData& other)
    : internal_forced_color_(other.internal_forced_color_)
    , internal_forced_visited_color_(other.internal_forced_visited_color_)
{
}

ComputedStyleBase::StyleInheritedVisitedData::StyleInheritedVisitedData()
    : internal_visited_text_emphasis_color_(StyleColor::CurrentColor())
    , internal_visited_text_fill_color_(StyleColor::CurrentColor())
    , internal_visited_text_stroke_color_(StyleColor::CurrentColor())
    , internal_visited_caret_color_(StyleAutoColor::AutoColor())
{
}

ComputedStyleBase::StyleInheritedVisitedData::StyleInheritedVisitedData(const StyleInheritedVisitedData& other)
    : internal_visited_text_emphasis_color_(other.internal_visited_text_emphasis_color_)
    , internal_visited_text_fill_color_(other.internal_visited_text_fill_color_)
    , internal_visited_text_stroke_color_(other.internal_visited_text_stroke_color_)
    , internal_visited_caret_color_(other.internal_visited_caret_color_)
{
}

ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentSubData::StyleRareInheritedUsageLessThan64PercentSubData()
    : text_emphasis_custom_mark_(AtomicString())
    , applied_text_decorations_(nullptr)
    , highlight_data_(nullptr)
    , initial_data_(nullptr)
    , cursor_data_(nullptr)
    , effective_zoom_(1.0f)
    , accent_color_(StyleAutoColor::AutoColor())
    , hyphenate_limit_chars_(StyleHyphenateLimitChars())
    , line_height_step_(0)
    , effective_touch_action_(static_cast<unsigned>(TouchAction::kAuto))
    , text_emphasis_mark_(static_cast<unsigned>(TextEmphasisMark::kNone))
    , has_line_if_empty_(static_cast<unsigned>(false))
    , subtree_is_sticky_(static_cast<unsigned>(false))
    , subtree_will_change_contents_(static_cast<unsigned>(false))
    , text_emphasis_fill_(static_cast<unsigned>(TextEmphasisFill::kFilled))
{
    inherited_forced_colors_data_.Init();
    inherited_visited_data_.Init();
}

ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentSubData::StyleRareInheritedUsageLessThan64PercentSubData(const StyleRareInheritedUsageLessThan64PercentSubData& other)
    : inherited_forced_colors_data_(other.inherited_forced_colors_data_)
    , inherited_visited_data_(other.inherited_visited_data_)
    , text_emphasis_custom_mark_(other.text_emphasis_custom_mark_)
    , applied_text_decorations_(MemberCopy(other.applied_text_decorations_))
    , highlight_data_(MemberCopy(other.highlight_data_))
    , initial_data_(MemberCopy(other.initial_data_))
    , cursor_data_(MemberCopy(other.cursor_data_))
    , effective_zoom_(other.effective_zoom_)
    , accent_color_(other.accent_color_)
    , hyphenate_limit_chars_(other.hyphenate_limit_chars_)
    , line_height_step_(other.line_height_step_)
    , effective_touch_action_(other.effective_touch_action_)
    , text_emphasis_mark_(other.text_emphasis_mark_)
    , has_line_if_empty_(other.has_line_if_empty_)
    , subtree_is_sticky_(other.subtree_is_sticky_)
    , subtree_will_change_contents_(other.subtree_will_change_contents_)
    , text_emphasis_fill_(other.text_emphasis_fill_)
{
}

ComputedStyleBase::StyleRareInheritedUsageLessThan100PercentData::StyleRareInheritedUsageLessThan100PercentData()
    : text_underline_offset_(Length())
    , tap_highlight_color_(StyleColor(LayoutTheme::TapHighlightColor()))
    , math_depth_(0)
    , math_shift_(static_cast<unsigned>(EMathShift::kNormal))
    , math_style_(static_cast<unsigned>(EMathStyle::kNormal))
    , respect_image_orientation_(static_cast<unsigned>(true))
    , ruby_position_(static_cast<unsigned>(RubyPosition::kBefore))
{
}

ComputedStyleBase::StyleRareInheritedUsageLessThan100PercentData::StyleRareInheritedUsageLessThan100PercentData(const StyleRareInheritedUsageLessThan100PercentData& other)
    : text_underline_offset_(other.text_underline_offset_)
    , tap_highlight_color_(other.tap_highlight_color_)
    , math_depth_(other.math_depth_)
    , math_shift_(other.math_shift_)
    , math_style_(other.math_style_)
    , respect_image_orientation_(other.respect_image_orientation_)
    , ruby_position_(other.ruby_position_)
{
}

ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentData::StyleRareInheritedUsageLessThan64PercentData()
    : color_scheme_(Vector<AtomicString, 0>())
    , hyphenation_string_(AtomicString())
    , highlight_(g_null_atom)
    , quotes_(nullptr)
    , text_shadow_(nullptr)
    , list_style_image_(nullptr)
    , list_style_type_(ListStyleTypeData::CreateCounterStyle("disc", nullptr))
    , text_decoration_thickness_(TextDecorationThickness(Length::Auto()))
    , text_indent_(Length::Fixed())
    , text_size_adjust_(TextSizeAdjust::AdjustAuto())
    , tab_size_(TabSize(8))
    , text_stroke_width_(0)
    , text_emphasis_color_(StyleColor::CurrentColor())
    , text_fill_color_(StyleColor::CurrentColor())
    , text_stroke_color_(StyleColor::CurrentColor())
    , caret_color_(StyleAutoColor::AutoColor())
    , orphans_(2)
    , widows_(2)
    , text_underline_position_(static_cast<unsigned>(kTextUnderlinePositionAuto))
    , image_rendering_(static_cast<unsigned>(EImageRendering::kAuto))
    , line_break_(static_cast<unsigned>(LineBreak::kAuto))
    , speak_(static_cast<unsigned>(ESpeak::kNormal))
    , text_align_last_(static_cast<unsigned>(ETextAlignLast::kAuto))
    , forced_color_adjust_(static_cast<unsigned>(EForcedColorAdjust::kAuto))
    , hyphens_(static_cast<unsigned>(Hyphens::kManual))
    , overflow_wrap_(static_cast<unsigned>(EOverflowWrap::kNormal))
    , text_emphasis_position_(static_cast<unsigned>(TextEmphasisPosition::kOverRight))
    , text_orientation_(static_cast<unsigned>(ETextOrientation::kMixed))
    , text_security_(static_cast<unsigned>(ETextSecurity::kNone))
    , user_modify_(static_cast<unsigned>(EUserModify::kReadOnly))
    , user_select_(static_cast<unsigned>(EUserSelect::kAuto))
    , word_break_(static_cast<unsigned>(EWordBreak::kNormal))
    , text_combine_(static_cast<unsigned>(ETextCombine::kNone))
    , text_decoration_skip_ink_(static_cast<unsigned>(ETextDecorationSkipInk::kAuto))
{
    rare_inherited_usage_less_than_64_percent_sub_data_.Init();
    rare_inherited_usage_less_than_100_percent_data_.Init();
}

ComputedStyleBase::StyleRareInheritedUsageLessThan64PercentData::StyleRareInheritedUsageLessThan64PercentData(const StyleRareInheritedUsageLessThan64PercentData& other)
    : rare_inherited_usage_less_than_64_percent_sub_data_(other.rare_inherited_usage_less_than_64_percent_sub_data_)
    , rare_inherited_usage_less_than_100_percent_data_(other.rare_inherited_usage_less_than_100_percent_data_)
    , color_scheme_(other.color_scheme_)
    , hyphenation_string_(other.hyphenation_string_)
    , highlight_(other.highlight_)
    , quotes_(MemberCopy(other.quotes_))
    , text_shadow_(MemberCopy(other.text_shadow_))
    , list_style_image_(MemberCopy(other.list_style_image_))
    , list_style_type_(MemberCopy(other.list_style_type_))
    , text_decoration_thickness_(other.text_decoration_thickness_)
    , text_indent_(other.text_indent_)
    , text_size_adjust_(other.text_size_adjust_)
    , tab_size_(other.tab_size_)
    , text_stroke_width_(other.text_stroke_width_)
    , text_emphasis_color_(other.text_emphasis_color_)
    , text_fill_color_(other.text_fill_color_)
    , text_stroke_color_(other.text_stroke_color_)
    , caret_color_(other.caret_color_)
    , orphans_(other.orphans_)
    , widows_(other.widows_)
    , text_underline_position_(other.text_underline_position_)
    , image_rendering_(other.image_rendering_)
    , line_break_(other.line_break_)
    , speak_(other.speak_)
    , text_align_last_(other.text_align_last_)
    , forced_color_adjust_(other.forced_color_adjust_)
    , hyphens_(other.hyphens_)
    , overflow_wrap_(other.overflow_wrap_)
    , text_emphasis_position_(other.text_emphasis_position_)
    , text_orientation_(other.text_orientation_)
    , text_security_(other.text_security_)
    , user_modify_(other.user_modify_)
    , user_select_(other.user_select_)
    , word_break_(other.word_break_)
    , text_combine_(other.text_combine_)
    , text_decoration_skip_ink_(other.text_decoration_skip_ink_)
{
}

ComputedStyleBase::StyleVisualData::StyleVisualData()
    : clip_(LengthBox())
    , zoom_(1.0)
    , text_decoration_line_(static_cast<unsigned>(TextDecorationLine::kNone))
    , has_auto_clip_(static_cast<unsigned>(true))
    , has_clip_path_(static_cast<unsigned>(false))
{
}

ComputedStyleBase::StyleVisualData::StyleVisualData(const StyleVisualData& other)
    : clip_(other.clip_)
    , zoom_(other.zoom_)
    , text_decoration_line_(other.text_decoration_line_)
    , has_auto_clip_(other.has_auto_clip_)
    , has_clip_path_(other.has_clip_path_)
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan100PercentData::StyleRareNonInheritedUsageLessThan100PercentData()
    : grid_auto_columns_(GridTrackList(GridTrackSize(Length::Auto())))
    , grid_auto_rows_(GridTrackList(GridTrackSize(Length::Auto())))
    , grid_column_end_(GridPosition())
    , grid_column_start_(GridPosition())
    , grid_row_end_(GridPosition())
    , grid_row_start_(GridPosition())
    , page_(AtomicString())
    , clip_path_(nullptr)
    , offset_path_(nullptr)
    , rotate_(nullptr)
    , scale_(nullptr)
    , translate_(nullptr)
    , box_reflect_(nullptr)
    , backdrop_filter_(MakeGarbageCollected<StyleFilterData>())
    , shape_outside_(nullptr)
    , column_gap_(absl::nullopt)
    , row_gap_(absl::nullopt)
    , offset_rotate_(StyleOffsetRotation(0, OffsetRotationType::kAuto))
    , object_position_(LengthPoint(Length::Percent(50.0), Length::Percent(50.0)))
    , offset_anchor_(LengthPoint(Length::Auto(), Length::Auto()))
    , offset_position_(LengthPoint(Length::Auto(), Length::Auto()))
    , perspective_origin_(LengthPoint(Length::Percent(50.0), Length::Percent(50.0)))
    , offset_distance_(Length::Fixed(0))
    , scroll_padding_bottom_(Length())
    , scroll_padding_left_(Length())
    , scroll_padding_right_(Length())
    , scroll_padding_top_(Length())
    , shape_margin_(Length::Fixed(0))
    , column_width_(0.0f)
    , perspective_(-1.0)
    , shape_image_threshold_(0.0)
    , scroll_snap_type_(cc::ScrollSnapType())
    , scroll_snap_align_(cc::ScrollSnapAlign())
    , column_rule_color_(StyleColor::CurrentColor())
    , outline_color_(StyleColor::CurrentColor())
    , text_decoration_color_(StyleColor::CurrentColor())
    , column_rule_width_(LayoutUnit(3))
    , box_ordinal_group_(1)
    , column_count_(1)
    , justify_items_(StyleSelfAlignmentData(ItemPosition::kLegacy, OverflowAlignment::kDefault))
    , justify_self_(StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault))
    , blend_mode_(static_cast<unsigned>(BlendMode::kNormal))
    , contain_(static_cast<unsigned>(kContainsNone))
    , column_rule_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , grid_auto_flow_(static_cast<unsigned>(kAutoFlowRow))
    , text_decoration_style_(static_cast<unsigned>(ETextDecorationStyle::kSolid))
    , draggable_region_mode_(static_cast<unsigned>(EDraggableRegionMode::kNone))
    , page_orientation_(static_cast<unsigned>(PageOrientation::kUpright))
    , scroll_behavior_(static_cast<unsigned>(mojom::blink::ScrollBehavior::kAuto))
    , user_drag_(static_cast<unsigned>(EUserDrag::kAuto))
    , column_fill_(static_cast<unsigned>(EColumnFill::kBalance))
    , column_span_(static_cast<unsigned>(EColumnSpan::kNone))
    , isolation_(static_cast<unsigned>(EIsolation::kAuto))
    , transform_style_3d_(static_cast<unsigned>(ETransformStyle3D::kFlat))
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan100PercentData::StyleRareNonInheritedUsageLessThan100PercentData(const StyleRareNonInheritedUsageLessThan100PercentData& other)
    : grid_auto_columns_(other.grid_auto_columns_)
    , grid_auto_rows_(other.grid_auto_rows_)
    , grid_column_end_(other.grid_column_end_)
    , grid_column_start_(other.grid_column_start_)
    , grid_row_end_(other.grid_row_end_)
    , grid_row_start_(other.grid_row_start_)
    , page_(other.page_)
    , clip_path_(MemberCopy(other.clip_path_))
    , offset_path_(MemberCopy(other.offset_path_))
    , rotate_(MemberCopy(other.rotate_))
    , scale_(MemberCopy(other.scale_))
    , translate_(MemberCopy(other.translate_))
    , box_reflect_(MemberCopy(other.box_reflect_))
    , backdrop_filter_(MemberCopy(other.backdrop_filter_))
    , shape_outside_(MemberCopy(other.shape_outside_))
    , column_gap_(other.column_gap_)
    , row_gap_(other.row_gap_)
    , offset_rotate_(other.offset_rotate_)
    , object_position_(other.object_position_)
    , offset_anchor_(other.offset_anchor_)
    , offset_position_(other.offset_position_)
    , perspective_origin_(other.perspective_origin_)
    , offset_distance_(other.offset_distance_)
    , scroll_padding_bottom_(other.scroll_padding_bottom_)
    , scroll_padding_left_(other.scroll_padding_left_)
    , scroll_padding_right_(other.scroll_padding_right_)
    , scroll_padding_top_(other.scroll_padding_top_)
    , shape_margin_(other.shape_margin_)
    , column_width_(other.column_width_)
    , perspective_(other.perspective_)
    , shape_image_threshold_(other.shape_image_threshold_)
    , scroll_snap_type_(other.scroll_snap_type_)
    , scroll_snap_align_(other.scroll_snap_align_)
    , column_rule_color_(other.column_rule_color_)
    , outline_color_(other.outline_color_)
    , text_decoration_color_(other.text_decoration_color_)
    , column_rule_width_(other.column_rule_width_)
    , box_ordinal_group_(other.box_ordinal_group_)
    , column_count_(other.column_count_)
    , justify_items_(other.justify_items_)
    , justify_self_(other.justify_self_)
    , blend_mode_(other.blend_mode_)
    , contain_(other.contain_)
    , column_rule_style_(other.column_rule_style_)
    , grid_auto_flow_(other.grid_auto_flow_)
    , text_decoration_style_(other.text_decoration_style_)
    , draggable_region_mode_(other.draggable_region_mode_)
    , page_orientation_(other.page_orientation_)
    , scroll_behavior_(other.scroll_behavior_)
    , user_drag_(other.user_drag_)
    , column_fill_(other.column_fill_)
    , column_span_(other.column_span_)
    , isolation_(other.isolation_)
    , transform_style_3d_(other.transform_style_3d_)
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan22PercentData::StyleRareNonInheritedUsageLessThan22PercentData()
    : filter_(MakeGarbageCollected<StyleFilterData>())
    , flex_basis_(Length::Auto())
    , flex_grow_(0.0f)
    , flex_shrink_(1.0f)
    , box_flex_(0.0f)
    , outline_offset_(LayoutUnit(0))
    , outline_width_(LayoutUnit(3))
    , order_(0)
    , line_clamp_(0)
    , align_self_(StyleSelfAlignmentData(ItemPosition::kAuto, OverflowAlignment::kDefault))
    , align_content_(StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault))
    , touch_action_(static_cast<unsigned>(TouchAction::kAuto))
    , outline_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , box_align_(static_cast<unsigned>(EBoxAlignment::kStretch))
    , object_fit_(static_cast<unsigned>(EObjectFit::kFill))
    , resize_(static_cast<unsigned>(EResize::kNone))
    , box_pack_(static_cast<unsigned>(EBoxPack::kStart))
    , backface_visibility_(static_cast<unsigned>(EBackfaceVisibility::kVisible))
    , box_orient_(static_cast<unsigned>(EBoxOrient::kHorizontal))
{
    rare_non_inherited_usage_less_than_100_percent_data_.Init();
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan22PercentData::StyleRareNonInheritedUsageLessThan22PercentData(const StyleRareNonInheritedUsageLessThan22PercentData& other)
    : rare_non_inherited_usage_less_than_100_percent_data_(other.rare_non_inherited_usage_less_than_100_percent_data_)
    , filter_(MemberCopy(other.filter_))
    , flex_basis_(other.flex_basis_)
    , flex_grow_(other.flex_grow_)
    , flex_shrink_(other.flex_shrink_)
    , box_flex_(other.box_flex_)
    , outline_offset_(other.outline_offset_)
    , outline_width_(other.outline_width_)
    , order_(other.order_)
    , line_clamp_(other.line_clamp_)
    , align_self_(other.align_self_)
    , align_content_(other.align_content_)
    , touch_action_(other.touch_action_)
    , outline_style_(other.outline_style_)
    , box_align_(other.box_align_)
    , object_fit_(other.object_fit_)
    , resize_(other.resize_)
    , box_pack_(other.box_pack_)
    , backface_visibility_(other.backface_visibility_)
    , box_orient_(other.box_orient_)
{
}

ComputedStyleBase::StyleGridData::StyleGridData()
    : grid_template_columns_(ComputedGridTrackList())
    , grid_template_rows_(ComputedGridTrackList())
    , implicit_named_grid_column_lines_(NamedGridLinesMap())
    , implicit_named_grid_row_lines_(NamedGridLinesMap())
    , named_grid_area_(NamedGridAreaMap())
    , named_grid_area_row_count_(0)
    , named_grid_area_column_count_(0)
{
}

ComputedStyleBase::StyleGridData::StyleGridData(const StyleGridData& other)
    : grid_template_columns_(other.grid_template_columns_)
    , grid_template_rows_(other.grid_template_rows_)
    , implicit_named_grid_column_lines_(other.implicit_named_grid_column_lines_)
    , implicit_named_grid_row_lines_(other.implicit_named_grid_row_lines_)
    , named_grid_area_(other.named_grid_area_)
    , named_grid_area_row_count_(other.named_grid_area_row_count_)
    , named_grid_area_column_count_(other.named_grid_area_column_count_)
{
}

ComputedStyleBase::StyleForcedColorsData::StyleForcedColorsData()
    : internal_forced_background_color_(StyleColor(CSSValueID::kCanvas))
    , internal_forced_border_color_(StyleColor::CurrentColor())
    , internal_forced_outline_color_(StyleColor::CurrentColor())
{
}

ComputedStyleBase::StyleForcedColorsData::StyleForcedColorsData(const StyleForcedColorsData& other)
    : internal_forced_background_color_(other.internal_forced_background_color_)
    , internal_forced_border_color_(other.internal_forced_border_color_)
    , internal_forced_outline_color_(other.internal_forced_outline_color_)
{
}

ComputedStyleBase::StyleVisitedData::StyleVisitedData()
    : internal_visited_background_color_(StyleColor(Color::kTransparent))
    , internal_visited_border_bottom_color_(StyleColor::CurrentColor())
    , internal_visited_border_left_color_(StyleColor::CurrentColor())
    , internal_visited_border_right_color_(StyleColor::CurrentColor())
    , internal_visited_border_top_color_(StyleColor::CurrentColor())
    , internal_visited_column_rule_color_(StyleColor::CurrentColor())
    , internal_visited_outline_color_(StyleColor::CurrentColor())
    , internal_visited_text_decoration_color_(StyleColor::CurrentColor())
{
}

ComputedStyleBase::StyleVisitedData::StyleVisitedData(const StyleVisitedData& other)
    : internal_visited_background_color_(other.internal_visited_background_color_)
    , internal_visited_border_bottom_color_(other.internal_visited_border_bottom_color_)
    , internal_visited_border_left_color_(other.internal_visited_border_left_color_)
    , internal_visited_border_right_color_(other.internal_visited_border_right_color_)
    , internal_visited_border_top_color_(other.internal_visited_border_top_color_)
    , internal_visited_column_rule_color_(other.internal_visited_column_rule_color_)
    , internal_visited_outline_color_(other.internal_visited_outline_color_)
    , internal_visited_text_decoration_color_(other.internal_visited_text_decoration_color_)
{
}

ComputedStyleBase::StyleTimelineData::StyleTimelineData()
    : view_timeline_name_(Vector<AtomicString>())
    , view_timeline_axis_(Vector<TimelineAxis>())
    , view_timeline_inset_(Vector<TimelineInset>())
    , scroll_timeline_name_(g_null_atom)
    , scroll_timeline_axis_(static_cast<unsigned>(TimelineAxis::kBlock))
{
}

ComputedStyleBase::StyleTimelineData::StyleTimelineData(const StyleTimelineData& other)
    : view_timeline_name_(other.view_timeline_name_)
    , view_timeline_axis_(other.view_timeline_axis_)
    , view_timeline_inset_(other.view_timeline_inset_)
    , scroll_timeline_name_(other.scroll_timeline_name_)
    , scroll_timeline_axis_(other.scroll_timeline_axis_)
{
}

ComputedStyleBase::StyleWillChangeData::StyleWillChangeData()
    : will_change_properties_(Vector<CSSPropertyID>())
    , will_change_contents_(static_cast<unsigned>(false))
    , will_change_scroll_position_(static_cast<unsigned>(false))
{
}

ComputedStyleBase::StyleWillChangeData::StyleWillChangeData(const StyleWillChangeData& other)
    : will_change_properties_(other.will_change_properties_)
    , will_change_contents_(other.will_change_contents_)
    , will_change_scroll_position_(other.will_change_scroll_position_)
{
}

ComputedStyleBase::StyleMathData::StyleMathData()
    : math_baseline_(Length())
    , math_fraction_bar_thickness_(Length())
    , math_l_space_(Length())
    , math_r_space_(Length())
    , math_padded_v_offset_(Length())
    , math_padded_depth_(Length())
    , math_min_size_(Length())
    , math_max_size_(Length())
{
}

ComputedStyleBase::StyleMathData::StyleMathData(const StyleMathData& other)
    : math_baseline_(other.math_baseline_)
    , math_fraction_bar_thickness_(other.math_fraction_bar_thickness_)
    , math_l_space_(other.math_l_space_)
    , math_r_space_(other.math_r_space_)
    , math_padded_v_offset_(other.math_padded_v_offset_)
    , math_padded_depth_(other.math_padded_depth_)
    , math_min_size_(other.math_min_size_)
    , math_max_size_(other.math_max_size_)
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentSubData::StyleRareNonInheritedUsageLessThan14PercentSubData()
    : container_name_(Vector<AtomicString>())
    , anchor_name_(g_null_atom)
    , anchor_scroll_(g_null_atom)
    , page_transition_tag_(AtomicString())
    , position_fallback_(g_null_atom)
    , toggle_visibility_(g_null_atom)
    , display_layout_custom_name_(g_null_atom)
    , display_layout_custom_parent_name_(g_null_atom)
    , pseudo_argument_(g_null_atom)
    , object_view_box_(nullptr)
    , toggle_group_(nullptr)
    , toggle_root_(nullptr)
    , toggle_trigger_(nullptr)
    , custom_highlight_names_(nullptr)
    , counter_directives_(nullptr)
    , animations_(nullptr)
    , transitions_(nullptr)
    , paint_images_(nullptr)
    , non_inherited_variables_(nullptr)
    , callback_selectors_(Vector<String>())
    , mask_(FillLayer(EFillLayerType::kMask, true))
    , mask_box_image_(NinePieceImage::MaskDefaults())
    , overflow_clip_margin_(absl::nullopt)
    , initial_letter_(StyleInitialLetter())
    , page_size_(gfx::SizeF())
    , scroll_margin_bottom_(0.0f)
    , scroll_margin_left_(0.0f)
    , scroll_margin_right_(0.0f)
    , scroll_margin_top_(0.0f)
    , effective_appearance_(static_cast<unsigned>(kNoControlPart))
    , scroll_customization_(static_cast<unsigned>(scroll_customization::kScrollDirectionNone))
    , container_type_(static_cast<unsigned>(kContainerTypeNormal))
    , page_size_type_(static_cast<unsigned>(PageSizeType::kAuto))
    , scrollbar_width_(static_cast<unsigned>(EScrollbarWidth::kAuto))
    , align_self_block_center_(static_cast<unsigned>(false))
    , compositable_paint_animation_changed_(static_cast<unsigned>(false))
    , depends_on_size_container_queries_(static_cast<unsigned>(false))
    , depends_on_style_container_queries_(static_cast<unsigned>(false))
    , effective_z_index_zero_(static_cast<unsigned>(false))
    , first_line_depends_on_size_container_queries_(static_cast<unsigned>(false))
    , has_auto_column_count_(static_cast<unsigned>(true))
    , has_auto_column_width_(static_cast<unsigned>(true))
    , has_current_backdrop_filter_animation_(static_cast<unsigned>(false))
    , has_current_background_color_animation_(static_cast<unsigned>(false))
    , has_current_clip_path_animation_(static_cast<unsigned>(false))
    , has_current_filter_animation_(static_cast<unsigned>(false))
    , has_current_opacity_animation_(static_cast<unsigned>(false))
    , has_current_rotate_animation_(static_cast<unsigned>(false))
    , has_current_scale_animation_(static_cast<unsigned>(false))
    , has_current_transform_animation_(static_cast<unsigned>(false))
    , has_current_translate_animation_(static_cast<unsigned>(false))
    , has_explicit_overflow_x_visible_(static_cast<unsigned>(false))
    , has_explicit_overflow_y_visible_(static_cast<unsigned>(false))
    , has_line_height_relative_units_(static_cast<unsigned>(false))
    , has_non_universal_highlight_pseudo_styles_(static_cast<unsigned>(false))
    , inline_style_lost_cascade_(static_cast<unsigned>(false))
    , is_running_backdrop_filter_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_filter_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_opacity_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_rotate_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_scale_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_transform_animation_on_compositor_(static_cast<unsigned>(false))
    , is_running_translate_animation_on_compositor_(static_cast<unsigned>(false))
    , is_secondary_body_element_(static_cast<unsigned>(false))
    , outline_style_is_auto_(static_cast<unsigned>(false))
    , requires_accelerated_compositing_for_external_reasons_(static_cast<unsigned>(false))
{
    grid_data_.Init();
    forced_colors_data_.Init();
    visited_data_.Init();
    timeline_data_.Init();
    will_change_data_.Init();
    math_data_.Init();
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentSubData::StyleRareNonInheritedUsageLessThan14PercentSubData(
    const StyleRareNonInheritedUsageLessThan14PercentSubData& other)
    : grid_data_(other.grid_data_)
    , forced_colors_data_(other.forced_colors_data_)
    , visited_data_(other.visited_data_)
    , timeline_data_(other.timeline_data_)
    , will_change_data_(other.will_change_data_)
    , math_data_(other.math_data_)
    , container_name_(other.container_name_)
    , anchor_name_(other.anchor_name_)
    , anchor_scroll_(other.anchor_scroll_)
    , page_transition_tag_(other.page_transition_tag_)
    , position_fallback_(other.position_fallback_)
    , toggle_visibility_(other.toggle_visibility_)
    , display_layout_custom_name_(other.display_layout_custom_name_)
    , display_layout_custom_parent_name_(other.display_layout_custom_parent_name_)
    , pseudo_argument_(other.pseudo_argument_)
    , object_view_box_(MemberCopy(other.object_view_box_))
    , toggle_group_(MemberCopy(other.toggle_group_))
    , toggle_root_(MemberCopy(other.toggle_root_))
    , toggle_trigger_(MemberCopy(other.toggle_trigger_))
    , custom_highlight_names_(MemberCopy(other.custom_highlight_names_))
    , counter_directives_(MemberCopy(other.counter_directives_))
    , animations_(MemberCopy(other.animations_))
    , transitions_(MemberCopy(other.transitions_))
    , paint_images_(MemberCopy(other.paint_images_))
    , non_inherited_variables_(MemberCopy(other.non_inherited_variables_))
    , callback_selectors_(other.callback_selectors_)
    , mask_(other.mask_)
    , mask_box_image_(other.mask_box_image_)
    , overflow_clip_margin_(other.overflow_clip_margin_)
    , initial_letter_(other.initial_letter_)
    , page_size_(other.page_size_)
    , scroll_margin_bottom_(other.scroll_margin_bottom_)
    , scroll_margin_left_(other.scroll_margin_left_)
    , scroll_margin_right_(other.scroll_margin_right_)
    , scroll_margin_top_(other.scroll_margin_top_)
    , effective_appearance_(other.effective_appearance_)
    , scroll_customization_(other.scroll_customization_)
    , container_type_(other.container_type_)
    , page_size_type_(other.page_size_type_)
    , scrollbar_width_(other.scrollbar_width_)
    , align_self_block_center_(other.align_self_block_center_)
    , compositable_paint_animation_changed_(other.compositable_paint_animation_changed_)
    , depends_on_size_container_queries_(other.depends_on_size_container_queries_)
    , depends_on_style_container_queries_(other.depends_on_style_container_queries_)
    , effective_z_index_zero_(other.effective_z_index_zero_)
    , first_line_depends_on_size_container_queries_(other.first_line_depends_on_size_container_queries_)
    , has_auto_column_count_(other.has_auto_column_count_)
    , has_auto_column_width_(other.has_auto_column_width_)
    , has_current_backdrop_filter_animation_(other.has_current_backdrop_filter_animation_)
    , has_current_background_color_animation_(other.has_current_background_color_animation_)
    , has_current_clip_path_animation_(other.has_current_clip_path_animation_)
    , has_current_filter_animation_(other.has_current_filter_animation_)
    , has_current_opacity_animation_(other.has_current_opacity_animation_)
    , has_current_rotate_animation_(other.has_current_rotate_animation_)
    , has_current_scale_animation_(other.has_current_scale_animation_)
    , has_current_transform_animation_(other.has_current_transform_animation_)
    , has_current_translate_animation_(other.has_current_translate_animation_)
    , has_explicit_overflow_x_visible_(other.has_explicit_overflow_x_visible_)
    , has_explicit_overflow_y_visible_(other.has_explicit_overflow_y_visible_)
    , has_line_height_relative_units_(other.has_line_height_relative_units_)
    , has_non_universal_highlight_pseudo_styles_(other.has_non_universal_highlight_pseudo_styles_)
    , inline_style_lost_cascade_(other.inline_style_lost_cascade_)
    , is_running_backdrop_filter_animation_on_compositor_(other.is_running_backdrop_filter_animation_on_compositor_)
    , is_running_filter_animation_on_compositor_(other.is_running_filter_animation_on_compositor_)
    , is_running_opacity_animation_on_compositor_(other.is_running_opacity_animation_on_compositor_)
    , is_running_rotate_animation_on_compositor_(other.is_running_rotate_animation_on_compositor_)
    , is_running_scale_animation_on_compositor_(other.is_running_scale_animation_on_compositor_)
    , is_running_transform_animation_on_compositor_(other.is_running_transform_animation_on_compositor_)
    , is_running_translate_animation_on_compositor_(other.is_running_translate_animation_on_compositor_)
    , is_secondary_body_element_(other.is_secondary_body_element_)
    , outline_style_is_auto_(other.outline_style_is_auto_)
    , requires_accelerated_compositing_for_external_reasons_(other.requires_accelerated_compositing_for_external_reasons_)
{
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentData::StyleRareNonInheritedUsageLessThan14PercentData()
    : transform_(EmptyTransformOperations())
    , box_shadow_(nullptr)
    , content_(nullptr)
    , transform_origin_(TransformOrigin(Length::Percent(50.0), Length::Percent(50.0), 0))
    , opacity_(1.0)
    , align_items_(StyleSelfAlignmentData(ItemPosition::kNormal, OverflowAlignment::kDefault))
    , justify_content_(StyleContentAlignmentData(ContentPosition::kNormal, ContentDistributionType::kDefault, OverflowAlignment::kDefault))
    , appearance_(static_cast<unsigned>(kNoControlPart))
    , flex_direction_(static_cast<unsigned>(EFlexDirection::kRow))
    , flex_wrap_(static_cast<unsigned>(EFlexWrap::kNowrap))
    , is_stacking_context_without_containment_(static_cast<unsigned>(false))
    , text_overflow_(static_cast<unsigned>(ETextOverflow::kClip))
{
    rare_non_inherited_usage_less_than_22_percent_data_.Init();
    rare_non_inherited_usage_less_than_14_percent_sub_data_.Init();
}

ComputedStyleBase::StyleRareNonInheritedUsageLessThan14PercentData::StyleRareNonInheritedUsageLessThan14PercentData(const StyleRareNonInheritedUsageLessThan14PercentData& other)
    : rare_non_inherited_usage_less_than_22_percent_data_(other.rare_non_inherited_usage_less_than_22_percent_data_)
    , rare_non_inherited_usage_less_than_14_percent_sub_data_(other.rare_non_inherited_usage_less_than_14_percent_sub_data_)
    , transform_(other.transform_)
    , box_shadow_(MemberCopy(other.box_shadow_))
    , content_(MemberCopy(other.content_))
    , transform_origin_(other.transform_origin_)
    , opacity_(other.opacity_)
    , align_items_(other.align_items_)
    , justify_content_(other.justify_content_)
    , appearance_(other.appearance_)
    , flex_direction_(other.flex_direction_)
    , flex_wrap_(other.flex_wrap_)
    , is_stacking_context_without_containment_(other.is_stacking_context_without_containment_)
    , text_overflow_(other.text_overflow_)
{
}

ComputedStyleBase::StyleMiscData::StyleMiscData()
    : baseline_shift_(Length::Fixed())
    , flood_opacity_(1)
    , flood_color_(StyleColor(Color::kBlack))
    , lighting_color_(StyleColor(Color::kWhite))
    , baseline_shift_type_(static_cast<unsigned>(EBaselineShiftType::kLength))
{
}

ComputedStyleBase::StyleMiscData::StyleMiscData(const StyleMiscData& other)
    : baseline_shift_(other.baseline_shift_)
    , flood_opacity_(other.flood_opacity_)
    , flood_color_(other.flood_color_)
    , lighting_color_(other.lighting_color_)
    , baseline_shift_type_(other.baseline_shift_type_)
{
}

ComputedStyleBase::StyleGeometryData::StyleGeometryData()
    : d_(nullptr)
    , cx_(Length::Fixed())
    , cy_(Length::Fixed())
    , r_(Length::Fixed())
    , rx_(Length::Auto())
    , ry_(Length::Auto())
    , x_(Length::Fixed())
    , y_(Length::Fixed())
{
}

ComputedStyleBase::StyleGeometryData::StyleGeometryData(const StyleGeometryData& other)
    : d_(MemberCopy(other.d_))
    , cx_(other.cx_)
    , cy_(other.cy_)
    , r_(other.r_)
    , rx_(other.rx_)
    , ry_(other.ry_)
    , x_(other.x_)
    , y_(other.y_)
{
}

ComputedStyleBase::StyleFillData::StyleFillData()
    : fill_paint_(SVGPaint(Color::kBlack))
    , internal_visited_fill_paint_(SVGPaint(Color::kBlack))
    , fill_opacity_(1)
{
}

ComputedStyleBase::StyleFillData::StyleFillData(const StyleFillData& other)
    : fill_paint_(other.fill_paint_)
    , internal_visited_fill_paint_(other.internal_visited_fill_paint_)
    , fill_opacity_(other.fill_opacity_)
{
}

ComputedStyleBase::StyleStrokeData::StyleStrokeData()
    : stroke_dash_array_(EmptyDashArray())
    , internal_visited_stroke_paint_(SVGPaint())
    , stroke_paint_(SVGPaint())
    , stroke_dash_offset_(Length::Fixed())
    , stroke_width_(UnzoomedLength(Length::Fixed(1)))
    , stroke_miter_limit_(4)
    , stroke_opacity_(1)
    , cap_style_(static_cast<unsigned>(kButtCap))
    , join_style_(static_cast<unsigned>(kMiterJoin))
{
}

ComputedStyleBase::StyleStrokeData::StyleStrokeData(const StyleStrokeData& other)
    : stroke_dash_array_(MemberCopy(other.stroke_dash_array_))
    , internal_visited_stroke_paint_(other.internal_visited_stroke_paint_)
    , stroke_paint_(other.stroke_paint_)
    , stroke_dash_offset_(other.stroke_dash_offset_)
    , stroke_width_(other.stroke_width_)
    , stroke_miter_limit_(other.stroke_miter_limit_)
    , stroke_opacity_(other.stroke_opacity_)
    , cap_style_(other.cap_style_)
    , join_style_(other.join_style_)
{
}

ComputedStyleBase::StyleInheritedResourcesData::StyleInheritedResourcesData()
    : marker_end_resource_(nullptr)
    , marker_mid_resource_(nullptr)
    , marker_start_resource_(nullptr)
{
}

ComputedStyleBase::StyleInheritedResourcesData::StyleInheritedResourcesData(const StyleInheritedResourcesData& other)
    : marker_end_resource_(MemberCopy(other.marker_end_resource_))
    , marker_mid_resource_(MemberCopy(other.marker_mid_resource_))
    , marker_start_resource_(MemberCopy(other.marker_start_resource_))
{
}

ComputedStyleBase::StyleStopData::StyleStopData()
    : stop_opacity_(1)
    , stop_color_(StyleColor(Color::kBlack))
{
}

ComputedStyleBase::StyleStopData::StyleStopData(const StyleStopData& other)
    : stop_opacity_(other.stop_opacity_)
    , stop_color_(other.stop_color_)
{
}

ComputedStyleBase::StyleSVGData::StyleSVGData()
    : masker_resource_(nullptr)
    , alignment_baseline_(static_cast<unsigned>(EAlignmentBaseline::kAuto))
    , css_dominant_baseline_(static_cast<unsigned>(EDominantBaseline::kAuto))
    , dominant_baseline_(static_cast<unsigned>(EDominantBaseline::kAuto))
    , paint_order_(static_cast<unsigned>(kPaintOrderNormal))
    , buffered_rendering_(static_cast<unsigned>(EBufferedRendering::kAuto))
    , color_interpolation_(static_cast<unsigned>(EColorInterpolation::kSRGB))
    , color_interpolation_filters_(static_cast<unsigned>(EColorInterpolation::kLinearrgb))
    , color_rendering_(static_cast<unsigned>(EColorRendering::kAuto))
    , shape_rendering_(static_cast<unsigned>(EShapeRendering::kAuto))
    , text_anchor_(static_cast<unsigned>(ETextAnchor::kStart))
    , clip_rule_(static_cast<unsigned>(RULE_NONZERO))
    , fill_rule_(static_cast<unsigned>(RULE_NONZERO))
    , mask_type_(static_cast<unsigned>(EMaskType::kLuminance))
    , vector_effect_(static_cast<unsigned>(EVectorEffect::kNone))
{
    misc_data_.Init();
    geometry_data_.Init();
    fill_data_.Init();
    stroke_data_.Init();
    inherited_resources_data_.Init();
    stop_data_.Init();
}

ComputedStyleBase::StyleSVGData::StyleSVGData(const StyleSVGData& other)
    : misc_data_(other.misc_data_)
    , geometry_data_(other.geometry_data_)
    , fill_data_(other.fill_data_)
    , stroke_data_(other.stroke_data_)
    , inherited_resources_data_(other.inherited_resources_data_)
    , stop_data_(other.stop_data_)
    , masker_resource_(MemberCopy(other.masker_resource_))
    , alignment_baseline_(other.alignment_baseline_)
    , css_dominant_baseline_(other.css_dominant_baseline_)
    , dominant_baseline_(other.dominant_baseline_)
    , paint_order_(other.paint_order_)
    , buffered_rendering_(other.buffered_rendering_)
    , color_interpolation_(other.color_interpolation_)
    , color_interpolation_filters_(other.color_interpolation_filters_)
    , color_rendering_(other.color_rendering_)
    , shape_rendering_(other.shape_rendering_)
    , text_anchor_(other.text_anchor_)
    , clip_rule_(other.clip_rule_)
    , fill_rule_(other.fill_rule_)
    , mask_type_(other.mask_type_)
    , vector_effect_(other.vector_effect_)
{
}

ComputedStyleBase::StyleBoxData::StyleBoxData()
    : aspect_ratio_(StyleAspectRatio(EAspectRatioType::kAuto, gfx::SizeF()))
    , contain_intrinsic_height_(absl::optional<StyleIntrinsicLength>())
    , contain_intrinsic_width_(absl::nullopt)
    , height_(Length())
    , max_height_(Length::None())
    , max_width_(Length::None())
    , min_height_(Length())
    , min_width_(Length())
    , width_(Length())
    , vertical_align_length_(Length())
    , z_index_(0)
    , box_decoration_break_(static_cast<unsigned>(EBoxDecorationBreak::kSlice))
    , box_sizing_(static_cast<unsigned>(EBoxSizing::kContentBox))
    , has_auto_z_index_(static_cast<unsigned>(true))
{
}

ComputedStyleBase::StyleBoxData::StyleBoxData(const StyleBoxData& other)
    : aspect_ratio_(other.aspect_ratio_)
    , contain_intrinsic_height_(other.contain_intrinsic_height_)
    , contain_intrinsic_width_(other.contain_intrinsic_width_)
    , height_(other.height_)
    , max_height_(other.max_height_)
    , max_width_(other.max_width_)
    , min_height_(other.min_height_)
    , min_width_(other.min_width_)
    , width_(other.width_)
    , vertical_align_length_(other.vertical_align_length_)
    , z_index_(other.z_index_)
    , box_decoration_break_(other.box_decoration_break_)
    , box_sizing_(other.box_sizing_)
    , has_auto_z_index_(other.has_auto_z_index_)
{
}

ComputedStyleBase::StyleBackgroundData::StyleBackgroundData()
    : background_(FillLayer(EFillLayerType::kBackground, true))
    , background_color_(StyleColor(Color::kTransparent))
{
}

ComputedStyleBase::StyleBackgroundData::StyleBackgroundData(const StyleBackgroundData& other)
    : background_(other.background_)
    , background_color_(other.background_color_)
{
}

ComputedStyleBase::StyleSurroundData::StyleSurroundData()
    : border_image_(NinePieceImage())
    , border_bottom_left_radius_(LengthSize(Length::Fixed(0), Length::Fixed(0)))
    , border_bottom_right_radius_(LengthSize(Length::Fixed(0), Length::Fixed(0)))
    , border_top_left_radius_(LengthSize(Length::Fixed(0), Length::Fixed(0)))
    , border_top_right_radius_(LengthSize(Length::Fixed(0), Length::Fixed(0)))
    , bottom_(Length())
    , left_(Length())
    , margin_bottom_(Length::Fixed())
    , margin_left_(Length::Fixed())
    , margin_right_(Length::Fixed())
    , margin_top_(Length::Fixed())
    , padding_bottom_(Length::Fixed())
    , padding_left_(Length::Fixed())
    , padding_right_(Length::Fixed())
    , padding_top_(Length::Fixed())
    , right_(Length())
    , top_(Length())
    , border_bottom_color_(StyleColor::CurrentColor())
    , border_left_color_(StyleColor::CurrentColor())
    , border_right_color_(StyleColor::CurrentColor())
    , border_top_color_(StyleColor::CurrentColor())
    , border_bottom_width_(LayoutUnit(3))
    , border_left_width_(LayoutUnit(3))
    , border_right_width_(LayoutUnit(3))
    , border_top_width_(LayoutUnit(3))
    , border_bottom_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , border_left_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , border_right_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , border_top_style_(static_cast<unsigned>(EBorderStyle::kNone))
    , may_have_margin_(static_cast<unsigned>(false))
    , may_have_padding_(static_cast<unsigned>(false))
{
}

ComputedStyleBase::StyleSurroundData::StyleSurroundData(const StyleSurroundData& other)
    : border_image_(other.border_image_)
    , border_bottom_left_radius_(other.border_bottom_left_radius_)
    , border_bottom_right_radius_(other.border_bottom_right_radius_)
    , border_top_left_radius_(other.border_top_left_radius_)
    , border_top_right_radius_(other.border_top_right_radius_)
    , bottom_(other.bottom_)
    , left_(other.left_)
    , margin_bottom_(other.margin_bottom_)
    , margin_left_(other.margin_left_)
    , margin_right_(other.margin_right_)
    , margin_top_(other.margin_top_)
    , padding_bottom_(other.padding_bottom_)
    , padding_left_(other.padding_left_)
    , padding_right_(other.padding_right_)
    , padding_top_(other.padding_top_)
    , right_(other.right_)
    , top_(other.top_)
    , border_bottom_color_(other.border_bottom_color_)
    , border_left_color_(other.border_left_color_)
    , border_right_color_(other.border_right_color_)
    , border_top_color_(other.border_top_color_)
    , border_bottom_width_(other.border_bottom_width_)
    , border_left_width_(other.border_left_width_)
    , border_right_width_(other.border_right_width_)
    , border_top_width_(other.border_top_width_)
    , border_bottom_style_(other.border_bottom_style_)
    , border_left_style_(other.border_left_style_)
    , border_right_style_(other.border_right_style_)
    , border_top_style_(other.border_top_style_)
    , may_have_margin_(other.may_have_margin_)
    , may_have_padding_(other.may_have_padding_)
{
}

} // namespace blink
