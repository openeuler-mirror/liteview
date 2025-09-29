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


#include "gen/third_party/blink/public/mojom/blob/blob.mojom-blink.h"
#include "gen/third_party/blink/public/mojom/blob/blob_url_store.mojom-blink.h"
#include "mojo/public/cpp/bindings/remote.h"
#include <map>

namespace content {

class BlobURLStoreSet {
public:
    struct SecurityOriginAndBlob {
        ::mojo::Remote<::blink::mojom::blink::Blob> blob;
        std::string securityOriginToken;
    };
    using UrlToBlobs = std::map<std::string, SecurityOriginAndBlob*>;

    static BlobURLStoreSet* get();

    void addUrlBlob(const std::string& url, const std::string& securityOriginToken, ::mojo::PendingRemote<::blink::mojom::blink::Blob> blob);
    void removeUrlBlob(const std::string& url);
    void removeBySecurityOriginToken(const std::string& securityOriginToken);
    ::mojo::Remote<::blink::mojom::blink::Blob>* getBlobByUrl(const std::string& url);
private:
    UrlToBlobs m_urlToBlobs;
};

class BlobURLStoreImpl : public ::blink::mojom::blink::BlobURLStore {
public:
    BlobURLStoreImpl(const ::scoped_refptr<const ::blink::SecurityOrigin>& origin);
    ~BlobURLStoreImpl();

    bool Register(::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, 
        const ::blink::KURL& url, 
        const ::base::UnguessableToken& unsafe_agent_cluster_id,
        const absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site) override;

    //using RegisterCallback = base::OnceCallback<void()>;
    void Register(::mojo::PendingRemote<::blink::mojom::blink::Blob> blob, 
        const ::blink::KURL& url, 
        const ::base::UnguessableToken& unsafe_agent_cluster_id,
        const absl::optional<::blink::BlinkSchemefulSite>& unsafe_top_level_site, 
        ::blink::mojom::blink::BlobURLStore::RegisterCallback callback) override;

    void Revoke(const ::blink::KURL& url) override;

    //using ResolveCallback = base::OnceCallback<void(::mojo::PendingRemote<::blink::mojom::blink::Blob>, const absl::optional<::base::UnguessableToken>&)> override;
    void Resolve(const ::blink::KURL& url, ResolveCallback callback) override;

    //using ResolveAsURLLoaderFactoryCallback = base::OnceCallback<void(const absl::optional<::base::UnguessableToken>&, const absl::optional<::blink::BlinkSchemefulSite>&)> override;
    void ResolveAsURLLoaderFactory(
        const ::blink::KURL& url,
        ::mojo::PendingReceiver<::network::mojom::blink::URLLoaderFactory> factory, 
        ResolveAsURLLoaderFactoryCallback callback) override;

    //using ResolveForNavigationCallback = base::OnceCallback<void(const absl::optional<::base::UnguessableToken>&)>;
    void ResolveForNavigation(const ::blink::KURL& url, ::mojo::PendingReceiver<blink::mojom::blink::BlobURLToken> token, ResolveForNavigationCallback callback) override;

    ::scoped_refptr<const ::blink::SecurityOrigin> m_origin;
private:
    ::mojo::Remote<::blink::mojom::blink::Blob> m_blobRemote;
};

}
