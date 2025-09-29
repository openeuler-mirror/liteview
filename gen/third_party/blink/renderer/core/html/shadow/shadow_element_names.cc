// Copyright 2014 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/make_names.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/shadow/shadow_element_names.json5

#include "third_party/blink/renderer/core/html/shadow/shadow_element_names.h"

#include <iterator>

#include "third_party/blink/renderer/platform/wtf/std_lib_extras.h"

namespace blink {
namespace shadow_element_names {

void* names_storage[kNamesCount * ((sizeof(AtomicString) + sizeof(void*) - 1) / sizeof(void*))];

const AtomicString& kPseudoInternalInputSuggested = reinterpret_cast<AtomicString*>(&names_storage)[0];
const AtomicString& kPseudoMediaControlsSegmentedTrack = reinterpret_cast<AtomicString*>(&names_storage)[1];
const AtomicString& kPseudoWebKitDetailsMarker = reinterpret_cast<AtomicString*>(&names_storage)[2];
const AtomicString& kPseudoFileUploadButton = reinterpret_cast<AtomicString*>(&names_storage)[3];
const AtomicString& kPseudoInputPlaceholder = reinterpret_cast<AtomicString*>(&names_storage)[4];
const AtomicString& kPseudoMediaSliderContainer = reinterpret_cast<AtomicString*>(&names_storage)[5];
const AtomicString& kPseudoMediaSliderThumb = reinterpret_cast<AtomicString*>(&names_storage)[6];
const AtomicString& kPseudoMeterInnerElement = reinterpret_cast<AtomicString*>(&names_storage)[7];
const AtomicString& kPseudoSliderContainer = reinterpret_cast<AtomicString*>(&names_storage)[8];
const AtomicString& kPseudoSliderTrack = reinterpret_cast<AtomicString*>(&names_storage)[9];
const AtomicString& kPseudoSliderThumb = reinterpret_cast<AtomicString*>(&names_storage)[10];
const AtomicString& kPseudoTextFieldDecorationContainer = reinterpret_cast<AtomicString*>(&names_storage)[11];
const AtomicString& kIdClearButton = reinterpret_cast<AtomicString*>(&names_storage)[12];
const AtomicString& kIdDateTimeEdit = reinterpret_cast<AtomicString*>(&names_storage)[13];
const AtomicString& kIdDetailsContent = reinterpret_cast<AtomicString*>(&names_storage)[14];
const AtomicString& kIdDetailsMarker = reinterpret_cast<AtomicString*>(&names_storage)[15];
const AtomicString& kIdDetailsSummary = reinterpret_cast<AtomicString*>(&names_storage)[16];
const AtomicString& kIdEditingViewPort = reinterpret_cast<AtomicString*>(&names_storage)[17];
const AtomicString& kIdFileUploadButton = reinterpret_cast<AtomicString*>(&names_storage)[18];
const AtomicString& kIdOptGroupLabel = reinterpret_cast<AtomicString*>(&names_storage)[19];
const AtomicString& kIdPasswordRevealButton = reinterpret_cast<AtomicString*>(&names_storage)[20];
const AtomicString& kIdPickerIndicator = reinterpret_cast<AtomicString*>(&names_storage)[21];
const AtomicString& kIdPlaceholder = reinterpret_cast<AtomicString*>(&names_storage)[22];
const AtomicString& kIdSearchClearButton = reinterpret_cast<AtomicString*>(&names_storage)[23];
const AtomicString& kIdSpinButton = reinterpret_cast<AtomicString*>(&names_storage)[24];
const AtomicString& kIdTextFieldContainer = reinterpret_cast<AtomicString*>(&names_storage)[25];
const AtomicString& kIdSliderThumb = reinterpret_cast<AtomicString*>(&names_storage)[26];
const AtomicString& kIdSliderTrack = reinterpret_cast<AtomicString*>(&names_storage)[27];

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
        { "-internal-input-suggested", 1535817, 25 },
        { "-internal-media-controls-segmented-track", 14200538, 40 },
        { "-webkit-details-marker", 12898648, 22 },
        { "-webkit-file-upload-button", 13143276, 26 },
        { "-webkit-input-placeholder", 9360465, 25 },
        { "-webkit-media-slider-container", 4347047, 30 },
        { "-webkit-media-slider-thumb", 13195184, 26 },
        { "-webkit-meter-inner-element", 364878, 27 },
        { "-webkit-slider-container", 9910812, 24 },
        { "-webkit-slider-runnable-track", 10232827, 29 },
        { "-webkit-slider-thumb", 1019927, 20 },
        { "-webkit-textfield-decoration-container", 3017310, 38 },
        { "clear", 12832795, 5 },
        { "date-time-edit", 12129860, 14 },
        { "details-content", 16696624, 15 },
        { "details-marker", 10084267, 14 },
        { "details-summary", 12451391, 15 },
        { "editing-view-port", 3347658, 17 },
        { "file-upload-button", 9713997, 18 },
        { "optgroup-label", 14380082, 14 },
        { "password-reveal", 13799031, 15 },
        { "picker", 11224516, 6 },
        { "placeholder", 6132349, 11 },
        { "search-clear", 12955485, 12 },
        { "spin", 13451339, 4 },
        { "text-field-container", 1467182, 20 },
        { "thumb", 14593165, 5 },
        { "track", 10988706, 5 },
    };

    for (size_t i = 0; i < std::size(kNames); ++i) {
        StringImpl* impl = StringImpl::CreateStatic(kNames[i].name, kNames[i].length, kNames[i].hash);
        void* address = reinterpret_cast<AtomicString*>(&names_storage) + i;
        new (address) AtomicString(impl);
    }
}

} // namespace shadow_element_names
} // namespace blink
