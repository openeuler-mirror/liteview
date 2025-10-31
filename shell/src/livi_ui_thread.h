#ifndef __livi_ui_thread_h__
#define __livi_ui_thread_h__

#include "utils/taskqueue.h"

namespace livi {

class UiThreadImpl;

class UiThread {
public:
    static UiThread &getInstance();

    UiThread(const UiThread &) = delete;
    UiThread &operator=(const UiThread &) = delete;

    UiThread();
    ~UiThread();

    void attach();
    void detach();
    TaskQueue *getTaskQueue();

private:
    UiThreadImpl *impl;
};

}  // namespace livi

#endif