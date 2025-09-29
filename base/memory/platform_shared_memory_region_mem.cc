// Copyright 2018 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "base/memory/platform_shared_memory_region.h"

#include <stddef.h>
#include <stdint.h>

#include "base/memory/direct_mem_mgr.h"
#include "base/bits.h"
#include <windows.h>

namespace base {

DirectMemMgr* DirectMemMgr::inst_ = nullptr;

namespace subtle {

// PlatformSharedMemoryRegion::PlatformSharedMemoryRegion(uintptr_t mem_handle)
// {
//     mem_handle_ = mem_handle;
// }

PlatformSharedMemoryRegion::PlatformSharedMemoryRegion(uintptr_t handle, Mode mode, size_t size, const UnguessableToken& guid)
{
    mem_handle_ = handle;
    mode_ = mode;
    size_ = size;
    guid_ = guid;
}

PlatformSharedMemoryRegion::~PlatformSharedMemoryRegion()
{
    if (mem_handle_) {
        DirectMemMgr::Get()->Free(mem_handle_);
    }
}

PlatformSharedMemoryRegion::PlatformSharedMemoryRegion(PlatformSharedMemoryRegion&& other)
{
    mem_handle_ = other.mem_handle_;
    mode_ = other.mode_;
    size_ = other.size_;
    guid_ = other.guid_;

    other.mem_handle_ = 0;
}

PlatformSharedMemoryRegion& PlatformSharedMemoryRegion::operator=(PlatformSharedMemoryRegion&& other)
{
    mem_handle_ = other.mem_handle_;
    mode_ = other.mode_;
    size_ = other.size_;
    guid_ = other.guid_;
    
    other.mem_handle_ = 0;
    return *this;
}

#if BUILDFLAG(IS_WIN)
// static
PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Take(win::ScopedHandle handle, Mode mode, size_t size, const UnguessableToken& guid)
{
//     if (!handle.is_valid())
//         return {};
// 
//     if (size == 0)
//         return {};
// 
//     if (size > static_cast<size_t>(std::numeric_limits<int>::max()))
//         return {};
// 
//     if (!IsSectionSafeToMap(handle.get()))
//         return {};
// 
//     CHECK(CheckPlatformHandlePermissionsCorrespondToMode(handle.get(), mode, size));
// 
//     return PlatformSharedMemoryRegion(std::move(handle), mode, size, guid);
    DebugBreak();

    return PlatformSharedMemoryRegion();
}
#endif

PlatformSharedMemoryHandle PlatformSharedMemoryRegion::GetPlatformHandle() const
{
#if BUILDFLAG(IS_WIN)
    return (HANDLE)(mem_handle_);
#else
    subtle::FDPair fd = { mem_handle_, 0 };
    return fd;
#endif
}

bool PlatformSharedMemoryRegion::IsValid() const
{
    return (mem_handle_ != 0);
}

PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Duplicate() const
{
    if (!IsValid())
        return {};

    CHECK_NE(mode_, Mode::kWritable) << "Duplicating a writable shared memory region is prohibited";

//     HANDLE duped_handle;
//     ProcessHandle process = GetCurrentProcess();
//     BOOL success = ::DuplicateHandle(process, handle_.get(), process, &duped_handle, 0, FALSE, DUPLICATE_SAME_ACCESS);
//     if (!success)
//         return {};
// 
//     return PlatformSharedMemoryRegion(win::ScopedHandle(duped_handle), mode_, size_, guid_);
    uintptr_t duped_handle = DirectMemMgr::Get()->Duplicate(mem_handle_);
    return PlatformSharedMemoryRegion(duped_handle, mode_, size_, guid_);
}

bool PlatformSharedMemoryRegion::ConvertToReadOnly()
{
    if (!IsValid())
        return false;

    CHECK_EQ(mode_, Mode::kWritable) << "Only writable shared memory region can be converted to read-only";

//     win::ScopedHandle handle_copy(handle_.release());
// 
//     HANDLE duped_handle;
//     ProcessHandle process = GetCurrentProcess();
//     BOOL success = ::DuplicateHandle(process, handle_copy.get(), process, &duped_handle, FILE_MAP_READ | SECTION_QUERY, FALSE, 0);
//     if (!success)
//         return false;
// 
//     handle_.Set(duped_handle);
    mode_ = Mode::kReadOnly;

    return true;
}

bool PlatformSharedMemoryRegion::ConvertToUnsafe()
{
    if (!IsValid())
        return false;

    CHECK_EQ(mode_, Mode::kWritable) << "Only writable shared memory region can be converted to unsafe";

    mode_ = Mode::kUnsafe;
    return true;
}

// static
PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Create(Mode mode, size_t size
#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
    , bool executable
#endif
)
{
    // TODO(crbug.com/210609): NaCl forces us to round up 64k here, wasting 32k
    // per mapping on average.
    static const size_t kSectionSize = 65536;
    if (size == 0)
        return {};

    // Aligning may overflow so check that the result doesn't decrease.
    size_t rounded_size = bits::AlignUp(size, kSectionSize);
    if (rounded_size < size || rounded_size > static_cast<size_t>(std::numeric_limits<int>::max()))
        return {};

    CHECK_NE(mode, Mode::kReadOnly) << "Creating a region in read-only mode will lead to this region being non-modifiable";

//     // Add an empty DACL to enforce anonymous read-only sections.
//     ACL dacl;
//     SECURITY_DESCRIPTOR sd;
//     if (!InitializeAcl(&dacl, sizeof(dacl), ACL_REVISION)) {
//         return {};
//     }
//     if (!InitializeSecurityDescriptor(&sd, SECURITY_DESCRIPTOR_REVISION)) {
//         return {};
//     }
//     if (!SetSecurityDescriptorDacl(&sd, TRUE, &dacl, FALSE)) {
//         return {};
//     }
// 
//     std::u16string name;
//     if (win::GetVersion() < win::Version::WIN8_1) {
//         // Windows < 8.1 ignores DACLs on certain unnamed objects (like shared
//         // sections). So, we generate a random name when we need to enforce
//         // read-only.
//         uint64_t rand_values[4];
//         RandBytes(&rand_values, sizeof(rand_values));
//         name = ASCIIToUTF16(StringPrintf("CrSharedMem_%016llx%016llx%016llx%016llx", rand_values[0], rand_values[1], rand_values[2], rand_values[3]));
//         DCHECK(!name.empty());
//     }
// 
//     SECURITY_ATTRIBUTES sa = { sizeof(sa), &sd, FALSE };
//     // Ask for the file mapping with reduced permisions to avoid passing the
//     // access control permissions granted by default into unpriviledged process.
//     HANDLE h = CreateFileMappingWithReducedPermissions(&sa, rounded_size, name.empty() ? nullptr : as_wcstr(name));
//     if (h == nullptr) {
//         // The error is logged within CreateFileMappingWithReducedPermissions().
//         return {};
//     }
// 
//     win::ScopedHandle scoped_h(h);
//     // Check if the shared memory pre-exists.
//     if (GetLastError() == ERROR_ALREADY_EXISTS) {
//         return {};
//     }
// 
//     return PlatformSharedMemoryRegion(std::move(scoped_h), mode, size, UnguessableToken::Create());

    void* ptr = nullptr;
    uintptr_t handle = DirectMemMgr::Get()->NewMemory(size, &ptr);
    return PlatformSharedMemoryRegion(std::move(handle), mode, size, UnguessableToken::Create());
}

// static
bool PlatformSharedMemoryRegion::CheckPlatformHandlePermissionsCorrespondToMode(PlatformSharedMemoryHandle handle, Mode mode, size_t size)
{
//     // Call ::DuplicateHandle() with FILE_MAP_WRITE as a desired access to check
//     // if the |handle| has a write access.
//     ProcessHandle process = GetCurrentProcess();
//     HANDLE duped_handle;
//     BOOL success = ::DuplicateHandle(process, handle, process, &duped_handle, FILE_MAP_WRITE, FALSE, 0);
//     if (success) {
//         BOOL rv = ::CloseHandle(duped_handle);
//         DCHECK(rv);
//     }
// 
//     bool is_read_only = !success;
//     bool expected_read_only = mode == Mode::kReadOnly;
// 
//     if (is_read_only != expected_read_only) {
//         DLOG(ERROR) << "File mapping handle has wrong access rights: it is" << (is_read_only ? " " : " not ") << "read-only but it should"
//                     << (expected_read_only ? " " : " not ") << "be";
//         return false;
//     }
// 
//     return true;

    OutputDebugStringA("CheckPlatformHandlePermissionsCorrespondToMode fail\n");
    DebugBreak();
    return false;
}

#if BUILDFLAG(IS_POSIX) && !BUILDFLAG(IS_ANDROID) && !BUILDFLAG(IS_APPLE)
// Specialized version of Take() for POSIX that takes only one file descriptor
// instead of pair. Cannot be used with kWritable |mode|.
PlatformSharedMemoryRegion PlatformSharedMemoryRegion::Take(ScopedFD handle, Mode mode, size_t size, const UnguessableToken& guid)
{
    OutputDebugStringA("PlatformSharedMemoryRegion::Take not impl\n");
    DebugBreak();
    return PlatformSharedMemoryRegion();
}
#endif

// PlatformSharedMemoryRegion::PlatformSharedMemoryRegion(win::ScopedHandle handle, Mode mode, size_t size, const UnguessableToken& guid)
//     : handle_(std::move(handle))
//     , mode_(mode)
//     , size_(size)
//     , guid_(guid)
// {
// }

} // namespace subtle
} // namespace base
