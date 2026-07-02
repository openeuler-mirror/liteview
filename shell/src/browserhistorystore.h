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

#ifndef BROWSERHISTORYSTORE_H
#define BROWSERHISTORYSTORE_H

#include <QDateTime>
#include <QObject>
#include <QPair>
#include <QString>
#include <QVector>

struct HistoryEntry {
    QString title;
    QString url;
    QDateTime visited;
};

class BrowserHistoryStore : public QObject
{
    Q_OBJECT
public:
    static BrowserHistoryStore* instance();

    void addVisit(const QString& url, const QString& title);
    void removeAt(int index);
    void clear();

    /** 全局下标 + 条目；下标用于删除；按时间从新到旧与 m_entries 一致。 */
    QVector<QPair<int, HistoryEntry>> entriesFilteredWithIndex(const QString& searchText) const;

signals:
    void changed();

private:
    explicit BrowserHistoryStore(QObject* parent = nullptr);
    void loadFromDisk();
    void saveToDisk() const;

    QVector<HistoryEntry> m_entries;
    static BrowserHistoryStore* s_instance;
};

#endif // BROWSERHISTORYSTORE_H
