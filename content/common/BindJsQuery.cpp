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


#include "content/browser/MbWebview.h"
#include "content/common/BindJsQuery.h"
#include "content/common/LiveIdDetect.h"
#include "content/common/ThreadCall.h"
#include "content/resources/InjectScript.h"
#include "api/core/MbJsValue.h"
#include "base/strings/utf_string_conversions.h"
#include <string>
#include <string.h>

extern bool g_isElectronMode;

namespace v8 {
bool ApiStringIsWellFormed(v8::Isolate* isolate, v8::Local<v8::String> source);
v8::Local<v8::String> ApiStringToWellFormed(v8::Isolate* isolate, v8::Local<v8::String> source);
}

namespace content {

static const char* injectStringWellFormed =
"String.prototype.toWellFormed = function() { return __ApiStringToWellFormed__(this); }\n"
"String.prototype.isWellFormed = function() { return __ApiStringIsWellFormed__(this); }\n";

// "function __NumberFormat__() {}\n"
// "__NumberFormat__.prototype.format = function(num) { return num; }\n"
// "window.Intl = {};\n"
// "Intl.NumberFormat = __NumberFormat__;\n"
;

void printCallstack()
{
    const v8::StackTrace::StackTraceOptions options = static_cast<v8::StackTrace::StackTraceOptions>(
        v8::StackTrace::kLineNumber
        | v8::StackTrace::kColumnOffset
        | v8::StackTrace::kScriptId
        | v8::StackTrace::kScriptNameOrSourceURL
        | v8::StackTrace::kFunctionName);

    int stackNum = 50;
    v8::HandleScope handleScope(v8::Isolate::GetCurrent());
    v8::Local<v8::StackTrace> stackTrace(v8::StackTrace::CurrentStackTrace(v8::Isolate::GetCurrent(), stackNum, options));
    int count = stackTrace->GetFrameCount();

    char* output = (char*)malloc(0x100);
    sprintf(output, "content::printCallstack: %d\n", count);
    OutputDebugStringA(output);
    free(output);

    for (int i = 0; i < count; ++i) {
        v8::Local<v8::StackFrame> stackFrame = stackTrace->GetFrame(v8::Isolate::GetCurrent(), i);
        int line = stackFrame->GetLineNumber();
        v8::Local<v8::String> scriptName = stackFrame->GetScriptNameOrSourceURL();
        v8::Local<v8::String> funcName = stackFrame->GetFunctionName();

        std::string scriptNameWTF;
        std::string funcNameWTF;

        if (!scriptName.IsEmpty()) {
            v8::String::Utf8Value scriptNameUtf8(v8::Isolate::GetCurrent(), scriptName);
            scriptNameWTF = *scriptNameUtf8;
        }

        if (!funcName.IsEmpty()) {
            v8::String::Utf8Value funcNameUtf8(v8::Isolate::GetCurrent(), funcName);
            funcNameWTF = *funcNameUtf8;
        }
        std::vector<char> output2;
        output2.resize(1000);
        sprintf(&output2[0], "line:%d, [", line);
        OutputDebugStringA(&output2[0]);

        if (!scriptNameWTF.empty()) {
            OutputDebugStringA(scriptNameWTF.c_str());
        }
        OutputDebugStringA("] , [");

        if (!funcNameWTF.empty()) {
            OutputDebugStringA(funcNameWTF.c_str());
        }
        OutputDebugStringA("]\n");
    }
    OutputDebugStringA("\n");
}

static void mbConsoleLog(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Isolate* isolate = info.GetIsolate();
    v8::Local<v8::Context> context = isolate->GetCurrentContext();

    v8::Local<v8::Value> param0 = info[0];
    v8::MaybeLocal<v8::String> param0Maybe = param0->ToString(context);
    //v8::Local<v8::String> param0V8String = param0->ToString(isolate);
    if (param0Maybe.IsEmpty())
        return;
    v8::Local<v8::String> param0V8String = param0Maybe.ToLocalChecked();

    v8::String::Utf8Value param0String(isolate, param0V8String);
    std::string str = "mbConsoleLog, ";
    str += *param0String;
    str += "\n";

    if (std::string::npos != str.find("__callstack__ registerModule"))
        OutputDebugStringA("");

    if (std::string::npos != str.find("__callstack__")) {
        const v8::StackTrace::StackTraceOptions options = static_cast<v8::StackTrace::StackTraceOptions>(
            v8::StackTrace::kLineNumber
            | v8::StackTrace::kColumnOffset
            | v8::StackTrace::kScriptId
            | v8::StackTrace::kScriptNameOrSourceURL
            | v8::StackTrace::kFunctionName);

        int stackNum = 50;
        v8::HandleScope handleScope(info.GetIsolate());
        v8::Local<v8::StackTrace> stackTrace(v8::StackTrace::CurrentStackTrace(info.GetIsolate(), stackNum, options));
        int count = stackTrace->GetFrameCount();

        char* output = (char*)malloc(0x100);
        sprintf(output, "mbConsoleLog: %d\n", count);
        OutputDebugStringA(output);
        free(output);

        for (int i = 0; i < count; ++i) {
            v8::Local<v8::StackFrame> stackFrame = stackTrace->GetFrame(info.GetIsolate(), i);
            int frameCount = stackTrace->GetFrameCount();
            int line = stackFrame->GetLineNumber();
            v8::Local<v8::String> scriptName = stackFrame->GetScriptNameOrSourceURL();
            v8::Local<v8::String> funcName = stackFrame->GetFunctionName();

            std::string scriptNameWTF;
            std::string funcNameWTF;

            if (!scriptName.IsEmpty()) {
                v8::String::Utf8Value scriptNameUtf8(isolate, scriptName);
                scriptNameWTF = *scriptNameUtf8;
            }

            if (!funcName.IsEmpty()) {
                v8::String::Utf8Value funcNameUtf8(isolate, funcName);
                funcNameWTF = *funcNameUtf8;
            }
            std::vector<char> output;
            output.resize(1000);
            sprintf(&output[0], "line:%d, [", line);
            OutputDebugStringA(&output[0]);

            if (!scriptNameWTF.empty()) {
                OutputDebugStringA(scriptNameWTF.c_str());
            }
            OutputDebugStringA("] , [");

            if (!funcNameWTF.empty()) {
                OutputDebugStringA(funcNameWTF.c_str());
            }
            OutputDebugStringA("]\n");
        }
        OutputDebugStringA("\n");
    }

    std::u16string strW = base::UTF8ToUTF16(str);
    OutputDebugStringW((const WCHAR*)strW.c_str());
}

// 新增加一个不定参数的版本
void BindJsQuery::jsCallback2(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Local<v8::External> ext = info.Data().As<v8::External>();
    BindJsQuery* self = (BindJsQuery*)ext->Value();

    v8::Isolate* isolate = info.GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Context::Scope contextScope(context);

    void* host = (void*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(self->m_webviewId);
    if (!host)
        return;
    common::LiveIdDetect::getMbWebviewIds()->unlock(self->m_webviewId, self);

    std::vector<mb::MbJsValue*>* jsValues = new std::vector<mb::MbJsValue *>(info.Length());
    for (int i = 0; i < info.Length(); ++i) {
        v8::Local<v8::Value> argIt = info[i];
        mb::MbJsValue* jsValue = mb::MbJsValue::v8ValueToMb(isolate, context, argIt);
        jsValues->at(i) = jsValue;
    }

    self->onJsQuery2InBlinkThread(self->m_frameToken, jsValues);
}

void BindJsQuery::onJsQuery2InBlinkThread(const blink::LocalFrameToken& frameToken, std::vector<mb::MbJsValue*>* jsValues)
{
    int64_t id = m_webviewId;
    BindJsQuery* self = this;

    size_t frameId = (blink::LocalFrameToken::Hasher()(m_frameToken));

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self, id, jsValues] {
        void* unuse = common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(id);
        if (!unuse) {
            delete jsValues;
            return;
        }

        std::vector<mbJsValue> vals;
        for (size_t i = 0; i < jsValues->size(); ++i) {
            mb::MbJsValue* v = jsValues->at(i);
            vals.push_back(v->getId());
        }

        //std::function<void(mbJsExecState es, int64_t idInfo, int customMsg, const utf8* request)>* closure = self->getClosure().m_jsQueryClosure;
        QueryFn2* closure = self->m_closure2;
        if (closure)
            (*closure)((mbJsExecState)nullptr, vals.data(), vals.size());
        
        for (size_t i = 0; i < jsValues->size(); ++i) {
            mb::MbJsValue* v = jsValues->at(i);
            v->deref();
        }

        common::LiveIdDetect::getMbWebviewIds()->unlock(id, unuse);
    });
}

void BindJsQuery::jsCallback(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    v8::Local<v8::External> ext = info.Data().As<v8::External>();
    BindJsQuery* self = (BindJsQuery*)ext->Value();

    if (3 != info.Length())
        return;

    v8::Isolate* isolate = info.GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::Local<v8::Context> context = isolate->GetCurrentContext();
    v8::Context::Scope contextScope(context);

    v8::Local<v8::Value> arg0 = info[0];
    int customMsg = arg0->ToInt32(context).ToLocalChecked()->Value();

    v8::Local<v8::Value> arg1 = info[1];
    v8::Local<v8::String> str = arg1->ToString(context).ToLocalChecked();
    v8::String::Utf8Value strUtf8(isolate, str);

    v8::Local<v8::Value> arg2 = info[2];
    int queryId = arg2->ToInt32(context).ToLocalChecked()->Value();

    void* host = (void*)common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(self->m_webviewId);
    if (!host)
        return;
    common::LiveIdDetect::getMbWebviewIds()->unlock(self->m_webviewId, self);

    std::string* requestString = new std::string(*strUtf8, strUtf8.length());
    self->onJsQueryInBlinkThread(self->m_frameToken, customMsg, requestString, queryId);
}

void BindJsQuery::onJsQueryInBlinkThread(const blink::LocalFrameToken& frameToken, int customMsg, const std::string* requestString, int queryId)
{
    int64_t id = m_webviewId;
    BindJsQuery* self = this;

    size_t frameId = (blink::LocalFrameToken::Hasher()(m_frameToken));

    std::pair<size_t, int>* idInfo = new std::pair<size_t, int>(frameId, queryId);

//     OutputDebugStringA("BindJsQuery::onJsQueryInBlinkThread 1\n");
// 
//     content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [] {
//         OutputDebugStringA("BindJsQuery::onJsQueryInBlinkThread 3\n");
//     });

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self, id, customMsg, requestString, idInfo] {
        //OutputDebugStringA("BindJsQuery::onJsQueryInBlinkThread 2\n");
        void* unuse = common::LiveIdDetect::getMbWebviewIds()->getPtrLocked(id);
        if (!unuse) {
            delete idInfo;
            delete requestString;
            return;
        }

        //std::function<void(mbJsExecState es, int64_t idInfo, int customMsg, const utf8* request)>* closure = self->getClosure().m_jsQueryClosure;
        QueryFn* closure = self->m_closure;
        if (closure)
            (*closure)((mbJsExecState)nullptr, (__int64)idInfo, customMsg, requestString->c_str());
        delete requestString;

        common::LiveIdDetect::getMbWebviewIds()->unlock(id, unuse);
    });

//     content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [] {
//         OutputDebugStringA("BindJsQuery::onJsQueryInBlinkThread 4\n");
//     });
}

static void bindGlobalFunction(v8::Local<v8::Context> context, const char* name, v8::FunctionCallback callback)
{
    v8::Isolate* isolate = context->GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::TryCatch block(isolate);
    v8::Context::Scope contextScope(context);

    v8::Local<v8::Object> object = context->Global();
    v8::Local<v8::FunctionTemplate> tmpl = v8::FunctionTemplate::New(isolate);

    // Set the function handler callback.
    tmpl->SetCallHandler(callback);

    // Retrieve the function object and set the name.
    v8::Local<v8::Function> func = tmpl->GetFunction(context).ToLocalChecked();
    v8::Local<v8::String> nameV8 = v8::String::NewFromUtf8(isolate, name, v8::NewStringType::kNormal, -1).ToLocalChecked();
    func->SetName(nameV8);

    object->Set(context, nameV8, func);
}

static void V8StringToWellFormed(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (1 != info.Length())
        return;
    if (!info[0]->IsStringObject())
        return;
    v8::Local<v8::StringObject> a0 = info[0].As<v8::StringObject>();
    v8::Local<v8::String> ret = v8::ApiStringToWellFormed(info.GetIsolate(), a0->ValueOf());
    info.GetReturnValue().Set(ret);
}

static void V8StringIsWellFormed(const v8::FunctionCallbackInfo<v8::Value>& info)
{
    if (1 != info.Length())
        return;
    if (!info[0]->IsStringObject())
        return;
    v8::Local<v8::StringObject> a0 = info[0].As<v8::StringObject>();
    bool ret = v8::ApiStringIsWellFormed(info.GetIsolate(), a0->ValueOf());
    info.GetReturnValue().Set(ret);
}

void fixStringWelFormed(v8::Local<v8::Context> context)
{
    bindGlobalFunction(context, "__ApiStringToWellFormed__", V8StringToWellFormed);
    bindGlobalFunction(context, "__ApiStringIsWellFormed__", V8StringIsWellFormed);

    v8::Isolate* isolate = context->GetIsolate();
    v8::Isolate::Scope isolateScope(isolate);
    v8::HandleScope handleScope(isolate);
    v8::Context::Scope contextScope(context);

    v8::Local<v8::String> source = v8::String::NewFromUtf8(isolate, injectStringWellFormed).ToLocalChecked();
    v8::Local<v8::Script> script = v8::Script::Compile(context, source).ToLocalChecked();
    script->Run(context);
}

void bindOnWebWorkers(v8::Local<v8::Context> context)
{
    v8::Isolate* isolate = context->GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::Context::Scope contextScope(context);
    v8::MicrotasksScope miscrotaskScope(isolate, v8::MicrotasksScope::Type::kRunMicrotasks);
    bindGlobalFunction(context, "mbConsoleLog", mbConsoleLog);

    v8::Local<v8::String> code = v8::String::NewFromUtf8(isolate, kInjectScript, v8::NewStringType::kNormal, -1).ToLocalChecked();
    v8::ScriptOrigin origin(isolate, v8::String::NewFromUtf8(isolate, "bindOnWebWorkers.js", v8::NewStringType::kNormal, -1).ToLocalChecked());
    v8::ScriptCompiler::Source source(code, origin);
    v8::MaybeLocal<v8::Script> script = v8::ScriptCompiler::Compile(context, &source, v8::ScriptCompiler::kNoCompileOptions);
    script.ToLocalChecked()->Run(context);
}

void BindJsQuery::bindFun(v8::Local<v8::Context> context, QueryFn* queryFn, QueryFn2* queryFn2, MbWebView* webview, const blink::LocalFrameToken& frameToken)
{
    int64_t webviewId = webview->getId();
    v8::Isolate* isolate = context->GetIsolate();
    v8::HandleScope handleScope(isolate);
    v8::Context::Scope contextScope(context);
    v8::Local<v8::Object> globalObj = context->Global();
    v8::MicrotasksScope microtasksScope(isolate, v8::MicrotasksScope::Type::kDoNotRunMicrotasks);

    if (!g_isElectronMode)
        bindGlobalFunction(context, "mbConsoleLog", mbConsoleLog);

    fixStringWelFormed(context);

    size_t frameId = (blink::LocalFrameToken::Hasher()(frameToken));
    std::string injectScriptStr(kInjectScript);
    mb::MbJsValue* mbVal = webview->runJsOnBlinkThreadImpl((mbWebFrameHandle)frameId, 0, &injectScriptStr, false, nullptr, nullptr);
    if (mbVal)
        mbVal->deref();

    // 构建func参数
    BindJsQuery* self = new BindJsQuery();
    self->m_webviewId = webviewId;
    self->m_frameToken = frameToken;
    self->m_closure = queryFn;
    self->m_closure2 = queryFn2;
    v8::Local<v8::Value> dataLocal = v8::External::New(isolate, self);

    v8::Local<v8::FunctionTemplate> functionTemplate = v8::FunctionTemplate::New(isolate, jsCallback, dataLocal);
    v8::Local<v8::Function> v8Function;
    if (!functionTemplate->GetFunction(context).ToLocal(&v8Function))
        DebugBreak();

    v8::Local<v8::FunctionTemplate> functionTemplate2 = v8::FunctionTemplate::New(isolate, jsCallback2, dataLocal);
    v8::Local<v8::Function> v8Function2;
    if (!functionTemplate2->GetFunction(context).ToLocal(&v8Function2))
        DebugBreak();

    v8::Local<v8::Object> global = context->Global();
    v8::Local<v8::Value> windowVal = global->Get(context, v8::String::NewFromUtf8(isolate, "window", v8::NewStringType::kNormal, -1).ToLocalChecked()).ToLocalChecked();
    v8::Local<v8::Object> windowObj = windowVal->ToObject(context).ToLocalChecked();

    v8::Local<v8::String> setMbQueryStr = v8::String::NewFromUtf8(isolate, "__setMbQuery__", v8::NewStringType::kNormal, -1).ToLocalChecked();
    v8::Local<v8::Value> setMbQueryStrValue = windowObj->Get(context, setMbQueryStr).ToLocalChecked();
    if (!setMbQueryStrValue->IsFunction())// https://www.hao123.com/?tn=48021271_79_hao_pg 这网页不知道为啥有时绑定失败
        return;

    v8::Function* setMbQueryFunc = v8::Function::Cast(*setMbQueryStrValue);

    v8::Local<v8::Value> argv[2] = { v8Function, v8Function2 };
    setMbQueryFunc->Call(context, v8::Undefined(isolate), 2, argv);
}

}