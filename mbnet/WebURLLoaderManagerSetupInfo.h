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


#ifndef net_WebURLLoaderManagerSetupInfo_h
#define net_WebURLLoaderManagerSetupInfo_h

#include "third_party/libcurl/include/curl/curl.h"

namespace mbnet {

struct FlattenHTTPBodyElement;

struct SetupDataInfo {
    CURLoption sizeOption;
    curl_off_t size;
    bool islongLong;
    bool chunkedTransfer;
    std::vector<FlattenHTTPBodyElement*> flattenElements;

    ~SetupDataInfo()
    {

    }
};

struct SetupInfoBase {
    SetupDataInfo* data;

    SetupInfoBase() { data = nullptr; }

    ~SetupInfoBase()
    {
        if (data)
            delete data;
    }
};

struct SetupPutInfo : public SetupInfoBase {
};

struct SetupPostInfo : public SetupInfoBase {
};

struct SetupHttpMethodInfo {
    SetupHttpMethodInfo()
    {
        put = nullptr;
        post = nullptr;
    }

    ~SetupHttpMethodInfo()
    {
        if (put)
            delete put;
        if (post)
            delete post;
    }
    SetupPutInfo* put;
    SetupPostInfo* post;
    //SetupDeleteInfo* del;
};

}

#endif // net_WebURLLoaderManagerSetupInfo_h