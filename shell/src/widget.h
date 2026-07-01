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

#ifndef WIDGET_H
#define WIDGET_H

#include <QPointer>
#include <QHash>
#include <QDateTime>
#include <QEvent>
#include <QPixmap>
#include <QIcon>
#include <QPoint>
#include <QWidget>
#include "webwidget.h"
class QFrame;
class QListWidget;
class QListWidgetItem;
class QEvent;
class QResizeEvent;
class QShowEvent;
class QMoveEvent;
class QPaintEvent;
class QWebView;
class QWebEngineView;
class QTabBar;
class QStackedWidget;
class QDialog;
class QToolButton;
class QTimer;
class QProgressBar;
class QLabel;
class QPushButton;

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    void closeEvent( QCloseEvent * event );
    /** 设置「清除浏览数据」：isLocal==2 时删除 LocalStorage 内 *.localsto 与 favicon 缓存，并对各标签 mbClearStorage。 */
    void clearMiniBlinkStorageOnAllWebTabs(int isLocal);
    void clearMiniBlinkCookiesOnAllWebTabs();

    void enterBrowserFullScreen(WebWidget* web = nullptr);
    void exitBrowserFullScreen();
    bool isBrowserFullScreen() const;

protected:
    void showEvent(QShowEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    void moveEvent(QMoveEvent* event) override;
    void resizeEvent(QResizeEvent* event) override;
    void changeEvent(QEvent* event) override;
    bool eventFilter(QObject* watched, QEvent* event) override;
#if defined(Q_OS_WIN)
#  if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
    bool nativeEvent(const QByteArray& eventType, void* message, qintptr* result) override;
#  else
    bool nativeEvent(const QByteArray& eventType, void* message, long* result) override;
#  endif
#endif

private slots:
    void initForm();
    void navigateToInput();
    void goHome();
    void createNewTab();
    void closeTab(int index);
    void onCurrentTabChanged(int index);
    /** 供 miniblink 在非 UI 线程请求新标签时，经 invokeMethod 在主线程执行。 */
    void slotCreateTabForPopup(QString url);
    void openSettingsTab();
    void onTabBarContextMenu(int index, const QPoint& globalPos);

private:
    WebWidget* currentWebWidget() const;
    WebWidget* createTab(const QString& url, bool makeCurrent = true, bool blankAddressBar = false);
    void setupWebWidget(WebWidget* web);
    mbWebView createTabFromPopup(const QString& url);
    void applyTabTitleForWeb(WebWidget* web, const QString& title);
    void updateTabMuteIndicator(WebWidget* web);
    void updateUiFromCurrentTab();
    /** 地址栏单行参与布局；联想列表为浮动层叠在网页上（Chrome 式不撑高顶栏） */
    void setupChromeOmnibox();
    void updateUrlSuggestPopup(const QString& text);
    void hideUrlSuggestPopup();
    void applyUrlFromSuggest(const QString& url);
    /** 内核规避：当前为 about:blank 且多标签时，用“新建目标标签并移除空白标签”替代直接 loadUrl。 */
    bool navigateViaReplacementTabIfNeeded(WebWidget* current, const QString& targetUrl);
    void refreshUrlSuggestSelectionVisual();
    void polishOmniboxChromeFrameFocus(bool focused);
    void setOmniboxOpen(bool open);
    void repositionOmniboxDropdown();
    void closeOtherTabs(int keepIndex);
    void closeTabsToTheRightOf(int index);
    void closeWebWidgetTab(WebWidget* web);
    /** 窗口最大化时应用设计稿背景渐变、去边距与圆角；还原窗口后恢复 */
    void updateMaximizedChrome();
    /** Linux/WM 状态切换时强制同步主布局与当前 WebView 视口 */
    void forceWindowLayoutSync();
    /** 无边框窗体：用位图 mask 裁剪窗口区域，圆角与参考图一致（仅靠 QSS 子控件仍会画成直角） */
    void updateWindowRoundedMask();
#if defined(Q_OS_WIN)
    /** Win11：DWM 圆角；失败时仍用 updateWindowRoundedMask */
    bool tryApplyWindows11RoundedCorners();
#endif
    /** 无边框窗口：顶栏最小化/最大化/关闭图标与提示随窗口状态切换 */
    void syncWindowFrameButtons();
    /** 跨平台统一的最大化状态（Linux 支持伪最大化） */
    bool isWindowMaximizedCompat() const;
    void maximizeWindowCompat();
    void restoreWindowCompat();
    void toggleWindowMaximizeCompat();
    /** 从最大化还原：固定 1280×800，并按该宽度重排标签栏（避免标签栏仍按宽屏撑大窗体） */
    void applyNormalWindowSizeAfterRestore();
    QRect normalRestoreTargetGeometry() const;
    void forceWindowFrameGeometry(const QRect& geo);
    void releaseChromeMouseGrab();
    void refreshChromeAfterLayout();
    void applyBrowserFullScreen();
    /** 还原/布局稳定后：重排标签栏、同步各 WebView 视口并刷新顶栏 */
    void finishWindowRestoreLayout();
    void syncAllWebWidgetsViewports();
    void syncCurrentWebWidgetViewport();
    /** 标签栏随窗体变窄后，按每个 tab 的可用宽度重新省略标题（Chrome 式） */
    void refreshTabBarTitlesForLayout();
    /** 顶栏中标签条可用宽度（按窗体宽度计，避免 tabBar sizeHint 反推撑大窗体） */
    int topTabStripAvailableForTabBar(int forcedOuterWidth = -1) const;
    /** 让 tabBar 宽度贴合内容但不超过可用空间，保证 + 按钮紧跟在最后一个 tab 右侧 */
    void relayoutTopTabBar(int forcedOuterWidth = -1);
    /** 非最大化时标签布局用的外宽（不超过 1280，避免随窗体被撑宽反推） */
    int tabBarLayoutOuterWidth(int forcedOuterWidth = -1) const;
    /** 先立即重排，再延迟一次重排，避免启动/增删标签时 QTabBar 内部几何未稳定导致抖动 */
    void stabilizeTabBarLayout();
    void ensureDownloadPanel();
    QListWidgetItem* findDownloadItem(const QString& savePath) const;
    QWidget* ensureDownloadItemWidget(const QString& savePath);
    void updateDownloadItemWidget(
        const QString& savePath,
        const QString& title,
        const QString& status,
        qint64 receivedBytes,
        qint64 totalBytes,
        bool finished,
        bool success);
    void rebuildDownloadListFromRecords();
    void loadDownloadRecordsFromDisk();
    void saveDownloadRecordsToDisk() const;
    void removeDownloadRecordsByDate(const QString& dateKey);
    /** 有进行中下载时显示圆环进度图标，否则恢复静态下载图标 */
    void updateDownloadsNavButtonVisual();
    void slotDownloadNavIndeterminateTick();
    void restoreDownloadsNavIcon();
    void openDownloadPageTab();
    void ensureDownloadTabPage();
    void updateDownloadTabWrapWidth();
    void requestDownloadTabRebuild(bool immediate = false);
    QListWidgetItem* findDownloadTabItem(const QString& savePath) const;
    bool updateDownloadTabItemWidget(const QString& savePath);
    void rebuildDownloadTabListFromRecords();
    void clearAllDownloadRecords();
    void removeDownloadRecord(const QString& savePath);
    /** 下载面板关闭后，重置下载按钮 hover/pressed 视觉状态 */
    void resetDownloadsNavButtonHoverState();
    QPixmap buildDownloadNavProgressPixmap(bool indeterminate, double progress01, int indeterminateStartDeg) const;
    QIcon buildTabLoadingIcon() const;
    void refreshTabLoadingIcons();
    void syncTabLoadingAnimationState();
    /** 与 isLoading()==false 一致：恢复/默认标签图标（避免动画停后仍残留转圈） */
    void applyLoadedTabIconForWeb(WebWidget* web);
    /** 切换标签/新建标签后：仅从缓存或内存恢复站点图标，不清空已有 favicon */
    void refreshTabSiteIconForWeb(WebWidget* web);
    /** 全局坐标是否在可拖动容器的顶栏区域（排除 +、三键、标签关闭等） */
    bool isChromeWindowDragGrip(const QPoint& globalPos) const;
    /** 双击切换最大化：仅标签间隙/顶栏非 tab 区域及导航条空白（与单击还原区分开） */
    bool isChromeDoubleClickToggleMax(const QPoint& globalPos) const;

    Ui::Widget *ui;
    mbWebView m_pendingCreateViewResult = NULL_WEBVIEW;
    QPointer<QWidget> m_settingsTabPage;
    QFrame* m_omniboxFrame = nullptr;
    /** 联想列表浮动层：不参与 nav 布局，叠在网页上方，避免顶栏被撑高 */
    QFrame* m_omniboxDropdown = nullptr;
    QFrame* m_omniboxSep = nullptr;
    QListWidget* m_urlSuggestList = nullptr;
    QToolButton* m_btnDownloads = nullptr;
    QPixmap m_downloadNavBasePixmap;
    int m_downloadIndeterminateRingDeg = 0;
    QIcon m_icoWinMinimize;
    QIcon m_icoWinMaximize;
    QIcon m_icoWinRestore;
    QIcon m_icoWinClose;
    QTimer* m_downloadNavAnimTimer = nullptr;
    QTimer* m_tabLoadingAnimTimer = nullptr;
    QPixmap m_tabLoadingBasePixmap;
    int m_tabLoadingAngleDeg = 0;
    QHash<WebWidget*, QIcon> m_tabIconRestoreWhenLoading;
    /** faviconChanged 后保留的站点图标，供切换标签时恢复（不依赖 QTabBar 当前像素） */
    QHash<WebWidget*, QIcon> m_tabSiteIconByWeb;
    QPointer<QDialog> m_downloadPanel;
    QListWidget* m_downloadList = nullptr;
    QPointer<QWidget> m_downloadTabPage;
    QFrame* m_downloadTabHeaderWrap = nullptr;
    QFrame* m_downloadTabWrap = nullptr;
    QListWidget* m_downloadTabList = nullptr;
    bool m_downloadTabRebuildScheduled = false;
    bool m_downloadTabListRebuilding = false;
    bool m_downloadTabResizeRebuildPending = false;
    int m_lastDownloadTabViewportWidth = -1;
    struct DownloadTaskMeta {
        QPointer<WebWidget> source;
        QString url;
        bool finished = false;
    };
    struct DownloadRecord {
        QString savePath;
        QString url;
        QString title;
        QString status;
        QString dateKey;
        qint64 receivedBytes = 0;
        qint64 totalBytes = 0;
        qint64 speedBytesPerSec = 0;
        bool finished = false;
        bool success = false;
        QDateTime updatedAt;
    };
    QHash<QString, DownloadTaskMeta> m_downloadTasks;
    QHash<QString, DownloadRecord> m_downloadRecords;
    /** 标签区一旦顶到 + 按钮即锁定宽度，后续新增仅压缩 tab，不再移动 + */
    bool m_tabBarPinnedToAvailable = false;
    /** 单标签模式下标签栏宽度基准（与「新标签页」短标题时一致，不随页面标题变长而变宽） */
    int m_singleTabBarBaselineWidth = 0;
    int m_prevTabBarCount = 0;
    /** Windows：DWM 圆角已成功则不再用 setMask，避免两套机制打架 */
    bool m_winRoundedCornersApplied = false;
    int m_lastWindowChromeMaxState = -1;
    bool m_linuxPseudoMaximized = false;
    bool m_browserFullScreenActive = false;
    QPointer<WebWidget> m_browserFullScreenWeb;
    bool m_browserFullScreenRestoreMaximized = false;
    QRect m_browserFullScreenRestoreGeometry;
    /** 最大化前保存的窗体 geometry（Win/Linux 还原非最大化尺寸） */
    QRect m_windowRestoreGeometry;
    /** showNormal 过程中为 true，避免 changeEvent/resizeEvent 用宽屏宽度重排标签 */
    bool m_restoringNormalSize = false;
    /** 还原后短暂锁定 1280 宽，防止布局/WM_SIZE 逐步撑宽窗体 */
    bool m_normalWidthLockActive = false;
    /** 应用级事件过滤：顶栏子控件会抢走 mouseMove，须在 qApp 上拖窗 */
    bool m_appChromeDragArmed = false;
    bool m_appChromeDragging = false;
    QPoint m_appChromeDragPressGlobal;
    QPoint m_appChromeDragOffset;
#ifndef Q_OS_WIN
    /** Linux 无边框：窗体边缘拖拽缩放（Windows 由 WM_NCHITTEST 提供） */
    int hitWindowResizeEdges(const QPoint& globalPos) const;
    static Qt::CursorShape cursorForWindowResizeEdges(int edges);
    void updateWindowResizeCursor(const QPoint& globalPos);
    void clearWindowResizeCursor();
    void applyWindowEdgeResize(const QPoint& globalPos);
    bool m_windowEdgeResizing = false;
    int m_windowResizeEdges = 0;
    QPoint m_windowResizePressGlobal;
    QRect m_windowResizeStartGeometry;
    bool m_windowResizeCursorActive = false;
#endif
};

#endif // WIDGET_H
