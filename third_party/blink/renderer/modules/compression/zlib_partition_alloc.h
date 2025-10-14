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

#ifndef THIRD_PARTY_BLINK_RENDERER_MODULES_COMPRESSION_ZLIB_PARTITION_ALLOC_H_
#define THIRD_PARTY_BLINK_RENDERER_MODULES_COMPRESSION_ZLIB_PARTITION_ALLOC_H_

#include "third_party/blink/renderer/platform/wtf/allocator/allocator.h"
#include "third_party/zlib/zlib.h"

namespace blink {

// Use partition alloc for zlib allocations.
class ZlibPartitionAlloc {
    STATIC_ONLY(ZlibPartitionAlloc);

public:
    static void Configure(z_stream* s);

private:
    static void* Alloc(void*, uint32_t items, uint32_t size);

    static void Free(void*, void*);
};

} // namespace blink

#endif // THIRD_PARTY_BLINK_RENDERER_MODULES_COMPRESSION_ZLIB_PARTITION_ALLOC_H_
