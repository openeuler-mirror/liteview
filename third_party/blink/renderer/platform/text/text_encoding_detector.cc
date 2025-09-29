/*
 * Copyright (C) 2008, 2009 Google Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above
 * copyright notice, this list of conditions and the following disclaimer
 * in the documentation and/or other materials provided with the
 * distribution.
 *     * Neither the name of Google Inc. nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "third_party/blink/renderer/platform/text/text_encoding_detector.h"

#include "build/build_config.h"
#include "third_party/blink/renderer/platform/weborigin/kurl.h"
#include "third_party/blink/renderer/platform/wtf/text/text_encoding.h"
// #include "third_party/ced/src/compact_enc_det/compact_enc_det.h"

// third_party/ced/src/util/encodings/encodings.h, which is included
// by the include above, undefs UNICODE because that is a macro used
// internally in ced. If we later in the same translation unit do
// anything related to Windows or Windows headers those will then use
// the ASCII versions which we do not want. To avoid that happening in
// jumbo builds, we redefine UNICODE again here.
#if BUILDFLAG(IS_WIN)
#define UNICODE 1
#endif // BUILDFLAG(IS_WIN)

//----
#include "third_party/blink/renderer/platform/wtf/allocator/partitions.h"
#include "unicode/umachine.h"
#include "unicode/utypes.h"
#include <unicode/ucnv.h>
#include <unicode/utypes.h>

#define BUFFER_SIZE 8192
#define ARRAY_SIZE(array) (sizeof array / sizeof array[0])
#define NEW_ARRAY(type, count) (type*)WTF::Partitions::FastMalloc((count) * sizeof(type), "InputText")
#define DELETE_ARRAY(array) WTF::Partitions::FastFree((void*)(array))

class InputText {
    // Prevent copying
    InputText(const InputText&);

public:
    InputText(UErrorCode& status);
    ~InputText();

    void setText(const char* in, int32_t len);
    //     void setDeclaredEncoding(const char *encoding, int32_t len);
    UBool isSet() const;
    void MungeInput(UBool fStripTags);

    // The text to be checked.  Markup will have been
    //   removed if appropriate.
    uint8_t* fInputBytes;
    int32_t fInputLen; // Length of the byte data in fInputBytes.
    // byte frequency statistics for the input text.
    //   Value is percent, not absolute.
    //   Value is rounded up, so zero really means zero occurences.
    int16_t* fByteStats;
    UBool fC1Bytes; // True if any bytes in the range 0x80 - 0x9F are in the input;false by default
    char* fDeclaredEncoding;

    const uint8_t* fRawInput; // Original, untouched input bytes.
    //  If user gave us a byte array, this is it.
    //  If user gave us a stream, it's read to a
    //   buffer here.
    int32_t fRawLength; // Length of data in fRawInput array.
};

class CharsetRecognizer;

class CharsetMatch {
private:
    InputText* textIn;
    int32_t confidence;
    const char* fCharsetName;
    const char* fLang;

public:
    CharsetMatch();

    /**
    * fully set the state of this CharsetMatch.
    * Called by the CharsetRecognizers to record match results.
    * Default (NULL) parameters for names will be filled by calling the
    *   corresponding getters on the recognizer.
    */
    void set(InputText* input,
        const CharsetRecognizer* cr,
        int32_t conf,
        const char* csName = NULL,
        const char* lang = NULL);

    /**
    * Return the name of the charset for this Match
    */
    const char* getName() const;

    const char* getLanguage() const;

    int32_t getConfidence() const;

    int32_t getUChars(UChar* buf, int32_t cap, UErrorCode* status) const;
};

class CharsetRecognizer {
public:
    virtual const char* getName() const = 0;

    virtual const char* getLanguage() const { return ""; }

    virtual UBool match(InputText* textIn, CharsetMatch* results) const = 0;

    virtual ~CharsetRecognizer() { }
};

class CharsetRecog_UTF8 : public CharsetRecognizer {

public:
    virtual ~CharsetRecog_UTF8();

    const char* getName() const;

    /* (non-Javadoc)
    * @see com.ibm.icu.text.CharsetRecognizer#match(com.ibm.icu.text.CharsetDetector)
    */
    UBool match(InputText* input, CharsetMatch* results) const;
};

class CharsetDetector {
private:
    InputText* textIn;
    CharsetMatch** resultArray;
    int32_t resultCount;
    UBool fStripTags; // If true, setText() will strip tags from input text.
    UBool fFreshTextSet;
    static void setRecognizers(UErrorCode& status);

    UBool* fEnabledRecognizers; // If not null, active set of charset recognizers had
    // been changed from the default. The array index is
    // corresponding to fCSRecognizers. See setDetectableCharset().

public:
    CharsetDetector(UErrorCode& status);

    ~CharsetDetector();

    void setText(const char* in, int32_t len);

    const CharsetMatch* const* detectAll(int32_t& maxMatchesFound, UErrorCode& status);

    const CharsetMatch* detect(UErrorCode& status);
};

//////////////////////////////////////////////////////////////////////////
struct CSRecognizerInfo {
    CSRecognizerInfo(CharsetRecognizer* recognizer, UBool isDefaultEnabled)
        : recognizer(recognizer)
        , isDefaultEnabled(isDefaultEnabled) {};

    ~CSRecognizerInfo() { delete recognizer; };

    CharsetRecognizer* recognizer;
    UBool isDefaultEnabled;
};

InputText::InputText(UErrorCode& status)
    : fInputBytes(NEW_ARRAY(uint8_t, BUFFER_SIZE))
    , // The text to be checked.  Markup will have been
    // removed if appropriate.
    fByteStats(NEW_ARRAY(int16_t, 256))
    , // byte frequency statistics for the input text.
    // Value is percent, not absolute.
    fDeclaredEncoding(0)
    , fRawInput(0)
    , fRawLength(0)
{
    if (fInputBytes == NULL || fByteStats == NULL) {
        status = U_MEMORY_ALLOCATION_ERROR;
    }
}

InputText::~InputText()
{
    DELETE_ARRAY(fDeclaredEncoding);
    DELETE_ARRAY(fByteStats);
    DELETE_ARRAY(fInputBytes);
}

void InputText::setText(const char* in, int32_t len)
{
    fInputLen = 0;
    fC1Bytes = FALSE;
    fRawInput = (const uint8_t*)in;
    fRawLength = len == -1 ? (int32_t)strlen(in) : len;
}

UBool InputText::isSet() const
{
    return fRawInput != NULL;
}

void InputText::MungeInput(UBool fStripTags)
{
    int srci = 0;
    int dsti = 0;
    uint8_t b;
    bool inMarkup = FALSE;
    int32_t openTags = 0;
    int32_t badTags = 0;

    //
    //  html / xml markup stripping.
    //     quick and dirty, not 100% accurate, but hopefully good enough, statistically.
    //     discard everything within < brackets >
    //     Count how many total '<' and illegal (nested) '<' occur, so we can make some
    //     guess as to whether the input was actually marked up at all.
    // TODO: Think about how this interacts with EBCDIC charsets that are detected.
    if (fStripTags) {
        for (srci = 0; srci < fRawLength && dsti < BUFFER_SIZE; srci += 1) {
            b = fRawInput[srci];

            if (b == (uint8_t)0x3C) { /* Check for the ASCII '<' */
                if (inMarkup) {
                    badTags += 1;
                }

                inMarkup = TRUE;
                openTags += 1;
            }

            if (!inMarkup) {
                fInputBytes[dsti++] = b;
            }

            if (b == (uint8_t)0x3E) { /* Check for the ASCII '>' */
                inMarkup = FALSE;
            }
        }

        fInputLen = dsti;
    }

    //
    //  If it looks like this input wasn't marked up, or if it looks like it's
    //    essentially nothing but markup abandon the markup stripping.
    //    Detection will have to work on the unstripped input.
    //
    if (openTags < 5 || openTags / 5 < badTags || (fInputLen < 100 && fRawLength > 600)) {
        int32_t limit = fRawLength;

        if (limit > BUFFER_SIZE) {
            limit = BUFFER_SIZE;
        }

        for (srci = 0; srci < limit; srci++) {
            fInputBytes[srci] = fRawInput[srci];
        }

        fInputLen = srci;
    }

    //
    // Tally up the byte occurence statistics.
    // These are available for use by the various detectors.
    //

    memset(fByteStats, 0, (sizeof fByteStats[0]) * 256);

    for (srci = 0; srci < fInputLen; srci += 1) {
        fByteStats[fInputBytes[srci]] += 1;
    }

    for (int32_t i = 0x80; i <= 0x9F; i += 1) {
        if (fByteStats[i] != 0) {
            fC1Bytes = TRUE;
            break;
        }
    }
}

CharsetRecog_UTF8::~CharsetRecog_UTF8()
{
    // nothing to do
}

const char* CharsetRecog_UTF8::getName() const
{
    return "UTF-8";
}

UBool CharsetRecog_UTF8::match(InputText* input, CharsetMatch* results) const
{
    bool hasBOM = FALSE;
    int32_t numValid = 0;
    int32_t numInvalid = 0;
    const uint8_t* inputBytes = input->fRawInput;
    int32_t i;
    int32_t trailBytes = 0;
    int32_t confidence;

    if (input->fRawLength >= 3 && inputBytes[0] == 0xEF && inputBytes[1] == 0xBB && inputBytes[2] == 0xBF) {
        hasBOM = TRUE;
    }

    // Scan for multi-byte sequences
    for (i = 0; i < input->fRawLength; i += 1) {
        int32_t b = inputBytes[i];

        if ((b & 0x80) == 0) {
            continue; // ASCII
        }

        // Hi bit on char found.  Figure out how long the sequence should be
        if ((b & 0x0E0) == 0x0C0) {
            trailBytes = 1;
        } else if ((b & 0x0F0) == 0x0E0) {
            trailBytes = 2;
        } else if ((b & 0x0F8) == 0xF0) {
            trailBytes = 3;
        } else {
            numInvalid += 1;
            continue;
        }

        // Verify that we've got the right number of trail bytes in the sequence
        for (;;) {
            i += 1;

            if (i >= input->fRawLength) {
                break;
            }

            b = inputBytes[i];

            if ((b & 0xC0) != 0x080) {
                numInvalid += 1;
                break;
            }

            if (--trailBytes == 0) {
                numValid += 1;
                break;
            }
        }
    }

    // Cook up some sort of confidence score, based on presence of a BOM
    //    and the existence of valid and/or invalid multi-byte sequences.
    confidence = 0;
    if (hasBOM && numInvalid == 0) {
        confidence = 100;
    } else if (hasBOM && numValid > numInvalid * 10) {
        confidence = 80;
    } else if (numValid > 3 && numInvalid == 0) {
        confidence = 100;
    } else if (numValid > 0 && numInvalid == 0) {
        confidence = 80;
    } else if (numValid == 0 && numInvalid == 0) {
        // Plain ASCII. Confidence must be > 10, it's more likely than UTF-16, which
        //              accepts ASCII with confidence = 10.
        confidence = 15;
    } else if (numValid > numInvalid * 10) {
        // Probably corruput utf-8 data.  Valid sequences aren't likely by chance.
        confidence = 25;
    }

    results->set(input, this, confidence);
    return (confidence > 0);
}
//////////////////////////////////////////////////////////////////////////

CharsetMatch::CharsetMatch()
    : textIn(NULL)
    , confidence(0)
    , fCharsetName(NULL)
    , fLang(NULL)
{
    // nothing else to do.
}

void CharsetMatch::set(InputText* input, const CharsetRecognizer* cr, int32_t conf,
    const char* csName, const char* lang)
{
    textIn = input;
    confidence = conf;
    fCharsetName = csName;
    fLang = lang;
    if (cr != NULL) {
        if (fCharsetName == NULL) {
            fCharsetName = cr->getName();
        }
        if (fLang == NULL) {
            fLang = cr->getLanguage();
        }
    }
}

const char* CharsetMatch::getName() const
{
    return fCharsetName;
}

const char* CharsetMatch::getLanguage() const
{
    return fLang;
}

int32_t CharsetMatch::getConfidence() const
{
    return confidence;
}

static CSRecognizerInfo** fCSRecognizers = NULL;
static int32_t fCSRecognizers_size = 0;

CharsetDetector::CharsetDetector(UErrorCode& status)
    : textIn(new InputText(status))
    , resultArray(NULL)
    , resultCount(0)
    , fStripTags(FALSE)
    , fFreshTextSet(FALSE)
    , fEnabledRecognizers(NULL)
{
    setRecognizers(status);

    resultArray = (CharsetMatch**)WTF::Partitions::FastMalloc(sizeof(CharsetMatch*) * fCSRecognizers_size, "CharsetDetector");

    if (resultArray == NULL) {
        status = U_MEMORY_ALLOCATION_ERROR;
        return;
    }

    for (int32_t i = 0; i < fCSRecognizers_size; i += 1) {
        resultArray[i] = new CharsetMatch();

        if (resultArray[i] == NULL) {
            status = U_MEMORY_ALLOCATION_ERROR;
            break;
        }
    }
}

CharsetDetector::~CharsetDetector()
{
    delete textIn;

    for (int32_t i = 0; i < fCSRecognizers_size; i += 1) {
        delete resultArray[i];
    }

    WTF::Partitions::FastFree(resultArray);

    if (fEnabledRecognizers) {
        WTF::Partitions::FastFree(fEnabledRecognizers);
    }
}

void CharsetDetector::setText(const char* in, int32_t len)
{
    textIn->setText(in, len);
    fFreshTextSet = TRUE;
}

const CharsetMatch* CharsetDetector::detect(UErrorCode& status)
{
    int32_t maxMatchesFound = 0;

    detectAll(maxMatchesFound, status);

    if (maxMatchesFound > 0) {
        return resultArray[0];
    } else {
        return NULL;
    }
}

void CharsetDetector::setRecognizers(UErrorCode& status)
{
    static bool init = false;
    if (init)
        return;
    init = true;

    CSRecognizerInfo* tempArray[] = {
        new CSRecognizerInfo(new CharsetRecog_UTF8(), TRUE),
    };
    int32_t rCount = ARRAY_SIZE(tempArray);

    fCSRecognizers = NEW_ARRAY(CSRecognizerInfo*, rCount);

    if (fCSRecognizers == NULL) {
        status = U_MEMORY_ALLOCATION_ERROR;
    } else {
        fCSRecognizers_size = rCount;
        for (int32_t r = 0; r < rCount; r += 1) {
            fCSRecognizers[r] = tempArray[r];
            if (fCSRecognizers[r] == NULL) {
                status = U_MEMORY_ALLOCATION_ERROR;
            }
        }
    }
}

const CharsetMatch* const* CharsetDetector::detectAll(int32_t& maxMatchesFound, UErrorCode& status)
{
    if (!textIn->isSet()) {
        status = U_MISSING_RESOURCE_ERROR; // TODO:  Need to set proper status code for input text not set

        return NULL;
    } else if (fFreshTextSet) {
        CharsetRecognizer* csr;
        int32_t i;

        textIn->MungeInput(fStripTags);

        // Iterate over all possible charsets, remember all that
        // give a match quality > 0.
        resultCount = 0;
        for (i = 0; i < fCSRecognizers_size; i += 1) {
            csr = fCSRecognizers[i]->recognizer;
            if (csr->match(textIn, resultArray[resultCount])) {
                resultCount++;
            }
        }

        //         if (resultCount > 1) {
        //             uprv_sortArray(resultArray, resultCount, sizeof resultArray[0], charsetMatchComparator, NULL, TRUE, &status);
        //         }
        fFreshTextSet = FALSE;
    }

    maxMatchesFound = resultCount;

    return resultArray;
}
//====

namespace blink {

bool DetectTextEncoding(const char* data, uint32_t length, const char* hint_encoding_name, const KURL& hint_url, const char* hint_user_language,
    WTF::TextEncoding* detected_encoding)
{
    //OutputDebugStringA("DetectTextEncoding not impl\n");
    //*detected_encoding = WTF::TextEncoding("UTF-8");
    //return true;

    *detected_encoding = WTF::TextEncoding();
    int matchesCount = 0;
    UErrorCode status = U_ZERO_ERROR;
    CharsetDetector* detector = new CharsetDetector(status);
    if (U_ZERO_ERROR != (status))
        return false;
    //ucsdet_enableInputFilter(detector, true);
    detector->setText(data, static_cast<int32_t>(length));

    const CharsetMatch* const* matches = detector->detectAll(matchesCount, status);
    if (U_ZERO_ERROR != (status)) {
        delete (detector);
        return false;
    }

    const char* encoding = 0;
    if (hint_encoding_name) {
        WTF::TextEncoding hintEncoding(hint_encoding_name);
        const int32_t kThresold = 10;
        for (int i = 0; i < matchesCount; ++i) {
            int32_t confidence = matches[i]->getConfidence();
            if (confidence < kThresold)
                break;
            const char* matchEncoding = matches[i]->getName();
            if (WTF::TextEncoding(matchEncoding) == hintEncoding) {
                encoding = hint_encoding_name;
                break;
            }
        }
    }
    // If no match is found so far, just pick the top match.
    // This can happen, say, when a parent frame in EUC-JP refers to
    // a child frame in Shift_JIS and both frames do NOT specify the encoding
    // making us resort to auto-detection (when it IS turned on).
    if ((!encoding || encoding[0] == '\0') && matchesCount > 0)
        encoding = matches[0]->getName();

    if (!encoding || encoding[0] == '\0') {
        //encoding = "GBK";
        delete (detector);
        return false;
    }

    *detected_encoding = WTF::TextEncoding(encoding);

    delete (detector);
    return true;

    //     *detected_encoding = WTF::TextEncoding();
    //     // In general, do not use language hint. This helps get more
    //     // deterministic encoding detection results across devices. Note that local
    //     // file resources can still benefit from the hint.
    //     Language language = UNKNOWN_LANGUAGE;
    //     if (hint_url.Protocol() == "file")
    //         LanguageFromCode(hint_user_language, &language);
    //
    //     int consumed_bytes;
    //     bool is_reliable;
    //     Encoding encoding = CompactEncDet::DetectEncoding(
    //         data, length, hint_url.GetString().Ascii().c_str(), nullptr, nullptr,
    //         EncodingNameAliasToEncoding(hint_encoding_name), language,
    //         CompactEncDet::WEB_CORPUS,
    //         false,  // Include 7-bit encodings to detect ISO-2022-JP
    //         &consumed_bytes, &is_reliable);
    //
    //     if (encoding == UNKNOWN_ENCODING)
    //         *detected_encoding = WTF::UnknownEncoding();
    //     else
    //         *detected_encoding = WTF::TextEncoding(MimeEncodingName(encoding));
    //
    //     // Should return false if the detected encoding is UTF8. This helps prevent
    //     // modern web sites from neglecting proper encoding labelling and simply
    //     // relying on browser-side encoding detection. Encoding detection is supposed
    //     // to work for web sites with legacy encoding only (so this doesn't have to
    //     // be applied to local file resources).
    //     // Detection failure leads |TextResourceDecoder| to use its default encoding
    //     // determined from system locale or TLD.
    //     return !(encoding == UNKNOWN_ENCODING || (hint_url.Protocol() != "file" && encoding == UTF8));
}

} // namespace blink
