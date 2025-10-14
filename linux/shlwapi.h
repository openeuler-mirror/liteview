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


#ifndef windows_for_linux_shlwapi_h
#define windows_for_linux_shlwapi_h

#include "windows.h"

#define OFN_LONGNAMES 0x00200000 
#define OFN_NOCHANGEDIR 0x00000008
#define OFN_EXPLORER 0x00080000     // new look commdlg
#define OFN_ALLOWMULTISELECT 0x00000200
#define OFN_FILEMUSTEXIST 0x00001000
#define OFN_OVERWRITEPROMPT 0x00000002
#define OFN_PATHMUSTEXIST 0x00000800

#define FILE_ATTRIBUTE_DIRECTORY 0x00000010

typedef UINT_PTR(* LPOFNHOOKPROC) (HWND, UINT, WPARAM, LPARAM);

typedef struct tagOFNW {
   DWORD        lStructSize;
   HWND         hwndOwner;
   HINSTANCE    hInstance;
   LPCWSTR      lpstrFilter;
   LPWSTR       lpstrCustomFilter;
   DWORD        nMaxCustFilter;
   DWORD        nFilterIndex;
   LPWSTR       lpstrFile;
   DWORD        nMaxFile;
   LPWSTR       lpstrFileTitle;
   DWORD        nMaxFileTitle;
   LPCWSTR      lpstrInitialDir;
   LPCWSTR      lpstrTitle;
   DWORD        Flags;
   WORD         nFileOffset;
   WORD         nFileExtension;
   LPCWSTR      lpstrDefExt;
   LPARAM       lCustData;
   LPOFNHOOKPROC lpfnHook;
   LPCWSTR      lpTemplateName;

   void*        pvReserved;
   DWORD        dwReserved;
   DWORD        FlagsEx;
} OPENFILENAMEW, *LPOPENFILENAMEW;

typedef OPENFILENAMEW OPENFILENAME;
typedef LPOPENFILENAMEW LPOPENFILENAME;

DWORD GetFileAttributesW(LPCWSTR lpFileName);
BOOL PathIsDirectoryW(LPCWSTR pszPath);
BOOL GetOpenFileNameW(LPOPENFILENAMEW);
BOOL GetSaveFileNameW(LPOPENFILENAMEW);

#endif // windows_for_linux_shlwapi_h