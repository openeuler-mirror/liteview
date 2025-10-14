// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5

#include "build/build_config.h"
#include "build/chromeos_buildflags.h"

#include "third_party/blink/renderer/platform/runtime_enabled_features.h"

#include "third_party/blink/public/common/features.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {

RuntimeEnabledFeaturesBase::Backup::Backup()
    : is_abort_signal_throw_if_aborted_enabled_(RuntimeEnabledFeaturesBase::is_abort_signal_throw_if_aborted_enabled_)
    , is_abort_signal_timeout_enabled_(RuntimeEnabledFeaturesBase::is_abort_signal_timeout_enabled_)
    , is_accelerated_2d_canvas_enabled_(RuntimeEnabledFeaturesBase::is_accelerated_2d_canvas_enabled_)
    , is_accelerated_small_canvases_enabled_(RuntimeEnabledFeaturesBase::is_accelerated_small_canvases_enabled_)
    , is_accessibility_aria_touch_passthrough_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_aria_touch_passthrough_enabled_)
    , is_accessibility_aria_virtual_content_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_aria_virtual_content_enabled_)
    , is_accessibility_expose_display_none_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_expose_display_none_enabled_)
    , is_accessibility_expose_html_element_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_expose_html_element_enabled_)
    , is_accessibility_expose_ignored_nodes_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_expose_ignored_nodes_enabled_)
    , is_accessibility_object_model_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_object_model_enabled_)
    , is_accessibility_page_zoom_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_page_zoom_enabled_)
    , is_accessibility_use_ax_position_for_document_markers_enabled_(RuntimeEnabledFeaturesBase::is_accessibility_use_ax_position_for_document_markers_enabled_)
    , is_address_space_enabled_(RuntimeEnabledFeaturesBase::is_address_space_enabled_)
    , is_ad_interest_group_api_enabled_(RuntimeEnabledFeaturesBase::is_ad_interest_group_api_enabled_)
    , is_ad_tagging_enabled_(RuntimeEnabledFeaturesBase::is_ad_tagging_enabled_)
    , is_allow_content_initiated_data_url_navigations_enabled_(RuntimeEnabledFeaturesBase::is_allow_content_initiated_data_url_navigations_enabled_)
    , is_android_downloadable_fonts_matching_enabled_(RuntimeEnabledFeaturesBase::is_android_downloadable_fonts_matching_enabled_)
    , is_animation_worklet_enabled_(RuntimeEnabledFeaturesBase::is_animation_worklet_enabled_)
    , is_anonymous_iframe_enabled_(RuntimeEnabledFeaturesBase::is_anonymous_iframe_enabled_)
    , is_aom_aria_relationship_properties_enabled_(RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_enabled_)
    , is_aria_touch_passthrough_enabled_(RuntimeEnabledFeaturesBase::is_aria_touch_passthrough_enabled_)
    , is_attribution_reporting_enabled_(RuntimeEnabledFeaturesBase::is_attribution_reporting_enabled_)
    , is_audio_context_set_sink_id_enabled_(RuntimeEnabledFeaturesBase::is_audio_context_set_sink_id_enabled_)
    , is_audio_output_devices_enabled_(RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_)
    , is_audio_video_tracks_enabled_(RuntimeEnabledFeaturesBase::is_audio_video_tracks_enabled_)
    , is_auto_dark_mode_enabled_(RuntimeEnabledFeaturesBase::is_auto_dark_mode_enabled_)
    , is_auto_disable_accessibility_v_2_enabled_(RuntimeEnabledFeaturesBase::is_auto_disable_accessibility_v_2_enabled_)
    , is_autofill_shadow_dom_enabled_(RuntimeEnabledFeaturesBase::is_autofill_shadow_dom_enabled_)
    , is_automation_controlled_enabled_(RuntimeEnabledFeaturesBase::is_automation_controlled_enabled_)
    , is_auto_picture_in_picture_enabled_(RuntimeEnabledFeaturesBase::is_auto_picture_in_picture_enabled_)
    , is_autoplay_ignores_web_audio_enabled_(RuntimeEnabledFeaturesBase::is_autoplay_ignores_web_audio_enabled_)
    , is_backface_visibility_interop_enabled_(RuntimeEnabledFeaturesBase::is_backface_visibility_interop_enabled_)
    , is_back_forward_cache_enabled_(RuntimeEnabledFeaturesBase::is_back_forward_cache_enabled_)
    , is_back_forward_cache_experiment_http_header_enabled_(RuntimeEnabledFeaturesBase::is_back_forward_cache_experiment_http_header_enabled_)
    , is_back_forward_cache_not_restored_reasons_enabled_(RuntimeEnabledFeaturesBase::is_back_forward_cache_not_restored_reasons_enabled_)
    , is_background_fetch_enabled_(RuntimeEnabledFeaturesBase::is_background_fetch_enabled_)
    , is_barcode_detector_enabled_(RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_)
    , is_batch_fetch_requests_enabled_(RuntimeEnabledFeaturesBase::is_batch_fetch_requests_enabled_)
    , is_before_match_event_enabled_(RuntimeEnabledFeaturesBase::is_before_match_event_enabled_)
    , is_bidi_caret_affinity_enabled_(RuntimeEnabledFeaturesBase::is_bidi_caret_affinity_enabled_)
    , is_blink_extension_chrome_os_enabled_(RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_enabled_)
    , is_blink_extension_chrome_oshid_enabled_(RuntimeEnabledFeaturesBase::is_blink_extension_chrome_oshid_enabled_)
    , is_blink_extension_chrome_os_window_management_enabled_(RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_window_management_enabled_)
    , is_blink_runtime_call_stats_enabled_(RuntimeEnabledFeaturesBase::is_blink_runtime_call_stats_enabled_)
    , is_blocking_attribute_enabled_(RuntimeEnabledFeaturesBase::is_blocking_attribute_enabled_)
    , is_blocking_focus_without_user_activation_enabled_(RuntimeEnabledFeaturesBase::is_blocking_focus_without_user_activation_enabled_)
    , is_browser_verified_user_activation_keyboard_enabled_(RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_keyboard_enabled_)
    , is_browser_verified_user_activation_mouse_enabled_(RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_mouse_enabled_)
    , is_cache_storage_code_cache_hint_enabled_(RuntimeEnabledFeaturesBase::is_cache_storage_code_cache_hint_enabled_)
    , is_canvas_2d_image_chromium_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_image_chromium_enabled_)
    , is_canvas_2d_layers_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_layers_enabled_)
    , is_canvas_2d_scroll_path_into_view_enabled_(RuntimeEnabledFeaturesBase::is_canvas_2d_scroll_path_into_view_enabled_)
    , is_canvas_color_management_v_2_enabled_(RuntimeEnabledFeaturesBase::is_canvas_color_management_v_2_enabled_)
    , is_canvas_hdr_enabled_(RuntimeEnabledFeaturesBase::is_canvas_hdr_enabled_)
    , is_canvas_image_smoothing_enabled_(RuntimeEnabledFeaturesBase::is_canvas_image_smoothing_enabled_)
    , is_capability_delegation_fullscreen_request_enabled_(RuntimeEnabledFeaturesBase::is_capability_delegation_fullscreen_request_enabled_)
    , is_capture_handle_enabled_(RuntimeEnabledFeaturesBase::is_capture_handle_enabled_)
    , is_check_visibility_enabled_(RuntimeEnabledFeaturesBase::is_check_visibility_enabled_)
    , is_clear_identity_in_can_make_payment_event_enabled_(RuntimeEnabledFeaturesBase::is_clear_identity_in_can_make_payment_event_enabled_)
    , is_click_to_captured_pointer_enabled_(RuntimeEnabledFeaturesBase::is_click_to_captured_pointer_enabled_)
    , is_client_hints_meta_equiv_delegate_ch_enabled_(RuntimeEnabledFeaturesBase::is_client_hints_meta_equiv_delegate_ch_enabled_)
    , is_client_hints_meta_http_equiv_accept_ch_enabled_(RuntimeEnabledFeaturesBase::is_client_hints_meta_http_equiv_accept_ch_enabled_)
    , is_client_hint_third_party_delegation_enabled_(RuntimeEnabledFeaturesBase::is_client_hint_third_party_delegation_enabled_)
    , is_clipboard_custom_formats_enabled_(RuntimeEnabledFeaturesBase::is_clipboard_custom_formats_enabled_)
    , is_clipboard_svg_enabled_(RuntimeEnabledFeaturesBase::is_clipboard_svg_enabled_)
    , is_clipboard_unsanitized_content_enabled_(RuntimeEnabledFeaturesBase::is_clipboard_unsanitized_content_enabled_)
    , is_close_watcher_enabled_(RuntimeEnabledFeaturesBase::is_close_watcher_enabled_)
    , is_cls_scroll_anchoring_enabled_(RuntimeEnabledFeaturesBase::is_cls_scroll_anchoring_enabled_)
    , is_coep_reflection_enabled_(RuntimeEnabledFeaturesBase::is_coep_reflection_enabled_)
    , is_composite_bg_color_animation_enabled_(RuntimeEnabledFeaturesBase::is_composite_bg_color_animation_enabled_)
    , is_composite_box_shadow_animation_enabled_(RuntimeEnabledFeaturesBase::is_composite_box_shadow_animation_enabled_)
    , is_composite_clip_path_animation_enabled_(RuntimeEnabledFeaturesBase::is_composite_clip_path_animation_enabled_)
    , is_composited_selection_update_enabled_(RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_)
    , is_computed_accessibility_info_enabled_(RuntimeEnabledFeaturesBase::is_computed_accessibility_info_enabled_)
    , is_compute_pressure_enabled_(RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_)
    , is_conditional_focus_enabled_(RuntimeEnabledFeaturesBase::is_conditional_focus_enabled_)
    , is_consolidated_movement_xy_enabled_(RuntimeEnabledFeaturesBase::is_consolidated_movement_xy_enabled_)
    , is_contacts_manager_enabled_(RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_)
    , is_contacts_manager_extra_properties_enabled_(RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_)
    , is_content_index_enabled_(RuntimeEnabledFeaturesBase::is_content_index_enabled_)
    , is_content_visibility_auto_state_change_event_enabled_(RuntimeEnabledFeaturesBase::is_content_visibility_auto_state_change_event_enabled_)
    , is_context_menu_enabled_(RuntimeEnabledFeaturesBase::is_context_menu_enabled_)
    , is_cooperative_scheduling_enabled_(RuntimeEnabledFeaturesBase::is_cooperative_scheduling_enabled_)
    , is_cors_rfc_1918_enabled_(RuntimeEnabledFeaturesBase::is_cors_rfc_1918_enabled_)
    , is_cross_origin_opener_policy_reporting_enabled_(RuntimeEnabledFeaturesBase::is_cross_origin_opener_policy_reporting_enabled_)
    , is_css_anchor_positioning_enabled_(RuntimeEnabledFeaturesBase::is_css_anchor_positioning_enabled_)
    , is_css_at_rule_counter_style_image_symbols_enabled_(RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_image_symbols_enabled_)
    , is_css_at_rule_counter_style_speak_as_descriptor_enabled_(RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_speak_as_descriptor_enabled_)
    , is_css_at_supports_always_non_forgiving_parsing_enabled_(RuntimeEnabledFeaturesBase::is_css_at_supports_always_non_forgiving_parsing_enabled_)
    , is_css_calc_simplification_and_serialization_enabled_(RuntimeEnabledFeaturesBase::is_css_calc_simplification_and_serialization_enabled_)
    , is_css_case_sensitive_selector_enabled_(RuntimeEnabledFeaturesBase::is_css_case_sensitive_selector_enabled_)
    , is_css_color_4_enabled_(RuntimeEnabledFeaturesBase::is_css_color_4_enabled_)
    , is_css_color_contrast_enabled_(RuntimeEnabledFeaturesBase::is_css_color_contrast_enabled_)
    , is_css_color_typed_om_enabled_(RuntimeEnabledFeaturesBase::is_css_color_typed_om_enabled_)
    , is_css_container_queries_enabled_(RuntimeEnabledFeaturesBase::is_css_container_queries_enabled_)
    , is_css_container_relative_units_enabled_(RuntimeEnabledFeaturesBase::is_css_container_relative_units_enabled_)
    , is_css_container_skip_style_recalc_enabled_(RuntimeEnabledFeaturesBase::is_css_container_skip_style_recalc_enabled_)
    , is_css_contain_size_1d_enabled_(RuntimeEnabledFeaturesBase::is_css_contain_size_1d_enabled_)
    , is_css_enumerated_custom_properties_enabled_(RuntimeEnabledFeaturesBase::is_css_enumerated_custom_properties_enabled_)
    , is_css_focus_visible_enabled_(RuntimeEnabledFeaturesBase::is_css_focus_visible_enabled_)
    , is_css_foldables_enabled_(RuntimeEnabledFeaturesBase::is_css_foldables_enabled_)
    , is_css_font_face_auto_variable_range_enabled_(RuntimeEnabledFeaturesBase::is_css_font_face_auto_variable_range_enabled_)
    , is_css_font_face_src_tech_parsing_enabled_(RuntimeEnabledFeaturesBase::is_css_font_face_src_tech_parsing_enabled_)
    , is_css_font_family_math_enabled_(RuntimeEnabledFeaturesBase::is_css_font_family_math_enabled_)
    , is_css_font_size_adjust_enabled_(RuntimeEnabledFeaturesBase::is_css_font_size_adjust_enabled_)
    , is_css_grid_template_property_interpolation_enabled_(RuntimeEnabledFeaturesBase::is_css_grid_template_property_interpolation_enabled_)
    , is_css_hex_alpha_color_enabled_(RuntimeEnabledFeaturesBase::is_css_hex_alpha_color_enabled_)
    , is_css_hyphenate_limit_chars_enabled_(RuntimeEnabledFeaturesBase::is_css_hyphenate_limit_chars_enabled_)
    , is_css_ic_unit_enabled_(RuntimeEnabledFeaturesBase::is_css_ic_unit_enabled_)
    , is_css_independent_transform_properties_enabled_(RuntimeEnabledFeaturesBase::is_css_independent_transform_properties_enabled_)
    , is_css_initial_letter_enabled_(RuntimeEnabledFeaturesBase::is_css_initial_letter_enabled_)
    , is_css_last_baseline_enabled_(RuntimeEnabledFeaturesBase::is_css_last_baseline_enabled_)
    , is_css_layout_api_enabled_(RuntimeEnabledFeaturesBase::is_css_layout_api_enabled_)
    , is_css_lh_unit_enabled_(RuntimeEnabledFeaturesBase::is_css_lh_unit_enabled_)
    , is_css_logical_enabled_(RuntimeEnabledFeaturesBase::is_css_logical_enabled_)
    , is_css_logical_overflow_enabled_(RuntimeEnabledFeaturesBase::is_css_logical_overflow_enabled_)
    , is_css_marker_nested_pseudo_element_enabled_(RuntimeEnabledFeaturesBase::is_css_marker_nested_pseudo_element_enabled_)
    , is_css_math_depth_enabled_(RuntimeEnabledFeaturesBase::is_css_math_depth_enabled_)
    , is_css_math_shift_enabled_(RuntimeEnabledFeaturesBase::is_css_math_shift_enabled_)
    , is_css_math_style_enabled_(RuntimeEnabledFeaturesBase::is_css_math_style_enabled_)
    , is_css_math_variant_enabled_(RuntimeEnabledFeaturesBase::is_css_math_variant_enabled_)
    , is_css_media_queries_4_enabled_(RuntimeEnabledFeaturesBase::is_css_media_queries_4_enabled_)
    , is_css_mix_blend_mode_plus_lighter_enabled_(RuntimeEnabledFeaturesBase::is_css_mix_blend_mode_plus_lighter_enabled_)
    , is_css_object_view_box_enabled_(RuntimeEnabledFeaturesBase::is_css_object_view_box_enabled_)
    , is_css_offset_path_ray_enabled_(RuntimeEnabledFeaturesBase::is_css_offset_path_ray_enabled_)
    , is_css_offset_path_ray_contain_enabled_(RuntimeEnabledFeaturesBase::is_css_offset_path_ray_contain_enabled_)
    , is_css_offset_position_anchor_enabled_(RuntimeEnabledFeaturesBase::is_css_offset_position_anchor_enabled_)
    , is_css_overflow_for_replaced_elements_enabled_(RuntimeEnabledFeaturesBase::is_css_overflow_for_replaced_elements_enabled_)
    , is_css_paint_api_arguments_enabled_(RuntimeEnabledFeaturesBase::is_css_paint_api_arguments_enabled_)
    , is_css_picture_in_picture_enabled_(RuntimeEnabledFeaturesBase::is_css_picture_in_picture_enabled_)
    , is_css_position_sticky_static_scroll_position_enabled_(RuntimeEnabledFeaturesBase::is_css_position_sticky_static_scroll_position_enabled_)
    , is_css_pseudo_autofill_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_autofill_enabled_)
    , is_css_pseudo_dir_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_dir_enabled_)
    , is_css_pseudo_has_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_has_enabled_)
    , is_css_pseudo_playing_paused_enabled_(RuntimeEnabledFeaturesBase::is_css_pseudo_playing_paused_enabled_)
    , is_css_scope_enabled_(RuntimeEnabledFeaturesBase::is_css_scope_enabled_)
    , is_css_scrollbars_enabled_(RuntimeEnabledFeaturesBase::is_css_scrollbars_enabled_)
    , is_css_scroll_timeline_enabled_(RuntimeEnabledFeaturesBase::is_css_scroll_timeline_enabled_)
    , is_css_selector_fragment_anchor_enabled_(RuntimeEnabledFeaturesBase::is_css_selector_fragment_anchor_enabled_)
    , is_css_snap_size_enabled_(RuntimeEnabledFeaturesBase::is_css_snap_size_enabled_)
    , is_css_spelling_grammar_errors_enabled_(RuntimeEnabledFeaturesBase::is_css_spelling_grammar_errors_enabled_)
    , is_css_style_queries_enabled_(RuntimeEnabledFeaturesBase::is_css_style_queries_enabled_)
    , is_css_toggles_enabled_(RuntimeEnabledFeaturesBase::is_css_toggles_enabled_)
    , is_css_trigonometric_functions_enabled_(RuntimeEnabledFeaturesBase::is_css_trigonometric_functions_enabled_)
    , is_css_variables_2_image_values_enabled_(RuntimeEnabledFeaturesBase::is_css_variables_2_image_values_enabled_)
    , is_css_variables_2_transform_values_enabled_(RuntimeEnabledFeaturesBase::is_css_variables_2_transform_values_enabled_)
    , is_css_video_dynamic_range_media_queries_enabled_(RuntimeEnabledFeaturesBase::is_css_video_dynamic_range_media_queries_enabled_)
    , is_css_viewport_units_4_enabled_(RuntimeEnabledFeaturesBase::is_css_viewport_units_4_enabled_)
    , is_css_view_timeline_enabled_(RuntimeEnabledFeaturesBase::is_css_view_timeline_enabled_)
    , is_custom_element_default_style_enabled_(RuntimeEnabledFeaturesBase::is_custom_element_default_style_enabled_)
    , is_database_enabled_(RuntimeEnabledFeaturesBase::is_database_enabled_)
    , is_decode_jpeg_420_images_to_yuv_enabled_(RuntimeEnabledFeaturesBase::is_decode_jpeg_420_images_to_yuv_enabled_)
    , is_decode_lossy_web_p_images_to_yuv_enabled_(RuntimeEnabledFeaturesBase::is_decode_lossy_web_p_images_to_yuv_enabled_)
    , is_deferred_shaping_enabled_(RuntimeEnabledFeaturesBase::is_deferred_shaping_enabled_)
    , is_deflate_raw_compression_format_enabled_(RuntimeEnabledFeaturesBase::is_deflate_raw_compression_format_enabled_)
    , is_delegated_ink_trails_enabled_(RuntimeEnabledFeaturesBase::is_delegated_ink_trails_enabled_)
    , is_delivery_type_enabled_(RuntimeEnabledFeaturesBase::is_delivery_type_enabled_)
    , is_desktop_capture_disable_local_echo_control_enabled_(RuntimeEnabledFeaturesBase::is_desktop_capture_disable_local_echo_control_enabled_)
    , is_desktop_pw_as_sub_apps_enabled_(RuntimeEnabledFeaturesBase::is_desktop_pw_as_sub_apps_enabled_)
    , is_device_attributes_enabled_(RuntimeEnabledFeaturesBase::is_device_attributes_enabled_)
    , is_device_orientation_request_permission_enabled_(RuntimeEnabledFeaturesBase::is_device_orientation_request_permission_enabled_)
    , is_device_posture_enabled_(RuntimeEnabledFeaturesBase::is_device_posture_enabled_)
    , is_digital_goods_enabled_(RuntimeEnabledFeaturesBase::is_digital_goods_enabled_)
    , is_digital_goods_v_2_1_enabled_(RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_)
    , is_direct_sockets_enabled_(RuntimeEnabledFeaturesBase::is_direct_sockets_enabled_)
    , is_disable_different_origin_subframe_dialog_suppression_enabled_(RuntimeEnabledFeaturesBase::is_disable_different_origin_subframe_dialog_suppression_enabled_)
    , is_disable_hardware_noise_suppression_enabled_(RuntimeEnabledFeaturesBase::is_disable_hardware_noise_suppression_enabled_)
    , is_display_cutout_api_enabled_(RuntimeEnabledFeaturesBase::is_display_cutout_api_enabled_)
    , is_display_surface_constraint_enabled_(RuntimeEnabledFeaturesBase::is_display_surface_constraint_enabled_)
    , is_document_cookie_enabled_(RuntimeEnabledFeaturesBase::is_document_cookie_enabled_)
    , is_document_domain_enabled_(RuntimeEnabledFeaturesBase::is_document_domain_enabled_)
    , is_document_picture_in_picture_api_enabled_(RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_)
    , is_document_policy_enabled_(RuntimeEnabledFeaturesBase::is_document_policy_enabled_)
    , is_document_policy_document_domain_enabled_(RuntimeEnabledFeaturesBase::is_document_policy_document_domain_enabled_)
    , is_document_policy_negotiation_enabled_(RuntimeEnabledFeaturesBase::is_document_policy_negotiation_enabled_)
    , is_document_policy_sync_xhr_enabled_(RuntimeEnabledFeaturesBase::is_document_policy_sync_xhr_enabled_)
    , is_document_transition_enabled_(RuntimeEnabledFeaturesBase::is_document_transition_enabled_)
    , is_document_write_enabled_(RuntimeEnabledFeaturesBase::is_document_write_enabled_)
    , is_early_hints_preload_for_navigation_opt_in_enabled_(RuntimeEnabledFeaturesBase::is_early_hints_preload_for_navigation_opt_in_enabled_)
    , is_edit_context_enabled_(RuntimeEnabledFeaturesBase::is_edit_context_enabled_)
    , is_element_super_rare_data_enabled_(RuntimeEnabledFeaturesBase::is_element_super_rare_data_enabled_)
    , is_event_path_enabled_(RuntimeEnabledFeaturesBase::is_event_path_enabled_)
    , is_experimental_content_security_policy_features_enabled_(RuntimeEnabledFeaturesBase::is_experimental_content_security_policy_features_enabled_)
    , is_experimental_js_profiler_markers_enabled_(RuntimeEnabledFeaturesBase::is_experimental_js_profiler_markers_enabled_)
    , is_experimental_policies_enabled_(RuntimeEnabledFeaturesBase::is_experimental_policies_enabled_)
    , is_experimental_web_snapshots_enabled_(RuntimeEnabledFeaturesBase::is_experimental_web_snapshots_enabled_)
    , is_extended_text_metrics_enabled_(RuntimeEnabledFeaturesBase::is_extended_text_metrics_enabled_)
    , is_extra_webgl_video_texture_metadata_enabled_(RuntimeEnabledFeaturesBase::is_extra_webgl_video_texture_metadata_enabled_)
    , is_eye_dropper_api_enabled_(RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_)
    , is_face_detector_enabled_(RuntimeEnabledFeaturesBase::is_face_detector_enabled_)
    , is_fake_no_alloc_direct_call_for_testing_enabled_(RuntimeEnabledFeaturesBase::is_fake_no_alloc_direct_call_for_testing_enabled_)
    , is_feature_policy_reporting_enabled_(RuntimeEnabledFeaturesBase::is_feature_policy_reporting_enabled_)
    , is_fed_cm_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_enabled_)
    , is_fed_cm_idp_signin_status_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_idp_signin_status_enabled_)
    , is_fed_cm_idp_signout_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_idp_signout_enabled_)
    , is_fed_cm_iframe_support_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_iframe_support_enabled_)
    , is_fed_cm_multiple_identity_providers_enabled_(RuntimeEnabledFeaturesBase::is_fed_cm_multiple_identity_providers_enabled_)
    , is_fenced_frames_enabled_(RuntimeEnabledFeaturesBase::is_fenced_frames_enabled_)
    , is_fetch_upload_streaming_enabled_(RuntimeEnabledFeaturesBase::is_fetch_upload_streaming_enabled_)
    , is_file_handling_enabled_(RuntimeEnabledFeaturesBase::is_file_handling_enabled_)
    , is_file_handling_icons_enabled_(RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_)
    , is_file_system_enabled_(RuntimeEnabledFeaturesBase::is_file_system_enabled_)
    , is_file_system_access_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_enabled_)
    , is_file_system_access_access_handle_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_access_handle_enabled_)
    , is_file_system_access_api_experimental_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_api_experimental_enabled_)
    , is_file_system_access_local_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_)
    , is_file_system_access_origin_private_enabled_(RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_)
    , is_file_system_sync_access_handle_async_interface_override_enabled_(RuntimeEnabledFeaturesBase::is_file_system_sync_access_handle_async_interface_override_enabled_)
    , is_first_party_sets_enabled_(RuntimeEnabledFeaturesBase::is_first_party_sets_enabled_)
    , is_fixed_elements_dont_overscroll_enabled_(RuntimeEnabledFeaturesBase::is_fixed_elements_dont_overscroll_enabled_)
    , is_fledge_enabled_(RuntimeEnabledFeaturesBase::is_fledge_enabled_)
    , is_fluent_scrollbars_enabled_(RuntimeEnabledFeaturesBase::is_fluent_scrollbars_enabled_)
    , is_focusgroup_enabled_(RuntimeEnabledFeaturesBase::is_focusgroup_enabled_)
    , is_focusless_spatial_navigation_enabled_(RuntimeEnabledFeaturesBase::is_focusless_spatial_navigation_enabled_)
    , is_font_access_enabled_(RuntimeEnabledFeaturesBase::is_font_access_enabled_)
    , is_font_palette_enabled_(RuntimeEnabledFeaturesBase::is_font_palette_enabled_)
    , is_font_src_local_matching_enabled_(RuntimeEnabledFeaturesBase::is_font_src_local_matching_enabled_)
    , is_forced_colors_enabled_(RuntimeEnabledFeaturesBase::is_forced_colors_enabled_)
    , is_forced_colors_preserve_parent_color_enabled_(RuntimeEnabledFeaturesBase::is_forced_colors_preserve_parent_color_enabled_)
    , is_force_eager_measure_memory_enabled_(RuntimeEnabledFeaturesBase::is_force_eager_measure_memory_enabled_)
    , is_force_reduce_motion_enabled_(RuntimeEnabledFeaturesBase::is_force_reduce_motion_enabled_)
    , is_force_taller_select_popup_enabled_(RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_)
    , is_formatted_text_enabled_(RuntimeEnabledFeaturesBase::is_formatted_text_enabled_)
    , is_form_rel_attribute_enabled_(RuntimeEnabledFeaturesBase::is_form_rel_attribute_enabled_)
    , is_fractional_scroll_offsets_enabled_(RuntimeEnabledFeaturesBase::is_fractional_scroll_offsets_enabled_)
    , is_freeze_frames_on_visibility_enabled_(RuntimeEnabledFeaturesBase::is_freeze_frames_on_visibility_enabled_)
    , is_gamepad_button_axis_events_enabled_(RuntimeEnabledFeaturesBase::is_gamepad_button_axis_events_enabled_)
    , is_get_display_media_enabled_(RuntimeEnabledFeaturesBase::is_get_display_media_enabled_)
    , is_get_display_media_set_enabled_(RuntimeEnabledFeaturesBase::is_get_display_media_set_enabled_)
    , is_get_display_media_set_auto_select_all_screens_enabled_(RuntimeEnabledFeaturesBase::is_get_display_media_set_auto_select_all_screens_enabled_)
    , is_group_effect_enabled_(RuntimeEnabledFeaturesBase::is_group_effect_enabled_)
    , is_handwriting_recognition_enabled_(RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_)
    , is_hid_device_forget_enabled_(RuntimeEnabledFeaturesBase::is_hid_device_forget_enabled_)
    , is_highlight_api_enabled_(RuntimeEnabledFeaturesBase::is_highlight_api_enabled_)
    , is_highlight_inheritance_enabled_(RuntimeEnabledFeaturesBase::is_highlight_inheritance_enabled_)
    , is_highlight_overlay_painting_enabled_(RuntimeEnabledFeaturesBase::is_highlight_overlay_painting_enabled_)
    , is_highlight_pointer_events_enabled_(RuntimeEnabledFeaturesBase::is_highlight_pointer_events_enabled_)
    , is_href_translate_enabled_(RuntimeEnabledFeaturesBase::is_href_translate_enabled_)
    , is_html_param_element_url_support_enabled_(RuntimeEnabledFeaturesBase::is_html_param_element_url_support_enabled_)
    , is_html_popup_attribute_enabled_(RuntimeEnabledFeaturesBase::is_html_popup_attribute_enabled_)
    , is_html_select_menu_element_enabled_(RuntimeEnabledFeaturesBase::is_html_select_menu_element_enabled_)
    , is_idb_batch_get_all_enabled_(RuntimeEnabledFeaturesBase::is_idb_batch_get_all_enabled_)
    , is_idle_detection_enabled_(RuntimeEnabledFeaturesBase::is_idle_detection_enabled_)
    , is_implicit_root_scroller_enabled_(RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_)
    , is_inert_attribute_enabled_(RuntimeEnabledFeaturesBase::is_inert_attribute_enabled_)
    , is_infinite_cull_rect_enabled_(RuntimeEnabledFeaturesBase::is_infinite_cull_rect_enabled_)
    , is_input_multiple_fields_ui_enabled_(RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_)
    , is_installed_app_enabled_(RuntimeEnabledFeaturesBase::is_installed_app_enabled_)
    , is_keyboard_accessible_tooltip_enabled_(RuntimeEnabledFeaturesBase::is_keyboard_accessible_tooltip_enabled_)
    , is_keyboard_focusable_scrollers_enabled_(RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_enabled_)
    , is_lang_attribute_aware_form_control_ui_enabled_(RuntimeEnabledFeaturesBase::is_lang_attribute_aware_form_control_ui_enabled_)
    , is_lang_attribute_aware_svg_text_enabled_(RuntimeEnabledFeaturesBase::is_lang_attribute_aware_svg_text_enabled_)
    , is_layout_ng_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_enabled_)
    , is_layout_ng_block_fragmentation_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_block_fragmentation_enabled_)
    , is_layout_ng_block_in_inline_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_block_in_inline_enabled_)
    , is_layout_ng_delay_scroll_offset_clamping_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_delay_scroll_offset_clamping_enabled_)
    , is_layout_ng_flex_fragmentation_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_flex_fragmentation_enabled_)
    , is_layout_ng_foreign_object_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_foreign_object_enabled_)
    , is_layout_ng_frame_set_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_frame_set_enabled_)
    , is_layout_ng_grid_fragmentation_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_grid_fragmentation_enabled_)
    , is_layout_ng_printing_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_printing_enabled_)
    , is_layout_ng_subgrid_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_subgrid_enabled_)
    , is_layout_ng_table_fragmentation_enabled_(RuntimeEnabledFeaturesBase::is_layout_ng_table_fragmentation_enabled_)
    , is_layout_ngvtt_cue_enabled_(RuntimeEnabledFeaturesBase::is_layout_ngvtt_cue_enabled_)
    , is_lazy_frame_loading_enabled_(RuntimeEnabledFeaturesBase::is_lazy_frame_loading_enabled_)
    , is_lazy_frame_visible_load_time_metrics_enabled_(RuntimeEnabledFeaturesBase::is_lazy_frame_visible_load_time_metrics_enabled_)
    , is_lazy_image_loading_enabled_(RuntimeEnabledFeaturesBase::is_lazy_image_loading_enabled_)
    , is_lazy_image_visible_load_time_metrics_enabled_(RuntimeEnabledFeaturesBase::is_lazy_image_visible_load_time_metrics_enabled_)
    , is_lazy_initialize_media_controls_enabled_(RuntimeEnabledFeaturesBase::is_lazy_initialize_media_controls_enabled_)
    , is_lcp_animated_images_web_exposed_enabled_(RuntimeEnabledFeaturesBase::is_lcp_animated_images_web_exposed_enabled_)
    , is_legacy_windows_d_write_font_fallback_enabled_(RuntimeEnabledFeaturesBase::is_legacy_windows_d_write_font_fallback_enabled_)
    , is_machine_learning_common_enabled_(RuntimeEnabledFeaturesBase::is_machine_learning_common_enabled_)
    , is_machine_learning_model_loader_enabled_(RuntimeEnabledFeaturesBase::is_machine_learning_model_loader_enabled_)
    , is_machine_learning_neural_network_enabled_(RuntimeEnabledFeaturesBase::is_machine_learning_neural_network_enabled_)
    , is_managed_configuration_enabled_(RuntimeEnabledFeaturesBase::is_managed_configuration_enabled_)
    , is_mathml_core_enabled_(RuntimeEnabledFeaturesBase::is_mathml_core_enabled_)
    , is_measure_memory_enabled_(RuntimeEnabledFeaturesBase::is_measure_memory_enabled_)
    , is_media_capabilities_dynamic_range_enabled_(RuntimeEnabledFeaturesBase::is_media_capabilities_dynamic_range_enabled_)
    , is_media_capabilities_encoding_info_enabled_(RuntimeEnabledFeaturesBase::is_media_capabilities_encoding_info_enabled_)
    , is_media_capabilities_spatial_audio_enabled_(RuntimeEnabledFeaturesBase::is_media_capabilities_spatial_audio_enabled_)
    , is_media_capture_enabled_(RuntimeEnabledFeaturesBase::is_media_capture_enabled_)
    , is_media_capture_background_blur_enabled_(RuntimeEnabledFeaturesBase::is_media_capture_background_blur_enabled_)
    , is_media_cast_overlay_button_enabled_(RuntimeEnabledFeaturesBase::is_media_cast_overlay_button_enabled_)
    , is_media_controls_expand_gesture_enabled_(RuntimeEnabledFeaturesBase::is_media_controls_expand_gesture_enabled_)
    , is_media_controls_overlay_play_button_enabled_(RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_)
    , is_media_element_volume_greater_than_one_enabled_(RuntimeEnabledFeaturesBase::is_media_element_volume_greater_than_one_enabled_)
    , is_media_engagement_bypass_autoplay_policies_enabled_(RuntimeEnabledFeaturesBase::is_media_engagement_bypass_autoplay_policies_enabled_)
    , is_media_latency_hint_enabled_(RuntimeEnabledFeaturesBase::is_media_latency_hint_enabled_)
    , is_media_query_navigation_controls_enabled_(RuntimeEnabledFeaturesBase::is_media_query_navigation_controls_enabled_)
    , is_media_session_enabled_(RuntimeEnabledFeaturesBase::is_media_session_enabled_)
    , is_media_session_web_rtc_enabled_(RuntimeEnabledFeaturesBase::is_media_session_web_rtc_enabled_)
    , is_media_source_experimental_enabled_(RuntimeEnabledFeaturesBase::is_media_source_experimental_enabled_)
    , is_media_source_extensions_for_webcodecs_enabled_(RuntimeEnabledFeaturesBase::is_media_source_extensions_for_webcodecs_enabled_)
    , is_media_source_in_workers_enabled_(RuntimeEnabledFeaturesBase::is_media_source_in_workers_enabled_)
    , is_media_source_in_workers_using_handle_enabled_(RuntimeEnabledFeaturesBase::is_media_source_in_workers_using_handle_enabled_)
    , is_media_source_new_abort_and_duration_enabled_(RuntimeEnabledFeaturesBase::is_media_source_new_abort_and_duration_enabled_)
    , is_media_source_stable_enabled_(RuntimeEnabledFeaturesBase::is_media_source_stable_enabled_)
    , is_media_stream_track_in_window_enabled_(RuntimeEnabledFeaturesBase::is_media_stream_track_in_window_enabled_)
    , is_media_stream_track_in_worker_enabled_(RuntimeEnabledFeaturesBase::is_media_stream_track_in_worker_enabled_)
    , is_media_stream_track_transfer_enabled_(RuntimeEnabledFeaturesBase::is_media_stream_track_transfer_enabled_)
    , is_middle_click_autoscroll_enabled_(RuntimeEnabledFeaturesBase::is_middle_click_autoscroll_enabled_)
    , is_mobile_layout_theme_enabled_(RuntimeEnabledFeaturesBase::is_mobile_layout_theme_enabled_)
    , is_mojo_js_enabled_(RuntimeEnabledFeaturesBase::is_mojo_js_enabled_)
    , is_mojo_js_test_enabled_(RuntimeEnabledFeaturesBase::is_mojo_js_test_enabled_)
    , is_mouse_subframe_no_implicit_capture_enabled_(RuntimeEnabledFeaturesBase::is_mouse_subframe_no_implicit_capture_enabled_)
    , is_navigation_api_enabled_(RuntimeEnabledFeaturesBase::is_navigation_api_enabled_)
    , is_navigation_id_enabled_(RuntimeEnabledFeaturesBase::is_navigation_id_enabled_)
    , is_navigator_content_utils_enabled_(RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_)
    , is_net_info_downlink_max_enabled_(RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_)
    , is_never_slow_mode_enabled_(RuntimeEnabledFeaturesBase::is_never_slow_mode_enabled_)
    , is_new_flexbox_sizing_enabled_(RuntimeEnabledFeaturesBase::is_new_flexbox_sizing_enabled_)
    , is_no_idle_encoding_for_web_tests_enabled_(RuntimeEnabledFeaturesBase::is_no_idle_encoding_for_web_tests_enabled_)
    , is_notification_constructor_enabled_(RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_)
    , is_notification_content_image_enabled_(RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_)
    , is_notifications_enabled_(RuntimeEnabledFeaturesBase::is_notifications_enabled_)
    , is_notification_triggers_enabled_(RuntimeEnabledFeaturesBase::is_notification_triggers_enabled_)
    , is_off_main_thread_css_paint_enabled_(RuntimeEnabledFeaturesBase::is_off_main_thread_css_paint_enabled_)
    , is_offscreen_canvas_commit_enabled_(RuntimeEnabledFeaturesBase::is_offscreen_canvas_commit_enabled_)
    , is_offset_parent_new_spec_behavior_enabled_(RuntimeEnabledFeaturesBase::is_offset_parent_new_spec_behavior_enabled_)
    , is_on_device_change_enabled_(RuntimeEnabledFeaturesBase::is_on_device_change_enabled_)
    , is_orientation_event_enabled_(RuntimeEnabledFeaturesBase::is_orientation_event_enabled_)
    , is_origin_isolation_header_enabled_(RuntimeEnabledFeaturesBase::is_origin_isolation_header_enabled_)
    , is_origin_policy_enabled_(RuntimeEnabledFeaturesBase::is_origin_policy_enabled_)
    , is_origin_trials_sample_api_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_enabled_)
    , is_origin_trials_sample_api_dependent_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_dependent_enabled_)
    , is_origin_trials_sample_api_deprecation_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_deprecation_enabled_)
    , is_origin_trials_sample_api_expiry_grace_period_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_enabled_)
    , is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_)
    , is_origin_trials_sample_api_implied_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_implied_enabled_)
    , is_origin_trials_sample_api_invalid_os_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_invalid_os_enabled_)
    , is_origin_trials_sample_api_navigation_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_navigation_enabled_)
    , is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_)
    , is_origin_trials_sample_api_persistent_feature_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_feature_enabled_)
    , is_origin_trials_sample_api_third_party_enabled_(RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_third_party_enabled_)
    , is_overscroll_customization_enabled_(RuntimeEnabledFeaturesBase::is_overscroll_customization_enabled_)
    , is_page_freeze_opt_in_enabled_(RuntimeEnabledFeaturesBase::is_page_freeze_opt_in_enabled_)
    , is_page_freeze_opt_out_enabled_(RuntimeEnabledFeaturesBase::is_page_freeze_opt_out_enabled_)
    , is_page_popup_enabled_(RuntimeEnabledFeaturesBase::is_page_popup_enabled_)
    , is_paint_under_invalidation_checking_enabled_(RuntimeEnabledFeaturesBase::is_paint_under_invalidation_checking_enabled_)
    , is_parakeet_enabled_(RuntimeEnabledFeaturesBase::is_parakeet_enabled_)
    , is_parallel_primary_font_enabled_(RuntimeEnabledFeaturesBase::is_parallel_primary_font_enabled_)
    , is_parallel_text_shaping_enabled_(RuntimeEnabledFeaturesBase::is_parallel_text_shaping_enabled_)
    , is_partitioned_cookies_enabled_(RuntimeEnabledFeaturesBase::is_partitioned_cookies_enabled_)
    , is_password_reveal_enabled_(RuntimeEnabledFeaturesBase::is_password_reveal_enabled_)
    , is_payment_app_enabled_(RuntimeEnabledFeaturesBase::is_payment_app_enabled_)
    , is_payment_method_change_event_enabled_(RuntimeEnabledFeaturesBase::is_payment_method_change_event_enabled_)
    , is_payment_request_enabled_(RuntimeEnabledFeaturesBase::is_payment_request_enabled_)
    , is_payment_request_merchant_validation_event_enabled_(RuntimeEnabledFeaturesBase::is_payment_request_merchant_validation_event_enabled_)
    , is_pending_beacon_api_enabled_(RuntimeEnabledFeaturesBase::is_pending_beacon_api_enabled_)
    , is_percent_based_scrolling_enabled_(RuntimeEnabledFeaturesBase::is_percent_based_scrolling_enabled_)
    , is_performance_manager_instrumentation_enabled_(RuntimeEnabledFeaturesBase::is_performance_manager_instrumentation_enabled_)
    , is_periodic_background_sync_enabled_(RuntimeEnabledFeaturesBase::is_periodic_background_sync_enabled_)
    , is_per_method_can_make_payment_quota_enabled_(RuntimeEnabledFeaturesBase::is_per_method_can_make_payment_quota_enabled_)
    , is_permissions_enabled_(RuntimeEnabledFeaturesBase::is_permissions_enabled_)
    , is_permissions_policy_unload_enabled_(RuntimeEnabledFeaturesBase::is_permissions_policy_unload_enabled_)
    , is_permissions_request_revoke_enabled_(RuntimeEnabledFeaturesBase::is_permissions_request_revoke_enabled_)
    , is_picture_in_picture_enabled_(RuntimeEnabledFeaturesBase::is_picture_in_picture_enabled_)
    , is_picture_in_picture_api_enabled_(RuntimeEnabledFeaturesBase::is_picture_in_picture_api_enabled_)
    , is_p_na_cl_enabled_(RuntimeEnabledFeaturesBase::is_p_na_cl_enabled_)
    , is_pointer_lock_options_enabled_(RuntimeEnabledFeaturesBase::is_pointer_lock_options_enabled_)
    , is_portals_enabled_(RuntimeEnabledFeaturesBase::is_portals_enabled_)
    , is_precise_memory_info_enabled_(RuntimeEnabledFeaturesBase::is_precise_memory_info_enabled_)
    , is_prefer_non_composited_scrolling_enabled_(RuntimeEnabledFeaturesBase::is_prefer_non_composited_scrolling_enabled_)
    , is_prefers_color_scheme_client_hint_header_enabled_(RuntimeEnabledFeaturesBase::is_prefers_color_scheme_client_hint_header_enabled_)
    , is_prefers_reduced_data_enabled_(RuntimeEnabledFeaturesBase::is_prefers_reduced_data_enabled_)
    , is_prefers_reduced_motion_client_hint_header_enabled_(RuntimeEnabledFeaturesBase::is_prefers_reduced_motion_client_hint_header_enabled_)
    , is_prefixed_storage_info_enabled_(RuntimeEnabledFeaturesBase::is_prefixed_storage_info_enabled_)
    , is_prefixed_video_fullscreen_enabled_(RuntimeEnabledFeaturesBase::is_prefixed_video_fullscreen_enabled_)
    , is_prerender_2_enabled_(RuntimeEnabledFeaturesBase::is_prerender_2_enabled_)
    , is_prerender_2_related_features_enabled_(RuntimeEnabledFeaturesBase::is_prerender_2_related_features_enabled_)
    , is_presentation_enabled_(RuntimeEnabledFeaturesBase::is_presentation_enabled_)
    , is_priority_hints_enabled_(RuntimeEnabledFeaturesBase::is_priority_hints_enabled_)
    , is_privacy_sandbox_ads_api_s_enabled_(RuntimeEnabledFeaturesBase::is_privacy_sandbox_ads_api_s_enabled_)
    , is_private_network_access_non_secure_contexts_allowed_enabled_(RuntimeEnabledFeaturesBase::is_private_network_access_non_secure_contexts_allowed_enabled_)
    , is_private_network_access_permission_prompt_enabled_(RuntimeEnabledFeaturesBase::is_private_network_access_permission_prompt_enabled_)
    , is_push_messaging_enabled_(RuntimeEnabledFeaturesBase::is_push_messaging_enabled_)
    , is_push_messaging_subscription_change_enabled_(RuntimeEnabledFeaturesBase::is_push_messaging_subscription_change_enabled_)
    , is_quick_intensive_wake_up_throttling_after_loading_enabled_(RuntimeEnabledFeaturesBase::is_quick_intensive_wake_up_throttling_after_loading_enabled_)
    , is_quota_change_enabled_(RuntimeEnabledFeaturesBase::is_quota_change_enabled_)
    , is_reduce_user_agent_minor_version_enabled_(RuntimeEnabledFeaturesBase::is_reduce_user_agent_minor_version_enabled_)
    , is_reduce_user_agent_platform_os_cpu_enabled_(RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_)
    , is_region_capture_enabled_(RuntimeEnabledFeaturesBase::is_region_capture_enabled_)
    , is_remote_playback_enabled_(RuntimeEnabledFeaturesBase::is_remote_playback_enabled_)
    , is_remote_playback_backend_enabled_(RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_)
    , is_remove_mobile_viewport_double_tap_enabled_(RuntimeEnabledFeaturesBase::is_remove_mobile_viewport_double_tap_enabled_)
    , is_render_blocking_status_enabled_(RuntimeEnabledFeaturesBase::is_render_blocking_status_enabled_)
    , is_render_priority_attribute_enabled_(RuntimeEnabledFeaturesBase::is_render_priority_attribute_enabled_)
    , is_resource_timing_response_status_enabled_(RuntimeEnabledFeaturesBase::is_resource_timing_response_status_enabled_)
    , is_restrict_gamepad_access_enabled_(RuntimeEnabledFeaturesBase::is_restrict_gamepad_access_enabled_)
    , is_rtc_audio_jitter_buffer_max_packets_enabled_(RuntimeEnabledFeaturesBase::is_rtc_audio_jitter_buffer_max_packets_enabled_)
    , is_rtc_ice_transport_extension_enabled_(RuntimeEnabledFeaturesBase::is_rtc_ice_transport_extension_enabled_)
    , is_rtc_insertable_streams_enabled_(RuntimeEnabledFeaturesBase::is_rtc_insertable_streams_enabled_)
    , is_rtc_quic_transport_enabled_(RuntimeEnabledFeaturesBase::is_rtc_quic_transport_enabled_)
    , is_rtc_rtp_header_extension_control_enabled_(RuntimeEnabledFeaturesBase::is_rtc_rtp_header_extension_control_enabled_)
    , is_rtc_stats_relative_packet_arrival_delay_enabled_(RuntimeEnabledFeaturesBase::is_rtc_stats_relative_packet_arrival_delay_enabled_)
    , is_rtc_svc_scalability_mode_enabled_(RuntimeEnabledFeaturesBase::is_rtc_svc_scalability_mode_enabled_)
    , is_sanitizer_api_enabled_(RuntimeEnabledFeaturesBase::is_sanitizer_api_enabled_)
    , is_sanitizer_api_v_0_enabled_(RuntimeEnabledFeaturesBase::is_sanitizer_api_v_0_enabled_)
    , is_scoped_custom_element_registry_enabled_(RuntimeEnabledFeaturesBase::is_scoped_custom_element_registry_enabled_)
    , is_scripted_speech_recognition_enabled_(RuntimeEnabledFeaturesBase::is_scripted_speech_recognition_enabled_)
    , is_scripted_speech_synthesis_enabled_(RuntimeEnabledFeaturesBase::is_scripted_speech_synthesis_enabled_)
    , is_script_element_supports_enabled_(RuntimeEnabledFeaturesBase::is_script_element_supports_enabled_)
    , is_scrollbar_width_enabled_(RuntimeEnabledFeaturesBase::is_scrollbar_width_enabled_)
    , is_scroll_customization_enabled_(RuntimeEnabledFeaturesBase::is_scroll_customization_enabled_)
    , is_scroll_end_events_enabled_(RuntimeEnabledFeaturesBase::is_scroll_end_events_enabled_)
    , is_scroll_timeline_enabled_(RuntimeEnabledFeaturesBase::is_scroll_timeline_enabled_)
    , is_scroll_top_left_interop_enabled_(RuntimeEnabledFeaturesBase::is_scroll_top_left_interop_enabled_)
    , is_scroll_update_optimizations_enabled_(RuntimeEnabledFeaturesBase::is_scroll_update_optimizations_enabled_)
    , is_secure_context_fix_for_shared_workers_enabled_(RuntimeEnabledFeaturesBase::is_secure_context_fix_for_shared_workers_enabled_)
    , is_secure_payment_confirmation_enabled_(RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_enabled_)
    , is_secure_payment_confirmation_debug_enabled_(RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_debug_enabled_)
    , is_secure_payment_confirmation_opt_out_enabled_(RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_opt_out_enabled_)
    , is_self_browser_surface_constraint_enabled_(RuntimeEnabledFeaturesBase::is_self_browser_surface_constraint_enabled_)
    , is_send_beacon_throw_for_blob_with_non_simple_type_enabled_(RuntimeEnabledFeaturesBase::is_send_beacon_throw_for_blob_with_non_simple_type_enabled_)
    , is_send_full_user_agent_after_reduction_enabled_(RuntimeEnabledFeaturesBase::is_send_full_user_agent_after_reduction_enabled_)
    , is_send_mouse_events_disabled_form_controls_enabled_(RuntimeEnabledFeaturesBase::is_send_mouse_events_disabled_form_controls_enabled_)
    , is_sensor_extra_classes_enabled_(RuntimeEnabledFeaturesBase::is_sensor_extra_classes_enabled_)
    , is_serial_enabled_(RuntimeEnabledFeaturesBase::is_serial_enabled_)
    , is_serial_port_forget_enabled_(RuntimeEnabledFeaturesBase::is_serial_port_forget_enabled_)
    , is_service_worker_client_lifecycle_state_enabled_(RuntimeEnabledFeaturesBase::is_service_worker_client_lifecycle_state_enabled_)
    , is_shared_array_buffer_enabled_(RuntimeEnabledFeaturesBase::is_shared_array_buffer_enabled_)
    , is_shared_array_buffer_on_desktop_enabled_(RuntimeEnabledFeaturesBase::is_shared_array_buffer_on_desktop_enabled_)
    , is_shared_array_buffer_unrestricted_access_allowed_enabled_(RuntimeEnabledFeaturesBase::is_shared_array_buffer_unrestricted_access_allowed_enabled_)
    , is_shared_autofill_enabled_(RuntimeEnabledFeaturesBase::is_shared_autofill_enabled_)
    , is_shared_storage_api_enabled_(RuntimeEnabledFeaturesBase::is_shared_storage_api_enabled_)
    , is_shared_worker_enabled_(RuntimeEnabledFeaturesBase::is_shared_worker_enabled_)
    , is_signature_based_integrity_enabled_(RuntimeEnabledFeaturesBase::is_signature_based_integrity_enabled_)
    , is_site_initiated_mirroring_enabled_(RuntimeEnabledFeaturesBase::is_site_initiated_mirroring_enabled_)
    , is_skip_ad_enabled_(RuntimeEnabledFeaturesBase::is_skip_ad_enabled_)
    , is_skip_touch_event_filter_enabled_(RuntimeEnabledFeaturesBase::is_skip_touch_event_filter_enabled_)
    , is_soft_navigation_heuristics_enabled_(RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_enabled_)
    , is_speculation_rules_enabled_(RuntimeEnabledFeaturesBase::is_speculation_rules_enabled_)
    , is_speculation_rules_fetch_from_header_enabled_(RuntimeEnabledFeaturesBase::is_speculation_rules_fetch_from_header_enabled_)
    , is_speculation_rules_prefetch_proxy_enabled_(RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_proxy_enabled_)
    , is_speculation_rules_prefetch_with_subresources_enabled_(RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_with_subresources_enabled_)
    , is_srcset_max_density_enabled_(RuntimeEnabledFeaturesBase::is_srcset_max_density_enabled_)
    , is_stable_blink_features_enabled_(RuntimeEnabledFeaturesBase::is_stable_blink_features_enabled_)
    , is_storage_access_api_enabled_(RuntimeEnabledFeaturesBase::is_storage_access_api_enabled_)
    , is_storage_access_api_for_origin_extension_enabled_(RuntimeEnabledFeaturesBase::is_storage_access_api_for_origin_extension_enabled_)
    , is_storage_buckets_enabled_(RuntimeEnabledFeaturesBase::is_storage_buckets_enabled_)
    , is_storage_foundation_api_enabled_(RuntimeEnabledFeaturesBase::is_storage_foundation_api_enabled_)
    , is_strict_mime_types_for_workers_enabled_(RuntimeEnabledFeaturesBase::is_strict_mime_types_for_workers_enabled_)
    , is_stylus_handwriting_enabled_(RuntimeEnabledFeaturesBase::is_stylus_handwriting_enabled_)
    , is_supports_font_format_tech_enabled_(RuntimeEnabledFeaturesBase::is_supports_font_format_tech_enabled_)
    , is_surface_switching_constraint_enabled_(RuntimeEnabledFeaturesBase::is_surface_switching_constraint_enabled_)
    , is_svg_text_ng_enabled_(RuntimeEnabledFeaturesBase::is_svg_text_ng_enabled_)
    , is_synthesized_keyboard_events_for_accessibility_actions_enabled_(RuntimeEnabledFeaturesBase::is_synthesized_keyboard_events_for_accessibility_actions_enabled_)
    , is_system_audio_constraint_enabled_(RuntimeEnabledFeaturesBase::is_system_audio_constraint_enabled_)
    , is_system_wake_lock_enabled_(RuntimeEnabledFeaturesBase::is_system_wake_lock_enabled_)
    , is_test_feature_enabled_(RuntimeEnabledFeaturesBase::is_test_feature_enabled_)
    , is_test_feature_dependent_enabled_(RuntimeEnabledFeaturesBase::is_test_feature_dependent_enabled_)
    , is_test_feature_implied_enabled_(RuntimeEnabledFeaturesBase::is_test_feature_implied_enabled_)
    , is_text_decorating_box_enabled_(RuntimeEnabledFeaturesBase::is_text_decorating_box_enabled_)
    , is_text_detector_enabled_(RuntimeEnabledFeaturesBase::is_text_detector_enabled_)
    , is_text_fragment_api_enabled_(RuntimeEnabledFeaturesBase::is_text_fragment_api_enabled_)
    , is_text_fragment_identifiers_enabled_(RuntimeEnabledFeaturesBase::is_text_fragment_identifiers_enabled_)
    , is_text_fragment_tap_opens_context_menu_enabled_(RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_)
    , is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_(
          RuntimeEnabledFeaturesBase::is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_)
    , is_timer_throttling_for_background_tabs_enabled_(RuntimeEnabledFeaturesBase::is_timer_throttling_for_background_tabs_enabled_)
    , is_time_zone_change_event_enabled_(RuntimeEnabledFeaturesBase::is_time_zone_change_event_enabled_)
    , is_topics_api_enabled_(RuntimeEnabledFeaturesBase::is_topics_api_enabled_)
    , is_touch_action_effective_at_pointer_down_enabled_(RuntimeEnabledFeaturesBase::is_touch_action_effective_at_pointer_down_enabled_)
    , is_touch_drag_and_context_menu_enabled_(RuntimeEnabledFeaturesBase::is_touch_drag_and_context_menu_enabled_)
    , is_touch_drag_on_short_press_enabled_(RuntimeEnabledFeaturesBase::is_touch_drag_on_short_press_enabled_)
    , is_touch_event_feature_detection_enabled_(RuntimeEnabledFeaturesBase::is_touch_event_feature_detection_enabled_)
    , is_translate_service_enabled_(RuntimeEnabledFeaturesBase::is_translate_service_enabled_)
    , is_trusted_type_before_policy_creation_event_enabled_(RuntimeEnabledFeaturesBase::is_trusted_type_before_policy_creation_event_enabled_)
    , is_trusted_types_use_code_like_enabled_(RuntimeEnabledFeaturesBase::is_trusted_types_use_code_like_enabled_)
    , is_trust_tokens_enabled_(RuntimeEnabledFeaturesBase::is_trust_tokens_enabled_)
    , is_trust_tokens_always_allow_issuance_enabled_(RuntimeEnabledFeaturesBase::is_trust_tokens_always_allow_issuance_enabled_)
    , is_u_2_f_security_key_api_enabled_(RuntimeEnabledFeaturesBase::is_u_2_f_security_key_api_enabled_)
    , is_unclosed_form_control_is_invalid_enabled_(RuntimeEnabledFeaturesBase::is_unclosed_form_control_is_invalid_enabled_)
    , is_unexposed_task_ids_enabled_(RuntimeEnabledFeaturesBase::is_unexposed_task_ids_enabled_)
    , is_unrestricted_shared_array_buffer_enabled_(RuntimeEnabledFeaturesBase::is_unrestricted_shared_array_buffer_enabled_)
    , is_url_pattern_compare_component_enabled_(RuntimeEnabledFeaturesBase::is_url_pattern_compare_component_enabled_)
    , is_user_activation_same_origin_visibility_enabled_(RuntimeEnabledFeaturesBase::is_user_activation_same_origin_visibility_enabled_)
    , is_user_agent_client_hint_enabled_(RuntimeEnabledFeaturesBase::is_user_agent_client_hint_enabled_)
    , is_user_agent_reduction_enabled_(RuntimeEnabledFeaturesBase::is_user_agent_reduction_enabled_)
    , is_v8_idle_tasks_enabled_(RuntimeEnabledFeaturesBase::is_v8_idle_tasks_enabled_)
    , is_variable_colrv_1_enabled_(RuntimeEnabledFeaturesBase::is_variable_colrv_1_enabled_)
    , is_video_auto_fullscreen_enabled_(RuntimeEnabledFeaturesBase::is_video_auto_fullscreen_enabled_)
    , is_video_fullscreen_orientation_lock_enabled_(RuntimeEnabledFeaturesBase::is_video_fullscreen_orientation_lock_enabled_)
    , is_video_playback_quality_enabled_(RuntimeEnabledFeaturesBase::is_video_playback_quality_enabled_)
    , is_video_rotate_to_fullscreen_enabled_(RuntimeEnabledFeaturesBase::is_video_rotate_to_fullscreen_enabled_)
    , is_video_track_generator_enabled_(RuntimeEnabledFeaturesBase::is_video_track_generator_enabled_)
    , is_video_track_generator_in_window_enabled_(RuntimeEnabledFeaturesBase::is_video_track_generator_in_window_enabled_)
    , is_video_track_generator_in_worker_enabled_(RuntimeEnabledFeaturesBase::is_video_track_generator_in_worker_enabled_)
    , is_video_wake_lock_optimisation_hidden_muted_enabled_(RuntimeEnabledFeaturesBase::is_video_wake_lock_optimisation_hidden_muted_enabled_)
    , is_viewport_height_client_hint_header_enabled_(RuntimeEnabledFeaturesBase::is_viewport_height_client_hint_header_enabled_)
    , is_viewport_meta_interactive_widget_property_enabled_(RuntimeEnabledFeaturesBase::is_viewport_meta_interactive_widget_property_enabled_)
    , is_viewport_segments_enabled_(RuntimeEnabledFeaturesBase::is_viewport_segments_enabled_)
    , is_visibility_collapse_column_enabled_(RuntimeEnabledFeaturesBase::is_visibility_collapse_column_enabled_)
    , is_visibility_state_entry_enabled_(RuntimeEnabledFeaturesBase::is_visibility_state_entry_enabled_)
    , is_wake_lock_enabled_(RuntimeEnabledFeaturesBase::is_wake_lock_enabled_)
    , is_warn_on_content_visibility_render_access_enabled_(RuntimeEnabledFeaturesBase::is_warn_on_content_visibility_render_access_enabled_)
    , is_web_animations_api_enabled_(RuntimeEnabledFeaturesBase::is_web_animations_api_enabled_)
    , is_web_animations_svg_enabled_(RuntimeEnabledFeaturesBase::is_web_animations_svg_enabled_)
    , is_web_app_dark_mode_enabled_(RuntimeEnabledFeaturesBase::is_web_app_dark_mode_enabled_)
    , is_web_app_launch_handler_enabled_(RuntimeEnabledFeaturesBase::is_web_app_launch_handler_enabled_)
    , is_web_app_launch_queue_enabled_(RuntimeEnabledFeaturesBase::is_web_app_launch_queue_enabled_)
    , is_web_apps_lock_screen_enabled_(RuntimeEnabledFeaturesBase::is_web_apps_lock_screen_enabled_)
    , is_web_app_tab_strip_enabled_(RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_)
    , is_web_app_translations_enabled_(RuntimeEnabledFeaturesBase::is_web_app_translations_enabled_)
    , is_web_app_url_handling_enabled_(RuntimeEnabledFeaturesBase::is_web_app_url_handling_enabled_)
    , is_web_app_window_controls_overlay_enabled_(RuntimeEnabledFeaturesBase::is_web_app_window_controls_overlay_enabled_)
    , is_web_assembly_csp_enabled_(RuntimeEnabledFeaturesBase::is_web_assembly_csp_enabled_)
    , is_web_assembly_exceptions_enabled_(RuntimeEnabledFeaturesBase::is_web_assembly_exceptions_enabled_)
    , is_web_auth_enabled_(RuntimeEnabledFeaturesBase::is_web_auth_enabled_)
    , is_web_auth_authenticator_attachment_enabled_(RuntimeEnabledFeaturesBase::is_web_auth_authenticator_attachment_enabled_)
    , is_web_authentication_conditional_ui_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_conditional_ui_enabled_)
    , is_web_authentication_device_public_key_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_device_public_key_enabled_)
    , is_web_authentication_large_blob_extension_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_large_blob_extension_enabled_)
    , is_web_authentication_remote_desktop_support_enabled_(RuntimeEnabledFeaturesBase::is_web_authentication_remote_desktop_support_enabled_)
    , is_web_bluetooth_enabled_(RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_)
    , is_web_bluetooth_get_devices_enabled_(RuntimeEnabledFeaturesBase::is_web_bluetooth_get_devices_enabled_)
    , is_web_bluetooth_scanning_enabled_(RuntimeEnabledFeaturesBase::is_web_bluetooth_scanning_enabled_)
    , is_web_bluetooth_watch_advertisements_enabled_(RuntimeEnabledFeaturesBase::is_web_bluetooth_watch_advertisements_enabled_)
    , is_webcodecs_enabled_(RuntimeEnabledFeaturesBase::is_webcodecs_enabled_)
    , is_webcodecs_dequeue_event_enabled_(RuntimeEnabledFeaturesBase::is_webcodecs_dequeue_event_enabled_)
    , is_webgl_color_management_enabled_(RuntimeEnabledFeaturesBase::is_webgl_color_management_enabled_)
    , is_webgl_developer_extensions_enabled_(RuntimeEnabledFeaturesBase::is_webgl_developer_extensions_enabled_)
    , is_webgl_draft_extensions_enabled_(RuntimeEnabledFeaturesBase::is_webgl_draft_extensions_enabled_)
    , is_webgl_image_chromium_enabled_(RuntimeEnabledFeaturesBase::is_webgl_image_chromium_enabled_)
    , is_webgpu_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_enabled_)
    , is_webgpu_developer_features_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_developer_features_enabled_)
    , is_webgpu_import_texture_enabled_(RuntimeEnabledFeaturesBase::is_webgpu_import_texture_enabled_)
    , is_web_hid_enabled_(RuntimeEnabledFeaturesBase::is_web_hid_enabled_)
    , is_web_hid_exclusion_filters_option_enabled_(RuntimeEnabledFeaturesBase::is_web_hid_exclusion_filters_option_enabled_)
    , is_web_hid_on_service_workers_enabled_(RuntimeEnabledFeaturesBase::is_web_hid_on_service_workers_enabled_)
    , is_web_kit_scrollbar_styling_enabled_(RuntimeEnabledFeaturesBase::is_web_kit_scrollbar_styling_enabled_)
    , is_web_nfc_enabled_(RuntimeEnabledFeaturesBase::is_web_nfc_enabled_)
    , is_web_nfc_make_read_only_enabled_(RuntimeEnabledFeaturesBase::is_web_nfc_make_read_only_enabled_)
    , is_web_otp_enabled_(RuntimeEnabledFeaturesBase::is_web_otp_enabled_)
    , is_web_otp_assertion_feature_policy_enabled_(RuntimeEnabledFeaturesBase::is_web_otp_assertion_feature_policy_enabled_)
    , is_web_payment_api_csp_enabled_(RuntimeEnabledFeaturesBase::is_web_payment_api_csp_enabled_)
    , is_web_share_enabled_(RuntimeEnabledFeaturesBase::is_web_share_enabled_)
    , is_websocket_stream_enabled_(RuntimeEnabledFeaturesBase::is_websocket_stream_enabled_)
    , is_web_transport_custom_certificates_enabled_(RuntimeEnabledFeaturesBase::is_web_transport_custom_certificates_enabled_)
    , is_web_usb_enabled_(RuntimeEnabledFeaturesBase::is_web_usb_enabled_)
    , is_web_usb_device_forget_enabled_(RuntimeEnabledFeaturesBase::is_web_usb_device_forget_enabled_)
    , is_web_usb_on_dedicated_workers_enabled_(RuntimeEnabledFeaturesBase::is_web_usb_on_dedicated_workers_enabled_)
    , is_web_usb_on_service_workers_enabled_(RuntimeEnabledFeaturesBase::is_web_usb_on_service_workers_enabled_)
    , is_web_vtt_regions_enabled_(RuntimeEnabledFeaturesBase::is_web_vtt_regions_enabled_)
    , is_web_xr_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_enabled_)
    , is_web_xr_anchors_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_anchors_enabled_)
    , is_web_xr_ar_module_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_ar_module_enabled_)
    , is_web_xr_camera_access_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_camera_access_enabled_)
    , is_web_xr_depth_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_depth_enabled_)
    , is_web_xr_hand_input_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_hand_input_enabled_)
    , is_web_xr_hit_test_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_hit_test_enabled_)
    , is_web_xr_hit_test_entity_types_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_hit_test_entity_types_enabled_)
    , is_web_xr_image_tracking_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_image_tracking_enabled_)
    , is_web_xr_light_estimation_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_light_estimation_enabled_)
    , is_web_xr_plane_detection_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_plane_detection_enabled_)
    , is_web_xr_viewport_scale_enabled_(RuntimeEnabledFeaturesBase::is_web_xr_viewport_scale_enabled_)
    , is_wgi_gamepad_trigger_rumble_enabled_(RuntimeEnabledFeaturesBase::is_wgi_gamepad_trigger_rumble_enabled_)
    , is_window_default_status_enabled_(RuntimeEnabledFeaturesBase::is_window_default_status_enabled_)
    , is_window_open_new_popup_behavior_enabled_(RuntimeEnabledFeaturesBase::is_window_open_new_popup_behavior_enabled_)
    , is_window_placement_enabled_(RuntimeEnabledFeaturesBase::is_window_placement_enabled_)
    , is_window_placement_enhanced_screen_labels_enabled_(RuntimeEnabledFeaturesBase::is_window_placement_enhanced_screen_labels_enabled_)
    , is_window_placement_fullscreen_on_screens_change_enabled_(RuntimeEnabledFeaturesBase::is_window_placement_fullscreen_on_screens_change_enabled_)
    , is_zero_copy_tab_capture_enabled_(RuntimeEnabledFeaturesBase::is_zero_copy_tab_capture_enabled_)
{
}

void RuntimeEnabledFeaturesBase::Backup::Restore()
{
    RuntimeEnabledFeaturesBase::is_abort_signal_throw_if_aborted_enabled_ = is_abort_signal_throw_if_aborted_enabled_;
    RuntimeEnabledFeaturesBase::is_abort_signal_timeout_enabled_ = is_abort_signal_timeout_enabled_;
    RuntimeEnabledFeaturesBase::is_accelerated_2d_canvas_enabled_ = is_accelerated_2d_canvas_enabled_;
    RuntimeEnabledFeaturesBase::is_accelerated_small_canvases_enabled_ = is_accelerated_small_canvases_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_aria_touch_passthrough_enabled_ = is_accessibility_aria_touch_passthrough_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_aria_virtual_content_enabled_ = is_accessibility_aria_virtual_content_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_expose_display_none_enabled_ = is_accessibility_expose_display_none_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_expose_html_element_enabled_ = is_accessibility_expose_html_element_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_expose_ignored_nodes_enabled_ = is_accessibility_expose_ignored_nodes_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_object_model_enabled_ = is_accessibility_object_model_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_page_zoom_enabled_ = is_accessibility_page_zoom_enabled_;
    RuntimeEnabledFeaturesBase::is_accessibility_use_ax_position_for_document_markers_enabled_ = is_accessibility_use_ax_position_for_document_markers_enabled_;
    RuntimeEnabledFeaturesBase::is_address_space_enabled_ = is_address_space_enabled_;
    RuntimeEnabledFeaturesBase::is_ad_interest_group_api_enabled_ = is_ad_interest_group_api_enabled_;
    RuntimeEnabledFeaturesBase::is_ad_tagging_enabled_ = is_ad_tagging_enabled_;
    RuntimeEnabledFeaturesBase::is_allow_content_initiated_data_url_navigations_enabled_ = is_allow_content_initiated_data_url_navigations_enabled_;
    RuntimeEnabledFeaturesBase::is_android_downloadable_fonts_matching_enabled_ = is_android_downloadable_fonts_matching_enabled_;
    RuntimeEnabledFeaturesBase::is_animation_worklet_enabled_ = is_animation_worklet_enabled_;
    RuntimeEnabledFeaturesBase::is_anonymous_iframe_enabled_ = is_anonymous_iframe_enabled_;
    RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_enabled_ = is_aom_aria_relationship_properties_enabled_;
    RuntimeEnabledFeaturesBase::is_aria_touch_passthrough_enabled_ = is_aria_touch_passthrough_enabled_;
    RuntimeEnabledFeaturesBase::is_attribution_reporting_enabled_ = is_attribution_reporting_enabled_;
    RuntimeEnabledFeaturesBase::is_audio_context_set_sink_id_enabled_ = is_audio_context_set_sink_id_enabled_;
    RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = is_audio_output_devices_enabled_;
    RuntimeEnabledFeaturesBase::is_audio_video_tracks_enabled_ = is_audio_video_tracks_enabled_;
    RuntimeEnabledFeaturesBase::is_auto_dark_mode_enabled_ = is_auto_dark_mode_enabled_;
    RuntimeEnabledFeaturesBase::is_auto_disable_accessibility_v_2_enabled_ = is_auto_disable_accessibility_v_2_enabled_;
    RuntimeEnabledFeaturesBase::is_autofill_shadow_dom_enabled_ = is_autofill_shadow_dom_enabled_;
    RuntimeEnabledFeaturesBase::is_automation_controlled_enabled_ = is_automation_controlled_enabled_;
    RuntimeEnabledFeaturesBase::is_auto_picture_in_picture_enabled_ = is_auto_picture_in_picture_enabled_;
    RuntimeEnabledFeaturesBase::is_autoplay_ignores_web_audio_enabled_ = is_autoplay_ignores_web_audio_enabled_;
    RuntimeEnabledFeaturesBase::is_backface_visibility_interop_enabled_ = is_backface_visibility_interop_enabled_;
    RuntimeEnabledFeaturesBase::is_back_forward_cache_enabled_ = is_back_forward_cache_enabled_;
    RuntimeEnabledFeaturesBase::is_back_forward_cache_experiment_http_header_enabled_ = is_back_forward_cache_experiment_http_header_enabled_;
    RuntimeEnabledFeaturesBase::is_back_forward_cache_not_restored_reasons_enabled_ = is_back_forward_cache_not_restored_reasons_enabled_;
    RuntimeEnabledFeaturesBase::is_background_fetch_enabled_ = is_background_fetch_enabled_;
    RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = is_barcode_detector_enabled_;
    RuntimeEnabledFeaturesBase::is_batch_fetch_requests_enabled_ = is_batch_fetch_requests_enabled_;
    RuntimeEnabledFeaturesBase::is_before_match_event_enabled_ = is_before_match_event_enabled_;
    RuntimeEnabledFeaturesBase::is_bidi_caret_affinity_enabled_ = is_bidi_caret_affinity_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_enabled_ = is_blink_extension_chrome_os_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_extension_chrome_oshid_enabled_ = is_blink_extension_chrome_oshid_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_window_management_enabled_ = is_blink_extension_chrome_os_window_management_enabled_;
    RuntimeEnabledFeaturesBase::is_blink_runtime_call_stats_enabled_ = is_blink_runtime_call_stats_enabled_;
    RuntimeEnabledFeaturesBase::is_blocking_attribute_enabled_ = is_blocking_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_blocking_focus_without_user_activation_enabled_ = is_blocking_focus_without_user_activation_enabled_;
    RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_keyboard_enabled_ = is_browser_verified_user_activation_keyboard_enabled_;
    RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_mouse_enabled_ = is_browser_verified_user_activation_mouse_enabled_;
    RuntimeEnabledFeaturesBase::is_cache_storage_code_cache_hint_enabled_ = is_cache_storage_code_cache_hint_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_image_chromium_enabled_ = is_canvas_2d_image_chromium_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_layers_enabled_ = is_canvas_2d_layers_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_2d_scroll_path_into_view_enabled_ = is_canvas_2d_scroll_path_into_view_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_color_management_v_2_enabled_ = is_canvas_color_management_v_2_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_hdr_enabled_ = is_canvas_hdr_enabled_;
    RuntimeEnabledFeaturesBase::is_canvas_image_smoothing_enabled_ = is_canvas_image_smoothing_enabled_;
    RuntimeEnabledFeaturesBase::is_capability_delegation_fullscreen_request_enabled_ = is_capability_delegation_fullscreen_request_enabled_;
    RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = is_capture_handle_enabled_;
    RuntimeEnabledFeaturesBase::is_check_visibility_enabled_ = is_check_visibility_enabled_;
    RuntimeEnabledFeaturesBase::is_clear_identity_in_can_make_payment_event_enabled_ = is_clear_identity_in_can_make_payment_event_enabled_;
    RuntimeEnabledFeaturesBase::is_click_to_captured_pointer_enabled_ = is_click_to_captured_pointer_enabled_;
    RuntimeEnabledFeaturesBase::is_client_hints_meta_equiv_delegate_ch_enabled_ = is_client_hints_meta_equiv_delegate_ch_enabled_;
    RuntimeEnabledFeaturesBase::is_client_hints_meta_http_equiv_accept_ch_enabled_ = is_client_hints_meta_http_equiv_accept_ch_enabled_;
    RuntimeEnabledFeaturesBase::is_client_hint_third_party_delegation_enabled_ = is_client_hint_third_party_delegation_enabled_;
    RuntimeEnabledFeaturesBase::is_clipboard_custom_formats_enabled_ = is_clipboard_custom_formats_enabled_;
    RuntimeEnabledFeaturesBase::is_clipboard_svg_enabled_ = is_clipboard_svg_enabled_;
    RuntimeEnabledFeaturesBase::is_clipboard_unsanitized_content_enabled_ = is_clipboard_unsanitized_content_enabled_;
    RuntimeEnabledFeaturesBase::is_close_watcher_enabled_ = is_close_watcher_enabled_;
    RuntimeEnabledFeaturesBase::is_cls_scroll_anchoring_enabled_ = is_cls_scroll_anchoring_enabled_;
    RuntimeEnabledFeaturesBase::is_coep_reflection_enabled_ = is_coep_reflection_enabled_;
    RuntimeEnabledFeaturesBase::is_composite_bg_color_animation_enabled_ = is_composite_bg_color_animation_enabled_;
    RuntimeEnabledFeaturesBase::is_composite_box_shadow_animation_enabled_ = is_composite_box_shadow_animation_enabled_;
    RuntimeEnabledFeaturesBase::is_composite_clip_path_animation_enabled_ = is_composite_clip_path_animation_enabled_;
    RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = is_composited_selection_update_enabled_;
    RuntimeEnabledFeaturesBase::is_computed_accessibility_info_enabled_ = is_computed_accessibility_info_enabled_;
    RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = is_compute_pressure_enabled_;
    RuntimeEnabledFeaturesBase::is_conditional_focus_enabled_ = is_conditional_focus_enabled_;
    RuntimeEnabledFeaturesBase::is_consolidated_movement_xy_enabled_ = is_consolidated_movement_xy_enabled_;
    RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = is_contacts_manager_enabled_;
    RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = is_contacts_manager_extra_properties_enabled_;
    RuntimeEnabledFeaturesBase::is_content_index_enabled_ = is_content_index_enabled_;
    RuntimeEnabledFeaturesBase::is_content_visibility_auto_state_change_event_enabled_ = is_content_visibility_auto_state_change_event_enabled_;
    RuntimeEnabledFeaturesBase::is_context_menu_enabled_ = is_context_menu_enabled_;
    RuntimeEnabledFeaturesBase::is_cooperative_scheduling_enabled_ = is_cooperative_scheduling_enabled_;
    RuntimeEnabledFeaturesBase::is_cors_rfc_1918_enabled_ = is_cors_rfc_1918_enabled_;
    RuntimeEnabledFeaturesBase::is_cross_origin_opener_policy_reporting_enabled_ = is_cross_origin_opener_policy_reporting_enabled_;
    RuntimeEnabledFeaturesBase::is_css_anchor_positioning_enabled_ = is_css_anchor_positioning_enabled_;
    RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_image_symbols_enabled_ = is_css_at_rule_counter_style_image_symbols_enabled_;
    RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_speak_as_descriptor_enabled_ = is_css_at_rule_counter_style_speak_as_descriptor_enabled_;
    RuntimeEnabledFeaturesBase::is_css_at_supports_always_non_forgiving_parsing_enabled_ = is_css_at_supports_always_non_forgiving_parsing_enabled_;
    RuntimeEnabledFeaturesBase::is_css_calc_simplification_and_serialization_enabled_ = is_css_calc_simplification_and_serialization_enabled_;
    RuntimeEnabledFeaturesBase::is_css_case_sensitive_selector_enabled_ = is_css_case_sensitive_selector_enabled_;
    RuntimeEnabledFeaturesBase::is_css_color_4_enabled_ = is_css_color_4_enabled_;
    RuntimeEnabledFeaturesBase::is_css_color_contrast_enabled_ = is_css_color_contrast_enabled_;
    RuntimeEnabledFeaturesBase::is_css_color_typed_om_enabled_ = is_css_color_typed_om_enabled_;
    RuntimeEnabledFeaturesBase::is_css_container_queries_enabled_ = is_css_container_queries_enabled_;
    RuntimeEnabledFeaturesBase::is_css_container_relative_units_enabled_ = is_css_container_relative_units_enabled_;
    RuntimeEnabledFeaturesBase::is_css_container_skip_style_recalc_enabled_ = is_css_container_skip_style_recalc_enabled_;
    RuntimeEnabledFeaturesBase::is_css_contain_size_1d_enabled_ = is_css_contain_size_1d_enabled_;
    RuntimeEnabledFeaturesBase::is_css_enumerated_custom_properties_enabled_ = is_css_enumerated_custom_properties_enabled_;
    RuntimeEnabledFeaturesBase::is_css_focus_visible_enabled_ = is_css_focus_visible_enabled_;
    RuntimeEnabledFeaturesBase::is_css_foldables_enabled_ = is_css_foldables_enabled_;
    RuntimeEnabledFeaturesBase::is_css_font_face_auto_variable_range_enabled_ = is_css_font_face_auto_variable_range_enabled_;
    RuntimeEnabledFeaturesBase::is_css_font_face_src_tech_parsing_enabled_ = is_css_font_face_src_tech_parsing_enabled_;
    RuntimeEnabledFeaturesBase::is_css_font_family_math_enabled_ = is_css_font_family_math_enabled_;
    RuntimeEnabledFeaturesBase::is_css_font_size_adjust_enabled_ = is_css_font_size_adjust_enabled_;
    RuntimeEnabledFeaturesBase::is_css_grid_template_property_interpolation_enabled_ = is_css_grid_template_property_interpolation_enabled_;
    RuntimeEnabledFeaturesBase::is_css_hex_alpha_color_enabled_ = is_css_hex_alpha_color_enabled_;
    RuntimeEnabledFeaturesBase::is_css_hyphenate_limit_chars_enabled_ = is_css_hyphenate_limit_chars_enabled_;
    RuntimeEnabledFeaturesBase::is_css_ic_unit_enabled_ = is_css_ic_unit_enabled_;
    RuntimeEnabledFeaturesBase::is_css_independent_transform_properties_enabled_ = is_css_independent_transform_properties_enabled_;
    RuntimeEnabledFeaturesBase::is_css_initial_letter_enabled_ = is_css_initial_letter_enabled_;
    RuntimeEnabledFeaturesBase::is_css_last_baseline_enabled_ = is_css_last_baseline_enabled_;
    RuntimeEnabledFeaturesBase::is_css_layout_api_enabled_ = is_css_layout_api_enabled_;
    RuntimeEnabledFeaturesBase::is_css_lh_unit_enabled_ = is_css_lh_unit_enabled_;
    RuntimeEnabledFeaturesBase::is_css_logical_enabled_ = is_css_logical_enabled_;
    RuntimeEnabledFeaturesBase::is_css_logical_overflow_enabled_ = is_css_logical_overflow_enabled_;
    RuntimeEnabledFeaturesBase::is_css_marker_nested_pseudo_element_enabled_ = is_css_marker_nested_pseudo_element_enabled_;
    RuntimeEnabledFeaturesBase::is_css_math_depth_enabled_ = is_css_math_depth_enabled_;
    RuntimeEnabledFeaturesBase::is_css_math_shift_enabled_ = is_css_math_shift_enabled_;
    RuntimeEnabledFeaturesBase::is_css_math_style_enabled_ = is_css_math_style_enabled_;
    RuntimeEnabledFeaturesBase::is_css_math_variant_enabled_ = is_css_math_variant_enabled_;
    RuntimeEnabledFeaturesBase::is_css_media_queries_4_enabled_ = is_css_media_queries_4_enabled_;
    RuntimeEnabledFeaturesBase::is_css_mix_blend_mode_plus_lighter_enabled_ = is_css_mix_blend_mode_plus_lighter_enabled_;
    RuntimeEnabledFeaturesBase::is_css_object_view_box_enabled_ = is_css_object_view_box_enabled_;
    RuntimeEnabledFeaturesBase::is_css_offset_path_ray_enabled_ = is_css_offset_path_ray_enabled_;
    RuntimeEnabledFeaturesBase::is_css_offset_path_ray_contain_enabled_ = is_css_offset_path_ray_contain_enabled_;
    RuntimeEnabledFeaturesBase::is_css_offset_position_anchor_enabled_ = is_css_offset_position_anchor_enabled_;
    RuntimeEnabledFeaturesBase::is_css_overflow_for_replaced_elements_enabled_ = is_css_overflow_for_replaced_elements_enabled_;
    RuntimeEnabledFeaturesBase::is_css_paint_api_arguments_enabled_ = is_css_paint_api_arguments_enabled_;
    RuntimeEnabledFeaturesBase::is_css_picture_in_picture_enabled_ = is_css_picture_in_picture_enabled_;
    RuntimeEnabledFeaturesBase::is_css_position_sticky_static_scroll_position_enabled_ = is_css_position_sticky_static_scroll_position_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_autofill_enabled_ = is_css_pseudo_autofill_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_dir_enabled_ = is_css_pseudo_dir_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_has_enabled_ = is_css_pseudo_has_enabled_;
    RuntimeEnabledFeaturesBase::is_css_pseudo_playing_paused_enabled_ = is_css_pseudo_playing_paused_enabled_;
    RuntimeEnabledFeaturesBase::is_css_scope_enabled_ = is_css_scope_enabled_;
    RuntimeEnabledFeaturesBase::is_css_scrollbars_enabled_ = is_css_scrollbars_enabled_;
    RuntimeEnabledFeaturesBase::is_css_scroll_timeline_enabled_ = is_css_scroll_timeline_enabled_;
    RuntimeEnabledFeaturesBase::is_css_selector_fragment_anchor_enabled_ = is_css_selector_fragment_anchor_enabled_;
    RuntimeEnabledFeaturesBase::is_css_snap_size_enabled_ = is_css_snap_size_enabled_;
    RuntimeEnabledFeaturesBase::is_css_spelling_grammar_errors_enabled_ = is_css_spelling_grammar_errors_enabled_;
    RuntimeEnabledFeaturesBase::is_css_style_queries_enabled_ = is_css_style_queries_enabled_;
    RuntimeEnabledFeaturesBase::is_css_toggles_enabled_ = is_css_toggles_enabled_;
    RuntimeEnabledFeaturesBase::is_css_trigonometric_functions_enabled_ = is_css_trigonometric_functions_enabled_;
    RuntimeEnabledFeaturesBase::is_css_variables_2_image_values_enabled_ = is_css_variables_2_image_values_enabled_;
    RuntimeEnabledFeaturesBase::is_css_variables_2_transform_values_enabled_ = is_css_variables_2_transform_values_enabled_;
    RuntimeEnabledFeaturesBase::is_css_video_dynamic_range_media_queries_enabled_ = is_css_video_dynamic_range_media_queries_enabled_;
    RuntimeEnabledFeaturesBase::is_css_viewport_units_4_enabled_ = is_css_viewport_units_4_enabled_;
    RuntimeEnabledFeaturesBase::is_css_view_timeline_enabled_ = is_css_view_timeline_enabled_;
    RuntimeEnabledFeaturesBase::is_custom_element_default_style_enabled_ = is_custom_element_default_style_enabled_;
    RuntimeEnabledFeaturesBase::is_database_enabled_ = is_database_enabled_;
    RuntimeEnabledFeaturesBase::is_decode_jpeg_420_images_to_yuv_enabled_ = is_decode_jpeg_420_images_to_yuv_enabled_;
    RuntimeEnabledFeaturesBase::is_decode_lossy_web_p_images_to_yuv_enabled_ = is_decode_lossy_web_p_images_to_yuv_enabled_;
    RuntimeEnabledFeaturesBase::is_deferred_shaping_enabled_ = is_deferred_shaping_enabled_;
    RuntimeEnabledFeaturesBase::is_deflate_raw_compression_format_enabled_ = is_deflate_raw_compression_format_enabled_;
    RuntimeEnabledFeaturesBase::is_delegated_ink_trails_enabled_ = is_delegated_ink_trails_enabled_;
    RuntimeEnabledFeaturesBase::is_delivery_type_enabled_ = is_delivery_type_enabled_;
    RuntimeEnabledFeaturesBase::is_desktop_capture_disable_local_echo_control_enabled_ = is_desktop_capture_disable_local_echo_control_enabled_;
    RuntimeEnabledFeaturesBase::is_desktop_pw_as_sub_apps_enabled_ = is_desktop_pw_as_sub_apps_enabled_;
    RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = is_device_attributes_enabled_;
    RuntimeEnabledFeaturesBase::is_device_orientation_request_permission_enabled_ = is_device_orientation_request_permission_enabled_;
    RuntimeEnabledFeaturesBase::is_device_posture_enabled_ = is_device_posture_enabled_;
    RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = is_digital_goods_enabled_;
    RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = is_digital_goods_v_2_1_enabled_;
    RuntimeEnabledFeaturesBase::is_direct_sockets_enabled_ = is_direct_sockets_enabled_;
    RuntimeEnabledFeaturesBase::is_disable_different_origin_subframe_dialog_suppression_enabled_ = is_disable_different_origin_subframe_dialog_suppression_enabled_;
    RuntimeEnabledFeaturesBase::is_disable_hardware_noise_suppression_enabled_ = is_disable_hardware_noise_suppression_enabled_;
    RuntimeEnabledFeaturesBase::is_display_cutout_api_enabled_ = is_display_cutout_api_enabled_;
    RuntimeEnabledFeaturesBase::is_display_surface_constraint_enabled_ = is_display_surface_constraint_enabled_;
    RuntimeEnabledFeaturesBase::is_document_cookie_enabled_ = is_document_cookie_enabled_;
    RuntimeEnabledFeaturesBase::is_document_domain_enabled_ = is_document_domain_enabled_;
    RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = is_document_picture_in_picture_api_enabled_;
    RuntimeEnabledFeaturesBase::is_document_policy_enabled_ = is_document_policy_enabled_;
    RuntimeEnabledFeaturesBase::is_document_policy_document_domain_enabled_ = is_document_policy_document_domain_enabled_;
    RuntimeEnabledFeaturesBase::is_document_policy_negotiation_enabled_ = is_document_policy_negotiation_enabled_;
    RuntimeEnabledFeaturesBase::is_document_policy_sync_xhr_enabled_ = is_document_policy_sync_xhr_enabled_;
    RuntimeEnabledFeaturesBase::is_document_transition_enabled_ = is_document_transition_enabled_;
    RuntimeEnabledFeaturesBase::is_document_write_enabled_ = is_document_write_enabled_;
    RuntimeEnabledFeaturesBase::is_early_hints_preload_for_navigation_opt_in_enabled_ = is_early_hints_preload_for_navigation_opt_in_enabled_;
    RuntimeEnabledFeaturesBase::is_edit_context_enabled_ = is_edit_context_enabled_;
    RuntimeEnabledFeaturesBase::is_element_super_rare_data_enabled_ = is_element_super_rare_data_enabled_;
    RuntimeEnabledFeaturesBase::is_event_path_enabled_ = is_event_path_enabled_;
    RuntimeEnabledFeaturesBase::is_experimental_content_security_policy_features_enabled_ = is_experimental_content_security_policy_features_enabled_;
    RuntimeEnabledFeaturesBase::is_experimental_js_profiler_markers_enabled_ = is_experimental_js_profiler_markers_enabled_;
    RuntimeEnabledFeaturesBase::is_experimental_policies_enabled_ = is_experimental_policies_enabled_;
    RuntimeEnabledFeaturesBase::is_experimental_web_snapshots_enabled_ = is_experimental_web_snapshots_enabled_;
    RuntimeEnabledFeaturesBase::is_extended_text_metrics_enabled_ = is_extended_text_metrics_enabled_;
    RuntimeEnabledFeaturesBase::is_extra_webgl_video_texture_metadata_enabled_ = is_extra_webgl_video_texture_metadata_enabled_;
    RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = is_eye_dropper_api_enabled_;
    RuntimeEnabledFeaturesBase::is_face_detector_enabled_ = is_face_detector_enabled_;
    RuntimeEnabledFeaturesBase::is_fake_no_alloc_direct_call_for_testing_enabled_ = is_fake_no_alloc_direct_call_for_testing_enabled_;
    RuntimeEnabledFeaturesBase::is_feature_policy_reporting_enabled_ = is_feature_policy_reporting_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_enabled_ = is_fed_cm_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_idp_signin_status_enabled_ = is_fed_cm_idp_signin_status_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_idp_signout_enabled_ = is_fed_cm_idp_signout_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_iframe_support_enabled_ = is_fed_cm_iframe_support_enabled_;
    RuntimeEnabledFeaturesBase::is_fed_cm_multiple_identity_providers_enabled_ = is_fed_cm_multiple_identity_providers_enabled_;
    RuntimeEnabledFeaturesBase::is_fenced_frames_enabled_ = is_fenced_frames_enabled_;
    RuntimeEnabledFeaturesBase::is_fetch_upload_streaming_enabled_ = is_fetch_upload_streaming_enabled_;
    RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = is_file_handling_enabled_;
    RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = is_file_handling_icons_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_enabled_ = is_file_system_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_enabled_ = is_file_system_access_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_access_handle_enabled_ = is_file_system_access_access_handle_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_api_experimental_enabled_ = is_file_system_access_api_experimental_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = is_file_system_access_local_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = is_file_system_access_origin_private_enabled_;
    RuntimeEnabledFeaturesBase::is_file_system_sync_access_handle_async_interface_override_enabled_ = is_file_system_sync_access_handle_async_interface_override_enabled_;
    RuntimeEnabledFeaturesBase::is_first_party_sets_enabled_ = is_first_party_sets_enabled_;
    RuntimeEnabledFeaturesBase::is_fixed_elements_dont_overscroll_enabled_ = is_fixed_elements_dont_overscroll_enabled_;
    RuntimeEnabledFeaturesBase::is_fledge_enabled_ = is_fledge_enabled_;
    RuntimeEnabledFeaturesBase::is_fluent_scrollbars_enabled_ = is_fluent_scrollbars_enabled_;
    RuntimeEnabledFeaturesBase::is_focusgroup_enabled_ = is_focusgroup_enabled_;
    RuntimeEnabledFeaturesBase::is_focusless_spatial_navigation_enabled_ = is_focusless_spatial_navigation_enabled_;
    RuntimeEnabledFeaturesBase::is_font_access_enabled_ = is_font_access_enabled_;
    RuntimeEnabledFeaturesBase::is_font_palette_enabled_ = is_font_palette_enabled_;
    RuntimeEnabledFeaturesBase::is_font_src_local_matching_enabled_ = is_font_src_local_matching_enabled_;
    RuntimeEnabledFeaturesBase::is_forced_colors_enabled_ = is_forced_colors_enabled_;
    RuntimeEnabledFeaturesBase::is_forced_colors_preserve_parent_color_enabled_ = is_forced_colors_preserve_parent_color_enabled_;
    RuntimeEnabledFeaturesBase::is_force_eager_measure_memory_enabled_ = is_force_eager_measure_memory_enabled_;
    RuntimeEnabledFeaturesBase::is_force_reduce_motion_enabled_ = is_force_reduce_motion_enabled_;
    RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = is_force_taller_select_popup_enabled_;
    RuntimeEnabledFeaturesBase::is_formatted_text_enabled_ = is_formatted_text_enabled_;
    RuntimeEnabledFeaturesBase::is_form_rel_attribute_enabled_ = is_form_rel_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_fractional_scroll_offsets_enabled_ = is_fractional_scroll_offsets_enabled_;
    RuntimeEnabledFeaturesBase::is_freeze_frames_on_visibility_enabled_ = is_freeze_frames_on_visibility_enabled_;
    RuntimeEnabledFeaturesBase::is_gamepad_button_axis_events_enabled_ = is_gamepad_button_axis_events_enabled_;
    RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = is_get_display_media_enabled_;
    RuntimeEnabledFeaturesBase::is_get_display_media_set_enabled_ = is_get_display_media_set_enabled_;
    RuntimeEnabledFeaturesBase::is_get_display_media_set_auto_select_all_screens_enabled_ = is_get_display_media_set_auto_select_all_screens_enabled_;
    RuntimeEnabledFeaturesBase::is_group_effect_enabled_ = is_group_effect_enabled_;
    RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = is_handwriting_recognition_enabled_;
    RuntimeEnabledFeaturesBase::is_hid_device_forget_enabled_ = is_hid_device_forget_enabled_;
    RuntimeEnabledFeaturesBase::is_highlight_api_enabled_ = is_highlight_api_enabled_;
    RuntimeEnabledFeaturesBase::is_highlight_inheritance_enabled_ = is_highlight_inheritance_enabled_;
    RuntimeEnabledFeaturesBase::is_highlight_overlay_painting_enabled_ = is_highlight_overlay_painting_enabled_;
    RuntimeEnabledFeaturesBase::is_highlight_pointer_events_enabled_ = is_highlight_pointer_events_enabled_;
    RuntimeEnabledFeaturesBase::is_href_translate_enabled_ = is_href_translate_enabled_;
    RuntimeEnabledFeaturesBase::is_html_param_element_url_support_enabled_ = is_html_param_element_url_support_enabled_;
    RuntimeEnabledFeaturesBase::is_html_popup_attribute_enabled_ = is_html_popup_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_html_select_menu_element_enabled_ = is_html_select_menu_element_enabled_;
    RuntimeEnabledFeaturesBase::is_idb_batch_get_all_enabled_ = is_idb_batch_get_all_enabled_;
    RuntimeEnabledFeaturesBase::is_idle_detection_enabled_ = is_idle_detection_enabled_;
    RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = is_implicit_root_scroller_enabled_;
    RuntimeEnabledFeaturesBase::is_inert_attribute_enabled_ = is_inert_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_infinite_cull_rect_enabled_ = is_infinite_cull_rect_enabled_;
    RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = is_input_multiple_fields_ui_enabled_;
    RuntimeEnabledFeaturesBase::is_installed_app_enabled_ = is_installed_app_enabled_;
    RuntimeEnabledFeaturesBase::is_keyboard_accessible_tooltip_enabled_ = is_keyboard_accessible_tooltip_enabled_;
    RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_enabled_ = is_keyboard_focusable_scrollers_enabled_;
    RuntimeEnabledFeaturesBase::is_lang_attribute_aware_form_control_ui_enabled_ = is_lang_attribute_aware_form_control_ui_enabled_;
    RuntimeEnabledFeaturesBase::is_lang_attribute_aware_svg_text_enabled_ = is_lang_attribute_aware_svg_text_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_enabled_ = is_layout_ng_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_block_fragmentation_enabled_ = is_layout_ng_block_fragmentation_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_block_in_inline_enabled_ = is_layout_ng_block_in_inline_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_delay_scroll_offset_clamping_enabled_ = is_layout_ng_delay_scroll_offset_clamping_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_flex_fragmentation_enabled_ = is_layout_ng_flex_fragmentation_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_foreign_object_enabled_ = is_layout_ng_foreign_object_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_frame_set_enabled_ = is_layout_ng_frame_set_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_grid_fragmentation_enabled_ = is_layout_ng_grid_fragmentation_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_printing_enabled_ = is_layout_ng_printing_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_subgrid_enabled_ = is_layout_ng_subgrid_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ng_table_fragmentation_enabled_ = is_layout_ng_table_fragmentation_enabled_;
    RuntimeEnabledFeaturesBase::is_layout_ngvtt_cue_enabled_ = is_layout_ngvtt_cue_enabled_;
    RuntimeEnabledFeaturesBase::is_lazy_frame_loading_enabled_ = is_lazy_frame_loading_enabled_;
    RuntimeEnabledFeaturesBase::is_lazy_frame_visible_load_time_metrics_enabled_ = is_lazy_frame_visible_load_time_metrics_enabled_;
    RuntimeEnabledFeaturesBase::is_lazy_image_loading_enabled_ = is_lazy_image_loading_enabled_;
    RuntimeEnabledFeaturesBase::is_lazy_image_visible_load_time_metrics_enabled_ = is_lazy_image_visible_load_time_metrics_enabled_;
    RuntimeEnabledFeaturesBase::is_lazy_initialize_media_controls_enabled_ = is_lazy_initialize_media_controls_enabled_;
    RuntimeEnabledFeaturesBase::is_lcp_animated_images_web_exposed_enabled_ = is_lcp_animated_images_web_exposed_enabled_;
    RuntimeEnabledFeaturesBase::is_legacy_windows_d_write_font_fallback_enabled_ = is_legacy_windows_d_write_font_fallback_enabled_;
    RuntimeEnabledFeaturesBase::is_machine_learning_common_enabled_ = is_machine_learning_common_enabled_;
    RuntimeEnabledFeaturesBase::is_machine_learning_model_loader_enabled_ = is_machine_learning_model_loader_enabled_;
    RuntimeEnabledFeaturesBase::is_machine_learning_neural_network_enabled_ = is_machine_learning_neural_network_enabled_;
    RuntimeEnabledFeaturesBase::is_managed_configuration_enabled_ = is_managed_configuration_enabled_;
    RuntimeEnabledFeaturesBase::is_mathml_core_enabled_ = is_mathml_core_enabled_;
    RuntimeEnabledFeaturesBase::is_measure_memory_enabled_ = is_measure_memory_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capabilities_dynamic_range_enabled_ = is_media_capabilities_dynamic_range_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capabilities_encoding_info_enabled_ = is_media_capabilities_encoding_info_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capabilities_spatial_audio_enabled_ = is_media_capabilities_spatial_audio_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = is_media_capture_enabled_;
    RuntimeEnabledFeaturesBase::is_media_capture_background_blur_enabled_ = is_media_capture_background_blur_enabled_;
    RuntimeEnabledFeaturesBase::is_media_cast_overlay_button_enabled_ = is_media_cast_overlay_button_enabled_;
    RuntimeEnabledFeaturesBase::is_media_controls_expand_gesture_enabled_ = is_media_controls_expand_gesture_enabled_;
    RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = is_media_controls_overlay_play_button_enabled_;
    RuntimeEnabledFeaturesBase::is_media_element_volume_greater_than_one_enabled_ = is_media_element_volume_greater_than_one_enabled_;
    RuntimeEnabledFeaturesBase::is_media_engagement_bypass_autoplay_policies_enabled_ = is_media_engagement_bypass_autoplay_policies_enabled_;
    RuntimeEnabledFeaturesBase::is_media_latency_hint_enabled_ = is_media_latency_hint_enabled_;
    RuntimeEnabledFeaturesBase::is_media_query_navigation_controls_enabled_ = is_media_query_navigation_controls_enabled_;
    RuntimeEnabledFeaturesBase::is_media_session_enabled_ = is_media_session_enabled_;
    RuntimeEnabledFeaturesBase::is_media_session_web_rtc_enabled_ = is_media_session_web_rtc_enabled_;
    RuntimeEnabledFeaturesBase::is_media_source_experimental_enabled_ = is_media_source_experimental_enabled_;
    RuntimeEnabledFeaturesBase::is_media_source_extensions_for_webcodecs_enabled_ = is_media_source_extensions_for_webcodecs_enabled_;
    RuntimeEnabledFeaturesBase::is_media_source_in_workers_enabled_ = is_media_source_in_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_media_source_in_workers_using_handle_enabled_ = is_media_source_in_workers_using_handle_enabled_;
    RuntimeEnabledFeaturesBase::is_media_source_new_abort_and_duration_enabled_ = is_media_source_new_abort_and_duration_enabled_;
    RuntimeEnabledFeaturesBase::is_media_source_stable_enabled_ = is_media_source_stable_enabled_;
    RuntimeEnabledFeaturesBase::is_media_stream_track_in_window_enabled_ = is_media_stream_track_in_window_enabled_;
    RuntimeEnabledFeaturesBase::is_media_stream_track_in_worker_enabled_ = is_media_stream_track_in_worker_enabled_;
    RuntimeEnabledFeaturesBase::is_media_stream_track_transfer_enabled_ = is_media_stream_track_transfer_enabled_;
    RuntimeEnabledFeaturesBase::is_middle_click_autoscroll_enabled_ = is_middle_click_autoscroll_enabled_;
    RuntimeEnabledFeaturesBase::is_mobile_layout_theme_enabled_ = is_mobile_layout_theme_enabled_;
    RuntimeEnabledFeaturesBase::is_mojo_js_enabled_ = is_mojo_js_enabled_;
    RuntimeEnabledFeaturesBase::is_mojo_js_test_enabled_ = is_mojo_js_test_enabled_;
    RuntimeEnabledFeaturesBase::is_mouse_subframe_no_implicit_capture_enabled_ = is_mouse_subframe_no_implicit_capture_enabled_;
    RuntimeEnabledFeaturesBase::is_navigation_api_enabled_ = is_navigation_api_enabled_;
    RuntimeEnabledFeaturesBase::is_navigation_id_enabled_ = is_navigation_id_enabled_;
    RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = is_navigator_content_utils_enabled_;
    RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = is_net_info_downlink_max_enabled_;
    RuntimeEnabledFeaturesBase::is_never_slow_mode_enabled_ = is_never_slow_mode_enabled_;
    RuntimeEnabledFeaturesBase::is_new_flexbox_sizing_enabled_ = is_new_flexbox_sizing_enabled_;
    RuntimeEnabledFeaturesBase::is_no_idle_encoding_for_web_tests_enabled_ = is_no_idle_encoding_for_web_tests_enabled_;
    RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = is_notification_constructor_enabled_;
    RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = is_notification_content_image_enabled_;
    RuntimeEnabledFeaturesBase::is_notifications_enabled_ = is_notifications_enabled_;
    RuntimeEnabledFeaturesBase::is_notification_triggers_enabled_ = is_notification_triggers_enabled_;
    RuntimeEnabledFeaturesBase::is_off_main_thread_css_paint_enabled_ = is_off_main_thread_css_paint_enabled_;
    RuntimeEnabledFeaturesBase::is_offscreen_canvas_commit_enabled_ = is_offscreen_canvas_commit_enabled_;
    RuntimeEnabledFeaturesBase::is_offset_parent_new_spec_behavior_enabled_ = is_offset_parent_new_spec_behavior_enabled_;
    RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = is_on_device_change_enabled_;
    RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = is_orientation_event_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_isolation_header_enabled_ = is_origin_isolation_header_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_policy_enabled_ = is_origin_policy_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_enabled_ = is_origin_trials_sample_api_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_dependent_enabled_ = is_origin_trials_sample_api_dependent_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_deprecation_enabled_ = is_origin_trials_sample_api_deprecation_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_enabled_ = is_origin_trials_sample_api_expiry_grace_period_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_ = is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_implied_enabled_ = is_origin_trials_sample_api_implied_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_invalid_os_enabled_ = is_origin_trials_sample_api_invalid_os_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_navigation_enabled_ = is_origin_trials_sample_api_navigation_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_ = is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_feature_enabled_ = is_origin_trials_sample_api_persistent_feature_enabled_;
    RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_third_party_enabled_ = is_origin_trials_sample_api_third_party_enabled_;
    RuntimeEnabledFeaturesBase::is_overscroll_customization_enabled_ = is_overscroll_customization_enabled_;
    RuntimeEnabledFeaturesBase::is_page_freeze_opt_in_enabled_ = is_page_freeze_opt_in_enabled_;
    RuntimeEnabledFeaturesBase::is_page_freeze_opt_out_enabled_ = is_page_freeze_opt_out_enabled_;
    RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = is_page_popup_enabled_;
    RuntimeEnabledFeaturesBase::is_paint_under_invalidation_checking_enabled_ = is_paint_under_invalidation_checking_enabled_;
    RuntimeEnabledFeaturesBase::is_parakeet_enabled_ = is_parakeet_enabled_;
    RuntimeEnabledFeaturesBase::is_parallel_primary_font_enabled_ = is_parallel_primary_font_enabled_;
    RuntimeEnabledFeaturesBase::is_parallel_text_shaping_enabled_ = is_parallel_text_shaping_enabled_;
    RuntimeEnabledFeaturesBase::is_partitioned_cookies_enabled_ = is_partitioned_cookies_enabled_;
    RuntimeEnabledFeaturesBase::is_password_reveal_enabled_ = is_password_reveal_enabled_;
    RuntimeEnabledFeaturesBase::is_payment_app_enabled_ = is_payment_app_enabled_;
    RuntimeEnabledFeaturesBase::is_payment_method_change_event_enabled_ = is_payment_method_change_event_enabled_;
    RuntimeEnabledFeaturesBase::is_payment_request_enabled_ = is_payment_request_enabled_;
    RuntimeEnabledFeaturesBase::is_payment_request_merchant_validation_event_enabled_ = is_payment_request_merchant_validation_event_enabled_;
    RuntimeEnabledFeaturesBase::is_pending_beacon_api_enabled_ = is_pending_beacon_api_enabled_;
    RuntimeEnabledFeaturesBase::is_percent_based_scrolling_enabled_ = is_percent_based_scrolling_enabled_;
    RuntimeEnabledFeaturesBase::is_performance_manager_instrumentation_enabled_ = is_performance_manager_instrumentation_enabled_;
    RuntimeEnabledFeaturesBase::is_periodic_background_sync_enabled_ = is_periodic_background_sync_enabled_;
    RuntimeEnabledFeaturesBase::is_per_method_can_make_payment_quota_enabled_ = is_per_method_can_make_payment_quota_enabled_;
    RuntimeEnabledFeaturesBase::is_permissions_enabled_ = is_permissions_enabled_;
    RuntimeEnabledFeaturesBase::is_permissions_policy_unload_enabled_ = is_permissions_policy_unload_enabled_;
    RuntimeEnabledFeaturesBase::is_permissions_request_revoke_enabled_ = is_permissions_request_revoke_enabled_;
    RuntimeEnabledFeaturesBase::is_picture_in_picture_enabled_ = is_picture_in_picture_enabled_;
    RuntimeEnabledFeaturesBase::is_picture_in_picture_api_enabled_ = is_picture_in_picture_api_enabled_;
    RuntimeEnabledFeaturesBase::is_p_na_cl_enabled_ = is_p_na_cl_enabled_;
    RuntimeEnabledFeaturesBase::is_pointer_lock_options_enabled_ = is_pointer_lock_options_enabled_;
    RuntimeEnabledFeaturesBase::is_portals_enabled_ = is_portals_enabled_;
    RuntimeEnabledFeaturesBase::is_precise_memory_info_enabled_ = is_precise_memory_info_enabled_;
    RuntimeEnabledFeaturesBase::is_prefer_non_composited_scrolling_enabled_ = is_prefer_non_composited_scrolling_enabled_;
    RuntimeEnabledFeaturesBase::is_prefers_color_scheme_client_hint_header_enabled_ = is_prefers_color_scheme_client_hint_header_enabled_;
    RuntimeEnabledFeaturesBase::is_prefers_reduced_data_enabled_ = is_prefers_reduced_data_enabled_;
    RuntimeEnabledFeaturesBase::is_prefers_reduced_motion_client_hint_header_enabled_ = is_prefers_reduced_motion_client_hint_header_enabled_;
    RuntimeEnabledFeaturesBase::is_prefixed_storage_info_enabled_ = is_prefixed_storage_info_enabled_;
    RuntimeEnabledFeaturesBase::is_prefixed_video_fullscreen_enabled_ = is_prefixed_video_fullscreen_enabled_;
    RuntimeEnabledFeaturesBase::is_prerender_2_enabled_ = is_prerender_2_enabled_;
    RuntimeEnabledFeaturesBase::is_prerender_2_related_features_enabled_ = is_prerender_2_related_features_enabled_;
    RuntimeEnabledFeaturesBase::is_presentation_enabled_ = is_presentation_enabled_;
    RuntimeEnabledFeaturesBase::is_priority_hints_enabled_ = is_priority_hints_enabled_;
    RuntimeEnabledFeaturesBase::is_privacy_sandbox_ads_api_s_enabled_ = is_privacy_sandbox_ads_api_s_enabled_;
    RuntimeEnabledFeaturesBase::is_private_network_access_non_secure_contexts_allowed_enabled_ = is_private_network_access_non_secure_contexts_allowed_enabled_;
    RuntimeEnabledFeaturesBase::is_private_network_access_permission_prompt_enabled_ = is_private_network_access_permission_prompt_enabled_;
    RuntimeEnabledFeaturesBase::is_push_messaging_enabled_ = is_push_messaging_enabled_;
    RuntimeEnabledFeaturesBase::is_push_messaging_subscription_change_enabled_ = is_push_messaging_subscription_change_enabled_;
    RuntimeEnabledFeaturesBase::is_quick_intensive_wake_up_throttling_after_loading_enabled_ = is_quick_intensive_wake_up_throttling_after_loading_enabled_;
    RuntimeEnabledFeaturesBase::is_quota_change_enabled_ = is_quota_change_enabled_;
    RuntimeEnabledFeaturesBase::is_reduce_user_agent_minor_version_enabled_ = is_reduce_user_agent_minor_version_enabled_;
    RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = is_reduce_user_agent_platform_os_cpu_enabled_;
    RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = is_region_capture_enabled_;
    RuntimeEnabledFeaturesBase::is_remote_playback_enabled_ = is_remote_playback_enabled_;
    RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = is_remote_playback_backend_enabled_;
    RuntimeEnabledFeaturesBase::is_remove_mobile_viewport_double_tap_enabled_ = is_remove_mobile_viewport_double_tap_enabled_;
    RuntimeEnabledFeaturesBase::is_render_blocking_status_enabled_ = is_render_blocking_status_enabled_;
    RuntimeEnabledFeaturesBase::is_render_priority_attribute_enabled_ = is_render_priority_attribute_enabled_;
    RuntimeEnabledFeaturesBase::is_resource_timing_response_status_enabled_ = is_resource_timing_response_status_enabled_;
    RuntimeEnabledFeaturesBase::is_restrict_gamepad_access_enabled_ = is_restrict_gamepad_access_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_audio_jitter_buffer_max_packets_enabled_ = is_rtc_audio_jitter_buffer_max_packets_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_ice_transport_extension_enabled_ = is_rtc_ice_transport_extension_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_insertable_streams_enabled_ = is_rtc_insertable_streams_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_quic_transport_enabled_ = is_rtc_quic_transport_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_rtp_header_extension_control_enabled_ = is_rtc_rtp_header_extension_control_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_stats_relative_packet_arrival_delay_enabled_ = is_rtc_stats_relative_packet_arrival_delay_enabled_;
    RuntimeEnabledFeaturesBase::is_rtc_svc_scalability_mode_enabled_ = is_rtc_svc_scalability_mode_enabled_;
    RuntimeEnabledFeaturesBase::is_sanitizer_api_enabled_ = is_sanitizer_api_enabled_;
    RuntimeEnabledFeaturesBase::is_sanitizer_api_v_0_enabled_ = is_sanitizer_api_v_0_enabled_;
    RuntimeEnabledFeaturesBase::is_scoped_custom_element_registry_enabled_ = is_scoped_custom_element_registry_enabled_;
    RuntimeEnabledFeaturesBase::is_scripted_speech_recognition_enabled_ = is_scripted_speech_recognition_enabled_;
    RuntimeEnabledFeaturesBase::is_scripted_speech_synthesis_enabled_ = is_scripted_speech_synthesis_enabled_;
    RuntimeEnabledFeaturesBase::is_script_element_supports_enabled_ = is_script_element_supports_enabled_;
    RuntimeEnabledFeaturesBase::is_scrollbar_width_enabled_ = is_scrollbar_width_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_customization_enabled_ = is_scroll_customization_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_end_events_enabled_ = is_scroll_end_events_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_timeline_enabled_ = is_scroll_timeline_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_top_left_interop_enabled_ = is_scroll_top_left_interop_enabled_;
    RuntimeEnabledFeaturesBase::is_scroll_update_optimizations_enabled_ = is_scroll_update_optimizations_enabled_;
    RuntimeEnabledFeaturesBase::is_secure_context_fix_for_shared_workers_enabled_ = is_secure_context_fix_for_shared_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_enabled_ = is_secure_payment_confirmation_enabled_;
    RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_debug_enabled_ = is_secure_payment_confirmation_debug_enabled_;
    RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_opt_out_enabled_ = is_secure_payment_confirmation_opt_out_enabled_;
    RuntimeEnabledFeaturesBase::is_self_browser_surface_constraint_enabled_ = is_self_browser_surface_constraint_enabled_;
    RuntimeEnabledFeaturesBase::is_send_beacon_throw_for_blob_with_non_simple_type_enabled_ = is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
    RuntimeEnabledFeaturesBase::is_send_full_user_agent_after_reduction_enabled_ = is_send_full_user_agent_after_reduction_enabled_;
    RuntimeEnabledFeaturesBase::is_send_mouse_events_disabled_form_controls_enabled_ = is_send_mouse_events_disabled_form_controls_enabled_;
    RuntimeEnabledFeaturesBase::is_sensor_extra_classes_enabled_ = is_sensor_extra_classes_enabled_;
    RuntimeEnabledFeaturesBase::is_serial_enabled_ = is_serial_enabled_;
    RuntimeEnabledFeaturesBase::is_serial_port_forget_enabled_ = is_serial_port_forget_enabled_;
    RuntimeEnabledFeaturesBase::is_service_worker_client_lifecycle_state_enabled_ = is_service_worker_client_lifecycle_state_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_array_buffer_enabled_ = is_shared_array_buffer_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_array_buffer_on_desktop_enabled_ = is_shared_array_buffer_on_desktop_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_array_buffer_unrestricted_access_allowed_enabled_ = is_shared_array_buffer_unrestricted_access_allowed_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_autofill_enabled_ = is_shared_autofill_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_storage_api_enabled_ = is_shared_storage_api_enabled_;
    RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = is_shared_worker_enabled_;
    RuntimeEnabledFeaturesBase::is_signature_based_integrity_enabled_ = is_signature_based_integrity_enabled_;
    RuntimeEnabledFeaturesBase::is_site_initiated_mirroring_enabled_ = is_site_initiated_mirroring_enabled_;
    RuntimeEnabledFeaturesBase::is_skip_ad_enabled_ = is_skip_ad_enabled_;
    RuntimeEnabledFeaturesBase::is_skip_touch_event_filter_enabled_ = is_skip_touch_event_filter_enabled_;
    RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_enabled_ = is_soft_navigation_heuristics_enabled_;
    RuntimeEnabledFeaturesBase::is_speculation_rules_enabled_ = is_speculation_rules_enabled_;
    RuntimeEnabledFeaturesBase::is_speculation_rules_fetch_from_header_enabled_ = is_speculation_rules_fetch_from_header_enabled_;
    RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_proxy_enabled_ = is_speculation_rules_prefetch_proxy_enabled_;
    RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_with_subresources_enabled_ = is_speculation_rules_prefetch_with_subresources_enabled_;
    RuntimeEnabledFeaturesBase::is_srcset_max_density_enabled_ = is_srcset_max_density_enabled_;
    RuntimeEnabledFeaturesBase::is_stable_blink_features_enabled_ = is_stable_blink_features_enabled_;
    RuntimeEnabledFeaturesBase::is_storage_access_api_enabled_ = is_storage_access_api_enabled_;
    RuntimeEnabledFeaturesBase::is_storage_access_api_for_origin_extension_enabled_ = is_storage_access_api_for_origin_extension_enabled_;
    RuntimeEnabledFeaturesBase::is_storage_buckets_enabled_ = is_storage_buckets_enabled_;
    RuntimeEnabledFeaturesBase::is_storage_foundation_api_enabled_ = is_storage_foundation_api_enabled_;
    RuntimeEnabledFeaturesBase::is_strict_mime_types_for_workers_enabled_ = is_strict_mime_types_for_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_stylus_handwriting_enabled_ = is_stylus_handwriting_enabled_;
    RuntimeEnabledFeaturesBase::is_supports_font_format_tech_enabled_ = is_supports_font_format_tech_enabled_;
    RuntimeEnabledFeaturesBase::is_surface_switching_constraint_enabled_ = is_surface_switching_constraint_enabled_;
    RuntimeEnabledFeaturesBase::is_svg_text_ng_enabled_ = is_svg_text_ng_enabled_;
    RuntimeEnabledFeaturesBase::is_synthesized_keyboard_events_for_accessibility_actions_enabled_ = is_synthesized_keyboard_events_for_accessibility_actions_enabled_;
    RuntimeEnabledFeaturesBase::is_system_audio_constraint_enabled_ = is_system_audio_constraint_enabled_;
    RuntimeEnabledFeaturesBase::is_system_wake_lock_enabled_ = is_system_wake_lock_enabled_;
    RuntimeEnabledFeaturesBase::is_test_feature_enabled_ = is_test_feature_enabled_;
    RuntimeEnabledFeaturesBase::is_test_feature_dependent_enabled_ = is_test_feature_dependent_enabled_;
    RuntimeEnabledFeaturesBase::is_test_feature_implied_enabled_ = is_test_feature_implied_enabled_;
    RuntimeEnabledFeaturesBase::is_text_decorating_box_enabled_ = is_text_decorating_box_enabled_;
    RuntimeEnabledFeaturesBase::is_text_detector_enabled_ = is_text_detector_enabled_;
    RuntimeEnabledFeaturesBase::is_text_fragment_api_enabled_ = is_text_fragment_api_enabled_;
    RuntimeEnabledFeaturesBase::is_text_fragment_identifiers_enabled_ = is_text_fragment_identifiers_enabled_;
    RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = is_text_fragment_tap_opens_context_menu_enabled_;
    RuntimeEnabledFeaturesBase::is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_
        = is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_;
    RuntimeEnabledFeaturesBase::is_timer_throttling_for_background_tabs_enabled_ = is_timer_throttling_for_background_tabs_enabled_;
    RuntimeEnabledFeaturesBase::is_time_zone_change_event_enabled_ = is_time_zone_change_event_enabled_;
    RuntimeEnabledFeaturesBase::is_topics_api_enabled_ = is_topics_api_enabled_;
    RuntimeEnabledFeaturesBase::is_touch_action_effective_at_pointer_down_enabled_ = is_touch_action_effective_at_pointer_down_enabled_;
    RuntimeEnabledFeaturesBase::is_touch_drag_and_context_menu_enabled_ = is_touch_drag_and_context_menu_enabled_;
    RuntimeEnabledFeaturesBase::is_touch_drag_on_short_press_enabled_ = is_touch_drag_on_short_press_enabled_;
    RuntimeEnabledFeaturesBase::is_touch_event_feature_detection_enabled_ = is_touch_event_feature_detection_enabled_;
    RuntimeEnabledFeaturesBase::is_translate_service_enabled_ = is_translate_service_enabled_;
    RuntimeEnabledFeaturesBase::is_trusted_type_before_policy_creation_event_enabled_ = is_trusted_type_before_policy_creation_event_enabled_;
    RuntimeEnabledFeaturesBase::is_trusted_types_use_code_like_enabled_ = is_trusted_types_use_code_like_enabled_;
    RuntimeEnabledFeaturesBase::is_trust_tokens_enabled_ = is_trust_tokens_enabled_;
    RuntimeEnabledFeaturesBase::is_trust_tokens_always_allow_issuance_enabled_ = is_trust_tokens_always_allow_issuance_enabled_;
    RuntimeEnabledFeaturesBase::is_u_2_f_security_key_api_enabled_ = is_u_2_f_security_key_api_enabled_;
    RuntimeEnabledFeaturesBase::is_unclosed_form_control_is_invalid_enabled_ = is_unclosed_form_control_is_invalid_enabled_;
    RuntimeEnabledFeaturesBase::is_unexposed_task_ids_enabled_ = is_unexposed_task_ids_enabled_;
    RuntimeEnabledFeaturesBase::is_unrestricted_shared_array_buffer_enabled_ = is_unrestricted_shared_array_buffer_enabled_;
    RuntimeEnabledFeaturesBase::is_url_pattern_compare_component_enabled_ = is_url_pattern_compare_component_enabled_;
    RuntimeEnabledFeaturesBase::is_user_activation_same_origin_visibility_enabled_ = is_user_activation_same_origin_visibility_enabled_;
    RuntimeEnabledFeaturesBase::is_user_agent_client_hint_enabled_ = is_user_agent_client_hint_enabled_;
    RuntimeEnabledFeaturesBase::is_user_agent_reduction_enabled_ = is_user_agent_reduction_enabled_;
    RuntimeEnabledFeaturesBase::is_v8_idle_tasks_enabled_ = is_v8_idle_tasks_enabled_;
    RuntimeEnabledFeaturesBase::is_variable_colrv_1_enabled_ = is_variable_colrv_1_enabled_;
    RuntimeEnabledFeaturesBase::is_video_auto_fullscreen_enabled_ = is_video_auto_fullscreen_enabled_;
    RuntimeEnabledFeaturesBase::is_video_fullscreen_orientation_lock_enabled_ = is_video_fullscreen_orientation_lock_enabled_;
    RuntimeEnabledFeaturesBase::is_video_playback_quality_enabled_ = is_video_playback_quality_enabled_;
    RuntimeEnabledFeaturesBase::is_video_rotate_to_fullscreen_enabled_ = is_video_rotate_to_fullscreen_enabled_;
    RuntimeEnabledFeaturesBase::is_video_track_generator_enabled_ = is_video_track_generator_enabled_;
    RuntimeEnabledFeaturesBase::is_video_track_generator_in_window_enabled_ = is_video_track_generator_in_window_enabled_;
    RuntimeEnabledFeaturesBase::is_video_track_generator_in_worker_enabled_ = is_video_track_generator_in_worker_enabled_;
    RuntimeEnabledFeaturesBase::is_video_wake_lock_optimisation_hidden_muted_enabled_ = is_video_wake_lock_optimisation_hidden_muted_enabled_;
    RuntimeEnabledFeaturesBase::is_viewport_height_client_hint_header_enabled_ = is_viewport_height_client_hint_header_enabled_;
    RuntimeEnabledFeaturesBase::is_viewport_meta_interactive_widget_property_enabled_ = is_viewport_meta_interactive_widget_property_enabled_;
    RuntimeEnabledFeaturesBase::is_viewport_segments_enabled_ = is_viewport_segments_enabled_;
    RuntimeEnabledFeaturesBase::is_visibility_collapse_column_enabled_ = is_visibility_collapse_column_enabled_;
    RuntimeEnabledFeaturesBase::is_visibility_state_entry_enabled_ = is_visibility_state_entry_enabled_;
    RuntimeEnabledFeaturesBase::is_wake_lock_enabled_ = is_wake_lock_enabled_;
    RuntimeEnabledFeaturesBase::is_warn_on_content_visibility_render_access_enabled_ = is_warn_on_content_visibility_render_access_enabled_;
    RuntimeEnabledFeaturesBase::is_web_animations_api_enabled_ = is_web_animations_api_enabled_;
    RuntimeEnabledFeaturesBase::is_web_animations_svg_enabled_ = is_web_animations_svg_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_dark_mode_enabled_ = is_web_app_dark_mode_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_launch_handler_enabled_ = is_web_app_launch_handler_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_launch_queue_enabled_ = is_web_app_launch_queue_enabled_;
    RuntimeEnabledFeaturesBase::is_web_apps_lock_screen_enabled_ = is_web_apps_lock_screen_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = is_web_app_tab_strip_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_translations_enabled_ = is_web_app_translations_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_url_handling_enabled_ = is_web_app_url_handling_enabled_;
    RuntimeEnabledFeaturesBase::is_web_app_window_controls_overlay_enabled_ = is_web_app_window_controls_overlay_enabled_;
    RuntimeEnabledFeaturesBase::is_web_assembly_csp_enabled_ = is_web_assembly_csp_enabled_;
    RuntimeEnabledFeaturesBase::is_web_assembly_exceptions_enabled_ = is_web_assembly_exceptions_enabled_;
    RuntimeEnabledFeaturesBase::is_web_auth_enabled_ = is_web_auth_enabled_;
    RuntimeEnabledFeaturesBase::is_web_auth_authenticator_attachment_enabled_ = is_web_auth_authenticator_attachment_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_conditional_ui_enabled_ = is_web_authentication_conditional_ui_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_device_public_key_enabled_ = is_web_authentication_device_public_key_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_large_blob_extension_enabled_ = is_web_authentication_large_blob_extension_enabled_;
    RuntimeEnabledFeaturesBase::is_web_authentication_remote_desktop_support_enabled_ = is_web_authentication_remote_desktop_support_enabled_;
    RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = is_web_bluetooth_enabled_;
    RuntimeEnabledFeaturesBase::is_web_bluetooth_get_devices_enabled_ = is_web_bluetooth_get_devices_enabled_;
    RuntimeEnabledFeaturesBase::is_web_bluetooth_scanning_enabled_ = is_web_bluetooth_scanning_enabled_;
    RuntimeEnabledFeaturesBase::is_web_bluetooth_watch_advertisements_enabled_ = is_web_bluetooth_watch_advertisements_enabled_;
    RuntimeEnabledFeaturesBase::is_webcodecs_enabled_ = is_webcodecs_enabled_;
    RuntimeEnabledFeaturesBase::is_webcodecs_dequeue_event_enabled_ = is_webcodecs_dequeue_event_enabled_;
    RuntimeEnabledFeaturesBase::is_webgl_color_management_enabled_ = is_webgl_color_management_enabled_;
    RuntimeEnabledFeaturesBase::is_webgl_developer_extensions_enabled_ = is_webgl_developer_extensions_enabled_;
    RuntimeEnabledFeaturesBase::is_webgl_draft_extensions_enabled_ = is_webgl_draft_extensions_enabled_;
    RuntimeEnabledFeaturesBase::is_webgl_image_chromium_enabled_ = is_webgl_image_chromium_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_enabled_ = is_webgpu_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_developer_features_enabled_ = is_webgpu_developer_features_enabled_;
    RuntimeEnabledFeaturesBase::is_webgpu_import_texture_enabled_ = is_webgpu_import_texture_enabled_;
    RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = is_web_hid_enabled_;
    RuntimeEnabledFeaturesBase::is_web_hid_exclusion_filters_option_enabled_ = is_web_hid_exclusion_filters_option_enabled_;
    RuntimeEnabledFeaturesBase::is_web_hid_on_service_workers_enabled_ = is_web_hid_on_service_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_web_kit_scrollbar_styling_enabled_ = is_web_kit_scrollbar_styling_enabled_;
    RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = is_web_nfc_enabled_;
    RuntimeEnabledFeaturesBase::is_web_nfc_make_read_only_enabled_ = is_web_nfc_make_read_only_enabled_;
    RuntimeEnabledFeaturesBase::is_web_otp_enabled_ = is_web_otp_enabled_;
    RuntimeEnabledFeaturesBase::is_web_otp_assertion_feature_policy_enabled_ = is_web_otp_assertion_feature_policy_enabled_;
    RuntimeEnabledFeaturesBase::is_web_payment_api_csp_enabled_ = is_web_payment_api_csp_enabled_;
    RuntimeEnabledFeaturesBase::is_web_share_enabled_ = is_web_share_enabled_;
    RuntimeEnabledFeaturesBase::is_websocket_stream_enabled_ = is_websocket_stream_enabled_;
    RuntimeEnabledFeaturesBase::is_web_transport_custom_certificates_enabled_ = is_web_transport_custom_certificates_enabled_;
    RuntimeEnabledFeaturesBase::is_web_usb_enabled_ = is_web_usb_enabled_;
    RuntimeEnabledFeaturesBase::is_web_usb_device_forget_enabled_ = is_web_usb_device_forget_enabled_;
    RuntimeEnabledFeaturesBase::is_web_usb_on_dedicated_workers_enabled_ = is_web_usb_on_dedicated_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_web_usb_on_service_workers_enabled_ = is_web_usb_on_service_workers_enabled_;
    RuntimeEnabledFeaturesBase::is_web_vtt_regions_enabled_ = is_web_vtt_regions_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_enabled_ = is_web_xr_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_anchors_enabled_ = is_web_xr_anchors_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_ar_module_enabled_ = is_web_xr_ar_module_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_camera_access_enabled_ = is_web_xr_camera_access_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_depth_enabled_ = is_web_xr_depth_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_hand_input_enabled_ = is_web_xr_hand_input_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_hit_test_enabled_ = is_web_xr_hit_test_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_hit_test_entity_types_enabled_ = is_web_xr_hit_test_entity_types_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_image_tracking_enabled_ = is_web_xr_image_tracking_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_light_estimation_enabled_ = is_web_xr_light_estimation_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_plane_detection_enabled_ = is_web_xr_plane_detection_enabled_;
    RuntimeEnabledFeaturesBase::is_web_xr_viewport_scale_enabled_ = is_web_xr_viewport_scale_enabled_;
    RuntimeEnabledFeaturesBase::is_wgi_gamepad_trigger_rumble_enabled_ = is_wgi_gamepad_trigger_rumble_enabled_;
    RuntimeEnabledFeaturesBase::is_window_default_status_enabled_ = is_window_default_status_enabled_;
    RuntimeEnabledFeaturesBase::is_window_open_new_popup_behavior_enabled_ = is_window_open_new_popup_behavior_enabled_;
    RuntimeEnabledFeaturesBase::is_window_placement_enabled_ = is_window_placement_enabled_;
    RuntimeEnabledFeaturesBase::is_window_placement_enhanced_screen_labels_enabled_ = is_window_placement_enhanced_screen_labels_enabled_;
    RuntimeEnabledFeaturesBase::is_window_placement_fullscreen_on_screens_change_enabled_ = is_window_placement_fullscreen_on_screens_change_enabled_;
    RuntimeEnabledFeaturesBase::is_zero_copy_tab_capture_enabled_ = is_zero_copy_tab_capture_enabled_;
}

void RuntimeEnabledFeaturesBase::SetStableFeaturesEnabled(bool enable)
{
    SetAbortSignalThrowIfAbortedEnabled(enable);
    SetAbortSignalTimeoutEnabled(enable);
    SetAccelerated2dCanvasEnabled(enable);
    SetAcceleratedSmallCanvasesEnabled(enable);
    SetBackgroundFetchEnabled(enable);
    SetBeforeMatchEventEnabled(enable);
    SetBlockingAttributeEnabled(enable);
    SetCapabilityDelegationFullscreenRequestEnabled(enable);
    SetcheckVisibilityEnabled(enable);
    SetClientHintsMetaEquivDelegateCHEnabled(enable);
    SetClientHintsMetaHTTPEquivAcceptCHEnabled(enable);
    SetClientHintThirdPartyDelegationEnabled(enable);
    SetClipboardCustomFormatsEnabled(enable);
    SetCLSScrollAnchoringEnabled(enable);
    SetContentVisibilityAutoStateChangeEventEnabled(enable);
    SetCSSContainerQueriesEnabled(enable);
    SetCSSFocusVisibleEnabled(enable);
    SetCSSFontFaceSrcTechParsingEnabled(enable);
    SetCSSGridTemplatePropertyInterpolationEnabled(enable);
    SetCSSHexAlphaColorEnabled(enable);
    SetCSSIcUnitEnabled(enable);
    SetCSSIndependentTransformPropertiesEnabled(enable);
    SetCSSLastBaselineEnabled(enable);
    SetCSSMediaQueries4Enabled(enable);
    SetCSSMixBlendModePlusLighterEnabled(enable);
    SetCSSObjectViewBoxEnabled(enable);
    SetCSSPseudoHasEnabled(enable);
    SetCSSViewportUnits4Enabled(enable);
    SetDatabaseEnabled(enable);
    SetDecodeJpeg420ImagesToYUVEnabled(enable);
    SetDecodeLossyWebPImagesToYUVEnabled(enable);
    SetDeflateRawCompressionFormatEnabled(enable);
    SetDelegatedInkTrailsEnabled(enable);
    SetDisplaySurfaceConstraintEnabled(enable);
    SetDocumentPolicyEnabled(enable);
    SetEarlyHintsPreloadForNavigationOptInEnabled(enable);
    SetEventPathEnabled(enable);
    SetFedCmEnabled(enable);
    SetFetchUploadStreamingEnabled(enable);
    SetFileSystemEnabled(enable);
    SetFileSystemAccessAccessHandleEnabled(enable);
    SetFixedElementsDontOverscrollEnabled(enable);
    SetFontPaletteEnabled(enable);
    SetForcedColorsEnabled(enable);
    SetForcedColorsPreserveParentColorEnabled(enable);
    SetFormRelAttributeEnabled(enable);
    SetHighlightAPIEnabled(enable);
    SetHighlightOverlayPaintingEnabled(enable);
    SetHrefTranslateEnabled(enable);
    SetHTMLParamElementUrlSupportEnabled(enable);
    SetIdleDetectionEnabled(enable);
    SetInertAttributeEnabled(enable);
    SetInstalledAppEnabled(enable);
    SetLangAttributeAwareSvgTextEnabled(enable);
    SetLayoutNGEnabled(enable);
    SetLayoutNGBlockFragmentationEnabled(enable);
    SetLayoutNGBlockInInlineEnabled(enable);
    SetLayoutNGDelayScrollOffsetClampingEnabled(enable);
    SetLayoutNGFlexFragmentationEnabled(enable);
    SetLayoutNGForeignObjectEnabled(enable);
    SetLayoutNGFrameSetEnabled(enable);
    SetLayoutNGGridFragmentationEnabled(enable);
    SetLayoutNGPrintingEnabled(enable);
    SetLayoutNGTableFragmentationEnabled(enable);
    SetLayoutNGVTTCueEnabled(enable);
    SetLazyFrameLoadingEnabled(enable);
    SetLazyImageLoadingEnabled(enable);
    SetManagedConfigurationEnabled(enable);
    SetMeasureMemoryEnabled(enable);
    SetMediaSessionEnabled(enable);
    SetMediaSourceInWorkersEnabled(enable);
    SetMediaSourceInWorkersUsingHandleEnabled(enable);
    SetMediaSourceStableEnabled(enable);
    SetMediaStreamTrackInWindowEnabled(enable);
    SetNavigationApiEnabled(enable);
    SetNotificationsEnabled(enable);
    SetOffMainThreadCSSPaintEnabled(enable);
    SetOriginIsolationHeaderEnabled(enable);
    SetPaymentMethodChangeEventEnabled(enable);
    SetPeriodicBackgroundSyncEnabled(enable);
    SetPermissionsEnabled(enable);
    SetPictureInPictureAPIEnabled(enable);
    SetPointerLockOptionsEnabled(enable);
    SetPrefersColorSchemeClientHintHeaderEnabled(enable);
    SetPrefersReducedMotionClientHintHeaderEnabled(enable);
    SetPrefixedStorageInfoEnabled(enable);
    SetPrefixedVideoFullscreenEnabled(enable);
    SetPrerender2Enabled(enable);
    SetPresentationEnabled(enable);
    SetPriorityHintsEnabled(enable);
    SetPushMessagingEnabled(enable);
    SetReduceUserAgentMinorVersionEnabled(enable);
    SetRemotePlaybackEnabled(enable);
    SetRemoveMobileViewportDoubleTapEnabled(enable);
    SetRenderBlockingStatusEnabled(enable);
    SetSanitizerAPIv0Enabled(enable);
    SetScriptedSpeechRecognitionEnabled(enable);
    SetScriptedSpeechSynthesisEnabled(enable);
    SetScriptElementSupportsEnabled(enable);
    SetScrollTopLeftInteropEnabled(enable);
    SetScrollUpdateOptimizationsEnabled(enable);
    SetSecureContextFixForSharedWorkersEnabled(enable);
    SetSelfBrowserSurfaceConstraintEnabled(enable);
    SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled(enable);
    SetSkipTouchEventFilterEnabled(enable);
    SetStableBlinkFeaturesEnabled(enable);
    SetSupportsFontFormatTechEnabled(enable);
    SetSurfaceSwitchingConstraintEnabled(enable);
    SetSVGTextNGEnabled(enable);
    SetSystemAudioConstraintEnabled(enable);
    SetTextDecoratingBoxEnabled(enable);
    SetTextFragmentIdentifiersEnabled(enable);
    SetTimerThrottlingForBackgroundTabsEnabled(enable);
    SetTouchActionEffectiveAtPointerDownEnabled(enable);
    SetTouchEventFeatureDetectionEnabled(enable);
    SetUserAgentClientHintEnabled(enable);
    SetVariableCOLRV1Enabled(enable);
    SetVideoPlaybackQualityEnabled(enable);
    SetVideoWakeLockOptimisationHiddenMutedEnabled(enable);
    SetViewportHeightClientHintHeaderEnabled(enable);
    SetViewportMetaInteractiveWidgetPropertyEnabled(enable);
    SetWakeLockEnabled(enable);
    SetWebAnimationsAPIEnabled(enable);
    SetWebAppWindowControlsOverlayEnabled(enable);
    SetWebAssemblyCSPEnabled(enable);
    SetWebAuthEnabled(enable);
    SetWebAuthenticationConditionalUIEnabled(enable);
    SetWebCodecsEnabled(enable);
    SetWebCodecsDequeueEventEnabled(enable);
    SetWebGLColorManagementEnabled(enable);
    SetWebHIDExclusionFiltersOptionEnabled(enable);
    SetWebKitScrollbarStylingEnabled(enable);
    SetWebOTPEnabled(enable);
    SetWebOTPAssertionFeaturePolicyEnabled(enable);
    SetWebTransportCustomCertificatesEnabled(enable);
    SetWebUSBEnabled(enable);
    SetWebUsbDeviceForgetEnabled(enable);
    SetWebUSBOnDedicatedWorkersEnabled(enable);
    SetWebXREnabled(enable);
    SetWebXRAnchorsEnabled(enable);
    SetWebXRARModuleEnabled(enable);
    SetWebXRCameraAccessEnabled(enable);
    SetWebXRDepthEnabled(enable);
    SetWebXRHitTestEnabled(enable);
    SetWebXRLightEstimationEnabled(enable);
    SetWebXRViewportScaleEnabled(enable);
    SetWindowOpenNewPopupBehaviorEnabled(enable);
    SetWindowPlacementEnabled(enable);
    SetWindowPlacementEnhancedScreenLabelsEnabled(enable);

    // Platform-dependent features
#if BUILDFLAG(IS_ANDROID)
    SetBarcodeDetectorEnabled(enable);
    SetCompositedSelectionUpdateEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetImplicitRootScrollerEnabled(enable);
    SetMediaCaptureEnabled(enable);
    SetMediaControlsOverlayPlayButtonEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetOrientationEventEnabled(enable);
    SetRemotePlaybackBackendEnabled(enable);
    SetSpeculationRulesPrefetchProxyEnabled(enable);
    SetTextFragmentTapOpensContextMenuEnabled(enable);
    SetWebBluetoothEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebNFCMakeReadOnlyEnabled(enable);
#endif

#if BUILDFLAG(IS_WIN)
    SetAudioOutputDevicesEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetEyeDropperAPIEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFileSystemAccessOriginPrivateEnabled(enable);
    SetFontAccessEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHidDeviceForgetEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetOnDeviceChangeEnabled(enable);
    SetPagePopupEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetSerialEnabled(enable);
    SetSerialPortForgetEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
    SetAudioOutputDevicesEnabled(enable);
    SetBarcodeDetectorEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFileSystemAccessOriginPrivateEnabled(enable);
    SetFontAccessEnabled(enable);
    SetForceTallerSelectPopupEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetHidDeviceForgetEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetOnDeviceChangeEnabled(enable);
    SetPagePopupEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetSerialEnabled(enable);
    SetSerialPortForgetEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebBluetoothEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_LACROS)
    SetAudioOutputDevicesEnabled(enable);
    SetBarcodeDetectorEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFileSystemAccessOriginPrivateEnabled(enable);
    SetFontAccessEnabled(enable);
    SetForceTallerSelectPopupEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetHidDeviceForgetEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetOnDeviceChangeEnabled(enable);
    SetPagePopupEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetSerialEnabled(enable);
    SetSerialPortForgetEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebBluetoothEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

#if BUILDFLAG(IS_MAC)
    SetAudioOutputDevicesEnabled(enable);
    SetBarcodeDetectorEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetEyeDropperAPIEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFileSystemAccessOriginPrivateEnabled(enable);
    SetFontAccessEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHidDeviceForgetEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetOnDeviceChangeEnabled(enable);
    SetPagePopupEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetSerialEnabled(enable);
    SetSerialPortForgetEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebBluetoothEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

#if BUILDFLAG(IS_LINUX)
    SetAudioOutputDevicesEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetEyeDropperAPIEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFileSystemAccessOriginPrivateEnabled(enable);
    SetFontAccessEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHidDeviceForgetEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetOnDeviceChangeEnabled(enable);
    SetPagePopupEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetSerialEnabled(enable);
    SetSerialPortForgetEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebHIDEnabled(enable);
#endif

    // Default values for platforms not specifically handled above
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
    SetAudioOutputDevicesEnabled(enable);
    SetCaptureHandleEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetFileSystemAccessOriginPrivateEnabled(enable);
    SetFontAccessEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHidDeviceForgetEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
    SetNavigatorContentUtilsEnabled(enable);
    SetNotificationConstructorEnabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetOnDeviceChangeEnabled(enable);
    SetPagePopupEnabled(enable);
    SetRegionCaptureEnabled(enable);
    SetSerialEnabled(enable);
    SetSerialPortForgetEnabled(enable);
    SetSharedWorkerEnabled(enable);
    SetWebHIDEnabled(enable);
#endif
}

void RuntimeEnabledFeaturesBase::SetExperimentalFeaturesEnabled(bool enable)
{
    SetAccessibilityAriaTouchPassthroughEnabled(enable);
    SetAccessibilityAriaVirtualContentEnabled(enable);
    SetAccessibilityObjectModelEnabled(enable);
    SetAddressSpaceEnabled(enable);
    SetAnimationWorkletEnabled(enable);
    SetAOMAriaRelationshipPropertiesEnabled(enable);
    SetAriaTouchPassthroughEnabled(enable);
    SetAttributionReportingEnabled(enable);
    SetAudioVideoTracksEnabled(enable);
    SetAutofillShadowDOMEnabled(enable);
    SetAutoPictureInPictureEnabled(enable);
    SetBackForwardCacheExperimentHTTPHeaderEnabled(enable);
    SetBackForwardCacheNotRestoredReasonsEnabled(enable);
    SetBlockingFocusWithoutUserActivationEnabled(enable);
    SetCacheStorageCodeCacheHintEnabled(enable);
    SetCanvas2dScrollPathIntoViewEnabled(enable);
    SetCanvasColorManagementV2Enabled(enable);
    SetCanvasHDREnabled(enable);
    SetCanvasImageSmoothingEnabled(enable);
    SetClickToCapturedPointerEnabled(enable);
    SetClipboardSvgEnabled(enable);
    SetClipboardUnsanitizedContentEnabled(enable);
    SetCompositeBGColorAnimationEnabled(enable);
    SetComputedAccessibilityInfoEnabled(enable);
    SetComputePressureEnabled(enable);
    SetContextMenuEnabled(enable);
    SetCrossOriginOpenerPolicyReportingEnabled(enable);
    SetCSSAnchorPositioningEnabled(enable);
    SetCSSAtSupportsAlwaysNonForgivingParsingEnabled(enable);
    SetCSSColor4Enabled(enable);
    SetCSSColorContrastEnabled(enable);
    SetCSSColorTypedOMEnabled(enable);
    SetCSSFoldablesEnabled(enable);
    SetCSSFontFamilyMathEnabled(enable);
    SetCSSLayoutAPIEnabled(enable);
    SetCSSLhUnitEnabled(enable);
    SetCSSLogicalEnabled(enable);
    SetCSSMarkerNestedPseudoElementEnabled(enable);
    SetCSSMathDepthEnabled(enable);
    SetCSSMathShiftEnabled(enable);
    SetCSSMathStyleEnabled(enable);
    SetCSSMathVariantEnabled(enable);
    SetCSSOffsetPathRayEnabled(enable);
    SetCSSOffsetPathRayContainEnabled(enable);
    SetCSSOffsetPositionAnchorEnabled(enable);
    SetCSSPaintAPIArgumentsEnabled(enable);
    SetCSSPictureInPictureEnabled(enable);
    SetCSSPositionStickyStaticScrollPositionEnabled(enable);
    SetCSSPseudoAutofillEnabled(enable);
    SetCSSPseudoDirEnabled(enable);
    SetCSSScopeEnabled(enable);
    SetCSSScrollTimelineEnabled(enable);
    SetCSSSelectorFragmentAnchorEnabled(enable);
    SetCSSSnapSizeEnabled(enable);
    SetCSSSpellingGrammarErrorsEnabled(enable);
    SetCSSStyleQueriesEnabled(enable);
    SetCSSVideoDynamicRangeMediaQueriesEnabled(enable);
    SetCustomElementDefaultStyleEnabled(enable);
    SetDeliveryTypeEnabled(enable);
    SetDesktopCaptureDisableLocalEchoControlEnabled(enable);
    SetDeviceAttributesEnabled(enable);
    SetDeviceOrientationRequestPermissionEnabled(enable);
    SetDevicePostureEnabled(enable);
    SetDirectSocketsEnabled(enable);
    SetDisableHardwareNoiseSuppressionEnabled(enable);
    SetDocumentPolicyDocumentDomainEnabled(enable);
    SetDocumentPolicyNegotiationEnabled(enable);
    SetDocumentPolicySyncXHREnabled(enable);
    SetEditContextEnabled(enable);
    SetElementSuperRareDataEnabled(enable);
    SetExperimentalContentSecurityPolicyFeaturesEnabled(enable);
    SetExperimentalJSProfilerMarkersEnabled(enable);
    SetExperimentalPoliciesEnabled(enable);
    SetExtendedTextMetricsEnabled(enable);
    SetFaceDetectorEnabled(enable);
    SetFeaturePolicyReportingEnabled(enable);
    SetFileSystemAccessAPIExperimentalEnabled(enable);
    SetFocusgroupEnabled(enable);
    SetFormattedTextEnabled(enable);
    SetFreezeFramesOnVisibilityEnabled(enable);
    SetGamepadButtonAxisEventsEnabled(enable);
    SetHTMLPopupAttributeEnabled(enable);
    SetHTMLSelectMenuElementEnabled(enable);
    SetIDBBatchGetAllEnabled(enable);
    SetKeyboardAccessibleTooltipEnabled(enable);
    SetKeyboardFocusableScrollersEnabled(enable);
    SetMachineLearningCommonEnabled(enable);
    SetMachineLearningModelLoaderEnabled(enable);
    SetMathMLCoreEnabled(enable);
    SetMediaCapabilitiesEncodingInfoEnabled(enable);
    SetMediaCaptureBackgroundBlurEnabled(enable);
    SetMediaSourceExperimentalEnabled(enable);
    SetMediaSourceExtensionsForWebCodecsEnabled(enable);
    SetMediaSourceNewAbortAndDurationEnabled(enable);
    SetNavigationIdEnabled(enable);
    SetNotificationTriggersEnabled(enable);
    SetOffscreenCanvasCommitEnabled(enable);
    SetOffsetParentNewSpecBehaviorEnabled(enable);
    SetOriginPolicyEnabled(enable);
    SetOverscrollCustomizationEnabled(enable);
    SetPartitionedCookiesEnabled(enable);
    SetPaymentAppEnabled(enable);
    SetPaymentRequestEnabled(enable);
    SetPaymentRequestMerchantValidationEventEnabled(enable);
    SetPendingBeaconAPIEnabled(enable);
    SetPerMethodCanMakePaymentQuotaEnabled(enable);
    SetPermissionsPolicyUnloadEnabled(enable);
    SetPermissionsRequestRevokeEnabled(enable);
    SetPrefersReducedDataEnabled(enable);
    SetPrivateNetworkAccessNonSecureContextsAllowedEnabled(enable);
    SetPushMessagingSubscriptionChangeEnabled(enable);
    SetQuotaChangeEnabled(enable);
    SetReduceUserAgentPlatformOsCpuEnabled(enable);
    SetResourceTimingResponseStatusEnabled(enable);
    SetRestrictGamepadAccessEnabled(enable);
    SetRtcAudioJitterBufferMaxPacketsEnabled(enable);
    SetRTCIceTransportExtensionEnabled(enable);
    SetRTCInsertableStreamsEnabled(enable);
    SetRTCQuicTransportEnabled(enable);
    SetRTCRtpHeaderExtensionControlEnabled(enable);
    SetRTCStatsRelativePacketArrivalDelayEnabled(enable);
    SetRTCSvcScalabilityModeEnabled(enable);
    SetSanitizerAPIEnabled(enable);
    SetScrollEndEventsEnabled(enable);
    SetScrollTimelineEnabled(enable);
    SetSendMouseEventsDisabledFormControlsEnabled(enable);
    SetSensorExtraClassesEnabled(enable);
    SetServiceWorkerClientLifecycleStateEnabled(enable);
    SetSignatureBasedIntegrityEnabled(enable);
    SetSiteInitiatedMirroringEnabled(enable);
    SetSkipAdEnabled(enable);
    SetSoftNavigationHeuristicsEnabled(enable);
    SetStorageBucketsEnabled(enable);
    SetStorageFoundationAPIEnabled(enable);
    SetStrictMimeTypesForWorkersEnabled(enable);
    SetSynthesizedKeyboardEventsForAccessibilityActionsEnabled(enable);
    SetSystemWakeLockEnabled(enable);
    SetTextDetectorEnabled(enable);
    SetTextFragmentAPIEnabled(enable);
    SetThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframesEnabled(enable);
    SetTimeZoneChangeEventEnabled(enable);
    SetTrustedTypeBeforePolicyCreationEventEnabled(enable);
    SetTrustedTypesUseCodeLikeEnabled(enable);
    SetUnclosedFormControlIsInvalidEnabled(enable);
    SetURLPatternCompareComponentEnabled(enable);
    SetViewportSegmentsEnabled(enable);
    SetVisibilityStateEntryEnabled(enable);
    SetWebAnimationsSVGEnabled(enable);
    SetWebAppDarkModeEnabled(enable);
    SetWebAppLaunchHandlerEnabled(enable);
    SetWebAppsLockScreenEnabled(enable);
    SetWebAppTabStripEnabled(enable);
    SetWebAppTranslationsEnabled(enable);
    SetWebAppUrlHandlingEnabled(enable);
    SetWebAuthenticationDevicePublicKeyEnabled(enable);
    SetWebAuthenticationLargeBlobExtensionEnabled(enable);
    SetWebBluetoothGetDevicesEnabled(enable);
    SetWebBluetoothScanningEnabled(enable);
    SetWebBluetoothWatchAdvertisementsEnabled(enable);
    SetWebGLDeveloperExtensionsEnabled(enable);
    SetWebGPUImportTextureEnabled(enable);
    SetWebSocketStreamEnabled(enable);
    SetWebVTTRegionsEnabled(enable);
    SetWebXRHandInputEnabled(enable);
    SetWebXRHitTestEntityTypesEnabled(enable);
    SetWebXRImageTrackingEnabled(enable);
    SetWebXRPlaneDetectionEnabled(enable);
    SetWindowPlacementFullscreenOnScreensChangeEnabled(enable);

    // Platform-dependent features
#if BUILDFLAG(IS_ANDROID)
    SetFileSystemAccessOriginPrivateEnabled(enable);
    SetGetDisplayMediaEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
#endif

#if BUILDFLAG(IS_WIN)
    SetConditionalFocusEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetWebBluetoothEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
    SetConditionalFocusEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_LACROS)
    SetConditionalFocusEnabled(enable);
    SetContentIndexEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
#endif

#if BUILDFLAG(IS_MAC)
    SetConditionalFocusEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
#endif

#if BUILDFLAG(IS_LINUX)
    SetConditionalFocusEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetWebBluetoothEnabled(enable);
#endif

    // Default values for platforms not specifically handled above
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
    SetConditionalFocusEnabled(enable);
    SetContentIndexEnabled(enable);
    SetDocumentPictureInPictureAPIEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetHandwritingRecognitionEnabled(enable);
    SetNetInfoDownlinkMaxEnabled(enable);
    SetWebBluetoothEnabled(enable);
#endif
}

void RuntimeEnabledFeaturesBase::SetTestFeaturesEnabled(bool enable)
{
    SetAccessibilityExposeDisplayNoneEnabled(enable);
    SetAdTaggingEnabled(enable);
    SetAnonymousIframeEnabled(enable);
    SetAudioContextSetSinkIdEnabled(enable);
    SetBatchFetchRequestsEnabled(enable);
    SetCoepReflectionEnabled(enable);
    SetCSSAtRuleCounterStyleSpeakAsDescriptorEnabled(enable);
    SetCSSCaseSensitiveSelectorEnabled(enable);
    SetCSSEnumeratedCustomPropertiesEnabled(enable);
    SetCSSFontFaceAutoVariableRangeEnabled(enable);
    SetCSSFontSizeAdjustEnabled(enable);
    SetCSSHyphenateLimitCharsEnabled(enable);
    SetCSSInitialLetterEnabled(enable);
    SetCSSLogicalOverflowEnabled(enable);
    SetCSSOverflowForReplacedElementsEnabled(enable);
    SetCSSPseudoPlayingPausedEnabled(enable);
    SetCSSScrollbarsEnabled(enable);
    SetCSSTogglesEnabled(enable);
    SetCSSTrigonometricFunctionsEnabled(enable);
    SetCSSVariables2ImageValuesEnabled(enable);
    SetCSSVariables2TransformValuesEnabled(enable);
    SetCSSViewTimelineEnabled(enable);
    SetDeferredShapingEnabled(enable);
    SetDesktopPWAsSubAppsEnabled(enable);
    SetFakeNoAllocDirectCallForTestingEnabled(enable);
    SetFedCmIdpSigninStatusEnabled(enable);
    SetFedCmIdpSignoutEnabled(enable);
    SetFedCmIframeSupportEnabled(enable);
    SetFedCmMultipleIdentityProvidersEnabled(enable);
    SetGetDisplayMediaSetEnabled(enable);
    SetGroupEffectEnabled(enable);
    SetLayoutNGSubgridEnabled(enable);
    SetLCPAnimatedImagesWebExposedEnabled(enable);
    SetMachineLearningNeuralNetworkEnabled(enable);
    SetMediaCapabilitiesDynamicRangeEnabled(enable);
    SetMediaCapabilitiesSpatialAudioEnabled(enable);
    SetMediaLatencyHintEnabled(enable);
    SetMediaStreamTrackTransferEnabled(enable);
    SetMiddleClickAutoscrollEnabled(enable);
    SetMojoJSEnabled(enable);
    SetMojoJSTestEnabled(enable);
    SetNoIdleEncodingForWebTestsEnabled(enable);
    SetScopedCustomElementRegistryEnabled(enable);
    SetScrollbarWidthEnabled(enable);
    SetSecurePaymentConfirmationEnabled(enable);
    SetSharedAutofillEnabled(enable);
    SetStorageAccessAPIEnabled(enable);
    SetStorageAccessAPIForOriginExtensionEnabled(enable);
    SetTrustTokensEnabled(enable);
    SetTrustTokensAlwaysAllowIssuanceEnabled(enable);
    SetVideoTrackGeneratorEnabled(enable);
    SetVideoTrackGeneratorInWindowEnabled(enable);
    SetWebAssemblyExceptionsEnabled(enable);
    SetWebAuthAuthenticatorAttachmentEnabled(enable);
    SetWebShareEnabled(enable);
    SetWGIGamepadTriggerRumbleEnabled(enable);

    // Platform-dependent features
#if BUILDFLAG(IS_ANDROID)
    SetFileHandlingEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetFileSystemAccessLocalEnabled(enable);
    SetInputMultipleFieldsUIEnabled(enable);
#endif

#if BUILDFLAG(IS_WIN)
    SetBarcodeDetectorEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetWebNFCEnabled(enable);
    SetWebNFCMakeReadOnlyEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetGetDisplayMediaSetAutoSelectAllScreensEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebNFCMakeReadOnlyEnabled(enable);
#endif

#if BUILDFLAG(IS_CHROMEOS_LACROS)
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetGetDisplayMediaSetAutoSelectAllScreensEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebNFCMakeReadOnlyEnabled(enable);
#endif

#if BUILDFLAG(IS_MAC)
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetNotificationContentImageEnabled(enable);
    SetWebNFCEnabled(enable);
    SetWebNFCMakeReadOnlyEnabled(enable);
#endif

#if BUILDFLAG(IS_LINUX)
    SetBarcodeDetectorEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetWebNFCEnabled(enable);
    SetWebNFCMakeReadOnlyEnabled(enable);
#endif

    // Default values for platforms not specifically handled above
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
    SetBarcodeDetectorEnabled(enable);
    SetContactsManagerEnabled(enable);
    SetContactsManagerExtraPropertiesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDigitalGoodsV2_1Enabled(enable);
    SetWebNFCEnabled(enable);
    SetWebNFCMakeReadOnlyEnabled(enable);
#endif
}

void RuntimeEnabledFeaturesBase::SetOriginTrialControlledFeaturesEnabled(bool enable)
{
    SetAccessibilityAriaTouchPassthroughEnabled(enable);
    SetAdInterestGroupAPIEnabled(enable);
    SetAnonymousIframeEnabled(enable);
    SetAttributionReportingEnabled(enable);
    SetAutoDarkModeEnabled(enable);
    SetBackForwardCacheExperimentHTTPHeaderEnabled(enable);
    SetBackForwardCacheNotRestoredReasonsEnabled(enable);
    SetBeforeMatchEventEnabled(enable);
    SetCacheStorageCodeCacheHintEnabled(enable);
    SetClearIdentityInCanMakePaymentEventEnabled(enable);
    SetComputePressureEnabled(enable);
    SetConditionalFocusEnabled(enable);
    SetCrossOriginOpenerPolicyReportingEnabled(enable);
    SetDeviceAttributesEnabled(enable);
    SetDigitalGoodsEnabled(enable);
    SetDisableDifferentOriginSubframeDialogSuppressionEnabled(enable);
    SetDisableHardwareNoiseSuppressionEnabled(enable);
    SetDocumentPolicyNegotiationEnabled(enable);
    SetEarlyHintsPreloadForNavigationOptInEnabled(enable);
    SetFencedFramesEnabled(enable);
    SetFileHandlingEnabled(enable);
    SetFileHandlingIconsEnabled(enable);
    SetFledgeEnabled(enable);
    SetFocusgroupEnabled(enable);
    SetHrefTranslateEnabled(enable);
    SetHTMLPopupAttributeEnabled(enable);
    SetMediaSourceExtensionsForWebCodecsEnabled(enable);
    SetMediaSourceInWorkersEnabled(enable);
    SetNotificationTriggersEnabled(enable);
    SetOriginTrialsSampleAPIEnabled(enable);
    SetOriginTrialsSampleAPIDependentEnabled(enable);
    SetOriginTrialsSampleAPIDeprecationEnabled(enable);
    SetOriginTrialsSampleAPIExpiryGracePeriodEnabled(enable);
    SetOriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(enable);
    SetOriginTrialsSampleAPIImpliedEnabled(enable);
    SetOriginTrialsSampleAPIInvalidOSEnabled(enable);
    SetOriginTrialsSampleAPINavigationEnabled(enable);
    SetOriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(enable);
    SetOriginTrialsSampleAPIPersistentFeatureEnabled(enable);
    SetOriginTrialsSampleAPIThirdPartyEnabled(enable);
    SetPageFreezeOptInEnabled(enable);
    SetPageFreezeOptOutEnabled(enable);
    SetParakeetEnabled(enable);
    SetPartitionedCookiesEnabled(enable);
    SetPendingBeaconAPIEnabled(enable);
    SetPerMethodCanMakePaymentQuotaEnabled(enable);
    SetPermissionsPolicyUnloadEnabled(enable);
    SetPNaClEnabled(enable);
    SetPointerLockOptionsEnabled(enable);
    SetPortalsEnabled(enable);
    SetPrerender2RelatedFeaturesEnabled(enable);
    SetPrivacySandboxAdsAPIsEnabled(enable);
    SetPrivateNetworkAccessNonSecureContextsAllowedEnabled(enable);
    SetRtcAudioJitterBufferMaxPacketsEnabled(enable);
    SetRTCIceTransportExtensionEnabled(enable);
    SetRTCInsertableStreamsEnabled(enable);
    SetRTCQuicTransportEnabled(enable);
    SetRTCStatsRelativePacketArrivalDelayEnabled(enable);
    SetSecurePaymentConfirmationOptOutEnabled(enable);
    SetSendFullUserAgentAfterReductionEnabled(enable);
    SetSharedStorageAPIEnabled(enable);
    SetSignatureBasedIntegrityEnabled(enable);
    SetSkipAdEnabled(enable);
    SetSpeculationRulesEnabled(enable);
    SetSpeculationRulesPrefetchProxyEnabled(enable);
    SetStorageFoundationAPIEnabled(enable);
    SetTextFragmentIdentifiersEnabled(enable);
    SetTopicsAPIEnabled(enable);
    SetTouchEventFeatureDetectionEnabled(enable);
    SetTrustTokensEnabled(enable);
    SetU2FSecurityKeyAPIEnabled(enable);
    SetUnrestrictedSharedArrayBufferEnabled(enable);
    SetUserAgentReductionEnabled(enable);
    SetWebAppDarkModeEnabled(enable);
    SetWebAppLaunchHandlerEnabled(enable);
    SetWebAppLaunchQueueEnabled(enable);
    SetWebAppUrlHandlingEnabled(enable);
    SetWebAppWindowControlsOverlayEnabled(enable);
    SetWebAssemblyExceptionsEnabled(enable);
    SetWebCodecsEnabled(enable);
    SetWebGPUEnabled(enable);
    SetWebPaymentAPICSPEnabled(enable);
    SetWebTransportCustomCertificatesEnabled(enable);
    SetWebXRDepthEnabled(enable);
    SetWebXRImageTrackingEnabled(enable);
    SetWebXRPlaneDetectionEnabled(enable);
}

void RuntimeEnabledFeaturesBase::SetFeatureEnabledFromString(const std::string& name, bool enable)
{
    static const struct {
        const char* name;
        bool* setting;
    } kFeatures[] = {
        { "AOMAriaRelationshipProperties", &is_aom_aria_relationship_properties_enabled_ },
        { "AbortSignalThrowIfAborted", &is_abort_signal_throw_if_aborted_enabled_ },
        { "AbortSignalTimeout", &is_abort_signal_timeout_enabled_ },
        { "Accelerated2dCanvas", &is_accelerated_2d_canvas_enabled_ },
        { "AcceleratedSmallCanvases", &is_accelerated_small_canvases_enabled_ },
        { "AccessibilityAriaTouchPassthrough", &is_accessibility_aria_touch_passthrough_enabled_ },
        { "AccessibilityAriaVirtualContent", &is_accessibility_aria_virtual_content_enabled_ },
        { "AccessibilityExposeDisplayNone", &is_accessibility_expose_display_none_enabled_ },
        { "AccessibilityExposeHTMLElement", &is_accessibility_expose_html_element_enabled_ },
        { "AccessibilityExposeIgnoredNodes", &is_accessibility_expose_ignored_nodes_enabled_ },
        { "AccessibilityObjectModel", &is_accessibility_object_model_enabled_ },
        { "AccessibilityPageZoom", &is_accessibility_page_zoom_enabled_ },
        { "AccessibilityUseAXPositionForDocumentMarkers", &is_accessibility_use_ax_position_for_document_markers_enabled_ },
        { "AdInterestGroupAPI", &is_ad_interest_group_api_enabled_ },
        { "AdTagging", &is_ad_tagging_enabled_ },
        { "AddressSpace", &is_address_space_enabled_ },
        { "AllowContentInitiatedDataUrlNavigations", &is_allow_content_initiated_data_url_navigations_enabled_ },
        { "AndroidDownloadableFontsMatching", &is_android_downloadable_fonts_matching_enabled_ },
        { "AnimationWorklet", &is_animation_worklet_enabled_ },
        { "AnonymousIframe", &is_anonymous_iframe_enabled_ },
        { "AriaTouchPassthrough", &is_aria_touch_passthrough_enabled_ },
        { "AttributionReporting", &is_attribution_reporting_enabled_ },
        { "AudioContextSetSinkId", &is_audio_context_set_sink_id_enabled_ },
        { "AudioOutputDevices", &is_audio_output_devices_enabled_ },
        { "AudioVideoTracks", &is_audio_video_tracks_enabled_ },
        { "AutoDarkMode", &is_auto_dark_mode_enabled_ },
        { "AutoDisableAccessibilityV2", &is_auto_disable_accessibility_v_2_enabled_ },
        { "AutoPictureInPicture", &is_auto_picture_in_picture_enabled_ },
        { "AutofillShadowDOM", &is_autofill_shadow_dom_enabled_ },
        { "AutomationControlled", &is_automation_controlled_enabled_ },
        { "AutoplayIgnoresWebAudio", &is_autoplay_ignores_web_audio_enabled_ },
        { "BackForwardCache", &is_back_forward_cache_enabled_ },
        { "BackForwardCacheExperimentHTTPHeader", &is_back_forward_cache_experiment_http_header_enabled_ },
        { "BackForwardCacheNotRestoredReasons", &is_back_forward_cache_not_restored_reasons_enabled_ },
        { "BackfaceVisibilityInterop", &is_backface_visibility_interop_enabled_ },
        { "BackgroundFetch", &is_background_fetch_enabled_ },
        { "BarcodeDetector", &is_barcode_detector_enabled_ },
        { "BatchFetchRequests", &is_batch_fetch_requests_enabled_ },
        { "BeforeMatchEvent", &is_before_match_event_enabled_ },
        { "BidiCaretAffinity", &is_bidi_caret_affinity_enabled_ },
        { "BlinkExtensionChromeOS", &is_blink_extension_chrome_os_enabled_ },
        { "BlinkExtensionChromeOSHID", &is_blink_extension_chrome_oshid_enabled_ },
        { "BlinkExtensionChromeOSWindowManagement", &is_blink_extension_chrome_os_window_management_enabled_ },
        { "BlinkRuntimeCallStats", &is_blink_runtime_call_stats_enabled_ },
        { "BlockingAttribute", &is_blocking_attribute_enabled_ },
        { "BlockingFocusWithoutUserActivation", &is_blocking_focus_without_user_activation_enabled_ },
        { "BrowserVerifiedUserActivationKeyboard", &is_browser_verified_user_activation_keyboard_enabled_ },
        { "BrowserVerifiedUserActivationMouse", &is_browser_verified_user_activation_mouse_enabled_ },
        { "CLSScrollAnchoring", &is_cls_scroll_anchoring_enabled_ },
        { "CSSAnchorPositioning", &is_css_anchor_positioning_enabled_ },
        { "CSSAtRuleCounterStyleImageSymbols", &is_css_at_rule_counter_style_image_symbols_enabled_ },
        { "CSSAtRuleCounterStyleSpeakAsDescriptor", &is_css_at_rule_counter_style_speak_as_descriptor_enabled_ },
        { "CSSAtSupportsAlwaysNonForgivingParsing", &is_css_at_supports_always_non_forgiving_parsing_enabled_ },
        { "CSSCalcSimplificationAndSerialization", &is_css_calc_simplification_and_serialization_enabled_ },
        { "CSSCaseSensitiveSelector", &is_css_case_sensitive_selector_enabled_ },
        { "CSSColor4", &is_css_color_4_enabled_ },
        { "CSSColorContrast", &is_css_color_contrast_enabled_ },
        { "CSSColorTypedOM", &is_css_color_typed_om_enabled_ },
        { "CSSContainSize1D", &is_css_contain_size_1d_enabled_ },
        { "CSSContainerQueries", &is_css_container_queries_enabled_ },
        { "CSSContainerRelativeUnits", &is_css_container_relative_units_enabled_ },
        { "CSSContainerSkipStyleRecalc", &is_css_container_skip_style_recalc_enabled_ },
        { "CSSEnumeratedCustomProperties", &is_css_enumerated_custom_properties_enabled_ },
        { "CSSFocusVisible", &is_css_focus_visible_enabled_ },
        { "CSSFoldables", &is_css_foldables_enabled_ },
        { "CSSFontFaceAutoVariableRange", &is_css_font_face_auto_variable_range_enabled_ },
        { "CSSFontFaceSrcTechParsing", &is_css_font_face_src_tech_parsing_enabled_ },
        { "CSSFontFamilyMath", &is_css_font_family_math_enabled_ },
        { "CSSFontSizeAdjust", &is_css_font_size_adjust_enabled_ },
        { "CSSGridTemplatePropertyInterpolation", &is_css_grid_template_property_interpolation_enabled_ },
        { "CSSHexAlphaColor", &is_css_hex_alpha_color_enabled_ },
        { "CSSHyphenateLimitChars", &is_css_hyphenate_limit_chars_enabled_ },
        { "CSSIcUnit", &is_css_ic_unit_enabled_ },
        { "CSSIndependentTransformProperties", &is_css_independent_transform_properties_enabled_ },
        { "CSSInitialLetter", &is_css_initial_letter_enabled_ },
        { "CSSLastBaseline", &is_css_last_baseline_enabled_ },
        { "CSSLayoutAPI", &is_css_layout_api_enabled_ },
        { "CSSLhUnit", &is_css_lh_unit_enabled_ },
        { "CSSLogical", &is_css_logical_enabled_ },
        { "CSSLogicalOverflow", &is_css_logical_overflow_enabled_ },
        { "CSSMarkerNestedPseudoElement", &is_css_marker_nested_pseudo_element_enabled_ },
        { "CSSMathDepth", &is_css_math_depth_enabled_ },
        { "CSSMathShift", &is_css_math_shift_enabled_ },
        { "CSSMathStyle", &is_css_math_style_enabled_ },
        { "CSSMathVariant", &is_css_math_variant_enabled_ },
        { "CSSMediaQueries4", &is_css_media_queries_4_enabled_ },
        { "CSSMixBlendModePlusLighter", &is_css_mix_blend_mode_plus_lighter_enabled_ },
        { "CSSObjectViewBox", &is_css_object_view_box_enabled_ },
        { "CSSOffsetPathRay", &is_css_offset_path_ray_enabled_ },
        { "CSSOffsetPathRayContain", &is_css_offset_path_ray_contain_enabled_ },
        { "CSSOffsetPositionAnchor", &is_css_offset_position_anchor_enabled_ },
        { "CSSOverflowForReplacedElements", &is_css_overflow_for_replaced_elements_enabled_ },
        { "CSSPaintAPIArguments", &is_css_paint_api_arguments_enabled_ },
        { "CSSPictureInPicture", &is_css_picture_in_picture_enabled_ },
        { "CSSPositionStickyStaticScrollPosition", &is_css_position_sticky_static_scroll_position_enabled_ },
        { "CSSPseudoAutofill", &is_css_pseudo_autofill_enabled_ },
        { "CSSPseudoDir", &is_css_pseudo_dir_enabled_ },
        { "CSSPseudoHas", &is_css_pseudo_has_enabled_ },
        { "CSSPseudoPlayingPaused", &is_css_pseudo_playing_paused_enabled_ },
        { "CSSScope", &is_css_scope_enabled_ },
        { "CSSScrollTimeline", &is_css_scroll_timeline_enabled_ },
        { "CSSScrollbars", &is_css_scrollbars_enabled_ },
        { "CSSSelectorFragmentAnchor", &is_css_selector_fragment_anchor_enabled_ },
        { "CSSSnapSize", &is_css_snap_size_enabled_ },
        { "CSSSpellingGrammarErrors", &is_css_spelling_grammar_errors_enabled_ },
        { "CSSStyleQueries", &is_css_style_queries_enabled_ },
        { "CSSToggles", &is_css_toggles_enabled_ },
        { "CSSTrigonometricFunctions", &is_css_trigonometric_functions_enabled_ },
        { "CSSVariables2ImageValues", &is_css_variables_2_image_values_enabled_ },
        { "CSSVariables2TransformValues", &is_css_variables_2_transform_values_enabled_ },
        { "CSSVideoDynamicRangeMediaQueries", &is_css_video_dynamic_range_media_queries_enabled_ },
        { "CSSViewTimeline", &is_css_view_timeline_enabled_ },
        { "CSSViewportUnits4", &is_css_viewport_units_4_enabled_ },
        { "CacheStorageCodeCacheHint", &is_cache_storage_code_cache_hint_enabled_ },
        { "Canvas2dImageChromium", &is_canvas_2d_image_chromium_enabled_ },
        { "Canvas2dLayers", &is_canvas_2d_layers_enabled_ },
        { "Canvas2dScrollPathIntoView", &is_canvas_2d_scroll_path_into_view_enabled_ },
        { "CanvasColorManagementV2", &is_canvas_color_management_v_2_enabled_ },
        { "CanvasHDR", &is_canvas_hdr_enabled_ },
        { "CanvasImageSmoothing", &is_canvas_image_smoothing_enabled_ },
        { "CapabilityDelegationFullscreenRequest", &is_capability_delegation_fullscreen_request_enabled_ },
        { "CaptureHandle", &is_capture_handle_enabled_ },
        { "ClearIdentityInCanMakePaymentEvent", &is_clear_identity_in_can_make_payment_event_enabled_ },
        { "ClickToCapturedPointer", &is_click_to_captured_pointer_enabled_ },
        { "ClientHintThirdPartyDelegation", &is_client_hint_third_party_delegation_enabled_ },
        { "ClientHintsMetaEquivDelegateCH", &is_client_hints_meta_equiv_delegate_ch_enabled_ },
        { "ClientHintsMetaHTTPEquivAcceptCH", &is_client_hints_meta_http_equiv_accept_ch_enabled_ },
        { "ClipboardCustomFormats", &is_clipboard_custom_formats_enabled_ },
        { "ClipboardSvg", &is_clipboard_svg_enabled_ },
        { "ClipboardUnsanitizedContent", &is_clipboard_unsanitized_content_enabled_ },
        { "CloseWatcher", &is_close_watcher_enabled_ },
        { "CoepReflection", &is_coep_reflection_enabled_ },
        { "CompositeBGColorAnimation", &is_composite_bg_color_animation_enabled_ },
        { "CompositeBoxShadowAnimation", &is_composite_box_shadow_animation_enabled_ },
        { "CompositeClipPathAnimation", &is_composite_clip_path_animation_enabled_ },
        { "CompositedSelectionUpdate", &is_composited_selection_update_enabled_ },
        { "ComputePressure", &is_compute_pressure_enabled_ },
        { "ComputedAccessibilityInfo", &is_computed_accessibility_info_enabled_ },
        { "ConditionalFocus", &is_conditional_focus_enabled_ },
        { "ConsolidatedMovementXY", &is_consolidated_movement_xy_enabled_ },
        { "ContactsManager", &is_contacts_manager_enabled_ },
        { "ContactsManagerExtraProperties", &is_contacts_manager_extra_properties_enabled_ },
        { "ContentIndex", &is_content_index_enabled_ },
        { "ContentVisibilityAutoStateChangeEvent", &is_content_visibility_auto_state_change_event_enabled_ },
        { "ContextMenu", &is_context_menu_enabled_ },
        { "CooperativeScheduling", &is_cooperative_scheduling_enabled_ },
        { "CorsRFC1918", &is_cors_rfc_1918_enabled_ },
        { "CrossOriginOpenerPolicyReporting", &is_cross_origin_opener_policy_reporting_enabled_ },
        { "CustomElementDefaultStyle", &is_custom_element_default_style_enabled_ },
        { "Database", &is_database_enabled_ },
        { "DecodeJpeg420ImagesToYUV", &is_decode_jpeg_420_images_to_yuv_enabled_ },
        { "DecodeLossyWebPImagesToYUV", &is_decode_lossy_web_p_images_to_yuv_enabled_ },
        { "DeferredShaping", &is_deferred_shaping_enabled_ },
        { "DeflateRawCompressionFormat", &is_deflate_raw_compression_format_enabled_ },
        { "DelegatedInkTrails", &is_delegated_ink_trails_enabled_ },
        { "DeliveryType", &is_delivery_type_enabled_ },
        { "DesktopCaptureDisableLocalEchoControl", &is_desktop_capture_disable_local_echo_control_enabled_ },
        { "DesktopPWAsSubApps", &is_desktop_pw_as_sub_apps_enabled_ },
        { "DeviceAttributes", &is_device_attributes_enabled_ },
        { "DeviceOrientationRequestPermission", &is_device_orientation_request_permission_enabled_ },
        { "DevicePosture", &is_device_posture_enabled_ },
        { "DigitalGoods", &is_digital_goods_enabled_ },
        { "DigitalGoodsV2_1", &is_digital_goods_v_2_1_enabled_ },
        { "DirectSockets", &is_direct_sockets_enabled_ },
        { "DisableDifferentOriginSubframeDialogSuppression", &is_disable_different_origin_subframe_dialog_suppression_enabled_ },
        { "DisableHardwareNoiseSuppression", &is_disable_hardware_noise_suppression_enabled_ },
        { "DisplayCutoutAPI", &is_display_cutout_api_enabled_ },
        { "DisplaySurfaceConstraint", &is_display_surface_constraint_enabled_ },
        { "DocumentCookie", &is_document_cookie_enabled_ },
        { "DocumentDomain", &is_document_domain_enabled_ },
        { "DocumentPictureInPictureAPI", &is_document_picture_in_picture_api_enabled_ },
        { "DocumentPolicy", &is_document_policy_enabled_ },
        { "DocumentPolicyDocumentDomain", &is_document_policy_document_domain_enabled_ },
        { "DocumentPolicyNegotiation", &is_document_policy_negotiation_enabled_ },
        { "DocumentPolicySyncXHR", &is_document_policy_sync_xhr_enabled_ },
        { "DocumentTransition", &is_document_transition_enabled_ },
        { "DocumentWrite", &is_document_write_enabled_ },
        { "EarlyHintsPreloadForNavigationOptIn", &is_early_hints_preload_for_navigation_opt_in_enabled_ },
        { "EditContext", &is_edit_context_enabled_ },
        { "ElementSuperRareData", &is_element_super_rare_data_enabled_ },
        { "EventPath", &is_event_path_enabled_ },
        { "ExperimentalContentSecurityPolicyFeatures", &is_experimental_content_security_policy_features_enabled_ },
        { "ExperimentalJSProfilerMarkers", &is_experimental_js_profiler_markers_enabled_ },
        { "ExperimentalPolicies", &is_experimental_policies_enabled_ },
        { "ExperimentalWebSnapshots", &is_experimental_web_snapshots_enabled_ },
        { "ExtendedTextMetrics", &is_extended_text_metrics_enabled_ },
        { "ExtraWebGLVideoTextureMetadata", &is_extra_webgl_video_texture_metadata_enabled_ },
        { "EyeDropperAPI", &is_eye_dropper_api_enabled_ },
        { "FaceDetector", &is_face_detector_enabled_ },
        { "FakeNoAllocDirectCallForTesting", &is_fake_no_alloc_direct_call_for_testing_enabled_ },
        { "FeaturePolicyReporting", &is_feature_policy_reporting_enabled_ },
        { "FedCm", &is_fed_cm_enabled_ },
        { "FedCmIdpSigninStatus", &is_fed_cm_idp_signin_status_enabled_ },
        { "FedCmIdpSignout", &is_fed_cm_idp_signout_enabled_ },
        { "FedCmIframeSupport", &is_fed_cm_iframe_support_enabled_ },
        { "FedCmMultipleIdentityProviders", &is_fed_cm_multiple_identity_providers_enabled_ },
        { "FencedFrames", &is_fenced_frames_enabled_ },
        { "FetchUploadStreaming", &is_fetch_upload_streaming_enabled_ },
        { "FileHandling", &is_file_handling_enabled_ },
        { "FileHandlingIcons", &is_file_handling_icons_enabled_ },
        { "FileSystem", &is_file_system_enabled_ },
        { "FileSystemAccess", &is_file_system_access_enabled_ },
        { "FileSystemAccessAPIExperimental", &is_file_system_access_api_experimental_enabled_ },
        { "FileSystemAccessAccessHandle", &is_file_system_access_access_handle_enabled_ },
        { "FileSystemAccessLocal", &is_file_system_access_local_enabled_ },
        { "FileSystemAccessOriginPrivate", &is_file_system_access_origin_private_enabled_ },
        { "FileSystemSyncAccessHandleAsyncInterfaceOverride", &is_file_system_sync_access_handle_async_interface_override_enabled_ },
        { "FirstPartySets", &is_first_party_sets_enabled_ },
        { "FixedElementsDontOverscroll", &is_fixed_elements_dont_overscroll_enabled_ },
        { "Fledge", &is_fledge_enabled_ },
        { "FluentScrollbars", &is_fluent_scrollbars_enabled_ },
        { "Focusgroup", &is_focusgroup_enabled_ },
        { "FocuslessSpatialNavigation", &is_focusless_spatial_navigation_enabled_ },
        { "FontAccess", &is_font_access_enabled_ },
        { "FontPalette", &is_font_palette_enabled_ },
        { "FontSrcLocalMatching", &is_font_src_local_matching_enabled_ },
        { "ForceEagerMeasureMemory", &is_force_eager_measure_memory_enabled_ },
        { "ForceReduceMotion", &is_force_reduce_motion_enabled_ },
        { "ForceTallerSelectPopup", &is_force_taller_select_popup_enabled_ },
        { "ForcedColors", &is_forced_colors_enabled_ },
        { "ForcedColorsPreserveParentColor", &is_forced_colors_preserve_parent_color_enabled_ },
        { "FormRelAttribute", &is_form_rel_attribute_enabled_ },
        { "FormattedText", &is_formatted_text_enabled_ },
        { "FractionalScrollOffsets", &is_fractional_scroll_offsets_enabled_ },
        { "FreezeFramesOnVisibility", &is_freeze_frames_on_visibility_enabled_ },
        { "GamepadButtonAxisEvents", &is_gamepad_button_axis_events_enabled_ },
        { "GetDisplayMedia", &is_get_display_media_enabled_ },
        { "GetDisplayMediaSet", &is_get_display_media_set_enabled_ },
        { "GetDisplayMediaSetAutoSelectAllScreens", &is_get_display_media_set_auto_select_all_screens_enabled_ },
        { "GroupEffect", &is_group_effect_enabled_ },
        { "HTMLParamElementUrlSupport", &is_html_param_element_url_support_enabled_ },
        { "HTMLPopupAttribute", &is_html_popup_attribute_enabled_ },
        { "HTMLSelectMenuElement", &is_html_select_menu_element_enabled_ },
        { "HandwritingRecognition", &is_handwriting_recognition_enabled_ },
        { "HidDeviceForget", &is_hid_device_forget_enabled_ },
        { "HighlightAPI", &is_highlight_api_enabled_ },
        { "HighlightInheritance", &is_highlight_inheritance_enabled_ },
        { "HighlightOverlayPainting", &is_highlight_overlay_painting_enabled_ },
        { "HighlightPointerEvents", &is_highlight_pointer_events_enabled_ },
        { "HrefTranslate", &is_href_translate_enabled_ },
        { "IDBBatchGetAll", &is_idb_batch_get_all_enabled_ },
        { "IdleDetection", &is_idle_detection_enabled_ },
        { "ImplicitRootScroller", &is_implicit_root_scroller_enabled_ },
        { "InertAttribute", &is_inert_attribute_enabled_ },
        { "InfiniteCullRect", &is_infinite_cull_rect_enabled_ },
        { "InputMultipleFieldsUI", &is_input_multiple_fields_ui_enabled_ },
        { "InstalledApp", &is_installed_app_enabled_ },
        { "KeyboardAccessibleTooltip", &is_keyboard_accessible_tooltip_enabled_ },
        { "KeyboardFocusableScrollers", &is_keyboard_focusable_scrollers_enabled_ },
        { "LCPAnimatedImagesWebExposed", &is_lcp_animated_images_web_exposed_enabled_ },
        { "LangAttributeAwareFormControlUI", &is_lang_attribute_aware_form_control_ui_enabled_ },
        { "LangAttributeAwareSvgText", &is_lang_attribute_aware_svg_text_enabled_ },
        { "LayoutNG", &is_layout_ng_enabled_ },
        { "LayoutNGBlockFragmentation", &is_layout_ng_block_fragmentation_enabled_ },
        { "LayoutNGBlockInInline", &is_layout_ng_block_in_inline_enabled_ },
        { "LayoutNGDelayScrollOffsetClamping", &is_layout_ng_delay_scroll_offset_clamping_enabled_ },
        { "LayoutNGFlexFragmentation", &is_layout_ng_flex_fragmentation_enabled_ },
        { "LayoutNGForeignObject", &is_layout_ng_foreign_object_enabled_ },
        { "LayoutNGFrameSet", &is_layout_ng_frame_set_enabled_ },
        { "LayoutNGGridFragmentation", &is_layout_ng_grid_fragmentation_enabled_ },
        { "LayoutNGPrinting", &is_layout_ng_printing_enabled_ },
        { "LayoutNGSubgrid", &is_layout_ng_subgrid_enabled_ },
        { "LayoutNGTableFragmentation", &is_layout_ng_table_fragmentation_enabled_ },
        { "LayoutNGVTTCue", &is_layout_ngvtt_cue_enabled_ },
        { "LazyFrameLoading", &is_lazy_frame_loading_enabled_ },
        { "LazyFrameVisibleLoadTimeMetrics", &is_lazy_frame_visible_load_time_metrics_enabled_ },
        { "LazyImageLoading", &is_lazy_image_loading_enabled_ },
        { "LazyImageVisibleLoadTimeMetrics", &is_lazy_image_visible_load_time_metrics_enabled_ },
        { "LazyInitializeMediaControls", &is_lazy_initialize_media_controls_enabled_ },
        { "LegacyWindowsDWriteFontFallback", &is_legacy_windows_d_write_font_fallback_enabled_ },
        { "MachineLearningCommon", &is_machine_learning_common_enabled_ },
        { "MachineLearningModelLoader", &is_machine_learning_model_loader_enabled_ },
        { "MachineLearningNeuralNetwork", &is_machine_learning_neural_network_enabled_ },
        { "ManagedConfiguration", &is_managed_configuration_enabled_ },
        { "MathMLCore", &is_mathml_core_enabled_ },
        { "MeasureMemory", &is_measure_memory_enabled_ },
        { "MediaCapabilitiesDynamicRange", &is_media_capabilities_dynamic_range_enabled_ },
        { "MediaCapabilitiesEncodingInfo", &is_media_capabilities_encoding_info_enabled_ },
        { "MediaCapabilitiesSpatialAudio", &is_media_capabilities_spatial_audio_enabled_ },
        { "MediaCapture", &is_media_capture_enabled_ },
        { "MediaCaptureBackgroundBlur", &is_media_capture_background_blur_enabled_ },
        { "MediaCastOverlayButton", &is_media_cast_overlay_button_enabled_ },
        { "MediaControlsExpandGesture", &is_media_controls_expand_gesture_enabled_ },
        { "MediaControlsOverlayPlayButton", &is_media_controls_overlay_play_button_enabled_ },
        { "MediaElementVolumeGreaterThanOne", &is_media_element_volume_greater_than_one_enabled_ },
        { "MediaEngagementBypassAutoplayPolicies", &is_media_engagement_bypass_autoplay_policies_enabled_ },
        { "MediaLatencyHint", &is_media_latency_hint_enabled_ },
        { "MediaQueryNavigationControls", &is_media_query_navigation_controls_enabled_ },
        { "MediaSession", &is_media_session_enabled_ },
        { "MediaSessionWebRTC", &is_media_session_web_rtc_enabled_ },
        { "MediaSourceExperimental", &is_media_source_experimental_enabled_ },
        { "MediaSourceExtensionsForWebCodecs", &is_media_source_extensions_for_webcodecs_enabled_ },
        { "MediaSourceInWorkers", &is_media_source_in_workers_enabled_ },
        { "MediaSourceInWorkersUsingHandle", &is_media_source_in_workers_using_handle_enabled_ },
        { "MediaSourceNewAbortAndDuration", &is_media_source_new_abort_and_duration_enabled_ },
        { "MediaSourceStable", &is_media_source_stable_enabled_ },
        { "MediaStreamTrackInWindow", &is_media_stream_track_in_window_enabled_ },
        { "MediaStreamTrackInWorker", &is_media_stream_track_in_worker_enabled_ },
        { "MediaStreamTrackTransfer", &is_media_stream_track_transfer_enabled_ },
        { "MiddleClickAutoscroll", &is_middle_click_autoscroll_enabled_ },
        { "MobileLayoutTheme", &is_mobile_layout_theme_enabled_ },
        { "MojoJS", &is_mojo_js_enabled_ },
        { "MojoJSTest", &is_mojo_js_test_enabled_ },
        { "MouseSubframeNoImplicitCapture", &is_mouse_subframe_no_implicit_capture_enabled_ },
        { "NavigationApi", &is_navigation_api_enabled_ },
        { "NavigationId", &is_navigation_id_enabled_ },
        { "NavigatorContentUtils", &is_navigator_content_utils_enabled_ },
        { "NetInfoDownlinkMax", &is_net_info_downlink_max_enabled_ },
        { "NeverSlowMode", &is_never_slow_mode_enabled_ },
        { "NewFlexboxSizing", &is_new_flexbox_sizing_enabled_ },
        { "NoIdleEncodingForWebTests", &is_no_idle_encoding_for_web_tests_enabled_ },
        { "NotificationConstructor", &is_notification_constructor_enabled_ },
        { "NotificationContentImage", &is_notification_content_image_enabled_ },
        { "NotificationTriggers", &is_notification_triggers_enabled_ },
        { "Notifications", &is_notifications_enabled_ },
        { "OffMainThreadCSSPaint", &is_off_main_thread_css_paint_enabled_ },
        { "OffscreenCanvasCommit", &is_offscreen_canvas_commit_enabled_ },
        { "OffsetParentNewSpecBehavior", &is_offset_parent_new_spec_behavior_enabled_ },
        { "OnDeviceChange", &is_on_device_change_enabled_ },
        { "OrientationEvent", &is_orientation_event_enabled_ },
        { "OriginIsolationHeader", &is_origin_isolation_header_enabled_ },
        { "OriginPolicy", &is_origin_policy_enabled_ },
        { "OriginTrialsSampleAPI", &is_origin_trials_sample_api_enabled_ },
        { "OriginTrialsSampleAPIDependent", &is_origin_trials_sample_api_dependent_enabled_ },
        { "OriginTrialsSampleAPIDeprecation", &is_origin_trials_sample_api_deprecation_enabled_ },
        { "OriginTrialsSampleAPIExpiryGracePeriod", &is_origin_trials_sample_api_expiry_grace_period_enabled_ },
        { "OriginTrialsSampleAPIExpiryGracePeriodThirdParty", &is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_ },
        { "OriginTrialsSampleAPIImplied", &is_origin_trials_sample_api_implied_enabled_ },
        { "OriginTrialsSampleAPIInvalidOS", &is_origin_trials_sample_api_invalid_os_enabled_ },
        { "OriginTrialsSampleAPINavigation", &is_origin_trials_sample_api_navigation_enabled_ },
        { "OriginTrialsSampleAPIPersistentExpiryGracePeriod", &is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_ },
        { "OriginTrialsSampleAPIPersistentFeature", &is_origin_trials_sample_api_persistent_feature_enabled_ },
        { "OriginTrialsSampleAPIThirdParty", &is_origin_trials_sample_api_third_party_enabled_ },
        { "OverscrollCustomization", &is_overscroll_customization_enabled_ },
        { "PNaCl", &is_p_na_cl_enabled_ },
        { "PageFreezeOptIn", &is_page_freeze_opt_in_enabled_ },
        { "PageFreezeOptOut", &is_page_freeze_opt_out_enabled_ },
        { "PagePopup", &is_page_popup_enabled_ },
        { "PaintUnderInvalidationChecking", &is_paint_under_invalidation_checking_enabled_ },
        { "Parakeet", &is_parakeet_enabled_ },
        { "ParallelPrimaryFont", &is_parallel_primary_font_enabled_ },
        { "ParallelTextShaping", &is_parallel_text_shaping_enabled_ },
        { "PartitionedCookies", &is_partitioned_cookies_enabled_ },
        { "PasswordReveal", &is_password_reveal_enabled_ },
        { "PaymentApp", &is_payment_app_enabled_ },
        { "PaymentMethodChangeEvent", &is_payment_method_change_event_enabled_ },
        { "PaymentRequest", &is_payment_request_enabled_ },
        { "PaymentRequestMerchantValidationEvent", &is_payment_request_merchant_validation_event_enabled_ },
        { "PendingBeaconAPI", &is_pending_beacon_api_enabled_ },
        { "PerMethodCanMakePaymentQuota", &is_per_method_can_make_payment_quota_enabled_ },
        { "PercentBasedScrolling", &is_percent_based_scrolling_enabled_ },
        { "PerformanceManagerInstrumentation", &is_performance_manager_instrumentation_enabled_ },
        { "PeriodicBackgroundSync", &is_periodic_background_sync_enabled_ },
        { "Permissions", &is_permissions_enabled_ },
        { "PermissionsPolicyUnload", &is_permissions_policy_unload_enabled_ },
        { "PermissionsRequestRevoke", &is_permissions_request_revoke_enabled_ },
        { "PictureInPicture", &is_picture_in_picture_enabled_ },
        { "PictureInPictureAPI", &is_picture_in_picture_api_enabled_ },
        { "PointerLockOptions", &is_pointer_lock_options_enabled_ },
        { "Portals", &is_portals_enabled_ },
        { "PreciseMemoryInfo", &is_precise_memory_info_enabled_ },
        { "PreferNonCompositedScrolling", &is_prefer_non_composited_scrolling_enabled_ },
        { "PrefersColorSchemeClientHintHeader", &is_prefers_color_scheme_client_hint_header_enabled_ },
        { "PrefersReducedData", &is_prefers_reduced_data_enabled_ },
        { "PrefersReducedMotionClientHintHeader", &is_prefers_reduced_motion_client_hint_header_enabled_ },
        { "PrefixedStorageInfo", &is_prefixed_storage_info_enabled_ },
        { "PrefixedVideoFullscreen", &is_prefixed_video_fullscreen_enabled_ },
        { "Prerender2", &is_prerender_2_enabled_ },
        { "Prerender2RelatedFeatures", &is_prerender_2_related_features_enabled_ },
        { "Presentation", &is_presentation_enabled_ },
        { "PriorityHints", &is_priority_hints_enabled_ },
        { "PrivacySandboxAdsAPIs", &is_privacy_sandbox_ads_api_s_enabled_ },
        { "PrivateNetworkAccessNonSecureContextsAllowed", &is_private_network_access_non_secure_contexts_allowed_enabled_ },
        { "PrivateNetworkAccessPermissionPrompt", &is_private_network_access_permission_prompt_enabled_ },
        { "PushMessaging", &is_push_messaging_enabled_ },
        { "PushMessagingSubscriptionChange", &is_push_messaging_subscription_change_enabled_ },
        { "QuickIntensiveWakeUpThrottlingAfterLoading", &is_quick_intensive_wake_up_throttling_after_loading_enabled_ },
        { "QuotaChange", &is_quota_change_enabled_ },
        { "RTCIceTransportExtension", &is_rtc_ice_transport_extension_enabled_ },
        { "RTCInsertableStreams", &is_rtc_insertable_streams_enabled_ },
        { "RTCQuicTransport", &is_rtc_quic_transport_enabled_ },
        { "RTCRtpHeaderExtensionControl", &is_rtc_rtp_header_extension_control_enabled_ },
        { "RTCStatsRelativePacketArrivalDelay", &is_rtc_stats_relative_packet_arrival_delay_enabled_ },
        { "RTCSvcScalabilityMode", &is_rtc_svc_scalability_mode_enabled_ },
        { "ReduceUserAgentMinorVersion", &is_reduce_user_agent_minor_version_enabled_ },
        { "ReduceUserAgentPlatformOsCpu", &is_reduce_user_agent_platform_os_cpu_enabled_ },
        { "RegionCapture", &is_region_capture_enabled_ },
        { "RemotePlayback", &is_remote_playback_enabled_ },
        { "RemotePlaybackBackend", &is_remote_playback_backend_enabled_ },
        { "RemoveMobileViewportDoubleTap", &is_remove_mobile_viewport_double_tap_enabled_ },
        { "RenderBlockingStatus", &is_render_blocking_status_enabled_ },
        { "RenderPriorityAttribute", &is_render_priority_attribute_enabled_ },
        { "ResourceTimingResponseStatus", &is_resource_timing_response_status_enabled_ },
        { "RestrictGamepadAccess", &is_restrict_gamepad_access_enabled_ },
        { "RtcAudioJitterBufferMaxPackets", &is_rtc_audio_jitter_buffer_max_packets_enabled_ },
        { "SVGTextNG", &is_svg_text_ng_enabled_ },
        { "SanitizerAPI", &is_sanitizer_api_enabled_ },
        { "SanitizerAPIv0", &is_sanitizer_api_v_0_enabled_ },
        { "ScopedCustomElementRegistry", &is_scoped_custom_element_registry_enabled_ },
        { "ScriptElementSupports", &is_script_element_supports_enabled_ },
        { "ScriptedSpeechRecognition", &is_scripted_speech_recognition_enabled_ },
        { "ScriptedSpeechSynthesis", &is_scripted_speech_synthesis_enabled_ },
        { "ScrollCustomization", &is_scroll_customization_enabled_ },
        { "ScrollEndEvents", &is_scroll_end_events_enabled_ },
        { "ScrollTimeline", &is_scroll_timeline_enabled_ },
        { "ScrollTopLeftInterop", &is_scroll_top_left_interop_enabled_ },
        { "ScrollUpdateOptimizations", &is_scroll_update_optimizations_enabled_ },
        { "ScrollbarWidth", &is_scrollbar_width_enabled_ },
        { "SecureContextFixForSharedWorkers", &is_secure_context_fix_for_shared_workers_enabled_ },
        { "SecurePaymentConfirmation", &is_secure_payment_confirmation_enabled_ },
        { "SecurePaymentConfirmationDebug", &is_secure_payment_confirmation_debug_enabled_ },
        { "SecurePaymentConfirmationOptOut", &is_secure_payment_confirmation_opt_out_enabled_ },
        { "SelfBrowserSurfaceConstraint", &is_self_browser_surface_constraint_enabled_ },
        { "SendBeaconThrowForBlobWithNonSimpleType", &is_send_beacon_throw_for_blob_with_non_simple_type_enabled_ },
        { "SendFullUserAgentAfterReduction", &is_send_full_user_agent_after_reduction_enabled_ },
        { "SendMouseEventsDisabledFormControls", &is_send_mouse_events_disabled_form_controls_enabled_ },
        { "SensorExtraClasses", &is_sensor_extra_classes_enabled_ },
        { "Serial", &is_serial_enabled_ },
        { "SerialPortForget", &is_serial_port_forget_enabled_ },
        { "ServiceWorkerClientLifecycleState", &is_service_worker_client_lifecycle_state_enabled_ },
        { "SharedArrayBuffer", &is_shared_array_buffer_enabled_ },
        { "SharedArrayBufferOnDesktop", &is_shared_array_buffer_on_desktop_enabled_ },
        { "SharedArrayBufferUnrestrictedAccessAllowed", &is_shared_array_buffer_unrestricted_access_allowed_enabled_ },
        { "SharedAutofill", &is_shared_autofill_enabled_ },
        { "SharedStorageAPI", &is_shared_storage_api_enabled_ },
        { "SharedWorker", &is_shared_worker_enabled_ },
        { "SignatureBasedIntegrity", &is_signature_based_integrity_enabled_ },
        { "SiteInitiatedMirroring", &is_site_initiated_mirroring_enabled_ },
        { "SkipAd", &is_skip_ad_enabled_ },
        { "SkipTouchEventFilter", &is_skip_touch_event_filter_enabled_ },
        { "SoftNavigationHeuristics", &is_soft_navigation_heuristics_enabled_ },
        { "SpeculationRules", &is_speculation_rules_enabled_ },
        { "SpeculationRulesFetchFromHeader", &is_speculation_rules_fetch_from_header_enabled_ },
        { "SpeculationRulesPrefetchProxy", &is_speculation_rules_prefetch_proxy_enabled_ },
        { "SpeculationRulesPrefetchWithSubresources", &is_speculation_rules_prefetch_with_subresources_enabled_ },
        { "SrcsetMaxDensity", &is_srcset_max_density_enabled_ },
        { "StableBlinkFeatures", &is_stable_blink_features_enabled_ },
        { "StorageAccessAPI", &is_storage_access_api_enabled_ },
        { "StorageAccessAPIForOriginExtension", &is_storage_access_api_for_origin_extension_enabled_ },
        { "StorageBuckets", &is_storage_buckets_enabled_ },
        { "StorageFoundationAPI", &is_storage_foundation_api_enabled_ },
        { "StrictMimeTypesForWorkers", &is_strict_mime_types_for_workers_enabled_ },
        { "StylusHandwriting", &is_stylus_handwriting_enabled_ },
        { "SupportsFontFormatTech", &is_supports_font_format_tech_enabled_ },
        { "SurfaceSwitchingConstraint", &is_surface_switching_constraint_enabled_ },
        { "SynthesizedKeyboardEventsForAccessibilityActions", &is_synthesized_keyboard_events_for_accessibility_actions_enabled_ },
        { "SystemAudioConstraint", &is_system_audio_constraint_enabled_ },
        { "SystemWakeLock", &is_system_wake_lock_enabled_ },
        { "TestFeature", &is_test_feature_enabled_ },
        { "TestFeatureDependent", &is_test_feature_dependent_enabled_ },
        { "TestFeatureImplied", &is_test_feature_implied_enabled_ },
        { "TextDecoratingBox", &is_text_decorating_box_enabled_ },
        { "TextDetector", &is_text_detector_enabled_ },
        { "TextFragmentAPI", &is_text_fragment_api_enabled_ },
        { "TextFragmentIdentifiers", &is_text_fragment_identifiers_enabled_ },
        { "TextFragmentTapOpensContextMenu", &is_text_fragment_tap_opens_context_menu_enabled_ },
        { "ThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframes", &is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_ },
        { "TimeZoneChangeEvent", &is_time_zone_change_event_enabled_ },
        { "TimerThrottlingForBackgroundTabs", &is_timer_throttling_for_background_tabs_enabled_ },
        { "TopicsAPI", &is_topics_api_enabled_ },
        { "TouchActionEffectiveAtPointerDown", &is_touch_action_effective_at_pointer_down_enabled_ },
        { "TouchDragAndContextMenu", &is_touch_drag_and_context_menu_enabled_ },
        { "TouchDragOnShortPress", &is_touch_drag_on_short_press_enabled_ },
        { "TouchEventFeatureDetection", &is_touch_event_feature_detection_enabled_ },
        { "TranslateService", &is_translate_service_enabled_ },
        { "TrustTokens", &is_trust_tokens_enabled_ },
        { "TrustTokensAlwaysAllowIssuance", &is_trust_tokens_always_allow_issuance_enabled_ },
        { "TrustedTypeBeforePolicyCreationEvent", &is_trusted_type_before_policy_creation_event_enabled_ },
        { "TrustedTypesUseCodeLike", &is_trusted_types_use_code_like_enabled_ },
        { "U2FSecurityKeyAPI", &is_u_2_f_security_key_api_enabled_ },
        { "URLPatternCompareComponent", &is_url_pattern_compare_component_enabled_ },
        { "UnclosedFormControlIsInvalid", &is_unclosed_form_control_is_invalid_enabled_ },
        { "UnexposedTaskIds", &is_unexposed_task_ids_enabled_ },
        { "UnrestrictedSharedArrayBuffer", &is_unrestricted_shared_array_buffer_enabled_ },
        { "UserActivationSameOriginVisibility", &is_user_activation_same_origin_visibility_enabled_ },
        { "UserAgentClientHint", &is_user_agent_client_hint_enabled_ },
        { "UserAgentReduction", &is_user_agent_reduction_enabled_ },
        { "V8IdleTasks", &is_v8_idle_tasks_enabled_ },
        { "VariableCOLRV1", &is_variable_colrv_1_enabled_ },
        { "VideoAutoFullscreen", &is_video_auto_fullscreen_enabled_ },
        { "VideoFullscreenOrientationLock", &is_video_fullscreen_orientation_lock_enabled_ },
        { "VideoPlaybackQuality", &is_video_playback_quality_enabled_ },
        { "VideoRotateToFullscreen", &is_video_rotate_to_fullscreen_enabled_ },
        { "VideoTrackGenerator", &is_video_track_generator_enabled_ },
        { "VideoTrackGeneratorInWindow", &is_video_track_generator_in_window_enabled_ },
        { "VideoTrackGeneratorInWorker", &is_video_track_generator_in_worker_enabled_ },
        { "VideoWakeLockOptimisationHiddenMuted", &is_video_wake_lock_optimisation_hidden_muted_enabled_ },
        { "ViewportHeightClientHintHeader", &is_viewport_height_client_hint_header_enabled_ },
        { "ViewportMetaInteractiveWidgetProperty", &is_viewport_meta_interactive_widget_property_enabled_ },
        { "ViewportSegments", &is_viewport_segments_enabled_ },
        { "VisibilityCollapseColumn", &is_visibility_collapse_column_enabled_ },
        { "VisibilityStateEntry", &is_visibility_state_entry_enabled_ },
        { "WGIGamepadTriggerRumble", &is_wgi_gamepad_trigger_rumble_enabled_ },
        { "WakeLock", &is_wake_lock_enabled_ },
        { "WarnOnContentVisibilityRenderAccess", &is_warn_on_content_visibility_render_access_enabled_ },
        { "WebAnimationsAPI", &is_web_animations_api_enabled_ },
        { "WebAnimationsSVG", &is_web_animations_svg_enabled_ },
        { "WebAppDarkMode", &is_web_app_dark_mode_enabled_ },
        { "WebAppLaunchHandler", &is_web_app_launch_handler_enabled_ },
        { "WebAppLaunchQueue", &is_web_app_launch_queue_enabled_ },
        { "WebAppTabStrip", &is_web_app_tab_strip_enabled_ },
        { "WebAppTranslations", &is_web_app_translations_enabled_ },
        { "WebAppUrlHandling", &is_web_app_url_handling_enabled_ },
        { "WebAppWindowControlsOverlay", &is_web_app_window_controls_overlay_enabled_ },
        { "WebAppsLockScreen", &is_web_apps_lock_screen_enabled_ },
        { "WebAssemblyCSP", &is_web_assembly_csp_enabled_ },
        { "WebAssemblyExceptions", &is_web_assembly_exceptions_enabled_ },
        { "WebAuth", &is_web_auth_enabled_ },
        { "WebAuthAuthenticatorAttachment", &is_web_auth_authenticator_attachment_enabled_ },
        { "WebAuthenticationConditionalUI", &is_web_authentication_conditional_ui_enabled_ },
        { "WebAuthenticationDevicePublicKey", &is_web_authentication_device_public_key_enabled_ },
        { "WebAuthenticationLargeBlobExtension", &is_web_authentication_large_blob_extension_enabled_ },
        { "WebAuthenticationRemoteDesktopSupport", &is_web_authentication_remote_desktop_support_enabled_ },
        { "WebBluetooth", &is_web_bluetooth_enabled_ },
        { "WebBluetoothGetDevices", &is_web_bluetooth_get_devices_enabled_ },
        { "WebBluetoothScanning", &is_web_bluetooth_scanning_enabled_ },
        { "WebBluetoothWatchAdvertisements", &is_web_bluetooth_watch_advertisements_enabled_ },
        { "WebCodecs", &is_webcodecs_enabled_ },
        { "WebCodecsDequeueEvent", &is_webcodecs_dequeue_event_enabled_ },
        { "WebGLColorManagement", &is_webgl_color_management_enabled_ },
        { "WebGLDeveloperExtensions", &is_webgl_developer_extensions_enabled_ },
        { "WebGLDraftExtensions", &is_webgl_draft_extensions_enabled_ },
        { "WebGLImageChromium", &is_webgl_image_chromium_enabled_ },
        { "WebGPU", &is_webgpu_enabled_ },
        { "WebGPUDeveloperFeatures", &is_webgpu_developer_features_enabled_ },
        { "WebGPUImportTexture", &is_webgpu_import_texture_enabled_ },
        { "WebHID", &is_web_hid_enabled_ },
        { "WebHIDExclusionFiltersOption", &is_web_hid_exclusion_filters_option_enabled_ },
        { "WebHIDOnServiceWorkers", &is_web_hid_on_service_workers_enabled_ },
        { "WebKitScrollbarStyling", &is_web_kit_scrollbar_styling_enabled_ },
        { "WebNFC", &is_web_nfc_enabled_ },
        { "WebNFCMakeReadOnly", &is_web_nfc_make_read_only_enabled_ },
        { "WebOTP", &is_web_otp_enabled_ },
        { "WebOTPAssertionFeaturePolicy", &is_web_otp_assertion_feature_policy_enabled_ },
        { "WebPaymentAPICSP", &is_web_payment_api_csp_enabled_ },
        { "WebShare", &is_web_share_enabled_ },
        { "WebSocketStream", &is_websocket_stream_enabled_ },
        { "WebTransportCustomCertificates", &is_web_transport_custom_certificates_enabled_ },
        { "WebUSB", &is_web_usb_enabled_ },
        { "WebUSBOnDedicatedWorkers", &is_web_usb_on_dedicated_workers_enabled_ },
        { "WebUSBOnServiceWorkers", &is_web_usb_on_service_workers_enabled_ },
        { "WebUsbDeviceForget", &is_web_usb_device_forget_enabled_ },
        { "WebVTTRegions", &is_web_vtt_regions_enabled_ },
        { "WebXR", &is_web_xr_enabled_ },
        { "WebXRARModule", &is_web_xr_ar_module_enabled_ },
        { "WebXRAnchors", &is_web_xr_anchors_enabled_ },
        { "WebXRCameraAccess", &is_web_xr_camera_access_enabled_ },
        { "WebXRDepth", &is_web_xr_depth_enabled_ },
        { "WebXRHandInput", &is_web_xr_hand_input_enabled_ },
        { "WebXRHitTest", &is_web_xr_hit_test_enabled_ },
        { "WebXRHitTestEntityTypes", &is_web_xr_hit_test_entity_types_enabled_ },
        { "WebXRImageTracking", &is_web_xr_image_tracking_enabled_ },
        { "WebXRLightEstimation", &is_web_xr_light_estimation_enabled_ },
        { "WebXRPlaneDetection", &is_web_xr_plane_detection_enabled_ },
        { "WebXRViewportScale", &is_web_xr_viewport_scale_enabled_ },
        { "WindowDefaultStatus", &is_window_default_status_enabled_ },
        { "WindowOpenNewPopupBehavior", &is_window_open_new_popup_behavior_enabled_ },
        { "WindowPlacement", &is_window_placement_enabled_ },
        { "WindowPlacementEnhancedScreenLabels", &is_window_placement_enhanced_screen_labels_enabled_ },
        { "WindowPlacementFullscreenOnScreensChange", &is_window_placement_fullscreen_on_screens_change_enabled_ },
        { "ZeroCopyTabCapture", &is_zero_copy_tab_capture_enabled_ },
        { "checkVisibility", &is_check_visibility_enabled_ },
    };

    auto feature = std::lower_bound(std::begin(kFeatures), std::end(kFeatures), name, [](const auto& feature, const std::string& name) { return feature.name < name; });

    if (feature != std::end(kFeatures) && feature->name == name)
        *feature->setting = enable;
    else
        DLOG(ERROR) << "RuntimeEnabledFeature not recognized: " << name;
}

// static
void RuntimeEnabledFeaturesBase::UpdateStatusFromBaseFeatures()
{
    struct BaseFeatureToRuntimeFeatureMap {
        const base::Feature& feature;
        void (*enabler)(bool enable);
        bool if_overridden;
    };
    const BaseFeatureToRuntimeFeatureMap mappings[] = {
        { blink::features::kAdInterestGroupAPI, SetAdInterestGroupAPIEnabled, false },
        { blink::features::kAutofillShadowDOM, SetAutofillShadowDOMEnabled, false },
        { blink::features::kBackForwardCacheSendNotRestoredReasons, SetBackForwardCacheNotRestoredReasonsEnabled, true },
        { blink::features::kBackfaceVisibilityInterop, SetBackfaceVisibilityInteropEnabled, false },
        { blink::features::kBatchFetchRequests, SetBatchFetchRequestsEnabled, false },
        { blink::features::kBlockingFocusWithoutUserActivation, SetBlockingFocusWithoutUserActivationEnabled, false },
        { blink::features::kCLSScrollAnchoring, SetCLSScrollAnchoringEnabled, false },
        { blink::features::kCSSOverflowForReplacedElements, SetCSSOverflowForReplacedElementsEnabled, true },
        { blink::features::kCssSelectorFragmentAnchor, SetCSSSelectorFragmentAnchorEnabled, false },
        { blink::features::kClearIdentityInCanMakePaymentEvent, SetClearIdentityInCanMakePaymentEventEnabled, false },
        { blink::features::kClientHintThirdPartyDelegation, SetClientHintThirdPartyDelegationEnabled, false },
        { blink::features::kClientHintsMetaEquivDelegateCH, SetClientHintsMetaEquivDelegateCHEnabled, false },
        { blink::features::kClientHintsMetaHTTPEquivAcceptCH, SetClientHintsMetaHTTPEquivAcceptCHEnabled, false },
        { blink::features::kClipboardCustomFormats, SetClipboardCustomFormatsEnabled, false },
        { blink::features::kComputePressure, SetComputePressureEnabled, true },
        { blink::features::kDeferredShaping, SetDeferredShapingEnabled, false },
        { blink::features::kDesktopPWAsSubApps, SetDesktopPWAsSubAppsEnabled, false },
        { blink::features::kDocumentTransition, SetDocumentTransitionEnabled, false },
        { blink::features::kEditContext, SetEditContextEnabled, false },
        { blink::features::kElementSuperRareData, SetElementSuperRareDataEnabled, false },
        { blink::features::kEventPath, SetEventPathEnabled, false },
        { blink::features::kFileHandlingAPI, SetFileHandlingEnabled, false },
        { blink::features::kFixedElementsDontOverscroll, SetFixedElementsDontOverscrollEnabled, false },
        { blink::features::kFontAccess, SetFontAccessEnabled, false },
        { blink::features::kFormRelAttribute, SetFormRelAttributeEnabled, false },
        { blink::features::kHTMLParamElementUrlSupport, SetHTMLParamElementUrlSupportEnabled, false },
        { blink::features::kHTMLPopupAttribute, SetHTMLPopupAttributeEnabled, false },
        { blink::features::kLangAttributeAwareSvgText, SetLangAttributeAwareSvgTextEnabled, false },
        { blink::features::kLayoutNG, SetLayoutNGEnabled, false },
        { blink::features::kLayoutNGDelayScrollOffsetClamping, SetLayoutNGDelayScrollOffsetClampingEnabled, false },
        { blink::features::kLayoutNGPrinting, SetLayoutNGPrintingEnabled, false },
        { blink::features::kManagedConfiguration, SetManagedConfigurationEnabled, false },
        { blink::features::kMediaSourceInWorkers, SetMediaSourceInWorkersEnabled, false },
        { blink::features::kMediaSourceInWorkersUsingHandle, SetMediaSourceInWorkersUsingHandleEnabled, false },
        { blink::features::kNavigationId, SetNavigationIdEnabled, false },
        { blink::features::kOffsetParentNewSpecBehavior, SetOffsetParentNewSpecBehaviorEnabled, false },
        { blink::features::kParakeet, SetParakeetEnabled, false },
        { blink::features::kPermissionsPolicyUnload, SetPermissionsPolicyUnloadEnabled, false },
        { blink::features::kPortals, SetPortalsEnabled, true },
        { blink::features::kPrefersColorSchemeClientHintHeader, SetPrefersColorSchemeClientHintHeaderEnabled, false },
        { blink::features::kPrefersReducedMotionClientHintHeader, SetPrefersReducedMotionClientHintHeaderEnabled, false },
        { blink::features::kPrefixedStorageInfo, SetPrefixedStorageInfoEnabled, false },
        { blink::features::kPrerender2, SetPrerender2Enabled, false },
        { blink::features::kPrivateNetworkAccessPermissionPrompt, SetPrivateNetworkAccessPermissionPromptEnabled, false },
        { blink::features::kQuickIntensiveWakeUpThrottlingAfterLoading, SetQuickIntensiveWakeUpThrottlingAfterLoadingEnabled, false },
        { blink::features::kReduceUserAgentMinorVersion, SetReduceUserAgentMinorVersionEnabled, false },
        { blink::features::kReduceUserAgentPlatformOsCpu, SetReduceUserAgentPlatformOsCpuEnabled, false },
        { blink::features::kSanitizerAPI, SetSanitizerAPIEnabled, false },
        { blink::features::kSanitizerAPIv0, SetSanitizerAPIv0Enabled, false },
        { blink::features::kScrollUpdateOptimizations, SetScrollUpdateOptimizationsEnabled, false },
        { blink::features::kSkipTouchEventFilter, SetSkipTouchEventFilterEnabled, false },
        { blink::features::kSoftNavigationHeuristics, SetSoftNavigationHeuristicsEnabled, false },
        { blink::features::kSpeculationRulesPrefetchProxy, SetSpeculationRulesPrefetchProxyEnabled, true },
        { blink::features::kStorageAccessAPIForOriginExtension, SetStorageAccessAPIForOriginExtensionEnabled, false },
        { blink::features::kStorageBuckets, SetStorageBucketsEnabled, false },
        { blink::features::kTextFragmentAnchor, SetTextFragmentIdentifiersEnabled, false },
        { blink::features::kThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframes, SetThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframesEnabled, false },
        { blink::features::kUserAgentClientHint, SetUserAgentClientHintEnabled, false },
        { blink::features::kReduceUserAgent, SetUserAgentReductionEnabled, false },
        { blink::features::kVariableCOLRV1, SetVariableCOLRV1Enabled, false },
        { blink::features::kViewportHeightClientHintHeader, SetViewportHeightClientHintHeaderEnabled, false },
        { blink::features::kWebAppEnableDarkMode, SetWebAppDarkModeEnabled, false },
        { blink::features::kWebAppEnableLaunchHandler, SetWebAppLaunchHandlerEnabled, false },
        { blink::features::kWebAppEnableTranslations, SetWebAppTranslationsEnabled, false },
        { blink::features::kWindowDefaultStatus, SetWindowDefaultStatusEnabled, false },
        { blink::features::kWindowOpenNewPopupBehavior, SetWindowOpenNewPopupBehaviorEnabled, false },
        { blink::features::kWindowPlacement, SetWindowPlacementEnabled, false },
        { blink::features::kWindowPlacementFullscreenOnScreensChange, SetWindowPlacementFullscreenOnScreensChangeEnabled, false },
        { blink::features::kZeroCopyTabCapture, SetZeroCopyTabCaptureEnabled, false },
    };
    for (const auto& map : mappings) {
        const bool feature_enabled = base::FeatureList::IsEnabled(map.feature);
        const bool is_overridden = base::FeatureList::GetInstance()->IsFeatureOverridden(map.feature.name);
        if (map.if_overridden) {
            if (is_overridden)
                map.enabler(feature_enabled);
        } else {
            if (feature_enabled || is_overridden)
                map.enabler(feature_enabled);
        }
    }
}

bool RuntimeEnabledFeaturesBase::AccessibilityAriaTouchPassthroughEnabled(const FeatureContext* context)
{
    if (is_accessibility_aria_touch_passthrough_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kAccessibilityAriaTouchPassthrough);
}

bool RuntimeEnabledFeaturesBase::AdInterestGroupAPIEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::FledgeEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::ParakeetEnabled(context))
        return true;
    if (is_ad_interest_group_api_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kAdInterestGroupAPI);
}

bool RuntimeEnabledFeaturesBase::AnonymousIframeEnabled(const FeatureContext* context)
{
    if (is_anonymous_iframe_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kAnonymousIframe);
}

bool RuntimeEnabledFeaturesBase::AttributionReportingEnabled(const FeatureContext* context)
{
    if (is_attribution_reporting_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kAttributionReporting);
}

bool RuntimeEnabledFeaturesBase::AutoDarkModeEnabled(const FeatureContext* context)
{
    if (is_auto_dark_mode_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kAutoDarkMode);
}

bool RuntimeEnabledFeaturesBase::BackForwardCacheExperimentHTTPHeaderEnabled(const FeatureContext* context)
{
    if (is_back_forward_cache_experiment_http_header_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kBackForwardCacheExperimentHTTPHeader);
}

bool RuntimeEnabledFeaturesBase::BackForwardCacheNotRestoredReasonsEnabled(const FeatureContext* context)
{
    if (is_back_forward_cache_not_restored_reasons_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kBackForwardCacheNotRestoredReasons);
}

bool RuntimeEnabledFeaturesBase::BeforeMatchEventEnabled(const FeatureContext* context)
{
    if (is_before_match_event_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kBeforeMatchEvent);
}

bool RuntimeEnabledFeaturesBase::CacheStorageCodeCacheHintEnabled(const FeatureContext* context)
{
    if (is_cache_storage_code_cache_hint_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kCacheStorageCodeCacheHint);
}

bool RuntimeEnabledFeaturesBase::ClearIdentityInCanMakePaymentEventEnabled(const FeatureContext* context)
{
    if (is_clear_identity_in_can_make_payment_event_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kClearIdentityInCanMakePaymentEvent);
}

bool RuntimeEnabledFeaturesBase::ComputePressureEnabled(const FeatureContext* context)
{
    if (is_compute_pressure_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kComputePressure);
}

bool RuntimeEnabledFeaturesBase::ConditionalFocusEnabled(const FeatureContext* context)
{
    if (is_conditional_focus_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kConditionalFocus);
}

bool RuntimeEnabledFeaturesBase::CrossOriginOpenerPolicyReportingEnabled(const FeatureContext* context)
{
    if (is_cross_origin_opener_policy_reporting_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kCrossOriginOpenerPolicyReporting);
}

bool RuntimeEnabledFeaturesBase::DeviceAttributesEnabled(const FeatureContext* context)
{
    if (is_device_attributes_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kDeviceAttributes);
}

bool RuntimeEnabledFeaturesBase::DigitalGoodsEnabled(const FeatureContext* context)
{
    if (is_digital_goods_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kDigitalGoods);
}

bool RuntimeEnabledFeaturesBase::DisableDifferentOriginSubframeDialogSuppressionEnabled(const FeatureContext* context)
{
    if (is_disable_different_origin_subframe_dialog_suppression_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kDisableDifferentOriginSubframeDialogSuppression);
}

bool RuntimeEnabledFeaturesBase::DisableHardwareNoiseSuppressionEnabled(const FeatureContext* context)
{
    if (is_disable_hardware_noise_suppression_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kDisableHardwareNoiseSuppression);
}

bool RuntimeEnabledFeaturesBase::DocumentPolicyNegotiationEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::DocumentPolicyEnabled(context))
        return false;
    if (is_document_policy_negotiation_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kDocumentPolicyNegotiation);
}

bool RuntimeEnabledFeaturesBase::EarlyHintsPreloadForNavigationOptInEnabled(const FeatureContext* context)
{
    if (is_early_hints_preload_for_navigation_opt_in_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kEarlyHintsPreloadForNavigationOptIn);
}

bool RuntimeEnabledFeaturesBase::FencedFramesEnabled(const FeatureContext* context)
{
    if (is_fenced_frames_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kFencedFrames);
}

bool RuntimeEnabledFeaturesBase::FileHandlingEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::FileSystemAccessLocalEnabled(context))
        return false;
    if (is_file_handling_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kFileHandling);
}

bool RuntimeEnabledFeaturesBase::FileHandlingIconsEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::FileHandlingEnabled(context))
        return false;
    if (is_file_handling_icons_enabled_)
        return true;
    // The feature does not have an origin trial name and its runtime flag
    // is not enabled.
    return false;
}

bool RuntimeEnabledFeaturesBase::FledgeEnabled(const FeatureContext* context)
{
    if (is_fledge_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kFledge);
}

bool RuntimeEnabledFeaturesBase::FocusgroupEnabled(const FeatureContext* context)
{
    if (is_focusgroup_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kFocusgroup);
}

bool RuntimeEnabledFeaturesBase::HrefTranslateEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::TranslateServiceEnabled(context))
        return false;
    if (is_href_translate_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kHrefTranslate);
}

bool RuntimeEnabledFeaturesBase::HTMLPopupAttributeEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::HTMLSelectMenuElementEnabled(context))
        return true;
    if (is_html_popup_attribute_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kHTMLPopupAttribute);
}

bool RuntimeEnabledFeaturesBase::MediaSourceExtensionsForWebCodecsEnabled(const FeatureContext* context)
{
    if (is_media_source_extensions_for_webcodecs_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kMediaSourceExtensionsForWebCodecs);
}

bool RuntimeEnabledFeaturesBase::MediaSourceInWorkersEnabled(const FeatureContext* context)
{
    if (is_media_source_in_workers_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kMediaSourceInWorkers);
}

bool RuntimeEnabledFeaturesBase::NotificationTriggersEnabled(const FeatureContext* context)
{
    if (is_notification_triggers_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kNotificationTriggers);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPI);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIDependentEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIEnabled(context))
        return false;
    if (is_origin_trials_sample_api_dependent_enabled_)
        return true;
    // The feature does not have an origin trial name and its runtime flag
    // is not enabled.
    return false;
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIDeprecationEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_deprecation_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIDeprecation);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIExpiryGracePeriodEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_expiry_grace_period_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriod);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIExpiryGracePeriodThirdParty);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIImpliedEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIInvalidOSEnabled(context))
        return true;
    if (is_origin_trials_sample_api_implied_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIImplied);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIInvalidOSEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_invalid_os_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIInvalidOS);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPINavigationEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_navigation_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPINavigation);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIPersistentExpiryGracePeriod);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIPersistentFeatureEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_persistent_feature_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIPersistentFeature);
}

bool RuntimeEnabledFeaturesBase::OriginTrialsSampleAPIThirdPartyEnabled(const FeatureContext* context)
{
    if (is_origin_trials_sample_api_third_party_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kOriginTrialsSampleAPIThirdParty);
}

bool RuntimeEnabledFeaturesBase::PageFreezeOptInEnabled(const FeatureContext* context)
{
    if (is_page_freeze_opt_in_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPageFreezeOptIn);
}

bool RuntimeEnabledFeaturesBase::PageFreezeOptOutEnabled(const FeatureContext* context)
{
    if (is_page_freeze_opt_out_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPageFreezeOptOut);
}

bool RuntimeEnabledFeaturesBase::ParakeetEnabled(const FeatureContext* context)
{
    if (is_parakeet_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kParakeet);
}

bool RuntimeEnabledFeaturesBase::PartitionedCookiesEnabled(const FeatureContext* context)
{
    if (is_partitioned_cookies_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPartitionedCookies);
}

bool RuntimeEnabledFeaturesBase::PendingBeaconAPIEnabled(const FeatureContext* context)
{
    if (is_pending_beacon_api_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPendingBeaconAPI);
}

bool RuntimeEnabledFeaturesBase::PerMethodCanMakePaymentQuotaEnabled(const FeatureContext* context)
{
    if (is_per_method_can_make_payment_quota_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPerMethodCanMakePaymentQuota);
}

bool RuntimeEnabledFeaturesBase::PermissionsPolicyUnloadEnabled(const FeatureContext* context)
{
    if (is_permissions_policy_unload_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPermissionsPolicyUnload);
}

bool RuntimeEnabledFeaturesBase::PNaClEnabled(const FeatureContext* context)
{
    if (is_p_na_cl_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPNaCl);
}

bool RuntimeEnabledFeaturesBase::PointerLockOptionsEnabled(const FeatureContext* context)
{
    if (is_pointer_lock_options_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPointerLockOptions);
}

bool RuntimeEnabledFeaturesBase::PortalsEnabled(const FeatureContext* context)
{
    if (is_portals_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPortals);
}

bool RuntimeEnabledFeaturesBase::Prerender2RelatedFeaturesEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::Prerender2Enabled(context))
        return true;
    if (is_prerender_2_related_features_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPrerender2RelatedFeatures);
}

bool RuntimeEnabledFeaturesBase::PrivacySandboxAdsAPIsEnabled(const FeatureContext* context)
{
    if (is_privacy_sandbox_ads_api_s_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPrivacySandboxAdsAPIs);
}

bool RuntimeEnabledFeaturesBase::PrivateNetworkAccessNonSecureContextsAllowedEnabled(const FeatureContext* context)
{
    if (is_private_network_access_non_secure_contexts_allowed_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kPrivateNetworkAccessNonSecureContextsAllowed);
}

bool RuntimeEnabledFeaturesBase::RtcAudioJitterBufferMaxPacketsEnabled(const FeatureContext* context)
{
    if (is_rtc_audio_jitter_buffer_max_packets_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kRtcAudioJitterBufferMaxPackets);
}

bool RuntimeEnabledFeaturesBase::RTCIceTransportExtensionEnabled(const FeatureContext* context)
{
    if (is_rtc_ice_transport_extension_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kRTCIceTransportExtension);
}

bool RuntimeEnabledFeaturesBase::RTCInsertableStreamsEnabled(const FeatureContext* context)
{
    if (is_rtc_insertable_streams_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kRTCInsertableStreams);
}

bool RuntimeEnabledFeaturesBase::RTCQuicTransportEnabled(const FeatureContext* context)
{
    if (is_rtc_quic_transport_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kRTCQuicTransport);
}

bool RuntimeEnabledFeaturesBase::RTCStatsRelativePacketArrivalDelayEnabled(const FeatureContext* context)
{
    if (is_rtc_stats_relative_packet_arrival_delay_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kRTCStatsRelativePacketArrivalDelay);
}

bool RuntimeEnabledFeaturesBase::SecurePaymentConfirmationOptOutEnabled(const FeatureContext* context)
{
    if (is_secure_payment_confirmation_opt_out_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kSecurePaymentConfirmationOptOut);
}

bool RuntimeEnabledFeaturesBase::SendFullUserAgentAfterReductionEnabled(const FeatureContext* context)
{
    if (is_send_full_user_agent_after_reduction_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kSendFullUserAgentAfterReduction);
}

bool RuntimeEnabledFeaturesBase::SharedStorageAPIEnabled(const FeatureContext* context)
{
    if (is_shared_storage_api_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kSharedStorageAPI);
}

bool RuntimeEnabledFeaturesBase::SignatureBasedIntegrityEnabled(const FeatureContext* context)
{
    if (is_signature_based_integrity_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kSignatureBasedIntegrity);
}

bool RuntimeEnabledFeaturesBase::SkipAdEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::MediaSessionEnabled(context))
        return false;
    if (is_skip_ad_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kSkipAd);
}

bool RuntimeEnabledFeaturesBase::SpeculationRulesEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::SpeculationRulesPrefetchProxyEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::SpeculationRulesPrefetchWithSubresourcesEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::Prerender2Enabled(context))
        return true;
    if (is_speculation_rules_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kSpeculationRules);
}

bool RuntimeEnabledFeaturesBase::SpeculationRulesPrefetchProxyEnabled(const FeatureContext* context)
{
    if (is_speculation_rules_prefetch_proxy_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kSpeculationRulesPrefetchProxy);
}

bool RuntimeEnabledFeaturesBase::StorageFoundationAPIEnabled(const FeatureContext* context)
{
    if (is_storage_foundation_api_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kStorageFoundationAPI);
}

bool RuntimeEnabledFeaturesBase::TextFragmentIdentifiersEnabled(const FeatureContext* context)
{
    if (is_text_fragment_identifiers_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kTextFragmentIdentifiers);
}

bool RuntimeEnabledFeaturesBase::TopicsAPIEnabled(const FeatureContext* context)
{
    if (is_topics_api_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kTopicsAPI);
}

bool RuntimeEnabledFeaturesBase::TouchEventFeatureDetectionEnabled(const FeatureContext* context)
{
    if (is_touch_event_feature_detection_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kTouchEventFeatureDetection);
}

bool RuntimeEnabledFeaturesBase::TrustTokensEnabled(const FeatureContext* context)
{
    if (is_trust_tokens_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kTrustTokens);
}

bool RuntimeEnabledFeaturesBase::U2FSecurityKeyAPIEnabled(const FeatureContext* context)
{
    if (is_u_2_f_security_key_api_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kU2FSecurityKeyAPI);
}

bool RuntimeEnabledFeaturesBase::UnrestrictedSharedArrayBufferEnabled(const FeatureContext* context)
{
    if (is_unrestricted_shared_array_buffer_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kUnrestrictedSharedArrayBuffer);
}

bool RuntimeEnabledFeaturesBase::UserAgentReductionEnabled(const FeatureContext* context)
{
    if (is_user_agent_reduction_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kUserAgentReduction);
}

bool RuntimeEnabledFeaturesBase::WebAppDarkModeEnabled(const FeatureContext* context)
{
    if (is_web_app_dark_mode_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebAppDarkMode);
}

bool RuntimeEnabledFeaturesBase::WebAppLaunchHandlerEnabled(const FeatureContext* context)
{
    if (is_web_app_launch_handler_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebAppLaunchHandler);
}

bool RuntimeEnabledFeaturesBase::WebAppLaunchQueueEnabled(const FeatureContext* context)
{
    if (RuntimeEnabledFeaturesBase::WebAppLaunchHandlerEnabled(context))
        return true;
    if (RuntimeEnabledFeaturesBase::FileHandlingEnabled(context))
        return true;
    if (is_web_app_launch_queue_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebAppLaunchQueue);
}

bool RuntimeEnabledFeaturesBase::WebAppUrlHandlingEnabled(const FeatureContext* context)
{
    if (is_web_app_url_handling_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebAppUrlHandling);
}

bool RuntimeEnabledFeaturesBase::WebAppWindowControlsOverlayEnabled(const FeatureContext* context)
{
    if (is_web_app_window_controls_overlay_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebAppWindowControlsOverlay);
}

bool RuntimeEnabledFeaturesBase::WebAssemblyExceptionsEnabled(const FeatureContext* context)
{
    if (is_web_assembly_exceptions_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebAssemblyExceptions);
}

bool RuntimeEnabledFeaturesBase::WebCodecsEnabled(const FeatureContext* context)
{
    if (is_webcodecs_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebCodecs);
}

bool RuntimeEnabledFeaturesBase::WebGPUEnabled(const FeatureContext* context)
{
    if (is_webgpu_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebGPU);
}

bool RuntimeEnabledFeaturesBase::WebPaymentAPICSPEnabled(const FeatureContext* context)
{
    if (is_web_payment_api_csp_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebPaymentAPICSP);
}

bool RuntimeEnabledFeaturesBase::WebTransportCustomCertificatesEnabled(const FeatureContext* context)
{
    if (is_web_transport_custom_certificates_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebTransportCustomCertificates);
}

bool RuntimeEnabledFeaturesBase::WebXRDepthEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::WebXRARModuleEnabled(context))
        return false;
    if (is_web_xr_depth_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebXRDepth);
}

bool RuntimeEnabledFeaturesBase::WebXRImageTrackingEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::WebXRARModuleEnabled(context))
        return false;
    if (is_web_xr_image_tracking_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebXRImageTracking);
}

bool RuntimeEnabledFeaturesBase::WebXRPlaneDetectionEnabled(const FeatureContext* context)
{
    if (!RuntimeEnabledFeaturesBase::WebXRARModuleEnabled(context))
        return false;
    if (is_web_xr_plane_detection_enabled_)
        return true;
    return context && context->FeatureEnabled(OriginTrialFeature::kWebXRPlaneDetection);
}

bool RuntimeEnabledFeaturesBase::is_abort_signal_throw_if_aborted_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_abort_signal_timeout_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_accelerated_2d_canvas_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_accelerated_small_canvases_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_accessibility_aria_touch_passthrough_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_aria_virtual_content_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_expose_display_none_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_expose_html_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_expose_ignored_nodes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_object_model_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_page_zoom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_accessibility_use_ax_position_for_document_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_address_space_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_ad_interest_group_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_ad_tagging_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_allow_content_initiated_data_url_navigations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_android_downloadable_fonts_matching_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_animation_worklet_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_anonymous_iframe_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_aom_aria_relationship_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_aria_touch_passthrough_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_attribution_reporting_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_audio_context_set_sink_id_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_audio_video_tracks_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_auto_dark_mode_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_auto_disable_accessibility_v_2_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_autofill_shadow_dom_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_automation_controlled_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_auto_picture_in_picture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_autoplay_ignores_web_audio_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_backface_visibility_interop_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_back_forward_cache_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_back_forward_cache_experiment_http_header_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_back_forward_cache_not_restored_reasons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_background_fetch_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_batch_fetch_requests_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_before_match_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_bidi_caret_affinity_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_extension_chrome_oshid_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_extension_chrome_os_window_management_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blink_runtime_call_stats_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_blocking_attribute_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_blocking_focus_without_user_activation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_keyboard_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_browser_verified_user_activation_mouse_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_cache_storage_code_cache_hint_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_image_chromium_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_layers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_2d_scroll_path_into_view_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_color_management_v_2_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_hdr_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_canvas_image_smoothing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capability_delegation_fullscreen_request_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_check_visibility_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_clear_identity_in_can_make_payment_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_click_to_captured_pointer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_client_hints_meta_equiv_delegate_ch_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_client_hints_meta_http_equiv_accept_ch_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_client_hint_third_party_delegation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_clipboard_custom_formats_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_clipboard_svg_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_clipboard_unsanitized_content_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_close_watcher_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_cls_scroll_anchoring_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_coep_reflection_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composite_bg_color_animation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composite_box_shadow_animation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composite_clip_path_animation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_computed_accessibility_info_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_compute_pressure_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_consolidated_movement_xy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_visibility_auto_state_change_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_cooperative_scheduling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_cors_rfc_1918_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_cross_origin_opener_policy_reporting_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_anchor_positioning_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_image_symbols_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_at_rule_counter_style_speak_as_descriptor_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_at_supports_always_non_forgiving_parsing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_calc_simplification_and_serialization_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_case_sensitive_selector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_color_4_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_color_contrast_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_color_typed_om_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_container_queries_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_container_relative_units_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_container_skip_style_recalc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_contain_size_1d_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_enumerated_custom_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_focus_visible_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_foldables_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_font_face_auto_variable_range_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_font_face_src_tech_parsing_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_font_family_math_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_font_size_adjust_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_grid_template_property_interpolation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_hex_alpha_color_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_hyphenate_limit_chars_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_ic_unit_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_independent_transform_properties_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_initial_letter_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_last_baseline_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_layout_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_lh_unit_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_logical_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_logical_overflow_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_marker_nested_pseudo_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_math_depth_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_math_shift_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_math_style_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_math_variant_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_media_queries_4_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_mix_blend_mode_plus_lighter_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_object_view_box_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_offset_path_ray_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_offset_path_ray_contain_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_offset_position_anchor_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_overflow_for_replaced_elements_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_paint_api_arguments_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_picture_in_picture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_position_sticky_static_scroll_position_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_autofill_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_dir_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_has_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_pseudo_playing_paused_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_scope_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_scrollbars_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_scroll_timeline_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_selector_fragment_anchor_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_snap_size_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_spelling_grammar_errors_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_style_queries_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_toggles_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_trigonometric_functions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_variables_2_image_values_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_variables_2_transform_values_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_video_dynamic_range_media_queries_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_css_viewport_units_4_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_css_view_timeline_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_custom_element_default_style_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_database_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_decode_jpeg_420_images_to_yuv_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_decode_lossy_web_p_images_to_yuv_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_deferred_shaping_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_deflate_raw_compression_format_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_delegated_ink_trails_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_delivery_type_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_desktop_capture_disable_local_echo_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_desktop_pw_as_sub_apps_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_attributes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_orientation_request_permission_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_device_posture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_direct_sockets_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_disable_different_origin_subframe_dialog_suppression_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_disable_hardware_noise_suppression_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_display_cutout_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_display_surface_constraint_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_cookie_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_domain_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_policy_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_policy_document_domain_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_policy_negotiation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_policy_sync_xhr_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_transition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_write_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_early_hints_preload_for_navigation_opt_in_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_edit_context_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_element_super_rare_data_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_event_path_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_experimental_content_security_policy_features_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_experimental_js_profiler_markers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_experimental_policies_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_experimental_web_snapshots_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_extended_text_metrics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_extra_webgl_video_texture_metadata_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_face_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fake_no_alloc_direct_call_for_testing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_feature_policy_reporting_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fed_cm_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fed_cm_idp_signin_status_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fed_cm_idp_signout_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fed_cm_iframe_support_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fed_cm_multiple_identity_providers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fenced_frames_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fetch_upload_streaming_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_access_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_api_experimental_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_sync_access_handle_async_interface_override_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_first_party_sets_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fixed_elements_dont_overscroll_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fledge_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_fluent_scrollbars_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_focusgroup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_focusless_spatial_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_font_palette_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_src_local_matching_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_forced_colors_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_forced_colors_preserve_parent_color_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_eager_measure_memory_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_force_reduce_motion_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_formatted_text_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_form_rel_attribute_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_fractional_scroll_offsets_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_freeze_frames_on_visibility_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_gamepad_button_axis_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_set_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_group_effect_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_highlight_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_highlight_inheritance_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_highlight_overlay_painting_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_highlight_pointer_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_href_translate_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_html_param_element_url_support_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_html_popup_attribute_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_html_select_menu_element_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_idb_batch_get_all_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_idle_detection_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_inert_attribute_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_infinite_cull_rect_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_installed_app_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_keyboard_accessible_tooltip_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_keyboard_focusable_scrollers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_lang_attribute_aware_form_control_ui_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_lang_attribute_aware_svg_text_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_block_fragmentation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_block_in_inline_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_delay_scroll_offset_clamping_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_flex_fragmentation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_foreign_object_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_frame_set_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_grid_fragmentation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_printing_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ng_subgrid_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_layout_ng_table_fragmentation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_layout_ngvtt_cue_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_lazy_frame_loading_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_lazy_frame_visible_load_time_metrics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_lazy_image_loading_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_lazy_image_visible_load_time_metrics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_lazy_initialize_media_controls_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_lcp_animated_images_web_exposed_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_legacy_windows_d_write_font_fallback_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_machine_learning_common_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_machine_learning_model_loader_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_machine_learning_neural_network_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_managed_configuration_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_mathml_core_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_measure_memory_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capabilities_dynamic_range_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capabilities_encoding_info_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capabilities_spatial_audio_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capture_background_blur_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_cast_overlay_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_expand_gesture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_element_volume_greater_than_one_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_engagement_bypass_autoplay_policies_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_latency_hint_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_query_navigation_controls_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_session_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_session_web_rtc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_source_experimental_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_source_extensions_for_webcodecs_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_source_in_workers_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_source_in_workers_using_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_source_new_abort_and_duration_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_source_stable_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_stream_track_in_window_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_stream_track_in_worker_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_stream_track_transfer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_middle_click_autoscroll_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_mobile_layout_theme_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_mojo_js_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_mojo_js_test_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_mouse_subframe_no_implicit_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigation_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_navigation_id_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_never_slow_mode_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_new_flexbox_sizing_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_no_idle_encoding_for_web_tests_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notifications_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_triggers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_off_main_thread_css_paint_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_offscreen_canvas_commit_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_offset_parent_new_spec_behavior_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_isolation_header_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_origin_policy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_dependent_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_deprecation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_implied_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_invalid_os_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_navigation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_persistent_feature_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_origin_trials_sample_api_third_party_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_overscroll_customization_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_freeze_opt_in_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_freeze_opt_out_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_paint_under_invalidation_checking_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_parakeet_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_parallel_text_shaping_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_partitioned_cookies_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_password_reveal_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_payment_app_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_payment_method_change_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_payment_request_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_payment_request_merchant_validation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_pending_beacon_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_percent_based_scrolling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_performance_manager_instrumentation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_periodic_background_sync_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_per_method_can_make_payment_quota_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permissions_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_permissions_policy_unload_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_permissions_request_revoke_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_picture_in_picture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_picture_in_picture_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_p_na_cl_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_pointer_lock_options_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_portals_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_precise_memory_info_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_prefer_non_composited_scrolling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_prefers_color_scheme_client_hint_header_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_prefers_reduced_data_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_prefers_reduced_motion_client_hint_header_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_prefixed_storage_info_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_prefixed_video_fullscreen_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_prerender_2_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_prerender_2_related_features_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_presentation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_priority_hints_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_privacy_sandbox_ads_api_s_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_private_network_access_non_secure_contexts_allowed_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_private_network_access_permission_prompt_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_push_messaging_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_push_messaging_subscription_change_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_quick_intensive_wake_up_throttling_after_loading_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_quota_change_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_minor_version_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_reduce_user_agent_platform_os_cpu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_remote_playback_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remove_mobile_viewport_double_tap_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_render_blocking_status_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_render_priority_attribute_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_resource_timing_response_status_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_restrict_gamepad_access_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_audio_jitter_buffer_max_packets_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_ice_transport_extension_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_insertable_streams_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_quic_transport_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_rtp_header_extension_control_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_stats_relative_packet_arrival_delay_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_rtc_svc_scalability_mode_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_sanitizer_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_sanitizer_api_v_0_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scoped_custom_element_registry_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_scripted_speech_recognition_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scripted_speech_synthesis_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_script_element_supports_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scrollbar_width_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_scroll_customization_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_scroll_end_events_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_scroll_timeline_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_scroll_top_left_interop_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_scroll_update_optimizations_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_secure_context_fix_for_shared_workers_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_debug_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_secure_payment_confirmation_opt_out_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_self_browser_surface_constraint_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_send_beacon_throw_for_blob_with_non_simple_type_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_send_full_user_agent_after_reduction_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_send_mouse_events_disabled_form_controls_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_sensor_extra_classes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_service_worker_client_lifecycle_state_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_array_buffer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_array_buffer_on_desktop_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_array_buffer_unrestricted_access_allowed_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_autofill_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_storage_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_signature_based_integrity_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_site_initiated_mirroring_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_skip_ad_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_skip_touch_event_filter_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_soft_navigation_heuristics_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_fetch_from_header_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_with_subresources_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_srcset_max_density_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_stable_blink_features_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_storage_access_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_storage_access_api_for_origin_extension_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_storage_buckets_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_storage_foundation_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_strict_mime_types_for_workers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_stylus_handwriting_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_supports_font_format_tech_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_surface_switching_constraint_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_svg_text_ng_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_synthesized_keyboard_events_for_accessibility_actions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_system_audio_constraint_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_system_wake_lock_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_test_feature_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_test_feature_dependent_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_test_feature_implied_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_decorating_box_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_text_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_identifiers_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_timer_throttling_for_background_tabs_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_time_zone_change_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_topics_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_touch_action_effective_at_pointer_down_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_touch_drag_and_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_touch_drag_on_short_press_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_touch_event_feature_detection_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_translate_service_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_trusted_type_before_policy_creation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_trusted_types_use_code_like_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_trust_tokens_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_trust_tokens_always_allow_issuance_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_u_2_f_security_key_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_unclosed_form_control_is_invalid_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_unexposed_task_ids_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_unrestricted_shared_array_buffer_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_url_pattern_compare_component_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_user_activation_same_origin_visibility_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_user_agent_client_hint_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_user_agent_reduction_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_v8_idle_tasks_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_variable_colrv_1_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_video_auto_fullscreen_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_fullscreen_orientation_lock_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_playback_quality_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_video_rotate_to_fullscreen_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_track_generator_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_track_generator_in_window_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_track_generator_in_worker_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_video_wake_lock_optimisation_hidden_muted_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_viewport_height_client_hint_header_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_viewport_meta_interactive_widget_property_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_viewport_segments_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_visibility_collapse_column_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_visibility_state_entry_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_wake_lock_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_warn_on_content_visibility_render_access_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_animations_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_animations_svg_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_dark_mode_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_launch_handler_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_launch_queue_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_apps_lock_screen_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_tab_strip_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_translations_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_url_handling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_app_window_controls_overlay_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_assembly_csp_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_assembly_exceptions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_auth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_auth_authenticator_attachment_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_authentication_conditional_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_authentication_device_public_key_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_authentication_large_blob_extension_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_authentication_remote_desktop_support_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_get_devices_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_scanning_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_watch_advertisements_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webcodecs_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_webcodecs_dequeue_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_webgl_color_management_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_webgl_developer_extensions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgl_draft_extensions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgl_image_chromium_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgpu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgpu_developer_features_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_webgpu_import_texture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_hid_exclusion_filters_option_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_on_service_workers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_kit_scrollbar_styling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_otp_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_otp_assertion_feature_policy_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_payment_api_csp_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_share_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_websocket_stream_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_transport_custom_certificates_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_usb_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_usb_device_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_usb_on_dedicated_workers_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_usb_on_service_workers_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_vtt_regions_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_anchors_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_ar_module_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_camera_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_depth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_hand_input_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_hit_test_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_hit_test_entity_types_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_image_tracking_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_light_estimation_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_xr_plane_detection_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_xr_viewport_scale_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_wgi_gamepad_trigger_rumble_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_window_default_status_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_window_open_new_popup_behavior_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_window_placement_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_window_placement_enhanced_screen_labels_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_window_placement_fullscreen_on_screens_change_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_zero_copy_tab_capture_enabled_ = false;

// Platform-dependent features
#if BUILDFLAG(IS_ANDROID)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_conditional_focus_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_set_auto_select_all_screens_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_hid_device_forget_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_parallel_primary_font_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_port_forget_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_proxy_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_make_read_only_enabled_ = true;
#endif

#if BUILDFLAG(IS_WIN)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_conditional_focus_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_set_auto_select_all_screens_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_hid_device_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_parallel_primary_font_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_proxy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_nfc_make_read_only_enabled_ = false;
#endif

#if BUILDFLAG(IS_CHROMEOS_ASH)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_conditional_focus_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_set_auto_select_all_screens_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_hid_device_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_parallel_primary_font_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_proxy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_nfc_make_read_only_enabled_ = false;
#endif

#if BUILDFLAG(IS_CHROMEOS_LACROS)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_conditional_focus_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_set_auto_select_all_screens_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_hid_device_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_parallel_primary_font_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_proxy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_nfc_make_read_only_enabled_ = false;
#endif

#if BUILDFLAG(IS_MAC)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_conditional_focus_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_set_auto_select_all_screens_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_hid_device_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_parallel_primary_font_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_proxy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_nfc_make_read_only_enabled_ = false;
#endif

#if BUILDFLAG(IS_LINUX)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_conditional_focus_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_set_auto_select_all_screens_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_hid_device_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_parallel_primary_font_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_proxy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_nfc_make_read_only_enabled_ = false;
#endif

// Default values for platforms not specifically handled above
#if !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_WIN) && !BUILDFLAG(IS_CHROMEOS_ASH) && !BUILDFLAG(IS_CHROMEOS_LACROS) && !BUILDFLAG(IS_MAC) && !BUILDFLAG(IS_LINUX)
bool RuntimeEnabledFeaturesBase::is_audio_output_devices_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_barcode_detector_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_capture_handle_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_composited_selection_update_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_conditional_focus_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_contacts_manager_extra_properties_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_content_index_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_digital_goods_v_2_1_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_document_picture_in_picture_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_eye_dropper_api_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_handling_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_handling_icons_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_file_system_access_local_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_file_system_access_origin_private_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_font_access_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_force_taller_select_popup_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_get_display_media_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_get_display_media_set_auto_select_all_screens_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_handwriting_recognition_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_hid_device_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_implicit_root_scroller_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_input_multiple_fields_ui_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_media_capture_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_media_controls_overlay_play_button_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_navigator_content_utils_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_net_info_downlink_max_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_notification_constructor_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_notification_content_image_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_on_device_change_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_orientation_event_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_page_popup_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_parallel_primary_font_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_region_capture_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_remote_playback_backend_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_serial_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_serial_port_forget_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_shared_worker_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_speculation_rules_prefetch_proxy_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_text_fragment_tap_opens_context_menu_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_bluetooth_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_hid_enabled_ = true;
bool RuntimeEnabledFeaturesBase::is_web_nfc_enabled_ = false;
bool RuntimeEnabledFeaturesBase::is_web_nfc_make_read_only_enabled_ = false;
#endif

} // namespace blink
