#ifndef __livi_utils_runtime_info_h__
#define __livi_utils_runtime_info_h__

#include <string>

namespace livi {

struct RuntimeInfo {
    std::string appdata_dir;
    std::string download_dir;
    std::string miniblink_kernel;
};

void runtimeInfoInit();
const RuntimeInfo &runtimeInfoGet();

}  // namespace livi

#endif
