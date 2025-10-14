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


#if 0 // ndef net_DownloadFileBlobCache_h
#define net_DownloadFileBlobCache_h

namespace mbnet {

class DownloadFileBlobCache {
public:
    static DownloadFileBlobCache* inst();

    void shutdown();

    void appendDataToBlobCache(
        blink::WebURLLoaderClient* client,
        blink::WebURLLoader* loader,
        const String& url,
        const char* data,
        int dataLength,
        int encodedDataLength
        );

    BlobTempFileInfo* getBlobTempFileInfoByTempFilePath(const String& path);
    String createBlobTempFileInfoByUrlIfNeeded(const String& url);
    void removeBlobTempFileInfo(const String& path);

private:
    static DownloadFileBlobCache* m_inst;

    typedef WTF::HashMap<String, BlobTempFileInfo*> BlobCache;
    BlobCache m_blobCaches; // real url -> <temp, data>
};
    
}

#endif