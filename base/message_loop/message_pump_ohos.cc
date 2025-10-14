// Copyright 2012 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/message_loop/message_pump_ohos.h"

#include <fcntl.h>
#include <math.h>

#include "base/logging.h"
#include "base/memory/raw_ptr.h"
#include "base/notreached.h"
#include "W:/opencode/OpenHarmony-v3.1-Release/foundation/graphic/ui/interfaces/innerkits/common/task_manager.h"

namespace base {

MessagePumpOhos::MessagePumpOhos()
{
    
}

MessagePumpOhos::~MessagePumpOhos()
{

}

void MessagePumpOhos::Run(Delegate* delegate)
{
    for (;;) {
        if (should_quit_)
            break;

        OHOS::TaskManager::GetInstance()->TaskHandler();
        usleep(1000 * 10); /* 1000 * 10: Just to let the system breathe */
    }
}

void MessagePumpOhos::Quit()
{
    should_quit_ = true;
}

void MessagePumpOhos::ScheduleWork()
{
    OHOS::TaskManager::GetInstance()->TaskHandler();
}

void MessagePumpOhos::ScheduleDelayedWork(const Delegate::NextWorkInfo& next_work_info)
{
    // We need to wake up the loop in case the poll timeout needs to be
    // adjusted.  This will cause us to try to do work, but that's OK.
    ScheduleWork();
}

bool MessagePumpOhos::WatchFileDescriptor(int fd, bool persistent, int mode, FdWatchController* controller, FdWatcher* delegate)
{
    printf("MessagePumpOhos::WatchFileDescriptor fail\n");
    return true;
}

//////////////////////////////////////////////////////////////////////////

MessagePumpOhos::FdWatchController::FdWatchController(const Location& from_here)
    : FdWatchControllerInterface(from_here)
{
}

MessagePumpOhos::FdWatchController::~FdWatchController()
{
}

bool MessagePumpOhos::FdWatchController::StopWatchingFileDescriptor()
{
    printf("MessagePumpOhos::FdWatchController::StopWatchingFileDescriptor fail\n");
    return false;
}

} // namespace base
