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


#ifndef net_StorageMgr_h
#define net_StorageMgr_h

#include "net/StorageDef.h"

#include "wtf/HashMap.h"
#include "wtf/text/WTFString.h"
#include "wtf/text/StringHash.h"

namespace net {

class WebStorageAreaImpl;
class WebStorageNamespaceImpl;

class StorageMgr {
public:
    static StorageMgr* getInst()
    {
        if (!m_inst)
            m_inst = new StorageMgr();
        return m_inst;
    }

    DOMStorageMap* createOrGet(const String& fullPath);

private:
    static StorageMgr* m_inst;
    HashMap<String, DOMStorageMap*> m_pathToStorageNamespace;
};

}

#endif // net_StorageMgr_h