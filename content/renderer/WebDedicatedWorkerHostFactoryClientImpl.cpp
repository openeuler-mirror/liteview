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


#include "content/renderer/WebDedicatedWorkerHostFactoryClientImpl.h"

#include "content/renderer/BlobURLStoreImpl.h"
#include "content/common/CreateAndBindTempl.h"
#include "third_party/blink/public/platform/web_worker_fetch_context.h"
#include "third_party/blink/public/platform/web_dedicated_worker.h"
#include "services/network/public/cpp/cross_origin_embedder_policy.h"
#include "gen/third_party/blink/public/mojom/loader/code_cache.mojom-blink.h"
#include "gen/third_party/blink/public/mojom/reporting/reporting.mojom-blink.h"
#include <windows.h>

namespace content {

class CodeCacheHostImpl : public ::blink::mojom::blink::CodeCacheHost {
public:
    CodeCacheHostImpl()
    {

    }

    ~CodeCacheHostImpl()
    {

    }

    void DidGenerateCacheableMetadata(::blink::mojom::blink::CodeCacheType cache_type, const ::blink::KURL& url, ::base::Time expected_response_time, ::mojo_base::BigBuffer data) override
    {
        DebugBreak();
    }

    //using FetchCachedCodeCallback = base::OnceCallback<void(::base::Time, ::mojo_base::BigBuffer)>;
    void FetchCachedCode(::blink::mojom::blink::CodeCacheType cache_type, const ::blink::KURL& url, ::blink::mojom::blink::CodeCacheHost::FetchCachedCodeCallback callback) override
    {
        DebugBreak();
    }

    void ClearCodeCacheEntry(::blink::mojom::blink::CodeCacheType cache_type, const ::blink::KURL& url) override
    {
        DebugBreak();
    }

    void DidGenerateCacheableMetadataInCacheStorage(
        const ::blink::KURL& url,
        ::base::Time expected_response_time,
        ::mojo_base::BigBuffer data,
        const ::scoped_refptr<const ::blink::SecurityOrigin>& cache_storage_origin,
        const WTF::String& cache_storage_cache_name) override
    {
        DebugBreak();
    }
};

class ReportingServiceProxyImpl : public ::blink::mojom::blink::ReportingServiceProxy {
public:
    void QueueInterventionReport(
        const ::blink::KURL& url, const WTF::String& id, const WTF::String& message, const WTF::String& source_file, int32_t line_number, int32_t column_number) override
    {

    }

    void QueueDeprecationReport(const ::blink::KURL& url, const WTF::String& id, absl::optional<::base::Time> anticipatedRemoval, const WTF::String& message,
        const WTF::String& source_file, int32_t line_number, int32_t column_number) override
    {

    }

    void QueueCspViolationReport(const ::blink::KURL& url, const WTF::String& group, const WTF::String& document_url, const WTF::String& referrer,
        const WTF::String& blocked_url, const WTF::String& effective_directive, const WTF::String& original_policy, const WTF::String& source_file,
        const WTF::String& script_sample, const WTF::String& disposition, uint16_t status_code, int32_t line_number, int32_t column_number) override
    {

    }

    void QueuePermissionsPolicyViolationReport(const ::blink::KURL& url, const WTF::String& policy_id, const WTF::String& disposition, const WTF::String& message,
        const WTF::String& source_file, int32_t line_number, int32_t column_number)
        override
    {

    }

    void QueueDocumentPolicyViolationReport(const ::blink::KURL& url, const WTF::String& group, const WTF::String& policy_id, const WTF::String& disposition,
        const WTF::String& message, const WTF::String& source_file, int32_t line_number, int32_t column_number) override
    {

    }
};

class DedicatedWorkerHostBrowserInterfaceBroker : public ::blink::mojom::BrowserInterfaceBroker {
public:
    DedicatedWorkerHostBrowserInterfaceBroker()
    {

    }

    void setOrgin(::scoped_refptr<const ::blink::SecurityOrigin> origin)
    {
        m_origin = origin;
    }

private:
    void GetInterface(::mojo::GenericPendingReceiver receiver) override // ²Î¿¼WebLocalFrameClientImpl::GetInterface
    {
        std::string output("DedicatedWorkerHostBrowserInterfaceBroker::GetInterface: ");
        std::string name = receiver.interface_name().has_value() ? receiver.interface_name().value() : "no-name";
        output += name;
        output += "\n";
        OutputDebugStringA(output.c_str());

        if ("blink.mojom.CodeCacheHost" == name) {
            createAndBindBrokerProxy<::blink::mojom::blink::CodeCacheHost, CodeCacheHostImpl>(receiver.PassPipe());
        } else if ("blink.mojom.ReportingServiceProxy" == name) {
            createAndBindBrokerProxy<::blink::mojom::blink::ReportingServiceProxy, ReportingServiceProxyImpl>(receiver.PassPipe());
        } else if ("blink.mojom.BlobURLStore" == name) {
            createAndBindInterface<::blink::mojom::blink::BlobURLStore, BlobURLStoreImpl>(std::move(receiver.PassPipe()), m_origin);
        } else
            DebugBreak();
    }

    ::scoped_refptr<const ::blink::SecurityOrigin> m_origin;
};

class DedicatedWorkerHostImpl : public blink::mojom::blink::DedicatedWorkerHost {
    ~DedicatedWorkerHostImpl() override
    {

    }
};

WebDedicatedWorkerHostFactoryClientImpl::WebDedicatedWorkerHostFactoryClientImpl(blink::WebDedicatedWorker* worker) 
    : m_browserInterfaceBrokerImpl(new DedicatedWorkerHostBrowserInterfaceBroker())
    , m_browserInterfaceBroker(new DedicatedWorkerHostBrowserInterfaceBroker())
    , m_dedicatedWorkerHost(new DedicatedWorkerHostImpl())
    , m_weakFactory(this)
{
    m_worker = worker;
}

WebDedicatedWorkerHostFactoryClientImpl::~WebDedicatedWorkerHostFactoryClientImpl()
{

}

void WebDedicatedWorkerHostFactoryClientImpl::CreateWorkerHostDeprecated(
    const blink::DedicatedWorkerToken& dedicatedWorkerToken,
    const blink::WebURL& scriptUrl,
    blink::WebDedicatedWorkerHostFactoryClient::CreateWorkerHostCallback callback)
{
    mojo::PendingRemote<blink::mojom::blink::DedicatedWorkerHost> dedicatedWorkerHost;
    mojo::PendingRemote<blink::mojom::BrowserInterfaceBroker> browserInterfaceBroker;

    blink::WebSecurityOrigin origin = blink::WebSecurityOrigin::Create(scriptUrl);
    m_browserInterfaceBrokerImpl->setOrgin(origin);
    mojo::PendingReceiver<blink::mojom::BrowserInterfaceBroker> pendingBroker = browserInterfaceBroker.InitWithNewPipeAndPassReceiver();
    m_browserInterfaceBroker.Bind(std::move(pendingBroker));

    mojo::PendingReceiver<blink::mojom::blink::DedicatedWorkerHost> pendingWorkerHost = dedicatedWorkerHost.InitWithNewPipeAndPassReceiver();
    m_dedicatedWorkerHost.Bind(std::move(pendingWorkerHost));

    m_worker->OnWorkerHostCreated(std::move(browserInterfaceBroker), std::move(dedicatedWorkerHost));

    base::WeakPtr<WebDedicatedWorkerHostFactoryClientImpl> weak = m_weakFactory.GetWeakPtr();

    base::ThreadTaskRunnerHandle::Get()->PostTask(FROM_HERE, base::BindOnce([] (
        blink::WebDedicatedWorkerHostFactoryClient::CreateWorkerHostCallback callback,
        base::WeakPtr<WebDedicatedWorkerHostFactoryClientImpl> self) {
        if (self.get()) {
            std::move(callback).Run(network::CrossOriginEmbedderPolicy(), 
                blink::CrossVariantMojoRemote<blink::mojom::BackForwardCacheControllerHostInterfaceBase>());
        }
    }, std::move(callback), std::move(weak)));
}

void WebDedicatedWorkerHostFactoryClientImpl::CreateWorkerHost(const blink::DedicatedWorkerToken& dedicatedWorkerToken, const blink::WebURL& scriptUrl,
    network::mojom::CredentialsMode credentialsMode, const blink::WebFetchClientSettingsObject& fetchClientSettingsObject,
    blink::CrossVariantMojoRemote<blink::mojom::BlobURLTokenInterfaceBase> blobUrlToken)
{
    DebugBreak();
}

scoped_refptr<blink::WebWorkerFetchContext> WebDedicatedWorkerHostFactoryClientImpl::CloneWorkerFetchContext(blink::WebWorkerFetchContext*, scoped_refptr<base::SingleThreadTaskRunner>)
{
    DebugBreak();
    return nullptr;
}

}