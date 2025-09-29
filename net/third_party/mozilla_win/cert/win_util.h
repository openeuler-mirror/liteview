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

/*
 * Windows utility functions
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef NET_THIRD_PARTY_MOZILLA_WIN_CERT_WIN_UTIL_H_
#define NET_THIRD_PARTY_MOZILLA_WIN_CERT_WIN_UTIL_H_

#include "base/win/wincrypt_shim.h"

namespace net {

// Loads the enterprise roots at the registry location corresponding to the
// given location flag into the passed in cert_store collection. See
// https://docs.microsoft.com/en-us/windows/win32/seccrypto/system-store-locations
// and
// https://docs.microsoft.com/en-us/dotnet/api/system.security.cryptography.x509certificates.storename?view=net-5.0
// for definitions of supported locations (yes the two docs might be
// inconsistent).
//
// Silently fail for errors loading the enterprise roots at the location.
void GatherEnterpriseCertsForLocation(HCERTSTORE cert_store, DWORD location, LPCWSTR store_name);
} // namespace net

#endif // NET_THIRD_PARTY_MOZILLA_WIN_CERT_WIN_UTIL_H_
