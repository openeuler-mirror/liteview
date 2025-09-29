// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef mbnet_WebURLLoaderImplCurl_h
#define mbnet_WebURLLoaderImplCurl_h

#include "third_party/blink/public/platform/web_url_loader.h"
#include "third_party/blink/public/platform/scheduler/web_resource_loading_task_runner_handle.h"
#include "third_party/blink/renderer/platform/loader/fetch/loader_freeze_mode.h"

namespace base {
class WaitableEvent;
}

namespace blink {
class WebURLRequest;
class WebURLLoaderClient;
}

namespace mbnet {

class WebURLLoaderInternal;
class BlobResourceLoader;

using ResTaskRunnerHandle = blink::scheduler::WebResourceLoadingTaskRunnerHandle;

class WebURLLoaderImplCurl : public blink::WebURLLoader {
public:
    WebURLLoaderImplCurl(
        std::unique_ptr<ResTaskRunnerHandle> freezableTaskRunnerHandle,
        std::unique_ptr<ResTaskRunnerHandle> unfreezableTaskRunnerHandle,
        base::WaitableEvent* terminateSyncLoadEvent);
    ~WebURLLoaderImplCurl() override;

    // --WebURLLoader methods:
    void LoadSynchronously(std::unique_ptr<network::ResourceRequest> request, scoped_refptr<blink::WebURLRequestExtraData> url_request_extra_data,
        bool pass_response_pipe_to_client, bool no_mime_sniffing, base::TimeDelta timeout_interval, blink::WebURLLoaderClient*, blink::WebURLResponse&,
        absl::optional<blink::WebURLError>& error, blink::WebData&, int64_t& encoded_data_length, int64_t& encoded_body_length, blink::WebBlobInfo& downloaded_blob,
        std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resource_load_info_notifier_wrapper) override;

    void LoadAsynchronously(
        std::unique_ptr<network::ResourceRequest> request,
        scoped_refptr<blink::WebURLRequestExtraData> extraData,
        bool noMimeSniffing,
        std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper,
        blink::WebURLLoaderClient* client) override;

    void Freeze(blink::LoaderFreezeMode mode) override;
    void DidChangePriority(blink::WebURLRequest::Priority, int intra_priority_value) override;
    scoped_refptr<base::SingleThreadTaskRunner> GetTaskRunnerForBodyLoader() override;
    //--

    void setNotAutoDestroy()
    {
        m_isAutoDestroy = false;
    }


private:
    void init();

    //mojo::ScopedDataPipeConsumerHandle m_responseBodyConsumerDataPipe;

    bool m_isAutoDestroy = true; // 一般都是自动销毁，不过main frame的例外

    bool* m_hadDestroied = nullptr;
    int m_jobId = 0;

    mbnet::BlobResourceLoader* m_blobLoader = nullptr;

    //blink::KURL m_url;
    blink::WebURLLoaderClient* m_client = nullptr;
    blink::LoaderFreezeMode m_mode = blink::LoaderFreezeMode::kNone;

    //const std::unique_ptr<blink::scheduler::WebResourceLoadingTaskRunnerHandle> m_freezableTaskRunnerHandle;
    //const std::unique_ptr<blink::scheduler::WebResourceLoadingTaskRunnerHandle> m_unfreezableTaskRunnerHandle;
    scoped_refptr<base::SingleThreadTaskRunner> m_freezableTaskRunner;

    base::WaitableEvent* m_terminateSyncLoadEvent = nullptr;

    base::WeakPtrFactory<WebURLLoaderImplCurl> m_weakPtr{ this };
};

}  // namespace content

#endif  // WebURLLoaderImplCurl_h
