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

#ifndef XML_BUF_H_PRIVATE__
#define XML_BUF_H_PRIVATE__

#include <libxml/tree.h>

xmlBufPtr xmlBufCreate(void);
xmlBufPtr xmlBufCreateSize(size_t size);
xmlBufPtr xmlBufCreateStatic(void* mem, size_t size);

int xmlBufSetAllocationScheme(xmlBufPtr buf, xmlBufferAllocationScheme scheme);
int xmlBufGetAllocationScheme(xmlBufPtr buf);

void xmlBufFree(xmlBufPtr buf);
void xmlBufEmpty(xmlBufPtr buf);

/* size_t xmlBufShrink(xmlBufPtr buf, size_t len); */
int xmlBufGrow(xmlBufPtr buf, int len);
int xmlBufResize(xmlBufPtr buf, size_t len);

int xmlBufAdd(xmlBufPtr buf, const xmlChar* str, int len);
int xmlBufCat(xmlBufPtr buf, const xmlChar* str);
int xmlBufCCat(xmlBufPtr buf, const char* str);
int xmlBufWriteQuotedString(xmlBufPtr buf, const xmlChar* string);

size_t xmlBufAvail(const xmlBufPtr buf);
size_t xmlBufLength(const xmlBufPtr buf);
/* size_t xmlBufUse(const xmlBufPtr buf); */
int xmlBufIsEmpty(const xmlBufPtr buf);
int xmlBufAddLen(xmlBufPtr buf, size_t len);

/* const xmlChar * xmlBufContent(const xmlBuf *buf); */
/* const xmlChar * xmlBufEnd(xmlBufPtr buf); */

xmlChar* xmlBufDetach(xmlBufPtr buf);

size_t xmlBufDump(FILE* file, xmlBufPtr buf);

xmlBufPtr xmlBufFromBuffer(xmlBufferPtr buffer);
xmlBufferPtr xmlBufBackToBuffer(xmlBufPtr buf);
int xmlBufMergeBuffer(xmlBufPtr buf, xmlBufferPtr buffer);

int xmlBufResetInput(xmlBufPtr buf, xmlParserInputPtr input);
size_t xmlBufGetInputBase(xmlBufPtr buf, xmlParserInputPtr input);
int xmlBufSetInputBaseCur(xmlBufPtr buf, xmlParserInputPtr input, size_t base, size_t cur);

#endif /* XML_BUF_H_PRIVATE__ */
