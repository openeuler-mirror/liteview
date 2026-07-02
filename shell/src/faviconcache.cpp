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

#include "faviconcache.h"

#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QUrl>

namespace {

QString sanitizeHostFileKey(const QString& host)
{
    QString safe;
    safe.reserve(host.size());
    for (const QChar c : host) {
        if (c.isLetterOrNumber() || c == QLatin1Char('.') || c == QLatin1Char('-') || c == QLatin1Char('_'))
            safe.append(c);
        else
            safe.append(QLatin1Char('_'));
    }
    return safe;
}

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

} // namespace

QString FaviconCache::cacheDirectory()
{
    const QString dir = QDir(QCoreApplication::applicationDirPath()).filePath(QStringLiteral("LocalStorage/favicon"));
    QDir().mkpath(dir);
    return dir;
}

QString FaviconCache::hostKeyFromPageUrl(const QString& pageUrl)
{
    const QString trimmed = pageUrl.trimmed();
    if (trimmed.isEmpty() || trimmed == QStringLiteral("about:blank"))
        return QString();
    QUrl u = QUrl::fromUserInput(trimmed);
    if (!u.isValid() || u.host().isEmpty())
        return QString();
    QString host = u.host().toLower();
    const int port = u.port();
    if (port > 0) {
        const bool defaultPort = (u.scheme().compare(QStringLiteral("https"), Qt::CaseInsensitive) == 0 && port == 443)
            || (u.scheme().compare(QStringLiteral("http"), Qt::CaseInsensitive) == 0 && port == 80);
        if (!defaultPort)
            host += QLatin1Char('_') + QString::number(port);
    }
    return sanitizeHostFileKey(host);
}

QIcon FaviconCache::loadIconForPageUrl(const QString& pageUrl)
{
    const QString key = hostKeyFromPageUrl(pageUrl);
    if (key.isEmpty())
        return QIcon();
    const QDir dir(cacheDirectory());
    static const QStringList exts = {
        QStringLiteral(".png"),
        QStringLiteral(".ico"),
        QStringLiteral(".jpg"),
        QStringLiteral(".jpeg"),
        QStringLiteral(".webp"),
    };
    for (const QString& ext : exts) {
        const QString path = dir.filePath(key + ext);
        if (!QFileInfo::exists(path))
            continue;
        const QIcon ico(path);
        if (!ico.isNull())
            return ico;
    }
    return QIcon();
}

bool FaviconCache::clearAllCachedIcons()
{
    QDir dir(cacheDirectory());
    if (!dir.exists())
        return true;
    const QStringList names = dir.entryList(QDir::Files | QDir::NoDotAndDotDot | QDir::Hidden);
    bool ok = true;
    for (const QString& name : names) {
        if (!QFile::remove(dir.filePath(name)))
            ok = false;
    }
    return ok;
}

bool FaviconCache::saveIconForPageUrl(const QString& pageUrl, const QImage& image)
{
    const QString key = hostKeyFromPageUrl(pageUrl);
    if (key.isEmpty() || image.isNull())
        return false;
    const QString path = QDir(cacheDirectory()).filePath(key + QStringLiteral(".png"));
    return image.save(path, "PNG");
}

QIcon FaviconCache::defaultTabIcon()
{
    static const QIcon ico = loadImageFromImagesDir({QStringLiteral("label")});
    return ico;
}
