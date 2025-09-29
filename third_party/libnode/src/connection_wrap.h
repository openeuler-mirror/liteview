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

#ifndef SRC_CONNECTION_WRAP_H_
#define SRC_CONNECTION_WRAP_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "stream_wrap.h"

namespace node {

class Environment;

template <typename WrapType, typename UVType> class ConnectionWrap : public LibuvStreamWrap {
public:
    static void OnConnection(uv_stream_t* handle, int status);
    static void AfterConnect(uv_connect_t* req, int status);

protected:
    ConnectionWrap(Environment* env, v8::Local<v8::Object> object, ProviderType provider);

    UVType handle_;
};

} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_CONNECTION_WRAP_H_
