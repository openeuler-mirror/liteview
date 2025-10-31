#include "runtime_info.h"

#include <errno.h>
#include <fcntl.h>
#include <fmt/core.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "arguments.h"

namespace livi {

static const char *systmp = "/tmp";

static bool makeDirectory(const char *dir, mode_t mode = 0700) {
    if (mkdir(dir, mode) < 0) {
        return errno == EEXIST;
    }
    return true;
}

static bool isFile(const char *filename) {
    return (access(filename, O_RDONLY) == 0);
}

static std::string getCurrentWorkDirectory() {
    char *cwd = get_current_dir_name();
    std::string result = cwd;
    free(cwd);
    return result;
}

static std::string getExecutableDirectory() {

    int max_path = 500;
    char current_path[max_path];

    int cnt = readlink("/proc/self/exe", current_path, max_path);
    if(cnt < 0 || cnt >= max_path){
        fmt::print(stderr, "Error: getExecutableDirectory\n");
        abort();
    }

    for(int i=cnt; i>=0; --i)
    {
        if(current_path[i] == '/'){
            current_path[i+1] = '\0';
            break;
        }
    }

    return std::string(current_path);
}

static std::string getHomeDirectory() {
    struct passwd *pw = getpwuid(getuid());
    if (pw) {
        const char *home = pw->pw_dir;
        if (access(home, O_RDWR) == 0) {
            return home;
        }
    }
    return "";
}

static std::string getDownloadDirectory(const std::string &home, const std::string &appdata) {
    std::string dir;
    if (home.size()) {
        dir = fmt::format("{}/{}", home, "Downloads");
        if (makeDirectory(dir.c_str())) {
            return dir;
        }
        fmt::print(stderr, "{}: fail to create download directory: {}\n", __func__, dir);
    }
    dir = fmt::format("{}/{}", appdata, "Downloads");
    if (makeDirectory(dir.c_str())) {
        return dir;
    }
    fmt::print(stderr, "{}: fail to create download directory: {}\n", __func__, dir);
    abort();
}

static std::string getAppDataDirectory(const std::string &home) {
    std::string appdata;

    if (home.empty()) {
        appdata = fmt::format("{}/livibrowser_{}", systmp, getuid());
        if (!makeDirectory(appdata.c_str())) {
            fmt::print(stderr, "{}: fail to create temp appdata: {}\n", __func__, appdata);
            abort();
        }
        return appdata;
    }
    appdata = fmt::format("{}/{}", home, ".livibrowser");
    if (!makeDirectory(appdata.c_str())) {
        fmt::print(stderr, "{}: fail to create appdata: {}\n", __func__, appdata);
        abort();
    }
    return appdata;
}

static std::string getMiniblinkKernel(const std::string &exedir, const std::string &appdata) {
    // search order: exedir, exedir/../third_party/miniblink, appdata
    const char *filename = "livicore.so";
    std::string result;
    result = fmt::format("{}{}", exedir, filename);
    if (isFile(result.c_str())) {
        return result;
    }

    fmt::print(stderr, "{}: cannot found {}\n", __func__, filename);
    abort();
}

static RuntimeInfo runtimeInfo;

void runtimeInfoInit() {
    std::string home = getHomeDirectory();
    std::string exedir = getExecutableDirectory();

    runtimeInfo.appdata_dir = getAppDataDirectory(home);
    runtimeInfo.download_dir = getDownloadDirectory(home, runtimeInfo.appdata_dir);
    runtimeInfo.miniblink_kernel = getMiniblinkKernel(exedir, runtimeInfo.appdata_dir);

    fmt::print(stdout, "appdata  directory: {}\n", runtimeInfo.appdata_dir);
    fmt::print(stdout, "download directory: {}\n", runtimeInfo.download_dir);
    fmt::print(stdout, "miniblink  libpath: {}\n", runtimeInfo.miniblink_kernel);
}

const RuntimeInfo &runtimeInfoGet() {
    return runtimeInfo;
}

}  // namespace livi
