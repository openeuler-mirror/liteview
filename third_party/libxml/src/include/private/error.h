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

#ifndef XML_ERROR_H_PRIVATE__
#define XML_ERROR_H_PRIVATE__

#include <libxml/xmlerror.h>
#ifdef _WIN32
#include "third_party/libxml/win32/include/libxml/xmlversion.h"
#else
#include <libxml/xmlversion.h>
#endif

void __xmlRaiseError(xmlStructuredErrorFunc schannel, xmlGenericErrorFunc channel, void* data, void* ctx, void* nod, int domain, int code, xmlErrorLevel level,
    const char* file, int line, const char* str1, const char* str2, const char* str3, int int1, int col, const char* msg, ...) LIBXML_ATTR_FORMAT(16, 17);
void __xmlSimpleError(int domain, int code, xmlNodePtr node, const char* msg, const char* extra) LIBXML_ATTR_FORMAT(4, 0);
void xmlGenericErrorDefaultFunc(void* ctx, const char* msg, ...) LIBXML_ATTR_FORMAT(2, 3);

#endif /* XML_ERROR_H_PRIVATE__ */
