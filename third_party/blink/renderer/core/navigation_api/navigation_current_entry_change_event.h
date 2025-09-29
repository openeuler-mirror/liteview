//
// Copyright (c) 2025 Institute of Software, Chinese Academy of Sciences (ISCAS)
// LiteView is licensed under Mulan PSL v2.
// You can use this software according to the terms and conditions of the Mulan PSL v2.
// You may obtain a copy of Mulan PSL v2 at:
//          http://license.coscl.org.cn/MulanPSL2
// THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
// EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
// MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
// See the Mulan PSL v2 for more details.
//

#ifndef THIRD_PARTY_BLINK_RENDERER_CORE_NAVIGATION_API_NAVIGATION_CURRENT_ENTRY_CHANGE_EVENT_H_
#define THIRD_PARTY_BLINK_RENDERER_CORE_NAVIGATION_API_NAVIGATION_CURRENT_ENTRY_CHANGE_EVENT_H_

#include "third_party/blink/renderer/core/dom/events/event.h"
#include "third_party/blink/renderer/platform/heap/member.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"

namespace blink {
class NavigationCurrentEntryChangeEventInit;
class NavigationHistoryEntry;

class NavigationCurrentEntryChangeEvent final : public Event {
    DEFINE_WRAPPERTYPEINFO();

public:
    static NavigationCurrentEntryChangeEvent* Create(const AtomicString& type, NavigationCurrentEntryChangeEventInit* init)
    {
        return MakeGarbageCollected<NavigationCurrentEntryChangeEvent>(type, init);
    }

    NavigationCurrentEntryChangeEvent(const AtomicString& type, NavigationCurrentEntryChangeEventInit* init);

    String navigationType()
    {
        return navigation_type_;
    }
    NavigationHistoryEntry* from()
    {
        return from_;
    }

    const AtomicString& InterfaceName() const final;
    void Trace(Visitor* visitor) const final;

private:
    String navigation_type_;
    Member<NavigationHistoryEntry> from_;
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_CORE_NAVIGATION_API_NAVIGATION_CURRENT_ENTRY_CHANGE_EVENT_H_
