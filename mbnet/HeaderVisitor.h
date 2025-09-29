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


#ifndef net_HeaderVisitor_h
#define net_HeaderVisitor_h

#include "third_party/blink/public/platform/web_http_header_visitor.h"
#include "third_party/blink/renderer/platform/wtf/text/string_builder.h"
#include "third_party/libcurl/include/curl/curl.h"

namespace net {

class HeaderVisitor : public blink::WebHTTPHeaderVisitor {
public:
    explicit HeaderVisitor(curl_slist** headers) : m_headers(headers) {}

    virtual void VisitHeader(const blink::WebString& webName, const blink::WebString& webValue) override
    {
        WTF::String value = webValue;
        WTF::StringBuilder headerString;
        headerString.Append(webName);
        if (value.IsNull() || value.empty())
            // Insert the ; to tell curl that this header has an empty value.
            headerString.Append(";");
        else {
            headerString.Append(": ");
            headerString.Append(value);
        }
        
        *m_headers = curl_slist_append(*m_headers, headerString.ReleaseString().Utf8().c_str());
    }

    curl_slist* headers() { return*m_headers; }
private:
    curl_slist** m_headers;
};
}

#endif