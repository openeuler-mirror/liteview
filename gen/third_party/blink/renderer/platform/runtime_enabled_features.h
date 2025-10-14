// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/runtime_enabled_features.h.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/runtime_enabled_features.json5
#ifndef THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_
#define THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_

#include <string>

#include "base/gtest_prod_util.h"
#include "third_party/blink/public/common/origin_trials/origin_trial_feature.h"
#include "third_party/blink/renderer/platform/platform_export.h"
#include "third_party/blink/renderer/platform/wtf/allocator/allocator.h"

#define ASSERT_ORIGIN_TRIAL(feature)                                                                                                                                               \
    static_assert(std::is_same<decltype(::blink::RuntimeEnabledFeatures::feature##EnabledByRuntimeFlag()), bool>(), #feature " must be part of an origin trial");

namespace blink {

// A pure virtual interface for checking the availability of origin trial
// features in a context.
class PLATFORM_EXPORT FeatureContext {
public:
    virtual bool FeatureEnabled(OriginTrialFeature) const = 0;
};

// A class that stores static enablers for all experimental features.

class PLATFORM_EXPORT RuntimeEnabledFeaturesBase {
    STATIC_ONLY(RuntimeEnabledFeaturesBase);

public:
    class PLATFORM_EXPORT Backup {
    public:
        explicit Backup();
        void Restore();

    private:
        bool is_abort_signal_throw_if_aborted_enabled_;
        bool is_abort_signal_timeout_enabled_;
        bool is_accelerated_2d_canvas_enabled_;
        bool is_accelerated_small_canvases_enabled_;
        bool is_accessibility_aria_touch_passthrough_enabled_;
        bool is_accessibility_aria_virtual_content_enabled_;
        bool is_accessibility_expose_display_none_enabled_;
        bool is_accessibility_expose_html_element_enabled_;
        bool is_accessibility_expose_ignored_nodes_enabled_;
        bool is_accessibility_object_model_enabled_;
        bool is_accessibility_page_zoom_enabled_;
        bool is_accessibility_use_ax_position_for_document_markers_enabled_;
        bool is_address_space_enabled_;
        bool is_ad_interest_group_api_enabled_;
        bool is_ad_tagging_enabled_;
        bool is_allow_content_initiated_data_url_navigations_enabled_;
        bool is_android_downloadable_fonts_matching_enabled_;
        bool is_animation_worklet_enabled_;
        bool is_anonymous_iframe_enabled_;
        bool is_aom_aria_relationship_properties_enabled_;
        bool is_aria_touch_passthrough_enabled_;
        bool is_attribution_reporting_enabled_;
        bool is_audio_context_set_sink_id_enabled_;
        bool is_audio_output_devices_enabled_;
        bool is_audio_video_tracks_enabled_;
        bool is_auto_dark_mode_enabled_;
        bool is_auto_disable_accessibility_v_2_enabled_;
        bool is_autofill_shadow_dom_enabled_;
        bool is_automation_controlled_enabled_;
        bool is_auto_picture_in_picture_enabled_;
        bool is_autoplay_ignores_web_audio_enabled_;
        bool is_backface_visibility_interop_enabled_;
        bool is_back_forward_cache_enabled_;
        bool is_back_forward_cache_experiment_http_header_enabled_;
        bool is_back_forward_cache_not_restored_reasons_enabled_;
        bool is_background_fetch_enabled_;
        bool is_barcode_detector_enabled_;
        bool is_batch_fetch_requests_enabled_;
        bool is_before_match_event_enabled_;
        bool is_bidi_caret_affinity_enabled_;
        bool is_blink_extension_chrome_os_enabled_;
        bool is_blink_extension_chrome_oshid_enabled_;
        bool is_blink_extension_chrome_os_window_management_enabled_;
        bool is_blink_runtime_call_stats_enabled_;
        bool is_blocking_attribute_enabled_;
        bool is_blocking_focus_without_user_activation_enabled_;
        bool is_browser_verified_user_activation_keyboard_enabled_;
        bool is_browser_verified_user_activation_mouse_enabled_;
        bool is_cache_storage_code_cache_hint_enabled_;
        bool is_canvas_2d_image_chromium_enabled_;
        bool is_canvas_2d_layers_enabled_;
        bool is_canvas_2d_scroll_path_into_view_enabled_;
        bool is_canvas_color_management_v_2_enabled_;
        bool is_canvas_hdr_enabled_;
        bool is_canvas_image_smoothing_enabled_;
        bool is_capability_delegation_fullscreen_request_enabled_;
        bool is_capture_handle_enabled_;
        bool is_check_visibility_enabled_;
        bool is_clear_identity_in_can_make_payment_event_enabled_;
        bool is_click_to_captured_pointer_enabled_;
        bool is_client_hints_meta_equiv_delegate_ch_enabled_;
        bool is_client_hints_meta_http_equiv_accept_ch_enabled_;
        bool is_client_hint_third_party_delegation_enabled_;
        bool is_clipboard_custom_formats_enabled_;
        bool is_clipboard_svg_enabled_;
        bool is_clipboard_unsanitized_content_enabled_;
        bool is_close_watcher_enabled_;
        bool is_cls_scroll_anchoring_enabled_;
        bool is_coep_reflection_enabled_;
        bool is_composite_bg_color_animation_enabled_;
        bool is_composite_box_shadow_animation_enabled_;
        bool is_composite_clip_path_animation_enabled_;
        bool is_composited_selection_update_enabled_;
        bool is_computed_accessibility_info_enabled_;
        bool is_compute_pressure_enabled_;
        bool is_conditional_focus_enabled_;
        bool is_consolidated_movement_xy_enabled_;
        bool is_contacts_manager_enabled_;
        bool is_contacts_manager_extra_properties_enabled_;
        bool is_content_index_enabled_;
        bool is_content_visibility_auto_state_change_event_enabled_;
        bool is_context_menu_enabled_;
        bool is_cooperative_scheduling_enabled_;
        bool is_cors_rfc_1918_enabled_;
        bool is_cross_origin_opener_policy_reporting_enabled_;
        bool is_css_anchor_positioning_enabled_;
        bool is_css_at_rule_counter_style_image_symbols_enabled_;
        bool is_css_at_rule_counter_style_speak_as_descriptor_enabled_;
        bool is_css_at_supports_always_non_forgiving_parsing_enabled_;
        bool is_css_calc_simplification_and_serialization_enabled_;
        bool is_css_case_sensitive_selector_enabled_;
        bool is_css_color_4_enabled_;
        bool is_css_color_contrast_enabled_;
        bool is_css_color_typed_om_enabled_;
        bool is_css_container_queries_enabled_;
        bool is_css_container_relative_units_enabled_;
        bool is_css_container_skip_style_recalc_enabled_;
        bool is_css_contain_size_1d_enabled_;
        bool is_css_enumerated_custom_properties_enabled_;
        bool is_css_focus_visible_enabled_;
        bool is_css_foldables_enabled_;
        bool is_css_font_face_auto_variable_range_enabled_;
        bool is_css_font_face_src_tech_parsing_enabled_;
        bool is_css_font_family_math_enabled_;
        bool is_css_font_size_adjust_enabled_;
        bool is_css_grid_template_property_interpolation_enabled_;
        bool is_css_hex_alpha_color_enabled_;
        bool is_css_hyphenate_limit_chars_enabled_;
        bool is_css_ic_unit_enabled_;
        bool is_css_independent_transform_properties_enabled_;
        bool is_css_initial_letter_enabled_;
        bool is_css_last_baseline_enabled_;
        bool is_css_layout_api_enabled_;
        bool is_css_lh_unit_enabled_;
        bool is_css_logical_enabled_;
        bool is_css_logical_overflow_enabled_;
        bool is_css_marker_nested_pseudo_element_enabled_;
        bool is_css_math_depth_enabled_;
        bool is_css_math_shift_enabled_;
        bool is_css_math_style_enabled_;
        bool is_css_math_variant_enabled_;
        bool is_css_media_queries_4_enabled_;
        bool is_css_mix_blend_mode_plus_lighter_enabled_;
        bool is_css_object_view_box_enabled_;
        bool is_css_offset_path_ray_enabled_;
        bool is_css_offset_path_ray_contain_enabled_;
        bool is_css_offset_position_anchor_enabled_;
        bool is_css_overflow_for_replaced_elements_enabled_;
        bool is_css_paint_api_arguments_enabled_;
        bool is_css_picture_in_picture_enabled_;
        bool is_css_position_sticky_static_scroll_position_enabled_;
        bool is_css_pseudo_autofill_enabled_;
        bool is_css_pseudo_dir_enabled_;
        bool is_css_pseudo_has_enabled_;
        bool is_css_pseudo_playing_paused_enabled_;
        bool is_css_scope_enabled_;
        bool is_css_scrollbars_enabled_;
        bool is_css_scroll_timeline_enabled_;
        bool is_css_selector_fragment_anchor_enabled_;
        bool is_css_snap_size_enabled_;
        bool is_css_spelling_grammar_errors_enabled_;
        bool is_css_style_queries_enabled_;
        bool is_css_toggles_enabled_;
        bool is_css_trigonometric_functions_enabled_;
        bool is_css_variables_2_image_values_enabled_;
        bool is_css_variables_2_transform_values_enabled_;
        bool is_css_video_dynamic_range_media_queries_enabled_;
        bool is_css_viewport_units_4_enabled_;
        bool is_css_view_timeline_enabled_;
        bool is_custom_element_default_style_enabled_;
        bool is_database_enabled_;
        bool is_decode_jpeg_420_images_to_yuv_enabled_;
        bool is_decode_lossy_web_p_images_to_yuv_enabled_;
        bool is_deferred_shaping_enabled_;
        bool is_deflate_raw_compression_format_enabled_;
        bool is_delegated_ink_trails_enabled_;
        bool is_delivery_type_enabled_;
        bool is_desktop_capture_disable_local_echo_control_enabled_;
        bool is_desktop_pw_as_sub_apps_enabled_;
        bool is_device_attributes_enabled_;
        bool is_device_orientation_request_permission_enabled_;
        bool is_device_posture_enabled_;
        bool is_digital_goods_enabled_;
        bool is_digital_goods_v_2_1_enabled_;
        bool is_direct_sockets_enabled_;
        bool is_disable_different_origin_subframe_dialog_suppression_enabled_;
        bool is_disable_hardware_noise_suppression_enabled_;
        bool is_display_cutout_api_enabled_;
        bool is_display_surface_constraint_enabled_;
        bool is_document_cookie_enabled_;
        bool is_document_domain_enabled_;
        bool is_document_picture_in_picture_api_enabled_;
        bool is_document_policy_enabled_;
        bool is_document_policy_document_domain_enabled_;
        bool is_document_policy_negotiation_enabled_;
        bool is_document_policy_sync_xhr_enabled_;
        bool is_document_transition_enabled_;
        bool is_document_write_enabled_;
        bool is_early_hints_preload_for_navigation_opt_in_enabled_;
        bool is_edit_context_enabled_;
        bool is_element_super_rare_data_enabled_;
        bool is_event_path_enabled_;
        bool is_experimental_content_security_policy_features_enabled_;
        bool is_experimental_js_profiler_markers_enabled_;
        bool is_experimental_policies_enabled_;
        bool is_experimental_web_snapshots_enabled_;
        bool is_extended_text_metrics_enabled_;
        bool is_extra_webgl_video_texture_metadata_enabled_;
        bool is_eye_dropper_api_enabled_;
        bool is_face_detector_enabled_;
        bool is_fake_no_alloc_direct_call_for_testing_enabled_;
        bool is_feature_policy_reporting_enabled_;
        bool is_fed_cm_enabled_;
        bool is_fed_cm_idp_signin_status_enabled_;
        bool is_fed_cm_idp_signout_enabled_;
        bool is_fed_cm_iframe_support_enabled_;
        bool is_fed_cm_multiple_identity_providers_enabled_;
        bool is_fenced_frames_enabled_;
        bool is_fetch_upload_streaming_enabled_;
        bool is_file_handling_enabled_;
        bool is_file_handling_icons_enabled_;
        bool is_file_system_enabled_;
        bool is_file_system_access_enabled_;
        bool is_file_system_access_access_handle_enabled_;
        bool is_file_system_access_api_experimental_enabled_;
        bool is_file_system_access_local_enabled_;
        bool is_file_system_access_origin_private_enabled_;
        bool is_file_system_sync_access_handle_async_interface_override_enabled_;
        bool is_first_party_sets_enabled_;
        bool is_fixed_elements_dont_overscroll_enabled_;
        bool is_fledge_enabled_;
        bool is_fluent_scrollbars_enabled_;
        bool is_focusgroup_enabled_;
        bool is_focusless_spatial_navigation_enabled_;
        bool is_font_access_enabled_;
        bool is_font_palette_enabled_;
        bool is_font_src_local_matching_enabled_;
        bool is_forced_colors_enabled_;
        bool is_forced_colors_preserve_parent_color_enabled_;
        bool is_force_eager_measure_memory_enabled_;
        bool is_force_reduce_motion_enabled_;
        bool is_force_taller_select_popup_enabled_;
        bool is_formatted_text_enabled_;
        bool is_form_rel_attribute_enabled_;
        bool is_fractional_scroll_offsets_enabled_;
        bool is_freeze_frames_on_visibility_enabled_;
        bool is_gamepad_button_axis_events_enabled_;
        bool is_get_display_media_enabled_;
        bool is_get_display_media_set_enabled_;
        bool is_get_display_media_set_auto_select_all_screens_enabled_;
        bool is_group_effect_enabled_;
        bool is_handwriting_recognition_enabled_;
        bool is_hid_device_forget_enabled_;
        bool is_highlight_api_enabled_;
        bool is_highlight_inheritance_enabled_;
        bool is_highlight_overlay_painting_enabled_;
        bool is_highlight_pointer_events_enabled_;
        bool is_href_translate_enabled_;
        bool is_html_param_element_url_support_enabled_;
        bool is_html_popup_attribute_enabled_;
        bool is_html_select_menu_element_enabled_;
        bool is_idb_batch_get_all_enabled_;
        bool is_idle_detection_enabled_;
        bool is_implicit_root_scroller_enabled_;
        bool is_inert_attribute_enabled_;
        bool is_infinite_cull_rect_enabled_;
        bool is_input_multiple_fields_ui_enabled_;
        bool is_installed_app_enabled_;
        bool is_keyboard_accessible_tooltip_enabled_;
        bool is_keyboard_focusable_scrollers_enabled_;
        bool is_lang_attribute_aware_form_control_ui_enabled_;
        bool is_lang_attribute_aware_svg_text_enabled_;
        bool is_layout_ng_enabled_;
        bool is_layout_ng_block_fragmentation_enabled_;
        bool is_layout_ng_block_in_inline_enabled_;
        bool is_layout_ng_delay_scroll_offset_clamping_enabled_;
        bool is_layout_ng_flex_fragmentation_enabled_;
        bool is_layout_ng_foreign_object_enabled_;
        bool is_layout_ng_frame_set_enabled_;
        bool is_layout_ng_grid_fragmentation_enabled_;
        bool is_layout_ng_printing_enabled_;
        bool is_layout_ng_subgrid_enabled_;
        bool is_layout_ng_table_fragmentation_enabled_;
        bool is_layout_ngvtt_cue_enabled_;
        bool is_lazy_frame_loading_enabled_;
        bool is_lazy_frame_visible_load_time_metrics_enabled_;
        bool is_lazy_image_loading_enabled_;
        bool is_lazy_image_visible_load_time_metrics_enabled_;
        bool is_lazy_initialize_media_controls_enabled_;
        bool is_lcp_animated_images_web_exposed_enabled_;
        bool is_legacy_windows_d_write_font_fallback_enabled_;
        bool is_machine_learning_common_enabled_;
        bool is_machine_learning_model_loader_enabled_;
        bool is_machine_learning_neural_network_enabled_;
        bool is_managed_configuration_enabled_;
        bool is_mathml_core_enabled_;
        bool is_measure_memory_enabled_;
        bool is_media_capabilities_dynamic_range_enabled_;
        bool is_media_capabilities_encoding_info_enabled_;
        bool is_media_capabilities_spatial_audio_enabled_;
        bool is_media_capture_enabled_;
        bool is_media_capture_background_blur_enabled_;
        bool is_media_cast_overlay_button_enabled_;
        bool is_media_controls_expand_gesture_enabled_;
        bool is_media_controls_overlay_play_button_enabled_;
        bool is_media_element_volume_greater_than_one_enabled_;
        bool is_media_engagement_bypass_autoplay_policies_enabled_;
        bool is_media_latency_hint_enabled_;
        bool is_media_query_navigation_controls_enabled_;
        bool is_media_session_enabled_;
        bool is_media_session_web_rtc_enabled_;
        bool is_media_source_experimental_enabled_;
        bool is_media_source_extensions_for_webcodecs_enabled_;
        bool is_media_source_in_workers_enabled_;
        bool is_media_source_in_workers_using_handle_enabled_;
        bool is_media_source_new_abort_and_duration_enabled_;
        bool is_media_source_stable_enabled_;
        bool is_media_stream_track_in_window_enabled_;
        bool is_media_stream_track_in_worker_enabled_;
        bool is_media_stream_track_transfer_enabled_;
        bool is_middle_click_autoscroll_enabled_;
        bool is_mobile_layout_theme_enabled_;
        bool is_mojo_js_enabled_;
        bool is_mojo_js_test_enabled_;
        bool is_mouse_subframe_no_implicit_capture_enabled_;
        bool is_navigation_api_enabled_;
        bool is_navigation_id_enabled_;
        bool is_navigator_content_utils_enabled_;
        bool is_net_info_downlink_max_enabled_;
        bool is_never_slow_mode_enabled_;
        bool is_new_flexbox_sizing_enabled_;
        bool is_no_idle_encoding_for_web_tests_enabled_;
        bool is_notification_constructor_enabled_;
        bool is_notification_content_image_enabled_;
        bool is_notifications_enabled_;
        bool is_notification_triggers_enabled_;
        bool is_off_main_thread_css_paint_enabled_;
        bool is_offscreen_canvas_commit_enabled_;
        bool is_offset_parent_new_spec_behavior_enabled_;
        bool is_on_device_change_enabled_;
        bool is_orientation_event_enabled_;
        bool is_origin_isolation_header_enabled_;
        bool is_origin_policy_enabled_;
        bool is_origin_trials_sample_api_enabled_;
        bool is_origin_trials_sample_api_dependent_enabled_;
        bool is_origin_trials_sample_api_deprecation_enabled_;
        bool is_origin_trials_sample_api_expiry_grace_period_enabled_;
        bool is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_;
        bool is_origin_trials_sample_api_implied_enabled_;
        bool is_origin_trials_sample_api_invalid_os_enabled_;
        bool is_origin_trials_sample_api_navigation_enabled_;
        bool is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_;
        bool is_origin_trials_sample_api_persistent_feature_enabled_;
        bool is_origin_trials_sample_api_third_party_enabled_;
        bool is_overscroll_customization_enabled_;
        bool is_page_freeze_opt_in_enabled_;
        bool is_page_freeze_opt_out_enabled_;
        bool is_page_popup_enabled_;
        bool is_paint_under_invalidation_checking_enabled_;
        bool is_parakeet_enabled_;
        bool is_parallel_primary_font_enabled_;
        bool is_parallel_text_shaping_enabled_;
        bool is_partitioned_cookies_enabled_;
        bool is_password_reveal_enabled_;
        bool is_payment_app_enabled_;
        bool is_payment_method_change_event_enabled_;
        bool is_payment_request_enabled_;
        bool is_payment_request_merchant_validation_event_enabled_;
        bool is_pending_beacon_api_enabled_;
        bool is_percent_based_scrolling_enabled_;
        bool is_performance_manager_instrumentation_enabled_;
        bool is_periodic_background_sync_enabled_;
        bool is_per_method_can_make_payment_quota_enabled_;
        bool is_permissions_enabled_;
        bool is_permissions_policy_unload_enabled_;
        bool is_permissions_request_revoke_enabled_;
        bool is_picture_in_picture_enabled_;
        bool is_picture_in_picture_api_enabled_;
        bool is_p_na_cl_enabled_;
        bool is_pointer_lock_options_enabled_;
        bool is_portals_enabled_;
        bool is_precise_memory_info_enabled_;
        bool is_prefer_non_composited_scrolling_enabled_;
        bool is_prefers_color_scheme_client_hint_header_enabled_;
        bool is_prefers_reduced_data_enabled_;
        bool is_prefers_reduced_motion_client_hint_header_enabled_;
        bool is_prefixed_storage_info_enabled_;
        bool is_prefixed_video_fullscreen_enabled_;
        bool is_prerender_2_enabled_;
        bool is_prerender_2_related_features_enabled_;
        bool is_presentation_enabled_;
        bool is_priority_hints_enabled_;
        bool is_privacy_sandbox_ads_api_s_enabled_;
        bool is_private_network_access_non_secure_contexts_allowed_enabled_;
        bool is_private_network_access_permission_prompt_enabled_;
        bool is_push_messaging_enabled_;
        bool is_push_messaging_subscription_change_enabled_;
        bool is_quick_intensive_wake_up_throttling_after_loading_enabled_;
        bool is_quota_change_enabled_;
        bool is_reduce_user_agent_minor_version_enabled_;
        bool is_reduce_user_agent_platform_os_cpu_enabled_;
        bool is_region_capture_enabled_;
        bool is_remote_playback_enabled_;
        bool is_remote_playback_backend_enabled_;
        bool is_remove_mobile_viewport_double_tap_enabled_;
        bool is_render_blocking_status_enabled_;
        bool is_render_priority_attribute_enabled_;
        bool is_resource_timing_response_status_enabled_;
        bool is_restrict_gamepad_access_enabled_;
        bool is_rtc_audio_jitter_buffer_max_packets_enabled_;
        bool is_rtc_ice_transport_extension_enabled_;
        bool is_rtc_insertable_streams_enabled_;
        bool is_rtc_quic_transport_enabled_;
        bool is_rtc_rtp_header_extension_control_enabled_;
        bool is_rtc_stats_relative_packet_arrival_delay_enabled_;
        bool is_rtc_svc_scalability_mode_enabled_;
        bool is_sanitizer_api_enabled_;
        bool is_sanitizer_api_v_0_enabled_;
        bool is_scoped_custom_element_registry_enabled_;
        bool is_scripted_speech_recognition_enabled_;
        bool is_scripted_speech_synthesis_enabled_;
        bool is_script_element_supports_enabled_;
        bool is_scrollbar_width_enabled_;
        bool is_scroll_customization_enabled_;
        bool is_scroll_end_events_enabled_;
        bool is_scroll_timeline_enabled_;
        bool is_scroll_top_left_interop_enabled_;
        bool is_scroll_update_optimizations_enabled_;
        bool is_secure_context_fix_for_shared_workers_enabled_;
        bool is_secure_payment_confirmation_enabled_;
        bool is_secure_payment_confirmation_debug_enabled_;
        bool is_secure_payment_confirmation_opt_out_enabled_;
        bool is_self_browser_surface_constraint_enabled_;
        bool is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
        bool is_send_full_user_agent_after_reduction_enabled_;
        bool is_send_mouse_events_disabled_form_controls_enabled_;
        bool is_sensor_extra_classes_enabled_;
        bool is_serial_enabled_;
        bool is_serial_port_forget_enabled_;
        bool is_service_worker_client_lifecycle_state_enabled_;
        bool is_shared_array_buffer_enabled_;
        bool is_shared_array_buffer_on_desktop_enabled_;
        bool is_shared_array_buffer_unrestricted_access_allowed_enabled_;
        bool is_shared_autofill_enabled_;
        bool is_shared_storage_api_enabled_;
        bool is_shared_worker_enabled_;
        bool is_signature_based_integrity_enabled_;
        bool is_site_initiated_mirroring_enabled_;
        bool is_skip_ad_enabled_;
        bool is_skip_touch_event_filter_enabled_;
        bool is_soft_navigation_heuristics_enabled_;
        bool is_speculation_rules_enabled_;
        bool is_speculation_rules_fetch_from_header_enabled_;
        bool is_speculation_rules_prefetch_proxy_enabled_;
        bool is_speculation_rules_prefetch_with_subresources_enabled_;
        bool is_srcset_max_density_enabled_;
        bool is_stable_blink_features_enabled_;
        bool is_storage_access_api_enabled_;
        bool is_storage_access_api_for_origin_extension_enabled_;
        bool is_storage_buckets_enabled_;
        bool is_storage_foundation_api_enabled_;
        bool is_strict_mime_types_for_workers_enabled_;
        bool is_stylus_handwriting_enabled_;
        bool is_supports_font_format_tech_enabled_;
        bool is_surface_switching_constraint_enabled_;
        bool is_svg_text_ng_enabled_;
        bool is_synthesized_keyboard_events_for_accessibility_actions_enabled_;
        bool is_system_audio_constraint_enabled_;
        bool is_system_wake_lock_enabled_;
        bool is_test_feature_enabled_;
        bool is_test_feature_dependent_enabled_;
        bool is_test_feature_implied_enabled_;
        bool is_text_decorating_box_enabled_;
        bool is_text_detector_enabled_;
        bool is_text_fragment_api_enabled_;
        bool is_text_fragment_identifiers_enabled_;
        bool is_text_fragment_tap_opens_context_menu_enabled_;
        bool is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_;
        bool is_timer_throttling_for_background_tabs_enabled_;
        bool is_time_zone_change_event_enabled_;
        bool is_topics_api_enabled_;
        bool is_touch_action_effective_at_pointer_down_enabled_;
        bool is_touch_drag_and_context_menu_enabled_;
        bool is_touch_drag_on_short_press_enabled_;
        bool is_touch_event_feature_detection_enabled_;
        bool is_translate_service_enabled_;
        bool is_trusted_type_before_policy_creation_event_enabled_;
        bool is_trusted_types_use_code_like_enabled_;
        bool is_trust_tokens_enabled_;
        bool is_trust_tokens_always_allow_issuance_enabled_;
        bool is_u_2_f_security_key_api_enabled_;
        bool is_unclosed_form_control_is_invalid_enabled_;
        bool is_unexposed_task_ids_enabled_;
        bool is_unrestricted_shared_array_buffer_enabled_;
        bool is_url_pattern_compare_component_enabled_;
        bool is_user_activation_same_origin_visibility_enabled_;
        bool is_user_agent_client_hint_enabled_;
        bool is_user_agent_reduction_enabled_;
        bool is_v8_idle_tasks_enabled_;
        bool is_variable_colrv_1_enabled_;
        bool is_video_auto_fullscreen_enabled_;
        bool is_video_fullscreen_orientation_lock_enabled_;
        bool is_video_playback_quality_enabled_;
        bool is_video_rotate_to_fullscreen_enabled_;
        bool is_video_track_generator_enabled_;
        bool is_video_track_generator_in_window_enabled_;
        bool is_video_track_generator_in_worker_enabled_;
        bool is_video_wake_lock_optimisation_hidden_muted_enabled_;
        bool is_viewport_height_client_hint_header_enabled_;
        bool is_viewport_meta_interactive_widget_property_enabled_;
        bool is_viewport_segments_enabled_;
        bool is_visibility_collapse_column_enabled_;
        bool is_visibility_state_entry_enabled_;
        bool is_wake_lock_enabled_;
        bool is_warn_on_content_visibility_render_access_enabled_;
        bool is_web_animations_api_enabled_;
        bool is_web_animations_svg_enabled_;
        bool is_web_app_dark_mode_enabled_;
        bool is_web_app_launch_handler_enabled_;
        bool is_web_app_launch_queue_enabled_;
        bool is_web_apps_lock_screen_enabled_;
        bool is_web_app_tab_strip_enabled_;
        bool is_web_app_translations_enabled_;
        bool is_web_app_url_handling_enabled_;
        bool is_web_app_window_controls_overlay_enabled_;
        bool is_web_assembly_csp_enabled_;
        bool is_web_assembly_exceptions_enabled_;
        bool is_web_auth_enabled_;
        bool is_web_auth_authenticator_attachment_enabled_;
        bool is_web_authentication_conditional_ui_enabled_;
        bool is_web_authentication_device_public_key_enabled_;
        bool is_web_authentication_large_blob_extension_enabled_;
        bool is_web_authentication_remote_desktop_support_enabled_;
        bool is_web_bluetooth_enabled_;
        bool is_web_bluetooth_get_devices_enabled_;
        bool is_web_bluetooth_scanning_enabled_;
        bool is_web_bluetooth_watch_advertisements_enabled_;
        bool is_webcodecs_enabled_;
        bool is_webcodecs_dequeue_event_enabled_;
        bool is_webgl_color_management_enabled_;
        bool is_webgl_developer_extensions_enabled_;
        bool is_webgl_draft_extensions_enabled_;
        bool is_webgl_image_chromium_enabled_;
        bool is_webgpu_enabled_;
        bool is_webgpu_developer_features_enabled_;
        bool is_webgpu_import_texture_enabled_;
        bool is_web_hid_enabled_;
        bool is_web_hid_exclusion_filters_option_enabled_;
        bool is_web_hid_on_service_workers_enabled_;
        bool is_web_kit_scrollbar_styling_enabled_;
        bool is_web_nfc_enabled_;
        bool is_web_nfc_make_read_only_enabled_;
        bool is_web_otp_enabled_;
        bool is_web_otp_assertion_feature_policy_enabled_;
        bool is_web_payment_api_csp_enabled_;
        bool is_web_share_enabled_;
        bool is_websocket_stream_enabled_;
        bool is_web_transport_custom_certificates_enabled_;
        bool is_web_usb_enabled_;
        bool is_web_usb_device_forget_enabled_;
        bool is_web_usb_on_dedicated_workers_enabled_;
        bool is_web_usb_on_service_workers_enabled_;
        bool is_web_vtt_regions_enabled_;
        bool is_web_xr_enabled_;
        bool is_web_xr_anchors_enabled_;
        bool is_web_xr_ar_module_enabled_;
        bool is_web_xr_camera_access_enabled_;
        bool is_web_xr_depth_enabled_;
        bool is_web_xr_hand_input_enabled_;
        bool is_web_xr_hit_test_enabled_;
        bool is_web_xr_hit_test_entity_types_enabled_;
        bool is_web_xr_image_tracking_enabled_;
        bool is_web_xr_light_estimation_enabled_;
        bool is_web_xr_plane_detection_enabled_;
        bool is_web_xr_viewport_scale_enabled_;
        bool is_wgi_gamepad_trigger_rumble_enabled_;
        bool is_window_default_status_enabled_;
        bool is_window_open_new_popup_behavior_enabled_;
        bool is_window_placement_enabled_;
        bool is_window_placement_enhanced_screen_labels_enabled_;
        bool is_window_placement_fullscreen_on_screens_change_enabled_;
        bool is_zero_copy_tab_capture_enabled_;
    };

    static bool AbortSignalThrowIfAbortedEnabled() { return is_abort_signal_throw_if_aborted_enabled_; }
    static bool AbortSignalThrowIfAbortedEnabled(const FeatureContext*) { return AbortSignalThrowIfAbortedEnabled(); }

    static bool AbortSignalTimeoutEnabled() { return is_abort_signal_timeout_enabled_; }
    static bool AbortSignalTimeoutEnabled(const FeatureContext*) { return AbortSignalTimeoutEnabled(); }

    static bool Accelerated2dCanvasEnabled() { return is_accelerated_2d_canvas_enabled_; }
    static bool Accelerated2dCanvasEnabled(const FeatureContext*) { return Accelerated2dCanvasEnabled(); }

    static bool AcceleratedSmallCanvasesEnabled() { return is_accelerated_small_canvases_enabled_; }
    static bool AcceleratedSmallCanvasesEnabled(const FeatureContext*) { return AcceleratedSmallCanvasesEnabled(); }

    static bool AccessibilityAriaVirtualContentEnabled() { return is_accessibility_aria_virtual_content_enabled_; }
    static bool AccessibilityAriaVirtualContentEnabled(const FeatureContext*) { return AccessibilityAriaVirtualContentEnabled(); }

    static bool AccessibilityExposeDisplayNoneEnabled() { return is_accessibility_expose_display_none_enabled_; }
    static bool AccessibilityExposeDisplayNoneEnabled(const FeatureContext*) { return AccessibilityExposeDisplayNoneEnabled(); }

    static bool AccessibilityExposeHTMLElementEnabled() { return is_accessibility_expose_html_element_enabled_; }
    static bool AccessibilityExposeHTMLElementEnabled(const FeatureContext*) { return AccessibilityExposeHTMLElementEnabled(); }

    static bool AccessibilityExposeIgnoredNodesEnabled() { return is_accessibility_expose_ignored_nodes_enabled_; }
    static bool AccessibilityExposeIgnoredNodesEnabled(const FeatureContext*) { return AccessibilityExposeIgnoredNodesEnabled(); }

    static bool AccessibilityObjectModelEnabled() { return is_accessibility_object_model_enabled_; }
    static bool AccessibilityObjectModelEnabled(const FeatureContext*) { return AccessibilityObjectModelEnabled(); }

    static bool AccessibilityPageZoomEnabled() { return is_accessibility_page_zoom_enabled_; }
    static bool AccessibilityPageZoomEnabled(const FeatureContext*) { return AccessibilityPageZoomEnabled(); }

    static bool AccessibilityUseAXPositionForDocumentMarkersEnabled() { return is_accessibility_use_ax_position_for_document_markers_enabled_; }
    static bool AccessibilityUseAXPositionForDocumentMarkersEnabled(const FeatureContext*) { return AccessibilityUseAXPositionForDocumentMarkersEnabled(); }

    static bool AddressSpaceEnabled()
    {
        if (CorsRFC1918Enabled())
            return true;
        return is_address_space_enabled_;
    }
    static bool AddressSpaceEnabled(const FeatureContext*) { return AddressSpaceEnabled(); }

    static bool AdTaggingEnabled() { return is_ad_tagging_enabled_; }
    static bool AdTaggingEnabled(const FeatureContext*) { return AdTaggingEnabled(); }

    static bool AllowContentInitiatedDataUrlNavigationsEnabled() { return is_allow_content_initiated_data_url_navigations_enabled_; }
    static bool AllowContentInitiatedDataUrlNavigationsEnabled(const FeatureContext*) { return AllowContentInitiatedDataUrlNavigationsEnabled(); }

    static bool AndroidDownloadableFontsMatchingEnabled() { return is_android_downloadable_fonts_matching_enabled_; }
    static bool AndroidDownloadableFontsMatchingEnabled(const FeatureContext*) { return AndroidDownloadableFontsMatchingEnabled(); }

    static bool AnimationWorkletEnabled() { return is_animation_worklet_enabled_; }
    static bool AnimationWorkletEnabled(const FeatureContext*) { return AnimationWorkletEnabled(); }

    static bool AOMAriaRelationshipPropertiesEnabled() { return is_aom_aria_relationship_properties_enabled_; }
    static bool AOMAriaRelationshipPropertiesEnabled(const FeatureContext*) { return AOMAriaRelationshipPropertiesEnabled(); }

    static bool AriaTouchPassthroughEnabled() { return is_aria_touch_passthrough_enabled_; }
    static bool AriaTouchPassthroughEnabled(const FeatureContext*) { return AriaTouchPassthroughEnabled(); }

    static bool AudioContextSetSinkIdEnabled() { return is_audio_context_set_sink_id_enabled_; }
    static bool AudioContextSetSinkIdEnabled(const FeatureContext*) { return AudioContextSetSinkIdEnabled(); }

    static bool AudioOutputDevicesEnabled() { return is_audio_output_devices_enabled_; }
    static bool AudioOutputDevicesEnabled(const FeatureContext*) { return AudioOutputDevicesEnabled(); }

    static bool AudioVideoTracksEnabled() { return is_audio_video_tracks_enabled_; }
    static bool AudioVideoTracksEnabled(const FeatureContext*) { return AudioVideoTracksEnabled(); }

    static bool AutoDisableAccessibilityV2Enabled() { return is_auto_disable_accessibility_v_2_enabled_; }
    static bool AutoDisableAccessibilityV2Enabled(const FeatureContext*) { return AutoDisableAccessibilityV2Enabled(); }

    static bool AutofillShadowDOMEnabled() { return is_autofill_shadow_dom_enabled_; }
    static bool AutofillShadowDOMEnabled(const FeatureContext*) { return AutofillShadowDOMEnabled(); }

    static bool AutomationControlledEnabled() { return is_automation_controlled_enabled_; }
    static bool AutomationControlledEnabled(const FeatureContext*) { return AutomationControlledEnabled(); }

    static bool AutoPictureInPictureEnabled()
    {
        if (!PictureInPictureAPIEnabled())
            return false;
        return is_auto_picture_in_picture_enabled_;
    }
    static bool AutoPictureInPictureEnabled(const FeatureContext*) { return AutoPictureInPictureEnabled(); }

    static bool AutoplayIgnoresWebAudioEnabled() { return is_autoplay_ignores_web_audio_enabled_; }
    static bool AutoplayIgnoresWebAudioEnabled(const FeatureContext*) { return AutoplayIgnoresWebAudioEnabled(); }

    static bool BackfaceVisibilityInteropEnabled() { return is_backface_visibility_interop_enabled_; }
    static bool BackfaceVisibilityInteropEnabled(const FeatureContext*) { return BackfaceVisibilityInteropEnabled(); }

    static bool BackForwardCacheEnabled() { return is_back_forward_cache_enabled_; }
    static bool BackForwardCacheEnabled(const FeatureContext*) { return BackForwardCacheEnabled(); }

    static bool BackgroundFetchEnabled() { return is_background_fetch_enabled_; }
    static bool BackgroundFetchEnabled(const FeatureContext*) { return BackgroundFetchEnabled(); }

    static bool BarcodeDetectorEnabled() { return is_barcode_detector_enabled_; }
    static bool BarcodeDetectorEnabled(const FeatureContext*) { return BarcodeDetectorEnabled(); }

    static bool BatchFetchRequestsEnabled() { return is_batch_fetch_requests_enabled_; }
    static bool BatchFetchRequestsEnabled(const FeatureContext*) { return BatchFetchRequestsEnabled(); }

    static bool BidiCaretAffinityEnabled() { return is_bidi_caret_affinity_enabled_; }
    static bool BidiCaretAffinityEnabled(const FeatureContext*) { return BidiCaretAffinityEnabled(); }

    static bool BlinkExtensionChromeOSEnabled() { return is_blink_extension_chrome_os_enabled_; }
    static bool BlinkExtensionChromeOSEnabled(const FeatureContext*) { return BlinkExtensionChromeOSEnabled(); }

    static bool BlinkExtensionChromeOSHIDEnabled()
    {
        if (!BlinkExtensionChromeOSEnabled())
            return false;
        return is_blink_extension_chrome_oshid_enabled_;
    }
    static bool BlinkExtensionChromeOSHIDEnabled(const FeatureContext*) { return BlinkExtensionChromeOSHIDEnabled(); }

    static bool BlinkExtensionChromeOSWindowManagementEnabled()
    {
        if (!BlinkExtensionChromeOSEnabled())
            return false;
        return is_blink_extension_chrome_os_window_management_enabled_;
    }
    static bool BlinkExtensionChromeOSWindowManagementEnabled(const FeatureContext*) { return BlinkExtensionChromeOSWindowManagementEnabled(); }

    static bool BlinkRuntimeCallStatsEnabled() { return is_blink_runtime_call_stats_enabled_; }
    static bool BlinkRuntimeCallStatsEnabled(const FeatureContext*) { return BlinkRuntimeCallStatsEnabled(); }

    static bool BlockingAttributeEnabled() { return is_blocking_attribute_enabled_; }
    static bool BlockingAttributeEnabled(const FeatureContext*) { return BlockingAttributeEnabled(); }

    static bool BlockingFocusWithoutUserActivationEnabled() { return is_blocking_focus_without_user_activation_enabled_; }
    static bool BlockingFocusWithoutUserActivationEnabled(const FeatureContext*) { return BlockingFocusWithoutUserActivationEnabled(); }

    static bool BrowserVerifiedUserActivationKeyboardEnabled() { return is_browser_verified_user_activation_keyboard_enabled_; }
    static bool BrowserVerifiedUserActivationKeyboardEnabled(const FeatureContext*) { return BrowserVerifiedUserActivationKeyboardEnabled(); }

    static bool BrowserVerifiedUserActivationMouseEnabled() { return is_browser_verified_user_activation_mouse_enabled_; }
    static bool BrowserVerifiedUserActivationMouseEnabled(const FeatureContext*) { return BrowserVerifiedUserActivationMouseEnabled(); }

    static bool Canvas2dImageChromiumEnabled() { return is_canvas_2d_image_chromium_enabled_; }
    static bool Canvas2dImageChromiumEnabled(const FeatureContext*) { return Canvas2dImageChromiumEnabled(); }

    static bool Canvas2dLayersEnabled() { return is_canvas_2d_layers_enabled_; }
    static bool Canvas2dLayersEnabled(const FeatureContext*) { return Canvas2dLayersEnabled(); }

    static bool Canvas2dScrollPathIntoViewEnabled() { return is_canvas_2d_scroll_path_into_view_enabled_; }
    static bool Canvas2dScrollPathIntoViewEnabled(const FeatureContext*) { return Canvas2dScrollPathIntoViewEnabled(); }

    static bool CanvasColorManagementV2Enabled() { return is_canvas_color_management_v_2_enabled_; }
    static bool CanvasColorManagementV2Enabled(const FeatureContext*) { return CanvasColorManagementV2Enabled(); }

    static bool CanvasHDREnabled() { return is_canvas_hdr_enabled_; }
    static bool CanvasHDREnabled(const FeatureContext*) { return CanvasHDREnabled(); }

    static bool CanvasImageSmoothingEnabled() { return is_canvas_image_smoothing_enabled_; }
    static bool CanvasImageSmoothingEnabled(const FeatureContext*) { return CanvasImageSmoothingEnabled(); }

    static bool CapabilityDelegationFullscreenRequestEnabled() { return is_capability_delegation_fullscreen_request_enabled_; }
    static bool CapabilityDelegationFullscreenRequestEnabled(const FeatureContext*) { return CapabilityDelegationFullscreenRequestEnabled(); }

    static bool CaptureHandleEnabled()
    {
        if (!GetDisplayMediaEnabled())
            return false;
        return is_capture_handle_enabled_;
    }
    static bool CaptureHandleEnabled(const FeatureContext*) { return CaptureHandleEnabled(); }

    static bool checkVisibilityEnabled() { return is_check_visibility_enabled_; }
    static bool checkVisibilityEnabled(const FeatureContext*) { return checkVisibilityEnabled(); }

    static bool ClickToCapturedPointerEnabled() { return is_click_to_captured_pointer_enabled_; }
    static bool ClickToCapturedPointerEnabled(const FeatureContext*) { return ClickToCapturedPointerEnabled(); }

    static bool ClientHintsMetaEquivDelegateCHEnabled() { return is_client_hints_meta_equiv_delegate_ch_enabled_; }
    static bool ClientHintsMetaEquivDelegateCHEnabled(const FeatureContext*) { return ClientHintsMetaEquivDelegateCHEnabled(); }

    static bool ClientHintsMetaHTTPEquivAcceptCHEnabled() { return is_client_hints_meta_http_equiv_accept_ch_enabled_; }
    static bool ClientHintsMetaHTTPEquivAcceptCHEnabled(const FeatureContext*) { return ClientHintsMetaHTTPEquivAcceptCHEnabled(); }

    static bool ClientHintThirdPartyDelegationEnabled() { return is_client_hint_third_party_delegation_enabled_; }
    static bool ClientHintThirdPartyDelegationEnabled(const FeatureContext*) { return ClientHintThirdPartyDelegationEnabled(); }

    static bool ClipboardCustomFormatsEnabled() { return is_clipboard_custom_formats_enabled_; }
    static bool ClipboardCustomFormatsEnabled(const FeatureContext*) { return ClipboardCustomFormatsEnabled(); }

    static bool ClipboardSvgEnabled() { return is_clipboard_svg_enabled_; }
    static bool ClipboardSvgEnabled(const FeatureContext*) { return ClipboardSvgEnabled(); }

    static bool ClipboardUnsanitizedContentEnabled() { return is_clipboard_unsanitized_content_enabled_; }
    static bool ClipboardUnsanitizedContentEnabled(const FeatureContext*) { return ClipboardUnsanitizedContentEnabled(); }

    static bool CloseWatcherEnabled() { return is_close_watcher_enabled_; }
    static bool CloseWatcherEnabled(const FeatureContext*) { return CloseWatcherEnabled(); }

    static bool CLSScrollAnchoringEnabled() { return is_cls_scroll_anchoring_enabled_; }
    static bool CLSScrollAnchoringEnabled(const FeatureContext*) { return CLSScrollAnchoringEnabled(); }

    static bool CoepReflectionEnabled() { return is_coep_reflection_enabled_; }
    static bool CoepReflectionEnabled(const FeatureContext*) { return CoepReflectionEnabled(); }

    static bool CompositeBGColorAnimationEnabled() { return is_composite_bg_color_animation_enabled_; }
    static bool CompositeBGColorAnimationEnabled(const FeatureContext*) { return CompositeBGColorAnimationEnabled(); }

    static bool CompositeBoxShadowAnimationEnabled() { return is_composite_box_shadow_animation_enabled_; }
    static bool CompositeBoxShadowAnimationEnabled(const FeatureContext*) { return CompositeBoxShadowAnimationEnabled(); }

    static bool CompositeClipPathAnimationEnabled() { return is_composite_clip_path_animation_enabled_; }
    static bool CompositeClipPathAnimationEnabled(const FeatureContext*) { return CompositeClipPathAnimationEnabled(); }

    static bool CompositedSelectionUpdateEnabled() { return is_composited_selection_update_enabled_; }
    static bool CompositedSelectionUpdateEnabled(const FeatureContext*) { return CompositedSelectionUpdateEnabled(); }

    static bool ComputedAccessibilityInfoEnabled() { return is_computed_accessibility_info_enabled_; }
    static bool ComputedAccessibilityInfoEnabled(const FeatureContext*) { return ComputedAccessibilityInfoEnabled(); }

    static bool ConsolidatedMovementXYEnabled() { return is_consolidated_movement_xy_enabled_; }
    static bool ConsolidatedMovementXYEnabled(const FeatureContext*) { return ConsolidatedMovementXYEnabled(); }

    static bool ContactsManagerEnabled() { return is_contacts_manager_enabled_; }
    static bool ContactsManagerEnabled(const FeatureContext*) { return ContactsManagerEnabled(); }

    static bool ContactsManagerExtraPropertiesEnabled() { return is_contacts_manager_extra_properties_enabled_; }
    static bool ContactsManagerExtraPropertiesEnabled(const FeatureContext*) { return ContactsManagerExtraPropertiesEnabled(); }

    static bool ContentIndexEnabled() { return is_content_index_enabled_; }
    static bool ContentIndexEnabled(const FeatureContext*) { return ContentIndexEnabled(); }

    static bool ContentVisibilityAutoStateChangeEventEnabled() { return is_content_visibility_auto_state_change_event_enabled_; }
    static bool ContentVisibilityAutoStateChangeEventEnabled(const FeatureContext*) { return ContentVisibilityAutoStateChangeEventEnabled(); }

    static bool ContextMenuEnabled() { return is_context_menu_enabled_; }
    static bool ContextMenuEnabled(const FeatureContext*) { return ContextMenuEnabled(); }

    static bool CooperativeSchedulingEnabled() { return is_cooperative_scheduling_enabled_; }
    static bool CooperativeSchedulingEnabled(const FeatureContext*) { return CooperativeSchedulingEnabled(); }

    static bool CorsRFC1918Enabled() { return is_cors_rfc_1918_enabled_; }
    static bool CorsRFC1918Enabled(const FeatureContext*) { return CorsRFC1918Enabled(); }

    static bool CSSAnchorPositioningEnabled() { return is_css_anchor_positioning_enabled_; }
    static bool CSSAnchorPositioningEnabled(const FeatureContext*) { return CSSAnchorPositioningEnabled(); }

    static bool CSSAtRuleCounterStyleImageSymbolsEnabled() { return is_css_at_rule_counter_style_image_symbols_enabled_; }
    static bool CSSAtRuleCounterStyleImageSymbolsEnabled(const FeatureContext*) { return CSSAtRuleCounterStyleImageSymbolsEnabled(); }

    static bool CSSAtRuleCounterStyleSpeakAsDescriptorEnabled() { return is_css_at_rule_counter_style_speak_as_descriptor_enabled_; }
    static bool CSSAtRuleCounterStyleSpeakAsDescriptorEnabled(const FeatureContext*) { return CSSAtRuleCounterStyleSpeakAsDescriptorEnabled(); }

    static bool CSSAtSupportsAlwaysNonForgivingParsingEnabled() { return is_css_at_supports_always_non_forgiving_parsing_enabled_; }
    static bool CSSAtSupportsAlwaysNonForgivingParsingEnabled(const FeatureContext*) { return CSSAtSupportsAlwaysNonForgivingParsingEnabled(); }

    static bool CSSCalcSimplificationAndSerializationEnabled() { return is_css_calc_simplification_and_serialization_enabled_; }
    static bool CSSCalcSimplificationAndSerializationEnabled(const FeatureContext*) { return CSSCalcSimplificationAndSerializationEnabled(); }

    static bool CSSCaseSensitiveSelectorEnabled() { return is_css_case_sensitive_selector_enabled_; }
    static bool CSSCaseSensitiveSelectorEnabled(const FeatureContext*) { return CSSCaseSensitiveSelectorEnabled(); }

    static bool CSSColor4Enabled() { return is_css_color_4_enabled_; }
    static bool CSSColor4Enabled(const FeatureContext*) { return CSSColor4Enabled(); }

    static bool CSSColorContrastEnabled() { return is_css_color_contrast_enabled_; }
    static bool CSSColorContrastEnabled(const FeatureContext*) { return CSSColorContrastEnabled(); }

    static bool CSSColorTypedOMEnabled() { return is_css_color_typed_om_enabled_; }
    static bool CSSColorTypedOMEnabled(const FeatureContext*) { return CSSColorTypedOMEnabled(); }

    static bool CSSContainerQueriesEnabled() { return is_css_container_queries_enabled_; }
    static bool CSSContainerQueriesEnabled(const FeatureContext*) { return CSSContainerQueriesEnabled(); }

    static bool CSSContainerRelativeUnitsEnabled()
    {
        if (CSSContainerQueriesEnabled())
            return true;
        return is_css_container_relative_units_enabled_;
    }
    static bool CSSContainerRelativeUnitsEnabled(const FeatureContext*) { return CSSContainerRelativeUnitsEnabled(); }

    static bool CSSContainerSkipStyleRecalcEnabled()
    {
        if (CSSContainerQueriesEnabled())
            return true;
        return is_css_container_skip_style_recalc_enabled_;
    }
    static bool CSSContainerSkipStyleRecalcEnabled(const FeatureContext*) { return CSSContainerSkipStyleRecalcEnabled(); }

    static bool CSSContainSize1DEnabled()
    {
        if (CSSContainerQueriesEnabled())
            return true;
        return is_css_contain_size_1d_enabled_;
    }
    static bool CSSContainSize1DEnabled(const FeatureContext*) { return CSSContainSize1DEnabled(); }

    static bool CSSEnumeratedCustomPropertiesEnabled() { return is_css_enumerated_custom_properties_enabled_; }
    static bool CSSEnumeratedCustomPropertiesEnabled(const FeatureContext*) { return CSSEnumeratedCustomPropertiesEnabled(); }

    static bool CSSFocusVisibleEnabled() { return is_css_focus_visible_enabled_; }
    static bool CSSFocusVisibleEnabled(const FeatureContext*) { return CSSFocusVisibleEnabled(); }

    static bool CSSFoldablesEnabled() { return is_css_foldables_enabled_; }
    static bool CSSFoldablesEnabled(const FeatureContext*) { return CSSFoldablesEnabled(); }

    static bool CSSFontFaceAutoVariableRangeEnabled() { return is_css_font_face_auto_variable_range_enabled_; }
    static bool CSSFontFaceAutoVariableRangeEnabled(const FeatureContext*) { return CSSFontFaceAutoVariableRangeEnabled(); }

    static bool CSSFontFaceSrcTechParsingEnabled() { return is_css_font_face_src_tech_parsing_enabled_; }
    static bool CSSFontFaceSrcTechParsingEnabled(const FeatureContext*) { return CSSFontFaceSrcTechParsingEnabled(); }

    static bool CSSFontFamilyMathEnabled()
    {
        if (MathMLCoreEnabled())
            return true;
        return is_css_font_family_math_enabled_;
    }
    static bool CSSFontFamilyMathEnabled(const FeatureContext*) { return CSSFontFamilyMathEnabled(); }

    static bool CSSFontSizeAdjustEnabled() { return is_css_font_size_adjust_enabled_; }
    static bool CSSFontSizeAdjustEnabled(const FeatureContext*) { return CSSFontSizeAdjustEnabled(); }

    static bool CSSGridTemplatePropertyInterpolationEnabled()
    {
        if (!LayoutNGGridFragmentationEnabled())
            return false;
        return is_css_grid_template_property_interpolation_enabled_;
    }
    static bool CSSGridTemplatePropertyInterpolationEnabled(const FeatureContext*) { return CSSGridTemplatePropertyInterpolationEnabled(); }

    static bool CSSHexAlphaColorEnabled() { return is_css_hex_alpha_color_enabled_; }
    static bool CSSHexAlphaColorEnabled(const FeatureContext*) { return CSSHexAlphaColorEnabled(); }

    static bool CSSHyphenateLimitCharsEnabled() { return is_css_hyphenate_limit_chars_enabled_; }
    static bool CSSHyphenateLimitCharsEnabled(const FeatureContext*) { return CSSHyphenateLimitCharsEnabled(); }

    static bool CSSIcUnitEnabled() { return is_css_ic_unit_enabled_; }
    static bool CSSIcUnitEnabled(const FeatureContext*) { return CSSIcUnitEnabled(); }

    static bool CSSIndependentTransformPropertiesEnabled() { return is_css_independent_transform_properties_enabled_; }
    static bool CSSIndependentTransformPropertiesEnabled(const FeatureContext*) { return CSSIndependentTransformPropertiesEnabled(); }

    static bool CSSInitialLetterEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_css_initial_letter_enabled_;
    }
    static bool CSSInitialLetterEnabled(const FeatureContext*) { return CSSInitialLetterEnabled(); }

    static bool CSSLastBaselineEnabled() { return is_css_last_baseline_enabled_; }
    static bool CSSLastBaselineEnabled(const FeatureContext*) { return CSSLastBaselineEnabled(); }

    static bool CSSLayoutAPIEnabled() { return is_css_layout_api_enabled_; }
    static bool CSSLayoutAPIEnabled(const FeatureContext*) { return CSSLayoutAPIEnabled(); }

    static bool CSSLhUnitEnabled() { return is_css_lh_unit_enabled_; }
    static bool CSSLhUnitEnabled(const FeatureContext*) { return CSSLhUnitEnabled(); }

    static bool CSSLogicalEnabled() { return is_css_logical_enabled_; }
    static bool CSSLogicalEnabled(const FeatureContext*) { return CSSLogicalEnabled(); }

    static bool CSSLogicalOverflowEnabled() { return is_css_logical_overflow_enabled_; }
    static bool CSSLogicalOverflowEnabled(const FeatureContext*) { return CSSLogicalOverflowEnabled(); }

    static bool CSSMarkerNestedPseudoElementEnabled() { return is_css_marker_nested_pseudo_element_enabled_; }
    static bool CSSMarkerNestedPseudoElementEnabled(const FeatureContext*) { return CSSMarkerNestedPseudoElementEnabled(); }

    static bool CSSMathDepthEnabled()
    {
        if (MathMLCoreEnabled())
            return true;
        return is_css_math_depth_enabled_;
    }
    static bool CSSMathDepthEnabled(const FeatureContext*) { return CSSMathDepthEnabled(); }

    static bool CSSMathShiftEnabled()
    {
        if (MathMLCoreEnabled())
            return true;
        return is_css_math_shift_enabled_;
    }
    static bool CSSMathShiftEnabled(const FeatureContext*) { return CSSMathShiftEnabled(); }

    static bool CSSMathStyleEnabled()
    {
        if (MathMLCoreEnabled())
            return true;
        return is_css_math_style_enabled_;
    }
    static bool CSSMathStyleEnabled(const FeatureContext*) { return CSSMathStyleEnabled(); }

    static bool CSSMathVariantEnabled()
    {
        if (MathMLCoreEnabled())
            return true;
        return is_css_math_variant_enabled_;
    }
    static bool CSSMathVariantEnabled(const FeatureContext*) { return CSSMathVariantEnabled(); }

    static bool CSSMediaQueries4Enabled() { return is_css_media_queries_4_enabled_; }
    static bool CSSMediaQueries4Enabled(const FeatureContext*) { return CSSMediaQueries4Enabled(); }

    static bool CSSMixBlendModePlusLighterEnabled() { return is_css_mix_blend_mode_plus_lighter_enabled_; }
    static bool CSSMixBlendModePlusLighterEnabled(const FeatureContext*) { return CSSMixBlendModePlusLighterEnabled(); }

    static bool CSSObjectViewBoxEnabled() { return is_css_object_view_box_enabled_; }
    static bool CSSObjectViewBoxEnabled(const FeatureContext*) { return CSSObjectViewBoxEnabled(); }

    static bool CSSOffsetPathRayEnabled() { return is_css_offset_path_ray_enabled_; }
    static bool CSSOffsetPathRayEnabled(const FeatureContext*) { return CSSOffsetPathRayEnabled(); }

    static bool CSSOffsetPathRayContainEnabled() { return is_css_offset_path_ray_contain_enabled_; }
    static bool CSSOffsetPathRayContainEnabled(const FeatureContext*) { return CSSOffsetPathRayContainEnabled(); }

    static bool CSSOffsetPositionAnchorEnabled() { return is_css_offset_position_anchor_enabled_; }
    static bool CSSOffsetPositionAnchorEnabled(const FeatureContext*) { return CSSOffsetPositionAnchorEnabled(); }

    static bool CSSOverflowForReplacedElementsEnabled() { return is_css_overflow_for_replaced_elements_enabled_; }
    static bool CSSOverflowForReplacedElementsEnabled(const FeatureContext*) { return CSSOverflowForReplacedElementsEnabled(); }

    static bool CSSPaintAPIArgumentsEnabled() { return is_css_paint_api_arguments_enabled_; }
    static bool CSSPaintAPIArgumentsEnabled(const FeatureContext*) { return CSSPaintAPIArgumentsEnabled(); }

    static bool CSSPictureInPictureEnabled()
    {
        if (!PictureInPictureAPIEnabled())
            return false;
        return is_css_picture_in_picture_enabled_;
    }
    static bool CSSPictureInPictureEnabled(const FeatureContext*) { return CSSPictureInPictureEnabled(); }

    static bool CSSPositionStickyStaticScrollPositionEnabled() { return is_css_position_sticky_static_scroll_position_enabled_; }
    static bool CSSPositionStickyStaticScrollPositionEnabled(const FeatureContext*) { return CSSPositionStickyStaticScrollPositionEnabled(); }

    static bool CSSPseudoAutofillEnabled() { return is_css_pseudo_autofill_enabled_; }
    static bool CSSPseudoAutofillEnabled(const FeatureContext*) { return CSSPseudoAutofillEnabled(); }

    static bool CSSPseudoDirEnabled() { return is_css_pseudo_dir_enabled_; }
    static bool CSSPseudoDirEnabled(const FeatureContext*) { return CSSPseudoDirEnabled(); }

    static bool CSSPseudoHasEnabled() { return is_css_pseudo_has_enabled_; }
    static bool CSSPseudoHasEnabled(const FeatureContext*) { return CSSPseudoHasEnabled(); }

    static bool CSSPseudoPlayingPausedEnabled() { return is_css_pseudo_playing_paused_enabled_; }
    static bool CSSPseudoPlayingPausedEnabled(const FeatureContext*) { return CSSPseudoPlayingPausedEnabled(); }

    static bool CSSScopeEnabled() { return is_css_scope_enabled_; }
    static bool CSSScopeEnabled(const FeatureContext*) { return CSSScopeEnabled(); }

    static bool CSSScrollbarsEnabled() { return is_css_scrollbars_enabled_; }
    static bool CSSScrollbarsEnabled(const FeatureContext*) { return CSSScrollbarsEnabled(); }

    static bool CSSScrollTimelineEnabled() { return is_css_scroll_timeline_enabled_; }
    static bool CSSScrollTimelineEnabled(const FeatureContext*) { return CSSScrollTimelineEnabled(); }

    static bool CSSSelectorFragmentAnchorEnabled() { return is_css_selector_fragment_anchor_enabled_; }
    static bool CSSSelectorFragmentAnchorEnabled(const FeatureContext*) { return CSSSelectorFragmentAnchorEnabled(); }

    static bool CSSSnapSizeEnabled() { return is_css_snap_size_enabled_; }
    static bool CSSSnapSizeEnabled(const FeatureContext*) { return CSSSnapSizeEnabled(); }

    static bool CSSSpellingGrammarErrorsEnabled() { return is_css_spelling_grammar_errors_enabled_; }
    static bool CSSSpellingGrammarErrorsEnabled(const FeatureContext*) { return CSSSpellingGrammarErrorsEnabled(); }

    static bool CSSStyleQueriesEnabled() { return is_css_style_queries_enabled_; }
    static bool CSSStyleQueriesEnabled(const FeatureContext*) { return CSSStyleQueriesEnabled(); }

    static bool CSSTogglesEnabled() { return is_css_toggles_enabled_; }
    static bool CSSTogglesEnabled(const FeatureContext*) { return CSSTogglesEnabled(); }

    static bool CSSTrigonometricFunctionsEnabled() { return is_css_trigonometric_functions_enabled_; }
    static bool CSSTrigonometricFunctionsEnabled(const FeatureContext*) { return CSSTrigonometricFunctionsEnabled(); }

    static bool CSSVariables2ImageValuesEnabled() { return is_css_variables_2_image_values_enabled_; }
    static bool CSSVariables2ImageValuesEnabled(const FeatureContext*) { return CSSVariables2ImageValuesEnabled(); }

    static bool CSSVariables2TransformValuesEnabled() { return is_css_variables_2_transform_values_enabled_; }
    static bool CSSVariables2TransformValuesEnabled(const FeatureContext*) { return CSSVariables2TransformValuesEnabled(); }

    static bool CSSVideoDynamicRangeMediaQueriesEnabled() { return is_css_video_dynamic_range_media_queries_enabled_; }
    static bool CSSVideoDynamicRangeMediaQueriesEnabled(const FeatureContext*) { return CSSVideoDynamicRangeMediaQueriesEnabled(); }

    static bool CSSViewportUnits4Enabled() { return is_css_viewport_units_4_enabled_; }
    static bool CSSViewportUnits4Enabled(const FeatureContext*) { return CSSViewportUnits4Enabled(); }

    static bool CSSViewTimelineEnabled() { return is_css_view_timeline_enabled_; }
    static bool CSSViewTimelineEnabled(const FeatureContext*) { return CSSViewTimelineEnabled(); }

    static bool CustomElementDefaultStyleEnabled() { return is_custom_element_default_style_enabled_; }
    static bool CustomElementDefaultStyleEnabled(const FeatureContext*) { return CustomElementDefaultStyleEnabled(); }

    static bool DatabaseEnabled() { return is_database_enabled_; }
    static bool DatabaseEnabled(const FeatureContext*) { return DatabaseEnabled(); }

    static bool DecodeJpeg420ImagesToYUVEnabled() { return is_decode_jpeg_420_images_to_yuv_enabled_; }
    static bool DecodeJpeg420ImagesToYUVEnabled(const FeatureContext*) { return DecodeJpeg420ImagesToYUVEnabled(); }

    static bool DecodeLossyWebPImagesToYUVEnabled() { return is_decode_lossy_web_p_images_to_yuv_enabled_; }
    static bool DecodeLossyWebPImagesToYUVEnabled(const FeatureContext*) { return DecodeLossyWebPImagesToYUVEnabled(); }

    static bool DeferredShapingEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_deferred_shaping_enabled_;
    }
    static bool DeferredShapingEnabled(const FeatureContext*) { return DeferredShapingEnabled(); }

    static bool DeflateRawCompressionFormatEnabled() { return is_deflate_raw_compression_format_enabled_; }
    static bool DeflateRawCompressionFormatEnabled(const FeatureContext*) { return DeflateRawCompressionFormatEnabled(); }

    static bool DelegatedInkTrailsEnabled() { return is_delegated_ink_trails_enabled_; }
    static bool DelegatedInkTrailsEnabled(const FeatureContext*) { return DelegatedInkTrailsEnabled(); }

    static bool DeliveryTypeEnabled() { return is_delivery_type_enabled_; }
    static bool DeliveryTypeEnabled(const FeatureContext*) { return DeliveryTypeEnabled(); }

    static bool DesktopCaptureDisableLocalEchoControlEnabled() { return is_desktop_capture_disable_local_echo_control_enabled_; }
    static bool DesktopCaptureDisableLocalEchoControlEnabled(const FeatureContext*) { return DesktopCaptureDisableLocalEchoControlEnabled(); }

    static bool DesktopPWAsSubAppsEnabled() { return is_desktop_pw_as_sub_apps_enabled_; }
    static bool DesktopPWAsSubAppsEnabled(const FeatureContext*) { return DesktopPWAsSubAppsEnabled(); }

    static bool DeviceOrientationRequestPermissionEnabled() { return is_device_orientation_request_permission_enabled_; }
    static bool DeviceOrientationRequestPermissionEnabled(const FeatureContext*) { return DeviceOrientationRequestPermissionEnabled(); }

    static bool DevicePostureEnabled() { return is_device_posture_enabled_; }
    static bool DevicePostureEnabled(const FeatureContext*) { return DevicePostureEnabled(); }

    static bool DigitalGoodsV2_1Enabled() { return is_digital_goods_v_2_1_enabled_; }
    static bool DigitalGoodsV2_1Enabled(const FeatureContext*) { return DigitalGoodsV2_1Enabled(); }

    static bool DirectSocketsEnabled() { return is_direct_sockets_enabled_; }
    static bool DirectSocketsEnabled(const FeatureContext*) { return DirectSocketsEnabled(); }

    static bool DisplayCutoutAPIEnabled() { return is_display_cutout_api_enabled_; }
    static bool DisplayCutoutAPIEnabled(const FeatureContext*) { return DisplayCutoutAPIEnabled(); }

    static bool DisplaySurfaceConstraintEnabled() { return is_display_surface_constraint_enabled_; }
    static bool DisplaySurfaceConstraintEnabled(const FeatureContext*) { return DisplaySurfaceConstraintEnabled(); }

    static bool DocumentCookieEnabled() { return is_document_cookie_enabled_; }
    static bool DocumentCookieEnabled(const FeatureContext*) { return DocumentCookieEnabled(); }

    static bool DocumentDomainEnabled() { return is_document_domain_enabled_; }
    static bool DocumentDomainEnabled(const FeatureContext*) { return DocumentDomainEnabled(); }

    static bool DocumentPictureInPictureAPIEnabled()
    {
        if (!PictureInPictureAPIEnabled())
            return false;
        return is_document_picture_in_picture_api_enabled_;
    }
    static bool DocumentPictureInPictureAPIEnabled(const FeatureContext*) { return DocumentPictureInPictureAPIEnabled(); }

    static bool DocumentPolicyEnabled() { return is_document_policy_enabled_; }
    static bool DocumentPolicyEnabled(const FeatureContext*) { return DocumentPolicyEnabled(); }

    static bool DocumentPolicyDocumentDomainEnabled()
    {
        if (!DocumentPolicyEnabled())
            return false;
        return is_document_policy_document_domain_enabled_;
    }
    static bool DocumentPolicyDocumentDomainEnabled(const FeatureContext*) { return DocumentPolicyDocumentDomainEnabled(); }

    static bool DocumentPolicySyncXHREnabled()
    {
        if (!DocumentPolicyEnabled())
            return false;
        return is_document_policy_sync_xhr_enabled_;
    }
    static bool DocumentPolicySyncXHREnabled(const FeatureContext*) { return DocumentPolicySyncXHREnabled(); }

    static bool DocumentTransitionEnabled() { return is_document_transition_enabled_; }
    static bool DocumentTransitionEnabled(const FeatureContext*) { return DocumentTransitionEnabled(); }

    static bool DocumentWriteEnabled() { return is_document_write_enabled_; }
    static bool DocumentWriteEnabled(const FeatureContext*) { return DocumentWriteEnabled(); }

    static bool EditContextEnabled() { return is_edit_context_enabled_; }
    static bool EditContextEnabled(const FeatureContext*) { return EditContextEnabled(); }

    static bool ElementSuperRareDataEnabled() { return is_element_super_rare_data_enabled_; }
    static bool ElementSuperRareDataEnabled(const FeatureContext*) { return ElementSuperRareDataEnabled(); }

    static bool EventPathEnabled() { return is_event_path_enabled_; }
    static bool EventPathEnabled(const FeatureContext*) { return EventPathEnabled(); }

    static bool ExperimentalContentSecurityPolicyFeaturesEnabled() { return is_experimental_content_security_policy_features_enabled_; }
    static bool ExperimentalContentSecurityPolicyFeaturesEnabled(const FeatureContext*) { return ExperimentalContentSecurityPolicyFeaturesEnabled(); }

    static bool ExperimentalJSProfilerMarkersEnabled() { return is_experimental_js_profiler_markers_enabled_; }
    static bool ExperimentalJSProfilerMarkersEnabled(const FeatureContext*) { return ExperimentalJSProfilerMarkersEnabled(); }

    static bool ExperimentalPoliciesEnabled()
    {
        if (!DocumentPolicyEnabled())
            return false;
        return is_experimental_policies_enabled_;
    }
    static bool ExperimentalPoliciesEnabled(const FeatureContext*) { return ExperimentalPoliciesEnabled(); }

    static bool ExperimentalWebSnapshotsEnabled() { return is_experimental_web_snapshots_enabled_; }
    static bool ExperimentalWebSnapshotsEnabled(const FeatureContext*) { return ExperimentalWebSnapshotsEnabled(); }

    static bool ExtendedTextMetricsEnabled() { return is_extended_text_metrics_enabled_; }
    static bool ExtendedTextMetricsEnabled(const FeatureContext*) { return ExtendedTextMetricsEnabled(); }

    static bool ExtraWebGLVideoTextureMetadataEnabled() { return is_extra_webgl_video_texture_metadata_enabled_; }
    static bool ExtraWebGLVideoTextureMetadataEnabled(const FeatureContext*) { return ExtraWebGLVideoTextureMetadataEnabled(); }

    static bool EyeDropperAPIEnabled() { return is_eye_dropper_api_enabled_; }
    static bool EyeDropperAPIEnabled(const FeatureContext*) { return EyeDropperAPIEnabled(); }

    static bool FaceDetectorEnabled() { return is_face_detector_enabled_; }
    static bool FaceDetectorEnabled(const FeatureContext*) { return FaceDetectorEnabled(); }

    static bool FakeNoAllocDirectCallForTestingEnabled() { return is_fake_no_alloc_direct_call_for_testing_enabled_; }
    static bool FakeNoAllocDirectCallForTestingEnabled(const FeatureContext*) { return FakeNoAllocDirectCallForTestingEnabled(); }

    static bool FeaturePolicyReportingEnabled() { return is_feature_policy_reporting_enabled_; }
    static bool FeaturePolicyReportingEnabled(const FeatureContext*) { return FeaturePolicyReportingEnabled(); }

    static bool FedCmEnabled() { return is_fed_cm_enabled_; }
    static bool FedCmEnabled(const FeatureContext*) { return FedCmEnabled(); }

    static bool FedCmIdpSigninStatusEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_idp_signin_status_enabled_;
    }
    static bool FedCmIdpSigninStatusEnabled(const FeatureContext*) { return FedCmIdpSigninStatusEnabled(); }

    static bool FedCmIdpSignoutEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_idp_signout_enabled_;
    }
    static bool FedCmIdpSignoutEnabled(const FeatureContext*) { return FedCmIdpSignoutEnabled(); }

    static bool FedCmIframeSupportEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_iframe_support_enabled_;
    }
    static bool FedCmIframeSupportEnabled(const FeatureContext*) { return FedCmIframeSupportEnabled(); }

    static bool FedCmMultipleIdentityProvidersEnabled()
    {
        if (!FedCmEnabled())
            return false;
        return is_fed_cm_multiple_identity_providers_enabled_;
    }
    static bool FedCmMultipleIdentityProvidersEnabled(const FeatureContext*) { return FedCmMultipleIdentityProvidersEnabled(); }

    static bool FetchUploadStreamingEnabled() { return is_fetch_upload_streaming_enabled_; }
    static bool FetchUploadStreamingEnabled(const FeatureContext*) { return FetchUploadStreamingEnabled(); }

    static bool FileSystemEnabled() { return is_file_system_enabled_; }
    static bool FileSystemEnabled(const FeatureContext*) { return FileSystemEnabled(); }

    static bool FileSystemAccessEnabled()
    {
        if (FileSystemAccessLocalEnabled())
            return true;
        if (FileSystemAccessOriginPrivateEnabled())
            return true;
        return is_file_system_access_enabled_;
    }
    static bool FileSystemAccessEnabled(const FeatureContext*) { return FileSystemAccessEnabled(); }

    static bool FileSystemAccessAccessHandleEnabled() { return is_file_system_access_access_handle_enabled_; }
    static bool FileSystemAccessAccessHandleEnabled(const FeatureContext*) { return FileSystemAccessAccessHandleEnabled(); }

    static bool FileSystemAccessAPIExperimentalEnabled() { return is_file_system_access_api_experimental_enabled_; }
    static bool FileSystemAccessAPIExperimentalEnabled(const FeatureContext*) { return FileSystemAccessAPIExperimentalEnabled(); }

    static bool FileSystemAccessLocalEnabled() { return is_file_system_access_local_enabled_; }
    static bool FileSystemAccessLocalEnabled(const FeatureContext*) { return FileSystemAccessLocalEnabled(); }

    static bool FileSystemAccessOriginPrivateEnabled() { return is_file_system_access_origin_private_enabled_; }
    static bool FileSystemAccessOriginPrivateEnabled(const FeatureContext*) { return FileSystemAccessOriginPrivateEnabled(); }

    static bool FileSystemSyncAccessHandleAsyncInterfaceOverrideEnabled() { return is_file_system_sync_access_handle_async_interface_override_enabled_; }
    static bool FileSystemSyncAccessHandleAsyncInterfaceOverrideEnabled(const FeatureContext*) { return FileSystemSyncAccessHandleAsyncInterfaceOverrideEnabled(); }

    static bool FirstPartySetsEnabled() { return is_first_party_sets_enabled_; }
    static bool FirstPartySetsEnabled(const FeatureContext*) { return FirstPartySetsEnabled(); }

    static bool FixedElementsDontOverscrollEnabled() { return is_fixed_elements_dont_overscroll_enabled_; }
    static bool FixedElementsDontOverscrollEnabled(const FeatureContext*) { return FixedElementsDontOverscrollEnabled(); }

    static bool FluentScrollbarsEnabled() { return is_fluent_scrollbars_enabled_; }
    static bool FluentScrollbarsEnabled(const FeatureContext*) { return FluentScrollbarsEnabled(); }

    static bool FocuslessSpatialNavigationEnabled() { return is_focusless_spatial_navigation_enabled_; }
    static bool FocuslessSpatialNavigationEnabled(const FeatureContext*) { return FocuslessSpatialNavigationEnabled(); }

    static bool FontAccessEnabled() { return is_font_access_enabled_; }
    static bool FontAccessEnabled(const FeatureContext*) { return FontAccessEnabled(); }

    static bool FontPaletteEnabled() { return is_font_palette_enabled_; }
    static bool FontPaletteEnabled(const FeatureContext*) { return FontPaletteEnabled(); }

    static bool FontSrcLocalMatchingEnabled() { return is_font_src_local_matching_enabled_; }
    static bool FontSrcLocalMatchingEnabled(const FeatureContext*) { return FontSrcLocalMatchingEnabled(); }

    static bool ForcedColorsEnabled() { return is_forced_colors_enabled_; }
    static bool ForcedColorsEnabled(const FeatureContext*) { return ForcedColorsEnabled(); }

    static bool ForcedColorsPreserveParentColorEnabled() { return is_forced_colors_preserve_parent_color_enabled_; }
    static bool ForcedColorsPreserveParentColorEnabled(const FeatureContext*) { return ForcedColorsPreserveParentColorEnabled(); }

    static bool ForceEagerMeasureMemoryEnabled() { return is_force_eager_measure_memory_enabled_; }
    static bool ForceEagerMeasureMemoryEnabled(const FeatureContext*) { return ForceEagerMeasureMemoryEnabled(); }

    static bool ForceReduceMotionEnabled() { return is_force_reduce_motion_enabled_; }
    static bool ForceReduceMotionEnabled(const FeatureContext*) { return ForceReduceMotionEnabled(); }

    static bool ForceTallerSelectPopupEnabled() { return is_force_taller_select_popup_enabled_; }
    static bool ForceTallerSelectPopupEnabled(const FeatureContext*) { return ForceTallerSelectPopupEnabled(); }

    static bool FormattedTextEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_formatted_text_enabled_;
    }
    static bool FormattedTextEnabled(const FeatureContext*) { return FormattedTextEnabled(); }

    static bool FormRelAttributeEnabled() { return is_form_rel_attribute_enabled_; }
    static bool FormRelAttributeEnabled(const FeatureContext*) { return FormRelAttributeEnabled(); }

    static bool FractionalScrollOffsetsEnabled()
    {
        if (PercentBasedScrollingEnabled())
            return true;
        return is_fractional_scroll_offsets_enabled_;
    }
    static bool FractionalScrollOffsetsEnabled(const FeatureContext*) { return FractionalScrollOffsetsEnabled(); }

    static bool FreezeFramesOnVisibilityEnabled() { return is_freeze_frames_on_visibility_enabled_; }
    static bool FreezeFramesOnVisibilityEnabled(const FeatureContext*) { return FreezeFramesOnVisibilityEnabled(); }

    static bool GamepadButtonAxisEventsEnabled() { return is_gamepad_button_axis_events_enabled_; }
    static bool GamepadButtonAxisEventsEnabled(const FeatureContext*) { return GamepadButtonAxisEventsEnabled(); }

    static bool GetDisplayMediaEnabled() { return is_get_display_media_enabled_; }
    static bool GetDisplayMediaEnabled(const FeatureContext*) { return GetDisplayMediaEnabled(); }

    static bool GetDisplayMediaSetEnabled()
    {
        if (!GetDisplayMediaEnabled())
            return false;
        return is_get_display_media_set_enabled_;
    }
    static bool GetDisplayMediaSetEnabled(const FeatureContext*) { return GetDisplayMediaSetEnabled(); }

    static bool GetDisplayMediaSetAutoSelectAllScreensEnabled()
    {
        if (!GetDisplayMediaSetEnabled())
            return false;
        return is_get_display_media_set_auto_select_all_screens_enabled_;
    }
    static bool GetDisplayMediaSetAutoSelectAllScreensEnabled(const FeatureContext*) { return GetDisplayMediaSetAutoSelectAllScreensEnabled(); }

    static bool GroupEffectEnabled() { return is_group_effect_enabled_; }
    static bool GroupEffectEnabled(const FeatureContext*) { return GroupEffectEnabled(); }

    static bool HandwritingRecognitionEnabled() { return is_handwriting_recognition_enabled_; }
    static bool HandwritingRecognitionEnabled(const FeatureContext*) { return HandwritingRecognitionEnabled(); }

    static bool HidDeviceForgetEnabled()
    {
        if (!WebHIDEnabled())
            return false;
        return is_hid_device_forget_enabled_;
    }
    static bool HidDeviceForgetEnabled(const FeatureContext*) { return HidDeviceForgetEnabled(); }

    static bool HighlightAPIEnabled() { return is_highlight_api_enabled_; }
    static bool HighlightAPIEnabled(const FeatureContext*) { return HighlightAPIEnabled(); }

    static bool HighlightInheritanceEnabled() { return is_highlight_inheritance_enabled_; }
    static bool HighlightInheritanceEnabled(const FeatureContext*) { return HighlightInheritanceEnabled(); }

    static bool HighlightOverlayPaintingEnabled() { return is_highlight_overlay_painting_enabled_; }
    static bool HighlightOverlayPaintingEnabled(const FeatureContext*) { return HighlightOverlayPaintingEnabled(); }

    static bool HighlightPointerEventsEnabled()
    {
        if (!HighlightAPIEnabled())
            return false;
        return is_highlight_pointer_events_enabled_;
    }
    static bool HighlightPointerEventsEnabled(const FeatureContext*) { return HighlightPointerEventsEnabled(); }

    static bool HTMLParamElementUrlSupportEnabled() { return is_html_param_element_url_support_enabled_; }
    static bool HTMLParamElementUrlSupportEnabled(const FeatureContext*) { return HTMLParamElementUrlSupportEnabled(); }

    static bool HTMLSelectMenuElementEnabled() { return is_html_select_menu_element_enabled_; }
    static bool HTMLSelectMenuElementEnabled(const FeatureContext*) { return HTMLSelectMenuElementEnabled(); }

    static bool IDBBatchGetAllEnabled() { return is_idb_batch_get_all_enabled_; }
    static bool IDBBatchGetAllEnabled(const FeatureContext*) { return IDBBatchGetAllEnabled(); }

    static bool IdleDetectionEnabled() { return is_idle_detection_enabled_; }
    static bool IdleDetectionEnabled(const FeatureContext*) { return IdleDetectionEnabled(); }

    static bool ImplicitRootScrollerEnabled() { return is_implicit_root_scroller_enabled_; }
    static bool ImplicitRootScrollerEnabled(const FeatureContext*) { return ImplicitRootScrollerEnabled(); }

    static bool InertAttributeEnabled() { return is_inert_attribute_enabled_; }
    static bool InertAttributeEnabled(const FeatureContext*) { return InertAttributeEnabled(); }

    static bool InfiniteCullRectEnabled() { return is_infinite_cull_rect_enabled_; }
    static bool InfiniteCullRectEnabled(const FeatureContext*) { return InfiniteCullRectEnabled(); }

    static bool InputMultipleFieldsUIEnabled() { return is_input_multiple_fields_ui_enabled_; }
    static bool InputMultipleFieldsUIEnabled(const FeatureContext*) { return InputMultipleFieldsUIEnabled(); }

    static bool InstalledAppEnabled() { return is_installed_app_enabled_; }
    static bool InstalledAppEnabled(const FeatureContext*) { return InstalledAppEnabled(); }

    static bool KeyboardAccessibleTooltipEnabled() { return is_keyboard_accessible_tooltip_enabled_; }
    static bool KeyboardAccessibleTooltipEnabled(const FeatureContext*) { return KeyboardAccessibleTooltipEnabled(); }

    static bool KeyboardFocusableScrollersEnabled() { return is_keyboard_focusable_scrollers_enabled_; }
    static bool KeyboardFocusableScrollersEnabled(const FeatureContext*) { return KeyboardFocusableScrollersEnabled(); }

    static bool LangAttributeAwareFormControlUIEnabled() { return is_lang_attribute_aware_form_control_ui_enabled_; }
    static bool LangAttributeAwareFormControlUIEnabled(const FeatureContext*) { return LangAttributeAwareFormControlUIEnabled(); }

    static bool LangAttributeAwareSvgTextEnabled() { return is_lang_attribute_aware_svg_text_enabled_; }
    static bool LangAttributeAwareSvgTextEnabled(const FeatureContext*) { return LangAttributeAwareSvgTextEnabled(); }

    static bool LayoutNGEnabled()
    {
        if (BidiCaretAffinityEnabled())
            return true;
        return is_layout_ng_enabled_;
    }
    static bool LayoutNGEnabled(const FeatureContext*) { return LayoutNGEnabled(); }

    static bool LayoutNGBlockFragmentationEnabled() { return is_layout_ng_block_fragmentation_enabled_; }
    static bool LayoutNGBlockFragmentationEnabled(const FeatureContext*) { return LayoutNGBlockFragmentationEnabled(); }

    static bool LayoutNGBlockInInlineEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_layout_ng_block_in_inline_enabled_;
    }
    static bool LayoutNGBlockInInlineEnabled(const FeatureContext*) { return LayoutNGBlockInInlineEnabled(); }

    static bool LayoutNGDelayScrollOffsetClampingEnabled() { return is_layout_ng_delay_scroll_offset_clamping_enabled_; }
    static bool LayoutNGDelayScrollOffsetClampingEnabled(const FeatureContext*) { return LayoutNGDelayScrollOffsetClampingEnabled(); }

    static bool LayoutNGFlexFragmentationEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        if (!LayoutNGBlockFragmentationEnabled())
            return false;
        return is_layout_ng_flex_fragmentation_enabled_;
    }
    static bool LayoutNGFlexFragmentationEnabled(const FeatureContext*) { return LayoutNGFlexFragmentationEnabled(); }

    static bool LayoutNGForeignObjectEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_layout_ng_foreign_object_enabled_;
    }
    static bool LayoutNGForeignObjectEnabled(const FeatureContext*) { return LayoutNGForeignObjectEnabled(); }

    static bool LayoutNGFrameSetEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_layout_ng_frame_set_enabled_;
    }
    static bool LayoutNGFrameSetEnabled(const FeatureContext*) { return LayoutNGFrameSetEnabled(); }

    static bool LayoutNGGridFragmentationEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        if (!LayoutNGBlockFragmentationEnabled())
            return false;
        return is_layout_ng_grid_fragmentation_enabled_;
    }
    static bool LayoutNGGridFragmentationEnabled(const FeatureContext*) { return LayoutNGGridFragmentationEnabled(); }

    static bool LayoutNGPrintingEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        if (!LayoutNGBlockFragmentationEnabled())
            return false;
        return is_layout_ng_printing_enabled_;
    }
    static bool LayoutNGPrintingEnabled(const FeatureContext*) { return LayoutNGPrintingEnabled(); }

    static bool LayoutNGSubgridEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_layout_ng_subgrid_enabled_;
    }
    static bool LayoutNGSubgridEnabled(const FeatureContext*) { return LayoutNGSubgridEnabled(); }

    static bool LayoutNGTableFragmentationEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        if (!LayoutNGBlockFragmentationEnabled())
            return false;
        return is_layout_ng_table_fragmentation_enabled_;
    }
    static bool LayoutNGTableFragmentationEnabled(const FeatureContext*) { return LayoutNGTableFragmentationEnabled(); }

    static bool LayoutNGVTTCueEnabled() { return is_layout_ngvtt_cue_enabled_; }
    static bool LayoutNGVTTCueEnabled(const FeatureContext*) { return LayoutNGVTTCueEnabled(); }

    static bool LazyFrameLoadingEnabled() { return is_lazy_frame_loading_enabled_; }
    static bool LazyFrameLoadingEnabled(const FeatureContext*) { return LazyFrameLoadingEnabled(); }

    static bool LazyFrameVisibleLoadTimeMetricsEnabled() { return is_lazy_frame_visible_load_time_metrics_enabled_; }
    static bool LazyFrameVisibleLoadTimeMetricsEnabled(const FeatureContext*) { return LazyFrameVisibleLoadTimeMetricsEnabled(); }

    static bool LazyImageLoadingEnabled() { return is_lazy_image_loading_enabled_; }
    static bool LazyImageLoadingEnabled(const FeatureContext*) { return LazyImageLoadingEnabled(); }

    static bool LazyImageVisibleLoadTimeMetricsEnabled() { return is_lazy_image_visible_load_time_metrics_enabled_; }
    static bool LazyImageVisibleLoadTimeMetricsEnabled(const FeatureContext*) { return LazyImageVisibleLoadTimeMetricsEnabled(); }

    static bool LazyInitializeMediaControlsEnabled() { return is_lazy_initialize_media_controls_enabled_; }
    static bool LazyInitializeMediaControlsEnabled(const FeatureContext*) { return LazyInitializeMediaControlsEnabled(); }

    static bool LCPAnimatedImagesWebExposedEnabled() { return is_lcp_animated_images_web_exposed_enabled_; }
    static bool LCPAnimatedImagesWebExposedEnabled(const FeatureContext*) { return LCPAnimatedImagesWebExposedEnabled(); }

    static bool LegacyWindowsDWriteFontFallbackEnabled() { return is_legacy_windows_d_write_font_fallback_enabled_; }
    static bool LegacyWindowsDWriteFontFallbackEnabled(const FeatureContext*) { return LegacyWindowsDWriteFontFallbackEnabled(); }

    static bool MachineLearningCommonEnabled()
    {
        if (MachineLearningModelLoaderEnabled())
            return true;
        if (MachineLearningNeuralNetworkEnabled())
            return true;
        return is_machine_learning_common_enabled_;
    }
    static bool MachineLearningCommonEnabled(const FeatureContext*) { return MachineLearningCommonEnabled(); }

    static bool MachineLearningModelLoaderEnabled() { return is_machine_learning_model_loader_enabled_; }
    static bool MachineLearningModelLoaderEnabled(const FeatureContext*) { return MachineLearningModelLoaderEnabled(); }

    static bool MachineLearningNeuralNetworkEnabled() { return is_machine_learning_neural_network_enabled_; }
    static bool MachineLearningNeuralNetworkEnabled(const FeatureContext*) { return MachineLearningNeuralNetworkEnabled(); }

    static bool ManagedConfigurationEnabled() { return is_managed_configuration_enabled_; }
    static bool ManagedConfigurationEnabled(const FeatureContext*) { return ManagedConfigurationEnabled(); }

    static bool MathMLCoreEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_mathml_core_enabled_;
    }
    static bool MathMLCoreEnabled(const FeatureContext*) { return MathMLCoreEnabled(); }

    static bool MeasureMemoryEnabled() { return is_measure_memory_enabled_; }
    static bool MeasureMemoryEnabled(const FeatureContext*) { return MeasureMemoryEnabled(); }

    static bool MediaCapabilitiesDynamicRangeEnabled() { return is_media_capabilities_dynamic_range_enabled_; }
    static bool MediaCapabilitiesDynamicRangeEnabled(const FeatureContext*) { return MediaCapabilitiesDynamicRangeEnabled(); }

    static bool MediaCapabilitiesEncodingInfoEnabled() { return is_media_capabilities_encoding_info_enabled_; }
    static bool MediaCapabilitiesEncodingInfoEnabled(const FeatureContext*) { return MediaCapabilitiesEncodingInfoEnabled(); }

    static bool MediaCapabilitiesSpatialAudioEnabled() { return is_media_capabilities_spatial_audio_enabled_; }
    static bool MediaCapabilitiesSpatialAudioEnabled(const FeatureContext*) { return MediaCapabilitiesSpatialAudioEnabled(); }

    static bool MediaCaptureEnabled() { return is_media_capture_enabled_; }
    static bool MediaCaptureEnabled(const FeatureContext*) { return MediaCaptureEnabled(); }

    static bool MediaCaptureBackgroundBlurEnabled() { return is_media_capture_background_blur_enabled_; }
    static bool MediaCaptureBackgroundBlurEnabled(const FeatureContext*) { return MediaCaptureBackgroundBlurEnabled(); }

    static bool MediaCastOverlayButtonEnabled() { return is_media_cast_overlay_button_enabled_; }
    static bool MediaCastOverlayButtonEnabled(const FeatureContext*) { return MediaCastOverlayButtonEnabled(); }

    static bool MediaControlsExpandGestureEnabled() { return is_media_controls_expand_gesture_enabled_; }
    static bool MediaControlsExpandGestureEnabled(const FeatureContext*) { return MediaControlsExpandGestureEnabled(); }

    static bool MediaControlsOverlayPlayButtonEnabled() { return is_media_controls_overlay_play_button_enabled_; }
    static bool MediaControlsOverlayPlayButtonEnabled(const FeatureContext*) { return MediaControlsOverlayPlayButtonEnabled(); }

    static bool MediaElementVolumeGreaterThanOneEnabled() { return is_media_element_volume_greater_than_one_enabled_; }
    static bool MediaElementVolumeGreaterThanOneEnabled(const FeatureContext*) { return MediaElementVolumeGreaterThanOneEnabled(); }

    static bool MediaEngagementBypassAutoplayPoliciesEnabled() { return is_media_engagement_bypass_autoplay_policies_enabled_; }
    static bool MediaEngagementBypassAutoplayPoliciesEnabled(const FeatureContext*) { return MediaEngagementBypassAutoplayPoliciesEnabled(); }

    static bool MediaLatencyHintEnabled() { return is_media_latency_hint_enabled_; }
    static bool MediaLatencyHintEnabled(const FeatureContext*) { return MediaLatencyHintEnabled(); }

    static bool MediaQueryNavigationControlsEnabled() { return is_media_query_navigation_controls_enabled_; }
    static bool MediaQueryNavigationControlsEnabled(const FeatureContext*) { return MediaQueryNavigationControlsEnabled(); }

    static bool MediaSessionEnabled() { return is_media_session_enabled_; }
    static bool MediaSessionEnabled(const FeatureContext*) { return MediaSessionEnabled(); }

    static bool MediaSessionWebRTCEnabled() { return is_media_session_web_rtc_enabled_; }
    static bool MediaSessionWebRTCEnabled(const FeatureContext*) { return MediaSessionWebRTCEnabled(); }

    static bool MediaSourceExperimentalEnabled() { return is_media_source_experimental_enabled_; }
    static bool MediaSourceExperimentalEnabled(const FeatureContext*) { return MediaSourceExperimentalEnabled(); }

    static bool MediaSourceInWorkersUsingHandleEnabled() { return is_media_source_in_workers_using_handle_enabled_; }
    static bool MediaSourceInWorkersUsingHandleEnabled(const FeatureContext*) { return MediaSourceInWorkersUsingHandleEnabled(); }

    static bool MediaSourceNewAbortAndDurationEnabled() { return is_media_source_new_abort_and_duration_enabled_; }
    static bool MediaSourceNewAbortAndDurationEnabled(const FeatureContext*) { return MediaSourceNewAbortAndDurationEnabled(); }

    static bool MediaSourceStableEnabled() { return is_media_source_stable_enabled_; }
    static bool MediaSourceStableEnabled(const FeatureContext*) { return MediaSourceStableEnabled(); }

    static bool MediaStreamTrackInWindowEnabled() { return is_media_stream_track_in_window_enabled_; }
    static bool MediaStreamTrackInWindowEnabled(const FeatureContext*) { return MediaStreamTrackInWindowEnabled(); }

    static bool MediaStreamTrackInWorkerEnabled() { return is_media_stream_track_in_worker_enabled_; }
    static bool MediaStreamTrackInWorkerEnabled(const FeatureContext*) { return MediaStreamTrackInWorkerEnabled(); }

    static bool MediaStreamTrackTransferEnabled() { return is_media_stream_track_transfer_enabled_; }
    static bool MediaStreamTrackTransferEnabled(const FeatureContext*) { return MediaStreamTrackTransferEnabled(); }

    static bool MiddleClickAutoscrollEnabled() { return is_middle_click_autoscroll_enabled_; }
    static bool MiddleClickAutoscrollEnabled(const FeatureContext*) { return MiddleClickAutoscrollEnabled(); }

    static bool MobileLayoutThemeEnabled() { return is_mobile_layout_theme_enabled_; }
    static bool MobileLayoutThemeEnabled(const FeatureContext*) { return MobileLayoutThemeEnabled(); }

    static bool MojoJSEnabled() { return is_mojo_js_enabled_; }
    static bool MojoJSEnabled(const FeatureContext*) { return MojoJSEnabled(); }

    static bool MojoJSTestEnabled() { return is_mojo_js_test_enabled_; }
    static bool MojoJSTestEnabled(const FeatureContext*) { return MojoJSTestEnabled(); }

    static bool MouseSubframeNoImplicitCaptureEnabled() { return is_mouse_subframe_no_implicit_capture_enabled_; }
    static bool MouseSubframeNoImplicitCaptureEnabled(const FeatureContext*) { return MouseSubframeNoImplicitCaptureEnabled(); }

    static bool NavigationApiEnabled() { return is_navigation_api_enabled_; }
    static bool NavigationApiEnabled(const FeatureContext*) { return NavigationApiEnabled(); }

    static bool NavigationIdEnabled() { return is_navigation_id_enabled_; }
    static bool NavigationIdEnabled(const FeatureContext*) { return NavigationIdEnabled(); }

    static bool NavigatorContentUtilsEnabled() { return is_navigator_content_utils_enabled_; }
    static bool NavigatorContentUtilsEnabled(const FeatureContext*) { return NavigatorContentUtilsEnabled(); }

    static bool NetInfoDownlinkMaxEnabled() { return is_net_info_downlink_max_enabled_; }
    static bool NetInfoDownlinkMaxEnabled(const FeatureContext*) { return NetInfoDownlinkMaxEnabled(); }

    static bool NeverSlowModeEnabled() { return is_never_slow_mode_enabled_; }
    static bool NeverSlowModeEnabled(const FeatureContext*) { return NeverSlowModeEnabled(); }

    static bool NewFlexboxSizingEnabled() { return is_new_flexbox_sizing_enabled_; }
    static bool NewFlexboxSizingEnabled(const FeatureContext*) { return NewFlexboxSizingEnabled(); }

    static bool NoIdleEncodingForWebTestsEnabled() { return is_no_idle_encoding_for_web_tests_enabled_; }
    static bool NoIdleEncodingForWebTestsEnabled(const FeatureContext*) { return NoIdleEncodingForWebTestsEnabled(); }

    static bool NotificationConstructorEnabled() { return is_notification_constructor_enabled_; }
    static bool NotificationConstructorEnabled(const FeatureContext*) { return NotificationConstructorEnabled(); }

    static bool NotificationContentImageEnabled() { return is_notification_content_image_enabled_; }
    static bool NotificationContentImageEnabled(const FeatureContext*) { return NotificationContentImageEnabled(); }

    static bool NotificationsEnabled() { return is_notifications_enabled_; }
    static bool NotificationsEnabled(const FeatureContext*) { return NotificationsEnabled(); }

    static bool OffMainThreadCSSPaintEnabled() { return is_off_main_thread_css_paint_enabled_; }
    static bool OffMainThreadCSSPaintEnabled(const FeatureContext*) { return OffMainThreadCSSPaintEnabled(); }

    static bool OffscreenCanvasCommitEnabled() { return is_offscreen_canvas_commit_enabled_; }
    static bool OffscreenCanvasCommitEnabled(const FeatureContext*) { return OffscreenCanvasCommitEnabled(); }

    static bool OffsetParentNewSpecBehaviorEnabled() { return is_offset_parent_new_spec_behavior_enabled_; }
    static bool OffsetParentNewSpecBehaviorEnabled(const FeatureContext*) { return OffsetParentNewSpecBehaviorEnabled(); }

    static bool OnDeviceChangeEnabled() { return is_on_device_change_enabled_; }
    static bool OnDeviceChangeEnabled(const FeatureContext*) { return OnDeviceChangeEnabled(); }

    static bool OrientationEventEnabled() { return is_orientation_event_enabled_; }
    static bool OrientationEventEnabled(const FeatureContext*) { return OrientationEventEnabled(); }

    static bool OriginIsolationHeaderEnabled() { return is_origin_isolation_header_enabled_; }
    static bool OriginIsolationHeaderEnabled(const FeatureContext*) { return OriginIsolationHeaderEnabled(); }

    static bool OriginPolicyEnabled() { return is_origin_policy_enabled_; }
    static bool OriginPolicyEnabled(const FeatureContext*) { return OriginPolicyEnabled(); }

    static bool OverscrollCustomizationEnabled() { return is_overscroll_customization_enabled_; }
    static bool OverscrollCustomizationEnabled(const FeatureContext*) { return OverscrollCustomizationEnabled(); }

    static bool PagePopupEnabled() { return is_page_popup_enabled_; }
    static bool PagePopupEnabled(const FeatureContext*) { return PagePopupEnabled(); }

    static bool PaintUnderInvalidationCheckingEnabled() { return is_paint_under_invalidation_checking_enabled_; }
    static bool PaintUnderInvalidationCheckingEnabled(const FeatureContext*) { return PaintUnderInvalidationCheckingEnabled(); }

    static bool ParallelPrimaryFontEnabled()
    {
        if (!ParallelTextShapingEnabled())
            return false;
        return is_parallel_primary_font_enabled_;
    }
    static bool ParallelPrimaryFontEnabled(const FeatureContext*) { return ParallelPrimaryFontEnabled(); }

    static bool ParallelTextShapingEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_parallel_text_shaping_enabled_;
    }
    static bool ParallelTextShapingEnabled(const FeatureContext*) { return ParallelTextShapingEnabled(); }

    static bool PasswordRevealEnabled() { return is_password_reveal_enabled_; }
    static bool PasswordRevealEnabled(const FeatureContext*) { return PasswordRevealEnabled(); }

    static bool PaymentAppEnabled()
    {
        if (!PaymentRequestEnabled())
            return false;
        return is_payment_app_enabled_;
    }
    static bool PaymentAppEnabled(const FeatureContext*) { return PaymentAppEnabled(); }

    static bool PaymentMethodChangeEventEnabled()
    {
        if (!PaymentRequestEnabled())
            return false;
        return is_payment_method_change_event_enabled_;
    }
    static bool PaymentMethodChangeEventEnabled(const FeatureContext*) { return PaymentMethodChangeEventEnabled(); }

    static bool PaymentRequestEnabled() { return is_payment_request_enabled_; }
    static bool PaymentRequestEnabled(const FeatureContext*) { return PaymentRequestEnabled(); }

    static bool PaymentRequestMerchantValidationEventEnabled() { return is_payment_request_merchant_validation_event_enabled_; }
    static bool PaymentRequestMerchantValidationEventEnabled(const FeatureContext*) { return PaymentRequestMerchantValidationEventEnabled(); }

    static bool PercentBasedScrollingEnabled() { return is_percent_based_scrolling_enabled_; }
    static bool PercentBasedScrollingEnabled(const FeatureContext*) { return PercentBasedScrollingEnabled(); }

    static bool PerformanceManagerInstrumentationEnabled() { return is_performance_manager_instrumentation_enabled_; }
    static bool PerformanceManagerInstrumentationEnabled(const FeatureContext*) { return PerformanceManagerInstrumentationEnabled(); }

    static bool PeriodicBackgroundSyncEnabled() { return is_periodic_background_sync_enabled_; }
    static bool PeriodicBackgroundSyncEnabled(const FeatureContext*) { return PeriodicBackgroundSyncEnabled(); }

    static bool PermissionsEnabled() { return is_permissions_enabled_; }
    static bool PermissionsEnabled(const FeatureContext*) { return PermissionsEnabled(); }

    static bool PermissionsRequestRevokeEnabled() { return is_permissions_request_revoke_enabled_; }
    static bool PermissionsRequestRevokeEnabled(const FeatureContext*) { return PermissionsRequestRevokeEnabled(); }

    static bool PictureInPictureEnabled() { return is_picture_in_picture_enabled_; }
    static bool PictureInPictureEnabled(const FeatureContext*) { return PictureInPictureEnabled(); }

    static bool PictureInPictureAPIEnabled() { return is_picture_in_picture_api_enabled_; }
    static bool PictureInPictureAPIEnabled(const FeatureContext*) { return PictureInPictureAPIEnabled(); }

    static bool PreciseMemoryInfoEnabled() { return is_precise_memory_info_enabled_; }
    static bool PreciseMemoryInfoEnabled(const FeatureContext*) { return PreciseMemoryInfoEnabled(); }

    static bool PreferNonCompositedScrollingEnabled() { return is_prefer_non_composited_scrolling_enabled_; }
    static bool PreferNonCompositedScrollingEnabled(const FeatureContext*) { return PreferNonCompositedScrollingEnabled(); }

    static bool PrefersColorSchemeClientHintHeaderEnabled() { return is_prefers_color_scheme_client_hint_header_enabled_; }
    static bool PrefersColorSchemeClientHintHeaderEnabled(const FeatureContext*) { return PrefersColorSchemeClientHintHeaderEnabled(); }

    static bool PrefersReducedDataEnabled() { return is_prefers_reduced_data_enabled_; }
    static bool PrefersReducedDataEnabled(const FeatureContext*) { return PrefersReducedDataEnabled(); }

    static bool PrefersReducedMotionClientHintHeaderEnabled() { return is_prefers_reduced_motion_client_hint_header_enabled_; }
    static bool PrefersReducedMotionClientHintHeaderEnabled(const FeatureContext*) { return PrefersReducedMotionClientHintHeaderEnabled(); }

    static bool PrefixedStorageInfoEnabled() { return is_prefixed_storage_info_enabled_; }
    static bool PrefixedStorageInfoEnabled(const FeatureContext*) { return PrefixedStorageInfoEnabled(); }

    static bool PrefixedVideoFullscreenEnabled() { return is_prefixed_video_fullscreen_enabled_; }
    static bool PrefixedVideoFullscreenEnabled(const FeatureContext*) { return PrefixedVideoFullscreenEnabled(); }

    static bool Prerender2Enabled() { return is_prerender_2_enabled_; }
    static bool Prerender2Enabled(const FeatureContext*) { return Prerender2Enabled(); }

    static bool PresentationEnabled() { return is_presentation_enabled_; }
    static bool PresentationEnabled(const FeatureContext*) { return PresentationEnabled(); }

    static bool PriorityHintsEnabled() { return is_priority_hints_enabled_; }
    static bool PriorityHintsEnabled(const FeatureContext*) { return PriorityHintsEnabled(); }

    static bool PrivateNetworkAccessPermissionPromptEnabled() { return is_private_network_access_permission_prompt_enabled_; }
    static bool PrivateNetworkAccessPermissionPromptEnabled(const FeatureContext*) { return PrivateNetworkAccessPermissionPromptEnabled(); }

    static bool PushMessagingEnabled() { return is_push_messaging_enabled_; }
    static bool PushMessagingEnabled(const FeatureContext*) { return PushMessagingEnabled(); }

    static bool PushMessagingSubscriptionChangeEnabled() { return is_push_messaging_subscription_change_enabled_; }
    static bool PushMessagingSubscriptionChangeEnabled(const FeatureContext*) { return PushMessagingSubscriptionChangeEnabled(); }

    static bool QuickIntensiveWakeUpThrottlingAfterLoadingEnabled() { return is_quick_intensive_wake_up_throttling_after_loading_enabled_; }
    static bool QuickIntensiveWakeUpThrottlingAfterLoadingEnabled(const FeatureContext*) { return QuickIntensiveWakeUpThrottlingAfterLoadingEnabled(); }

    static bool QuotaChangeEnabled() { return is_quota_change_enabled_; }
    static bool QuotaChangeEnabled(const FeatureContext*) { return QuotaChangeEnabled(); }

    static bool ReduceUserAgentMinorVersionEnabled() { return is_reduce_user_agent_minor_version_enabled_; }
    static bool ReduceUserAgentMinorVersionEnabled(const FeatureContext*) { return ReduceUserAgentMinorVersionEnabled(); }

    static bool ReduceUserAgentPlatformOsCpuEnabled()
    {
        if (!ReduceUserAgentMinorVersionEnabled())
            return false;
        return is_reduce_user_agent_platform_os_cpu_enabled_;
    }
    static bool ReduceUserAgentPlatformOsCpuEnabled(const FeatureContext*) { return ReduceUserAgentPlatformOsCpuEnabled(); }

    static bool RegionCaptureEnabled() { return is_region_capture_enabled_; }
    static bool RegionCaptureEnabled(const FeatureContext*) { return RegionCaptureEnabled(); }

    static bool RemotePlaybackEnabled() { return is_remote_playback_enabled_; }
    static bool RemotePlaybackEnabled(const FeatureContext*) { return RemotePlaybackEnabled(); }

    static bool RemotePlaybackBackendEnabled() { return is_remote_playback_backend_enabled_; }
    static bool RemotePlaybackBackendEnabled(const FeatureContext*) { return RemotePlaybackBackendEnabled(); }

    static bool RemoveMobileViewportDoubleTapEnabled() { return is_remove_mobile_viewport_double_tap_enabled_; }
    static bool RemoveMobileViewportDoubleTapEnabled(const FeatureContext*) { return RemoveMobileViewportDoubleTapEnabled(); }

    static bool RenderBlockingStatusEnabled() { return is_render_blocking_status_enabled_; }
    static bool RenderBlockingStatusEnabled(const FeatureContext*) { return RenderBlockingStatusEnabled(); }

    static bool RenderPriorityAttributeEnabled() { return is_render_priority_attribute_enabled_; }
    static bool RenderPriorityAttributeEnabled(const FeatureContext*) { return RenderPriorityAttributeEnabled(); }

    static bool ResourceTimingResponseStatusEnabled() { return is_resource_timing_response_status_enabled_; }
    static bool ResourceTimingResponseStatusEnabled(const FeatureContext*) { return ResourceTimingResponseStatusEnabled(); }

    static bool RestrictGamepadAccessEnabled() { return is_restrict_gamepad_access_enabled_; }
    static bool RestrictGamepadAccessEnabled(const FeatureContext*) { return RestrictGamepadAccessEnabled(); }

    static bool RTCRtpHeaderExtensionControlEnabled() { return is_rtc_rtp_header_extension_control_enabled_; }
    static bool RTCRtpHeaderExtensionControlEnabled(const FeatureContext*) { return RTCRtpHeaderExtensionControlEnabled(); }

    static bool RTCSvcScalabilityModeEnabled() { return is_rtc_svc_scalability_mode_enabled_; }
    static bool RTCSvcScalabilityModeEnabled(const FeatureContext*) { return RTCSvcScalabilityModeEnabled(); }

    static bool SanitizerAPIEnabled() { return is_sanitizer_api_enabled_; }
    static bool SanitizerAPIEnabled(const FeatureContext*) { return SanitizerAPIEnabled(); }

    static bool SanitizerAPIv0Enabled()
    {
        if (SanitizerAPIEnabled())
            return true;
        return is_sanitizer_api_v_0_enabled_;
    }
    static bool SanitizerAPIv0Enabled(const FeatureContext*) { return SanitizerAPIv0Enabled(); }

    static bool ScopedCustomElementRegistryEnabled() { return is_scoped_custom_element_registry_enabled_; }
    static bool ScopedCustomElementRegistryEnabled(const FeatureContext*) { return ScopedCustomElementRegistryEnabled(); }

    static bool ScriptedSpeechRecognitionEnabled() { return is_scripted_speech_recognition_enabled_; }
    static bool ScriptedSpeechRecognitionEnabled(const FeatureContext*) { return ScriptedSpeechRecognitionEnabled(); }

    static bool ScriptedSpeechSynthesisEnabled() { return is_scripted_speech_synthesis_enabled_; }
    static bool ScriptedSpeechSynthesisEnabled(const FeatureContext*) { return ScriptedSpeechSynthesisEnabled(); }

    static bool ScriptElementSupportsEnabled() { return is_script_element_supports_enabled_; }
    static bool ScriptElementSupportsEnabled(const FeatureContext*) { return ScriptElementSupportsEnabled(); }

    static bool ScrollbarWidthEnabled() { return is_scrollbar_width_enabled_; }
    static bool ScrollbarWidthEnabled(const FeatureContext*) { return ScrollbarWidthEnabled(); }

    static bool ScrollCustomizationEnabled() { return is_scroll_customization_enabled_; }
    static bool ScrollCustomizationEnabled(const FeatureContext*) { return ScrollCustomizationEnabled(); }

    static bool ScrollEndEventsEnabled() { return is_scroll_end_events_enabled_; }
    static bool ScrollEndEventsEnabled(const FeatureContext*) { return ScrollEndEventsEnabled(); }

    static bool ScrollTimelineEnabled()
    {
        if (AnimationWorkletEnabled())
            return true;
        if (CSSScrollTimelineEnabled())
            return true;
        if (CSSViewTimelineEnabled())
            return true;
        return is_scroll_timeline_enabled_;
    }
    static bool ScrollTimelineEnabled(const FeatureContext*) { return ScrollTimelineEnabled(); }

    static bool ScrollTopLeftInteropEnabled() { return is_scroll_top_left_interop_enabled_; }
    static bool ScrollTopLeftInteropEnabled(const FeatureContext*) { return ScrollTopLeftInteropEnabled(); }

    static bool ScrollUpdateOptimizationsEnabled() { return is_scroll_update_optimizations_enabled_; }
    static bool ScrollUpdateOptimizationsEnabled(const FeatureContext*) { return ScrollUpdateOptimizationsEnabled(); }

    static bool SecureContextFixForSharedWorkersEnabled() { return is_secure_context_fix_for_shared_workers_enabled_; }
    static bool SecureContextFixForSharedWorkersEnabled(const FeatureContext*) { return SecureContextFixForSharedWorkersEnabled(); }

    static bool SecurePaymentConfirmationEnabled() { return is_secure_payment_confirmation_enabled_; }
    static bool SecurePaymentConfirmationEnabled(const FeatureContext*) { return SecurePaymentConfirmationEnabled(); }

    static bool SecurePaymentConfirmationDebugEnabled() { return is_secure_payment_confirmation_debug_enabled_; }
    static bool SecurePaymentConfirmationDebugEnabled(const FeatureContext*) { return SecurePaymentConfirmationDebugEnabled(); }

    static bool SelfBrowserSurfaceConstraintEnabled() { return is_self_browser_surface_constraint_enabled_; }
    static bool SelfBrowserSurfaceConstraintEnabled(const FeatureContext*) { return SelfBrowserSurfaceConstraintEnabled(); }

    static bool SendBeaconThrowForBlobWithNonSimpleTypeEnabled() { return is_send_beacon_throw_for_blob_with_non_simple_type_enabled_; }
    static bool SendBeaconThrowForBlobWithNonSimpleTypeEnabled(const FeatureContext*) { return SendBeaconThrowForBlobWithNonSimpleTypeEnabled(); }

    static bool SendMouseEventsDisabledFormControlsEnabled() { return is_send_mouse_events_disabled_form_controls_enabled_; }
    static bool SendMouseEventsDisabledFormControlsEnabled(const FeatureContext*) { return SendMouseEventsDisabledFormControlsEnabled(); }

    static bool SensorExtraClassesEnabled() { return is_sensor_extra_classes_enabled_; }
    static bool SensorExtraClassesEnabled(const FeatureContext*) { return SensorExtraClassesEnabled(); }

    static bool SerialEnabled() { return is_serial_enabled_; }
    static bool SerialEnabled(const FeatureContext*) { return SerialEnabled(); }

    static bool SerialPortForgetEnabled() { return is_serial_port_forget_enabled_; }
    static bool SerialPortForgetEnabled(const FeatureContext*) { return SerialPortForgetEnabled(); }

    static bool ServiceWorkerClientLifecycleStateEnabled() { return is_service_worker_client_lifecycle_state_enabled_; }
    static bool ServiceWorkerClientLifecycleStateEnabled(const FeatureContext*) { return ServiceWorkerClientLifecycleStateEnabled(); }

    static bool SharedArrayBufferEnabled() { return is_shared_array_buffer_enabled_; }
    static bool SharedArrayBufferEnabled(const FeatureContext*) { return SharedArrayBufferEnabled(); }

    static bool SharedArrayBufferOnDesktopEnabled() { return is_shared_array_buffer_on_desktop_enabled_; }
    static bool SharedArrayBufferOnDesktopEnabled(const FeatureContext*) { return SharedArrayBufferOnDesktopEnabled(); }

    static bool SharedArrayBufferUnrestrictedAccessAllowedEnabled() { return is_shared_array_buffer_unrestricted_access_allowed_enabled_; }
    static bool SharedArrayBufferUnrestrictedAccessAllowedEnabled(const FeatureContext*) { return SharedArrayBufferUnrestrictedAccessAllowedEnabled(); }

    static bool SharedAutofillEnabled() { return is_shared_autofill_enabled_; }
    static bool SharedAutofillEnabled(const FeatureContext*) { return SharedAutofillEnabled(); }

    static bool SharedWorkerEnabled() { return is_shared_worker_enabled_; }
    static bool SharedWorkerEnabled(const FeatureContext*) { return SharedWorkerEnabled(); }

    static bool SiteInitiatedMirroringEnabled() { return is_site_initiated_mirroring_enabled_; }
    static bool SiteInitiatedMirroringEnabled(const FeatureContext*) { return SiteInitiatedMirroringEnabled(); }

    static bool SkipTouchEventFilterEnabled() { return is_skip_touch_event_filter_enabled_; }
    static bool SkipTouchEventFilterEnabled(const FeatureContext*) { return SkipTouchEventFilterEnabled(); }

    static bool SoftNavigationHeuristicsEnabled()
    {
        if (!NavigationIdEnabled())
            return false;
        return is_soft_navigation_heuristics_enabled_;
    }
    static bool SoftNavigationHeuristicsEnabled(const FeatureContext*) { return SoftNavigationHeuristicsEnabled(); }

    static bool SpeculationRulesFetchFromHeaderEnabled() { return is_speculation_rules_fetch_from_header_enabled_; }
    static bool SpeculationRulesFetchFromHeaderEnabled(const FeatureContext*) { return SpeculationRulesFetchFromHeaderEnabled(); }

    static bool SpeculationRulesPrefetchWithSubresourcesEnabled() { return is_speculation_rules_prefetch_with_subresources_enabled_; }
    static bool SpeculationRulesPrefetchWithSubresourcesEnabled(const FeatureContext*) { return SpeculationRulesPrefetchWithSubresourcesEnabled(); }

    static bool SrcsetMaxDensityEnabled() { return is_srcset_max_density_enabled_; }
    static bool SrcsetMaxDensityEnabled(const FeatureContext*) { return SrcsetMaxDensityEnabled(); }

    static bool StableBlinkFeaturesEnabled() { return is_stable_blink_features_enabled_; }
    static bool StableBlinkFeaturesEnabled(const FeatureContext*) { return StableBlinkFeaturesEnabled(); }

    static bool StorageAccessAPIEnabled() { return is_storage_access_api_enabled_; }
    static bool StorageAccessAPIEnabled(const FeatureContext*) { return StorageAccessAPIEnabled(); }

    static bool StorageAccessAPIForOriginExtensionEnabled() { return is_storage_access_api_for_origin_extension_enabled_; }
    static bool StorageAccessAPIForOriginExtensionEnabled(const FeatureContext*) { return StorageAccessAPIForOriginExtensionEnabled(); }

    static bool StorageBucketsEnabled() { return is_storage_buckets_enabled_; }
    static bool StorageBucketsEnabled(const FeatureContext*) { return StorageBucketsEnabled(); }

    static bool StrictMimeTypesForWorkersEnabled() { return is_strict_mime_types_for_workers_enabled_; }
    static bool StrictMimeTypesForWorkersEnabled(const FeatureContext*) { return StrictMimeTypesForWorkersEnabled(); }

    static bool StylusHandwritingEnabled() { return is_stylus_handwriting_enabled_; }
    static bool StylusHandwritingEnabled(const FeatureContext*) { return StylusHandwritingEnabled(); }

    static bool SupportsFontFormatTechEnabled() { return is_supports_font_format_tech_enabled_; }
    static bool SupportsFontFormatTechEnabled(const FeatureContext*) { return SupportsFontFormatTechEnabled(); }

    static bool SurfaceSwitchingConstraintEnabled() { return is_surface_switching_constraint_enabled_; }
    static bool SurfaceSwitchingConstraintEnabled(const FeatureContext*) { return SurfaceSwitchingConstraintEnabled(); }

    static bool SVGTextNGEnabled()
    {
        if (!LayoutNGEnabled())
            return false;
        return is_svg_text_ng_enabled_;
    }
    static bool SVGTextNGEnabled(const FeatureContext*) { return SVGTextNGEnabled(); }

    static bool SynthesizedKeyboardEventsForAccessibilityActionsEnabled() { return is_synthesized_keyboard_events_for_accessibility_actions_enabled_; }
    static bool SynthesizedKeyboardEventsForAccessibilityActionsEnabled(const FeatureContext*) { return SynthesizedKeyboardEventsForAccessibilityActionsEnabled(); }

    static bool SystemAudioConstraintEnabled() { return is_system_audio_constraint_enabled_; }
    static bool SystemAudioConstraintEnabled(const FeatureContext*) { return SystemAudioConstraintEnabled(); }

    static bool SystemWakeLockEnabled() { return is_system_wake_lock_enabled_; }
    static bool SystemWakeLockEnabled(const FeatureContext*) { return SystemWakeLockEnabled(); }

    static bool TestFeatureEnabled() { return is_test_feature_enabled_; }
    static bool TestFeatureEnabled(const FeatureContext*) { return TestFeatureEnabled(); }

    static bool TestFeatureDependentEnabled()
    {
        if (!TestFeatureImpliedEnabled())
            return false;
        return is_test_feature_dependent_enabled_;
    }
    static bool TestFeatureDependentEnabled(const FeatureContext*) { return TestFeatureDependentEnabled(); }

    static bool TestFeatureImpliedEnabled()
    {
        if (TestFeatureEnabled())
            return true;
        return is_test_feature_implied_enabled_;
    }
    static bool TestFeatureImpliedEnabled(const FeatureContext*) { return TestFeatureImpliedEnabled(); }

    static bool TextDecoratingBoxEnabled() { return is_text_decorating_box_enabled_; }
    static bool TextDecoratingBoxEnabled(const FeatureContext*) { return TextDecoratingBoxEnabled(); }

    static bool TextDetectorEnabled() { return is_text_detector_enabled_; }
    static bool TextDetectorEnabled(const FeatureContext*) { return TextDetectorEnabled(); }

    static bool TextFragmentAPIEnabled() { return is_text_fragment_api_enabled_; }
    static bool TextFragmentAPIEnabled(const FeatureContext*) { return TextFragmentAPIEnabled(); }

    static bool TextFragmentTapOpensContextMenuEnabled() { return is_text_fragment_tap_opens_context_menu_enabled_; }
    static bool TextFragmentTapOpensContextMenuEnabled(const FeatureContext*) { return TextFragmentTapOpensContextMenuEnabled(); }

    static bool ThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframesEnabled() { return is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_; }
    static bool ThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframesEnabled(const FeatureContext*) { return ThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframesEnabled(); }

    static bool TimerThrottlingForBackgroundTabsEnabled() { return is_timer_throttling_for_background_tabs_enabled_; }
    static bool TimerThrottlingForBackgroundTabsEnabled(const FeatureContext*) { return TimerThrottlingForBackgroundTabsEnabled(); }

    static bool TimeZoneChangeEventEnabled() { return is_time_zone_change_event_enabled_; }
    static bool TimeZoneChangeEventEnabled(const FeatureContext*) { return TimeZoneChangeEventEnabled(); }

    static bool TouchActionEffectiveAtPointerDownEnabled() { return is_touch_action_effective_at_pointer_down_enabled_; }
    static bool TouchActionEffectiveAtPointerDownEnabled(const FeatureContext*) { return TouchActionEffectiveAtPointerDownEnabled(); }

    static bool TouchDragAndContextMenuEnabled()
    {
        if (TouchDragOnShortPressEnabled())
            return true;
        return is_touch_drag_and_context_menu_enabled_;
    }
    static bool TouchDragAndContextMenuEnabled(const FeatureContext*) { return TouchDragAndContextMenuEnabled(); }

    static bool TouchDragOnShortPressEnabled() { return is_touch_drag_on_short_press_enabled_; }
    static bool TouchDragOnShortPressEnabled(const FeatureContext*) { return TouchDragOnShortPressEnabled(); }

    static bool TranslateServiceEnabled() { return is_translate_service_enabled_; }
    static bool TranslateServiceEnabled(const FeatureContext*) { return TranslateServiceEnabled(); }

    static bool TrustedTypeBeforePolicyCreationEventEnabled() { return is_trusted_type_before_policy_creation_event_enabled_; }
    static bool TrustedTypeBeforePolicyCreationEventEnabled(const FeatureContext*) { return TrustedTypeBeforePolicyCreationEventEnabled(); }

    static bool TrustedTypesUseCodeLikeEnabled() { return is_trusted_types_use_code_like_enabled_; }
    static bool TrustedTypesUseCodeLikeEnabled(const FeatureContext*) { return TrustedTypesUseCodeLikeEnabled(); }

    static bool TrustTokensAlwaysAllowIssuanceEnabled() { return is_trust_tokens_always_allow_issuance_enabled_; }
    static bool TrustTokensAlwaysAllowIssuanceEnabled(const FeatureContext*) { return TrustTokensAlwaysAllowIssuanceEnabled(); }

    static bool UnclosedFormControlIsInvalidEnabled() { return is_unclosed_form_control_is_invalid_enabled_; }
    static bool UnclosedFormControlIsInvalidEnabled(const FeatureContext*) { return UnclosedFormControlIsInvalidEnabled(); }

    static bool UnexposedTaskIdsEnabled() { return is_unexposed_task_ids_enabled_; }
    static bool UnexposedTaskIdsEnabled(const FeatureContext*) { return UnexposedTaskIdsEnabled(); }

    static bool URLPatternCompareComponentEnabled() { return is_url_pattern_compare_component_enabled_; }
    static bool URLPatternCompareComponentEnabled(const FeatureContext*) { return URLPatternCompareComponentEnabled(); }

    static bool UserActivationSameOriginVisibilityEnabled() { return is_user_activation_same_origin_visibility_enabled_; }
    static bool UserActivationSameOriginVisibilityEnabled(const FeatureContext*) { return UserActivationSameOriginVisibilityEnabled(); }

    static bool UserAgentClientHintEnabled() { return is_user_agent_client_hint_enabled_; }
    static bool UserAgentClientHintEnabled(const FeatureContext*) { return UserAgentClientHintEnabled(); }

    static bool V8IdleTasksEnabled() { return is_v8_idle_tasks_enabled_; }
    static bool V8IdleTasksEnabled(const FeatureContext*) { return V8IdleTasksEnabled(); }

    static bool VariableCOLRV1Enabled() { return is_variable_colrv_1_enabled_; }
    static bool VariableCOLRV1Enabled(const FeatureContext*) { return VariableCOLRV1Enabled(); }

    static bool VideoAutoFullscreenEnabled() { return is_video_auto_fullscreen_enabled_; }
    static bool VideoAutoFullscreenEnabled(const FeatureContext*) { return VideoAutoFullscreenEnabled(); }

    static bool VideoFullscreenOrientationLockEnabled() { return is_video_fullscreen_orientation_lock_enabled_; }
    static bool VideoFullscreenOrientationLockEnabled(const FeatureContext*) { return VideoFullscreenOrientationLockEnabled(); }

    static bool VideoPlaybackQualityEnabled() { return is_video_playback_quality_enabled_; }
    static bool VideoPlaybackQualityEnabled(const FeatureContext*) { return VideoPlaybackQualityEnabled(); }

    static bool VideoRotateToFullscreenEnabled() { return is_video_rotate_to_fullscreen_enabled_; }
    static bool VideoRotateToFullscreenEnabled(const FeatureContext*) { return VideoRotateToFullscreenEnabled(); }

    static bool VideoTrackGeneratorEnabled() { return is_video_track_generator_enabled_; }
    static bool VideoTrackGeneratorEnabled(const FeatureContext*) { return VideoTrackGeneratorEnabled(); }

    static bool VideoTrackGeneratorInWindowEnabled() { return is_video_track_generator_in_window_enabled_; }
    static bool VideoTrackGeneratorInWindowEnabled(const FeatureContext*) { return VideoTrackGeneratorInWindowEnabled(); }

    static bool VideoTrackGeneratorInWorkerEnabled() { return is_video_track_generator_in_worker_enabled_; }
    static bool VideoTrackGeneratorInWorkerEnabled(const FeatureContext*) { return VideoTrackGeneratorInWorkerEnabled(); }

    static bool VideoWakeLockOptimisationHiddenMutedEnabled() { return is_video_wake_lock_optimisation_hidden_muted_enabled_; }
    static bool VideoWakeLockOptimisationHiddenMutedEnabled(const FeatureContext*) { return VideoWakeLockOptimisationHiddenMutedEnabled(); }

    static bool ViewportHeightClientHintHeaderEnabled() { return is_viewport_height_client_hint_header_enabled_; }
    static bool ViewportHeightClientHintHeaderEnabled(const FeatureContext*) { return ViewportHeightClientHintHeaderEnabled(); }

    static bool ViewportMetaInteractiveWidgetPropertyEnabled() { return is_viewport_meta_interactive_widget_property_enabled_; }
    static bool ViewportMetaInteractiveWidgetPropertyEnabled(const FeatureContext*) { return ViewportMetaInteractiveWidgetPropertyEnabled(); }

    static bool ViewportSegmentsEnabled() { return is_viewport_segments_enabled_; }
    static bool ViewportSegmentsEnabled(const FeatureContext*) { return ViewportSegmentsEnabled(); }

    static bool VisibilityCollapseColumnEnabled() { return is_visibility_collapse_column_enabled_; }
    static bool VisibilityCollapseColumnEnabled(const FeatureContext*) { return VisibilityCollapseColumnEnabled(); }

    static bool VisibilityStateEntryEnabled() { return is_visibility_state_entry_enabled_; }
    static bool VisibilityStateEntryEnabled(const FeatureContext*) { return VisibilityStateEntryEnabled(); }

    static bool WakeLockEnabled()
    {
        if (SystemWakeLockEnabled())
            return true;
        return is_wake_lock_enabled_;
    }
    static bool WakeLockEnabled(const FeatureContext*) { return WakeLockEnabled(); }

    static bool WarnOnContentVisibilityRenderAccessEnabled() { return is_warn_on_content_visibility_render_access_enabled_; }
    static bool WarnOnContentVisibilityRenderAccessEnabled(const FeatureContext*) { return WarnOnContentVisibilityRenderAccessEnabled(); }

    static bool WebAnimationsAPIEnabled()
    {
        if (AnimationWorkletEnabled())
            return true;
        return is_web_animations_api_enabled_;
    }
    static bool WebAnimationsAPIEnabled(const FeatureContext*) { return WebAnimationsAPIEnabled(); }

    static bool WebAnimationsSVGEnabled() { return is_web_animations_svg_enabled_; }
    static bool WebAnimationsSVGEnabled(const FeatureContext*) { return WebAnimationsSVGEnabled(); }

    static bool WebAppsLockScreenEnabled() { return is_web_apps_lock_screen_enabled_; }
    static bool WebAppsLockScreenEnabled(const FeatureContext*) { return WebAppsLockScreenEnabled(); }

    static bool WebAppTabStripEnabled() { return is_web_app_tab_strip_enabled_; }
    static bool WebAppTabStripEnabled(const FeatureContext*) { return WebAppTabStripEnabled(); }

    static bool WebAppTranslationsEnabled() { return is_web_app_translations_enabled_; }
    static bool WebAppTranslationsEnabled(const FeatureContext*) { return WebAppTranslationsEnabled(); }

    static bool WebAssemblyCSPEnabled() { return is_web_assembly_csp_enabled_; }
    static bool WebAssemblyCSPEnabled(const FeatureContext*) { return WebAssemblyCSPEnabled(); }

    static bool WebAuthEnabled() { return is_web_auth_enabled_; }
    static bool WebAuthEnabled(const FeatureContext*) { return WebAuthEnabled(); }

    static bool WebAuthAuthenticatorAttachmentEnabled() { return is_web_auth_authenticator_attachment_enabled_; }
    static bool WebAuthAuthenticatorAttachmentEnabled(const FeatureContext*) { return WebAuthAuthenticatorAttachmentEnabled(); }

    static bool WebAuthenticationConditionalUIEnabled() { return is_web_authentication_conditional_ui_enabled_; }
    static bool WebAuthenticationConditionalUIEnabled(const FeatureContext*) { return WebAuthenticationConditionalUIEnabled(); }

    static bool WebAuthenticationDevicePublicKeyEnabled() { return is_web_authentication_device_public_key_enabled_; }
    static bool WebAuthenticationDevicePublicKeyEnabled(const FeatureContext*) { return WebAuthenticationDevicePublicKeyEnabled(); }

    static bool WebAuthenticationLargeBlobExtensionEnabled() { return is_web_authentication_large_blob_extension_enabled_; }
    static bool WebAuthenticationLargeBlobExtensionEnabled(const FeatureContext*) { return WebAuthenticationLargeBlobExtensionEnabled(); }

    static bool WebAuthenticationRemoteDesktopSupportEnabled() { return is_web_authentication_remote_desktop_support_enabled_; }
    static bool WebAuthenticationRemoteDesktopSupportEnabled(const FeatureContext*) { return WebAuthenticationRemoteDesktopSupportEnabled(); }

    static bool WebBluetoothEnabled() { return is_web_bluetooth_enabled_; }
    static bool WebBluetoothEnabled(const FeatureContext*) { return WebBluetoothEnabled(); }

    static bool WebBluetoothGetDevicesEnabled() { return is_web_bluetooth_get_devices_enabled_; }
    static bool WebBluetoothGetDevicesEnabled(const FeatureContext*) { return WebBluetoothGetDevicesEnabled(); }

    static bool WebBluetoothScanningEnabled() { return is_web_bluetooth_scanning_enabled_; }
    static bool WebBluetoothScanningEnabled(const FeatureContext*) { return WebBluetoothScanningEnabled(); }

    static bool WebBluetoothWatchAdvertisementsEnabled() { return is_web_bluetooth_watch_advertisements_enabled_; }
    static bool WebBluetoothWatchAdvertisementsEnabled(const FeatureContext*) { return WebBluetoothWatchAdvertisementsEnabled(); }

    static bool WebCodecsDequeueEventEnabled() { return is_webcodecs_dequeue_event_enabled_; }
    static bool WebCodecsDequeueEventEnabled(const FeatureContext*) { return WebCodecsDequeueEventEnabled(); }

    static bool WebGLColorManagementEnabled() { return is_webgl_color_management_enabled_; }
    static bool WebGLColorManagementEnabled(const FeatureContext*) { return WebGLColorManagementEnabled(); }

    static bool WebGLDeveloperExtensionsEnabled() { return is_webgl_developer_extensions_enabled_; }
    static bool WebGLDeveloperExtensionsEnabled(const FeatureContext*) { return WebGLDeveloperExtensionsEnabled(); }

    static bool WebGLDraftExtensionsEnabled() { return is_webgl_draft_extensions_enabled_; }
    static bool WebGLDraftExtensionsEnabled(const FeatureContext*) { return WebGLDraftExtensionsEnabled(); }

    static bool WebGLImageChromiumEnabled() { return is_webgl_image_chromium_enabled_; }
    static bool WebGLImageChromiumEnabled(const FeatureContext*) { return WebGLImageChromiumEnabled(); }

    static bool WebGPUDeveloperFeaturesEnabled() { return is_webgpu_developer_features_enabled_; }
    static bool WebGPUDeveloperFeaturesEnabled(const FeatureContext*) { return WebGPUDeveloperFeaturesEnabled(); }

    static bool WebGPUImportTextureEnabled() { return is_webgpu_import_texture_enabled_; }
    static bool WebGPUImportTextureEnabled(const FeatureContext*) { return WebGPUImportTextureEnabled(); }

    static bool WebHIDEnabled() { return is_web_hid_enabled_; }
    static bool WebHIDEnabled(const FeatureContext*) { return WebHIDEnabled(); }

    static bool WebHIDExclusionFiltersOptionEnabled() { return is_web_hid_exclusion_filters_option_enabled_; }
    static bool WebHIDExclusionFiltersOptionEnabled(const FeatureContext*) { return WebHIDExclusionFiltersOptionEnabled(); }

    static bool WebHIDOnServiceWorkersEnabled()
    {
        if (!WebHIDEnabled())
            return false;
        return is_web_hid_on_service_workers_enabled_;
    }
    static bool WebHIDOnServiceWorkersEnabled(const FeatureContext*) { return WebHIDOnServiceWorkersEnabled(); }

    static bool WebKitScrollbarStylingEnabled() { return is_web_kit_scrollbar_styling_enabled_; }
    static bool WebKitScrollbarStylingEnabled(const FeatureContext*) { return WebKitScrollbarStylingEnabled(); }

    static bool WebNFCEnabled() { return is_web_nfc_enabled_; }
    static bool WebNFCEnabled(const FeatureContext*) { return WebNFCEnabled(); }

    static bool WebNFCMakeReadOnlyEnabled()
    {
        if (!WebNFCEnabled())
            return false;
        return is_web_nfc_make_read_only_enabled_;
    }
    static bool WebNFCMakeReadOnlyEnabled(const FeatureContext*) { return WebNFCMakeReadOnlyEnabled(); }

    static bool WebOTPEnabled() { return is_web_otp_enabled_; }
    static bool WebOTPEnabled(const FeatureContext*) { return WebOTPEnabled(); }

    static bool WebOTPAssertionFeaturePolicyEnabled()
    {
        if (!WebOTPEnabled())
            return false;
        return is_web_otp_assertion_feature_policy_enabled_;
    }
    static bool WebOTPAssertionFeaturePolicyEnabled(const FeatureContext*) { return WebOTPAssertionFeaturePolicyEnabled(); }

    static bool WebShareEnabled() { return is_web_share_enabled_; }
    static bool WebShareEnabled(const FeatureContext*) { return WebShareEnabled(); }

    static bool WebSocketStreamEnabled() { return is_websocket_stream_enabled_; }
    static bool WebSocketStreamEnabled(const FeatureContext*) { return WebSocketStreamEnabled(); }

    static bool WebUSBEnabled() { return is_web_usb_enabled_; }
    static bool WebUSBEnabled(const FeatureContext*) { return WebUSBEnabled(); }

    static bool WebUsbDeviceForgetEnabled() { return is_web_usb_device_forget_enabled_; }
    static bool WebUsbDeviceForgetEnabled(const FeatureContext*) { return WebUsbDeviceForgetEnabled(); }

    static bool WebUSBOnDedicatedWorkersEnabled()
    {
        if (!WebUSBEnabled())
            return false;
        return is_web_usb_on_dedicated_workers_enabled_;
    }
    static bool WebUSBOnDedicatedWorkersEnabled(const FeatureContext*) { return WebUSBOnDedicatedWorkersEnabled(); }

    static bool WebUSBOnServiceWorkersEnabled()
    {
        if (!WebUSBEnabled())
            return false;
        return is_web_usb_on_service_workers_enabled_;
    }
    static bool WebUSBOnServiceWorkersEnabled(const FeatureContext*) { return WebUSBOnServiceWorkersEnabled(); }

    static bool WebVTTRegionsEnabled() { return is_web_vtt_regions_enabled_; }
    static bool WebVTTRegionsEnabled(const FeatureContext*) { return WebVTTRegionsEnabled(); }

    static bool WebXREnabled() { return is_web_xr_enabled_; }
    static bool WebXREnabled(const FeatureContext*) { return WebXREnabled(); }

    static bool WebXRAnchorsEnabled()
    {
        if (!WebXRARModuleEnabled())
            return false;
        if (!WebXRHitTestEnabled())
            return false;
        return is_web_xr_anchors_enabled_;
    }
    static bool WebXRAnchorsEnabled(const FeatureContext*) { return WebXRAnchorsEnabled(); }

    static bool WebXRARModuleEnabled()
    {
        if (!WebXREnabled())
            return false;
        return is_web_xr_ar_module_enabled_;
    }
    static bool WebXRARModuleEnabled(const FeatureContext*) { return WebXRARModuleEnabled(); }

    static bool WebXRCameraAccessEnabled()
    {
        if (!WebXRARModuleEnabled())
            return false;
        return is_web_xr_camera_access_enabled_;
    }
    static bool WebXRCameraAccessEnabled(const FeatureContext*) { return WebXRCameraAccessEnabled(); }

    static bool WebXRHandInputEnabled()
    {
        if (!WebXRARModuleEnabled())
            return false;
        return is_web_xr_hand_input_enabled_;
    }
    static bool WebXRHandInputEnabled(const FeatureContext*) { return WebXRHandInputEnabled(); }

    static bool WebXRHitTestEnabled()
    {
        if (!WebXRARModuleEnabled())
            return false;
        return is_web_xr_hit_test_enabled_;
    }
    static bool WebXRHitTestEnabled(const FeatureContext*) { return WebXRHitTestEnabled(); }

    static bool WebXRHitTestEntityTypesEnabled()
    {
        if (!WebXRHitTestEnabled())
            return false;
        return is_web_xr_hit_test_entity_types_enabled_;
    }
    static bool WebXRHitTestEntityTypesEnabled(const FeatureContext*) { return WebXRHitTestEntityTypesEnabled(); }

    static bool WebXRLightEstimationEnabled()
    {
        if (!WebXRARModuleEnabled())
            return false;
        return is_web_xr_light_estimation_enabled_;
    }
    static bool WebXRLightEstimationEnabled(const FeatureContext*) { return WebXRLightEstimationEnabled(); }

    static bool WebXRViewportScaleEnabled()
    {
        if (!WebXRARModuleEnabled())
            return false;
        return is_web_xr_viewport_scale_enabled_;
    }
    static bool WebXRViewportScaleEnabled(const FeatureContext*) { return WebXRViewportScaleEnabled(); }

    static bool WGIGamepadTriggerRumbleEnabled() { return is_wgi_gamepad_trigger_rumble_enabled_; }
    static bool WGIGamepadTriggerRumbleEnabled(const FeatureContext*) { return WGIGamepadTriggerRumbleEnabled(); }

    static bool WindowDefaultStatusEnabled() { return is_window_default_status_enabled_; }
    static bool WindowDefaultStatusEnabled(const FeatureContext*) { return WindowDefaultStatusEnabled(); }

    static bool WindowOpenNewPopupBehaviorEnabled() { return is_window_open_new_popup_behavior_enabled_; }
    static bool WindowOpenNewPopupBehaviorEnabled(const FeatureContext*) { return WindowOpenNewPopupBehaviorEnabled(); }

    static bool WindowPlacementEnabled() { return is_window_placement_enabled_; }
    static bool WindowPlacementEnabled(const FeatureContext*) { return WindowPlacementEnabled(); }

    static bool WindowPlacementEnhancedScreenLabelsEnabled() { return is_window_placement_enhanced_screen_labels_enabled_; }
    static bool WindowPlacementEnhancedScreenLabelsEnabled(const FeatureContext*) { return WindowPlacementEnhancedScreenLabelsEnabled(); }

    static bool WindowPlacementFullscreenOnScreensChangeEnabled()
    {
        if (!WindowPlacementEnabled())
            return false;
        return is_window_placement_fullscreen_on_screens_change_enabled_;
    }
    static bool WindowPlacementFullscreenOnScreensChangeEnabled(const FeatureContext*) { return WindowPlacementFullscreenOnScreensChangeEnabled(); }

    static bool ZeroCopyTabCaptureEnabled() { return is_zero_copy_tab_capture_enabled_; }
    static bool ZeroCopyTabCaptureEnabled(const FeatureContext*) { return ZeroCopyTabCaptureEnabled(); }
    // Origin-trial-enabled features:
    //
    // These features are currently part of an origin trial (see
    // https://www.chromium.org/blink/origin-trials). <feature>EnabledByRuntimeFlag()
    // can be used to test whether the feature is unconditionally enabled
    // (for example, by starting the browser with the appropriate command-line flag).
    // However, that is almost always the incorrect check. Most renderer code should
    // be calling <feature>Enabled(const FeatureContext*) instead, to test if the
    // feature is enabled in a given context.

    static bool AccessibilityAriaTouchPassthroughEnabledByRuntimeFlag() { return AccessibilityAriaTouchPassthroughEnabled(nullptr); }
    static bool AccessibilityAriaTouchPassthroughEnabled(const FeatureContext*);

    static bool AdInterestGroupAPIEnabledByRuntimeFlag() { return AdInterestGroupAPIEnabled(nullptr); }
    static bool AdInterestGroupAPIEnabled(const FeatureContext*);

    static bool AnonymousIframeEnabledByRuntimeFlag() { return AnonymousIframeEnabled(nullptr); }
    static bool AnonymousIframeEnabled(const FeatureContext*);

    static bool AttributionReportingEnabledByRuntimeFlag() { return AttributionReportingEnabled(nullptr); }
    static bool AttributionReportingEnabled(const FeatureContext*);

    static bool AutoDarkModeEnabledByRuntimeFlag() { return AutoDarkModeEnabled(nullptr); }
    static bool AutoDarkModeEnabled(const FeatureContext*);

    static bool BackForwardCacheExperimentHTTPHeaderEnabledByRuntimeFlag() { return BackForwardCacheExperimentHTTPHeaderEnabled(nullptr); }
    static bool BackForwardCacheExperimentHTTPHeaderEnabled(const FeatureContext*);

    static bool BackForwardCacheNotRestoredReasonsEnabledByRuntimeFlag() { return BackForwardCacheNotRestoredReasonsEnabled(nullptr); }
    static bool BackForwardCacheNotRestoredReasonsEnabled(const FeatureContext*);

    static bool BeforeMatchEventEnabledByRuntimeFlag() { return BeforeMatchEventEnabled(nullptr); }
    static bool BeforeMatchEventEnabled(const FeatureContext*);

    static bool CacheStorageCodeCacheHintEnabledByRuntimeFlag() { return CacheStorageCodeCacheHintEnabled(nullptr); }
    static bool CacheStorageCodeCacheHintEnabled(const FeatureContext*);

    static bool ClearIdentityInCanMakePaymentEventEnabledByRuntimeFlag() { return ClearIdentityInCanMakePaymentEventEnabled(nullptr); }
    static bool ClearIdentityInCanMakePaymentEventEnabled(const FeatureContext*);

    static bool ComputePressureEnabledByRuntimeFlag() { return ComputePressureEnabled(nullptr); }
    static bool ComputePressureEnabled(const FeatureContext*);

    static bool ConditionalFocusEnabledByRuntimeFlag() { return ConditionalFocusEnabled(nullptr); }
    static bool ConditionalFocusEnabled(const FeatureContext*);

    static bool CrossOriginOpenerPolicyReportingEnabledByRuntimeFlag() { return CrossOriginOpenerPolicyReportingEnabled(nullptr); }
    static bool CrossOriginOpenerPolicyReportingEnabled(const FeatureContext*);

    static bool DeviceAttributesEnabledByRuntimeFlag() { return DeviceAttributesEnabled(nullptr); }
    static bool DeviceAttributesEnabled(const FeatureContext*);

    static bool DigitalGoodsEnabledByRuntimeFlag() { return DigitalGoodsEnabled(nullptr); }
    static bool DigitalGoodsEnabled(const FeatureContext*);

    static bool DisableDifferentOriginSubframeDialogSuppressionEnabledByRuntimeFlag() { return DisableDifferentOriginSubframeDialogSuppressionEnabled(nullptr); }
    static bool DisableDifferentOriginSubframeDialogSuppressionEnabled(const FeatureContext*);

    static bool DisableHardwareNoiseSuppressionEnabledByRuntimeFlag() { return DisableHardwareNoiseSuppressionEnabled(nullptr); }
    static bool DisableHardwareNoiseSuppressionEnabled(const FeatureContext*);

    static bool DocumentPolicyNegotiationEnabledByRuntimeFlag() { return DocumentPolicyNegotiationEnabled(nullptr); }
    static bool DocumentPolicyNegotiationEnabled(const FeatureContext*);

    static bool EarlyHintsPreloadForNavigationOptInEnabledByRuntimeFlag() { return EarlyHintsPreloadForNavigationOptInEnabled(nullptr); }
    static bool EarlyHintsPreloadForNavigationOptInEnabled(const FeatureContext*);

    static bool FencedFramesEnabledByRuntimeFlag() { return FencedFramesEnabled(nullptr); }
    static bool FencedFramesEnabled(const FeatureContext*);

    static bool FileHandlingEnabledByRuntimeFlag() { return FileHandlingEnabled(nullptr); }
    static bool FileHandlingEnabled(const FeatureContext*);

    static bool FileHandlingIconsEnabledByRuntimeFlag() { return FileHandlingIconsEnabled(nullptr); }
    static bool FileHandlingIconsEnabled(const FeatureContext*);

    static bool FledgeEnabledByRuntimeFlag() { return FledgeEnabled(nullptr); }
    static bool FledgeEnabled(const FeatureContext*);

    static bool FocusgroupEnabledByRuntimeFlag() { return FocusgroupEnabled(nullptr); }
    static bool FocusgroupEnabled(const FeatureContext*);

    static bool HrefTranslateEnabledByRuntimeFlag() { return HrefTranslateEnabled(nullptr); }
    static bool HrefTranslateEnabled(const FeatureContext*);

    static bool HTMLPopupAttributeEnabledByRuntimeFlag() { return HTMLPopupAttributeEnabled(nullptr); }
    static bool HTMLPopupAttributeEnabled(const FeatureContext*);

    static bool MediaSourceExtensionsForWebCodecsEnabledByRuntimeFlag() { return MediaSourceExtensionsForWebCodecsEnabled(nullptr); }
    static bool MediaSourceExtensionsForWebCodecsEnabled(const FeatureContext*);

    static bool MediaSourceInWorkersEnabledByRuntimeFlag() { return MediaSourceInWorkersEnabled(nullptr); }
    static bool MediaSourceInWorkersEnabled(const FeatureContext*);

    static bool NotificationTriggersEnabledByRuntimeFlag() { return NotificationTriggersEnabled(nullptr); }
    static bool NotificationTriggersEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIEnabledByRuntimeFlag() { return OriginTrialsSampleAPIEnabled(nullptr); }
    static bool OriginTrialsSampleAPIEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIDependentEnabledByRuntimeFlag() { return OriginTrialsSampleAPIDependentEnabled(nullptr); }
    static bool OriginTrialsSampleAPIDependentEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIDeprecationEnabledByRuntimeFlag() { return OriginTrialsSampleAPIDeprecationEnabled(nullptr); }
    static bool OriginTrialsSampleAPIDeprecationEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIExpiryGracePeriodEnabledByRuntimeFlag() { return OriginTrialsSampleAPIExpiryGracePeriodEnabled(nullptr); }
    static bool OriginTrialsSampleAPIExpiryGracePeriodEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabledByRuntimeFlag() { return OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(nullptr); }
    static bool OriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIImpliedEnabledByRuntimeFlag() { return OriginTrialsSampleAPIImpliedEnabled(nullptr); }
    static bool OriginTrialsSampleAPIImpliedEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIInvalidOSEnabledByRuntimeFlag() { return OriginTrialsSampleAPIInvalidOSEnabled(nullptr); }
    static bool OriginTrialsSampleAPIInvalidOSEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPINavigationEnabledByRuntimeFlag() { return OriginTrialsSampleAPINavigationEnabled(nullptr); }
    static bool OriginTrialsSampleAPINavigationEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabledByRuntimeFlag() { return OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(nullptr); }
    static bool OriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIPersistentFeatureEnabledByRuntimeFlag() { return OriginTrialsSampleAPIPersistentFeatureEnabled(nullptr); }
    static bool OriginTrialsSampleAPIPersistentFeatureEnabled(const FeatureContext*);

    static bool OriginTrialsSampleAPIThirdPartyEnabledByRuntimeFlag() { return OriginTrialsSampleAPIThirdPartyEnabled(nullptr); }
    static bool OriginTrialsSampleAPIThirdPartyEnabled(const FeatureContext*);

    static bool PageFreezeOptInEnabledByRuntimeFlag() { return PageFreezeOptInEnabled(nullptr); }
    static bool PageFreezeOptInEnabled(const FeatureContext*);

    static bool PageFreezeOptOutEnabledByRuntimeFlag() { return PageFreezeOptOutEnabled(nullptr); }
    static bool PageFreezeOptOutEnabled(const FeatureContext*);

    static bool ParakeetEnabledByRuntimeFlag() { return ParakeetEnabled(nullptr); }
    static bool ParakeetEnabled(const FeatureContext*);

    static bool PartitionedCookiesEnabledByRuntimeFlag() { return PartitionedCookiesEnabled(nullptr); }
    static bool PartitionedCookiesEnabled(const FeatureContext*);

    static bool PendingBeaconAPIEnabledByRuntimeFlag() { return PendingBeaconAPIEnabled(nullptr); }
    static bool PendingBeaconAPIEnabled(const FeatureContext*);

    static bool PerMethodCanMakePaymentQuotaEnabledByRuntimeFlag() { return PerMethodCanMakePaymentQuotaEnabled(nullptr); }
    static bool PerMethodCanMakePaymentQuotaEnabled(const FeatureContext*);

    static bool PermissionsPolicyUnloadEnabledByRuntimeFlag() { return PermissionsPolicyUnloadEnabled(nullptr); }
    static bool PermissionsPolicyUnloadEnabled(const FeatureContext*);

    static bool PNaClEnabledByRuntimeFlag() { return PNaClEnabled(nullptr); }
    static bool PNaClEnabled(const FeatureContext*);

    static bool PointerLockOptionsEnabledByRuntimeFlag() { return PointerLockOptionsEnabled(nullptr); }
    static bool PointerLockOptionsEnabled(const FeatureContext*);

    static bool PortalsEnabledByRuntimeFlag() { return PortalsEnabled(nullptr); }
    static bool PortalsEnabled(const FeatureContext*);

    static bool Prerender2RelatedFeaturesEnabledByRuntimeFlag() { return Prerender2RelatedFeaturesEnabled(nullptr); }
    static bool Prerender2RelatedFeaturesEnabled(const FeatureContext*);

    static bool PrivacySandboxAdsAPIsEnabledByRuntimeFlag() { return PrivacySandboxAdsAPIsEnabled(nullptr); }
    static bool PrivacySandboxAdsAPIsEnabled(const FeatureContext*);

    static bool PrivateNetworkAccessNonSecureContextsAllowedEnabledByRuntimeFlag() { return PrivateNetworkAccessNonSecureContextsAllowedEnabled(nullptr); }
    static bool PrivateNetworkAccessNonSecureContextsAllowedEnabled(const FeatureContext*);

    static bool RtcAudioJitterBufferMaxPacketsEnabledByRuntimeFlag() { return RtcAudioJitterBufferMaxPacketsEnabled(nullptr); }
    static bool RtcAudioJitterBufferMaxPacketsEnabled(const FeatureContext*);

    static bool RTCIceTransportExtensionEnabledByRuntimeFlag() { return RTCIceTransportExtensionEnabled(nullptr); }
    static bool RTCIceTransportExtensionEnabled(const FeatureContext*);

    static bool RTCInsertableStreamsEnabledByRuntimeFlag() { return RTCInsertableStreamsEnabled(nullptr); }
    static bool RTCInsertableStreamsEnabled(const FeatureContext*);

    static bool RTCQuicTransportEnabledByRuntimeFlag() { return RTCQuicTransportEnabled(nullptr); }
    static bool RTCQuicTransportEnabled(const FeatureContext*);

    static bool RTCStatsRelativePacketArrivalDelayEnabledByRuntimeFlag() { return RTCStatsRelativePacketArrivalDelayEnabled(nullptr); }
    static bool RTCStatsRelativePacketArrivalDelayEnabled(const FeatureContext*);

    static bool SecurePaymentConfirmationOptOutEnabledByRuntimeFlag() { return SecurePaymentConfirmationOptOutEnabled(nullptr); }
    static bool SecurePaymentConfirmationOptOutEnabled(const FeatureContext*);

    static bool SendFullUserAgentAfterReductionEnabledByRuntimeFlag() { return SendFullUserAgentAfterReductionEnabled(nullptr); }
    static bool SendFullUserAgentAfterReductionEnabled(const FeatureContext*);

    static bool SharedStorageAPIEnabledByRuntimeFlag() { return SharedStorageAPIEnabled(nullptr); }
    static bool SharedStorageAPIEnabled(const FeatureContext*);

    static bool SignatureBasedIntegrityEnabledByRuntimeFlag() { return SignatureBasedIntegrityEnabled(nullptr); }
    static bool SignatureBasedIntegrityEnabled(const FeatureContext*);

    static bool SkipAdEnabledByRuntimeFlag() { return SkipAdEnabled(nullptr); }
    static bool SkipAdEnabled(const FeatureContext*);

    static bool SpeculationRulesEnabledByRuntimeFlag() { return SpeculationRulesEnabled(nullptr); }
    static bool SpeculationRulesEnabled(const FeatureContext*);

    static bool SpeculationRulesPrefetchProxyEnabledByRuntimeFlag() { return SpeculationRulesPrefetchProxyEnabled(nullptr); }
    static bool SpeculationRulesPrefetchProxyEnabled(const FeatureContext*);

    static bool StorageFoundationAPIEnabledByRuntimeFlag() { return StorageFoundationAPIEnabled(nullptr); }
    static bool StorageFoundationAPIEnabled(const FeatureContext*);

    static bool TextFragmentIdentifiersEnabledByRuntimeFlag() { return TextFragmentIdentifiersEnabled(nullptr); }
    static bool TextFragmentIdentifiersEnabled(const FeatureContext*);

    static bool TopicsAPIEnabledByRuntimeFlag() { return TopicsAPIEnabled(nullptr); }
    static bool TopicsAPIEnabled(const FeatureContext*);

    static bool TouchEventFeatureDetectionEnabledByRuntimeFlag() { return TouchEventFeatureDetectionEnabled(nullptr); }
    static bool TouchEventFeatureDetectionEnabled(const FeatureContext*);

    static bool TrustTokensEnabledByRuntimeFlag() { return TrustTokensEnabled(nullptr); }
    static bool TrustTokensEnabled(const FeatureContext*);

    static bool U2FSecurityKeyAPIEnabledByRuntimeFlag() { return U2FSecurityKeyAPIEnabled(nullptr); }
    static bool U2FSecurityKeyAPIEnabled(const FeatureContext*);

    static bool UnrestrictedSharedArrayBufferEnabledByRuntimeFlag() { return UnrestrictedSharedArrayBufferEnabled(nullptr); }
    static bool UnrestrictedSharedArrayBufferEnabled(const FeatureContext*);

    static bool UserAgentReductionEnabledByRuntimeFlag() { return UserAgentReductionEnabled(nullptr); }
    static bool UserAgentReductionEnabled(const FeatureContext*);

    static bool WebAppDarkModeEnabledByRuntimeFlag() { return WebAppDarkModeEnabled(nullptr); }
    static bool WebAppDarkModeEnabled(const FeatureContext*);

    static bool WebAppLaunchHandlerEnabledByRuntimeFlag() { return WebAppLaunchHandlerEnabled(nullptr); }
    static bool WebAppLaunchHandlerEnabled(const FeatureContext*);

    static bool WebAppLaunchQueueEnabledByRuntimeFlag() { return WebAppLaunchQueueEnabled(nullptr); }
    static bool WebAppLaunchQueueEnabled(const FeatureContext*);

    static bool WebAppUrlHandlingEnabledByRuntimeFlag() { return WebAppUrlHandlingEnabled(nullptr); }
    static bool WebAppUrlHandlingEnabled(const FeatureContext*);

    static bool WebAppWindowControlsOverlayEnabledByRuntimeFlag() { return WebAppWindowControlsOverlayEnabled(nullptr); }
    static bool WebAppWindowControlsOverlayEnabled(const FeatureContext*);

    static bool WebAssemblyExceptionsEnabledByRuntimeFlag() { return WebAssemblyExceptionsEnabled(nullptr); }
    static bool WebAssemblyExceptionsEnabled(const FeatureContext*);

    static bool WebCodecsEnabledByRuntimeFlag() { return WebCodecsEnabled(nullptr); }
    static bool WebCodecsEnabled(const FeatureContext*);

    static bool WebGPUEnabledByRuntimeFlag() { return WebGPUEnabled(nullptr); }
    static bool WebGPUEnabled(const FeatureContext*);

    static bool WebPaymentAPICSPEnabledByRuntimeFlag() { return WebPaymentAPICSPEnabled(nullptr); }
    static bool WebPaymentAPICSPEnabled(const FeatureContext*);

    static bool WebTransportCustomCertificatesEnabledByRuntimeFlag() { return WebTransportCustomCertificatesEnabled(nullptr); }
    static bool WebTransportCustomCertificatesEnabled(const FeatureContext*);

    static bool WebXRDepthEnabledByRuntimeFlag() { return WebXRDepthEnabled(nullptr); }
    static bool WebXRDepthEnabled(const FeatureContext*);

    static bool WebXRImageTrackingEnabledByRuntimeFlag() { return WebXRImageTrackingEnabled(nullptr); }
    static bool WebXRImageTrackingEnabled(const FeatureContext*);

    static bool WebXRPlaneDetectionEnabledByRuntimeFlag() { return WebXRPlaneDetectionEnabled(nullptr); }
    static bool WebXRPlaneDetectionEnabled(const FeatureContext*);

protected:
    // See the comment in RuntimeEnabledFeatures for why these are protected.
    static void SetStableFeaturesEnabled(bool);
    static void SetExperimentalFeaturesEnabled(bool);
    static void SetTestFeaturesEnabled(bool);
    static void SetOriginTrialControlledFeaturesEnabled(bool);

    static void SetFeatureEnabledFromString(const std::string& name, bool enabled);
    static void UpdateStatusFromBaseFeatures();

    static void SetAbortSignalThrowIfAbortedEnabled(bool enabled) { is_abort_signal_throw_if_aborted_enabled_ = enabled; }
    static void SetAbortSignalTimeoutEnabled(bool enabled) { is_abort_signal_timeout_enabled_ = enabled; }
    static void SetAccelerated2dCanvasEnabled(bool enabled) { is_accelerated_2d_canvas_enabled_ = enabled; }
    static void SetAcceleratedSmallCanvasesEnabled(bool enabled) { is_accelerated_small_canvases_enabled_ = enabled; }
    static void SetAccessibilityAriaTouchPassthroughEnabled(bool enabled) { is_accessibility_aria_touch_passthrough_enabled_ = enabled; }
    static void SetAccessibilityAriaVirtualContentEnabled(bool enabled) { is_accessibility_aria_virtual_content_enabled_ = enabled; }
    static void SetAccessibilityExposeDisplayNoneEnabled(bool enabled) { is_accessibility_expose_display_none_enabled_ = enabled; }
    static void SetAccessibilityExposeHTMLElementEnabled(bool enabled) { is_accessibility_expose_html_element_enabled_ = enabled; }
    static void SetAccessibilityExposeIgnoredNodesEnabled(bool enabled) { is_accessibility_expose_ignored_nodes_enabled_ = enabled; }
    static void SetAccessibilityObjectModelEnabled(bool enabled) { is_accessibility_object_model_enabled_ = enabled; }
    static void SetAccessibilityPageZoomEnabled(bool enabled) { is_accessibility_page_zoom_enabled_ = enabled; }
    static void SetAccessibilityUseAXPositionForDocumentMarkersEnabled(bool enabled) { is_accessibility_use_ax_position_for_document_markers_enabled_ = enabled; }
    static void SetAddressSpaceEnabled(bool enabled) { is_address_space_enabled_ = enabled; }
    static void SetAdInterestGroupAPIEnabled(bool enabled) { is_ad_interest_group_api_enabled_ = enabled; }
    static void SetAdTaggingEnabled(bool enabled) { is_ad_tagging_enabled_ = enabled; }
    static void SetAllowContentInitiatedDataUrlNavigationsEnabled(bool enabled) { is_allow_content_initiated_data_url_navigations_enabled_ = enabled; }
    static void SetAndroidDownloadableFontsMatchingEnabled(bool enabled) { is_android_downloadable_fonts_matching_enabled_ = enabled; }
    static void SetAnimationWorkletEnabled(bool enabled) { is_animation_worklet_enabled_ = enabled; }
    static void SetAnonymousIframeEnabled(bool enabled) { is_anonymous_iframe_enabled_ = enabled; }
    static void SetAOMAriaRelationshipPropertiesEnabled(bool enabled) { is_aom_aria_relationship_properties_enabled_ = enabled; }
    static void SetAriaTouchPassthroughEnabled(bool enabled) { is_aria_touch_passthrough_enabled_ = enabled; }
    static void SetAttributionReportingEnabled(bool enabled) { is_attribution_reporting_enabled_ = enabled; }
    static void SetAudioContextSetSinkIdEnabled(bool enabled) { is_audio_context_set_sink_id_enabled_ = enabled; }
    static void SetAudioOutputDevicesEnabled(bool enabled) { is_audio_output_devices_enabled_ = enabled; }
    static void SetAudioVideoTracksEnabled(bool enabled) { is_audio_video_tracks_enabled_ = enabled; }
    static void SetAutoDarkModeEnabled(bool enabled) { is_auto_dark_mode_enabled_ = enabled; }
    static void SetAutoDisableAccessibilityV2Enabled(bool enabled) { is_auto_disable_accessibility_v_2_enabled_ = enabled; }
    static void SetAutofillShadowDOMEnabled(bool enabled) { is_autofill_shadow_dom_enabled_ = enabled; }
    static void SetAutomationControlledEnabled(bool enabled) { is_automation_controlled_enabled_ = enabled; }
    static void SetAutoPictureInPictureEnabled(bool enabled) { is_auto_picture_in_picture_enabled_ = enabled; }
    static void SetAutoplayIgnoresWebAudioEnabled(bool enabled) { is_autoplay_ignores_web_audio_enabled_ = enabled; }
    static void SetBackfaceVisibilityInteropEnabled(bool enabled) { is_backface_visibility_interop_enabled_ = enabled; }
    static void SetBackForwardCacheEnabled(bool enabled) { is_back_forward_cache_enabled_ = enabled; }
    static void SetBackForwardCacheExperimentHTTPHeaderEnabled(bool enabled) { is_back_forward_cache_experiment_http_header_enabled_ = enabled; }
    static void SetBackForwardCacheNotRestoredReasonsEnabled(bool enabled) { is_back_forward_cache_not_restored_reasons_enabled_ = enabled; }
    static void SetBackgroundFetchEnabled(bool enabled) { is_background_fetch_enabled_ = enabled; }
    static void SetBarcodeDetectorEnabled(bool enabled) { is_barcode_detector_enabled_ = enabled; }
    static void SetBatchFetchRequestsEnabled(bool enabled) { is_batch_fetch_requests_enabled_ = enabled; }
    static void SetBeforeMatchEventEnabled(bool enabled) { is_before_match_event_enabled_ = enabled; }
    static void SetBidiCaretAffinityEnabled(bool enabled) { is_bidi_caret_affinity_enabled_ = enabled; }
    static void SetBlinkExtensionChromeOSEnabled(bool enabled) { is_blink_extension_chrome_os_enabled_ = enabled; }
    static void SetBlinkExtensionChromeOSHIDEnabled(bool enabled) { is_blink_extension_chrome_oshid_enabled_ = enabled; }
    static void SetBlinkExtensionChromeOSWindowManagementEnabled(bool enabled) { is_blink_extension_chrome_os_window_management_enabled_ = enabled; }
    static void SetBlinkRuntimeCallStatsEnabled(bool enabled) { is_blink_runtime_call_stats_enabled_ = enabled; }
    static void SetBlockingAttributeEnabled(bool enabled) { is_blocking_attribute_enabled_ = enabled; }
    static void SetBlockingFocusWithoutUserActivationEnabled(bool enabled) { is_blocking_focus_without_user_activation_enabled_ = enabled; }
    static void SetBrowserVerifiedUserActivationKeyboardEnabled(bool enabled) { is_browser_verified_user_activation_keyboard_enabled_ = enabled; }
    static void SetBrowserVerifiedUserActivationMouseEnabled(bool enabled) { is_browser_verified_user_activation_mouse_enabled_ = enabled; }
    static void SetCacheStorageCodeCacheHintEnabled(bool enabled) { is_cache_storage_code_cache_hint_enabled_ = enabled; }
    static void SetCanvas2dImageChromiumEnabled(bool enabled) { is_canvas_2d_image_chromium_enabled_ = enabled; }
    static void SetCanvas2dLayersEnabled(bool enabled) { is_canvas_2d_layers_enabled_ = enabled; }
    static void SetCanvas2dScrollPathIntoViewEnabled(bool enabled) { is_canvas_2d_scroll_path_into_view_enabled_ = enabled; }
    static void SetCanvasColorManagementV2Enabled(bool enabled) { is_canvas_color_management_v_2_enabled_ = enabled; }
    static void SetCanvasHDREnabled(bool enabled) { is_canvas_hdr_enabled_ = enabled; }
    static void SetCanvasImageSmoothingEnabled(bool enabled) { is_canvas_image_smoothing_enabled_ = enabled; }
    static void SetCapabilityDelegationFullscreenRequestEnabled(bool enabled) { is_capability_delegation_fullscreen_request_enabled_ = enabled; }
    static void SetCaptureHandleEnabled(bool enabled) { is_capture_handle_enabled_ = enabled; }
    static void SetcheckVisibilityEnabled(bool enabled) { is_check_visibility_enabled_ = enabled; }
    static void SetClearIdentityInCanMakePaymentEventEnabled(bool enabled) { is_clear_identity_in_can_make_payment_event_enabled_ = enabled; }
    static void SetClickToCapturedPointerEnabled(bool enabled) { is_click_to_captured_pointer_enabled_ = enabled; }
    static void SetClientHintsMetaEquivDelegateCHEnabled(bool enabled) { is_client_hints_meta_equiv_delegate_ch_enabled_ = enabled; }
    static void SetClientHintsMetaHTTPEquivAcceptCHEnabled(bool enabled) { is_client_hints_meta_http_equiv_accept_ch_enabled_ = enabled; }
    static void SetClientHintThirdPartyDelegationEnabled(bool enabled) { is_client_hint_third_party_delegation_enabled_ = enabled; }
    static void SetClipboardCustomFormatsEnabled(bool enabled) { is_clipboard_custom_formats_enabled_ = enabled; }
    static void SetClipboardSvgEnabled(bool enabled) { is_clipboard_svg_enabled_ = enabled; }
    static void SetClipboardUnsanitizedContentEnabled(bool enabled) { is_clipboard_unsanitized_content_enabled_ = enabled; }
    static void SetCloseWatcherEnabled(bool enabled) { is_close_watcher_enabled_ = enabled; }
    static void SetCLSScrollAnchoringEnabled(bool enabled) { is_cls_scroll_anchoring_enabled_ = enabled; }
    static void SetCoepReflectionEnabled(bool enabled) { is_coep_reflection_enabled_ = enabled; }
    static void SetCompositeBGColorAnimationEnabled(bool enabled) { is_composite_bg_color_animation_enabled_ = enabled; }
    static void SetCompositeBoxShadowAnimationEnabled(bool enabled) { is_composite_box_shadow_animation_enabled_ = enabled; }
    static void SetCompositeClipPathAnimationEnabled(bool enabled) { is_composite_clip_path_animation_enabled_ = enabled; }
    static void SetCompositedSelectionUpdateEnabled(bool enabled) { is_composited_selection_update_enabled_ = enabled; }
    static void SetComputedAccessibilityInfoEnabled(bool enabled) { is_computed_accessibility_info_enabled_ = enabled; }
    static void SetComputePressureEnabled(bool enabled) { is_compute_pressure_enabled_ = enabled; }
    static void SetConditionalFocusEnabled(bool enabled) { is_conditional_focus_enabled_ = enabled; }
    static void SetConsolidatedMovementXYEnabled(bool enabled) { is_consolidated_movement_xy_enabled_ = enabled; }
    static void SetContactsManagerEnabled(bool enabled) { is_contacts_manager_enabled_ = enabled; }
    static void SetContactsManagerExtraPropertiesEnabled(bool enabled) { is_contacts_manager_extra_properties_enabled_ = enabled; }
    static void SetContentIndexEnabled(bool enabled) { is_content_index_enabled_ = enabled; }
    static void SetContentVisibilityAutoStateChangeEventEnabled(bool enabled) { is_content_visibility_auto_state_change_event_enabled_ = enabled; }
    static void SetContextMenuEnabled(bool enabled) { is_context_menu_enabled_ = enabled; }
    static void SetCooperativeSchedulingEnabled(bool enabled) { is_cooperative_scheduling_enabled_ = enabled; }
    static void SetCorsRFC1918Enabled(bool enabled) { is_cors_rfc_1918_enabled_ = enabled; }
    static void SetCrossOriginOpenerPolicyReportingEnabled(bool enabled) { is_cross_origin_opener_policy_reporting_enabled_ = enabled; }
    static void SetCSSAnchorPositioningEnabled(bool enabled) { is_css_anchor_positioning_enabled_ = enabled; }
    static void SetCSSAtRuleCounterStyleImageSymbolsEnabled(bool enabled) { is_css_at_rule_counter_style_image_symbols_enabled_ = enabled; }
    static void SetCSSAtRuleCounterStyleSpeakAsDescriptorEnabled(bool enabled) { is_css_at_rule_counter_style_speak_as_descriptor_enabled_ = enabled; }
    static void SetCSSAtSupportsAlwaysNonForgivingParsingEnabled(bool enabled) { is_css_at_supports_always_non_forgiving_parsing_enabled_ = enabled; }
    static void SetCSSCalcSimplificationAndSerializationEnabled(bool enabled) { is_css_calc_simplification_and_serialization_enabled_ = enabled; }
    static void SetCSSCaseSensitiveSelectorEnabled(bool enabled) { is_css_case_sensitive_selector_enabled_ = enabled; }
    static void SetCSSColor4Enabled(bool enabled) { is_css_color_4_enabled_ = enabled; }
    static void SetCSSColorContrastEnabled(bool enabled) { is_css_color_contrast_enabled_ = enabled; }
    static void SetCSSColorTypedOMEnabled(bool enabled) { is_css_color_typed_om_enabled_ = enabled; }
    static void SetCSSContainerQueriesEnabled(bool enabled) { is_css_container_queries_enabled_ = enabled; }
    static void SetCSSContainerRelativeUnitsEnabled(bool enabled) { is_css_container_relative_units_enabled_ = enabled; }
    static void SetCSSContainerSkipStyleRecalcEnabled(bool enabled) { is_css_container_skip_style_recalc_enabled_ = enabled; }
    static void SetCSSContainSize1DEnabled(bool enabled) { is_css_contain_size_1d_enabled_ = enabled; }
    static void SetCSSEnumeratedCustomPropertiesEnabled(bool enabled) { is_css_enumerated_custom_properties_enabled_ = enabled; }
    static void SetCSSFocusVisibleEnabled(bool enabled) { is_css_focus_visible_enabled_ = enabled; }
    static void SetCSSFoldablesEnabled(bool enabled) { is_css_foldables_enabled_ = enabled; }
    static void SetCSSFontFaceAutoVariableRangeEnabled(bool enabled) { is_css_font_face_auto_variable_range_enabled_ = enabled; }
    static void SetCSSFontFaceSrcTechParsingEnabled(bool enabled) { is_css_font_face_src_tech_parsing_enabled_ = enabled; }
    static void SetCSSFontFamilyMathEnabled(bool enabled) { is_css_font_family_math_enabled_ = enabled; }
    static void SetCSSFontSizeAdjustEnabled(bool enabled) { is_css_font_size_adjust_enabled_ = enabled; }
    static void SetCSSGridTemplatePropertyInterpolationEnabled(bool enabled) { is_css_grid_template_property_interpolation_enabled_ = enabled; }
    static void SetCSSHexAlphaColorEnabled(bool enabled) { is_css_hex_alpha_color_enabled_ = enabled; }
    static void SetCSSHyphenateLimitCharsEnabled(bool enabled) { is_css_hyphenate_limit_chars_enabled_ = enabled; }
    static void SetCSSIcUnitEnabled(bool enabled) { is_css_ic_unit_enabled_ = enabled; }
    static void SetCSSIndependentTransformPropertiesEnabled(bool enabled) { is_css_independent_transform_properties_enabled_ = enabled; }
    static void SetCSSInitialLetterEnabled(bool enabled) { is_css_initial_letter_enabled_ = enabled; }
    static void SetCSSLastBaselineEnabled(bool enabled) { is_css_last_baseline_enabled_ = enabled; }
    static void SetCSSLayoutAPIEnabled(bool enabled) { is_css_layout_api_enabled_ = enabled; }
    static void SetCSSLhUnitEnabled(bool enabled) { is_css_lh_unit_enabled_ = enabled; }
    static void SetCSSLogicalEnabled(bool enabled) { is_css_logical_enabled_ = enabled; }
    static void SetCSSLogicalOverflowEnabled(bool enabled) { is_css_logical_overflow_enabled_ = enabled; }
    static void SetCSSMarkerNestedPseudoElementEnabled(bool enabled) { is_css_marker_nested_pseudo_element_enabled_ = enabled; }
    static void SetCSSMathDepthEnabled(bool enabled) { is_css_math_depth_enabled_ = enabled; }
    static void SetCSSMathShiftEnabled(bool enabled) { is_css_math_shift_enabled_ = enabled; }
    static void SetCSSMathStyleEnabled(bool enabled) { is_css_math_style_enabled_ = enabled; }
    static void SetCSSMathVariantEnabled(bool enabled) { is_css_math_variant_enabled_ = enabled; }
    static void SetCSSMediaQueries4Enabled(bool enabled) { is_css_media_queries_4_enabled_ = enabled; }
    static void SetCSSMixBlendModePlusLighterEnabled(bool enabled) { is_css_mix_blend_mode_plus_lighter_enabled_ = enabled; }
    static void SetCSSObjectViewBoxEnabled(bool enabled) { is_css_object_view_box_enabled_ = enabled; }
    static void SetCSSOffsetPathRayEnabled(bool enabled) { is_css_offset_path_ray_enabled_ = enabled; }
    static void SetCSSOffsetPathRayContainEnabled(bool enabled) { is_css_offset_path_ray_contain_enabled_ = enabled; }
    static void SetCSSOffsetPositionAnchorEnabled(bool enabled) { is_css_offset_position_anchor_enabled_ = enabled; }
    static void SetCSSOverflowForReplacedElementsEnabled(bool enabled) { is_css_overflow_for_replaced_elements_enabled_ = enabled; }
    static void SetCSSPaintAPIArgumentsEnabled(bool enabled) { is_css_paint_api_arguments_enabled_ = enabled; }
    static void SetCSSPictureInPictureEnabled(bool enabled) { is_css_picture_in_picture_enabled_ = enabled; }
    static void SetCSSPositionStickyStaticScrollPositionEnabled(bool enabled) { is_css_position_sticky_static_scroll_position_enabled_ = enabled; }
    static void SetCSSPseudoAutofillEnabled(bool enabled) { is_css_pseudo_autofill_enabled_ = enabled; }
    static void SetCSSPseudoDirEnabled(bool enabled) { is_css_pseudo_dir_enabled_ = enabled; }
    static void SetCSSPseudoHasEnabled(bool enabled) { is_css_pseudo_has_enabled_ = enabled; }
    static void SetCSSPseudoPlayingPausedEnabled(bool enabled) { is_css_pseudo_playing_paused_enabled_ = enabled; }
    static void SetCSSScopeEnabled(bool enabled) { is_css_scope_enabled_ = enabled; }
    static void SetCSSScrollbarsEnabled(bool enabled) { is_css_scrollbars_enabled_ = enabled; }
    static void SetCSSScrollTimelineEnabled(bool enabled) { is_css_scroll_timeline_enabled_ = enabled; }
    static void SetCSSSelectorFragmentAnchorEnabled(bool enabled) { is_css_selector_fragment_anchor_enabled_ = enabled; }
    static void SetCSSSnapSizeEnabled(bool enabled) { is_css_snap_size_enabled_ = enabled; }
    static void SetCSSSpellingGrammarErrorsEnabled(bool enabled) { is_css_spelling_grammar_errors_enabled_ = enabled; }
    static void SetCSSStyleQueriesEnabled(bool enabled) { is_css_style_queries_enabled_ = enabled; }
    static void SetCSSTogglesEnabled(bool enabled) { is_css_toggles_enabled_ = enabled; }
    static void SetCSSTrigonometricFunctionsEnabled(bool enabled) { is_css_trigonometric_functions_enabled_ = enabled; }
    static void SetCSSVariables2ImageValuesEnabled(bool enabled) { is_css_variables_2_image_values_enabled_ = enabled; }
    static void SetCSSVariables2TransformValuesEnabled(bool enabled) { is_css_variables_2_transform_values_enabled_ = enabled; }
    static void SetCSSVideoDynamicRangeMediaQueriesEnabled(bool enabled) { is_css_video_dynamic_range_media_queries_enabled_ = enabled; }
    static void SetCSSViewportUnits4Enabled(bool enabled) { is_css_viewport_units_4_enabled_ = enabled; }
    static void SetCSSViewTimelineEnabled(bool enabled) { is_css_view_timeline_enabled_ = enabled; }
    static void SetCustomElementDefaultStyleEnabled(bool enabled) { is_custom_element_default_style_enabled_ = enabled; }
    static void SetDatabaseEnabled(bool enabled) { is_database_enabled_ = enabled; }
    static void SetDecodeJpeg420ImagesToYUVEnabled(bool enabled) { is_decode_jpeg_420_images_to_yuv_enabled_ = enabled; }
    static void SetDecodeLossyWebPImagesToYUVEnabled(bool enabled) { is_decode_lossy_web_p_images_to_yuv_enabled_ = enabled; }
    static void SetDeferredShapingEnabled(bool enabled) { is_deferred_shaping_enabled_ = enabled; }
    static void SetDeflateRawCompressionFormatEnabled(bool enabled) { is_deflate_raw_compression_format_enabled_ = enabled; }
    static void SetDelegatedInkTrailsEnabled(bool enabled) { is_delegated_ink_trails_enabled_ = enabled; }
    static void SetDeliveryTypeEnabled(bool enabled) { is_delivery_type_enabled_ = enabled; }
    static void SetDesktopCaptureDisableLocalEchoControlEnabled(bool enabled) { is_desktop_capture_disable_local_echo_control_enabled_ = enabled; }
    static void SetDesktopPWAsSubAppsEnabled(bool enabled) { is_desktop_pw_as_sub_apps_enabled_ = enabled; }
    static void SetDeviceAttributesEnabled(bool enabled) { is_device_attributes_enabled_ = enabled; }
    static void SetDeviceOrientationRequestPermissionEnabled(bool enabled) { is_device_orientation_request_permission_enabled_ = enabled; }
    static void SetDevicePostureEnabled(bool enabled) { is_device_posture_enabled_ = enabled; }
    static void SetDigitalGoodsEnabled(bool enabled) { is_digital_goods_enabled_ = enabled; }
    static void SetDigitalGoodsV2_1Enabled(bool enabled) { is_digital_goods_v_2_1_enabled_ = enabled; }
    static void SetDirectSocketsEnabled(bool enabled) { is_direct_sockets_enabled_ = enabled; }
    static void SetDisableDifferentOriginSubframeDialogSuppressionEnabled(bool enabled) { is_disable_different_origin_subframe_dialog_suppression_enabled_ = enabled; }
    static void SetDisableHardwareNoiseSuppressionEnabled(bool enabled) { is_disable_hardware_noise_suppression_enabled_ = enabled; }
    static void SetDisplayCutoutAPIEnabled(bool enabled) { is_display_cutout_api_enabled_ = enabled; }
    static void SetDisplaySurfaceConstraintEnabled(bool enabled) { is_display_surface_constraint_enabled_ = enabled; }
    static void SetDocumentCookieEnabled(bool enabled) { is_document_cookie_enabled_ = enabled; }
    static void SetDocumentDomainEnabled(bool enabled) { is_document_domain_enabled_ = enabled; }
    static void SetDocumentPictureInPictureAPIEnabled(bool enabled) { is_document_picture_in_picture_api_enabled_ = enabled; }
    static void SetDocumentPolicyEnabled(bool enabled) { is_document_policy_enabled_ = enabled; }
    static void SetDocumentPolicyDocumentDomainEnabled(bool enabled) { is_document_policy_document_domain_enabled_ = enabled; }
    static void SetDocumentPolicyNegotiationEnabled(bool enabled) { is_document_policy_negotiation_enabled_ = enabled; }
    static void SetDocumentPolicySyncXHREnabled(bool enabled) { is_document_policy_sync_xhr_enabled_ = enabled; }
    static void SetDocumentTransitionEnabled(bool enabled) { is_document_transition_enabled_ = enabled; }
    static void SetDocumentWriteEnabled(bool enabled) { is_document_write_enabled_ = enabled; }
    static void SetEarlyHintsPreloadForNavigationOptInEnabled(bool enabled) { is_early_hints_preload_for_navigation_opt_in_enabled_ = enabled; }
    static void SetEditContextEnabled(bool enabled) { is_edit_context_enabled_ = enabled; }
    static void SetElementSuperRareDataEnabled(bool enabled) { is_element_super_rare_data_enabled_ = enabled; }
    static void SetEventPathEnabled(bool enabled) { is_event_path_enabled_ = enabled; }
    static void SetExperimentalContentSecurityPolicyFeaturesEnabled(bool enabled) { is_experimental_content_security_policy_features_enabled_ = enabled; }
    static void SetExperimentalJSProfilerMarkersEnabled(bool enabled) { is_experimental_js_profiler_markers_enabled_ = enabled; }
    static void SetExperimentalPoliciesEnabled(bool enabled) { is_experimental_policies_enabled_ = enabled; }
    static void SetExperimentalWebSnapshotsEnabled(bool enabled) { is_experimental_web_snapshots_enabled_ = enabled; }
    static void SetExtendedTextMetricsEnabled(bool enabled) { is_extended_text_metrics_enabled_ = enabled; }
    static void SetExtraWebGLVideoTextureMetadataEnabled(bool enabled) { is_extra_webgl_video_texture_metadata_enabled_ = enabled; }
    static void SetEyeDropperAPIEnabled(bool enabled) { is_eye_dropper_api_enabled_ = enabled; }
    static void SetFaceDetectorEnabled(bool enabled) { is_face_detector_enabled_ = enabled; }
    static void SetFakeNoAllocDirectCallForTestingEnabled(bool enabled) { is_fake_no_alloc_direct_call_for_testing_enabled_ = enabled; }
    static void SetFeaturePolicyReportingEnabled(bool enabled) { is_feature_policy_reporting_enabled_ = enabled; }
    static void SetFedCmEnabled(bool enabled) { is_fed_cm_enabled_ = enabled; }
    static void SetFedCmIdpSigninStatusEnabled(bool enabled) { is_fed_cm_idp_signin_status_enabled_ = enabled; }
    static void SetFedCmIdpSignoutEnabled(bool enabled) { is_fed_cm_idp_signout_enabled_ = enabled; }
    static void SetFedCmIframeSupportEnabled(bool enabled) { is_fed_cm_iframe_support_enabled_ = enabled; }
    static void SetFedCmMultipleIdentityProvidersEnabled(bool enabled) { is_fed_cm_multiple_identity_providers_enabled_ = enabled; }
    static void SetFencedFramesEnabled(bool enabled) { is_fenced_frames_enabled_ = enabled; }
    static void SetFetchUploadStreamingEnabled(bool enabled) { is_fetch_upload_streaming_enabled_ = enabled; }
    static void SetFileHandlingEnabled(bool enabled) { is_file_handling_enabled_ = enabled; }
    static void SetFileHandlingIconsEnabled(bool enabled) { is_file_handling_icons_enabled_ = enabled; }
    static void SetFileSystemEnabled(bool enabled) { is_file_system_enabled_ = enabled; }
    static void SetFileSystemAccessEnabled(bool enabled) { is_file_system_access_enabled_ = enabled; }
    static void SetFileSystemAccessAccessHandleEnabled(bool enabled) { is_file_system_access_access_handle_enabled_ = enabled; }
    static void SetFileSystemAccessAPIExperimentalEnabled(bool enabled) { is_file_system_access_api_experimental_enabled_ = enabled; }
    static void SetFileSystemAccessLocalEnabled(bool enabled) { is_file_system_access_local_enabled_ = enabled; }
    static void SetFileSystemAccessOriginPrivateEnabled(bool enabled) { is_file_system_access_origin_private_enabled_ = enabled; }
    static void SetFileSystemSyncAccessHandleAsyncInterfaceOverrideEnabled(bool enabled) { is_file_system_sync_access_handle_async_interface_override_enabled_ = enabled; }
    static void SetFirstPartySetsEnabled(bool enabled) { is_first_party_sets_enabled_ = enabled; }
    static void SetFixedElementsDontOverscrollEnabled(bool enabled) { is_fixed_elements_dont_overscroll_enabled_ = enabled; }
    static void SetFledgeEnabled(bool enabled) { is_fledge_enabled_ = enabled; }
    static void SetFluentScrollbarsEnabled(bool enabled) { is_fluent_scrollbars_enabled_ = enabled; }
    static void SetFocusgroupEnabled(bool enabled) { is_focusgroup_enabled_ = enabled; }
    static void SetFocuslessSpatialNavigationEnabled(bool enabled) { is_focusless_spatial_navigation_enabled_ = enabled; }
    static void SetFontAccessEnabled(bool enabled) { is_font_access_enabled_ = enabled; }
    static void SetFontPaletteEnabled(bool enabled) { is_font_palette_enabled_ = enabled; }
    static void SetFontSrcLocalMatchingEnabled(bool enabled) { is_font_src_local_matching_enabled_ = enabled; }
    static void SetForcedColorsEnabled(bool enabled) { is_forced_colors_enabled_ = enabled; }
    static void SetForcedColorsPreserveParentColorEnabled(bool enabled) { is_forced_colors_preserve_parent_color_enabled_ = enabled; }
    static void SetForceEagerMeasureMemoryEnabled(bool enabled) { is_force_eager_measure_memory_enabled_ = enabled; }
    static void SetForceReduceMotionEnabled(bool enabled) { is_force_reduce_motion_enabled_ = enabled; }
    static void SetForceTallerSelectPopupEnabled(bool enabled) { is_force_taller_select_popup_enabled_ = enabled; }
    static void SetFormattedTextEnabled(bool enabled) { is_formatted_text_enabled_ = enabled; }
    static void SetFormRelAttributeEnabled(bool enabled) { is_form_rel_attribute_enabled_ = enabled; }
    static void SetFractionalScrollOffsetsEnabled(bool enabled) { is_fractional_scroll_offsets_enabled_ = enabled; }
    static void SetFreezeFramesOnVisibilityEnabled(bool enabled) { is_freeze_frames_on_visibility_enabled_ = enabled; }
    static void SetGamepadButtonAxisEventsEnabled(bool enabled) { is_gamepad_button_axis_events_enabled_ = enabled; }
    static void SetGetDisplayMediaEnabled(bool enabled) { is_get_display_media_enabled_ = enabled; }
    static void SetGetDisplayMediaSetEnabled(bool enabled) { is_get_display_media_set_enabled_ = enabled; }
    static void SetGetDisplayMediaSetAutoSelectAllScreensEnabled(bool enabled) { is_get_display_media_set_auto_select_all_screens_enabled_ = enabled; }
    static void SetGroupEffectEnabled(bool enabled) { is_group_effect_enabled_ = enabled; }
    static void SetHandwritingRecognitionEnabled(bool enabled) { is_handwriting_recognition_enabled_ = enabled; }
    static void SetHidDeviceForgetEnabled(bool enabled) { is_hid_device_forget_enabled_ = enabled; }
    static void SetHighlightAPIEnabled(bool enabled) { is_highlight_api_enabled_ = enabled; }
    static void SetHighlightInheritanceEnabled(bool enabled) { is_highlight_inheritance_enabled_ = enabled; }
    static void SetHighlightOverlayPaintingEnabled(bool enabled) { is_highlight_overlay_painting_enabled_ = enabled; }
    static void SetHighlightPointerEventsEnabled(bool enabled) { is_highlight_pointer_events_enabled_ = enabled; }
    static void SetHrefTranslateEnabled(bool enabled) { is_href_translate_enabled_ = enabled; }
    static void SetHTMLParamElementUrlSupportEnabled(bool enabled) { is_html_param_element_url_support_enabled_ = enabled; }
    static void SetHTMLPopupAttributeEnabled(bool enabled) { is_html_popup_attribute_enabled_ = enabled; }
    static void SetHTMLSelectMenuElementEnabled(bool enabled) { is_html_select_menu_element_enabled_ = enabled; }
    static void SetIDBBatchGetAllEnabled(bool enabled) { is_idb_batch_get_all_enabled_ = enabled; }
    static void SetIdleDetectionEnabled(bool enabled) { is_idle_detection_enabled_ = enabled; }
    static void SetImplicitRootScrollerEnabled(bool enabled) { is_implicit_root_scroller_enabled_ = enabled; }
    static void SetInertAttributeEnabled(bool enabled) { is_inert_attribute_enabled_ = enabled; }
    static void SetInfiniteCullRectEnabled(bool enabled) { is_infinite_cull_rect_enabled_ = enabled; }
    static void SetInputMultipleFieldsUIEnabled(bool enabled) { is_input_multiple_fields_ui_enabled_ = enabled; }
    static void SetInstalledAppEnabled(bool enabled) { is_installed_app_enabled_ = enabled; }
    static void SetKeyboardAccessibleTooltipEnabled(bool enabled) { is_keyboard_accessible_tooltip_enabled_ = enabled; }
    static void SetKeyboardFocusableScrollersEnabled(bool enabled) { is_keyboard_focusable_scrollers_enabled_ = enabled; }
    static void SetLangAttributeAwareFormControlUIEnabled(bool enabled) { is_lang_attribute_aware_form_control_ui_enabled_ = enabled; }
    static void SetLangAttributeAwareSvgTextEnabled(bool enabled) { is_lang_attribute_aware_svg_text_enabled_ = enabled; }
    static void SetLayoutNGEnabled(bool enabled) { is_layout_ng_enabled_ = enabled; }
    static void SetLayoutNGBlockFragmentationEnabled(bool enabled) { is_layout_ng_block_fragmentation_enabled_ = enabled; }
    static void SetLayoutNGBlockInInlineEnabled(bool enabled) { is_layout_ng_block_in_inline_enabled_ = enabled; }
    static void SetLayoutNGDelayScrollOffsetClampingEnabled(bool enabled) { is_layout_ng_delay_scroll_offset_clamping_enabled_ = enabled; }
    static void SetLayoutNGFlexFragmentationEnabled(bool enabled) { is_layout_ng_flex_fragmentation_enabled_ = enabled; }
    static void SetLayoutNGForeignObjectEnabled(bool enabled) { is_layout_ng_foreign_object_enabled_ = enabled; }
    static void SetLayoutNGFrameSetEnabled(bool enabled) { is_layout_ng_frame_set_enabled_ = enabled; }
    static void SetLayoutNGGridFragmentationEnabled(bool enabled) { is_layout_ng_grid_fragmentation_enabled_ = enabled; }
    static void SetLayoutNGPrintingEnabled(bool enabled) { is_layout_ng_printing_enabled_ = enabled; }
    static void SetLayoutNGSubgridEnabled(bool enabled) { is_layout_ng_subgrid_enabled_ = enabled; }
    static void SetLayoutNGTableFragmentationEnabled(bool enabled) { is_layout_ng_table_fragmentation_enabled_ = enabled; }
    static void SetLayoutNGVTTCueEnabled(bool enabled) { is_layout_ngvtt_cue_enabled_ = enabled; }
    static void SetLazyFrameLoadingEnabled(bool enabled) { is_lazy_frame_loading_enabled_ = enabled; }
    static void SetLazyFrameVisibleLoadTimeMetricsEnabled(bool enabled) { is_lazy_frame_visible_load_time_metrics_enabled_ = enabled; }
    static void SetLazyImageLoadingEnabled(bool enabled) { is_lazy_image_loading_enabled_ = enabled; }
    static void SetLazyImageVisibleLoadTimeMetricsEnabled(bool enabled) { is_lazy_image_visible_load_time_metrics_enabled_ = enabled; }
    static void SetLazyInitializeMediaControlsEnabled(bool enabled) { is_lazy_initialize_media_controls_enabled_ = enabled; }
    static void SetLCPAnimatedImagesWebExposedEnabled(bool enabled) { is_lcp_animated_images_web_exposed_enabled_ = enabled; }
    static void SetLegacyWindowsDWriteFontFallbackEnabled(bool enabled) { is_legacy_windows_d_write_font_fallback_enabled_ = enabled; }
    static void SetMachineLearningCommonEnabled(bool enabled) { is_machine_learning_common_enabled_ = enabled; }
    static void SetMachineLearningModelLoaderEnabled(bool enabled) { is_machine_learning_model_loader_enabled_ = enabled; }
    static void SetMachineLearningNeuralNetworkEnabled(bool enabled) { is_machine_learning_neural_network_enabled_ = enabled; }
    static void SetManagedConfigurationEnabled(bool enabled) { is_managed_configuration_enabled_ = enabled; }
    static void SetMathMLCoreEnabled(bool enabled) { is_mathml_core_enabled_ = enabled; }
    static void SetMeasureMemoryEnabled(bool enabled) { is_measure_memory_enabled_ = enabled; }
    static void SetMediaCapabilitiesDynamicRangeEnabled(bool enabled) { is_media_capabilities_dynamic_range_enabled_ = enabled; }
    static void SetMediaCapabilitiesEncodingInfoEnabled(bool enabled) { is_media_capabilities_encoding_info_enabled_ = enabled; }
    static void SetMediaCapabilitiesSpatialAudioEnabled(bool enabled) { is_media_capabilities_spatial_audio_enabled_ = enabled; }
    static void SetMediaCaptureEnabled(bool enabled) { is_media_capture_enabled_ = enabled; }
    static void SetMediaCaptureBackgroundBlurEnabled(bool enabled) { is_media_capture_background_blur_enabled_ = enabled; }
    static void SetMediaCastOverlayButtonEnabled(bool enabled) { is_media_cast_overlay_button_enabled_ = enabled; }
    static void SetMediaControlsExpandGestureEnabled(bool enabled) { is_media_controls_expand_gesture_enabled_ = enabled; }
    static void SetMediaControlsOverlayPlayButtonEnabled(bool enabled) { is_media_controls_overlay_play_button_enabled_ = enabled; }
    static void SetMediaElementVolumeGreaterThanOneEnabled(bool enabled) { is_media_element_volume_greater_than_one_enabled_ = enabled; }
    static void SetMediaEngagementBypassAutoplayPoliciesEnabled(bool enabled) { is_media_engagement_bypass_autoplay_policies_enabled_ = enabled; }
    static void SetMediaLatencyHintEnabled(bool enabled) { is_media_latency_hint_enabled_ = enabled; }
    static void SetMediaQueryNavigationControlsEnabled(bool enabled) { is_media_query_navigation_controls_enabled_ = enabled; }
    static void SetMediaSessionEnabled(bool enabled) { is_media_session_enabled_ = enabled; }
    static void SetMediaSessionWebRTCEnabled(bool enabled) { is_media_session_web_rtc_enabled_ = enabled; }
    static void SetMediaSourceExperimentalEnabled(bool enabled) { is_media_source_experimental_enabled_ = enabled; }
    static void SetMediaSourceExtensionsForWebCodecsEnabled(bool enabled) { is_media_source_extensions_for_webcodecs_enabled_ = enabled; }
    static void SetMediaSourceInWorkersEnabled(bool enabled) { is_media_source_in_workers_enabled_ = enabled; }
    static void SetMediaSourceInWorkersUsingHandleEnabled(bool enabled) { is_media_source_in_workers_using_handle_enabled_ = enabled; }
    static void SetMediaSourceNewAbortAndDurationEnabled(bool enabled) { is_media_source_new_abort_and_duration_enabled_ = enabled; }
    static void SetMediaSourceStableEnabled(bool enabled) { is_media_source_stable_enabled_ = enabled; }
    static void SetMediaStreamTrackInWindowEnabled(bool enabled) { is_media_stream_track_in_window_enabled_ = enabled; }
    static void SetMediaStreamTrackInWorkerEnabled(bool enabled) { is_media_stream_track_in_worker_enabled_ = enabled; }
    static void SetMediaStreamTrackTransferEnabled(bool enabled) { is_media_stream_track_transfer_enabled_ = enabled; }
    static void SetMiddleClickAutoscrollEnabled(bool enabled) { is_middle_click_autoscroll_enabled_ = enabled; }
    static void SetMobileLayoutThemeEnabled(bool enabled) { is_mobile_layout_theme_enabled_ = enabled; }
    static void SetMojoJSEnabled(bool enabled) { is_mojo_js_enabled_ = enabled; }
    static void SetMojoJSTestEnabled(bool enabled) { is_mojo_js_test_enabled_ = enabled; }
    static void SetMouseSubframeNoImplicitCaptureEnabled(bool enabled) { is_mouse_subframe_no_implicit_capture_enabled_ = enabled; }
    static void SetNavigationApiEnabled(bool enabled) { is_navigation_api_enabled_ = enabled; }
    static void SetNavigationIdEnabled(bool enabled) { is_navigation_id_enabled_ = enabled; }
    static void SetNavigatorContentUtilsEnabled(bool enabled) { is_navigator_content_utils_enabled_ = enabled; }
    static void SetNetInfoDownlinkMaxEnabled(bool enabled) { is_net_info_downlink_max_enabled_ = enabled; }
    static void SetNeverSlowModeEnabled(bool enabled) { is_never_slow_mode_enabled_ = enabled; }
    static void SetNewFlexboxSizingEnabled(bool enabled) { is_new_flexbox_sizing_enabled_ = enabled; }
    static void SetNoIdleEncodingForWebTestsEnabled(bool enabled) { is_no_idle_encoding_for_web_tests_enabled_ = enabled; }
    static void SetNotificationConstructorEnabled(bool enabled) { is_notification_constructor_enabled_ = enabled; }
    static void SetNotificationContentImageEnabled(bool enabled) { is_notification_content_image_enabled_ = enabled; }
    static void SetNotificationsEnabled(bool enabled) { is_notifications_enabled_ = enabled; }
    static void SetNotificationTriggersEnabled(bool enabled) { is_notification_triggers_enabled_ = enabled; }
    static void SetOffMainThreadCSSPaintEnabled(bool enabled) { is_off_main_thread_css_paint_enabled_ = enabled; }
    static void SetOffscreenCanvasCommitEnabled(bool enabled) { is_offscreen_canvas_commit_enabled_ = enabled; }
    static void SetOffsetParentNewSpecBehaviorEnabled(bool enabled) { is_offset_parent_new_spec_behavior_enabled_ = enabled; }
    static void SetOnDeviceChangeEnabled(bool enabled) { is_on_device_change_enabled_ = enabled; }
    static void SetOrientationEventEnabled(bool enabled) { is_orientation_event_enabled_ = enabled; }
    static void SetOriginIsolationHeaderEnabled(bool enabled) { is_origin_isolation_header_enabled_ = enabled; }
    static void SetOriginPolicyEnabled(bool enabled) { is_origin_policy_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIEnabled(bool enabled) { is_origin_trials_sample_api_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIDependentEnabled(bool enabled) { is_origin_trials_sample_api_dependent_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIDeprecationEnabled(bool enabled) { is_origin_trials_sample_api_deprecation_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIExpiryGracePeriodEnabled(bool enabled) { is_origin_trials_sample_api_expiry_grace_period_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIExpiryGracePeriodThirdPartyEnabled(bool enabled) { is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIImpliedEnabled(bool enabled) { is_origin_trials_sample_api_implied_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIInvalidOSEnabled(bool enabled) { is_origin_trials_sample_api_invalid_os_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPINavigationEnabled(bool enabled) { is_origin_trials_sample_api_navigation_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIPersistentExpiryGracePeriodEnabled(bool enabled) { is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIPersistentFeatureEnabled(bool enabled) { is_origin_trials_sample_api_persistent_feature_enabled_ = enabled; }
    static void SetOriginTrialsSampleAPIThirdPartyEnabled(bool enabled) { is_origin_trials_sample_api_third_party_enabled_ = enabled; }
    static void SetOverscrollCustomizationEnabled(bool enabled) { is_overscroll_customization_enabled_ = enabled; }
    static void SetPageFreezeOptInEnabled(bool enabled) { is_page_freeze_opt_in_enabled_ = enabled; }
    static void SetPageFreezeOptOutEnabled(bool enabled) { is_page_freeze_opt_out_enabled_ = enabled; }
    static void SetPagePopupEnabled(bool enabled) { is_page_popup_enabled_ = enabled; }
    static void SetPaintUnderInvalidationCheckingEnabled(bool enabled) { is_paint_under_invalidation_checking_enabled_ = enabled; }
    static void SetParakeetEnabled(bool enabled) { is_parakeet_enabled_ = enabled; }
    static void SetParallelPrimaryFontEnabled(bool enabled) { is_parallel_primary_font_enabled_ = enabled; }
    static void SetParallelTextShapingEnabled(bool enabled) { is_parallel_text_shaping_enabled_ = enabled; }
    static void SetPartitionedCookiesEnabled(bool enabled) { is_partitioned_cookies_enabled_ = enabled; }
    static void SetPasswordRevealEnabled(bool enabled) { is_password_reveal_enabled_ = enabled; }
    static void SetPaymentAppEnabled(bool enabled) { is_payment_app_enabled_ = enabled; }
    static void SetPaymentMethodChangeEventEnabled(bool enabled) { is_payment_method_change_event_enabled_ = enabled; }
    static void SetPaymentRequestEnabled(bool enabled) { is_payment_request_enabled_ = enabled; }
    static void SetPaymentRequestMerchantValidationEventEnabled(bool enabled) { is_payment_request_merchant_validation_event_enabled_ = enabled; }
    static void SetPendingBeaconAPIEnabled(bool enabled) { is_pending_beacon_api_enabled_ = enabled; }
    static void SetPercentBasedScrollingEnabled(bool enabled) { is_percent_based_scrolling_enabled_ = enabled; }
    static void SetPerformanceManagerInstrumentationEnabled(bool enabled) { is_performance_manager_instrumentation_enabled_ = enabled; }
    static void SetPeriodicBackgroundSyncEnabled(bool enabled) { is_periodic_background_sync_enabled_ = enabled; }
    static void SetPerMethodCanMakePaymentQuotaEnabled(bool enabled) { is_per_method_can_make_payment_quota_enabled_ = enabled; }
    static void SetPermissionsEnabled(bool enabled) { is_permissions_enabled_ = enabled; }
    static void SetPermissionsPolicyUnloadEnabled(bool enabled) { is_permissions_policy_unload_enabled_ = enabled; }
    static void SetPermissionsRequestRevokeEnabled(bool enabled) { is_permissions_request_revoke_enabled_ = enabled; }
    static void SetPictureInPictureEnabled(bool enabled) { is_picture_in_picture_enabled_ = enabled; }
    static void SetPictureInPictureAPIEnabled(bool enabled) { is_picture_in_picture_api_enabled_ = enabled; }
    static void SetPNaClEnabled(bool enabled) { is_p_na_cl_enabled_ = enabled; }
    static void SetPointerLockOptionsEnabled(bool enabled) { is_pointer_lock_options_enabled_ = enabled; }
    static void SetPortalsEnabled(bool enabled) { is_portals_enabled_ = enabled; }
    static void SetPreciseMemoryInfoEnabled(bool enabled) { is_precise_memory_info_enabled_ = enabled; }
    static void SetPreferNonCompositedScrollingEnabled(bool enabled) { is_prefer_non_composited_scrolling_enabled_ = enabled; }
    static void SetPrefersColorSchemeClientHintHeaderEnabled(bool enabled) { is_prefers_color_scheme_client_hint_header_enabled_ = enabled; }
    static void SetPrefersReducedDataEnabled(bool enabled) { is_prefers_reduced_data_enabled_ = enabled; }
    static void SetPrefersReducedMotionClientHintHeaderEnabled(bool enabled) { is_prefers_reduced_motion_client_hint_header_enabled_ = enabled; }
    static void SetPrefixedStorageInfoEnabled(bool enabled) { is_prefixed_storage_info_enabled_ = enabled; }
    static void SetPrefixedVideoFullscreenEnabled(bool enabled) { is_prefixed_video_fullscreen_enabled_ = enabled; }
    static void SetPrerender2Enabled(bool enabled) { is_prerender_2_enabled_ = enabled; }
    static void SetPrerender2RelatedFeaturesEnabled(bool enabled) { is_prerender_2_related_features_enabled_ = enabled; }
    static void SetPresentationEnabled(bool enabled) { is_presentation_enabled_ = enabled; }
    static void SetPriorityHintsEnabled(bool enabled) { is_priority_hints_enabled_ = enabled; }
    static void SetPrivacySandboxAdsAPIsEnabled(bool enabled) { is_privacy_sandbox_ads_api_s_enabled_ = enabled; }
    static void SetPrivateNetworkAccessNonSecureContextsAllowedEnabled(bool enabled) { is_private_network_access_non_secure_contexts_allowed_enabled_ = enabled; }
    static void SetPrivateNetworkAccessPermissionPromptEnabled(bool enabled) { is_private_network_access_permission_prompt_enabled_ = enabled; }
    static void SetPushMessagingEnabled(bool enabled) { is_push_messaging_enabled_ = enabled; }
    static void SetPushMessagingSubscriptionChangeEnabled(bool enabled) { is_push_messaging_subscription_change_enabled_ = enabled; }
    static void SetQuickIntensiveWakeUpThrottlingAfterLoadingEnabled(bool enabled) { is_quick_intensive_wake_up_throttling_after_loading_enabled_ = enabled; }
    static void SetQuotaChangeEnabled(bool enabled) { is_quota_change_enabled_ = enabled; }
    static void SetReduceUserAgentMinorVersionEnabled(bool enabled) { is_reduce_user_agent_minor_version_enabled_ = enabled; }
    static void SetReduceUserAgentPlatformOsCpuEnabled(bool enabled) { is_reduce_user_agent_platform_os_cpu_enabled_ = enabled; }
    static void SetRegionCaptureEnabled(bool enabled) { is_region_capture_enabled_ = enabled; }
    static void SetRemotePlaybackEnabled(bool enabled) { is_remote_playback_enabled_ = enabled; }
    static void SetRemotePlaybackBackendEnabled(bool enabled) { is_remote_playback_backend_enabled_ = enabled; }
    static void SetRemoveMobileViewportDoubleTapEnabled(bool enabled) { is_remove_mobile_viewport_double_tap_enabled_ = enabled; }
    static void SetRenderBlockingStatusEnabled(bool enabled) { is_render_blocking_status_enabled_ = enabled; }
    static void SetRenderPriorityAttributeEnabled(bool enabled) { is_render_priority_attribute_enabled_ = enabled; }
    static void SetResourceTimingResponseStatusEnabled(bool enabled) { is_resource_timing_response_status_enabled_ = enabled; }
    static void SetRestrictGamepadAccessEnabled(bool enabled) { is_restrict_gamepad_access_enabled_ = enabled; }
    static void SetRtcAudioJitterBufferMaxPacketsEnabled(bool enabled) { is_rtc_audio_jitter_buffer_max_packets_enabled_ = enabled; }
    static void SetRTCIceTransportExtensionEnabled(bool enabled) { is_rtc_ice_transport_extension_enabled_ = enabled; }
    static void SetRTCInsertableStreamsEnabled(bool enabled) { is_rtc_insertable_streams_enabled_ = enabled; }
    static void SetRTCQuicTransportEnabled(bool enabled) { is_rtc_quic_transport_enabled_ = enabled; }
    static void SetRTCRtpHeaderExtensionControlEnabled(bool enabled) { is_rtc_rtp_header_extension_control_enabled_ = enabled; }
    static void SetRTCStatsRelativePacketArrivalDelayEnabled(bool enabled) { is_rtc_stats_relative_packet_arrival_delay_enabled_ = enabled; }
    static void SetRTCSvcScalabilityModeEnabled(bool enabled) { is_rtc_svc_scalability_mode_enabled_ = enabled; }
    static void SetSanitizerAPIEnabled(bool enabled) { is_sanitizer_api_enabled_ = enabled; }
    static void SetSanitizerAPIv0Enabled(bool enabled) { is_sanitizer_api_v_0_enabled_ = enabled; }
    static void SetScopedCustomElementRegistryEnabled(bool enabled) { is_scoped_custom_element_registry_enabled_ = enabled; }
    static void SetScriptedSpeechRecognitionEnabled(bool enabled) { is_scripted_speech_recognition_enabled_ = enabled; }
    static void SetScriptedSpeechSynthesisEnabled(bool enabled) { is_scripted_speech_synthesis_enabled_ = enabled; }
    static void SetScriptElementSupportsEnabled(bool enabled) { is_script_element_supports_enabled_ = enabled; }
    static void SetScrollbarWidthEnabled(bool enabled) { is_scrollbar_width_enabled_ = enabled; }
    static void SetScrollCustomizationEnabled(bool enabled) { is_scroll_customization_enabled_ = enabled; }
    static void SetScrollEndEventsEnabled(bool enabled) { is_scroll_end_events_enabled_ = enabled; }
    static void SetScrollTimelineEnabled(bool enabled) { is_scroll_timeline_enabled_ = enabled; }
    static void SetScrollTopLeftInteropEnabled(bool enabled) { is_scroll_top_left_interop_enabled_ = enabled; }
    static void SetScrollUpdateOptimizationsEnabled(bool enabled) { is_scroll_update_optimizations_enabled_ = enabled; }
    static void SetSecureContextFixForSharedWorkersEnabled(bool enabled) { is_secure_context_fix_for_shared_workers_enabled_ = enabled; }
    static void SetSecurePaymentConfirmationEnabled(bool enabled) { is_secure_payment_confirmation_enabled_ = enabled; }
    static void SetSecurePaymentConfirmationDebugEnabled(bool enabled) { is_secure_payment_confirmation_debug_enabled_ = enabled; }
    static void SetSecurePaymentConfirmationOptOutEnabled(bool enabled) { is_secure_payment_confirmation_opt_out_enabled_ = enabled; }
    static void SetSelfBrowserSurfaceConstraintEnabled(bool enabled) { is_self_browser_surface_constraint_enabled_ = enabled; }
    static void SetSendBeaconThrowForBlobWithNonSimpleTypeEnabled(bool enabled) { is_send_beacon_throw_for_blob_with_non_simple_type_enabled_ = enabled; }
    static void SetSendFullUserAgentAfterReductionEnabled(bool enabled) { is_send_full_user_agent_after_reduction_enabled_ = enabled; }
    static void SetSendMouseEventsDisabledFormControlsEnabled(bool enabled) { is_send_mouse_events_disabled_form_controls_enabled_ = enabled; }
    static void SetSensorExtraClassesEnabled(bool enabled) { is_sensor_extra_classes_enabled_ = enabled; }
    static void SetSerialEnabled(bool enabled) { is_serial_enabled_ = enabled; }
    static void SetSerialPortForgetEnabled(bool enabled) { is_serial_port_forget_enabled_ = enabled; }
    static void SetServiceWorkerClientLifecycleStateEnabled(bool enabled) { is_service_worker_client_lifecycle_state_enabled_ = enabled; }
    static void SetSharedArrayBufferEnabled(bool enabled) { is_shared_array_buffer_enabled_ = enabled; }
    static void SetSharedArrayBufferOnDesktopEnabled(bool enabled) { is_shared_array_buffer_on_desktop_enabled_ = enabled; }
    static void SetSharedArrayBufferUnrestrictedAccessAllowedEnabled(bool enabled) { is_shared_array_buffer_unrestricted_access_allowed_enabled_ = enabled; }
    static void SetSharedAutofillEnabled(bool enabled) { is_shared_autofill_enabled_ = enabled; }
    static void SetSharedStorageAPIEnabled(bool enabled) { is_shared_storage_api_enabled_ = enabled; }
    static void SetSharedWorkerEnabled(bool enabled) { is_shared_worker_enabled_ = enabled; }
    static void SetSignatureBasedIntegrityEnabled(bool enabled) { is_signature_based_integrity_enabled_ = enabled; }
    static void SetSiteInitiatedMirroringEnabled(bool enabled) { is_site_initiated_mirroring_enabled_ = enabled; }
    static void SetSkipAdEnabled(bool enabled) { is_skip_ad_enabled_ = enabled; }
    static void SetSkipTouchEventFilterEnabled(bool enabled) { is_skip_touch_event_filter_enabled_ = enabled; }
    static void SetSoftNavigationHeuristicsEnabled(bool enabled) { is_soft_navigation_heuristics_enabled_ = enabled; }
    static void SetSpeculationRulesEnabled(bool enabled) { is_speculation_rules_enabled_ = enabled; }
    static void SetSpeculationRulesFetchFromHeaderEnabled(bool enabled) { is_speculation_rules_fetch_from_header_enabled_ = enabled; }
    static void SetSpeculationRulesPrefetchProxyEnabled(bool enabled) { is_speculation_rules_prefetch_proxy_enabled_ = enabled; }
    static void SetSpeculationRulesPrefetchWithSubresourcesEnabled(bool enabled) { is_speculation_rules_prefetch_with_subresources_enabled_ = enabled; }
    static void SetSrcsetMaxDensityEnabled(bool enabled) { is_srcset_max_density_enabled_ = enabled; }
    static void SetStableBlinkFeaturesEnabled(bool enabled) { is_stable_blink_features_enabled_ = enabled; }
    static void SetStorageAccessAPIEnabled(bool enabled) { is_storage_access_api_enabled_ = enabled; }
    static void SetStorageAccessAPIForOriginExtensionEnabled(bool enabled) { is_storage_access_api_for_origin_extension_enabled_ = enabled; }
    static void SetStorageBucketsEnabled(bool enabled) { is_storage_buckets_enabled_ = enabled; }
    static void SetStorageFoundationAPIEnabled(bool enabled) { is_storage_foundation_api_enabled_ = enabled; }
    static void SetStrictMimeTypesForWorkersEnabled(bool enabled) { is_strict_mime_types_for_workers_enabled_ = enabled; }
    static void SetStylusHandwritingEnabled(bool enabled) { is_stylus_handwriting_enabled_ = enabled; }
    static void SetSupportsFontFormatTechEnabled(bool enabled) { is_supports_font_format_tech_enabled_ = enabled; }
    static void SetSurfaceSwitchingConstraintEnabled(bool enabled) { is_surface_switching_constraint_enabled_ = enabled; }
    static void SetSVGTextNGEnabled(bool enabled) { is_svg_text_ng_enabled_ = enabled; }
    static void SetSynthesizedKeyboardEventsForAccessibilityActionsEnabled(bool enabled) { is_synthesized_keyboard_events_for_accessibility_actions_enabled_ = enabled; }
    static void SetSystemAudioConstraintEnabled(bool enabled) { is_system_audio_constraint_enabled_ = enabled; }
    static void SetSystemWakeLockEnabled(bool enabled) { is_system_wake_lock_enabled_ = enabled; }
    static void SetTestFeatureEnabled(bool enabled) { is_test_feature_enabled_ = enabled; }
    static void SetTestFeatureDependentEnabled(bool enabled) { is_test_feature_dependent_enabled_ = enabled; }
    static void SetTestFeatureImpliedEnabled(bool enabled) { is_test_feature_implied_enabled_ = enabled; }
    static void SetTextDecoratingBoxEnabled(bool enabled) { is_text_decorating_box_enabled_ = enabled; }
    static void SetTextDetectorEnabled(bool enabled) { is_text_detector_enabled_ = enabled; }
    static void SetTextFragmentAPIEnabled(bool enabled) { is_text_fragment_api_enabled_ = enabled; }
    static void SetTextFragmentIdentifiersEnabled(bool enabled) { is_text_fragment_identifiers_enabled_ = enabled; }
    static void SetTextFragmentTapOpensContextMenuEnabled(bool enabled) { is_text_fragment_tap_opens_context_menu_enabled_ = enabled; }
    static void SetThrottleDisplayNoneAndVisibilityHiddenCrossOriginIframesEnabled(bool enabled)
    {
        is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_ = enabled;
    }
    static void SetTimerThrottlingForBackgroundTabsEnabled(bool enabled) { is_timer_throttling_for_background_tabs_enabled_ = enabled; }
    static void SetTimeZoneChangeEventEnabled(bool enabled) { is_time_zone_change_event_enabled_ = enabled; }
    static void SetTopicsAPIEnabled(bool enabled) { is_topics_api_enabled_ = enabled; }
    static void SetTouchActionEffectiveAtPointerDownEnabled(bool enabled) { is_touch_action_effective_at_pointer_down_enabled_ = enabled; }
    static void SetTouchDragAndContextMenuEnabled(bool enabled) { is_touch_drag_and_context_menu_enabled_ = enabled; }
    static void SetTouchDragOnShortPressEnabled(bool enabled) { is_touch_drag_on_short_press_enabled_ = enabled; }
    static void SetTouchEventFeatureDetectionEnabled(bool enabled) { is_touch_event_feature_detection_enabled_ = enabled; }
    static void SetTranslateServiceEnabled(bool enabled) { is_translate_service_enabled_ = enabled; }
    static void SetTrustedTypeBeforePolicyCreationEventEnabled(bool enabled) { is_trusted_type_before_policy_creation_event_enabled_ = enabled; }
    static void SetTrustedTypesUseCodeLikeEnabled(bool enabled) { is_trusted_types_use_code_like_enabled_ = enabled; }
    static void SetTrustTokensEnabled(bool enabled) { is_trust_tokens_enabled_ = enabled; }
    static void SetTrustTokensAlwaysAllowIssuanceEnabled(bool enabled) { is_trust_tokens_always_allow_issuance_enabled_ = enabled; }
    static void SetU2FSecurityKeyAPIEnabled(bool enabled) { is_u_2_f_security_key_api_enabled_ = enabled; }
    static void SetUnclosedFormControlIsInvalidEnabled(bool enabled) { is_unclosed_form_control_is_invalid_enabled_ = enabled; }
    static void SetUnexposedTaskIdsEnabled(bool enabled) { is_unexposed_task_ids_enabled_ = enabled; }
    static void SetUnrestrictedSharedArrayBufferEnabled(bool enabled) { is_unrestricted_shared_array_buffer_enabled_ = enabled; }
    static void SetURLPatternCompareComponentEnabled(bool enabled) { is_url_pattern_compare_component_enabled_ = enabled; }
    static void SetUserActivationSameOriginVisibilityEnabled(bool enabled) { is_user_activation_same_origin_visibility_enabled_ = enabled; }
    static void SetUserAgentClientHintEnabled(bool enabled) { is_user_agent_client_hint_enabled_ = enabled; }
    static void SetUserAgentReductionEnabled(bool enabled) { is_user_agent_reduction_enabled_ = enabled; }
    static void SetV8IdleTasksEnabled(bool enabled) { is_v8_idle_tasks_enabled_ = enabled; }
    static void SetVariableCOLRV1Enabled(bool enabled) { is_variable_colrv_1_enabled_ = enabled; }
    static void SetVideoAutoFullscreenEnabled(bool enabled) { is_video_auto_fullscreen_enabled_ = enabled; }
    static void SetVideoFullscreenOrientationLockEnabled(bool enabled) { is_video_fullscreen_orientation_lock_enabled_ = enabled; }
    static void SetVideoPlaybackQualityEnabled(bool enabled) { is_video_playback_quality_enabled_ = enabled; }
    static void SetVideoRotateToFullscreenEnabled(bool enabled) { is_video_rotate_to_fullscreen_enabled_ = enabled; }
    static void SetVideoTrackGeneratorEnabled(bool enabled) { is_video_track_generator_enabled_ = enabled; }
    static void SetVideoTrackGeneratorInWindowEnabled(bool enabled) { is_video_track_generator_in_window_enabled_ = enabled; }
    static void SetVideoTrackGeneratorInWorkerEnabled(bool enabled) { is_video_track_generator_in_worker_enabled_ = enabled; }
    static void SetVideoWakeLockOptimisationHiddenMutedEnabled(bool enabled) { is_video_wake_lock_optimisation_hidden_muted_enabled_ = enabled; }
    static void SetViewportHeightClientHintHeaderEnabled(bool enabled) { is_viewport_height_client_hint_header_enabled_ = enabled; }
    static void SetViewportMetaInteractiveWidgetPropertyEnabled(bool enabled) { is_viewport_meta_interactive_widget_property_enabled_ = enabled; }
    static void SetViewportSegmentsEnabled(bool enabled) { is_viewport_segments_enabled_ = enabled; }
    static void SetVisibilityCollapseColumnEnabled(bool enabled) { is_visibility_collapse_column_enabled_ = enabled; }
    static void SetVisibilityStateEntryEnabled(bool enabled) { is_visibility_state_entry_enabled_ = enabled; }
    static void SetWakeLockEnabled(bool enabled) { is_wake_lock_enabled_ = enabled; }
    static void SetWarnOnContentVisibilityRenderAccessEnabled(bool enabled) { is_warn_on_content_visibility_render_access_enabled_ = enabled; }
    static void SetWebAnimationsAPIEnabled(bool enabled) { is_web_animations_api_enabled_ = enabled; }
    static void SetWebAnimationsSVGEnabled(bool enabled) { is_web_animations_svg_enabled_ = enabled; }
    static void SetWebAppDarkModeEnabled(bool enabled) { is_web_app_dark_mode_enabled_ = enabled; }
    static void SetWebAppLaunchHandlerEnabled(bool enabled) { is_web_app_launch_handler_enabled_ = enabled; }
    static void SetWebAppLaunchQueueEnabled(bool enabled) { is_web_app_launch_queue_enabled_ = enabled; }
    static void SetWebAppsLockScreenEnabled(bool enabled) { is_web_apps_lock_screen_enabled_ = enabled; }
    static void SetWebAppTabStripEnabled(bool enabled) { is_web_app_tab_strip_enabled_ = enabled; }
    static void SetWebAppTranslationsEnabled(bool enabled) { is_web_app_translations_enabled_ = enabled; }
    static void SetWebAppUrlHandlingEnabled(bool enabled) { is_web_app_url_handling_enabled_ = enabled; }
    static void SetWebAppWindowControlsOverlayEnabled(bool enabled) { is_web_app_window_controls_overlay_enabled_ = enabled; }
    static void SetWebAssemblyCSPEnabled(bool enabled) { is_web_assembly_csp_enabled_ = enabled; }
    static void SetWebAssemblyExceptionsEnabled(bool enabled) { is_web_assembly_exceptions_enabled_ = enabled; }
    static void SetWebAuthEnabled(bool enabled) { is_web_auth_enabled_ = enabled; }
    static void SetWebAuthAuthenticatorAttachmentEnabled(bool enabled) { is_web_auth_authenticator_attachment_enabled_ = enabled; }
    static void SetWebAuthenticationConditionalUIEnabled(bool enabled) { is_web_authentication_conditional_ui_enabled_ = enabled; }
    static void SetWebAuthenticationDevicePublicKeyEnabled(bool enabled) { is_web_authentication_device_public_key_enabled_ = enabled; }
    static void SetWebAuthenticationLargeBlobExtensionEnabled(bool enabled) { is_web_authentication_large_blob_extension_enabled_ = enabled; }
    static void SetWebAuthenticationRemoteDesktopSupportEnabled(bool enabled) { is_web_authentication_remote_desktop_support_enabled_ = enabled; }
    static void SetWebBluetoothEnabled(bool enabled) { is_web_bluetooth_enabled_ = enabled; }
    static void SetWebBluetoothGetDevicesEnabled(bool enabled) { is_web_bluetooth_get_devices_enabled_ = enabled; }
    static void SetWebBluetoothScanningEnabled(bool enabled) { is_web_bluetooth_scanning_enabled_ = enabled; }
    static void SetWebBluetoothWatchAdvertisementsEnabled(bool enabled) { is_web_bluetooth_watch_advertisements_enabled_ = enabled; }
    static void SetWebCodecsEnabled(bool enabled) { is_webcodecs_enabled_ = enabled; }
    static void SetWebCodecsDequeueEventEnabled(bool enabled) { is_webcodecs_dequeue_event_enabled_ = enabled; }
    static void SetWebGLColorManagementEnabled(bool enabled) { is_webgl_color_management_enabled_ = enabled; }
    static void SetWebGLDeveloperExtensionsEnabled(bool enabled) { is_webgl_developer_extensions_enabled_ = enabled; }
    static void SetWebGLDraftExtensionsEnabled(bool enabled) { is_webgl_draft_extensions_enabled_ = enabled; }
    static void SetWebGLImageChromiumEnabled(bool enabled) { is_webgl_image_chromium_enabled_ = enabled; }
    static void SetWebGPUEnabled(bool enabled) { is_webgpu_enabled_ = enabled; }
    static void SetWebGPUDeveloperFeaturesEnabled(bool enabled) { is_webgpu_developer_features_enabled_ = enabled; }
    static void SetWebGPUImportTextureEnabled(bool enabled) { is_webgpu_import_texture_enabled_ = enabled; }
    static void SetWebHIDEnabled(bool enabled) { is_web_hid_enabled_ = enabled; }
    static void SetWebHIDExclusionFiltersOptionEnabled(bool enabled) { is_web_hid_exclusion_filters_option_enabled_ = enabled; }
    static void SetWebHIDOnServiceWorkersEnabled(bool enabled) { is_web_hid_on_service_workers_enabled_ = enabled; }
    static void SetWebKitScrollbarStylingEnabled(bool enabled) { is_web_kit_scrollbar_styling_enabled_ = enabled; }
    static void SetWebNFCEnabled(bool enabled) { is_web_nfc_enabled_ = enabled; }
    static void SetWebNFCMakeReadOnlyEnabled(bool enabled) { is_web_nfc_make_read_only_enabled_ = enabled; }
    static void SetWebOTPEnabled(bool enabled) { is_web_otp_enabled_ = enabled; }
    static void SetWebOTPAssertionFeaturePolicyEnabled(bool enabled) { is_web_otp_assertion_feature_policy_enabled_ = enabled; }
    static void SetWebPaymentAPICSPEnabled(bool enabled) { is_web_payment_api_csp_enabled_ = enabled; }
    static void SetWebShareEnabled(bool enabled) { is_web_share_enabled_ = enabled; }
    static void SetWebSocketStreamEnabled(bool enabled) { is_websocket_stream_enabled_ = enabled; }
    static void SetWebTransportCustomCertificatesEnabled(bool enabled) { is_web_transport_custom_certificates_enabled_ = enabled; }
    static void SetWebUSBEnabled(bool enabled) { is_web_usb_enabled_ = enabled; }
    static void SetWebUsbDeviceForgetEnabled(bool enabled) { is_web_usb_device_forget_enabled_ = enabled; }
    static void SetWebUSBOnDedicatedWorkersEnabled(bool enabled) { is_web_usb_on_dedicated_workers_enabled_ = enabled; }
    static void SetWebUSBOnServiceWorkersEnabled(bool enabled) { is_web_usb_on_service_workers_enabled_ = enabled; }
    static void SetWebVTTRegionsEnabled(bool enabled) { is_web_vtt_regions_enabled_ = enabled; }
    static void SetWebXREnabled(bool enabled) { is_web_xr_enabled_ = enabled; }
    static void SetWebXRAnchorsEnabled(bool enabled) { is_web_xr_anchors_enabled_ = enabled; }
    static void SetWebXRARModuleEnabled(bool enabled) { is_web_xr_ar_module_enabled_ = enabled; }
    static void SetWebXRCameraAccessEnabled(bool enabled) { is_web_xr_camera_access_enabled_ = enabled; }
    static void SetWebXRDepthEnabled(bool enabled) { is_web_xr_depth_enabled_ = enabled; }
    static void SetWebXRHandInputEnabled(bool enabled) { is_web_xr_hand_input_enabled_ = enabled; }
    static void SetWebXRHitTestEnabled(bool enabled) { is_web_xr_hit_test_enabled_ = enabled; }
    static void SetWebXRHitTestEntityTypesEnabled(bool enabled) { is_web_xr_hit_test_entity_types_enabled_ = enabled; }
    static void SetWebXRImageTrackingEnabled(bool enabled) { is_web_xr_image_tracking_enabled_ = enabled; }
    static void SetWebXRLightEstimationEnabled(bool enabled) { is_web_xr_light_estimation_enabled_ = enabled; }
    static void SetWebXRPlaneDetectionEnabled(bool enabled) { is_web_xr_plane_detection_enabled_ = enabled; }
    static void SetWebXRViewportScaleEnabled(bool enabled) { is_web_xr_viewport_scale_enabled_ = enabled; }
    static void SetWGIGamepadTriggerRumbleEnabled(bool enabled) { is_wgi_gamepad_trigger_rumble_enabled_ = enabled; }
    static void SetWindowDefaultStatusEnabled(bool enabled) { is_window_default_status_enabled_ = enabled; }
    static void SetWindowOpenNewPopupBehaviorEnabled(bool enabled) { is_window_open_new_popup_behavior_enabled_ = enabled; }
    static void SetWindowPlacementEnabled(bool enabled) { is_window_placement_enabled_ = enabled; }
    static void SetWindowPlacementEnhancedScreenLabelsEnabled(bool enabled) { is_window_placement_enhanced_screen_labels_enabled_ = enabled; }
    static void SetWindowPlacementFullscreenOnScreensChangeEnabled(bool enabled) { is_window_placement_fullscreen_on_screens_change_enabled_ = enabled; }
    static void SetZeroCopyTabCaptureEnabled(bool enabled) { is_zero_copy_tab_capture_enabled_ = enabled; }

private:
    friend class RuntimeEnabledFeaturesTestHelpers;

    static bool is_abort_signal_throw_if_aborted_enabled_;
    static bool is_abort_signal_timeout_enabled_;
    static bool is_accelerated_2d_canvas_enabled_;
    static bool is_accelerated_small_canvases_enabled_;
    static bool is_accessibility_aria_touch_passthrough_enabled_;
    static bool is_accessibility_aria_virtual_content_enabled_;
    static bool is_accessibility_expose_display_none_enabled_;
    static bool is_accessibility_expose_html_element_enabled_;
    static bool is_accessibility_expose_ignored_nodes_enabled_;
    static bool is_accessibility_object_model_enabled_;
    static bool is_accessibility_page_zoom_enabled_;
    static bool is_accessibility_use_ax_position_for_document_markers_enabled_;
    static bool is_address_space_enabled_;
    static bool is_ad_interest_group_api_enabled_;
    static bool is_ad_tagging_enabled_;
    static bool is_allow_content_initiated_data_url_navigations_enabled_;
    static bool is_android_downloadable_fonts_matching_enabled_;
    static bool is_animation_worklet_enabled_;
    static bool is_anonymous_iframe_enabled_;
    static bool is_aom_aria_relationship_properties_enabled_;
    static bool is_aria_touch_passthrough_enabled_;
    static bool is_attribution_reporting_enabled_;
    static bool is_audio_context_set_sink_id_enabled_;
    static bool is_audio_output_devices_enabled_;
    static bool is_audio_video_tracks_enabled_;
    static bool is_auto_dark_mode_enabled_;
    static bool is_auto_disable_accessibility_v_2_enabled_;
    static bool is_autofill_shadow_dom_enabled_;
    static bool is_automation_controlled_enabled_;
    static bool is_auto_picture_in_picture_enabled_;
    static bool is_autoplay_ignores_web_audio_enabled_;
    static bool is_backface_visibility_interop_enabled_;
    static bool is_back_forward_cache_enabled_;
    static bool is_back_forward_cache_experiment_http_header_enabled_;
    static bool is_back_forward_cache_not_restored_reasons_enabled_;
    static bool is_background_fetch_enabled_;
    static bool is_barcode_detector_enabled_;
    static bool is_batch_fetch_requests_enabled_;
    static bool is_before_match_event_enabled_;
    static bool is_bidi_caret_affinity_enabled_;
    static bool is_blink_extension_chrome_os_enabled_;
    static bool is_blink_extension_chrome_oshid_enabled_;
    static bool is_blink_extension_chrome_os_window_management_enabled_;
    static bool is_blink_runtime_call_stats_enabled_;
    static bool is_blocking_attribute_enabled_;
    static bool is_blocking_focus_without_user_activation_enabled_;
    static bool is_browser_verified_user_activation_keyboard_enabled_;
    static bool is_browser_verified_user_activation_mouse_enabled_;
    static bool is_cache_storage_code_cache_hint_enabled_;
    static bool is_canvas_2d_image_chromium_enabled_;
    static bool is_canvas_2d_layers_enabled_;
    static bool is_canvas_2d_scroll_path_into_view_enabled_;
    static bool is_canvas_color_management_v_2_enabled_;
    static bool is_canvas_hdr_enabled_;
    static bool is_canvas_image_smoothing_enabled_;
    static bool is_capability_delegation_fullscreen_request_enabled_;
    static bool is_capture_handle_enabled_;
    static bool is_check_visibility_enabled_;
    static bool is_clear_identity_in_can_make_payment_event_enabled_;
    static bool is_click_to_captured_pointer_enabled_;
    static bool is_client_hints_meta_equiv_delegate_ch_enabled_;
    static bool is_client_hints_meta_http_equiv_accept_ch_enabled_;
    static bool is_client_hint_third_party_delegation_enabled_;
    static bool is_clipboard_custom_formats_enabled_;
    static bool is_clipboard_svg_enabled_;
    static bool is_clipboard_unsanitized_content_enabled_;
    static bool is_close_watcher_enabled_;
    static bool is_cls_scroll_anchoring_enabled_;
    static bool is_coep_reflection_enabled_;
    static bool is_composite_bg_color_animation_enabled_;
    static bool is_composite_box_shadow_animation_enabled_;
    static bool is_composite_clip_path_animation_enabled_;
    static bool is_composited_selection_update_enabled_;
    static bool is_computed_accessibility_info_enabled_;
    static bool is_compute_pressure_enabled_;
    static bool is_conditional_focus_enabled_;
    static bool is_consolidated_movement_xy_enabled_;
    static bool is_contacts_manager_enabled_;
    static bool is_contacts_manager_extra_properties_enabled_;
    static bool is_content_index_enabled_;
    static bool is_content_visibility_auto_state_change_event_enabled_;
    static bool is_context_menu_enabled_;
    static bool is_cooperative_scheduling_enabled_;
    static bool is_cors_rfc_1918_enabled_;
    static bool is_cross_origin_opener_policy_reporting_enabled_;
    static bool is_css_anchor_positioning_enabled_;
    static bool is_css_at_rule_counter_style_image_symbols_enabled_;
    static bool is_css_at_rule_counter_style_speak_as_descriptor_enabled_;
    static bool is_css_at_supports_always_non_forgiving_parsing_enabled_;
    static bool is_css_calc_simplification_and_serialization_enabled_;
    static bool is_css_case_sensitive_selector_enabled_;
    static bool is_css_color_4_enabled_;
    static bool is_css_color_contrast_enabled_;
    static bool is_css_color_typed_om_enabled_;
    static bool is_css_container_queries_enabled_;
    static bool is_css_container_relative_units_enabled_;
    static bool is_css_container_skip_style_recalc_enabled_;
    static bool is_css_contain_size_1d_enabled_;
    static bool is_css_enumerated_custom_properties_enabled_;
    static bool is_css_focus_visible_enabled_;
    static bool is_css_foldables_enabled_;
    static bool is_css_font_face_auto_variable_range_enabled_;
    static bool is_css_font_face_src_tech_parsing_enabled_;
    static bool is_css_font_family_math_enabled_;
    static bool is_css_font_size_adjust_enabled_;
    static bool is_css_grid_template_property_interpolation_enabled_;
    static bool is_css_hex_alpha_color_enabled_;
    static bool is_css_hyphenate_limit_chars_enabled_;
    static bool is_css_ic_unit_enabled_;
    static bool is_css_independent_transform_properties_enabled_;
    static bool is_css_initial_letter_enabled_;
    static bool is_css_last_baseline_enabled_;
    static bool is_css_layout_api_enabled_;
    static bool is_css_lh_unit_enabled_;
    static bool is_css_logical_enabled_;
    static bool is_css_logical_overflow_enabled_;
    static bool is_css_marker_nested_pseudo_element_enabled_;
    static bool is_css_math_depth_enabled_;
    static bool is_css_math_shift_enabled_;
    static bool is_css_math_style_enabled_;
    static bool is_css_math_variant_enabled_;
    static bool is_css_media_queries_4_enabled_;
    static bool is_css_mix_blend_mode_plus_lighter_enabled_;
    static bool is_css_object_view_box_enabled_;
    static bool is_css_offset_path_ray_enabled_;
    static bool is_css_offset_path_ray_contain_enabled_;
    static bool is_css_offset_position_anchor_enabled_;
    static bool is_css_overflow_for_replaced_elements_enabled_;
    static bool is_css_paint_api_arguments_enabled_;
    static bool is_css_picture_in_picture_enabled_;
    static bool is_css_position_sticky_static_scroll_position_enabled_;
    static bool is_css_pseudo_autofill_enabled_;
    static bool is_css_pseudo_dir_enabled_;
    static bool is_css_pseudo_has_enabled_;
    static bool is_css_pseudo_playing_paused_enabled_;
    static bool is_css_scope_enabled_;
    static bool is_css_scrollbars_enabled_;
    static bool is_css_scroll_timeline_enabled_;
    static bool is_css_selector_fragment_anchor_enabled_;
    static bool is_css_snap_size_enabled_;
    static bool is_css_spelling_grammar_errors_enabled_;
    static bool is_css_style_queries_enabled_;
    static bool is_css_toggles_enabled_;
    static bool is_css_trigonometric_functions_enabled_;
    static bool is_css_variables_2_image_values_enabled_;
    static bool is_css_variables_2_transform_values_enabled_;
    static bool is_css_video_dynamic_range_media_queries_enabled_;
    static bool is_css_viewport_units_4_enabled_;
    static bool is_css_view_timeline_enabled_;
    static bool is_custom_element_default_style_enabled_;
    static bool is_database_enabled_;
    static bool is_decode_jpeg_420_images_to_yuv_enabled_;
    static bool is_decode_lossy_web_p_images_to_yuv_enabled_;
    static bool is_deferred_shaping_enabled_;
    static bool is_deflate_raw_compression_format_enabled_;
    static bool is_delegated_ink_trails_enabled_;
    static bool is_delivery_type_enabled_;
    static bool is_desktop_capture_disable_local_echo_control_enabled_;
    static bool is_desktop_pw_as_sub_apps_enabled_;
    static bool is_device_attributes_enabled_;
    static bool is_device_orientation_request_permission_enabled_;
    static bool is_device_posture_enabled_;
    static bool is_digital_goods_enabled_;
    static bool is_digital_goods_v_2_1_enabled_;
    static bool is_direct_sockets_enabled_;
    static bool is_disable_different_origin_subframe_dialog_suppression_enabled_;
    static bool is_disable_hardware_noise_suppression_enabled_;
    static bool is_display_cutout_api_enabled_;
    static bool is_display_surface_constraint_enabled_;
    static bool is_document_cookie_enabled_;
    static bool is_document_domain_enabled_;
    static bool is_document_picture_in_picture_api_enabled_;
    static bool is_document_policy_enabled_;
    static bool is_document_policy_document_domain_enabled_;
    static bool is_document_policy_negotiation_enabled_;
    static bool is_document_policy_sync_xhr_enabled_;
    static bool is_document_transition_enabled_;
    static bool is_document_write_enabled_;
    static bool is_early_hints_preload_for_navigation_opt_in_enabled_;
    static bool is_edit_context_enabled_;
    static bool is_element_super_rare_data_enabled_;
    static bool is_event_path_enabled_;
    static bool is_experimental_content_security_policy_features_enabled_;
    static bool is_experimental_js_profiler_markers_enabled_;
    static bool is_experimental_policies_enabled_;
    static bool is_experimental_web_snapshots_enabled_;
    static bool is_extended_text_metrics_enabled_;
    static bool is_extra_webgl_video_texture_metadata_enabled_;
    static bool is_eye_dropper_api_enabled_;
    static bool is_face_detector_enabled_;
    static bool is_fake_no_alloc_direct_call_for_testing_enabled_;
    static bool is_feature_policy_reporting_enabled_;
    static bool is_fed_cm_enabled_;
    static bool is_fed_cm_idp_signin_status_enabled_;
    static bool is_fed_cm_idp_signout_enabled_;
    static bool is_fed_cm_iframe_support_enabled_;
    static bool is_fed_cm_multiple_identity_providers_enabled_;
    static bool is_fenced_frames_enabled_;
    static bool is_fetch_upload_streaming_enabled_;
    static bool is_file_handling_enabled_;
    static bool is_file_handling_icons_enabled_;
    static bool is_file_system_enabled_;
    static bool is_file_system_access_enabled_;
    static bool is_file_system_access_access_handle_enabled_;
    static bool is_file_system_access_api_experimental_enabled_;
    static bool is_file_system_access_local_enabled_;
    static bool is_file_system_access_origin_private_enabled_;
    static bool is_file_system_sync_access_handle_async_interface_override_enabled_;
    static bool is_first_party_sets_enabled_;
    static bool is_fixed_elements_dont_overscroll_enabled_;
    static bool is_fledge_enabled_;
    static bool is_fluent_scrollbars_enabled_;
    static bool is_focusgroup_enabled_;
    static bool is_focusless_spatial_navigation_enabled_;
    static bool is_font_access_enabled_;
    static bool is_font_palette_enabled_;
    static bool is_font_src_local_matching_enabled_;
    static bool is_forced_colors_enabled_;
    static bool is_forced_colors_preserve_parent_color_enabled_;
    static bool is_force_eager_measure_memory_enabled_;
    static bool is_force_reduce_motion_enabled_;
    static bool is_force_taller_select_popup_enabled_;
    static bool is_formatted_text_enabled_;
    static bool is_form_rel_attribute_enabled_;
    static bool is_fractional_scroll_offsets_enabled_;
    static bool is_freeze_frames_on_visibility_enabled_;
    static bool is_gamepad_button_axis_events_enabled_;
    static bool is_get_display_media_enabled_;
    static bool is_get_display_media_set_enabled_;
    static bool is_get_display_media_set_auto_select_all_screens_enabled_;
    static bool is_group_effect_enabled_;
    static bool is_handwriting_recognition_enabled_;
    static bool is_hid_device_forget_enabled_;
    static bool is_highlight_api_enabled_;
    static bool is_highlight_inheritance_enabled_;
    static bool is_highlight_overlay_painting_enabled_;
    static bool is_highlight_pointer_events_enabled_;
    static bool is_href_translate_enabled_;
    static bool is_html_param_element_url_support_enabled_;
    static bool is_html_popup_attribute_enabled_;
    static bool is_html_select_menu_element_enabled_;
    static bool is_idb_batch_get_all_enabled_;
    static bool is_idle_detection_enabled_;
    static bool is_implicit_root_scroller_enabled_;
    static bool is_inert_attribute_enabled_;
    static bool is_infinite_cull_rect_enabled_;
    static bool is_input_multiple_fields_ui_enabled_;
    static bool is_installed_app_enabled_;
    static bool is_keyboard_accessible_tooltip_enabled_;
    static bool is_keyboard_focusable_scrollers_enabled_;
    static bool is_lang_attribute_aware_form_control_ui_enabled_;
    static bool is_lang_attribute_aware_svg_text_enabled_;
    static bool is_layout_ng_enabled_;
    static bool is_layout_ng_block_fragmentation_enabled_;
    static bool is_layout_ng_block_in_inline_enabled_;
    static bool is_layout_ng_delay_scroll_offset_clamping_enabled_;
    static bool is_layout_ng_flex_fragmentation_enabled_;
    static bool is_layout_ng_foreign_object_enabled_;
    static bool is_layout_ng_frame_set_enabled_;
    static bool is_layout_ng_grid_fragmentation_enabled_;
    static bool is_layout_ng_printing_enabled_;
    static bool is_layout_ng_subgrid_enabled_;
    static bool is_layout_ng_table_fragmentation_enabled_;
    static bool is_layout_ngvtt_cue_enabled_;
    static bool is_lazy_frame_loading_enabled_;
    static bool is_lazy_frame_visible_load_time_metrics_enabled_;
    static bool is_lazy_image_loading_enabled_;
    static bool is_lazy_image_visible_load_time_metrics_enabled_;
    static bool is_lazy_initialize_media_controls_enabled_;
    static bool is_lcp_animated_images_web_exposed_enabled_;
    static bool is_legacy_windows_d_write_font_fallback_enabled_;
    static bool is_machine_learning_common_enabled_;
    static bool is_machine_learning_model_loader_enabled_;
    static bool is_machine_learning_neural_network_enabled_;
    static bool is_managed_configuration_enabled_;
    static bool is_mathml_core_enabled_;
    static bool is_measure_memory_enabled_;
    static bool is_media_capabilities_dynamic_range_enabled_;
    static bool is_media_capabilities_encoding_info_enabled_;
    static bool is_media_capabilities_spatial_audio_enabled_;
    static bool is_media_capture_enabled_;
    static bool is_media_capture_background_blur_enabled_;
    static bool is_media_cast_overlay_button_enabled_;
    static bool is_media_controls_expand_gesture_enabled_;
    static bool is_media_controls_overlay_play_button_enabled_;
    static bool is_media_element_volume_greater_than_one_enabled_;
    static bool is_media_engagement_bypass_autoplay_policies_enabled_;
    static bool is_media_latency_hint_enabled_;
    static bool is_media_query_navigation_controls_enabled_;
    static bool is_media_session_enabled_;
    static bool is_media_session_web_rtc_enabled_;
    static bool is_media_source_experimental_enabled_;
    static bool is_media_source_extensions_for_webcodecs_enabled_;
    static bool is_media_source_in_workers_enabled_;
    static bool is_media_source_in_workers_using_handle_enabled_;
    static bool is_media_source_new_abort_and_duration_enabled_;
    static bool is_media_source_stable_enabled_;
    static bool is_media_stream_track_in_window_enabled_;
    static bool is_media_stream_track_in_worker_enabled_;
    static bool is_media_stream_track_transfer_enabled_;
    static bool is_middle_click_autoscroll_enabled_;
    static bool is_mobile_layout_theme_enabled_;
    static bool is_mojo_js_enabled_;
    static bool is_mojo_js_test_enabled_;
    static bool is_mouse_subframe_no_implicit_capture_enabled_;
    static bool is_navigation_api_enabled_;
    static bool is_navigation_id_enabled_;
    static bool is_navigator_content_utils_enabled_;
    static bool is_net_info_downlink_max_enabled_;
    static bool is_never_slow_mode_enabled_;
    static bool is_new_flexbox_sizing_enabled_;
    static bool is_no_idle_encoding_for_web_tests_enabled_;
    static bool is_notification_constructor_enabled_;
    static bool is_notification_content_image_enabled_;
    static bool is_notifications_enabled_;
    static bool is_notification_triggers_enabled_;
    static bool is_off_main_thread_css_paint_enabled_;
    static bool is_offscreen_canvas_commit_enabled_;
    static bool is_offset_parent_new_spec_behavior_enabled_;
    static bool is_on_device_change_enabled_;
    static bool is_orientation_event_enabled_;
    static bool is_origin_isolation_header_enabled_;
    static bool is_origin_policy_enabled_;
    static bool is_origin_trials_sample_api_enabled_;
    static bool is_origin_trials_sample_api_dependent_enabled_;
    static bool is_origin_trials_sample_api_deprecation_enabled_;
    static bool is_origin_trials_sample_api_expiry_grace_period_enabled_;
    static bool is_origin_trials_sample_api_expiry_grace_period_third_party_enabled_;
    static bool is_origin_trials_sample_api_implied_enabled_;
    static bool is_origin_trials_sample_api_invalid_os_enabled_;
    static bool is_origin_trials_sample_api_navigation_enabled_;
    static bool is_origin_trials_sample_api_persistent_expiry_grace_period_enabled_;
    static bool is_origin_trials_sample_api_persistent_feature_enabled_;
    static bool is_origin_trials_sample_api_third_party_enabled_;
    static bool is_overscroll_customization_enabled_;
    static bool is_page_freeze_opt_in_enabled_;
    static bool is_page_freeze_opt_out_enabled_;
    static bool is_page_popup_enabled_;
    static bool is_paint_under_invalidation_checking_enabled_;
    static bool is_parakeet_enabled_;
    static bool is_parallel_primary_font_enabled_;
    static bool is_parallel_text_shaping_enabled_;
    static bool is_partitioned_cookies_enabled_;
    static bool is_password_reveal_enabled_;
    static bool is_payment_app_enabled_;
    static bool is_payment_method_change_event_enabled_;
    static bool is_payment_request_enabled_;
    static bool is_payment_request_merchant_validation_event_enabled_;
    static bool is_pending_beacon_api_enabled_;
    static bool is_percent_based_scrolling_enabled_;
    static bool is_performance_manager_instrumentation_enabled_;
    static bool is_periodic_background_sync_enabled_;
    static bool is_per_method_can_make_payment_quota_enabled_;
    static bool is_permissions_enabled_;
    static bool is_permissions_policy_unload_enabled_;
    static bool is_permissions_request_revoke_enabled_;
    static bool is_picture_in_picture_enabled_;
    static bool is_picture_in_picture_api_enabled_;
    static bool is_p_na_cl_enabled_;
    static bool is_pointer_lock_options_enabled_;
    static bool is_portals_enabled_;
    static bool is_precise_memory_info_enabled_;
    static bool is_prefer_non_composited_scrolling_enabled_;
    static bool is_prefers_color_scheme_client_hint_header_enabled_;
    static bool is_prefers_reduced_data_enabled_;
    static bool is_prefers_reduced_motion_client_hint_header_enabled_;
    static bool is_prefixed_storage_info_enabled_;
    static bool is_prefixed_video_fullscreen_enabled_;
    static bool is_prerender_2_enabled_;
    static bool is_prerender_2_related_features_enabled_;
    static bool is_presentation_enabled_;
    static bool is_priority_hints_enabled_;
    static bool is_privacy_sandbox_ads_api_s_enabled_;
    static bool is_private_network_access_non_secure_contexts_allowed_enabled_;
    static bool is_private_network_access_permission_prompt_enabled_;
    static bool is_push_messaging_enabled_;
    static bool is_push_messaging_subscription_change_enabled_;
    static bool is_quick_intensive_wake_up_throttling_after_loading_enabled_;
    static bool is_quota_change_enabled_;
    static bool is_reduce_user_agent_minor_version_enabled_;
    static bool is_reduce_user_agent_platform_os_cpu_enabled_;
    static bool is_region_capture_enabled_;
    static bool is_remote_playback_enabled_;
    static bool is_remote_playback_backend_enabled_;
    static bool is_remove_mobile_viewport_double_tap_enabled_;
    static bool is_render_blocking_status_enabled_;
    static bool is_render_priority_attribute_enabled_;
    static bool is_resource_timing_response_status_enabled_;
    static bool is_restrict_gamepad_access_enabled_;
    static bool is_rtc_audio_jitter_buffer_max_packets_enabled_;
    static bool is_rtc_ice_transport_extension_enabled_;
    static bool is_rtc_insertable_streams_enabled_;
    static bool is_rtc_quic_transport_enabled_;
    static bool is_rtc_rtp_header_extension_control_enabled_;
    static bool is_rtc_stats_relative_packet_arrival_delay_enabled_;
    static bool is_rtc_svc_scalability_mode_enabled_;
    static bool is_sanitizer_api_enabled_;
    static bool is_sanitizer_api_v_0_enabled_;
    static bool is_scoped_custom_element_registry_enabled_;
    static bool is_scripted_speech_recognition_enabled_;
    static bool is_scripted_speech_synthesis_enabled_;
    static bool is_script_element_supports_enabled_;
    static bool is_scrollbar_width_enabled_;
    static bool is_scroll_customization_enabled_;
    static bool is_scroll_end_events_enabled_;
    static bool is_scroll_timeline_enabled_;
    static bool is_scroll_top_left_interop_enabled_;
    static bool is_scroll_update_optimizations_enabled_;
    static bool is_secure_context_fix_for_shared_workers_enabled_;
    static bool is_secure_payment_confirmation_enabled_;
    static bool is_secure_payment_confirmation_debug_enabled_;
    static bool is_secure_payment_confirmation_opt_out_enabled_;
    static bool is_self_browser_surface_constraint_enabled_;
    static bool is_send_beacon_throw_for_blob_with_non_simple_type_enabled_;
    static bool is_send_full_user_agent_after_reduction_enabled_;
    static bool is_send_mouse_events_disabled_form_controls_enabled_;
    static bool is_sensor_extra_classes_enabled_;
    static bool is_serial_enabled_;
    static bool is_serial_port_forget_enabled_;
    static bool is_service_worker_client_lifecycle_state_enabled_;
    static bool is_shared_array_buffer_enabled_;
    static bool is_shared_array_buffer_on_desktop_enabled_;
    static bool is_shared_array_buffer_unrestricted_access_allowed_enabled_;
    static bool is_shared_autofill_enabled_;
    static bool is_shared_storage_api_enabled_;
    static bool is_shared_worker_enabled_;
    static bool is_signature_based_integrity_enabled_;
    static bool is_site_initiated_mirroring_enabled_;
    static bool is_skip_ad_enabled_;
    static bool is_skip_touch_event_filter_enabled_;
    static bool is_soft_navigation_heuristics_enabled_;
    static bool is_speculation_rules_enabled_;
    static bool is_speculation_rules_fetch_from_header_enabled_;
    static bool is_speculation_rules_prefetch_proxy_enabled_;
    static bool is_speculation_rules_prefetch_with_subresources_enabled_;
    static bool is_srcset_max_density_enabled_;
    static bool is_stable_blink_features_enabled_;
    static bool is_storage_access_api_enabled_;
    static bool is_storage_access_api_for_origin_extension_enabled_;
    static bool is_storage_buckets_enabled_;
    static bool is_storage_foundation_api_enabled_;
    static bool is_strict_mime_types_for_workers_enabled_;
    static bool is_stylus_handwriting_enabled_;
    static bool is_supports_font_format_tech_enabled_;
    static bool is_surface_switching_constraint_enabled_;
    static bool is_svg_text_ng_enabled_;
    static bool is_synthesized_keyboard_events_for_accessibility_actions_enabled_;
    static bool is_system_audio_constraint_enabled_;
    static bool is_system_wake_lock_enabled_;
    static bool is_test_feature_enabled_;
    static bool is_test_feature_dependent_enabled_;
    static bool is_test_feature_implied_enabled_;
    static bool is_text_decorating_box_enabled_;
    static bool is_text_detector_enabled_;
    static bool is_text_fragment_api_enabled_;
    static bool is_text_fragment_identifiers_enabled_;
    static bool is_text_fragment_tap_opens_context_menu_enabled_;
    static bool is_throttle_display_none_and_visibility_hidden_cross_origin_iframes_enabled_;
    static bool is_timer_throttling_for_background_tabs_enabled_;
    static bool is_time_zone_change_event_enabled_;
    static bool is_topics_api_enabled_;
    static bool is_touch_action_effective_at_pointer_down_enabled_;
    static bool is_touch_drag_and_context_menu_enabled_;
    static bool is_touch_drag_on_short_press_enabled_;
    static bool is_touch_event_feature_detection_enabled_;
    static bool is_translate_service_enabled_;
    static bool is_trusted_type_before_policy_creation_event_enabled_;
    static bool is_trusted_types_use_code_like_enabled_;
    static bool is_trust_tokens_enabled_;
    static bool is_trust_tokens_always_allow_issuance_enabled_;
    static bool is_u_2_f_security_key_api_enabled_;
    static bool is_unclosed_form_control_is_invalid_enabled_;
    static bool is_unexposed_task_ids_enabled_;
    static bool is_unrestricted_shared_array_buffer_enabled_;
    static bool is_url_pattern_compare_component_enabled_;
    static bool is_user_activation_same_origin_visibility_enabled_;
    static bool is_user_agent_client_hint_enabled_;
    static bool is_user_agent_reduction_enabled_;
    static bool is_v8_idle_tasks_enabled_;
    static bool is_variable_colrv_1_enabled_;
    static bool is_video_auto_fullscreen_enabled_;
    static bool is_video_fullscreen_orientation_lock_enabled_;
    static bool is_video_playback_quality_enabled_;
    static bool is_video_rotate_to_fullscreen_enabled_;
    static bool is_video_track_generator_enabled_;
    static bool is_video_track_generator_in_window_enabled_;
    static bool is_video_track_generator_in_worker_enabled_;
    static bool is_video_wake_lock_optimisation_hidden_muted_enabled_;
    static bool is_viewport_height_client_hint_header_enabled_;
    static bool is_viewport_meta_interactive_widget_property_enabled_;
    static bool is_viewport_segments_enabled_;
    static bool is_visibility_collapse_column_enabled_;
    static bool is_visibility_state_entry_enabled_;
    static bool is_wake_lock_enabled_;
    static bool is_warn_on_content_visibility_render_access_enabled_;
    static bool is_web_animations_api_enabled_;
    static bool is_web_animations_svg_enabled_;
    static bool is_web_app_dark_mode_enabled_;
    static bool is_web_app_launch_handler_enabled_;
    static bool is_web_app_launch_queue_enabled_;
    static bool is_web_apps_lock_screen_enabled_;
    static bool is_web_app_tab_strip_enabled_;
    static bool is_web_app_translations_enabled_;
    static bool is_web_app_url_handling_enabled_;
    static bool is_web_app_window_controls_overlay_enabled_;
    static bool is_web_assembly_csp_enabled_;
    static bool is_web_assembly_exceptions_enabled_;
    static bool is_web_auth_enabled_;
    static bool is_web_auth_authenticator_attachment_enabled_;
    static bool is_web_authentication_conditional_ui_enabled_;
    static bool is_web_authentication_device_public_key_enabled_;
    static bool is_web_authentication_large_blob_extension_enabled_;
    static bool is_web_authentication_remote_desktop_support_enabled_;
    static bool is_web_bluetooth_enabled_;
    static bool is_web_bluetooth_get_devices_enabled_;
    static bool is_web_bluetooth_scanning_enabled_;
    static bool is_web_bluetooth_watch_advertisements_enabled_;
    static bool is_webcodecs_enabled_;
    static bool is_webcodecs_dequeue_event_enabled_;
    static bool is_webgl_color_management_enabled_;
    static bool is_webgl_developer_extensions_enabled_;
    static bool is_webgl_draft_extensions_enabled_;
    static bool is_webgl_image_chromium_enabled_;
    static bool is_webgpu_enabled_;
    static bool is_webgpu_developer_features_enabled_;
    static bool is_webgpu_import_texture_enabled_;
    static bool is_web_hid_enabled_;
    static bool is_web_hid_exclusion_filters_option_enabled_;
    static bool is_web_hid_on_service_workers_enabled_;
    static bool is_web_kit_scrollbar_styling_enabled_;
    static bool is_web_nfc_enabled_;
    static bool is_web_nfc_make_read_only_enabled_;
    static bool is_web_otp_enabled_;
    static bool is_web_otp_assertion_feature_policy_enabled_;
    static bool is_web_payment_api_csp_enabled_;
    static bool is_web_share_enabled_;
    static bool is_websocket_stream_enabled_;
    static bool is_web_transport_custom_certificates_enabled_;
    static bool is_web_usb_enabled_;
    static bool is_web_usb_device_forget_enabled_;
    static bool is_web_usb_on_dedicated_workers_enabled_;
    static bool is_web_usb_on_service_workers_enabled_;
    static bool is_web_vtt_regions_enabled_;
    static bool is_web_xr_enabled_;
    static bool is_web_xr_anchors_enabled_;
    static bool is_web_xr_ar_module_enabled_;
    static bool is_web_xr_camera_access_enabled_;
    static bool is_web_xr_depth_enabled_;
    static bool is_web_xr_hand_input_enabled_;
    static bool is_web_xr_hit_test_enabled_;
    static bool is_web_xr_hit_test_entity_types_enabled_;
    static bool is_web_xr_image_tracking_enabled_;
    static bool is_web_xr_light_estimation_enabled_;
    static bool is_web_xr_plane_detection_enabled_;
    static bool is_web_xr_viewport_scale_enabled_;
    static bool is_wgi_gamepad_trigger_rumble_enabled_;
    static bool is_window_default_status_enabled_;
    static bool is_window_open_new_popup_behavior_enabled_;
    static bool is_window_placement_enabled_;
    static bool is_window_placement_enhanced_screen_labels_enabled_;
    static bool is_window_placement_fullscreen_on_screens_change_enabled_;
    static bool is_zero_copy_tab_capture_enabled_;
};

class PLATFORM_EXPORT RuntimeEnabledFeatures : public RuntimeEnabledFeaturesBase {
    STATIC_ONLY(RuntimeEnabledFeatures);

    // Only the following friends are allowed to use the setters defined in the
    // protected section of RuntimeEnabledFeaturesBase. Normally, unit tests
    // should use the ScopedFeatureNameForTest classes defined in
    // platform/testing/runtime_enabled_features_test_helpers.h.
    friend class DevToolsEmulator;
    friend class InternalRuntimeFlags;
    friend class V8ContextSnapshotImpl;
    friend class WebRuntimeFeaturesBase;
    friend class WebRuntimeFeatures;
    friend class WebView;
    FRIEND_TEST_ALL_PREFIXES(RuntimeEnabledFeaturesTest, Relationship);
    FRIEND_TEST_ALL_PREFIXES(RuntimeEnabledFeaturesTest, BackupRestore);
    FRIEND_TEST_ALL_PREFIXES(RuntimeEnabledFeaturesTest, OriginTrialsByRuntimeEnabled);
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_PLATFORM_RUNTIME_ENABLED_FEATURES_H_
