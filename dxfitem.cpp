#include "dxfitem.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

DxfItem::DxfItem(const QColor &color,
                 QList<QLineF> *lines, QList<QPointF> *points, QRectF boundary_box)
{
    this->boundary_boxF = boundary_box;
    this->linesF = lines;
    this->pointsF = points;
    this->x = 0.0;
    this->y = 0.0;
    this->color = color;
    //setZValue((x + y) % 2);
    setZValue(0);

    //setFlags(ItemIsSelectable | ItemIsMovable);
    //setFlags(ItemIsSelectable);
    setAcceptHoverEvents(true);
}

QRectF DxfItem::boundingRect() const
{
    return this->boundary_boxF;
}

QPainterPath DxfItem::shape() const
{
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

void DxfItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget)
{
    Q_UNUSED(widget);

    QColor fillColor = (item->state & QStyle::State_Selected) ? color.darker(150) : color;
    if (item->state & QStyle::State_MouseOver)
        fillColor = fillColor.lighter(125);

    // information about how much the user has zoomed in
    const qreal lod = item->levelOfDetailFromTransform(painter->worldTransform());


    painter->setPen(QPen(Qt::white, 0));
    // draw lines
    for(int i = 0; i < this->linesF->count(); i++){
        painter->drawLine(this->linesF->at(i));
    }

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
