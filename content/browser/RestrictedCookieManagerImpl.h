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


#ifndef content_browser_RestrictedCookieManagerImpl_h
#define content_browser_RestrictedCookieManagerImpl_h

#include "services/network/public/mojom/restricted_cookie_manager.mojom-blink.h"

namespace content {

class RestrictedCookieManagerImpl : public ::network::mojom::blink::RestrictedCookieManager {
public:
    RestrictedCookieManagerImpl(int64_t webviewId);

    virtual void GetAllForUrl(
        const ::blink::KURL& url, 
        const ::net::SiteForCookies& site_for_cookies, 
        const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
        ::network::mojom::blink::CookieManagerGetOptionsPtr options,
        bool partitioned_cookies_runtime_feature_enabled, 
        GetAllForUrlCallback callback) override;

    void SetCanonicalCookie(
        const ::net::CanonicalCookie& cookie, 
        const ::blink::KURL& url,
        const ::net::SiteForCookies& site_for_cookies,
        const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, 
        ::net::CookieInclusionStatus status, SetCanonicalCookieCallback callback) override;

    void AddChangeListener(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies, const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
        ::mojo::PendingRemote<::network::mojom::blink::CookieChangeListener> listener, AddChangeListenerCallback callback) override;

    // Sync method. This signature is used by the client side; the service side
    // should implement the signature with callback below.

    bool SetCookieFromString(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
        const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, const WTF::String& cookie, bool partitioned_cookies_runtime_feature_enabled,
        bool* out_site_for_cookies_ok, bool* out_top_frame_origin_ok) override;

    void SetCookieFromString(const ::blink::KURL& url, const ::net::SiteForCookies& site_for_cookies,
        const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, const WTF::String& cookie, bool partitioned_cookies_runtime_feature_enabled,
        SetCookieFromStringCallback callback) override;

    // Sync method. This signature is used by the client side; the service side
    // should implement the signature with callback below.

    bool GetCookiesString(
        const ::blink::KURL& url, 
        const ::net::SiteForCookies& site_for_cookies, 
        const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
        bool partitioned_cookies_runtime_feature_enabled, 
        WTF::String* out_cookies) override;

    void GetCookiesString(
        const ::blink::KURL& url, 
        const ::net::SiteForCookies& site_for_cookies, 
        const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
        bool partitioned_cookies_runtime_feature_enabled, 
        GetCookiesStringCallback callback) override;

    bool CookiesEnabledFor(
        const ::blink::KURL& url, 
        const ::net::SiteForCookies& site_for_cookies, 
        const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin, 
        bool* out_cookies_enabled) override;

    void CookiesEnabledFor(
        const ::blink::KURL& url, 
        const ::net::SiteForCookies& site_for_cookies, 
        const ::scoped_refptr<const ::blink::SecurityOrigin>& top_frame_origin,
        CookiesEnabledForCallback callback) override;

    void ConvertPartitionedCookiesToUnpartitioned(const ::blink::KURL& url) override;

private:
    int64_t m_webviewId = 0;
};

}

#endif // content_browser_RestrictedCookieManagerImpl_h