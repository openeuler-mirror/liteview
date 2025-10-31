#ifndef __livi_debug_server_h__
#define __livi_debug_server_h__

#include <stdint.h>

#include <functional>
#include <string>

namespace livi {

struct PageInfo {
    std::string id;
    std::string title;
    std::string url;
};

struct DebugServerOps {
    std::function<std::vector<PageInfo>()> page_list;
    std::function<bool(const PageInfo &)> page_loadurl;
    std::function<bool(const std::string &id)> page_close;
};

void debugServerInit(const DebugServerOps &ops);

class DebugServerImpl;

class DebugServer {
public:
    DebugServer();
    ~DebugServer();

    DebugServer(const DebugServer &) = delete;
    DebugServer &operator=(const DebugServer &) = delete;

    static DebugServer &getInstance();

    void start();
    void stop();

    void sendPageCreated(const PageInfo &info);
    void sendPageUpdated(const PageInfo &info);
    void sendPageClosed(uint64_t id);

private:
    friend class DebugServerImpl;
    DebugServerImpl *impl_;
};

}  // namespace livi

#endif  // __livi_debug_server_h__