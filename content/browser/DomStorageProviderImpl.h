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


#ifndef content_browser_DomStorageProviderImpl_h
#define content_browser_DomStorageProviderImpl_h

#include "third_party/blink/public/mojom/dom_storage/dom_storage.mojom-blink.h"

namespace content {

class DomStorageProviderImpl : public ::blink::mojom::blink::DomStorageProvider {
public:
    DomStorageProviderImpl();

    void BindDomStorage(
        ::mojo::PendingReceiver<::blink::mojom::blink::DomStorage> receiver, ::mojo::PendingRemote<::blink::mojom::blink::DomStorageClient> client) override;
};

}

#endif // content_browser_DomStorageProviderImpl_h