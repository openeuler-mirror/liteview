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

#ifndef HDR_TESTS_H
#define HDR_TESTS_H

/* These are functions used in tests and are not intended for normal usage. */

#include <hdr/hdr_histogram.h>

#ifdef __cplusplus
extern "C" {
#endif

int32_t counts_index_for(const struct hdr_histogram* h, int64_t value);
int hdr_encode_compressed(struct hdr_histogram* h, uint8_t** compressed_histogram, size_t* compressed_len);
int hdr_decode_compressed(uint8_t* buffer, size_t length, struct hdr_histogram** histogram);
void hdr_base64_decode_block(const char* input, uint8_t* output);
void hdr_base64_encode_block(const uint8_t* input, char* output);

#ifdef __cplusplus
}
#endif

#endif
