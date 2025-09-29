// Copyright 2010 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/win/i18n.h"

#include <windows.h>

#include <ostream>

#include "base/check_op.h"
#include "base/strings/string_piece.h"
#include "base/strings/string_split.h"
#include "base/strings/string_util.h"

namespace {

using GetPreferredUILanguages_Fn = decltype(::GetSystemPreferredUILanguages)*;

#ifndef SUPPORT_XP_CODE

constexpr base::WStringPiece kNullTerminator { L"\0", 1 };

bool GetPreferredUILanguageList(GetPreferredUILanguages_Fn function, ULONG flags, std::vector<std::wstring>* languages)
{
    DCHECK_EQ((flags & (MUI_LANGUAGE_ID | MUI_LANGUAGE_NAME)), 0U);
    const ULONG call_flags = flags | MUI_LANGUAGE_NAME;
    ULONG language_count = 0;
    ULONG buffer_length = 0;
    if (!function(call_flags, &language_count, nullptr, &buffer_length) || !buffer_length) {
        DPCHECK(!buffer_length) << "Failed getting size of preferred UI languages.";
        return false;
    }

    std::wstring buffer(buffer_length, '\0');
    if (!function(call_flags, &language_count, std::data(buffer), &buffer_length) || !language_count) {
        DPCHECK(!language_count) << "Failed getting preferred UI languages.";
        return false;
    }

    // The buffer has been populated with a series of strings separated by
    // terminators, which ends with a single empty string (two terminators in a
    // row). Chop off the last of those two terminators so that |buffer| is a
    // basic_string that contains the terminator ending the last string but not
    // the terminator denoting an empty string.
    buffer.resize(buffer_length - 1);

    // Split string on NUL characters.
    ULONG languages_added = 0;
    for (auto token : base::SplitStringPiece(buffer, kNullTerminator, base::KEEP_WHITESPACE, base::SPLIT_WANT_NONEMPTY)) {
        languages->emplace_back(token);
        ++languages_added;
    }
    DCHECK_EQ(languages_added, language_count);
    return true;
}

#else

// Keep this enum in sync with kLanguageFunctionNames.
enum LanguageFunction { SYSTEM_LANGUAGES, USER_LANGUAGES, PROCESS_LANGUAGES, THREAD_LANGUAGES, NUM_FUNCTIONS };

const char kSystemLanguagesFunctionName[] = "GetSystemPreferredUILanguages";
const char kUserLanguagesFunctionName[] = "GetUserPreferredUILanguages";
const char kProcessLanguagesFunctionName[] = "GetProcessPreferredUILanguages";
const char kThreadLanguagesFunctionName[] = "GetThreadPreferredUILanguages";

// Keep this array in sync with enum LanguageFunction.
const char* const kLanguageFunctionNames[]
    = { &kSystemLanguagesFunctionName[0], &kUserLanguagesFunctionName[0], &kProcessLanguagesFunctionName[0], &kThreadLanguagesFunctionName[0] };

// static_assert(NUM_FUNCTIONS == base::size(kLanguageFunctionNames), language_function_enum_and_names_out_of_sync);

// Calls one of the MUI Get*PreferredUILanguages functions, placing the result
// in |languages|.  |function| identifies the function to call and |flags| is
// the function-specific flags (callers must not specify MUI_LANGUAGE_ID or
// MUI_LANGUAGE_NAME).  Returns true if at least one language is placed in
// |languages|.
bool GetMUIPreferredUILanguageList(LanguageFunction function, ULONG flags, std::vector<wchar_t>* languages)
{
    DCHECK(0 <= function && NUM_FUNCTIONS > function);
    DCHECK_EQ(0U, (flags & (MUI_LANGUAGE_ID | MUI_LANGUAGE_NAME)));
    DCHECK(languages);

    HMODULE kernel32 = GetModuleHandle(L"kernel32.dll");
    if (NULL != kernel32) {
        GetPreferredUILanguages_Fn get_preferred_ui_languages
            = reinterpret_cast<GetPreferredUILanguages_Fn>(GetProcAddress(kernel32, kLanguageFunctionNames[function]));
        if (NULL != get_preferred_ui_languages) {
            const ULONG call_flags = flags | MUI_LANGUAGE_NAME;
            ULONG language_count = 0;
            ULONG buffer_length = 0;
            if (get_preferred_ui_languages(call_flags, &language_count, NULL, &buffer_length) && 0 != buffer_length) {
                languages->resize(buffer_length);
                if (get_preferred_ui_languages(call_flags, &language_count, &(*languages)[0], &buffer_length) && 0 != language_count) {
                    DCHECK(languages->size() == buffer_length);
                    return true;
                } else {
                    DPCHECK(0 == language_count) << "Failed getting preferred UI languages.";
                }
            } else {
                DPCHECK(0 == buffer_length) << "Failed getting size of preferred UI languages.";
            }
        } else {
            // DVLOG(2) << "MUI not available.";
            OutputDebugStringA("GetMUIPreferredUILanguageList: MUI not available.\n");
        }
    } else {
        // NOTREACHED() << "kernel32.dll not found.";
        DebugBreak();
    }

    return false;
}

bool GetUserDefaultUILanguage(std::wstring* language, std::wstring* region)
{
    DCHECK(language);

    LANGID lang_id = ::GetUserDefaultUILanguage();
    if (LOCALE_CUSTOM_UI_DEFAULT != lang_id) {
        const LCID locale_id = MAKELCID(lang_id, SORT_DEFAULT);
        // max size for LOCALE_SISO639LANGNAME and LOCALE_SISO3166CTRYNAME is 9
        wchar_t result_buffer[9];
        int result_length = GetLocaleInfo(locale_id, LOCALE_SISO639LANGNAME, &result_buffer[0], sizeof(result_buffer) / sizeof(wchar_t));
        DPCHECK(0 != result_length) << "Failed getting language id";
        if (1 < result_length) {
            language->assign(&result_buffer[0], (size_t)(result_length - 1));
            region->clear();
            if (SUBLANG_NEUTRAL != SUBLANGID(lang_id)) {
                result_length = GetLocaleInfo(locale_id, LOCALE_SISO3166CTRYNAME, &result_buffer[0], sizeof(result_buffer) / sizeof(wchar_t));
                DPCHECK(0 != result_length) << "Failed getting region id";
                if (1 < result_length)
                    region->assign(&result_buffer[0], (size_t)(result_length - 1));
            }
            return true;
        }
    } else {
        // This is entirely unexpected on pre-Vista, which is the only time we
        // should try GetUserDefaultUILanguage anyway.
        // NOTREACHED() << "Cannot determine language for a supplemental locale.";
        DebugBreak();
    }
    return false;
}

bool GetPreferredUILanguageList(LanguageFunction function, ULONG flags, std::vector<std::wstring>* languages)
{
    std::vector<wchar_t> buffer;
    std::wstring language;
    std::wstring region;

    if (GetMUIPreferredUILanguageList(function, flags, &buffer)) {
        std::vector<wchar_t>::const_iterator scan = buffer.begin();
        language.assign(&*scan);
        while (!language.empty()) {
            languages->push_back(language);
            scan += (int)(language.size() + 1);
            language.assign(&*scan);
        }
    } else if (GetUserDefaultUILanguage(&language, &region)) {
        // Mimic the MUI behavior of putting the neutral version of the lang after
        // the regional one (e.g., "fr-CA, fr").
        if (!region.empty())
            languages->push_back(std::wstring(language).append(1, L'-').append(region));
        languages->push_back(language);
    } else {
        return false;
    }

    return true;
}

#endif

} // namespace

namespace base {
namespace win {
namespace i18n {

#ifdef SUPPORT_XP_CODE

bool GetUserPreferredUILanguageList(std::vector<std::wstring>* languages)
{
    DCHECK(languages);
    return GetPreferredUILanguageList(USER_LANGUAGES, 0, languages);
}

bool GetThreadPreferredUILanguageList(std::vector<std::wstring>* languages)
{
    DCHECK(languages);
    return GetPreferredUILanguageList(THREAD_LANGUAGES, MUI_MERGE_SYSTEM_FALLBACK | MUI_MERGE_USER_FALLBACK, languages);
}

#else

bool GetUserPreferredUILanguageList(std::vector<std::wstring>* languages)
{
    DCHECK(languages);
    return GetPreferredUILanguageList(::GetUserPreferredUILanguages, 0, languages);
}

bool GetThreadPreferredUILanguageList(std::vector<std::wstring>* languages)
{
    DCHECK(languages);
    return GetPreferredUILanguageList(::GetThreadPreferredUILanguages, MUI_MERGE_SYSTEM_FALLBACK | MUI_MERGE_USER_FALLBACK, languages);
}

#endif // SUPPORT_XP_CODE

} // namespace i18n
} // namespace win
} // namespace base
