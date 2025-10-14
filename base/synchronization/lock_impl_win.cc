// Copyright 2011 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/synchronization/lock_impl.h"

#include "base/debug/activity_tracker.h"

#include <windows.h>
#include "patch_code/sync_xp.h" // SUPPORT_XP_CODE

namespace base {
namespace internal {

void LockImpl::Lock()
{
    // The ScopedLockAcquireActivity in LockInternalWithTracking() (not inlined
    // here because of circular includes) is relatively expensive and so its
    // actions can become significant due to the very large number of locks that
    // tend to be used throughout the build. It is also not needed unless the lock
    // is contended.
    //
    // To avoid this cost in the vast majority of the calls, simply "try" the lock
    // first and only do the (tracked) blocking call if that fails. |Try()| is
    // cheap on platforms with futex-type locks, as it doesn't call into the
    // kernel.
    if (LIKELY(Try()))
        return;

    LockInternalWithTracking();
}

#if BUILDFLAG(IS_WIN)
bool LockImpl::Try()
{
    return !!::TryAcquireSRWLockExclusiveXp(reinterpret_cast<PSRWLOCK>(&native_handle_));
}

void LockImpl::Unlock()
{
    ::ReleaseSRWLockExclusiveXp(reinterpret_cast<PSRWLOCK>(&native_handle_));
}

#elif BUILDFLAG(IS_POSIX) || BUILDFLAG(IS_FUCHSIA)

#if DCHECK_IS_ON()
BASE_EXPORT void dcheck_trylock_result(int rv);
BASE_EXPORT void dcheck_unlock_result(int rv);
#endif

bool LockImpl::Try()
{
    int rv = pthread_mutex_trylock(&native_handle_);
#if DCHECK_IS_ON()
    dcheck_trylock_result(rv);
#endif
    return rv == 0;
}

void LockImpl::Unlock()
{
    [[maybe_unused]] int rv = pthread_mutex_unlock(&native_handle_);
#if DCHECK_IS_ON()
    dcheck_unlock_result(rv);
#endif
}
#endif

LockImpl::LockImpl()
    : native_handle_(SRWLOCK_INIT)
{
}

LockImpl::~LockImpl() = default;

void LockImpl::LockInternalWithTracking()
{
    base::debug::ScopedLockAcquireActivity lock_activity(this);
    ::AcquireSRWLockExclusiveXp(reinterpret_cast<PSRWLOCK>(&native_handle_));
}

} // namespace internal
} // namespace base
