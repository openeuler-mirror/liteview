#include "livi_work_thread.h"

#include <sys/prctl.h>

#include <condition_variable>
#include <mutex>
#include <thread>

namespace livi {

class WorkThreadImpl {
public:
    WorkThreadImpl() {
        bool done = false;
        std::mutex condition_mutex;
        std::condition_variable condition_variable;

        mLoop = ev_loop_new(0);
        mThread = std::thread([&]() {
            prctl(PR_SET_NAME, "WorkThread", 0, 0, 0);
            mTaskQueue.attach(mLoop);
            {
                std::lock_guard<std::mutex> lock_guard(condition_mutex);
                done = true;
            }
            condition_variable.notify_one();
            ev_run(mLoop, 0);
        });

        {
            std::unique_lock<std::mutex> unique_lock(condition_mutex);
            condition_variable.wait(unique_lock, [&]() { return done; });
        }
    }

    ~WorkThreadImpl() {
        ev_loop_destroy(mLoop);
    }

    struct ev_loop *getLoop() {
        return mLoop;
    }

    TaskQueue *getTaskQueue() {
        return &mTaskQueue;
    }

private:
    std::thread mThread;
    TaskQueueLibev mTaskQueue;
    struct ev_loop *mLoop;
};

WorkThread& WorkThread::getInstance() {
    static WorkThread* instance = nullptr;
    if (!instance)
    	instance = new WorkThread();
    return *instance;
}

WorkThread::WorkThread() {
    impl = new WorkThreadImpl;
}

WorkThread::~WorkThread() {
    delete impl;
}

struct ev_loop *WorkThread::getLoop() {
    return impl->getLoop();
}

TaskQueue *WorkThread::getTaskQueue() {
    return impl->getTaskQueue();
}

}  // namespace livi
