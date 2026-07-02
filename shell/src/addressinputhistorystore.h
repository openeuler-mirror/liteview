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

#ifndef ADDRESSINPUTHISTORYSTORE_H
#define ADDRESSINPUTHISTORYSTORE_H

#include <QObject>
#include <QPair>
#include <QString>
#include <QVector>

/** 地址栏输入过的网址（与浏览历史分开存储，用于 Omnibox 联想） */
struct AddressInputEntry {
    QString url;
};

class AddressInputHistoryStore : public QObject
{
public:
    static AddressInputHistoryStore* instance();

    /** 在地址栏回车或从联想选中后调用；仅记录 http(s) 规范化 URL */
    void recordInput(const QString& urlOrText);

    /** 清空地址栏输入记录文件 */
    void clear();

    QVector<QPair<int, AddressInputEntry>> entriesFilteredWithIndex(const QString& searchText) const;

private:
    explicit AddressInputHistoryStore(QObject* parent = nullptr);
    void loadFromDisk();
    void saveToDisk() const;

    QVector<AddressInputEntry> m_entries;
    static AddressInputHistoryStore* s_instance;
};

#endif
