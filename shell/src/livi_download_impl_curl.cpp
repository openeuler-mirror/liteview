#include <assert.h>
#include <curl/curl.h>
#include <fmt/core.h>
#include <glib.h>
#include <mb.h>

#include <map>
#include <memory>

#include "livi_download_manager.h"
#include "livi_download_storage.h"
#include "livi_work_thread.h"
#include "utils/guess.h"
#include "utils/misc.h"
#include "utils/runtime_info.h"

namespace livi {

struct CurlInitializer {
    CurlInitializer() {
        curl_global_init(CURL_GLOBAL_DEFAULT);
    }
};

static CurlInitializer curlInitializer;
static DownloadStorage &downloadStorage = DownloadStorage::getInstance();

class CurlDownloadThread {
public:
    CurlDownloadThread() {
        ev_init(&timer, evTimerCallback);
        timer.data = (void *)this;
        WorkThread::getInstance().getTaskQueue()->call(std::bind(&CurlDownloadThread::threadEntry, this));
    }

    void jobStart(const char *url, uint64_t total) {
        WorkThread::getInstance().getTaskQueue()->call(
            [this, url = std::string(url), total]() { threadJobStart(std::move(url), total); });
    }

    void jobPause(uint64_t id) {
        WorkThread::getInstance().getTaskQueue()->call([this, id]() { threadJobPause(id); });
    }

    void jobResume(uint64_t id) {
        WorkThread::getInstance().getTaskQueue()->call([this, id]() { threadJobResume(id); });
    }

    void jobCancel(uint64_t id) {
        WorkThread::getInstance().getTaskQueue()->call([this, id]() { threadJobCancel(id); });
    }

    std::vector<DownloadJobInfo> jobList() {
        std::vector<DownloadJobInfo> result;
        WorkThread::getInstance().getTaskQueue()->call([this, &result]() { result = threadJobList(); });
        return result;
    }

private:
    struct JobData final : DownloadJobInfo, ev_io {
        CurlDownloadThread *downloadThread;
        CURL *curl;
        FILE *file;

        JobData(CurlDownloadThread *downloadThread) {
            ev_io *w = this;
            this->downloadThread = downloadThread;
            ev_init(w, evSocketCallback);
        }

        ~JobData() {
            ev_io *w = this;
            ev_io_stop(WorkThread::getInstance().getLoop(), w);
        }
    };

    static void checkResult(CURLM *curlm) {
        int msgs;
        while (CURLMsg *message = curl_multi_info_read(curlm, &msgs)) {
            assert(message->msg == CURLMSG_DONE);
            CURL *curl = message->easy_handle;
            JobData *jd;
            curl_easy_getinfo(curl, CURLINFO_PRIVATE, &jd);
            curl_easy_cleanup(jd->curl);
            fclose(jd->file);
            jd->curl = nullptr;
            jd->file = nullptr;
            jobUpdateSignal(jd, DOWNLOAD_STATE_DONE);
        }
    }

    static void evSocketCallback(struct ev_loop *loop, ev_io *w, int revents) {
        JobData *jd = (JobData *)w;
        CurlDownloadThread *downloadThread = jd->downloadThread;
        CURLM *curlm = downloadThread->curlm;
        int ev_bitmask = 0;
        int running_handles;

        if ((revents & EV_READ)) {
            ev_bitmask |= CURL_POLL_IN;
        }
        if ((revents & EV_WRITE)) {
            ev_bitmask |= CURL_POLL_OUT;
        }
        curl_multi_socket_action(curlm, w->fd, ev_bitmask, &running_handles);
        checkResult(curlm);
    }

    static void evTimerCallback(struct ev_loop *loop, ev_timer *w, int revents) {
        CurlDownloadThread *downloadThread = (CurlDownloadThread *)w->data;
        CURLM *curlm = downloadThread->curlm;
        int running_handles;

        curl_multi_socket_action(curlm, CURL_SOCKET_TIMEOUT, 0, &running_handles);
        checkResult(curlm);
    }

    static int curlSocketCallback(CURL *curl, curl_socket_t s, int what, void *userp, void *socketp) {
        JobData *jd;
        curl_easy_getinfo(curl, CURLINFO_PRIVATE, &jd);
        ev_io *w = (ev_io *)jd;
        CurlDownloadThread *downloadThread = jd->downloadThread;
        struct ev_loop *loop = WorkThread::getInstance().getLoop();
        int events = 0;

        switch (what) {
            case CURL_POLL_IN:
                events = EV_READ;
                break;
            case CURL_POLL_OUT:
                events = EV_WRITE;
                break;
            case CURL_POLL_INOUT:
                events = EV_READ | EV_WRITE;
                break;
            case CURL_POLL_REMOVE:
                ev_io_stop(loop, w);
                return 0;
            default:
                fprintf(stderr, "%s: unhandle value: what = %d\n", __func__, what);
                abort();
        }
        ev_io_stop(loop, w);
        ev_io_set(w, s, events);
        ev_io_start(loop, w);
        return 0;
    }

    static int curlTimerCallback(CURLM *multi, long timeout_ms, CurlDownloadThread *downloadThread) {
        struct ev_loop *loop = WorkThread::getInstance().getLoop();

        ev_timer_stop(loop, &downloadThread->timer);
        if (timeout_ms >= 0) {
            ev_timer_set(&downloadThread->timer, timeout_ms / 1000.0, false);
            ev_timer_start(loop, &downloadThread->timer);
        }
        return 0;
    }

    void threadEntry() {
        curlm = curl_multi_init();
        curl_multi_setopt(curlm, CURLMOPT_SOCKETFUNCTION, curlSocketCallback);
        curl_multi_setopt(curlm, CURLMOPT_TIMERFUNCTION, curlTimerCallback);
        curl_multi_setopt(curlm, CURLMOPT_TIMERDATA, this);
    }

    JobData *jobNew(uint64_t id) {
        auto it = jobs.find(id);
        assert(it == std::end(jobs));
        auto &res = (jobs[id] = std::make_unique<JobData>(this));
        res->id = id;
        return res.get();
    }

    JobData *jobById(uint64_t id) {
        auto it = jobs.find(id);
        assert(it != std::end(jobs));
        return it->second.get();
    }

    static void jobCreateSignal(JobData *jd, DownloadState state) {
        jd->state = state;
        downloadNotifyCreate(*jd);

        DownloadRecord record;
        record.id = jd->id;
        record.url = jd->url;
        record.filename = jd->filename;
        record.filepath = jd->filepath;
        record.state = downloadStateToDownloadRecordState(jd->state);
        downloadStorage.updateJob(record);
    }

    static void jobRemoveIfNotNeed(JobData *jd) {
        if (jd->state == DOWNLOAD_STATE_RUN || jd->state == DOWNLOAD_STATE_PAUSE) {
            return;
        }
        jd->downloadThread->jobs.erase(jd->id);
    }

    static void jobUpdateSignal(JobData *jd, DownloadState state) {
        jd->state = state;
        downloadNotifyUpdate(*jd);

        if (state == DOWNLOAD_STATE_RUN) {
            return;
        }
        downloadStorage.updateJob(jd->id, downloadStateToDownloadRecordState(state));
        jobRemoveIfNotNeed(jd);
    }

    static int progressReport(JobData *jd, curl_off_t dltotal, curl_off_t dlnow, curl_off_t ultotal, curl_off_t ulnow) {
        jd->total_size = dltotal;
        jd->download_size = dlnow;
        downloadNotifyUpdate(*jd);

        jobRemoveIfNotNeed(jd);
        return 0;
    }

    void threadJobStart(std::string url, uint64_t total) {
        std::string download_dir = runtimeInfoGet().download_dir;
        std::string err;
        JobData *jd = jobNew(downloadStorage.createJob());

        jd->url = url;
        jd->total_size = total;
        jd->filename = guessFilenameByUrl(url.c_str(), download_dir.c_str(), &err);
        if (err.size()) {
            jobCreateSignal(jd, DOWNLOAD_STATE_FAIL);
            return;
        }
        jd->filepath = fmt::format("{}/{}", download_dir, jd->filename);
        jd->file = fopen(jd->filepath.c_str(), "w");
        if (!jd->file) {
            jd->state = DOWNLOAD_STATE_FAIL;
            jobCreateSignal(jd, DOWNLOAD_STATE_FAIL);
            return;
        }

        jobCreateSignal(jd, DOWNLOAD_STATE_RUN);
        jd->curl = curl_easy_init();
        curl_easy_setopt(jd->curl, CURLOPT_PRIVATE, jd);
        curl_easy_setopt(jd->curl, CURLOPT_URL, jd->url.c_str());
        curl_easy_setopt(jd->curl, CURLOPT_WRITEDATA, jd->file);
        curl_easy_setopt(jd->curl, CURLOPT_NOPROGRESS, 0);
        curl_easy_setopt(jd->curl, CURLOPT_XFERINFODATA, jd);
        curl_easy_setopt(jd->curl, CURLOPT_XFERINFOFUNCTION, progressReport);
        curl_easy_setopt(jd->curl, CURLOPT_NOSIGNAL, 1);
        curl_multi_add_handle(curlm, jd->curl);
    }

    void threadJobPause(uint64_t id) {
        JobData *jd = jobById(id);
        if (jd->curl) {
            curl_easy_pause(jd->curl, CURLPAUSE_ALL);
            jobUpdateSignal(jd, DOWNLOAD_STATE_PAUSE);
        }
    }

    void threadJobResume(uint64_t id) {
        JobData *jd = jobById(id);
        if (jd->curl) {
            curl_easy_pause(jd->curl, CURLPAUSE_CONT);
            jobUpdateSignal(jd, DOWNLOAD_STATE_RUN);
        }
    }

    void threadJobCancel(uint64_t id) {
        JobData *jd = jobById(id);
        if (jd->curl) {
            curl_multi_remove_handle(curlm, jd->curl);
            curl_easy_cleanup(jd->curl);
            fclose(jd->file);
            jd->curl = nullptr;
            jd->file = nullptr;
            remove(jd->filepath.c_str());
            jobUpdateSignal(jd, DOWNLOAD_STATE_CANCEL);
        }
    }

    std::vector<DownloadJobInfo> threadJobList() {
        std::vector<DownloadJobInfo> result;
        result.reserve(jobs.size());
        for (auto &job : jobs) {
            result.emplace_back(*job.second);
        }
        return result;
    }

    ev_timer timer;
    CURLM *curlm;
    std::map<uint64_t, std::unique_ptr<JobData>> jobs;
};
static std::optional<CurlDownloadThread> downloadThread;

void downloadManagerImplInit() {
    downloadThread.emplace();
}

static MB_CALL_TYPE mbDownloadOpt mbDownloadCallback(mbWebView webView, void *param, size_t expectedContentLength,
                                                     const char *url, const char *mime, const char *disposition,
                                                     mbNetJob job, mbNetJobDataBind *dataBind) {
    downloadThread->jobStart(url, expectedContentLength);
    return kMbDownloadOptCancel;
}

void downloadManagerWebviewRegister(mbWebView webView) {
    mbOnDownloadInBlinkThread(webView, mbDownloadCallback, nullptr);
}

void downloadManagerJobPause(uint64_t id) {
    downloadThread->jobPause(id);
}

void downloadManagerJobResume(uint64_t id) {
    downloadThread->jobResume(id);
}

void downloadManagerJobCancel(uint64_t id) {
    downloadThread->jobCancel(id);
}

std::vector<DownloadJobInfo> downloadManagerJobList() {
    return downloadThread->jobList();
}

}  // namespace livi
