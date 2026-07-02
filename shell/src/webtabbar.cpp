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

#include "webtabbar.h"
#include <QApplication>
#include <QContextMenuEvent>
#include <QFontMetrics>
#include <QPaintEvent>
#include <QPainter>
#include <QStyleOptionTab>
#include <QStyle>
#include <QVariant>
#include <QResizeEvent>
#include <QPalette>
#include <QMouseEvent>
#include <QAbstractButton>
#include <QEvent>

WebProxyStyle::WebProxyStyle(QStyle* base)
    : QProxyStyle(base ? base : QApplication::style())
{
}

int WebProxyStyle::styleHint(StyleHint hint, const QStyleOption* opt, const QWidget* widget, QStyleHintReturn* returnData) const
{
    if (hint == QStyle::SH_TabBar_Alignment)
        return int(Qt::AlignLeft | Qt::AlignVCenter);
    return QProxyStyle::styleHint(hint, opt, widget, returnData);
}

int WebProxyStyle::pixelMetric(PixelMetric metric, const QStyleOption* opt, const QWidget* widget) const
{
    /* 即使 setUsesScrollButtons(false)，部分原生样式仍会为滚动箭头预留宽度，导致单标签左侧出现大块空白 */
    if (qobject_cast<const WebTabBar*>(widget) && metric == QStyle::PM_TabBarScrollButtonWidth)
        return 0;
    return QProxyStyle::pixelMetric(metric, opt, widget);
}

void WebProxyStyle::drawControl(ControlElement element, const QStyleOption* option, QPainter* painter, const QWidget* widget) const
{
    if (const auto* tb = qobject_cast<const WebTabBar*>(widget)) {
        if (element == QStyle::CE_TabBarTabLabel) {
            /* 不在样式里画标题：Windows 等会在 tab 内居中；统一在 WebTabBar::paintEvent 里左对齐绘制（单/多标签同一套逻辑） */
            Q_UNUSED(option);
            Q_UNUSED(painter);
            return;
        }
        if (element == QStyle::CE_TabBarTab) {
            if (const QStyleOptionTab* tab = qstyleoption_cast<const QStyleOptionTab*>(option)) {
                QStyleOptionTab copy = *tab;
                copy.text.clear();
                QProxyStyle::drawControl(element, &copy, painter, widget);
                return;
            }
        }
    }
    QProxyStyle::drawControl(element, option, painter, widget);
}

namespace {

/** 单标签栏总宽；多标签时每个 tab 的首选宽度（空间不足时仍可被压缩） */
constexpr int kPreferredTabWidthPx = 270;
/** 多标签极限压缩时仅保留 favicon 区（文本可完全不显示） */
constexpr int kMinIconOnlyTabWidthPx = 24;
} // namespace

QRect WebTabBar::titleDrawingRect(int index) const
{
    return titleTextRect(index);
}

QRect WebTabBar::titleTextRect(int index) const
{
    const QRect tbr = tabRect(index);
    if (!tbr.isValid())
        return QRect();
    const int kLeftPad = 6;
    const int kIconGap = 10;
    const int kTitleShrinkPx = 8;
    /* 与有 favicon 时一致：无图标也预留槽位，避免「新标签页」贴左、加载图标后标题跳动 */
    const QSize isz = iconSize();
    const int iconW = isz.width() > 0 ? isz.width() : 16;
    int x = tbr.left() + kLeftPad + iconW + kIconGap;
    QWidget* right = tabButton(index, QTabBar::RightSide);
    const int rw = (right && right->isVisible()) ? (right->width() + 10 + kTitleShrinkPx) : (8 + kTitleShrinkPx);
    const int maxRight = tbr.right() - rw;
    return QRect(x, tbr.top(), qMax(1, maxRight - x + 1), tbr.height());
}

WebTabBar::WebTabBar(QWidget* parent)
    : QTabBar(parent)
{
    setDocumentMode(true);
    setIconSize(QSize(16, 16));
    setElideMode(Qt::ElideNone);
    setExpanding(false);
    m_proxyStyle = new WebProxyStyle(QApplication::style());
    setStyle(m_proxyStyle);
}

void WebTabBar::setTabLayoutWidthCap(int capPx)
{
    const int cap = qMax(0, capPx);
    if (m_tabLayoutWidthCap == cap)
        return;
    m_tabLayoutWidthCap = cap;
    updateGeometry();
}

int WebTabBar::innerLayoutWidth() const
{
    if (m_tabLayoutWidthCap > 0)
        return m_tabLayoutWidthCap;
    /* 多标签未注入 cap 时不用 width()，避免 tabSizeHint 在还原过渡态按宽屏均分 */
    if (count() > 1)
        return 0;
    const int w = width();
    return w > 0 ? w : 0;
}

WebTabBar::~WebTabBar()
{
    cancelWindowTabDrag();
    setStyle(nullptr);
    delete m_proxyStyle;
    m_proxyStyle = nullptr;
}

void WebTabBar::cancelWindowTabDrag()
{
    if (mouseGrabber() == this)
        releaseMouse();
    const bool wasDragging = m_windowDragging;
    m_windowDragArmed = false;
    m_windowDragging = false;
    m_dragLockedWindowSize = QSize();
    if (wasDragging)
        emit windowTabDragEnded();
}

void WebTabBar::resizeEvent(QResizeEvent* event)
{
    QTabBar::resizeEvent(event);
    updateGeometry();
    emit tabBarInteractionChanged();
}

void WebTabBar::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton) {
        bool onRightButton = false;
        QWidget* hit = childAt(event->pos());
        if (hit) {
            QWidget* cur = hit;
            while (cur && cur != this) {
                if (qobject_cast<QAbstractButton*>(cur)) {
                    onRightButton = true;
                    break;
                }
                cur = cur->parentWidget();
            }
        }
        for (int i = 0; i < count(); ++i) {
            if (QWidget* btn = tabButton(i, QTabBar::RightSide)) {
                const QRect hitRect = btn->geometry().adjusted(-4, -8, 4, 8);
                const bool hitByGeom = btn->isVisible() && hitRect.contains(event->pos());
                const bool hitByChild = hit && (hit == btn || btn->isAncestorOf(hit));
                if (hitByGeom || hitByChild) {
                    onRightButton = true;
                    break;
                }
            }
        }
        if (!onRightButton && tabAt(event->pos()) >= 0) {
            m_windowDragArmed = true;
            m_windowDragging = false;
            m_windowDragPressGlobal = event->globalPos();
            if (QWidget* win = window())
                m_dragLockedWindowSize = win->size();
        } else {
            m_windowDragArmed = false;
            m_windowDragging = false;
            m_dragLockedWindowSize = QSize();
        }
    }
    QTabBar::mousePressEvent(event);
}

void WebTabBar::mouseMoveEvent(QMouseEvent* event)
{
    QWidget* win = window();
    if (m_windowDragArmed && (event->buttons() & Qt::LeftButton) && win && !win->isFullScreen()) {
        const int dist = (event->globalPos() - m_windowDragPressGlobal).manhattanLength();
        if (!m_windowDragging && dist >= QApplication::startDragDistance()) {
            m_windowDragging = true;
            if (win->isMaximized()) {
                const QPoint g = event->globalPos();
                const QPoint rel = g - win->frameGeometry().topLeft();
                win->showNormal();
                win->move(g - rel);
                m_dragLockedWindowSize = win->size();
            }
            m_windowDragOffset = event->globalPos() - win->frameGeometry().topLeft();
            grabMouse();
        }
        if (m_windowDragging) {
            if (m_dragLockedWindowSize.isValid() && win->size() != m_dragLockedWindowSize)
                win->resize(m_dragLockedWindowSize);
            win->move(event->globalPos() - m_windowDragOffset);
            event->accept();
            return;
        }
    }
    const int hoverIdx = tabAt(event->pos());
    if (hoverIdx != m_hoveredTabIndex) {
        m_hoveredTabIndex = hoverIdx;
        emit tabBarInteractionChanged();
    }
    QTabBar::mouseMoveEvent(event);
}

void WebTabBar::leaveEvent(QEvent* event)
{
    if (m_hoveredTabIndex >= 0) {
        m_hoveredTabIndex = -1;
        emit tabBarInteractionChanged();
    }
    QTabBar::leaveEvent(event);
}

void WebTabBar::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::LeftButton && (m_windowDragging || m_windowDragArmed))
        cancelWindowTabDrag();
    QTabBar::mouseReleaseEvent(event);
}

void WebTabBar::contextMenuEvent(QContextMenuEvent* event)
{
    const int idx = tabAt(event->pos());
    if (idx >= 0) {
        emit tabContextMenuRequested(idx, event->globalPos());
        event->accept();
        return;
    }
    QTabBar::contextMenuEvent(event);
}

void WebTabBar::paintEvent(QPaintEvent* event)
{
    QTabBar::paintEvent(event);
    /* CE_TabBarTabLabel 已跳过；展示文案只放在 tabData（勿写 tabText，否则样式/引擎仍会画字导致重叠） */
    QPainter painter(this);
    painter.setRenderHint(QPainter::TextAntialiasing, true);
    QFontMetrics fm(font());
    for (int i = 0; i < count(); ++i) {
        const QRect trRect = tabRect(i);
        if (!trRect.intersects(event->rect()))
            continue;
        QString line = tabData(i).toString();
        if (line.isEmpty())
            line = tabText(i);
        if (line.isEmpty())
            line = tabToolTip(i);
        if (line.isEmpty())
            continue;
        QStyleOptionTab opt;
        initStyleOption(&opt, i);
        const QRect tr = titleTextRect(i);
        if (!tr.isValid() || tr.width() < 2)
            continue;
        const QColor textColor = opt.palette.color(QPalette::WindowText);
        painter.setPen(textColor);
        const QString elided = fm.elidedText(line, Qt::ElideRight, tr.width());
        painter.drawText(tr, Qt::AlignLeft | Qt::AlignVCenter | Qt::TextShowMnemonic, elided);
    }
}

QSize WebTabBar::minimumSizeHint() const
{
    const int h = QTabBar::minimumSizeHint().height();
    if (count() <= 1)
        return QSize(1, h);
    const int n = qMax(1, count());
    const int floorW = n * kMinIconOnlyTabWidthPx;
    if (m_tabLayoutWidthCap > 0)
        return QSize(qMin(m_tabLayoutWidthCap, floorW), h);
    return QSize(floorW, h);
}

QSize WebTabBar::sizeHint() const
{
    const int h = QTabBar::sizeHint().height();
    if (count() <= 1) {
        const int cap = m_tabLayoutWidthCap > 0 ? m_tabLayoutWidthCap : kPreferredTabWidthPx;
        const int barW = width() > 0 ? qMin(width(), cap) : cap;
        return QSize(qMax(1, qMin(barW, kPreferredTabWidthPx)), h);
    }
    const int n = qMax(1, count());
    const int naturalW = n * kPreferredTabWidthPx;
    if (m_tabLayoutWidthCap > 0)
        return QSize(qMax(1, qMin(m_tabLayoutWidthCap, naturalW)), h);
    /* 多标签且 cap 未注入：勿用 width()（最大化→还原过渡会把窗体 minimumSize 撑到 2000+） */
    return QSize(qMax(1, qMin(n * kMinIconOnlyTabWidthPx, naturalW)), h);
}

QSize WebTabBar::tabSizeHint(int index) const
{
    Q_UNUSED(index);
    const int h = QTabBar::tabSizeHint(index).height();
    if (count() <= 1) {
        const int barW = width() > 0 ? width() : kPreferredTabWidthPx;
        const int w = qMin(barW, kPreferredTabWidthPx);
        return QSize(qMax(w, 1), h);
    }
    const int n = qMax(1, count());
    const int innerW = innerLayoutWidth();
    const int naturalW = n * kPreferredTabWidthPx;
    const int barW = innerW > 0 ? innerW : naturalW;
    /* 未满：每枚 270；顶满后：在栏宽内均分且不低于最小宽度 */
    const int perTab = qMin(kPreferredTabWidthPx,
                            qMax(kMinIconOnlyTabWidthPx, barW / n));
    return QSize(perTab, h);
}

QSize WebTabBar::minimumTabSizeHint(int index) const
{
    if (count() <= 1)
        return tabSizeHint(index);
    const int h = QTabBar::minimumTabSizeHint(index).height();
    return QSize(kMinIconOnlyTabWidthPx, h);
}
