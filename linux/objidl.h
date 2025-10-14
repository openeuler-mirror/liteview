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


#include <windows.h>

typedef struct _userSTGMEDIUM {
    struct _STGMEDIUM_UNION {
        DWORD tymed;
        /* [switch_type] */ union __MIDL_IAdviseSink_0003 {
            /* Empty union arm */
            wireHMETAFILEPICT hMetaFilePict;
            wireHENHMETAFILE hHEnhMetaFile;
            GDI_OBJECT* hGdiHandle;
            wireHGLOBAL hGlobal;
            LPOLESTR lpszFileName;
            BYTE_BLOB* pstm;
            BYTE_BLOB* pstg;
        } 	u;
    } DUMMYUNIONNAME;
    IUnknown* pUnkForRelease;
} userSTGMEDIUM;

typedef STGMEDIUM *LPSTGMEDIUM;