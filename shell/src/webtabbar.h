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

#ifndef WEBTABBAR_H
#define WEBTABBAR_H

#include <QPoint>
#include <QSize>
#include <QProxyStyle>
#include <QStyle>
#include <QTabBar>

class QContextMenuEvent;
class QMouseEvent;
class QResizeEvent;

/** 浏览器式标签：左对齐文字与图标，并统一图标尺寸与省略号。 */
class WebProxyStyle : public QProxyStyle
{
public:
    explicit WebProxyStyle(QStyle* base = nullptr);
    int styleHint(StyleHint hint, const QStyleOption* opt = nullptr, const QWidget* widget = nullptr, QStyleHintReturn* returnData = nullptr) const override;
    int pixelMetric(PixelMetric metric, const QStyleOption* opt = nullptr, const QWidget* widget = nullptr) const override;
    void drawControl(ControlElement element, const QStyleOption* option, QPainter* painter, const QWidget* widget) const override;
};

class WebTabBar : public QTabBar
{
    Q_OBJECT
public:
    explicit WebTabBar(QWidget* parent = nullptr);
    ~WebTabBar();

    /** 标题与图标、右侧控件留白一致的可绘文字区域（多标签时用于左对齐，避免系统样式在 tab 内居中） */
    QRect titleDrawingRect(int index) const;
    bool isWindowTabDragging() const { return m_windowDragging; }
    bool isWindowTabDragArmed() const { return m_windowDragArmed; }
    /** 结束标签拖窗（释放鼠标捕获；应用级 MouseRelease 也会调用以防状态卡住） */
    void cancelWindowTabDrag();
    /** 由 Widget::relayoutTopTabBar 注入；限制 sizeHint/tabSizeHint，避免撑大窗体 */
    void setTabLayoutWidthCap(int capPx);
    int tabLayoutWidthCap() const { return m_tabLayoutWidthCap; }
    int hoveredTabIndex() const { return m_hoveredTabIndex; }

signals:
    void windowTabDragEnded();
    /** 悬停标签或栏宽变化，需刷新关闭按钮可见性 */
    void tabBarInteractionChanged();
    /** 在某一标签上弹出右键菜单（index 为标签下标） */
    void tabContextMenuRequested(int index, QPoint globalPos);

protected:
    void resizeEvent(QResizeEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void contextMenuEvent(QContextMenuEvent* event) override;
    void leaveEvent(QEvent* event) override;
    void paintEvent(QPaintEvent* event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    QSize tabSizeHint(int index) const override;
    QSize minimumTabSizeHint(int index) const override;

private:
    QRect titleTextRect(int index) const;
    int innerLayoutWidth() const;
    WebProxyStyle* m_proxyStyle = nullptr;
    bool m_windowDragArmed = false;
    bool m_windowDragging = false;
    QPoint m_windowDragPressGlobal;
    QPoint m_windowDragOffset;
    QSize m_dragLockedWindowSize;
    int m_tabLayoutWidthCap = 0;
    int m_hoveredTabIndex = -1;
};

#endif // WEBTABBAR_H

