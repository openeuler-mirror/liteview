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

#include "third_party/blink/renderer/modules/compression/zlib_partition_alloc.h"
#include "third_party/blink/renderer/platform/wtf/allocator/partitions.h"

namespace blink {

void ZlibPartitionAlloc::Configure(z_stream* stream)
{
    stream->zalloc = Alloc;
    stream->zfree = Free;
}

void* ZlibPartitionAlloc::Alloc(void*, uint32_t items, uint32_t size)
{
    // BufferMalloc is safer than FastMalloc when handling untrusted data.
    return WTF::Partitions::BufferMalloc(items * size, "zlib");
}

void ZlibPartitionAlloc::Free(void*, void* address)
{
    WTF::Partitions::BufferFree(address);
}

} // namespace blink
