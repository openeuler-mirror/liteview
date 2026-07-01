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

#ifndef BROWSERSETTINGSWIDGET_H
#define BROWSERSETTINGSWIDGET_H

#include "browserhistorystore.h"
#include <QDate>
#include <QIcon>
#include <QVector>
#include <QWidget>

class QListWidget;
class QStackedWidget;
class QRadioButton;
class QLabel;
class QLineEdit;
class QPushButton;
class QCheckBox;
class QScrollArea;
class QVBoxLayout;

class BrowserSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BrowserSettingsWidget(QWidget* parent = nullptr);

    /** 当前下载保存目录（规范化路径，供下载逻辑使用） */
    static QString downloadSavePath();

signals:
    void startupSettingsSaved();
    void openUrlRequested(const QString& url);

private slots:
    void onSidebarRowChanged(int row);
    void onHomepageRadioToggled();
    void onSaveHomepageClicked();
    void onHistorySearchChanged(const QString& text);
    void onClearHistoryClicked();
    void onHistoryStoreChanged();
    void onChangeDownloadPathClicked();
    void onClearBrowsingDataClicked();

private:
    void refreshSidebarIcons();
    void loadHomepageSettings();
    void loadDownloadSettings();
    void refreshHistoryView();
    QString formatHistoryDateHeader(const QDate& d) const;
    void addHistoryRow(int storeIndex, const HistoryEntry& e);

    QListWidget* m_sidebar = nullptr;
    QVector<QIcon> m_sidebarIconsNormal;
    QVector<QIcon> m_sidebarIconsActive;
    int m_sidebarHoverRow = -1;
    QStackedWidget* m_stack = nullptr;
    QRadioButton* m_radioNewTab = nullptr;
    QRadioButton* m_radioSpecificUrl = nullptr;
    QLabel* m_lblStartupUrlCaption = nullptr;
    QLineEdit* m_editSpecificUrl = nullptr;
    QPushButton* m_btnSaveHomepage = nullptr;

    QLineEdit* m_historySearchEdit = nullptr;
    QPushButton* m_btnClearHistory = nullptr;
    QScrollArea* m_historyScroll = nullptr;
    QWidget* m_historyContentWidget = nullptr;
    QVBoxLayout* m_historyListLayout = nullptr;

    QLabel* m_downloadPathLabel = nullptr;
    QPushButton* m_btnChangeDownloadPath = nullptr;

    QCheckBox* m_chkClearInputHistory = nullptr;
    QCheckBox* m_chkClearBrowseHistory = nullptr;
    QCheckBox* m_chkClearWebCache = nullptr;
    QCheckBox* m_chkClearCookies = nullptr;
    QPushButton* m_btnClearBrowsingData = nullptr;
};

#endif // BROWSERSETTINGSWIDGET_H
