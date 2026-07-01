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

// #ifndef WEBWIDGET_H
// #define WEBWIDGET_H

// #include <QWidget>

// class WebWidget : public QWidget
// {
//     Q_OBJECT
// public:
//     explicit WebWidget(QWidget *parent = nullptr);

// signals:
// };

// #endif // WEBWIDGET_H
#ifndef WEBWIDGET_H
#define WEBWIDGET_H

#include <QWidget>
#include <QPoint>
#include <QRect>
#include <QPointer>
#include <QResizeEvent>
#include <QString>
#include <QVector>
#include <QByteArray>
#include <QIcon>
#include <functional>
#include "mb.h"
class QNetworkAccessManager;
class QNetworkReply;
class QTimer;
class QKeyEvent;
class QInputMethodEvent;
class QLineEdit;

#if __SIZEOF_LONG__ == 8
typedef uint64_t         mbWebView;
#else
typedef intptr_t         mbWebView;
#endif

class WebWidget : public QWidget
{
    Q_OBJECT
    friend BOOL MB_CALL_TYPE onNavigationAllowCallback(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url);
    friend mbWebView MB_CALL_TYPE onCreateViewCallback(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url, const mbWindowFeatures* windowFeatures);
    friend BOOL MB_CALL_TYPE onCloseCallback(mbWebView webView, void* param, void* unuse);
    friend BOOL MB_CALL_TYPE onContextMenuPopup(mbWebView webView, void* param, int itemSize, mbMenuItemId ids[], const utf8* text[], const mbContextMenuParams* menuParams);
public:
    struct EngineContextMenuInfo {
        QString linkUrl;
        QString selectionText;
        bool isEditable = false;
        int mediaType = 0;
        /** 内核命中坐标（与 mbContextMenuParams::x/y 一致），用于 DOM 兜底时与视图标尺对齐 */
        bool hasHitPoint = false;
        int hitX = 0;
        int hitY = 0;
    };

    /** blankAddressBar：加载 about:blank 但地址栏显示为空（用于「打开新标签页」启动方式）。 */
    explicit WebWidget(const QString& url = QString(), QWidget* parent = 0, bool blankAddressBar = false);
    ~WebWidget();

    // Keep miniblink viewport size in sync with widget size.
    void syncViewport();

    mbWebView m_webView;
    void loadUrl(QString url);
    /** 直接加载内联 HTML 内容（用于内部页面，如下载管理页）。 */
    void loadHtml(const QString& html, const QString& baseUrl = QStringLiteral("about:blank"));
    /** 加载 about:blank，且地址栏显示为空（与「新标签页 / 主页-空白」一致）。 */
    void loadBlankHome();
    /** 由外壳提供：在 target=_blank / window.open 时同步创建新标签并返回其 mbWebView。 */
    void setCreateNewTabHandler(const std::function<mbWebView(const QString&)>& handler);
    /** 标记为登录/OAuth 弹窗标签（window.open），便于回调后自动关闭。 */
    void setAuthPopupTab(bool popup, WebWidget* opener = nullptr);
    WebWidget* authPopupOpener() const;
    bool authPopupShouldReloadOpener() const;

    void goBack();
    void goForward();
    void reload();
    void stop();
    void enterBrowserFullScreen();
    void exitBrowserFullScreen();
    bool isBrowserFullScreen() const;
    /** 销毁前收紧 miniblink：停载、静音、失焦、隐藏；复杂站点（视频/音频）退出进程前宜先调用。可重复调用。 */
    void preDestroyMiniblinkView();
    /** 切换该页签音视频静音（内核 mbSetAudioMuted）。成功返回 true 并发 audioMuteChanged。 */
    bool toggleAudioMute();
    /** 左键按下 grabMouse 后若未收到 release（如窗体状态切换），由外壳强制释放 */
    void releaseMouseCapture();
    bool isAudioMuted() const;
    QString currentUrl() const;
    QString title() const;
    bool isLoading() const;
    QString linkUrlAtPoint(const QPoint& mbPoint) const;
    /** 指定 miniblink 坐标处是否为可编辑控件（input/textarea/contenteditable），用于空输入框右键出粘贴菜单 */
    bool hitIsEditableFieldAtMb(const QPoint& mbPoint) const;
    /** 将系统剪贴板纯文本插入坐标处可编辑控件（内核 mbEditorPaste 失效时的兜底） */
    bool pastePlainTextFromClipboardAtMb(const QPoint& mbPoint) const;
    /** 将剪贴板纯文本插入当前焦点可编辑控件（快捷键粘贴兜底） */
    bool pastePlainTextToFocusedField(const QString& clipOverride = QString()) const;
    /** 指定 miniblink 坐标处的选中文本（先严后宽），供右键复制菜单使用 */
    QString selectedTextForContextMenuAt(const QPoint& mbPoint) const;
    /** 内核 mbContextMenuParams.selectionText 缓存（右键选区时由内核返回） */
    QString kernelSelectedText() const;
    /** 当前页面文本选区（无选区时为空），用于右键「复制/搜索」菜单；依赖最近一次右键坐标 */
    QString selectedTextFromPage() const;
    void openLinkInNewTab(const QString& url);
    void openLinkInNewWindow(const QString& url);
    void copyLinkToClipboard(const QString& url);
    bool cancelDownload(const QString& savePath);

    /** 内核右键回调里解析菜单（全局 onContextMenuPopup 调用，须为 public） */
    static void dispatchEngineContextMenu(mbWebView webView, WebWidget* self,
        const QVector<mbMenuItemId>& idVec, const QVector<QString>& texts, const EngineContextMenuInfo& info);
    /** 地址栏等 Qt 输入框：与网页选区相同的「复制/粘贴」右键菜单 */
    static void showCopyPasteContextMenuForLineEdit(QLineEdit* edit);
    static void copyTextToSystemClipboard(const QString& text);
    static QString textFromSystemClipboard();
    static void pasteTextToLineEdit(QLineEdit* edit);
    /** 从系统剪贴板粘贴到网页可编辑控件（读 Qt 剪贴板，JS 注入或按键输入，不用 mbEditorPaste） */
    bool pasteFromSystemClipboardAtMb(const QPoint& mbPoint);
    /** 将已知文本粘贴到网页坐标处可编辑控件（避免重复读剪贴板） */
    bool pastePlainTextAtMb(const QPoint& mbPoint, const QString& clip);

    void resizeEvent(QResizeEvent *event) override;
    void onMove();

    void onPaintBitUpdated(mbWebView webView, const void* buffer, const mbRect* r, int width, int height);

private:
    // Friend callbacks for miniblink C-style hooks.
    friend void MB_CALL_TYPE onUrlChangedCallback(mbWebView webView, void* param, const utf8* url, BOOL canGoBack, BOOL canGoForward);
    friend void MB_CALL_TYPE onTitleChangedCallback(mbWebView webView, void* param, const utf8* title);
    friend void MB_CALL_TYPE onLoadingFinishCallback(mbWebView webView, void* param, mbWebFrameHandle frameId, const utf8* url, mbLoadingResult result, const utf8* failedReason);
    friend void MB_CALL_TYPE onDocumentReadyCallback(mbWebView webView, void* param, mbWebFrameHandle frameId);
    friend void MB_CALL_TYPE onJsQueryCallback(mbWebView webView, void* param, mbJsExecState es, int64_t queryId, int customMsg, const utf8* request);

private slots:
    void onUrlChangedQueued(const QString& url, bool canGoBack, bool canGoForward);
    void onTitleChangedQueued(const QString& title);
    void onLoadingFinishQueued(const QString& url, bool ok, const QString& failedReason);
    void onDocumentReadyQueued();
    void onInternalActionUrlQueued(const QString& url);
    void onFaviconArrived(const QString& iconUrl);
    void onFaviconDownloadFinished(QNetworkReply* reply);
    void onDownloadStartedQueued(const QString& url, const QString& savePath, qint64 totalBytes);
    void onDownloadProgressQueued(const QString& url, const QString& savePath, qint64 receivedBytes, qint64 totalBytes);
    void onDownloadFinishedQueued(const QString& url, const QString& savePath, bool ok, const QString& reason);
    void onWindowCloseRequested();
    void applyWebPageCopiedText(const QString& text);
protected:
    void showEvent(QShowEvent* event) override;
    void paintEvent(QPaintEvent *event) override;
    void setNextFrame(const uchar* data, const mbRect& dirtyRect, int width, int height);

    void contextMenuEvent(QContextMenuEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseDoubleClickEvent(QMouseEvent* event) override;
    void enterEvent(QEnterEvent* event) /*override*/;
    void leaveEvent(QEvent* event) override;
    void wheelEvent(QWheelEvent* event) override;
    void keyPressEvent(QKeyEvent* event) override;
    void keyReleaseEvent(QKeyEvent* event) override;
    void inputMethodEvent(QInputMethodEvent* event) override;
    QVariant inputMethodQuery(Qt::InputMethodQuery query) const override;
    void changeEvent(QEvent *event) override;
    void focusInEvent(QFocusEvent* event) override;
    void focusOutEvent(QFocusEvent* event) override;

    const uchar* m_currentFrameData = nullptr;
    int m_frameWidth = 0;
    int m_frameHeight = 0;
    mbRect m_dirtyRect;
    bool m_isCaptured = false;
    QString m_lastUrl;
    QString m_lastTitle;
    bool m_lastCanGoBack = false;
    bool m_lastCanGoForward = false;
    bool m_lastIsLoading = false;

    void handleUrlChanged(const QString& url, bool canGoBack, bool canGoForward);
    void handleTitleChanged(const QString& title);
    void handleLoadingFinished(const QString& url, bool ok, const QString& failedReason);
    void maybeCloseAuthPopupAfterOAuth(const QString& url);
    void setLoadingState(bool loading, bool forceEmit = false);

    /** Last mbResize() size in pixels (matches mbFireMouseEvent coords on Windows). */
    int m_mbPixelW = 0;
    int m_mbPixelH = 0;
    /** 最近一次右键的 miniblink 坐标，供选区 JS 与 onContextMenuPopup 使用 */
    bool m_lastRmbValid = false;
    QPoint m_lastRmbMbPos;
    /** 已由 onContextMenuPopup/dispatch 弹出菜单，showContextMenuForPage 的 JS 后备不再弹 */
    bool m_engineContextMenuHandled = false;
    /** onContextMenuPopup 仅缓存内核命中信息，统一在 showContextMenuForPage 的单通道里消费并弹菜单 */
    bool m_hasPendingEngineContextMenu = false;
    QVector<mbMenuItemId> m_pendingEngineMenuIds;
    QVector<QString> m_pendingEngineMenuTexts;
    EngineContextMenuInfo m_pendingEngineMenuInfo;
    /** 内核右键回调 mbContextMenuParams.selectionText，供复制菜单写入系统剪贴板 */
    QString m_kernelSelectionText;
    bool m_isDestroying = false;
    QPoint mapEventToMb(const QPoint& logicalPos) const;
    QPoint mapMbToWidget(const QPoint& mbPos) const;
    QRect caretRectInWidgetCoords() const;
    void scheduleInputMethodCursorUpdate();
    void updateInputMethodCursorRectNow();
    QRect m_cachedImCursorRect;
    bool m_hasCachedImCursorRect = false;
    QTimer* m_imeCursorUpdateTimer = nullptr;
    QString selectedTextFromPageAtPoint(const QPoint& mbPoint) const;
    /** 仅读取 (x,y) 命中帧上的选区，不扫其它 iframe（避免广告框残留选区挡住链接菜单） */
    QString selectedTextStrictAtMbPoint(const QPoint& mbPoint) const;
    /** 在网页坐标对应位置弹出右键菜单（选区 / 链接 / 页面） */
    void showContextMenuForPage(const QPoint& widgetLocalPos);
    static bool focusEditableAtMbPoint(mbWebView webView, const QPoint& mbPoint);
    static bool fireSyntheticCtrlV(mbWebView webView);

    std::function<mbWebView(const QString&)> m_createNewTabHandler;
    bool m_authPopupTab = false;
    bool m_authPopupCloseScheduled = false;
    bool m_authPopupOAuthSucceeded = false;
    QPointer<WebWidget> m_authPopupOpener;
    bool m_displayUrlEmpty = false;
    /** 无 mbIsAudioMuted 时由外壳记录静音态（与 toggleAudioMute 成对使用） */
    bool m_assumedAudioMuted = false;
    QNetworkAccessManager* m_faviconNet = nullptr;
    QNetworkReply* m_activeFaviconReply = nullptr;
    quint64 m_faviconFetchId = 0;
    QString m_pendingFaviconUrl;
    /** 当前页 URL，用于按域名写入 LocalStorage/favicon 缓存 */
    QString m_faviconPageUrl;
    QTimer* m_loadingGuardTimer = nullptr;
    /** 内核 mbOnNetGetFavicon 可能在主文档仍「加载中」即回调；延迟到 setLoadingState(false) 再对该 URL 拉取图标 */
    bool m_hasDeferredKernelFavicon = false;
    QString m_deferredKernelFaviconUrl;
    void requestFaviconUrl(const QUrl& url, bool retriedHttp = false);
    void requestFaviconForPage(const QString& pageUrl);
    void processKernelFaviconPayload(const QString& iconUrl);
    void flushDeferredKernelFavicon();
    void applyFaviconForPageUrl(const QString& pageUrl);
    void emitDefaultFavicon();
    static QImage decodeFaviconImage(const QByteArray& payload);

signals:
    void internalActionUrlTriggered(const QString& url);
    void urlChanged(const QString& url);
    void navigationStateChanged(bool canGoBack, bool canGoForward);
    void titleChanged(const QString& title);
    void faviconChanged(const QIcon& icon);
    void loadingChanged(bool isLoading);
    void loadFinished(const QString& url, bool ok, const QString& failedReason);
    void audioMuteChanged(bool muted);
    void downloadStarted(const QString& url, const QString& savePath, qint64 totalBytes);
    void downloadProgress(const QString& url, const QString& savePath, qint64 receivedBytes, qint64 totalBytes);
    void downloadFinished(const QString& url, const QString& savePath, bool ok, const QString& reason);
    void closeTabRequested();

public slots:
};

#endif // WEBWIDGET_H

