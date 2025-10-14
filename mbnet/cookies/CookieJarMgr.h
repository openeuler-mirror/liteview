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


#ifndef net_CookieJarMgr_h
#define net_CookieJarMgr_h

#include <string>
#include <map>

namespace mbnet {

class WebCookieJarImpl;

class CookieJarMgr {
public:
    static CookieJarMgr* getInst()
    {
        if (!m_inst)
            m_inst = new CookieJarMgr();
        return m_inst;
    }

    WebCookieJarImpl* createOrGet(const std::string& fullPath);

private:
    static CookieJarMgr* m_inst;
    std::map<std::string, WebCookieJarImpl*> m_pathToCookies;
};

}

#endif // net_CookieJarMgr_h