#include "livi_history_storage.h"

#include <fmt/core.h>
#include <sqlite_orm/sqlite_orm.h>

#include <mutex>
#include <optional>

#include "utils/runtime_info.h"

namespace livi {

static auto openStorage() {
    using namespace sqlite_orm;
    std::string dbfile = fmt::format("{}/{}", runtimeInfoGet().appdata_dir, "history.sqlite3");
    // clang-format off
    return make_storage(dbfile,
                        make_table("t_history", 
                            make_column("id", &HistoryRecord::id, autoincrement(), primary_key()),
                            make_column("url", &HistoryRecord::url),
                            make_column("title", &HistoryRecord::title)));
    // clang-format on
}

class HistoryStorageImpl {
public:
    typedef decltype(openStorage()) StorageType;

    void init() {
        m_storage.emplace(openStorage());
        m_storage->sync_schema();
    }

    void saveRecord(HistoryRecord &record) {
        std::lock_guard<std::mutex> lock(m_mutex);

        record.id = m_storage->insert(record);
    }

    void updateRecord(const HistoryRecord &record) {
        std::lock_guard<std::mutex> lock(m_mutex);

        m_storage->update(record);
    }

    void deleteRecord(uint64_t id) {
        std::lock_guard<std::mutex> lock(m_mutex);

        m_storage->remove<HistoryRecord>(id);
    }

    std::vector<HistoryRecord> readRecords(size_t page_number, size_t page_size) {
        std::lock_guard<std::mutex> lock(m_mutex);

        using namespace sqlite_orm;
        return m_storage->get_all<HistoryRecord>(order_by(&HistoryRecord::id).desc(),
                                                 limit(page_size, offset(page_size * page_number)));
    }

private:
    std::optional<StorageType> m_storage;
    std::mutex m_mutex;
};

HistoryStorage::HistoryStorage() {
    impl = new HistoryStorageImpl;
}

HistoryStorage::~HistoryStorage() {
    delete impl;
}

void HistoryStorage::init() {
    impl->init();
}

void HistoryStorage::saveRecord(HistoryRecord &record) {
    impl->saveRecord(record);
}

void HistoryStorage::updateRecord(const HistoryRecord &record) {
    impl->updateRecord(record);
}

void HistoryStorage::deleteRecord(uint64_t id) {
    impl->deleteRecord(id);
}

std::vector<HistoryRecord> HistoryStorage::readRecords(size_t page_number, size_t page_size) {
    return impl->readRecords(page_number, page_size);
}

HistoryStorage &HistoryStorage::getInstance() {
    static HistoryStorage instance;
    return instance;
}

}  // namespace livi
