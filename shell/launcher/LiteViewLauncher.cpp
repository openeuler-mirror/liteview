//
// Copyright (c) 2025 Institute of Software, Chinese Academy of Sciences (ISCAS)
// LiteView is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
//          http://license.coscl.org.cn/MulanPSL2
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// See the Mulan PSL v2 for more details.
//

/*
g++ LiteViewLauncher.cpp -std=c++17 -O2 -o LiteViewLauncher

*/

#include <unistd.h>


#include <cerrno>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <limits.h>

extern char** environ;


namespace fs = std::filesystem;

namespace {

// 全局静态缓冲区，存放拼接后的完整路径
static char g_full_path[PATH_MAX] = {0};

// 程序启动时初始化路径
__attribute__((constructor)) void InitAppPath()
{
    // 获取当前可执行文件绝对路径
    ssize_t len = readlink("/proc/self/exe", g_full_path, PATH_MAX - 1);
    if (len <= 0)
    {
        // 读取失败，回退为原路径 ./LiteView
        strcpy(g_full_path, "./LiteView");
        return;
    }

    // 截取目录部分
    char* dir_end = strrchr(g_full_path, '/');
    if (dir_end == nullptr)
    {
        strcpy(g_full_path, "./LiteView");
        return;
    }

    // 在目录后拼接 /LiteView
    ++dir_end;
    *dir_end = '\0';
    strcat(g_full_path, "LiteView");
}

constexpr const char* kAppPath = g_full_path;


bool HasDisableJemallocArg(int argc, char* argv[]) {
    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "--no-jemalloc") == 0) {
            return true;
        }
    }
    return false;
}

unsigned GetNProc() {
    unsigned n = std::thread::hardware_concurrency();
    if (n > 0) {
        return n;
    }

    long online = sysconf(_SC_NPROCESSORS_ONLN);
    if (online > 0) {
        return static_cast<unsigned>(online);
    }

    return 1;
}

std::string BuildMallocConf() {
    std::string conf =
        "background_thread:true,"
        "dirty_decay_ms:8000,"
        "muzzy_decay_ms:8000,"
        "metadata_thp:auto,"
        "tcache_max:4096";

    conf += ",narenas:";
    conf += std::to_string(GetNProc());

    return conf;
}

std::string FindJemalloc() {
    const char* candidates[] = {
        "./libjemalloc.so",
        "./libjemalloc.so.2",

        "/usr/lib64/libjemalloc.so",
        "/usr/lib64/libjemalloc.so.2",

        "/usr/lib/libjemalloc.so",
        "/usr/lib/libjemalloc.so.2",

        "/lib64/libjemalloc.so",
        "/lib64/libjemalloc.so.2",

        "/lib/libjemalloc.so",
        "/lib/libjemalloc.so.2",

        "/usr/local/lib64/libjemalloc.so",
        "/usr/local/lib64/libjemalloc.so.2",

        "/usr/local/lib/libjemalloc.so",
        "/usr/local/lib/libjemalloc.so.2",
    };

    for (auto path : candidates) {
        if (fs::exists(path)) {
            return path;
        }
    }

    return {};
}

std::vector<char*> BuildArgv(
    int argc,
    char* argv[]) {

    std::vector<char*> result;

    result.reserve(argc + 1);

    result.push_back(
        const_cast<char*>(kAppPath));

    for (int i = 1; i < argc; ++i) {

        if (strcmp(argv[i], "--jemalloc") == 0 ||
            strcmp(argv[i], "--no-jemalloc") == 0) {
            continue;
        }

        result.push_back(argv[i]);
    }

    result.push_back(nullptr);

    return result;
}

std::vector<char*> BuildEnvp(
    bool enable_jemalloc,
    const std::string& jemalloc_path,
    const std::string& malloc_conf) {

    static std::vector<std::string> storage;

    storage.clear();

    std::string old_ld_preload;

    for (char** p = environ; *p; ++p) {

        std::string env(*p);

        if (env.rfind("LD_PRELOAD=", 0) == 0) {
            old_ld_preload = env.substr(strlen("LD_PRELOAD="));
            continue;
        }

        if (env.rfind("MALLOC_CONF=", 0) == 0) {
            continue;
        }

        storage.emplace_back(std::move(env));
    }

    if (enable_jemalloc && !jemalloc_path.empty()) {

        std::string preload;

        preload = jemalloc_path;

        if (!old_ld_preload.empty()) {
            preload += ":";
            preload += old_ld_preload;
        }

        storage.emplace_back(
            "LD_PRELOAD=" + preload);

        storage.emplace_back(
            "MALLOC_CONF=" + malloc_conf);
    } else {

        if (!old_ld_preload.empty()) {
            storage.emplace_back(
                "LD_PRELOAD=" + old_ld_preload);
        }
    }

    std::vector<char*> envp;

    envp.reserve(storage.size() + 1);

    for (auto& s : storage) {
        envp.push_back(s.data());
    }

    envp.push_back(nullptr);

    return envp;
}

} // namespace

int main(int argc, char* argv[]) {

    if (!fs::exists(kAppPath)) {
        std::cerr
            << "Executable not found: "
            << kAppPath
            << std::endl;
        return 1;
    }

    bool enable_jemalloc =
        !HasDisableJemallocArg(argc, argv);

    std::string jemalloc_path;

    if (enable_jemalloc) {

        jemalloc_path = FindJemalloc();

        if (jemalloc_path.empty()) {

            std::cerr
                << "[WARN] jemalloc requested "
                << "but libjemalloc.so not found"
                << std::endl;

            enable_jemalloc = false;

        } else {

            std::cout
                << "[INFO] jemalloc found: "
                << jemalloc_path
                << std::endl;
        }
    }

    std::string malloc_conf =
        BuildMallocConf();

    pid_t pid = fork();

    if (pid < 0) {

        std::cerr
            << "fork failed: "
            << strerror(errno)
            << std::endl;

        return 1;
    }

    if (pid == 0) {

        auto child_argv =
            BuildArgv(argc, argv);

        auto child_env =
            BuildEnvp(enable_jemalloc,
                      jemalloc_path,
                      malloc_conf);

        execve(
            kAppPath,
            child_argv.data(),
            child_env.data());

        std::cerr
            << "execve failed: "
            << strerror(errno)
            << std::endl;

        _exit(127);
    }

    std::cout
        << "[INFO] launched: "
        << kAppPath
        << " pid="
        << pid
        << std::endl;

    return 0;
}
