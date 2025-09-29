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
#include "mbvip/core/MbJsValue.h"
#include "base/strings/utf_string_conversions.h"
#include <string>
#include <string.h>

extern bool g_isElectronMode;

namespace v8 {
bool ApiStringIsWellFormed(v8::Isolate* isolate, v8::Local<v8::String> source);
v8::Local<v8::String> ApiStringToWellFormed(v8::Isolate* isolate, v8::Local<v8::String> source);
}

namespace content {

static const char* injectScript =
//"window.chrome = {app:null, runtime:null};\n"
"if (!('chrome' in window)) {\n"
"    Object.defineProperty(window, \"chrome\", {\n"
"        get: function() {\n"
"            return {\n"
"                app:null, \n"
"                runtime: {\n"
"                    sendMessage:function() {} \n"
"                }\n"
"            };\n"
"        },\n"
"        set : function(val) {\n"
"        },\n"
"        enumerable : true,\n"
"    });\n"
"}\n"
"window.__g_callbackMap__ = {};\n"
"window.__g_callbackMapIdGen__ = 0;\n"
"window.__onMbQuery__ = function(id, customMsg, response) {\n"
"    var cb = window.__g_callbackMap__[id];\n"
"    console.log('__onMbQuery__ cb:' + customMsg);\n"
"    if (cb) {\n"
"        cb(customMsg, response);\n"
"        delete window.__g_callbackMap__[id];\n"
"    }\n"
"}\n"
"window.__setMbQuery__ = function(func, func2) {\n"
"    window.mbQuery = function(customMsg, request, cb) {\n"
"        var id = -1\n"
"        if ('function' == typeof cb) {\n"
"            id = ++window.__g_callbackMapIdGen__;"
"            window.__g_callbackMap__[id] = cb;\n"
"        }\n"
"        func(customMsg, request, id);\n"
"        console.log('mbQuery cb:' + typeof cb);\n"
"    }\n"
"    window.mbSendToNative = func2;"
"    window.mbSendToNative2 = function(request) {\n"
"        var args = Array.prototype.slice.call(arguments);\n"
"        func2(args);\n"
"        console.log('mbSendToNative cb:' + typeof cb);\n"
"    }\n"
"}\n"
"function __Audio__(url) {\n"
"    this.paused = false;\n"
"    this.loop = false;\n"
"    this.playbackRate = 1;\n"
"    this.defaultPlaybackRate = false;\n"
"    this.src = false;\n"
"    this.duration = 1;\n"
"}\n"
"__Audio__.prototype.addEventListener = function() {\n"
"    return this;\n"
"};\n"
"__Audio__.prototype.pause = function() {\n"
"    return this;\n"
"};\n"
"__Audio__.prototype.load = function() {\n"
"    return this;\n"
"};\n"
"__Audio__.prototype.play = function() {\n"
"    return this;\n"
"};\n"
"\n"
"window.Audio = __Audio__;\n"
"(function() {\n"
"    class FakeAnalyser {\n"
"        constructor() {\n"
"            this.fftSize = 0;\n"
"            this.frequencyBinCount = 0;\n"
"        }\n"
"        getByteTimeDomainData(array) { array.fill(0) }\n"
"        getByteFrequencyData(array) { array.fill(0) }\n"
"    }\n"
"\n"
"    class FakeAudioContext {\n"
"        constructor() { }\n"
"        createAnalyser() { return new FakeAnalyser() }\n"
"        resume() { }\n"
"        close() { }\n"
"        suspend() { }\n"
"    }\n"
"    \n"
"    window.AudioContext = FakeAudioContext;\n"
"        class FakeMediaStreamTrack {\n"
"        constructor(kind = 'video') {\n"
"            this.kind = kind;\n"
"            this.enabled = true;\n"
"            this.muted = false;\n"
"            this.readyState = 'live';\n"
"            this.id = Math.random().toString(36).slice(2);\n"
"            this.label = 'track';\n"
"        }\n"
"        stop() { }\n"
"        clone() { return new FakeMediaStreamTrack(this.kind); }\n"
"    }\n"
"    \n"
"    class FakeMediaStream {\n"
"        constructor(tracks = []) {\n"
"            this._tracks = tracks;\n"
"            this.id = Math.random().toString(36).slice(2);\n"
"            this.active = true;\n"
"        }\n"
"        getTracks() { return this._tracks; }\n"
"        getAudioTracks() { return this._tracks.filter(t => t.kind === 'audio'); }\n"
"        getVideoTracks() { return this._tracks.filter(t => t.kind === 'video'); }\n"
"        addTrack(track) { this._tracks.push(track); }\n"
"        removeTrack(track) { this._tracks = this._tracks.filter(t => t !== track); }\n"
"        clone() { return new FakeMediaStream(this._tracks.map(t => t.clone())); }\n"
"    }\n"
"    \n"
"    window.MediaStream = FakeMediaStream;\n"
"    window.MediaStreamTrack = FakeMediaStreamTrack;\n"
"})();\n"
"\n"
"if (!('indexedDB' in window)) {\n"
"    (function() {\n"
// 模拟IDBRequest
"        class MockIDBRequest {\n"
"            constructor() {\n"
"                this.readyState = 'pending';\n"
"                this.result = null;\n"
"                this.error = null;\n"
"                this.oncomplete = null;\n"
"                this.onsuccess = null;\n"
"                this.onerror = null;\n"
"                this.source = null;\n"
"                this.transaction = null;\n"
"            }\n"
"\n"
"            addEventListener(type, callback) {\n"
"                //alert('MockIDBRequest addEventListener');\n"
"                if (type === 'complete') this.oncomplete = callback;\n"
"                if (type === 'success') this.onsuccess = callback;\n"
"                if (type === 'error') this.onerror = callback;\n"
"            }\n"
"            removeEventListener(type) {\n"
"                if (type === 'complete') this.oncomplete = null;\n"
"                if (type === 'success') this.onsuccess = null;\n"
"                if (type === 'error') this.onerror = null;\n"
"            }\n"
"\n"
// 触发成功回调
"            _resolve(value) {\n"
"                this.readyState = 'done';\n"
"                this.result = value;\n"
"                if (typeof this.onsuccess === 'function') {\n"
"                    this.onsuccess({\n"
"                        target: this\n"
"                    });\n"
"                }\n"
"                if (typeof this.oncomplete === 'function') {\n"
"                    this.oncomplete({\n"
"                        target: this\n"
"                    });\n"
"                }\n"
"            }\n"
"\n"
// 触发错误回调
"            _reject(error) {\n"
"                this.readyState = 'done';\n"
"                this.error = error instanceof Error ? error : new Error(error);\n"
"                if (typeof this.onerror === 'function') {\n"
"                    this.onerror({\n"
"                        target: this\n"
"                    });\n"
"                }\n"
"            }\n"
"        }\n"
"\n"
// 模拟IDBKeyRange
"        class MockIDBKeyRange {\n"
"            constructor(lower, upper, lowerOpen, upperOpen) {\n"
"                this.lower = lower;\n"
"                this.upper = upper;\n"
"                this.lowerOpen = lowerOpen;\n"
"                this.upperOpen = upperOpen;\n"
"            }\n"
"\n"
"            addEventListener(type, callback) {\n"
"                alert('MockIDBKeyRange addEventListener');\n"
"            }\n"
"\n"
"            static only(value) {\n"
"                return new MockIDBKeyRange(value, value, false, false);\n"
"            }\n"
"\n"
"            static lowerBound(value, open = false) {\n"
"                return new MockIDBKeyRange(value, undefined, open, true);\n"
"            }\n"
"\n"
"            static upperBound(value, open = false) {\n"
"                return new MockIDBKeyRange(undefined, value, true, open);\n"
"            }\n"
"\n"
"            static bound(lower, upper, lowerOpen = false, upperOpen = false) {\n"
"                return new MockIDBKeyRange(lower, upper, lowerOpen, upperOpen);\n"
"            }\n"
"        }\n"
"\n"
// 模拟IDBCursor
"        class MockIDBCursor {\n"
"            constructor(store, range, direction = 'next') {\n"
"                this.store = store;\n"
"                this.range = range;\n"
"                this.direction = direction;\n"
"                this._position = -1;\n"
"                this._filteredRecords = this._filterRecords();\n"
"                this.value = null;\n"
"                this.key = null;\n"
"                this.primaryKey = null;\n"
"            }\n"
"\n"
"            addEventListener(type, callback) {\n"
"                alert('MockIDBCursor addEventListener');\n"
"            }\n"
"\n"
// 根据范围过滤记录
"            _filterRecords() {\n"
"                const records = this.store._records.slice();\n"
"                const filtered = [];\n"
"\n"
// 应用排序
"                if (this.direction === 'prev' || this.direction === 'prevunique') {\n"
"                    records.reverse();\n"
"                }\n"
"\n"
// 应用范围过滤
"                for (const record of records) {\n"
"                    const key = record.key;\n"
"                    let inRange = true;\n"
"\n"
"                    if (this.range) {\n"
"                        if (this.range.lower !== undefined) {\n"
"                            if (this.range.lowerOpen) {\n"
"                                inRange = inRange && key > this.range.lower;\n"
"                            } else {\n"
"                                inRange = inRange && key >= this.range.lower;\n"
"                            }\n"
"                        }\n"
"\n"
"                        if (this.range.upper !== undefined) {\n"
"                            if (this.range.upperOpen) {\n"
"                                inRange = inRange && key < this.range.upper;\n"
"                            } else {\n"
"                                inRange = inRange && key <= this.range.upper;\n"
"                            }\n"
"                        }\n"
"                    }\n"
"\n"
"                    if (inRange) {\n"
// 处理unique
"                        if (this.direction === 'nextunique' || this.direction === 'prevunique') {\n"
"                            if (!filtered.some(r => r.key === key)) {\n"
"                                filtered.push(record);\n"
"                            }\n"
"                        } else {\n"
"                            filtered.push(record);\n"
"                        }\n"
"                    }\n"
"                }\n"
"\n"
"                return filtered;\n"
"            }\n"
"\n"
// 移动到下一个记录
"            continue (key) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    if (key !== undefined) {\n"
// 查找指定key的位置
"                        this._position = this._filteredRecords.findIndex(r => r.key === key);\n"
"                        if (this._position === -1) {\n"
"                            request._resolve(null);\n"
"                            return;\n"
"                        }\n"
"                    } else {\n"
"                        this._position++;\n"
"                    }\n"
"\n"
"                    if (this._position < this._filteredRecords.length) {\n"
"                        const record = this._filteredRecords[this._position];\n"
"                        this.value = record.value;\n"
"                        this.key = record.key;\n"
"                        this.primaryKey = record.key;\n"
"                        request._resolve(this);\n"
"                    } else {\n"
"                        request._resolve(null);\n"
"                    }\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"\n"
// 更新当前记录
"            update(value) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    if (this._position >= 0 && this._position < this._filteredRecords.length) {\n"
"                        const record = this._filteredRecords[this._position];\n"
"                        const index = this.store._records.findIndex(r => r.key === record.key);\n"
"\n"
"                        if (index !== -1) {\n"
"                            this.store._records[index].value = value;\n"
"                            this.value = value;\n"
"                            request._resolve(value);\n"
"                        } else {\n"
"                            request._reject('Record not found');\n"
"                        }\n"
"                    } else {\n"
"                        request._reject('No current record');\n"
"                    }\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"\n"
// 删除当前记录
"            delete() {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    if (this._position >= 0 && this._position < this._filteredRecords.length) {\n"
"                        const record = this._filteredRecords[this._position];\n"
"                        const index = this.store._records.findIndex(r => r.key === record.key);\n"
"\n"
"                        if (index !== -1) {\n"
"                            this.store._records.splice(index, 1);\n"
"                            request._resolve(undefined);\n"
"                        } else {\n"
"                            request._reject('Record not found');\n"
"                        }\n"
"                    } else {\n"
"                        request._reject('No current record');\n"
"                    }\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"        }\n"
"\n"
// 模拟IDBIndex
"        class MockIDBIndex {\n"
"            constructor(store, name, keyPath, multiEntry, unique) {\n"
"                this.name = name;\n"
"                this.keyPath = keyPath;\n"
"                this.multiEntry = multiEntry || false;\n"
"                this.unique = unique || false;\n"
"                this.store = store;\n"
"                this._indexMap = new Map();"
"                this._buildIndex();\n"
"            }\n"
"\n"
"            addEventListener(type, callback) {\n"
"                alert('MockIDBIndex addEventListener');\n"
"            }\n"
"\n"
// 构建索引
"            _buildIndex() {\n"
"                this._indexMap.clear();\n"
"\n"
"                for (const record of this.store._records) {\n"
"                    this._addRecordToIndex(record);\n"
"                }\n"
"            }\n"
"\n"
// 添加记录到索引
"            _addRecordToIndex(record) {\n"
"                let keys;\n"
"\n"
"                if (Array.isArray(this.keyPath)) {\n"
"                    keys = this.keyPath.map(k => getNestedValue(record.value, k));\n"
"                } else {\n"
"                    keys = [getNestedValue(record.value, this.keyPath)];\n"
"                }\n"
"\n"
// 处理multiEntry
"                if (this.multiEntry && Array.isArray(keys[0])) {\n"
"                    keys = keys[0];\n"
"                }\n"
"\n"
"                for (const key of keys) {\n"
"                    if (this._indexMap.has(key)) {\n"
"                        if (this.unique) {\n"
"                            throw new Error(`Unique constraint error for index ${this.name}`);\n"
"                        }\n"
"                        this._indexMap.get(key).push(record.key);\n"
"                    } else {\n"
"                        this._indexMap.set(key, [record.key]);\n"
"                    }\n"
"                }\n"
"            }\n"
"\n"
// 根据索引获取记录
"            get(key) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    if (this._indexMap.has(key)) {\n"
"                        const primaryKeys = this._indexMap.get(key);\n"
// 对于非unique索引，返回第一个匹配的记录
"                        const record = this.store._records.find(r => r.key === primaryKeys[0]);\n"
"                        request._resolve(record ? record.value : undefined);\n"
"                    } else {\n"
"                        request._resolve(undefined);\n"
"                    }\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"\n"
// 打开游标 
"            openCursor(range, direction) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
// 创建基于索引的范围 
"                    let indexRange = range;\n"
"\n"
// 如果提供了range，使用它；否则使用整个索引范围 
"                    const cursor = new MockIDBCursor(this.store, indexRange, direction);\n"
"                    request._resolve(cursor);\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"        }\n"
"\n"
// 辅助函数：获取嵌套属性值 
"        function getNestedValue(obj, keyPath) {\n"
"            if (!obj || !keyPath) return undefined;\n"
"\n"
"            const keys = Array.isArray(keyPath) ? keyPath : keyPath.split('.');\n"
"            let value = obj;\n"
"\n"
"            for (const key of keys) {\n"
"                if (value === null || value === undefined) return undefined;\n"
"                value = value[key];\n"
"            }\n"
"\n"
"            return value;\n"
"        }\n"
"\n"
// 模拟IDBObjectStore 
"        class MockIDBObjectStore {\n"
"            constructor(db, name, options) {\n"
"                this.db = db;\n"
"                this.name = name;\n"
"                this.keyPath = options.keyPath;\n"
"                this.autoIncrement = options.autoIncrement || false;\n"
"                this._records = [];"
"                this._indexes = new Map();"
"                this._nextAutoIncrementKey = 1;\n"
"            }\n"
"\n"
"            addEventListener(type, callback) {\n"
"                alert('MockIDBObjectStore addEventListener');\n"
"            }\n"
"\n"
// 创建索引
"            createIndex(name, keyPath, options = {}) {\n"
"                if (this._indexes.has(name)) {\n"
"                    throw new Error(`Index ${name} already exists`);\n"
"                }\n"
"\n"
"                const index = new MockIDBIndex(this, name, keyPath, options.multiEntry, options.unique);\n"
"                this._indexes.set(name, index);\n"
"                return index;\n"
"            }\n"
"\n"
// 获取索引
"            index(name) {\n"
"                return this._indexes.get(name);\n"
"            }\n"
"\n"
// 删除索引
"            deleteIndex(name) {\n"
"                this._indexes.delete(name);\n"
"            }\n"
"\n"
// 添加记录
"            add(value, key) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    try {\n"
"                        let recordKey = key;\n"
"\n"
// 确定记录键
"                        if (recordKey === undefined && this.keyPath) {\n"
"                            recordKey = getNestedValue(value, this.keyPath);\n"
"                        }\n"
"\n"
"                        if (recordKey === undefined && this.autoIncrement) {\n"
"                            recordKey = this._nextAutoIncrementKey++;\n"
"                        }\n"
"\n"
"                        if (recordKey === undefined) {\n"
"                            throw new Error('Could not determine record key');\n"
"                        }\n"
"\n"
// 检查键是否已存在
"                        if (this._records.some(r => r.key === recordKey)) {\n"
"                            throw new Error(`Key ${recordKey} already exists`);\n"
"                        }\n"
"\n"
// 创建记录
"                        const record = {\n"
"                            key: recordKey,\n"
"                            value: structuredClone(value)\n"
"                        };\n"
"                        this._records.push(record);\n"
"\n"
// 更新索引
"                        this._indexes.forEach(index => index._addRecordToIndex(record));\n"
"\n"
"                        request._resolve(recordKey);\n"
"                    } catch (error) {\n"
"                        request._reject(error);\n"
"                    }\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"\n"
// 放置记录（添加或更新
"            put(value, key) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    try {\n"
"                        let recordKey = key;\n"
"\n"
// 确定记录键
"                        if (recordKey === undefined && this.keyPath) {\n"
"                            recordKey = getNestedValue(value, this.keyPath);\n"
"                        }\n"
"\n"
"                        if (recordKey === undefined && this.autoIncrement) {\n"
"                            recordKey = this._nextAutoIncrementKey++;\n"
"                        }\n"
"\n"
"                        if (recordKey === undefined) {\n"
"                            throw new Error('Could not determine record key');\n"
"                        }\n"
"\n"
// 检查是否存在该键
"                        const existingIndex = this._records.findIndex(r => r.key === recordKey);\n"
"\n"
// 创建或更新记录
"                        const record = {\n"
"                            key: recordKey,\n"
"                            value: structuredClone(value)\n"
"                        };\n"
"\n"
"                        if (existingIndex !== -1) {\n"
"                            this._records[existingIndex] = record;\n"
"                        } else {\n"
"                            this._records.push(record);\n"
"                        }\n"
"\n"
// 重新构建所有索引
"                        this._indexes.forEach(index => index._buildIndex());\n"
"\n"
"                        request._resolve(recordKey);\n"
"                    } catch (error) {\n"
"                        request._reject(error);\n"
"                    }\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"\n"
// 获取记录
"            get(key) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    const record = this._records.find(r => r.key === key);\n"
"                    request._resolve(record ? structuredClone(record.value) : undefined);\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"\n"
// 删除记录
"            delete(key) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    const index = this._records.findIndex(r => r.key === key);\n"
"\n"
"                    if (index !== -1) {\n"
"                        this._records.splice(index, 1);\n"
// 重新构建所有索引
"                        this._indexes.forEach(index => index._buildIndex());\n"
"                        request._resolve(undefined);\n"
"                    } else {\n"
"                        request._reject(`Record with key ${key} not found`);\n"
"                    }\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"\n"
// 清空存储
"            clear() {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    this._records = [];\n"
// 清空所有索引
"                    this._indexes.forEach(index => index._buildIndex());\n"
"                    request._resolve(undefined);\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"\n"
// 打开游标
"            openCursor(range, direction) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    const cursor = new MockIDBCursor(this, range, direction);\n"
"                    request._resolve(cursor);\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"        }\n"
"\n"
// 模拟IDBTransaction
"        class MockIDBTransaction {\n"
"            constructor(db, storeNames, mode = 'readonly') {\n"
"                this.db = db;\n"
"                this.storeNames = Array.isArray(storeNames) ? storeNames : [storeNames];\n"
"                this.mode = mode;\n"
"                this.oncomplete = null;\n"
"                this.onerror = null;\n"
"                this.onabort = null;\n"
"                this._active = true;\n"
"            }\n"
"\n"
"            addEventListener(type, callback) {\n"
"                //alert('MockIDBTransaction addEventListener');\n"
"                if (type === 'complete') this.oncomplete = callback;\n"
"                if (type === 'error') this.onerror = callback;\n"
"                if (type === 'abort') this.onabort = callback;\n"
"            }\n"
"            removeEventListener(type) {\n"
"                if (type === 'complete') this.oncomplete = null;\n"
"                if (type === 'error') this.onerror = null;\n"
"                if (type === 'abort') this.onabort = null;\n"
"            }\n"
"\n"
// 获取对象存储
"            objectStore(name) {\n"
"                if (!this._active) {\n"
"                    throw new Error('Transaction is no longer active');\n"
"                }\n"
"\n"
"                if (!this.storeNames.includes(name)) {\n"
"                    throw new Error(`Object store ${name} not in transaction scope`);\n"
"                }\n"
"\n"
"                return this.db.objectStore(name);\n"
"            }\n"
"\n"
// 提交事务
"            commit() {\n"
"                if (!this._active) return;\n"
"\n"
"                this._active = false;\n"
"                if (typeof this.oncomplete === 'function') {\n"
"                    this.oncomplete({\n"
"                        target: this\n"
"                    });\n"
"                }\n"
"            }\n"
"\n"
// 中止事务
"            abort() {\n"
"                if (!this._active) return;\n"
"\n"
"                this._active = false;\n"
"                if (typeof this.onabort === 'function') {\n"
"                    this.onabort({\n"
"                        target: this\n"
"                    });\n"
"                }\n"
"            }\n"
"        }\n"
"\n"
// 模拟IDBDatabase
"        class MockIDBDatabase {\n"
"            constructor(name, version) {\n"
"                this.name = name;\n"
"                this.version = version;\n"
"                this.objectStoreNames = new Set();\n"
"                this._objectStores = new Map();"
"                this.onversionchange = null;\n"
"                this.onclose = null;\n"
"            }\n"
"\n"
"            addEventListener(type, callback) {\n"
"                //alert('MockIDBDatabase addEventListener');\n"
"                if (type === 'versionchange') this.onversionchange = callback;\n"
"                if (type === 'close') this.onclose = callback;\n"
"            }\n"
"            removeEventListener(type) {\n"
"                if (type === 'versionchange') this.onversionchange = null;\n"
"                if (type === 'close') this.onclose = null;\n"
"            }\n"
"\n"
// 创建对象存储
"            createObjectStore(name, options = {}) {\n"
"                if (this._objectStores.has(name)) {\n"
"                    throw new Error(`Object store ${name} already exists`);\n"
"                }\n"
"\n"
"                const store = new MockIDBObjectStore(this, name, options);\n"
"                this._objectStores.set(name, store);\n"
"                this.objectStoreNames.add(name);\n"
"                return store;\n"
"            }\n"
"\n"
// 删除对象存储
"            deleteObjectStore(name) {\n"
"                if (!this._objectStores.has(name)) {\n"
"                    throw new Error(`Object store ${name} does not exist`);\n"
"                }\n"
"\n"
"                this._objectStores.delete(name);\n"
"                this.objectStoreNames.delete(name);\n"
"            }\n"
"\n"
// 获取对象存储
"            objectStore(name) {\n"
"                return this._objectStores.get(name);\n"
"            }\n"
"\n"
// 开始事务
"            transaction(storeNames, mode) {\n"
"                return new MockIDBTransaction(this, storeNames, mode);\n"
"            }\n"
"\n"
// 关闭数据库
"            close() {\n"
"                if (typeof this.onclose === 'function') {\n"
"                    this.onclose({\n"
"                        target: this\n"
"                    });\n"
"                }\n"
"            }\n"
"        }\n"
"\n"
// 模拟 indexedDB 全局对象
"        const mockIndexedDB = {\n"
"            databases: new Map(),"
"            version: 1,\n"
"\n"
"            onsuccess: null,\n"
"            onerror: null,\n"
"            addEventListener: function(type, callback) {\n"
"                if (type === 'success') this.onsuccess = callback;\n"
"                if (type === 'error') this.onerror = callback;\n"
"            },\n"
"            removeEventListener: function(type) {\n"
"                if (type === 'success') this.onsuccess = null;\n"
"                if (type === 'error') this.onerror = null;\n"
"            },\n"
"\n"
// 打开数据库
"            open(name, version = 1) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    try {\n"
"                        let db;\n"
"\n"
"                        if (this.databases.has(name)) {\n"
"                            db = this.databases.get(name);\n"
"\n"
// 如果版本号低于现有版本，触发versionchange
"                            if (version < db.version) {\n"
"                                if (typeof db.onversionchange === 'function') {\n"
"                                    db.onversionchange({\n"
"                                        target: db,\n"
"                                        newVersion: version,\n"
"                                        oldVersion: db.version\n"
"                                    });\n"
"                                }\n"
"                                request._reject('Version lower than current');\n"
"                                return;\n"
"                            }\n"
"\n"
// 如果版本号相同，直接返回现有数据库
"                            if (version === db.version) {\n"
"                                request._resolve(db);\n"
"                                return;\n"
"                            }\n"
"\n"
// 版本号高于现有版本，视为升级
"                            db.version = version;\n"
"                        } else {\n"
// 创建新数据库
"                            db = new MockIDBDatabase(name, version);\n"
"                            this.databases.set(name, db);\n"
"                        }\n"
"\n"
"                        request._resolve(db);\n"
"                    } catch (error) {\n"
"                        request._reject(error);\n"
"                    }\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            },\n"
"\n"
// 删除数据库
"            deleteDatabase(name) {\n"
"                const request = new MockIDBRequest();\n"
"\n"
"                setTimeout(() => {\n"
"                    if (this.databases.has(name)) {\n"
"                        const db = this.databases.get(name);\n"
"                        this.databases.delete(name);\n"
"\n"
"                        if (typeof db.onversionchange === 'function') {\n"
"                            db.onversionchange({\n"
"                                target: db,\n"
"                                newVersion: null,\n"
"                                oldVersion: db.version\n"
"                            });\n"
"                        }\n"
"\n"
"                        request._resolve({});\n"
"                    } else {\n"
"                        request._resolve({});\n"
"                    }\n"
"                }, 0);\n"
"\n"
"                return request;\n"
"            }\n"
"        };\n"
"\n"
// 将模拟的IndexedDB API暴露到全局
"        window.indexedDB = mockIndexedDB;\n"
"        window.IDBRequest = MockIDBRequest;\n"
"        window.IDBDatabase = MockIDBDatabase;\n"
"        window.IDBObjectStore = MockIDBObjectStore;\n"
"        window.IDBTransaction = MockIDBTransaction;\n"
"        window.IDBIndex = MockIDBIndex;\n"
"        window.IDBCursor = MockIDBCursor;\n"
"        window.IDBKeyRange = MockIDBKeyRange;\n"
// 为了让 typeof indexedDB === 'object' 且符合 IDBFactory 接口习惯，也可以挂载为 IDBFactory 的实例
// 但一般网站只检测 window.indexedDB 是否存在以及是否具有 .open 方法
// 可选：定义其他构造器在全局（有些网站可能会用 new IDBDatabase(...) 等，但极少）
// 这里为了简单，不强制要求，因为大多数网站只调用 indexedDB.open()
    "    })();\n"
    "} else {\n"
    "}\n"
;

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

    content::ThreadCall::callUiThreadAsync(MB_FROM_HERE, [self, id, customMsg, requestString, idInfo] {
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
    std::string injectScriptStr(injectScript);
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