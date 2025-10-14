// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#ifndef GPU_CONFIG_GPU_DRIVER_BUG_LIST_ARRAYS_AND_STRUCTS_AUTOGEN_H_
#define GPU_CONFIG_GPU_DRIVER_BUG_LIST_ARRAYS_AND_STRUCTS_AUTOGEN_H_

#include "gpu/config/gpu_driver_bug_workaround_type.h"

namespace gpu {
const int kFeatureListForWorkaroundsEntry17[1] = {
    EXIT_ON_CONTEXT_LOST,
};

const GpuControlList::More kMoreForEntry17_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry19[1] = {
    DISABLE_DEPTH_TEXTURE,
};

const char* const kDisabledExtensionsForEntry19[1] = {
    "GL_OES_depth_texture",
};

const uint32_t kCrBugsForWorkaroundsEntry19[2] = {
    682075,
    1042214,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry19 = {
    nullptr,
    "Adreno \\(TM\\) 2.*",
    nullptr,
    nullptr,
};

const GpuControlList::More kMoreForEntry19_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry26[1] = {
    DISABLE_D3D11,
};

const GpuControlList::More kMoreForEntry26_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry31[1] = {
    USE_VIRTUALIZED_GL_CONTEXTS,
};

const uint32_t kCrBugsForWorkaroundsEntry31[6] = {
    154715,
    10068,
    269829,
    294779,
    285292,
    1018528,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry31 = {
    "ARM.*",
    "Mali-[T34].*",
    nullptr,
    nullptr,
};

const GpuControlList::More kMoreForEntry31_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry33[1] = {
    USE_VIRTUALIZED_GL_CONTEXTS,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry33 = {
    "Imagination.*",
    nullptr,
    nullptr,
    nullptr,
};

const GpuControlList::More kMoreForEntry33_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry54[1] = {
    CLEAR_UNIFORMS_BEFORE_FIRST_PROGRAM_USE,
};

const uint32_t kCrBugsForWorkaroundsEntry54[2] = {
    124764,
    349137,
};

const GpuControlList::More kMoreForEntry54_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::More kMoreForEntry54_619971032Exception0 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry70[1] = {
    DISABLE_D3D11,
};

const uint32_t kCrBugsForWorkaroundsEntry70[1] = {
    349929,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry70 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "8.17.12.6973", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry70_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry86[1] = {
    DISABLE_D3D11,
};

const uint32_t kCrBugsForWorkaroundsEntry86[1] = {
    395861,
};

const GpuControlList::More kMoreForEntry86_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry87[1] = {
    DISABLE_D3D11,
};

const uint32_t kCrBugsForWorkaroundsEntry87[1] = {
    402134,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry87 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "8.17.10.1070", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry87_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry92[1] = {
    DISABLE_D3D11,
};

const uint32_t kCrBugsForWorkaroundsEntry92[1] = {
    363721,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry92 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "9.18.0.0", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry92_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry100[1] = {
    DISABLE_D3D11,
};

const uint32_t kCrBugsForWorkaroundsEntry100[3] = {
    451420,
    721121,
    755722,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry100 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "20.19.0.32837", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry100_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry132[1] = {
    MSAA_IS_SLOW,
};

const uint32_t kCrBugsForWorkaroundsEntry132[2] = {
    527565,
    1298585,
};

const GpuControlList::More kMoreForEntry132_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::More kMoreForEntry132_619971032Exception0 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry149[1] = {
    DISABLE_DIRECT_COMPOSITION,
};

const uint32_t kCrBugsForWorkaroundsEntry149[1] = {
    588588,
};

const GpuControlList::More kMoreForEntry149_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry165[1] = {
    UNPACK_OVERLAPPING_ROWS_SEPARATELY_UNPACK_BUFFER,
};

const uint32_t kCrBugsForWorkaroundsEntry165[1] = {
    596774,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry165 = {
    "NVIDIA.*",
    nullptr,
    nullptr,
    nullptr,
};

const GpuControlList::More kMoreForEntry165_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry170[1] = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

const uint32_t kCrBugsForWorkaroundsEntry170[1] = {
    621190,
};

const GpuControlList::More kMoreForEntry170_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry185[1] = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

const uint32_t kCrBugsForWorkaroundsEntry185[1] = {
    635319,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry185 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "21.21.13.7576", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry185_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry192[1] = {
    DECODE_ENCODE_SRGB_FOR_GENERATEMIPMAP,
};

const uint32_t kCrBugsForWorkaroundsEntry192[1] = {
    634519,
};

const GpuControlList::More kMoreForEntry192_619971032 = {
    GpuControlList::kGLTypeGL, // gl_type
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "4.4", nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::More kMoreForEntry192_619971032Exception0 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry206[2] = {
    "GL_KHR_blend_equation_advanced",
    "GL_KHR_blend_equation_advanced_coherent",
};

const uint32_t kCrBugsForWorkaroundsEntry206[1] = {
    661715,
};

const GpuControlList::More kMoreForEntry206_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry207[1] = {
    DECODE_ENCODE_SRGB_FOR_GENERATEMIPMAP,
};

const uint32_t kCrBugsForWorkaroundsEntry207[1] = {
    634519,
};

const GpuControlList::More kMoreForEntry207_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry213[1] = {
    USE_VIRTUALIZED_GL_CONTEXTS,
};

const uint32_t kCrBugsForWorkaroundsEntry213[1] = {
    678508,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry213 = {
    "ARM.*",
    "Mali-G.*",
    nullptr,
    nullptr,
};

const GpuControlList::More kMoreForEntry213_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry215[1] = {
    USE_GPU_DRIVER_WORKAROUND_FOR_TESTING,
};

const uint32_t kCrBugsForWorkaroundsEntry215[1] = {
    682912,
};

const GpuControlList::More kMoreForEntry215_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    1, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry219[1] = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

const uint32_t kCrBugsForWorkaroundsEntry219[2] = {
    623029,
    1025427,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry219 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "23.20.826.5120", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry219_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry220[1] = {
    DISABLE_NV12_DXGI_VIDEO,
};

const uint32_t kCrBugsForWorkaroundsEntry220[1] = {
    644293,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry220 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "21.19.519.2", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry220_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry224[2] = {
    DISABLE_ACCELERATED_VP8_DECODE,
    DISABLE_ACCELERATED_VP9_DECODE,
};

const uint32_t kCrBugsForWorkaroundsEntry224[2] = {
    616318,
    667532,
};

const GpuControlList::More kMoreForEntry224_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry225[1] = {
    DISABLE_ACCELERATED_VP9_DECODE,
};

const uint32_t kCrBugsForWorkaroundsEntry225[1] = {
    616318,
};

const IntelGpuSeriesType kIntelGpuSeriesForEntry225[3] = {
    IntelGpuSeriesType::kBroadwell,
    IntelGpuSeriesType::kSkylake,
    IntelGpuSeriesType::kCherrytrail,
};

const GpuControlList::More kMoreForEntry225_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry226[1] = {
    DISABLE_ACCELERATED_VP9_DECODE,
};

const uint32_t kCrBugsForWorkaroundsEntry226[1] = {
    654111,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry226 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "21.20.16.4542", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry226_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry232[1] = {
    DISABLE_DELAYED_COPY_NV12,
};

const uint32_t kCrBugsForWorkaroundsEntry232[1] = {
    727216,
};

const GpuControlList::More kMoreForEntry232_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry233[1] = {
    DISABLE_DELAYED_COPY_NV12,
};

const uint32_t kCrBugsForWorkaroundsEntry233[1] = {
    728670,
};

const GpuControlList::More kMoreForEntry233_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry249[1] = {
    DISABLE_DIRECT_COMPOSITION,
};

const uint32_t kCrBugsForWorkaroundsEntry249[1] = {
    775898,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry249[1] = {
    { 0x10d8, 0x0 },
};

const GpuControlList::More kMoreForEntry249_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry256[1] = {
    ENABLE_WEBGL_TIMER_QUERY_EXTENSIONS,
};

const uint32_t kCrBugsForWorkaroundsEntry256[2] = {
    808744,
    870491,
};

const GpuControlList::More kMoreForEntry256_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::More kMoreForEntry256_619971032Exception0 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const char* const kDisabledWebGLExtensionsForEntry257[1] = {
    "WEBGL_lose_context",
};

const uint32_t kCrBugsForWorkaroundsEntry257[1] = {
    808744,
};

const GpuControlList::More kMoreForEntry257_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    2, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry261[1] = {
    DISABLE_D3D11,
};

const uint32_t kCrBugsForWorkaroundsEntry261[1] = {
    817286,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry261[1] = {
    { 0xfffe, 0x0 },
};

const GpuControlList::More kMoreForEntry261_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry277[1] = {
    DISABLE_DIRECT_COMPOSITION,
};

const uint32_t kCrBugsForWorkaroundsEntry277[1] = {
    800950,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry277 = {
    nullptr, // driver_vendor
    { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "8.17.10.1129", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry277_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry278[1] = {
    DISABLE_DIRECT_COMPOSITION,
};

const uint32_t kCrBugsForWorkaroundsEntry278[1] = {
    800950,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry278[1] = {
    { 0x6900, 0x0 },
};

const GpuControlList::More kMoreForEntry278_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry286[1] = {
    DISABLE_DIRECT_COMPOSITION,
};

const uint32_t kCrBugsForWorkaroundsEntry286[1] = {
    908069,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry286[1] = {
    { 0x1912, 0x0 },
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry286 = {
    nullptr, // driver_vendor
    { GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaIntelDriver, "0.0.100.0", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry286_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kUnsupported, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry289[1] = {
    DISABLE_ES3_GL_CONTEXT_FOR_TESTING,
};

const uint32_t kCrBugsForWorkaroundsEntry289[1] = {
    923134,
};

const GpuControlList::More kMoreForEntry289_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    3, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry300[1] = {
    DISABLE_DIRECT_COMPOSITION,
};

const uint32_t kCrBugsForWorkaroundsEntry300[3] = {
    775898,
    785648,
    9245627,
};

const IntelGpuSeriesType kIntelGpuSeriesForEntry300[2] = {
    IntelGpuSeriesType::kSandybridge,
    IntelGpuSeriesType::kIvybridge,
};

const GpuControlList::More kMoreForEntry300_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry303[1] = {
    DISABLE_NV12_DYNAMIC_TEXTURES,
};

const uint32_t kCrBugsForWorkaroundsEntry303[1] = {
    890227,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry303 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaIntelDriver, "0.0.99.9999", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry303_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry304[1] = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

const uint32_t kCrBugsForWorkaroundsEntry304[2] = {
    911349,
    1113893,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry304 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaNvidiaDriver, "456.38", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry304_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry308[1] = {
    DISABLE_DELAYED_COPY_NV12,
};

const uint32_t kCrBugsForWorkaroundsEntry308[1] = {
    983787,
};

const GpuControlList::More kMoreForEntry308_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry309[1] = {
    DISABLE_VP_SCALING,
};

const uint32_t kCrBugsForWorkaroundsEntry309[1] = {
    993233,
};

const GpuControlList::More kMoreForEntry309_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::More kMoreForEntry309_619971032Exception0 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::More kMoreForEntry309_619971032Exception1 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const char* const kDisabledExtensionsForEntry315[1] = {
    "GL_MESA_framebuffer_flip_y",
};

const uint32_t kCrBugsForWorkaroundsEntry315[1] = {
    964010,
};

const GpuControlList::More kMoreForEntry315_619971032 = {
    GpuControlList::kGLTypeGL, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry318[1] = {
    DISABLE_DIRECT_COMPOSITION,
};

const uint32_t kCrBugsForWorkaroundsEntry318[1] = {
    995396,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry318[1] = {
    { 0x694c, 0x0 },
};

const GpuControlList::More kMoreForEntry318_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry321[1] = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

const uint32_t kCrBugsForWorkaroundsEntry321[2] = {
    623029,
    1025427,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry321[3] = {
    { 0x9870, 0x0 },
    { 0x9874, 0x0 },
    { 0x98E4, 0x0 },
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry321 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.15000.37", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry321_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry322[1] = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

const uint32_t kCrBugsForWorkaroundsEntry322[2] = {
    932879,
    1025427,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry322 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "23.20.826.5120", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry322_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry323[1] = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

const uint32_t kCrBugsForWorkaroundsEntry323[2] = {
    932879,
    1025427,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry323[3] = {
    { 0x9870, 0x0 },
    { 0x9874, 0x0 },
    { 0x98E4, 0x0 },
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry323 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.15000.37", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry323_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry324[1] = {
    DISABLE_NV12_DYNAMIC_TEXTURES,
};

const uint32_t kCrBugsForWorkaroundsEntry324[2] = {
    1029855,
    1050666,
};

const GpuControlList::More kMoreForEntry324_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry328[1] = {
    DISABLE_D3D11_VIDEO_DECODER,
};

const uint32_t kCrBugsForWorkaroundsEntry328[1] = {
    1041166,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry328 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaNvidiaDriver, "451.48", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry328_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry329[1] = {
    LIMIT_D3D11_VIDEO_DECODER_TO_11_0,
};

const uint32_t kCrBugsForWorkaroundsEntry329[1] = {
    1012464,
};

const GpuControlList::More kMoreForEntry329_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry332[1] = {
    USE_EMPTY_VIDEO_HDR_METADATA,
};

const uint32_t kCrBugsForWorkaroundsEntry332[1] = {
    1045586,
};

const GpuControlList::More kMoreForEntry332_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry336[1] = {
    DISABLE_DXVA_VIDEO_DECODER,
};

const uint32_t kCrBugsForWorkaroundsEntry336[1] = {
    625785,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry336[2] = {
    { 0x15d8, 0x0 },
    { 0x15dd, 0x0 },
};

const GpuControlList::More kMoreForEntry336_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry336Exception0 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.11030.2", "26.20.11999.99999" }, // driver_version
};

const GpuControlList::More kMoreForEntry336_619971032Exception0 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry336Exception1 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.12020.15", "26.20.12999.99999" }, // driver_version
};

const GpuControlList::More kMoreForEntry336_619971032Exception1 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry336Exception2 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.13001.27002", "26.20.13999.99999" }, // driver_version
};

const GpuControlList::More kMoreForEntry336_619971032Exception2 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry336Exception3 = {
    nullptr, // driver_vendor
    { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.14001.7001", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry336_619971032Exception3 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry337[1] = {
    DISABLE_ACCELERATED_H264_ENCODE,
};

const uint32_t kCrBugsForWorkaroundsEntry337[2] = {
    1058583,
    1263058,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry337 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "24.21.13.9858", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry337_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry338[1] = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

const uint32_t kCrBugsForWorkaroundsEntry338[1] = {
    1062653,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry338 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.100.7755", nullptr }, // driver_version
};

const IntelGpuSeriesType kIntelGpuSeriesForEntry338[1] = {
    IntelGpuSeriesType::kIcelake,
};

const GpuControlList::More kMoreForEntry338_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry339[1] = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

const uint32_t kCrBugsForWorkaroundsEntry339[1] = {
    971952,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry339 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "20.19.15.4285", "20.19.15.4380" }, // driver_version
};

const IntelGpuSeriesType kIntelGpuSeriesForEntry339[1] = {
    IntelGpuSeriesType::kSkylake,
};

const GpuControlList::More kMoreForEntry339_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry340[1] = {
    DISABLE_DXGI_ZERO_COPY_VIDEO,
};

const uint32_t kCrBugsForWorkaroundsEntry340[1] = {
    971952,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry340 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.18.15.4256", "10.18.15.4293" }, // driver_version
};

const IntelGpuSeriesType kIntelGpuSeriesForEntry340[1] = {
    IntelGpuSeriesType::kSkylake,
};

const GpuControlList::More kMoreForEntry340_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry343[1] = {
    DISABLE_IMAGEBITMAP_FROM_VIDEO_USING_GPU,
};

const uint32_t kCrBugsForWorkaroundsEntry343[2] = {
    1098445,
    1105923,
};

const GpuControlList::GLStrings kGLStringsForWorkaroundsEntry343 = {
    nullptr,
    ".*Direct3D9.*",
    nullptr,
    nullptr,
};

const GpuControlList::More kMoreForEntry343_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry344[1] = {
    DISABLE_ACCELERATED_VP8_DECODE,
};

const uint32_t kCrBugsForWorkaroundsEntry344[1] = {
    1094840,
};

const GpuControlList::More kMoreForEntry344_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry345[1] = {
    DISABLE_DECODE_SWAP_CHAIN,
};

const uint32_t kCrBugsForWorkaroundsEntry345[1] = {
    1107403,
};

const GpuControlList::More kMoreForEntry345_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry347[1] = {
    ENABLE_BGRA8_OVERLAYS_WITH_YUV_OVERLAY_SUPPORT,
};

const uint32_t kCrBugsForWorkaroundsEntry347[1] = {
    1119491,
};

const GpuControlList::More kMoreForEntry347_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry352[1] = {
    DISABLE_D3D11_VIDEO_DECODER,
};

const uint32_t kCrBugsForWorkaroundsEntry352[1] = {
    1038006,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry352[1] = {
    { 0x0166, 0x0 },
};

const GpuControlList::More kMoreForEntry352_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry353[1] = {
    DISABLE_D3D11_VIDEO_DECODER,
};

const uint32_t kCrBugsForWorkaroundsEntry353[1] = {
    1038006,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry353[1] = {
    { 0x8a56, 0x0 },
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry353 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26", "27" }, // driver_version
};

const GpuControlList::More kMoreForEntry353_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry354[1] = {
    DISABLE_D3D11_VIDEO_DECODER,
};

const uint32_t kCrBugsForWorkaroundsEntry354[1] = {
    1126834,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry354[2] = {
    { 0x98e4, 0x0 },
    { 0x15dd, 0x0 },
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry354 = {
    nullptr, // driver_vendor
    { GpuControlList::kBetween, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "24", "27" }, // driver_version
};

const GpuControlList::More kMoreForEntry354_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry360[1] = {
    MAX_MSAA_SAMPLE_COUNT_4,
};

const uint32_t kCrBugsForWorkaroundsEntry360[1] = {
    1145793,
};

const GpuControlList::More kMoreForEntry360_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry362[1] = {
    SUPPORTS_TWO_YUV_HARDWARE_OVERLAYS,
};

const uint32_t kCrBugsForWorkaroundsEntry362[1] = {
    1105618,
};

const IntelGpuSeriesType kIntelGpuSeriesForEntry362[4] = {
    IntelGpuSeriesType::kIcelake,
    IntelGpuSeriesType::kTigerlake,
    IntelGpuSeriesType::kAlderlake,
    IntelGpuSeriesType::kAlchemist,
};

const GpuControlList::More kMoreForEntry362_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry364[1] = {
    DISABLE_DIRECT_COMPOSITION_SW_VIDEO_OVERLAYS,
};

const uint32_t kCrBugsForWorkaroundsEntry364[2] = {
    1161215,
    1160217,
};

const GpuControlList::More kMoreForEntry364_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry371[1] = {
    DISABLE_DIRECT_COMPOSITION_SW_VIDEO_OVERLAYS,
};

const uint32_t kCrBugsForWorkaroundsEntry371[1] = {
    1192748,
};

const GpuControlList::More kMoreForEntry371_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry372[1] = {
    CHECK_YCBCR_STUDIO_G22_LEFT_P709_FOR_NV12_SUPPORT,
};

const uint32_t kCrBugsForWorkaroundsEntry372[1] = {
    1103852,
};

const GpuControlList::More kMoreForEntry372_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry374[1] = {
    DISALLOW_VP9_RESILIENT_DXVA_DECODING,
};

const uint32_t kCrBugsForWorkaroundsEntry374[1] = {
    1087422,
};

const GpuControlList::More kMoreForEntry374_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry376[1] = {
    DISABLE_MEDIA_FOUNDATION_HARDWARE_SECURITY,
};

const uint32_t kCrBugsForWorkaroundsEntry376[1] = {
    1219028,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry376[33] = {
    { 0x1f82, 0x0 },
    { 0x1f92, 0x0 },
    { 0x2182, 0x0 },
    { 0x2184, 0x0 },
    { 0x21d1, 0x0 },
    { 0x2191, 0x0 },
    { 0x1f08, 0x0 },
    { 0x1f06, 0x0 },
    { 0x1f47, 0x0 },
    { 0x1f42, 0x0 },
    { 0x1f51, 0x0 },
    { 0x1f11, 0x0 },
    { 0x1f02, 0x0 },
    { 0x1f07, 0x0 },
    { 0x1ec2, 0x0 },
    { 0x1ec7, 0x0 },
    { 0x1e84, 0x0 },
    { 0x1f50, 0x0 },
    { 0x1f10, 0x0 },
    { 0x1e82, 0x0 },
    { 0x1e87, 0x0 },
    { 0x1e81, 0x0 },
    { 0x1ed0, 0x0 },
    { 0x1e90, 0x0 },
    { 0x1e07, 0x0 },
    { 0x1e04, 0x0 },
    { 0x1eb1, 0x0 },
    { 0x1eb6, 0x0 },
    { 0x1eb0, 0x0 },
    { 0x1eb5, 0x0 },
    { 0x1e02, 0x0 },
    { 0x1e30, 0x0 },
    { 0x1eb8, 0x0 },
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry376 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.21.14.4140", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry376_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry377[1] = {
    DISABLE_MEDIA_FOUNDATION_HARDWARE_SECURITY,
};

const uint32_t kCrBugsForWorkaroundsEntry377[1] = {
    1219028,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry377[31] = {
    { 0x1d01, 0x0 },
    { 0x1d10, 0x0 },
    { 0x1d12, 0x0 },
    { 0x1c81, 0x0 },
    { 0x1c82, 0x0 },
    { 0x1c83, 0x0 },
    { 0x1c8c, 0x0 },
    { 0x1c8d, 0x0 },
    { 0x1c8f, 0x0 },
    { 0x1c92, 0x0 },
    { 0x1c02, 0x0 },
    { 0x1c03, 0x0 },
    { 0x1c20, 0x0 },
    { 0x1c23, 0x0 },
    { 0x1c60, 0x0 },
    { 0x1c61, 0x0 },
    { 0x1c62, 0x0 },
    { 0x1b81, 0x0 },
    { 0x1b82, 0x0 },
    { 0x1b83, 0x0 },
    { 0x1b84, 0x0 },
    { 0x1ba0, 0x0 },
    { 0x1ba1, 0x0 },
    { 0x1ba2, 0x0 },
    { 0x1be0, 0x0 },
    { 0x1be1, 0x0 },
    { 0x1b06, 0x0 },
    { 0x1b00, 0x0 },
    { 0x1b02, 0x0 },
    { 0x17e4, 0x0 },
    { 0x174d, 0x0 },
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry377 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.21.14.4140", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry377_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry380[1] = {
    NO_DOWNSCALED_OVERLAY_PROMOTION,
};

const uint32_t kCrBugsForWorkaroundsEntry380[1] = {
    1245835,
};

const GpuControlList::More kMoreForEntry380_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry387[3] = {
    DISABLE_ACCELERATED_AV1_DECODE,
    DISABLE_ACCELERATED_VP8_DECODE,
    DISABLE_ACCELERATED_VP9_DECODE,
};

const uint32_t kCrBugsForWorkaroundsEntry387[2] = {
    822644,
    1187900,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry387[314] = {
    { 0x130f, 0x0 },
    { 0x6700, 0x0 },
    { 0x6701, 0x0 },
    { 0x6702, 0x0 },
    { 0x6703, 0x0 },
    { 0x6704, 0x0 },
    { 0x6705, 0x0 },
    { 0x6706, 0x0 },
    { 0x6707, 0x0 },
    { 0x6708, 0x0 },
    { 0x6709, 0x0 },
    { 0x6718, 0x0 },
    { 0x6719, 0x0 },
    { 0x671c, 0x0 },
    { 0x671d, 0x0 },
    { 0x671f, 0x0 },
    { 0x6720, 0x0 },
    { 0x6721, 0x0 },
    { 0x6722, 0x0 },
    { 0x6723, 0x0 },
    { 0x6724, 0x0 },
    { 0x6725, 0x0 },
    { 0x6726, 0x0 },
    { 0x6727, 0x0 },
    { 0x6728, 0x0 },
    { 0x6729, 0x0 },
    { 0x6738, 0x0 },
    { 0x6739, 0x0 },
    { 0x673e, 0x0 },
    { 0x6740, 0x0 },
    { 0x6741, 0x0 },
    { 0x6742, 0x0 },
    { 0x6743, 0x0 },
    { 0x6744, 0x0 },
    { 0x6745, 0x0 },
    { 0x6746, 0x0 },
    { 0x6747, 0x0 },
    { 0x6748, 0x0 },
    { 0x6749, 0x0 },
    { 0x674a, 0x0 },
    { 0x6750, 0x0 },
    { 0x6751, 0x0 },
    { 0x6758, 0x0 },
    { 0x6759, 0x0 },
    { 0x675b, 0x0 },
    { 0x675d, 0x0 },
    { 0x675f, 0x0 },
    { 0x6760, 0x0 },
    { 0x6761, 0x0 },
    { 0x6762, 0x0 },
    { 0x6763, 0x0 },
    { 0x6764, 0x0 },
    { 0x6765, 0x0 },
    { 0x6766, 0x0 },
    { 0x6767, 0x0 },
    { 0x6768, 0x0 },
    { 0x6770, 0x0 },
    { 0x6771, 0x0 },
    { 0x6772, 0x0 },
    { 0x6778, 0x0 },
    { 0x6779, 0x0 },
    { 0x677b, 0x0 },
    { 0x6798, 0x0 },
    { 0x67b1, 0x0 },
    { 0x6821, 0x0 },
    { 0x683d, 0x0 },
    { 0x6840, 0x0 },
    { 0x6841, 0x0 },
    { 0x6842, 0x0 },
    { 0x6843, 0x0 },
    { 0x6849, 0x0 },
    { 0x6850, 0x0 },
    { 0x6858, 0x0 },
    { 0x6859, 0x0 },
    { 0x6880, 0x0 },
    { 0x6888, 0x0 },
    { 0x6889, 0x0 },
    { 0x688a, 0x0 },
    { 0x688c, 0x0 },
    { 0x688d, 0x0 },
    { 0x6898, 0x0 },
    { 0x6899, 0x0 },
    { 0x689b, 0x0 },
    { 0x689c, 0x0 },
    { 0x689d, 0x0 },
    { 0x689e, 0x0 },
    { 0x68a0, 0x0 },
    { 0x68a1, 0x0 },
    { 0x68a8, 0x0 },
    { 0x68a9, 0x0 },
    { 0x68b0, 0x0 },
    { 0x68b8, 0x0 },
    { 0x68b9, 0x0 },
    { 0x68ba, 0x0 },
    { 0x68be, 0x0 },
    { 0x68bf, 0x0 },
    { 0x68c0, 0x0 },
    { 0x68c1, 0x0 },
    { 0x68c7, 0x0 },
    { 0x68c8, 0x0 },
    { 0x68c9, 0x0 },
    { 0x68d8, 0x0 },
    { 0x68d9, 0x0 },
    { 0x68da, 0x0 },
    { 0x68de, 0x0 },
    { 0x68e0, 0x0 },
    { 0x68e1, 0x0 },
    { 0x68e4, 0x0 },
    { 0x68e5, 0x0 },
    { 0x68e8, 0x0 },
    { 0x68e9, 0x0 },
    { 0x68f1, 0x0 },
    { 0x68f2, 0x0 },
    { 0x68f8, 0x0 },
    { 0x68f9, 0x0 },
    { 0x68fa, 0x0 },
    { 0x68fe, 0x0 },
    { 0x9400, 0x0 },
    { 0x9401, 0x0 },
    { 0x9402, 0x0 },
    { 0x9403, 0x0 },
    { 0x9405, 0x0 },
    { 0x940a, 0x0 },
    { 0x940b, 0x0 },
    { 0x940f, 0x0 },
    { 0x9440, 0x0 },
    { 0x9441, 0x0 },
    { 0x9442, 0x0 },
    { 0x9443, 0x0 },
    { 0x9444, 0x0 },
    { 0x9446, 0x0 },
    { 0x944a, 0x0 },
    { 0x944b, 0x0 },
    { 0x944c, 0x0 },
    { 0x944e, 0x0 },
    { 0x9450, 0x0 },
    { 0x9452, 0x0 },
    { 0x9456, 0x0 },
    { 0x945a, 0x0 },
    { 0x945b, 0x0 },
    { 0x945e, 0x0 },
    { 0x9460, 0x0 },
    { 0x9462, 0x0 },
    { 0x946a, 0x0 },
    { 0x946b, 0x0 },
    { 0x947a, 0x0 },
    { 0x947b, 0x0 },
    { 0x9480, 0x0 },
    { 0x9487, 0x0 },
    { 0x9488, 0x0 },
    { 0x9489, 0x0 },
    { 0x948a, 0x0 },
    { 0x948f, 0x0 },
    { 0x9490, 0x0 },
    { 0x9491, 0x0 },
    { 0x9495, 0x0 },
    { 0x9498, 0x0 },
    { 0x949c, 0x0 },
    { 0x949e, 0x0 },
    { 0x949f, 0x0 },
    { 0x94a0, 0x0 },
    { 0x94a1, 0x0 },
    { 0x94a3, 0x0 },
    { 0x94b1, 0x0 },
    { 0x94b3, 0x0 },
    { 0x94b4, 0x0 },
    { 0x94b5, 0x0 },
    { 0x94b9, 0x0 },
    { 0x94c0, 0x0 },
    { 0x94c1, 0x0 },
    { 0x94c3, 0x0 },
    { 0x94c4, 0x0 },
    { 0x94c5, 0x0 },
    { 0x94c6, 0x0 },
    { 0x94c7, 0x0 },
    { 0x94c8, 0x0 },
    { 0x94c9, 0x0 },
    { 0x94cb, 0x0 },
    { 0x94cc, 0x0 },
    { 0x94cd, 0x0 },
    { 0x9500, 0x0 },
    { 0x9501, 0x0 },
    { 0x9504, 0x0 },
    { 0x9505, 0x0 },
    { 0x9506, 0x0 },
    { 0x9507, 0x0 },
    { 0x9508, 0x0 },
    { 0x9509, 0x0 },
    { 0x950f, 0x0 },
    { 0x9511, 0x0 },
    { 0x9515, 0x0 },
    { 0x9517, 0x0 },
    { 0x9519, 0x0 },
    { 0x9540, 0x0 },
    { 0x9541, 0x0 },
    { 0x9542, 0x0 },
    { 0x954e, 0x0 },
    { 0x954f, 0x0 },
    { 0x9552, 0x0 },
    { 0x9553, 0x0 },
    { 0x9555, 0x0 },
    { 0x9557, 0x0 },
    { 0x955f, 0x0 },
    { 0x9580, 0x0 },
    { 0x9581, 0x0 },
    { 0x9583, 0x0 },
    { 0x9586, 0x0 },
    { 0x9587, 0x0 },
    { 0x9588, 0x0 },
    { 0x9589, 0x0 },
    { 0x958a, 0x0 },
    { 0x958b, 0x0 },
    { 0x958c, 0x0 },
    { 0x958d, 0x0 },
    { 0x958e, 0x0 },
    { 0x958f, 0x0 },
    { 0x9590, 0x0 },
    { 0x9591, 0x0 },
    { 0x9593, 0x0 },
    { 0x9595, 0x0 },
    { 0x9596, 0x0 },
    { 0x9597, 0x0 },
    { 0x9598, 0x0 },
    { 0x9599, 0x0 },
    { 0x959b, 0x0 },
    { 0x95c0, 0x0 },
    { 0x95c2, 0x0 },
    { 0x95c4, 0x0 },
    { 0x95c5, 0x0 },
    { 0x95c6, 0x0 },
    { 0x95c7, 0x0 },
    { 0x95c9, 0x0 },
    { 0x95cc, 0x0 },
    { 0x95cd, 0x0 },
    { 0x95ce, 0x0 },
    { 0x95cf, 0x0 },
    { 0x9610, 0x0 },
    { 0x9611, 0x0 },
    { 0x9612, 0x0 },
    { 0x9613, 0x0 },
    { 0x9614, 0x0 },
    { 0x9615, 0x0 },
    { 0x9616, 0x0 },
    { 0x9640, 0x0 },
    { 0x9641, 0x0 },
    { 0x9642, 0x0 },
    { 0x9643, 0x0 },
    { 0x9644, 0x0 },
    { 0x9645, 0x0 },
    { 0x9647, 0x0 },
    { 0x9648, 0x0 },
    { 0x9649, 0x0 },
    { 0x964a, 0x0 },
    { 0x964b, 0x0 },
    { 0x964c, 0x0 },
    { 0x964e, 0x0 },
    { 0x964f, 0x0 },
    { 0x9710, 0x0 },
    { 0x9711, 0x0 },
    { 0x9712, 0x0 },
    { 0x9713, 0x0 },
    { 0x9714, 0x0 },
    { 0x9715, 0x0 },
    { 0x9802, 0x0 },
    { 0x9803, 0x0 },
    { 0x9804, 0x0 },
    { 0x9805, 0x0 },
    { 0x9806, 0x0 },
    { 0x9807, 0x0 },
    { 0x9808, 0x0 },
    { 0x9809, 0x0 },
    { 0x980a, 0x0 },
    { 0x9830, 0x0 },
    { 0x983d, 0x0 },
    { 0x9850, 0x0 },
    { 0x9851, 0x0 },
    { 0x9874, 0x0 },
    { 0x9900, 0x0 },
    { 0x9901, 0x0 },
    { 0x9903, 0x0 },
    { 0x9904, 0x0 },
    { 0x9905, 0x0 },
    { 0x9906, 0x0 },
    { 0x9907, 0x0 },
    { 0x9908, 0x0 },
    { 0x9909, 0x0 },
    { 0x990a, 0x0 },
    { 0x990b, 0x0 },
    { 0x990c, 0x0 },
    { 0x990d, 0x0 },
    { 0x990e, 0x0 },
    { 0x990f, 0x0 },
    { 0x9910, 0x0 },
    { 0x9913, 0x0 },
    { 0x9917, 0x0 },
    { 0x9918, 0x0 },
    { 0x9919, 0x0 },
    { 0x9990, 0x0 },
    { 0x9991, 0x0 },
    { 0x9992, 0x0 },
    { 0x9993, 0x0 },
    { 0x9994, 0x0 },
    { 0x9995, 0x0 },
    { 0x9996, 0x0 },
    { 0x9997, 0x0 },
    { 0x9998, 0x0 },
    { 0x9999, 0x0 },
    { 0x999a, 0x0 },
    { 0x999b, 0x0 },
    { 0x999c, 0x0 },
    { 0x999d, 0x0 },
    { 0x99a0, 0x0 },
    { 0x99a2, 0x0 },
    { 0x99a4, 0x0 },
};

const GpuControlList::More kMoreForEntry387_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry388[3] = {
    DISABLE_ACCELERATED_AV1_DECODE,
    DISABLE_ACCELERATED_VP8_DECODE,
    DISABLE_ACCELERATED_VP9_DECODE,
};

const uint32_t kCrBugsForWorkaroundsEntry388[2] = {
    822644,
    1187900,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry388[14] = {
    { 0x102, 0x0 },
    { 0x106, 0x0 },
    { 0x116, 0x0 },
    { 0x126, 0x0 },
    { 0x152, 0x0 },
    { 0x156, 0x0 },
    { 0x166, 0x0 },
    { 0x402, 0x0 },
    { 0x406, 0x0 },
    { 0x416, 0x0 },
    { 0x41e, 0x0 },
    { 0xa06, 0x0 },
    { 0xa16, 0x0 },
    { 0xf31, 0x0 },
};

const GpuControlList::More kMoreForEntry388_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry390[1] = {
    DISABLE_DYNAMIC_VIDEO_ENCODE_FRAMERATE_UPDATE,
};

const uint32_t kCrBugsForWorkaroundsEntry390[1] = {
    1295815,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry390 = {
    nullptr, // driver_vendor
    { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "30.0.101.1340", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry390_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry391[1] = {
    DISABLE_SKIA_REDUCE_OPS_TASK_SPLITTING,
};

const uint32_t kCrBugsForWorkaroundsEntry391[1] = {
    1298809,
};

const IntelGpuSeriesType kIntelGpuSeriesForEntry391[1] = {
    IntelGpuSeriesType::kSkylake,
};

const GpuControlList::More kMoreForEntry391_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry394[1] = {
    DISABLE_VP_SUPER_RESOLUTION,
};

const uint32_t kCrBugsForWorkaroundsEntry394[1] = {
    1318380,
};

const GpuControlList::More kMoreForEntry394_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry394Exception0 = {
    nullptr, // driver_vendor
    { GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "27.20.100.8681", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry394_619971032Exception0 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry395[1] = {
    DISABLE_DIRECT_COMPOSITION_VIDEO_OVERLAYS,
};

const uint32_t kCrBugsForWorkaroundsEntry395[1] = {
    1327088,
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry395 = {
    nullptr, // driver_vendor
    { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "27.20.100.9168", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry395_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry397[1] = {
    DISABLE_ACCELERATED_VP9_DECODE,
};

const uint32_t kCrBugsForWorkaroundsEntry397[1] = {
    1333299,
};

const GpuControlList::Device kDevicesForWorkaroundsEntry397[1] = {
    { 0x591B, 0x0 },
};

const GpuControlList::DriverInfo kDriverInfoForWorkaroundsEntry397 = {
    nullptr, // driver_vendor
    { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "26.20.100.6998", nullptr }, // driver_version
};

const GpuControlList::More kMoreForEntry397_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry398[1] = {
    MSAA_IS_SLOW_2,
};

const uint32_t kCrBugsForWorkaroundsEntry398[3] = {
    527565,
    1298585,
    1341830,
};

const GpuControlList::More kMoreForEntry398_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const GpuControlList::More kMoreForEntry398_619971032Exception0 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

const int kFeatureListForWorkaroundsEntry403[1] = {
    DISABLE_ACCELERATED_AV1_ENCODE,
};

const uint32_t kCrBugsForWorkaroundsEntry403[1] = {
    1367038,
};

const GpuControlList::More kMoreForEntry403_619971032 = {
    GpuControlList::kGLTypeNone, // gl_type
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // gl_version
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // pixel_shader_version
    false, // in_process_gpu
    0, // gl_reset_notification_strategy
    { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // direct_rendering_version
    { GpuControlList::kGT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "2", nullptr }, // gpu_count
    GpuControlList::kDontCare, // hardware_overlay
    0, // test_group
    GpuControlList::kDontCare, // subpixel_font_rendering
};

} // namespace gpu

#endif // GPU_CONFIG_GPU_DRIVER_BUG_LIST_ARRAYS_AND_STRUCTS_AUTOGEN_H_
