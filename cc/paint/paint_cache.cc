// Copyright 2018 The Chromium Authors
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "cc/paint/paint_cache.h"

#include "base/check_op.h"
#include "base/containers/flat_set.h"
#include "base/notreached.h"
#include "base/synchronization/lock.h"

namespace cc {
namespace {

template <typename T> void EraseFromMap(T* map, size_t n, const volatile PaintCacheId* ids)
{
    for (size_t i = 0; i < n; ++i) {
        auto id = ids[i];
        map->erase(id);
    }
}

} // namespace

constexpr size_t ClientPaintCache::kNoCachingBudget;

ClientPaintCache::ClientPaintCache(size_t max_budget_bytes)
    : cache_map_(CacheMap::NO_AUTO_EVICT)
    , max_budget_(max_budget_bytes)
{
}
ClientPaintCache::~ClientPaintCache() = default;

//--
template <typename TContainerType, int stack_capacity> class StackContainer2 {
public:
    using ContainerType = TContainerType;
    using ContainedType = typename ContainerType::value_type;
    using Allocator = typename ContainerType::allocator_type;

    // Allocator must be constructed before the container!
    StackContainer2()
        : allocator_(&stack_data_)
        , container_(allocator_)
    {
        container_.reserve(stack_capacity);
    }
    StackContainer2(const StackContainer2&) = delete;
    StackContainer2& operator=(const StackContainer2&) = delete;

    ContainerType& container()
    {
        return container_;
    }
    const ContainerType& container() const
    {
        return container_;
    }

    ContainerType* operator->()
    {
        return &container_;
    }
    const ContainerType* operator->() const
    {
        return &container_;
    }

protected:
    typename Allocator::Source stack_data_;
    NO_UNIQUE_ADDRESS Allocator allocator_;
    ContainerType container_;
};

template <typename T, size_t stack_capacity> class StackAllocator3 : public std::allocator<T> {
public:
    //   typedef typename std::allocator<T>::pointer pointer;
    //   typedef typename std::allocator<T>::size_type size_type;
    using pointer = typename std::allocator_traits<std::allocator<T>>::pointer;
    using size_type = typename std::allocator_traits<std::allocator<T>>::size_type;

    struct Source {
        Source()
            : used_stack_buffer_(false)
        {
        }

        // Casts the buffer in its right type.
        T* stack_buffer()
        {
            // return stack_buffer_.template data_as<T>();
            return nullptr;
        }
        const T* stack_buffer() const
        {
            return nullptr;
            // return stack_buffer_.template data_as<T>();
        }

        //     base::AlignedMemory<sizeof(T[stack_capacity]), ALIGNOF(T)> stack_buffer_;
        // #if defined(__GNUC__) && !defined(ARCH_CPU_X86_FAMILY)
        //     static_assert(ALIGNOF(T) <= 16, "http://crbug.com/115612");
        // #endif

        // Set when the stack buffer is used for an allocation. We do not track
        // how much of the buffer is used, only that somebody is using it.
        bool used_stack_buffer_;
    };

    // Used by containers when they want to refer to an allocator of type U.
    template <typename U> struct rebind {
        typedef StackAllocator3<U, stack_capacity> other;
    };

    // For the straight up copy c-tor, we can share storage.
    StackAllocator3(const StackAllocator3<T, stack_capacity>& rhs)
        : std::allocator<T>()
        , source_(rhs.source_)
    {
    }

    template <typename U, size_t other_capacity>
    StackAllocator3(const StackAllocator3<U, other_capacity>& other)
        : source_(NULL)
    {
    }

    StackAllocator3()
        : source_(NULL)
    {
    }

    explicit StackAllocator3(Source* source)
        : source_(source)
    {
    }

    pointer allocate(size_type n, void* hint = 0)
    {
        if (source_ != NULL && !source_->used_stack_buffer_ && n <= stack_capacity) {
            source_->used_stack_buffer_ = true;
            return source_->stack_buffer();
        } else {
            return std::allocator<T>::allocate(n, hint);
        }
    }

    void deallocate(pointer p, size_type n)
    {
        if (source_ != NULL && p == source_->stack_buffer())
            source_->used_stack_buffer_ = false;
        else
            std::allocator<T>::deallocate(p, n);
    }

private:
    Source* source_;
};

template <typename T, size_t stack_capacity, typename FallbackAllocator> class StackAllocator4 : public std::allocator<T> {
public:
    using pointer = typename std::allocator_traits<std::allocator<T>>::pointer;
    using size_type = typename std::allocator_traits<std::allocator<T>>::size_type;

    // Backing store for the allocator. The container owner is responsible for
    // maintaining this for as long as any containers using this allocator are
    // live.
    struct Source {
        Source()
            : used_stack_buffer_(false)
        {
        }

        // Casts the buffer in its right type.
        NO_SANITIZE("cfi-unrelated-cast")
        T* stack_buffer()
        {
            return reinterpret_cast<T*>(stack_buffer_);
        }
        NO_SANITIZE("cfi-unrelated-cast")
        const T* stack_buffer() const
        {
            return reinterpret_cast<const T*>(&stack_buffer_);
        }

        // The buffer itself. It is not of type T because we don't want the
        // constructors and destructors to be automatically called. Define a POD
        // buffer of the right size instead.
        alignas(T) char stack_buffer_[sizeof(T[stack_capacity])];
#if defined(__GNUC__) && !defined(ARCH_CPU_X86_FAMILY)
        static_assert(alignof(T) <= 16, "http://crbug.com/115612");
#endif

        // Set when the stack buffer is used for an allocation. We do not track
        // how much of the buffer is used, only that somebody is using it.
        bool used_stack_buffer_;
    };

    // Used by containers when they want to refer to an allocator of type U.
    template <typename U> struct rebind {
        typedef StackAllocator4<U, stack_capacity, std::allocator<T>> other;
    };

    // For the straight up copy c-tor, we can share storage.
    StackAllocator4(const StackAllocator4<T, stack_capacity, std::allocator<T>>& rhs)
        : source_(rhs.source_)
    {
    }

    // ISO C++ requires the following constructor to be defined,
    // and std::vector in VC++2008SP1 Release fails with an error
    // in the class _Container_base_aux_alloc_real (from <xutility>)
    // if the constructor does not exist.
    // For this constructor, we cannot share storage; there's
    // no guarantee that the Source buffer of Ts is large enough
    // for Us.
    // TODO: If we were fancy pants, perhaps we could share storage
    // iff sizeof(T) == sizeof(U).
    template <typename U, size_t other_capacity, typename FA>
    StackAllocator4(const StackAllocator4<U, other_capacity, FA>& other)
        : source_(nullptr)
    {
    }

    // This constructor must exist. It creates a default allocator that doesn't
    // actually have a stack buffer. glibc's std::string() will compare the
    // current allocator against the default-constructed allocator, so this
    // should be fast.
    StackAllocator4()
        : source_(nullptr)
    {
    }

    explicit StackAllocator4(Source* source)
        : source_(source)
    {
    }

    // Actually do the allocation. Use the stack buffer if nobody has used it yet
    // and the size requested fits. Otherwise, fall through to the standard
    // allocator.
    pointer allocate(size_type n)
    {
        if (source_ && !source_->used_stack_buffer_ && n <= stack_capacity) {
            source_->used_stack_buffer_ = true;
            return source_->stack_buffer();
        } else {
            return std::allocator_traits<std::allocator<T>>::allocate(*this, n);
        }
    }

    // Free: when trying to free the stack buffer, just mark it as free. For
    // non-stack-buffer pointers, just fall though to the standard allocator.
    void deallocate(pointer p, size_type n)
    {
        if (source_ && p == source_->stack_buffer())
            source_->used_stack_buffer_ = false;
        else
            std::allocator_traits<std::allocator<T>>::deallocate(*this, p, n);
    }

private:
    // `source_` is not a raw_ptr<T> for performance reasons: on-stack pointee.
    RAW_PTR_EXCLUSION Source* source_;
};

template <typename T, size_t stack_capacity, typename FallbackAllocator = std::allocator<T>>
class StackVector2
    //: public StackContainer2<std::vector<T, base::StackAllocator<T, stack_capacity, FallbackAllocator>>, stack_capacity> {
    : public StackContainer2<std::vector<T, StackAllocator4<T, stack_capacity, std::allocator<T>>>, stack_capacity> {
public:
    StackVector2()
        //: StackContainer2<std::vector<T, base::StackAllocator<T, stack_capacity, FallbackAllocator>>,
        : StackContainer2<std::vector<T, StackAllocator4<T, stack_capacity, std::allocator<T>>>, stack_capacity>()
    {
    }

    T& operator[](size_t i)
    {
        return this->container().operator[](i);
    }

    const T& operator[](size_t i) const
    {
        return this->container().operator[](i);
    }
};

////////
//

template <typename TContainerType, int stack_capacity> class StackContainer3 {
public:
    typedef TContainerType ContainerType;
    typedef typename ContainerType::value_type ContainedType;
    typedef StackAllocator3<ContainedType, stack_capacity> Allocator;

    // Allocator must be constructed before the container!
    StackContainer3()
        : allocator_(&stack_data_)
        , container_(allocator_)
    {
        container_.reserve(stack_capacity);
    }

    ContainerType& container()
    {
        return container_;
    }
    const ContainerType& container() const
    {
        return container_;
    }

    ContainerType* operator->()
    {
        return &container_;
    }
    const ContainerType* operator->() const
    {
        return &container_;
    }

protected:
    typename Allocator::Source stack_data_;
    Allocator allocator_;
    ContainerType container_;

private:
};

template <typename T, size_t stack_capacity> class StackVector3 : public StackContainer3<std::vector<T, StackAllocator3<T, stack_capacity>>, stack_capacity> {
public:
    StackVector3()
        : StackContainer3<std::vector<T, StackAllocator3<T, stack_capacity>>, stack_capacity>()
    {
    }

    T& operator[](size_t i)
    {
        return this->container().operator[](i);
    }
    const T& operator[](size_t i) const
    {
        return this->container().operator[](i);
    }
};

//----------

bool ClientPaintCache::Get(PaintCacheDataType type, PaintCacheId id)
{
    return cache_map_.Get(std::make_pair(type, id)) != cache_map_.end();
}

void ClientPaintCache::Put(PaintCacheDataType type, PaintCacheId id, size_t size)
{
    if (max_budget_ == kNoCachingBudget)
        return;
    auto key = std::make_pair(type, id);
    DCHECK(cache_map_.Peek(key) == cache_map_.end());

    pending_entries_->push_back(key);
    cache_map_.Put(key, size);
    bytes_used_ += size;
}

template <typename Iterator> void ClientPaintCache::EraseFromMap(Iterator it)
{
    DCHECK_GE(bytes_used_, it->second);
    bytes_used_ -= it->second;
    cache_map_.Erase(it);
}

void ClientPaintCache::FinalizePendingEntries()
{
    pending_entries_->clear();
}

void ClientPaintCache::AbortPendingEntries()
{
    for (const auto& entry : pending_entries_) {
        auto it = cache_map_.Peek(entry);
        DCHECK(it != cache_map_.end());
        EraseFromMap(it);
    }
    pending_entries_->clear();
}

void ClientPaintCache::Purge(PurgedData* purged_data)
{
    DCHECK(pending_entries_->empty());

    while (bytes_used_ > max_budget_) {
        auto it = cache_map_.rbegin();
        PaintCacheDataType type = it->first.first;
        PaintCacheId id = it->first.second;

        EraseFromMap(it);
        (*purged_data)[static_cast<uint32_t>(type)].push_back(id);
    }
}

bool ClientPaintCache::PurgeAll()
{
    DCHECK(pending_entries_->empty());

    bool has_data = !cache_map_.empty();
    cache_map_.Clear();
    bytes_used_ = 0u;
    return has_data;
}

ServicePaintCache::ServicePaintCache() = default;
ServicePaintCache::~ServicePaintCache() = default;

void ServicePaintCache::PutPath(PaintCacheId id, SkPath path)
{
    cached_paths_.emplace(id, std::move(path));
}

bool ServicePaintCache::GetPath(PaintCacheId id, SkPath* path) const
{
    auto it = cached_paths_.find(id);
    if (it == cached_paths_.end())
        return false;
    *path = it->second;
    return true;
}

void ServicePaintCache::Purge(PaintCacheDataType type, size_t n, const volatile PaintCacheId* ids)
{
    switch (type) {
    case PaintCacheDataType::kPath:
        EraseFromMap(&cached_paths_, n, ids);
        return;
    }

    NOTREACHED();
}

void ServicePaintCache::PurgeAll()
{
    cached_paths_.clear();
}

} // namespace cc
