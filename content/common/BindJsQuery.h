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


#ifndef content_BindJsQuery_h
#define content_BindJsQuery_h

#include "api/core/mb.h"
#include "third_party/blink/public/common/tokens/tokens.h"
#include <functional>
#include "v8.h"

namespace content {

class MbWebView;

class BindJsQuery /*: public jsData*/ {
public:
    typedef std::function<void(mbJsExecState es, int64_t idInfo, int customMsg, const utf8* request)> QueryFn;
    typedef std::function<void(mbJsExecState es, const mbJsValue* val, int count)> QueryFn2;

//     BindJsQuery(int64_t hostId, mbWebFrameHandle frameId);
// 
//     static jsValue WKE_CALL_TYPE jsQueryCallback(jsExecState es, jsValue object, jsValue* args, int argCount);
//     void onJsQueryInBlinkThread(mbWebFrameHandle frameId, int customMsg, const utf8* request, int queryId);
//     static void WKE_CALL_TYPE jsQueryFinalizeCallback(jsData* data);

    static void bindFun(v8::Local<v8::Context> context, QueryFn* queryFn, QueryFn2* queryFn2, MbWebView* webview, const blink::LocalFrameToken& frameToken);

private:
    void onJsQueryInBlinkThread(const blink::LocalFrameToken& m_frameToken, int customMsg, const std::string* request, int queryId);
    void onJsQuery2InBlinkThread(const blink::LocalFrameToken& frameToken, std::vector<mb::MbJsValue*>* jsValues);
    static void jsCallback(const v8::FunctionCallbackInfo<v8::Value>& info);
    static void jsCallback2(const v8::FunctionCallbackInfo<v8::Value>& info);

    QueryFn* m_closure = nullptr;
    QueryFn2* m_closure2 = nullptr;
    int64_t m_webviewId = 0;
    blink::LocalFrameToken m_frameToken;
};

}

#endif // content_BindJsQuery_h