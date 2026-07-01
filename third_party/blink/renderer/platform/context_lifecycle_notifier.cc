// Copyright 2021 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "third_party/blink/renderer/platform/context_lifecycle_notifier.h"

#include "third_party/blink/renderer/platform/bindings/script_forbidden_scope.h"
#include "third_party/blink/renderer/platform/context_lifecycle_observer.h"

namespace blink {

ContextLifecycleNotifier::~ContextLifecycleNotifier()
{
    // `NotifyContextDestroyed()` must be called prior to destruction.
    DCHECK(context_destroyed_);
}

bool ContextLifecycleNotifier::IsContextDestroyed() const
{
    return context_destroyed_;
}

void ContextLifecycleNotifier::AddContextLifecycleObserver(ContextLifecycleObserver* observer)
{
    observers_.AddObserver(observer);
}

void ContextLifecycleNotifier::RemoveContextLifecycleObserver(ContextLifecycleObserver* observer)
{
    DCHECK(observers_.HasObserver(observer));
    observers_.RemoveObserver(observer);
}

void ContextLifecycleNotifier::NotifyContextDestroyed()
{
    context_destroyed_ = true;

    ScriptForbiddenScope forbid_script;
    observers_.ForEachObserver([](ContextLifecycleObserver* observer) {
        // todo(mb): release 版本偶现, 这里是看环境堆栈改的
        // cli.im 验证码登录的时候, 这里会崩溃, 原因是 observer 的 notifier 是空(0), 但从设计上来看是不可能的, 需要找到根本原因
        if (observer->GetContextLifecycleNotifier()) {
            observer->NotifyContextDestroyed();
        }
    });
    observers_.Clear();
}

void ContextLifecycleNotifier::Trace(Visitor* visitor) const
{
    visitor->Trace(observers_);
}

} // namespace blink
