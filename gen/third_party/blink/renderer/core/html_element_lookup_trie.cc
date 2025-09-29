// Copyright 2016 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// Generated from template:
//   templates/element_lookup_trie.cc.tmpl
// and input files:
//   ../../third_party/blink/renderer/core/html/html_tag_names.json5

#include "third_party/blink/renderer/core/html_element_lookup_trie.h"

#include "third_party/blink/renderer/core/html_names.h"

namespace blink {
namespace {

template <typename CharType> html_names::HTMLTag lookupHTMLTagImpl(const CharType* data, unsigned length)
{
    DCHECK(data);
    DCHECK(length);
    switch (length) {
    case 1:
        switch (data[0]) {
        case 'a':
            return html_names::HTMLTag::kA;
            ;

        case 'b':
            return html_names::HTMLTag::kB;
            ;

        case 'i':
            return html_names::HTMLTag::kI;
            ;

        case 'p':
            return html_names::HTMLTag::kP;
            ;

        case 'q':
            return html_names::HTMLTag::kQ;
            ;

        case 's':
            return html_names::HTMLTag::kS;
            ;

        case 'u':
            return html_names::HTMLTag::kU;
            ;
        }
        break;

    case 4:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'b':
                if (data[2] == 'b' && data[3] == 'r')
                    return html_names::HTMLTag::kAbbr;
                ;
                break;

            case 'r':
                if (data[2] == 'e' && data[3] == 'a')
                    return html_names::HTMLTag::kArea;
                ;
                break;
            }
            break;

        case 'b':
            switch (data[1]) {
            case 'a':
                if (data[2] == 's' && data[3] == 'e')
                    return html_names::HTMLTag::kBase;
                ;
                break;

            case 'o':
                if (data[2] == 'd' && data[3] == 'y')
                    return html_names::HTMLTag::kBody;
                ;
                break;
            }
            break;

        case 'c':
            switch (data[1]) {
            case 'i':
                if (data[2] == 't' && data[3] == 'e')
                    return html_names::HTMLTag::kCite;
                ;
                break;

            case 'o':
                if (data[2] == 'd' && data[3] == 'e')
                    return html_names::HTMLTag::kCode;
                ;
                break;
            }
            break;

        case 'd':
            if (data[1] == 'a' && data[2] == 't' && data[3] == 'a')
                return html_names::HTMLTag::kData;
            ;
            break;

        case 'f':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 't')
                        return html_names::HTMLTag::kFont;
                    ;
                    break;

                case 'r':
                    if (data[3] == 'm')
                        return html_names::HTMLTag::kForm;
                    ;
                    break;
                }
                break;
            }
            break;

        case 'h':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'a' && data[3] == 'd')
                    return html_names::HTMLTag::kHead;
                ;
                break;

            case 't':
                if (data[2] == 'm' && data[3] == 'l')
                    return html_names::HTMLTag::kHTML;
                ;
                break;
            }
            break;

        case 'l':
            if (data[1] == 'i' && data[2] == 'n' && data[3] == 'k')
                return html_names::HTMLTag::kLink;
            ;
            break;

        case 'm':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'i':
                    if (data[3] == 'n')
                        return html_names::HTMLTag::kMain;
                    ;
                    break;

                case 'r':
                    if (data[3] == 'k')
                        return html_names::HTMLTag::kMark;
                    ;
                    break;
                }
                break;

            case 'e':
                switch (data[2]) {
                case 'n':
                    if (data[3] == 'u')
                        return html_names::HTMLTag::kMenu;
                    ;
                    break;

                case 't':
                    if (data[3] == 'a')
                        return html_names::HTMLTag::kMeta;
                    ;
                    break;
                }
                break;
            }
            break;

        case 'n':
            if (data[1] == 'o' && data[2] == 'b' && data[3] == 'r')
                return html_names::HTMLTag::kNobr;
            ;
            break;

        case 'r':
            if (data[1] == 'u' && data[2] == 'b' && data[3] == 'y')
                return html_names::HTMLTag::kRuby;
            ;
            break;

        case 's':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'm' && data[3] == 'p')
                    return html_names::HTMLTag::kSamp;
                ;
                break;

            case 'l':
                if (data[2] == 'o' && data[3] == 't')
                    return html_names::HTMLTag::kSlot;
                ;
                break;

            case 'p':
                if (data[2] == 'a' && data[3] == 'n')
                    return html_names::HTMLTag::kSpan;
                ;
                break;
            }
            break;

        case 't':
            if (data[1] == 'i' && data[2] == 'm' && data[3] == 'e')
                return html_names::HTMLTag::kTime;
            ;
            break;
        }
        break;

    case 7:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'r' && data[3] == 'o' && data[4] == 'n' && data[5] == 'y' && data[6] == 'm')
                    return html_names::HTMLTag::kAcronym;
                ;
                break;

            case 'd':
                if (data[2] == 'd' && data[3] == 'r' && data[4] == 'e' && data[5] == 's' && data[6] == 's')
                    return html_names::HTMLTag::kAddress;
                ;
                break;

            case 'r':
                if (data[2] == 't' && data[3] == 'i' && data[4] == 'c' && data[5] == 'l' && data[6] == 'e')
                    return html_names::HTMLTag::kArticle;
                ;
                break;
            }
            break;

        case 'b':
            if (data[1] == 'g' && data[2] == 's' && data[3] == 'o' && data[4] == 'u' && data[5] == 'n' && data[6] == 'd')
                return html_names::HTMLTag::kBgsound;
            ;
            break;

        case 'c':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'p' && data[3] == 't' && data[4] == 'i' && data[5] == 'o' && data[6] == 'n')
                    return html_names::HTMLTag::kCaption;
                ;
                break;

            case 'o':
                if (data[2] == 'm' && data[3] == 'm' && data[4] == 'a' && data[5] == 'n' && data[6] == 'd')
                    return html_names::HTMLTag::kCommand;
                ;
                break;
            }
            break;

        case 'd':
            if (data[1] == 'e' && data[2] == 't' && data[3] == 'a' && data[4] == 'i' && data[5] == 'l' && data[6] == 's')
                return html_names::HTMLTag::kDetails;
            ;
            break;

        case 'l':
            if (data[1] == 'i' && data[2] == 's' && data[3] == 't' && data[4] == 'i' && data[5] == 'n' && data[6] == 'g')
                return html_names::HTMLTag::kListing;
            ;
            break;

        case 'm':
            if (data[1] == 'a' && data[2] == 'r' && data[3] == 'q' && data[4] == 'u' && data[5] == 'e' && data[6] == 'e')
                return html_names::HTMLTag::kMarquee;
            ;
            break;

        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'e':
                    if (data[3] == 'm' && data[4] == 'b' && data[5] == 'e' && data[6] == 'd')
                        return html_names::HTMLTag::kNoembed;
                    ;
                    break;

                case 'l':
                    if (data[3] == 'a' && data[4] == 'y' && data[5] == 'e' && data[6] == 'r')
                        return html_names::HTMLTag::kNolayer;
                    ;
                    break;
                }
                break;
            }
            break;

        case 'p':
            if (data[1] == 'i' && data[2] == 'c' && data[3] == 't' && data[4] == 'u' && data[5] == 'r' && data[6] == 'e')
                return html_names::HTMLTag::kPicture;
            ;
            break;

        case 's':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'c' && data[3] == 't' && data[4] == 'i' && data[5] == 'o' && data[6] == 'n')
                    return html_names::HTMLTag::kSection;
                ;
                break;

            case 'u':
                if (data[2] == 'm' && data[3] == 'm' && data[4] == 'a' && data[5] == 'r' && data[6] == 'y')
                    return html_names::HTMLTag::kSummary;
                ;
                break;
            }
            break;
        }
        break;

    case 6:
        switch (data[0]) {
        case 'a':
            if (data[1] == 'p' && data[2] == 'p' && data[3] == 'l' && data[4] == 'e' && data[5] == 't')
                return html_names::HTMLTag::kApplet;
            ;
            break;

        case 'b':
            if (data[1] == 'u' && data[2] == 't' && data[3] == 't' && data[4] == 'o' && data[5] == 'n')
                return html_names::HTMLTag::kButton;
            ;
            break;

        case 'c':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'n' && data[3] == 'v' && data[4] == 'a' && data[5] == 's')
                    return html_names::HTMLTag::kCanvas;
                ;
                break;

            case 'e':
                if (data[2] == 'n' && data[3] == 't' && data[4] == 'e' && data[5] == 'r')
                    return html_names::HTMLTag::kCenter;
                ;
                break;
            }
            break;

        case 'd':
            if (data[1] == 'i' && data[2] == 'a' && data[3] == 'l' && data[4] == 'o' && data[5] == 'g')
                return html_names::HTMLTag::kDialog;
            ;
            break;

        case 'f':
            switch (data[1]) {
            case 'i':
                if (data[2] == 'g' && data[3] == 'u' && data[4] == 'r' && data[5] == 'e')
                    return html_names::HTMLTag::kFigure;
                ;
                break;

            case 'o':
                if (data[2] == 'o' && data[3] == 't' && data[4] == 'e' && data[5] == 'r')
                    return html_names::HTMLTag::kFooter;
                ;
                break;
            }
            break;

        case 'h':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'a' && data[3] == 'd' && data[4] == 'e' && data[5] == 'r')
                    return html_names::HTMLTag::kHeader;
                ;
                break;

            case 'g':
                if (data[2] == 'r' && data[3] == 'o' && data[4] == 'u' && data[5] == 'p')
                    return html_names::HTMLTag::kHgroup;
                ;
                break;
            }
            break;

        case 'i':
            if (data[1] == 'f' && data[2] == 'r' && data[3] == 'a' && data[4] == 'm' && data[5] == 'e')
                return html_names::HTMLTag::kIFrame;
            ;
            break;

        case 'k':
            if (data[1] == 'e' && data[2] == 'y' && data[3] == 'g' && data[4] == 'e' && data[5] == 'n')
                return html_names::HTMLTag::kKeygen;
            ;
            break;

        case 'l':
            if (data[1] == 'e' && data[2] == 'g' && data[3] == 'e' && data[4] == 'n' && data[5] == 'd')
                return html_names::HTMLTag::kLegend;
            ;
            break;

        case 'o':
            switch (data[1]) {
            case 'b':
                if (data[2] == 'j' && data[3] == 'e' && data[4] == 'c' && data[5] == 't')
                    return html_names::HTMLTag::kObject;
                ;
                break;

            case 'p':
                if (data[2] == 't' && data[3] == 'i' && data[4] == 'o' && data[5] == 'n')
                    return html_names::HTMLTag::kOption;
                ;
                break;

            case 'u':
                if (data[2] == 't' && data[3] == 'p' && data[4] == 'u' && data[5] == 't')
                    return html_names::HTMLTag::kOutput;
                ;
                break;
            }
            break;

        case 'p':
            if (data[1] == 'o' && data[2] == 'r' && data[3] == 't' && data[4] == 'a' && data[5] == 'l')
                return html_names::HTMLTag::kPortal;
            ;
            break;

        case 's':
            switch (data[1]) {
            case 'c':
                if (data[2] == 'r' && data[3] == 'i' && data[4] == 'p' && data[5] == 't')
                    return html_names::HTMLTag::kScript;
                ;
                break;

            case 'e':
                if (data[2] == 'l' && data[3] == 'e' && data[4] == 'c' && data[5] == 't')
                    return html_names::HTMLTag::kSelect;
                ;
                break;

            case 'o':
                if (data[2] == 'u' && data[3] == 'r' && data[4] == 'c' && data[5] == 'e')
                    return html_names::HTMLTag::kSource;
                ;
                break;

            case 't':
                switch (data[2]) {
                case 'r':
                    switch (data[3]) {
                    case 'i':
                        if (data[4] == 'k' && data[5] == 'e')
                            return html_names::HTMLTag::kStrike;
                        ;
                        break;

                    case 'o':
                        if (data[4] == 'n' && data[5] == 'g')
                            return html_names::HTMLTag::kStrong;
                        ;
                        break;
                    }
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 5:
        switch (data[0]) {
        case 'a':
            switch (data[1]) {
            case 's':
                if (data[2] == 'i' && data[3] == 'd' && data[4] == 'e')
                    return html_names::HTMLTag::kAside;
                ;
                break;

            case 'u':
                if (data[2] == 'd' && data[3] == 'i' && data[4] == 'o')
                    return html_names::HTMLTag::kAudio;
                ;
                break;
            }
            break;

        case 'e':
            if (data[1] == 'm' && data[2] == 'b' && data[3] == 'e' && data[4] == 'd')
                return html_names::HTMLTag::kEmbed;
            ;
            break;

        case 'f':
            if (data[1] == 'r' && data[2] == 'a' && data[3] == 'm' && data[4] == 'e')
                return html_names::HTMLTag::kFrame;
            ;
            break;

        case 'i':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'a' && data[3] == 'g' && data[4] == 'e')
                    return html_names::HTMLTag::kImage;
                ;
                break;

            case 'n':
                if (data[2] == 'p' && data[3] == 'u' && data[4] == 't')
                    return html_names::HTMLTag::kInput;
                ;
                break;
            }
            break;

        case 'l':
            switch (data[1]) {
            case 'a':
                switch (data[2]) {
                case 'b':
                    if (data[3] == 'e' && data[4] == 'l')
                        return html_names::HTMLTag::kLabel;
                    ;
                    break;

                case 'y':
                    if (data[3] == 'e' && data[4] == 'r')
                        return html_names::HTMLTag::kLayer;
                    ;
                    break;
                }
                break;
            }
            break;

        case 'm':
            if (data[1] == 'e' && data[2] == 't' && data[3] == 'e' && data[4] == 'r')
                return html_names::HTMLTag::kMeter;
            ;
            break;

        case 'p':
            if (data[1] == 'a' && data[2] == 'r' && data[3] == 'a' && data[4] == 'm')
                return html_names::HTMLTag::kParam;
            ;
            break;

        case 's':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'a' && data[3] == 'l' && data[4] == 'l')
                    return html_names::HTMLTag::kSmall;
                ;
                break;

            case 't':
                if (data[2] == 'y' && data[3] == 'l' && data[4] == 'e')
                    return html_names::HTMLTag::kStyle;
                ;
                break;
            }
            break;

        case 't':
            switch (data[1]) {
            case 'a':
                if (data[2] == 'b' && data[3] == 'l' && data[4] == 'e')
                    return html_names::HTMLTag::kTable;
                ;
                break;

            case 'b':
                if (data[2] == 'o' && data[3] == 'd' && data[4] == 'y')
                    return html_names::HTMLTag::kTbody;
                ;
                break;

            case 'f':
                if (data[2] == 'o' && data[3] == 'o' && data[4] == 't')
                    return html_names::HTMLTag::kTfoot;
                ;
                break;

            case 'h':
                if (data[2] == 'e' && data[3] == 'a' && data[4] == 'd')
                    return html_names::HTMLTag::kThead;
                ;
                break;

            case 'i':
                if (data[2] == 't' && data[3] == 'l' && data[4] == 'e')
                    return html_names::HTMLTag::kTitle;
                ;
                break;

            case 'r':
                if (data[2] == 'a' && data[3] == 'c' && data[4] == 'k')
                    return html_names::HTMLTag::kTrack;
                ;
                break;
            }
            break;

        case 'v':
            if (data[1] == 'i' && data[2] == 'd' && data[3] == 'e' && data[4] == 'o')
                return html_names::HTMLTag::kVideo;
            ;
            break;
        }
        break;

    case 8:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'a' && data[2] == 's' && data[3] == 'e' && data[4] == 'f' && data[5] == 'o' && data[6] == 'n' && data[7] == 't')
                return html_names::HTMLTag::kBasefont;
            ;
            break;

        case 'c':
            if (data[1] == 'o' && data[2] == 'l' && data[3] == 'g' && data[4] == 'r' && data[5] == 'o' && data[6] == 'u' && data[7] == 'p')
                return html_names::HTMLTag::kColgroup;
            ;
            break;

        case 'd':
            if (data[1] == 'a' && data[2] == 't' && data[3] == 'a' && data[4] == 'l' && data[5] == 'i' && data[6] == 's' && data[7] == 't')
                return html_names::HTMLTag::kDatalist;
            ;
            break;

        case 'f':
            switch (data[1]) {
            case 'i':
                if (data[2] == 'e' && data[3] == 'l' && data[4] == 'd' && data[5] == 's' && data[6] == 'e' && data[7] == 't')
                    return html_names::HTMLTag::kFieldset;
                ;
                break;

            case 'r':
                if (data[2] == 'a' && data[3] == 'm' && data[4] == 'e' && data[5] == 's' && data[6] == 'e' && data[7] == 't')
                    return html_names::HTMLTag::kFrameset;
                ;
                break;
            }
            break;

        case 'n':
            switch (data[1]) {
            case 'o':
                switch (data[2]) {
                case 'f':
                    if (data[3] == 'r' && data[4] == 'a' && data[5] == 'm' && data[6] == 'e' && data[7] == 's')
                        return html_names::HTMLTag::kNoframes;
                    ;
                    break;

                case 's':
                    if (data[3] == 'c' && data[4] == 'r' && data[5] == 'i' && data[6] == 'p' && data[7] == 't')
                        return html_names::HTMLTag::kNoscript;
                    ;
                    break;
                }
                break;
            }
            break;

        case 'o':
            if (data[1] == 'p' && data[2] == 't' && data[3] == 'g' && data[4] == 'r' && data[5] == 'o' && data[6] == 'u' && data[7] == 'p')
                return html_names::HTMLTag::kOptgroup;
            ;
            break;

        case 'p':
            if (data[1] == 'r' && data[2] == 'o' && data[3] == 'g' && data[4] == 'r' && data[5] == 'e' && data[6] == 's' && data[7] == 's')
                return html_names::HTMLTag::kProgress;
            ;
            break;

        case 't':
            switch (data[1]) {
            case 'e':
                switch (data[2]) {
                case 'm':
                    if (data[3] == 'p' && data[4] == 'l' && data[5] == 'a' && data[6] == 't' && data[7] == 'e')
                        return html_names::HTMLTag::kTemplate;
                    ;
                    break;

                case 'x':
                    if (data[3] == 't' && data[4] == 'a' && data[5] == 'r' && data[6] == 'e' && data[7] == 'a')
                        return html_names::HTMLTag::kTextarea;
                    ;
                    break;
                }
                break;
            }
            break;
        }
        break;

    case 3:
        switch (data[0]) {
        case 'b':
            switch (data[1]) {
            case 'd':
                switch (data[2]) {
                case 'i':
                    return html_names::HTMLTag::kBdi;
                    ;

                case 'o':
                    return html_names::HTMLTag::kBdo;
                    ;
                }
                break;

            case 'i':
                if (data[2] == 'g')
                    return html_names::HTMLTag::kBig;
                ;
                break;
            }
            break;

        case 'c':
            if (data[1] == 'o' && data[2] == 'l')
                return html_names::HTMLTag::kCol;
            ;
            break;

        case 'd':
            switch (data[1]) {
            case 'e':
                if (data[2] == 'l')
                    return html_names::HTMLTag::kDel;
                ;
                break;

            case 'f':
                if (data[2] == 'n')
                    return html_names::HTMLTag::kDfn;
                ;
                break;

            case 'i':
                switch (data[2]) {
                case 'r':
                    return html_names::HTMLTag::kDir;
                    ;

                case 'v':
                    return html_names::HTMLTag::kDiv;
                    ;
                }
                break;
            }
            break;

        case 'i':
            switch (data[1]) {
            case 'm':
                if (data[2] == 'g')
                    return html_names::HTMLTag::kImg;
                ;
                break;

            case 'n':
                if (data[2] == 's')
                    return html_names::HTMLTag::kIns;
                ;
                break;
            }
            break;

        case 'k':
            if (data[1] == 'b' && data[2] == 'd')
                return html_names::HTMLTag::kKbd;
            ;
            break;

        case 'm':
            if (data[1] == 'a' && data[2] == 'p')
                return html_names::HTMLTag::kMap;
            ;
            break;

        case 'n':
            if (data[1] == 'a' && data[2] == 'v')
                return html_names::HTMLTag::kNav;
            ;
            break;

        case 'p':
            if (data[1] == 'r' && data[2] == 'e')
                return html_names::HTMLTag::kPre;
            ;
            break;

        case 'r':
            if (data[1] == 't' && data[2] == 'c')
                return html_names::HTMLTag::kRTC;
            ;
            break;

        case 's':
            switch (data[1]) {
            case 'u':
                switch (data[2]) {
                case 'b':
                    return html_names::HTMLTag::kSub;
                    ;

                case 'p':
                    return html_names::HTMLTag::kSup;
                    ;
                }
                break;
            }
            break;

        case 'v':
            if (data[1] == 'a' && data[2] == 'r')
                return html_names::HTMLTag::kVar;
            ;
            break;

        case 'w':
            if (data[1] == 'b' && data[2] == 'r')
                return html_names::HTMLTag::kWbr;
            ;
            break;

        case 'x':
            if (data[1] == 'm' && data[2] == 'p')
                return html_names::HTMLTag::kXmp;
            ;
            break;
        }
        break;

    case 10:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'l' && data[2] == 'o' && data[3] == 'c' && data[4] == 'k' && data[5] == 'q' && data[6] == 'u' && data[7] == 'o' && data[8] == 't' && data[9] == 'e')
                return html_names::HTMLTag::kBlockquote;
            ;
            break;

        case 'f':
            if (data[1] == 'i' && data[2] == 'g' && data[3] == 'c' && data[4] == 'a' && data[5] == 'p' && data[6] == 't' && data[7] == 'i' && data[8] == 'o' && data[9] == 'n')
                return html_names::HTMLTag::kFigcaption;
            ;
            break;

        case 's':
            if (data[1] == 'e' && data[2] == 'l' && data[3] == 'e' && data[4] == 'c' && data[5] == 't' && data[6] == 'm' && data[7] == 'e' && data[8] == 'n' && data[9] == 'u')
                return html_names::HTMLTag::kSelectmenu;
            ;
            break;
        }
        break;

    case 2:
        switch (data[0]) {
        case 'b':
            if (data[1] == 'r')
                return html_names::HTMLTag::kBr;
            ;
            break;

        case 'd':
            switch (data[1]) {
            case 'd':
                return html_names::HTMLTag::kDd;
                ;

            case 'l':
                return html_names::HTMLTag::kDl;
                ;

            case 't':
                return html_names::HTMLTag::kDt;
                ;
            }
            break;

        case 'e':
            if (data[1] == 'm')
                return html_names::HTMLTag::kEm;
            ;
            break;

        case 'h':
            switch (data[1]) {
            case '1':
                return html_names::HTMLTag::kH1;
                ;

            case '2':
                return html_names::HTMLTag::kH2;
                ;

            case '3':
                return html_names::HTMLTag::kH3;
                ;

            case '4':
                return html_names::HTMLTag::kH4;
                ;

            case '5':
                return html_names::HTMLTag::kH5;
                ;

            case '6':
                return html_names::HTMLTag::kH6;
                ;

            case 'r':
                return html_names::HTMLTag::kHr;
                ;
            }
            break;

        case 'l':
            if (data[1] == 'i')
                return html_names::HTMLTag::kLi;
            ;
            break;

        case 'o':
            if (data[1] == 'l')
                return html_names::HTMLTag::kOl;
            ;
            break;

        case 'r':
            switch (data[1]) {
            case 'b':
                return html_names::HTMLTag::kRb;
                ;

            case 'p':
                return html_names::HTMLTag::kRp;
                ;

            case 't':
                return html_names::HTMLTag::kRt;
                ;
            }
            break;

        case 't':
            switch (data[1]) {
            case 'd':
                return html_names::HTMLTag::kTd;
                ;

            case 'h':
                return html_names::HTMLTag::kTh;
                ;

            case 'r':
                return html_names::HTMLTag::kTr;
                ;

            case 't':
                return html_names::HTMLTag::kTt;
                ;
            }
            break;

        case 'u':
            if (data[1] == 'l')
                return html_names::HTMLTag::kUl;
            ;
            break;
        }
        break;

    case 11:
        switch (data[0]) {
        case 'f':
            if (data[1] == 'e' && data[2] == 'n' && data[3] == 'c' && data[4] == 'e' && data[5] == 'd' && data[6] == 'f' && data[7] == 'r' && data[8] == 'a' && data[9] == 'm'
                && data[10] == 'e')
                return html_names::HTMLTag::kFencedframe;
            ;
            break;
        }
        break;

    case 9:
        switch (data[0]) {
        case 'p':
            if (data[1] == 'l' && data[2] == 'a' && data[3] == 'i' && data[4] == 'n' && data[5] == 't' && data[6] == 'e' && data[7] == 'x' && data[8] == 't')
                return html_names::HTMLTag::kPlaintext;
            ;
            break;
        }
        break;
    }

    return html_names::HTMLTag::kUnknown;
}

} // namespace

CORE_EXPORT html_names::HTMLTag lookupHTMLTag(const UChar* data, unsigned length) { return lookupHTMLTagImpl(data, length); }

CORE_EXPORT html_names::HTMLTag lookupHTMLTag(const LChar* data, unsigned length) { return lookupHTMLTagImpl(data, length); }

} // namespace blink
