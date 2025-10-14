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


#ifndef mbvip_core_MbJsValue_h
#define mbvip_core_MbJsValue_h

#include "mbvip/core/mb.h"
#include "content/common/LiveIdDetect.h"
#include "v8.h"

typedef void* mbWebFrameHandle;

namespace mb {

class MbJsValue {
public:
    static MbJsValue* create();
    void ref();
    void deref();

private:
    MbJsValue();
    ~MbJsValue();

public:
    static MbJsValue* v8ValueToMb(v8::Isolate* isolate, v8::Local<v8::Context> context, v8::Local<v8::Value> value);

    int64_t getId() const { return m_id; }
    mbJsType getType() const { return m_type; }

    double getDoubleVal() const { return m_doubleVal; }
    std::string getStrVal() const { return m_strVal; }
    BOOL getBoolVal() const { return m_boolVal; }
    mbWebFrameHandle getWebFrameHandle() const { return m_webFrameHandle; }

private:
    int m_ref = 1;
    int64_t m_id = -1;
    mbJsType m_type = kMbJsTypeUndefined;

    double m_doubleVal = 0;
    std::string m_strVal;
    BOOL m_boolVal = FALSE;
    mbWebFrameHandle m_webFrameHandle = nullptr;
};

}

#endif // mbvip_core_MbJsValue_h