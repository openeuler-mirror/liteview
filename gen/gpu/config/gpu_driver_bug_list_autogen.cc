// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#include "gpu/config/gpu_driver_bug_list_autogen.h"

#include <iterator>

#include "gpu/config/gpu_driver_bug_list_arrays_and_structs_autogen.h"
#include "gpu/config/gpu_driver_bug_list_exceptions_autogen.h"

namespace gpu {

const GpuControlList::Entry kGpuDriverBugListEntries[] = {
    {
        17, // id
        "Some drivers are unable to reset the D3D device in the GPU process sandbox",
        std::size(kFeatureListForWorkaroundsEntry17), // features size
        kFeatureListForWorkaroundsEntry17, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        0, // CrBugs size
        nullptr, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry17_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        19, // id
        "Disable depth textures on older Adreno 2xx Qualcomm GPUs (legacy blocklist entry, original problem unclear)",
        std::size(kFeatureListForWorkaroundsEntry19), // features size
        kFeatureListForWorkaroundsEntry19, // features
        std::size(kDisabledExtensionsForEntry19), // DisabledExtensions size
        kDisabledExtensionsForEntry19, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry19), // CrBugs size
        kCrBugsForWorkaroundsEntry19, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            &kGLStringsForWorkaroundsEntry19, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry19_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        26, // id
        "Disable use of Direct3D 11 on Windows Vista and lower",
        std::size(kFeatureListForWorkaroundsEntry26), // features size
        kFeatureListForWorkaroundsEntry26, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        0, // CrBugs size
        nullptr, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "6.0", nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry26_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        31, // id
        "The Mali-3xx/4xx/Txxx driver does not guarantee flush ordering",
        std::size(kFeatureListForWorkaroundsEntry31), // features size
        kFeatureListForWorkaroundsEntry31, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry31), // CrBugs size
        kCrBugsForWorkaroundsEntry31, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            &kGLStringsForWorkaroundsEntry31, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry31_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        33, // id
        "Share group-related crashes and poor context switching perf on Imagination drivers",
        std::size(kFeatureListForWorkaroundsEntry33), // features size
        kFeatureListForWorkaroundsEntry33, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        0, // CrBugs size
        nullptr, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            &kGLStringsForWorkaroundsEntry33, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry33_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        54, // id
        "Clear uniforms before first program use on all platforms",
        std::size(kFeatureListForWorkaroundsEntry54), // features size
        kFeatureListForWorkaroundsEntry54, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry54), // CrBugs size
        kCrBugsForWorkaroundsEntry54, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry54_619971032, // more data
        },
        std::size(kExceptionsForEntry54), // exceptions count
        kExceptionsForEntry54, // exceptions
    },
    {
        70, // id
        "Disable D3D11 on older nVidia drivers",
        std::size(kFeatureListForWorkaroundsEntry70), // features size
        kFeatureListForWorkaroundsEntry70, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry70), // CrBugs size
        kCrBugsForWorkaroundsEntry70, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry70, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry70_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        86, // id
        "Disable use of Direct3D 11 on Matrox video cards",
        std::size(kFeatureListForWorkaroundsEntry86), // features size
        kFeatureListForWorkaroundsEntry86, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry86), // CrBugs size
        kCrBugsForWorkaroundsEntry86, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x102b, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry86_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        87, // id
        "Disable use of Direct3D 11 on older AMD drivers",
        std::size(kFeatureListForWorkaroundsEntry87), // features size
        kFeatureListForWorkaroundsEntry87, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry87), // CrBugs size
        kCrBugsForWorkaroundsEntry87, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry87, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry87_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        92, // id
        "Old Intel drivers cannot reliably support D3D11",
        std::size(kFeatureListForWorkaroundsEntry92), // features size
        kFeatureListForWorkaroundsEntry92, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry92), // CrBugs size
        kCrBugsForWorkaroundsEntry92, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry92, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry92_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        100, // id
        "Disable Direct3D11 on systems with AMD switchable graphics",
        std::size(kFeatureListForWorkaroundsEntry100), // features size
        kFeatureListForWorkaroundsEntry100, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry100), // CrBugs size
        kCrBugsForWorkaroundsEntry100, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10", nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleAMDSwitchable, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry100, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry100_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        132, // id
        "On Intel GPUs MSAA performance is not acceptable for GPU rasterization",
        std::size(kFeatureListForWorkaroundsEntry132), // features size
        kFeatureListForWorkaroundsEntry132, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry132), // CrBugs size
        kCrBugsForWorkaroundsEntry132, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryActive, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry132_619971032, // more data
        },
        std::size(kExceptionsForEntry132), // exceptions count
        kExceptionsForEntry132, // exceptions
    },
    {
        149, // id
        "Direct composition flashes black initially on Win <10",
        std::size(kFeatureListForWorkaroundsEntry149), // features size
        kFeatureListForWorkaroundsEntry149, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry149), // CrBugs size
        kCrBugsForWorkaroundsEntry149, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.0", nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry149_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        165, // id
        "Unpacking overlapping rows from unpack buffers is unstable on NVIDIA GL driver",
        std::size(kFeatureListForWorkaroundsEntry165), // features size
        kFeatureListForWorkaroundsEntry165, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry165), // CrBugs size
        kCrBugsForWorkaroundsEntry165, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            &kGLStringsForWorkaroundsEntry165, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry165_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        170, // id
        "Zero copy DXGI video hangs on shutdown on Win < 8.1",
        std::size(kFeatureListForWorkaroundsEntry170), // features size
        kFeatureListForWorkaroundsEntry170, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry170), // CrBugs size
        kCrBugsForWorkaroundsEntry170, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "8.1", nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry170_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        185, // id
        "Zero-copy NV12 video displays incorrect colors on NVIDIA drivers.",
        std::size(kFeatureListForWorkaroundsEntry185), // features size
        kFeatureListForWorkaroundsEntry185, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry185), // CrBugs size
        kCrBugsForWorkaroundsEntry185, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry185, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry185_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        192, // id
        "Decode and encode before generateMipmap for srgb format textures on os except macosx",
        std::size(kFeatureListForWorkaroundsEntry192), // features size
        kFeatureListForWorkaroundsEntry192, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry192), // CrBugs size
        kCrBugsForWorkaroundsEntry192, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry192_619971032, // more data
        },
        std::size(kExceptionsForEntry192), // exceptions count
        kExceptionsForEntry192, // exceptions
    },
    {
        206, // id
        "Disable KHR_blend_equation_advanced until cc shaders are updated",
        0, // feature size
        nullptr, // features
        std::size(kDisabledExtensionsForEntry206), // DisabledExtensions size
        kDisabledExtensionsForEntry206, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry206), // CrBugs size
        kCrBugsForWorkaroundsEntry206, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry206_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        207, // id
        "Decode and Encode before generateMipmap for srgb format textures on Windows",
        std::size(kFeatureListForWorkaroundsEntry207), // features size
        kFeatureListForWorkaroundsEntry207, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry207), // CrBugs size
        kCrBugsForWorkaroundsEntry207, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry207_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        213, // id
        "The Mali-Gxx driver does not guarantee flush ordering",
        std::size(kFeatureListForWorkaroundsEntry213), // features size
        kFeatureListForWorkaroundsEntry213, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry213), // CrBugs size
        kCrBugsForWorkaroundsEntry213, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            &kGLStringsForWorkaroundsEntry213, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry213_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        215, // id
        "Fake no-op GPU driver bug workaround for testing",
        std::size(kFeatureListForWorkaroundsEntry215), // features size
        kFeatureListForWorkaroundsEntry215, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry215), // CrBugs size
        kCrBugsForWorkaroundsEntry215, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry215_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        219, // id
        "Zero-copy DXGI video hangs or displays incorrect colors on older AMD drivers",
        std::size(kFeatureListForWorkaroundsEntry219), // features size
        kFeatureListForWorkaroundsEntry219, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry219), // CrBugs size
        kCrBugsForWorkaroundsEntry219, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry219, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry219_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        220, // id
        "NV12 DXGI video displays incorrect colors on older AMD drivers",
        std::size(kFeatureListForWorkaroundsEntry220), // features size
        kFeatureListForWorkaroundsEntry220, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry220), // CrBugs size
        kCrBugsForWorkaroundsEntry220, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry220, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry220_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        224, // id
        "VPx decoding isn't supported well before Windows 10 creators update.",
        std::size(kFeatureListForWorkaroundsEntry224), // features size
        kFeatureListForWorkaroundsEntry224, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry224), // CrBugs size
        kCrBugsForWorkaroundsEntry224, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.0.15063", nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry224_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        225, // id
        "VP9 decoding is too slow on Intel Broadwell, Skylake, and CherryTrail",
        std::size(kFeatureListForWorkaroundsEntry225), // features size
        kFeatureListForWorkaroundsEntry225, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry225), // CrBugs size
        kCrBugsForWorkaroundsEntry225, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            std::size(kIntelGpuSeriesForEntry225), // intel_gpu_series size
            kIntelGpuSeriesForEntry225, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry225_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        226, // id
        "Accelerated VP9 decoding is hanging on some videos.",
        std::size(kFeatureListForWorkaroundsEntry226), // features size
        kFeatureListForWorkaroundsEntry226, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry226), // CrBugs size
        kCrBugsForWorkaroundsEntry226, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry226, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry226_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        232, // id
        "Delayed copy NV12 crashes on Intel on Windows <= 8.1.",
        std::size(kFeatureListForWorkaroundsEntry232), // features size
        kFeatureListForWorkaroundsEntry232, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry232), // CrBugs size
        kCrBugsForWorkaroundsEntry232, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "8.1", nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry232_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        233, // id
        "Delayed copy NV12 displays incorrect colors on NVIDIA drivers.",
        std::size(kFeatureListForWorkaroundsEntry233), // features size
        kFeatureListForWorkaroundsEntry233, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry233), // CrBugs size
        kCrBugsForWorkaroundsEntry233, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry233_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        249, // id
        "Direct composition causes slow presents on old Nvidia GPUs",
        std::size(kFeatureListForWorkaroundsEntry249), // features size
        kFeatureListForWorkaroundsEntry249, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry249), // CrBugs size
        kCrBugsForWorkaroundsEntry249, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            std::size(kDevicesForWorkaroundsEntry249), // Devices size
            kDevicesForWorkaroundsEntry249, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry249_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        256, // id
        "Expose WebGL's disjoint_timer_query extensions on platforms with site isolation",
        std::size(kFeatureListForWorkaroundsEntry256), // features size
        kFeatureListForWorkaroundsEntry256, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry256), // CrBugs size
        kCrBugsForWorkaroundsEntry256, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry256_619971032, // more data
        },
        std::size(kExceptionsForEntry256), // exceptions count
        kExceptionsForEntry256, // exceptions
    },
    {
        257, // id
        "Fake entry for testing disabling of WebGL extensions",
        0, // feature size
        nullptr, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        std::size(kDisabledWebGLExtensionsForEntry257), // DisabledWebGLExtensions size
        kDisabledWebGLExtensionsForEntry257, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry257), // CrBugs size
        kCrBugsForWorkaroundsEntry257, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry257_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        261, // id
        "Fallback to D3D9 if basic info collection fails on Win7",
        std::size(kFeatureListForWorkaroundsEntry261), // features size
        kFeatureListForWorkaroundsEntry261, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry261), // CrBugs size
        kCrBugsForWorkaroundsEntry261, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "6.1", nullptr }, // os_version
            0xffff, // vendor_id
            std::size(kDevicesForWorkaroundsEntry261), // Devices size
            kDevicesForWorkaroundsEntry261, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry261_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        277, // id
        "Direct composition path is buggy on certain AMD devices/drivers",
        std::size(kFeatureListForWorkaroundsEntry277), // features size
        kFeatureListForWorkaroundsEntry277, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry277), // CrBugs size
        kCrBugsForWorkaroundsEntry277, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry277, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry277_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        278, // id
        "Direct composition path is buggy on certain AMD devices/drivers",
        std::size(kFeatureListForWorkaroundsEntry278), // features size
        kFeatureListForWorkaroundsEntry278, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry278), // CrBugs size
        kCrBugsForWorkaroundsEntry278, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            std::size(kDevicesForWorkaroundsEntry278), // Devices size
            kDevicesForWorkaroundsEntry278, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry278_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        286, // id
        "Video corruption on Intel HD 530 without hardware overlay support",
        std::size(kFeatureListForWorkaroundsEntry286), // features size
        kFeatureListForWorkaroundsEntry286, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry286), // CrBugs size
        kCrBugsForWorkaroundsEntry286, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            std::size(kDevicesForWorkaroundsEntry286), // Devices size
            kDevicesForWorkaroundsEntry286, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry286, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry286_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        289, // id
        "Fake entry for testing command buffer init failures on ES 2.0",
        std::size(kFeatureListForWorkaroundsEntry289), // features size
        kFeatureListForWorkaroundsEntry289, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry289), // CrBugs size
        kCrBugsForWorkaroundsEntry289, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry289_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        300, // id
        "Direct composition causes rendering issues on Intel SandyBridge and IvyBridge GPUs",
        std::size(kFeatureListForWorkaroundsEntry300), // features size
        kFeatureListForWorkaroundsEntry300, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry300), // CrBugs size
        kCrBugsForWorkaroundsEntry300, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            std::size(kIntelGpuSeriesForEntry300), // intel_gpu_series size
            kIntelGpuSeriesForEntry300, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry300_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        303, // id
        "Dynamic texture map crashes on Intel drivers less than version 24",
        std::size(kFeatureListForWorkaroundsEntry303), // features size
        kFeatureListForWorkaroundsEntry303, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry303), // CrBugs size
        kCrBugsForWorkaroundsEntry303, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry303, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry303_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        304, // id
        "Per NVIDIA, software and hardware overlays don't work properly prior to this driver.",
        std::size(kFeatureListForWorkaroundsEntry304), // features size
        kFeatureListForWorkaroundsEntry304, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry304), // CrBugs size
        kCrBugsForWorkaroundsEntry304, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry304, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry304_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        308, // id
        "Delayed copy NV12 causes crashes on GPU main thread when DXVA video decoder runs on another thread",
        std::size(kFeatureListForWorkaroundsEntry308), // features size
        kFeatureListForWorkaroundsEntry308, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry308), // CrBugs size
        kCrBugsForWorkaroundsEntry308, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry308_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        309, // id
        "Don't use video processor scaling on non-Intel, non-NVIDIA GPUs.",
        std::size(kFeatureListForWorkaroundsEntry309), // features size
        kFeatureListForWorkaroundsEntry309, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry309), // CrBugs size
        kCrBugsForWorkaroundsEntry309, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry309_619971032, // more data
        },
        std::size(kExceptionsForEntry309), // exceptions count
        kExceptionsForEntry309, // exceptions
    },
    {
        315, // id
        "Disable GL_MESA_framebuffer_flip_y for desktop GL",
        0, // feature size
        nullptr, // features
        std::size(kDisabledExtensionsForEntry315), // DisabledExtensions size
        kDisabledExtensionsForEntry315, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry315), // CrBugs size
        kCrBugsForWorkaroundsEntry315, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry315_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        318, // id
        "Direct composition caused performance issues on AMD GPUs",
        std::size(kFeatureListForWorkaroundsEntry318), // features size
        kFeatureListForWorkaroundsEntry318, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry318), // CrBugs size
        kCrBugsForWorkaroundsEntry318, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            std::size(kDevicesForWorkaroundsEntry318), // Devices size
            kDevicesForWorkaroundsEntry318, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry318_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        321, // id
        "Zero-copy DXGI video hangs or displays incorrect colors on older AMD drivers",
        std::size(kFeatureListForWorkaroundsEntry321), // features size
        kFeatureListForWorkaroundsEntry321, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry321), // CrBugs size
        kCrBugsForWorkaroundsEntry321, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            std::size(kDevicesForWorkaroundsEntry321), // Devices size
            kDevicesForWorkaroundsEntry321, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry321, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry321_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        322, // id
        "Hardware overlays fail to work on older AMD drivers",
        std::size(kFeatureListForWorkaroundsEntry322), // features size
        kFeatureListForWorkaroundsEntry322, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry322), // CrBugs size
        kCrBugsForWorkaroundsEntry322, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry322, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry322_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        323, // id
        "Hardware overlays fail to work on older AMD drivers",
        std::size(kFeatureListForWorkaroundsEntry323), // features size
        kFeatureListForWorkaroundsEntry323, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry323), // CrBugs size
        kCrBugsForWorkaroundsEntry323, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            std::size(kDevicesForWorkaroundsEntry323), // Devices size
            kDevicesForWorkaroundsEntry323, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry323, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry323_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        324, // id
        "dynamic textures fail to work on AMD GPUs",
        std::size(kFeatureListForWorkaroundsEntry324), // features size
        kFeatureListForWorkaroundsEntry324, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry324), // CrBugs size
        kCrBugsForWorkaroundsEntry324, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry324_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        328, // id
        "Disable D3D11VideoDecoder due to crashes on NVIDIA on older drivers",
        std::size(kFeatureListForWorkaroundsEntry328), // features size
        kFeatureListForWorkaroundsEntry328, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry328), // CrBugs size
        kCrBugsForWorkaroundsEntry328, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry328, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry328_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        329, // id
        "Limit D3D11VideoDecoder to 11.0 due to crashes on AMD",
        std::size(kFeatureListForWorkaroundsEntry329), // features size
        kFeatureListForWorkaroundsEntry329, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry329), // CrBugs size
        kCrBugsForWorkaroundsEntry329, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry329_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        332, // id
        "Send empty video hdr metadata due to crashes on AMD",
        std::size(kFeatureListForWorkaroundsEntry332), // features size
        kFeatureListForWorkaroundsEntry332, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry332), // CrBugs size
        kCrBugsForWorkaroundsEntry332, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry332_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        336, // id
        "DXVA video decoder crashes on some AMD GPUs.",
        std::size(kFeatureListForWorkaroundsEntry336), // features size
        kFeatureListForWorkaroundsEntry336, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry336), // CrBugs size
        kCrBugsForWorkaroundsEntry336, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            std::size(kDevicesForWorkaroundsEntry336), // Devices size
            kDevicesForWorkaroundsEntry336, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry336_619971032, // more data
        },
        std::size(kExceptionsForEntry336), // exceptions count
        kExceptionsForEntry336, // exceptions
    },
    {
        337, // id
        "Disable hardware MFT H.264 encoder on older NVIDIA drivers",
        std::size(kFeatureListForWorkaroundsEntry337), // features size
        kFeatureListForWorkaroundsEntry337, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry337), // CrBugs size
        kCrBugsForWorkaroundsEntry337, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry337, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry337_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        338, // id
        "Disable hardware overlay on icelake with older Intel drivers",
        std::size(kFeatureListForWorkaroundsEntry338), // features size
        kFeatureListForWorkaroundsEntry338, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry338), // CrBugs size
        kCrBugsForWorkaroundsEntry338, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry338, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            std::size(kIntelGpuSeriesForEntry338), // intel_gpu_series size
            kIntelGpuSeriesForEntry338, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry338_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        339, // id
        "Binding video decoder textures triggers crash on Intel driver 20.19.15.*",
        std::size(kFeatureListForWorkaroundsEntry339), // features size
        kFeatureListForWorkaroundsEntry339, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry339), // CrBugs size
        kCrBugsForWorkaroundsEntry339, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10", nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry339, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            std::size(kIntelGpuSeriesForEntry339), // intel_gpu_series size
            kIntelGpuSeriesForEntry339, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry339_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        340, // id
        "Binding video decoder textures triggers crash on Intel driver 10.18.15.*",
        std::size(kFeatureListForWorkaroundsEntry340), // features size
        kFeatureListForWorkaroundsEntry340, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry340), // CrBugs size
        kCrBugsForWorkaroundsEntry340, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10", nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry340, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            std::size(kIntelGpuSeriesForEntry340), // intel_gpu_series size
            kIntelGpuSeriesForEntry340, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry340_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        343, // id
        "Disable using GPU backed resource for imageBitmap from video on d3d9",
        std::size(kFeatureListForWorkaroundsEntry343), // features size
        kFeatureListForWorkaroundsEntry343, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry343), // CrBugs size
        kCrBugsForWorkaroundsEntry343, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            &kGLStringsForWorkaroundsEntry343, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry343_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        344, // id
        "VP8 decoding crashes before Windows 10 Fall Creators Update.",
        std::size(kFeatureListForWorkaroundsEntry344), // features size
        kFeatureListForWorkaroundsEntry344, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry344), // CrBugs size
        kCrBugsForWorkaroundsEntry344, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.0.16299", nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry344_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        345, // id
        "Disable DecodeSwapChain for Intel Gen9 and older devices",
        std::size(kFeatureListForWorkaroundsEntry345), // features size
        kFeatureListForWorkaroundsEntry345, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry345), // CrBugs size
        kCrBugsForWorkaroundsEntry345, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kLE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "9", nullptr }, // intel_gpu_generation
            &kMoreForEntry345_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        347, // id
        "Intel GPUs fail to report BGRA8 overlay support",
        std::size(kFeatureListForWorkaroundsEntry347), // features size
        kFeatureListForWorkaroundsEntry347, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry347), // CrBugs size
        kCrBugsForWorkaroundsEntry347, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry347_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        352, // id
        "Intel device 0x1066 can't use d3d11 video decoder",
        std::size(kFeatureListForWorkaroundsEntry352), // features size
        kFeatureListForWorkaroundsEntry352, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry352), // CrBugs size
        kCrBugsForWorkaroundsEntry352, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            std::size(kDevicesForWorkaroundsEntry352), // Devices size
            kDevicesForWorkaroundsEntry352, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry352_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        353, // id
        "Intel device 0x8a56 with specific drivers can't use d3d11 video decoder",
        std::size(kFeatureListForWorkaroundsEntry353), // features size
        kFeatureListForWorkaroundsEntry353, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry353), // CrBugs size
        kCrBugsForWorkaroundsEntry353, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            std::size(kDevicesForWorkaroundsEntry353), // Devices size
            kDevicesForWorkaroundsEntry353, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry353, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry353_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        354, // id
        "AMD devices 98e4 and 15d8 with specific drivers can't use d3d11 video decoder",
        std::size(kFeatureListForWorkaroundsEntry354), // features size
        kFeatureListForWorkaroundsEntry354, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry354), // CrBugs size
        kCrBugsForWorkaroundsEntry354, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            std::size(kDevicesForWorkaroundsEntry354), // Devices size
            kDevicesForWorkaroundsEntry354, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry354, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry354_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        360, // id
        "8x MSAA for WebGL contexts is slow on Win Intel",
        std::size(kFeatureListForWorkaroundsEntry360), // features size
        kFeatureListForWorkaroundsEntry360, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry360), // CrBugs size
        kCrBugsForWorkaroundsEntry360, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry360_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        362, // id
        "Promote 2 videos to hardware overlays on Windows Intel platforms",
        std::size(kFeatureListForWorkaroundsEntry362), // features size
        kFeatureListForWorkaroundsEntry362, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry362), // CrBugs size
        kCrBugsForWorkaroundsEntry362, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            std::size(kIntelGpuSeriesForEntry362), // intel_gpu_series size
            kIntelGpuSeriesForEntry362, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry362_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        364, // id
        "Software overlays fail to work reliably on AMD devices",
        std::size(kFeatureListForWorkaroundsEntry364), // features size
        kFeatureListForWorkaroundsEntry364, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry364), // CrBugs size
        kCrBugsForWorkaroundsEntry364, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry364_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        371, // id
        "Disable software overlays for Intel GPUs. All Skylake+ devices support hw overlays, older devices peform poorly.",
        std::size(kFeatureListForWorkaroundsEntry371), // features size
        kFeatureListForWorkaroundsEntry371, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry371), // CrBugs size
        kCrBugsForWorkaroundsEntry371, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry371_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        372, // id
        "Check YCbCr_Studio_G22_Left_P709 color space for NV12 overlay support on Intel",
        std::size(kFeatureListForWorkaroundsEntry372), // features size
        kFeatureListForWorkaroundsEntry372, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry372), // CrBugs size
        kCrBugsForWorkaroundsEntry372, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "9", nullptr }, // intel_gpu_generation
            &kMoreForEntry372_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        374, // id
        "VP9 resilient mode causes corruptions with AMD VCN HW decoders, using DXVA",
        std::size(kFeatureListForWorkaroundsEntry374), // features size
        kFeatureListForWorkaroundsEntry374, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry374), // CrBugs size
        kCrBugsForWorkaroundsEntry374, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry374_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        376, // id
        "Don't use Media Foundation hardware security on Turing-architecture NVIDIA GPUs.",
        std::size(kFeatureListForWorkaroundsEntry376), // features size
        kFeatureListForWorkaroundsEntry376, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry376), // CrBugs size
        kCrBugsForWorkaroundsEntry376, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            std::size(kDevicesForWorkaroundsEntry376), // Devices size
            kDevicesForWorkaroundsEntry376, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry376, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry376_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        377, // id
        "Don't use Media Foundation hardware security on Pascal-architecture NVIDIA GPUs.",
        std::size(kFeatureListForWorkaroundsEntry377), // features size
        kFeatureListForWorkaroundsEntry377, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry377), // CrBugs size
        kCrBugsForWorkaroundsEntry377, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            std::size(kDevicesForWorkaroundsEntry377), // Devices size
            kDevicesForWorkaroundsEntry377, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry377, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry377_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        380, // id
        "Intel GPUs do not promote downscaled overlays",
        std::size(kFeatureListForWorkaroundsEntry380), // features size
        kFeatureListForWorkaroundsEntry380, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry380), // CrBugs size
        kCrBugsForWorkaroundsEntry380, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10.0", nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "9", nullptr }, // intel_gpu_generation
            &kMoreForEntry380_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        387, // id
        "DXVAVideoDecodeAccelerator doesn't support a set of legacy AMD Gpus",
        std::size(kFeatureListForWorkaroundsEntry387), // features size
        kFeatureListForWorkaroundsEntry387, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry387), // CrBugs size
        kCrBugsForWorkaroundsEntry387, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            std::size(kDevicesForWorkaroundsEntry387), // Devices size
            kDevicesForWorkaroundsEntry387, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry387_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        388, // id
        "DXVAVideoDecodeAccelerator doesn't support a set of legacy Intel Gpus",
        std::size(kFeatureListForWorkaroundsEntry388), // features size
        kFeatureListForWorkaroundsEntry388, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry388), // CrBugs size
        kCrBugsForWorkaroundsEntry388, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            std::size(kDevicesForWorkaroundsEntry388), // Devices size
            kDevicesForWorkaroundsEntry388, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry388_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        390, // id
        "AVC/AV1 hardware encoder MFT output bitrate incorrect upon framerate update on Intel GPUs.",
        std::size(kFeatureListForWorkaroundsEntry390), // features size
        kFeatureListForWorkaroundsEntry390, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry390), // CrBugs size
        kCrBugsForWorkaroundsEntry390, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry390, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry390_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        391, // id
        "Skia ReduceOpsTaskSplitting causes artifacts on Intel Skylake",
        std::size(kFeatureListForWorkaroundsEntry391), // features size
        kFeatureListForWorkaroundsEntry391, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry391), // CrBugs size
        kCrBugsForWorkaroundsEntry391, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            std::size(kIntelGpuSeriesForEntry391), // intel_gpu_series size
            kIntelGpuSeriesForEntry391, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry391_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        394, // id
        "Don't use video processor super resolution on Intel Gen9 and older GPUs and non-Intel GPUs.",
        std::size(kFeatureListForWorkaroundsEntry394), // features size
        kFeatureListForWorkaroundsEntry394, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry394), // CrBugs size
        kCrBugsForWorkaroundsEntry394, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry394_619971032, // more data
        },
        std::size(kExceptionsForEntry394), // exceptions count
        kExceptionsForEntry394, // exceptions
    },
    {
        395, // id
        "Don't use MPO on Intel TigerLake GPUs with old drivers due to VideoProcessorBlt crash.",
        std::size(kFeatureListForWorkaroundsEntry395), // features size
        kFeatureListForWorkaroundsEntry395, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry395), // CrBugs size
        kCrBugsForWorkaroundsEntry395, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry395, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "12", nullptr }, // intel_gpu_generation
            &kMoreForEntry395_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        397, // id
        "VPx decoding crashes due to a buggy driver / chipset combo.",
        std::size(kFeatureListForWorkaroundsEntry397), // features size
        kFeatureListForWorkaroundsEntry397, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry397), // CrBugs size
        kCrBugsForWorkaroundsEntry397, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10", nullptr }, // os_version
            0x8086, // vendor_id
            std::size(kDevicesForWorkaroundsEntry397), // Devices size
            kDevicesForWorkaroundsEntry397, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForWorkaroundsEntry397, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry397_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        398, // id
        "On pre-Ice Lake Intel GPUs MSAA performance is not acceptable for GPU rasterization",
        std::size(kFeatureListForWorkaroundsEntry398), // features size
        kFeatureListForWorkaroundsEntry398, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry398), // CrBugs size
        kCrBugsForWorkaroundsEntry398, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryActive, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "11", nullptr }, // intel_gpu_generation
            &kMoreForEntry398_619971032, // more data
        },
        std::size(kExceptionsForEntry398), // exceptions count
        kExceptionsForEntry398, // exceptions
    },
    {
        403, // id
        "Disable hardware MFT Av1 encoder on machines with multiple GPUs",
        std::size(kFeatureListForWorkaroundsEntry403), // features size
        kFeatureListForWorkaroundsEntry403, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForWorkaroundsEntry403), // CrBugs size
        kCrBugsForWorkaroundsEntry403, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry403_619971032, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
};
const size_t kGpuDriverBugListEntryCount = 80;
} // namespace gpu
