// Copyright 2012 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef BASE_MESSAGE_LOOP_MESSAGE_PUMP_OHOS_H_
#define BASE_MESSAGE_LOOP_MESSAGE_PUMP_OHOS_H_

#include <memory>

#include "base/base_export.h"
#include "base/memory/raw_ptr.h"
#include "base/message_loop/message_pump.h"
#include "base/message_loop/watchable_io_message_pump_posix.h"

namespace base {

// This class implements a base MessagePump needed for TYPE_UI MessageLoops on
// platforms using ohos.
class BASE_EXPORT MessagePumpOhos : public MessagePump, public WatchableIOMessagePumpPosix {
public:
    MessagePumpOhos();

    MessagePumpOhos(const MessagePumpOhos&) = delete;
    MessagePumpOhos& operator=(const MessagePumpOhos&) = delete;

    ~MessagePumpOhos() override;

    class FdWatchController : public FdWatchControllerInterface {
    public:
        explicit FdWatchController(const Location& from_here);

        FdWatchController(const FdWatchController&) = delete;
        FdWatchController& operator=(const FdWatchController&) = delete;

        ~FdWatchController() override;

        // FdWatchControllerInterface:
        bool StopWatchingFileDescriptor() override;
    };

    bool WatchFileDescriptor(int fd, bool persistent, int mode, FdWatchController* controller, FdWatcher* delegate);

    // Overridden from MessagePump:
    void Run(Delegate* delegate) override;
    void Quit() override;
    void ScheduleWork() override;
    void ScheduleDelayedWork(const Delegate::NextWorkInfo& next_work_info) override;
private:
    bool should_quit_ = false;
};

} // namespace base

#endif // BASE_MESSAGE_LOOP_MESSAGE_PUMP_OHOS_H_
