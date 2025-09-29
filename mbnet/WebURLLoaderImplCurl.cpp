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


#include "mbnet/WebURLLoaderImplCurl.h"

#include "mbnet/WebURLLoaderInternal.h"
#include "mbnet/WebURLRequestExtraDataWrap.h"
#include "mbnet/WebURLLoaderManager.h"
#include "mbnet/BlobResourceLoader.h"
#include "content/renderer/BlobURLStoreImpl.h"

#include "third_party/blink/public/platform/web_url_request_extra_data.h"
#include "third_party/blink/public/platform/resource_load_info_notifier_wrapper.h"
#include "third_party/blink/public/platform/web_data.h"
#include "services/network/public/cpp/resource_request.h"
#include "third_party/blink/renderer/platform/wtf/text/wtf_string.h"
#include "base/strings/string_util.h"
#include <windows.h>

#ifndef NDEBUG
//DEFINE_DEBUG_ONLY_GLOBAL(WTF::RefCountedLeakCounter, webURLLoaderImplCurlCount, ("WebURLLoaderImplCurl"));
#endif

namespace mbnet {

class BlinkSynchronousLoader : public blink::WebURLLoaderClient {
public:
    BlinkSynchronousLoader(absl::optional<blink::WebURLError>&, blink::WebURLResponse&, std::vector<char>*);
    ~BlinkSynchronousLoader();

    void DidReceiveResponse(const blink::WebURLResponse&) override;
    void DidReceiveData(const char* data, int dataLength) override;
    void DidFinishLoading(base::TimeTicks finish_time,
        int64_t total_encoded_data_length, 
        int64_t total_encoded_body_length,
        int64_t total_decoded_body_length, 
        bool should_report_corb_blocking, 
        absl::optional<bool> pervasive_payload_requested) override;
    void DidFail(const blink::WebURLError&,
        base::TimeTicks finish_time, 
        int64_t total_encoded_data_length, 
        int64_t total_encoded_body_length,
        int64_t total_decoded_body_length) override;

    void DidStartLoadingResponseBody(mojo::ScopedDataPipeConsumerHandle responseBodyConsumer) override;

private:
    absl::optional<blink::WebURLError>& m_error;
    blink::WebURLResponse& m_response;
    std::vector<char>* m_data;
};

inline BlinkSynchronousLoader::BlinkSynchronousLoader(absl::optional<blink::WebURLError>& error, blink::WebURLResponse& response, std::vector<char>* data)
    : m_error(error)
    , m_response(response)
    , m_data(data)
{
}

inline BlinkSynchronousLoader::~BlinkSynchronousLoader()
{

}

inline void BlinkSynchronousLoader::DidReceiveResponse(const blink::WebURLResponse& response)
{
    m_response = response;
}

inline void BlinkSynchronousLoader::DidReceiveData(const char* data, int dataLength)
{
    m_data->insert(m_data->end(), data, data + dataLength);
}

inline void BlinkSynchronousLoader::DidStartLoadingResponseBody(mojo::ScopedDataPipeConsumerHandle responseBodyConsumer)
{
    DebugBreak();
//     uint32_t num_bytes_consumed = 0;
//     while (reader.ShouldContinueReading()) {
//         const void* buffer = nullptr;
//         uint32_t available = 0;
//         MojoResult result = handle->BeginReadData(&buffer, &available, MOJO_READ_DATA_FLAG_NONE);
//         if (result == MOJO_RESULT_SHOULD_WAIT) {
//             handle_watcher.ArmOrNotify();
//             return;
//         }
//         if (result == MOJO_RESULT_FAILED_PRECONDITION) {
//             reader.FinishedReading(/*has_error=*/false);
//             return;
//         }
//         if (result != MOJO_RESULT_OK) {
//             reader.FinishedReading(/*has_error=*/true);
//             return;
//         }
//         const uint32_t chunk_size = network::features::GetLoaderChunkSize();
//         DCHECK_LE(num_bytes_consumed, chunk_size);
//         available = std::min(available, chunk_size - num_bytes_consumed);
//         if (available == 0) {
//             // We've already consumed many bytes in this task. Defer the remaining
//             // to the next task.
//             result = handle->EndReadData(0);
//             DCHECK_EQ(result, MOJO_RESULT_OK);
//             handle_watcher.ArmOrNotify();
//             return;
//         }
//         num_bytes_consumed += available;
//         if (!reader.DataReceived(static_cast<const char*>(buffer), available))
//             return;
//         result = handle->EndReadData(available);
//         DCHECK_EQ(MOJO_RESULT_OK, result);
//     }
}

inline void BlinkSynchronousLoader::DidFinishLoading(base::TimeTicks finish_time,
    int64_t total_encoded_data_length,
    int64_t total_encoded_body_length,
    int64_t total_decoded_body_length,
    bool should_report_corb_blocking,
    absl::optional<bool> pervasive_payload_requested)
{
}

inline void BlinkSynchronousLoader::DidFail(const blink::WebURLError& error,
    base::TimeTicks finish_time,
    int64_t total_encoded_data_length,
    int64_t total_encoded_body_length,
    int64_t total_decoded_body_length)
{
    m_error = error;
}

//------

WebURLLoaderImplCurl::WebURLLoaderImplCurl(
    std::unique_ptr<ResTaskRunnerHandle> freezableTaskRunnerHandle,
    std::unique_ptr<ResTaskRunnerHandle> unfreezableTaskRunnerHandle,
    base::WaitableEvent* terminateSyncLoadEvent)
    //: m_freezableTaskRunner(std::move(freezableTaskRunnerHandle))
    //, m_unfreezableTaskRunner(std::move(unfreezableTaskRunnerHandle))
    : m_terminateSyncLoadEvent(terminateSyncLoadEvent)
{
    m_jobId = -1;
#ifndef NDEBUG
    //webURLLoaderImplCurlCount.increment();
#endif
    const scoped_refptr<base::SingleThreadTaskRunner> currentRunner = base::ThreadTaskRunnerHandle::Get();
    scoped_refptr<base::SingleThreadTaskRunner> runner = freezableTaskRunnerHandle->GetTaskRunner();
    if (runner->BelongsToCurrentThread())
        m_freezableTaskRunner = currentRunner; // 有时候就算runner是本线程的，但和ThreadTaskRunnerHandle::Get还不是同一个实例
    else
        m_freezableTaskRunner = runner;
}

WebURLLoaderImplCurl::~WebURLLoaderImplCurl()
{
#ifndef NDEBUG
    //webURLLoaderImplCurlCount.decrement();
#endif

    mbnet::WebURLLoaderManager* mgr = mbnet::WebURLLoaderManager::sharedInstance();
    if (!mgr)
        return;
    if (m_isAutoDestroy)
        mgr->cancel(m_jobId);
}

void WebURLLoaderImplCurl::init()
{
    m_hadDestroied = nullptr;
    m_jobId = 0;
}

static bool shouldContentSniffURL(const GURL& url)
{
    // We shouldn't content sniff file URLs as their MIME type should be established via their extension.
    return !url.SchemeIs("file");
}

static bool checkIsResURL(const GURL& url)
{
    std::string urlStr = url.possibly_invalid_spec();
    urlStr = base::ToLowerASCII(urlStr);

    if (std::string::npos != urlStr.find("jpg") ||
        std::string::npos != urlStr.find("gif") ||
        std::string::npos != urlStr.find("bmp") ||
        std::string::npos != urlStr.find("png") ||
        std::string::npos != urlStr.find("mp3") ||
        std::string::npos != urlStr.find("mp4")
        )
        return true;
    return false;
}

void WebURLLoaderImplCurl::LoadSynchronously(
    std::unique_ptr<network::ResourceRequest> request,
    scoped_refptr<blink::WebURLRequestExtraData> urlRequestExtraData,
    bool passResponsePipeToClient,
    bool noMimeSniffing,
    base::TimeDelta timeoutInterval,
    blink::WebURLLoaderClient* client,
    blink::WebURLResponse& response,
    absl::optional<blink::WebURLError>& error,
    blink::WebData& data,
    int64_t& encodedDataLength,
    int64_t& encodedBodyLength,
    blink::WebBlobInfo& downloadedBlob,
    std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper
    )
{
    if (!mbnet::WebURLLoaderManager::sharedInstance())
        return;

    init();

    GURL url = request->url;
    if (url.SchemeIs("blob")) {
//         ::mojo::Remote<::blink::mojom::blink::Blob>* blob = content::BlobURLStoreSet::get()->getBlobByUrl(url.possibly_invalid_spec());
//         if (!blob)
//             return;
// 
//         m_blobLoader = mbnet::BlobResourceLoader::createAsync(url, client);
//         m_blobLoader->start();
        DebugBreak();
        return;
    }

    mbnet::WebURLLoaderManager* netManager = mbnet::WebURLLoaderManager::sharedInstance();
    mbnet::WebURLLoaderManager::IoThreadType type = mbnet::WebURLLoaderManager::kIoThreadTypeSync; 
    // checkIsResURL(url) ? mbnet::WebURLLoaderManager::kIoThreadTypeRes : mbnet::WebURLLoaderManager::kIoThreadTypeOther;

    std::vector<char> buffer;
    mbnet::BlinkSynchronousLoader syncLoader(error, response, &buffer);
    mbnet::WebURLLoaderInternal* job = new mbnet::WebURLLoaderInternal(netManager->getIoThread(type), this, std::move(request), &syncLoader, false, shouldContentSniffURL(url));
    netManager->dispatchSynchronousJob(job, m_terminateSyncLoadEvent);

    data.Assign(buffer.data(), buffer.size());
}

void WebURLLoaderImplCurl::LoadAsynchronously(
    std::unique_ptr<network::ResourceRequest> request,
    scoped_refptr<blink::WebURLRequestExtraData> extraData,
    bool noMimeSniffing,
    std::unique_ptr<blink::ResourceLoadInfoNotifierWrapper> resourceLoadInfoNotifierWrapper,
    blink::WebURLLoaderClient* client
    )
{
    mbnet::WebURLLoaderManager* netManager = mbnet::WebURLLoaderManager::sharedInstance();
    WebURLRequestExtraDataWrap* extraDataWrap = (WebURLRequestExtraDataWrap*)extraData.get();
    if (!netManager) {
        MojoClose(extraDataWrap->dataPipeProducerHandle);
        return;
    }

    init();

    GURL url = request->url;
    mbnet::WebURLLoaderManager::IoThreadType type = checkIsResURL(url) ? mbnet::WebURLLoaderManager::kIoThreadTypeRes : mbnet::WebURLLoaderManager::kIoThreadTypeOther;

    int64_t mbwebviewId = extraDataWrap->mbwebviewId;
    if (url.SchemeIs("blob") && !extraDataWrap->isDownload()) {
        ::mojo::Remote<::blink::mojom::blink::Blob>* blob = content::BlobURLStoreSet::get()->getBlobByUrl(url.possibly_invalid_spec());
        if (!blob)
            return;

        m_blobLoader = mbnet::BlobResourceLoader::createAsync(mbwebviewId, url, client);
        m_blobLoader->start();
        return;
    }

    WebURLLoaderInternal* job = new WebURLLoaderInternal(netManager->getIoThread(type), this, std::move(request), client, false, shouldContentSniffURL(url));
    job->m_mbwebviewId = mbwebviewId;
    job->m_dataPipeProducerHandle = extraDataWrap->dataPipeProducerHandle;
    job->m_frameType = extraDataWrap->frameType;
    job->m_downloadName = extraDataWrap->releaseDownloadName();

    int jobIds = 0;
//     if (WTF::IsMainThread()) {
//         jobIds = netManager->addAsynchronousJob(job);
//     } else {
//         content::ThreadCall::callBlinkThreadAsync(FROM_HERE, [] {
//             
//         });
//     }
    jobIds = netManager->addAsynchronousJob(job);
    if (0 == jobIds)
        return;
    m_jobId = jobIds;
    job->m_jobId = m_jobId;

    // 执行完add后，this可能被销毁，当dataurl的时候
#if 0
//     blink::KURL url = (blink::KURL)requestNew.url();
//     Vector<UChar> host = WTF::ensureUTF16UChar(url.host());
// 
//     if (!url.isValid() || !url.protocolIsData()) {
//         WTF::String outstr = String::format("WebURLLoaderImpl.loadAsynchronously: %p %ws\n", this, WTF::ensureUTF16UChar(url.string()).data());
//         OutputDebugStringW(outstr.charactersWithNullTermination().data());
//     }
#endif
}

void WebURLLoaderImplCurl::DidChangePriority(blink::WebURLRequest::Priority, int intra_priority_value)
{

}

scoped_refptr<base::SingleThreadTaskRunner> WebURLLoaderImplCurl::GetTaskRunnerForBodyLoader()
{
    return m_freezableTaskRunner;
}

void WebURLLoaderImplCurl::Freeze(blink::LoaderFreezeMode mode)
{
    m_mode = mode;
//     if (m_mode != blink::LoaderFreezeMode::kNone || !m_client)
//         return;
//     m_freezableTaskRunner->GetTaskRunner()->PostTask(FROM_HERE, WTF::BindOnce(&WebURLLoaderImplCurl::fail, m_weakPtr.GetWeakPtr()));
}


} // content