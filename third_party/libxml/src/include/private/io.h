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

#ifndef XML_IO_H_PRIVATE__
#define XML_IO_H_PRIVATE__

#include <libxml/encoding.h>
#include <libxml/tree.h>
#ifdef _WIN32
#include "third_party/libxml/win32/include/libxml/xmlversion.h"
#else
#include <libxml/xmlversion.h>
#endif

void __xmlIOErr(int domain, int code, const char* extra);
void __xmlLoaderErr(void* ctx, const char* msg, const char* filename) LIBXML_ATTR_FORMAT(2, 0);
int xmlInputReadCallbackNop(void* context, char* buffer, int len);

#ifdef LIBXML_OUTPUT_ENABLED
xmlOutputBufferPtr xmlAllocOutputBufferInternal(xmlCharEncodingHandlerPtr encoder);
#endif

#endif /* XML_IO_H_PRIVATE__ */
