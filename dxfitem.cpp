#include "dxfitem.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

DxfItem::DxfItem(const QColor &color, QList<DRW_Arc> *arcs, QList<DRW_Circle> *circles,
                 QList<DRW_Line> *lines, QList<DRW_Point> *points)
{
    this->x = 0.0;
    this->y = 0.0;
    this->color = color;
    //setZValue((x + y) % 2);
    setZValue(0);

    //setFlags(ItemIsSelectable | ItemIsMovable);
    setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
}

QRectF DxfItem::boundingRect() const
{

}

QPainterPath DxfItem::shape() const
{

}

void DxfItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);

    QColor fillColor = (item->state & QStyle::State_Selected) ? color.darker(150) : color;
    if (item->state & QStyle::State_MouseOver)
        fillColor = fillColor.lighter(125);

     const qreal lod = item->levelOfDetailFromTransform(painter->worldTransform());

}

void DxfItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void DxfItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /*
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
    */
    QGraphicsItem::mouseMoveEvent(event);
}

void DxfItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
