#ifndef __livi_utils_taskqueue_ev_h__
#define __livi_utils_taskqueue_ev_h__

#include <ev.h>

#include "taskqueue.h"

namespace livi {

class TaskQueueLibev : public TaskQueue {
public:
    TaskQueueLibev(struct ev_loop *loop = nullptr) {
        m_watcher.taskQueue = this;
        m_loop = nullptr;
        ev_init((ev_io *)&m_watcher, io_callback);
        ev_io_set((ev_io *)&m_watcher, getFd(), EV_READ);
        attach(loop);
    }

    ~TaskQueueLibev() {
        attach(nullptr);
    }

    void detach() {
        if (m_loop) {
            detachThread();
            ev_io_stop(m_loop, &m_watcher);
        }
    }

    void attach(struct ev_loop *loop) {
        detach();
        m_loop = loop;
        if (m_loop) {
            attachThread();
            ev_io_start(m_loop, &m_watcher);
        }
    }

private:
    struct WatcherData : ev_io {
        TaskQueueLibev *taskQueue;
    };

    static void io_callback(struct ev_loop *loop, struct ev_io *w, int revents) {
        WatcherData *wd = (WatcherData *)w;
        wd->taskQueue->execute();
    }

    struct ev_loop *m_loop;
    WatcherData m_watcher;
};

}  // namespace livi

#endif
