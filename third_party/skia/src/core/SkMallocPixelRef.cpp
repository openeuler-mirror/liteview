/*
 * Copyright 2011 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "include/core/SkMallocPixelRef.h"

#include "include/core/SkData.h"
#include "include/core/SkImageInfo.h"
#include "include/private/SkMalloc.h"
#include <windows.h>

static bool is_valid(const SkImageInfo& info)
{
    if (info.width() < 0 || info.height() < 0 || (unsigned)info.colorType() > (unsigned)kLastEnum_SkColorType
        || (unsigned)info.alphaType() > (unsigned)kLastEnum_SkAlphaType) {
        return false;
    }
    return true;
}

sk_sp<SkPixelRef> SkMallocPixelRef::MakeAllocate(const SkImageInfo& info, size_t rowBytes)
{
    if (rowBytes == 0) {
        rowBytes = info.minRowBytes();
        // rowBytes can still be zero, if it overflowed (width * bytesPerPixel > size_t)
        // or if colortype is unknown
    }
    if (!is_valid(info) || !info.validRowBytes(rowBytes)) {
        return nullptr;
    }
    size_t size = info.computeByteSize(rowBytes);
    if (SkImageInfo::ByteSizeOverflowed(size)) {
        return nullptr;
    }
#if defined(SK_BUILD_FOR_FUZZER)
    if (size > 100000) {
        return nullptr;
    }
#endif
    void* addr = sk_calloc_canfail(size);
    if (nullptr == addr) {
        return nullptr;
    }

//     struct Head {
//         uint32_t size;
//         uint32_t magic;
//     };
//     Head* head = (Head*)sk_calloc_canfail(size + sizeof(Head) + kSizexxxxx);
//     sk_free(head);
//     head = (Head*)sk_calloc_canfail(size + sizeof(Head) + kSizexxxxx);
//     memset(head, 0xf2, size + sizeof(Head) + kSizexxxxx);
//     head->size = size;
//     head->magic = 0x11223344;
// 
//     void* addr = head + 1;
// 
//     static int s_count = 0;
//     s_count++;
//     if (5 == s_count)
//         OutputDebugStringA("");
//     char output[100] = { 0 };
//     sprintf_s(output, 99, "SkMallocPixelRef::MakeAllocate: %p %p, %d, %x\n", head, addr, size, (uintptr_t)addr + size - 4);
//     OutputDebugStringA(output);

    struct PixelRef final : public SkPixelRef {
        PixelRef(int w, int h, void* s, size_t r)
            : SkPixelRef(w, h, s, r)
        {
        }
        ~PixelRef() override
        {
            sk_free(this->pixels());
//             Head* head2 = (Head*)this->pixels();
//             head2 -= 1;
// 
//             unsigned char* ptr = (unsigned char*)head2;
//             ptr += head2->size + sizeof(Head);
//             for (size_t i = 0; i < kSizexxxxx; ++i) {
//                 if (ptr[i] != 0xf2)
//                     DebugBreak();
//             }
// 
//             char output[100] = { 0 };
//             sprintf_s(output, 99, "SkMallocPixelRef::~~~MakeAllocate: %p %p\n", head2, this->pixels());
//             OutputDebugStringA(output);
// 
//             sk_free(head2);
        }
    };
    return sk_sp<SkPixelRef>(new PixelRef(info.width(), info.height(), addr, rowBytes));
}

sk_sp<SkPixelRef> SkMallocPixelRef::MakeWithData(const SkImageInfo& info, size_t rowBytes, sk_sp<SkData> data)
{
    SkASSERT(data != nullptr);
    if (!is_valid(info)) {
        return nullptr;
    }
    // TODO: what should we return if computeByteSize returns 0?
    // - the info was empty?
    // - we overflowed computing the size?
    if ((rowBytes < info.minRowBytes()) || (data->size() < info.computeByteSize(rowBytes))) {
        return nullptr;
    }
    struct PixelRef final : public SkPixelRef {
        sk_sp<SkData> fData;
        PixelRef(int w, int h, void* s, size_t r, sk_sp<SkData> d)
            : SkPixelRef(w, h, s, r)
            , fData(std::move(d))
        {
        }
    };
    void* pixels = const_cast<void*>(data->data());
    sk_sp<SkPixelRef> pr(new PixelRef(info.width(), info.height(), pixels, rowBytes, std::move(data)));
    pr->setImmutable(); // since we were created with (immutable) data
    return pr;
}
