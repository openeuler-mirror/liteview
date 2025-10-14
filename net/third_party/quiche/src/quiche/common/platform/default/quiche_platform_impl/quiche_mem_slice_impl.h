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

#ifndef QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_MEM_SLICE_IMPL_H_
#define QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_MEM_SLICE_IMPL_H_

#include "quiche/common/platform/api/quiche_export.h"
#include "quiche/common/quiche_buffer_allocator.h"
#include "quiche/common/simple_buffer_allocator.h"

namespace quiche {

class QUICHE_EXPORT_PRIVATE QuicheMemSliceImpl {
public:
    QuicheMemSliceImpl() = default;

    explicit QuicheMemSliceImpl(QuicheBuffer buffer)
        : buffer_(std::move(buffer))
    {
    }

    QuicheMemSliceImpl(std::unique_ptr<char[]> buffer, size_t length)
        : buffer_(QuicheBuffer(QuicheUniqueBufferPtr(buffer.release(), QuicheBufferDeleter(SimpleBufferAllocator::Get())), length))
    {
    }

    QuicheMemSliceImpl(const QuicheMemSliceImpl& other) = delete;
    QuicheMemSliceImpl& operator=(const QuicheMemSliceImpl& other) = delete;

    // Move constructors. |other| will not hold a reference to the data buffer
    // after this call completes.
    QuicheMemSliceImpl(QuicheMemSliceImpl&& other) = default;
    QuicheMemSliceImpl& operator=(QuicheMemSliceImpl&& other) = default;

    ~QuicheMemSliceImpl() = default;

    void Reset() { buffer_ = QuicheBuffer(); }

    const char* data() const { return buffer_.data(); }
    size_t length() const { return buffer_.size(); }
    bool empty() const { return buffer_.empty(); }

private:
    QuicheBuffer buffer_;
};

} // namespace quiche

#endif // QUICHE_COMMON_PLATFORM_DEFAULT_QUICHE_PLATFORM_IMPL_QUICHE_MEM_SLICE_IMPL_H_
