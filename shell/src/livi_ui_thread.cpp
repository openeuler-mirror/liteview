#include "livi_ui_thread.h"

#include <sys/prctl.h>

#include "utils/taskqueue_gtk.h"

namespace livi {

class UiThreadImpl : public TaskQueueGtk {};

UiThread &UiThread::getInstance() {
    static UiThread instance;
    return instance;
}

UiThread::UiThread() {
    impl = new UiThreadImpl;
}

UiThread::~UiThread() {
    delete impl;
}

void UiThread::attach() {
    // prctl(PR_SET_NAME, "UiThread", 0, 0, 0);
    impl->attach();
}

void UiThread::detach() {
    impl->detach();
}

TaskQueue *UiThread::getTaskQueue() {
    return impl;
}

}  // namespace livi
