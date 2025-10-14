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


#ifndef content_browser_BackForwardCacheControllerHostImpl_h
#define content_browser_BackForwardCacheControllerHostImpl_h

#include "third_party/blink/public/mojom/frame/back_forward_cache_controller.mojom-blink.h"
#include "content/common/common.h"

namespace content {

class BackForwardCacheControllerHostImpl : public ::blink::mojom::blink::BackForwardCacheControllerHost {
    virtual void EvictFromBackForwardCache(::blink::mojom::blink::RendererEvictionReason reason) override
    {
        //printFuncName(__FUNCTION__, true, false);
    }

    virtual void DidChangeBackForwardCacheDisablingFeatures(uint64_t features_mask) override
    {
        //printFuncName(__FUNCTION__, true, false);
    }
};

}

#endif