#include "guess.h"

#include <ctype.h>
#include <error.h>
#include <fcntl.h>
#include <fmt/core.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unicode/schriter.h>
#include <unicode/unistr.h>
#include <unistd.h>

#include "misc.h"

namespace livi {

static inline int hex2num(char ch) {
    if (isdigit(ch)) {
        return ch - '0';
    } else if (isupper(ch)) {
        if (ch <= 'F') {
            return ch - 'F';
        }
    } else if (islower(ch)) {
        if (ch <= 'f') {
            return ch - 'f';
        }
    }
    return -1;
}

std::string urlDecode(const char *url, bool *result_p) {
    bool result = true;
    std::string url_decoded;

    size_t url_len = strlen(url);
    url_decoded.reserve(url_len);
    for (size_t i = 0; i < url_len; ++i) {
        char c = url[i];
        if (c == '%') {
            if (i + 2 >= url_len) {
                result = false;
                break;
            }
            int h4, l4;
            h4 = hex2num(url[i + 1]);
            l4 = hex2num(url[i + 2]);
            if (h4 < 0 || l4 < 0) {
                result = false;
                break;
            }
            char c = (char)((h4 << 4) | (l4 << 0));
            url_decoded.push_back(c);
        } else {
            url_decoded.push_back(c);
        }
    }
    if (result_p) {
        *result_p = result;
    }
    return result ? url_decoded : "";
}

static inline std::string ensureUniqueName(const std::string &basename, const char *save_directory,
                                           std::string *error_message) {
    const unsigned int start_number = 1;
    const unsigned int stop_number = 65536;

    *error_message = "";
    int ret, dirfd = open(save_directory, O_PATH);
    if (dirfd < 0) {
        *error_message = fmt::format("cannot access directory: {}", save_directory);
        return basename;
    }
    Defer defer = [dirfd]() { close(dirfd); };

    ret = faccessat(dirfd, basename.c_str(), O_RDONLY, 0);
    if (ret != F_OK) {
        if (errno != ENOENT) {
            *error_message = strerror(errno);
        }
        return basename;
    }

    for (unsigned int i = start_number; i <= stop_number; ++i) {
        std::string result = fmt::format("({}) {}", i, basename);
        ret = faccessat(dirfd, result.c_str(), O_RDONLY, 0);
        if (ret != F_OK) {
            if (errno != ENOENT) {
                *error_message = strerror(errno);
            }
            return result;
        }
    }
    *error_message = "no available filename";
    return basename;
}

static inline std::string guessBasename(const char *url) {
    const static std::string default_name = "download";
    std::string url_decoded;

    url_decoded = urlDecode(url, nullptr);
    if (url_decoded.size() == 0) {
        return default_name;
    }

    icu::UnicodeString url_unicode = icu::UnicodeString::fromUTF8(url_decoded);
    icu::UnicodeString filename;
    int slash_pos = url_unicode.lastIndexOf((UChar32)'/');
    if (slash_pos < 0) {
        return default_name;
    }
    int question_pos = url_unicode.indexOf((UChar32)'?', slash_pos);
    if (question_pos < slash_pos) {
        filename = url_unicode.tempSubString(slash_pos + 1);
    } else {
        filename = url_unicode.tempSubString(slash_pos + 1, question_pos - slash_pos - 1);
    }
    if (filename.length() == 0) {
        return default_name;
    }
    icu::UCharCharacterIterator iterator(filename.getBuffer(), filename.length());
    for (UChar32 ch = iterator.next32PostInc(); ch != icu::UCharCharacterIterator::DONE;
         ch = iterator.next32PostInc()) {
        if (ch == 0xfffd) {
            return default_name;
        }
    }
    std::string basename;
    filename.toUTF8String(basename);
    return basename;
}

std::string guessFilenameByUrl(const char *url, const char *save_directory, std::string *error_message) {
    std::string basename = guessBasename(url);
    return ensureUniqueName(basename, save_directory, error_message);
}

std::u16string utf8To16(const std::string &str) {
    std::u16string result;
    icu::UnicodeString ustr = icu::UnicodeString::fromUTF8(str);

    result.resize(ustr.length());
    memcpy((void *)result.data(), (void *)ustr.getBuffer(), ustr.length() * 2);

    return result;
}

}  // namespace livi
