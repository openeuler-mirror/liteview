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


#ifndef content_browser_FileChooserImpl_h
#define content_browser_FileChooserImpl_h

#include "third_party/blink/public/mojom/choosers/file_chooser.mojom-blink.h"

namespace content {

class FileChooserImpl : public ::blink::mojom::blink::FileChooser {
public:
    FileChooserImpl(int64_t mbwebviewId);

    void OpenFileChooser(::blink::mojom::blink::FileChooserParamsPtr params, ::blink::mojom::blink::FileChooser::OpenFileChooserCallback callback) override;

    void EnumerateChosenDirectory(const ::base::FilePath& directory_path, ::blink::mojom::blink::FileChooser::EnumerateChosenDirectoryCallback callback) override;

private:
    int64_t m_webviewId = 0;
};

}

#endif
