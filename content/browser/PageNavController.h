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


#ifndef content_browser_PageNavController_h
#define content_browser_PageNavController_h

#include "third_party/blink/public/web/web_history_item.h"
#include "third_party/blink/public/web/web_history_commit_type.h"
#include "third_party/blink/public/common/tokens/tokens.h"
#include "third_party/blink/renderer/platform/heap/garbage_collected.h"
#include "third_party/blink/renderer/platform/heap/member.h"
#include "third_party/blink/renderer/platform/heap/collection_support/heap_vector.h"

namespace blink {
class WebLocalFrame;
class WebFrame;
class WebNavigationControl;
}

namespace content {

class WebPageImpl;
class HistoryEntry;
class MbWebView;

class PageNavController : public blink::GarbageCollected<PageNavController> {
public:
    PageNavController(MbWebView* page);
    ~PageNavController();

    int historyBackListCount();
    int historyForwardListCount();
    void navigateBackForwardSoon(int offset);
    void navigateToIndex(int index);

    void insertOrReplaceEntry(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, blink::WebHistoryCommitType type, bool isSameDocument);
    blink::WebHistoryItem historyItemForNewChildFrame(blink::WebFrame* frame);

    int getCurrentOffset() const { return m_currentOffset; }
    void navigate(int offset);

    void Trace(cppgc::Visitor*) const;

private:
    struct FrameHistoryItem : public GarbageCollected<FrameHistoryItem> {
        FrameHistoryItem(const blink::FrameToken& name, const blink::WebHistoryItem& item)
        {
            uniqueName = name;
            copyHistoryItem(item);
        }

        FrameHistoryItem(const FrameHistoryItem& other)
        {
            uniqueName = other.uniqueName;
            isSameDocument = other.isSameDocument;
            copyHistoryItem(other.historyItem);
        }

        ~FrameHistoryItem()
        {

        }
        static void loadFromHistoryItem(MbWebView* page, PageNavController::FrameHistoryItem* curItem, PageNavController::FrameHistoryItem* newItem);

        void copyHistoryItem(const blink::WebHistoryItem& item); // 如果直接用WebHistoryItem，会导致GC无法回收

        void Trace(cppgc::Visitor*) const;

        blink::FrameToken uniqueName;
        blink::WebHistoryItem historyItem;
        bool isSameDocument;
    };

    struct AllFrameHistoryItemSet : public blink::GarbageCollected<AllFrameHistoryItemSet> {
        void insertOrReplaceEntry(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, blink::WebHistoryCommitType type, bool isSameDocument);
        void clearRemovedFrame(const blink::WebLocalFrame* frame);

        ~AllFrameHistoryItemSet();

        AllFrameHistoryItemSet* clone() const;

        void Trace(cppgc::Visitor*) const;

        blink::HeapVector<blink::Member<FrameHistoryItem>> m_frameHistoryItems;
        //std::vector<FrameHistoryItem*> m_frameHistoryItems;
    };

    bool findEntryImpl(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, const AllFrameHistoryItemSet& itemSet) const;
    int findEntry(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item) const;
    static bool shouldDoSameDocumentNavigationTo(const FrameHistoryItem* curItem, const FrameHistoryItem* otherItem);
    
private:
    void onStandardCommit(blink::WebLocalFrame* frame, const blink::WebHistoryItem& item, blink::WebHistoryCommitType type, bool isSameDocument);

    MbWebView* m_page;

    //std::vector<AllFrameHistoryItemSet*> m_frameHistoryStates;
    blink::HeapVector<blink::Member<AllFrameHistoryItemSet>> m_frameHistoryStates;

    int m_currentOffset;
    bool m_protectReentryBackForwardCommit; // 有sub frame的时候，有一种情况会走N次BackForwardCommit
};

}

#endif // content_browser_PageNavController_h