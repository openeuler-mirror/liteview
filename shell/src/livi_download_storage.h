#include <optional>
#include <vector>

#include "livi_download_manager.h"

namespace livi {

enum DownloadRecordState {
    DOWNLOAD_RECORD_STATE_RUN = DOWNLOAD_STATE_RUN,
    DOWNLOAD_RECORD_STATE_DONE = DOWNLOAD_STATE_DONE,
    DOWNLOAD_RECORD_STATE_CANCEL = DOWNLOAD_STATE_CANCEL,
    DOWNLOAD_RECORD_STATE_FAIL = DOWNLOAD_STATE_FAIL,
    DOWNLOAD_RECORD_STATE_INVALID = DOWNLOAD_STATE_INVALID,
};

static DownloadState downloadRecordStateToDownloadState(DownloadRecordState state) {
    return (DownloadState)state;
}

static DownloadRecordState downloadStateToDownloadRecordState(DownloadState state) {
    if (state == DOWNLOAD_STATE_PAUSE) {
        return DOWNLOAD_RECORD_STATE_RUN;
    }
    return (DownloadRecordState)state;
}

struct DownloadRecord {
    uint64_t id;
    std::string url;
    std::string filename;
    std::string filepath;
    DownloadRecordState state;
};

class DownloadStorageImpl;

class DownloadStorage {
public:
    void init();
    std::vector<DownloadRecord> readJobs();
    std::optional<DownloadRecord> getJobById(uint64_t id);
    uint64_t createJob();
    void updateJob(const DownloadRecord &data);
    void updateJob(uint64_t id, DownloadRecordState state);
    void removeJob(uint64_t id);

    DownloadStorage(const DownloadStorage &) = delete;
    DownloadStorage &operator=(const DownloadStorage &) = delete;

    static DownloadStorage &getInstance() {
        static DownloadStorage instance;
        return instance;
    }

private:
    DownloadStorage();
    ~DownloadStorage();
    DownloadStorageImpl *impl;
};

}  // namespace livi