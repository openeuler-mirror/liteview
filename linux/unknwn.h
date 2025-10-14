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

#ifndef windows_for_linux_Unknwn_h
#define windows_for_linux_Unknwn_h

#include "windows.h"

typedef struct _GUID {
    unsigned long  Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char  Data4[8];
} GUID;

typedef GUID IID;
#define REFIID const IID&

class IUnknown {
public:
    virtual HRESULT QueryInterface(
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void** ppvObject) = 0;

    virtual ULONG AddRef(void) = 0;

    virtual ULONG Release(void) = 0;
};

#endif // windows_for_linux_Unknwn_h