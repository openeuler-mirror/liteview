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

#include "widget.h"
#include <QApplication>
#include <QCoreApplication>
#include <QEvent>
#include <QThread>
#include <QThreadPool>
#include <QIcon>
#include <QDir>
#include <QFileInfo>
#include <atomic>
#include <cstdlib>
#include "mb.h"

#ifdef Q_OS_LINUX
/* Linux 下 main 使用手动循环驱动 miniblink；关闭主窗口时由 Widget::closeEvent 置 false 以退出循环。
 * 须用 atomic：否则编译器可能把 while 条件优化成永真（循环体内未“可见”地修改该变量）。 */
std::atomic<bool> g_liteviewLinuxMessageLoopRunning{true};
#endif

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    {
        const QString iconPath = QDir(QCoreApplication::applicationDirPath())
                                     .filePath(QStringLiteral("images/icon.png"));
        if (QFileInfo::exists(iconPath))
            a.setWindowIcon(QIcon(iconPath));
    }
    /* 与 QSettings、历史记录路径一致；否则 Linux 上 AppDataLocation 可能为空或不可写 */
    QCoreApplication::setOrganizationName(QStringLiteral("LiteView"));
    QCoreApplication::setApplicationName(QStringLiteral("LiteViewBrowser"));

#ifdef Q_OS_LINUX
    /* 作用域结束后再 mbUninit：须先析构 Widget/WebWidget，mbDestroyWebView 全部执行完 */
    {
        Widget w;
        /* 默认窗口化，否则铺满屏时四角被屏幕裁掉，圆角看不出来；需要一启动就铺满可改回 showMaximized() */
        w.resize(1280, 800);
        w.show();

        while (g_liteviewLinuxMessageLoopRunning.load(std::memory_order_acquire)) {
            /* 先处理 Qt 事件（含关闭） */
            QCoreApplication::processEvents();
            /* 用户已关窗：不要再跑 miniblink，否则可能长时间不返回或继续拉起工作线程 */
            if (!g_liteviewLinuxMessageLoopRunning.load(std::memory_order_acquire))
                break;
            if (mbRunMessageLoopUntilIdle)
                mbRunMessageLoopUntilIdle();
            QThread::msleep(16);
        }
    }
    /* mb.h：mbDestroyWebView 之后仍可能有异步收尾；抽空队列再 mbUninit，利于释放媒体/解码相关线程 */
    if (mbExitMessageLoop)
        mbExitMessageLoop();
    for (int i = 0; i < 15; ++i) {
        QCoreApplication::processEvents();
        if (mbRunMessageLoopUntilIdle)
            mbRunMessageLoopUntilIdle();
        QThread::msleep(1);
    }
    if (mbUninit)
        mbUninit();

    /* ~QApplication 里会 join 线程池等；若仍有 Runnable 或与 native 交错，可能卡在此处（gdb 见 ~QApplication）。
     * 在销毁 QApplication 前尽量排空全局线程池与 DeferredDelete。 */
    QThreadPool::globalInstance()->waitForDone(800);
    for (int i = 0; i < 3; ++i) {
        QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
        QCoreApplication::processEvents();
    }

    /* 某些 Linux 环境下 ~QApplication 可能因第三方内核线程回收卡死；清理完成后直接退出进程。 */
    std::_Exit(0);
#else
    int exitCode = 0;
    {
        Widget w;
        w.resize(1280, 800);
        w.show();
        exitCode = a.exec();
    }
    /* 先尽量排空 Qt 延迟事件，避免销毁后的 queued 回调仍触发 native 访问 */
    for (int i = 0; i < 3; ++i) {
        QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
        QCoreApplication::processEvents();
    }
    /* Windows 下同样做一次 miniblink 收尾，减少退出阶段线程回调导致的 first-chance 异常 */
    if (mbExitMessageLoop)
        mbExitMessageLoop();
    for (int i = 0; i < 15; ++i) {
        QCoreApplication::processEvents();
        if (mbRunMessageLoopUntilIdle)
            mbRunMessageLoopUntilIdle();
        QThread::msleep(1);
    }
    if (mbUninit)
        mbUninit();
    /* 与 Linux 分支一致：在 ~QApplication 前尽量排空线程池和 DeferredDelete */
    QThreadPool::globalInstance()->waitForDone(800);
    for (int i = 0; i < 3; ++i) {
        QCoreApplication::sendPostedEvents(nullptr, QEvent::DeferredDelete);
        QCoreApplication::processEvents();
    }

    /* miniblink 在 mbUninit 后仍可能有异步 Viz/渲染收尾；若继续执行 ~QApplication，易在 return 附近
     * 与已释放内核状态交错触发 0xc0000005（调试器常停在 return exitCode）。进程退出由系统回收资源。 */
    std::_Exit(exitCode);
#endif

}
