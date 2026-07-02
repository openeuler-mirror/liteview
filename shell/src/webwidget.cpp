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

#include "webwidget.h"
#include "faviconcache.h"
#include "browsersettingswidget.h"
#include "widget.h"
#include <QHBoxLayout>
#include <QDebug>
#include <QPainter>
#include <QMenu>
#include <QContextMenuEvent>
#include <QMessageBox>
#include <QMetaObject>
#include <QFocusEvent>
#include <QSizePolicy>
#include <QTimer>
#include <QShowEvent>
#include <QAction>
#include <QStyle>
#include <QApplication>
#include <QCoreApplication>
#include <QLineEdit>
#include <QDir>
#include <QFileInfo>
#include <QRegularExpression>
#include <QPainterPath>
#include <QImage>
#include <QPixmap>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QSslSocket>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QClipboard>
#include <QMimeData>
#include <QGuiApplication>
#include <QDateTime>
#include <QDesktopServices>
#include <QKeyEvent>
#include <QInputMethodEvent>
#include <QInputMethod>
#include <QMutex>
#include <QMutexLocker>
#include <QHash>
#include <QSet>
#include <QPointer>
#include <functional>
#include <memory>
#include <limits>
#include <QtGlobal>
#ifdef Q_OS_WIN
#include <windows.h>
#endif

#ifdef QT_DEBUG
#define FAVICON_LOG() qDebug()
#else
#define FAVICON_LOG() QNoDebug()
#endif

/* 定义 LITEVIEW_FORCE_CONTEXT_MENU_LOG 后，Release 也会打印右键回调诊断（用完可删宏） */
#if defined(QT_DEBUG) || defined(LITEVIEW_FORCE_CONTEXT_MENU_LOG)
#  define LITEVIEW_CTXMENU_LOG(x) qDebug().noquote() << x
#else
#  define LITEVIEW_CTXMENU_LOG(x) static_cast<void>(0)
#endif

#if defined(MB_SELECTANY_NO_DEF)

MB_FOR_EACH_DEFINE_FUNCTION(MB_DEFINE_ITERATOR0, MB_DEFINE_ITERATOR1, MB_DEFINE_ITERATOR2, \
    MB_DEFINE_ITERATOR3, MB_DEFINE_ITERATOR4, MB_DEFINE_ITERATOR5, MB_DEFINE_ITERATOR6, MB_DEFINE_ITERATOR7, MB_DEFINE_ITERATOR8, MB_DEFINE_ITERATOR9, MB_DEFINE_ITERATOR10, MB_DEFINE_ITERATOR11)

#endif

static void MB_CALL_TYPE onPaintBitUpdatedCallback(mbWebView webView, void* param, const void* buffer, const mbRect* r, int width, int height);
// Keep signature consistent with friend declarations in webwidget.h.
void MB_CALL_TYPE onUrlChangedCallback(mbWebView webView, void* param, const utf8* url, BOOL canGoBack, BOOL canGoForward);
void MB_CALL_TYPE onTitleChangedCallback(mbWebView webView, void* param, const utf8* title);
void MB_CALL_TYPE onLoadingFinishCallback(mbWebView webView, void* param, mbWebFrameHandle frameId, const utf8* url, mbLoadingResult result, const utf8* failedReason);
void MB_CALL_TYPE onDocumentReadyCallback(mbWebView webView, void* param, mbWebFrameHandle frameId);
void MB_CALL_TYPE onJsQueryCallback(mbWebView webView, void* param, mbJsExecState es, int64_t queryId, int customMsg, const utf8* request);
void MB_CALL_TYPE onNetGetFaviconCallback(mbWebView webView, void* param, const utf8* url, mbMemBuf* buf);
mbDownloadOpt MB_CALL_TYPE onDownloadInBlinkThreadCallback(
    mbWebView webView,
    void* param,
    size_t expectedContentLength,
    const char* url,
    const char* mime,
    const char* disposition,
    mbNetJob job,
    mbNetJobDataBind* dataBind);
void MB_CALL_TYPE onDownloadDataRecvCallback(void* ptr, mbNetJob job, const char* data, int length);
void MB_CALL_TYPE onDownloadDataFinishCallback(void* ptr, mbNetJob job, mbLoadingResult result);

struct DownloadProgressContext {
    WebWidget* self = nullptr;
    QString url;
    QString savePath;
    qint64 totalBytes = 0;
    qint64 receivedBytes = 0;
    mbNetJob job = nullptr;
};

QMutex g_downloadJobMapMutex;
QHash<QString, mbNetJob> g_downloadJobByPath;
QSet<QString> g_cancelRequestedPaths;
/* miniblink 内部 SimpleDownload 等对并发进入较敏感，串行化 mbDownloadByUtf8Path 避免多任务同时失败 */
static QMutex g_mbDownloadByUtf8PathMutex;

static mbDownloadOptions mbDownloadByUtf8PathOptions()
{
    mbDownloadOptions o;
    o.magic = static_cast<int>('mbdo');
    o.saveAsPathAndName = TRUE;
    return o;
}

// miniblink utf8* is UTF-8; avoid fromLocal8Bit to prevent mojibake.
static QString mbUtf8(const utf8* s)
{
    if (!s)
        return QString();
    return QString::fromUtf8(reinterpret_cast<const char*>(s));
}

struct MbBlinkEvalPack {
    mbWebView view = 0; /* mbWebView 为整型句柄，非指针 */
    mbWebFrameHandle frame = nullptr;
    const char* script = nullptr;
    QByteArray scriptOwned;
    QString result;
};

static void MB_CALL_TYPE blinkEvalJsThunk(void* param1, void* param2)
{
    Q_UNUSED(param2);
    MbBlinkEvalPack* p = static_cast<MbBlinkEvalPack*>(param1);
    if (!p || !p->view || !p->frame || !p->script || !mbRunJsSync || !mbJsToString)
        return;

    auto valueToQString = [&](mbWebView w, mbWebFrameHandle fr, mbJsValue v) -> QString {
        mbJsExecState es = mbGetGlobalExecByFrame ? mbGetGlobalExecByFrame(w, fr) : nullptr;
        const utf8* s = mbJsToString(es, v);
        QString out = mbUtf8(s);
        if (out.isEmpty()) {
            s = mbJsToString(nullptr, v);
            out = mbUtf8(s);
        }
        return out;
    };

    for (int pass = 0; pass < 2; ++pass) {
        const BOOL inClosure = pass == 0 ? FALSE : TRUE;
        const mbJsValue v = mbRunJsSync(p->view, p->frame, p->script, inClosure);
        p->result = valueToQString(p->view, p->frame, v).trimmed();
        if (!p->result.isEmpty())
            return;
    }
}

/** 在页面中执行脚本并取字符串返回值；部分 mb 须在 Blink 线程或 mbJsToString(es=null) 才能取到结果 */
static QString evalPageJsReturnString(mbWebView webView, mbWebFrameHandle frame, const QByteArray& utf8Js)
{
    if (!webView || !frame || utf8Js.isEmpty() || !mbRunJsSync || !mbJsToString)
        return QString();
    const char* script = utf8Js.constData();

    auto valueToQString = [&](mbJsValue v) -> QString {
        mbJsExecState es = mbGetGlobalExecByFrame ? mbGetGlobalExecByFrame(webView, frame) : nullptr;
        const utf8* s = mbJsToString(es, v);
        QString out = mbUtf8(s);
        if (out.isEmpty()) {
            s = mbJsToString(nullptr, v);
            out = mbUtf8(s);
        }
        return out;
    };

    for (int pass = 0; pass < 2; ++pass) {
        const BOOL inClosure = pass == 0 ? FALSE : TRUE;
        const mbJsValue v = mbRunJsSync(webView, frame, script, inClosure);
        const QString out = valueToQString(v).trimmed();
        if (!out.isEmpty())
            return out;
    }

    if (mbCallBlinkThreadSync) {
        MbBlinkEvalPack pack;
        pack.view = webView;
        pack.frame = frame;
        pack.script = script;
        mbCallBlinkThreadSync(blinkEvalJsThunk, &pack, nullptr);
        return pack.result;
    }
    return QString();
}

static QString evalPageJsOnBlinkThread(mbWebView webView, mbWebFrameHandle frame, const QByteArray& utf8Js)
{
    if (!webView || !frame || utf8Js.isEmpty() || !mbCallBlinkThreadSync)
        return QString();
    MbBlinkEvalPack pack;
    pack.view = webView;
    pack.frame = frame;
    pack.scriptOwned = utf8Js;
    pack.script = pack.scriptOwned.constData();
    mbCallBlinkThreadSync(blinkEvalJsThunk, &pack, nullptr);
    return pack.result;
}

static void focusMbPointByClick(mbWebView webView, const QPoint& mbPoint)
{
    if (!webView || !mbFireMouseEvent)
        return;
    mbFireMouseEvent(webView, WM_LBUTTONDOWN, mbPoint.x(), mbPoint.y(), 0);
    mbFireMouseEvent(webView, WM_LBUTTONUP, mbPoint.x(), mbPoint.y(), 0);
}

/** 将系统剪贴板文本逐字送入页面（mbFireKeyPressEvent），不依赖内核剪贴板/mbEditorPaste */
static bool typePlainTextViaMbKeyPress(mbWebView webView, const QString& text)
{
    if (!webView || text.isEmpty() || !mbFireKeyPressEvent)
        return false;
    for (const QChar ch : text) {
        if (ch == QLatin1Char('\r'))
            continue;
        if (ch == QLatin1Char('\n')) {
            mbFireKeyPressEvent(webView, static_cast<unsigned int>('\r'), 0, FALSE);
            continue;
        }
        mbFireKeyPressEvent(webView, static_cast<unsigned int>(ch.unicode()), 0, FALSE);
    }
    return true;
}

static bool evalPageJsPasteOk(mbWebView webView, mbWebFrameHandle frame, const QByteArray& utf8Js)
{
    if (!webView || !frame || utf8Js.isEmpty())
        return false;
#if defined(Q_OS_LINUX)
    if (mbCallBlinkThreadSync)
        return evalPageJsOnBlinkThread(webView, frame, utf8Js) == QStringLiteral("1");
#endif
    return evalPageJsReturnString(webView, frame, utf8Js).trimmed() == QStringLiteral("1");
}

static void setClipboardPlainText(const QString& text);
static void noteWebClipboardText(const QString& text);

static void installWebClipboardSyncHook(mbWebView webView)
{
    if (!webView || !mbWebFrameGetMainFrame)
        return;
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(webView);
    static const QByteArray js(
        "(function(){"
        "function lvNotify(t){"
        "try{"
        "if(!t||typeof window.mbQuery!=='function')return;"
        "window.mbQuery(0,'lv-clip-sync:'+JSON.stringify({t:String(t)}),function(){});"
        "}catch(z){}"
        "}"
        "function lvFromEvent(e){"
        "try{"
        "if(e&&e.clipboardData){var t=e.clipboardData.getData('text/plain');if(t)return String(t);}"
        "var s=window.getSelection&&window.getSelection();return s?s.toString():'';"
        "}catch(z){return'';}"
        "}"
        "function hookDoc(d){"
        "if(!d||d.__lvClipHook)return;"
        "d.__lvClipHook=1;"
        "d.addEventListener('copy',function(e){lvNotify(lvFromEvent(e));},true);"
        "d.addEventListener('cut',function(e){lvNotify(lvFromEvent(e));},true);"
        "d.addEventListener('click',function(e){"
        "try{"
        "var el=e.target;if(!el)return;"
        "var lbl=(el.innerText||el.textContent||'').trim();"
        "if(lbl!=='\\u590d\\u5236'&&lbl.indexOf('\\u590d\\u5236')<0)return;"
        "setTimeout(function(){lvNotify(lvFromEvent(null));},80);"
        "}catch(z){}"
        "},true);"
        "}"
        "function hookWin(w){"
        "try{"
        "if(!w||!w.document)return;"
        "hookDoc(w.document);"
        "var L=w.document.querySelectorAll('iframe');"
        "for(var i=0;i<L.length;i++){"
        "try{var cw=L[i].contentWindow;if(cw)hookWin(cw);}catch(e1){}"
        "}"
        "}catch(z){}"
        "}"
        "function hookAll(){hookWin(window);}"
        "hookAll();"
        "setTimeout(hookAll,400);"
        "setTimeout(hookAll,1200);"
        "window.addEventListener('load',hookAll,true);"
        "try{"
        "var cp=window.Clipboard&&window.Clipboard.prototype;"
        "if(cp&&cp.writeText){"
        "var ow=cp.writeText;"
        "cp.writeText=function(t){lvNotify(t);return ow.apply(this,arguments);};"
        "}"
        "}catch(z1){}"
        "try{"
        "var nc=navigator.clipboard;"
        "if(nc&&nc.writeText){"
        "var ow2=nc.writeText.bind(nc);"
        "nc.writeText=function(t){lvNotify(t);return ow2(t);};"
        "}"
        "}catch(z2){}"
        "try{"
        "var ox=document.execCommand.bind(document);"
        "document.execCommand=function(cmd){"
        "var r=ox.apply(document,arguments);"
        "if(cmd==='copy'||cmd==='cut')setTimeout(function(){lvNotify(lvFromEvent(null));},0);"
        "return r;"
        "};"
        "}catch(z3){}"
        "})()");
    evalPageJsReturnString(webView, frame, js);
}

void MB_CALL_TYPE onJsQueryCallback(mbWebView webView, void* param, mbJsExecState es,
    int64_t queryId, int customMsg, const utf8* request)
{
    Q_UNUSED(es);
    WebWidget* self = static_cast<WebWidget*>(param);
    const QString req = mbUtf8(request);
    if (req.startsWith(QStringLiteral("lv-clip-sync:"))) {
        const QJsonDocument doc = QJsonDocument::fromJson(req.mid(13).toUtf8());
        if (doc.isObject()) {
            const QString t = doc.object().value(QStringLiteral("t")).toString();
            if (!t.isEmpty()) {
                noteWebClipboardText(t);
                if (self) {
                    QMetaObject::invokeMethod(self, "applyWebPageCopiedText", Qt::QueuedConnection, Q_ARG(QString, t));
                }
            }
        }
    }
    if (mbResponseQuery)
        mbResponseQuery(webView, queryId, customMsg, reinterpret_cast<const utf8*>(""));
}

static void applyBlankHomeBackgroundIfNeeded(mbWebView webView, const QString& urlHint)
{
    if (!webView || !mbWebFrameGetMainFrame)
        return;
    const QString u = urlHint.trimmed();
    if (!u.isEmpty() && u.compare(QStringLiteral("about:blank"), Qt::CaseInsensitive) != 0)
        return;
    if (mbGetUrl) {
        const QString cur = mbUtf8(mbGetUrl(webView)).trimmed();
        if (!cur.isEmpty() && cur.compare(QStringLiteral("about:blank"), Qt::CaseInsensitive) != 0)
            return;
    }
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(webView);
    if (!frame)
        return;
    const QByteArray js(
        "(function(){"
        "try{"
        "var d=document.documentElement,b=document.body,h=document.head||document.getElementsByTagName('head')[0];"
        "if(h&&!document.getElementById('__lv_blank_bg')){"
        "var s=document.createElement('style');s.id='__lv_blank_bg';"
        "s.textContent='html,body{background:#F7F9FC !important;background-color:#F7F9FC !important;margin:0 !important;}';"
        "h.appendChild(s);"
        "}"
        "if(d){d.style.setProperty('background','#F7F9FC','important');d.style.setProperty('background-color','#F7F9FC','important');}"
        "if(b){b.style.setProperty('background','#F7F9FC','important');b.style.setProperty('background-color','#F7F9FC','important');b.style.setProperty('margin','0','important');}"
        "}catch(e){}"
        "return 'ok';"
        "})()");
    evalPageJsReturnString(webView, frame, js);
}

static void scheduleBlankHomeBackgroundApply(WebWidget* self, const QString& urlHint)
{
    if (!self)
        return;
    const int delaysMs[] = {0, 30, 80, 180};
    for (int d : delaysMs) {
        QTimer::singleShot(d, self, [self, urlHint]() {
            if (!self || !self->m_webView)
                return;
            /* 避免新建标签后快速导航时，about:blank 注入脚本与目标页导航并发。 */
            if (self->isLoading())
                return;
            applyBlankHomeBackgroundIfNeeded(self->m_webView, urlHint);
        });
    }
}

static QString sanitizeDownloadFileName(QString name)
{
    name = name.trimmed();
    name.replace(QRegularExpression(QStringLiteral("[\\\\/:*?\"<>|\\x00-\\x1F]")), QStringLiteral("_"));
    while (name.startsWith('.'))
        name.remove(0, 1);
    if (name.isEmpty())
        name = QStringLiteral("download.bin");
    return name;
}

static QString fileNameFromDisposition(const QString& disposition)
{
    if (disposition.isEmpty())
        return QString();
    {
        QRegularExpression re(QStringLiteral("filename\\*\\s*=\\s*UTF-8''([^;]+)"), QRegularExpression::CaseInsensitiveOption);
        const QRegularExpressionMatch m = re.match(disposition);
        if (m.hasMatch())
            return QString::fromUtf8(QByteArray::fromPercentEncoding(m.captured(1).toUtf8())).trimmed();
    }
    {
        QRegularExpression re(QStringLiteral("filename\\s*=\\s*\"?([^\";]+)\"?"), QRegularExpression::CaseInsensitiveOption);
        const QRegularExpressionMatch m = re.match(disposition);
        if (m.hasMatch())
            return m.captured(1).trimmed();
    }
    return QString();
}

static QString chooseDownloadFileName(const char* url, const char* disposition)
{
    QString name = sanitizeDownloadFileName(fileNameFromDisposition(QString::fromUtf8(disposition ? disposition : "")));
    if (!name.isEmpty() && name != QStringLiteral("download.bin"))
        return name;
    const QUrl u = QUrl::fromUserInput(QString::fromUtf8(url ? url : ""));
    const QString byUrl = sanitizeDownloadFileName(QFileInfo(u.path()).fileName());
    if (!byUrl.isEmpty() && byUrl != QStringLiteral("download.bin"))
        return byUrl;
    return QStringLiteral("download.bin");
}

static QString uniqueDownloadPath(const QString& dir, const QString& fileName)
{
    QString base = QFileInfo(fileName).completeBaseName();
    QString ext = QFileInfo(fileName).suffix();
    if (base.isEmpty())
        base = QStringLiteral("download");
    const QString suffix = ext.isEmpty() ? QString() : QStringLiteral(".") + ext;
    /* 与磁盘存在性、进行中的下载一并判断，并立刻占位，避免并发同名任务拿到同一路径导致写入失败 */
    QMutexLocker locker(&g_downloadJobMapMutex);
    for (int i = 0;; ++i) {
        const QString candidate = QDir(dir).filePath(
            i == 0 ? (base + suffix) : QStringLiteral("%1(%2)%3").arg(base).arg(i).arg(suffix));
        if (QFileInfo::exists(candidate))
            continue;
        if (!g_downloadJobByPath.contains(candidate)) {
            g_downloadJobByPath.insert(candidate, nullptr);
            return candidate;
        }
    }
}

static unsigned int qtKeyToVirtualKey(int key)
{
#if defined(Q_OS_WIN)
    if (key >= Qt::Key_A && key <= Qt::Key_Z)
        return static_cast<unsigned int>('A' + (key - Qt::Key_A));
    if (key >= Qt::Key_0 && key <= Qt::Key_9)
        return static_cast<unsigned int>('0' + (key - Qt::Key_0));
    switch (key) {
    case Qt::Key_Backspace: return VK_BACK;
    case Qt::Key_Tab: return VK_TAB;
    case Qt::Key_Return:
    case Qt::Key_Enter: return VK_RETURN;
    case Qt::Key_Escape: return VK_ESCAPE;
    case Qt::Key_Space: return VK_SPACE;
    case Qt::Key_Left: return VK_LEFT;
    case Qt::Key_Up: return VK_UP;
    case Qt::Key_Right: return VK_RIGHT;
    case Qt::Key_Down: return VK_DOWN;
    case Qt::Key_Delete: return VK_DELETE;
    case Qt::Key_Home: return VK_HOME;
    case Qt::Key_End: return VK_END;
    case Qt::Key_PageUp: return VK_PRIOR;
    case Qt::Key_PageDown: return VK_NEXT;
    default: return 0;
    }
#else
    // Windows Virtual-Key code values (miniblink expects this set on all platforms)
    static constexpr unsigned int VK_BACK_  = 0x08;
    static constexpr unsigned int VK_TAB_   = 0x09;
    static constexpr unsigned int VK_RETURN_= 0x0D;
    static constexpr unsigned int VK_ESCAPE_= 0x1B;
    static constexpr unsigned int VK_SPACE_ = 0x20;
    static constexpr unsigned int VK_PRIOR_ = 0x21; // PageUp
    static constexpr unsigned int VK_NEXT_  = 0x22; // PageDown
    static constexpr unsigned int VK_END_   = 0x23;
    static constexpr unsigned int VK_HOME_  = 0x24;
    static constexpr unsigned int VK_LEFT_  = 0x25;
    static constexpr unsigned int VK_UP_    = 0x26;
    static constexpr unsigned int VK_RIGHT_ = 0x27;
    static constexpr unsigned int VK_DOWN_  = 0x28;
    static constexpr unsigned int VK_DELETE_= 0x2E;
    if (key >= Qt::Key_A && key <= Qt::Key_Z)
        return static_cast<unsigned int>('A' + (key - Qt::Key_A));
    if (key >= Qt::Key_0 && key <= Qt::Key_9)
        return static_cast<unsigned int>('0' + (key - Qt::Key_0));
    switch (key) {
    case Qt::Key_Backspace: return VK_BACK_;
    case Qt::Key_Tab: return VK_TAB_;
    case Qt::Key_Return:
    case Qt::Key_Enter: return VK_RETURN_;
    case Qt::Key_Escape: return VK_ESCAPE_;
    case Qt::Key_Space: return VK_SPACE_;
    case Qt::Key_Left: return VK_LEFT_;
    case Qt::Key_Up: return VK_UP_;
    case Qt::Key_Right: return VK_RIGHT_;
    case Qt::Key_Down: return VK_DOWN_;
    case Qt::Key_Delete: return VK_DELETE_;
    case Qt::Key_Home: return VK_HOME_;
    case Qt::Key_End: return VK_END_;
    case Qt::Key_PageUp: return VK_PRIOR_;
    case Qt::Key_PageDown: return VK_NEXT_;
    default: return 0;
    }
#endif
}

static bool isMbControlKey(int key)
{
    switch (key) {
    case Qt::Key_Backspace:
    case Qt::Key_Tab:
    case Qt::Key_Return:
    case Qt::Key_Enter:
    case Qt::Key_Escape:
    case Qt::Key_Left:
    case Qt::Key_Up:
    case Qt::Key_Right:
    case Qt::Key_Down:
    case Qt::Key_Delete:
    case Qt::Key_Home:
    case Qt::Key_End:
    case Qt::Key_PageUp:
    case Qt::Key_PageDown:
        return true;
    default:
        return false;
    }
}

static qint64 normalizeExpectedBytes(size_t expectedContentLength)
{
    if (expectedContentLength == 0 || expectedContentLength == static_cast<size_t>(-1))
        return 0;
    if (expectedContentLength > static_cast<size_t>((std::numeric_limits<qint64>::max)()))
        return 0;
    return static_cast<qint64>(expectedContentLength);
}

static void injectPageScrollbarStyle(mbWebView webView)
{
    if (!webView || !mbRunJsSync || !mbWebFrameGetMainFrame)
        return;
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(webView);
    const QString js = QString::fromLatin1(
        "(function(){"
        "try{"
        "var d=document;if(!d||!d.documentElement)return '';"
        "var id='liteview-scrollbar-style';"
        "var css='::-webkit-scrollbar{width:8px;height:8px;}'"
        "+'::-webkit-scrollbar-thumb{background:rgba(120,130,150,.45);border-radius:4px;}'"
        "+'::-webkit-scrollbar-track{background:transparent;}';"
        "var st=d.getElementById(id);"
        "if(!st){st=d.createElement('style');st.id=id;(d.head||d.documentElement).appendChild(st);}"
        "st.textContent=css;"
        "return 'ok';"
        "}catch(e){return '';}"
        "})();");
    const QByteArray jsUtf8 = js.toUtf8();
    mbRunJsSync(webView, frame, jsUtf8.constData(), TRUE);
}

mbDownloadOpt MB_CALL_TYPE onDownloadInBlinkThreadCallback(
    mbWebView webView,
    void* param,
    size_t expectedContentLength,
    const char* url,
    const char* mime,
    const char* disposition,
    mbNetJob job,
    mbNetJobDataBind* dataBind)
{
    WebWidget* self = static_cast<WebWidget*>(param);
    if (!self)
        return kMbDownloadOptCancel;
    Q_UNUSED(mime);
    QString saveDir = BrowserSettingsWidget::downloadSavePath();
    if (saveDir.trimmed().isEmpty())
        saveDir = QDir::homePath() + QStringLiteral("/Downloads");
    QDir d(saveDir);
    if (!d.exists() && !d.mkpath(QStringLiteral(".")))
        return kMbDownloadOptCancel;
    const QString fileName = chooseDownloadFileName(url, disposition);
    const QString savePath = uniqueDownloadPath(saveDir, fileName);
    if (!mbDownloadByUtf8Path) {
        QMutexLocker locker(&g_downloadJobMapMutex);
        g_downloadJobByPath.remove(savePath);
        return kMbDownloadOptCancel;
    }
    const QByteArray saveUtf8 = QDir::toNativeSeparators(savePath).toUtf8();
    DownloadProgressContext* ctx = new DownloadProgressContext();
    ctx->self = self;
    ctx->url = QString::fromUtf8(url ? url : "");
    ctx->savePath = savePath;
    ctx->totalBytes = normalizeExpectedBytes(expectedContentLength);
    ctx->receivedBytes = 0;
    ctx->job = job;
    mbDownloadBind callbackBind = { 0 };
    callbackBind.param = ctx;
    callbackBind.recvCallback = onDownloadDataRecvCallback;
    callbackBind.finishCallback = onDownloadDataFinishCallback;
    callbackBind.saveNameCallback = nullptr;
    callbackBind.beginSaveCallback = nullptr;
    {
        QMutexLocker locker(&g_downloadJobMapMutex);
        g_downloadJobByPath.insert(savePath, job);
        g_cancelRequestedPaths.remove(savePath);
    }
    if (self) {
        QMetaObject::invokeMethod(
            self,
            "onDownloadStartedQueued",
            Qt::QueuedConnection,
            Q_ARG(QString, ctx->url),
            Q_ARG(QString, savePath),
            Q_ARG(qint64, ctx->totalBytes));
    }
    mbDownloadOptions dlOpt = mbDownloadByUtf8PathOptions();
    mbDownloadOpt opt = kMbDownloadOptCancel;
    {
        QMutexLocker dlLock(&g_mbDownloadByUtf8PathMutex);
        opt = mbDownloadByUtf8Path(
            webView,
            &dlOpt,
            saveUtf8.constData(),
            expectedContentLength,
            url,
            mime,
            disposition,
            job,
            dataBind,
            &callbackBind);
    }
    if (opt == kMbDownloadOptCancel) {
        {
            QMutexLocker locker(&g_downloadJobMapMutex);
            g_downloadJobByPath.remove(savePath);
            g_cancelRequestedPaths.remove(savePath);
        }
        if (self) {
            QMetaObject::invokeMethod(
                self,
                "onDownloadFinishedQueued",
                Qt::QueuedConnection,
                Q_ARG(QString, ctx->url),
                Q_ARG(QString, savePath),
                Q_ARG(bool, false),
                Q_ARG(QString, QString::fromUtf8("\xe5\x90\xaf\xe5\x8a\xa8\xe4\xb8\x8b\xe8\xbd\xbd\xe5\xa4\xb1\xe8\xb4\xa5")));
        }
        delete ctx;
    }
    return opt;
}

void MB_CALL_TYPE onDownloadDataRecvCallback(void* ptr, mbNetJob job, const char* data, int length)
{
    Q_UNUSED(job);
    Q_UNUSED(data);
    DownloadProgressContext* ctx = static_cast<DownloadProgressContext*>(ptr);
    if (!ctx || !ctx->self)
        return;
    if (length > 0)
        ctx->receivedBytes += static_cast<qint64>(length);
    QMetaObject::invokeMethod(
        ctx->self,
        "onDownloadProgressQueued",
        Qt::QueuedConnection,
        Q_ARG(QString, ctx->url),
        Q_ARG(QString, ctx->savePath),
        Q_ARG(qint64, ctx->receivedBytes),
        Q_ARG(qint64, ctx->totalBytes));
}

void MB_CALL_TYPE onDownloadDataFinishCallback(void* ptr, mbNetJob job, mbLoadingResult result)
{
    Q_UNUSED(job);
    DownloadProgressContext* ctx = static_cast<DownloadProgressContext*>(ptr);
    if (!ctx)
        return;
    WebWidget* self = ctx->self;
    const QString url = ctx->url;
    const QString savePath = ctx->savePath;
    const bool ok = (result == MB_LOADING_SUCCEEDED);
    QString reason;
    {
        QMutexLocker locker(&g_downloadJobMapMutex);
        g_downloadJobByPath.remove(savePath);
        const bool cancelled = g_cancelRequestedPaths.remove(savePath);
        if (!ok)
            reason = cancelled ? QString::fromUtf8("\xe5\xb7\xb2\xe5\x8f\x96\xe6\xb6\x88") : QStringLiteral("download failed");
    }
    delete ctx;
    if (!self)
        return;
    QMetaObject::invokeMethod(
        self,
        "onDownloadFinishedQueued",
        Qt::QueuedConnection,
        Q_ARG(QString, url),
        Q_ARG(QString, savePath),
        Q_ARG(bool, ok),
        Q_ARG(QString, reason));
}

static QIcon loadMenuIconFromImagesDir(const QStringList& stems)
{
    const QStringList roots = {
        QDir::currentPath() + QStringLiteral("/images"),
        QCoreApplication::applicationDirPath() + QStringLiteral("/images"),
    };
    const QStringList exts = {QStringLiteral(".png"), QStringLiteral(".svg"), QStringLiteral(".jpg")};
    for (const QString& root : roots) {
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

static bool textContainsAnyToken(const QString& text, const QStringList& tokens)
{
    const QString lower = text.toLower();
    for (const QString& t : tokens) {
        if (!t.isEmpty() && lower.contains(t))
            return true;
    }
    return false;
}

static QIcon buildMenuLinkIcon()
{
    const int s = 18;
    QPixmap pm(s, s);
    pm.fill(Qt::transparent);
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing, true);
    const QColor c(QStringLiteral("#0f172a"));
    p.setPen(QPen(c, 1.7, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    p.setBrush(Qt::NoBrush);
    p.drawRect(QRectF(3.0, 5.0, 8.5, 9.0));
    p.drawLine(QPointF(7.4, 10.8), QPointF(14.2, 4.1));
    p.drawLine(QPointF(10.0, 4.1), QPointF(14.2, 4.1));
    p.drawLine(QPointF(14.2, 4.1), QPointF(14.2, 8.3));
    return QIcon(pm);
}

static QIcon buildMenuWindowIcon()
{
    const int s = 18;
    QPixmap pm(s, s);
    pm.fill(Qt::transparent);
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing, true);
    const QColor c(QStringLiteral("#0f172a"));
    p.setPen(QPen(c, 1.7, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    p.setBrush(Qt::NoBrush);
    p.drawRoundedRect(QRectF(2.5, 4.5, 13.0, 10.0), 1.8, 1.8);
    p.drawLine(QPointF(2.5, 7.4), QPointF(15.5, 7.4));
    return QIcon(pm);
}

static QIcon buildMenuCopyIcon()
{
    const QSize s(18, 18);
    QIcon src = loadMenuIconFromImagesDir({QStringLiteral("copy")});
    if (!src.isNull()) {
        QPixmap base = src.pixmap(s);
        if (!base.isNull()) {
            QPixmap out(s);
            out.fill(Qt::transparent);
            QPainter p(&out);
            p.setRenderHint(QPainter::Antialiasing, true);
            p.drawPixmap(0, 0, base);
            p.setCompositionMode(QPainter::CompositionMode_SourceIn);
            p.fillRect(out.rect(), QColor(QStringLiteral("#0f172a")));
            p.end();
            return QIcon(out);
        }
    }
    const int side = 18;
    QPixmap pm(side, side);
    pm.fill(Qt::transparent);
    QPainter p(&pm);
    p.setRenderHint(QPainter::Antialiasing, true);
    const QColor c(QStringLiteral("#0f172a"));
    p.setPen(QPen(c, 1.7, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    p.setBrush(Qt::NoBrush);
    p.drawRoundedRect(QRectF(6.4, 4.0, 8.0, 10.0), 1.3, 1.3);
    p.drawRoundedRect(QRectF(3.0, 6.3, 8.0, 8.8), 1.3, 1.3);
    return QIcon(pm);
}

static QIcon buildMenuPasteIcon()
{
    const QSize s(18, 18);
    QIcon src = loadMenuIconFromImagesDir({QStringLiteral("paste")});
    if (src.isNull())
        return QIcon();
    QPixmap base = src.pixmap(s);
    if (base.isNull())
        return QIcon();
    QPixmap out(s);
    out.fill(Qt::transparent);
    QPainter p(&out);
    p.setRenderHint(QPainter::Antialiasing, true);
    p.drawPixmap(0, 0, base);
    p.setCompositionMode(QPainter::CompositionMode_SourceIn);
    p.fillRect(out.rect(), QColor(QStringLiteral("#0f172a")));
    p.end();
    return QIcon(out);
}

static QString systemClipboardText()
{
    QClipboard* cb = QApplication::clipboard();
    if (!cb)
        return QString();
    if (const QMimeData* md = cb->mimeData(QClipboard::Clipboard)) {
        if (md->hasText())
            return md->text();
    }
    return cb->text(QClipboard::Clipboard);
}

static QString g_cachedWebPlainText;
static qint64 g_cachedWebPlainTextMs = 0;

static void noteWebClipboardText(const QString& text)
{
    if (text.isEmpty())
        return;
    g_cachedWebPlainText = text;
    g_cachedWebPlainTextMs = QDateTime::currentMSecsSinceEpoch();
}

static QString textForPaste(const WebWidget* webHint = nullptr)
{
    const qint64 now = QDateTime::currentMSecsSinceEpoch();
#if defined(Q_OS_LINUX)
    /* 网页刚复制后 8 秒内优先用应用缓存，避免读 X11 CLIPBOARD 被 miniblink 持锁阻塞 */
    if (!g_cachedWebPlainText.isEmpty() && (now - g_cachedWebPlainTextMs) <= 8000)
        return g_cachedWebPlainText;
#endif
    const QString clip = systemClipboardText();
    if (!clip.isEmpty()) {
        noteWebClipboardText(clip);
        return clip;
    }
    if (webHint) {
        const QString sel = webHint->kernelSelectedText().trimmed();
        if (!sel.isEmpty())
            return sel;
    }
    return g_cachedWebPlainText;
}

static void setClipboardPlainText(const QString& text)
{
    if (text.isNull())
        return;
    noteWebClipboardText(text);
    QClipboard* cb = QApplication::clipboard();
    if (!cb)
        return;
    QMimeData* mime = new QMimeData();
    mime->setText(text);
    cb->setMimeData(mime, QClipboard::Clipboard);
}

static QMenu* createCommonContextMenu(QWidget* parent)
{
    static QPointer<QMenu> s_lastMenu;
    if (s_lastMenu) {
        s_lastMenu->close();
        s_lastMenu.clear();
    }
    QMenu* menu = new QMenu(parent);
    s_lastMenu = menu;
    menu->setAttribute(Qt::WA_DeleteOnClose);
    menu->setStyleSheet(QStringLiteral(
        "QMenu {"
        "  background: #ffffff;"
        "  border: 1px solid #e5e7eb;"
        "  border-radius: 10px;"
        "  font-family: 'Microsoft YaHei', 'PingFang SC', 'Segoe UI';"
        "  font-size: 16px;"
        "  padding: 8px 0;"
        "}"
        "QMenu::item {"
        "  min-width: 200px;"
        "  padding: 10px 24px 10px 48px;"
        "  color: #0f172a;"
        "  font-weight: 600;"
        "  background: transparent;"
        "}"
        "QMenu::item:disabled {"
        "  color: #64748b;"
        "}"
        "QMenu::item:selected {"
        "  background: #e5e7eb;"
        "}"
        "QMenu::icon {"
        "  padding-left: 14px;"
        "  padding-right: 8px;"
        "}"));
    auto applyRoundedMask = [menu]() {
        const QRect r = menu->rect();
        if (r.width() <= 0 || r.height() <= 0)
            return;
        QPainterPath path;
        path.addRoundedRect(QRectF(r), 10.0, 10.0);
        menu->setMask(QRegion(path.toFillPolygon().toPolygon()));
    };
    QObject::connect(menu, &QMenu::aboutToShow, menu, applyRoundedMask);
    QTimer::singleShot(0, menu, applyRoundedMask);
    return menu;
}

/** 是否为可导航的超链接（过滤 Linux 内核误报的无效 linkUrl） */
static bool isNavigableWebLink(const QString& urlStr)
{
    const QString t = urlStr.trimmed();
    if (t.isEmpty())
        return false;
    const QUrl u = QUrl::fromUserInput(t);
    if (!u.isValid() || u.scheme().isEmpty())
        return false;
    const QString scheme = u.scheme().toLower();
    return scheme == QStringLiteral("http") || scheme == QStringLiteral("https")
        || scheme == QStringLiteral("mailto") || scheme == QStringLiteral("ftp");
}

static QString pickFirstNavigableLink(const QString& a, const QString& b = QString(), const QString& c = QString())
{
    for (const QString& raw : {a, b, c}) {
        if (isNavigableWebLink(raw))
            return raw.trimmed();
    }
    return QString();
}

/** constrainCopyWithoutSelection：为 true 且无选区时禁用「复制」（搜索框等空输入框右键仍出「粘贴」） */
static bool showCopyPasteContextMenu(WebWidget* self, const QPoint& mbHit, bool constrainCopyWithoutSelection,
    const QString& selectionOverride = QString())
{
    if (!self)
        return false;
    /* onContextMenuPopup 与 mouseRelease 可能先后触发，避免连续弹出两个相同菜单 */
    static qint64 s_lastPopupMs = 0;
    const qint64 now = QDateTime::currentMSecsSinceEpoch();
    if (s_lastPopupMs != 0 && now - s_lastPopupMs < 180)
        return false;

    /* 右键弹出菜单后页面选区可能被内核折叠，须在展示时缓存选中文本（来自内核 selectionText） */
    QString cachedSel = selectionOverride.trimmed();
    if (cachedSel.isEmpty())
        cachedSel = self->kernelSelectedText().trimmed();

    QMenu* menu = createCommonContextMenu(self);
    QAction* copyAct = menu->addAction(buildMenuCopyIcon(), QString::fromUtf8("\xe5\xa4\x8d\xe5\x88\xb6"));
    copyAct->setIconVisibleInMenu(true);
    if (constrainCopyWithoutSelection)
        copyAct->setEnabled(!cachedSel.isEmpty());
    else
        copyAct->setEnabled(true);

    QObject::connect(copyAct, &QAction::triggered, self, [cachedSel]() {
        if (!cachedSel.isEmpty())
            setClipboardPlainText(cachedSel);
    });

    QIcon pasteIcon = buildMenuPasteIcon();
    QAction* pasteAct = menu->addAction(
        pasteIcon,
        QString::fromUtf8("\xe7\xb2\x98\xe8\xb4\xb4"));
    pasteAct->setIconVisibleInMenu(true);
    pasteAct->setEnabled(true);

    QObject::connect(pasteAct, &QAction::triggered, self, [self, mbHit]() {
        const QString clip = textForPaste(self);
        QPointer<WebWidget> guard(self);
        const QPoint hit = mbHit;
        QTimer::singleShot(0, self, [guard, hit, clip]() {
            if (guard && !clip.isEmpty())
                guard->pastePlainTextAtMb(hit, clip);
        });
    });

    menu->popup(QCursor::pos());
    s_lastPopupMs = now;
    return true;
}

void WebWidget::showCopyPasteContextMenuForLineEdit(QLineEdit* edit)
{
    if (!edit)
        return;

    QMenu* menu = createCommonContextMenu(edit);
    QAction* copyAct = menu->addAction(buildMenuCopyIcon(), QString::fromUtf8("\xe5\xa4\x8d\xe5\x88\xb6"));
    copyAct->setIconVisibleInMenu(true);
    auto syncCopyEnabled = [edit, copyAct]() {
        copyAct->setEnabled(!edit->selectedText().isEmpty());
    };
    QObject::connect(menu, &QMenu::aboutToShow, menu, syncCopyEnabled);
    syncCopyEnabled();
    QObject::connect(copyAct, &QAction::triggered, edit, [edit]() {
        const QString sel = edit->selectedText();
        if (!sel.isEmpty())
            WebWidget::copyTextToSystemClipboard(sel);
    });

    QAction* pasteAct = menu->addAction(
        buildMenuPasteIcon(),
        QString::fromUtf8("\xe7\xb2\x98\xe8\xb4\xb4"));
    pasteAct->setIconVisibleInMenu(true);
    pasteAct->setEnabled(true);
    QObject::connect(pasteAct, &QAction::triggered, edit, [edit]() {
        WebWidget::pasteTextToLineEdit(edit);
    });

    menu->popup(QCursor::pos());
}

void WebWidget::copyTextToSystemClipboard(const QString& text)
{
    setClipboardPlainText(text);
}

QString WebWidget::textFromSystemClipboard()
{
    return textForPaste();
}

void WebWidget::pasteTextToLineEdit(QLineEdit* edit)
{
    if (!edit)
        return;
    edit->setFocus();
    const QString clip = textForPaste();
    if (clip.isEmpty())
        return;
    edit->insert(clip);
}

/** @return 是否已弹出菜单（节流未命中时为 false，调用方勿置 m_engineContextMenuHandled） */
static bool popupTextSelectionContextMenu(WebWidget* self, const QPoint& mbHit, const QString& selectionOverride = QString())
{
    return showCopyPasteContextMenu(self, mbHit, false, selectionOverride);
}

static void popupBrowserContextMenu(WebWidget* self, mbWebView webView, bool canBack, bool canForward, bool canReload)
{
    if (!self)
        return;
    QMenu* menu = createCommonContextMenu(self);

    auto addAction = [&](const QIcon& icon, const QString& label, mbMenuItemId id, bool enabled) {
        QAction* action = menu->addAction(icon, label);
        action->setIconVisibleInMenu(true);
        action->setEnabled(enabled);
        self->connect(action, &QAction::triggered, self, [webView, id]() {
            mbExecuteContextMenu(webView, id);
        });
    };

    QIcon backIcon = loadMenuIconFromImagesDir({QStringLiteral("nav_back"), QStringLiteral("back")});
    if (backIcon.isNull())
        backIcon = qApp->style()->standardIcon(QStyle::SP_ArrowBack);
    QIcon forwardIcon = loadMenuIconFromImagesDir({QStringLiteral("nav_forward"), QStringLiteral("forward")});
    if (forwardIcon.isNull())
        forwardIcon = qApp->style()->standardIcon(QStyle::SP_ArrowForward);
    QIcon reloadIcon = loadMenuIconFromImagesDir({QStringLiteral("nav_reload"), QStringLiteral("reload"), QStringLiteral("refresh")});
    if (reloadIcon.isNull())
        reloadIcon = qApp->style()->standardIcon(QStyle::SP_BrowserReload);

    auto tintIconDark = [](const QIcon& src) -> QIcon {
        if (src.isNull())
            return src;
        const QSize sz(18, 18);
        QPixmap base = src.pixmap(sz);
        if (base.isNull())
            return src;
        QPixmap out(base.size());
        out.fill(Qt::transparent);
        QPainter p(&out);
        p.drawPixmap(0, 0, base);
        p.setCompositionMode(QPainter::CompositionMode_SourceIn);
        p.fillRect(out.rect(), QColor(QStringLiteral("#0f172a")));
        p.end();
        return QIcon(out);
    };

    addAction(tintIconDark(backIcon), QString::fromUtf8("\xe5\x90\x8e\xe9\x80\x80"), kMbMenuGoBackId, canBack);
    addAction(tintIconDark(forwardIcon), QString::fromUtf8("\xe5\x89\x8d\xe8\xbf\x9b"), kMbMenuGoForwardId, canForward);
    addAction(tintIconDark(reloadIcon), QString::fromUtf8("\xe5\x88\xb7\xe6\x96\xb0"), kMbMenuReloadId, canReload);
    menu->popup(QCursor::pos());
}

static void popupLinkContextMenu(WebWidget* self, mbWebView webView, mbMenuItemId openTabId, mbMenuItemId copyLinkId)
{
    if (!self)
        return;
    QMenu* menu = createCommonContextMenu(self);

    auto addAction = [&](const QIcon& icon, const QString& label, mbMenuItemId id) {
        QAction* action = menu->addAction(icon, label);
        action->setIconVisibleInMenu(true);
        self->connect(action, &QAction::triggered, self, [webView, id]() {
            mbExecuteContextMenu(webView, id);
        });
    };

    addAction(buildMenuLinkIcon(), QString::fromUtf8("\xe5\x9c\xa8\xe6\x96\xb0\xe6\xa0\x87\xe7\xad\xbe\xe9\xa1\xb5\xe4\xb8\xad\xe6\x89\x93\xe5\xbc\x80\xe9\x93\xbe\xe6\x8e\xa5"), openTabId);
    addAction(buildMenuCopyIcon(), QString::fromUtf8("\xe5\xa4\x8d\xe5\x88\xb6\xe9\x93\xbe\xe6\x8e\xa5"), copyLinkId);
    menu->popup(QCursor::pos());
}

static void popupLinkContextMenuByUrl(WebWidget* self, const QString& linkUrl)
{
    if (!self)
        return;
    QMenu* menu = createCommonContextMenu(self);
    auto addAction = [&](const QIcon& icon, const QString& label, const std::function<void()>& fn) {
        QAction* action = menu->addAction(icon, label);
        action->setIconVisibleInMenu(true);
        self->connect(action, &QAction::triggered, self, fn);
    };
    addAction(buildMenuLinkIcon(), QString::fromUtf8("\xe5\x9c\xa8\xe6\x96\xb0\xe6\xa0\x87\xe7\xad\xbe\xe9\xa1\xb5\xe4\xb8\xad\xe6\x89\x93\xe5\xbc\x80\xe9\x93\xbe\xe6\x8e\xa5"), [self, linkUrl]() { self->openLinkInNewTab(linkUrl); });
    addAction(buildMenuCopyIcon(), QString::fromUtf8("\xe5\xa4\x8d\xe5\x88\xb6\xe9\x93\xbe\xe6\x8e\xa5"), [self, linkUrl]() { self->copyLinkToClipboard(linkUrl); });
    menu->popup(QCursor::pos());
}

static QString fromWidePtr(const WCHAR* w)
{
    if (!w)
        return QString();
    /* Linux/Miniblink headers may expose WCHAR as char16_t (not wchar_t). */
    return QString::fromUtf16(reinterpret_cast<const ushort*>(w));
}

BOOL MB_CALL_TYPE onNavigationAllowCallback(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url)
{
    Q_UNUSED(webView);
    WebWidget* self = static_cast<WebWidget*>(param);
    const QString qurl = mbUtf8(url);
    qWarning().noquote() << "[LiteView][nav-trace] onNavigationAllow type=" << int(navigationType)
                         << " url=" << qurl;
    if (self) {
        const QUrl u(qurl);
        if (u.scheme().compare(QStringLiteral("liteview-download"), Qt::CaseInsensitive) == 0) {
            QMetaObject::invokeMethod(
                self,
                "onInternalActionUrlQueued",
                Qt::QueuedConnection,
                Q_ARG(QString, qurl));
            return FALSE;
        }
    }
    return TRUE;
}

mbWebView MB_CALL_TYPE onCreateViewCallback(mbWebView webView, void* param, mbNavigationType navigationType, const utf8* url, const mbWindowFeatures* windowFeatures)
{
    Q_UNUSED(webView);
    Q_UNUSED(navigationType);
    Q_UNUSED(windowFeatures);
    WebWidget* self = static_cast<WebWidget*>(param);
    if (!self)
        return NULL_WEBVIEW;
    const QString qurl = mbUtf8(url);
    if (self->m_createNewTabHandler)
        return self->m_createNewTabHandler(qurl);
    return NULL_WEBVIEW;
}

BOOL MB_CALL_TYPE onCloseCallback(mbWebView webView, void* param, void* unuse)
{
    Q_UNUSED(webView);
    Q_UNUSED(unuse);
    WebWidget* self = static_cast<WebWidget*>(param);
    if (!self || !self->m_authPopupTab)
        return FALSE;
    QMetaObject::invokeMethod(self, "onWindowCloseRequested", Qt::QueuedConnection);
    return TRUE;
}

BOOL MB_CALL_TYPE onFullscreenRequestedCallback(mbWebView webView, void* param, BOOL enter)
{
    Q_UNUSED(webView);
    WebWidget* self = static_cast<WebWidget*>(param);
    if (!self)
        return FALSE;

    if (enter)
        self->enterBrowserFullScreen();
    else
        self->exitBrowserFullScreen();
    return TRUE;
}

static bool oauthQueryHasAuthResult(const QUrlQuery& query)
{
    static const char* keys[] = {
        "auth_code", "code", "ticket", "access_token", "authorization_code"
    };
    for (const char* key : keys) {
        if (query.hasQueryItem(QString::fromLatin1(key)))
            return true;
    }
    return false;
}

static bool isLikelyOAuthCallbackUrl(const QString& urlStr)
{
    const QString trimmed = urlStr.trimmed();
    if (trimmed.isEmpty() || trimmed.compare(QStringLiteral("about:blank"), Qt::CaseInsensitive) == 0)
        return false;
    const QUrl u(trimmed);
    if (!u.isValid() || u.scheme().isEmpty())
        return false;

    const QString host = u.host().toLower();
    const QString path = u.path().toLower();
    const QUrlQuery query(u);
    if (!oauthQueryHasAuthResult(query))
        return false;

    if (path.contains(QStringLiteral("oauth_sign"))
        || path.contains(QStringLiteral("oauth/sign"))
        || path.contains(QStringLiteral("oauth/callback"))
        || path.contains(QStringLiteral("login/callback"))
        || path.contains(QStringLiteral("auth/callback"))
        || path.contains(QStringLiteral("wx_callback"))
        || path.contains(QStringLiteral("wechat/callback"))
        || path.contains(QStringLiteral("qq_callback"))
        || path.contains(QStringLiteral("connect/callback"))
        || path.endsWith(QStringLiteral("/callback")))
        return true;

    if (host.contains(QStringLiteral("passport"))
        || host.contains(QStringLiteral("account"))
        || host.contains(QStringLiteral("oauth"))
        || path.contains(QStringLiteral("oauth"))
        || path.contains(QStringLiteral("alipay"))
        || path.contains(QStringLiteral("wechat"))
        || path.contains(QStringLiteral("callback")))
        return true;

    return false;
}

Qt::CursorShape mbCursorInfoTypeToQt(mbCursorInfoType cursor_info_type)
{
    switch (cursor_info_type) {
        case kMbCursorInfoPointer:
            return Qt::ArrowCursor;
        case kMbCursorInfoCross:
            return Qt::CrossCursor;
        case kMbCursorInfoHand:
            return Qt::PointingHandCursor;
        case kMbCursorInfoIBeam:
            return Qt::IBeamCursor;
        case kMbCursorInfoWait:
            return Qt::WaitCursor;
        case kMbCursorInfoHelp:
            return Qt::WhatsThisCursor;
        case kMbCursorInfoEastResize:
        case kMbCursorInfoWestResize:
            return Qt::SizeHorCursor;
        case kMbCursorInfoNorthResize:
        case kMbCursorInfoSouthResize:
            return Qt::SizeVerCursor;
        case kMbCursorInfoNorthEastResize:
        case kMbCursorInfoSouthWestResize:
            return Qt::SizeBDiagCursor;
        case kMbCursorInfoNorthWestResize:
        case kMbCursorInfoSouthEastResize:
            return Qt::SizeFDiagCursor;
        case kMbCursorInfoNorthSouthResize:
            return Qt::SizeVerCursor;
        case kMbCursorInfoEastWestResize:
            return Qt::SizeHorCursor;
        case kMbCursorInfoNorthEastSouthWestResize:
            return Qt::SizeBDiagCursor;
        case kMbCursorInfoNorthWestSouthEastResize:
            return Qt::SizeFDiagCursor;
        case kMbCursorInfoColumnResize:
            return Qt::SplitHCursor;
        case kMbCursorInfoRowResize:
            return Qt::SplitVCursor;
        // Panning cursors in Qt are typically represented by the standard resize cursors
        // or a specific hand cursor. We'll map them to SizeAllCursor as a general panning indicator.
        case kMbCursorInfoMiddlePanning:
        case kMbCursorInfoEastPanning:
        case kMbCursorInfoNorthPanning:
        case kMbCursorInfoNorthEastPanning:
        case kMbCursorInfoNorthWestPanning:
        case kMbCursorInfoSouthPanning:
        case kMbCursorInfoSouthEastPanning:
        case kMbCursorInfoSouthWestPanning:
        case kMbCursorInfoWestPanning:
            return Qt::SizeAllCursor; // Or Qt::OpenHandCursor if preferred for panning
        case kMbCursorInfoMove:
            return Qt::SizeAllCursor;
        //case kMbCursorInfoVerticalText:
        //    return Qt::VerticalTextCursor; // Requires Qt 5.15+
        case kMbCursorInfoCell:
            return Qt::CrossCursor; // Closest approximation
        case kMbCursorInfoContextMenu:
            return Qt::ArrowCursor; // No direct equivalent, arrow is a safe default
        case kMbCursorInfoAlias:
            return Qt::DragCopyCursor; // Closest approximation
        case kMbCursorInfoProgress:
            return Qt::BusyCursor; // Or Qt::WaitCursor
        case kMbCursorInfoNoDrop:
        case kMbCursorInfoNotAllowed:
            return Qt::ForbiddenCursor;
        case kMbCursorInfoZoomIn:
        case kMbCursorInfoZoomOut:
            return Qt::ArrowCursor; // No direct equivalent
        case kMbCursorInfoGrab:
            return Qt::OpenHandCursor;
        case kMbCursorInfoGrabbing:
            return Qt::ClosedHandCursor;
        case kMbCursorInfoCustom:
            // This requires special handling. The function can't create a custom Qt cursor.
            // It should return a default, and the caller must handle the custom image separately.
            return Qt::ArrowCursor; // Default fallback

        // Handle any unlisted enum values for safety.
        default:
            return Qt::ArrowCursor;
    }
}

void WebWidget::dispatchEngineContextMenu(mbWebView webView, WebWidget* self,
    const QVector<mbMenuItemId>& ids, const QVector<QString>& texts, const EngineContextMenuInfo& info)
{
    if (!self)
        return;
    if (self->m_engineContextMenuHandled)
        return;
    const int itemSize = ids.size();

    const QString kernelSel = info.selectionText.trimmed();

    bool engineHasTextSelection = !kernelSel.isEmpty();
    for (int i = 0; i < itemSize; ++i) {
        if (ids[i] == kMbMenuCutId && !kernelSel.isEmpty()) {
            engineHasTextSelection = true;
            break;
        }
        /* 须同时存在内核选区文本，避免 kMbMenuSelectedTextId 占位误判 */
        if (ids[i] == kMbMenuSelectedTextId && !kernelSel.isEmpty()) {
            engineHasTextSelection = true;
            break;
        }
        const QString t = texts.value(i);
        if (!kernelSel.isEmpty()
            && textContainsAnyToken(t, {QStringLiteral("copy"), QStringLiteral("复制")})
            && !textContainsAnyToken(t, {QStringLiteral("link"), QStringLiteral("链接"), QStringLiteral("image"), QStringLiteral("图片")})) {
            engineHasTextSelection = true;
            break;
        }
    }

    bool hasOpenTab = false;
    bool hasCopyLink = false;
    mbMenuItemId idOpenTab = (mbMenuItemId)0;
    mbMenuItemId idCopyLink = (mbMenuItemId)0;

    for (int i = 0; i < itemSize; ++i) {
        const QString t = texts.value(i);
        if (!hasOpenTab && textContainsAnyToken(t, {QStringLiteral("new tab"), QStringLiteral("open link"), QStringLiteral("新标签页"),
                QStringLiteral("在新标签"), QStringLiteral("标签页中"), QStringLiteral("open in new tab")})) {
            hasOpenTab = true;
            idOpenTab = ids[i];
        } else if (!hasCopyLink && textContainsAnyToken(t, {QStringLiteral("copy link"), QStringLiteral("copy link address"),
                QStringLiteral("复制链接"), QStringLiteral("复制链接地址")})) {
            hasCopyLink = true;
            idCopyLink = ids[i];
        }
    }

    auto tryDomLink = [&](const QPoint& pt) -> QString {
        return self->linkUrlAtPoint(pt).trimmed();
    };

    if (engineHasTextSelection || !kernelSel.isEmpty()) {
        const QPoint menuHit = info.hasHitPoint ? QPoint(info.hitX, info.hitY) : self->m_lastRmbMbPos;
        if (popupTextSelectionContextMenu(self, menuHit, kernelSel))
            self->m_engineContextMenuHandled = true;
        return;
    }

    /* 空搜索框等：无选区但命中可编辑区，仍出「复制/粘贴」（复制无选区时禁用） */
    if (info.isEditable) {
        const QPoint menuHit = info.hasHitPoint ? QPoint(info.hitX, info.hitY) : self->m_lastRmbMbPos;
        showCopyPasteContextMenu(self, menuHit, true);
        self->m_engineContextMenuHandled = true;
        return;
    }

    const QPoint menuHit = info.hasHitPoint ? QPoint(info.hitX, info.hitY) : self->m_lastRmbMbPos;
    const QString engineLink = pickFirstNavigableLink(info.linkUrl);
    QString domLink;
    if (engineLink.isEmpty()) {
        domLink = tryDomLink(menuHit);
        if (domLink.isEmpty())
            domLink = tryDomLink(self->m_lastRmbMbPos);
        if (!isNavigableWebLink(domLink))
            domLink.clear();
    }
    const QString linkForMenu = !engineLink.isEmpty() ? engineLink : domLink;

    if (!linkForMenu.isEmpty()) {
        self->m_engineContextMenuHandled = true;
        if (hasOpenTab && hasCopyLink)
            popupLinkContextMenu(self, webView, idOpenTab, idCopyLink);
        else
            popupLinkContextMenuByUrl(self, linkForMenu);
        return;
    }

    /* 默认：后退 / 前进 / 刷新（勿仅凭内核菜单项含「复制链接」就判为链接菜单，Linux 上常误报） */
    self->m_engineContextMenuHandled = true;
    popupBrowserContextMenu(self, webView, self->m_lastCanGoBack, self->m_lastCanGoForward, true);
}

BOOL MB_CALL_TYPE onContextMenuPopup(mbWebView webView, void* param, int itemSize, mbMenuItemId ids[], const utf8* text[], const mbContextMenuParams* menuParams)
{
    WebWidget* self = static_cast<WebWidget*>(param);
    if (!self || self->m_isDestroying || !self->m_webView)
        return FALSE;
    QVector<mbMenuItemId> idVec;
    idVec.reserve(itemSize);
    for (int i = 0; i < itemSize; ++i)
        idVec.append(ids[i]);
    QVector<QString> textVec;
    textVec.reserve(itemSize);
    for (int i = 0; i < itemSize; ++i)
        textVec.append(mbUtf8(text ? text[i] : nullptr));

    LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu] mbSetContextMenuCallback: webView=0x%1 itemSize=%2 textArray=%3 menuParams=%4 (ptr=0x%5)")
        .arg(quintptr(webView), 0, 16)
        .arg(itemSize)
        .arg(text ? QStringLiteral("ok") : QStringLiteral("null"))
        .arg(menuParams ? QStringLiteral("non-null") : QStringLiteral("NULL"))
        .arg(quintptr(reinterpret_cast<const void*>(menuParams)), 0, 16));
    {
        const int cap = qMin(itemSize, 24);
        for (int i = 0; i < cap; ++i) {
            const QString t = textVec.value(i);
            const QString shortText = t.length() > 120 ? t.left(120) + QStringLiteral("…") : t;
            LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu]   item[%1] id=0x%2 text=\"%3\"")
                .arg(i)
                .arg(quintptr(ids[i]), 0, 16)
                .arg(shortText));
        }
        if (itemSize > cap)
            LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu]   ... (%1 more items)").arg(itemSize - cap));
    }

    WebWidget::EngineContextMenuInfo info;
    if (menuParams) {
        info.mediaType = static_cast<int>(menuParams->mediaType);
        info.isEditable = menuParams->isEditable;
        info.linkUrl = pickFirstNavigableLink(
            mbUtf8(menuParams->linkUrl),
            mbUtf8(menuParams->unfilteredLinkUrl),
            mbUtf8(menuParams->unfiltered_link_url));
        info.selectionText = fromWidePtr(menuParams->selectionText).trimmed();
        if (!info.selectionText.isEmpty())
            self->m_kernelSelectionText = info.selectionText;
        info.hasHitPoint = true;
        info.hitX = menuParams->x;
        info.hitY = menuParams->y;

        const QString selDbg = fromWidePtr(menuParams->selectionText);
        const QString selShort = selDbg.length() > 200 ? selDbg.left(200) + QStringLiteral("…") : selDbg;
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu] mbContextMenuParams: structSize=%1 mediaType=%2 x=%3 y=%4 isEditable=%5")
            .arg(menuParams->structSize)
            .arg(static_cast<int>(menuParams->mediaType))
            .arg(menuParams->x)
            .arg(menuParams->y)
            .arg(menuParams->isEditable ? 1 : 0));
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu]   linkUrl ptr=0x%1 utf8=\"%2\"")
            .arg(quintptr(reinterpret_cast<const void*>(menuParams->linkUrl)), 0, 16)
            .arg(mbUtf8(menuParams->linkUrl)));
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu]   unfilteredLinkUrl=\"%1\" unfiltered_link_url=\"%2\"")
            .arg(mbUtf8(menuParams->unfilteredLinkUrl))
            .arg(mbUtf8(menuParams->unfiltered_link_url)));
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu]   srcUrl=\"%1\"").arg(mbUtf8(menuParams->srcUrl)));
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu]   selectionText(WCHAR) len~%1 preview=\"%2\"")
            .arg(selDbg.length())
            .arg(selShort));
    } else {
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu] menuParams is NULL — 无 linkUrl/selectionText/坐标等内核命中信息"));
    }

    /* 仅缓存回调数据；统一由 showContextMenuForPage 的单通道定时点消费并弹菜单，避免竞态叠加菜单 */
    QTimer::singleShot(0, self, [self, idVec, textVec, info]() {
        if (!self)
            return;
        self->m_pendingEngineMenuIds = idVec;
        self->m_pendingEngineMenuTexts = textVec;
        self->m_pendingEngineMenuInfo = info;
        self->m_hasPendingEngineContextMenu = true;
        if (!info.selectionText.isEmpty())
            self->m_kernelSelectionText = info.selectionText;
        if (info.hasHitPoint) {
            self->m_lastRmbMbPos = QPoint(info.hitX, info.hitY);
            self->m_lastRmbValid = true;
        }
    });
    /* 该 DLL 下返回 TRUE 仍会弹内核菜单；改为 FALSE 以拦截默认菜单，仅保留应用自定义菜单 */
    LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu] returning FALSE (suppress built-in menu, use app menu only)"));
    return FALSE;
}

WebWidget::WebWidget(const QString& url, QWidget* parent, bool blankAddressBar)
    : QWidget(parent)
    , m_displayUrlEmpty(blankAddressBar)
{
    setFocusPolicy(Qt::StrongFocus);
    setAttribute(Qt::WA_InputMethodEnabled, true);
    setMouseTracking(true);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    setMinimumSize(64, 64);
    //setCursor(Qt::CrossCursor);
    //setContextMenuPolicy(Qt::NoContextMenu);

    //webView = mbCreateWebWindow(MB_WINDOW_TYPE_CONTROL, (HWND)this->winId(), 0, 0, this->width(), this->height());
    m_webView = mbCreateWebView();
    // 构造时 width/height 尚未经布局确定，先占位，真正尺寸在 syncViewport() 中设置
    mbResize(m_webView, 1, 1);
    m_loadingGuardTimer = new QTimer(this);
    m_loadingGuardTimer->setSingleShot(true);
    m_loadingGuardTimer->setInterval(2200);
    connect(m_loadingGuardTimer, &QTimer::timeout, this, [this]() {
        if (!m_lastIsLoading)
            return;
        setLoadingState(false);
    });

    mbOnPaintBitUpdated(m_webView, onPaintBitUpdatedCallback, this);
    if (mbSetContextMenuItemShow) {
        mbSetContextMenuItemShow(m_webView, kMbMenuGoForwardId, TRUE);
        mbSetContextMenuItemShow(m_webView, kMbMenuGoBackId, TRUE);
        mbSetContextMenuItemShow(m_webView, kMbMenuReloadId, TRUE);
    }
    LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu] api ptrs: setEnabled=0x%1 setCallback=0x%2 fireEvent=0x%3")
        .arg(quintptr(reinterpret_cast<const void*>(mbSetContextMenuEnabled)), 0, 16)
        .arg(quintptr(reinterpret_cast<const void*>(mbSetContextMenuCallback)), 0, 16)
        .arg(quintptr(reinterpret_cast<const void*>(mbFireContextMenuEvent)), 0, 16));
    if (mbSetContextMenuEnabled)
        mbSetContextMenuEnabled(m_webView, TRUE);
    if (mbSetContextMenuCallback) {
        mbSetContextMenuCallback(m_webView, onContextMenuPopup, this);
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu] callback registered: webView=0x%1 cb=0x%2 self=0x%3")
            .arg(quintptr(m_webView), 0, 16)
            .arg(quintptr(reinterpret_cast<const void*>(onContextMenuPopup)), 0, 16)
            .arg(quintptr(reinterpret_cast<const void*>(this)), 0, 16));
    } else {
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu] WARNING: mbSetContextMenuCallback is null, callback will never fire"));
    }
    mbOnURLChanged(m_webView, onUrlChangedCallback, this);
    mbOnTitleChanged(m_webView, onTitleChangedCallback, this);
    mbOnLoadingFinish(m_webView, onLoadingFinishCallback, this);
    if (mbOnDocumentReady)
        mbOnDocumentReady(m_webView, onDocumentReadyCallback, this);
    if (mbOnJsQuery)
        mbOnJsQuery(m_webView, onJsQueryCallback, this);

    if (mbSetNavigationToNewWindowEnable)
        mbSetNavigationToNewWindowEnable(m_webView, TRUE);
    if (mbOnNavigation)
        mbOnNavigation(m_webView, onNavigationAllowCallback, this);
    if (mbOnCreateView)
        mbOnCreateView(m_webView, onCreateViewCallback, this);
    if (mbOnClose)
        mbOnClose(m_webView, onCloseCallback, this);
    if (mbOnDownloadInBlinkThread)
        mbOnDownloadInBlinkThread(m_webView, onDownloadInBlinkThreadCallback, this);
    FAVICON_LOG() << "[favicon] mbOnNetGetFavicon ptr =" << (void*)mbOnNetGetFavicon;
    if (mbOnNetGetFavicon) {
        mbOnNetGetFavicon(m_webView, onNetGetFaviconCallback, this);
        qWarning().noquote() << "[LiteView][FAVICON][KERNEL] mbOnNetGetFavicon registered; icon/url from callback applied after load completes";
    } else {
        qWarning().noquote() << "[LiteView][FAVICON][KERNEL] mbOnNetGetFavicon is NULL (not exported) — kernel will not deliver favicon via this path";
    }
    if (mbOnFullscreenRequested)
        mbOnFullscreenRequested(m_webView, onFullscreenRequestedCallback, this);

#ifdef _WIN32
    HWND hWnd = (HWND)winId();
    mbSetHandle(m_webView, hWnd);
    // 离屏位图自绘时关闭 HWND 自动上屏，避免与 paint 冲突、视口尺寸异常
    if (mbSetAutoDrawToHwnd)
        mbSetAutoDrawToHwnd(m_webView, FALSE);
#endif

    const QString loadUrl = url.isEmpty() ? QStringLiteral("about:blank") : url;
    FAVICON_LOG() << "[favicon] initial load url =" << loadUrl;
    mbShowWindow(m_webView, TRUE);
    setLoadingState(true, true);
    mbLoadURL(m_webView, loadUrl.toUtf8().constData());

    QTimer::singleShot(0, this, [this]() { syncViewport(); });
    QTimer::singleShot(100, this, [this]() { syncViewport(); });

    if (mbGetUrl)
        m_lastUrl = mbUtf8(mbGetUrl(m_webView));
    if (mbGetTitle)
        m_lastTitle = mbUtf8(mbGetTitle(m_webView));

}

void WebWidget::preDestroyMiniblinkView()
{
    if (!m_webView)
        return;
    m_isDestroying = true;
    /* 先解除右键回调，避免 mbDestroyWebView 期间再次回调访问到即将销毁对象 */
    if (mbSetContextMenuCallback)
        mbSetContextMenuCallback(m_webView, nullptr, nullptr);
    if (mbOnClose)
        mbOnClose(m_webView, nullptr, nullptr);
    if (mbOnDocumentReady)
        mbOnDocumentReady(m_webView, nullptr, nullptr);
    /* 该 DLL 的 mbStopLoading 为 not impl，关闭阶段避免调用桩函数引发不稳定 */
    if (mbSetAudioMuted)
        mbSetAudioMuted(m_webView, TRUE);
    if (mbKillFocus)
        mbKillFocus(m_webView);
    if (mbShowWindow)
        mbShowWindow(m_webView, FALSE);
}

WebWidget::~WebWidget()
{
    preDestroyMiniblinkView();
    if (m_webView) {
        if (mbDestroyWebView)
            mbDestroyWebView(m_webView);
        m_webView = 0;
    }
}

void WebWidget::loadUrl(QString url)
{
    m_displayUrlEmpty = false;
    setLoadingState(true);
    qWarning().noquote() << "[LiteView][nav-trace] loadUrl mbLoadURL=" << url;
    mbLoadURL(m_webView, url.toUtf8().constData());
}

void WebWidget::loadHtml(const QString& html, const QString& baseUrl)
{
    m_displayUrlEmpty = true;
    setLoadingState(true);
    const QByteArray htmlUtf8 = html.toUtf8();
    const QByteArray baseUtf8 = (baseUrl.trimmed().isEmpty() ? QStringLiteral("about:blank") : baseUrl).toUtf8();
    if (mbLoadHtmlWithBaseUrl) {
        mbLoadHtmlWithBaseUrl(m_webView, htmlUtf8.constData(), baseUtf8.constData());
        return;
    }
    const QString dataUrl = QStringLiteral("data:text/html;charset=utf-8,%1")
        .arg(QString::fromLatin1(QUrl::toPercentEncoding(html)));
    mbLoadURL(m_webView, dataUrl.toUtf8().constData());
}

void WebWidget::loadBlankHome()
{
    m_displayUrlEmpty = true;
    setLoadingState(true);
    mbLoadURL(m_webView, QStringLiteral("about:blank").toUtf8().constData());
    scheduleBlankHomeBackgroundApply(this, QStringLiteral("about:blank"));
}

void WebWidget::setCreateNewTabHandler(const std::function<mbWebView(const QString&)>& handler)
{
    m_createNewTabHandler = handler;
}

void WebWidget::setAuthPopupTab(bool popup, WebWidget* opener)
{
    m_authPopupTab = popup;
    m_authPopupOpener = opener;
    m_authPopupOAuthSucceeded = false;
}

WebWidget* WebWidget::authPopupOpener() const
{
    return m_authPopupOpener.data();
}

bool WebWidget::authPopupShouldReloadOpener() const
{
    return m_authPopupOAuthSucceeded;
}

void WebWidget::goBack()
{
    if (m_webView) {
        setLoadingState(true);
        mbGoBack(m_webView);
    }
}

void WebWidget::goForward()
{
    if (m_webView) {
        setLoadingState(true);
        mbGoForward(m_webView);
    }
}

void WebWidget::reload()
{
    if (m_webView) {
        setLoadingState(true);
        mbReload(m_webView);
    }
}

void WebWidget::stop()
{
    if (m_webView) {
        if (mbStopLoading)
            mbStopLoading(m_webView);
        setLoadingState(false);
    }
}

void WebWidget::enterBrowserFullScreen()
{
    if (Widget* host = qobject_cast<Widget*>(window()))
        host->enterBrowserFullScreen(this);
}

void WebWidget::exitBrowserFullScreen()
{
    if (Widget* host = qobject_cast<Widget*>(window()))
        host->exitBrowserFullScreen();
}

bool WebWidget::isBrowserFullScreen() const
{
    if (const Widget* host = qobject_cast<const Widget*>(window()))
        return host->isBrowserFullScreen();
    return false;
}

bool WebWidget::toggleAudioMute()
{
    if (!m_webView || !mbSetAudioMuted)
        return false;
    if (mbIsAudioMuted) {
        const BOOL now = mbIsAudioMuted(m_webView);
        mbSetAudioMuted(m_webView, now ? FALSE : TRUE);
    } else {
        m_assumedAudioMuted = !m_assumedAudioMuted;
        mbSetAudioMuted(m_webView, m_assumedAudioMuted ? TRUE : FALSE);
    }
    const bool muted = isAudioMuted();
    emit audioMuteChanged(muted);
    return true;
}

bool WebWidget::isAudioMuted() const
{
    if (!m_webView || !mbSetAudioMuted)
        return false;
    if (mbIsAudioMuted)
        return mbIsAudioMuted(m_webView) != FALSE;
    return m_assumedAudioMuted;
}

QString WebWidget::currentUrl() const
{
    if (!m_webView)
        return QString();
    if (m_displayUrlEmpty)
        return QString();
    if (!mbGetUrl)
        return m_lastUrl;
    return mbUtf8(mbGetUrl(m_webView));
}

QString WebWidget::title() const
{
    if (!m_webView)
        return QString();
    if (!mbGetTitle)
        return m_lastTitle;
    return mbUtf8(mbGetTitle(m_webView));
}

bool WebWidget::isLoading() const
{
    if (!m_webView)
        return false;
    return m_lastIsLoading;
}

bool WebWidget::cancelDownload(const QString& savePath)
{
    if (savePath.trimmed().isEmpty() || !mbNetCancelRequest)
        return false;
    mbNetJob job = nullptr;
    {
        QMutexLocker locker(&g_downloadJobMapMutex);
        job = g_downloadJobByPath.value(savePath, nullptr);
        if (!job)
            return false;
        g_cancelRequestedPaths.insert(savePath);
    }
    mbNetCancelRequest(job);
    return true;
}

void WebWidget::releaseMouseCapture()
{
    if (m_isCaptured) {
        releaseMouse();
        m_isCaptured = false;
    }
}

void WebWidget::syncViewport()
{
    if (!m_webView)
        return;
    int w = qMax(1, width());
    int h = qMax(1, height());
#ifdef Q_OS_WIN
    if (HWND hwnd = reinterpret_cast<HWND>(winId())) {
        RECT rc;
        if (GetClientRect(hwnd, &rc)) {
            w = qMax(1, static_cast<int>(rc.right - rc.left));
            h = qMax(1, static_cast<int>(rc.bottom - rc.top));
        }
    }
#endif
    m_mbPixelW = w;
    m_mbPixelH = h;
    if (mbResize)
        mbResize(m_webView, w, h);
#ifdef _WIN32
    if (mbSetAutoDrawToHwnd)
        mbSetAutoDrawToHwnd(m_webView, FALSE);
#endif
    if (mbWake)
        mbWake(m_webView);
    update();
}

QPoint WebWidget::mapEventToMb(const QPoint& logicalPos) const
{
    const int lw = qMax(1, width());
    const int lh = qMax(1, height());
    const int mw = qMax(1, m_mbPixelW);
    const int mh = qMax(1, m_mbPixelH);
    const int x = qRound(logicalPos.x() * double(mw) / double(lw));
    const int y = qRound(logicalPos.y() * double(mh) / double(lh));
    return QPoint(x, y);
}

QPoint WebWidget::mapMbToWidget(const QPoint& mbPos) const
{
    const int lw = qMax(1, width());
    const int lh = qMax(1, height());
    const int mw = qMax(1, m_mbPixelW);
    const int mh = qMax(1, m_mbPixelH);
    const int x = qRound(mbPos.x() * double(lw) / double(mw));
    const int y = qRound(mbPos.y() * double(lh) / double(mh));
    return QPoint(x, y);
}

QRect WebWidget::caretRectInWidgetCoords() const
{
    if (!m_webView || !mbGetCaretRect)
        return QRect();
    mbRect r;
    mbGetCaretRect(m_webView, &r);
    int w = r.w;
    int h = r.h;
    if (w <= 0)
        w = 1;
    if (h <= 0)
        h = qMax(1, fontMetrics().height());
    const QPoint tl = mapMbToWidget(QPoint(r.x, r.y));
    const QPoint br = mapMbToWidget(QPoint(r.x + w, r.y + h));
    const int outW = qMax(1, br.x() - tl.x());
    const int outH = qMax(1, br.y() - tl.y());
    return QRect(tl, QSize(outW, outH));
}

void WebWidget::scheduleInputMethodCursorUpdate()
{
    if (!m_imeCursorUpdateTimer) {
        m_imeCursorUpdateTimer = new QTimer(this);
        m_imeCursorUpdateTimer->setSingleShot(true);
        m_imeCursorUpdateTimer->setInterval(0);
        connect(m_imeCursorUpdateTimer, &QTimer::timeout, this, &WebWidget::updateInputMethodCursorRectNow);
    }
    if (!m_imeCursorUpdateTimer->isActive())
        m_imeCursorUpdateTimer->start();
}

void WebWidget::updateInputMethodCursorRectNow()
{
    if (!hasFocus())
        return;
    const QRect now = caretRectInWidgetCoords();
    if (!m_hasCachedImCursorRect || now != m_cachedImCursorRect) {
        m_cachedImCursorRect = now;
        m_hasCachedImCursorRect = true;
        if (QInputMethod* im = QGuiApplication::inputMethod())
            im->update(Qt::ImCursorRectangle | Qt::ImMicroFocus);
    }
}

void WebWidget::resizeEvent(QResizeEvent *event)
{
    QWidget::resizeEvent(event);
    syncViewport();
    scheduleInputMethodCursorUpdate();
}

void WebWidget::showEvent(QShowEvent* event)
{
    QWidget::showEvent(event);
    syncViewport();
    QTimer::singleShot(0, this, [this]() { syncViewport(); });
    scheduleInputMethodCursorUpdate();
}

void WebWidget::onMove()
{
    // QPoint pos=this->mapToGlobal(QPoint(0,0));
    // wkeMoveWindow(webView,pos.x(),pos.y(),this->width(),this->height());
    //wkeRunJSW(webView,"ggg");
}

static void MB_CALL_TYPE onPaintBitUpdatedCallback(mbWebView webView, void* param, const void* buffer, const mbRect* r, int width, int height)
{
    WebWidget* self = (WebWidget*)param;
    if (!self || !r)
        return;
    self->onPaintBitUpdated(webView, buffer, r, width, height);
    //     int size = width * height;
    //     int whiteSize = 0;
    //     for (int y = 0; y < height; y++) {
    //         for (int x = 0; x < width; x++) {
    //             const unsigned int* ptr = (const unsigned int*)buffer;
    //             const unsigned int* ptrDst = &((ptr)[x + y * width]);
    //             int c = *ptrDst;
    //             if (c & 0xff000000) {
    //                 whiteSize++;
    //             }
    //         }
    //     }
    //     if (size == whiteSize)
    //         OutputDebugStringA("onPaintBitUpdatedCallback fail\n");
    //     else
    //         OutputDebugStringA("onPaintBitUpdatedCallback ok\n");
}

void MB_CALL_TYPE onUrlChangedCallback(mbWebView webView, void* param, const utf8* url, BOOL canGoBack, BOOL canGoForward)
{
    WebWidget* self = (WebWidget*)param;
    if (!self)
        return;
    const QString qurl = mbUtf8(url);
    QMetaObject::invokeMethod(
        self,
        "onUrlChangedQueued",
        Qt::QueuedConnection,
        Q_ARG(QString, qurl),
        Q_ARG(bool, !!canGoBack),
        Q_ARG(bool, !!canGoForward));
}

void MB_CALL_TYPE onTitleChangedCallback(mbWebView webView, void* param, const utf8* title)
{
    WebWidget* self = (WebWidget*)param;
    if (!self)
        return;
    const QString qtitle = mbUtf8(title);
    QMetaObject::invokeMethod(
        self,
        "onTitleChangedQueued",
        Qt::QueuedConnection,
        Q_ARG(QString, qtitle));
}

void MB_CALL_TYPE onLoadingFinishCallback(mbWebView webView, void* param, mbWebFrameHandle frameId, const utf8* url, mbLoadingResult result, const utf8* failedReason)
{
    WebWidget* self = (WebWidget*)param;
    if (!self)
        return;
    /* 仅主帧：部分站点子帧先结束/反复结束，若据此清加载态会与主文档不同步；东财等主帧 Finish 若缺失由 documentReady 兜底 */
    if (frameId) {
        if (mbIsMainFrame && webView) {
            if (!mbIsMainFrame(webView, frameId))
                return;
        } else if (mbWebFrameGetMainFrame && webView) {
            const mbWebFrameHandle mainFr = mbWebFrameGetMainFrame(webView);
            if (mainFr && mainFr != frameId)
                return;
        }
    }
    const QString qurl = mbUtf8(url);
    const QString qreason = mbUtf8(failedReason);
    const bool ok = (result == MB_LOADING_SUCCEEDED);
    QMetaObject::invokeMethod(
        self,
        "onLoadingFinishQueued",
        Qt::QueuedConnection,
        Q_ARG(QString, qurl),
        Q_ARG(bool, ok),
        Q_ARG(QString, qreason));
}

void MB_CALL_TYPE onDocumentReadyCallback(mbWebView webView, void* param, mbWebFrameHandle frameId)
{
    WebWidget* self = static_cast<WebWidget*>(param);
    if (!self || self->m_webView != webView || self->m_isDestroying)
        return;
    if (frameId) {
        if (mbIsMainFrame && webView) {
            if (!mbIsMainFrame(webView, frameId))
                return;
        } else if (mbWebFrameGetMainFrame && webView) {
            const mbWebFrameHandle mainFr = mbWebFrameGetMainFrame(webView);
            if (mainFr && mainFr != frameId)
                return;
        }
    }
    QMetaObject::invokeMethod(self, "onDocumentReadyQueued", Qt::QueuedConnection);
}

void MB_CALL_TYPE onNetGetFaviconCallback(mbWebView webView, void* param, const utf8* url, mbMemBuf* buf)
{
    Q_UNUSED(webView);
    WebWidget* self = static_cast<WebWidget*>(param);
    if (!self)
        return;
    const QString favUrl = mbUtf8(url);
    if (buf && mbFreeMemBuf)
        mbFreeMemBuf(buf);
    qWarning().noquote() << "[LiteView][FAVICON][KERNEL] mbOnNetGetFavicon callback url=" << favUrl;
    FAVICON_LOG() << "[favicon] callback url =" << favUrl;
    QMetaObject::invokeMethod(self, "onFaviconArrived", Qt::QueuedConnection, Q_ARG(QString, favUrl));
}

void WebWidget::onFaviconArrived(const QString& iconUrl)
{
    qWarning().noquote() << "[LiteView][FAVICON][KERNEL] onFaviconArrived (UI thread) url=" << iconUrl;
    if (m_lastIsLoading) {
        m_hasDeferredKernelFavicon = true;
        m_deferredKernelFaviconUrl = iconUrl;
        qWarning().noquote() << "[LiteView][FAVICON][KERNEL] deferred until load finished — will fetch icon URL then";
        FAVICON_LOG() << "[favicon] defer kernel favicon until load done, url =" << iconUrl;
        return;
    }
    processKernelFaviconPayload(iconUrl);
}

void WebWidget::flushDeferredKernelFavicon()
{
    if (!m_hasDeferredKernelFavicon)
        return;
    m_hasDeferredKernelFavicon = false;
    const QString u = m_deferredKernelFaviconUrl;
    m_deferredKernelFaviconUrl.clear();
    processKernelFaviconPayload(u);
}

void WebWidget::emitDefaultFavicon()
{
    const QIcon def = FaviconCache::defaultTabIcon();
    emit faviconChanged(def.isNull() ? QIcon() : def);
}

void WebWidget::applyFaviconForPageUrl(const QString& pageUrl)
{
    const QString u = pageUrl.trimmed();
    if (u.isEmpty() || u == QStringLiteral("about:blank"))
        return;
    m_faviconPageUrl = u;
    const QIcon cached = FaviconCache::loadIconForPageUrl(u);
    if (!cached.isNull()) {
        FAVICON_LOG() << "[favicon] tab icon from cache, page =" << u;
        emit faviconChanged(cached);
        return;
    }
    emitDefaultFavicon();
    if (!mbOnNetGetFavicon)
        requestFaviconForPage(u);
}

QImage WebWidget::decodeFaviconImage(const QByteArray& payload)
{
    if (payload.isEmpty())
        return QImage();
    QImage image = QImage::fromData(payload);
    if (!image.isNull())
        return image;
    QPixmap pm;
    if (pm.loadFromData(payload))
        return pm.toImage();
    return QImage();
}

void WebWidget::processKernelFaviconPayload(const QString& iconUrl)
{
    const QString trimmed = iconUrl.trimmed();
    if (!trimmed.isEmpty()) {
        const QUrl reqUrl = QUrl::fromUserInput(trimmed);
        if (reqUrl.isValid() && !reqUrl.host().isEmpty()) {
            qWarning().noquote() << "[LiteView][FAVICON][KERNEL] HTTP fetch tab icon from kernel URL ->" << reqUrl.toString()
                                 << " sslSupported=" << QSslSocket::supportsSsl();
            FAVICON_LOG() << "[favicon] GET icon url =" << reqUrl.toString();
            requestFaviconUrl(reqUrl, false);
            return;
        }
    }
    qWarning().noquote() << "[LiteView][FAVICON][KERNEL] invalid or empty icon URL — use default tab icon";
    emitDefaultFavicon();
}

void WebWidget::onFaviconDownloadFinished(QNetworkReply* reply)
{
    if (!reply)
        return;
    if (reply == m_activeFaviconReply)
        m_activeFaviconReply = nullptr;
    const quint64 fetchId = reply->property("faviconFetchId").toULongLong();
    if (fetchId != 0 && fetchId != m_faviconFetchId) {
        qWarning().noquote() << "[LiteView][FAVICON] stale fetch ignored id=" << fetchId << " current=" << m_faviconFetchId;
        reply->deleteLater();
        return;
    }
    const QString replyUrl = reply->url().toString();
    const QString requestedUrl = reply->property("requestedFaviconUrl").toString();
    const bool retriedHttp = reply->property("retriedHttp").toBool();
    const QByteArray payload = reply->readAll();
    const QNetworkReply::NetworkError netErr = reply->error();
    const QString errText = reply->errorString();
    const bool ok = (netErr == QNetworkReply::NoError);
    QString pageUrl = reply->property("faviconPageUrl").toString();
    reply->deleteLater();
    if (netErr == QNetworkReply::OperationCanceledError) {
        FAVICON_LOG() << "[favicon] download canceled:" << requestedUrl;
        return;
    }
    if (!ok) {
        QUrl reqUrl(requestedUrl.isEmpty() ? replyUrl : requestedUrl);
        if (!retriedHttp && reqUrl.isValid() && reqUrl.scheme().compare(QStringLiteral("https"), Qt::CaseInsensitive) == 0) {
            reqUrl.setScheme(QStringLiteral("http"));
            qWarning().noquote() << "[LiteView][FAVICON] https failed, retry http ->" << reqUrl.toString()
                                 << " err=" << static_cast<int>(netErr) << errText;
            requestFaviconUrl(reqUrl, true);
            return;
        }
        qWarning().noquote() << "[LiteView][FAVICON] download failed url=" << replyUrl
                             << " err=" << static_cast<int>(netErr) << errText
                             << " bytes=" << payload.size();
        emitDefaultFavicon();
        return;
    }
    QImage image = decodeFaviconImage(payload);
    if (image.isNull()) {
        qWarning().noquote() << "[LiteView][FAVICON] decode failed url=" << replyUrl << " bytes=" << payload.size();
        emitDefaultFavicon();
        return;
    }
    if (pageUrl.trimmed().isEmpty())
        pageUrl = m_faviconPageUrl;
    if (pageUrl.trimmed().isEmpty())
        pageUrl = m_lastUrl;
    if (!pageUrl.trimmed().isEmpty())
        FaviconCache::saveIconForPageUrl(pageUrl, image);
    qWarning().noquote() << "[LiteView][FAVICON] saved to cache page=" << pageUrl << " size=" << image.width() << "x" << image.height();
    FAVICON_LOG() << "[favicon] saved to cache, page =" << pageUrl << ", size =" << image.size();
    emit faviconChanged(QIcon(QPixmap::fromImage(image)));
}

void WebWidget::requestFaviconUrl(const QUrl& url, bool retriedHttp)
{
    if (!url.isValid())
        return;
    if (!m_faviconNet) {
        m_faviconNet = new QNetworkAccessManager(this);
        connect(m_faviconNet, &QNetworkAccessManager::finished, this, &WebWidget::onFaviconDownloadFinished);
    }
    if (m_activeFaviconReply) {
        m_activeFaviconReply->abort();
        m_activeFaviconReply->deleteLater();
        m_activeFaviconReply = nullptr;
    }
    const QString target = url.toString();
    m_pendingFaviconUrl = target;
    const quint64 fetchId = ++m_faviconFetchId;
    QNetworkRequest req(url);
    req.setAttribute(QNetworkRequest::FollowRedirectsAttribute, true);
    const QString pageUrl = m_faviconPageUrl.isEmpty() ? m_lastUrl : m_faviconPageUrl;
    if (!pageUrl.trimmed().isEmpty()) {
        QUrl referer = QUrl::fromUserInput(pageUrl.trimmed());
        if (referer.isValid())
            req.setRawHeader("Referer", referer.toString().toUtf8());
    }
    QNetworkReply* reply = m_faviconNet->get(req);
    if (reply) {
        m_activeFaviconReply = reply;
        reply->setProperty("requestedFaviconUrl", target);
        reply->setProperty("retriedHttp", retriedHttp);
        reply->setProperty("faviconPageUrl", pageUrl);
        reply->setProperty("faviconFetchId", QVariant::fromValue(fetchId));
    }
}

void WebWidget::requestFaviconForPage(const QString& pageUrl)
{
    QUrl page = QUrl::fromUserInput(pageUrl.trimmed());
    if (!page.isValid() || page.host().isEmpty())
        return;
    page.setPath(QStringLiteral("/favicon.ico"));
    page.setQuery(QString());
    page.setFragment(QString());
    requestFaviconUrl(page, false);
    FAVICON_LOG() << "[favicon] proactive fetch =" << page.toString();
}

void WebWidget::onUrlChangedQueued(const QString& url, bool canGoBack, bool canGoForward)
{
    handleUrlChanged(url, canGoBack, canGoForward);
}

void WebWidget::onTitleChangedQueued(const QString& title)
{
    handleTitleChanged(title);
}

void WebWidget::onLoadingFinishQueued(const QString& url, bool ok, const QString& failedReason)
{
    handleLoadingFinished(url, ok, failedReason);
    if (ok) {
        scheduleBlankHomeBackgroundApply(this, url);
        installWebClipboardSyncHook(m_webView);
    }
}

void WebWidget::onDocumentReadyQueued()
{
    if (m_isDestroying)
        return;
    /* 东财等站主文档 mbOnLoadingFinish 可能迟迟不回调，但 DOM 已就绪；结束加载态以便标签 favicon/刷新按钮恢复 */
    setLoadingState(false);
    maybeCloseAuthPopupAfterOAuth(m_lastUrl);
    installWebClipboardSyncHook(m_webView);
}

void WebWidget::applyWebPageCopiedText(const QString& text)
{
    if (!text.isEmpty())
        setClipboardPlainText(text);
}

void WebWidget::onInternalActionUrlQueued(const QString& url)
{
    emit internalActionUrlTriggered(url);
}

void WebWidget::onDownloadStartedQueued(const QString& url, const QString& savePath, qint64 totalBytes)
{
    emit downloadStarted(url, savePath, totalBytes);
}

void WebWidget::onDownloadProgressQueued(const QString& url, const QString& savePath, qint64 receivedBytes, qint64 totalBytes)
{
    emit downloadProgress(url, savePath, receivedBytes, totalBytes);
}

void WebWidget::onDownloadFinishedQueued(const QString& url, const QString& savePath, bool ok, const QString& reason)
{
    emit downloadFinished(url, savePath, ok, reason);
}

void WebWidget::handleUrlChanged(const QString& url, bool canGoBack, bool canGoForward)
{
    const QString prevUrl = m_lastUrl;
    m_lastUrl = url;
    m_lastCanGoBack = canGoBack;
    m_lastCanGoForward = canGoForward;
    if (m_displayUrlEmpty) {
        const QString t = url.trimmed();
        if (!t.isEmpty() && t != QStringLiteral("about:blank"))
            m_displayUrlEmpty = false;
    }
    if (prevUrl != url) {
        FAVICON_LOG() << "[favicon] url changed:" << prevUrl << "->" << url;
        m_kernelSelectionText.clear();
        /* 加载中多次 URL 变更多为重定向；保留延迟队列中的内核图标 URL */
        if (!m_lastIsLoading) {
            m_hasDeferredKernelFavicon = false;
            m_deferredKernelFaviconUrl.clear();
        }
        m_pendingFaviconUrl.clear();
        applyFaviconForPageUrl(url);
    }
    emit urlChanged(m_displayUrlEmpty ? QString() : url);
    emit navigationStateChanged(canGoBack, canGoForward);
    maybeCloseAuthPopupAfterOAuth(url);
    /* 不在此根据 mbIsLoading 同步加载态：东方财富等站会持续请求，mbIsLoading 长期为 TRUE，
     * 会在主文档 onLoadingFinish 已结束后再次把标签打成「加载中」且无法收到新的 Finish。 */
}

void WebWidget::handleTitleChanged(const QString& title)
{
    m_lastTitle = title;
    emit titleChanged(title);
}

void WebWidget::handleLoadingFinished(const QString& url, bool ok, const QString& failedReason)
{
    if (ok)
        injectPageScrollbarStyle(m_webView);
    setLoadingState(false);
    if (ok)
        maybeCloseAuthPopupAfterOAuth(url);
    emit loadFinished(url, ok, failedReason);
}

void WebWidget::maybeCloseAuthPopupAfterOAuth(const QString& url)
{
    if (!m_authPopupTab || m_authPopupCloseScheduled || m_isDestroying)
        return;
    if (!isLikelyOAuthCallbackUrl(url))
        return;
    m_authPopupOAuthSucceeded = true;
    m_authPopupCloseScheduled = true;
    QTimer::singleShot(400, this, [this]() {
        if (m_isDestroying)
            return;
        emit closeTabRequested();
    });
}

void WebWidget::onWindowCloseRequested()
{
    if (!m_authPopupTab || m_authPopupCloseScheduled || m_isDestroying)
        return;
    if (isLikelyOAuthCallbackUrl(m_lastUrl))
        m_authPopupOAuthSucceeded = true;
    m_authPopupCloseScheduled = true;
    emit closeTabRequested();
}

void WebWidget::setLoadingState(bool loading, bool forceEmit)
{
    const bool wasLoading = m_lastIsLoading;

    if (loading) {
        /* 仅在刚进入加载态时启动 guard；避免 SPA 反复 URL 回调把单发定时器不断 restart 导致永不超时 */
        if (m_loadingGuardTimer && (!wasLoading || forceEmit))
            m_loadingGuardTimer->start();
    } else {
        if (m_loadingGuardTimer)
            m_loadingGuardTimer->stop();
    }
    if (forceEmit || m_lastIsLoading != loading) {
        m_lastIsLoading = loading;
        emit loadingChanged(loading);
    } else {
        m_lastIsLoading = loading;
    }
    if (!loading)
        flushDeferredKernelFavicon();
}

QString WebWidget::linkUrlAtPoint(const QPoint& mbPoint) const
{
    if (!m_webView || !mbRunJsSync || !mbJsToString || !mbWebFrameGetMainFrame)
        return QString();
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(m_webView);
    /* 与 selectedTextFromPageAtPoint 一致：主文档 elementFromPoint 常命中 iframe 外壳，须递归进同源子帧取 a[href] */
    const QString js = QString::fromLatin1(
        "(function(x,y){"
        "function hrefFromEl(e){"
        "if(!e)return'';"
        "var c=e.closest&&e.closest('a[href]');"
        "if(c&&c.href)return String(c.href);"
        "if(e.closest){c=e.closest('area[href]');if(c&&c.href)return String(c.href);}"
        "if(e.closest){c=e.closest('a');if(c){var xh=c.getAttribute&&c.getAttribute('xlink:href');"
        "if(xh)return String(xh);if(c.href)return String(c.href);}}"
        "var t=e;"
        "while(t){"
        "if(t.tagName&&String(t.tagName).toLowerCase()==='a'&&t.href)return String(t.href);"
        "t=t.parentElement;"
        "}"
        "return'';"
        "}"
        "function hitLink(w,x,y,d){"
        "if(d>12||!w||!w.document)return'';"
        "try{"
        "var e=w.document.elementFromPoint(x,y);"
        "if(!e)return'';"
        "var h=hrefFromEl(e);"
        "if(h)return h;"
        "if(String(e.tagName).toLowerCase()==='iframe'){"
        "var r=e.getBoundingClientRect();"
        "var cw=e.contentWindow;"
        "if(cw)return hitLink(cw,x-r.left,y-r.top,d+1);"
        "}"
        "return'';"
        "}catch(z){return'';}"
        "}"
        "try{return hitLink(window,x,y,0)||'';}catch(e){return'';}"
        "})(%1,%2)").arg(mbPoint.x()).arg(mbPoint.y());
    return evalPageJsReturnString(m_webView, frame, js.toUtf8());
}

QString WebWidget::selectedTextFromPageAtPoint(const QPoint& mbPoint) const
{
    if (!m_webView || !mbRunJsSync || !mbJsToString || !mbWebFrameGetMainFrame)
        return QString();
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(m_webView);
    /* 先遍历主文档与同源 iframe 的 Selection（新闻页常见），再按坐标 elementFromPoint 兜底；
       勿在读取前向内核注入 WM_RBUTTON*，否则部分页面会提前折叠选区导致始终为空 */
    const QString js = QString::fromLatin1(
        "(function(x,y){"
        "function gs(w){try{var s=w.getSelection&&w.getSelection();return s?s.toString():\"\";}catch(e){return\"\";}}"
        "function walk(w,d){if(d>12)return\"\";var t=gs(w);if(t)return t;"
        "try{var L=w.document.querySelectorAll(\"iframe\");"
        "for(var i=0;i<L.length;i++){try{var c=L[i].contentWindow;if(c){t=walk(c,d+1);if(t)return t;}}catch(e){}}"
        "}catch(e){}return\"\";}"
        "try{var t=walk(window,0);if(t)return t;"
        "if(typeof x===\"number\"&&typeof y===\"number\"&&x>=0&&y>=0){"
        "var e=document.elementFromPoint(x,y);if(e){var w=(e.ownerDocument||document).defaultView||window;t=gs(w);if(t)return t;}}"
        "return gs(window);}catch(e){return\"\";}})(%1,%2)")
        .arg(mbPoint.x())
        .arg(mbPoint.y());
    return evalPageJsReturnString(m_webView, frame, js.toUtf8());
}

QString WebWidget::selectedTextForContextMenuAt(const QPoint& mbPoint) const
{
    Q_UNUSED(mbPoint);
    return kernelSelectedText();
}

QString WebWidget::kernelSelectedText() const
{
    return m_kernelSelectionText;
}

bool WebWidget::hitIsEditableFieldAtMb(const QPoint& mbPoint) const
{
    if (!m_webView || !mbRunJsSync || !mbJsToString || !mbWebFrameGetMainFrame)
        return false;
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(m_webView);
    const QString js = QString::fromLatin1(
        "(function(x,y){"
        "try{"
        "if(typeof x!=='number'||typeof y!=='number')return'';"
        "var d=document,e=d.elementFromPoint(x,y);"
        "if(!e)return'';"
        "var n=String(e.nodeName||'').toLowerCase();"
        "if(e.isContentEditable)return'1';"
        "if(n==='textarea')return'1';"
        "if(n==='input'){"
        "var t=(e.type||'text').toLowerCase();"
        "if(t==='text'||t==='search'||t==='url'||t==='email'||t==='password'||t==='tel'||t==='number'||t==='')return'1';"
        "}"
        "if(e.closest){var p=e.closest('[contenteditable]');if(p&&p.getAttribute('contenteditable')!=='false')return'1';}"
        "return'';"
        "}catch(z){return'';}"
        "})(%1,%2)")
        .arg(mbPoint.x())
        .arg(mbPoint.y());
    return evalPageJsReturnString(m_webView, frame, js.toUtf8()).trimmed() == QStringLiteral("1");
}

static QString buildPastePlainTextJs(const QPoint& mbPoint, const QByteArray& jsonPayload)
{
    return QStringLiteral("(function(x,y,a){"
                          "try{"
                          "var t=(a&&a.length)?a[0]:'';"
                          "if(typeof t!=='string'||t.length===0)return'';"
                          "function isEd(e){"
                          "if(!e)return false;"
                          "var n=String(e.nodeName||'').toLowerCase();"
                          "if(e.isContentEditable)return true;"
                          "if(n==='textarea')return true;"
                          "if(n==='input'){"
                          "var ty=(e.type||'text').toLowerCase();"
                          "return ty==='text'||ty==='search'||ty==='url'||ty==='email'||ty==='tel'||ty==='password'||ty==='number'||ty==='';"
                          "}"
                          "return false;"
                          "}"
                          "function ins(el,t){"
                          "var n=String(el.tagName||'').toLowerCase();"
                          "el.focus();"
                          "if(n==='input'||n==='textarea'){"
                          "var v=el.value||'',st=0,ed=v.length;"
                          "if(typeof el.selectionStart==='number'){st=el.selectionStart;ed=el.selectionEnd;}"
                          "el.value=v.slice(0,st)+t+v.slice(ed);"
                          "if(typeof el.selectionStart==='number'){var p=st+t.length;el.selectionStart=el.selectionEnd=p;}"
                          "try{el.dispatchEvent(new InputEvent('input',{bubbles:true,inputType:'insertFromPaste',data:t}));}catch(e1){"
                          "try{el.dispatchEvent(new Event('input',{bubbles:true}));}catch(e2){}"
                          "}"
                          "try{el.dispatchEvent(new Event('change',{bubbles:true}));}catch(e3){}"
                          "return true;"
                          "}"
                          "if(el.isContentEditable&&document.queryCommandSupported&&document.queryCommandSupported('insertText')){"
                          "return document.execCommand('insertText',false,t);"
                          "}"
                          "return false;"
                          "}"
                          "function pick(w,x,y,d){"
                          "if(d>12||!w||!w.document)return null;"
                          "try{"
                          "var e=w.document.elementFromPoint(x,y);"
                          "if(!e)return null;"
                          "for(var el=e;el;el=el.parentElement){if(isEd(el))return el;}"
                          "if(String(e.tagName).toLowerCase()==='iframe'){"
                          "var r=e.getBoundingClientRect();"
                          "var cw=e.contentWindow;"
                          "if(cw)return pick(cw,x-r.left,y-r.top,d+1);"
                          "}"
                          "var ae=w.document.activeElement;"
                          "if(ae&&isEd(ae))return ae;"
                          "}catch(z){}"
                          "return null;"
                          "}"
                          "var el=pick(window,x,y,0);"
                          "if(!el){try{var ae=document.activeElement;if(ae&&isEd(ae))el=ae;}catch(z0){}}"
                          "if(!el)return'';"
                          "return ins(el,t)?'1':'';"
                          "}catch(z){return'';}"
                          "})(%1,%2,")
               .arg(mbPoint.x())
               .arg(mbPoint.y())
        + QString::fromUtf8(jsonPayload)
        + QStringLiteral(")");
}

bool WebWidget::focusEditableAtMbPoint(mbWebView webView, const QPoint& mbPoint)
{
    if (!webView || !mbWebFrameGetMainFrame)
        return false;
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(webView);
    const QString js = QString::fromLatin1(
        "(function(x,y){"
        "function isEd(e){"
        "if(!e)return false;"
        "var n=String(e.nodeName||'').toLowerCase();"
        "if(e.isContentEditable)return true;"
        "if(n==='textarea')return true;"
        "if(n==='input'){"
        "var ty=(e.type||'text').toLowerCase();"
        "return ty==='text'||ty==='search'||ty==='url'||ty==='email'||ty==='tel'||ty==='password'||ty==='number'||ty==='';"
        "}"
        "return false;"
        "}"
        "function pick(w,x,y,d){"
        "if(d>12||!w||!w.document)return null;"
        "try{"
        "var e=w.document.elementFromPoint(x,y);"
        "if(!e)return null;"
        "for(var el=e;el;el=el.parentElement){if(isEd(el))return el;}"
        "if(String(e.tagName).toLowerCase()==='iframe'){"
        "var r=e.getBoundingClientRect();"
        "var cw=e.contentWindow;"
        "if(cw)return pick(cw,x-r.left,y-r.top,d+1);"
        "}"
        "var ae=w.document.activeElement;"
        "if(ae&&isEd(ae))return ae;"
        "}catch(z){}"
        "return null;"
        "}"
        "try{"
        "var el=pick(window,x,y,0);"
        "if(!el)return'';"
        "el.focus();"
        "return'1';"
        "}catch(z){return'';}"
        "})(%1,%2)")
        .arg(mbPoint.x())
        .arg(mbPoint.y());
    return evalPageJsReturnString(webView, frame, js.toUtf8()).trimmed() == QStringLiteral("1");
}

bool WebWidget::fireSyntheticCtrlV(mbWebView webView)
{
    if (!webView || !mbFireKeyDownEvent || !mbFireKeyUpEvent)
        return false;
    constexpr unsigned int kVkControl = 0x11;
    constexpr unsigned int kVkV = 0x56;
    mbFireKeyDownEvent(webView, kVkControl, 0, FALSE);
    mbFireKeyDownEvent(webView, kVkV, MK_CONTROL, FALSE);
    if (mbFireKeyPressEvent)
        mbFireKeyPressEvent(webView, static_cast<unsigned int>('V'), MK_CONTROL, FALSE);
    mbFireKeyUpEvent(webView, kVkV, MK_CONTROL, FALSE);
    mbFireKeyUpEvent(webView, kVkControl, 0, FALSE);
    return true;
}

bool WebWidget::pastePlainTextAtMb(const QPoint& mbPoint, const QString& clip)
{
    if (!m_webView || clip.isEmpty())
        return false;

    QPoint pt = mbPoint;
    if ((pt.x() <= 0 && pt.y() <= 0) && m_lastRmbValid)
        pt = m_lastRmbMbPos;

    setFocus();
    if (mbSetFocus)
        mbSetFocus(m_webView);

    focusMbPointByClick(m_webView, pt);

    const QByteArray jsonText = QJsonDocument(QJsonArray{clip}).toJson(QJsonDocument::Compact);
    const QByteArray pasteAtJs = buildPastePlainTextJs(pt, jsonText).toUtf8();

    if (mbWebFrameGetMainFrame) {
        const mbWebFrameHandle frame = mbWebFrameGetMainFrame(m_webView);
        if (evalPageJsPasteOk(m_webView, frame, pasteAtJs))
            return true;
    }

    return typePlainTextViaMbKeyPress(m_webView, clip);
}

bool WebWidget::pasteFromSystemClipboardAtMb(const QPoint& mbPoint)
{
    const QString clip = textForPaste(this);
    if (clip.isEmpty())
        return false;

    QPoint pt = mbPoint;
    if ((pt.x() <= 0 && pt.y() <= 0) && m_lastRmbValid)
        pt = m_lastRmbMbPos;

    const QString clipCopy = clip;
    const QPoint ptCopy = pt;
    QTimer::singleShot(0, this, [this, ptCopy, clipCopy]() {
        if (!m_isDestroying)
            pastePlainTextAtMb(ptCopy, clipCopy);
    });
    return true;
}

bool WebWidget::pastePlainTextFromClipboardAtMb(const QPoint& mbPoint) const
{
    if (!m_webView || !mbWebFrameGetMainFrame)
        return false;
    const QString clip = systemClipboardText();
    if (clip.isEmpty())
        return false;
    QJsonArray payload;
    payload.append(clip);
    const QByteArray jsonText = QJsonDocument(payload).toJson(QJsonDocument::Compact);
    const QString js = buildPastePlainTextJs(mbPoint, jsonText);
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(m_webView);
    return evalPageJsReturnString(m_webView, frame, js.toUtf8()).trimmed() == QStringLiteral("1");
}

bool WebWidget::pastePlainTextToFocusedField(const QString& clipOverride) const
{
    if (!m_webView || !mbWebFrameGetMainFrame)
        return false;
    const QString clip = clipOverride.isNull() ? systemClipboardText() : clipOverride;
    if (clip.isEmpty())
        return false;
    QJsonArray payload;
    payload.append(clip);
    const QByteArray jsonText = QJsonDocument(payload).toJson(QJsonDocument::Compact);
    const QString js = QStringLiteral("(function(a){"
                                      "try{"
                                      "var t=(a&&a.length)?a[0]:'';"
                                      "if(typeof t!=='string'||t.length===0)return'';"
                                      "var el=document.activeElement;"
                                      "if(!el)return'';"
                                      "var n=String(el.tagName||'').toLowerCase();"
                                      "el.focus();"
                                      "if(n==='input'||n==='textarea'){"
                                      "var v=el.value||'',st=0,ed=v.length;"
                                      "if(typeof el.selectionStart==='number'){st=el.selectionStart;ed=el.selectionEnd;}"
                                      "el.value=v.slice(0,st)+t+v.slice(ed);"
                                      "if(typeof el.selectionStart==='number'){var p=st+t.length;el.selectionStart=el.selectionEnd=p;}"
                                      "try{el.dispatchEvent(new InputEvent('input',{bubbles:true,inputType:'insertFromPaste',data:t}));}catch(e1){"
                                      "try{el.dispatchEvent(new Event('input',{bubbles:true}));}catch(e2){}"
                                      "}"
                                      "try{el.dispatchEvent(new Event('change',{bubbles:true}));}catch(e3){}"
                                      "return'1';"
                                      "}"
                                      "if(el.isContentEditable&&document.queryCommandSupported&&document.queryCommandSupported('insertText')){"
                                      "if(document.execCommand('insertText',false,t))return'1';"
                                      "}"
                                      "return'';"
                                      "}catch(z){return'';}"
                                      "})(")
        + QString::fromUtf8(jsonText)
        + QStringLiteral(")");
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(m_webView);
#if defined(Q_OS_LINUX)
    if (mbCallBlinkThreadSync) {
        if (evalPageJsOnBlinkThread(m_webView, frame, js.toUtf8()) == QStringLiteral("1"))
            return true;
    }
#endif
    return evalPageJsReturnString(m_webView, frame, js.toUtf8()).trimmed() == QStringLiteral("1");
}

QString WebWidget::selectedTextStrictAtMbPoint(const QPoint& mbPoint) const
{
    if (!m_webView || !mbRunJsSync || !mbJsToString || !mbWebFrameGetMainFrame)
        return QString();
    const mbWebFrameHandle frame = mbWebFrameGetMainFrame(m_webView);
    const QString js = QString::fromLatin1(
        "(function(x,y){"
        "function gs(w){try{var s=w.getSelection&&w.getSelection();return s?s.toString():\"\";}catch(e){return\"\";}}"
        "function targetWin(w,x,y,d){"
        "if(d>12||!w||!w.document)return w;"
        "try{"
        "var e=w.document.elementFromPoint(x,y);"
        "if(!e)return w;"
        "if(String(e.tagName).toLowerCase()==='iframe'){"
        "var r=e.getBoundingClientRect();"
        "var cw=e.contentWindow;"
        "if(cw)return targetWin(cw,x-r.left,y-r.top,d+1);"
        "}"
        "return (e.ownerDocument&&e.ownerDocument.defaultView)||w;"
        "}catch(z){return w;}"
        "}"
        "try{"
        "if(typeof x!==\"number\"||typeof y!==\"number\")return\"\";"
        "var win=targetWin(window,x,y,0)||window;"
        "return gs(win)||\"\";"
        "}catch(e){return\"\";}"
        "})(%1,%2)")
        .arg(mbPoint.x())
        .arg(mbPoint.y());
    return evalPageJsReturnString(m_webView, frame, js.toUtf8());
}

QString WebWidget::selectedTextFromPage() const
{
    if (m_lastRmbValid)
        return selectedTextFromPageAtPoint(m_lastRmbMbPos);
    return selectedTextFromPageAtPoint(mapEventToMb(rect().center()));
}

void WebWidget::showContextMenuForPage(const QPoint& widgetLocalPos)
{
    if (m_isDestroying || !m_webView)
        return;
    static qint64 s_lastOpenMs = 0;
    const qint64 now = QDateTime::currentMSecsSinceEpoch();
    /* 同一次右键在部分平台会先后触发 mouseRelease/contextMenuEvent，两次调用需更宽窗口去重 */
    if (s_lastOpenMs != 0 && now - s_lastOpenMs < 320)
        return;
    s_lastOpenMs = now;

    const QPoint mbPt = mapEventToMb(widgetLocalPos);
    m_lastRmbMbPos = mbPt;
    m_lastRmbValid = true;
    m_engineContextMenuHandled = false;
    m_hasPendingEngineContextMenu = false;
    m_pendingEngineMenuIds.clear();
    m_pendingEngineMenuTexts.clear();
    m_pendingEngineMenuInfo = EngineContextMenuInfo();

    /* 该 DLL 未实现 mbFireContextMenuEvent，改走真实 RMB 消息触发内核 popup 回调 */
    if (m_webView && mbFireMouseEvent) {
        mbFireMouseEvent(m_webView, WM_RBUTTONUP, mbPt.x(), mbPt.y(), MK_RBUTTON);
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu] showContextMenuForPage: trigger by WM_RBUTTONUP x=%1 y=%2")
            .arg(mbPt.x())
            .arg(mbPt.y()));
    } else {
        LITEVIEW_CTXMENU_LOG(QStringLiteral("[mbContextMenu] showContextMenuForPage: skip RMB trigger webView/mouseEvent null"));
    }

    const QPoint posCopy = widgetLocalPos;
    auto popupFallback = [this, posCopy]() {
        if (m_engineContextMenuHandled)
            return;
        const QPoint mbPt2 = mapEventToMb(posCopy);
        m_lastRmbMbPos = mbPt2;
        const QString selText = m_kernelSelectionText.trimmed();
        if (!selText.isEmpty()) {
            /* popupTextSelectionContextMenu 可能因节流返回 false（已弹过一次）；此时也不能再退回页面菜单 */
            m_engineContextMenuHandled = true;
            popupTextSelectionContextMenu(this, mbPt2, selText);
            return;
        }
        if (hitIsEditableFieldAtMb(mbPt2)) {
            m_engineContextMenuHandled = true;
            showCopyPasteContextMenu(this, mbPt2, true);
            return;
        }
        const QString linkUrl = linkUrlAtPoint(mbPt2).trimmed();
        if (isNavigableWebLink(linkUrl)) {
            m_engineContextMenuHandled = true;
            popupLinkContextMenuByUrl(this, linkUrl);
            return;
        }
        m_engineContextMenuHandled = true;
        popupBrowserContextMenu(this, m_webView, m_lastCanGoBack, m_lastCanGoForward, true);
    };
    auto tryConsumePending = [this]() -> bool {
        if (!m_hasPendingEngineContextMenu)
            return false;
        const QVector<mbMenuItemId> ids = m_pendingEngineMenuIds;
        const QVector<QString> texts = m_pendingEngineMenuTexts;
        const EngineContextMenuInfo info = m_pendingEngineMenuInfo;
        m_hasPendingEngineContextMenu = false;
        m_pendingEngineMenuIds.clear();
        m_pendingEngineMenuTexts.clear();
        m_pendingEngineMenuInfo = EngineContextMenuInfo();
        WebWidget::dispatchEngineContextMenu(m_webView, this, ids, texts, info);
        return true;
    };

    /* 准确率优先：给内核回调一个短窗口（最多约 60ms）再走 DOM 后备，避免超链接命中被过早降级。 */
    std::shared_ptr<int> tries(new int(0));
    auto pump = std::make_shared<std::function<void()>>();
    *pump = [this, popupFallback, tryConsumePending, tries, pump]() {
        if (m_engineContextMenuHandled)
            return;
        if (tryConsumePending()) {
            if (m_engineContextMenuHandled)
                return;
            popupFallback();
            return;
        }
        if (*tries >= 4) { // 0ms + 4*15ms ~= 60ms
            popupFallback();
            return;
        }
        ++(*tries);
        QTimer::singleShot(15, this, [pump]() { (*pump)(); });
    };
    QTimer::singleShot(0, this, [pump]() { (*pump)(); });
}

void WebWidget::openLinkInNewTab(const QString& url)
{
    const QString u = url.trimmed();
    if (u.isEmpty())
        return;
    if (m_createNewTabHandler) {
        m_createNewTabHandler(u);
        return;
    }
    loadUrl(u);
}

void WebWidget::openLinkInNewWindow(const QString& url)
{
    const QUrl u = QUrl::fromUserInput(url.trimmed());
    if (!u.isValid() || u.toString().isEmpty())
        return;
    QDesktopServices::openUrl(u);
}

void WebWidget::copyLinkToClipboard(const QString& url)
{
    setClipboardPlainText(url.trimmed());
}

void WebWidget::onPaintBitUpdated(mbWebView webView, const void* argbData, const mbRect* r, int bitmapWidth, int bitmapHeight)
{
    m_dirtyRect = *r;
    update(m_dirtyRect.x, m_dirtyRect.y, m_dirtyRect.w, m_dirtyRect.h);
}

void WebWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    if (m_displayUrlEmpty) {
        QPainter painter(this);
        painter.fillRect(rect(), QColor(QStringLiteral("#F7F9FC")));
        return;
    }
    if (!m_webView || !mbGetLockedViewBitmap || !mbUnlockViewBitmap) {
        QPainter painter(this);
        painter.fillRect(rect(), QColor(QStringLiteral("#ffffff")));
        return;
    }
    m_currentFrameData = mbGetLockedViewBitmap(m_webView, &m_frameWidth, &m_frameHeight);
    if (m_currentFrameData && m_frameWidth > 0 && m_frameHeight > 0) {
        QPainter painter(this);
        QImage image(m_currentFrameData, m_frameWidth, m_frameHeight, QImage::Format_ARGB32);
#ifndef _WIN32
        image = image.rgbSwapped();
#endif
        painter.drawImage(rect(), image, QRect(0, 0, m_frameWidth, m_frameHeight));
    } else {
        /* 首帧未就绪时勿留透明底，否则叠在 WA_TranslucentBackground 上会看到透明环 */
        QPainter painter(this);
        painter.fillRect(rect(), QColor(QStringLiteral("#ffffff")));
    }
    mbUnlockViewBitmap(m_webView);
}

void WebWidget::contextMenuEvent(QContextMenuEvent* event)
{
    if (!event)
        return;
    /* Windows 等常以 QContextMenuEvent 弹出右键，而不走 mouseRelease；在此统一出菜单 */
    if (event->reason() == QContextMenuEvent::Mouse)
        showContextMenuForPage(event->pos());
    event->accept();
}

void WebWidget::mousePressEvent(QMouseEvent* event)
{
    /* 点击网页区域时把键盘焦点交给内核，保证页面 input/textarea 可输入 */
    setFocus(Qt::MouseFocusReason);
    if (m_webView)
        mbSetFocus(m_webView);

    if (event->button() & Qt::LeftButton) {
        grabMouse();
        m_isCaptured = true;
        const QPoint mbPt = mapEventToMb(event->pos());
        mbFireMouseEvent(m_webView, WM_LBUTTONDOWN, mbPt.x(), mbPt.y(), /*flags*/0);
        scheduleInputMethodCursorUpdate();
    }

    if (event->button() & Qt::RightButton) {
        releaseMouse();
        m_isCaptured = false;
        m_lastRmbMbPos = mapEventToMb(event->pos());
        m_lastRmbValid = true;
        /* mbFireContextMenuEvent 未实现：改为补齐真实 RMB 事件链，靠内核自己触发 onContextMenuPopup */
        if (m_webView && mbFireMouseEvent)
            mbFireMouseEvent(m_webView, WM_RBUTTONDOWN, m_lastRmbMbPos.x(), m_lastRmbMbPos.y(), MK_RBUTTON);
        event->accept();
        return;
    }
    QWidget::mousePressEvent(event);
}

void WebWidget::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() & Qt::LeftButton) {
        if (m_isCaptured)
            releaseMouse();
        m_isCaptured = false;

        const QPoint mbPt = mapEventToMb(event->pos());
        mbFireMouseEvent(m_webView, WM_LBUTTONUP, mbPt.x(), mbPt.y(), /*flags*/0);
        scheduleInputMethodCursorUpdate();
    }
    if (event->button() & Qt::RightButton) {
        /* 与 contextMenuEvent 二选一或先后触发，showContextMenuForPage 内已去重 */
        showContextMenuForPage(event->pos());
        event->accept();
        return;
    }
    QWidget::mouseReleaseEvent(event);
}

void WebWidget::mouseMoveEvent(QMouseEvent* event)
{
    const QPoint mbPt = mapEventToMb(event->pos());
    Qt::MouseButtons btns = event->buttons();

    unsigned int flags = 0;
    if (btns & Qt::LeftButton)
        flags |= MK_LBUTTON;
    if (btns & Qt::RightButton)
        flags |= MK_RBUTTON;

    Qt::CursorShape qtCursor = mbCursorInfoTypeToQt((mbCursorInfoType)mbGetCursorInfoType(m_webView));
    setCursor(qtCursor);
    mbFireWindowsMessage(m_webView, nullptr, WM_SETCURSOR, 0, 0, nullptr);
    mbFireMouseEvent(m_webView, WM_MOUSEMOVE, mbPt.x(), mbPt.y(), flags);

    QWidget::mouseMoveEvent(event);
}

void WebWidget::mouseDoubleClickEvent(QMouseEvent* event)
{
    QWidget::mouseDoubleClickEvent(event);
    scheduleInputMethodCursorUpdate();
}

void WebWidget::enterEvent(QEnterEvent* event)
{
    //OutputDebugStringA("WebWidget::enterEvent\n");
    QWidget::enterEvent(event);
}

void WebWidget::leaveEvent(QEvent* event)
{
    //OutputDebugStringA("WebWidget::leaveEvent\n");
    QWidget::leaveEvent(event);
}

void WebWidget::wheelEvent(QWheelEvent* event)
{
    int delta = event->delta();
    const QPoint mbPt = mapEventToMb(event->pos());
    mbFireMouseWheelEvent(m_webView, mbPt.x(), mbPt.y(), delta, 0);
    scheduleInputMethodCursorUpdate();
    QWidget::wheelEvent(event);
}

void WebWidget::keyPressEvent(QKeyEvent* event)
{
    if (!m_webView || !event) {
        QWidget::keyPressEvent(event);
        return;
    }
    if ((event->modifiers() & Qt::ControlModifier) && !(event->modifiers() & Qt::AltModifier)) {
        if (event->key() == Qt::Key_C) {
            const QString sel = kernelSelectedText().trimmed();
            if (!sel.isEmpty()) {
                setClipboardPlainText(sel);
                event->accept();
                return;
            }
        } else if (event->key() == Qt::Key_V) {
            const QPoint mbPt = m_lastRmbValid ? m_lastRmbMbPos : mapEventToMb(rect().center());
            pasteFromSystemClipboardAtMb(mbPt);
            event->accept();
            scheduleInputMethodCursorUpdate();
            return;
        }
    }
    const QString text = event->text();
    const bool controlKey = isMbControlKey(event->key());
#if defined(Q_OS_WIN)
    const unsigned int vk = event->nativeVirtualKey()
        ? static_cast<unsigned int>(event->nativeVirtualKey())
        : qtKeyToVirtualKey(event->key());
#else
    const unsigned int vk = qtKeyToVirtualKey(event->key());
#endif
    const BOOL systemKey = (event->modifiers() & Qt::AltModifier) ? TRUE : FALSE;
    bool forwarded = false;
    if ((controlKey || !text.isEmpty()) && vk && mbFireKeyDownEvent) {
        mbFireKeyDownEvent(m_webView, vk, 0, systemKey);
        forwarded = true;
    }
    if (!text.isEmpty() && mbFireKeyPressEvent) {
        for (QChar ch : text)
            mbFireKeyPressEvent(m_webView, static_cast<unsigned int>(ch.unicode()), 0, systemKey);
        forwarded = true;
    } else if ((event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) && mbFireKeyPressEvent) {
        mbFireKeyPressEvent(m_webView, '\r', 0, systemKey);
        forwarded = true;
    }
    // 无文本且非控制键：交还 Qt，给输入法组合流程（openEuler/IBus/Fcitx）处理
    if (!forwarded && text.isEmpty() && !controlKey) {
        QWidget::keyPressEvent(event);
        return;
    }
    if (forwarded) {
        event->accept();
        scheduleInputMethodCursorUpdate();
        return;
    }
    QWidget::keyPressEvent(event);
}

void WebWidget::keyReleaseEvent(QKeyEvent* event)
{
    if (!m_webView || !event) {
        QWidget::keyReleaseEvent(event);
        return;
    }
    if (event->text().isEmpty() && !isMbControlKey(event->key())) {
        QWidget::keyReleaseEvent(event);
        return;
    }
#if defined(Q_OS_WIN)
    const unsigned int vk = event->nativeVirtualKey()
        ? static_cast<unsigned int>(event->nativeVirtualKey())
        : qtKeyToVirtualKey(event->key());
#else
    const unsigned int vk = qtKeyToVirtualKey(event->key());
#endif
    const BOOL systemKey = (event->modifiers() & Qt::AltModifier) ? TRUE : FALSE;
    if (vk && mbFireKeyUpEvent) {
        mbFireKeyUpEvent(m_webView, vk, 0, systemKey);
        event->accept();
        scheduleInputMethodCursorUpdate();
        return;
    }
    QWidget::keyReleaseEvent(event);
}

void WebWidget::inputMethodEvent(QInputMethodEvent* event)
{
    if (!m_webView || !event) {
        QWidget::inputMethodEvent(event);
        return;
    }
    const QString commit = event->commitString();
    if (!commit.isEmpty() && mbFireKeyPressEvent) {
        for (QChar ch : commit)
            mbFireKeyPressEvent(m_webView, static_cast<unsigned int>(ch.unicode()), 0, FALSE);
        event->accept();
        scheduleInputMethodCursorUpdate();
        return;
    }
    QWidget::inputMethodEvent(event);
}

QVariant WebWidget::inputMethodQuery(Qt::InputMethodQuery query) const
{
    if (query == Qt::ImEnabled)
        return true;
    if (query == Qt::ImCursorRectangle || query == Qt::ImMicroFocus)
        return caretRectInWidgetCoords();
    if (query == Qt::ImFont)
        return font();
    return QWidget::inputMethodQuery(query);
}

void WebWidget::changeEvent(QEvent *event)
{
    QWidget::changeEvent(event);
}

void WebWidget::focusInEvent(QFocusEvent* event)
{
    QWidget::focusInEvent(event);
    if (m_webView)
        mbSetFocus(m_webView);
    scheduleInputMethodCursorUpdate();
}

void WebWidget::focusOutEvent(QFocusEvent* event)
{
    QWidget::focusOutEvent(event);
    if (m_webView)
        mbKillFocus(m_webView);
}
// void WebWidget::setNextFrame(const uchar* data, const mbRect& dirtyRect, int width, int height)
// {
//     m_dirtyRect = dirtyRect;
//     m_currentFrameData = data;
//     m_frameWidth = width;
//     m_frameHeight = height;
//     update();
// }

