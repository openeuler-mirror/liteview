#include "livi_download_manager.h"

#include "livi_download_storage.h"
#include "livi_ui_thread.h"

namespace livi {

static struct {
    DownloadManagerJobCreateCallback create_cb;
    DownloadManagerJobUpdateCallback update_cb;
    void *callback_data;
} g;

void downloadManagerInit(DownloadManagerJobCreateCallback create_cb, DownloadManagerJobUpdateCallback update_cb,
                         void *userdata) {
    // extern void downloadManagerImplInit();
    // downloadManagerImplInit();

    // g.create_cb = create_cb;
    // g.update_cb = update_cb;
    // g.callback_data = userdata;
    // for (auto &record : DownloadStorage::getInstance().readJobs()) {
    //     DownloadJobInfo job{};
    //     job.id = record.id;
    //     job.url = record.url;
    //     job.filename = record.filename;
    //     job.filepath = record.filepath;
    //     job.state = downloadRecordStateToDownloadState(record.state);
    //     downloadNotifyCreate(job);
    // }
}

void downloadManagerStop() {
}

void downloadNotifyCreate(const DownloadJobInfo &job) {
    // DownloadJobInfo *job_tmp = new DownloadJobInfo(job);
    // UiThread::getInstance().getTaskQueue()->post([job_tmp]() {
    //     g.create_cb(*job_tmp, g.callback_data);
    //     delete job_tmp;
    // });
}

void downloadNotifyUpdate(const DownloadJobInfo &job) {
    // DownloadJobInfo *job_tmp = new DownloadJobInfo(job);
    // UiThread::getInstance().getTaskQueue()->post([job_tmp]() {
    //     g.update_cb(*job_tmp, g.callback_data);
    //     delete job_tmp;
    // });
}

}  // namespace livi
