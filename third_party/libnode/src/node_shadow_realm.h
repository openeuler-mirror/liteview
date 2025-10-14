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

#ifndef SRC_NODE_SHADOW_REALM_H_
#define SRC_NODE_SHADOW_REALM_H_

#if defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#include "node_realm.h"
#include "v8.h"

namespace node {
namespace shadow_realm {

class ShadowRealm : public Realm {
public:
    static ShadowRealm* New(Environment* env);

    SET_MEMORY_INFO_NAME(ShadowRealm)
    SET_SELF_SIZE(ShadowRealm)

    v8::Local<v8::Context> context() const override;

#define V(PropertyName, TypeName)                                                                                                                              \
    v8::Local<TypeName> PropertyName() const override;                                                                                                         \
    void set_##PropertyName(v8::Local<TypeName> value) override;
    PER_REALM_STRONG_PERSISTENT_VALUES(V)
#undef V

protected:
    v8::MaybeLocal<v8::Value> BootstrapRealm() override;

private:
    static void WeakCallback(const v8::WeakCallbackInfo<ShadowRealm>& data);
    static void DeleteMe(void* data);

    explicit ShadowRealm(Environment* env);
    ~ShadowRealm();
};

v8::MaybeLocal<v8::Context> HostCreateShadowRealmContextCallback(v8::Local<v8::Context> initiator_context);

} // namespace shadow_realm
} // namespace node

#endif // defined(NODE_WANT_INTERNALS) && NODE_WANT_INTERNALS

#endif // SRC_NODE_SHADOW_REALM_H_
