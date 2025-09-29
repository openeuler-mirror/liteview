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

#ifndef XML_ENC_H_PRIVATE__
#define XML_ENC_H_PRIVATE__

#include <libxml/encoding.h>
#include <libxml/tree.h>

int xmlCharEncFirstLineInput(xmlParserInputBufferPtr input, int len);
int xmlCharEncInput(xmlParserInputBufferPtr input, int flush);
int xmlCharEncOutput(xmlOutputBufferPtr output, int init);

#endif /* XML_ENC_H_PRIVATE__ */
