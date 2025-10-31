#ifndef __livi_utils_guess_h__
#define __livi_utils_guess_h__

#include <string>

namespace livi {

std::string guessFilenameByUrl(const char *url, const char *save_directory, std::string *error_message);
std::u16string utf8To16(const std::string &str);

}  // namespace livi

#endif
