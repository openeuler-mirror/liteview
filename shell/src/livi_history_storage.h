#ifndef __livi_history_storage_h__
#define __livi_history_storage_h__

#include <optional>
#include <vector>

#include "livi_download_manager.h"

namespace livi {

class HistoryStorageImpl;

struct HistoryRecord {
    uint64_t id;
    std::string url;
    std::string title;
};

class HistoryStorage {
public:
    void init();
    void saveRecord(HistoryRecord &record);
    void updateRecord(const HistoryRecord &record);
    void deleteRecord(uint64_t id);
    std::vector<HistoryRecord> readRecords(size_t page_number, size_t page_size);

    HistoryStorage(const HistoryStorage &) = delete;
    HistoryStorage &operator=(const HistoryStorage &) = delete;
    static HistoryStorage &getInstance();

private:
    HistoryStorage();
    ~HistoryStorage();
    HistoryStorageImpl *impl;
};

}  // namespace livi

#endif
