// Copyright 2020 the V8 project authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "src/heap/cppgc/heap-object-header.h"

#include "include/cppgc/internal/api-constants.h"
#include "src/base/macros.h"
#include "src/base/sanitizer/asan.h"
#include "src/heap/cppgc/gc-info-table.h"
#include "src/heap/cppgc/heap-base.h"
#include "src/heap/cppgc/heap-page.h"

extern "C" void __stdcall OutputDebugStringA(const char* lpOutputString);

namespace cppgc {
namespace internal {

static_assert((kAllocationGranularity % sizeof(HeapObjectHeader)) == 0);

// static
HeapObjectHeader& HeapObjectHeader::FromObject(void* object)
{
    return *reinterpret_cast<HeapObjectHeader*>(static_cast<Address>(object) - sizeof(HeapObjectHeader));
}

// static
const HeapObjectHeader& HeapObjectHeader::FromObject(const void* object)
{
    return *reinterpret_cast<const HeapObjectHeader*>(static_cast<ConstAddress>(object) - sizeof(HeapObjectHeader));
}

HeapObjectHeader::HeapObjectHeader(size_t size, GCInfoIndex gc_info_index)
{
#if defined(V8_TARGET_ARCH_64_BIT) && !defined(CPPGC_CAGED_HEAP)
    USE(padding_);
#endif // defined(V8_TARGET_ARCH_64_BIT) && !defined(CPPGC_CAGED_HEAP)
    DCHECK_LT(gc_info_index, GCInfoTable::kMaxIndex);
    DCHECK_EQ(0u, size & (sizeof(HeapObjectHeader) - 1));
    DCHECK_GE(kMaxSize, size);
    encoded_low_ = EncodeSize(size);
    // Objects may get published to the marker without any other synchronization
    // (e.g., write barrier) in which case the in-construction bit is read
    // concurrently which requires reading encoded_high_ atomically. It is ok if
    // this write is not observed by the marker, since the sweeper  sets the
    // in-construction bit to 0 and we can rely on that to guarantee a correct
    // answer when checking if objects are in-construction.
    v8::base::AsAtomicPtr(&encoded_high_)->store(GCInfoIndexField::encode(gc_info_index), std::memory_order_relaxed);
    DCHECK(IsInConstruction());
#ifdef DEBUG
    CheckApiConstants();
#endif // DEBUG
}

Address HeapObjectHeader::ObjectStart() const
{
    return reinterpret_cast<Address>(const_cast<HeapObjectHeader*>(this)) + sizeof(HeapObjectHeader);
}

void HeapObjectHeader::CheckApiConstants()
{
    static_assert(api_constants::kFullyConstructedBitMask == FullyConstructedField::kMask);
    static_assert(api_constants::kFullyConstructedBitFieldOffsetFromPayload == (sizeof(encoded_high_) + sizeof(encoded_low_)));
}

void HeapObjectHeader::Finalize()
{
#ifdef V8_USE_ADDRESS_SANITIZER
    const size_t size = IsLargeObject() ? LargePage::From(BasePage::FromPayload(this))->ObjectSize() : ObjectSize();
    ASAN_UNPOISON_MEMORY_REGION(ObjectStart(), size);
#endif // V8_USE_ADDRESS_SANITIZER
    const GCInfo& gc_info = GlobalGCInfoTable::GCInfoFromIndex(GetGCInfoIndex());
    if (gc_info.finalize) {
        gc_info.finalize(ObjectStart());
    }
}

HeapObjectName HeapObjectHeader::GetName() const
{
    const GCInfo& gc_info = GlobalGCInfoTable::GCInfoFromIndex(GetGCInfoIndex());
    return gc_info.name(ObjectStart(), BasePage::FromPayload(this)->heap().name_of_unnamed_object());
}

} // namespace internal
} // namespace cppgc
