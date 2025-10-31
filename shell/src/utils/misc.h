#ifndef __livi_utils_misc_h__
#define __livi_utils_misc_h__

#include <stddef.h>

#include <functional>

namespace livi {

class Defer {
public:
    template <typename F>
    Defer(F &&func) : m_func(std::forward<F>(func)) {
    }

    ~Defer() {
        if (m_func) {
            m_func();
        }
    }

    void clear() {
        m_func = nullptr;
    }

private:
    std::function<void(void)> m_func;
};

}  // namespace livi

#endif
