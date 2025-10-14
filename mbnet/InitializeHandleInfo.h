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


#ifndef net_InitializeHandleInfo_h
#define net_InitializeHandleInfo_h

#include "mbnet/ProxyType.h"
#include "mbnet/PageNetExtraData.h"
#include "third_party/libcurl/include/curl/curl.h"
#include "base/memory/scoped_refptr.h"
#include <string>

namespace mbnet {

struct SetupHttpMethodInfo;
    
struct InitializeHandleInfo {
    std::string url;
    std::string method;
    curl_slist* headers;
    scoped_refptr<PageNetExtraData> pageNetExtraData;
    std::string proxy;
    std::string proxyUserNamePassword;

    std::string range;
    std::string wkeNetInterface;
    ProxyType proxyType;
    SetupHttpMethodInfo* methodInfo;

    InitializeHandleInfo() {
        methodInfo = nullptr;
    }

    ~InitializeHandleInfo();
};

}

#endif // net_InitializeHandleInfo_h