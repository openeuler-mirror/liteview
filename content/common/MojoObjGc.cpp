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


#include "content/common/MojoObjGc.h"

namespace content {

void MojoObjGc::addReceiverObj(MojoObjHead* obj, MojoHandle handle)
{
    base::AutoLock locker(m_lock);
    ReceiverEntry* entry = new ReceiverEntry();
    entry->obj = obj;
    entry->handle = handle;
    m_receiverObjs.insert(entry);
}

void MojoObjGc::runGC()
{

}

}