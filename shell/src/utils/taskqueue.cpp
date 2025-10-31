#include "taskqueue.h"

#include <assert.h>
#include <sys/eventfd.h>
#include <unistd.h>

namespace livi {

TaskQueue::TaskQueue() {
    m_fd = eventfd(0, EFD_NONBLOCK);
}

TaskQueue::~TaskQueue() {
    close(m_fd);
}

size_t TaskQueue::readResourceCounter() {
    uint64_t counter = 0;
    ssize_t bytes = read(m_fd, (void *)&counter, sizeof(counter));
    assert(bytes == sizeof(counter));
    return counter;
}

void TaskQueue::increaseResourceCounter() {
    uint64_t one = 1;
    ssize_t bytes = write(m_fd, &one, sizeof(one));
    assert(bytes == sizeof(one));
}

void TaskQueue::execute() {
    if (!inExecuteThread()) {
        fprintf(stderr, "%s: not in execute thread\n", __func__);
        abort();
    }

    std::lock_guard<std::mutex> lock_guard(m_mutex);
    size_t counter = readResourceCounter();
    assert(counter == m_queue.size());
    while (!m_queue.empty()) {
        TaskCallback &callback = m_queue.front();
        callback();
        m_queue.pop();
    }
}

}  // namespace livi
