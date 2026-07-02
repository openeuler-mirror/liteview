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


#ifndef linux_ohosgdi_h
#define linux_ohosgdi_h

#include <unistd.h>
#include <map>
#include <set>
#include <pthread.h>
#include "windows.h"

namespace OHOS {
class RootView;
class Window;
}

class UIWebview;

class HwndOhos {
public:
    OHOS::Window* m_window = nullptr;

    WNDPROC m_wndProc;
    LPVOID m_userdata;

    unsigned int m_glTexture = 0;

    UIWebview* m_UIWebview = nullptr;

    DWORD m_style;
    DWORD m_styleex;

    DWORD m_threadId;

    HwndOhos();
    ~HwndOhos();

    void updataPosOnScreen();
    void clearSurface(void);

    void* m_msgPtr; // 不同消息不同含义的指针
    pthread_mutex_t m_propsMutex;
    std::map<unsigned int, void*> m_props;

    int m_rootX;
    int m_rootY;

    static void destroy(HWND hWnd, bool forceDelete);
    HWND m_hWnd = nullptr; // 以后会把HWND和HwndLinux区分开。现在暂时是同一个值。
    bool m_autoHandleClose = false; // true表示整个窗口mb接管；false表示窗口是外部创建好的，外部负责关闭
    bool m_isDestroying;

    static std::map<int, WNDCLASSEXW*>* s_wndClassMap;
    static std::set<HWND>* s_hwnds;
    static pthread_mutex_t s_hwndMutex;
};

#endif // linux_ohosgdi_h