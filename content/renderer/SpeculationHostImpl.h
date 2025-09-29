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


#ifndef content_renderer_SpeculationHostImpl_h
#define content_renderer_SpeculationHostImpl_h

#include "gen/third_party/blink/public/mojom/speculation_rules/speculation_rules.mojom-blink.h"

namespace content {

class SpeculationHostImpl : public ::blink::mojom::blink::SpeculationHost {
public:
    SpeculationHostImpl() { }
    ~SpeculationHostImpl()
    {

    }

    void UpdateSpeculationCandidates(WTF::Vector<::blink::mojom::blink::SpeculationCandidatePtr> candidates) override
    {

    }
};

}

#endif // content_renderer_SpeculationHostImpl_h