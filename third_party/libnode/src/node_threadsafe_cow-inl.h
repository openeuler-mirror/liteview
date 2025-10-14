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

#ifndef SRC_NODE_THREADSAFE_COW_INL_H_
#define SRC_NODE_THREADSAFE_COW_INL_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

namespace node {

template <typename T> T* CopyOnWrite<T>::write()
{
    if (data_.use_count() > 1l) {
        data_ = std::make_shared<T>(*data_);
    }
    return data_.get();
}

template <typename T>
ThreadsafeCopyOnWrite<T>::Read::Read(const ThreadsafeCopyOnWrite<T>* cow)
    : cow_(cow)
    , lock_(cow->impl_->mutex)
{
}

template <typename T> const T& ThreadsafeCopyOnWrite<T>::Read::operator*() const
{
    return cow_->impl_->data;
}

template <typename T> const T* ThreadsafeCopyOnWrite<T>::Read::operator->() const
{
    return &cow_->impl_->data;
}

template <typename T>
ThreadsafeCopyOnWrite<T>::Write::Write(ThreadsafeCopyOnWrite<T>* cow)
    : cow_(cow)
    , impl_(cow->impl_.write())
    , lock_(impl_->mutex)
{
}

template <typename T> T& ThreadsafeCopyOnWrite<T>::Write::operator*()
{
    return impl_->data;
}

template <typename T> T* ThreadsafeCopyOnWrite<T>::Write::operator->()
{
    return &impl_->data;
}

template <typename T> ThreadsafeCopyOnWrite<T>::Impl::Impl(const Impl& other)
{
    RwLock::ScopedReadLock lock(other.mutex);
    data = other.data;
}

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_NODE_THREADSAFE_COW_INL_H_
