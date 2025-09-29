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


#include "net/http/http_response_headers.h"

namespace net {

HttpResponseHeaders::~HttpResponseHeaders() = default;

bool HttpResponseHeaders::GetNormalizedHeader(base::StringPiece name, std::string* value) const
{
    //   // If you hit this assertion, please use EnumerateHeader instead!
    //   DCHECK(!HttpUtil::IsNonCoalescingHeader(name));
    //
    //   value->clear();
    //
    //   bool found = false;
    //   size_t i = 0;
    //   while (i < parsed_.size()) {
    //     i = FindHeader(i, name);
    //     if (i == std::string::npos)
    //       break;
    //
    //     if (found)
    //       value->append(", ");
    //
    //     found = true;
    //
    //     std::string::const_iterator value_begin = parsed_[i].value_begin;
    //     std::string::const_iterator value_end = parsed_[i].value_end;
    //     while (++i < parsed_.size() && parsed_[i].is_continuation())
    //       value_end = parsed_[i].value_end;
    //     value->append(value_begin, value_end);
    //   }
    //
    //   return found;
    *(int*)1 = 1;
    return false;
}

}