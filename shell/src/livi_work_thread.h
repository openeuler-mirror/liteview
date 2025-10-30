#ifndef __livi_work_thread_h__
#define __livi_work_thread_h__

#include "utils/taskqueue_ev.h"

namespace livi {

class WorkThreadImpl;

class WorkThread {
public:
    static WorkThread &getInstance();

    WorkThread(const WorkThread &) = delete;
    WorkThread &operator=(const WorkThread &) = delete;

    struct ev_loop *getLoop();
    TaskQueue *getTaskQueue();

private:
    WorkThread();
    ~WorkThread();
    WorkThreadImpl *impl;
};

}  // namespace livi

#endif
