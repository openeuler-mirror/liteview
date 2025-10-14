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


#ifndef content_common_MojoObjGc_h
#define content_common_MojoObjGc_h

#include "mojo/public/c/system/types.h"
#include "base/synchronization/lock.h"
#include <set>

namespace content {

class MojoObjHead {
public:
    virtual void destroy() = 0;
};

class MojoObjGc {
public:

    void addReceiverObj(MojoObjHead* obj, MojoHandle handle); // 添加的都是接收端对象

private:
    void runGC();

    base::Lock m_lock;

    struct ReceiverEntry {
        MojoObjHead* obj = nullptr;
        MojoHandle handle = 0;
    };
    std::set<ReceiverEntry*> m_receiverObjs;
};


}

#endif
 