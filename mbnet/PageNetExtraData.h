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


#ifndef mbnet_PageNetExtraData_h
#define mbnet_PageNetExtraData_h

#include "base/memory/ref_counted.h"
#include "base/files/file_path.h"
#include "mbnet/StorageDef.h"
#include <string>

typedef void CURL;
typedef void CURLSH;
typedef struct _mbProxy mbProxy;

namespace blink {
class WebStorageNamespace;
}

namespace mbnet {
    
class WebCookieJarImpl;
class WebStorageNamespaceImpl;

class PageNetExtraData : public base::RefCountedThreadSafe<PageNetExtraData> {
public:
    PageNetExtraData();
    ~PageNetExtraData();

    void setCookieJarFullPath(const std::string& fullPathUtf8);
    CURLSH* getCurlShareHandle();
    std::string getCookieJarFullPath();
    WebCookieJarImpl* getCookieJar() const { return m_cookieJar; }

    void setLocalStorageDir(const std::string& localStorageDir);
    base::FilePath getLocalStorageDir();

    void setProxy(const mbProxy* proxy);
    const mbProxy* getProxy() const;
private:
    mbProxy* m_proxy = nullptr;

    WebCookieJarImpl* m_cookieJar;
    base::FilePath m_localStotageFullPath;
};

}

#endif // net_PageCookie_h