#include "widget.h"
#include "ui_widget.h"

#ifdef Q_OS_LINUX
#include <atomic>
extern std::atomic<bool> g_liteviewLinuxMessageLoopRunning;
#endif
#include "webtabbar.h"
#include "browsersettingswidget.h"

static bool isTabBarWindowDragActive(const Ui::Widget* ui);

#include "browserhistorystore.h"
#include "addressinputhistorystore.h"
#include "faviconcache.h"
#include <QFile>
#include <QDir>
#include <QLineEdit>
#include <QToolButton>
#include <QApplication>
#include <QGuiApplication>
#include <QScreen>
#if !defined(Q_OS_WIN) || QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
#include <QWindow>
#endif
#if QT_VERSION < QT_VERSION_CHECK(5, 14, 0)
#include <QDesktopWidget>
#endif
#include <QDebug>
#include <QUrl>
#include <QAction>
#include <QSizePolicy>
#include <QString>
#include <QTabBar>
#include <QStackedWidget>
#include <QLayout>
#include <QResizeEvent>
#include <QTimer>
#include <QThread>
#include <QMutex>
#include <QMutexLocker>
#include <QFontMetrics>
#include <QIcon>
#include <QSettings>
#include <QButtonGroup>
#include <QFont>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QListWidget>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QStackedWidget>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QMenu>
#include <QMessageBox>
#include <QClipboard>
#include <QScrollArea>
#include <QShowEvent>
#include <QBitmap>
#include <QPainter>
#include <QRectF>
#include <QColor>

static QScreen* screenForWidget(const QWidget* w)
{
    QScreen* scr = nullptr;
#if QT_VERSION >= QT_VERSION_CHECK(5, 14, 0)
    if (w && w->windowHandle())
        scr = w->windowHandle()->screen();
    if (!scr && w)
        scr = QGuiApplication::screenAt(w->frameGeometry().center());
#else
    if (w) {
        QDesktopWidget* desktop = QApplication::desktop();
        if (desktop) {
            QWidget* win = w->window();
            const int idx = desktop->screenNumber(win ? win : const_cast<QWidget*>(w));
            const auto screens = QGuiApplication::screens();
            if (idx >= 0 && idx < screens.size())
                scr = screens.at(idx);
        }
    }
#endif
    if (!scr)
        scr = QGuiApplication::primaryScreen();
    return scr;
}

/** 地址栏展示 URL：光标置于开头，超长链接左对齐显示协议与域名 */
static void setAddressBarUrlDisplay(QLineEdit* edit, const QString& url)
{
    if (!edit)
        return;
    edit->setText(url);
    edit->setCursorPosition(0);
    edit->deselect();
}

namespace {
constexpr int kWindowCornerRadiusPx = 10;
/* 顶栏窗口键 tooltip：UTF-8 十六进制，避免未 /utf-8 编译时中文乱码 */
constexpr const char kTipWinMinimize[] = "\xe6\x9c\x80\xe5\xb0\x8f\xe5\x8c\x96";
constexpr const char kTipWinMaximize[] = "\xe6\x9c\x80\xe5\xa4\xa7\xe5\x8c\x96";
constexpr const char kTipWinRestore[] = "\xe8\xbf\x98\xe5\x8e\x9f";
constexpr const char kTipWinClose[] = "\xe5\x85\xb3\xe9\x97\xad";

static QIcon tintedSidebarIcon(const QIcon& src, const QSize& size, const QColor& color)
{
    QPixmap base = src.pixmap(size);
    if (base.isNull())
        return src;
    QImage img = base.toImage().convertToFormat(QImage::Format_ARGB32_Premultiplied);
    QPainter p(&img);
    p.setCompositionMode(QPainter::CompositionMode_SourceIn);
    p.fillRect(img.rect(), color);
    p.end();
    return QIcon(QPixmap::fromImage(img));
}

class DialogTitleDragFilter : public QObject
{
public:
    explicit DialogTitleDragFilter(QWidget* dialog, QObject* parent = nullptr)
        : QObject(parent), m_dialog(dialog) {}

protected:
    bool eventFilter(QObject* watched, QEvent* event) override
    {
        Q_UNUSED(watched);
        if (!m_dialog)
            return false;
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent* me = static_cast<QMouseEvent*>(event);
            if (me->button() == Qt::LeftButton) {
                m_dragging = true;
                m_dragOffset = me->globalPos() - m_dialog->frameGeometry().topLeft();
                return true;
            }
        } else if (event->type() == QEvent::MouseMove) {
            if (m_dragging) {
                QMouseEvent* me = static_cast<QMouseEvent*>(event);
                m_dialog->move(me->globalPos() - m_dragOffset);
                return true;
            }
        } else if (event->type() == QEvent::MouseButtonRelease) {
            QMouseEvent* me = static_cast<QMouseEvent*>(event);
            if (me->button() == Qt::LeftButton) {
                m_dragging = false;
                return true;
            }
        }
        return false;
    }

private:
    QWidget* m_dialog = nullptr;
    bool m_dragging = false;
    QPoint m_dragOffset;
};
}
#include <QDateTime>
#include <QStyle>
#include <QToolButton>
#include <QCursor>
#include <QFrame>
#include <QPoint>
#include <QWindow>
#if defined(Q_OS_WIN)
#include <windows.h>
#include <windowsx.h> /* GET_X_LPARAM / GET_Y_LPARAM */
#include <dwmapi.h>
#ifdef _MSC_VER
#pragma comment(lib, "dwmapi.lib")
#endif
#endif
#include <QSize>
#include <QCoreApplication>
#include <QPainter>
#include <QPaintEvent>
#include <QStyleOptionButton>
#include <QStyleOptionFocusRect>
#include <QDir>
#include <QFileDialog>
#include <QFileInfo>
#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QStandardPaths>
#include <QDesktopServices>
#include <QKeyEvent>
#include <QEvent>
#include <QMoveEvent>
#include <QMouseEvent>
#include <QCursor>
#include <QGuiApplication>
#include <QScreen>
#include <QSignalBlocker>
#include <QListWidgetItem>
#include <QAbstractItemView>
#include <QtGlobal>
#include <QGraphicsDropShadowEffect>
#include <QImage>
#include <QPainter>
#include <QPainterPath>
#include <QSizeGrip>
#include <QSet>
#include <QColor>
#include <QDialog>
#include <QVariant>
#include <algorithm>

namespace {

QString liteViewAppDataDir()
{
    QString base = QStandardPaths::writableLocation(QStandardPaths::AppDataLocation);
    if (base.isEmpty()) {
        base = QStandardPaths::writableLocation(QStandardPaths::GenericDataLocation);
        if (!base.isEmpty())
            base += QStringLiteral("/LiteView/LiteViewBrowser");
    }
    if (base.isEmpty())
        base = QDir::homePath() + QStringLiteral("/.local/share/LiteView/LiteViewBrowser");
    if (!QDir().mkpath(base)) {
        base = QDir::homePath() + QStringLiteral("/.liteview");
        QDir().mkpath(base);
    }
    return QDir::cleanPath(base);
}

QString browserHistoryFilePath()
{
    return liteViewAppDataDir() + QStringLiteral("/history.json");
}

QString addressInputHistoryFilePath()
{
    return liteViewAppDataDir() + QStringLiteral("/address_input_history.json");
}

QString downloadRecordFilePath()
{
    return liteViewAppDataDir() + QStringLiteral("/downloads.json");
}

bool isEffectivelyMaximizedWindow(const QWidget* w)
{
    if (!w)
        return false;
    if (w->isFullScreen() || w->isMaximized())
        return true;
#ifdef Q_OS_WIN
    return false;
#else
    QScreen* screen = screenForWidget(w);
    if (!screen)
        return false;
    const QRect ag = screen->availableGeometry();
    const QRect cg = w->geometry();
    const QRect fg = w->frameGeometry();
    const int tol = 12;
    const bool edgeCovered = fg.left() <= ag.left() + tol
        && fg.top() <= ag.top() + tol
        && fg.right() >= ag.right() - tol
        && fg.bottom() >= ag.bottom() - tol;
    if (edgeCovered)
        return true;
    if (ag.width() <= 0 || ag.height() <= 0)
        return false;
    const double widthRatio = double(cg.width()) / double(ag.width());
    const double heightRatio = double(cg.height()) / double(ag.height());
    return widthRatio >= 0.97 && heightRatio >= 0.97;
#endif
}

enum DownloadListItemType {
    DownloadListItemTypeRecord = 1,
};

/** 默认/还原时窗体客户区尺寸 */
static constexpr int kDefaultWindowWidthPx = 1280;
static constexpr int kDefaultWindowHeightPx = 800;

/** 单标签栏总宽度（与未访问/已访问网页保持一致） */
static constexpr int kSingleTabBarWidthPx = 270;

/** 导航栏「下载中」合成图标边长，与 QToolButton::setIconSize(22,22) 一致 */
static constexpr int kDownloadNavIconSidePx = 22;

/** 下载中圆环与中心图标的蓝色（与列表进度条 #409eff 同系） */
static const QColor kDownloadNavBlue(0x1a, 0x73, 0xe8);

static QPixmap pixmapWithBlueTint(const QPixmap& src, const QColor& blue)
{
    if (src.isNull())
        return src;
    QPixmap r(src.size());
    r.fill(Qt::transparent);
    QPainter p(&r);
    p.fillRect(r.rect(), blue);
    p.setCompositionMode(QPainter::CompositionMode_DestinationIn);
    p.drawPixmap(0, 0, src);
    p.end();
    return r;
}

static bool isCjkUnifiedChar(QChar ch)
{
    const ushort u = ch.unicode();
    if (u >= 0x4E00 && u <= 0x9FFF)
        return true;
    if (u >= 0x3400 && u <= 0x4DBF)
        return true;
    if (u >= 0xF900 && u <= 0xFAFF)
        return true;
    return false;
}

/** 单标签标题：中文为主最多 10 字，否则英文/数字等拉丁路径最多 15 个字符（QString 字符数） */
static QString truncateTabTitleForSingleTab(const QString& full)
{
    if (full.isEmpty())
        return full;
    int cjk = 0;
    for (QChar ch : full) {
        if (isCjkUnifiedChar(ch))
            ++cjk;
    }
    const int n = full.length();
    if (cjk * 2 > n)
        return full.left(10);
    return full.left(15);
}

/** 从 images/ 按备选 stem 名加载图标（与可执行文件同目录或当前工作目录） */
QIcon loadImageFromImagesDir(const QStringList& stems)
{
    const QStringList searchRoots = {
        QCoreApplication::applicationDirPath() + QStringLiteral("/images"),
        QDir::currentPath() + QStringLiteral("/images"),
    };
    const QStringList exts = {QStringLiteral(".png"), QStringLiteral(".svg"), QStringLiteral(".jpg")};
    for (const QString& root : searchRoots) {
        for (const QString& stem : stems) {
            for (const QString& ext : exts) {
                const QString path = QDir(root).filePath(stem + ext);
                if (QFileInfo::exists(path))
                    return QIcon(path);
            }
        }
    }
    return QIcon();
}

/** 与「新标签页」占位同一套 label 图；内核无 favicon 时用作普通网页标签默认图标 */
static QIcon tabSiteFaviconFallbackIcon()
{
    static const QIcon ico = loadImageFromImagesDir({QStringLiteral("label")});
    return ico;
}

static const QString& tabBarNewTabPageTitle()
{
    static const QString s = QString::fromUtf8("\xe6\x96\xb0\xe6\xa0\x87\xe7\xad\xbe\xe9\xa1\xb5");
    return s;
}

static bool webWidgetIsOnlyNewTabPlaceholder(WebWidget* web)
{
    if (!web)
        return true;
    const QString t = web->title().trimmed();
    return t.isEmpty() || t == tabBarNewTabPageTitle();
}

/** 已加载完成的普通网页：若标签仍无站点图标则显示默认图 */
static void ensureTabSiteIconOrFallback(QTabBar* tabBar, int tabIndex, WebWidget* web)
{
    if (!tabBar || tabIndex < 0 || !web || webWidgetIsOnlyNewTabPlaceholder(web))
        return;
    if (!tabBar->tabIcon(tabIndex).isNull())
        return;
    const QIcon cached = FaviconCache::loadIconForPageUrl(web->currentUrl());
    if (!cached.isNull()) {
        tabBar->setTabIcon(tabIndex, cached);
        return;
    }
    const QIcon fb = tabSiteFaviconFallbackIcon();
    if (!fb.isNull())
        tabBar->setTabIcon(tabIndex, fb);
}

void setupDownloadDeleteButton(QPushButton* btn)
{
    if (!btn)
        return;
    const QIcon delIco = loadImageFromImagesDir(
        {QStringLiteral("nav_close2"), QStringLiteral("close2"), QStringLiteral("nav_close")});
    btn->setFixedSize(24, 24);
    btn->setCursor(Qt::PointingHandCursor);
    if (!delIco.isNull()) {
        btn->setIcon(delIco);
        btn->setIconSize(QSize(14, 14));
        btn->setText(QString());
        btn->setToolTip(QString::fromUtf8("\xe5\x88\xa0\xe9\x99\xa4"));
        btn->setStyleSheet(QStringLiteral(
            "QPushButton{border:1px solid #dcdfe6;border-radius:12px;background:#ffffff;padding:0;}"
            "QPushButton:hover{background:#fef0f0;border-color:#f56c6c;}"));
    } else {
        btn->setText(QStringLiteral("X"));
        btn->setStyleSheet(QStringLiteral(
            "QPushButton{border:1px solid #dcdfe6;border-radius:12px;background:#ffffff;color:#909399;font-weight:600;font-size:13px;padding:0;}"
            "QPushButton:hover{background:#f56c6c;color:#ffffff;border-color:#f56c6c;}"));
    }
}

QString formatDataSize(qint64 bytes)
{
    const qint64 b = qMax<qint64>(0, bytes);
    if (b >= 1024LL * 1024LL * 1024LL)
        return QStringLiteral("%1 GB").arg(QString::number(static_cast<double>(b) / (1024.0 * 1024.0 * 1024.0), 'f', 1));
    if (b >= 1024LL * 1024LL)
        return QStringLiteral("%1 MB").arg(QString::number(static_cast<double>(b) / (1024.0 * 1024.0), 'f', 1));
    if (b >= 1024LL)
        return QStringLiteral("%1 KB").arg(QString::number(static_cast<double>(b) / 1024.0, 'f', 0));
    return QStringLiteral("%1 B").arg(b);
}

QPixmap loadDownloadFileIconPixmap()
{
    QIcon ico = loadImageFromImagesDir({QStringLiteral("download_file"), QStringLiteral("file"), QStringLiteral("download_item")});
    if (ico.isNull())
        return QPixmap();
    return ico.pixmap(QSize(22, 22));
}

QPixmap buildClockIcon(int size, const QColor& color)
{
    QPixmap pm(size, size);
    pm.fill(Qt::transparent);
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing, true);
    QPen pen(color);
    pen.setWidthF(qMax(1.2, size / 9.5));
    pen.setCapStyle(Qt::RoundCap);
    p.setPen(pen);
    p.setBrush(Qt::NoBrush);
    const qreal c = size / 2.0;
    const qreal r = size / 2.0 - pen.widthF();
    p.drawEllipse(QPointF(c, c), r, r);
    p.drawLine(QPointF(c, c), QPointF(c, c - r * 0.52));
    p.drawLine(QPointF(c, c), QPointF(c + r * 0.42, c));
    return pm;
}

QPixmap rotatePixmap(const QPixmap& src, int degrees)
{
    if (src.isNull())
        return QPixmap();
    QTransform t;
    t.rotate(degrees);
    return src.transformed(t, Qt::SmoothTransformation);
}

/** 标签页标题与关闭钮之间的黑色静音标识（16px） */
QPixmap buildBlackMuteTabPixmap()
{
    const int s = 16;
    QPixmap pm(s, s);
    pm.fill(Qt::transparent);
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing, true);
    const QColor blk(0, 0, 0);
    p.setPen(QPen(blk, 1.2, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    p.setBrush(blk);
    QPolygonF speaker;
    speaker << QPointF(1.5, 6.2) << QPointF(3.7, 6.2) << QPointF(5.9, 4.1) << QPointF(5.9, 11.9)
            << QPointF(3.7, 9.8) << QPointF(1.5, 9.8);
    p.drawPolygon(speaker);
    p.setBrush(Qt::NoBrush);
    p.setPen(QPen(blk, 1.6, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    p.drawLine(QPointF(8.0, 4.6), QPointF(13.2, 11.4));
    p.drawLine(QPointF(8.0, 11.4), QPointF(13.2, 4.6));
    return pm;
}

constexpr int kMaxTabCount = 40;

void setupTabCloseToolButton(QToolButton* closeBtn)
{
    if (!closeBtn)
        return;
    const QIcon ico = loadImageFromImagesDir(
        {QStringLiteral("nav_close"), QStringLiteral("close"), QStringLiteral("tab_close")});
    if (!ico.isNull()) {
        const QSize closeSize(14, 14);
        QPixmap src = ico.pixmap(closeSize);
        if (!src.isNull()) {
            QPixmap shifted(closeSize);
            shifted.fill(Qt::transparent);
            QPainter p(&shifted);
            p.drawPixmap(0, -2, src);
            p.end();
            closeBtn->setIcon(QIcon(shifted));
        } else {
            closeBtn->setIcon(ico);
        }
        closeBtn->setIconSize(closeSize);
        closeBtn->setText(QString());
        closeBtn->setToolButtonStyle(Qt::ToolButtonIconOnly);
    } else {
        closeBtn->setText(QStringLiteral("x"));
    }
    closeBtn->setCursor(Qt::PointingHandCursor);
    closeBtn->setAutoRaise(true);
    closeBtn->setObjectName(QStringLiteral("tabCloseButton"));
    closeBtn->setFixedSize(24, 24);
    closeBtn->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    closeBtn->setStyleSheet(QStringLiteral(
        "QToolButton { border: none; background: transparent; color: #000000; font-size: 15px; "
        "padding: 0; margin: 0; min-width: 24px; min-height: 24px; }"
        "QToolButton:hover { background: rgba(0,0,0,0.08); border: none; border-radius: 12px; }"
        "QToolButton:pressed { background: rgba(0,0,0,0.14); border: none; border-radius: 12px; }"));
    closeBtn->setToolTip(QString::fromUtf8("\xe5\x85\xb3\xe9\x97\xad\xe6\xa0\x87\xe7\xad\xbe"));
}

/** 按静音图标是否显示，收缩右侧条宽度（窄标签时只保留关闭按钮区）。 */
void adjustWebTabRightStripSize(QWidget* wrap)
{
    if (!wrap)
        return;
    QLabel* mute = wrap->findChild<QLabel*>(QStringLiteral("tabMuteIcon"));
    QToolButton* closeBtn = wrap->findChild<QToolButton*>(QStringLiteral("tabCloseButton"));
    const int closeW = closeBtn ? closeBtn->width() : 24;
    const int closeH = closeBtn ? closeBtn->height() : 24;
    const QPixmap* mutePm = mute ? mute->pixmap() : nullptr;
    const bool showMute = mute && mute->isVisible() && mutePm && !mutePm->isNull();
    const int w = showMute ? (16 + 6 + closeW) : closeW;
    wrap->setFixedSize(w, qMax(24, closeH));
    wrap->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

/** 网页标签右侧：静音图标（标题后）+ 关闭；静音标签默认隐藏。 */
QWidget* createWebTabRightStrip(QWidget* tabBar, QToolButton** outClose)
{
    QWidget* wrap = new QWidget(tabBar);
    wrap->setAttribute(Qt::WA_TranslucentBackground, true);
    wrap->setAutoFillBackground(false);
    wrap->setStyleSheet(QStringLiteral("background: transparent;"));
    auto* lay = new QHBoxLayout(wrap);
    lay->setContentsMargins(0, 0, 0, 0);
    lay->setSpacing(6);
    lay->setAlignment(Qt::AlignVCenter);
    auto* muteLbl = new QLabel(wrap);
    muteLbl->setAttribute(Qt::WA_TranslucentBackground, true);
    muteLbl->setAutoFillBackground(false);
    muteLbl->setStyleSheet(QStringLiteral("background: transparent;"));
    muteLbl->setObjectName(QStringLiteral("tabMuteIcon"));
    muteLbl->setPixmap(QPixmap());
    muteLbl->setFixedSize(16, 16);
    muteLbl->setAlignment(Qt::AlignCenter);
    muteLbl->setScaledContents(false);
    muteLbl->setVisible(false);
    muteLbl->setAttribute(Qt::WA_TransparentForMouseEvents, true);
    auto* closeBtn = new QToolButton(wrap);
    setupTabCloseToolButton(closeBtn);
    lay->addWidget(muteLbl, 0, Qt::AlignVCenter);
    lay->addWidget(closeBtn, 0, Qt::AlignVCenter);
    adjustWebTabRightStripSize(wrap);
    if (outClose)
        *outClose = closeBtn;
    return wrap;
}

/** 依据 tab 右侧控件实际尺寸计算文本预留，避免首标签把关闭按钮挤出。 */
int tabRightControlReservePx(const QTabBar* tabBar, int tabIndex)
{
    const int kFallback = 34;
    if (!tabBar || tabIndex < 0 || tabIndex >= tabBar->count())
        return kFallback;
    QWidget* right = tabBar->tabButton(tabIndex, QTabBar::RightSide);
    if (!right || !right->isVisible())
        return 10;
    return qMax(kFallback, right->sizeHint().width() + 10);
}

/** 窄标签下关闭按钮是否应显示：足够宽时常显，否则仅当前/悬停标签显示。 */
bool shouldShowTabCloseButton(const QTabBar* tabBar, int tabIndex, int hoveredTabIndex)
{
    if (!tabBar || tabIndex < 0 || tabIndex >= tabBar->count())
        return false;
    QWidget* right = tabBar->tabButton(tabIndex, QTabBar::RightSide);
    if (!right)
        return false;
    const QRect tr = tabBar->tabRect(tabIndex);
    if (!tr.isValid())
        return false;
    const int stripW = qMax(right->sizeHint().width(), right->width());
    const int minWideTab = 6 + 16 + 6 + stripW;
    if (tr.width() >= minWideTab)
        return true;
    return tabIndex == tabBar->currentIndex() || tabIndex == hoveredTabIndex;
}

void setReloadButtonLoadingState(Ui::Widget* ui, bool loading)
{
    if (!ui || !ui->btnReload)
        return;
    const QIcon ico = loading
        ? loadImageFromImagesDir({QStringLiteral("nav_close"), QStringLiteral("close"), QStringLiteral("tab_close")})
        : loadImageFromImagesDir({QStringLiteral("reload"), QStringLiteral("refresh"), QStringLiteral("nav_reload")});
    if (!ico.isNull()) {
        ui->btnReload->setIcon(ico);
        ui->btnReload->setIconSize(QSize(22, 22));
        ui->btnReload->setText(QString());
        ui->btnReload->setToolButtonStyle(Qt::ToolButtonIconOnly);
    }
    ui->btnReload->setToolTip(loading
        ? QString::fromUtf8("\xe5\x81\x9c\xe6\xad\xa2\xe5\x8a\xa0\xe8\xbd\xbd")
        : QString::fromUtf8("\xe5\x88\xb7\xe6\x96\xb0"));
}

/** 从可执行文件目录下 images/ 加载导航栏图标（支持多文件名备选） */
void applyNavToolbarIcons(Ui::Widget* ui)
{
    if (!ui)
        return;
    const QSize iconSize(22, 22);
    auto apply = [&](QToolButton* b, const QStringList& stems, const QString& tip) {
        const QIcon ico = loadImageFromImagesDir(stems);
        if (ico.isNull())
            return;
        b->setIcon(ico);
        b->setIconSize(iconSize);
        b->setText(QString());
        b->setToolButtonStyle(Qt::ToolButtonIconOnly);
        b->setToolTip(tip);
    };

    apply(ui->btnBack,
        {QStringLiteral("back"), QStringLiteral("nav_back")},
        QString::fromUtf8("\xe5\x90\x8e\xe9\x80\x80"));
    apply(ui->btnForward,
        {QStringLiteral("forward"), QStringLiteral("nav_forward")},
        QString::fromUtf8("\xe5\x89\x8d\xe8\xbf\x9b"));
    apply(ui->btnReload,
        {QStringLiteral("reload"), QStringLiteral("refresh"), QStringLiteral("nav_reload")},
        QString::fromUtf8("\xe5\x88\xb7\xe6\x96\xb0"));
    apply(ui->btnHome,
        {QStringLiteral("home"), QStringLiteral("nav_home")},
        QString::fromUtf8("\xe4\xb8\xbb\xe9\xa1\xb5"));
    apply(ui->btnSettings,
        {QStringLiteral("settings"), QStringLiteral("gear"), QStringLiteral("nav_settings")},
        QString::fromUtf8("\xe8\xae\xbe\xe7\xbd\xae"));
    apply(ui->btnNewTab,
        {QStringLiteral("new_tab"), QStringLiteral("newtab"), QStringLiteral("add"), QStringLiteral("tab_new")},
        QString::fromUtf8("\xe6\x96\xb0\xe5\xbb\xba\xe6\xa0\x87\xe7\xad\xbe\xe9\xa1\xb5"));
}

class HistoryRowFrame : public QFrame
{
public:
    explicit HistoryRowFrame(QWidget* parent = nullptr)
        : QFrame(parent)
    {
        setMouseTracking(false);
    }
    QToolButton* delBtn = nullptr;

protected:
    void enterEvent(QEvent* event) override
    {
        QFrame::enterEvent(event);
        if (delBtn)
            delBtn->setVisible(true);
    }
    void leaveEvent(QEvent* event) override
    {
        const QPoint p = mapFromGlobal(QCursor::pos());
        if (rect().contains(p)) {
            QFrame::leaveEvent(event);
            return;
        }
        if (delBtn)
            delBtn->setVisible(false);
        QFrame::leaveEvent(event);
    }
};

} // namespace

//////////////////////////////////////////////////////////////////////////

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
{
    ui->setupUi(this);
    /* 去掉系统标题栏；Windows 边缘缩放/顶栏拖窗见 nativeEvent(WM_NCHITTEST)；Linux 见 eventFilter */
    setWindowFlags(windowFlags() | Qt::FramelessWindowHint);
    /* 无边框窗体画圆角：须透明背景 + 样式表绘制，四角才能透出桌面形成圆角 */
    setAttribute(Qt::WA_TranslucentBackground, true);
    setAttribute(Qt::WA_StyledBackground, true);
    setWindowTitle(QStringLiteral("LiteView Browser"));
    resize(kDefaultWindowWidthPx, kDefaultWindowHeightPx);
    setStyleSheet(
        QStringLiteral(
            "QWidget { background: #f1f3f6; color: #2a2f36; font-family: 'Microsoft YaHei','PingFang SC','Noto Sans CJK SC',sans-serif; font-size: 16px; }"
            "QScrollBar:vertical { width: 5px; margin: 0; background: transparent; }"
            "QScrollBar::handle:vertical { min-height: 24px; background: rgba(120,130,150,0.45); border-radius: 4px; }"
            "QScrollBar:horizontal { height: 5px; margin: 0; background: transparent; }"
            "QScrollBar::handle:horizontal { min-width: 24px; background: rgba(120,130,150,0.45); border-radius: 4px; }"
            "QScrollBar::add-line, QScrollBar::sub-line, QScrollBar::add-page, QScrollBar::sub-page { background: transparent; border: none; }"
            "QToolTip { font-family: 'Microsoft YaHei','PingFang SC','Noto Sans CJK SC',sans-serif; font-size: 14px; }"
            "QWidget#Widget[maximized=\"false\"] { background: #f1f3f6; border: 3px solid #ffffff; border-radius: 10px; }"
            "QWidget#navBar { background: #FFFFFF; border-left: 1px solid #DADCE0; border-right: 1px solid #DADCE0; border-bottom: 1px solid #DADCE0; border-top: none; border-radius: 0px; }"
            "QWidget#contentCard { background: #ffffff; border: 1px solid #DADCE0; border-radius: 12px; }"
            "QStackedWidget#stackedWidget { background-color: #ffffff; border: none; }"
            "QToolButton { background: #ffffff; border: 1px solid #d8dde5; border-radius: 6px; padding: 3px 8px; min-width: 28px; min-height: 24px; font-size: 16px; }"
            "QToolButton:hover { background: #f3f6ff; border-color: #aec2ff; }"
            "QToolButton:pressed { background: #e5ecff; }"
            "QWidget#navBar QToolButton { background: transparent; border: none; border-radius: 16px; }"
            "QWidget#navBar QToolButton#btnDownloads, QWidget#navBar QToolButton#btnSettings { background: #FFFFFF; }"
            "QWidget#navBar QToolButton#btnDownloads:hover, QWidget#navBar QToolButton#btnSettings:hover { border: 1px solid #B9CCEA; border-radius: 16px; "
            "background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.45, "
            "stop:0 #ECF3FF, stop:0.60 #D5E4FB, stop:1 #BBD0EE); }"
            "QWidget#navBar QToolButton#btnDownloads:pressed, QWidget#navBar QToolButton#btnSettings:pressed { border: 1px solid #A8BFE3; border-radius: 16px; "
            "background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.45, "
            "stop:0 #DCE9FB, stop:0.60 #C0D4F2, stop:1 #9FBAE0); }"
            "QWidget#navBar QToolButton:hover { border: 1px solid #B9CCEA; border-radius: 16px; "
            "background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.45, "
            "stop:0 #ECF3FF, stop:0.60 #D5E4FB, stop:1 #BBD0EE); }"
            "QWidget#navBar QToolButton:pressed { border: 1px solid #A8BFE3; border-radius: 16px; "
            "background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.45, "
            "stop:0 #DCE9FB, stop:0.60 #C0D4F2, stop:1 #9FBAE0); }"
            "QToolButton#btnNewTab { background: transparent; border: none; border-radius: 18px; min-width: 36px; max-width: 36px; min-height: 36px; max-height: 36px; padding: 0; font-size: 24px; color: #3a3f45; }"
            "QToolButton#btnNewTab:hover { background: transparent; border: none; color: #3a3f45; }"
            "QToolButton#btnNewTab:pressed { background: transparent; border: none; color: #3a3f45; }"
            "QToolButton#btnWindowMinimize, QToolButton#btnWindowMaximize, QToolButton#btnWindowClose { "
            "background: transparent; border: none; color: #202124; min-width: 36px; max-width: 36px; "
            "min-height: 34px; max-height: 36px; padding: 0; border-radius: 0; }"
            "QToolButton#btnWindowMinimize:hover, QToolButton#btnWindowMaximize:hover { background: rgba(0,0,0,0.08); }"
            "QToolButton#btnWindowClose:hover { background: #e81123; }"
            /* Chrome Omnibox：44px 高时圆角不得超过半高，否则 Qt 常画成直角；设计稿 47px 在此等效为药丸形(22px)。
               外框透明+描边，白底与圆角在 QLineEdit 上，避免子控件盖住父框圆角。 */
            "QFrame#urlOmniboxChrome { background: transparent; border: 1px solid #dadce0; border-radius: 22px; }"
            "QFrame#urlOmniboxChrome:hover { border: 1px solid #B9CCEA; }"
            "QFrame#urlOmniboxChrome[omniboxOpen=\"true\"] { border-radius: 22px 22px 0 0; border-bottom: none; }"
            "QFrame#urlOmniboxChrome[chromeFocused=\"true\"] { border: 1px solid #1a73e8; }"
            "QFrame#urlOmniboxChrome[omniboxOpen=\"true\"][chromeFocused=\"true\"] { border-bottom: none; }"
            "QFrame#urlOmniboxChromeDropdown { background: #ffffff; border: 1px solid #ECEFF3; border-top: none; "
            "border-radius: 0 0 12px 12px; }"
            "QFrame#urlOmniboxChromeDropdown[chromeFocused=\"true\"] { border: 1px solid #dadce0; border-top: none; }"
            "QLineEdit#editUrl { border: none; background: #E3E7E9; border-radius: 21px; padding: 10px 20px; "
            "font-family: 'Segoe UI','Roboto','Microsoft YaHei','PingFang SC',sans-serif; font-size: 17px; color: #202124; "
            "selection-background-color: #a8c7fa; selection-color: #202124; }"
            "QLineEdit#editUrl:hover { "
            "background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.45, "
            "stop:0 #ECF3FF, stop:0.60 #D5E4FB, stop:1 #BBD0EE); }"
            "QFrame#urlOmniboxChrome[omniboxOpen=\"true\"] QLineEdit#editUrl { border-radius: 22px 22px 0 0; }"
            "QLineEdit#editUrl:focus { border: none; outline: none; }"
            "QFrame#urlOmniboxChromeDropdown QListWidget { border: none; outline: none; background: #ffffff; "
            "selection-background-color: #ffffff; "
            "font-family: 'Segoe UI','Roboto','Microsoft YaHei','PingFang SC',sans-serif; }"
            "QFrame#urlOmniboxChromeDropdown QListWidget::viewport { background: #ffffff; }"
            "QFrame#urlOmniboxChromeDropdown QListWidget::item { padding: 0; border: none; min-height: 44px; background: #ffffff; }"
            "QFrame#urlOmniboxChromeDropdown QListWidget::item:selected { background: #ffffff; }"
            "QFrame#urlOmniboxChromeDropdown QListWidget::item:hover { background: #ffffff; }"
            "QFrame#urlOmniboxChromeDropdown QListWidget::item:selected:hover { background: #ffffff; }"
            "QWidget#topTabBar { margin: 0px; padding: 0px; background-color: #FFFFFF; border-bottom: 1px solid #DADCE0; }"
            "QTabBar { background: transparent; padding: 0px; margin: 0px; }"
            /* 视觉尽量保持原样；仅在空间不足时收缩到较小宽度 */
            "QTabBar::tab { background: #f1f3f4; color: rgba(0,0,0,0.9); border: 1px solid #dadce0; border-bottom: none; min-width: 24px; max-width: 270px; min-height: 40px; max-height: 40px; padding: 0 40px 0 5px; margin-right: 0px; border-top-left-radius: 12px; border-top-right-radius: 12px; font-family: 'PingFang SC-Regular','PingFang SC'; font-weight: 400; font-size: 14px; font-style: normal; text-align: left; }"
            "QTabBar::tab:first { margin-left: 0px; }"
            "QTabBar::tab:hover { border-color: #c4c7ce; background: #e8eaed; }"
            "QTabBar::tab:pressed { border-color: #A8BFE3; "
            "background: qradialgradient(cx:0.5, cy:0.5, radius:1.0, fx:0.5, fy:0.45, "
            "stop:0 #DCE9FB, stop:0.60 #C0D4F2, stop:1 #9FBAE0); }"
            "QTabBar::tab:selected { background: #FFFFFF; color: #202124; border-color: #DADCE0; border-left: 1px solid #DADCE0; border-right: 1px solid #DADCE0; border-bottom-color: #DADCE0; }"
            "QTabBar::tab:selected:hover { border-color: #DADCE0; border-left: 1px solid #DADCE0; border-right: 1px solid #DADCE0; background: #FFFFFF; border-bottom-color: #DADCE0; }"
            /* 窗口最大化：设计稿渐变；第二层 linear-gradient(230deg,#fff,#fff) 为纯色底，与单层渐变等价 */
            "QWidget#Widget[maximized=\"true\"] { background: qlineargradient(x1:0, y1:0, x2:0.990268, y2:0.139173, "
            "stop:0 #E1EDFB, stop:0.5145 #E5E9FD, stop:1 #F0F1F7); border: 3px solid #ffffff; border-radius: 0px; }"
            "QWidget#topTabBar[maximized=\"true\"] { background: #FFFFFF; border-bottom: 1px solid #DADCE0; }"
            "QWidget#navBar[maximized=\"true\"] { background: #FFFFFF; border-left: 1px solid #DADCE0; border-right: 1px solid #DADCE0; border-bottom: 1px solid #DADCE0; border-top: none; border-radius: 0px; }"
            "QWidget#contentCard[maximized=\"true\"] { border-radius: 0px; }"
            "QWidget#Widget[browserFullScreen=\"true\"] { background: #ffffff; border: none; border-radius: 0px; }"
            "QWidget#topTabBar[browserFullScreen=\"true\"] { background: #ffffff; border: none; }"
            "QWidget#navBar[browserFullScreen=\"true\"] { background: #ffffff; border: none; border-radius: 0px; }"
            "QWidget#contentCard[browserFullScreen=\"true\"] { background: #ffffff; border: none; border-radius: 0px; }"
            ));
    this->initForm();
    updateMaximizedChrome();
}

Widget::~Widget()
{
    if (QCoreApplication* app = QCoreApplication::instance())
        app->removeEventFilter(this);
    if (m_tabLoadingAnimTimer)
        m_tabLoadingAnimTimer->stop();
    /* 先断开各页到主窗体的连接，避免 delete ui 析构 WebWidget 时 destroyed/loadingChanged 仍回调并遍历 stackedWidget（中间态易 AV）。 */
    if (ui && ui->stackedWidget) {
        for (int i = 0; i < ui->stackedWidget->count(); ++i) {
            if (auto* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i)))
                QObject::disconnect(web, nullptr, this, nullptr);
        }
    }
    delete ui;
    ui = nullptr;
}
void Widget::closeEvent( QCloseEvent * event )
{
    /* 各平台：关窗前先收紧各网页标签的 miniblink（解菜单回调、静音、失焦、隐藏）。
     * Windows 若不做，仍挂载 HWND/音频时 Qt 析构子控件，易与 mb108 退出路径冲突并触发 Debug abort()。 */
    if (ui && ui->stackedWidget) {
        for (int i = 0; i < ui->stackedWidget->count(); ++i) {
            if (auto* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i)))
                web->preDestroyMiniblinkView();
        }
    }
#ifdef Q_OS_LINUX
    if (mbExitMessageLoop)
        mbExitMessageLoop();
    g_liteviewLinuxMessageLoopRunning.store(false, std::memory_order_release);
#endif
    if (m_downloadPanel) {
        m_downloadPanel->hide();
        m_downloadPanel->close();
    }
    event->accept();
}

void Widget::moveEvent(QMoveEvent* event)
{
    QWidget::moveEvent(event);
    /* Linux：曾在此用「窗顶贴近工作区顶 + mouseButtons」模拟贴顶最大化，但无边框自绘拖动时 move 与
     * grabMouse 交错，mouseButtons/光标 Y 条件极易误触，且反复 showMaximized 会导致伪最大化状态与 WM
     * 不同步（还原按钮无效）。贴顶最大化交由系统/用户用标题区双击或最大化按钮即可。 */
}

void Widget::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    if (m_restoringNormalSize)
        return;
    updateWindowRoundedMask();
    if (isTabBarWindowDragActive(ui)) {
        updateDownloadTabWrapWidth();
        return;
    }
    if (!isWindowMaximizedCompat())
        relayoutTopTabBar(tabBarLayoutOuterWidth());
    updateDownloadTabWrapWidth();
}

void Widget::changeEvent(QEvent* event)
{
    if (event->type() == QEvent::WindowStateChange) {
        const bool wasMaximized = (m_lastWindowChromeMaxState == 1);
        m_lastWindowChromeMaxState = -1;
        QWidget::changeEvent(event);
        if (wasMaximized && !isWindowMaximizedCompat() && !m_restoringNormalSize)
            applyNormalWindowSizeAfterRestore();
        updateMaximizedChrome();
        syncWindowFrameButtons();
        if (!isTabBarWindowDragActive(ui) && !m_restoringNormalSize) {
            relayoutTopTabBar(tabBarLayoutOuterWidth());
            refreshTabBarTitlesForLayout();
            refreshChromeAfterLayout();
        }
        if (wasMaximized && !isWindowMaximizedCompat()) {
            QTimer::singleShot(0, this, [this]() { finishWindowRestoreLayout(); });
            QTimer::singleShot(50, this, [this]() { finishWindowRestoreLayout(); });
        }
        return;
    }
    QWidget::changeEvent(event);
}

void Widget::forceWindowLayoutSync()
{
    if (!ui)
        return;
    if (layout()) {
        layout()->invalidate();
        layout()->activate();
    }
    if (ui->gridLayout) {
        ui->gridLayout->invalidate();
        ui->gridLayout->activate();
    }
    if (ui->contentCardLayout) {
        ui->contentCardLayout->invalidate();
        ui->contentCardLayout->activate();
    }
    if (ui->stackedWidget) {
        ui->stackedWidget->updateGeometry();
        if (ui->contentCard)
            ui->stackedWidget->resize(ui->contentCard->size());
        QWidget* current = ui->stackedWidget->currentWidget();
        if (current) {
            current->setGeometry(ui->stackedWidget->rect());
            current->updateGeometry();
            current->update();
        }
        ui->stackedWidget->update();
    }
    repositionOmniboxDropdown();
    if (WebWidget* w = currentWebWidget())
        w->syncViewport();
}

void Widget::syncWindowFrameButtons()
{
    if (!ui->btnWindowMinimize || !ui->btnWindowMaximize || !ui->btnWindowClose)
        return;
    constexpr int kWinFrameIco = 16;
    auto applyFrameBtn = [&](QToolButton* b, const QIcon& customIco,
                             QStyle::StandardPixmap sp, const QString& tip) {
        if (!b)
            return;
        b->setIconSize(QSize(kWinFrameIco, kWinFrameIco));
        QIcon use = customIco;
        if (use.isNull())
            use = QApplication::style()->standardIcon(sp);
        b->setIcon(use);
        b->setToolButtonStyle(Qt::ToolButtonIconOnly);
        b->setText(QString());
        b->setToolTip(tip);
        b->setEnabled(true);
        b->setVisible(true);
        b->raise();
        b->repaint();
    };
    const bool mx = isWindowMaximizedCompat();
    applyFrameBtn(ui->btnWindowMinimize, m_icoWinMinimize, QStyle::SP_TitleBarMinButton,
        QString::fromUtf8(kTipWinMinimize));
    applyFrameBtn(ui->btnWindowMaximize, mx ? m_icoWinRestore : m_icoWinMaximize,
        mx ? QStyle::SP_TitleBarNormalButton : QStyle::SP_TitleBarMaxButton,
        mx ? QString::fromUtf8(kTipWinRestore) : QString::fromUtf8(kTipWinMaximize));
    applyFrameBtn(ui->btnWindowClose, m_icoWinClose, QStyle::SP_TitleBarCloseButton,
        QString::fromUtf8(kTipWinClose));
}

bool Widget::isWindowMaximizedCompat() const
{
#ifdef Q_OS_WIN
    return isMaximized();
#else
    return isMaximized() || m_linuxPseudoMaximized;
#endif
}

bool Widget::isBrowserFullScreen() const
{
    return m_browserFullScreenActive;
}

void Widget::applyBrowserFullScreen()
{
    if (!ui)
        return;
    const bool fs = m_browserFullScreenActive;
    if (ui->gridLayout) {
        ui->gridLayout->setContentsMargins(fs ? 0 : 3, fs ? 0 : 3, fs ? 0 : 3, fs ? 0 : 3);
        ui->gridLayout->setVerticalSpacing(0);
    }
    setProperty("browserFullScreen", fs);
    if (ui->topTabBar) {
        ui->topTabBar->setProperty("browserFullScreen", fs);
        ui->topTabBar->setVisible(!fs);
    }
    if (ui->navBar) {
        ui->navBar->setProperty("browserFullScreen", fs);
        ui->navBar->setVisible(!fs);
    }
    if (ui->contentCard)
        ui->contentCard->setProperty("browserFullScreen", fs);

    auto polishW = [](QWidget* w) {
        if (!w)
            return;
        w->style()->unpolish(w);
        w->style()->polish(w);
        w->update();
    };
    polishW(this);
    polishW(ui->topTabBar);
    polishW(ui->navBar);
    polishW(ui->contentCard);
}

void Widget::enterBrowserFullScreen(WebWidget* web)
{
    if (!ui || !ui->stackedWidget)
        return;
    if (!web)
        web = currentWebWidget();
    if (!web)
        return;
    const int idx = ui->stackedWidget->indexOf(web);
    if (idx < 0)
        return;
    if (ui->tabBar && ui->tabBar->currentIndex() != idx)
        ui->tabBar->setCurrentIndex(idx);
    if (ui->stackedWidget->currentIndex() != idx)
        ui->stackedWidget->setCurrentIndex(idx);
    if (m_browserFullScreenActive) {
        m_browserFullScreenWeb = web;
        forceWindowLayoutSync();
        return;
    }

    m_browserFullScreenActive = true;
    m_browserFullScreenWeb = web;
    m_browserFullScreenRestoreMaximized = isWindowMaximizedCompat();
    m_browserFullScreenRestoreGeometry = geometry();
    releaseChromeMouseGrab();
    hideUrlSuggestPopup();
    if (m_omniboxDropdown)
        m_omniboxDropdown->hide();
    setMaximumWidth(QWIDGETSIZE_MAX);
    applyBrowserFullScreen();
    showFullScreen();
    forceWindowLayoutSync();
    QTimer::singleShot(0, this, [this, web]() {
        if (!m_browserFullScreenActive)
            return;
        forceWindowLayoutSync();
        if (web)
            web->syncViewport();
    });
}

void Widget::exitBrowserFullScreen()
{
    if (!m_browserFullScreenActive)
        return;

    const bool restoreMaximized = m_browserFullScreenRestoreMaximized;
    const QRect restoreGeometry = m_browserFullScreenRestoreGeometry;
    m_browserFullScreenActive = false;
    m_browserFullScreenWeb.clear();
    m_browserFullScreenRestoreMaximized = false;

#ifndef Q_OS_WIN
    m_linuxPseudoMaximized = false;
#endif
    showNormal();
    applyBrowserFullScreen();

    if (restoreMaximized) {
        maximizeWindowCompat();
    } else if (restoreGeometry.isValid()) {
        forceWindowFrameGeometry(restoreGeometry);
    }

    m_lastWindowChromeMaxState = -1;
    updateMaximizedChrome();
    refreshChromeAfterLayout();
    forceWindowLayoutSync();
    QTimer::singleShot(0, this, [this]() {
        if (m_browserFullScreenActive)
            return;
        updateMaximizedChrome();
        refreshChromeAfterLayout();
        forceWindowLayoutSync();
    });
}

void Widget::maximizeWindowCompat()
{
#ifdef Q_OS_WIN
    if (isFullScreen())
        return;
    if (!isMaximized())
        m_windowRestoreGeometry = geometry();
    m_normalWidthLockActive = false;
    setMaximumWidth(QWIDGETSIZE_MAX);
    showMaximized();
    updateMaximizedChrome();
    syncWindowFrameButtons();
    forceWindowLayoutSync();
    QTimer::singleShot(0, this, [this]() {
        forceWindowLayoutSync();
        stabilizeTabBarLayout();
        refreshTabBarTitlesForLayout();
    });
#else
    if (isFullScreen())
        return;
    /* 避免 moveEvent/定时器等重复调用导致 WM 与 m_linuxPseudoMaximized 不一致 */
    if (isWindowMaximizedCompat())
        return;
    if (!m_linuxPseudoMaximized && !isMaximized())
        m_windowRestoreGeometry = geometry();
    m_linuxPseudoMaximized = true;
    if (testAttribute(Qt::WA_TranslucentBackground))
        setAttribute(Qt::WA_TranslucentBackground, false);
    clearMask();
    showMaximized();
    updateMaximizedChrome();
    syncWindowFrameButtons();
    forceWindowLayoutSync();
    QTimer::singleShot(20, this, [this]() {
        if (!isMaximized()) {
            QScreen* scr = screenForWidget(this);
            const QRect ag = scr ? scr->availableGeometry()
                                 : QRect(0, 0, kDefaultWindowWidthPx, kDefaultWindowHeightPx);
            setGeometry(ag);
        }
        forceWindowLayoutSync();
    });
    QTimer::singleShot(0, this, [this]() { forceWindowLayoutSync(); });
    QTimer::singleShot(50, this, [this]() { forceWindowLayoutSync(); });
    QTimer::singleShot(120, this, [this]() { forceWindowLayoutSync(); });
#endif
}

QRect Widget::normalRestoreTargetGeometry() const
{
    QPoint topLeft = m_windowRestoreGeometry.isValid() ? m_windowRestoreGeometry.topLeft() : QPoint(-1, -1);
    if (topLeft.x() < 0 || topLeft.y() < 0) {
        QScreen* scr = screenForWidget(this);
        const QRect ag = scr ? scr->availableGeometry() : QRect();
        topLeft = ag.isValid()
            ? QPoint(ag.x() + (ag.width() - kDefaultWindowWidthPx) / 2,
                     ag.y() + (ag.height() - kDefaultWindowHeightPx) / 2)
            : QPoint(50, 50);
    }
    return QRect(topLeft.x(), topLeft.y(), kDefaultWindowWidthPx, kDefaultWindowHeightPx);
}

void Widget::releaseChromeMouseGrab()
{
    if (QWidget* g = mouseGrabber())
        g->releaseMouse();
    if (ui && ui->tabBar) {
        if (auto* tb = qobject_cast<WebTabBar*>(ui->tabBar))
            tb->cancelWindowTabDrag();
    }
    if (ui && ui->stackedWidget) {
        for (int i = 0; i < ui->stackedWidget->count(); ++i) {
            if (auto* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i)))
                web->releaseMouseCapture();
        }
    }
    m_appChromeDragging = false;
    m_appChromeDragArmed = false;
#ifndef Q_OS_WIN
    m_windowEdgeResizing = false;
    clearWindowResizeCursor();
#endif
}

void Widget::syncAllWebWidgetsViewports()
{
    if (!ui || !ui->stackedWidget)
        return;
    for (int i = 0; i < ui->stackedWidget->count(); ++i) {
        if (auto* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i)))
            web->syncViewport();
    }
}

void Widget::syncCurrentWebWidgetViewport()
{
    if (WebWidget* w = currentWebWidget())
        w->syncViewport();
}

void Widget::finishWindowRestoreLayout()
{
    if (isWindowMaximizedCompat())
        return;
    releaseChromeMouseGrab();
    hideUrlSuggestPopup();
#ifdef Q_OS_WIN
    setMinimumSize(0, 0);
#endif
    applyNormalWindowSizeAfterRestore();
    forceWindowLayoutSync();
    syncCurrentWebWidgetViewport();
    stabilizeTabBarLayout();
    updateWindowRoundedMask();
    refreshChromeAfterLayout();
    if (ui && ui->topTabBar)
        ui->topTabBar->raise();
    if (ui && ui->navBar)
        ui->navBar->raise();
    if (ui && ui->contentCard)
        ui->contentCard->lower();
    update();
    repaint();
}

void Widget::refreshChromeAfterLayout()
{
    if (!ui)
        return;
    hideUrlSuggestPopup();
    if (m_omniboxDropdown) {
        m_omniboxDropdown->hide();
        m_omniboxDropdown->lower();
    }
    if (m_browserFullScreenActive) {
        applyBrowserFullScreen();
        if (WebWidget* w = currentWebWidget())
            w->syncViewport();
        update();
        return;
    }
    if (ui->editUrl) {
        ui->editUrl->setEnabled(true);
        ui->editUrl->setReadOnly(false);
        ui->editUrl->setFocusPolicy(Qt::StrongFocus);
    }
    if (ui->navBar) {
        ui->navBar->setEnabled(true);
        ui->navBar->raise();
    }
    if (ui->topTabBar) {
        ui->topTabBar->raise();
        ui->btnWindowMinimize->raise();
        ui->btnWindowMaximize->raise();
        ui->btnWindowClose->raise();
        ui->btnNewTab->raise();
    }
    syncWindowFrameButtons();
    if (WebWidget* w = currentWebWidget())
        w->syncViewport();
    update();
}

void Widget::forceWindowFrameGeometry(const QRect& geo)
{
    if (!geo.isValid())
        return;
#ifdef Q_OS_WIN
    HWND hwnd = reinterpret_cast<HWND>(winId());
    if (hwnd) {
        SetWindowPos(hwnd, nullptr, geo.left(), geo.top(), geo.width(), geo.height(),
                     SWP_NOZORDER | SWP_NOACTIVATE);
    }
#endif
    setGeometry(geo);
}

void Widget::applyNormalWindowSizeAfterRestore()
{
    const QRect geo = normalRestoreTargetGeometry();
#ifdef Q_OS_WIN
    setMinimumSize(0, 0);
#endif
    relayoutTopTabBar(geo.width());
    forceWindowFrameGeometry(geo);
    relayoutTopTabBar(geo.width());
    if (ui->tabBar) {
        ui->tabBar->updateGeometry();
        ui->tabBar->update();
    }
    refreshTabBarTitlesForLayout();
    syncWindowFrameButtons();
}

void Widget::restoreWindowCompat()
{
#ifdef Q_OS_WIN
    if (isFullScreen())
        return;
    if (!isMaximized())
        return;
#else
    if (isFullScreen())
        return;
    if (!isWindowMaximizedCompat())
        return;
    m_linuxPseudoMaximized = false;
#endif
    releaseChromeMouseGrab();
    hideUrlSuggestPopup();
    m_restoringNormalSize = true;
    showNormal();
    m_restoringNormalSize = false;
    m_lastWindowChromeMaxState = -1;
#ifdef Q_OS_WIN
    setMinimumSize(0, 0);
#endif
    relayoutTopTabBar(kDefaultWindowWidthPx);
    m_normalWidthLockActive = true;
    setMaximumWidth(kDefaultWindowWidthPx);
    updateMaximizedChrome();
    finishWindowRestoreLayout();
    QTimer::singleShot(0, this, [this]() { finishWindowRestoreLayout(); });
    QTimer::singleShot(50, this, [this]() { finishWindowRestoreLayout(); });
    QTimer::singleShot(600, this, [this]() {
        m_normalWidthLockActive = false;
        setMaximumWidth(QWIDGETSIZE_MAX);
    });
}

void Widget::toggleWindowMaximizeCompat()
{
    if (isWindowMaximizedCompat())
        restoreWindowCompat();
    else
        maximizeWindowCompat();
}

void Widget::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);
#ifdef Q_OS_WIN
    HWND hwnd = reinterpret_cast<HWND>(winId());
    if (hwnd) {
        const LONG_PTR style = GetWindowLongPtrW(hwnd, GWL_STYLE);
        const LONG_PTR needBits = WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SYSMENU;
        if ((style & needBits) != needBits) {
            SetWindowLongPtrW(hwnd, GWL_STYLE, style | needBits);
            SetWindowPos(hwnd, nullptr, 0, 0, 0, 0,
                SWP_NOMOVE | SWP_NOSIZE | SWP_NOZORDER | SWP_NOACTIVATE | SWP_FRAMECHANGED);
        }
    }
    tryApplyWindows11RoundedCorners();
#endif
    updateWindowRoundedMask();
#ifndef Q_OS_WIN
    /* Wayland 等环境下 setMask 常不生效；延迟再算一次，避免首帧 geometry 未稳定 */
    QTimer::singleShot(0, this, [this]() { updateWindowRoundedMask(); });
#endif
}

void Widget::paintEvent(QPaintEvent* event)
{
#ifdef Q_OS_LINUX
    /* 顶层 QWidget 的 QSS border-radius 在 Linux/Wayland 上常画成直角底；父类先于子控件绘制，
     * 仅靠 DestinationOut 也无法修正子控件之后盖回的矩形。此处整窗 Source 清透明后自绘圆角底+白边，
     * 与 QSS「maximized=false」一致，四角才真正透出桌面。 */
    if (!isWindowMaximizedCompat() && !isFullScreen()) {
        Q_UNUSED(event);
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing, true);
        painter.setRenderHint(QPainter::SmoothPixmapTransform, true);
        const QRectF outer = QRectF(rect());
        painter.setCompositionMode(QPainter::CompositionMode_Source);
        painter.fillRect(outer, QColor(0, 0, 0, 0));
        painter.setCompositionMode(QPainter::CompositionMode_SourceOver);
        const qreal inset = 1.5; /* 约等于 3px 描边一半，避免笔宽被窗缘裁成直角感 */
        const QRectF body = outer.adjusted(inset, inset, -inset, -inset);
        const qreal rr = qreal(kWindowCornerRadiusPx);
        QPainterPath roundPath;
        roundPath.addRoundedRect(body, rr, rr);
        static const QColor kFrameFill(0xf1, 0xf3, 0xf6);
        static const QColor kFrameBorder(0xff, 0xff, 0xff);
        painter.fillPath(roundPath, kFrameFill);
        QPen pen(kFrameBorder, 3, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin);
        painter.setPen(pen);
        painter.setBrush(Qt::NoBrush);
        painter.drawPath(roundPath);
        return;
    }
#endif
    QWidget::paintEvent(event);
}

#if defined(Q_OS_WIN)
bool Widget::tryApplyWindows11RoundedCorners()
{
    if (m_winRoundedCornersApplied)
        return true;
    HWND hwnd = reinterpret_cast<HWND>(winId());
    if (!hwnd)
        return false;
#ifndef DWMWA_WINDOW_CORNER_PREFERENCE
#define DWMWA_WINDOW_CORNER_PREFERENCE 33
#endif
#ifndef DWMWCP_ROUND
#define DWMWCP_ROUND 2
#endif
    const DWORD pref = DWMWCP_ROUND;
    const HRESULT hr = DwmSetWindowAttribute(
        hwnd, DWMWA_WINDOW_CORNER_PREFERENCE, &pref, sizeof(pref));
    if (SUCCEEDED(hr)) {
        m_winRoundedCornersApplied = true;
        clearMask();
        /* DWM 负责圆角时不必整窗透明；保留 WA_TranslucentBackground 易在客户区与边框间出现透明缝 */
        setAttribute(Qt::WA_TranslucentBackground, false);
        update();
        return true;
    }
    return false;
}
#endif

void Widget::updateWindowRoundedMask()
{
#ifdef Q_OS_WIN
    if (m_winRoundedCornersApplied) {
        if (isMaximized() || isFullScreen())
            clearMask();
        return;
    }
    if (tryApplyWindows11RoundedCorners())
        return;
    /* 非最大化：不用整窗位图 mask；关闭整窗透明以免子控件（顶栏三键、地址栏）不刷新/无法输入 */
    if (!isWindowMaximizedCompat()) {
        clearMask();
        if (testAttribute(Qt::WA_TranslucentBackground))
            setAttribute(Qt::WA_TranslucentBackground, false);
        return;
    }
    clearMask();
    return;
#endif
#ifndef Q_OS_WIN
    if (isWindowMaximizedCompat()) {
        if (testAttribute(Qt::WA_TranslucentBackground))
            setAttribute(Qt::WA_TranslucentBackground, false);
        clearMask();
        return;
    }
    /* 非最大化：圆角由 paintEvent 自绘；禁止 setMask（尺寸切换后易命中失效），保留透明底供四角透出 */
    clearMask();
    if (!testAttribute(Qt::WA_TranslucentBackground))
        setAttribute(Qt::WA_TranslucentBackground, true);
    return;
#endif
}

void Widget::updateMaximizedChrome()
{
    if (m_browserFullScreenActive) {
        applyBrowserFullScreen();
        updateWindowRoundedMask();
        forceWindowLayoutSync();
        return;
    }
    const bool mx = isWindowMaximizedCompat();
    const int mxState = mx ? 1 : 0;
    if (m_lastWindowChromeMaxState == mxState) {
        updateWindowRoundedMask();
        return;
    }
    m_lastWindowChromeMaxState = mxState;
    if (ui->gridLayout) {
        /* 预留边框可见区：否则子控件铺满会把 QWidget#Widget 的边框覆盖掉，看起来像“透明无边框” */
        const int kWindowBorderPx = 3;
        ui->gridLayout->setContentsMargins(kWindowBorderPx, kWindowBorderPx, kWindowBorderPx, kWindowBorderPx);
        ui->gridLayout->setVerticalSpacing(0);
    }
    setProperty("maximized", mx);
    if (ui->topTabBar)
        ui->topTabBar->setProperty("maximized", mx);
    if (ui->navBar)
        ui->navBar->setProperty("maximized", mx);
    if (ui->contentCard)
        ui->contentCard->setProperty("maximized", mx);

    auto polishW = [](QWidget* w) {
        if (!w)
            return;
        w->style()->unpolish(w);
        w->style()->polish(w);
    };
    polishW(this);
    polishW(ui->topTabBar);
    polishW(ui->navBar);
    polishW(ui->contentCard);
    if (mx) {
        setMaximumWidth(QWIDGETSIZE_MAX);
        relayoutTopTabBar();
    } else {
        relayoutTopTabBar(tabBarLayoutOuterWidth());
    }
    updateWindowRoundedMask();
    refreshChromeAfterLayout();
}

void Widget::initForm()
{
    // webWidget=new WebWidget("file:///" + qApp->applicationDirPath() + "/index.html",this);//(Setting::get("url"));
#ifdef Q_OS_WIN
    // Windows：程序目录下的 mb108_x64.dll
    QString dllPath = qApp->applicationDirPath() + "/mb108_x64.dll";
    mbSetMbMainDllPath(reinterpret_cast<const WCHAR*>(dllPath.utf16()));
    mbInit(nullptr);
    if (!mbCreateWebView) {
        qWarning() << "[LiteView][mb.dll] mbCreateWebView is null after mbInit — DLL load or exports failed."
                     << "DLL path:" << dllPath
                     << "Also check DebugView / VS Output for lines prefixed [LiteView][mb.dll]";
    }
    /* 须在 mbInit 之后：先于 mbInit 调用会因未建立 Chromium AtExitManager 在 mbEnableHighDPISupport 内崩溃（NOTREACHED / RegisterCallback） */
    if (mbEnableHighDPISupport)
        mbEnableHighDPISupport();
#else
    // 其他平台：程序目录下的 livicore.so
    QString soFullPath = qApp->applicationDirPath() + "/livicore.so";
    QByteArray soPathUtf8 = soFullPath.toUtf8();
    mbInitWithPath(nullptr, soPathUtf8.constData());
#endif

    ui->tabBar->setTabsClosable(false);
    /* setMovable(true) 会让 QTabBar 为排序抢占鼠标，导致无边框窗体在标签栏上无法拖动/双击最大化 */
    ui->tabBar->setMovable(false);
    /* QTabBar::setExpanding 由 relayoutTopTabBar 按标签数切换（单标签须 expanding 以免唯一 tab 在栏内居中） */
    ui->tabBar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    ui->tabBar->setUsesScrollButtons(false);
    /* 需求：标签栏总高固定 52px（最大化/非最大化一致） */
    const int kTopTabBarHeightPx = 52;
    const int kTopTabInsetTopPx = 11;
    const int kTabBodyHeightPx = kTopTabBarHeightPx - kTopTabInsetTopPx;
    ui->tabBar->setFixedHeight(kTabBodyHeightPx);
    if (ui->topTabBar)
        ui->topTabBar->setFixedHeight(kTopTabBarHeightPx);
    /* 标签栏与「新建标签」按钮：精确间距由 relayoutTopTabBar 动态控制（单标签需左5/上10） */
    const int kWindowBorderPx = 3;
    const int kTopTabLeftPx = 12;
    const int kTopTabTopPx = 14;
    const bool mxNow = isWindowMaximizedCompat();
    /* 最大化时系统会吞掉外沿，不能再扣 3px；窗口化才做边框补偿 */
    const int appliedLeft = mxNow ? kTopTabLeftPx : qMax(0, kTopTabLeftPx - kWindowBorderPx);
    const int appliedTop = mxNow ? kTopTabTopPx : qMax(0, kTopTabTopPx - kWindowBorderPx);
    ui->topTabLayout->setContentsMargins(appliedLeft, appliedTop, 10, 0);
    ui->topTabLayout->setSpacing(0);
    ui->topTabLayout->setAlignment(Qt::AlignLeft);
    ui->btnNewTab->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
    ui->btnNewTab->setCursor(Qt::PointingHandCursor);
    ui->navBar->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
    ui->navBar->setFixedHeight(62);
    ui->stackedWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    ui->contentCardLayout->setContentsMargins(0, 0, 0, 0);
    ui->contentCardLayout->setSpacing(0);
    ui->gridLayout->setRowStretch(0, 0);
    ui->gridLayout->setRowStretch(1, 0);
    ui->gridLayout->setRowStretch(2, 1);
    ui->gridLayout->setColumnStretch(0, 1);

    ui->btnBack->setEnabled(false);
    ui->btnForward->setEnabled(false);
    ui->editUrl->clear();
    ui->btnSettings->setEnabled(true);
    {
        QFont tabFont = ui->tabBar->font();
        tabFont.setFamily(QStringLiteral("PingFang SC"));
        tabFont.setWeight(QFont::Normal);
        tabFont.setPixelSize(14);
        ui->tabBar->setFont(tabFont);
    }

    applyNavToolbarIcons(ui);
    if (m_tabLoadingBasePixmap.isNull()) {
        const QIcon loadingIco = loadImageFromImagesDir({QStringLiteral("label_loading")});
        if (!loadingIco.isNull())
            m_tabLoadingBasePixmap = loadingIco.pixmap(QSize(16, 16));
    }
    if (!m_tabLoadingAnimTimer) {
        m_tabLoadingAnimTimer = new QTimer(this);
        m_tabLoadingAnimTimer->setInterval(90);
        connect(m_tabLoadingAnimTimer, &QTimer::timeout, this, [this]() {
            if (!ui)
                return;
            m_tabLoadingAngleDeg = (m_tabLoadingAngleDeg + 30) % 360;
            refreshTabLoadingIcons();
        });
    }
    if (ui->navLayout && ui->btnSettings) {
        ui->navLayout->setSpacing(30);
        int l = 0, t = 0, r = 0, b = 0;
        ui->navLayout->getContentsMargins(&l, &t, &r, &b);
        ui->navLayout->setContentsMargins(l, t, 30, b);
        m_btnDownloads = new QToolButton(ui->navBar);
        m_btnDownloads->setObjectName(QStringLiteral("btnDownloads"));
        m_btnDownloads->setCursor(Qt::PointingHandCursor);
        const QIcon downloadIco = loadImageFromImagesDir(
            {QStringLiteral("download"), QStringLiteral("downloads"), QStringLiteral("nav_download")});
        if (!downloadIco.isNull()) {
            m_btnDownloads->setIcon(downloadIco);
            m_btnDownloads->setIconSize(QSize(kDownloadNavIconSidePx, kDownloadNavIconSidePx));
            m_btnDownloads->setText(QString());
            m_btnDownloads->setToolButtonStyle(Qt::ToolButtonIconOnly);
        } else {
            m_btnDownloads->setText(QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd"));
        }
        m_btnDownloads->setToolTip(QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe7\xae\xa1\xe7\x90\x86"));
        const int settingsIdx = ui->navLayout->indexOf(ui->btnSettings);
        if (settingsIdx >= 0) {
            /* 从主导航条取下设置按钮，与下载放入同一行子布局，间距固定 5px。 */
            ui->navLayout->takeAt(settingsIdx);
            QWidget* downloadSettingsWrap = new QWidget(ui->navBar);
            downloadSettingsWrap->setAttribute(Qt::WA_TranslucentBackground, true);
            downloadSettingsWrap->setAutoFillBackground(false);
            auto* pairLay = new QHBoxLayout(downloadSettingsWrap);
            pairLay->setContentsMargins(0, 0, 0, 0);
            pairLay->setSpacing(5);
            pairLay->addWidget(m_btnDownloads);
            pairLay->addWidget(ui->btnSettings);
            ui->navLayout->insertWidget(settingsIdx, downloadSettingsWrap);
        } else {
            ui->navLayout->addWidget(m_btnDownloads);
        }
        if (!downloadIco.isNull())
            m_downloadNavBasePixmap = downloadIco.pixmap(QSize(kDownloadNavIconSidePx, kDownloadNavIconSidePx));
        m_downloadNavAnimTimer = new QTimer(this);
        m_downloadNavAnimTimer->setInterval(50);
        connect(m_downloadNavAnimTimer, &QTimer::timeout, this, &Widget::slotDownloadNavIndeterminateTick);
    }
    if (ui->navBar) {
        const QList<QToolButton*> navToolButtons = ui->navBar->findChildren<QToolButton*>();
        for (QToolButton* btn : navToolButtons) {
            if (btn)
                btn->setCursor(Qt::PointingHandCursor);
        }
        const QList<QPushButton*> navPushButtons = ui->navBar->findChildren<QPushButton*>();
        for (QPushButton* btn : navPushButtons) {
            if (btn)
                btn->setCursor(Qt::PointingHandCursor);
        }
    }

    connect(ui->btnBack, &QToolButton::clicked, this, [this]() { if (currentWebWidget()) currentWebWidget()->goBack(); });
    connect(ui->btnForward, &QToolButton::clicked, this, [this]() { if (currentWebWidget()) currentWebWidget()->goForward(); });
    connect(ui->btnReload, &QToolButton::clicked, this, [this]() {
        if (WebWidget* web = currentWebWidget()) {
            if (web->isLoading())
                web->stop();
            else
                web->reload();
        }
    });
    connect(ui->btnHome, &QToolButton::clicked, this, &Widget::goHome);
    connect(ui->btnNewTab, &QToolButton::clicked, this, &Widget::createNewTab);

    /* 顶栏右侧：最小化 / 最大化·还原 / 关闭（无边框窗口） */
    m_icoWinMinimize = loadImageFromImagesDir({QStringLiteral("min")});
    m_icoWinMaximize = loadImageFromImagesDir({QStringLiteral("max")});
    m_icoWinRestore = loadImageFromImagesDir({QStringLiteral("narrow"), QStringLiteral("restore")});
    m_icoWinClose = loadImageFromImagesDir({QStringLiteral("nav_close"), QStringLiteral("close")});
    const int kWinFrameBtn = 36;
    for (QToolButton* b : {ui->btnWindowMinimize, ui->btnWindowMaximize, ui->btnWindowClose}) {
        if (!b)
            continue;
        b->setCursor(Qt::PointingHandCursor);
        b->setFixedSize(kWinFrameBtn, kWinFrameBtn);
        b->setAutoRaise(false);
    }
    syncWindowFrameButtons();
    connect(ui->btnWindowMinimize, &QToolButton::clicked, this, [this]() { showMinimized(); });
    connect(ui->btnWindowMaximize, &QToolButton::clicked, this, [this]() { toggleWindowMaximizeCompat(); });
    connect(ui->btnWindowClose, &QToolButton::clicked, this, &Widget::close);
    connect(ui->editUrl, &QLineEdit::returnPressed, this, &Widget::navigateToInput);
    connect(ui->tabBar, &QTabBar::tabCloseRequested, this, &Widget::closeTab);
    connect(ui->tabBar, &QTabBar::currentChanged, this, &Widget::onCurrentTabChanged);
    connect(ui->tabBar, &WebTabBar::tabContextMenuRequested, this, &Widget::onTabBarContextMenu);
    connect(ui->tabBar, &WebTabBar::tabBarInteractionChanged, this, &Widget::refreshTabBarTitlesForLayout);
    connect(ui->tabBar, &WebTabBar::windowTabDragEnded, this, [this]() {
        QTimer::singleShot(0, this, [this]() { stabilizeTabBarLayout(); });
    });

    if (ui->topTabBar)
        ui->topTabBar->installEventFilter(this);

    setupChromeOmnibox();
    ui->editUrl->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui->editUrl, &QLineEdit::customContextMenuRequested, this, [this](const QPoint&) {
        WebWidget::showCopyPasteContextMenuForLineEdit(ui->editUrl);
    });
    ui->editUrl->installEventFilter(this);
    connect(ui->editUrl, &QLineEdit::textChanged, this, [this](const QString& t) {
        if (!ui->editUrl->hasFocus())
            return;
        updateUrlSuggestPopup(t);
    });

    BrowserHistoryStore::instance();
    AddressInputHistoryStore::instance();
    loadDownloadRecordsFromDisk();

    // 启动时按「主页设置」创建首个标签：新标签页 or 特定网页
    {
        QSettings s(QSettings::IniFormat, QSettings::UserScope,
            QStringLiteral("LiteView"), QStringLiteral("LiteViewBrowser"));
        const int mode = s.value(QStringLiteral("startup/mode"), 0).toInt();
        if (mode == 0) {
            createTab(QStringLiteral("about:blank"), true, true);
        } else {
            const QString raw = s.value(QStringLiteral("startup/specificUrl"), QString()).toString().trimmed();
            const QUrl u = QUrl::fromUserInput(raw);
            if (raw.isEmpty() || !u.isValid() || u.toString().trimmed().isEmpty())
                createTab(QStringLiteral("about:blank"), true, true);
            else
                createTab(u.toString(), true, false);
        }
    }
    QTimer::singleShot(0, this, [this]() { stabilizeTabBarLayout(); });

    // 常用快捷键（使用 QAction，兼容性更好）
    QAction* actBack = new QAction(this);
    actBack->setShortcut(QKeySequence(Qt::ALT | Qt::Key_Left));
    addAction(actBack);
    connect(actBack, &QAction::triggered, this, [this]() { if (currentWebWidget()) currentWebWidget()->goBack(); });

    QAction* actForward = new QAction(this);
    actForward->setShortcut(QKeySequence(Qt::ALT | Qt::Key_Right));
    addAction(actForward);
    connect(actForward, &QAction::triggered, this, [this]() { if (currentWebWidget()) currentWebWidget()->goForward(); });

    QAction* actFocusUrl = new QAction(this);
    actFocusUrl->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_L));
    addAction(actFocusUrl);
    connect(actFocusUrl, &QAction::triggered, this, [this]() {
        ui->editUrl->setFocus();
        ui->editUrl->selectAll();
    });

    QAction* actReload = new QAction(this);
    actReload->setShortcut(QKeySequence(Qt::Key_F5));
    addAction(actReload);
    connect(actReload, &QAction::triggered, this, [this]() { if (currentWebWidget()) currentWebWidget()->reload(); });

    connect(m_btnDownloads, &QToolButton::clicked, this, [this]() {
        ensureDownloadPanel();
        if (!m_downloadPanel)
            return;
        if (m_downloadPanel->isVisible()) {
            m_downloadPanel->hide();
            return;
        }
        const QPoint at = mapToGlobal(QPoint(width() - m_downloadPanel->width() - 18 - 55, 92));
        m_downloadPanel->move(at);
        m_downloadPanel->show();
        m_downloadPanel->raise();
        m_downloadPanel->activateWindow();
    });
    connect(ui->btnSettings, &QToolButton::clicked, this, &Widget::openSettingsTab);

    /* 顶栏拖窗：子控件（标签右侧条、关闭等）会拦截事件，必须在应用级过滤 */
    qApp->installEventFilter(this);
}

bool Widget::isChromeWindowDragGrip(const QPoint& globalPos) const
{
    if (!ui || isFullScreen())
        return false;
    const QPoint lp = mapFromGlobal(globalPos);
    if (!rect().contains(lp))
        return false;

    if (ui->topTabBar && ui->topTabBar->geometry().contains(lp)) {
        const QPoint inTop = ui->topTabBar->mapFrom(this, lp);
        if (ui->btnNewTab && ui->btnNewTab->geometry().contains(inTop))
            return false;
        if (ui->btnWindowMinimize && ui->btnWindowMinimize->geometry().contains(inTop))
            return false;
        if (ui->btnWindowMaximize && ui->btnWindowMaximize->geometry().contains(inTop))
            return false;
        if (ui->btnWindowClose && ui->btnWindowClose->geometry().contains(inTop))
            return false;
        if (ui->tabBar && ui->tabBar->geometry().contains(lp)) {
            const QPoint tp = ui->tabBar->mapFrom(this, lp);
            QWidget* hit = ui->tabBar->childAt(tp);
            for (int i = 0; i < ui->tabBar->count(); ++i) {
                if (QWidget* btn = ui->tabBar->tabButton(i, QTabBar::RightSide)) {
                    const QRect hitRect = btn->geometry().adjusted(-4, -8, 4, 8);
                    const bool hitByGeom = btn->isVisible() && hitRect.contains(tp);
                    const bool hitByChild = hit && (hit == btn || btn->isAncestorOf(hit));
                    if (hitByGeom || hitByChild)
                        return false;
                }
            }
            /* tab 本体拖拽交给 WebTabBar::mouseMoveEvent，顶栏过滤器只处理 tab 间隙/空白 */
            if (ui->tabBar->tabAt(tp) >= 0)
                return false;
        }
        return true;
    }
    if (ui->navBar && ui->navBar->geometry().contains(lp)) {
        const QPoint nlp = ui->navBar->mapFrom(this, lp);
        return !ui->navBar->childAt(nlp);
    }
    return false;
}

bool Widget::isChromeDoubleClickToggleMax(const QPoint& globalPos) const
{
    if (!ui || isFullScreen())
        return false;
    const QPoint lp = mapFromGlobal(globalPos);
    if (!rect().contains(lp))
        return false;

    if (ui->topTabBar && ui->topTabBar->geometry().contains(lp)) {
        const QPoint inTop = ui->topTabBar->mapFrom(this, lp);
        if (ui->btnNewTab && ui->btnNewTab->geometry().contains(inTop))
            return false;
        if (ui->btnWindowMinimize && ui->btnWindowMinimize->geometry().contains(inTop))
            return false;
        if (ui->btnWindowMaximize && ui->btnWindowMaximize->geometry().contains(inTop))
            return false;
        if (ui->btnWindowClose && ui->btnWindowClose->geometry().contains(inTop))
            return false;
        if (ui->tabBar && ui->tabBar->geometry().contains(lp)) {
            const QPoint tp = ui->tabBar->mapFrom(this, lp);
            QWidget* hit = ui->tabBar->childAt(tp);
            for (int i = 0; i < ui->tabBar->count(); ++i) {
                if (QWidget* btn = ui->tabBar->tabButton(i, QTabBar::RightSide)) {
                    const QRect hitRect = btn->geometry().adjusted(-4, -8, 4, 8);
                    const bool hitByGeom = btn->isVisible() && hitRect.contains(tp);
                    const bool hitByChild = hit && (hit == btn || btn->isAncestorOf(hit));
                    if (hitByGeom || hitByChild)
                        return false;
                }
            }
            if (ui->tabBar->tabAt(tp) >= 0)
                return false;
            return true;
        }
        return true;
    }
    if (ui->navBar && ui->navBar->geometry().contains(lp)) {
        const QPoint nlp = ui->navBar->mapFrom(this, lp);
        return !ui->navBar->childAt(nlp);
    }
    return false;
}

#ifndef Q_OS_WIN
namespace {
constexpr int kWindowResizeBorderPx = 14;
constexpr int kWindowResizeMinWidthPx = 640;
constexpr int kWindowResizeMinHeightPx = 400;
constexpr int kEdgeLeft = 1;
constexpr int kEdgeRight = 2;
constexpr int kEdgeTop = 4;
constexpr int kEdgeBottom = 8;
} // namespace

int Widget::hitWindowResizeEdges(const QPoint& globalPos) const
{
    if (isWindowMaximizedCompat() || isFullScreen())
        return 0;
    const QPoint lp = mapFromGlobal(globalPos);
    const QRect r = rect();
    if (!r.contains(lp))
        return 0;
    int edges = 0;
    if (lp.x() >= 0 && lp.x() < kWindowResizeBorderPx)
        edges |= kEdgeLeft;
    if (lp.x() > r.width() - kWindowResizeBorderPx && lp.x() <= r.width())
        edges |= kEdgeRight;
    if (lp.y() >= 0 && lp.y() < kWindowResizeBorderPx)
        edges |= kEdgeTop;
    if (lp.y() > r.height() - kWindowResizeBorderPx && lp.y() <= r.height())
        edges |= kEdgeBottom;
    return edges;
}

Qt::CursorShape Widget::cursorForWindowResizeEdges(int edges)
{
    if ((edges & kEdgeTop) && (edges & kEdgeLeft))
        return Qt::SizeFDiagCursor;
    if ((edges & kEdgeTop) && (edges & kEdgeRight))
        return Qt::SizeBDiagCursor;
    if ((edges & kEdgeBottom) && (edges & kEdgeLeft))
        return Qt::SizeBDiagCursor;
    if ((edges & kEdgeBottom) && (edges & kEdgeRight))
        return Qt::SizeFDiagCursor;
    if (edges & (kEdgeLeft | kEdgeRight))
        return Qt::SizeHorCursor;
    if (edges & (kEdgeTop | kEdgeBottom))
        return Qt::SizeVerCursor;
    return Qt::ArrowCursor;
}

void Widget::clearWindowResizeCursor()
{
    if (!m_windowResizeCursorActive)
        return;
    QApplication::restoreOverrideCursor();
    m_windowResizeCursorActive = false;
}

void Widget::updateWindowResizeCursor(const QPoint& globalPos)
{
    if (m_windowEdgeResizing)
        return;
    const int edges = hitWindowResizeEdges(globalPos);
    if (edges) {
        const Qt::CursorShape shape = cursorForWindowResizeEdges(edges);
        if (!m_windowResizeCursorActive) {
            QApplication::setOverrideCursor(shape);
            m_windowResizeCursorActive = true;
        } else {
            QApplication::changeOverrideCursor(shape);
        }
    } else {
        clearWindowResizeCursor();
    }
}

void Widget::applyWindowEdgeResize(const QPoint& globalPos)
{
    const QPoint delta = globalPos - m_windowResizePressGlobal;
    QRect g = m_windowResizeStartGeometry;
    const int minW = qMax(minimumWidth(), kWindowResizeMinWidthPx);
    const int minH = qMax(minimumHeight(), kWindowResizeMinHeightPx);

    if (m_windowResizeEdges & kEdgeLeft) {
        const int newLeft = g.left() + delta.x();
        if (g.right() - newLeft + 1 >= minW)
            g.setLeft(newLeft);
    }
    if (m_windowResizeEdges & kEdgeRight) {
        g.setRight(g.right() + delta.x());
        if (g.width() < minW)
            g.setRight(g.left() + minW - 1);
    }
    if (m_windowResizeEdges & kEdgeTop) {
        const int newTop = g.top() + delta.y();
        if (g.bottom() - newTop + 1 >= minH)
            g.setTop(newTop);
    }
    if (m_windowResizeEdges & kEdgeBottom) {
        g.setBottom(g.bottom() + delta.y());
        if (g.height() < minH)
            g.setBottom(g.top() + minH - 1);
    }
    setGeometry(g);
}
#endif

void Widget::restoreDownloadsNavIcon()
{
    if (!m_btnDownloads)
        return;
    m_downloadIndeterminateRingDeg = 0;
    if (!m_downloadNavBasePixmap.isNull())
        m_btnDownloads->setIcon(QIcon(m_downloadNavBasePixmap));
}

void Widget::resetDownloadsNavButtonHoverState()
{
    if (!m_btnDownloads)
        return;
    m_btnDownloads->setDown(false);
    m_btnDownloads->clearFocus();
    QEvent leaveEv(QEvent::Leave);
    QCoreApplication::sendEvent(m_btnDownloads, &leaveEv);
    m_btnDownloads->style()->unpolish(m_btnDownloads);
    m_btnDownloads->style()->polish(m_btnDownloads);
    m_btnDownloads->update();
}

QPixmap Widget::buildDownloadNavProgressPixmap(bool indeterminate, double progress01, int indeterminateStartDeg) const
{
    const int s = kDownloadNavIconSidePx;
    QPixmap out(s, s);
    out.fill(Qt::transparent);
    QPainter painter(&out);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, true);

    /* 中心图标略小于整格，让外圈进度环更粗、直径更大，明显「绕」在图标外 */
    const int glyph = 15;
    if (!m_downloadNavBasePixmap.isNull()) {
        const QPixmap base = m_downloadNavBasePixmap.scaled(glyph, glyph, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        const QPixmap baseBlue = pixmapWithBlueTint(base, kDownloadNavBlue);
        const int x = (s - baseBlue.width()) / 2;
        const int y = (s - baseBlue.height()) / 2;
        painter.drawPixmap(x, y, baseBlue);
    }

    /* 外圈尽量贴近 22px 画布边缘，线宽加大，视觉圆环更大 */
    const qreal ringPenTrack = 2.35;
    const qreal ringPenProg = 2.55;
    const QRectF ringRect(
        ringPenTrack * 0.5 + 0.15,
        ringPenTrack * 0.5 + 0.15,
        s - ringPenTrack - 0.3,
        s - ringPenTrack - 0.3);
    const QColor trackCol(0xd0, 0xe8, 0xfc);
    const QColor& progCol = kDownloadNavBlue;

    painter.setPen(QPen(trackCol, ringPenTrack));
    painter.setBrush(Qt::NoBrush);
    painter.drawEllipse(ringRect);

    if (indeterminate) {
        const int span = -90 * 16; /* 顺时针 90° */
        const int start = static_cast<int>((90.0 - double(indeterminateStartDeg % 360)) * 16.0);
        painter.setPen(QPen(progCol, ringPenProg));
        painter.drawArc(ringRect.toRect(), start, span);
    } else {
        const double p = qBound(0.0, progress01, 1.0);
        if (p > 0.001) {
            const int span = -static_cast<int>(p * 360.0 * 16.0);
            const int start = 90 * 16; /* 从 12 点顺时针填充 */
            painter.setPen(QPen(progCol, ringPenProg));
            painter.drawArc(ringRect.toRect(), start, span);
        }
    }

    painter.end();
    if (m_btnDownloads)
        out.setDevicePixelRatio(m_btnDownloads->devicePixelRatioF());
    return out;
}

void Widget::updateDownloadsNavButtonVisual()
{
    if (!m_btnDownloads || m_downloadNavBasePixmap.isNull())
        return;

    int active = 0;
    qint64 sumRKnown = 0;
    qint64 sumTKnown = 0;
    qint64 sumRUnknown = 0;

    for (auto it = m_downloadTasks.constBegin(); it != m_downloadTasks.constEnd(); ++it) {
        const DownloadRecord rec = m_downloadRecords.value(it.key());
        /* 须同时认记录：部分环境下 finish 已写入 m_downloadRecords 而 meta.finished 未及时一致，
         * 否则已完成文件仍占总量，圆环长期像「还有一大段未下完」。 */
        if (it->finished || rec.finished)
            continue;
        ++active;
        if (rec.totalBytes > 0) {
            sumRKnown += qMin(rec.receivedBytes, rec.totalBytes);
            sumTKnown += rec.totalBytes;
        } else {
            /* 无 Content-Length 的任务：已收字节仍应并入导航环的「总量」观感 */
            sumRUnknown += qMax<qint64>(0, rec.receivedBytes);
        }
    }

    if (active <= 0) {
        if (m_downloadNavAnimTimer)
            m_downloadNavAnimTimer->stop();
        restoreDownloadsNavIcon();
        return;
    }

    /* 至少有一个已知总大小时：分子 = 各任务已收（已知任务 cap 在 total）+ 未知任务已收；
     * 分母 = 已知 total 之和 + 未知任务已收（把未知部分按「当前至少已这么多」摊进总量），多任务并行时圆环为合并进度 */
    if (sumTKnown > 0) {
        if (m_downloadNavAnimTimer)
            m_downloadNavAnimTimer->stop();
        const qint64 num = sumRKnown + sumRUnknown;
        const qint64 den = sumTKnown + sumRUnknown;
        const double p = den > 0 ? qBound(0.0, double(num) / double(den), 1.0) : 0.0;
        m_btnDownloads->setIcon(QIcon(buildDownloadNavProgressPixmap(false, p, 0)));
        return;
    }

    /* 进行中任务全部未知总大小时：不定进度，用旋转弧 */
    if (m_downloadNavAnimTimer && !m_downloadNavAnimTimer->isActive())
        m_downloadNavAnimTimer->start();
    m_btnDownloads->setIcon(QIcon(buildDownloadNavProgressPixmap(true, 0.0, m_downloadIndeterminateRingDeg)));
}

void Widget::slotDownloadNavIndeterminateTick()
{
    if (!m_btnDownloads || m_downloadNavBasePixmap.isNull())
        return;

    int active = 0;
    qint64 sumT = 0;
    for (auto it = m_downloadTasks.constBegin(); it != m_downloadTasks.constEnd(); ++it) {
        const DownloadRecord rec = m_downloadRecords.value(it.key());
        if (it->finished || rec.finished)
            continue;
        ++active;
        sumT += qMax<qint64>(0, rec.totalBytes);
    }

    if (active <= 0 || sumT > 0) {
        if (m_downloadNavAnimTimer)
            m_downloadNavAnimTimer->stop();
        updateDownloadsNavButtonVisual();
        return;
    }

    m_downloadIndeterminateRingDeg = (m_downloadIndeterminateRingDeg + 14) % 360;
    m_btnDownloads->setIcon(QIcon(buildDownloadNavProgressPixmap(true, 0.0, m_downloadIndeterminateRingDeg)));
}

void Widget::openDownloadPageTab()
{
    ensureDownloadTabPage();
    if (!m_downloadTabPage || !ui->stackedWidget)
        return;
    const int i = ui->stackedWidget->indexOf(m_downloadTabPage.data());
    if (i < 0)
        return;
    ui->tabBar->setCurrentIndex(i);
    ui->stackedWidget->setCurrentIndex(i);
    updateDownloadTabWrapWidth();
    QTimer::singleShot(0, this, [this]() { updateDownloadTabWrapWidth(); });
    QTimer::singleShot(30, this, [this]() { updateDownloadTabWrapWidth(); });
    rebuildDownloadTabListFromRecords();
    updateUiFromCurrentTab();
}

void Widget::updateDownloadTabWrapWidth()
{
    if ((!m_downloadTabWrap && !m_downloadTabHeaderWrap) || !m_downloadTabPage)
        return;
    const int pageW = m_downloadTabPage->width();
    if (pageW <= 0)
        return;
    const int available = qMax(1, pageW - 56);
    const int minTarget = qMin(640, available);
    const int target = qBound(minTarget, static_cast<int>(available * 0.9), available);
    if (m_downloadTabHeaderWrap)
        m_downloadTabHeaderWrap->setFixedWidth(target);
    if (m_downloadTabWrap)
        m_downloadTabWrap->setFixedWidth(target);
}

void Widget::requestDownloadTabRebuild(bool immediate)
{
    if (immediate) {
        m_downloadTabRebuildScheduled = false;
        rebuildDownloadTabListFromRecords();
        return;
    }
    if (m_downloadTabRebuildScheduled)
        return;
    m_downloadTabRebuildScheduled = true;
    QTimer::singleShot(120, this, [this]() {
        m_downloadTabRebuildScheduled = false;
        rebuildDownloadTabListFromRecords();
    });
}

QListWidgetItem* Widget::findDownloadTabItem(const QString& savePath) const
{
    if (!m_downloadTabList || savePath.trimmed().isEmpty())
        return nullptr;
    for (int i = 0; i < m_downloadTabList->count(); ++i) {
        QListWidgetItem* item = m_downloadTabList->item(i);
        if (!item)
            continue;
        if (item->data(Qt::UserRole + 10).toInt() != DownloadListItemTypeRecord)
            continue;
        if (item->data(Qt::UserRole).toString() == savePath)
            return item;
    }
    return nullptr;
}

bool Widget::updateDownloadTabItemWidget(const QString& savePath)
{
    if (!m_downloadTabList || savePath.trimmed().isEmpty())
        return false;
    const DownloadRecord rec = m_downloadRecords.value(savePath);
    if (rec.savePath.trimmed().isEmpty())
        return false;
    QListWidgetItem* item = findDownloadTabItem(savePath);
    if (!item)
        return false;
    QWidget* row = m_downloadTabList->itemWidget(item);
    if (!row)
        return false;

    auto* titleLbl = row->findChild<QLabel*>(QStringLiteral("downloadTitlePage"));
    auto* urlLbl = row->findChild<QLabel*>(QStringLiteral("downloadUrlPage"));
    auto* sizeLbl = row->findChild<QLabel*>(QStringLiteral("downloadMetaPage"));
    auto* statusLbl = row->findChild<QLabel*>(QStringLiteral("downloadStatusBadgePage"));
    auto* progress = row->findChild<QProgressBar*>(QStringLiteral("downloadProgressPage"));
    auto* speedLbl = row->findChild<QLabel*>(QStringLiteral("downloadSpeedPage"));
    auto* progressTextLbl = row->findChild<QLabel*>(QStringLiteral("downloadProgressTextPage"));
    auto* progressWrap = row->findChild<QWidget*>(QStringLiteral("downloadProgressWrapPage"));
    auto* btnCopy = row->findChild<QToolButton*>(QStringLiteral("downloadCopyLinkPage"));
    auto* btnDelete = row->findChild<QToolButton*>(QStringLiteral("downloadDeleteRecordPage"));
    auto* openText = row->findChild<QPushButton*>(QStringLiteral("downloadOpenOpenDirText"));
    if (rec.finished && rec.success && !openText) {
        auto* v = qobject_cast<QVBoxLayout*>(row->layout());
        if (v) {
            openText = new QPushButton(QString::fromUtf8("在文件夹中打开"), row);
            openText->setObjectName(QStringLiteral("downloadOpenOpenDirText"));
            openText->setCursor(Qt::PointingHandCursor);
            openText->setIcon(loadImageFromImagesDir({QStringLiteral("folder_black"), QStringLiteral("folder"), QStringLiteral("open_dir"), QStringLiteral("download_open")}));
            openText->setIconSize(QSize(15, 15));
            v->addWidget(openText, 0, Qt::AlignLeft);
            connect(openText, &QPushButton::clicked, this, [p = rec.savePath]() {
                QDesktopServices::openUrl(QUrl::fromLocalFile(QFileInfo(p).absolutePath()));
            });
        }
    }

    if (titleLbl)
        titleLbl->setText(rec.title.isEmpty() ? QFileInfo(rec.savePath).fileName() : rec.title);
    if (urlLbl)
        urlLbl->setText(rec.url);
    if (sizeLbl)
        sizeLbl->setText(formatDataSize(rec.totalBytes > 0 ? rec.totalBytes : rec.receivedBytes));
    if (statusLbl) {
        if (rec.finished && rec.success) {
            statusLbl->setProperty("state", QStringLiteral("done"));
            statusLbl->setText(QString::fromUtf8("已完成"));
        } else if (rec.finished && !rec.success) {
            statusLbl->setProperty("state", QStringLiteral("failed"));
            statusLbl->setText(QString::fromUtf8("失败"));
        } else {
            statusLbl->setProperty("state", QStringLiteral("running"));
            statusLbl->setText(QString::fromUtf8("下载中"));
        }
        statusLbl->style()->unpolish(statusLbl);
        statusLbl->style()->polish(statusLbl);
    }
    const bool running = !rec.finished;
    if (progress) {
        if (rec.totalBytes > 0) {
            progress->setRange(0, 100);
            progress->setValue(static_cast<int>(qBound<qint64>(0, (rec.receivedBytes * 100) / rec.totalBytes, 100)));
        } else if (running) {
            progress->setRange(0, 0);
        } else {
            progress->setRange(0, 100);
            progress->setValue(rec.success ? 100 : 0);
        }
    }
    if (progressWrap)
        progressWrap->setVisible(running);
    if (speedLbl) {
        if (running && rec.speedBytesPerSec > 0)
            speedLbl->setText(QStringLiteral("%1/s").arg(formatDataSize(rec.speedBytesPerSec)));
        else if (running)
            speedLbl->setText(QString::fromUtf8("下载中"));
        else
            speedLbl->setText(QString());
    }
    if (progressTextLbl) {
        auto formatMB = [](qint64 bytes) -> QString {
            const double mb = qMax<qint64>(0, bytes) / (1024.0 * 1024.0);
            return QStringLiteral("%1MB").arg(QString::number(mb, 'f', 1));
        };
        const int pct = (rec.totalBytes > 0)
            ? static_cast<int>(qBound<qint64>(0, (rec.receivedBytes * 100) / rec.totalBytes, 100))
            : (rec.finished && rec.success ? 100 : 0);
        const QString recvMb = formatMB(rec.receivedBytes);
        const QString totalMb = (rec.totalBytes > 0) ? formatMB(rec.totalBytes) : QStringLiteral("--");
        if (running || rec.finished) {
            progressTextLbl->setText(QString::fromUtf8("已下载 %1%, %2/%3").arg(pct).arg(recvMb, totalMb));
        } else {
            progressTextLbl->setText(QString());
        }
    }
    if (btnCopy)
        btnCopy->setVisible(rec.finished);
    if (btnDelete)
        btnDelete->setVisible(rec.finished);
    if (openText)
        openText->setVisible(rec.finished && rec.success);

    item->setSizeHint(QSize(qMax(560, m_downloadTabList->viewport()->width() - 4), running ? 126 : 108));
    row->update();
    return true;
}

void Widget::ensureDownloadTabPage()
{
    if (m_downloadTabPage && ui->stackedWidget->indexOf(m_downloadTabPage.data()) >= 0)
        return;

    auto* page = new QWidget(ui->stackedWidget);
    page->setObjectName(QStringLiteral("downloadManageTabRoot"));
    page->setAttribute(Qt::WA_StyledBackground, true);
    page->setStyleSheet(QStringLiteral(
        "QWidget#downloadManageTabRoot { background:#F7F9FC; }"
        "QFrame#downloadManageHeaderWrap { background:#F7F9FC; border:none; }"
        "QFrame#downloadManageWrap { background:#F7F9FC; border:1px solid #dfe3e8; border-radius:8px; }"
        "QFrame#downloadManageTopLine { background:#e6e9ee; min-height:1px; max-height:1px; border:none; }"
        "QLabel#downloadManageTitle { background:#F7F9FC; color:#202124; font-size:24px; font-weight:600; }"
        "QPushButton#downloadManageClear { border:1px solid #d7dbe2; border-radius:6px; background:#fff; color:#5f6368; min-height:34px; padding:0 14px; font-size:14px; }"
        "QPushButton#downloadManageClear:hover { background:#f7f9fc; }"
        "QListWidget#downloadManageList { border:none; background:#F7F9FC; outline:none; }"
        "QListWidget#downloadManageList::viewport { background:#F7F9FC; }"
        "QListWidget#downloadManageList::item { border:none; }"
        "QFrame#downloadRowPage { background:#F7F9FC; border-bottom:1px solid #eef1f4; }"
        "QFrame#downloadRowPage[hovered=\"true\"] { background:#F7F9FC; }"
        "QFrame#downloadRowPage QWidget, QFrame#downloadRowPage QLabel { background:#F7F9FC; }"
        "QLabel#downloadTitlePage { color:#262a31; font-size:15px; font-weight:500; }"
        "QLabel#downloadUrlPage { color:#8a9099; font-size:12px; }"
        "QLabel#downloadMetaPage { color:#7a808c; font-size:13px; }"
        "QLabel#downloadStatusBadgePage { border-radius:8px; padding:3px 10px; font-size:12px; font-weight:600; }"
        "QLabel#downloadStatusBadgePage[state=\"done\"] { color:#35b06a; background:#e7f8ea; }"
        "QLabel#downloadStatusBadgePage[state=\"running\"] { color:#5d8cf2; background:#e8f2ff; }"
        "QLabel#downloadStatusBadgePage[state=\"failed\"] { color:#e06a7a; background:#fdecef; }"
        "QProgressBar#downloadProgressPage { border:none; border-radius:4px; background:#e1e5eb; min-height:6px; max-height:6px; }"
        "QProgressBar#downloadProgressPage::chunk { border-radius:4px; background:#4d8cf5; }"
        "QLabel#downloadSpeedPage, QLabel#downloadProgressTextPage { color:#7a808c; font-size:12px; }"
        "QToolButton#downloadCopyLinkPage, QToolButton#downloadDeleteRecordPage { border:none; background:transparent; min-width:22px; max-width:22px; min-height:22px; max-height:22px; }"
        "QToolButton#downloadCopyLinkPage:hover, QToolButton#downloadDeleteRecordPage:hover { background:#f5f7fa; border-radius:4px; }"
        "QPushButton#downloadOpenOpenDirText { border:1px solid #d7dbe2; border-radius:6px; background:#fff; color:#4b525f; min-height:28px; padding:0 12px; }"
        "QPushButton#downloadOpenOpenDirText:hover { background:#f7f9fc; }"
        "QLabel#downloadManageEmptyTitle { color:#4d5563; font-size:18px; font-weight:500; }"
        "QLabel#downloadManageEmptySub { color:#8a9099; font-size:13px; }"));

    auto* root = new QVBoxLayout(page);
    root->setContentsMargins(28, 22, 28, 22);
    root->setSpacing(0);

    auto* headerRow = new QHBoxLayout();
    headerRow->setContentsMargins(0, 0, 0, 0);
    headerRow->setSpacing(0);
    root->addLayout(headerRow);

    auto* headerWrap = new QFrame(page);
    headerWrap->setObjectName(QStringLiteral("downloadManageHeaderWrap"));
    m_downloadTabHeaderWrap = headerWrap;
    auto* headerLay = new QVBoxLayout(headerWrap);
    headerLay->setContentsMargins(0, 0, 0, 0);
    headerLay->setSpacing(0);

    auto* title = new QLabel(QString::fromUtf8("下载管理"), headerWrap);
    title->setObjectName(QStringLiteral("downloadManageTitle"));
    headerLay->addWidget(title, 0, Qt::AlignLeft | Qt::AlignTop);
    headerLay->addSpacing(30);

    auto* topLine = new QFrame(headerWrap);
    topLine->setObjectName(QStringLiteral("downloadManageTopLine"));
    headerLay->addWidget(topLine);
    headerLay->addSpacing(10);

    auto* clearRow = new QHBoxLayout();
    clearRow->setContentsMargins(0, 15, 0, 15);
    clearRow->setSpacing(0);
    auto* clearBtn = new QPushButton(QString::fromUtf8("清空下载记录"), headerWrap);
    clearBtn->setObjectName(QStringLiteral("downloadManageClear"));
    clearBtn->setCursor(Qt::PointingHandCursor);
    clearRow->addStretch(1);
    clearRow->addWidget(clearBtn, 0, Qt::AlignRight | Qt::AlignBottom);
    headerLay->addLayout(clearRow);

    headerRow->addStretch(1);
    headerRow->addWidget(headerWrap, 1);
    headerRow->addStretch(1);
    root->addSpacing(12);

    auto* wrapRow = new QHBoxLayout();
    wrapRow->setContentsMargins(0, 0, 0, 0);
    wrapRow->setSpacing(0);
    root->addLayout(wrapRow, 1);

    auto* wrap = new QFrame(page);
    wrap->setObjectName(QStringLiteral("downloadManageWrap"));
    m_downloadTabWrap = wrap;
    wrap->setMinimumHeight(390);
    auto* wrapLay = new QVBoxLayout(wrap);
    wrapLay->setContentsMargins(0, 0, 0, 0);
    wrapLay->setSpacing(0);
    wrapRow->addStretch(1);
    wrapRow->addWidget(wrap, 1);
    wrapRow->addStretch(1);

    m_downloadTabList = new QListWidget(wrap);
    m_downloadTabList->setObjectName(QStringLiteral("downloadManageList"));
    m_downloadTabList->setSelectionMode(QAbstractItemView::NoSelection);
    m_downloadTabList->setFocusPolicy(Qt::NoFocus);
    m_downloadTabList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_downloadTabList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    m_downloadTabList->setFrameShape(QFrame::NoFrame);
    m_downloadTabList->setSpacing(20);
    m_downloadTabList->setMouseTracking(true);
    m_downloadTabList->installEventFilter(this);
    m_downloadTabList->viewport()->installEventFilter(this);
    wrapLay->addWidget(m_downloadTabList, 1);

    connect(clearBtn, &QPushButton::clicked, this, [this]() { clearAllDownloadRecords(); });

    m_downloadTabPage = page;
    const int index = ui->stackedWidget->addWidget(page);
    ui->tabBar->addTab(QString());
    ui->tabBar->setTabData(index, QVariant(QString::fromUtf8("下载管理")));
    QToolButton* closeBtn = new QToolButton(ui->tabBar);
    setupTabCloseToolButton(closeBtn);
    ui->tabBar->setTabButton(index, QTabBar::RightSide, closeBtn);
    connect(closeBtn, &QToolButton::clicked, this, [this, closeBtn]() {
        for (int i = 0; i < ui->tabBar->count(); ++i) {
            if (ui->tabBar->tabButton(i, QTabBar::RightSide) == closeBtn) {
                closeTab(i);
                break;
            }
        }
    });
    connect(page, &QObject::destroyed, this, [this]() {
        m_downloadTabPage = nullptr;
        m_downloadTabHeaderWrap = nullptr;
        m_downloadTabWrap = nullptr;
        m_downloadTabList = nullptr;
        m_downloadTabRebuildScheduled = false;
        m_downloadTabListRebuilding = false;
        m_downloadTabResizeRebuildPending = false;
        m_lastDownloadTabViewportWidth = -1;
    });
    updateDownloadTabWrapWidth();
    rebuildDownloadTabListFromRecords();
    QTimer::singleShot(30, this, [this]() { rebuildDownloadTabListFromRecords(); });
    QTimer::singleShot(0, this, [this]() { stabilizeTabBarLayout(); });
}

void Widget::rebuildDownloadTabListFromRecords()
{
    if (!m_downloadTabList || m_downloadTabListRebuilding)
        return;
    struct RebuildFlagGuard {
        bool& flag;
        explicit RebuildFlagGuard(bool& f) : flag(f) { flag = true; }
        ~RebuildFlagGuard() { flag = false; }
    } rebuildGuard(m_downloadTabListRebuilding);

    if (m_downloadTabList->viewport())
        m_lastDownloadTabViewportWidth = m_downloadTabList->viewport()->width();
    m_downloadTabList->clear();
    const int rowW = qMax(560, m_downloadTabList->viewport()->width() - 4);
    QList<DownloadRecord> records = m_downloadRecords.values();
    std::sort(records.begin(), records.end(), [](const DownloadRecord& a, const DownloadRecord& b) {
        return a.updatedAt > b.updatedAt;
    });
    if (records.isEmpty()) {
        auto* it = new QListWidgetItem(m_downloadTabList);
        it->setFlags(Qt::NoItemFlags);
        it->setSizeHint(QSize(rowW, 210));
        auto* box = new QWidget(m_downloadTabList);
        auto* lay = new QVBoxLayout(box);
        lay->setContentsMargins(0, 56, 0, 0);
        lay->setSpacing(8);
        auto* t = new QLabel(QString::fromUtf8("暂无下载记录"), box);
        t->setObjectName(QStringLiteral("downloadManageEmptyTitle"));
        t->setAlignment(Qt::AlignHCenter);
        auto* s = new QLabel(QString::fromUtf8("下载任务会显示在这里"), box);
        s->setObjectName(QStringLiteral("downloadManageEmptySub"));
        s->setAlignment(Qt::AlignHCenter);
        lay->addWidget(t);
        lay->addWidget(s);
        m_downloadTabList->setItemWidget(it, box);
        return;
    }

    for (const DownloadRecord& rec : records) {
        auto* item = new QListWidgetItem(m_downloadTabList);
        item->setData(Qt::UserRole + 10, DownloadListItemTypeRecord);
        item->setData(Qt::UserRole, rec.savePath);
        const bool running = !rec.finished;
        item->setSizeHint(QSize(rowW, running ? 126 : 108));

        auto* row = new QFrame(m_downloadTabList);
        row->setObjectName(QStringLiteral("downloadRowPage"));
        row->setProperty("hovered", false);
        row->setProperty("downloadSavePath", rec.savePath);
        row->setMouseTracking(true);
        row->installEventFilter(this);
        auto* v = new QVBoxLayout(row);
        v->setContentsMargins(16, 11, 34, 11);
        v->setSpacing(10);

        auto* top = new QHBoxLayout();
        top->setContentsMargins(0, 0, 0, 0);
        top->setSpacing(10);
        auto* titleWrap = new QVBoxLayout();
        titleWrap->setContentsMargins(0, 0, 0, 0);
        titleWrap->setSpacing(10);
        auto* titleLbl = new QLabel(rec.title.isEmpty() ? QFileInfo(rec.savePath).fileName() : rec.title, row);
        titleLbl->setObjectName(QStringLiteral("downloadTitlePage"));
        titleLbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        auto* urlLbl = new QLabel(rec.url, row);
        urlLbl->setObjectName(QStringLiteral("downloadUrlPage"));
        urlLbl->setTextInteractionFlags(Qt::TextSelectableByMouse);
        titleWrap->addWidget(titleLbl);
        titleWrap->addWidget(urlLbl);
        auto* sizeLbl = new QLabel(formatDataSize(rec.totalBytes > 0 ? rec.totalBytes : rec.receivedBytes), row);
        sizeLbl->setObjectName(QStringLiteral("downloadMetaPage"));
        sizeLbl->setFixedWidth(72);
        sizeLbl->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        auto* statusLbl = new QLabel(row);
        statusLbl->setObjectName(QStringLiteral("downloadStatusBadgePage"));
        statusLbl->setFixedWidth(58);
        statusLbl->setAlignment(Qt::AlignCenter);
        if (rec.finished && rec.success) {
            statusLbl->setProperty("state", QStringLiteral("done"));
            statusLbl->setText(QString::fromUtf8("已完成"));
        } else if (rec.finished && !rec.success) {
            statusLbl->setProperty("state", QStringLiteral("failed"));
            statusLbl->setText(QString::fromUtf8("失败"));
        } else {
            statusLbl->setProperty("state", QStringLiteral("running"));
            statusLbl->setText(QString::fromUtf8("下载中"));
        }
        statusLbl->style()->unpolish(statusLbl);
        statusLbl->style()->polish(statusLbl);

        auto* btnCopy = new QToolButton(row);
        btnCopy->setObjectName(QStringLiteral("downloadCopyLinkPage"));
        btnCopy->setCursor(Qt::PointingHandCursor);
        QIcon icoCopy = loadImageFromImagesDir({QStringLiteral("copy")});
        if (icoCopy.isNull())
            icoCopy = style()->standardIcon(QStyle::SP_FileDialogDetailedView);
        btnCopy->setIcon(icoCopy);
        btnCopy->setIconSize(QSize(15, 15));
        btnCopy->setToolTip(QString::fromUtf8("复制下载链接"));
        auto* btnDelete = new QToolButton(row);
        btnDelete->setObjectName(QStringLiteral("downloadDeleteRecordPage"));
        QIcon icoDelete = loadImageFromImagesDir({QStringLiteral("trash"), QStringLiteral("nav_close"), QStringLiteral("close"), QStringLiteral("delete")});
        if (icoDelete.isNull())
            icoDelete = style()->standardIcon(QStyle::SP_DialogCloseButton);
        btnDelete->setIcon(icoDelete);
        btnDelete->setIconSize(QSize(15, 15));
        btnDelete->setToolTip(QString::fromUtf8("删除记录"));
        btnDelete->setCursor(Qt::PointingHandCursor);
        auto* actionLay = new QHBoxLayout();
        actionLay->setContentsMargins(0, 0, 0, 0);
        actionLay->setSpacing(6);
        actionLay->addWidget(btnCopy);
        actionLay->addWidget(btnDelete);
        auto* actionWrap = new QWidget(row);
        actionWrap->setLayout(actionLay);
        actionWrap->setFixedWidth(78);
        top->addLayout(titleWrap, 1);
        top->addWidget(sizeLbl, 0, Qt::AlignVCenter);
        top->addWidget(statusLbl, 0, Qt::AlignVCenter);
        top->addSpacing(150);
        top->addWidget(actionWrap, 0, Qt::AlignVCenter);
        v->addLayout(top);

        auto* progressWrap = new QWidget(row);
        progressWrap->setObjectName(QStringLiteral("downloadProgressWrapPage"));
        auto* pv = new QVBoxLayout(progressWrap);
        const int kProgressRightAlignReserve = 228; // 150 间距 + 78 按钮区：进度条右侧与状态列右侧齐平
        pv->setContentsMargins(0, 0, kProgressRightAlignReserve, 0);
        pv->setSpacing(5);
        auto* summary = new QHBoxLayout();
        summary->setContentsMargins(0, 0, 0, 0);
        summary->setSpacing(0);
        auto* speedLbl = new QLabel(progressWrap);
        speedLbl->setObjectName(QStringLiteral("downloadSpeedPage"));
        if (!rec.finished && rec.speedBytesPerSec > 0)
            speedLbl->setText(QStringLiteral("%1/s").arg(formatDataSize(rec.speedBytesPerSec)));
        else if (!rec.finished)
            speedLbl->setText(QString::fromUtf8("下载中"));
        auto* progressTextLbl = new QLabel(progressWrap);
        progressTextLbl->setObjectName(QStringLiteral("downloadProgressTextPage"));
        summary->addWidget(speedLbl, 0, Qt::AlignLeft | Qt::AlignVCenter);
        summary->addStretch(1);
        summary->addWidget(progressTextLbl, 0, Qt::AlignRight | Qt::AlignVCenter);
        auto* progress = new QProgressBar(progressWrap);
        progress->setObjectName(QStringLiteral("downloadProgressPage"));
        progress->setTextVisible(false);
        progress->setRange(0, 100);
        if (rec.totalBytes > 0)
            progress->setValue(static_cast<int>(qBound<qint64>(0, (rec.receivedBytes * 100) / rec.totalBytes, 100)));
        else if (!rec.finished)
            progress->setRange(0, 0);
        auto formatMB = [](qint64 bytes) -> QString {
            const double mb = qMax<qint64>(0, bytes) / (1024.0 * 1024.0);
            return QStringLiteral("%1MB").arg(QString::number(mb, 'f', 1));
        };
        const int pct = (rec.totalBytes > 0)
            ? static_cast<int>(qBound<qint64>(0, (rec.receivedBytes * 100) / rec.totalBytes, 100))
            : (rec.finished && rec.success ? 100 : 0);
        const QString recvMb = formatMB(rec.receivedBytes);
        const QString totalMb = (rec.totalBytes > 0) ? formatMB(rec.totalBytes) : QStringLiteral("--");
        progressTextLbl->setText(QString::fromUtf8("已下载 %1%, %2/%3").arg(pct).arg(recvMb, totalMb));
        pv->addLayout(summary);
        pv->addWidget(progress);
        progressWrap->setVisible(!rec.finished);
        v->addWidget(progressWrap);

        if (rec.finished && rec.success) {
            auto* openText = new QPushButton(QString::fromUtf8("在文件夹中打开"), row);
            openText->setObjectName(QStringLiteral("downloadOpenOpenDirText"));
            openText->setCursor(Qt::PointingHandCursor);
            openText->setIcon(loadImageFromImagesDir({QStringLiteral("folder_black"), QStringLiteral("folder"), QStringLiteral("open_dir"), QStringLiteral("download_open")}));
            openText->setIconSize(QSize(15, 15));
            v->addWidget(openText, 0, Qt::AlignLeft);
            connect(openText, &QPushButton::clicked, this, [p = rec.savePath]() {
                QDesktopServices::openUrl(QUrl::fromLocalFile(QFileInfo(p).absolutePath()));
            });
        }

        connect(btnCopy, &QToolButton::clicked, this, [u = rec.url]() {
            QApplication::clipboard()->setText(u);
        });
        connect(btnDelete, &QToolButton::clicked, this, [this, p = rec.savePath]() { removeDownloadRecord(p); });
        m_downloadTabList->setItemWidget(item, row);
    }
}

void Widget::clearAllDownloadRecords()
{
    m_downloadRecords.clear();
    m_downloadTasks.clear();
    saveDownloadRecordsToDisk();
    rebuildDownloadListFromRecords();
    requestDownloadTabRebuild(true);
}

void Widget::removeDownloadRecord(const QString& savePath)
{
    if (savePath.trimmed().isEmpty())
        return;
    m_downloadRecords.remove(savePath);
    m_downloadTasks.remove(savePath);
    saveDownloadRecordsToDisk();
    rebuildDownloadListFromRecords();
    requestDownloadTabRebuild(true);
}

void Widget::ensureDownloadPanel()
{
    if (m_downloadPanel && m_downloadList) {
        m_downloadPanel->setSizeGripEnabled(false);
        const QList<QSizeGrip*> grips = m_downloadPanel->findChildren<QSizeGrip*>();
        for (QSizeGrip* grip : grips) {
            if (!grip)
                continue;
            grip->hide();
            grip->setFixedSize(0, 0);
        }
        return;
    }

    QDialog* panel = new QDialog(this, Qt::Popup | Qt::FramelessWindowHint | Qt::MSWindowsFixedSizeDialogHint);
    panel->setObjectName(QStringLiteral("downloadPanelDialog"));
    panel->setAttribute(Qt::WA_DeleteOnClose, false);
    panel->setAttribute(Qt::WA_TranslucentBackground, true);
    panel->setSizeGripEnabled(false);
    panel->installEventFilter(this);
    panel->setWindowTitle(QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe7\xae\xa1\xe7\x90\x86"));
    panel->setFixedSize(560, 600);
    panel->setStyleSheet(QStringLiteral(
        "QDialog#downloadPanelDialog { background: transparent; border: none; }"
        "QSizeGrip { width: 0px; height: 0px; image: none; }"
        "QFrame#downloadPanelShell { background: #FFFFFF; border-radius: 16px; border: 2px solid #E0E0E0; }"
        "QFrame#downloadPanelHeader { border-bottom: 1px solid #ECEFF3; background: #ffffff; }"
        "QLabel#downloadPanelTitle { background: #ffffff; color: #1f2329; font-size: 19px; font-weight: 700; }"
        "QToolButton#downloadClearAllBtn { border: none; background: transparent; color: #737A86; font-size: 17px; padding: 0; }"
        "QToolButton#downloadClearAllBtn:hover { color: #4D8CF5; }"
        "QListWidget { border: none; background: #ffffff; outline: none; }"
        "QListWidget::viewport { background: #ffffff; }"
        "QListWidget::item { border: none; }"
        "QFrame#downloadRow { background: #ffffff; border-top: 1px solid #ECEFF3; }"
        "QFrame#downloadRow[hovered=\"true\"] { background: #ffffff; }"
        "QFrame#downloadRow QLabel, QFrame#downloadRow QWidget { background: transparent; }"
        "QLabel#downloadTitle { color:#262a31; font-size:16px; font-weight:500; }"
        "QLabel#downloadMeta { color:#7A808C; font-size:14px; font-weight:400; }"
        "QLabel#downloadStatusBadge { border-radius: 6px; padding: 3px 12px; font-size:14px; font-weight:600; }"
        "QLabel#downloadStatusBadge[state=\"done\"] { color:#35B06A; background:#E7F8EA; }"
        "QLabel#downloadStatusBadge[state=\"running\"] { color:#5D8CF2; background:#E8F2FF; }"
        "QLabel#downloadStatusBadge[state=\"failed\"] { color:#E06A7A; background:#FDECEF; }"
        "QProgressBar#downloadProgress { border:none; border-radius:3px; background:#E1E5EB; min-height:6px; max-height:6px; }"
        "QProgressBar#downloadProgress::chunk { border-radius:3px; background:#4D8CF5; }"
        "QLabel#downloadSpeed, QLabel#downloadProgressText { color:#6F7682; font-size:14px; }"
        "QToolButton#downloadCopyLink, QToolButton#downloadDeleteRecord { border:none; background:transparent; min-width:28px; min-height:28px; }"
        "QToolButton#downloadCopyLink:hover, QToolButton#downloadDeleteRecord:hover { background:#ffffff; border-radius:6px; }"
        "QPushButton#downloadOpenPageBtn { border:none; border-top:1px solid #ECEFF3; background:#ffffff; color:#7CA5F6; font-size:16px; min-height:60px; border-bottom-left-radius:14px; border-bottom-right-radius:14px; }"
        "QPushButton#downloadOpenPageBtn:hover { background:#ffffff; }"));

    auto* rootLay = new QVBoxLayout(panel);
    rootLay->setContentsMargins(0, 0, 0, 0);
    rootLay->setSpacing(0);

    auto* shell = new QFrame(panel);
    shell->setObjectName(QStringLiteral("downloadPanelShell"));
    shell->setAttribute(Qt::WA_StyledBackground, true);
    auto* shellLay = new QVBoxLayout(shell);
    /* 内容区与外壳留白，避免白色子控件覆盖圆角灰边 */
    shellLay->setContentsMargins(2, 2, 2, 2);
    shellLay->setSpacing(0);
    rootLay->addWidget(shell);

    auto* header = new QFrame(shell);
    header->setObjectName(QStringLiteral("downloadPanelHeader"));
    auto* headerLay = new QHBoxLayout(header);
    headerLay->setContentsMargins(24, 18, 24, 14);
    headerLay->setSpacing(8);
    auto* titleLbl = new QLabel(QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe7\xae\xa1\xe7\x90\x86"), header);
    titleLbl->setObjectName(QStringLiteral("downloadPanelTitle"));
    auto* clearAllBtn = new QToolButton(header);
    clearAllBtn->setObjectName(QStringLiteral("downloadClearAllBtn"));
    clearAllBtn->setCursor(Qt::PointingHandCursor);
    clearAllBtn->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
    clearAllBtn->setText(QString::fromUtf8("\xe6\xb8\x85\xe7\xa9\xba\xe4\xb8\x8b\xe8\xbd\xbd\xe8\xae\xb0\xe5\xbd\x95"));
    clearAllBtn->setIcon(loadImageFromImagesDir({QStringLiteral("clear"), QStringLiteral("delete_all"), QStringLiteral("trash")}));
    clearAllBtn->setIconSize(QSize(22, 22));
    headerLay->addWidget(titleLbl);
    headerLay->addStretch(1);
    headerLay->addWidget(clearAllBtn);
    shellLay->addWidget(header);

    m_downloadList = new QListWidget(shell);
    m_downloadList->setSelectionMode(QAbstractItemView::NoSelection);
    m_downloadList->setFocusPolicy(Qt::NoFocus);
    m_downloadList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_downloadList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
    m_downloadList->setFrameShape(QFrame::NoFrame);
    m_downloadList->setSpacing(0);
    shellLay->addWidget(m_downloadList, 1);

    auto* btnOpenPage = new QPushButton(QString::fromUtf8("\xe6\x89\x93\xe5\xbc\x80\xe4\xb8\x8b\xe8\xbd\xbd\xe9\xa1\xb5\xe9\x9d\xa2"), shell);
    btnOpenPage->setObjectName(QStringLiteral("downloadOpenPageBtn"));
    btnOpenPage->setCursor(Qt::PointingHandCursor);
    shellLay->addWidget(btnOpenPage, 0);

    connect(clearAllBtn, &QToolButton::clicked, this, [this]() {
        clearAllDownloadRecords();
    });
    connect(btnOpenPage, &QPushButton::clicked, this, [this, panel]() {
        panel->hide();
        openDownloadPageTab();
    });
    connect(panel, &QObject::destroyed, this, [this]() {
        m_downloadPanel = nullptr;
        m_downloadList = nullptr;
    });

    const QList<QSizeGrip*> grips = panel->findChildren<QSizeGrip*>();
    for (QSizeGrip* grip : grips) {
        if (!grip)
            continue;
        grip->hide();
        grip->setFixedSize(0, 0);
    }

    m_downloadPanel = panel;
    rebuildDownloadListFromRecords();
}

QListWidgetItem* Widget::findDownloadItem(const QString& savePath) const
{
    if (!m_downloadList)
        return nullptr;
    for (int i = 0; i < m_downloadList->count(); ++i) {
        QListWidgetItem* item = m_downloadList->item(i);
        if (!item)
            continue;
        if (item->data(Qt::UserRole + 10).toInt() != DownloadListItemTypeRecord)
            continue;
        if (item->data(Qt::UserRole).toString() == savePath)
            return item;
    }
    return nullptr;
}

QWidget* Widget::ensureDownloadItemWidget(const QString& savePath)
{
    if (!m_downloadList)
        return nullptr;
    QListWidgetItem* item = findDownloadItem(savePath);
    if (!item) {
        item = new QListWidgetItem(m_downloadList);
        item->setData(Qt::UserRole + 10, DownloadListItemTypeRecord);
        item->setData(Qt::UserRole, savePath);
        item->setData(Qt::UserRole + 2, false);
        item->setSizeHint(QSize(532, 90));
    }
    QWidget* row = m_downloadList->itemWidget(item);
    if (row)
        return row;

    auto* rowFrame = new QFrame(m_downloadList);
    rowFrame->setObjectName(QStringLiteral("downloadRow"));
    rowFrame->setProperty("hovered", false);
    rowFrame->setProperty("downloadSavePath", savePath);
    rowFrame->setMouseTracking(true);
    auto* v = new QVBoxLayout(rowFrame);
    v->setContentsMargins(18, 12, 18, 12);
    v->setSpacing(8);

    auto* top = new QHBoxLayout();
    top->setContentsMargins(0, 0, 0, 0);
    top->setSpacing(12);

    auto* fileIcon = new QLabel(rowFrame);
    fileIcon->setObjectName(QStringLiteral("downloadFileIcon"));
    fileIcon->setFixedSize(22, 22);
    fileIcon->setScaledContents(true);

    auto* titleLbl = new QLabel(rowFrame);
    titleLbl->setObjectName(QStringLiteral("downloadTitle"));
    titleLbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    titleLbl->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    auto* sizeLbl = new QLabel(rowFrame);
    sizeLbl->setObjectName(QStringLiteral("downloadMeta"));
    sizeLbl->setAlignment(Qt::AlignVCenter | Qt::AlignLeft);

    auto* badgeLbl = new QLabel(rowFrame);
    badgeLbl->setObjectName(QStringLiteral("downloadStatusBadge"));
    badgeLbl->setAlignment(Qt::AlignCenter);

    auto* btnCopyLink = new QToolButton(rowFrame);
    btnCopyLink->setObjectName(QStringLiteral("downloadCopyLink"));
    btnCopyLink->setCursor(Qt::PointingHandCursor);
    btnCopyLink->setIcon(loadImageFromImagesDir({QStringLiteral("folder")}));
    btnCopyLink->setIconSize(QSize(20, 20));
    btnCopyLink->setToolTip(QString::fromUtf8("\u6253\u5f00\u6587\u4ef6\u5939"));
    btnCopyLink->setVisible(false);

    auto* btnDeleteRecord = new QToolButton(rowFrame);
    btnDeleteRecord->setObjectName(QStringLiteral("downloadDeleteRecord"));
    btnDeleteRecord->setCursor(Qt::PointingHandCursor);
    btnDeleteRecord->setIcon(loadImageFromImagesDir({QStringLiteral("trash"), QStringLiteral("nav_close"), QStringLiteral("close"), QStringLiteral("delete")}));
    btnDeleteRecord->setIconSize(QSize(16, 16));
    btnDeleteRecord->setToolTip(QString::fromUtf8("\xe5\x88\xa0\xe9\x99\xa4\xe8\xae\xb0\xe5\xbd\x95"));
    btnDeleteRecord->setVisible(false);

    top->addWidget(fileIcon, 0, Qt::AlignVCenter);
    top->addSpacing(6);
    top->addWidget(titleLbl, 1);
    top->addWidget(sizeLbl, 0, Qt::AlignVCenter);
    top->addSpacing(8);
    top->addWidget(badgeLbl, 0, Qt::AlignVCenter);
    top->addSpacing(8);
    top->addWidget(btnCopyLink, 0, Qt::AlignVCenter);
    top->addWidget(btnDeleteRecord, 0, Qt::AlignVCenter);

    auto* progressWrap = new QWidget(rowFrame);
    progressWrap->setObjectName(QStringLiteral("downloadProgressWrap"));
    auto* pv = new QVBoxLayout(progressWrap);
    pv->setContentsMargins(40, 0, 0, 0);
    pv->setSpacing(5);
    auto* progress = new QProgressBar(rowFrame);
    progress->setObjectName(QStringLiteral("downloadProgress"));
    progress->setTextVisible(false);
    progress->setRange(0, 100);
    progress->setValue(0);
    auto* speedLbl = new QLabel(progressWrap);
    speedLbl->setObjectName(QStringLiteral("downloadSpeed"));
    auto* progressTextLbl = new QLabel(progressWrap);
    progressTextLbl->setObjectName(QStringLiteral("downloadProgressText"));
    auto* infoRow = new QHBoxLayout();
    infoRow->setContentsMargins(0, 0, 0, 0);
    infoRow->setSpacing(8);
    infoRow->addWidget(speedLbl);
    infoRow->addStretch(1);
    infoRow->addWidget(progressTextLbl);
    pv->addWidget(progress);
    pv->addLayout(infoRow);

    v->addLayout(top);
    v->addWidget(progressWrap);
    rowFrame->setLayout(v);
    m_downloadList->setItemWidget(item, rowFrame);

    connect(btnCopyLink, &QToolButton::clicked, this, [this, savePath]() {
        const QString path = m_downloadRecords.value(savePath).savePath;
        if (path.trimmed().isEmpty())
            return;
        QDesktopServices::openUrl(QUrl::fromLocalFile(QFileInfo(path).absolutePath()));
    });
    connect(btnDeleteRecord, &QToolButton::clicked, this, [this, savePath]() {
        removeDownloadRecord(savePath);
    });
    rowFrame->installEventFilter(this);

    QPixmap pm = loadDownloadFileIconPixmap();
    if (!pm.isNull())
        fileIcon->setPixmap(pm);

    return rowFrame;
}

void Widget::updateDownloadItemWidget(
    const QString& savePath,
    const QString& title,
    const QString& status,
    qint64 receivedBytes,
    qint64 totalBytes,
    bool finished,
    bool success)
{
    if (savePath.trimmed().isEmpty())
        return;

    const bool existed = m_downloadRecords.contains(savePath);
    const DownloadRecord oldRec = m_downloadRecords.value(savePath);
    /* 已完成后的迟滞 downloadProgress：勿把 finished 拉回 false，否则导航合并进度仍把该文件算进总量 */
    if (oldRec.finished && !finished && receivedBytes > 0)
        return;
    DownloadRecord rec = oldRec;
    rec.savePath = savePath;
    if (!title.trimmed().isEmpty())
        rec.title = title.trimmed();
    if (!status.trimmed().isEmpty())
        rec.status = status.trimmed();
    rec.receivedBytes = qMax<qint64>(0, receivedBytes);
    rec.totalBytes = qMax<qint64>(0, totalBytes);
    rec.finished = finished;
    rec.success = success;
    const QDateTime now = QDateTime::currentDateTime();
    rec.updatedAt = now;
    rec.speedBytesPerSec = 0;
    if (existed && !finished && !oldRec.finished && oldRec.updatedAt.isValid() && rec.receivedBytes >= oldRec.receivedBytes) {
        const qint64 dtMs = qMax<qint64>(1, oldRec.updatedAt.msecsTo(now));
        const qint64 delta = rec.receivedBytes - oldRec.receivedBytes;
        rec.speedBytesPerSec = (delta * 1000) / dtMs;
    }
    if (rec.dateKey.trimmed().isEmpty())
        rec.dateKey = rec.updatedAt.date().toString(QStringLiteral("yyyy-MM-dd"));
    m_downloadRecords.insert(savePath, rec);
    if (!existed || finished)
        saveDownloadRecordsToDisk();

    if (!m_downloadList) {
        if (!updateDownloadTabItemWidget(savePath))
            requestDownloadTabRebuild(false);
        return;
    }

    QListWidgetItem* item = findDownloadItem(savePath);
    if (!item) {
        rebuildDownloadListFromRecords();
        return;
    }
    item->setData(Qt::UserRole + 2, rec.finished);

    QWidget* row = m_downloadList->itemWidget(item);
    if (!row) {
        rebuildDownloadListFromRecords();
        return;
    }

    auto* titleLbl = row->findChild<QLabel*>(QStringLiteral("downloadTitle"));
    auto* sizeLbl = row->findChild<QLabel*>(QStringLiteral("downloadMeta"));
    auto* statusLbl = row->findChild<QLabel*>(QStringLiteral("downloadStatusBadge"));
    auto* progress = row->findChild<QProgressBar*>(QStringLiteral("downloadProgress"));
    auto* progressWrap = row->findChild<QWidget*>(QStringLiteral("downloadProgressWrap"));
    auto* speedLbl = row->findChild<QLabel*>(QStringLiteral("downloadSpeed"));
    auto* progressTextLbl = row->findChild<QLabel*>(QStringLiteral("downloadProgressText"));
    auto* btnCopyLink = row->findChild<QToolButton*>(QStringLiteral("downloadCopyLink"));
    auto* btnDeleteRecord = row->findChild<QToolButton*>(QStringLiteral("downloadDeleteRecord"));

    if (titleLbl)
        titleLbl->setText(rec.title.isEmpty() ? QFileInfo(rec.savePath).fileName() : rec.title);
    if (sizeLbl)
        sizeLbl->setText(formatDataSize(rec.totalBytes > 0 ? rec.totalBytes : rec.receivedBytes));
    if (statusLbl) {
        if (rec.finished && rec.success) {
            statusLbl->setProperty("state", QStringLiteral("done"));
            statusLbl->setText(QString::fromUtf8("\xe5\xb7\xb2\xe5\xae\x8c\xe6\x88\x90"));
        } else if (rec.finished && !rec.success) {
            statusLbl->setProperty("state", QStringLiteral("failed"));
            statusLbl->setText(QString::fromUtf8("\xe5\xa4\xb1\xe8\xb4\xa5"));
        } else {
            statusLbl->setProperty("state", QStringLiteral("running"));
            statusLbl->setText(QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe4\xb8\xad"));
        }
        statusLbl->style()->unpolish(statusLbl);
        statusLbl->style()->polish(statusLbl);
    }
    if (progress) {
        const bool running = !rec.finished;
        if (progressWrap)
            progressWrap->setVisible(running);
        if (rec.totalBytes > 0) {
            progress->setRange(0, 100);
            const int pct = static_cast<int>(qBound<qint64>(0, (rec.receivedBytes * 100) / rec.totalBytes, 100));
            const int shown = running ? pct : (rec.success ? 100 : qMax(0, qMin(pct, 100)));
            progress->setValue(shown);
        } else if (running) {
            progress->setRange(0, 0);
        } else {
            progress->setRange(0, 100);
            progress->setValue(rec.success ? 100 : 0);
        }
    }
    if (speedLbl) {
        if (!rec.finished && rec.speedBytesPerSec > 0)
            speedLbl->setText(QStringLiteral("%1/s").arg(formatDataSize(rec.speedBytesPerSec)));
        else if (!rec.finished)
            speedLbl->setText(QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe4\xb8\xad"));
        else
            speedLbl->setText(QString());
    }
    if (progressTextLbl) {
        if (!rec.finished && rec.totalBytes > 0)
            progressTextLbl->setText(QStringLiteral("%1/%2").arg(formatDataSize(rec.receivedBytes), formatDataSize(rec.totalBytes)));
        else if (!rec.finished)
            progressTextLbl->setText(formatDataSize(rec.receivedBytes));
        else
            progressTextLbl->setText(QString());
    }

    const bool showActions = rec.finished && row->property("hovered").toBool();
    if (btnCopyLink)
        btnCopyLink->setVisible(showActions);
    if (btnDeleteRecord)
        btnDeleteRecord->setVisible(showActions);

    item->setSizeHint(QSize(532, rec.finished ? 78 : 116));
    if (!updateDownloadTabItemWidget(savePath))
        requestDownloadTabRebuild(false);
}

void Widget::rebuildDownloadListFromRecords()
{
    if (!m_downloadList)
        return;
    m_downloadList->clear();
    if (m_downloadRecords.isEmpty())
        return;

    QList<DownloadRecord> records = m_downloadRecords.values();
    std::sort(records.begin(), records.end(), [](const DownloadRecord& a, const DownloadRecord& b) {
        return a.updatedAt > b.updatedAt;
    });

    for (const DownloadRecord& rec : records) {
        QWidget* row = ensureDownloadItemWidget(rec.savePath);
        QListWidgetItem* item = findDownloadItem(rec.savePath);
        if (item && row) {
            item->setData(Qt::UserRole + 2, rec.finished);
            updateDownloadItemWidget(
                rec.savePath,
                rec.title.isEmpty() ? QFileInfo(rec.savePath).fileName() : rec.title,
                rec.status,
                rec.receivedBytes,
                rec.totalBytes,
                rec.finished,
                rec.success);
        }
    }
    requestDownloadTabRebuild(true);
}

void Widget::loadDownloadRecordsFromDisk()
{
    m_downloadRecords.clear();
    QFile f(downloadRecordFilePath());
    if (!f.open(QIODevice::ReadOnly))
        return;
    const QByteArray data = f.readAll();
    f.close();
    QJsonParseError err;
    const QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if (err.error != QJsonParseError::NoError || !doc.isArray())
        return;
    const QJsonArray arr = doc.array();
    for (const QJsonValue& v : arr) {
        if (!v.isObject())
            continue;
        const QJsonObject o = v.toObject();
        DownloadRecord rec;
        rec.savePath = o.value(QStringLiteral("savePath")).toString().trimmed();
        rec.url = o.value(QStringLiteral("url")).toString();
        rec.title = o.value(QStringLiteral("title")).toString();
        rec.status = o.value(QStringLiteral("status")).toString();
        rec.dateKey = o.value(QStringLiteral("dateKey")).toString();
        rec.receivedBytes = static_cast<qint64>(o.value(QStringLiteral("receivedBytes")).toDouble(0));
        rec.totalBytes = static_cast<qint64>(o.value(QStringLiteral("totalBytes")).toDouble(0));
        rec.finished = o.value(QStringLiteral("finished")).toBool(false);
        rec.success = o.value(QStringLiteral("success")).toBool(false);
        rec.updatedAt = QDateTime::fromString(o.value(QStringLiteral("updatedAt")).toString(), Qt::ISODate);
        if (rec.savePath.isEmpty())
            continue;
        if (!rec.updatedAt.isValid())
            rec.updatedAt = QDateTime::currentDateTime();
        if (rec.dateKey.trimmed().isEmpty())
            rec.dateKey = rec.updatedAt.date().toString(QStringLiteral("yyyy-MM-dd"));
        m_downloadRecords.insert(rec.savePath, rec);
    }
}

void Widget::saveDownloadRecordsToDisk() const
{
    QJsonArray arr;
    const QList<DownloadRecord> records = m_downloadRecords.values();
    for (const DownloadRecord& rec : records) {
        QJsonObject o;
        o.insert(QStringLiteral("savePath"), rec.savePath);
        o.insert(QStringLiteral("url"), rec.url);
        o.insert(QStringLiteral("title"), rec.title);
        o.insert(QStringLiteral("status"), rec.status);
        o.insert(QStringLiteral("dateKey"), rec.dateKey);
        o.insert(QStringLiteral("receivedBytes"), static_cast<double>(rec.receivedBytes));
        o.insert(QStringLiteral("totalBytes"), static_cast<double>(rec.totalBytes));
        o.insert(QStringLiteral("finished"), rec.finished);
        o.insert(QStringLiteral("success"), rec.success);
        o.insert(QStringLiteral("updatedAt"), rec.updatedAt.toString(Qt::ISODate));
        arr.append(o);
    }
    const QString path = downloadRecordFilePath();
    QDir().mkpath(QFileInfo(path).absolutePath());
    QFile f(path);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return;
    f.write(QJsonDocument(arr).toJson(QJsonDocument::Compact));
    f.close();
}

void Widget::removeDownloadRecordsByDate(const QString& dateKey)
{
    if (dateKey.trimmed().isEmpty())
        return;
    QList<QString> keys = m_downloadRecords.keys();
    for (const QString& key : keys) {
        if (m_downloadRecords.value(key).dateKey == dateKey) {
            m_downloadRecords.remove(key);
            m_downloadTasks.remove(key);
        }
    }
    saveDownloadRecordsToDisk();
    rebuildDownloadListFromRecords();
}

void Widget::polishOmniboxChromeFrameFocus(bool focused)
{
    if (!m_omniboxFrame)
        return;
    m_omniboxFrame->setProperty("chromeFocused", focused);
    m_omniboxFrame->style()->unpolish(m_omniboxFrame);
    m_omniboxFrame->style()->polish(m_omniboxFrame);
    if (m_omniboxDropdown) {
        m_omniboxDropdown->setProperty("chromeFocused", focused);
        m_omniboxDropdown->style()->unpolish(m_omniboxDropdown);
        m_omniboxDropdown->style()->polish(m_omniboxDropdown);
    }
}

void Widget::setOmniboxOpen(bool open)
{
    if (!m_omniboxFrame)
        return;
    m_omniboxFrame->setProperty("omniboxOpen", open);
    m_omniboxFrame->style()->unpolish(m_omniboxFrame);
    m_omniboxFrame->style()->polish(m_omniboxFrame);
}

void Widget::repositionOmniboxDropdown()
{
    if (!m_omniboxFrame || !m_omniboxDropdown || !m_urlSuggestList)
        return;
    if (!m_omniboxDropdown->isVisible())
        return;
    const QPoint topLeft = m_omniboxFrame->mapTo(this, QPoint(0, 0));
    const int w = m_omniboxFrame->width();
    const int fh = m_omniboxFrame->height();
    m_omniboxDropdown->adjustSize();
    const int dh = m_omniboxDropdown->height();
    m_omniboxDropdown->setGeometry(topLeft.x(), topLeft.y() + fh - 1, w, dh);
    const int radius = 10;
    if (w > 0 && dh > 0) {
        QPainterPath path;
        path.moveTo(0, 0);
        path.lineTo(w, 0);
        path.lineTo(w, dh - radius);
        path.quadTo(w, dh, w - radius, dh);
        path.lineTo(radius, dh);
        path.quadTo(0, dh, 0, dh - radius);
        path.closeSubpath();
        m_omniboxDropdown->setMask(QRegion(path.toFillPolygon().toPolygon()));
    }
    m_omniboxDropdown->raise();
}

void Widget::setupChromeOmnibox()
{
    QHBoxLayout* nav = ui->navLayout;
    int idx = -1;
    for (int i = 0; i < nav->count(); ++i) {
        QLayoutItem* it = nav->itemAt(i);
        if (it && it->widget() == ui->editUrl) {
            idx = i;
            break;
        }
    }
    if (idx < 0)
        return;
    QLayoutItem* removed = nav->takeAt(idx);
    delete removed;

    m_omniboxFrame = new QFrame(ui->navBar);
    m_omniboxFrame->setObjectName(QStringLiteral("urlOmniboxChrome"));
    m_omniboxFrame->setAttribute(Qt::WA_StyledBackground, true);
    m_omniboxFrame->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    m_omniboxFrame->setFixedHeight(44);

    auto* v = new QVBoxLayout(m_omniboxFrame);
    v->setContentsMargins(0, 0, 0, 0);
    v->setSpacing(0);

    ui->editUrl->setParent(m_omniboxFrame);
    ui->editUrl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
    v->addWidget(ui->editUrl);

    nav->insertWidget(idx, m_omniboxFrame, 1);

    m_omniboxDropdown = new QFrame(this);
    m_omniboxDropdown->setObjectName(QStringLiteral("urlOmniboxChromeDropdown"));
    m_omniboxDropdown->setAttribute(Qt::WA_StyledBackground, true);
    m_omniboxDropdown->setFocusPolicy(Qt::NoFocus);
    m_omniboxDropdown->hide();
    auto* dropdownShadow = new QGraphicsDropShadowEffect(m_omniboxDropdown);
    dropdownShadow->setBlurRadius(20);
    dropdownShadow->setOffset(0, 4);
    dropdownShadow->setColor(QColor(0, 0, 0, 26));
    m_omniboxDropdown->setGraphicsEffect(dropdownShadow);

    auto* dv = new QVBoxLayout(m_omniboxDropdown);
    dv->setContentsMargins(0, 0, 0, 0);
    dv->setSpacing(0);

    m_omniboxSep = new QFrame(m_omniboxDropdown);
    m_omniboxSep->setObjectName(QStringLiteral("omniboxSep"));
    m_omniboxSep->setFrameShape(QFrame::NoFrame);
    m_omniboxSep->setFixedHeight(1);
    m_omniboxSep->setStyleSheet(QStringLiteral("background: #f1f3f4; border: none;"));
    m_omniboxSep->hide();
    dv->addWidget(m_omniboxSep);

    m_urlSuggestList = new QListWidget(m_omniboxDropdown);
    m_urlSuggestList->setObjectName(QStringLiteral("urlSuggestList"));
    m_urlSuggestList->setFocusPolicy(Qt::NoFocus);
    m_urlSuggestList->setMouseTracking(true);
    m_urlSuggestList->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_urlSuggestList->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_urlSuggestList->setSelectionBehavior(QAbstractItemView::SelectRows);
    m_urlSuggestList->setSelectionMode(QAbstractItemView::SingleSelection);
    m_urlSuggestList->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    m_urlSuggestList->hide();
    dv->addWidget(m_urlSuggestList);

    connect(m_urlSuggestList, &QListWidget::itemClicked, this, [this](QListWidgetItem* item) {
        if (!item)
            return;
        applyUrlFromSuggest(item->data(Qt::UserRole).toString());
    });
    connect(m_urlSuggestList, &QListWidget::currentRowChanged, this, [this](int row) {
        Q_UNUSED(row);
        refreshUrlSuggestSelectionVisual();
        if (!m_urlSuggestList)
            return;
        const int cr = m_urlSuggestList->currentRow();
        if (cr >= 0) {
            if (QListWidgetItem* it = m_urlSuggestList->item(cr))
                m_urlSuggestList->scrollToItem(it, QAbstractItemView::PositionAtCenter);
        }
    });
}

void Widget::hideUrlSuggestPopup()
{
    if (m_urlSuggestList)
        m_urlSuggestList->hide();
    if (m_omniboxSep)
        m_omniboxSep->hide();
    if (m_omniboxDropdown)
        m_omniboxDropdown->hide();
    setOmniboxOpen(false);
}

static QPixmap chromeTintedPixmap(const QPixmap& src, const QColor& tint)
{
    QImage img = src.toImage().convertToFormat(QImage::Format_ARGB32);
    for (int y = 0; y < img.height(); ++y) {
        for (int x = 0; x < img.width(); ++x) {
            const QRgb px = img.pixel(x, y);
            const int a = qAlpha(px);
            if (a == 0)
                continue;
            img.setPixel(x, y, qRgba(tint.red(), tint.green(), tint.blue(), a));
        }
    }
    return QPixmap::fromImage(img);
}

static QString hostLabelForUrl(const QString& urlStr)
{
    const QUrl u(urlStr);
    const QString host = u.host();
    if (!host.isEmpty())
        return host;
    return urlStr;
}

/** 地址栏输入转 URL：未写协议时默认 https；显式 http:// 或 https:// 则保留 */
static QUrl urlFromAddressBarText(const QString& text)
{
    const QString t = text.trimmed();
    if (t.isEmpty())
        return QUrl();
    if (t.startsWith(QStringLiteral("http://"), Qt::CaseInsensitive)
        || t.startsWith(QStringLiteral("https://"), Qt::CaseInsensitive)) {
        return QUrl::fromUserInput(t);
    }
    return QUrl(QStringLiteral("https://") + t);
}

/** 联想列表去重：同 host+path+query 视为同一条（忽略 http/https 差异，保留最新协议） */
static QString urlLocationDedupKey(const QString& urlStr)
{
    QUrl u = QUrl::fromUserInput(urlStr);
    if (!u.isValid() || u.host().isEmpty())
        return urlStr.trimmed().toLower();
    QString path = u.path();
    if (path.endsWith(QLatin1Char('/')) && path.length() > 1)
        path.chop(1);
    return u.host().toLower() + QLatin1Char('|') + path.toLower() + QLatin1Char('|') + u.query().toLower();
}

AddressInputHistoryStore* AddressInputHistoryStore::s_instance = nullptr;

AddressInputHistoryStore::AddressInputHistoryStore(QObject* parent)
    : QObject(parent)
{
    loadFromDisk();
}

AddressInputHistoryStore* AddressInputHistoryStore::instance()
{
    if (!s_instance)
        s_instance = new AddressInputHistoryStore(qApp);
    return s_instance;
}

void AddressInputHistoryStore::loadFromDisk()
{
    m_entries.clear();
    QFile f(addressInputHistoryFilePath());
    if (!f.open(QIODevice::ReadOnly))
        return;
    const QByteArray data = f.readAll();
    f.close();
    QJsonParseError err;
    const QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if (err.error != QJsonParseError::NoError || !doc.isArray())
        return;
    const QJsonArray arr = doc.array();
    for (const QJsonValue& v : arr) {
        if (!v.isObject())
            continue;
        const QJsonObject o = v.toObject();
        AddressInputEntry e;
        e.url = o.value(QStringLiteral("url")).toString().trimmed();
        if (e.url.isEmpty())
            continue;
        m_entries.append(e);
    }
}

void AddressInputHistoryStore::saveToDisk() const
{
    QJsonArray arr;
    for (const AddressInputEntry& e : m_entries) {
        QJsonObject o;
        o.insert(QStringLiteral("url"), e.url);
        arr.append(o);
    }
    const QString path = addressInputHistoryFilePath();
    QDir().mkpath(QFileInfo(path).absolutePath());
    QFile f(path);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return;
    f.write(QJsonDocument(arr).toJson(QJsonDocument::Compact));
    f.close();
}

void AddressInputHistoryStore::recordInput(const QString& rawUrl)
{
    QString u = rawUrl.trimmed();
    if (u.isEmpty())
        return;
    QUrl qu(u);
    if (qu.scheme().isEmpty())
        qu = urlFromAddressBarText(u);
    if (!qu.isValid())
        return;
    const QString scheme = qu.scheme().toLower();
    if (scheme != QStringLiteral("http") && scheme != QStringLiteral("https"))
        return;
    u = qu.toString(QUrl::RemovePassword);
    const QString locKey = urlLocationDedupKey(u);
    for (int i = m_entries.size() - 1; i >= 0; --i) {
        if (urlLocationDedupKey(m_entries[i].url) == locKey)
            m_entries.removeAt(i);
    }
    AddressInputEntry e;
    e.url = u;
    m_entries.prepend(e);
    const int kMax = 500;
    if (m_entries.size() > kMax)
        m_entries.resize(kMax);
    saveToDisk();
}

void AddressInputHistoryStore::clear()
{
    m_entries.clear();
    saveToDisk();
}

QVector<QPair<int, AddressInputEntry>> AddressInputHistoryStore::entriesFilteredWithIndex(const QString& searchText) const
{
    const QString needle = searchText.trimmed().toLower();
    QVector<QPair<int, AddressInputEntry>> out;
    for (int i = 0; i < m_entries.size(); ++i) {
        const AddressInputEntry& e = m_entries.at(i);
        if (needle.isEmpty()) {
            out.append(qMakePair(i, e));
            continue;
        }
        if (e.url.toLower().contains(needle))
            out.append(qMakePair(i, e));
    }
    return out;
}

void Widget::updateUrlSuggestPopup(const QString& text)
{
    if (!m_omniboxFrame || !m_omniboxDropdown || !m_urlSuggestList)
        return;
    const QString q = text.trimmed();
    if (q.isEmpty()) {
        hideUrlSuggestPopup();
        return;
    }
    const QVector<QPair<int, AddressInputEntry>> filtered = AddressInputHistoryStore::instance()->entriesFilteredWithIndex(q);
    if (filtered.isEmpty()) {
        hideUrlSuggestPopup();
        return;
    }
    QVector<QPair<int, AddressInputEntry>> unique;
    unique.reserve(qMin(filtered.size(), 5));
    QSet<QString> seenKeys;
    const int maxRows = 5;
    for (const QPair<int, AddressInputEntry>& p : filtered) {
        const QString key = urlLocationDedupKey(p.second.url);
        if (seenKeys.contains(key))
            continue;
        seenKeys.insert(key);
        unique.append(p);
        if (unique.size() >= maxRows)
            break;
    }
    if (unique.isEmpty()) {
        hideUrlSuggestPopup();
        return;
    }
    m_urlSuggestList->clear();
    const int n = unique.size();
    for (int i = 0; i < n; ++i) {
        const AddressInputEntry& e = unique[i].second;
        auto* item = new QListWidgetItem();
        item->setData(Qt::UserRole, e.url);
        item->setSizeHint(QSize(0, 44));
        m_urlSuggestList->addItem(item);
        QWidget* row = new QWidget(m_urlSuggestList);
        row->setStyleSheet(QStringLiteral("background: transparent;"));
        auto* hlay = new QHBoxLayout(row);
        hlay->setContentsMargins(14, 0, 16, 0);
        hlay->setSpacing(10);
        auto* iconLbl = new QLabel(row);
        iconLbl->setFixedSize(15, 15);
        iconLbl->setPixmap(buildClockIcon(15, QColor(0x83, 0x8a, 0x92)));
        const QString title = e.url;
        auto* titleLbl = new QLabel(title, row);
        titleLbl->setStyleSheet(QStringLiteral("background: transparent; color: rgba(0,0,0,0.88); font-family: 'PingFang SC','Microsoft YaHei'; font-size: 15px; font-weight: 400;"));
        titleLbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        titleLbl->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
        auto* hostLbl = new QLabel(hostLabelForUrl(e.url), row);
        hostLbl->setStyleSheet(QStringLiteral("background: transparent; color: rgba(0,0,0,0.45); font-family: 'PingFang SC','Microsoft YaHei'; font-size: 15px; font-weight: 400;"));
        hostLbl->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
        hostLbl->setMinimumWidth(180);
        hlay->addWidget(iconLbl, 0, Qt::AlignVCenter);
        hlay->addWidget(titleLbl, 1);
        hlay->addWidget(hostLbl, 0, Qt::AlignVCenter);
        m_urlSuggestList->setItemWidget(item, row);
    }
    m_urlSuggestList->setCurrentRow(-1);
    refreshUrlSuggestSelectionVisual();
    /* 固定列表高度并增加余量，避免最后一行在不同 DPI/字体下被裁掉 */
    const int rowH = qMax(44, m_urlSuggestList->sizeHintForRow(0));
    const int listH = qMin(420, n * rowH + 12);
    m_urlSuggestList->setMinimumHeight(listH);
    m_urlSuggestList->setMaximumHeight(listH);
    m_urlSuggestList->show();
    if (m_omniboxSep)
        m_omniboxSep->show();
    const int dropdownH = listH + (m_omniboxSep ? m_omniboxSep->height() : 0);
    m_omniboxDropdown->setMinimumHeight(dropdownH);
    m_omniboxDropdown->setMaximumHeight(dropdownH);
    setOmniboxOpen(true);
    polishOmniboxChromeFrameFocus(ui->editUrl->hasFocus());
    m_omniboxDropdown->show();
    repositionOmniboxDropdown();
    QTimer::singleShot(0, this, [this]() {
        repositionOmniboxDropdown();
    });
}

void Widget::applyUrlFromSuggest(const QString& url)
{
    if (url.isEmpty())
        return;
    hideUrlSuggestPopup();
    QSignalBlocker b(ui->editUrl);
    setAddressBarUrlDisplay(ui->editUrl, url);
    AddressInputHistoryStore::instance()->recordInput(url);
    if (!currentWebWidget()) {
        WebWidget* web = createTab(url, true, false);
        setAddressBarUrlDisplay(ui->editUrl, url);
        if (web)
            web->setFocus();
        return;
    }
    WebWidget* web = currentWebWidget();
    if (!web)
        return;
    if (navigateViaReplacementTabIfNeeded(web, url))
        return;
    web->loadUrl(url);
    web->setFocus();
}

bool Widget::navigateViaReplacementTabIfNeeded(WebWidget* current, const QString& targetUrl)
{
    if (!current || targetUrl.trimmed().isEmpty() || !ui || !ui->tabBar || !ui->stackedWidget)
        return false;
    const QString cur = current->currentUrl().trimmed();
    const bool blankLike = cur.isEmpty() || cur.compare(QStringLiteral("about:blank"), Qt::CaseInsensitive) == 0;
    if (!blankLike || ui->tabBar->count() <= 1)
        return false;
    const int oldIndex = ui->stackedWidget->indexOf(current);
    WebWidget* newWeb = createTab(targetUrl, true, false);
    if (!newWeb || oldIndex < 0)
        return false;
    ui->stackedWidget->removeWidget(current);
    ui->tabBar->removeTab(oldIndex);
    current->deleteLater();
    setAddressBarUrlDisplay(ui->editUrl, targetUrl);
    newWeb->setFocus();
    QTimer::singleShot(0, this, [this]() { stabilizeTabBarLayout(); });
    return true;
}

void Widget::refreshUrlSuggestSelectionVisual()
{
    if (!m_urlSuggestList)
        return;
    const int current = m_urlSuggestList->currentRow();
    for (int i = 0; i < m_urlSuggestList->count(); ++i) {
        QListWidgetItem* it = m_urlSuggestList->item(i);
        QWidget* row = m_urlSuggestList->itemWidget(it);
        if (!it || !row)
            continue;
        const bool selected = (i == current);
        row->setStyleSheet(selected
            ? QStringLiteral("background: #eef3ff; border-radius: 6px;")
            : QStringLiteral("background: transparent;"));
    }
}

bool Widget::eventFilter(QObject* watched, QEvent* event)
{
    if (!event)
        return QWidget::eventFilter(watched, event);

    if ((watched == m_downloadTabList || (m_downloadTabList && watched == m_downloadTabList->viewport()))
        && event->type() == QEvent::Resize) {
        if (!m_downloadTabListRebuilding && m_downloadTabList->viewport()) {
            const int viewportW = m_downloadTabList->viewport()->width();
            if (viewportW > 0 && viewportW != m_lastDownloadTabViewportWidth) {
                m_lastDownloadTabViewportWidth = viewportW;
                if (!m_downloadTabResizeRebuildPending) {
                    m_downloadTabResizeRebuildPending = true;
                    QTimer::singleShot(0, this, [this]() {
                        m_downloadTabResizeRebuildPending = false;
                        requestDownloadTabRebuild(false);
                    });
                }
            }
        }
    }
    if (m_downloadTabList && event->type() == QEvent::Enter) {
        QWidget* w = qobject_cast<QWidget*>(watched);
        if (w && w->property("downloadSavePath").isValid()) {
            w->setProperty("hovered", true);
            w->style()->unpolish(w);
            w->style()->polish(w);
        }
    } else if (m_downloadTabList && event->type() == QEvent::Leave) {
        QWidget* w = qobject_cast<QWidget*>(watched);
        if (w && w->property("downloadSavePath").isValid()) {
            const QPoint p = w->mapFromGlobal(QCursor::pos());
            const bool stillInside = w->rect().contains(p);
            w->setProperty("hovered", stillInside);
            w->style()->unpolish(w);
            w->style()->polish(w);
        }
    }

    /* ---------- 无边框窗口：顶栏拖动容器的整窗（子控件会吃掉 WebTabBar::mouseMove）---------- */
    switch (event->type()) {
    case QEvent::MouseButtonPress: {
        auto* me = static_cast<QMouseEvent*>(event);
        if (me->button() == Qt::LeftButton) {
#ifndef Q_OS_WIN
            if (!isWindowMaximizedCompat() && !isFullScreen()) {
                const int edges = hitWindowResizeEdges(me->globalPos());
                if (edges) {
#if QT_VERSION >= QT_VERSION_CHECK(5, 15, 0)
                    if (QWindow* wh = windowHandle()) {
                        Qt::Edges qtEdges;
                        if (edges & kEdgeLeft)
                            qtEdges |= Qt::LeftEdge;
                        if (edges & kEdgeRight)
                            qtEdges |= Qt::RightEdge;
                        if (edges & kEdgeTop)
                            qtEdges |= Qt::TopEdge;
                        if (edges & kEdgeBottom)
                            qtEdges |= Qt::BottomEdge;
                        if (qtEdges != Qt::Edges() && wh->startSystemResize(qtEdges))
                            return true;
                    }
#endif
                    m_windowEdgeResizing = true;
                    m_windowResizeEdges = edges;
                    m_windowResizePressGlobal = me->globalPos();
                    m_windowResizeStartGeometry = geometry();
                    clearWindowResizeCursor();
                    grabMouse();
                    return true;
                }
            }
#endif
            if (isChromeWindowDragGrip(me->globalPos())) {
                m_appChromeDragArmed = true;
                m_appChromeDragPressGlobal = me->globalPos();
                m_appChromeDragging = false;
            } else if (!m_appChromeDragging) {
                m_appChromeDragArmed = false;
            }
        }
        break;
    }
    case QEvent::MouseMove: {
        auto* me = static_cast<QMouseEvent*>(event);
#ifndef Q_OS_WIN
        if (!isWindowMaximizedCompat() && !isFullScreen()) {
            if (m_windowEdgeResizing && (me->buttons() & Qt::LeftButton)) {
                applyWindowEdgeResize(me->globalPos());
                return true;
            }
            if (isVisible() && frameGeometry().contains(me->globalPos()))
                updateWindowResizeCursor(me->globalPos());
            else
                clearWindowResizeCursor();
        }
#endif
        if (m_appChromeDragging && (me->buttons() & Qt::LeftButton)) {
            move(me->globalPos() - m_appChromeDragOffset);
            return false;
        }
        if (m_appChromeDragArmed && (me->buttons() & Qt::LeftButton)) {
            const int dist = (me->globalPos() - m_appChromeDragPressGlobal).manhattanLength();
            if (dist >= QApplication::startDragDistance()) {
                m_appChromeDragging = true;
                if (isWindowMaximizedCompat()) {
                    const QPoint g = me->globalPos();
                    const QPoint rel = g - frameGeometry().topLeft();
                    restoreWindowCompat();
                    move(g - rel);
                }
                m_appChromeDragOffset = me->globalPos() - frameGeometry().topLeft();
                grabMouse();
                move(me->globalPos() - m_appChromeDragOffset);
            }
        }
        break;
    }
    case QEvent::MouseButtonRelease: {
        auto* me = static_cast<QMouseEvent*>(event);
        if (me->button() == Qt::LeftButton) {
#ifndef Q_OS_WIN
            if (m_windowEdgeResizing) {
                m_windowEdgeResizing = false;
                releaseMouse();
                clearWindowResizeCursor();
                relayoutTopTabBar(tabBarLayoutOuterWidth());
                QTimer::singleShot(0, this, [this]() { stabilizeTabBarLayout(); });
                return true;
            }
#endif
            if (auto* tb = qobject_cast<WebTabBar*>(ui->tabBar)) {
                if (tb->isWindowTabDragging() || tb->isWindowTabDragArmed())
                    tb->cancelWindowTabDrag();
            }
            if (m_appChromeDragging || m_appChromeDragArmed) {
                if (m_appChromeDragging)
                    releaseMouse();
                m_appChromeDragging = false;
                m_appChromeDragArmed = false;
            }
        }
        break;
    }
    default:
        break;
    }

    if (event->type() == QEvent::MouseButtonDblClick) {
        auto* me = static_cast<QMouseEvent*>(event);
        if (me->button() == Qt::LeftButton && isChromeDoubleClickToggleMax(me->globalPos())) {
            toggleWindowMaximizeCompat();
            return true;
        }
    }

    if (watched == m_downloadPanel.data() && event->type() == QEvent::Hide)
        resetDownloadsNavButtonHoverState();

    if (watched) {
        QWidget* w = qobject_cast<QWidget*>(watched);
        if (w && w->objectName() == QStringLiteral("downloadRow")) {
            if (event->type() == QEvent::Enter || event->type() == QEvent::Leave) {
                bool hovered = (event->type() == QEvent::Enter);
                if (!hovered && w->rect().contains(w->mapFromGlobal(QCursor::pos())))
                    hovered = true;
                w->setProperty("hovered", hovered);
                w->style()->unpolish(w);
                w->style()->polish(w);
                const QString savePath = w->property("downloadSavePath").toString();
                const DownloadRecord rec = m_downloadRecords.value(savePath);
                const bool showActions = hovered && rec.finished;
                if (auto* btn = w->findChild<QToolButton*>(QStringLiteral("downloadCopyLink")))
                    btn->setVisible(showActions);
                if (auto* btn = w->findChild<QToolButton*>(QStringLiteral("downloadDeleteRecord")))
                    btn->setVisible(showActions);
            }
        }
    }
    if (watched == ui->editUrl) {
        if (event->type() == QEvent::FocusIn) {
            polishOmniboxChromeFrameFocus(true);
        } else if (event->type() == QEvent::FocusOut) {
            /* 延后处理，避免点击联想行时先失焦导致列表被提前收起 */
            QTimer::singleShot(0, this, [this]() {
                if (!ui->editUrl->hasFocus()) {
                    hideUrlSuggestPopup();
                    polishOmniboxChromeFrameFocus(false);
                }
            });
        }
        if (event->type() == QEvent::KeyPress) {
            auto* ke = static_cast<QKeyEvent*>(event);
            if ((ke->modifiers() & Qt::ControlModifier) && !(ke->modifiers() & Qt::AltModifier)) {
                if (ke->key() == Qt::Key_C && !ui->editUrl->selectedText().isEmpty()) {
                    WebWidget::copyTextToSystemClipboard(ui->editUrl->selectedText());
                    return true;
                }
                if (ke->key() == Qt::Key_V) {
                    WebWidget::pasteTextToLineEdit(ui->editUrl);
                    return true;
                }
            }
            if (m_urlSuggestList && m_urlSuggestList->isVisible() && m_urlSuggestList->count() > 0) {
                if (ke->key() == Qt::Key_Down) {
                    int r = m_urlSuggestList->currentRow();
                    if (r < 0)
                        m_urlSuggestList->setCurrentRow(0);
                    else
                        m_urlSuggestList->setCurrentRow(qMin(r + 1, m_urlSuggestList->count() - 1));
                    refreshUrlSuggestSelectionVisual();
                    if (QListWidgetItem* it = m_urlSuggestList->item(m_urlSuggestList->currentRow()))
                        m_urlSuggestList->scrollToItem(it, QAbstractItemView::PositionAtCenter);
                    return true;
                }
                if (ke->key() == Qt::Key_Up) {
                    int r = m_urlSuggestList->currentRow();
                    if (r <= 0)
                        m_urlSuggestList->setCurrentRow(-1);
                    else
                        m_urlSuggestList->setCurrentRow(r - 1);
                    refreshUrlSuggestSelectionVisual();
                    if (m_urlSuggestList->currentRow() >= 0) {
                        if (QListWidgetItem* it = m_urlSuggestList->item(m_urlSuggestList->currentRow()))
                            m_urlSuggestList->scrollToItem(it, QAbstractItemView::PositionAtCenter);
                    }
                    return true;
                }
                if (ke->key() == Qt::Key_Return || ke->key() == Qt::Key_Enter) {
                    const int r = m_urlSuggestList->currentRow();
                    if (r >= 0) {
                        QListWidgetItem* it = m_urlSuggestList->item(r);
                        if (it) {
                            applyUrlFromSuggest(it->data(Qt::UserRole).toString());
                            return true;
                        }
                    }
                }
                if (ke->key() == Qt::Key_Escape) {
                    hideUrlSuggestPopup();
                    return true;
                }
            }
        }
    }
    return QWidget::eventFilter(watched, event);
}

#if defined(Q_OS_WIN)
#  if QT_VERSION >= QT_VERSION_CHECK(6, 0, 0)
bool Widget::nativeEvent(const QByteArray& eventType, void* message, qintptr* result)
#  else
bool Widget::nativeEvent(const QByteArray& eventType, void* message, long* result)
#  endif
{
    if (eventType == "windows_generic_MSG") {
        auto* msg = static_cast<MSG*>(message);

        /* 非最大化：拖动过程中窗体上沿贴近工作区顶部 → 最大化（GetAsyncKeyState 在系统拖动时仍有效） */
        if (msg->message == WM_MOVING && !isMaximized() && !isFullScreen()) {
            if (GetAsyncKeyState(VK_LBUTTON) & 0x8000) {
                auto* pr = reinterpret_cast<RECT*>(msg->lParam);
                HMONITOR hm = MonitorFromRect(pr, MONITOR_DEFAULTTONEAREST);
                MONITORINFO mi;
                mi.cbSize = sizeof(MONITORINFO);
                if (GetMonitorInfoW(hm, &mi)) {
                    if (pr->top <= mi.rcWork.top + 12)
                        showMaximized();
                }
            }
        }

        /* 非客户区双击：与 eventFilter 使用同一命中规则，避免在标签上误触最大化/还原 */
        if (msg->message == WM_NCLBUTTONDBLCLK && msg->wParam == HTCAPTION) {
            const int x = GET_X_LPARAM(msg->lParam);
            const int y = GET_Y_LPARAM(msg->lParam);
            const QPoint g(x, y);
            if (isChromeDoubleClickToggleMax(g)) {
                if (isMaximized())
                    restoreWindowCompat();
                else
                    maximizeWindowCompat();
                *result = 0;
                return true;
            }
            return QWidget::nativeEvent(eventType, message, result);
        }

        /* 客户区双击由 qApp eventFilter（MouseButtonDblClick）统一处理 */

        if (msg->message == WM_NCHITTEST) {
            const int x = GET_X_LPARAM(msg->lParam);
            const int y = GET_Y_LPARAM(msg->lParam);

            /* 非最大化：允许边框/四角拖拽缩放（无边框窗口需手动返回命中） */
            if (!isMaximized() && !isFullScreen()) {
                const int resizeBorder = 14;
                HWND hwnd = reinterpret_cast<HWND>(winId());
                RECT wr = {0, 0, 0, 0};
                if (hwnd && GetWindowRect(hwnd, &wr)) {
                    const bool onLeft = (x >= wr.left && x < wr.left + resizeBorder);
                    const bool onRight = (x < wr.right && x >= wr.right - resizeBorder);
                    const bool onTop = (y >= wr.top && y < wr.top + resizeBorder);
                    const bool onBottom = (y < wr.bottom && y >= wr.bottom - resizeBorder);

                    if (onTop && onLeft) {
                        *result = HTTOPLEFT;
                        return true;
                    }
                    if (onTop && onRight) {
                        *result = HTTOPRIGHT;
                        return true;
                    }
                    if (onBottom && onLeft) {
                        *result = HTBOTTOMLEFT;
                        return true;
                    }
                    if (onBottom && onRight) {
                        *result = HTBOTTOMRIGHT;
                        return true;
                    }
                    if (onLeft) {
                        *result = HTLEFT;
                        return true;
                    }
                    if (onRight) {
                        *result = HTRIGHT;
                        return true;
                    }
                    if (onTop) {
                        *result = HTTOP;
                        return true;
                    }
                    if (onBottom) {
                        *result = HTBOTTOM;
                        return true;
                    }
                }
            }

            const QPoint lp = mapFromGlobal(QPoint(x, y));
            if (!rect().contains(lp))
                return QWidget::nativeEvent(eventType, message, result);

            /* 整块顶栏（标签区 + 留白）可拖动，但标签页、新建、三键区保持子控件命中 */
            if (ui->topTabBar && ui->tabBar && ui->topTabBar->geometry().contains(lp)) {
                const QPoint tbp = ui->topTabBar->mapFrom(this, lp);
                QWidget* ch = ui->topTabBar->childAt(tbp);
                if (!ch) {
                    *result = HTCAPTION;
                    return true;
                }
                if (ch == ui->btnNewTab || ch == ui->btnWindowMinimize
                    || ch == ui->btnWindowMaximize || ch == ui->btnWindowClose) {
                    *result = HTCLIENT;
                    return true;
                }
                /* 先按实际子控件命中：关闭按钮/右侧条带落在 tabRect 外时，仍应视为 HTCLIENT */
                if (ui->tabBar->geometry().contains(lp)) {
                    const QPoint tp = ui->tabBar->mapFrom(this, lp);
                    QWidget* tabHit = ui->tabBar->childAt(tp);
                    if (tabHit) {
                        *result = HTCLIENT;
                        return true;
                    }
                    for (int ti = 0; ti < ui->tabBar->count(); ++ti) {
                        if (ui->tabBar->tabRect(ti).contains(tp)) {
                            *result = HTCLIENT;
                            return true;
                        }
                    }
                    *result = HTCAPTION;
                    return true;
                }
            }
            if (ui->navBar && ui->navBar->geometry().contains(lp)) {
                const QPoint nlp = ui->navBar->mapFrom(this, lp);
                if (!ui->navBar->childAt(nlp)) {
                    *result = HTCAPTION;
                    return true;
                }
            }
        }
    }
    return QWidget::nativeEvent(eventType, message, result);
}
#endif

void Widget::navigateToInput()
{
    hideUrlSuggestPopup();
    QString text = ui->editUrl->text().trimmed();
    if (text.isEmpty())
        return;

    // 未写 scheme 时默认 https；显式 http:// 则保留 http
    QUrl url = urlFromAddressBarText(text);
    if (!url.isValid())
        return;
    QString finalUrl = url.toString(QUrl::RemovePassword);
    qWarning().noquote() << "[LiteView][nav-trace] navigate input=" << text
                         << " normalized=" << finalUrl;

    if (!currentWebWidget()) {
        WebWidget* web = createTab(finalUrl, true, false);
        setAddressBarUrlDisplay(ui->editUrl, finalUrl);
        if (web)
            web->setFocus();
        return;
    }
    WebWidget* web = currentWebWidget();
    if (!web)
        return;
    if (navigateViaReplacementTabIfNeeded(web, finalUrl))
        return;
    web->loadUrl(finalUrl);
    web->setFocus();
    setAddressBarUrlDisplay(ui->editUrl, finalUrl);
}

void Widget::goHome()
{
    WebWidget* web = currentWebWidget();
    if (!web)
        return;

    QSettings s(QSettings::IniFormat, QSettings::UserScope,
        QStringLiteral("LiteView"), QStringLiteral("LiteViewBrowser"));
    const int mode = s.value(QStringLiteral("startup/mode"), 0).toInt();
    if (mode == 0) {
        web->loadBlankHome();
        ui->editUrl->clear();
        QTimer::singleShot(0, this, [this]() {
            ui->editUrl->setFocus();
        });
        return;
    }
    const QString raw = s.value(QStringLiteral("startup/specificUrl"), QString()).toString().trimmed();
    if (raw.isEmpty()) {
        web->loadBlankHome();
        ui->editUrl->clear();
        QTimer::singleShot(0, this, [this]() {
            ui->editUrl->setFocus();
        });
        return;
    }
    const QUrl u = QUrl::fromUserInput(raw);
    if (!u.isValid() || u.toString().trimmed().isEmpty()) {
        web->loadBlankHome();
        ui->editUrl->clear();
        QTimer::singleShot(0, this, [this]() {
            ui->editUrl->setFocus();
        });
        return;
    }
    const QString dest = u.toString();
    web->loadUrl(dest);
    web->setFocus();
    setAddressBarUrlDisplay(ui->editUrl, dest);
}

WebWidget* Widget::currentWebWidget() const
{
    if (!ui || !ui->stackedWidget)
        return nullptr;
    return qobject_cast<WebWidget*>(ui->stackedWidget->currentWidget());
}

/** 与可执行文件同目录下的 LocalStorage，删除其中所有 .localsto（Windows/Linux 路径规则一致）。 */
static void removeAllLocalstoFilesInAppLocalStorageDir()
{
    const QString dirPath = QDir(QCoreApplication::applicationDirPath()).filePath(QStringLiteral("LocalStorage"));
    QDir dir(dirPath);
    if (!dir.exists())
        return;
    const QStringList names = dir.entryList(QStringList() << QStringLiteral("*.localsto"),
        QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    for (const QString& name : names)
        QFile::remove(dir.filePath(name));
}

void Widget::clearMiniBlinkStorageOnAllWebTabs(int isLocal)
{
    if (isLocal == 2) {
        removeAllLocalstoFilesInAppLocalStorageDir();
        FaviconCache::clearAllCachedIcons();
        m_tabSiteIconByWeb.clear();
        if (ui && ui->stackedWidget && ui->tabBar) {
            const QIcon fb = tabSiteFaviconFallbackIcon();
            for (int i = 0; i < ui->stackedWidget->count(); ++i) {
                auto* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i));
                if (!web || webWidgetIsOnlyNewTabPlaceholder(web))
                    continue;
                if (!fb.isNull())
                    ui->tabBar->setTabIcon(i, fb);
                else
                    ui->tabBar->setTabIcon(i, QIcon());
            }
        }
    }

    if (!ui || !ui->stackedWidget || !mbClearStorage)
        return;
    for (int i = 0; i < ui->stackedWidget->count(); ++i) {
        auto* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i));
        if (!web || web->m_webView == NULL_WEBVIEW)
            continue;
        mbClearStorage(web->m_webView, isLocal);
    }
}

void Widget::clearMiniBlinkCookiesOnAllWebTabs()
{
    if (!ui || !ui->stackedWidget || !mbClearCookie)
        return;
    for (int i = 0; i < ui->stackedWidget->count(); ++i) {
        auto* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i));
        if (!web || web->m_webView == NULL_WEBVIEW)
            continue;
        mbClearCookie(web->m_webView);
    }
}

void Widget::applyTabTitleForWeb(WebWidget* web, const QString& title)
{
    if (!web)
        return;
    const int tabIndex = ui->stackedWidget->indexOf(web);
    if (tabIndex < 0)
        return;
    const int rightReserve = tabRightControlReservePx(ui->tabBar, tabIndex);
    const QString& kNewTabTitle = tabBarNewTabPageTitle();
    static const QIcon kNewTabLabelIcon = loadImageFromImagesDir({QStringLiteral("label")});
    const QString fullTitle = title.isEmpty() ? kNewTabTitle : title;
    if (!kNewTabLabelIcon.isNull()) {
        if (fullTitle == kNewTabTitle) {
            ui->tabBar->setTabIcon(tabIndex, kNewTabLabelIcon);
        } else if (ui->tabBar->tabIcon(tabIndex).cacheKey() == kNewTabLabelIcon.cacheKey()) {
            /* 离开“新标签页”语义后去掉占位 icon，避免覆盖后续 favicon。 */
            ui->tabBar->setTabIcon(tabIndex, QIcon());
        }
    }
    QFontMetrics fm(ui->tabBar->font());
    if (ui->tabBar->count() <= 1) {
        /* 完整标题在 ToolTip；展示用标题在 tabData（中文≤10 字 / 拉丁路径≤15 字符）；标签由 WebTabBar 自绘 */
        Q_UNUSED(rightReserve);
        Q_UNUSED(fm);
        const QString displayTitle = truncateTabTitleForSingleTab(fullTitle);
        ui->tabBar->setTabToolTip(tabIndex, fullTitle);
        ui->tabBar->setTabData(tabIndex, QVariant(displayTitle));
        /* 勿写入 tabText：否则样式仍会画字，与 paintEvent 自绘重叠 */
        ui->tabBar->setTabText(tabIndex, QString());
        ui->tabBar->update();
        if (fullTitle != kNewTabTitle)
            ensureTabSiteIconOrFallback(ui->tabBar, tabIndex, web);
        return;
    }
    /* 多标签：同样只写 tabData + 空 tabText，省略宽度与 titleDrawingRect 一致 */
    const int kNormalTabWidth = kSingleTabBarWidthPx;
    int titlePixelBudget = qMax(28, kNormalTabWidth - rightReserve - 12);
    const QRect tr = ui->tabBar->tabRect(tabIndex);
    if (tr.isValid() && tr.width() > 12 && tr.width() < kNormalTabWidth - 2)
        titlePixelBudget = qMax(28, tr.width() - rightReserve);
    const QRect tdr = ui->tabBar->titleDrawingRect(tabIndex);
    if (tdr.isValid() && tdr.width() > 2)
        titlePixelBudget = tdr.width();
    const QString elided = fm.elidedText(fullTitle, Qt::ElideRight, titlePixelBudget);
    ui->tabBar->setTabToolTip(tabIndex, fullTitle);
    ui->tabBar->setTabData(tabIndex, QVariant(elided));
    ui->tabBar->setTabText(tabIndex, QString());
    ui->tabBar->update();
    if (fullTitle != kNewTabTitle)
        ensureTabSiteIconOrFallback(ui->tabBar, tabIndex, web);
}

void Widget::updateTabMuteIndicator(WebWidget* web)
{
    if (!web)
        return;
    const int tabIndex = ui->stackedWidget->indexOf(web);
    if (tabIndex < 0)
        return;
    QWidget* strip = ui->tabBar->tabButton(tabIndex, QTabBar::RightSide);
    if (!strip)
        return;
    QLabel* mute = strip->findChild<QLabel*>(QStringLiteral("tabMuteIcon"));
    if (!mute)
        return;
    mute->setPixmap(web->isAudioMuted() ? buildBlackMuteTabPixmap() : QPixmap());
    mute->setVisible(web->isAudioMuted());
    adjustWebTabRightStripSize(strip);
    mute->update();
    strip->updateGeometry();
    const QString tip = ui->tabBar->tabToolTip(tabIndex);
    applyTabTitleForWeb(web, tip.isEmpty() ? web->title() : tip);
}

void Widget::refreshTabBarTitlesForLayout()
{
    const auto* wtb = qobject_cast<const WebTabBar*>(ui->tabBar);
    const int hovered = wtb ? wtb->hoveredTabIndex() : -1;
    for (int i = 0; i < ui->tabBar->count(); ++i) {
        if (QWidget* strip = ui->tabBar->tabButton(i, QTabBar::RightSide)) {
            strip->setVisible(shouldShowTabCloseButton(ui->tabBar, i, hovered));
        }
        QWidget* page = ui->stackedWidget->widget(i);
        auto* web = qobject_cast<WebWidget*>(page);
        if (!web)
            continue;
        const QString tip = ui->tabBar->tabToolTip(i);
        applyTabTitleForWeb(web, tip.isEmpty() ? web->title() : tip);
    }
}

static bool isTabBarWindowDragActive(const Ui::Widget* ui)
{
    const auto* tb = qobject_cast<const WebTabBar*>(ui->tabBar);
    return tb && tb->isWindowTabDragging();
}

void Widget::stabilizeTabBarLayout()
{
    if (isTabBarWindowDragActive(ui))
        return;
    relayoutTopTabBar(tabBarLayoutOuterWidth());
    refreshTabBarTitlesForLayout();
    QTimer::singleShot(30, this, [this]() {
        if (isTabBarWindowDragActive(ui))
            return;
        relayoutTopTabBar(tabBarLayoutOuterWidth());
        refreshTabBarTitlesForLayout();
    });
}

int Widget::tabBarLayoutOuterWidth(int forcedOuterWidth) const
{
    int outerW = forcedOuterWidth >= 0 ? forcedOuterWidth : width();
    if (!isWindowMaximizedCompat() && !isFullScreen())
        outerW = qMin(outerW, kDefaultWindowWidthPx);
    return outerW;
}

int Widget::topTabStripAvailableForTabBar(int forcedOuterWidth) const
{
    if (!ui || !ui->topTabLayout || !ui->btnNewTab
        || !ui->btnWindowMinimize || !ui->btnWindowMaximize || !ui->btnWindowClose)
        return 0;
    int outerW = tabBarLayoutOuterWidth(forcedOuterWidth);
    if (ui->gridLayout) {
        const QMargins gm = ui->gridLayout->contentsMargins();
        outerW -= gm.left() + gm.right();
    }
    const QMargins m = ui->topTabLayout->contentsMargins();
    const int spacing = qMax(0, ui->topTabLayout->spacing());
    /* 与 initForm 中 setupWinFrameBtn 一致；布局未完成时 width() 常为 0，必须用下限否则标签栏会挤掉三键 */
    constexpr int kWinFrameBtnPx = 36;
    constexpr int kNewTabBtnPx = 36;
    constexpr int kTabToNewGapPx = 5;
    constexpr int kWinBtnGapPx = 5;
    auto chromeBtnW = [kWinFrameBtnPx](const QToolButton* b) {
        return b ? qMax(b->width(), kWinFrameBtnPx) : kWinFrameBtnPx;
    };
    const int newTabW = qMax(ui->btnNewTab->sizeHint().width(), kNewTabBtnPx);
    const int winChromeW = chromeBtnW(ui->btnWindowMinimize)
        + chromeBtnW(ui->btnWindowMaximize)
        + chromeBtnW(ui->btnWindowClose);
    const int rightChromeW = kTabToNewGapPx + newTabW + winChromeW + kWinBtnGapPx * 2;
    return qMax(0, outerW - m.left() - m.right() - rightChromeW - spacing);
}

void Widget::relayoutTopTabBar(int forcedOuterWidth)
{
    if (!ui->topTabBar || !ui->topTabLayout || !ui->tabBar || !ui->btnNewTab
        || !ui->btnWindowMinimize || !ui->btnWindowMaximize || !ui->btnWindowClose)
        return;
    const int tabCount = ui->tabBar->count();
    /* 单/多标签统一视觉：最大化直接用 9/11；窗口化扣除 3px 外边框补偿 */
    const int kWindowBorderPx = 3;
    const int kTopTabLeftPx = 12;
    const int kTopTabTopPx = 14;
    const bool mxNow = isWindowMaximizedCompat();
    const int appliedLeft = mxNow ? kTopTabLeftPx : qMax(0, kTopTabLeftPx - kWindowBorderPx);
    const int appliedTop = mxNow ? kTopTabTopPx : qMax(0, kTopTabTopPx - kWindowBorderPx);
    /* 0:tabBar 1:tab->+固定5px 2:+ 3:spacer(吃满中间空白，把窗口键顶到最右) 4:min 5:gap5 6:max 7:gap5 8:close */
    ui->topTabLayout->setStretch(0, 0);
    ui->topTabLayout->setStretch(1, 0);
    ui->topTabLayout->setStretch(2, 0);
    ui->topTabLayout->setStretch(3, 1);
    ui->topTabLayout->setStretch(4, 0);
    ui->topTabLayout->setStretch(5, 0);
    ui->topTabLayout->setStretch(6, 0);
    ui->topTabLayout->setStretch(7, 0);
    ui->topTabLayout->setStretch(8, 0);
    m_prevTabBarCount = tabCount;
    /* 多标签：顶栏 layout 额外左距，使首枚标签 pill 不贴窗体左缘（须在 available 计算前写入 margins） */
    constexpr int kMultiTabExtraLeftPx = 6;
    const int multiExtraLeft = tabCount > 1 ? kMultiTabExtraLeftPx : 0;
    ui->topTabLayout->setContentsMargins(appliedLeft + multiExtraLeft, appliedTop, 10, 0);
    ui->btnNewTab->show();
    ui->btnWindowMinimize->show();
    ui->btnWindowMaximize->show();
    ui->btnWindowClose->show();
    /* 必须用窗体宽度推算可用区，不能用 topTabBar->width()（会被 tabBar 的 N×270 sizeHint 撑大后反推窗体变宽） */
    const int available = topTabStripAvailableForTabBar(forcedOuterWidth);
    if (available <= 0) {
        ui->tabBar->setFixedWidth(0);
        ui->tabBar->setMaximumWidth(QWIDGETSIZE_MAX);
        return;
    }
    if (tabCount <= 1) {
        m_tabBarPinnedToAvailable = false;
        m_singleTabBarBaselineWidth = kSingleTabBarWidthPx;
        const int targetSingle = qMax(1, qMin(kSingleTabBarWidthPx, available));
        ui->tabBar->setFixedWidth(targetSingle);
        ui->tabBar->setMaximumWidth(targetSingle);
        if (auto* tb = qobject_cast<WebTabBar*>(ui->tabBar))
            tb->setTabLayoutWidthCap(targetSingle);
        ui->tabBar->setExpanding(true);
        syncWindowFrameButtons();
        return;
    }
    ui->tabBar->setExpanding(false);
    ui->tabBar->setMinimumWidth(0);
    const int naturalTabBarW = tabCount * kSingleTabBarWidthPx;
    const int targetMulti = qMax(1, qMin(naturalTabBarW, available));
    m_tabBarPinnedToAvailable = (naturalTabBarW >= available);
    ui->tabBar->setFixedWidth(targetMulti);
    ui->tabBar->setMaximumWidth(targetMulti);
    if (auto* tb = qobject_cast<WebTabBar*>(ui->tabBar))
        tb->setTabLayoutWidthCap(targetMulti);
    ui->tabBar->updateGeometry();
}

void Widget::setupWebWidget(WebWidget* web)
{
    web->setCreateNewTabHandler([this](const QString& popupUrl) -> mbWebView {
        if (QThread::currentThread() == qApp->thread())
            return createTabFromPopup(popupUrl);
        m_pendingCreateViewResult = NULL_WEBVIEW;
        QMetaObject::invokeMethod(
            this,
            "slotCreateTabForPopup",
            Qt::BlockingQueuedConnection,
            Q_ARG(QString, popupUrl));
        return m_pendingCreateViewResult;
    });
    connect(web, &WebWidget::closeTabRequested, this, [this, web]() {
        closeWebWidgetTab(web);
    });
}

void Widget::slotCreateTabForPopup(QString url)
{
    m_pendingCreateViewResult = createTabFromPopup(url);
}

mbWebView Widget::createTabFromPopup(const QString& url)
{
    WebWidget* opener = currentWebWidget();
    WebWidget* w = createTab(url, true, false);
    if (w)
        w->setAuthPopupTab(true, opener);
    return w ? w->m_webView : NULL_WEBVIEW;
}

WebWidget* Widget::createTab(const QString& url, bool makeCurrent, bool blankAddressBar)
{
    if (ui->tabBar && ui->tabBar->count() >= kMaxTabCount)
        return currentWebWidget();
    WebWidget* web = new WebWidget(url, ui->stackedWidget, blankAddressBar);
    setupWebWidget(web);
    web->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    const int index = ui->stackedWidget->addWidget(web);
    ui->tabBar->addTab(QString());
    applyTabTitleForWeb(web, QString());
    QToolButton* closeBtn = nullptr;
    QWidget* rightStrip = createWebTabRightStrip(ui->tabBar, &closeBtn);
    ui->tabBar->setTabButton(index, QTabBar::RightSide, rightStrip);
    connect(closeBtn, &QToolButton::clicked, this, [this, rightStrip]() {
        for (int i = 0; i < ui->tabBar->count(); ++i) {
            if (ui->tabBar->tabButton(i, QTabBar::RightSide) == rightStrip) {
                closeTab(i);
                break;
            }
        }
    });
    if (makeCurrent) {
        ui->tabBar->setCurrentIndex(index);
        ui->stackedWidget->setCurrentIndex(index);
        if (!blankAddressBar) {
            const QString intended = url.trimmed().isEmpty()
                ? QStringLiteral("about:blank") : url.trimmed();
            if (intended.compare(QStringLiteral("about:blank"), Qt::CaseInsensitive) != 0
                && web->currentUrl().trimmed().isEmpty()) {
                setAddressBarUrlDisplay(ui->editUrl, intended);
            }
        }
    }
    QTimer::singleShot(0, this, [this]() { stabilizeTabBarLayout(); });
    QTimer::singleShot(0, web, [web]() { web->syncViewport(); });
    QTimer::singleShot(50, web, [web]() { web->syncViewport(); });

    connect(web, &WebWidget::urlChanged, this, [this, web](const QString& currentUrl) {
        if (!ui)
            return;
        /* 导航后丢弃「加载前保存的标签图标」，否则 loadingChanged(true) 若先于 favicon 清空，
         * 会把上一站点（如 163）的 favicon 存进恢复表，加载结束又贴回当前页（如东财）标签。 */
        m_tabIconRestoreWhenLoading.remove(web);
        m_tabSiteIconByWeb.remove(web);
        if (web == currentWebWidget() && !ui->editUrl->hasFocus())
            setAddressBarUrlDisplay(ui->editUrl, currentUrl);
    });
    connect(web, &WebWidget::navigationStateChanged, this, [this, web](bool canGoBack, bool canGoForward) {
        if (!ui)
            return;
        if (web == currentWebWidget()) {
            ui->btnBack->setEnabled(canGoBack);
            ui->btnForward->setEnabled(canGoForward);
        }
    });
    connect(web, &WebWidget::loadingChanged, this, [this, web](bool loading) {
        if (!ui || !ui->stackedWidget || !ui->tabBar)
            return;
        if (web == currentWebWidget())
            setReloadButtonLoadingState(ui, loading);
        const int tabIndex = ui->stackedWidget->indexOf(web);
        if (loading) {
            if (tabIndex >= 0 && !m_tabIconRestoreWhenLoading.contains(web))
                m_tabIconRestoreWhenLoading.insert(web, ui->tabBar->tabIcon(tabIndex));
        } else {
            if (tabIndex >= 0)
                applyLoadedTabIconForWeb(web);
        }
        syncTabLoadingAnimationState();
    });
    connect(web, &WebWidget::titleChanged, this, [this, web](const QString& title) {
        if (!ui)
            return;
        applyTabTitleForWeb(web, title);
        if (ui->tabBar->count() > 1)
            QTimer::singleShot(0, this, [this]() { stabilizeTabBarLayout(); });

        if (web == currentWebWidget()) {
            if (!title.isEmpty())
                setWindowTitle(QStringLiteral("%1 - LiteView").arg(title));
            else
                setWindowTitle(QStringLiteral("LiteView Browser"));
        }
    });
    connect(web, &WebWidget::faviconChanged, this, [this, web](const QIcon& icon) {
        if (!ui || !ui->stackedWidget || !ui->tabBar)
            return;
        const int tabIndex = ui->stackedWidget->indexOf(web);
        if (tabIndex >= 0) {
            if (web->isLoading()) {
                if (!icon.isNull())
                    m_tabIconRestoreWhenLoading.insert(web, icon);
                refreshTabLoadingIcons();
            } else {
                if (icon.isNull()) {
                    m_tabSiteIconByWeb.remove(web);
                    if (!webWidgetIsOnlyNewTabPlaceholder(web)) {
                        const QIcon fb = tabSiteFaviconFallbackIcon();
                        if (!fb.isNull())
                            ui->tabBar->setTabIcon(tabIndex, fb);
                        else
                            ui->tabBar->setTabIcon(tabIndex, icon);
                    }
                } else {
                    m_tabSiteIconByWeb.insert(web, icon);
                    ui->tabBar->setTabIcon(tabIndex, icon);
                }
                ensureTabSiteIconOrFallback(ui->tabBar, tabIndex, web);
            }
            if (ui->tabBar->count() <= 1)
                ui->tabBar->update();
        }
    });
    connect(web, &QObject::destroyed, this, [this, web]() {
        m_tabIconRestoreWhenLoading.remove(web);
        m_tabSiteIconByWeb.remove(web);
        /* 勿在此立刻 syncTabLoadingAnimationState：stackedWidget 可能正在移除/析构子控件，count() 会 AV。 */
        if (!ui)
            return;
        if (m_tabIconRestoreWhenLoading.isEmpty()) {
            if (m_tabLoadingAnimTimer && m_tabLoadingAnimTimer->isActive())
                m_tabLoadingAnimTimer->stop();
            m_tabLoadingAngleDeg = 0;
            return;
        }
        QTimer::singleShot(0, this, [this]() { syncTabLoadingAnimationState(); });
    });
    connect(web, &WebWidget::audioMuteChanged, this, [this, web](bool) {
        updateTabMuteIndicator(web);
    });
    connect(web, &WebWidget::downloadStarted, this, [this, web](const QString& url, const QString& savePath, qint64 totalBytes) {
        const QString fileName = QFileInfo(savePath).fileName();
        DownloadTaskMeta meta;
        meta.source = web;
        meta.url = url;
        meta.finished = false;
        m_downloadTasks.insert(savePath, meta);
        DownloadRecord rec = m_downloadRecords.value(savePath);
        rec.savePath = savePath;
        rec.url = url;
        rec.title = fileName.isEmpty() ? savePath : fileName;
        if (!rec.updatedAt.isValid())
            rec.updatedAt = QDateTime::currentDateTime();
        if (rec.dateKey.trimmed().isEmpty())
            rec.dateKey = QDate::currentDate().toString(QStringLiteral("yyyy-MM-dd"));
        m_downloadRecords.insert(savePath, rec);
        updateDownloadItemWidget(
            savePath,
            fileName.isEmpty() ? savePath : fileName,
            QString::fromUtf8("\xe5\x87\x86\xe5\xa4\x87\xe4\xb8\x8b\xe8\xbd\xbd"),
            0,
            totalBytes,
            false,
            true);
        updateDownloadsNavButtonVisual();
    });
    connect(web, &WebWidget::downloadProgress, this, [this, web](const QString& url, const QString& savePath, qint64 receivedBytes, qint64 totalBytes) {
        if (m_downloadRecords.value(savePath).finished)
            return;
        auto it = m_downloadTasks.find(savePath);
        if (it == m_downloadTasks.end()) {
            DownloadTaskMeta meta;
            meta.source = web;
            meta.url = url;
            m_downloadTasks.insert(savePath, meta);
        } else if (it->url.trimmed().isEmpty() && !url.trimmed().isEmpty()) {
            it->url = url;
        }
        DownloadRecord rec = m_downloadRecords.value(savePath);
        rec.savePath = savePath;
        if (!url.trimmed().isEmpty())
            rec.url = url;
        if (rec.dateKey.trimmed().isEmpty())
            rec.dateKey = QDate::currentDate().toString(QStringLiteral("yyyy-MM-dd"));
        m_downloadRecords.insert(savePath, rec);
        const QString fileName = QFileInfo(savePath).fileName();
        QString status;
        if (totalBytes > 0) {
            status = QString::fromUtf8("\xe6\xad\xa3\xe5\x9c\xa8\xe4\xb8\x8b\xe8\xbd\xbd %1 / %2 \xe5\xad\x97\xe8\x8a\x82")
                    .arg(receivedBytes)
                    .arg(totalBytes);
        } else {
            status = QString::fromUtf8("\xe5\xb7\xb2\xe4\xb8\x8b\xe8\xbd\xbd %1 \xe5\xad\x97\xe8\x8a\x82").arg(receivedBytes);
        }
        updateDownloadItemWidget(
            savePath,
            fileName.isEmpty() ? savePath : fileName,
            status,
            receivedBytes,
            totalBytes,
            false,
            true);
        updateDownloadsNavButtonVisual();
    });
    connect(web, &WebWidget::downloadFinished, this, [this](const QString& url, const QString& savePath, bool ok, const QString& reason) {
        Q_UNUSED(url);
        auto it = m_downloadTasks.find(savePath);
        if (it == m_downloadTasks.end()) {
            DownloadTaskMeta meta;
            meta.finished = true;
            m_downloadTasks.insert(savePath, meta);
            it = m_downloadTasks.find(savePath);
        } else {
            it->finished = true;
        }
        DownloadRecord rec = m_downloadRecords.value(savePath);
        rec.savePath = savePath;
        if (rec.dateKey.trimmed().isEmpty())
            rec.dateKey = QDate::currentDate().toString(QStringLiteral("yyyy-MM-dd"));
        m_downloadRecords.insert(savePath, rec);
        const QString fileName = QFileInfo(savePath).fileName();
        const QString status = ok
            ? QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe5\xae\x8c\xe6\x88\x90\xef\xbc\x8c\xe4\xbf\x9d\xe5\xad\x98\xe8\x87\xb3\xef\xbc\x9a%1").arg(savePath)
            : QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe5\xa4\xb1\xe8\xb4\xa5\xef\xbc\x9a%1").arg(reason.isEmpty() ? QString::fromUtf8("\xe6\x9c\xaa\xe7\x9f\xa5\xe5\x8e\x9f\xe5\x9b\xa0") : reason);
        const qint64 finalReceived = qMax<qint64>(rec.receivedBytes, ok ? rec.totalBytes : rec.receivedBytes);
        const qint64 finalTotal = qMax<qint64>(rec.totalBytes, finalReceived);
        updateDownloadItemWidget(
            savePath,
            fileName.isEmpty() ? savePath : fileName,
            status,
            finalReceived,
            finalTotal,
            true,
            ok);
        updateDownloadsNavButtonVisual();
    });
    /* 历史：不依赖 loadFinished（Linux 上 miniblink 常不回调或 ok=false）。在 URL/标题稳定后用防抖写入。 */
    {
        auto* historyCommitTimer = new QTimer(web);
        historyCommitTimer->setSingleShot(true);
        historyCommitTimer->setInterval(480);
        auto commit = [web]() {
            const QString u = web->currentUrl().trimmed();
            if (u.isEmpty() || u == QStringLiteral("about:blank"))
                return;
            BrowserHistoryStore::instance()->addVisit(u, web->title());
        };
        QObject::connect(historyCommitTimer, &QTimer::timeout, web, commit);
        auto bump = [historyCommitTimer]() { historyCommitTimer->start(); };
        QObject::connect(web, &WebWidget::urlChanged, web, bump);
        QObject::connect(web, &WebWidget::titleChanged, web, bump);
    }
    /* 地址栏输入记录：导航完成后写入实际 URL（保留 https/http 真实协议） */
    {
        auto* inputHistoryTimer = new QTimer(web);
        inputHistoryTimer->setSingleShot(true);
        inputHistoryTimer->setInterval(480);
        auto commitInput = [web]() {
            const QString u = web->currentUrl().trimmed();
            if (u.isEmpty() || u == QStringLiteral("about:blank"))
                return;
            AddressInputHistoryStore::instance()->recordInput(u);
        };
        QObject::connect(inputHistoryTimer, &QTimer::timeout, web, commitInput);
        auto bumpInput = [inputHistoryTimer]() { inputHistoryTimer->start(); };
        QObject::connect(web, &WebWidget::urlChanged, web, bumpInput);
    }
    /* 备用：部分环境 url/title 防抖仍漏记时，在加载结束时再提交一次（receiver 用 web，避免自定义消息循环下 qApp 定时器异常） */
    QObject::connect(web, &WebWidget::loadFinished, web, [web](const QString&, bool, const QString&) {
        QTimer::singleShot(120, web, [web]() {
            const QString u = web->currentUrl().trimmed();
            if (u.isEmpty() || u == QStringLiteral("about:blank"))
                return;
            BrowserHistoryStore::instance()->addVisit(u, web->title());
        });
    });
    return web;
}

void Widget::openSettingsTab()
{
    if (m_settingsTabPage && ui->stackedWidget->indexOf(m_settingsTabPage.data()) >= 0) {
        const int i = ui->stackedWidget->indexOf(m_settingsTabPage.data());
        ui->tabBar->setCurrentIndex(i);
        ui->stackedWidget->setCurrentIndex(i);
        updateUiFromCurrentTab();
        return;
    }

    auto* page = new BrowserSettingsWidget(ui->stackedWidget);
    m_settingsTabPage = page;
    const int index = ui->stackedWidget->addWidget(page);
    /* 与网页标签一致：tabText 置空，标题只放 tabData，避免 QSS 与 WebTabBar::paintEvent 各画一遍导致「设置」重复 */
    ui->tabBar->addTab(QString());
    ui->tabBar->setTabData(index, QVariant(QString::fromUtf8("\xe8\xae\xbe\xe7\xbd\xae")));

    QToolButton* closeBtn = new QToolButton(ui->tabBar);
    setupTabCloseToolButton(closeBtn);
    ui->tabBar->setTabButton(index, QTabBar::RightSide, closeBtn);
    connect(closeBtn, &QToolButton::clicked, this, [this, closeBtn]() {
        for (int i = 0; i < ui->tabBar->count(); ++i) {
            if (ui->tabBar->tabButton(i, QTabBar::RightSide) == closeBtn) {
                closeTab(i);
                break;
            }
        }
    });

    ui->tabBar->setCurrentIndex(index);
    ui->stackedWidget->setCurrentIndex(index);
    QTimer::singleShot(0, this, [this]() { stabilizeTabBarLayout(); });
    updateUiFromCurrentTab();
    connect(page, &BrowserSettingsWidget::openUrlRequested, this, [this](const QString& url) {
        WebWidget* web = createTab(url, true, false);
        setAddressBarUrlDisplay(ui->editUrl, url);
        if (web)
            web->setFocus();
    });
}

void Widget::createNewTab()
{
    if (ui->tabBar && ui->tabBar->count() >= kMaxTabCount)
        return;
    createTab(QStringLiteral("about:blank"), true, true);
    QTimer::singleShot(0, this, [this]() {
        ui->editUrl->setFocus();
        ui->editUrl->selectAll();
    });
}

void Widget::closeTab(int index)
{
    if (index < 0)
        return;

    QWidget* page = ui->stackedWidget->widget(index);
    ui->stackedWidget->removeWidget(page);
    ui->tabBar->removeTab(index);
    delete page;

    if (ui->tabBar->count() == 0)
        createNewTab();
    else {
        const int current = qMin(index, ui->tabBar->count() - 1);
        ui->tabBar->setCurrentIndex(current);
        ui->stackedWidget->setCurrentIndex(current);
        updateUiFromCurrentTab();
    }
    if (ui->tabBar->count() == 1)
        ui->tabBar->setCurrentIndex(0);
    QTimer::singleShot(0, this, [this]() { stabilizeTabBarLayout(); });
}

void Widget::closeWebWidgetTab(WebWidget* web)
{
    if (!ui || !web)
        return;
    const int idx = ui->stackedWidget->indexOf(web);
    if (idx < 0)
        return;
    QPointer<WebWidget> opener = web->authPopupOpener();
    const bool reloadOpener = web->authPopupShouldReloadOpener();
    closeTab(idx);
    if (!opener)
        return;
    const int openerIdx = ui->stackedWidget->indexOf(opener.data());
    if (openerIdx < 0)
        return;
    ui->tabBar->setCurrentIndex(openerIdx);
    ui->stackedWidget->setCurrentIndex(openerIdx);
    updateUiFromCurrentTab();
    if (reloadOpener)
        opener->reload();
    opener->syncViewport();
}

void Widget::onCurrentTabChanged(int index)
{
    if (index >= 0 && index < ui->stackedWidget->count())
        ui->stackedWidget->setCurrentIndex(index);
    updateDownloadTabWrapWidth();
    QTimer::singleShot(0, this, [this]() { updateDownloadTabWrapWidth(); });
    refreshTabBarTitlesForLayout();
    updateUiFromCurrentTab();
    if (WebWidget* w = currentWebWidget())
        w->syncViewport();
}

void Widget::onTabBarContextMenu(int index, const QPoint& globalPos)
{
    if (index < 0 || index >= ui->tabBar->count())
        return;

    WebWidget* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(index));
    const bool isWeb = (web != nullptr);

    QMenu menu(this);
    QAction* actOpenNew = menu.addAction(QString::fromUtf8("\xe5\x9c\xa8\xe6\x96\xb0\xe6\xa0\x87\xe7\xad\xbe\xe9\xa1\xb5\xe6\x89\x93\xe5\xbc\x80"));
    QAction* actMute = menu.addAction(
        isWeb && web->isAudioMuted()
            ? QString::fromUtf8("\xe5\xb0\x86\xe6\xad\xa4\xe7\xbd\x91\xe9\xa1\xb5\xe5\x8f\x96\xe6\xb6\x88\xe9\x9d\x99\xe9\x9f\xb3")
            : QString::fromUtf8("\xe5\xb0\x86\xe6\xad\xa4\xe7\xbd\x91\xe9\xa1\xb5\xe9\x9d\x99\xe9\x9f\xb3"));
    menu.addSeparator();
    QAction* actClose = menu.addAction(QString::fromUtf8("\xe5\x85\xb3\xe9\x97\xad\xe6\xa0\x87\xe7\xad\xbe"));
    QAction* actCloseOthers = menu.addAction(QString::fromUtf8("\xe5\x85\xb3\xe9\x97\xad\xe5\x85\xb6\xe4\xbb\x96\xe6\xa0\x87\xe7\xad\xbe"));
    QAction* actCloseRight = menu.addAction(QString::fromUtf8("\xe5\x85\xb3\xe9\x97\xad\xe5\x8f\xb3\xe4\xbe\xa7\xe6\xa0\x87\xe7\xad\xbe"));

    actOpenNew->setEnabled(isWeb);
    actMute->setEnabled(isWeb);

    QAction* chosen = menu.exec(globalPos);
    if (!chosen)
        return;

    if (chosen == actOpenNew) {
        QString url = web->currentUrl().trimmed();
        if (url.isEmpty())
            url = QStringLiteral("about:blank");
        createTab(url, true, false);
        return;
    }
    if (chosen == actMute) {
        if (web)
            web->toggleAudioMute();
        return;
    }
    if (chosen == actClose) {
        closeTab(index);
        return;
    }
    if (chosen == actCloseOthers) {
        closeOtherTabs(index);
        return;
    }
    if (chosen == actCloseRight)
        closeTabsToTheRightOf(index);
}

void Widget::closeOtherTabs(int keepIndex)
{
    if (keepIndex < 0 || keepIndex >= ui->tabBar->count())
        return;
    for (int i = ui->tabBar->count() - 1; i >= 0; --i) {
        if (i != keepIndex)
            closeTab(i);
    }
}

void Widget::closeTabsToTheRightOf(int index)
{
    if (index < 0 || index >= ui->tabBar->count())
        return;
    for (int i = ui->tabBar->count() - 1; i > index; --i)
        closeTab(i);
}

void Widget::updateUiFromCurrentTab()
{
    hideUrlSuggestPopup();
    WebWidget* web = currentWebWidget();
    if (!web) {
        ui->btnBack->setEnabled(false);
        ui->btnForward->setEnabled(false);
        ui->btnReload->setEnabled(false);
        setReloadButtonLoadingState(ui, false);
        ui->editUrl->clear();
        ui->editUrl->setPlaceholderText(QString::fromUtf8("\xe8\xae\xbe\xe7\xbd\xae"));
        setWindowTitle(QString::fromUtf8("\xe8\xae\xbe\xe7\xbd\xae") + QStringLiteral(" - LiteView Browser"));
        return;
    }

    ui->btnReload->setEnabled(true);
    setReloadButtonLoadingState(ui, web->isLoading());
    if (!web->isLoading())
        refreshTabSiteIconForWeb(web);
    ui->editUrl->setPlaceholderText(QString::fromUtf8("\xe6\x90\x9c\xe7\xb4\xa2\xe6\x88\x96\xe8\xbe\x93\xe5\x85\xa5\xe7\xbd\x91\xe5\x9d\x80"));
    setAddressBarUrlDisplay(ui->editUrl, web->currentUrl());
    const QString t = web->title();
    if (!t.isEmpty())
        setWindowTitle(QStringLiteral("%1 - LiteView").arg(t));
    else
        setWindowTitle(QStringLiteral("LiteView Browser"));
}

QIcon Widget::buildTabLoadingIcon() const
{
    if (m_tabLoadingBasePixmap.isNull())
        return QIcon();
    const QPixmap rotated = rotatePixmap(m_tabLoadingBasePixmap, m_tabLoadingAngleDeg);
    return QIcon(rotated);
}

void Widget::refreshTabSiteIconForWeb(WebWidget* web)
{
    if (!ui || !web || !ui->stackedWidget || !ui->tabBar || web->isLoading())
        return;
    const int tabIndex = ui->stackedWidget->indexOf(web);
    if (tabIndex < 0 || webWidgetIsOnlyNewTabPlaceholder(web))
        return;
    const QIcon cached = FaviconCache::loadIconForPageUrl(web->currentUrl());
    if (!cached.isNull()) {
        ui->tabBar->setTabIcon(tabIndex, cached);
        m_tabSiteIconByWeb.insert(web, cached);
        return;
    }
    const auto it = m_tabSiteIconByWeb.constFind(web);
    if (it != m_tabSiteIconByWeb.constEnd() && !it.value().isNull()) {
        ui->tabBar->setTabIcon(tabIndex, it.value());
        return;
    }
    /* 无缓存、无记录时不改 tabIcon，避免切换/新建标签把已显示的站点图标打成默认 label */
}

void Widget::applyLoadedTabIconForWeb(WebWidget* web)
{
    if (!ui || !web || !ui->stackedWidget || !ui->tabBar)
        return;
    if (web->isLoading())
        return;
    const int tabIndex = ui->stackedWidget->indexOf(web);
    if (tabIndex < 0)
        return;
    const QIcon restoreIcon = m_tabIconRestoreWhenLoading.take(web);
    if (!restoreIcon.isNull()) {
        ui->tabBar->setTabIcon(tabIndex, restoreIcon);
        if (!webWidgetIsOnlyNewTabPlaceholder(web))
            m_tabSiteIconByWeb.insert(web, restoreIcon);
        return;
    }
    const QIcon cached = FaviconCache::loadIconForPageUrl(web->currentUrl());
    if (!cached.isNull()) {
        ui->tabBar->setTabIcon(tabIndex, cached);
        m_tabSiteIconByWeb.insert(web, cached);
        return;
    }
    const auto it = m_tabSiteIconByWeb.constFind(web);
    if (it != m_tabSiteIconByWeb.constEnd() && !it.value().isNull()) {
        ui->tabBar->setTabIcon(tabIndex, it.value());
        return;
    }
    static const QIcon kNewTabLabelIcon = loadImageFromImagesDir({QStringLiteral("label")});
    const QIcon current = ui->tabBar->tabIcon(tabIndex);
    if (!current.isNull() && !kNewTabLabelIcon.isNull() && current.cacheKey() != kNewTabLabelIcon.cacheKey()) {
        m_tabSiteIconByWeb.insert(web, current);
        return;
    }
    ui->tabBar->setTabIcon(tabIndex, QIcon());
    applyTabTitleForWeb(web, web->title());
    ensureTabSiteIconOrFallback(ui->tabBar, tabIndex, web);
}

void Widget::refreshTabLoadingIcons()
{
    if (!ui || !ui->tabBar || !ui->stackedWidget)
        return; /* ~Widget 置空 ui 后，定时器/队列槽仍可能触发 */
    const QIcon loadingIcon = buildTabLoadingIcon();
    if (loadingIcon.isNull())
        return;
    for (int i = 0; i < ui->stackedWidget->count(); ++i) {
        WebWidget* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i));
        if (!web || !web->isLoading())
            continue;
        ui->tabBar->setTabIcon(i, loadingIcon);
    }
}

void Widget::syncTabLoadingAnimationState()
{
    if (!ui || !ui->stackedWidget || !ui->tabBar)
        return;
    bool anyLoading = false;
    for (int i = 0; i < ui->stackedWidget->count(); ++i) {
        WebWidget* web = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i));
        if (web && web->isLoading()) {
            anyLoading = true;
            break;
        }
    }
    if (anyLoading) {
        if (m_tabLoadingAnimTimer && !m_tabLoadingAnimTimer->isActive())
            m_tabLoadingAnimTimer->start();
        refreshTabLoadingIcons();
    } else {
        if (m_tabLoadingAnimTimer && m_tabLoadingAnimTimer->isActive())
            m_tabLoadingAnimTimer->stop();
        m_tabLoadingAngleDeg = 0;
        for (int i = 0; i < ui->stackedWidget->count(); ++i) {
            auto* w = qobject_cast<WebWidget*>(ui->stackedWidget->widget(i));
            if (!w || w->isLoading())
                continue;
            const int ti = i;
            const QIcon cur = ui->tabBar->tabIcon(ti);
            const QIcon spin = buildTabLoadingIcon();
            const bool looksLoading = !spin.isNull() && !cur.isNull() && cur.cacheKey() == spin.cacheKey();
            if (looksLoading)
                applyLoadedTabIconForWeb(w);
            else
                refreshTabSiteIconForWeb(w);
        }
    }
}

namespace {

/** 先 qrc 再 exe 旁 images/；供自绘复选框使用（QSS 的 ::indicator image 在 Windows 上常不绘制） */
const QPixmap& clearBrowsingCheckboxCheckedPixmap()
{
    static QPixmap pm;
    static bool tried = false;
    if (!tried) {
        tried = true;
        if (!pm.load(QStringLiteral(":/images/checkbox_checked.png"))) {
            const QString disk = QDir(QCoreApplication::applicationDirPath()).filePath(QStringLiteral("images/checkbox_checked.png"));
            pm.load(disk);
        }
    }
    return pm;
}

/** 清除浏览数据专用：自绘指示器，保证蓝底白勾可见 */
class ClearBrowsingDataCheckBox final : public QCheckBox {
public:
    explicit ClearBrowsingDataCheckBox(const QString& text, QWidget* parent = nullptr)
        : QCheckBox(text, parent)
    {
        setAttribute(Qt::WA_StyledBackground, true);
        setMouseTracking(false);
        setCursor(Qt::PointingHandCursor);
        setMinimumHeight(44);
    }

    QSize sizeHint() const override
    {
        QSize s = QCheckBox::sizeHint();
        s.setHeight(qMax(s.height(), 44));
        return s;
    }

protected:
    bool hitButton(const QPoint& pos) const override
    {
        return rect().contains(pos);
    }

    void paintEvent(QPaintEvent* event) override
    {
        Q_UNUSED(event);
        QPainter p(this);
        p.setRenderHint(QPainter::Antialiasing, true);

        QStyleOptionButton opt;
        initStyleOption(&opt);
        opt.rect = rect();

        const QRect indicatorRect = style()->subElementRect(QStyle::SE_CheckBoxIndicator, &opt, this);
        const QRect textRect = style()->subElementRect(QStyle::SE_CheckBoxContents, &opt, this);

        p.fillRect(rect(), QColor(QStringLiteral("#F7F9FC")));

        if (isChecked()) {
            const QPixmap& pm = clearBrowsingCheckboxCheckedPixmap();
            if (!pm.isNull()) {
                const QPixmap scaled = pm.scaled(indicatorRect.size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
                const QPoint pos(indicatorRect.x() + (indicatorRect.width() - scaled.width()) / 2,
                    indicatorRect.y() + (indicatorRect.height() - scaled.height()) / 2);
                p.drawPixmap(pos, scaled);
            } else {
                p.fillRect(indicatorRect, QColor(0x4a, 0x90, 0xe2));
            }
        } else {
            p.setPen(QPen(QColor(0xcc, 0xcc, 0xcc)));
            p.setBrush(QColor(0xff, 0xff, 0xff));
            p.drawRoundedRect(indicatorRect.adjusted(0, 0, -1, -1), 3, 3);
        }

        const int tf = Qt::AlignLeft | Qt::AlignVCenter | Qt::TextShowMnemonic | Qt::TextDontClip;
        style()->drawItemText(&p, textRect, tf, palette(), isEnabled(), text(), QPalette::WindowText);

        if (hasFocus()) {
            QStyleOptionFocusRect fropt;
            fropt.rect = style()->subElementRect(QStyle::SE_CheckBoxFocusRect, &opt, this);
            fropt.palette = palette();
            fropt.state = QStyle::State_KeyboardFocusChange;
            style()->drawPrimitive(QStyle::PE_FrameFocusRect, &fropt, &p, this);
        }
    }
};

} // namespace

// --- BrowserSettingsWidget 实现（放在此文件内，避免单独 .cpp 未加入工程导致 LNK2019）---

BrowserSettingsWidget::BrowserSettingsWidget(QWidget* parent)
    : QWidget(parent)
{
    setAttribute(Qt::WA_StyledBackground, true);
    setObjectName(QStringLiteral("browserSettingsRoot"));

    setStyleSheet(
        QStringLiteral(
            "#browserSettingsRoot { background: #F7F9FC; color: #202124; font-family: 'Microsoft YaHei','Segoe UI',sans-serif; font-size: 19px; }"
            /* 覆盖主窗口全局 QWidget 灰/蓝底：设置页内统一 #F7F9FC */
            "#browserSettingsRoot QStackedWidget { background: #F7F9FC; border: none; }"
            "#browserSettingsRoot QStackedWidget > QWidget { background: #F7F9FC; }"
            "#browserSettingsRoot QWidget { background: #F7F9FC; }"
            "#browserSettingsRoot QFrame { background: #F7F9FC; border: none; }"
            "#browserSettingsRoot QLabel { background: transparent; color: #202124; }"
            "#browserSettingsRoot QListWidget { background: #F7F9FC; border: none; outline: none; padding: 10px 0; font-size: 18px; }"
            "#browserSettingsRoot QListWidget::item { padding: 14px 18px; margin: 0 8px; border-radius: 4px; color: #5f6368; font-size: 18px; background: #F7F9FC; }"
            "#browserSettingsRoot QListWidget::item:selected { background: #e8f0fe; color: #1967d2; border-left: 3px solid #1a73e8; margin-left: 5px; padding-left: 15px; }"
            "#browserSettingsRoot QListWidget::item:hover:!selected { background: #f5f6f8; }"
            "#browserSettingsRoot QRadioButton { spacing: 10px; font-size: 19px; background: #F7F9FC; color: #202124; }"
            "#browserSettingsRoot QLineEdit { padding: 12px 14px; border: 1px solid #dadce0; border-radius: 6px; min-height: 30px; font-size: 18px; background: #ffffff; color: #202124; }"
            "#browserSettingsRoot QLineEdit:focus { border-color: #1a73e8; background: #ffffff; }"
            "#browserSettingsRoot QLineEdit#historySearchEdit { min-width: 535px; max-width: 535px; border-radius: 27px; background: #F7F9FC; }"
            "#browserSettingsRoot QLineEdit#historySearchEdit:focus { background: #F7F9FC; border-color: #1a73e8; }"
            "#browserSettingsRoot QPushButton { background: #1a73e8; color: #ffffff; border: none; border-radius: 6px; padding: 10px 28px; font-weight: 500; font-size: 18px; min-height: 42px; }"
            "#browserSettingsRoot QPushButton:hover { background: #1765cc; }"
            "#browserSettingsRoot QPushButton:pressed { background: #1557b0; }"
            "#browserSettingsRoot QPushButton#btnClearHistory { background: #DDDDDD; color: #202124; border: 1px solid #dadce0; border-radius: 6px; padding: 10px 12px; font-weight: 400; font-size: 18px; min-height: 42px; min-width: 155px; max-width: 155px; }"
            "#browserSettingsRoot QPushButton#btnClearHistory:hover { background: #f5f6f8; }"
            "#browserSettingsRoot QPushButton#btnClearBrowsingData { background: #ea4335; color: #ffffff; border: none; border-radius: 6px; padding: 0px; font-weight: 500; font-size: 18px; min-width: 120px; max-width: 120px; min-height: 45px; max-height: 45px; }"
            "#browserSettingsRoot QPushButton#btnClearBrowsingData:hover { background: #d93025; }"
            "#browserSettingsRoot QPushButton#btnClearBrowsingData:pressed { background: #c5221f; }"
            /* 清除浏览数据复选框由 ClearBrowsingDataCheckBox 自绘，勿用 QSS ::indicator image */
            "#browserSettingsRoot QCheckBox { spacing: 10px; font-size: 19px; color: #202124; background: transparent; min-height: 44px; }"
            "#browserSettingsRoot QScrollArea { border: none; background: #F7F9FC; }"
            "#browserSettingsRoot QScrollArea#historyScroll { border: none; background: #F7F9FC; }"
            "#browserSettingsRoot QScrollBar:vertical { width: 5px; margin: 0; background: transparent; }"
            "#browserSettingsRoot QScrollBar::handle:vertical { min-height: 24px; background: rgba(120,130,150,0.45); border-radius: 4px; }"
            "#browserSettingsRoot QScrollBar:horizontal { height: 5px; margin: 0; background: transparent; }"
            "#browserSettingsRoot QScrollBar::handle:horizontal { min-width: 24px; background: rgba(120,130,150,0.45); border-radius: 4px; }"
            "#browserSettingsRoot QScrollBar::add-line, #browserSettingsRoot QScrollBar::sub-line, "
            "#browserSettingsRoot QScrollBar::add-page, #browserSettingsRoot QScrollBar::sub-page { background: transparent; border: none; }"
            "#browserSettingsRoot #historyScrollFrame { border: 1px solid #DDDDDD; border-radius: 8px; background: #F7F9FC; }"));

    auto* mainLay = new QHBoxLayout(this);
    mainLay->setContentsMargins(0, 0, 0, 0);
    mainLay->setSpacing(0);

    m_sidebar = new QListWidget(this);
    m_sidebar->setAttribute(Qt::WA_StyledBackground, true);
    m_sidebar->setMouseTracking(true);
    m_sidebar->setSpacing(2);
    m_sidebar->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    // 中文使用 UTF-8 十六进制，避免 MSVC 在未使用 /utf-8 时对 QStringLiteral 报 C2001
    m_sidebar->addItem(QString::fromUtf8("\xe4\xb8\xbb\xe9\xa1\xb5\xe8\xae\xbe\xe7\xbd\xae"));
    m_sidebar->addItem(QString::fromUtf8("\xe5\x8e\x86\xe5\x8f\xb2\xe8\xae\xb0\xe5\xbd\x95"));
    m_sidebar->addItem(QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe8\xae\xbe\xe7\xbd\xae"));
    m_sidebar->addItem(QString::fromUtf8("\xe6\xb8\x85\xe9\x99\xa4\xe6\xb5\x8f\xe8\xa7\x88\xe6\x95\xb0\xe6\x8d\xae"));
    m_sidebar->addItem(QString::fromUtf8("\xe5\x85\xb3\xe4\xba\x8e"));
    m_sidebar->setCurrentRow(0);
    m_sidebar->setIconSize(QSize(24, 24));
    m_sidebarIconsNormal.resize(m_sidebar->count());
    m_sidebarIconsActive.resize(m_sidebar->count());
    auto setSidebarIcon = [this](int index, const QStringList& stems, QStyle::StandardPixmap fallback, bool forceGrayNormal) {
        if (!m_sidebar || index < 0 || index >= m_sidebar->count())
            return;
        QIcon icon = loadImageFromImagesDir(stems);
        if (icon.isNull())
            icon = style()->standardIcon(fallback);
        m_sidebarIconsNormal[index] = forceGrayNormal
            ? tintedSidebarIcon(icon, m_sidebar->iconSize(), QColor(QStringLiteral("#5F6368")))
            : icon;
        m_sidebarIconsActive[index] = tintedSidebarIcon(icon, m_sidebar->iconSize(), QColor(QStringLiteral("#1A73E8")));
    };
    setSidebarIcon(0,
        {QStringLiteral("settings_home"), QStringLiteral("home_settings"), QStringLiteral("sidebar_home"), QStringLiteral("home"), QStringLiteral("nav_home")},
        QStyle::SP_DirHomeIcon, false);
    setSidebarIcon(1,
        {QStringLiteral("settings_history"), QStringLiteral("history_record"), QStringLiteral("sidebar_history"), QStringLiteral("history")},
        QStyle::SP_FileDialogListView, false);
    setSidebarIcon(2,
        {QStringLiteral("settings_download"), QStringLiteral("download_settings"), QStringLiteral("sidebar_download"), QStringLiteral("download")},
        QStyle::SP_DriveHDIcon, false);
    setSidebarIcon(3,
        {QStringLiteral("clean"), QStringLiteral("settings_clear"), QStringLiteral("clear_browsing_data"), QStringLiteral("sidebar_clear"), QStringLiteral("clear_data")},
        QStyle::SP_TrashIcon, false);
    setSidebarIcon(4,
        {QStringLiteral("settings_about"), QStringLiteral("about"), QStringLiteral("sidebar_about")},
        QStyle::SP_MessageBoxInformation, true);
    refreshSidebarIcons();

    m_stack = new QStackedWidget(this);
    m_stack->setAttribute(Qt::WA_StyledBackground, true);

    auto* homePage = new QWidget(m_stack);
    auto* homeLay = new QVBoxLayout(homePage);
    homeLay->setContentsMargins(56, 44, 64, 48);
    homeLay->setSpacing(0);

    auto* titleHome = new QLabel(QString::fromUtf8("\xe4\xb8\xbb\xe9\xa1\xb5\xe8\xae\xbe\xe7\xbd\xae"), homePage);
    titleHome->setStyleSheet(QStringLiteral("color: #202124; font-size: 26px; font-weight: 600; letter-spacing: 4px;"));
    homeLay->addWidget(titleHome);

    auto* line = new QFrame(homePage);
    line->setFrameShape(QFrame::HLine);
    line->setStyleSheet(QStringLiteral("background: #e8eaed; max-height: 1px; border: none;"));
    homeLay->addSpacing(20);
    homeLay->addWidget(line);
    homeLay->addSpacing(28);

    auto* homeStartupBlock = new QWidget(homePage);
    auto* startupLay = new QVBoxLayout(homeStartupBlock);
    startupLay->setContentsMargins(5, 0, 0, 0);
    startupLay->setSpacing(0);

    auto* section = new QLabel(QString::fromUtf8("\xe5\x90\xaf\xe5\x8a\xa8\xe6\x97\xb6"), homeStartupBlock);
    section->setStyleSheet(QStringLiteral("color: #202124; font-size: 19px; font-weight: 600; letter-spacing: 1.2px;"));
    startupLay->addWidget(section);
    startupLay->addSpacing(18);

    m_radioNewTab = new QRadioButton(QString::fromUtf8("\xe6\x89\x93\xe5\xbc\x80\xe6\x96\xb0\xe6\xa0\x87\xe7\xad\xbe\xe9\xa1\xb5"), homeStartupBlock);
    m_radioSpecificUrl = new QRadioButton(QString::fromUtf8("\xe6\x89\x93\xe5\xbc\x80\xe7\x89\xb9\xe5\xae\x9a\xe7\xbd\x91\xe9\xa1\xb5"), homeStartupBlock);
    m_radioNewTab->setStyleSheet(QStringLiteral("color: #202124; font-size: 19px;"));
    m_radioSpecificUrl->setStyleSheet(QStringLiteral("color: #202124; font-size: 19px;"));
    auto* group = new QButtonGroup(this);
    group->addButton(m_radioNewTab);
    group->addButton(m_radioSpecificUrl);
    startupLay->addWidget(m_radioNewTab);
    startupLay->addSpacing(14);
    startupLay->addWidget(m_radioSpecificUrl);
    startupLay->addSpacing(20);

    m_lblStartupUrlCaption = new QLabel(QString::fromUtf8("\xe5\x90\xaf\xe5\x8a\xa8\xe6\x97\xb6\xe6\x89\x93\xe5\xbc\x80\xe7\x9a\x84\xe7\xbd\x91\xe9\xa1\xb5"), homeStartupBlock);
    m_lblStartupUrlCaption->setStyleSheet(QStringLiteral("color: #5f6368; font-size: 18px;"));
    m_lblStartupUrlCaption->setVisible(false);
    startupLay->addWidget(m_lblStartupUrlCaption);
    startupLay->addSpacing(10);

    m_editSpecificUrl = new QLineEdit(homeStartupBlock);
    m_editSpecificUrl->setPlaceholderText(QString::fromUtf8("\xe8\xaf\xb7\xe8\xbe\x93\xe5\x85\xa5\xe7\xbd\x91\xe5\x9d\x80"));
    m_editSpecificUrl->setVisible(false);
    m_editSpecificUrl->setMinimumWidth(480);
    m_editSpecificUrl->setMaximumWidth(920);
    startupLay->addWidget(m_editSpecificUrl, 0, Qt::AlignLeft);
    startupLay->addSpacing(32);

    m_btnSaveHomepage = new QPushButton(QString::fromUtf8("\xe4\xbf\x9d\xe5\xad\x98"), homeStartupBlock);
    m_btnSaveHomepage->setMinimumWidth(120);
    m_btnSaveHomepage->setMinimumHeight(42);
    startupLay->addWidget(m_btnSaveHomepage, 0, Qt::AlignLeft);

    homeLay->addWidget(homeStartupBlock);
    homeLay->addStretch();

    m_stack->addWidget(homePage);

    auto* historyPage = new QWidget(m_stack);
    auto* histMain = new QVBoxLayout(historyPage);
    histMain->setContentsMargins(56, 44, 64, 48);
    histMain->setSpacing(0);

    auto* titleHist = new QLabel(QString::fromUtf8("\xe5\x8e\x86\xe5\x8f\xb2\xe8\xae\xb0\xe5\xbd\x95"), historyPage);
    titleHist->setStyleSheet(QStringLiteral("color: #202124; font-size: 26px; font-weight: 600; letter-spacing: 2px;"));
    histMain->addWidget(titleHist);

    auto* lineH = new QFrame(historyPage);
    lineH->setFrameShape(QFrame::HLine);
    lineH->setStyleSheet(QStringLiteral("background: #e8eaed; max-height: 1px; border: none;"));
    histMain->addSpacing(20);
    histMain->addWidget(lineH);
    histMain->addSpacing(28);

    auto* barRow = new QHBoxLayout();
    barRow->setSpacing(0);
    m_historySearchEdit = new QLineEdit(historyPage);
    m_historySearchEdit->setObjectName(QStringLiteral("historySearchEdit"));
    m_historySearchEdit->setPlaceholderText(QString::fromUtf8("\xe6\x90\x9c\xe7\xb4\xa2\xe5\x8e\x86\xe5\x8f\xb2\xe8\xae\xb0\xe5\xbd\x95\xe2\x80\xa6"));
    m_historySearchEdit->setClearButtonEnabled(true);
    m_btnClearHistory = new QPushButton(QString::fromUtf8("\xe6\xb8\x85\xe9\x99\xa4\xe5\x8e\x86\xe5\x8f\xb2\xe8\xae\xb0\xe5\xbd\x95"), historyPage);
    m_btnClearHistory->setObjectName(QStringLiteral("btnClearHistory"));
    barRow->addWidget(m_historySearchEdit, 0);
    barRow->addStretch(1);
    barRow->addWidget(m_btnClearHistory, 0, Qt::AlignVCenter);
    histMain->addLayout(barRow);
    histMain->addSpacing(16);
    auto* lineHistorySep = new QFrame(historyPage);
    lineHistorySep->setFrameShape(QFrame::HLine);
    lineHistorySep->setFixedHeight(1);
    lineHistorySep->setStyleSheet(QStringLiteral("background: #e8eaed; max-height: 1px; border: none;"));
    histMain->addWidget(lineHistorySep);
    histMain->addSpacing(16);

    m_historyScroll = new QScrollArea(historyPage);
    m_historyScroll->setObjectName(QStringLiteral("historyScroll"));
    m_historyScroll->setWidgetResizable(true);
    m_historyScroll->setFrameShape(QFrame::NoFrame);
    m_historyScroll->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_historyContentWidget = new QWidget();
    m_historyContentWidget->setObjectName(QStringLiteral("historyScrollFrame"));
    m_historyListLayout = new QVBoxLayout(m_historyContentWidget);
    /* 记录行与外框留 1px 缝隙，避免行背景覆盖边框视觉 */
    m_historyListLayout->setContentsMargins(1, 1, 1, 1);
    m_historyListLayout->setSpacing(0);
    m_historyScroll->setWidget(m_historyContentWidget);
    histMain->addWidget(m_historyScroll, 1);

    m_stack->addWidget(historyPage);

    auto* downloadPage = new QWidget(m_stack);
    auto* dlMain = new QVBoxLayout(downloadPage);
    dlMain->setContentsMargins(56, 44, 64, 48);
    dlMain->setSpacing(0);

    auto* titleDl = new QLabel(QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe8\xae\xbe\xe7\xbd\xae"), downloadPage);
    titleDl->setStyleSheet(QStringLiteral("color: #202124; font-size: 26px; font-weight: 600; letter-spacing: 2px;"));
    dlMain->addWidget(titleDl);

    auto* lineDl = new QFrame(downloadPage);
    lineDl->setFrameShape(QFrame::HLine);
    lineDl->setStyleSheet(QStringLiteral("background: #e8eaed; max-height: 1px; border: none;"));
    dlMain->addSpacing(20);
    dlMain->addWidget(lineDl);
    dlMain->addSpacing(28);

    auto* pathRow = new QHBoxLayout();
    pathRow->setSpacing(16);
    auto* pathCol = new QVBoxLayout();
    pathCol->setSpacing(8);
    auto* lblSaveTo = new QLabel(QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe5\x86\x85\xe5\xae\xb9\xe4\xbf\x9d\xe5\xad\x98\xe5\x88\xb0"), downloadPage);
    lblSaveTo->setStyleSheet(QStringLiteral("color: #202124; font-size: 19px; font-weight: 600; letter-spacing: 1.2px;"));
    m_downloadPathLabel = new QLabel(downloadPage);
    m_downloadPathLabel->setWordWrap(true);
    m_downloadPathLabel->setTextInteractionFlags(Qt::TextSelectableByMouse);
    m_downloadPathLabel->setStyleSheet(QStringLiteral("color: #202124; font-size: 19px;"));
    pathCol->addWidget(lblSaveTo);
    pathCol->addWidget(m_downloadPathLabel);
    pathRow->addLayout(pathCol, 1);
    m_btnChangeDownloadPath = new QPushButton(QString::fromUtf8("\xe6\x9b\xb4\xe6\x94\xb9"), downloadPage);
    m_btnChangeDownloadPath->setObjectName(QStringLiteral("btnClearHistory"));
    m_btnChangeDownloadPath->setMinimumHeight(40);
    pathRow->addWidget(m_btnChangeDownloadPath, 0, Qt::AlignTop);
    dlMain->addLayout(pathRow);
    dlMain->addStretch();

    m_stack->addWidget(downloadPage);

    auto* clearDataPage = new QWidget(m_stack);
    auto* clearMain = new QVBoxLayout(clearDataPage);
    clearMain->setContentsMargins(56, 44, 64, 48);
    clearMain->setSpacing(0);

    auto* titleClear = new QLabel(QString::fromUtf8("\xe6\xb8\x85\xe9\x99\xa4\xe6\xb5\x8f\xe8\xa7\x88\xe6\x95\xb0\xe6\x8d\xae"), clearDataPage);
    titleClear->setStyleSheet(QStringLiteral("color: #202124; font-size: 26px; font-weight: 600; letter-spacing: 2px;"));
    clearMain->addWidget(titleClear);

    auto* lineClear = new QFrame(clearDataPage);
    lineClear->setFrameShape(QFrame::HLine);
    lineClear->setStyleSheet(QStringLiteral("background: #e8eaed; max-height: 1px; border: none;"));
    clearMain->addSpacing(20);
    clearMain->addWidget(lineClear);
    clearMain->addSpacing(28);

    auto addClearDataSeparator = [clearDataPage, clearMain]() {
        auto* sep = new QFrame(clearDataPage);
        sep->setFrameShape(QFrame::HLine);
        sep->setFrameShadow(QFrame::Plain);
        sep->setLineWidth(1);
        sep->setFixedHeight(1);
        sep->setAttribute(Qt::WA_TransparentForMouseEvents, true);
        sep->setStyleSheet(QStringLiteral("background: #eeeeee; max-height: 1px; border: none;"));
        clearMain->addWidget(sep);
    };

    m_chkClearInputHistory = new ClearBrowsingDataCheckBox(QString::fromUtf8("\xe8\xbe\x93\xe5\x85\xa5\xe8\xae\xb0\xe5\xbd\x95"), clearDataPage);
    m_chkClearInputHistory->setChecked(false);
    clearMain->addWidget(m_chkClearInputHistory);
    clearMain->addSpacing(12);
    addClearDataSeparator();
    clearMain->addSpacing(12);

    m_chkClearBrowseHistory = new ClearBrowsingDataCheckBox(QString::fromUtf8("\xe6\xb5\x8f\xe8\xa7\x88\xe5\x8e\x86\xe5\x8f\xb2\xe8\xae\xb0\xe5\xbd\x95"), clearDataPage);
    m_chkClearBrowseHistory->setChecked(false);
    clearMain->addWidget(m_chkClearBrowseHistory);
    clearMain->addSpacing(12);
    addClearDataSeparator();
    clearMain->addSpacing(12);

    m_chkClearWebCache = new ClearBrowsingDataCheckBox(QString::fromUtf8("\xe7\xbd\x91\xe9\xa1\xb5\xe7\xbc\x93\xe5\xad\x98"), clearDataPage);
    m_chkClearWebCache->setChecked(false);
    clearMain->addWidget(m_chkClearWebCache);
    clearMain->addSpacing(12);
    addClearDataSeparator();
    clearMain->addSpacing(12);

    m_chkClearCookies = new ClearBrowsingDataCheckBox(QStringLiteral("Cookie"), clearDataPage);
    m_chkClearCookies->setChecked(false);
    clearMain->addWidget(m_chkClearCookies);
    clearMain->addSpacing(28);

    m_btnClearBrowsingData = new QPushButton(QString::fromUtf8("\xe6\xb8\x85\xe9\x99\xa4\xe6\x95\xb0\xe6\x8d\xae"), clearDataPage);
    m_btnClearBrowsingData->setObjectName(QStringLiteral("btnClearBrowsingData"));
    m_btnClearBrowsingData->setFixedSize(120, 45);
    clearMain->addWidget(m_btnClearBrowsingData, 0, Qt::AlignLeft);
    clearMain->addStretch();

    m_stack->addWidget(clearDataPage);

    auto* aboutPage = new QWidget(m_stack);
    auto* aboutMain = new QVBoxLayout(aboutPage);
    aboutMain->setContentsMargins(0, 0, 0, 20);
    aboutMain->setSpacing(0);
    aboutMain->addSpacing(100);

    auto* aboutCenterWrap = new QWidget(aboutPage);
    aboutCenterWrap->setAttribute(Qt::WA_StyledBackground, true);
    auto* centerLay = new QVBoxLayout(aboutCenterWrap);
    centerLay->setContentsMargins(0, 0, 0, 0);
    centerLay->setSpacing(0);
    centerLay->setAlignment(Qt::AlignHCenter);

    auto* iconLbl = new QLabel(aboutCenterWrap);
    iconLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    const QIcon aboutIcon = loadImageFromImagesDir({QStringLiteral("icon")});
    if (!aboutIcon.isNull())
        iconLbl->setPixmap(aboutIcon.pixmap(QSize(144, 144)));
    iconLbl->setFixedSize(144, 144);
    centerLay->addWidget(iconLbl, 0, Qt::AlignHCenter);
    centerLay->addSpacing(10);

    auto* appNameLbl = new QLabel(QString::fromUtf8("\xe6\xb5\x8f\xe8\xa7\x88\xe5\x99\xa8"), aboutCenterWrap);
    appNameLbl->setStyleSheet(QStringLiteral("color: #202124; font-size: 20px; font-weight: 600;"));
    appNameLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    centerLay->addWidget(appNameLbl, 0, Qt::AlignHCenter);
    centerLay->addSpacing(8);

    auto* verLbl = new QLabel(QStringLiteral("2.0.1"), aboutCenterWrap);
    verLbl->setStyleSheet(QStringLiteral("color: #5f6368; font-size: 16px; font-weight: 400;"));
    verLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    centerLay->addWidget(verLbl, 0, Qt::AlignHCenter);
    centerLay->addSpacing(8);

    const QString downloadLatestUrl = QStringLiteral("https://rvbook.isrc.ac.cn/repo/browser/liteview-latest.rpm");
    const QString downloadLatestText =
        QStringLiteral("<a href=\"%1\" style=\"color:#1a73e8; text-decoration:none;\">")
            .arg(downloadLatestUrl)
        + QString::fromUtf8("\xe4\xb8\x8b\xe8\xbd\xbd\xe6\x9c\x80\xe6\x96\xb0\xe7\x89\x88\xe6\x9c\xac")
        + QStringLiteral("</a>");
    auto* downloadLatestLbl = new QLabel(downloadLatestText, aboutCenterWrap);
    downloadLatestLbl->setStyleSheet(QStringLiteral("color: #5f6368; font-size: 16px; font-weight: 400;"));
    downloadLatestLbl->setTextFormat(Qt::RichText);
    downloadLatestLbl->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    downloadLatestLbl->setOpenExternalLinks(false);
    connect(downloadLatestLbl, &QLabel::linkActivated, this, [this](const QString& link) {
        emit openUrlRequested(link);
    });
    downloadLatestLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    centerLay->addWidget(downloadLatestLbl, 0, Qt::AlignHCenter);
    centerLay->addSpacing(14);

    auto* descLbl = new QLabel(QString::fromUtf8("\xe7\xae\x80\xe5\x8d\x95\xe3\x80\x81\xe8\xbd\xbb\xe9\x87\x8f\xe3\x80\x81\xe5\xbf\xab\xe9\x80\x9f\xe7\x9a\x84\xe7\xbd\x91\xe9\xa1\xb5\xe6\xb5\x8f\xe8\xa7\x88\xe4\xbd\x93\xe9\xaa\x8c\xe3\x80\x82"), aboutCenterWrap);
    descLbl->setStyleSheet(QStringLiteral("color: #202124; font-size: 16px; font-weight: 400;"));
    descLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    centerLay->addWidget(descLbl, 0, Qt::AlignHCenter);
    centerLay->addSpacing(22);

    auto* copyrightLbl = new QLabel(
        QStringLiteral("Copyright (c) 2025 Institute of Software, Chinese Academy of Sciences (ISCAS)"),
        aboutCenterWrap);
    copyrightLbl->setStyleSheet(QStringLiteral("color: #5f6368; font-size: 16px; font-weight: 400;"));
    copyrightLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    centerLay->addWidget(copyrightLbl, 0, Qt::AlignHCenter);
    centerLay->addSpacing(8);

    auto* warrantyLbl = new QLabel(QString::fromUtf8("\xe6\x9c\xac\xe7\xa8\x8b\xe5\xba\x8f\xe4\xb8\x8d\xe4\xbd\x9c\xe4\xbb\xbb\xe4\xbd\x95\xe6\x8b\x85\xe4\xbf\x9d\xe3\x80\x82"), aboutCenterWrap);
    warrantyLbl->setStyleSheet(QStringLiteral("color: #5f6368; font-size: 16px; font-weight: 400;"));
    warrantyLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    centerLay->addWidget(warrantyLbl, 0, Qt::AlignHCenter);
    centerLay->addSpacing(10);

    const QString licenseText =
        QString::fromUtf8("\xe8\xaf\xa6\xe6\x83\x85\xe8\xa7\x81")
        + QStringLiteral("<a href=\"http://license.coscl.org.cn/MulanPSL2\" style=\"color:#1a73e8; text-decoration:none;\">")
        + QString::fromUtf8("\xe6\x9c\xa8\xe5\x85\xb0\xe5\xae\xbd\xe6\x9d\xbe\xe8\xae\xb8\xe5\x8f\xaf\xe8\xaf\x81\xef\xbc\x8c\xe7\xac\xac")
        + QStringLiteral("2")
        + QString::fromUtf8("\xe7\x89\x88")
        + QStringLiteral("</a>");
    auto* licenseLbl = new QLabel(licenseText, aboutCenterWrap);
    licenseLbl->setStyleSheet(QStringLiteral("color: #5f6368; font-size: 16px; font-weight: 400;"));
    licenseLbl->setTextFormat(Qt::RichText);
    licenseLbl->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    licenseLbl->setOpenExternalLinks(false);
    connect(licenseLbl, &QLabel::linkActivated, this, [this](const QString& link) {
        emit openUrlRequested(link);
    });
    licenseLbl->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
    centerLay->addWidget(licenseLbl, 0, Qt::AlignHCenter);

    aboutMain->addWidget(aboutCenterWrap, 0, Qt::AlignTop | Qt::AlignHCenter);
    aboutMain->addStretch();

    m_stack->addWidget(aboutPage);

    auto* leftColumn = new QWidget(this);
    leftColumn->setAttribute(Qt::WA_StyledBackground, true);
    leftColumn->setStyleSheet(QStringLiteral("background: #F7F9FC;"));
    leftColumn->setFixedWidth(420);
    auto* leftLay = new QVBoxLayout(leftColumn);
    leftLay->setContentsMargins(0, 0, 0, 0);
    leftLay->setSpacing(0);
    auto* lblSettingsHeader = new QLabel(QString::fromUtf8("\xe8\xae\xbe\xe7\xbd\xae"), leftColumn);
    lblSettingsHeader->setStyleSheet(QStringLiteral(
        "background: #F7F9FC; color: #202124; font-size: 21px; font-weight: 600; letter-spacing: 1.5px; padding: 20px 20px 12px 20px;"));
    leftLay->addWidget(lblSettingsHeader);
    leftLay->addWidget(m_sidebar, 1);

    auto* settingsSplit = new QFrame(this);
    settingsSplit->setFixedWidth(2);
    settingsSplit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    settingsSplit->setStyleSheet(QStringLiteral("background: #c4c7ce; border: none;"));

    mainLay->addWidget(leftColumn);
    mainLay->addWidget(settingsSplit);
    mainLay->addWidget(m_stack, 1);

    connect(m_sidebar, &QListWidget::currentRowChanged, this, &BrowserSettingsWidget::onSidebarRowChanged);
    connect(m_radioNewTab, &QRadioButton::toggled, this, &BrowserSettingsWidget::onHomepageRadioToggled);
    connect(m_radioSpecificUrl, &QRadioButton::toggled, this, &BrowserSettingsWidget::onHomepageRadioToggled);
    connect(m_btnSaveHomepage, &QPushButton::clicked, this, &BrowserSettingsWidget::onSaveHomepageClicked);
    connect(m_historySearchEdit, &QLineEdit::textChanged, this, &BrowserSettingsWidget::onHistorySearchChanged);
    connect(m_btnClearHistory, &QPushButton::clicked, this, &BrowserSettingsWidget::onClearHistoryClicked);
    connect(BrowserHistoryStore::instance(), &BrowserHistoryStore::changed, this, &BrowserSettingsWidget::onHistoryStoreChanged);
    connect(m_btnChangeDownloadPath, &QPushButton::clicked, this, &BrowserSettingsWidget::onChangeDownloadPathClicked);
    connect(m_btnClearBrowsingData, &QPushButton::clicked, this, &BrowserSettingsWidget::onClearBrowsingDataClicked);

    loadHomepageSettings();
    loadDownloadSettings();
    refreshHistoryView();
}

void BrowserSettingsWidget::loadHomepageSettings()
{
    QSettings s(QSettings::IniFormat, QSettings::UserScope,
        QStringLiteral("LiteView"), QStringLiteral("LiteViewBrowser"));
    const int mode = s.value(QStringLiteral("startup/mode"), 0).toInt();
    const QString url = s.value(QStringLiteral("startup/specificUrl"), QString()).toString();
    if (mode == 1) {
        m_radioSpecificUrl->setChecked(true);
        m_editSpecificUrl->setText(url);
        m_editSpecificUrl->setVisible(true);
        if (m_lblStartupUrlCaption)
            m_lblStartupUrlCaption->setVisible(true);
    } else {
        m_radioNewTab->setChecked(true);
        m_editSpecificUrl->setText(url);
        m_editSpecificUrl->setVisible(false);
        if (m_lblStartupUrlCaption)
            m_lblStartupUrlCaption->setVisible(false);
    }
}

void BrowserSettingsWidget::onSidebarRowChanged(int row)
{
    if (row >= 0 && row < m_stack->count())
        m_stack->setCurrentIndex(row);
    refreshSidebarIcons();
}

void BrowserSettingsWidget::refreshSidebarIcons()
{
    if (!m_sidebar)
        return;
    const int current = m_sidebar->currentRow();
    for (int i = 0; i < m_sidebar->count(); ++i) {
        QListWidgetItem* item = m_sidebar->item(i);
        if (!item)
            continue;
        const bool active = (i == current);
        if (active && i < m_sidebarIconsActive.size() && !m_sidebarIconsActive[i].isNull())
            item->setIcon(m_sidebarIconsActive[i]);
        else if (i < m_sidebarIconsNormal.size())
            item->setIcon(m_sidebarIconsNormal[i]);
    }
}

void BrowserSettingsWidget::onHomepageRadioToggled()
{
    const bool specific = m_radioSpecificUrl->isChecked();
    m_editSpecificUrl->setVisible(specific);
    if (m_lblStartupUrlCaption)
        m_lblStartupUrlCaption->setVisible(specific);
    if (specific)
        m_editSpecificUrl->setFocus(Qt::OtherFocusReason);
}

void BrowserSettingsWidget::onSaveHomepageClicked()
{
    const QString kMsgTitle = QString::fromUtf8("\xe4\xbf\x9d\xe5\xad\x98");
    const QString kOkText = QString::fromUtf8("\xe8\xae\xbe\xe7\xbd\xae\xe5\xb7\xb2\xe4\xbf\x9d\xe5\xad\x98\xe3\x80\x82");
    const QString kFailText = QString::fromUtf8(
        "\xe8\xae\xbe\xe7\xbd\xae\xe4\xbf\x9d\xe5\xad\x98\xe5\xa4\xb1\xe8\xb4\xa5\xef\xbc\x8c\xe8\xaf\xb7\xe6\xa3\x80\xe6\x9f\xa5\xe7\xa3\x81\xe7\x9b\x98\xe6\x9d\x83\xe9\x99\x90\xe6\x88\x96\xe7\xa8\x8d\xe5\x90\x8e\xe9\x87\x8d\xe8\xaf\x95\xe3\x80\x82");
    const QString kNeedUrlText = QString::fromUtf8(
        "\xe8\xaf\xb7\xe5\x85\x88\xe8\xbe\x93\xe5\x85\xa5\xe8\xa6\x81\xe6\x89\x93\xe5\xbc\x80\xe7\x9a\x84\xe7\xbd\x91\xe5\x9d\x80\xe3\x80\x82");
    const QString kBadUrlText = QString::fromUtf8(
        "\xe7\xbd\x91\xe5\x9d\x80\xe6\xa0\xbc\xe5\xbc\x8f\xe6\x97\xa0\xe6\x95\x88\xef\xbc\x8c\xe8\xaf\xb7\xe8\xbe\x93\xe5\x85\xa5\xe5\xa6\x82\x20\x68\x74\x74\x70\x73\x3a\x2f\x2f\x77\x77\x77\x2e\x65\x78\x61\x6d\x70\x6c\x65\x2e\x63\x6f\x6d");

    auto showHomepageDialog = [this](const QString& title, const QString& message) {
        QDialog dlg(this);
        dlg.setObjectName(QStringLiteral("homepageSaveDialog"));
        dlg.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        dlg.setModal(true);
        dlg.resize(400, 262);
        dlg.setStyleSheet(QStringLiteral(
            "QDialog#homepageSaveDialog { background: #FFFFFF; border: 1px solid #000000; border-radius: 10px; }"
            "QWidget#homepageSaveTitleBar { background: #FFFFFF; border: none; border-top-left-radius: 10px; border-top-right-radius: 10px; }"
            "QLabel#homepageSaveTitle { color: #202124; font-size: 18px; font-weight: 600; background: transparent; }"
            "QToolButton#homepageSaveCloseBtn { border: none; background: transparent; color: #5f6368; font-size: 20px; min-width: 28px; max-width: 28px; min-height: 28px; max-height: 28px; }"
            "QToolButton#homepageSaveCloseBtn:hover { background: #F1F3F4; border-radius: 4px; color: #202124; }"
            "QLabel#homepageSaveMessage { color: #5f6368; font-size: 14px; background: transparent; }"
            "QFrame#homepageSaveTopLine, QFrame#homepageSaveBottomLine { border: none; background: #E8EAED; min-height: 1px; max-height: 1px; }"
            "QPushButton#homepageSaveOkBtn { min-width: 56px; max-width: 56px; min-height: 32px; max-height: 32px; border: none; border-radius: 4px; background: #4D8CF5; color: #FFFFFF; font-size: 13px; }"
            "QPushButton#homepageSaveOkBtn:hover { background: #3F7EE8; }"
            "QPushButton#homepageSaveOkBtn:pressed { background: #356FD6; }"));

        auto* rootLay = new QVBoxLayout(&dlg);
        rootLay->setContentsMargins(1, 1, 1, 1);
        rootLay->setSpacing(0);

        auto* titleBar = new QWidget(&dlg);
        titleBar->setObjectName(QStringLiteral("homepageSaveTitleBar"));
        auto* titleLay = new QHBoxLayout(titleBar);
        titleLay->setContentsMargins(20, 12, 12, 10);
        titleLay->setSpacing(8);
        auto* titleLbl = new QLabel(title, titleBar);
        titleLbl->setObjectName(QStringLiteral("homepageSaveTitle"));
        auto* closeBtn = new QToolButton(titleBar);
        closeBtn->setObjectName(QStringLiteral("homepageSaveCloseBtn"));
        closeBtn->setText(QString::fromUtf8("\xc3\x97"));
        closeBtn->setCursor(Qt::PointingHandCursor);
        titleLay->addWidget(titleLbl, 0, Qt::AlignLeft | Qt::AlignVCenter);
        titleLay->addStretch(1);
        titleLay->addWidget(closeBtn, 0, Qt::AlignRight | Qt::AlignVCenter);
        rootLay->addWidget(titleBar, 0);

        auto* topLine = new QFrame(&dlg);
        topLine->setObjectName(QStringLiteral("homepageSaveTopLine"));
        rootLay->addWidget(topLine);

        auto* msgLbl = new QLabel(message, &dlg);
        msgLbl->setObjectName(QStringLiteral("homepageSaveMessage"));
        msgLbl->setWordWrap(true);
        msgLbl->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        rootLay->addSpacing(40);
        auto* messageRow = new QHBoxLayout();
        messageRow->setContentsMargins(40, 0, 20, 0);
        messageRow->addWidget(msgLbl, 1, Qt::AlignLeft | Qt::AlignTop);
        rootLay->addLayout(messageRow);
        rootLay->addStretch(1);

        auto* bottomLine = new QFrame(&dlg);
        bottomLine->setObjectName(QStringLiteral("homepageSaveBottomLine"));
        rootLay->addWidget(bottomLine);

        auto* btnRow = new QHBoxLayout();
        btnRow->setContentsMargins(0, 10, 14, 8);
        btnRow->setSpacing(8);
        auto* btnOk = new QPushButton(QString::fromUtf8("\xe7\xa1\xae\xe5\xae\x9a"), &dlg);
        btnOk->setObjectName(QStringLiteral("homepageSaveOkBtn"));
        btnOk->setCursor(Qt::PointingHandCursor);
        btnRow->addStretch(1);
        btnRow->addWidget(btnOk, 0, Qt::AlignRight | Qt::AlignVCenter);
        rootLay->addLayout(btnRow);

        connect(closeBtn, &QToolButton::clicked, &dlg, &QDialog::reject);
        connect(btnOk, &QPushButton::clicked, &dlg, &QDialog::accept);

        DialogTitleDragFilter dragFilter(&dlg, &dlg);
        titleBar->installEventFilter(&dragFilter);
        titleLbl->installEventFilter(&dragFilter);

        dlg.exec();
    };

    if (m_radioSpecificUrl->isChecked()) {
        const QString urlText = m_editSpecificUrl->text().trimmed();
        if (urlText.isEmpty()) {
            showHomepageDialog(kMsgTitle, kNeedUrlText);
            return;
        }
        const QUrl u = QUrl::fromUserInput(urlText);
        if (!u.isValid()) {
            showHomepageDialog(kMsgTitle, kBadUrlText);
            return;
        }
    }

    QSettings s(QSettings::IniFormat, QSettings::UserScope,
        QStringLiteral("LiteView"), QStringLiteral("LiteViewBrowser"));
    if (m_radioNewTab->isChecked()) {
        s.setValue(QStringLiteral("startup/mode"), 0);
        s.setValue(QStringLiteral("startup/specificUrl"), m_editSpecificUrl->text().trimmed());
    } else {
        s.setValue(QStringLiteral("startup/mode"), 1);
        s.setValue(QStringLiteral("startup/specificUrl"), m_editSpecificUrl->text().trimmed());
    }
    s.sync();
    if (s.status() != QSettings::NoError) {
        showHomepageDialog(kMsgTitle, kFailText);
        return;
    }
    showHomepageDialog(kMsgTitle, kOkText);
    emit startupSettingsSaved();
}

static QString chineseWeekdayName(int dayOfWeek)
{
    // QDate::dayOfWeek：1=周一 … 7=周日；用 UTF-8 显式拼接，避免 QLocale::toString + 含中文的格式串在 MSVC 下乱码
    switch (dayOfWeek) {
    case 1:
        return QString::fromUtf8("\xe6\x98\x9f\xe6\x9c\x9f\xe4\xb8\x80");
    case 2:
        return QString::fromUtf8("\xe6\x98\x9f\xe6\x9c\x9f\xe4\xba\x8c");
    case 3:
        return QString::fromUtf8("\xe6\x98\x9f\xe6\x9c\x9f\xe4\xb8\x89");
    case 4:
        return QString::fromUtf8("\xe6\x98\x9f\xe6\x9c\x9f\xe5\x9b\x9b");
    case 5:
        return QString::fromUtf8("\xe6\x98\x9f\xe6\x9c\x9f\xe4\xba\x94");
    case 6:
        return QString::fromUtf8("\xe6\x98\x9f\xe6\x9c\x9f\xe5\x85\xad");
    case 7:
        return QString::fromUtf8("\xe6\x98\x9f\xe6\x9c\x9f\xe6\x97\xa5");
    default:
        return QString();
    }
}

QString BrowserSettingsWidget::formatHistoryDateHeader(const QDate& d) const
{
    const QDate today = QDate::currentDate();
    const QString core = QString::number(d.year()) + QString::fromUtf8("\xe5\xb9\xb4")
        + QString::number(d.month()) + QString::fromUtf8("\xe6\x9c\x88") + QString::number(d.day())
        + QString::fromUtf8("\xe6\x97\xa5") + QLatin1Char(' ') + chineseWeekdayName(d.dayOfWeek());
    if (d == today)
        return QString::fromUtf8("\xe4\xbb\x8a\xe5\xa4\xa9 - ") + core;
    return core;
}

void BrowserSettingsWidget::addHistoryRow(int storeIndex, const HistoryEntry& e)
{
    auto* row = new HistoryRowFrame(m_historyContentWidget);
    row->setObjectName(QStringLiteral("historyRow"));
    row->setStyleSheet(QStringLiteral(
        "QFrame#historyRow { border-bottom: 1px solid #e8eaed; background: #F7F9FC; }"));

    auto* mainRow = new QHBoxLayout(row);
    mainRow->setContentsMargins(14, 12, 12, 12);
    mainRow->setSpacing(14);

    auto* leftCol = new QVBoxLayout();
    leftCol->setSpacing(4);
    leftCol->setContentsMargins(0, 0, 0, 0);

    const QString titleText = e.title.isEmpty() ? e.url : e.title;
    auto* titleLb = new QLabel(row);
    titleLb->setText(QString(QStringLiteral("<a href=\"%1\" style=\"color:#1a0dab; text-decoration:none;\">%2</a>"))
        .arg(QString(e.url).toHtmlEscaped(), QString(titleText).toHtmlEscaped()));
    titleLb->setTextFormat(Qt::RichText);
    titleLb->setOpenExternalLinks(false);
    titleLb->setTextInteractionFlags(Qt::LinksAccessibleByMouse);
    titleLb->setStyleSheet(QStringLiteral("QLabel { color: #191919; font-size: 14px; font-weight: 400; }"));
    connect(titleLb, &QLabel::linkActivated, this, [this](const QString& link) {
        emit openUrlRequested(link);
    });

    auto* urlLb = new QLabel(e.url, row);
    urlLb->setStyleSheet(QStringLiteral("color: #606162; font-size: 12px; font-weight: 400;"));
    urlLb->setWordWrap(true);

    leftCol->addWidget(titleLb);
    leftCol->addWidget(urlLb);
    mainRow->addLayout(leftCol, 1);

    auto* timeLb = new QLabel(e.visited.toString(QStringLiteral("HH:mm")), row);
    timeLb->setStyleSheet(QStringLiteral("color: #606162; font-size: 12px; font-weight: 400;"));
    timeLb->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
    mainRow->addWidget(timeLb, 0, Qt::AlignRight | Qt::AlignVCenter);

    auto* delBtn = new QToolButton(row);
    row->delBtn = delBtn;
    delBtn->setText(QString::fromUtf8("\xc3\x97"));
    delBtn->setVisible(false);
    delBtn->setCursor(Qt::PointingHandCursor);
    delBtn->setFixedSize(28, 28);
    delBtn->setStyleSheet(QStringLiteral(
        "QToolButton { border: none; color: #5f6368; font-size: 19px; font-weight: bold; }"
        "QToolButton:hover { color: #202124; background: #e8eaed; border-radius: 4px; }"));
    connect(delBtn, &QToolButton::clicked, this, [storeIndex]() {
        BrowserHistoryStore::instance()->removeAt(storeIndex);
    });
    mainRow->addWidget(delBtn, 0, Qt::AlignRight | Qt::AlignVCenter);

    m_historyListLayout->addWidget(row);
}

void BrowserSettingsWidget::refreshHistoryView()
{
    if (!m_historyListLayout)
        return;
    QLayoutItem* child;
    while ((child = m_historyListLayout->takeAt(0)) != nullptr) {
        if (child->widget())
            delete child->widget();
        delete child;
    }

    const QVector<QPair<int, HistoryEntry>> filtered = BrowserHistoryStore::instance()->entriesFilteredWithIndex(m_historySearchEdit->text());
    if (filtered.isEmpty()) {
        auto* empty = new QLabel(QString::fromUtf8("\xe6\x9a\x82\xe6\x97\xa0\xe5\x8e\x86\xe5\x8f\xb2\xe8\xae\xb0\xe5\xbd\x95"), m_historyContentWidget);
        empty->setStyleSheet(QStringLiteral("color: #5f6368; padding: 16px;"));
        m_historyListLayout->addWidget(empty);
        m_historyListLayout->addStretch();
        return;
    }

    QDate lastDate;
    bool first = true;
    for (const QPair<int, HistoryEntry>& p : filtered) {
        const QDate d = p.second.visited.date();
        if (first || d != lastDate) {
            first = false;
            lastDate = d;
            auto* hdr = new QFrame(m_historyContentWidget);
            hdr->setStyleSheet(QStringLiteral("background: #F7F9FC; border: none;"));
            auto* hl = new QHBoxLayout(hdr);
            hl->setContentsMargins(12, 8, 12, 8);
            auto* lbl = new QLabel(formatHistoryDateHeader(d));
            lbl->setStyleSheet(QStringLiteral("color: #606162; font-size: 12px; font-weight: 400;"));
            hl->addWidget(lbl);
            m_historyListLayout->addWidget(hdr);
        }
        addHistoryRow(p.first, p.second);
    }
    m_historyListLayout->addStretch();
}

void BrowserSettingsWidget::onHistorySearchChanged(const QString& text)
{
    Q_UNUSED(text);
    refreshHistoryView();
}

void BrowserSettingsWidget::onHistoryStoreChanged()
{
    refreshHistoryView();
}

void BrowserSettingsWidget::onClearHistoryClicked()
{
    const QString kTitle = QString::fromUtf8("\xe6\xb8\x85\xe9\x99\xa4\xe5\x8e\x86\xe5\x8f\xb2\xe8\xae\xb0\xe5\xbd\x95");
    const int historyCount = BrowserHistoryStore::instance()->entriesFilteredWithIndex(QString()).size();
    const QString kText = QString::fromUtf8(
                              "\xe8\xaf\xb7\xe9\x97\xae\xe8\xa6\x81\xe6\xb8\x85\xe9\x99\xa4%1\xe9\xa1\xb9\xe5\x8e\x86\xe5\x8f\xb2\xe7\xba\xaa\xe5\xbd\x95\xe5\x90\x97\xef\xbc\x9f\xe6\xb8\x85\xe9\x99\xa4\xe5\x90\x8e\xe5\xb0\x86\xe6\x97\xa0\xe6\xb3\x95\xe6\x9f\xa5\xe7\x9c\x8b\xe8\xaf\xa5\xe8\xae\xb0\xe5\xbd\x95\xe3\x80\x82")
                              .arg(historyCount);

    QDialog dlg(this);
    dlg.setObjectName(QStringLiteral("clearHistoryConfirmDialog"));
    dlg.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
    dlg.setModal(true);
    dlg.resize(500, 262);
    dlg.setStyleSheet(QStringLiteral(
        "QDialog#clearHistoryConfirmDialog { background: #FFFFFF; border: 1px solid #000000; border-radius: 10px; }"
        "QWidget#clearHistoryTitleBar { background: #FFFFFF; border: none; border-top-left-radius: 10px; border-top-right-radius: 10px; }"
        "QLabel#clearHistoryTitle { color: #202124; font-size: 18px; font-weight: 600; background: transparent; }"
        "QToolButton#clearHistoryCloseBtn { border: none; background: transparent; color: #5f6368; font-size: 20px; min-width: 28px; max-width: 28px; min-height: 28px; max-height: 28px; }"
        "QToolButton#clearHistoryCloseBtn:hover { background: #F1F3F4; border-radius: 4px; color: #202124; }"
        "QLabel#clearHistoryMessage { color: #5f6368; font-size: 14px; background: transparent; }"
        "QFrame#clearHistoryTopLine { border: none; background: #E8EAED; min-height: 1px; max-height: 1px; }"
        "QFrame#clearHistoryBottomLine { border: none; background: #E8EAED; min-height: 1px; max-height: 1px; }"
        "QPushButton#clearHistoryCancelBtn { min-width: 56px; max-width: 56px; min-height: 32px; max-height: 32px; border: 1px solid #DADCE0; border-radius: 4px; background: #FFFFFF; color: #5f6368; font-size: 13px; }"
        "QPushButton#clearHistoryCancelBtn:hover { background: #F7F8FA; }"
        "QPushButton#clearHistoryConfirmBtn { min-width: 56px; max-width: 56px; min-height: 32px; max-height: 32px; border: none; border-radius: 4px; background: #4D8CF5; color: #FFFFFF; font-size: 13px; }"
        "QPushButton#clearHistoryConfirmBtn:hover { background: #3F7EE8; }"
        "QPushButton#clearHistoryConfirmBtn:pressed { background: #356FD6; }"));

    auto* rootLay = new QVBoxLayout(&dlg);
    /* 内容内缩 1px，避免子控件覆盖外层黑色边框与圆角 */
    rootLay->setContentsMargins(1, 1, 1, 1);
    rootLay->setSpacing(0);

    auto* titleBar = new QWidget(&dlg);
    titleBar->setObjectName(QStringLiteral("clearHistoryTitleBar"));
    auto* titleLay = new QHBoxLayout(titleBar);
    titleLay->setContentsMargins(20, 12, 12, 10);
    titleLay->setSpacing(8);
    auto* titleLbl = new QLabel(kTitle, titleBar);
    titleLbl->setObjectName(QStringLiteral("clearHistoryTitle"));
    auto* closeBtn = new QToolButton(titleBar);
    closeBtn->setObjectName(QStringLiteral("clearHistoryCloseBtn"));
    closeBtn->setText(QString::fromUtf8("\xc3\x97"));
    closeBtn->setCursor(Qt::PointingHandCursor);
    titleLay->addWidget(titleLbl, 0, Qt::AlignLeft | Qt::AlignVCenter);
    titleLay->addStretch(1);
    titleLay->addWidget(closeBtn, 0, Qt::AlignRight | Qt::AlignVCenter);
    rootLay->addWidget(titleBar, 0);

    auto* topLine = new QFrame(&dlg);
    topLine->setObjectName(QStringLiteral("clearHistoryTopLine"));
    rootLay->addWidget(topLine);

    auto* msgLbl = new QLabel(kText, &dlg);
    msgLbl->setObjectName(QStringLiteral("clearHistoryMessage"));
    msgLbl->setWordWrap(false);
    msgLbl->setAlignment(Qt::AlignLeft | Qt::AlignTop);
    msgLbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    rootLay->addSpacing(40);
    auto* messageRow = new QHBoxLayout();
    messageRow->setContentsMargins(40, 0, 20, 0);
    messageRow->addWidget(msgLbl, 1);
    rootLay->addLayout(messageRow);
    rootLay->addStretch(1);

    auto* bottomLine = new QFrame(&dlg);
    bottomLine->setObjectName(QStringLiteral("clearHistoryBottomLine"));
    rootLay->addWidget(bottomLine);

    auto* btnRow = new QHBoxLayout();
    btnRow->setContentsMargins(0, 10, 14, 8);
    btnRow->setSpacing(8);
    auto* btnCancel = new QPushButton(QString::fromUtf8("\xe5\x8f\x96\xe6\xb6\x88"), &dlg);
    btnCancel->setObjectName(QStringLiteral("clearHistoryCancelBtn"));
    btnCancel->setCursor(Qt::PointingHandCursor);
    auto* btnConfirm = new QPushButton(QString::fromUtf8("\xe7\xa1\xae\xe8\xae\xa4"), &dlg);
    btnConfirm->setObjectName(QStringLiteral("clearHistoryConfirmBtn"));
    btnConfirm->setCursor(Qt::PointingHandCursor);
    btnRow->addStretch(1);
    btnRow->addWidget(btnCancel, 0, Qt::AlignRight | Qt::AlignVCenter);
    btnRow->addWidget(btnConfirm, 0, Qt::AlignRight | Qt::AlignVCenter);
    rootLay->addLayout(btnRow);

    connect(closeBtn, &QToolButton::clicked, &dlg, &QDialog::reject);
    connect(btnCancel, &QPushButton::clicked, &dlg, &QDialog::reject);
    connect(btnConfirm, &QPushButton::clicked, &dlg, &QDialog::accept);

    DialogTitleDragFilter dragFilter(&dlg, &dlg);
    titleBar->installEventFilter(&dragFilter);
    titleLbl->installEventFilter(&dragFilter);

    if (dlg.exec() != QDialog::Accepted)
        return;
    BrowserHistoryStore::instance()->clear();
}

QString BrowserSettingsWidget::downloadSavePath()
{
    static QMutex s_downloadPathSettingsMutex;
    QMutexLocker locker(&s_downloadPathSettingsMutex);
    QSettings s(QSettings::IniFormat, QSettings::UserScope,
        QStringLiteral("LiteView"), QStringLiteral("LiteViewBrowser"));
    QString def = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation);
    if (def.isEmpty())
        def = QDir::cleanPath(QDir::homePath() + QStringLiteral("/Downloads"));
    QString p = s.value(QStringLiteral("downloads/savePath"), def).toString().trimmed();
    if (p.isEmpty())
        p = def;
    return QDir::cleanPath(p);
}

void BrowserSettingsWidget::loadDownloadSettings()
{
    if (!m_downloadPathLabel)
        return;
    const QString p = downloadSavePath();
    m_downloadPathLabel->setText(QDir::toNativeSeparators(p));
}

void BrowserSettingsWidget::onChangeDownloadPathClicked()
{
    const QString startDir = downloadSavePath();
    const QString caption = QString::fromUtf8("\xe9\x80\x89\xe6\x8b\xa9\xe4\xb8\x8b\xe8\xbd\xbd\xe7\x9b\xae\xe5\xbd\x95");
    const QString dir = QFileDialog::getExistingDirectory(this, caption, startDir,
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (dir.isEmpty())
        return;

    const QString cleaned = QDir::cleanPath(dir);
    QSettings s(QSettings::IniFormat, QSettings::UserScope,
        QStringLiteral("LiteView"), QStringLiteral("LiteViewBrowser"));
    s.setValue(QStringLiteral("downloads/savePath"), cleaned);
    s.sync();

    if (m_downloadPathLabel)
        m_downloadPathLabel->setText(QDir::toNativeSeparators(cleaned));
}

void BrowserSettingsWidget::onClearBrowsingDataClicked()
{
    const bool wantInput = m_chkClearInputHistory && m_chkClearInputHistory->isChecked();
    const bool wantBrowse = m_chkClearBrowseHistory && m_chkClearBrowseHistory->isChecked();
    const bool wantCache = m_chkClearWebCache && m_chkClearWebCache->isChecked();
    const bool wantCookie = m_chkClearCookies && m_chkClearCookies->isChecked();
    const QString kDlgTitle = QString::fromUtf8("\xe6\xb8\x85\xe9\x99\xa4\xe6\xb5\x8f\xe8\xa7\x88\xe6\x95\xb0\xe6\x8d\xae");

    auto showClearDataDialog = [this](const QString& title, const QString& message) {
        QDialog dlg(this);
        dlg.setObjectName(QStringLiteral("clearDataDialog"));
        dlg.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        dlg.setModal(true);

        QFont msgFont;
        msgFont.setPixelSize(14);
        QFontMetrics msgFm(msgFont);
        const int msgWidth = msgFm.width(message);
        const int dialogWidth = qMax(320, qMin(520, msgWidth + 40 + 20 + 2));
        dlg.resize(dialogWidth, 262);

        dlg.setStyleSheet(QStringLiteral(
            "QDialog#clearDataDialog { background: #FFFFFF; border: 1px solid #000000; border-radius: 10px; }"
            "QWidget#clearDataTitleBar { background: #FFFFFF; border: none; border-top-left-radius: 10px; border-top-right-radius: 10px; }"
            "QLabel#clearDataTitle { color: #202124; font-size: 18px; font-weight: 600; background: transparent; }"
            "QToolButton#clearDataCloseBtn { border: none; background: transparent; color: #5f6368; font-size: 20px; min-width: 28px; max-width: 28px; min-height: 28px; max-height: 28px; }"
            "QToolButton#clearDataCloseBtn:hover { background: #F1F3F4; border-radius: 4px; color: #202124; }"
            "QLabel#clearDataMessage { color: #5f6368; font-size: 14px; background: transparent; }"
            "QFrame#clearDataTopLine, QFrame#clearDataBottomLine { border: none; background: #E8EAED; min-height: 1px; max-height: 1px; }"
            "QPushButton#clearDataOkBtn { min-width: 56px; max-width: 56px; min-height: 32px; max-height: 32px; border: none; border-radius: 4px; background: #4D8CF5; color: #FFFFFF; font-size: 13px; }"
            "QPushButton#clearDataOkBtn:hover { background: #3F7EE8; }"
            "QPushButton#clearDataOkBtn:pressed { background: #356FD6; }"));

        auto* rootLay = new QVBoxLayout(&dlg);
        rootLay->setContentsMargins(1, 1, 1, 1);
        rootLay->setSpacing(0);

        auto* titleBar = new QWidget(&dlg);
        titleBar->setObjectName(QStringLiteral("clearDataTitleBar"));
        auto* titleLay = new QHBoxLayout(titleBar);
        titleLay->setContentsMargins(20, 12, 12, 10);
        titleLay->setSpacing(8);
        auto* titleLbl = new QLabel(title, titleBar);
        titleLbl->setObjectName(QStringLiteral("clearDataTitle"));
        auto* closeBtn = new QToolButton(titleBar);
        closeBtn->setObjectName(QStringLiteral("clearDataCloseBtn"));
        closeBtn->setText(QString::fromUtf8("\xc3\x97"));
        closeBtn->setCursor(Qt::PointingHandCursor);
        titleLay->addWidget(titleLbl, 0, Qt::AlignLeft | Qt::AlignVCenter);
        titleLay->addStretch(1);
        titleLay->addWidget(closeBtn, 0, Qt::AlignRight | Qt::AlignVCenter);
        rootLay->addWidget(titleBar, 0);

        auto* topLine = new QFrame(&dlg);
        topLine->setObjectName(QStringLiteral("clearDataTopLine"));
        rootLay->addWidget(topLine);

        auto* msgLbl = new QLabel(message, &dlg);
        msgLbl->setObjectName(QStringLiteral("clearDataMessage"));
        msgLbl->setWordWrap(false);
        msgLbl->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        msgLbl->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        rootLay->addSpacing(40);
        auto* messageRow = new QHBoxLayout();
        messageRow->setContentsMargins(40, 0, 20, 0);
        messageRow->addWidget(msgLbl, 1);
        rootLay->addLayout(messageRow);
        rootLay->addStretch(1);

        auto* bottomLine = new QFrame(&dlg);
        bottomLine->setObjectName(QStringLiteral("clearDataBottomLine"));
        rootLay->addWidget(bottomLine);

        auto* btnRow = new QHBoxLayout();
        btnRow->setContentsMargins(0, 10, 14, 8);
        auto* btnOk = new QPushButton(QString::fromUtf8("\xe7\xa1\xae\xe5\xae\x9a"), &dlg);
        btnOk->setObjectName(QStringLiteral("clearDataOkBtn"));
        btnOk->setCursor(Qt::PointingHandCursor);
        btnRow->addStretch(1);
        btnRow->addWidget(btnOk, 0, Qt::AlignRight | Qt::AlignVCenter);
        rootLay->addLayout(btnRow);

        connect(closeBtn, &QToolButton::clicked, &dlg, &QDialog::reject);
        connect(btnOk, &QPushButton::clicked, &dlg, &QDialog::accept);

        DialogTitleDragFilter dragFilter(&dlg, &dlg);
        titleBar->installEventFilter(&dragFilter);
        titleLbl->installEventFilter(&dragFilter);

        dlg.exec();
    };

    auto showClearDataConfirmDialog = [this](const QString& title, const QString& message) -> bool {
        QDialog dlg(this);
        dlg.setObjectName(QStringLiteral("clearDataConfirmDialog"));
        dlg.setWindowFlags(Qt::Dialog | Qt::FramelessWindowHint);
        dlg.setModal(true);
        dlg.resize(500, 262);
        dlg.setStyleSheet(QStringLiteral(
            "QDialog#clearDataConfirmDialog { background: #FFFFFF; border: 1px solid #000000; border-radius: 10px; }"
            "QWidget#clearDataConfirmTitleBar { background: #FFFFFF; border: none; border-top-left-radius: 10px; border-top-right-radius: 10px; }"
            "QLabel#clearDataConfirmTitle { color: #202124; font-size: 18px; font-weight: 600; background: transparent; }"
            "QToolButton#clearDataConfirmCloseBtn { border: none; background: transparent; color: #5f6368; font-size: 20px; min-width: 28px; max-width: 28px; min-height: 28px; max-height: 28px; }"
            "QToolButton#clearDataConfirmCloseBtn:hover { background: #F1F3F4; border-radius: 4px; color: #202124; }"
            "QLabel#clearDataConfirmMessage { color: #5f6368; font-size: 14px; background: transparent; }"
            "QFrame#clearDataConfirmTopLine, QFrame#clearDataConfirmBottomLine { border: none; background: #E8EAED; min-height: 1px; max-height: 1px; }"
            "QPushButton#clearDataConfirmCancelBtn { min-width: 56px; max-width: 56px; min-height: 32px; max-height: 32px; border: 1px solid #DADCE0; border-radius: 4px; background: #FFFFFF; color: #5f6368; font-size: 13px; }"
            "QPushButton#clearDataConfirmCancelBtn:hover { background: #F7F8FA; }"
            "QPushButton#clearDataConfirmOkBtn { min-width: 56px; max-width: 56px; min-height: 32px; max-height: 32px; border: none; border-radius: 4px; background: #4D8CF5; color: #FFFFFF; font-size: 13px; }"
            "QPushButton#clearDataConfirmOkBtn:hover { background: #3F7EE8; }"
            "QPushButton#clearDataConfirmOkBtn:pressed { background: #356FD6; }"));

        auto* rootLay = new QVBoxLayout(&dlg);
        rootLay->setContentsMargins(1, 1, 1, 1);
        rootLay->setSpacing(0);

        auto* titleBar = new QWidget(&dlg);
        titleBar->setObjectName(QStringLiteral("clearDataConfirmTitleBar"));
        auto* titleLay = new QHBoxLayout(titleBar);
        titleLay->setContentsMargins(20, 12, 12, 10);
        auto* titleLbl = new QLabel(title, titleBar);
        titleLbl->setObjectName(QStringLiteral("clearDataConfirmTitle"));
        auto* closeBtn = new QToolButton(titleBar);
        closeBtn->setObjectName(QStringLiteral("clearDataConfirmCloseBtn"));
        closeBtn->setText(QString::fromUtf8("\xc3\x97"));
        closeBtn->setCursor(Qt::PointingHandCursor);
        titleLay->addWidget(titleLbl, 0, Qt::AlignLeft | Qt::AlignVCenter);
        titleLay->addStretch(1);
        titleLay->addWidget(closeBtn, 0, Qt::AlignRight | Qt::AlignVCenter);
        rootLay->addWidget(titleBar);

        auto* topLine = new QFrame(&dlg);
        topLine->setObjectName(QStringLiteral("clearDataConfirmTopLine"));
        rootLay->addWidget(topLine);

        auto* msgLbl = new QLabel(message, &dlg);
        msgLbl->setObjectName(QStringLiteral("clearDataConfirmMessage"));
        msgLbl->setWordWrap(false);
        msgLbl->setAlignment(Qt::AlignLeft | Qt::AlignTop);
        rootLay->addSpacing(40);
        auto* messageRow = new QHBoxLayout();
        messageRow->setContentsMargins(40, 0, 20, 0);
        messageRow->addWidget(msgLbl, 1);
        rootLay->addLayout(messageRow);
        rootLay->addStretch(1);

        auto* bottomLine = new QFrame(&dlg);
        bottomLine->setObjectName(QStringLiteral("clearDataConfirmBottomLine"));
        rootLay->addWidget(bottomLine);

        auto* btnRow = new QHBoxLayout();
        btnRow->setContentsMargins(0, 10, 14, 8);
        btnRow->setSpacing(8);
        auto* btnCancel = new QPushButton(QString::fromUtf8("\xe5\x8f\x96\xe6\xb6\x88"), &dlg);
        btnCancel->setObjectName(QStringLiteral("clearDataConfirmCancelBtn"));
        btnCancel->setCursor(Qt::PointingHandCursor);
        auto* btnConfirm = new QPushButton(QString::fromUtf8("\xe7\xa1\xae\xe8\xae\xa4"), &dlg);
        btnConfirm->setObjectName(QStringLiteral("clearDataConfirmOkBtn"));
        btnConfirm->setCursor(Qt::PointingHandCursor);
        btnRow->addStretch(1);
        btnRow->addWidget(btnCancel, 0, Qt::AlignRight | Qt::AlignVCenter);
        btnRow->addWidget(btnConfirm, 0, Qt::AlignRight | Qt::AlignVCenter);
        rootLay->addLayout(btnRow);

        connect(closeBtn, &QToolButton::clicked, &dlg, &QDialog::reject);
        connect(btnCancel, &QPushButton::clicked, &dlg, &QDialog::reject);
        connect(btnConfirm, &QPushButton::clicked, &dlg, &QDialog::accept);

        DialogTitleDragFilter dragFilter(&dlg, &dlg);
        titleBar->installEventFilter(&dragFilter);
        titleLbl->installEventFilter(&dragFilter);

        return dlg.exec() == QDialog::Accepted;
    };

    if (!wantInput && !wantBrowse && !wantCache && !wantCookie) {
        showClearDataDialog(kDlgTitle,
            QString::fromUtf8("\xe8\xaf\xb7\xe8\x87\xb3\xe5\xb0\x91\xe9\x80\x89\xe6\x8b\xa9\xe4\xb8\x80\xe9\xa1\xb9\xe3\x80\x82"));
        return;
    }

    if (!showClearDataConfirmDialog(kDlgTitle,
            QString::fromUtf8("\xe8\xaf\xb7\xe9\x97\xae\xe8\xa6\x81\xe6\xb8\x85\xe9\x99\xa4\xe6\xb5\x8f\xe8\xa7\x88\xe8\xae\xb0\xe5\xbd\x95\xe5\x90\x97\xef\xbc\x9f")))
        return;

    if (wantInput)
        AddressInputHistoryStore::instance()->clear();
    if (wantBrowse)
        BrowserHistoryStore::instance()->clear();
    if (auto* mw = qobject_cast<Widget*>(window())) {
        if (wantCache)
            mw->clearMiniBlinkStorageOnAllWebTabs(2);
        if (wantCookie)
            mw->clearMiniBlinkCookiesOnAllWebTabs();
    }
    showClearDataDialog(kDlgTitle,
        QString::fromUtf8("\xe5\xb7\xb2\xe6\x8c\x89\xe6\x89\x80\xe9\x80\x89\xe9\xa1\xb9\xe7\x9b\xae\xe5\xae\x8c\xe6\x88\x90\xe6\xb8\x85\xe9\x99\xa4\xe3\x80\x82"));
}

// --- BrowserHistoryStore 实现（并入 widget.cpp，避免单独 .cpp 未加入工程导致 LNK2019）---

BrowserHistoryStore* BrowserHistoryStore::s_instance = nullptr;

BrowserHistoryStore::BrowserHistoryStore(QObject* parent)
    : QObject(parent)
{
    loadFromDisk();
}

BrowserHistoryStore* BrowserHistoryStore::instance()
{
    if (!s_instance)
        s_instance = new BrowserHistoryStore(qApp);
    return s_instance;
}

void BrowserHistoryStore::loadFromDisk()
{
    m_entries.clear();
    QFile f(browserHistoryFilePath());
    if (!f.open(QIODevice::ReadOnly))
        return;
    const QByteArray data = f.readAll();
    f.close();
    QJsonParseError err;
    const QJsonDocument doc = QJsonDocument::fromJson(data, &err);
    if (err.error != QJsonParseError::NoError || !doc.isArray())
        return;
    const QJsonArray arr = doc.array();
    for (const QJsonValue& v : arr) {
        if (!v.isObject())
            continue;
        const QJsonObject o = v.toObject();
        HistoryEntry e;
        e.title = o.value(QStringLiteral("title")).toString();
        e.url = o.value(QStringLiteral("url")).toString();
        e.visited = QDateTime::fromString(o.value(QStringLiteral("visited")).toString(), Qt::ISODate);
        if (e.url.isEmpty())
            continue;
        if (!e.visited.isValid())
            e.visited = QDateTime::currentDateTime();
        m_entries.append(e);
    }
}

void BrowserHistoryStore::saveToDisk() const
{
    QJsonArray arr;
    for (const HistoryEntry& e : m_entries) {
        QJsonObject o;
        o.insert(QStringLiteral("title"), e.title);
        o.insert(QStringLiteral("url"), e.url);
        o.insert(QStringLiteral("visited"), e.visited.toString(Qt::ISODate));
        arr.append(o);
    }
    const QString path = browserHistoryFilePath();
    QDir().mkpath(QFileInfo(path).absolutePath());
    QFile f(path);
    if (!f.open(QIODevice::WriteOnly | QIODevice::Truncate))
        return;
    f.write(QJsonDocument(arr).toJson(QJsonDocument::Compact));
    f.close();
}

void BrowserHistoryStore::addVisit(const QString& url, const QString& title)
{
    QString u = url.trimmed();
    if (u.isEmpty())
        return;
    QUrl qu(u);
    if (qu.scheme().isEmpty())
        qu = QUrl::fromUserInput(u);
    const QString scheme = qu.scheme().toLower();
    if (scheme != QStringLiteral("http") && scheme != QStringLiteral("https"))
        return;
    u = qu.toString(QUrl::RemovePassword);

    const QString t = title.trimmed().isEmpty() ? u : title.trimmed();
    const QDateTime now = QDateTime::currentDateTime();
    /* 防抖与 loadFinished 可能连续提交时合并；短间隔内同 URL 视为同一次导航 */
    if (!m_entries.isEmpty()) {
        const HistoryEntry& last = m_entries.first();
        if (last.url == u) {
            const qint64 dt = last.visited.msecsTo(now);
            if (dt >= 0 && dt < 3200)
                return;
        }
    }

    HistoryEntry e;
    e.url = u;
    e.title = t;
    e.visited = now;
    m_entries.prepend(e);
    const int kMax = 5000;
    if (m_entries.size() > kMax)
        m_entries.resize(kMax);
    saveToDisk();
    emit changed();
}

void BrowserHistoryStore::removeAt(int index)
{
    if (index < 0 || index >= m_entries.size())
        return;
    m_entries.removeAt(index);
    saveToDisk();
    emit changed();
}

void BrowserHistoryStore::clear()
{
    m_entries.clear();
    saveToDisk();
    emit changed();
}

QVector<QPair<int, HistoryEntry>> BrowserHistoryStore::entriesFilteredWithIndex(const QString& searchText) const
{
    const QString needle = searchText.trimmed().toLower();
    QVector<QPair<int, HistoryEntry>> out;
    for (int i = 0; i < m_entries.size(); ++i) {
        const HistoryEntry& e = m_entries.at(i);
        if (needle.isEmpty()) {
            out.append(qMakePair(i, e));
            continue;
        }
        if (e.title.toLower().contains(needle) || e.url.toLower().contains(needle))
            out.append(qMakePair(i, e));
    }
    return out;
}
