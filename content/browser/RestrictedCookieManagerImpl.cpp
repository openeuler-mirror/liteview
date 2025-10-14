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


#include "content/browser/RestrictedCookieManagerImpl.h"

#include "content/browser/MbWebview.h"
#include "content/common/LiveIdDetect.h"
#include "content/common/common.h"
#include "services/network/public/mojom/restricted_cookie_manager.mojom.h"
#include "mbnet/cookies/WebCookieJarCurlImpl.h"
#include "mbnet/WebURLLoaderManager.h"

// bool network::mojom::RestrictedCookieManager::SetCookieFromString(::GURL const&,
//     net::SiteForCookies const&, url::Origin const&,
//     std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> > const&, bool, bool*, bool*)
// {
//     content::printFuncName(__FUNCTION__, true, true);
//     return false;
// }
// 
// bool network::mojom::RestrictedCookieManager::GetCookiesString(class ::GURL const&, class net::SiteForCookies const&, class url::Origin const&, bool,
//     class std::basic_string<char, struct std::char_traits<char>, class std::allocator<char> >*)
// {
//     content::printFuncName(__FUNCTION__, true, true);
//     return false;
// }
// 
// bool network::mojom::RestrictedCookieManager::CookiesEnabledFor(class GURL const&, class net::SiteForCookies const&, class url::Origin const&, bool*)
// {
//     content::printFuncName(__FUNCTION__, true, true);
//     return false;
// }

bool network::mojom::blink::RestrictedCookieManager::SetCookieFromString(
    ::blink::KURL const&, net::SiteForCookies const&, scoped_refptr<::blink::SecurityOrigin const > const&,
    WTF::String const&, bool, bool*, bool*)
{
    content::printFuncName(__FUNCTION__, true, true);
    return false;
}

bool network::mojom::blink::RestrictedCookieManager::GetCookiesString(::blink::KURL const&, net::SiteForCookies const&, scoped_refptr<::blink::SecurityOrigin const > const&, 
    bool, class WTF::String*)
{
    content::printFuncName(__FUNCTION__, true, true);
    return false;
}

bool network::mojom::blink::RestrictedCookieManager::CookiesEnabledFor(::blink::KURL const&, net::SiteForCookies const&, scoped_refptr<::blink::SecurityOrigin const > const&, bool*)
{
    content::printFuncName(__FUNCTION__, true, true);
    return false;
}

const char network::mojom::RestrictedCookieManager::Name_[] = "network.mojom.RestrictedCookieManager";

namespace content {

class VisitAllCookies {
public:
    VisitAllCookies() {}
    ~VisitAllCookies() {}

    static bool cookieVisitor(void* params, const char* name, const char* value, const char* domain, const char* path, int secure, int httpOnly, int* expires)
    {
        VisitAllCookies* self = (VisitAllCookies*)params;
        return true;
    }
private:

};

RestrictedCookieManagerImpl::RestrictedCookieManagerImpl(int64_t webviewId)
{
    m_webviewId = webviewId;
}

static mbnet::WebCookieJarImpl* getCookieJar(int64_t webviewId)
{
    mbnet::WebCookieJarImpl* cookieJar = mbnet::WebURLLoaderManager::sharedInstance()->getShareCookieJar();

    MbWebView* webview = (MbWebView*)common::LiveIdDetect::getMbWebviewIds()->getPtr(webviewId);
    if (!webview)
        return cookieJar;
    cookieJar = webview->getWebCookieJarImpl();
    return cookieJar;
}

void RestrictedCookieManagerImpl::GetAllForUrl(
    const ::blink::KURL& url,
    const ::net::SiteForCookies& site_for_cookies, 
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
    ::network::mojom::blink::CookieManagerGetOptionsPtr options,
    bool partitioned_cookies_runtime_feature_enabled, 
    GetAllForUrlCallback callback)
{
    printFuncName(__FUNCTION__, true, true);
    mbnet::WebCookieJarImpl* cookieJar = mbnet::WebURLLoaderManager::sharedInstance()->getShareCookieJar();
    VisitAllCookies* visit = new VisitAllCookies();
    cookieJar->visitAllCookie(visit, &VisitAllCookies::cookieVisitor);
}

void RestrictedCookieManagerImpl::SetCanonicalCookie(
    const ::net::CanonicalCookie& cookie, 
    const ::blink::KURL& url, 
    const ::net::SiteForCookies& site_for_cookies, 
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
    ::net::CookieInclusionStatus status, 
    SetCanonicalCookieCallback callback)
{
    printFuncName(__FUNCTION__, true, true);
}

void RestrictedCookieManagerImpl::AddChangeListener(
    const ::blink::KURL& url, 
    const ::net::SiteForCookies& site_for_cookies, 
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
    ::mojo::PendingRemote<::network::mojom::blink::CookieChangeListener> listener,
    AddChangeListenerCallback callback)
{
    printFuncName(__FUNCTION__, true, true);
}

bool RestrictedCookieManagerImpl::SetCookieFromString(
    const ::blink::KURL& url, 
    const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, 
    const WTF::String& cookie, 
    bool partitioned_cookies_runtime_feature_enabled,
    bool* out_site_for_cookies_ok, 
    bool* out_top_frame_origin_ok)
{
    //printFuncName(__FUNCTION__, true, false);
    mbnet::WebCookieJarImpl* cookieJar = getCookieJar(m_webviewId);

//     std::string temp = "RestrictedCookieManagerImpl::SetCookieFromString:";
//     temp += cookie.Utf8().c_str();
//     temp += "\n";
//     OutputDebugStringA(temp.c_str());

    cookieJar->setCookiesFromDOM(blink::KURL(), url, cookie.Utf8());
    return true;
}

void RestrictedCookieManagerImpl::SetCookieFromString(
    const ::blink::KURL& url, 
    const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, 
    const WTF::String& cookie, 
    bool partitioned_cookies_runtime_feature_enabled,
    SetCookieFromStringCallback callback)
{
    printFuncName(__FUNCTION__, true, true);
}

bool RestrictedCookieManagerImpl::GetCookiesString(
    const ::blink::KURL& url,
    const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
    bool partitioned_cookies_runtime_feature_enabled,
    WTF::String* out_cookies)
{
    mbnet::WebCookieJarImpl* cookieJar = getCookieJar(m_webviewId);
    std::string result = cookieJar->getCookiesForSession(blink::KURL(), url, /*bool httponly*/ false);
    *out_cookies = WTF::String::FromUTF8((const uint8_t*)result.c_str(), result.size());
    return true;
}

void RestrictedCookieManagerImpl::GetCookiesString(
    const ::blink::KURL& url,
    const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
    bool partitioned_cookies_runtime_feature_enabled,
    GetCookiesStringCallback callback)
{
    printFuncName(__FUNCTION__, true, true);
}

bool RestrictedCookieManagerImpl::CookiesEnabledFor(
    const ::blink::KURL& url,
    const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
    bool* out_cookies_enabled)
{
    printFuncName(__FUNCTION__, false, false);
    *out_cookies_enabled = true;
    return true;
}

void RestrictedCookieManagerImpl::CookiesEnabledFor(
    const ::blink::KURL& url, 
    const ::net::SiteForCookies& site_for_cookies,
    const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, 
    CookiesEnabledForCallback callback)
{
    printFuncName(__FUNCTION__, true, true);
}

void RestrictedCookieManagerImpl::ConvertPartitionedCookiesToUnpartitioned(const ::blink::KURL& url)
{
    printFuncName(__FUNCTION__, true, true);
}

}
