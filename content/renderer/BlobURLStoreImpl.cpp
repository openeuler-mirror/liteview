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


#include "content/renderer/BlobURLStoreImpl.h"

#include "content/common/ThreadCall.h"
#include "gen/services/network/public/mojom/url_loader_factory.mojom-blink.h"
#include "content/common/CreateAndBindTempl.h"
#include "base/functional/bind.h"

bool blink::mojom::blink::BlobURLStore::Register(
    ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob,
    const ::blink::KURL& url,
    const ::base::UnguessableToken& unsafe_agent_cluster_id,
    const absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site)
{
    return false;
}

namespace content {

BlobURLStoreSet* BlobURLStoreSet::get()
{
    static BlobURLStoreSet* s_inst = nullptr;
    if (s_inst)
        return s_inst;
    s_inst = new BlobURLStoreSet();
    return s_inst;
}

void BlobURLStoreSet::addUrlBlob(const std::string& url, const std::string& securityOriginToken, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob)
{
    UrlToBlobs::iterator it = m_urlToBlobs.find(url);
    CHECK(it == m_urlToBlobs.end());

    SecurityOriginAndBlob* securityOriginAndBlob = new SecurityOriginAndBlob();
    securityOriginAndBlob->securityOriginToken = securityOriginToken;

    //::mojo::Remote<::blink::mojom::blink::Blob>* blobRemote = new ::mojo::Remote<::blink::mojom::blink::Blob>();
    securityOriginAndBlob->blob.Bind(std::move(blob));
    securityOriginAndBlob->blob.set_disconnect_handler(base::BindOnce([](const std::string& url) {
        BlobURLStoreSet::get()->removeUrlBlob(url);
    }, url));
    m_urlToBlobs[url] = securityOriginAndBlob;
}

void BlobURLStoreSet::removeUrlBlob(const std::string& url)
{
    base::SequencedTaskRunner::GetCurrentDefault()->PostDelayedTask(FROM_HERE, base::BindOnce([](BlobURLStoreSet* self, const std::string& url) {
        UrlToBlobs::iterator it = self->m_urlToBlobs.find(url);
        if (it == self->m_urlToBlobs.end())
            return;
        SecurityOriginAndBlob* securityOriginAndBlob = it->second;
        delete securityOriginAndBlob;

        self->m_urlToBlobs.erase(it);
    }, base::Unretained(this), url), base::Seconds(6));
}

void BlobURLStoreSet::removeBySecurityOriginToken(const std::string& securityOriginToken)
{
    for (UrlToBlobs::iterator it = m_urlToBlobs.begin(); it != m_urlToBlobs.end(); ) {
        SecurityOriginAndBlob* securityOriginAndBlob = it->second;
        if (securityOriginAndBlob->securityOriginToken == securityOriginToken) {
            SecurityOriginAndBlob* securityOriginAndBlob = it->second;
            m_urlToBlobs.erase(it++);
            delete securityOriginAndBlob;
        } else {
            ++it;
        }
    }
}

::mojo::Remote<::blink::mojom::blink::Blob>* BlobURLStoreSet::getBlobByUrl(const std::string& url)
{
    UrlToBlobs::iterator it = m_urlToBlobs.find(url);
    if (it == m_urlToBlobs.end())
        return nullptr;
    //::mojo::Remote<::blink::mojom::blink::Blob>* ret = it->second;
    SecurityOriginAndBlob* securityOriginAndBlob = it->second;
    return &securityOriginAndBlob->blob;
}

//-----

BlobURLStoreImpl::BlobURLStoreImpl(const ::scoped_refptr<const ::blink::SecurityOrigin>& origin)
    : m_origin(origin)
{

}

BlobURLStoreImpl::~BlobURLStoreImpl()
{
    BlobURLStoreSet::get()->removeBySecurityOriginToken(m_origin->ToString().Utf8());
}

bool BlobURLStoreImpl::Register(
    ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob,
    const ::blink::KURL& url,
    const ::base::UnguessableToken& unsafe_agent_cluster_id,
    const absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site)
{
//     std::string urlStr = "BlobURLStoreImpl::Register, url: ";
//     urlStr += url.GetString().Utf8();
//     urlStr += ",,,,,";
//     urlStr += m_origin->ToString().Utf8();
//     urlStr += "\n";
//     OutputDebugStringA(urlStr.c_str());

    BlobURLStoreSet::get()->addUrlBlob(url.GetString().Utf8(), m_origin->ToRawString().Utf8(), std::move(blob));

//     BlobURLStoreImpl* self = this;
//     ThreadCall::callBlinkThreadAsync(MB_FROM_HERE, [self] {
//         std::string* uuid = nullptr;
//         self->m_blobRemote->GetInternalUUID(base::BindOnce([](std::string** uuid, const WTF::String& uid) {
//             *uuid = new std::string(uid.Ascii());
//         }, &uuid));
// 
//         std::string output = "BlobURLStoreImpl::Register, uuid: ";
//         output += *uuid;
//         output += "\n";
//         delete uuid;
//         OutputDebugStringA(output.c_str());
//     });
// 
//     m_blobRemote.Bind(std::move(blob));
    return true;
}

//using RegisterCallback = base::OnceCallback<void()>;

void BlobURLStoreImpl::Register(
    ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, 
    const ::blink::KURL& url, 
    const ::base::UnguessableToken& unsafe_agent_cluster_id,
    const ::absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site, 
    ::blink::mojom::blink::BlobURLStore::RegisterCallback callback)
{
    DebugBreak();
    BlobURLStoreSet::get()->addUrlBlob(url.GetString().Utf8(), m_origin->ToString().Utf8(), std::move(blob));
}

void BlobURLStoreImpl::Revoke(const ::blink::KURL& url)
{
    BlobURLStoreSet::get()->removeUrlBlob(url.GetString().Utf8());
}

//using ResolveCallback = base::OnceCallback<void(::mojo::PendingRemote<::blink::mojom::blink::Blob>, const absl::optional<::base::UnguessableToken>&)>;
void BlobURLStoreImpl::Resolve(const ::blink::KURL& url, ResolveCallback callback)
{
    DebugBreak();
}

class URLLoaderFactoryImpl : public ::network::mojom::blink::URLLoaderFactory {
public:
    URLLoaderFactoryImpl(const ::blink::KURL& url)
    {
        m_url = url;
    }

    void CreateLoaderAndStart(::mojo::PendingReceiver<::network::mojom::blink::URLLoader> loader, int32_t request_id, uint32_t options,
        const ::network::ResourceRequest& request, ::mojo::PendingRemote<::network::mojom::blink::URLLoaderClient> client,
        const ::net::MutableNetworkTrafficAnnotationTag& traffic_annotation) override
    {
        DebugBreak();
    }

    void Clone(::mojo::PendingReceiver<URLLoaderFactory> factory) override
    {
        createAndBindInterface<::network::mojom::blink::URLLoaderFactory, URLLoaderFactoryImpl>(factory.PassPipe(), m_url);
    }

    ::blink::KURL m_url;
};

//using ResolveAsURLLoaderFactoryCallback = base::OnceCallback<void(const absl::optional<::base::UnguessableToken>&, const absl::optional<::blink::BlinkSchemefulSite>&)>;
void BlobURLStoreImpl::ResolveAsURLLoaderFactory(
    const ::blink::KURL& url, 
    ::mojo::PendingReceiver<::network::mojom::blink::URLLoaderFactory> factory, 
    ::blink::mojom::blink::BlobURLStore::ResolveAsURLLoaderFactoryCallback callback)
{
    createAndBindInterface<::network::mojom::blink::URLLoaderFactory, URLLoaderFactoryImpl>(factory.PassPipe(), url);
    absl::optional<::base::UnguessableToken> token;
    absl::optional<::blink::BlinkSchemefulSite> site;
    std::move(callback).Run(token, site);
}

#ifdef _DEBUG
static int s_BlobURLTokenImpl = 0;
#endif

class BlobURLTokenImpl : public ::blink::mojom::blink::BlobURLToken {
public:
    BlobURLTokenImpl()
    {
#ifdef _DEBUG
        s_BlobURLTokenImpl++;
        char output[100] = { 0 };
        sprintf_s(output, 99, "BlobURLTokenImpl: %d\n", s_BlobURLTokenImpl);
        OutputDebugStringA(output);
#endif
    }
    ~BlobURLTokenImpl()
    {
#ifdef _DEBUG
        --s_BlobURLTokenImpl;
        char output[100] = { 0 };
        sprintf_s(output, 99, "~BlobURLTokenImpl: %d\n", s_BlobURLTokenImpl);
        OutputDebugStringA(output);
#endif
    }

    /*virtual*/ void Clone(::mojo::PendingReceiver<::blink::mojom::blink::BlobURLToken> token) override
    {
        createAndBindInterface<::blink::mojom::blink::BlobURLToken, BlobURLTokenImpl>(token.PassPipe());
    }
    
    //using GetTokenCallback = base::OnceCallback<void(const ::base::UnguessableToken&)>;
    /*virtual*/ void GetToken(GetTokenCallback callback) override
    {
        DebugBreak();
    }
};

//using ResolveForNavigationCallback = base::OnceCallback<void(const absl::optional<::base::UnguessableToken>&)>;
void BlobURLStoreImpl::ResolveForNavigation(
    const ::blink::KURL& url, 
    ::mojo::PendingReceiver<::blink::mojom::blink::BlobURLToken> token, 
    ::blink::mojom::blink::BlobURLStore::ResolveForNavigationCallback callback)
{
    createAndBindInterface<::blink::mojom::blink::BlobURLToken, BlobURLTokenImpl>(token.PassPipe());
    std::move(callback).Run(absl::nullopt);
}

}