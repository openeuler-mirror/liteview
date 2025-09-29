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


#ifndef content_renderer_BlobRegistryImpl_h
#define content_renderer_BlobRegistryImpl_h

#include "gen/third_party/blink/public/mojom/blob/blob_registry.mojom.h"
#include "gen/third_party/blink/public/mojom/blob/blob_registry.mojom-blink.h"
#include "gen/third_party/blink/public/mojom/blob/data_element.mojom-blink.h"
#include "mojo/public/cpp/bindings/pending_receiver.h"
#include "mojo/public/cpp/bindings/receiver.h"
#include <map>

namespace content {

class BlobEntry;
class BlobURLStoreImpl;
class DataElementImpl;

class BlobEntry {
public:
    BlobEntry(
        ::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob,
        const std::string& uuid,
        const std::string& contentType,
        const std::string& contentDisposition,
        WTF::Vector<::blink::mojom::blink::DataElementPtr> elements);
    ~BlobEntry();

    static BlobEntry* findByUuid(const std::string& uuid);

    int64_t read(std::vector<char>* buffer, int64_t start, int64_t len, int64_t* allSize);

    //BlobReceiver* m_blob;
    int m_blobReceiverRefCount = 0;
    std::string m_uuid;
    std::string m_contentType;
    std::string m_contentDisposition;
    std::vector<DataElementImpl*> m_elements;
};

class BlobRegistryImpl : public ::blink::mojom::blink::BlobRegistry {
public:
    BlobRegistryImpl();
    ~BlobRegistryImpl();

    bool Register(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, 
        const WTF::String& uuid, const WTF::String& content_type,
        const WTF::String& content_disposition, 
        WTF::Vector<::blink::mojom::blink::DataElementPtr> elements) override;

    // using RegisterCallback = base::OnceCallback<void()>;
    void Register(
        ::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob,
        const WTF::String& uuid, 
        const WTF::String& content_type,
        const WTF::String& content_disposition, 
        WTF::Vector<::blink::mojom::blink::DataElementPtr> elements, 
        ::blink::mojom::blink::BlobRegistry::RegisterCallback callback) override;

    //using RegisterFromStreamCallback = base::OnceCallback<void(const ::scoped_refptr<::blink::BlobDataHandle>&)>;
    void RegisterFromStream(
        const WTF::String& contentType,
        const WTF::String& contentDisposition, 
        uint64_t lengthHint,
        ::mojo::ScopedDataPipeConsumerHandle data,
        ::mojo::PendingAssociatedRemote<::blink::mojom::blink::ProgressClient> progressClient,
        RegisterFromStreamCallback callback) override;

    // Sync method. This signature is used by the client side; the service side
    // should implement the signature with callback below.

    bool GetBlobFromUUID(::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid) override;

    //using GetBlobFromUUIDCallback = base::OnceCallback<void()>;
    void GetBlobFromUUID(
        ::mojo::PendingReceiver<::blink::mojom::blink::Blob> blob, const WTF::String& uuid, 
        ::blink::mojom::blink::BlobRegistry::GetBlobFromUUIDCallback callback) override;

    void URLStoreForOrigin(
        const ::scoped_refptr<const ::blink::SecurityOrigin>& origin, 
        ::mojo::PendingAssociatedReceiver<::blink::mojom::blink::BlobURLStore> urlStore) override;

    //mojo::AssociatedReceiver<::blink::mojom::blink::BlobURLStore>* m_blobURLStoreReceiver = nullptr;

    mojo::Receiver<::blink::mojom::blink::BlobRegistry> m_receiver{ this };
};

}

#endif // content_renderer_BlobRegistryImpl_h