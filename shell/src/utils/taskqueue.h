#ifndef __task_queue_h__
#define __task_queue_h__

#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

namespace livi {

class TaskQueue {
public:
    typedef std::function<void(void)> TaskCallback;

    TaskQueue();
    ~TaskQueue();
    TaskQueue(const TaskQueue &taskQueue) = delete;
    TaskQueue &operator=(const TaskQueue &taskQueue) = delete;

    void attachThread() {
        m_execute_thread_id = std::this_thread::get_id();
    }

    void detachThread() {
        m_execute_thread_id = std::thread::id{};
    }

    bool inExecuteThread() {
        return std::this_thread::get_id() == m_execute_thread_id;
    }

    template <typename T>
    void post(T &&task) {
        checkAttached();
        std::lock_guard<std::mutex> lock_guard(m_mutex);
        increaseResourceCounter();
        m_queue.emplace(std::forward<T>(task));
    }

    template <typename T>
    void call(const T &task) {
        checkAttached();
        if (inExecuteThread()) {
            // if in execute thread, just call it
            task();
        } else {
            // use std::semaphore will be more efficient, but is not available until c++20
            // we also can use sem_init/sem_take/sem_post in <sem.h> instead of std::semaphore
            // but it's platform-specific I don't want to use it in this header
            bool done = false;
            std::mutex condition_mutex;
            std::condition_variable condition_variable;
            post([&]() {
                task();
                {
                    std::lock_guard<std::mutex> lock_guard(condition_mutex);
                    done = true;
                }
                condition_variable.notify_one();
            });
            std::unique_lock<std::mutex> unique_lock(condition_mutex);
            condition_variable.wait(unique_lock, [&done]() { return done; });
        }
    }

protected:
    int getFd() {
        return m_fd;
    }

    void execute();

private:
    void checkAttached() {
        if (m_execute_thread_id == std::thread::id{}) {
            fprintf(stderr, "TaskQueue(%p) is not attached to any thread, please call attachThread() first\n", this);
            std::abort();
        }
    }

    size_t readResourceCounter();
    void increaseResourceCounter();

    std::thread::id m_execute_thread_id{};
    int m_fd{};
    std::mutex m_mutex;
    std::queue<TaskCallback> m_queue;
};

};  // namespace livi

#endif
