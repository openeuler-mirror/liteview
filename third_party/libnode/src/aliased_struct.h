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

#ifndef SRC_ALIASED_STRUCT_H_
#define SRC_ALIASED_STRUCT_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "node_internals.h"
#include "v8.h"
#include <memory>

namespace node {

// AliasedStruct is a utility that allows uses a V8 Backing Store
// to be exposed to the C++/C side as a struct and to the
// JavaScript side as an ArrayBuffer to efficiently share
// data without marshalling. It is similar in nature to
// AliasedBuffer.
//
//   struct Foo { int x; }
//
//   AliasedStruct<Foo> foo;
//   foo->x = 1;
//
//   Local<ArrayBuffer> ab = foo.GetArrayBuffer();
template <typename T> class AliasedStruct final {
public:
    template <typename... Args> explicit AliasedStruct(v8::Isolate* isolate, Args&&... args);

    inline AliasedStruct(const AliasedStruct& that);

    inline ~AliasedStruct();

    inline AliasedStruct& operator=(AliasedStruct&& that) noexcept;

    v8::Local<v8::ArrayBuffer> GetArrayBuffer() const
    {
        return buffer_.Get(isolate_);
    }

    const T* Data() const
    {
        return ptr_;
    }

    T* Data()
    {
        return ptr_;
    }

    const T& operator*() const
    {
        return *ptr_;
    }

    T& operator*()
    {
        return *ptr_;
    }

    const T* operator->() const
    {
        return ptr_;
    }

    T* operator->()
    {
        return ptr_;
    }

private:
    v8::Isolate* isolate_;
    std::shared_ptr<v8::BackingStore> store_;
    T* ptr_;
    v8::Global<v8::ArrayBuffer> buffer_;
};

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_ALIASED_STRUCT_H_
