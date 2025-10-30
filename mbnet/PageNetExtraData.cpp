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


#include "mbnet/PageNetExtraData.h"
#include "mbnet/WebURLLoaderManagerUtil.h"
#include "mbnet/cookies/WebCookieJarCurlImpl.h"
#include "mbnet/cookies/CookieJarMgr.h"
//#include "mbnet/StorageMgr.h"
//#include "mbnet/WebStorageNamespaceImpl.h"
#include "mbnet/DefaultLocalStorageDir.h"
#include "third_party/blink/renderer/platform/wtf/threading_primitives.h"
#include "api/core/mb.h"
#include <shlwapi.h>

namespace mbnet {
    
PageNetExtraData::PageNetExtraData()
{
    m_cookieJar = nullptr;
}

PageNetExtraData::~PageNetExtraData()
{
    // ��ɾ���ˣ���Ϊ��CookieJarMgr������
//     if (m_cookieJar)
//         delete m_cookieJar;

    if (m_proxy)
        delete m_proxy;
}

void PageNetExtraData::setCookieJarFullPath(const std::string& fullPathUtf8)
{
    WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
    WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

    if (m_cookieJar) {
        OutputDebugStringA("PageNetExtraData::setCookieJarPath has been set");
        return;
    }

    WebCookieJarImpl* cookieJar = CookieJarMgr::getInst()->createOrGet(fullPathUtf8);
    m_cookieJar = cookieJar;
}

CURLSH* PageNetExtraData::getCurlShareHandle()
{
    if (m_cookieJar)
        return m_cookieJar->getCurlShareHandle();
    return nullptr;
}

std::string PageNetExtraData::getCookieJarFullPath()
{
    if (m_cookieJar)
        return m_cookieJar->getCookieJarFullPath();
    return "";
}

// blink::WebStorageNamespace* PageNetExtraData::createWebStorageNamespace()
// {
//     if (m_localStotageFullPath.isEmpty())
//         m_localStotageFullPath = getDefaultLocalStorageFullPath();
// 
//     WebStorageNamespaceImpl* storageArea = nullptr;
//     if (m_localStorage) {
//         storageArea = new WebStorageNamespaceImpl(m_localStotageFullPath, kLocalStorageNamespaceId, m_localStorage, true);
//         return (blink::WebStorageNamespace*)storageArea;
//     }
// 
//     WTF::Vector<char> buffer = WTF::ensureStringToUTF8(m_localStotageFullPath, true);
//     setLocalStorageFullPath(buffer.data());
//     
//     storageArea = new WebStorageNamespaceImpl(m_localStotageFullPath, kLocalStorageNamespaceId, m_localStorage, true);
//     return (blink::WebStorageNamespace*)storageArea;
// }
//
// DOMStorageMap* createOrGet(const String& fullPath)
// {
//     CHECK(!fullPath.is8Bit());
//     WebStorageNamespaceImpl* storageArea = nullptr;
//     HashMap<String, DOMStorageMap*>::iterator it = m_pathToStorageNamespace.find(fullPath);
//     if (m_pathToStorageNamespace.end() != it)
//         return it->value;
// 
//     DOMStorageMap* storageMap = new DOMStorageMap();
//     m_pathToStorageNamespace.add(fullPath, storageMap);
//     return storageMap;
// }

base::FilePath PageNetExtraData::getLocalStorageDir()
{
    WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
    WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

    if(!m_localStotageFullPath.empty())
        return m_localStotageFullPath;
    m_localStotageFullPath = getDefaultLocalStorageDir();
    return m_localStotageFullPath;
}

void PageNetExtraData::setLocalStorageDir(const std::string& localStorageDir)
{
    WTF::RecursiveMutex* mutex = sharedResourceMutex(CURL_LOCK_DATA_COOKIE);
    WTF::Locker<WTF::RecursiveMutex> locker(*mutex);

    if (!m_localStotageFullPath.empty()) {
        OutputDebugStringA("PageNetExtraData::setStorageAreaFullPath has been set");
        return;
    }
    m_localStotageFullPath = base::FilePath::FromUTF8Unsafe(localStorageDir);
}

void PageNetExtraData::setProxy(const mbProxy* proxy)
{
    if (m_proxy)
        delete m_proxy;
    m_proxy = (mbProxy*)proxy;
}

const mbProxy* PageNetExtraData::getProxy() const
{
    return m_proxy;
}

}