// Copyright 2019 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
//    gpu/config/process_json.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#include "gpu/config/software_rendering_list_autogen.h"

#include <iterator>

#include "gpu/config/software_rendering_list_arrays_and_structs_autogen.h"
#include "gpu/config/software_rendering_list_exceptions_autogen.h"

namespace gpu {

const GpuControlList::Entry kSoftwareRenderingListEntries[] = {
    {
        4, // id
        "The Intel Mobile 945 Express family of chipsets is not compatible with WebGL",
        std::size(kFeatureListForSoftwareEntry4), // features size
        kFeatureListForSoftwareEntry4, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry4), // CrBugs size
        kCrBugsForSoftwareEntry4, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            std::size(kDevicesForSoftwareEntry4), // Devices size
            kDevicesForSoftwareEntry4, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry4_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        8, // id
        "NVIDIA GeForce FX Go5200 is assumed to be buggy",
        std::size(kFeatureListForSoftwareEntry8), // features size
        kFeatureListForSoftwareEntry8, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry8), // CrBugs size
        kCrBugsForSoftwareEntry8, // CrBugs
        {
            GpuControlList::kOsAny, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            std::size(kDevicesForSoftwareEntry8), // Devices size
            kDevicesForSoftwareEntry8, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry8_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        34, // id
        "S3 Trio (used in Virtual PC) is not compatible",
        std::size(kFeatureListForSoftwareEntry34), // features size
        kFeatureListForSoftwareEntry34, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry34), // CrBugs size
        kCrBugsForSoftwareEntry34, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x5333, // vendor_id
            std::size(kDevicesForSoftwareEntry34), // Devices size
            kDevicesForSoftwareEntry34, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry34_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        45, // id
        "Parallels drivers older than 7 are buggy",
        std::size(kFeatureListForSoftwareEntry45), // features size
        kFeatureListForSoftwareEntry45, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry45), // CrBugs size
        kCrBugsForSoftwareEntry45, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1ab8, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry45, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry45_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        46, // id
        "ATI FireMV 2400 cards on Windows are buggy",
        std::size(kFeatureListForSoftwareEntry46), // features size
        kFeatureListForSoftwareEntry46, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry46), // CrBugs size
        kCrBugsForSoftwareEntry46, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            std::size(kDevicesForSoftwareEntry46), // Devices size
            kDevicesForSoftwareEntry46, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry46_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        59, // id
        "NVidia driver 185.93 is crashy on Windows",
        std::size(kFeatureListForSoftwareEntry59), // features size
        kFeatureListForSoftwareEntry59, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry59), // CrBugs size
        kCrBugsForSoftwareEntry59, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry59, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry59_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        64, // id
        "Hardware video decode is only supported in win7+",
        std::size(kFeatureListForSoftwareEntry64), // features size
        kFeatureListForSoftwareEntry64, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry64), // CrBugs size
        kCrBugsForSoftwareEntry64, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "6.1", nullptr }, // os_version
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
            &kMoreForEntry64_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        68, // id
        "VMware Fusion 4 has corrupt rendering with Win Vista+",
        std::size(kFeatureListForSoftwareEntry68), // features size
        kFeatureListForSoftwareEntry68, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry68), // CrBugs size
        kCrBugsForSoftwareEntry68, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kGE, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "6.0", nullptr }, // os_version
            0x15ad, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry68, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry68_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        72, // id
        "NVIDIA GeForce 6200 LE is buggy with WebGL",
        std::size(kFeatureListForSoftwareEntry72), // features size
        kFeatureListForSoftwareEntry72, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry72), // CrBugs size
        kCrBugsForSoftwareEntry72, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            std::size(kDevicesForSoftwareEntry72), // Devices size
            kDevicesForSoftwareEntry72, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry72_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        74, // id
        "GPU access is blocked if users don't have proper graphics driver installed after Windows installation",
        std::size(kFeatureListForSoftwareEntry74), // features size
        kFeatureListForSoftwareEntry74, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry74), // CrBugs size
        kCrBugsForSoftwareEntry74, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1414, // vendor_id
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
            &kMoreForEntry74_1043157500, // more data
        },
        std::size(kExceptionsForEntry74), // exceptions count
        kExceptionsForEntry74, // exceptions
    },
    {
        78, // id
        "Accelerated video decode interferes with GPU sandbox on older Intel drivers",
        std::size(kFeatureListForSoftwareEntry78), // features size
        kFeatureListForSoftwareEntry78, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry78), // CrBugs size
        kCrBugsForSoftwareEntry78, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry78, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry78_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        79, // id
        "Disable GPU on all Windows versions prior to and including Vista",
        std::size(kFeatureListForSoftwareEntry79), // features size
        kFeatureListForSoftwareEntry79, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry79), // CrBugs size
        kCrBugsForSoftwareEntry79, // CrBugs
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
            &kMoreForEntry79_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        86, // id
        "Intel Graphics Media Accelerator 3150 causes the GPU process to hang running WebGL",
        std::size(kFeatureListForSoftwareEntry86), // features size
        kFeatureListForSoftwareEntry86, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry86), // CrBugs size
        kCrBugsForSoftwareEntry86, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            std::size(kDevicesForSoftwareEntry86), // Devices size
            kDevicesForSoftwareEntry86, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry86_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        87, // id
        "Accelerated video decode on Intel driver 10.18.10.3308 is incompatible with the GPU sandbox",
        std::size(kFeatureListForSoftwareEntry87), // features size
        kFeatureListForSoftwareEntry87, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry87), // CrBugs size
        kCrBugsForSoftwareEntry87, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry87, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry87_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        90, // id
        "Accelerated video decode interferes with GPU sandbox on certain NVIDIA drivers",
        std::size(kFeatureListForSoftwareEntry90), // features size
        kFeatureListForSoftwareEntry90, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry90), // CrBugs size
        kCrBugsForSoftwareEntry90, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry90, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry90_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        91, // id
        "Accelerated video decode interferes with GPU sandbox on certain NVIDIA drivers",
        std::size(kFeatureListForSoftwareEntry91), // features size
        kFeatureListForSoftwareEntry91, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry91), // CrBugs size
        kCrBugsForSoftwareEntry91, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry91, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry91_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        92, // id
        "Accelerated video decode does not work with the discrete GPU on AMD switchables",
        std::size(kFeatureListForSoftwareEntry92), // features size
        kFeatureListForSoftwareEntry92, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry92), // CrBugs size
        kCrBugsForSoftwareEntry92, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x00, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleAMDSwitchableDiscrete, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry92_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        94, // id
        "Intel driver version 8.15.10.1749 causes GPU process hangs.",
        std::size(kFeatureListForSoftwareEntry94), // features size
        kFeatureListForSoftwareEntry94, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry94), // CrBugs size
        kCrBugsForSoftwareEntry94, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry94, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry94_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        122, // id
        "GPU rasterization should only be enabled on NVIDIA and Intel and AMD RX-R2 GPUs with DX11+ or any GPU using ANGLE's GL backend.",
        std::size(kFeatureListForSoftwareEntry122), // features size
        kFeatureListForSoftwareEntry122, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry122), // CrBugs size
        kCrBugsForSoftwareEntry122, // CrBugs
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
            &kMoreForEntry122_1043157500, // more data
        },
        std::size(kExceptionsForEntry122), // exceptions count
        kExceptionsForEntry122, // exceptions
    },
    {
        124, // id
        "Some AMD drivers have rendering glitches with GPU Rasterization",
        std::size(kFeatureListForSoftwareEntry124), // features size
        kFeatureListForSoftwareEntry124, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry124), // CrBugs size
        kCrBugsForSoftwareEntry124, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry124, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry124_1043157500, // more data
        },
        std::size(kExceptionsForEntry124), // exceptions count
        kExceptionsForEntry124, // exceptions
    },
    {
        136, // id
        "GPU rasterization is blocklisted on NVidia Fermi architecture for now.",
        std::size(kFeatureListForSoftwareEntry136), // features size
        kFeatureListForSoftwareEntry136, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry136), // CrBugs size
        kCrBugsForSoftwareEntry136, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            std::size(kDevicesForSoftwareEntry136), // Devices size
            kDevicesForSoftwareEntry136, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            nullptr, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry136_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        139, // id
        "GPU Rasterization is disabled on pre-GCN AMD cards",
        std::size(kFeatureListForSoftwareEntry139), // features size
        kFeatureListForSoftwareEntry139, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry139), // CrBugs size
        kCrBugsForSoftwareEntry139, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry139, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry139_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        141, // id
        "Disable use of D3D11/WebGL2 on Windows Vista and lower",
        std::size(kFeatureListForSoftwareEntry141), // features size
        kFeatureListForSoftwareEntry141, // features
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
            &kMoreForEntry141_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        142, // id
        "Disable D3D11/WebGL2 on older nVidia drivers",
        std::size(kFeatureListForSoftwareEntry142), // features size
        kFeatureListForSoftwareEntry142, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry142), // CrBugs size
        kCrBugsForSoftwareEntry142, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry142, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry142_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        143, // id
        "Disable use of D3D11/WebGL2 on Matrox video cards",
        std::size(kFeatureListForSoftwareEntry143), // features size
        kFeatureListForSoftwareEntry143, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry143), // CrBugs size
        kCrBugsForSoftwareEntry143, // CrBugs
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
            &kMoreForEntry143_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        144, // id
        "Disable use of D3D11/WebGL2 on older AMD drivers",
        std::size(kFeatureListForSoftwareEntry144), // features size
        kFeatureListForSoftwareEntry144, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry144), // CrBugs size
        kCrBugsForSoftwareEntry144, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry144, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry144_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        145, // id
        "Old Intel drivers cannot reliably support D3D11/WebGL2",
        std::size(kFeatureListForSoftwareEntry145), // features size
        kFeatureListForSoftwareEntry145, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry145), // CrBugs size
        kCrBugsForSoftwareEntry145, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry145, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry145_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        146, // id
        "Disable D3D11/WebGL2 on AMD switchable graphics",
        std::size(kFeatureListForSoftwareEntry146), // features size
        kFeatureListForSoftwareEntry146, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry146), // CrBugs size
        kCrBugsForSoftwareEntry146, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kLT, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "10", nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleAMDSwitchable, // multi_gpu_style
            &kDriverInfoForSoftwareEntry146, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry146_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        152, // id
        "Test entry where all features except WebGL blocklisted",
        std::size(kFeatureListForSoftwareEntry152), // features size
        kFeatureListForSoftwareEntry152, // features
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
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry152_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        153, // id
        "Test entry where WebGL is blocklisted",
        std::size(kFeatureListForSoftwareEntry153), // features size
        kFeatureListForSoftwareEntry153, // features
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
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry153_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        157, // id
        "VMware can crash with older drivers and WebGL content",
        std::size(kFeatureListForSoftwareEntry157), // features size
        kFeatureListForSoftwareEntry157, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry157), // CrBugs size
        kCrBugsForSoftwareEntry157, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x15ad, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry157, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry157_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        163, // id
        "Intel drivers older than 2010 on Windows are possibly unreliable",
        std::size(kFeatureListForSoftwareEntry163), // features size
        kFeatureListForSoftwareEntry163, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry163), // CrBugs size
        kCrBugsForSoftwareEntry163, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry163, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry163_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        164, // id
        "NVidia drivers older than 2010 on Windows are possibly unreliable",
        std::size(kFeatureListForSoftwareEntry164), // features size
        kFeatureListForSoftwareEntry164, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry164), // CrBugs size
        kCrBugsForSoftwareEntry164, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry164, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry164_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        165, // id
        "Accelerated video decode is broken with some older Intel drivers.",
        std::size(kFeatureListForSoftwareEntry165), // features size
        kFeatureListForSoftwareEntry165, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry165), // CrBugs size
        kCrBugsForSoftwareEntry165, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry165, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry165_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        166, // id
        "8.17.10.* AMD drivers are buggy Please update your graphics driver via this link: "
        "https://www.amd.com/en/support/apu/amd-series-processors/amd-a8-series-apu-for-laptops/a8-5550m-radeon-hd-8550g",
        std::size(kFeatureListForSoftwareEntry166), // features size
        kFeatureListForSoftwareEntry166, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry166), // CrBugs size
        kCrBugsForSoftwareEntry166, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry166, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry166_1043157500, // more data
        },
        std::size(kExceptionsForEntry166), // exceptions count
        kExceptionsForEntry166, // exceptions
    },
    {
        167, // id
        "8.17.10.* AMD drivers trigger hangs in video stack",
        std::size(kFeatureListForSoftwareEntry167), // features size
        kFeatureListForSoftwareEntry167, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry167), // CrBugs size
        kCrBugsForSoftwareEntry167, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x1002, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry167, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry167_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        169, // id
        "Many crashes with the old Intel Haswell driver on Windows 8.1. Please update your graphics driver via this link: "
        "https://www.intel.com/content/www/us/en/download-center/home.html",
        std::size(kFeatureListForSoftwareEntry169), // features size
        kFeatureListForSoftwareEntry169, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry169), // CrBugs size
        kCrBugsForSoftwareEntry169, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kEQ, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, "8.1", nullptr }, // os_version
            0x806, // vendor_id
            std::size(kDevicesForSoftwareEntry169), // Devices size
            kDevicesForSoftwareEntry169, // Devices
            GpuControlList::kMultiGpuCategoryNone, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry169, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry169_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        170, // id
        "Disable hardware MFT video encoder on older Intel drivers",
        std::size(kFeatureListForSoftwareEntry170), // features size
        kFeatureListForSoftwareEntry170, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry170), // CrBugs size
        kCrBugsForSoftwareEntry170, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry170, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry170_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        171, // id
        "Disable hardware MFT video encoder on older Intel drivers",
        std::size(kFeatureListForSoftwareEntry171), // features size
        kFeatureListForSoftwareEntry171, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry171), // CrBugs size
        kCrBugsForSoftwareEntry171, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry171, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry171_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        172, // id
        "Disable hardware MFT video encoder on older Intel drivers",
        std::size(kFeatureListForSoftwareEntry172), // features size
        kFeatureListForSoftwareEntry172, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry172), // CrBugs size
        kCrBugsForSoftwareEntry172, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry172, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry172_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        173, // id
        "Disable hardware MFT video encoder on older Intel drivers",
        std::size(kFeatureListForSoftwareEntry173), // features size
        kFeatureListForSoftwareEntry173, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry173), // CrBugs size
        kCrBugsForSoftwareEntry173, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x8086, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry173, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry173_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
    {
        175, // id
        "Disable video encoding on NVidia drivers older than summer 2018",
        std::size(kFeatureListForSoftwareEntry175), // features size
        kFeatureListForSoftwareEntry175, // features
        0, // DisabledExtensions size
        nullptr, // DisabledExtensions
        0, // DisabledWebGLExtensions size
        nullptr, // DisabledWebGLExtensions
        std::size(kCrBugsForSoftwareEntry175), // CrBugs size
        kCrBugsForSoftwareEntry175, // CrBugs
        {
            GpuControlList::kOsWin, // os_type
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // os_version
            0x10de, // vendor_id
            0, // Devices size
            nullptr, // Devices
            GpuControlList::kMultiGpuCategoryAny, // multi_gpu_category
            GpuControlList::kMultiGpuStyleNone, // multi_gpu_style
            &kDriverInfoForSoftwareEntry175, // driver info
            nullptr, // GL strings
            nullptr, // machine model info
            0, // intel_gpu_series size
            nullptr, // intel_gpu_series
            { GpuControlList::kUnknown, GpuControlList::kVersionStyleNumerical, GpuControlList::kVersionSchemaCommon, nullptr, nullptr }, // intel_gpu_generation
            &kMoreForEntry175_1043157500, // more data
        },
        0, // exceptions count
        nullptr, // exceptions
    },
};
const size_t kSoftwareRenderingListEntryCount = 42;
} // namespace gpu
