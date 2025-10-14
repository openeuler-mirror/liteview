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


#ifndef content_browser_WebFrameMain_h
#define content_browser_WebFrameMain_h

#include <string>
#include <vector>
#include "third_party/blink/public/mojom/page/page_visibility_state.mojom-blink-forward.h"

namespace blink {
class WebLocalFrame;
}

namespace content {

class WebFrameMain {
public:
    explicit WebFrameMain(intptr_t frameId, intptr_t parentFrameId, bool m_isTop);

    static void destroy(intptr_t frameId);
    static WebFrameMain* fromFrameId(intptr_t frameId);

    static intptr_t getTopFrameId(intptr_t frameId);
    static intptr_t getParentFrameId(intptr_t frameId);
    static std::string getUrl(intptr_t frameId);
    static std::string getName(intptr_t frameId);
    static blink::mojom::blink::PageVisibilityState getPageVisibilityState(intptr_t frameId);
    static std::vector<WebFrameMain*> getChildrenFrames(intptr_t frameId); // 直系后代
    static std::vector<WebFrameMain*> getFramesInSubtree(intptr_t frameId); // 所有后代，包括自身
    
    // 本函数在渲染进程调用--
    static void updataFrameStateOnRenderProcess(blink::WebLocalFrame* frame);
    static void updataHiddenOnRenderProcess(blink::WebLocalFrame* frame, bool isHidden);
    //===

public:
    friend struct WebFrameMainIdMgr;
    ~WebFrameMain();
    bool m_isTop = false;
    intptr_t m_frameId = 0;
    intptr_t m_parentFrameId = 0;

    std::string m_url;
    std::string m_name;
    blink::mojom::blink::PageVisibilityState m_pageVisibilityState;

};

}

#endif // content_browser_WebFrameMain_h