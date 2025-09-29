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


#include "mbnet/cookies/CookieJarMgr.h"
#include "mbnet/cookies/WebCookieJarCurlImpl.h"

namespace mbnet {

CookieJarMgr* CookieJarMgr::m_inst = nullptr;

WebCookieJarImpl* CookieJarMgr::createOrGet(const std::string& fullPath)
{
    WebCookieJarImpl* cookiejar = nullptr;
    std::map<std::string, WebCookieJarImpl*>::iterator it = m_pathToCookies.find(fullPath);
    if (m_pathToCookies.end() != it)
        return it->second;

    cookiejar = WebCookieJarImpl::create(fullPath);
    m_pathToCookies.insert(std::pair<std::string, WebCookieJarImpl*>(fullPath, cookiejar));
    return cookiejar;
}
    
}