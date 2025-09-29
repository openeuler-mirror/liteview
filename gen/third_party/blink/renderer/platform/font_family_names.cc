// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/platform/fonts/font_family_names.json5

#include "third_party/blink/renderer/platform/font_family_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"

namespace blink {
namespace font_family_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kWebkitStandard = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kArial = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kBlinkMacSystemFont = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kCalibri = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kCourier = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kCourierNew = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kHelvetica = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kLucidaGrande = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kMSSansSerif = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kMSSerif = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kMSUIGothic = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kMicrosoftSansSerif = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kSans = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kSegoeUI = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kTimes = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kTimesNewRoman = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kCursive = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kFantasy = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kMath = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kMonospace = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kSansSerif = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kSerif = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kSystemUi = reinterpret_cast<AtomicString*>(&names_storage)[22];

void Init()
{
    static bool is_loaded = false;
    if (is_loaded)
        return;
    is_loaded = true;

    struct NameEntry {
        const char* name;
        unsigned hash;
        unsigned char length;
    };

    static const NameEntry kNames[] = {
        { "-webkit-standard", 6994621, 16 },
        { "Arial", 16574340, 5 },
        { "BlinkMacSystemFont", 1851454, 18 },
        { "Calibri", 3430454, 7 },
        { "Courier", 3193356, 7 },
        { "Courier New", 14670458, 11 },
        { "Helvetica", 15124250, 9 },
        { "Lucida Grande", 8192141, 13 },
        { "MS Sans Serif", 3551498, 13 },
        { "MS Serif", 7586295, 8 },
        { "MS UI Gothic", 12187834, 12 },
        { "Microsoft Sans Serif", 10902575, 20 },
        { "Sans", 6668891, 4 },
        { "Segoe UI", 2762116, 8 },
        { "Times", 1178907, 5 },
        { "Times New Roman", 8871567, 15 },
        { "cursive", 10597311, 7 },
        { "fantasy", 16039516, 7 },
        { "math", 8182406, 4 },
        { "monospace", 7438294, 9 },
        { "sans-serif", 5108456, 10 },
        { "serif", 14004670, 5 },
        { "system-ui", 14546067, 9 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace font_family_names
} // namespace blink
