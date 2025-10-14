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


#ifndef content_renderer_NoStatePrefetchProcessorImpl_h
#define content_renderer_NoStatePrefetchProcessorImpl_h

#include "gen/third_party/blink/public/mojom/prerender/prerender.mojom-blink.h"

namespace content {

class NoStatePrefetchProcessorImpl : public blink::mojom::blink::NoStatePrefetchProcessor {
public:
    NoStatePrefetchProcessorImpl() { }
    ~NoStatePrefetchProcessorImpl()
    {

    }

    void Start(::blink::mojom::blink::PrerenderAttributesPtr prerender_attribute) override
    {

    }

    void Cancel() override
    {

    }
};

}

#endif // content_renderer_PolicyContainerHostImpl_h