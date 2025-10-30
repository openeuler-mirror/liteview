#include "livi_debug_server.h"

#include <evco/file.h>
#include <evco/signal.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#include <boost/intrusive/list.hpp>
#include <map>
#include <nlohmann/json.hpp>
#include <optional>
#include <string>

#include "livi_ui_thread.h"
#include "livi_work_thread.h"
#include "utils/misc.h"

namespace livi {

static DebugServerOps gOps;

void debugServerInit(const DebugServerOps &ops) {
    gOps = ops;
}

static int create_server(uint16_t port, int af_family) {
    int fd = socket(af_family, SOCK_STREAM, 0);
    if (fd < 0) {
        perror("socket");
        return -1;
    }
    Defer fd_cleaner([fd] { close(fd); });
    sockaddr_storage addr;
    memset(&addr, 0, sizeof(addr));
    if (af_family == AF_INET) {
        sockaddr_in *addr4 = (sockaddr_in *)&addr;
        addr4->sin_family = AF_INET;
        addr4->sin_port = htons(port);
        addr4->sin_addr.s_addr = htonl(INADDR_ANY);
    } else if (af_family == AF_INET6) {
        sockaddr_in6 *addr6 = (sockaddr_in6 *)&addr;
        addr6->sin6_family = AF_INET6;
        addr6->sin6_port = htons(port);
        addr6->sin6_addr = in6addr_any;
    } else {
        fprintf(stderr, "unknown address family: %d\n", af_family);
        return -1;
    }

    if (bind(fd, (sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("bind");
        return -1;
    }
    if (listen(fd, 1) < 0) {
        perror("listen");
        return -1;
    }

    fd_cleaner.clear();
    return fd;
}

// all packets are in json format with 4-byte length prefix
// request (client send to server)
// { "type": "request", "command": "...", "data": ... }
// response (server reply client)
// { "type": "response", "command": "...", "success": true, "data": ... }
// message (server actively send to client)
// { "type": "message", "message": "...", "data": ... }

typedef bool (*CommandHandler)(const std::string &command, const nlohmann::json &request, nlohmann::json &response);

static bool handlerUnknown(const std::string &command, const nlohmann::json &request, nlohmann::json &response) {
    response = "unknown command";
    return false;
}

static bool handlerPageList(const std::string &command, const nlohmann::json &request, nlohmann::json &response) {
    response = nlohmann::json::array();
    std::vector<PageInfo> pages;
    UiThread::getInstance().getTaskQueue()->call([&pages]() { pages = gOps.page_list(); });
    for (auto &page : gOps.page_list()) {
        response.push_back({
            {"id", page.id},
            {"title", page.title},
            {"url", page.url},
        });
    }
    return true;
}

static bool handlerPageLoadurl(const std::string &command, const nlohmann::json &request, nlohmann::json &response) {
    if (!request.contains("id") || !request["id"].is_string()) {
        return false;
    }

    if (!request.contains("url") || !request["url"].is_string()) {
        return false;
    }

    PageInfo page;
    page.id = request["id"];
    page.url = request["url"];

    UiThread::getInstance().getTaskQueue()->call([&page]() { gOps.page_loadurl(page); });
    return true;
}

static bool handlerPageClose(const std::string &command, const nlohmann::json &request, nlohmann::json &response) {
    if (!request.contains("id") || !request["id"].is_string()) {
        return false;
    }

    std::string id = request["id"];
    UiThread::getInstance().getTaskQueue()->call([&id]() { gOps.page_close(id); });
    return true;
}

static std::map<std::string, CommandHandler> command_handlers = {
    {"page_list", handlerPageList},
    {"page_loadurl", handlerPageLoadurl},
    {"page_close", handlerPageClose},
};

class ClientSender : public evco::Coroutine {
public:
    void init(evco::File *file) {
        file_ = file;
    }

    void add_message(const nlohmann::json &data) {
        if (message_queue_.size() >= 128) {
            // this connection is too slow, drop it
            file_->close();
            return;
        }
        message_queue_.push(data);
        send_signal_.notify();
    }

    bool put_response(const nlohmann::json &data) {
        if (!response_signal_.wait([this] { return !response_.has_value(); })) {
            return false;
        }
        response_.emplace(data);
        send_signal_.notify();
        return true;
    }

protected:
    void entry() override {
        while (1) {
            if (!send_signal_.wait()) {
                return;
            }
            if (response_.has_value()) {
                if (!send_json(*response_)) {
                    return;
                }
                response_.reset();
            }
            while (!message_queue_.empty()) {
                if (!send_json(message_queue_.front())) {
                    return;
                }
                message_queue_.pop();
            }
        }
    }

private:
    bool send_json(const nlohmann::json &data) {
        std::string str = data.dump();
        uint32_t len = (uint32_t)str.size();
        len = htonl(len);

        if (!file_->write_ensure(&len, sizeof(len))) {
            return false;
        }
        if (!file_->write_ensure(str.data(), str.size())) {
            return false;
        }
        return true;
    };

    evco::File *file_;
    evco::Signal send_signal_;
    evco::Signal response_signal_;
    std::queue<nlohmann::json> message_queue_;
    std::optional<nlohmann::json> response_;
};

class ClientRequestHandler : public evco::Coroutine {
public:
    void init(evco::File *file, ClientSender *sender) {
        file_ = file;
        sender_ = sender;
    }

protected:
    void entry() override {
        while (true) {
            nlohmann::json request;
            if (!read_json(&request)) {
                return;
            }
            // check request is object
            if (!request.is_object()) {
                std::string str = request.dump();
                fprintf(stderr, "invalid request json: %s\n", str.c_str());
                return;
            }
            // check request.type is string and request.type == "request"
            if (!request.contains("type") || !request["type"].is_string() || request["type"] != "request") {
                fprintf(stderr, "invalid packet type\n");
                return;
            }
            // check request.command is string
            if (!request.contains("command") || !request["command"].is_string()) {
                fprintf(stderr, "invalid command\n");
                return;
            }
            std::string command = request["command"];
            auto it = command_handlers.find(command);
            CommandHandler handler = handlerUnknown;
            if (it != command_handlers.end()) {
                handler = it->second;
            }
            nlohmann::json response;
            response["type"] = "response";
            response["command"] = command;
            response["data"] = nullptr;
            response["success"] = handler(command, request["data"], response["data"]);
            if (!sender_->put_response(response)) {
                return;
            }
        }
    }

private:
    bool read_json(nlohmann::json *data) {
        uint32_t len;
        if (!file_->read_ensure(&len, sizeof(len))) {
            return false;
        }
        len = ntohl(len);
        std::string str;
        str.resize(len);
        if (!file_->read_ensure(str.data(), len)) {
            return false;
        }
        *data = nlohmann::json::parse(str);
        return true;
    }

    evco::File *file_;
    ClientSender *sender_;
};

class ClientCoroutine : public boost::intrusive::list_base_hook<>, public ClientSender, public ClientRequestHandler {
public:
    void init(int fd) {
        file_.set_fd(fd);
        ClientSender::init(&file_);
        ClientRequestHandler::init(&file_, this);
    }

    void start() {
        ClientSender::start();
        ClientRequestHandler::start();
    }

    void interrupt() {
        ClientSender::interrupt();
        ClientRequestHandler::interrupt();
    }

    void set_finish_callback(std::function<void()> callback) {
        auto forward_callback = [this, callback](Coroutine *) {
            ClientSender::set_finish_callback(nullptr);
            ClientRequestHandler::set_finish_callback(nullptr);
            interrupt();
            callback();
        };
        ClientSender::set_finish_callback(forward_callback);
        ClientRequestHandler::set_finish_callback(forward_callback);
    }

private:
    evco::File file_;
};

class Server : public evco::Coroutine {
protected:
    void entry() override {
        if (!WorkThread::getInstance().getTaskQueue()->inExecuteThread()) {
            fprintf(stderr, "Server::entry must be called in work thread\n");
            abort();
        }
        int fd = create_server(8226, AF_INET);
        if (fd < 0) {
            return;
        }
        file_.set_fd(fd);
        while (true) {
            int client_fd = file_.accept(nullptr, nullptr);
            if (client_fd < 0) {
                break;
            }
            ClientCoroutine *client = new ClientCoroutine();
            client->init(client_fd);
            fprintf(stderr, "client connected: %p\n", client);
            client->set_finish_callback([this, client]() {
                fprintf(stderr, "client disconnected: %p\n", client);
                clients_.erase(clients_.iterator_to(*client));
                delete client;
            });
            client->start();
            clients_.push_back(*client);
        }

        while (!clients_.empty()) {
            clients_.front().interrupt();
        }
    }

private:
    evco::File file_;
    boost::intrusive::list<ClientCoroutine> clients_;
};

class DebugServerImpl {
public:
    void start() {
        WorkThread::getInstance().getTaskQueue()->call([this]() { server_.start(); });
    }
    void stop() {
        WorkThread::getInstance().getTaskQueue()->call([this]() { server_.interrupt(); });
    }

    void sendPageCreated(const PageInfo &info) {
    }
    void sendPageUpdated(const PageInfo &info) {
    }
    void sendPageClosed(uint64_t id) {
    }

private:
    Server server_;
};

DebugServer::DebugServer() {
    impl_ = new DebugServerImpl;
}

DebugServer::~DebugServer() {
    delete impl_;
}

DebugServer &DebugServer::getInstance() {
    static DebugServer instance;
    return instance;
}

void DebugServer::start() {
    impl_->start();
}

void DebugServer::stop() {
    impl_->stop();
}

void DebugServer::sendPageCreated(const PageInfo &info) {
    impl_->sendPageCreated(info);
}

void DebugServer::sendPageUpdated(const PageInfo &info) {
    impl_->sendPageUpdated(info);
}

void DebugServer::sendPageClosed(uint64_t id) {
    impl_->sendPageClosed(id);
}

}  // namespace livi
