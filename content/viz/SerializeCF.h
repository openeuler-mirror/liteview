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


#ifndef content_demo_SerializeCF_h
#define content_demo_SerializeCF_h

#include "components/viz/common/quads/compositor_frame.h"
#include "third_party/skia/include/private/chromium/SkChromeRemoteGlyphCache.h"

namespace base {
class Pickle;
}

namespace rbi {

struct CompositorFrameHead {
    uint16_t version;
};

const uint32_t kDebugFlag = 0xff114325;

bool checkDebugFlag(base::PickleIterator& pickleIn);

void serializeVizCompositorFrame(const viz::CompositorFrame& frameIn, base::Pickle* pickleOut);
void deserializeVizCompositorFrame(viz::CompositorFrame* frameIn, base::PickleIterator& pickleIn);

}

namespace cc {

class TestDiscardableManager
    : public SkStrikeServer::DiscardableHandleManager
    , public SkStrikeClient::DiscardableHandleManager {
public:
    TestDiscardableManager() = default;
    ~TestDiscardableManager() override = default;

    // SkStrikeServer::DiscardableHandleManager implementation.
    SkDiscardableHandleId createHandle() override { return m_nextHandleId++; }
    bool lockHandle(SkDiscardableHandleId handle_id) override {
        CHECK_LT(handle_id, m_nextHandleId);
        return true;
    }

    // SkStrikeServer::DiscardableHandleManager::isHandleDeleted implementation.
    bool isHandleDeleted(SkDiscardableHandleId) override { return false; }

    // SkStrikeClient::DiscardableHandleManager implementation.
    bool deleteHandle(SkDiscardableHandleId handle_id) override {
        CHECK_LT(handle_id, m_nextHandleId);
        return false;
    }

    // SkStrikeClient::DiscardableHandleManager implementation.
    void notifyCacheMiss(SkStrikeClient::CacheMissType type,
        int fontSize) override {}

private:
    SkDiscardableHandleId m_nextHandleId = 1u;
};

class DisplayItemList;
class DisplayItemListTest {
public:
    static void deserializeCcDisplayItemList(::cc::DisplayItemList* out, base::PickleIterator& pickleIn);
    static void serializeCcDisplayItemList(const ::cc::DisplayItemList& in, base::Pickle* pickleOut);
};
}

#endif