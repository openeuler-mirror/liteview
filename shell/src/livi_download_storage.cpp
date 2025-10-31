#include "livi_download_storage.h"

#include <fmt/core.h>
#include <sqlite_orm/sqlite_orm.h>

#include <mutex>
#include <optional>

#include "utils/runtime_info.h"

namespace livi {
static const char *downloadRecordStateToString(DownloadRecordState state) {
    switch (state) {
        case DOWNLOAD_RECORD_STATE_RUN:
            return "run";
        case DOWNLOAD_RECORD_STATE_DONE:
            return "done";
        case DOWNLOAD_RECORD_STATE_CANCEL:
            return "cancel";
        case DOWNLOAD_RECORD_STATE_FAIL:
            return "fail";
    }
    return "invalid";
}

static std::optional<DownloadRecordState> downloadRecordStateFromString(const char *str) {
    if (strcmp(str, "run") == 0) {
        return std::make_optional<DownloadRecordState>(DOWNLOAD_RECORD_STATE_RUN);
    }
    if (strcmp(str, "done") == 0) {
        return std::make_optional<DownloadRecordState>(DOWNLOAD_RECORD_STATE_DONE);
    }
    if (strcmp(str, "cancel") == 0) {
        return std::make_optional<DownloadRecordState>(DOWNLOAD_RECORD_STATE_CANCEL);
    }
    if (strcmp(str, "fail") == 0) {
        return std::make_optional<DownloadRecordState>(DOWNLOAD_RECORD_STATE_FAIL);
    }
    return std::nullopt;
}
}  // namespace livi

namespace sqlite_orm {
using livi::DownloadRecordState;
using livi::downloadRecordStateFromString;
using livi::downloadRecordStateToString;

template <>
struct type_printer<DownloadRecordState> : public text_printer {};
template <>
struct statement_binder<DownloadRecordState> {
    int bind(sqlite3_stmt *stmt, int index, const DownloadRecordState &value) {
        return statement_binder<std::string>().bind(stmt, index, downloadRecordStateToString(value));
    }
};
template <>
struct field_printer<DownloadRecordState> {
    std::string operator()(const DownloadRecordState &t) const {
        return downloadRecordStateToString(t);
    }
};
template <>
struct row_extractor<DownloadRecordState> {
    DownloadRecordState extract(const char *row_value) {
        if (auto state = downloadRecordStateFromString(row_value)) {
            return *state;
        } else {
            throw std::runtime_error("incorrect state string (" + std::string(row_value) + ")");
        }
    }

    DownloadRecordState extract(sqlite3_stmt *stmt, int columnIndex) {
        auto str = sqlite3_column_text(stmt, columnIndex);
        return this->extract((const char *)str);
    }
};
}  // namespace sqlite_orm

namespace livi {

static auto openStorage() {
    using namespace sqlite_orm;
    std::string dbfile = fmt::format("{}/{}", runtimeInfoGet().appdata_dir, "download.sqlite3");
    // clang-format off
    return make_storage(dbfile, 
                        make_table("t_download",
                            make_column("id", &DownloadRecord::id, autoincrement(), primary_key()),
                            make_column("url", &DownloadRecord::url),
                            make_column("filename", &DownloadRecord::filename),
                            make_column("filepath", &DownloadRecord::filepath),
                            make_column("state", &DownloadRecord::state)));
    // clang-format on
}

class DownloadStorageImpl {
public:
    typedef decltype(openStorage()) StorageType;
    std::optional<StorageType> m_storage;

    void init() {
        m_storage.emplace(openStorage());
        m_storage->sync_schema();
    }

    std::vector<DownloadRecord> readJobs() {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_storage->get_all<DownloadRecord>();
    }

    std::optional<DownloadRecord> getJobById(uint64_t id) {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_storage->get_optional<DownloadRecord>(id);
    }

    uint64_t createJob() {
        std::lock_guard<std::mutex> lock(m_mutex);
        DownloadRecord empty{};
        return m_storage->insert(empty);
    }

    void updateJob(const DownloadRecord &data) {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_storage->update(data);
    }

    void updateJob(uint64_t id, DownloadRecordState state) {
        std::lock_guard<std::mutex> lock(m_mutex);
        using namespace sqlite_orm;
        m_storage->update_all(set(c(&DownloadRecord::state) = state), where(c(&DownloadRecord::id) == id));
    }

    void removeJob(uint64_t id) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_storage->remove<DownloadRecord>(id);
    }

private:
    std::mutex m_mutex;
};

DownloadStorage::DownloadStorage() {
    impl = new DownloadStorageImpl();
}

DownloadStorage::~DownloadStorage() {
    delete impl;
}

void DownloadStorage::init() {
    impl->init();
}

std::vector<DownloadRecord> DownloadStorage::readJobs() {
    return impl->readJobs();
}

std::optional<DownloadRecord> DownloadStorage::getJobById(uint64_t id) {
    return impl->getJobById(id);
}

uint64_t DownloadStorage::createJob() {
    return impl->createJob();
}

void DownloadStorage::updateJob(const DownloadRecord &data) {
    return impl->updateJob(data);
}

void DownloadStorage::updateJob(uint64_t id, DownloadRecordState state) {
    return impl->updateJob(id, state);
}

void DownloadStorage::removeJob(uint64_t id) {
    return impl->removeJob(id);
}
}  // namespace livi