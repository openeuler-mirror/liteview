#ifndef __livi_download_manager_h__
#define __livi_download_manager_h__

#include <mb.h>
#include <stdint.h>

#include <string>
#include <vector>

namespace livi {

enum DownloadState {
    DOWNLOAD_STATE_RUN,
    DOWNLOAD_STATE_DONE,
    DOWNLOAD_STATE_PAUSE,
    DOWNLOAD_STATE_CANCEL,
    DOWNLOAD_STATE_FAIL,
    DOWNLOAD_STATE_INVALID,
};

struct DownloadJobInfo {
    uint64_t id;
    std::string filename;
    std::string filepath;
    std::string url;
    uint64_t total_size;
    uint64_t download_size;
    uint64_t speed;
    DownloadState state;
};

typedef void (*DownloadManagerJobCreateCallback)(const DownloadJobInfo &job, void *userdata);
typedef void (*DownloadManagerJobUpdateCallback)(const DownloadJobInfo &job, void *userdata);

void downloadManagerInit(DownloadManagerJobCreateCallback create_cb, DownloadManagerJobUpdateCallback update_cb,
                         void *userdata);
void downloadManagerStop();
void downloadManagerWebviewRegister(mbWebView webView);
void downloadManagerJobPause(uint64_t id);
void downloadManagerJobResume(uint64_t id);
void downloadManagerJobCancel(uint64_t id);
std::vector<DownloadJobInfo> downloadManagerJobList();

// send the job info to UiThread to update the UI
void downloadNotifyCreate(const DownloadJobInfo &job);
void downloadNotifyUpdate(const DownloadJobInfo &job);

}  // namespace livi

#endif
