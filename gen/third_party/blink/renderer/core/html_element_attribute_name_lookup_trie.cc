// Copyright 2022 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_attribute_name_lookup_trie.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_attribute_names.json5

#include "third_party/blink/renderer/core/html_element_attribute_name_lookup_trie.h"

#include "third_party/blink/renderer/core/html_names.h"

namespace blink {

const QualifiedName& LookupHTMLAttributeName(const UChar* data, unsigned length)
{
    DCHECK(data);
    DCHECK(length);
    switch (length) {
    case 4:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'b':
                if (data[2] == 'b' && data[3] == 'r')
                    return html_names::kAbbrAttr;
                break;

            case 'x':
                if (data[2] == 'i' && data[3] == 's')
                    return html_names::kAxisAttr;
                break;
            }
            break;

        case 'c':
            switch (data[1]) {
            case 'h':
                if (data[2] == 'a' && data[3] == 'r')
                    return html_names::kCharAttr;
                break;

            case 'i':
                if (data[2] == 't' && data[3] == 'e')
                    return html_names::kCiteAttr;
                break;

            case 'o':
                switch (data[2]) {
                case 'd':
                    if (data[3] == 'e')
                        return html_names::kCodeAttr;
                    break;

                case 'l':
                    if (data[3] == 's')
                        return html_names::kColsAttr;
                    break;
                }
                break;
            }
            break;

        case 'd':
            if (data[1] == 'a' && data[2] == 't' && data[3] == 'a')
                return html_names::kDataAttr;
            break;

        case 'f':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'c' && data[3] == 'e')
                    return html_names::kFaceAttr;
                break;

            case 'o':
                if (data[2] == 'r' && data[3] == 'm')
                    return html_names::kFormAttr;
                break;
            }
            break;

        case 'h':
            switch (data[1]) {
            case 'i':
                if (data[2] == 'g' && data[3] == 'h')
                    return html_names::kHighAttr;
                break;

            case 'r':
                if (data[2] == 'e' && data[3] == 'f')
                    return html_names::kHrefAttr;
                break;
            }
            break;

        case 'k':
            if (data[1] == 'i' && data[2] == 'n' && data[3] == 'd')
                return html_names::kKindAttr;
            break;

        case 'l':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'n' && data[3] == 'g')
                    return html_names::kLangAttr;
                break;

            case 'i':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 'k')
                        return html_names::kLinkAttr;
                    break;

                case 's':
                    if (data[3] == 't')
                        return html_names::kListAttr;
                    break;
                }
                break;

            case 'o':
                if (data[2] == 'o' && data[3] == 'p')
                    return html_names::kLoopAttr;
                break;
            }
            break;

        case 'm':
            if (data[1] == 'o' && data[2] == 'd' && data[3] == 'e')
                return html_names::kModeAttr;
            break;

        case 'n':
            if (data[1] == 'a' && data[2] == 'm' && data[3] == 'e')
                return html_names::kNameAttr;
            break;

        case 'o':
            if (data[1] == 'p' && data[2] == 'e' && data[3] == 'n')
                return html_names::kOpenAttr;
            break;

        case 'p':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'r' && data[3] == 't')
                    return html_names::kPartAttr;
                break;

            case 'i':
                if (data[2] == 'n' && data[3] == 'g')
                    return html_names::kPingAttr;
                break;
            }
            break;

        case 'r':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'l':
                    if (data[3] == 'e')
                        return html_names::kRoleAttr;
                    break;

                case 'w':
                    if (data[3] == 's')
                        return html_names::kRowsAttr;
                    break;
                }
                break;
            }
            break;

        case 's':
            switch (data[1]) {
            case 'i':
                if (data[2] == 'z' && data[3] == 'e')
                    return html_names::kSizeAttr;
                break;

            case 'l':
                if (data[2] == 'o' && data[3] == 't')
                    return html_names::kSlotAttr;
                break;

            case 'p':
                if (data[2] == 'a' && data[3] == 'n')
                    return html_names::kSpanAttr;
                break;

            case 't':
                if (data[2] == 'e' && data[3] == 'p')
                    return html_names::kStepAttr;
                break;
            }
            break;

        case 't':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'x' && data[3] == 't')
                    return html_names::kTextAttr;
                break;

            case 'y':
                if (data[2] == 'p' && data[3] == 'e')
                    return html_names::kTypeAttr;
                break;
            }
            break;

        case 'w':
            if (data[1] == 'r' && data[2] == 'a' && data[3] == 'p')
                return html_names::kWrapAttr;
            break;
        }
        break;

    case 14:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'c' && data[3] == 'e' && data[4] == 'p' && data[5] == 't' && data[6] == '-' && data[7] == 'c' && data[8] == 'h' && data[9] == 'a' && data[10] == 'r'
                    && data[11] == 's' && data[12] == 'e' && data[13] == 't')
                    return html_names::kAcceptCharsetAttr;
                break;

            case 't':
                if (data[2] == 't' && data[3] == 'r' && data[4] == 'i' && data[5] == 'b' && data[6] == 'u' && data[7] == 't' && data[8] == 'i' && data[9] == 'o' && data[10] == 'n'
                    && data[11] == 's' && data[12] == 'r' && data[13] == 'c')
                    return html_names::kAttributionsrcAttr;
                break;

            case 'u':
                if (data[2] == 't' && data[3] == 'o' && data[4] == 'c' && data[5] == 'a' && data[6] == 'p' && data[7] == 'i' && data[8] == 't' && data[9] == 'a' && data[10] == 'l'
                    && data[11] == 'i' && data[12] == 'z' && data[13] == 'e')
                    return html_names::kAutocapitalizeAttr;
                break;
            }
            break;

        case 'd':
            if (data[1] == 'e' && data[2] == 'l' && data[3] == 'e' && data[4] == 'g' && data[5] == 'a' && data[6] == 't' && data[7] == 'e' && data[8] == 's' && data[9] == 'f'
                && data[10] == 'o' && data[11] == 'c' && data[12] == 'u' && data[13] == 's')
                return html_names::kDelegatesfocusAttr;
            break;

        case 'f':
            if (data[1] == 'o' && data[2] == 'r' && data[3] == 'm' && data[4] == 'n' && data[5] == 'o' && data[6] == 'v' && data[7] == 'a' && data[8] == 'l' && data[9] == 'i'
                && data[10] == 'd' && data[11] == 'a' && data[12] == 't' && data[13] == 'e')
                return html_names::kFormnovalidateAttr;
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 'n' && data[4] == 'i' && data[5] == 'm' && data[6] == 'a' && data[7] == 't' && data[8] == 'i' && data[9] == 'o' && data[10] == 'n'
                        && data[11] == 'e' && data[12] == 'n' && data[13] == 'd')
                        return html_names::kOnanimationendAttr;
                    break;

                case 'b':
                    if (data[3] == 'e' && data[4] == 'f' && data[5] == 'o' && data[6] == 'r' && data[7] == 'e' && data[8] == 'u' && data[9] == 'n' && data[10] == 'l'
                        && data[11] == 'o' && data[12] == 'a' && data[13] == 'd')
                        return html_names::kOnbeforeunloadAttr;
                    break;

                case 'm':
                    if (data[3] == 'e' && data[4] == 's' && data[5] == 's' && data[6] == 'a' && data[7] == 'g' && data[8] == 'e' && data[9] == 'e' && data[10] == 'r'
                        && data[11] == 'r' && data[12] == 'o' && data[13] == 'r')
                        return html_names::kOnmessageerrorAttr;
                    break;

                case 'p':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'i':
                            switch (data[5]) {
                            case 'n':
                                switch (data[6]) {
                                case 't':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 'r':
                                            switch (data[9]) {
                                            case 'e':
                                                if (data[10] == 'n' && data[11] == 't' && data[12] == 'e' && data[13] == 'r')
                                                    return html_names::kOnpointerenterAttr;
                                                break;

                                            case 'l':
                                                if (data[10] == 'e' && data[11] == 'a' && data[12] == 'v' && data[13] == 'e')
                                                    return html_names::kOnpointerleaveAttr;
                                                break;
                                            }
                                            break;
                                        }
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;

                case 'v':
                    if (data[3] == 'o' && data[4] == 'l' && data[5] == 'u' && data[6] == 'm' && data[7] == 'e' && data[8] == 'c' && data[9] == 'h' && data[10] == 'a'
                        && data[11] == 'n' && data[12] == 'g' && data[13] == 'e')
                        return html_names::kOnvolumechangeAttr;
                    break;
                }
                break;
            }
            break;

        case 'r':
            if (data[1] == 'e' && data[2] == 'f' && data[3] == 'e' && data[4] == 'r' && data[5] == 'r' && data[6] == 'e' && data[7] == 'r' && data[8] == 'p' && data[9] == 'o'
                && data[10] == 'l' && data[11] == 'i' && data[12] == 'c' && data[13] == 'y')
                return html_names::kReferrerpolicyAttr;
            break;
        }
        break;

    case 6:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                switch (data[2]) {
                case 'c':
                    if (data[3] == 'e' && data[4] == 'p' && data[5] == 't')
                        return html_names::kAcceptAttr;
                    break;

                case 't':
                    if (data[3] == 'i' && data[4] == 'o' && data[5] == 'n')
                        return html_names::kActionAttr;
                    break;
                }
                break;

            case 'n':
                if (data[2] == 'c' && data[3] == 'h' && data[4] == 'o' && data[5] == 'r')
                    return html_names::kAnchorAttr;
                break;
            }
            break;

        case 'b':
            if (data[1] == 'o' && data[2] == 'r' && data[3] == 'd' && data[4] == 'e' && data[5] == 'r')
                return html_names::kBorderAttr;
            break;

        case 'c':
            if (data[1] == 'o' && data[2] == 'o' && data[3] == 'r' && data[4] == 'd' && data[5] == 's')
                return html_names::kCoordsAttr;
            break;

        case 'h':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'i' && data[3] == 'g' && data[4] == 'h' && data[5] == 't')
                    return html_names::kHeightAttr;
                break;

            case 'i':
                if (data[2] == 'd' && data[3] == 'd' && data[4] == 'e' && data[5] == 'n')
                    return html_names::kHiddenAttr;
                break;

            case 's':
                if (data[2] == 'p' && data[3] == 'a' && data[4] == 'c' && data[5] == 'e')
                    return html_names::kHspaceAttr;
                break;
            }
            break;

        case 'l':
            if (data[1] == 'o' && data[2] == 'w' && data[3] == 's' && data[4] == 'r' && data[5] == 'c')
                return html_names::kLowsrcAttr;
            break;

        case 'm':
            if (data[1] == 'e' && data[2] == 't' && data[3] == 'h' && data[4] == 'o' && data[5] == 'd')
                return html_names::kMethodAttr;
            break;

        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'h':
                    if (data[3] == 'r' && data[4] == 'e' && data[5] == 'f')
                        return html_names::kNohrefAttr;
                    break;

                case 'w':
                    if (data[3] == 'r' && data[4] == 'a' && data[5] == 'p')
                        return html_names::kNowrapAttr;
                    break;
                }
                break;
            }
            break;

        case 'o':
            switch (data[1]) {
            case 'b':
                if (data[2] == 'j' && data[3] == 'e' && data[4] == 'c' && data[5] == 't')
                    return html_names::kObjectAttr;
                break;

            case 'n':
                switch (data[2]) {
                case 'b':
                    if (data[3] == 'l' && data[4] == 'u' && data[5] == 'r')
                        return html_names::kOnblurAttr;
                    break;

                case 'c':
                    if (data[3] == 'o' && data[4] == 'p' && data[5] == 'y')
                        return html_names::kOncopyAttr;
                    break;

                case 'd':
                    switch (data[3]) {
                    case 'r':
                        switch (data[4]) {
                        case 'a':
                            if (data[5] == 'g')
                                return html_names::kOndragAttr;
                            break;

                        case 'o':
                            if (data[5] == 'p')
                                return html_names::kOndropAttr;
                            break;
                        }
                        break;
                    }
                    break;

                case 'l':
                    if (data[3] == 'o' && data[4] == 'a' && data[5] == 'd')
                        return html_names::kOnloadAttr;
                    break;

                case 'p':
                    if (data[3] == 'l' && data[4] == 'a' && data[5] == 'y')
                        return html_names::kOnplayAttr;
                    break;

                case 's':
                    if (data[3] == 'h' && data[4] == 'o' && data[5] == 'w')
                        return html_names::kOnshowAttr;
                    break;
                }
                break;
            }
            break;

        case 'p':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'l':
                    if (data[3] == 'i' && data[4] == 'c' && data[5] == 'y')
                        return html_names::kPolicyAttr;
                    break;

                case 's':
                    if (data[3] == 't' && data[4] == 'e' && data[5] == 'r')
                        return html_names::kPosterAttr;
                    break;
                }
                break;

            case 's':
                if (data[2] == 'e' && data[3] == 'u' && data[4] == 'd' && data[5] == 'o')
                    return html_names::kPseudoAttr;
                break;
            }
            break;

        case 's':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'h' && data[3] == 'e' && data[4] == 'm' && data[5] == 'e')
                    return html_names::kSchemeAttr;
                break;

            case 'e':
                if (data[2] == 'l' && data[3] == 'e' && data[4] == 'c' && data[5] == 't')
                    return html_names::kSelectAttr;
                break;

            case 'r':
                switch (data[2]) {
                case 'c':
                    switch (data[3]) {
                    case 'd':
                        if (data[4] == 'o' && data[5] == 'c')
                            return html_names::kSrcdocAttr;
                        break;

                    case 's':
                        if (data[4] == 'e' && data[5] == 't')
                            return html_names::kSrcsetAttr;
                        break;
                    }
                    break;
                }
                break;
            }
            break;

        case 't':
            if (data[1] == 'a' && data[2] == 'r' && data[3] == 'g' && data[4] == 'e' && data[5] == 't')
                return html_names::kTargetAttr;
            break;

        case 'u':
            if (data[1] == 's' && data[2] == 'e' && data[3] == 'm' && data[4] == 'a' && data[5] == 'p')
                return html_names::kUsemapAttr;
            break;

        case 'v':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'l' && data[3] == 'i' && data[4] == 'g' && data[5] == 'n')
                    return html_names::kValignAttr;
                break;

            case 's':
                if (data[2] == 'p' && data[3] == 'a' && data[4] == 'c' && data[5] == 'e')
                    return html_names::kVspaceAttr;
                break;
            }
            break;
        }
        break;

    case 9:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'c' && data[3] == 'e' && data[4] == 's' && data[5] == 's' && data[6] == 'k' && data[7] == 'e' && data[8] == 'y')
                    return html_names::kAccesskeyAttr;
                break;

            case 'n':
                if (data[2] == 'o' && data[3] == 'n' && data[4] == 'y' && data[5] == 'm' && data[6] == 'o' && data[7] == 'u' && data[8] == 's')
                    return html_names::kAnonymousAttr;
                break;

            case 'u':
                if (data[2] == 't' && data[3] == 'o' && data[4] == 'f' && data[5] == 'o' && data[6] == 'c' && data[7] == 'u' && data[8] == 's')
                    return html_names::kAutofocusAttr;
                break;
            }
            break;

        case 'c':
            if (data[1] == 'h' && data[2] == 'a' && data[3] == 'l' && data[4] == 'l' && data[5] == 'e' && data[6] == 'n' && data[7] == 'g' && data[8] == 'e')
                return html_names::kChallengeAttr;
            break;

        case 'd':
            switch (data[1]) {
            case 'i':
                if (data[2] == 'r' && data[3] == 'e' && data[4] == 'c' && data[5] == 't' && data[6] == 'i' && data[7] == 'o' && data[8] == 'n')
                    return html_names::kDirectionAttr;
                break;

            case 'r':
                if (data[2] == 'a' && data[3] == 'g' && data[4] == 'g' && data[5] == 'a' && data[6] == 'b' && data[7] == 'l' && data[8] == 'e')
                    return html_names::kDraggableAttr;
                break;
            }
            break;

        case 'i':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'p':
                    if (data[3] == 'u' && data[4] == 't' && data[5] == 'm' && data[6] == 'o' && data[7] == 'd' && data[8] == 'e')
                        return html_names::kInputmodeAttr;
                    break;

                case 't':
                    if (data[3] == 'e' && data[4] == 'g' && data[5] == 'r' && data[6] == 'i' && data[7] == 't' && data[8] == 'y')
                        return html_names::kIntegrityAttr;
                    break;

                case 'v':
                    if (data[3] == 'i' && data[4] == 's' && data[5] == 'i' && data[6] == 'b' && data[7] == 'l' && data[8] == 'e')
                        return html_names::kInvisibleAttr;
                    break;
                }
                break;
            }
            break;

        case 'm':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'x':
                    if (data[3] == 'l' && data[4] == 'e' && data[5] == 'n' && data[6] == 'g' && data[7] == 't' && data[8] == 'h')
                        return html_names::kMaxlengthAttr;
                    break;

                case 'y':
                    if (data[3] == 's' && data[4] == 'c' && data[5] == 'r' && data[6] == 'i' && data[7] == 'p' && data[8] == 't')
                        return html_names::kMayscriptAttr;
                    break;
                }
                break;

            case 'i':
                if (data[2] == 'n' && data[3] == 'l' && data[4] == 'e' && data[5] == 'n' && data[6] == 'g' && data[7] == 't' && data[8] == 'h')
                    return html_names::kMinlengthAttr;
                break;
            }
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'c':
                    if (data[3] == 'a' && data[4] == 'n' && data[5] == 'p' && data[6] == 'l' && data[7] == 'a' && data[8] == 'y')
                        return html_names::kOncanplayAttr;
                    break;

                case 'd':
                    if (data[3] == 'r' && data[4] == 'a' && data[5] == 'g' && data[6] == 'e' && data[7] == 'n' && data[8] == 'd')
                        return html_names::kOndragendAttr;
                    break;

                case 'e':
                    if (data[3] == 'm' && data[4] == 'p' && data[5] == 't' && data[6] == 'i' && data[7] == 'e' && data[8] == 'd')
                        return html_names::kOnemptiedAttr;
                    break;

                case 'f':
                    if (data[3] == 'o' && data[4] == 'c' && data[5] == 'u' && data[6] == 's' && data[7] == 'i' && data[8] == 'n')
                        return html_names::kOnfocusinAttr;
                    break;

                case 'i':
                    if (data[3] == 'n' && data[4] == 'v' && data[5] == 'a' && data[6] == 'l' && data[7] == 'i' && data[8] == 'd')
                        return html_names::kOninvalidAttr;
                    break;

                case 'k':
                    if (data[3] == 'e' && data[4] == 'y' && data[5] == 'd' && data[6] == 'o' && data[7] == 'w' && data[8] == 'n')
                        return html_names::kOnkeydownAttr;
                    break;

                case 'm':
                    switch (data[3]) {
                    case 'e':
                        if (data[4] == 's' && data[5] == 's' && data[6] == 'a' && data[7] == 'g' && data[8] == 'e')
                            return html_names::kOnmessageAttr;
                        break;

                    case 'o':
                        if (data[4] == 'u' && data[5] == 's' && data[6] == 'e' && data[7] == 'u' && data[8] == 'p')
                            return html_names::kOnmouseupAttr;
                        break;
                    }
                    break;

                case 'o':
                    if (data[3] == 'f' && data[4] == 'f' && data[5] == 'l' && data[6] == 'i' && data[7] == 'n' && data[8] == 'e')
                        return html_names::kOnofflineAttr;
                    break;

                case 'p':
                    if (data[3] == 'l' && data[4] == 'a' && data[5] == 'y' && data[6] == 'i' && data[7] == 'n' && data[8] == 'g')
                        return html_names::kOnplayingAttr;
                    break;

                case 's':
                    switch (data[3]) {
                    case 'e':
                        if (data[4] == 'e' && data[5] == 'k' && data[6] == 'i' && data[7] == 'n' && data[8] == 'g')
                            return html_names::kOnseekingAttr;
                        break;

                    case 't':
                        switch (data[4]) {
                        case 'a':
                            if (data[5] == 'l' && data[6] == 'l' && data[7] == 'e' && data[8] == 'd')
                                return html_names::kOnstalledAttr;
                            break;

                        case 'o':
                            if (data[5] == 'r' && data[6] == 'a' && data[7] == 'g' && data[8] == 'e')
                                return html_names::kOnstorageAttr;
                            break;
                        }
                        break;

                    case 'u':
                        if (data[4] == 's' && data[5] == 'p' && data[6] == 'e' && data[7] == 'n' && data[8] == 'd')
                            return html_names::kOnsuspendAttr;
                        break;
                    }
                    break;

                case 'w':
                    if (data[3] == 'a' && data[4] == 'i' && data[5] == 't' && data[6] == 'i' && data[7] == 'n' && data[8] == 'g')
                        return html_names::kOnwaitingAttr;
                    break;
                }
                break;
            }
            break;

        case 's':
            if (data[1] == 'c' && data[2] == 'r' && data[3] == 'o' && data[4] == 'l' && data[5] == 'l' && data[6] == 'i' && data[7] == 'n' && data[8] == 'g')
                return html_names::kScrollingAttr;
            break;

        case 't':
            switch (data[1]) {
            case 'o':
                if (data[2] == 'p' && data[3] == 'm' && data[4] == 'a' && data[5] == 'r' && data[6] == 'g' && data[7] == 'i' && data[8] == 'n')
                    return html_names::kTopmarginAttr;
                break;

            case 'r':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 'n' && data[4] == 's' && data[5] == 'l' && data[6] == 'a' && data[7] == 't' && data[8] == 'e')
                        return html_names::kTranslateAttr;
                    break;

                case 'u':
                    if (data[3] == 'e' && data[4] == 's' && data[5] == 'p' && data[6] == 'e' && data[7] == 'e' && data[8] == 'd')
                        return html_names::kTruespeedAttr;
                    break;
                }
                break;
            }
            break;

        case 'v':
            if (data[1] == 'a' && data[2] == 'l' && data[3] == 'u' && data[4] == 'e' && data[5] == 't' && data[6] == 'y' && data[7] == 'p' && data[8] == 'e')
                return html_names::kValuetypeAttr;
            break;
        }
        break;

    case 5:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'l':
                switch (data[2]) {
                case 'i':
                    switch (data[3]) {
                    case 'g':
                        if (data[4] == 'n')
                            return html_names::kAlignAttr;
                        break;

                    case 'n':
                        if (data[4] == 'k')
                            return html_names::kAlinkAttr;
                        break;
                    }
                    break;

                case 'l':
                    if (data[3] == 'o' && data[4] == 'w')
                        return html_names::kAllowAttr;
                    break;
                }
                break;

            case 's':
                if (data[2] == 'y' && data[3] == 'n' && data[4] == 'c')
                    return html_names::kAsyncAttr;
                break;
            }
            break;

        case 'c':
            switch (data[1]) {
            case 'l':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 's' && data[4] == 's')
                        return html_names::kClassAttr;
                    break;

                case 'e':
                    if (data[3] == 'a' && data[4] == 'r')
                        return html_names::kClearAttr;
                    break;
                }
                break;

            case 'o':
                if (data[2] == 'l' && data[3] == 'o' && data[4] == 'r')
                    return html_names::kColorAttr;
                break;
            }
            break;

        case 'd':
            if (data[1] == 'e' && data[2] == 'f' && data[3] == 'e' && data[4] == 'r')
                return html_names::kDeferAttr;
            break;

        case 'e':
            if (data[1] == 'v' && data[2] == 'e' && data[3] == 'n' && data[4] == 't')
                return html_names::kEventAttr;
            break;

        case 'f':
            if (data[1] == 'r' && data[2] == 'a' && data[3] == 'm' && data[4] == 'e')
                return html_names::kFrameAttr;
            break;

        case 'i':
            switch (data[1]) {
            case 'n':
                if (data[2] == 'e' && data[3] == 'r' && data[4] == 't')
                    return html_names::kInertAttr;
                break;

            case 's':
                if (data[2] == 'm' && data[3] == 'a' && data[4] == 'p')
                    return html_names::kIsmapAttr;
                break;
            }
            break;

        case 'l':
            if (data[1] == 'a' && data[2] == 'b' && data[3] == 'e' && data[4] == 'l')
                return html_names::kLabelAttr;
            break;

        case 'm':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'd' && data[3] == 'i' && data[4] == 'a')
                    return html_names::kMediaAttr;
                break;

            case 'u':
                if (data[2] == 't' && data[3] == 'e' && data[4] == 'd')
                    return html_names::kMutedAttr;
                break;
            }
            break;

        case 'n':
            if (data[1] == 'o' && data[2] == 'n' && data[3] == 'c' && data[4] == 'e')
                return html_names::kNonceAttr;
            break;

        case 'o':
            if (data[1] == 'n' && data[2] == 'c' && data[3] == 'u' && data[4] == 't')
                return html_names::kOncutAttr;
            break;

        case 'p':
            if (data[1] == 'o' && data[2] == 'p' && data[3] == 'u' && data[4] == 'p')
                return html_names::kPopupAttr;
            break;

        case 'r':
            if (data[1] == 'u' && data[2] == 'l' && data[3] == 'e' && data[4] == 's')
                return html_names::kRulesAttr;
            break;

        case 's':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'o' && data[3] == 'p' && data[4] == 'e')
                    return html_names::kScopeAttr;
                break;

            case 'h':
                if (data[2] == 'a' && data[3] == 'p' && data[4] == 'e')
                    return html_names::kShapeAttr;
                break;

            case 'i':
                if (data[2] == 'z' && data[3] == 'e' && data[4] == 's')
                    return html_names::kSizesAttr;
                break;

            case 't':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 'r' && data[4] == 't')
                        return html_names::kStartAttr;
                    break;

                case 'y':
                    if (data[3] == 'l' && data[4] == 'e')
                        return html_names::kStyleAttr;
                    break;
                }
                break;
            }
            break;

        case 't':
            if (data[1] == 'i' && data[2] == 't' && data[3] == 'l' && data[4] == 'e')
                return html_names::kTitleAttr;
            break;

        case 'v':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'l' && data[3] == 'u' && data[4] == 'e')
                    return html_names::kValueAttr;
                break;

            case 'l':
                if (data[2] == 'i' && data[3] == 'n' && data[4] == 'k')
                    return html_names::kVlinkAttr;
                break;
            }
            break;

        case 'w':
            if (data[1] == 'i' && data[2] == 'd' && data[3] == 't' && data[4] == 'h')
                return html_names::kWidthAttr;
            break;
        }
        break;

    case 15:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'l' && data[2] == 'l' && data[3] == 'o' && data[4] == 'w' && data[5] == 'f' && data[6] == 'u' && data[7] == 'l' && data[8] == 'l' && data[9] == 's'
                && data[10] == 'c' && data[11] == 'r' && data[12] == 'e' && data[13] == 'e' && data[14] == 'n')
                return html_names::kAllowfullscreenAttr;
            break;

        case 'c':
            if (data[1] == 'o' && data[2] == 'n' && data[3] == 't' && data[4] == 'e' && data[5] == 'n' && data[6] == 't' && data[7] == 'e' && data[8] == 'd' && data[9] == 'i'
                && data[10] == 't' && data[11] == 'a' && data[12] == 'b' && data[13] == 'l' && data[14] == 'e')
                return html_names::kContenteditableAttr;
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'p':
                    if (data[3] == 'o' && data[4] == 'i' && data[5] == 'n' && data[6] == 't' && data[7] == 'e' && data[8] == 'r' && data[9] == 'c' && data[10] == 'a'
                        && data[11] == 'n' && data[12] == 'c' && data[13] == 'e' && data[14] == 'l')
                        return html_names::kOnpointercancelAttr;
                    break;

                case 't':
                    if (data[3] == 'r' && data[4] == 'a' && data[5] == 'n' && data[6] == 's' && data[7] == 'i' && data[8] == 't' && data[9] == 'i' && data[10] == 'o'
                        && data[11] == 'n' && data[12] == 'e' && data[13] == 'n' && data[14] == 'd')
                        return html_names::kOntransitionendAttr;
                    break;
                }
                break;
            }
            break;

        case 'p':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'p':
                    switch (data[3]) {
                    case 'u':
                        switch (data[4]) {
                        case 'p':
                            switch (data[5]) {
                            case 'h':
                                if (data[6] == 'i' && data[7] == 'd' && data[8] == 'e' && data[9] == 't' && data[10] == 'a' && data[11] == 'r' && data[12] == 'g' && data[13] == 'e'
                                    && data[14] == 't')
                                    return html_names::kPopuphidetargetAttr;
                                break;

                            case 's':
                                if (data[6] == 'h' && data[7] == 'o' && data[8] == 'w' && data[9] == 't' && data[10] == 'a' && data[11] == 'r' && data[12] == 'g' && data[13] == 'e'
                                    && data[14] == 't')
                                    return html_names::kPopupshowtargetAttr;
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;

        case 'w':
            if (data[1] == 'e' && data[2] == 'b' && data[3] == 'k' && data[4] == 'i' && data[5] == 't' && data[6] == 'd' && data[7] == 'i' && data[8] == 'r' && data[9] == 'e'
                && data[10] == 'c' && data[11] == 't' && data[12] == 'o' && data[13] == 'r' && data[14] == 'y')
                return html_names::kWebkitdirectoryAttr;
            break;
        }
        break;

    case 19:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'l' && data[2] == 'l' && data[3] == 'o' && data[4] == 'w' && data[5] == 'p' && data[6] == 'a' && data[7] == 'y' && data[8] == 'm' && data[9] == 'e'
                && data[10] == 'n' && data[11] == 't' && data[12] == 'r' && data[13] == 'e' && data[14] == 'q' && data[15] == 'u' && data[16] == 'e' && data[17] == 's'
                && data[18] == 't')
                return html_names::kAllowpaymentrequestAttr;
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'g':
                    if (data[3] == 'o' && data[4] == 't' && data[5] == 'p' && data[6] == 'o' && data[7] == 'i' && data[8] == 'n' && data[9] == 't' && data[10] == 'e'
                        && data[11] == 'r' && data[12] == 'c' && data[13] == 'a' && data[14] == 'p' && data[15] == 't' && data[16] == 'u' && data[17] == 'r' && data[18] == 'e')
                        return html_names::kOngotpointercaptureAttr;
                    break;

                case 'o':
                    if (data[3] == 'r' && data[4] == 'i' && data[5] == 'e' && data[6] == 'n' && data[7] == 't' && data[8] == 'a' && data[9] == 't' && data[10] == 'i'
                        && data[11] == 'o' && data[12] == 'n' && data[13] == 'c' && data[14] == 'h' && data[15] == 'a' && data[16] == 'n' && data[17] == 'g' && data[18] == 'e')
                        return html_names::kOnorientationchangeAttr;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 3:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'l' && data[2] == 't')
                return html_names::kAltAttr;
            break;

        case 'c':
            if (data[1] == 's' && data[2] == 'p')
                return html_names::kCspAttr;
            break;

        case 'd':
            if (data[1] == 'i' && data[2] == 'r')
                return html_names::kDirAttr;
            break;

        case 'e':
            if (data[1] == 'n' && data[2] == 'd')
                return html_names::kEndAttr;
            break;

        case 'f':
            if (data[1] == 'o' && data[2] == 'r')
                return html_names::kForAttr;
            break;

        case 'l':
            if (data[1] == 'o' && data[2] == 'w')
                return html_names::kLowAttr;
            break;

        case 'm':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'x')
                    return html_names::kMaxAttr;
                break;

            case 'i':
                if (data[2] == 'n')
                    return html_names::kMinAttr;
                break;
            }
            break;

        case 'r':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'l':
                    return html_names::kRelAttr;

                case 'v':
                    return html_names::kRevAttr;
                }
                break;
            }
            break;

        case 's':
            if (data[1] == 'r' && data[2] == 'c')
                return html_names::kSrcAttr;
            break;
        }
        break;

    case 7:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'r' && data[2] == 'c' && data[3] == 'h' && data[4] == 'i' && data[5] == 'v' && data[6] == 'e')
                return html_names::kArchiveAttr;
            break;

        case 'b':
            if (data[1] == 'g' && data[2] == 'c' && data[3] == 'o' && data[4] == 'l' && data[5] == 'o' && data[6] == 'r')
                return html_names::kBgcolorAttr;
            break;

        case 'c':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'p' && data[3] == 't' && data[4] == 'u' && data[5] == 'r' && data[6] == 'e')
                    return html_names::kCaptureAttr;
                break;

            case 'h':
                switch (data[2]) {
                case 'a':
                    switch (data[3]) {
                    case 'r':
                        switch (data[4]) {
                        case 'o':
                            if (data[5] == 'f' && data[6] == 'f')
                                return html_names::kCharoffAttr;
                            break;

                        case 's':
                            if (data[5] == 'e' && data[6] == 't')
                                return html_names::kCharsetAttr;
                            break;
                        }
                        break;
                    }
                    break;

                case 'e':
                    if (data[3] == 'c' && data[4] == 'k' && data[5] == 'e' && data[6] == 'd')
                        return html_names::kCheckedAttr;
                    break;
                }
                break;

            case 'l':
                if (data[2] == 'a' && data[3] == 's' && data[4] == 's' && data[5] == 'i' && data[6] == 'd')
                    return html_names::kClassidAttr;
                break;

            case 'o':
                switch (data[2]) {
                case 'l':
                    if (data[3] == 's' && data[4] == 'p' && data[5] == 'a' && data[6] == 'n')
                        return html_names::kColspanAttr;
                    break;

                case 'm':
                    if (data[3] == 'p' && data[4] == 'a' && data[5] == 'c' && data[6] == 't')
                        return html_names::kCompactAttr;
                    break;

                case 'n':
                    if (data[3] == 't' && data[4] == 'e' && data[5] == 'n' && data[6] == 't')
                        return html_names::kContentAttr;
                    break;
                }
                break;
            }
            break;

        case 'd':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'c':
                    if (data[3] == 'l' && data[4] == 'a' && data[5] == 'r' && data[6] == 'e')
                        return html_names::kDeclareAttr;
                    break;

                case 'f':
                    if (data[3] == 'a' && data[4] == 'u' && data[5] == 'l' && data[6] == 't')
                        return html_names::kDefaultAttr;
                    break;
                }
                break;

            case 'i':
                if (data[2] == 'r' && data[3] == 'n' && data[4] == 'a' && data[5] == 'm' && data[6] == 'e')
                    return html_names::kDirnameAttr;
                break;
            }
            break;

        case 'e':
            if (data[1] == 'n' && data[2] == 'c' && data[3] == 't' && data[4] == 'y' && data[5] == 'p' && data[6] == 'e')
                return html_names::kEnctypeAttr;
            break;

        case 'h':
            if (data[1] == 'e' && data[2] == 'a' && data[3] == 'd' && data[4] == 'e' && data[5] == 'r' && data[6] == 's')
                return html_names::kHeadersAttr;
            break;

        case 'k':
            if (data[1] == 'e' && data[2] == 'y' && data[3] == 't' && data[4] == 'y' && data[5] == 'p' && data[6] == 'e')
                return html_names::kKeytypeAttr;
            break;

        case 'l':
            if (data[1] == 'o' && data[2] == 'a' && data[3] == 'd' && data[4] == 'i' && data[5] == 'n' && data[6] == 'g')
                return html_names::kLoadingAttr;
            break;

        case 'n':
            if (data[1] == 'o' && data[2] == 's' && data[3] == 'h' && data[4] == 'a' && data[5] == 'd' && data[6] == 'e')
                return html_names::kNoshadeAttr;
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 'b' && data[4] == 'o' && data[5] == 'r' && data[6] == 't')
                        return html_names::kOnabortAttr;
                    break;

                case 'c':
                    switch (data[3]) {
                    case 'l':
                        switch (data[4]) {
                        case 'i':
                            if (data[5] == 'c' && data[6] == 'k')
                                return html_names::kOnclickAttr;
                            break;

                        case 'o':
                            if (data[5] == 's' && data[6] == 'e')
                                return html_names::kOncloseAttr;
                            break;
                        }
                        break;
                    }
                    break;

                case 'e':
                    switch (data[3]) {
                    case 'n':
                        if (data[4] == 'd' && data[5] == 'e' && data[6] == 'd')
                            return html_names::kOnendedAttr;
                        break;

                    case 'r':
                        if (data[4] == 'r' && data[5] == 'o' && data[6] == 'r')
                            return html_names::kOnerrorAttr;
                        break;
                    }
                    break;

                case 'f':
                    if (data[3] == 'o' && data[4] == 'c' && data[5] == 'u' && data[6] == 's')
                        return html_names::kOnfocusAttr;
                    break;

                case 'i':
                    if (data[3] == 'n' && data[4] == 'p' && data[5] == 'u' && data[6] == 't')
                        return html_names::kOninputAttr;
                    break;

                case 'k':
                    if (data[3] == 'e' && data[4] == 'y' && data[5] == 'u' && data[6] == 'p')
                        return html_names::kOnkeyupAttr;
                    break;

                case 'p':
                    switch (data[3]) {
                    case 'a':
                        switch (data[4]) {
                        case 's':
                            if (data[5] == 't' && data[6] == 'e')
                                return html_names::kOnpasteAttr;
                            break;

                        case 'u':
                            if (data[5] == 's' && data[6] == 'e')
                                return html_names::kOnpauseAttr;
                            break;
                        }
                        break;
                    }
                    break;

                case 'r':
                    if (data[3] == 'e' && data[4] == 's' && data[5] == 'e' && data[6] == 't')
                        return html_names::kOnresetAttr;
                    break;

                case 'w':
                    if (data[3] == 'h' && data[4] == 'e' && data[5] == 'e' && data[6] == 'l')
                        return html_names::kOnwheelAttr;
                    break;
                }
                break;

            case 'p':
                if (data[2] == 't' && data[3] == 'i' && data[4] == 'm' && data[5] == 'u' && data[6] == 'm')
                    return html_names::kOptimumAttr;
                break;
            }
            break;

        case 'p':
            switch (data[1]) {
            case 'a':
                if (data[2] == 't' && data[3] == 't' && data[4] == 'e' && data[5] == 'r' && data[6] == 'n')
                    return html_names::kPatternAttr;
                break;

            case 'r':
                if (data[2] == 'e' && data[3] == 'l' && data[4] == 'o' && data[5] == 'a' && data[6] == 'd')
                    return html_names::kPreloadAttr;
                break;
            }
            break;

        case 'r':
            if (data[1] == 'o' && data[2] == 'w' && data[3] == 's' && data[4] == 'p' && data[5] == 'a' && data[6] == 'n')
                return html_names::kRowspanAttr;
            break;

        case 's':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'n' && data[3] == 'd' && data[4] == 'b' && data[5] == 'o' && data[6] == 'x')
                    return html_names::kSandboxAttr;
                break;

            case 'r':
                if (data[2] == 'c' && data[3] == 'l' && data[4] == 'a' && data[5] == 'n' && data[6] == 'g')
                    return html_names::kSrclangAttr;
                break;

            case 't':
                if (data[2] == 'a' && data[3] == 'n' && data[4] == 'd' && data[5] == 'b' && data[6] == 'y')
                    return html_names::kStandbyAttr;
                break;

            case 'u':
                if (data[2] == 'm' && data[3] == 'm' && data[4] == 'a' && data[5] == 'r' && data[6] == 'y')
                    return html_names::kSummaryAttr;
                break;
            }
            break;

        case 'v':
            if (data[1] == 'e' && data[2] == 'r' && data[3] == 's' && data[4] == 'i' && data[5] == 'o' && data[6] == 'n')
                return html_names::kVersionAttr;
            break;
        }
        break;

    case 2:
        switch (data[0]) {
        case 'a':
            if (data[1] == 's')
                return html_names::kAsAttr;
            break;

        case 'i':
            switch (data[1]) {
            case 'd':
                return html_names::kIdAttr;

            case 's':
                return html_names::kIsAttr;
            }
            break;
        }
        break;

    case 12:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'u' && data[2] == 't' && data[3] == 'o' && data[4] == 'c' && data[5] == 'o' && data[6] == 'm' && data[7] == 'p' && data[8] == 'l' && data[9] == 'e'
                && data[10] == 't' && data[11] == 'e')
                return html_names::kAutocompleteAttr;
            break;

        case 'c':
            if (data[1] == 'o' && data[2] == 'n' && data[3] == 't' && data[4] == 'r' && data[5] == 'o' && data[6] == 'l' && data[7] == 's' && data[8] == 'l' && data[9] == 'i'
                && data[10] == 's' && data[11] == 't')
                return html_names::kControlslistAttr;
            break;

        case 'e':
            if (data[1] == 'n' && data[2] == 't' && data[3] == 'e' && data[4] == 'r' && data[5] == 'k' && data[6] == 'e' && data[7] == 'y' && data[8] == 'h' && data[9] == 'i'
                && data[10] == 'n' && data[11] == 't')
                return html_names::kEnterkeyhintAttr;
            break;

        case 'm':
            if (data[1] == 'a' && data[2] == 'r' && data[3] == 'g' && data[4] == 'i' && data[5] == 'n' && data[6] == 'h' && data[7] == 'e' && data[8] == 'i' && data[9] == 'g'
                && data[10] == 'h' && data[11] == 't')
                return html_names::kMarginheightAttr;
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 'f' && data[4] == 't' && data[5] == 'e' && data[6] == 'r' && data[7] == 'p' && data[8] == 'r' && data[9] == 'i' && data[10] == 'n'
                        && data[11] == 't')
                        return html_names::kOnafterprintAttr;
                    break;

                case 'b':
                    if (data[3] == 'e' && data[4] == 'f' && data[5] == 'o' && data[6] == 'r' && data[7] == 'e' && data[8] == 'c' && data[9] == 'o' && data[10] == 'p'
                        && data[11] == 'y')
                        return html_names::kOnbeforecopyAttr;
                    break;

                case 'h':
                    if (data[3] == 'a' && data[4] == 's' && data[5] == 'h' && data[6] == 'c' && data[7] == 'h' && data[8] == 'a' && data[9] == 'n' && data[10] == 'g'
                        && data[11] == 'e')
                        return html_names::kOnhashchangeAttr;
                    break;

                case 'l':
                    if (data[3] == 'o' && data[4] == 'a' && data[5] == 'd' && data[6] == 'e' && data[7] == 'd' && data[8] == 'd' && data[9] == 'a' && data[10] == 't'
                        && data[11] == 'a')
                        return html_names::kOnloadeddataAttr;
                    break;

                case 'm':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'u':
                            switch (data[5]) {
                            case 's':
                                switch (data[6]) {
                                case 'e':
                                    switch (data[7]) {
                                    case 'e':
                                        if (data[8] == 'n' && data[9] == 't' && data[10] == 'e' && data[11] == 'r')
                                            return html_names::kOnmouseenterAttr;
                                        break;

                                    case 'l':
                                        if (data[8] == 'e' && data[9] == 'a' && data[10] == 'v' && data[11] == 'e')
                                            return html_names::kOnmouseleaveAttr;
                                        break;

                                    case 'w':
                                        if (data[8] == 'h' && data[9] == 'e' && data[10] == 'e' && data[11] == 'l')
                                            return html_names::kOnmousewheelAttr;
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;

                case 'o':
                    if (data[3] == 'v' && data[4] == 'e' && data[5] == 'r' && data[6] == 's' && data[7] == 'c' && data[8] == 'r' && data[9] == 'o' && data[10] == 'l'
                        && data[11] == 'l')
                        return html_names::kOnoverscrollAttr;
                    break;

                case 'p':
                    if (data[3] == 'o' && data[4] == 'i' && data[5] == 'n' && data[6] == 't' && data[7] == 'e' && data[8] == 'r' && data[9] == 'o' && data[10] == 'u'
                        && data[11] == 't')
                        return html_names::kOnpointeroutAttr;
                    break;

                case 'r':
                    if (data[3] == 'a' && data[4] == 't' && data[5] == 'e' && data[6] == 'c' && data[7] == 'h' && data[8] == 'a' && data[9] == 'n' && data[10] == 'g'
                        && data[11] == 'e')
                        return html_names::kOnratechangeAttr;
                    break;

                case 's':
                    if (data[3] == 'l' && data[4] == 'o' && data[5] == 't' && data[6] == 'c' && data[7] == 'h' && data[8] == 'a' && data[9] == 'n' && data[10] == 'g'
                        && data[11] == 'e')
                        return html_names::kOnslotchangeAttr;
                    break;

                case 't':
                    switch (data[3]) {
                    case 'i':
                        if (data[4] == 'm' && data[5] == 'e' && data[6] == 'u' && data[7] == 'p' && data[8] == 'd' && data[9] == 'a' && data[10] == 't' && data[11] == 'e')
                            return html_names::kOntimeupdateAttr;
                        break;

                    case 'o':
                        if (data[4] == 'u' && data[5] == 'c' && data[6] == 'h' && data[7] == 's' && data[8] == 't' && data[9] == 'a' && data[10] == 'r' && data[11] == 't')
                            return html_names::kOntouchstartAttr;
                        break;
                    }
                    break;
                }
                break;
            }
            break;

        case 's':
            if (data[1] == 'c' && data[2] == 'r' && data[3] == 'o' && data[4] == 'l' && data[5] == 'l' && data[6] == 'a' && data[7] == 'm' && data[8] == 'o' && data[9] == 'u'
                && data[10] == 'n' && data[11] == 't')
                return html_names::kScrollamountAttr;
            break;
        }
        break;

    case 11:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'u' && data[2] == 't' && data[3] == 'o' && data[4] == 'c' && data[5] == 'o' && data[6] == 'r' && data[7] == 'r' && data[8] == 'e' && data[9] == 'c'
                && data[10] == 't')
                return html_names::kAutocorrectAttr;
            break;

        case 'b':
            if (data[1] == 'o' && data[2] == 'r' && data[3] == 'd' && data[4] == 'e' && data[5] == 'r' && data[6] == 'c' && data[7] == 'o' && data[8] == 'l' && data[9] == 'o'
                && data[10] == 'r')
                return html_names::kBordercolorAttr;
            break;

        case 'c':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'l':
                    switch (data[3]) {
                    case 'l':
                        switch (data[4]) {
                        case 'p':
                            if (data[5] == 'a' && data[6] == 'd' && data[7] == 'd' && data[8] == 'i' && data[9] == 'n' && data[10] == 'g')
                                return html_names::kCellpaddingAttr;
                            break;

                        case 's':
                            if (data[5] == 'p' && data[6] == 'a' && data[7] == 'c' && data[8] == 'i' && data[9] == 'n' && data[10] == 'g')
                                return html_names::kCellspacingAttr;
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;

            case 'r':
                if (data[2] == 'o' && data[3] == 's' && data[4] == 's' && data[5] == 'o' && data[6] == 'r' && data[7] == 'i' && data[8] == 'g' && data[9] == 'i' && data[10] == 'n')
                    return html_names::kCrossoriginAttr;
                break;
            }
            break;

        case 'd':
            if (data[1] == 'e' && data[2] == 'f' && data[3] == 'a' && data[4] == 'u' && data[5] == 'l' && data[6] == 't' && data[7] == 'o' && data[8] == 'p' && data[9] == 'e'
                && data[10] == 'n')
                return html_names::kDefaultopenAttr;
            break;

        case 'e':
            if (data[1] == 'x' && data[2] == 'p' && data[3] == 'o' && data[4] == 'r' && data[5] == 't' && data[6] == 'p' && data[7] == 'a' && data[8] == 'r' && data[9] == 't'
                && data[10] == 's')
                return html_names::kExportpartsAttr;
            break;

        case 'f':
            switch (data[1]) {
            case 'o':
                if (data[2] == 'r' && data[3] == 'm' && data[4] == 'e' && data[5] == 'n' && data[6] == 'c' && data[7] == 't' && data[8] == 'y' && data[9] == 'p' && data[10] == 'e')
                    return html_names::kFormenctypeAttr;
                break;

            case 'r':
                if (data[2] == 'a' && data[3] == 'm' && data[4] == 'e' && data[5] == 'b' && data[6] == 'o' && data[7] == 'r' && data[8] == 'd' && data[9] == 'e' && data[10] == 'r')
                    return html_names::kFrameborderAttr;
                break;
            }
            break;

        case 'i':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'a' && data[3] == 'g' && data[4] == 'e' && data[5] == 's' && data[6] == 'r' && data[7] == 'c' && data[8] == 's' && data[9] == 'e' && data[10] == 't')
                    return html_names::kImagesrcsetAttr;
                break;

            case 'n':
                if (data[2] == 'c' && data[3] == 'r' && data[4] == 'e' && data[5] == 'm' && data[6] == 'e' && data[7] == 'n' && data[8] == 't' && data[9] == 'a' && data[10] == 'l')
                    return html_names::kIncrementalAttr;
                break;
            }
            break;

        case 'l':
            if (data[1] == 'a' && data[2] == 't' && data[3] == 'e' && data[4] == 'n' && data[5] == 'c' && data[6] == 'y' && data[7] == 'h' && data[8] == 'i' && data[9] == 'n'
                && data[10] == 't')
                return html_names::kLatencyhintAttr;
            break;

        case 'm':
            if (data[1] == 'a' && data[2] == 'r' && data[3] == 'g' && data[4] == 'i' && data[5] == 'n' && data[6] == 'w' && data[7] == 'i' && data[8] == 'd' && data[9] == 't'
                && data[10] == 'h')
                return html_names::kMarginwidthAttr;
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'b':
                    if (data[3] == 'e' && data[4] == 'f' && data[5] == 'o' && data[6] == 'r' && data[7] == 'e' && data[8] == 'c' && data[9] == 'u' && data[10] == 't')
                        return html_names::kOnbeforecutAttr;
                    break;

                case 'c':
                    if (data[3] == 'u' && data[4] == 'e' && data[5] == 'c' && data[6] == 'h' && data[7] == 'a' && data[8] == 'n' && data[9] == 'g' && data[10] == 'e')
                        return html_names::kOncuechangeAttr;
                    break;

                case 'd':
                    switch (data[3]) {
                    case 'r':
                        switch (data[4]) {
                        case 'a':
                            switch (data[5]) {
                            case 'g':
                                switch (data[6]) {
                                case 'e':
                                    if (data[7] == 'n' && data[8] == 't' && data[9] == 'e' && data[10] == 'r')
                                        return html_names::kOndragenterAttr;
                                    break;

                                case 'l':
                                    if (data[7] == 'e' && data[8] == 'a' && data[9] == 'v' && data[10] == 'e')
                                        return html_names::kOndragleaveAttr;
                                    break;

                                case 's':
                                    if (data[7] == 't' && data[8] == 'a' && data[9] == 'r' && data[10] == 't')
                                        return html_names::kOndragstartAttr;
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;

                case 'l':
                    if (data[3] == 'o' && data[4] == 'a' && data[5] == 'd' && data[6] == 's' && data[7] == 't' && data[8] == 'a' && data[9] == 'r' && data[10] == 't')
                        return html_names::kOnloadstartAttr;
                    break;

                case 'm':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'u':
                            switch (data[5]) {
                            case 's':
                                switch (data[6]) {
                                case 'e':
                                    switch (data[7]) {
                                    case 'd':
                                        if (data[8] == 'o' && data[9] == 'w' && data[10] == 'n')
                                            return html_names::kOnmousedownAttr;
                                        break;

                                    case 'm':
                                        if (data[8] == 'o' && data[9] == 'v' && data[10] == 'e')
                                            return html_names::kOnmousemoveAttr;
                                        break;

                                    case 'o':
                                        if (data[8] == 'v' && data[9] == 'e' && data[10] == 'r')
                                            return html_names::kOnmouseoverAttr;
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;

                case 'p':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'i':
                            if (data[5] == 'n' && data[6] == 't' && data[7] == 'e' && data[8] == 'r' && data[9] == 'u' && data[10] == 'p')
                                return html_names::kOnpointerupAttr;
                            break;

                        case 'p':
                            switch (data[5]) {
                            case 'u':
                                switch (data[6]) {
                                case 'p':
                                    switch (data[7]) {
                                    case 'h':
                                        if (data[8] == 'i' && data[9] == 'd' && data[10] == 'e')
                                            return html_names::kOnpopuphideAttr;
                                        break;

                                    case 's':
                                        if (data[8] == 'h' && data[9] == 'o' && data[10] == 'w')
                                            return html_names::kOnpopupshowAttr;
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;

                case 's':
                    if (data[3] == 'c' && data[4] == 'r' && data[5] == 'o' && data[6] == 'l' && data[7] == 'l' && data[8] == 'e' && data[9] == 'n' && data[10] == 'd')
                        return html_names::kOnscrollendAttr;
                    break;

                case 't':
                    if (data[3] == 'o' && data[4] == 'u' && data[5] == 'c' && data[6] == 'h' && data[7] == 'm' && data[8] == 'o' && data[9] == 'v' && data[10] == 'e')
                        return html_names::kOntouchmoveAttr;
                    break;
                }
                break;
            }
            break;

        case 'p':
            switch (data[1]) {
            case 'l':
                switch (data[2]) {
                case 'a':
                    switch (data[3]) {
                    case 'c':
                        if (data[4] == 'e' && data[5] == 'h' && data[6] == 'o' && data[7] == 'l' && data[8] == 'd' && data[9] == 'e' && data[10] == 'r')
                            return html_names::kPlaceholderAttr;
                        break;

                    case 'y':
                        if (data[4] == 's' && data[5] == 'i' && data[6] == 'n' && data[7] == 'l' && data[8] == 'i' && data[9] == 'n' && data[10] == 'e')
                            return html_names::kPlaysinlineAttr;
                        break;
                    }
                    break;
                }
                break;
            }
            break;

        case 's':
            if (data[1] == 'c' && data[2] == 'r' && data[3] == 'o' && data[4] == 'l' && data[5] == 'l' && data[6] == 'd' && data[7] == 'e' && data[8] == 'l' && data[9] == 'a'
                && data[10] == 'y')
                return html_names::kScrolldelayAttr;
            break;
        }
        break;

    case 8:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'u' && data[2] == 't' && data[3] == 'o' && data[4] == 'p' && data[5] == 'l' && data[6] == 'a' && data[7] == 'y')
                return html_names::kAutoplayAttr;
            break;

        case 'b':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'h' && data[3] == 'a' && data[4] == 'v' && data[5] == 'i' && data[6] == 'o' && data[7] == 'r')
                    return html_names::kBehaviorAttr;
                break;

            case 'l':
                if (data[2] == 'o' && data[3] == 'c' && data[4] == 'k' && data[5] == 'i' && data[6] == 'n' && data[7] == 'g')
                    return html_names::kBlockingAttr;
                break;
            }
            break;

        case 'c':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'd':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'b':
                            if (data[5] == 'a' && data[6] == 's' && data[7] == 'e')
                                return html_names::kCodebaseAttr;
                            break;

                        case 't':
                            if (data[5] == 'y' && data[6] == 'p' && data[7] == 'e')
                                return html_names::kCodetypeAttr;
                            break;
                        }
                        break;
                    }
                    break;

                case 'n':
                    if (data[3] == 't' && data[4] == 'r' && data[5] == 'o' && data[6] == 'l' && data[7] == 's')
                        return html_names::kControlsAttr;
                    break;
                }
                break;
            }
            break;

        case 'd':
            switch (data[1]) {
            case 'a':
                if (data[2] == 't' && data[3] == 'e' && data[4] == 't' && data[5] == 'i' && data[6] == 'm' && data[7] == 'e')
                    return html_names::kDatetimeAttr;
                break;

            case 'e':
                if (data[2] == 'c' && data[3] == 'o' && data[4] == 'd' && data[5] == 'i' && data[6] == 'n' && data[7] == 'g')
                    return html_names::kDecodingAttr;
                break;

            case 'i':
                if (data[2] == 's' && data[3] == 'a' && data[4] == 'b' && data[5] == 'l' && data[6] == 'e' && data[7] == 'd')
                    return html_names::kDisabledAttr;
                break;

            case 'o':
                if (data[2] == 'w' && data[3] == 'n' && data[4] == 'l' && data[5] == 'o' && data[6] == 'a' && data[7] == 'd')
                    return html_names::kDownloadAttr;
                break;
            }
            break;

        case 'h':
            if (data[1] == 'r' && data[2] == 'e' && data[3] == 'f' && data[4] == 'l' && data[5] == 'a' && data[6] == 'n' && data[7] == 'g')
                return html_names::kHreflangAttr;
            break;

        case 'i':
            if (data[1] == 't' && data[2] == 'e' && data[3] == 'm' && data[4] == 'p' && data[5] == 'r' && data[6] == 'o' && data[7] == 'p')
                return html_names::kItempropAttr;
            break;

        case 'l':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'n' && data[3] == 'g' && data[4] == 'u' && data[5] == 'a' && data[6] == 'g' && data[7] == 'e')
                    return html_names::kLanguageAttr;
                break;

            case 'o':
                if (data[2] == 'n' && data[3] == 'g' && data[4] == 'd' && data[5] == 'e' && data[6] == 's' && data[7] == 'c')
                    return html_names::kLongdescAttr;
                break;
            }
            break;

        case 'm':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'n' && data[3] == 'i' && data[4] == 'f' && data[5] == 'e' && data[6] == 's' && data[7] == 't')
                    return html_names::kManifestAttr;
                break;

            case 'u':
                if (data[2] == 'l' && data[3] == 't' && data[4] == 'i' && data[5] == 'p' && data[6] == 'l' && data[7] == 'e')
                    return html_names::kMultipleAttr;
                break;
            }
            break;

        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'm':
                    if (data[3] == 'o' && data[4] == 'd' && data[5] == 'u' && data[6] == 'l' && data[7] == 'e')
                        return html_names::kNomoduleAttr;
                    break;

                case 'r':
                    if (data[3] == 'e' && data[4] == 's' && data[5] == 'i' && data[6] == 'z' && data[7] == 'e')
                        return html_names::kNoresizeAttr;
                    break;
                }
                break;
            }
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'c':
                    switch (data[3]) {
                    case 'a':
                        if (data[4] == 'n' && data[5] == 'c' && data[6] == 'e' && data[7] == 'l')
                            return html_names::kOncancelAttr;
                        break;

                    case 'h':
                        if (data[4] == 'a' && data[5] == 'n' && data[6] == 'g' && data[7] == 'e')
                            return html_names::kOnchangeAttr;
                        break;
                    }
                    break;

                case 'o':
                    if (data[3] == 'n' && data[4] == 'l' && data[5] == 'i' && data[6] == 'n' && data[7] == 'e')
                        return html_names::kOnonlineAttr;
                    break;

                case 'r':
                    if (data[3] == 'e' && data[4] == 's' && data[5] == 'i' && data[6] == 'z' && data[7] == 'e')
                        return html_names::kOnresizeAttr;
                    break;

                case 's':
                    switch (data[3]) {
                    case 'c':
                        if (data[4] == 'r' && data[5] == 'o' && data[6] == 'l' && data[7] == 'l')
                            return html_names::kOnscrollAttr;
                        break;

                    case 'e':
                        switch (data[4]) {
                        case 'a':
                            if (data[5] == 'r' && data[6] == 'c' && data[7] == 'h')
                                return html_names::kOnsearchAttr;
                            break;

                        case 'e':
                            if (data[5] == 'k' && data[6] == 'e' && data[7] == 'd')
                                return html_names::kOnseekedAttr;
                            break;

                        case 'l':
                            if (data[5] == 'e' && data[6] == 'c' && data[7] == 't')
                                return html_names::kOnselectAttr;
                            break;
                        }
                        break;

                    case 'u':
                        if (data[4] == 'b' && data[5] == 'm' && data[6] == 'i' && data[7] == 't')
                            return html_names::kOnsubmitAttr;
                        break;
                    }
                    break;

                case 't':
                    if (data[3] == 'o' && data[4] == 'g' && data[5] == 'g' && data[6] == 'l' && data[7] == 'e')
                        return html_names::kOntoggleAttr;
                    break;

                case 'u':
                    if (data[3] == 'n' && data[4] == 'l' && data[5] == 'o' && data[6] == 'a' && data[7] == 'd')
                        return html_names::kOnunloadAttr;
                    break;
                }
                break;
            }
            break;

        case 'p':
            if (data[1] == 'r' && data[2] == 'o' && data[3] == 'p' && data[4] == 'e' && data[5] == 'r' && data[6] == 't' && data[7] == 'y')
                return html_names::kPropertyAttr;
            break;

        case 'r':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 'd' && data[4] == 'o' && data[5] == 'n' && data[6] == 'l' && data[7] == 'y')
                        return html_names::kReadonlyAttr;
                    break;

                case 'q':
                    if (data[3] == 'u' && data[4] == 'i' && data[5] == 'r' && data[6] == 'e' && data[7] == 'd')
                        return html_names::kRequiredAttr;
                    break;

                case 'v':
                    if (data[3] == 'e' && data[4] == 'r' && data[5] == 's' && data[6] == 'e' && data[7] == 'd')
                        return html_names::kReversedAttr;
                    break;
                }
                break;
            }
            break;

        case 's':
            if (data[1] == 'e' && data[2] == 'l' && data[3] == 'e' && data[4] == 'c' && data[5] == 't' && data[6] == 'e' && data[7] == 'd')
                return html_names::kSelectedAttr;
            break;

        case 't':
            if (data[1] == 'a' && data[2] == 'b' && data[3] == 'i' && data[4] == 'n' && data[5] == 'd' && data[6] == 'e' && data[7] == 'x')
                return html_names::kTabindexAttr;
            break;
        }
        break;

    case 20:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'u' && data[2] == 't' && data[3] == 'o' && data[4] == 'p' && data[5] == 'i' && data[6] == 'c' && data[7] == 't' && data[8] == 'u' && data[9] == 'r'
                && data[10] == 'e' && data[11] == 'i' && data[12] == 'n' && data[13] == 'p' && data[14] == 'i' && data[15] == 'c' && data[16] == 't' && data[17] == 'u'
                && data[18] == 'r' && data[19] == 'e')
                return html_names::kAutopictureinpictureAttr;
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 'n' && data[4] == 'i' && data[5] == 'm' && data[6] == 'a' && data[7] == 't' && data[8] == 'i' && data[9] == 'o' && data[10] == 'n'
                        && data[11] == 'i' && data[12] == 't' && data[13] == 'e' && data[14] == 'r' && data[15] == 'a' && data[16] == 't' && data[17] == 'i' && data[18] == 'o'
                        && data[19] == 'n')
                        return html_names::kOnanimationiterationAttr;
                    break;

                case 'l':
                    if (data[3] == 'o' && data[4] == 's' && data[5] == 't' && data[6] == 'p' && data[7] == 'o' && data[8] == 'i' && data[9] == 'n' && data[10] == 't'
                        && data[11] == 'e' && data[12] == 'r' && data[13] == 'c' && data[14] == 'a' && data[15] == 'p' && data[16] == 't' && data[17] == 'u' && data[18] == 'r'
                        && data[19] == 'e')
                        return html_names::kOnlostpointercaptureAttr;
                    break;

                case 'w':
                    if (data[3] == 'e' && data[4] == 'b' && data[5] == 'k' && data[6] == 'i' && data[7] == 't' && data[8] == 'a' && data[9] == 'n' && data[10] == 'i'
                        && data[11] == 'm' && data[12] == 'a' && data[13] == 't' && data[14] == 'i' && data[15] == 'o' && data[16] == 'n' && data[17] == 'e' && data[18] == 'n'
                        && data[19] == 'd')
                        return html_names::kOnwebkitanimationendAttr;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 10:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'a' && data[2] == 'c' && data[3] == 'k' && data[4] == 'g' && data[5] == 'r' && data[6] == 'o' && data[7] == 'u' && data[8] == 'n' && data[9] == 'd')
                return html_names::kBackgroundAttr;
            break;

        case 'f':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'c':
                    if (data[3] == 'u' && data[4] == 's' && data[5] == 'g' && data[6] == 'r' && data[7] == 'o' && data[8] == 'u' && data[9] == 'p')
                        return html_names::kFocusgroupAttr;
                    break;

                case 'r':
                    switch (data[3]) {
                    case 'm':
                        switch (data[4]) {
                        case 'a':
                            if (data[5] == 'c' && data[6] == 't' && data[7] == 'i' && data[8] == 'o' && data[9] == 'n')
                                return html_names::kFormactionAttr;
                            break;

                        case 'm':
                            if (data[5] == 'e' && data[6] == 't' && data[7] == 'h' && data[8] == 'o' && data[9] == 'd')
                                return html_names::kFormmethodAttr;
                            break;

                        case 't':
                            if (data[5] == 'a' && data[6] == 'r' && data[7] == 'g' && data[8] == 'e' && data[9] == 't')
                                return html_names::kFormtargetAttr;
                            break;
                        }
                        break;
                    }
                    break;
                }
                break;
            }
            break;

        case 'h':
            if (data[1] == 't' && data[2] == 't' && data[3] == 'p' && data[4] == '-' && data[5] == 'e' && data[6] == 'q' && data[7] == 'u' && data[8] == 'i' && data[9] == 'v')
                return html_names::kHttpEquivAttr;
            break;

        case 'i':
            if (data[1] == 'm' && data[2] == 'a' && data[3] == 'g' && data[4] == 'e' && data[5] == 's' && data[6] == 'i' && data[7] == 'z' && data[8] == 'e' && data[9] == 's')
                return html_names::kImagesizesAttr;
            break;

        case 'l':
            if (data[1] == 'e' && data[2] == 'f' && data[3] == 't' && data[4] == 'm' && data[5] == 'a' && data[6] == 'r' && data[7] == 'g' && data[8] == 'i' && data[9] == 'n')
                return html_names::kLeftmarginAttr;
            break;

        case 'n':
            if (data[1] == 'o' && data[2] == 'v' && data[3] == 'a' && data[4] == 'l' && data[5] == 'i' && data[6] == 'd' && data[7] == 'a' && data[8] == 't' && data[9] == 'e')
                return html_names::kNovalidateAttr;
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 'u' && data[4] == 'x' && data[5] == 'c' && data[6] == 'l' && data[7] == 'i' && data[8] == 'c' && data[9] == 'k')
                        return html_names::kOnauxclickAttr;
                    break;

                case 'd':
                    switch (data[3]) {
                    case 'b':
                        if (data[4] == 'l' && data[5] == 'c' && data[6] == 'l' && data[7] == 'i' && data[8] == 'c' && data[9] == 'k')
                            return html_names::kOndblclickAttr;
                        break;

                    case 'r':
                        if (data[4] == 'a' && data[5] == 'g' && data[6] == 'o' && data[7] == 'v' && data[8] == 'e' && data[9] == 'r')
                            return html_names::kOndragoverAttr;
                        break;
                    }
                    break;

                case 'f':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'c':
                            if (data[5] == 'u' && data[6] == 's' && data[7] == 'o' && data[8] == 'u' && data[9] == 't')
                                return html_names::kOnfocusoutAttr;
                            break;

                        case 'r':
                            if (data[5] == 'm' && data[6] == 'd' && data[7] == 'a' && data[8] == 't' && data[9] == 'a')
                                return html_names::kOnformdataAttr;
                            break;
                        }
                        break;
                    }
                    break;

                case 'k':
                    if (data[3] == 'e' && data[4] == 'y' && data[5] == 'p' && data[6] == 'r' && data[7] == 'e' && data[8] == 's' && data[9] == 's')
                        return html_names::kOnkeypressAttr;
                    break;

                case 'm':
                    if (data[3] == 'o' && data[4] == 'u' && data[5] == 's' && data[6] == 'e' && data[7] == 'o' && data[8] == 'u' && data[9] == 't')
                        return html_names::kOnmouseoutAttr;
                    break;

                case 'p':
                    switch (data[3]) {
                    case 'a':
                        switch (data[4]) {
                        case 'g':
                            switch (data[5]) {
                            case 'e':
                                switch (data[6]) {
                                case 'h':
                                    if (data[7] == 'i' && data[8] == 'd' && data[9] == 'e')
                                        return html_names::kOnpagehideAttr;
                                    break;

                                case 's':
                                    if (data[7] == 'h' && data[8] == 'o' && data[9] == 'w')
                                        return html_names::kOnpageshowAttr;
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;

                    case 'o':
                        if (data[4] == 'p' && data[5] == 's' && data[6] == 't' && data[7] == 'a' && data[8] == 't' && data[9] == 'e')
                            return html_names::kOnpopstateAttr;
                        break;

                    case 'r':
                        if (data[4] == 'o' && data[5] == 'g' && data[6] == 'r' && data[7] == 'e' && data[8] == 's' && data[9] == 's')
                            return html_names::kOnprogressAttr;
                        break;
                    }
                    break;

                case 't':
                    if (data[3] == 'o' && data[4] == 'u' && data[5] == 'c' && data[6] == 'h' && data[7] == 'e' && data[8] == 'n' && data[9] == 'd')
                        return html_names::kOntouchendAttr;
                    break;
                }
                break;
            }
            break;

        case 's':
            switch (data[1]) {
            case 'h':
                if (data[2] == 'a' && data[3] == 'd' && data[4] == 'o' && data[5] == 'w' && data[6] == 'r' && data[7] == 'o' && data[8] == 'o' && data[9] == 't')
                    return html_names::kShadowrootAttr;
                break;

            case 'p':
                if (data[2] == 'e' && data[3] == 'l' && data[4] == 'l' && data[5] == 'c' && data[6] == 'h' && data[7] == 'e' && data[8] == 'c' && data[9] == 'k')
                    return html_names::kSpellcheckAttr;
                break;
            }
            break;

        case 't':
            if (data[1] == 'r' && data[2] == 'u' && data[3] == 's' && data[4] == 't' && data[5] == 't' && data[6] == 'o' && data[7] == 'k' && data[8] == 'e' && data[9] == 'n')
                return html_names::kTrusttokenAttr;
            break;
        }
        break;

    case 23:
        switch (data[0]) {
        case 'd':
            if (data[1] == 'i' && data[2] == 's' && data[3] == 'a' && data[4] == 'b' && data[5] == 'l' && data[6] == 'e' && data[7] == 'p' && data[8] == 'i' && data[9] == 'c'
                && data[10] == 't' && data[11] == 'u' && data[12] == 'r' && data[13] == 'e' && data[14] == 'i' && data[15] == 'n' && data[16] == 'p' && data[17] == 'i'
                && data[18] == 'c' && data[19] == 't' && data[20] == 'u' && data[21] == 'r' && data[22] == 'e')
                return html_names::kDisablepictureinpictureAttr;
            break;

        case 'o':
            if (data[1] == 'n' && data[2] == 'w' && data[3] == 'e' && data[4] == 'b' && data[5] == 'k' && data[6] == 'i' && data[7] == 't' && data[8] == 'f' && data[9] == 'u'
                && data[10] == 'l' && data[11] == 'l' && data[12] == 's' && data[13] == 'c' && data[14] == 'r' && data[15] == 'e' && data[16] == 'e' && data[17] == 'n'
                && data[18] == 'e' && data[19] == 'r' && data[20] == 'r' && data[21] == 'o' && data[22] == 'r')
                return html_names::kOnwebkitfullscreenerrorAttr;
            break;
        }
        break;

    case 21:
        switch (data[0]) {
        case 'd':
            if (data[1] == 'i' && data[2] == 's' && data[3] == 'a' && data[4] == 'b' && data[5] == 'l' && data[6] == 'e' && data[7] == 'r' && data[8] == 'e' && data[9] == 'm'
                && data[10] == 'o' && data[11] == 't' && data[12] == 'e' && data[13] == 'p' && data[14] == 'l' && data[15] == 'a' && data[16] == 'y' && data[17] == 'b'
                && data[18] == 'a' && data[19] == 'c' && data[20] == 'k')
                return html_names::kDisableremoteplaybackAttr;
            break;

        case 'o':
            if (data[1] == 'n' && data[2] == 'w' && data[3] == 'e' && data[4] == 'b' && data[5] == 'k' && data[6] == 'i' && data[7] == 't' && data[8] == 't' && data[9] == 'r'
                && data[10] == 'a' && data[11] == 'n' && data[12] == 's' && data[13] == 'i' && data[14] == 't' && data[15] == 'i' && data[16] == 'o' && data[17] == 'n'
                && data[18] == 'e' && data[19] == 'n' && data[20] == 'd')
                return html_names::kOnwebkittransitionendAttr;
            break;

        case 'v':
            if (data[1] == 'i' && data[2] == 'r' && data[3] == 't' && data[4] == 'u' && data[5] == 'a' && data[6] == 'l' && data[7] == 'k' && data[8] == 'e' && data[9] == 'y'
                && data[10] == 'b' && data[11] == 'o' && data[12] == 'a' && data[13] == 'r' && data[14] == 'd' && data[15] == 'p' && data[16] == 'o' && data[17] == 'l'
                && data[18] == 'i' && data[19] == 'c' && data[20] == 'y')
                return html_names::kVirtualkeyboardpolicyAttr;
            break;
        }
        break;

    case 13:
        switch (data[0]) {
        case 'e':
            if (data[1] == 'l' && data[2] == 'e' && data[3] == 'm' && data[4] == 'e' && data[5] == 'n' && data[6] == 't' && data[7] == 't' && data[8] == 'i' && data[9] == 'm'
                && data[10] == 'i' && data[11] == 'n' && data[12] == 'g')
                return html_names::kElementtimingAttr;
            break;

        case 'f':
            if (data[1] == 'e' && data[2] == 't' && data[3] == 'c' && data[4] == 'h' && data[5] == 'p' && data[6] == 'r' && data[7] == 'i' && data[8] == 'o' && data[9] == 'r'
                && data[10] == 'i' && data[11] == 't' && data[12] == 'y')
                return html_names::kFetchpriorityAttr;
            break;

        case 'h':
            if (data[1] == 'r' && data[2] == 'e' && data[3] == 'f' && data[4] == 't' && data[5] == 'r' && data[6] == 'a' && data[7] == 'n' && data[8] == 's' && data[9] == 'l'
                && data[10] == 'a' && data[11] == 't' && data[12] == 'e')
                return html_names::kHreftranslateAttr;
            break;

        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'b':
                    switch (data[3]) {
                    case 'e':
                        switch (data[4]) {
                        case 'f':
                            switch (data[5]) {
                            case 'o':
                                switch (data[6]) {
                                case 'r':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 'i':
                                            if (data[9] == 'n' && data[10] == 'p' && data[11] == 'u' && data[12] == 't')
                                                return html_names::kOnbeforeinputAttr;
                                            break;

                                        case 'p':
                                            switch (data[9]) {
                                            case 'a':
                                                if (data[10] == 's' && data[11] == 't' && data[12] == 'e')
                                                    return html_names::kOnbeforepasteAttr;
                                                break;

                                            case 'r':
                                                if (data[10] == 'i' && data[11] == 'n' && data[12] == 't')
                                                    return html_names::kOnbeforeprintAttr;
                                                break;
                                            }
                                            break;
                                        }
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;

                case 'c':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'n':
                            switch (data[5]) {
                            case 't':
                                switch (data[6]) {
                                case 'e':
                                    switch (data[7]) {
                                    case 'x':
                                        switch (data[8]) {
                                        case 't':
                                            switch (data[9]) {
                                            case 'l':
                                                if (data[10] == 'o' && data[11] == 's' && data[12] == 't')
                                                    return html_names::kOncontextlostAttr;
                                                break;

                                            case 'm':
                                                if (data[10] == 'e' && data[11] == 'n' && data[12] == 'u')
                                                    return html_names::kOncontextmenuAttr;
                                                break;
                                            }
                                            break;
                                        }
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;

                case 'p':
                    switch (data[3]) {
                    case 'o':
                        switch (data[4]) {
                        case 'i':
                            switch (data[5]) {
                            case 'n':
                                switch (data[6]) {
                                case 't':
                                    switch (data[7]) {
                                    case 'e':
                                        switch (data[8]) {
                                        case 'r':
                                            switch (data[9]) {
                                            case 'd':
                                                if (data[10] == 'o' && data[11] == 'w' && data[12] == 'n')
                                                    return html_names::kOnpointerdownAttr;
                                                break;

                                            case 'm':
                                                if (data[10] == 'o' && data[11] == 'v' && data[12] == 'e')
                                                    return html_names::kOnpointermoveAttr;
                                                break;

                                            case 'o':
                                                if (data[10] == 'v' && data[11] == 'e' && data[12] == 'r')
                                                    return html_names::kOnpointeroverAttr;
                                                break;
                                            }
                                            break;
                                        }
                                        break;
                                    }
                                    break;
                                }
                                break;
                            }
                            break;
                        }
                        break;
                    }
                    break;

                case 's':
                    if (data[3] == 'e' && data[4] == 'l' && data[5] == 'e' && data[6] == 'c' && data[7] == 't' && data[8] == 's' && data[9] == 't' && data[10] == 'a'
                        && data[11] == 'r' && data[12] == 't')
                        return html_names::kOnselectstartAttr;
                    break;

                case 't':
                    if (data[3] == 'o' && data[4] == 'u' && data[5] == 'c' && data[6] == 'h' && data[7] == 'c' && data[8] == 'a' && data[9] == 'n' && data[10] == 'c'
                        && data[11] == 'e' && data[12] == 'l')
                        return html_names::kOntouchcancelAttr;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 16:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'a':
                    if (data[3] == 'n' && data[4] == 'i' && data[5] == 'm' && data[6] == 'a' && data[7] == 't' && data[8] == 'i' && data[9] == 'o' && data[10] == 'n'
                        && data[11] == 's' && data[12] == 't' && data[13] == 'a' && data[14] == 'r' && data[15] == 't')
                        return html_names::kOnanimationstartAttr;
                    break;

                case 'c':
                    if (data[3] == 'a' && data[4] == 'n' && data[5] == 'p' && data[6] == 'l' && data[7] == 'a' && data[8] == 'y' && data[9] == 't' && data[10] == 'h'
                        && data[11] == 'r' && data[12] == 'o' && data[13] == 'u' && data[14] == 'g' && data[15] == 'h')
                        return html_names::kOncanplaythroughAttr;
                    break;

                case 'd':
                    if (data[3] == 'u' && data[4] == 'r' && data[5] == 'a' && data[6] == 't' && data[7] == 'i' && data[8] == 'o' && data[9] == 'n' && data[10] == 'c'
                        && data[11] == 'h' && data[12] == 'a' && data[13] == 'n' && data[14] == 'g' && data[15] == 'e')
                        return html_names::kOndurationchangeAttr;
                    break;

                case 'l':
                    switch (data[3]) {
                    case 'a':
                        if (data[4] == 'n' && data[5] == 'g' && data[6] == 'u' && data[7] == 'a' && data[8] == 'g' && data[9] == 'e' && data[10] == 'c' && data[11] == 'h'
                            && data[12] == 'a' && data[13] == 'n' && data[14] == 'g' && data[15] == 'e')
                            return html_names::kOnlanguagechangeAttr;
                        break;

                    case 'o':
                        if (data[4] == 'a' && data[5] == 'd' && data[6] == 'e' && data[7] == 'd' && data[8] == 'm' && data[9] == 'e' && data[10] == 't' && data[11] == 'a'
                            && data[12] == 'd' && data[13] == 'a' && data[14] == 't' && data[15] == 'a')
                            return html_names::kOnloadedmetadataAttr;
                        break;
                    }
                    break;

                case 'p':
                    if (data[3] == 'o' && data[4] == 'r' && data[5] == 't' && data[6] == 'a' && data[7] == 'l' && data[8] == 'a' && data[9] == 'c' && data[10] == 't'
                        && data[11] == 'i' && data[12] == 'v' && data[13] == 'a' && data[14] == 't' && data[15] == 'e')
                        return html_names::kOnportalactivateAttr;
                    break;

                case 't':
                    if (data[3] == 'i' && data[4] == 'm' && data[5] == 'e' && data[6] == 'z' && data[7] == 'o' && data[8] == 'n' && data[9] == 'e' && data[10] == 'c'
                        && data[11] == 'h' && data[12] == 'a' && data[13] == 'n' && data[14] == 'g' && data[15] == 'e')
                        return html_names::kOntimezonechangeAttr;
                    break;
                }
                break;
            }
            break;

        case 'p':
            if (data[1] == 'o' && data[2] == 'p' && data[3] == 'u' && data[4] == 'p' && data[5] == 'h' && data[6] == 'o' && data[7] == 'v' && data[8] == 'e' && data[9] == 'r'
                && data[10] == 't' && data[11] == 'a' && data[12] == 'r' && data[13] == 'g' && data[14] == 'e' && data[15] == 't')
                return html_names::kPopuphovertargetAttr;
            break;
        }
        break;

    case 34:
        switch (data[0]) {
        case 'o':
            if (data[1] == 'n' && data[2] == 'c' && data[3] == 'o' && data[4] == 'n' && data[5] == 't' && data[6] == 'e' && data[7] == 'n' && data[8] == 't' && data[9] == 'v'
                && data[10] == 'i' && data[11] == 's' && data[12] == 'i' && data[13] == 'b' && data[14] == 'i' && data[15] == 'l' && data[16] == 'i' && data[17] == 't'
                && data[18] == 'y' && data[19] == 'a' && data[20] == 'u' && data[21] == 't' && data[22] == 'o' && data[23] == 's' && data[24] == 't' && data[25] == 'a'
                && data[26] == 't' && data[27] == 'e' && data[28] == 'c' && data[29] == 'h' && data[30] == 'a' && data[31] == 'n' && data[32] == 'g' && data[33] == 'e')
                return html_names::kOncontentvisibilityautostatechangeAttr;
            break;
        }
        break;

    case 17:
        switch (data[0]) {
        case 'o':
            switch (data[1]) {
            case 'n':
                switch (data[2]) {
                case 'c':
                    if (data[3] == 'o' && data[4] == 'n' && data[5] == 't' && data[6] == 'e' && data[7] == 'x' && data[8] == 't' && data[9] == 'r' && data[10] == 'e'
                        && data[11] == 's' && data[12] == 't' && data[13] == 'o' && data[14] == 'r' && data[15] == 'e' && data[16] == 'd')
                        return html_names::kOncontextrestoredAttr;
                    break;

                case 's':
                    if (data[3] == 'e' && data[4] == 'l' && data[5] == 'e' && data[6] == 'c' && data[7] == 't' && data[8] == 'i' && data[9] == 'o' && data[10] == 'n'
                        && data[11] == 'c' && data[12] == 'h' && data[13] == 'a' && data[14] == 'n' && data[15] == 'g' && data[16] == 'e')
                        return html_names::kOnselectionchangeAttr;
                    break;
                }
                break;
            }
            break;

        case 'p':
            if (data[1] == 'o' && data[2] == 'p' && data[3] == 'u' && data[4] == 'p' && data[5] == 't' && data[6] == 'o' && data[7] == 'g' && data[8] == 'g' && data[9] == 'l'
                && data[10] == 'e' && data[11] == 't' && data[12] == 'a' && data[13] == 'r' && data[14] == 'g' && data[15] == 'e' && data[16] == 't')
                return html_names::kPopuptoggletargetAttr;
            break;
        }
        break;

    case 18:
        switch (data[0]) {
        case 'o':
            if (data[1] == 'n' && data[2] == 'p' && data[3] == 'o' && data[4] == 'i' && data[5] == 'n' && data[6] == 't' && data[7] == 'e' && data[8] == 'r' && data[9] == 'r'
                && data[10] == 'a' && data[11] == 'w' && data[12] == 'u' && data[13] == 'p' && data[14] == 'd' && data[15] == 'a' && data[16] == 't' && data[17] == 'e')
                return html_names::kOnpointerrawupdateAttr;
            break;
        }
        break;

    case 25:
        switch (data[0]) {
        case 'o':
            if (data[1] == 'n' && data[2] == 's' && data[3] == 'e' && data[4] == 'c' && data[5] == 'u' && data[6] == 'r' && data[7] == 'i' && data[8] == 't' && data[9] == 'y'
                && data[10] == 'p' && data[11] == 'o' && data[12] == 'l' && data[13] == 'i' && data[14] == 'c' && data[15] == 'y' && data[16] == 'v' && data[17] == 'i'
                && data[18] == 'o' && data[19] == 'l' && data[20] == 'a' && data[21] == 't' && data[22] == 'i' && data[23] == 'o' && data[24] == 'n')
                return html_names::kOnsecuritypolicyviolationAttr;
            break;
        }
        break;

    case 22:
        switch (data[0]) {
        case 'o':
            if (data[1] == 'n' && data[2] == 'w' && data[3] == 'e' && data[4] == 'b' && data[5] == 'k' && data[6] == 'i' && data[7] == 't' && data[8] == 'a' && data[9] == 'n'
                && data[10] == 'i' && data[11] == 'm' && data[12] == 'a' && data[13] == 't' && data[14] == 'i' && data[15] == 'o' && data[16] == 'n' && data[17] == 's'
                && data[18] == 't' && data[19] == 'a' && data[20] == 'r' && data[21] == 't')
                return html_names::kOnwebkitanimationstartAttr;
            break;
        }
        break;

    case 26:
        switch (data[0]) {
        case 'o':
            if (data[1] == 'n' && data[2] == 'w' && data[3] == 'e' && data[4] == 'b' && data[5] == 'k' && data[6] == 'i' && data[7] == 't' && data[8] == 'a' && data[9] == 'n'
                && data[10] == 'i' && data[11] == 'm' && data[12] == 'a' && data[13] == 't' && data[14] == 'i' && data[15] == 'o' && data[16] == 'n' && data[17] == 'i'
                && data[18] == 't' && data[19] == 'e' && data[20] == 'r' && data[21] == 'a' && data[22] == 't' && data[23] == 'i' && data[24] == 'o' && data[25] == 'n')
                return html_names::kOnwebkitanimationiterationAttr;
            break;
        }
        break;

    case 24:
        switch (data[0]) {
        case 'o':
            if (data[1] == 'n' && data[2] == 'w' && data[3] == 'e' && data[4] == 'b' && data[5] == 'k' && data[6] == 'i' && data[7] == 't' && data[8] == 'f' && data[9] == 'u'
                && data[10] == 'l' && data[11] == 'l' && data[12] == 's' && data[13] == 'c' && data[14] == 'r' && data[15] == 'e' && data[16] == 'e' && data[17] == 'n'
                && data[18] == 'c' && data[19] == 'h' && data[20] == 'a' && data[21] == 'n' && data[22] == 'g' && data[23] == 'e')
                return html_names::kOnwebkitfullscreenchangeAttr;
            break;

        case 's':
            if (data[1] == 'h' && data[2] == 'a' && data[3] == 'd' && data[4] == 'o' && data[5] == 'w' && data[6] == 'r' && data[7] == 'o' && data[8] == 'o' && data[9] == 't'
                && data[10] == 'd' && data[11] == 'e' && data[12] == 'l' && data[13] == 'e' && data[14] == 'g' && data[15] == 'a' && data[16] == 't' && data[17] == 'e'
                && data[18] == 's' && data[19] == 'f' && data[20] == 'o' && data[21] == 'c' && data[22] == 'u' && data[23] == 's')
                return html_names::kShadowrootdelegatesfocusAttr;
            break;
        }
        break;
    }

    return g_null_name;
}

} // namespace blink
