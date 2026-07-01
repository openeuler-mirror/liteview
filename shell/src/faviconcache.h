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

#ifndef FAVICONCACHE_H
#define FAVICONCACHE_H

#include <QIcon>
#include <QImage>
#include <QString>

/** 可执行文件目录 LocalStorage/favicon 下按站点 host 缓存标签页图标 */
class FaviconCache
{
public:
    static QString cacheDirectory();
    static QString hostKeyFromPageUrl(const QString& pageUrl);
    static QIcon loadIconForPageUrl(const QString& pageUrl);
    static bool saveIconForPageUrl(const QString& pageUrl, const QImage& image);
    /** 删除 LocalStorage/favicon 下全部已缓存站点图标文件 */
    static bool clearAllCachedIcons();
    /** images/label.png，内核无法取得站点图标时使用 */
    static QIcon defaultTabIcon();
};

#endif // FAVICONCACHE_H
