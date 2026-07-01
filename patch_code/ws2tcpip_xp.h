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


#ifndef patch_code_ws2tcpip_xp_h
#define patch_code_ws2tcpip_xp_h

#ifdef SUPPORT_XP_CODE

#include <ws2tcpip.h>

inline PCSTR inet_ntop_xp(INT Family, const VOID* pAddr, PSTR pStringBuf, size_t StringBufSize)
{
    typedef PCSTR(__stdcall * PFN_inet_ntop)(INT Family, const VOID* pAddr, PSTR pStringBuf, size_t StringBufSize);
    static PFN_inet_ntop s_inet_ntop = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"WS2_32.dll");
        s_inet_ntop = (PFN_inet_ntop)GetProcAddress(handle, "inet_ntop");
        s_is_init = TRUE;
    }

    if (s_inet_ntop)
        return s_inet_ntop(Family, pAddr, pStringBuf, StringBufSize);

    return NULL;
}

inline INT inet_pton_xp(INT Family, PCSTR pszAddrString, PVOID pAddrBuf)
{
    typedef INT(__stdcall * PFN_inet_pton)(INT Family, PCSTR pszAddrString, PVOID pAddrBuf);
    static PFN_inet_pton s_inet_pton = NULL;
    static BOOL s_is_init = FALSE;
    if (!s_is_init) {
        HMODULE handle = GetModuleHandle(L"WS2_32.dll");
        s_inet_pton = (PFN_inet_pton)GetProcAddress(handle, "inet_pton");
        s_is_init = TRUE;
    }

    if (s_inet_pton)
        return s_inet_pton(Family, pszAddrString, pAddrBuf);

    return -1;
}

#else

#define inet_ntop_xp inet_ntop
#define inet_pton_xp inet_pton

#endif
#endif