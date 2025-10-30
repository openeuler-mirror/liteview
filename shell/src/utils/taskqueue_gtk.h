#ifndef __taskqueue_gtk_h__
#define __taskqueue_gtk_h__

#include <glib.h>

#include "taskqueue.h"

namespace livi {

class TaskQueueGtk : public TaskQueue {
public:
    ~TaskQueueGtk() {
        detach();
    }

    void attach() {
        detach();
        attachThread();
        channel_ = g_io_channel_unix_new(getFd());
        g_io_add_watch(channel_, G_IO_IN, &TaskQueueGtk::gtkCallback, this);
    }

    void detach() {
        if (channel_) {
            detachThread();
            g_io_channel_unref(channel_);
            channel_ = nullptr;
        }
    }

    static int gtkCallback(GIOChannel *channel, GIOCondition condition, gpointer data) {
        TaskQueueGtk *taskQueue = static_cast<TaskQueueGtk *>(data);
        taskQueue->execute();
        return TRUE;
    }

private:
    GIOChannel *channel_ = nullptr;
};

}  // namespace livi

#endif
