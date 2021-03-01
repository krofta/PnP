#ifndef DXFITEM_H
#define DXFITEM_H

#include <QGraphicsItem>

#include "src/scene_items.h"
//#include "libdxfrw/src/drw_interface.h"

class DxfItem : public QGraphicsItem
{
public:
    DxfItem(const QColor &color,
            QList<QLineF> *lines, QList<QPointF> *points, QRectF boundary_box);


    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *item, QWidget *widget) override;


protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int x;
    int y;

    QRectF boundary_boxF;

    QColor color;
    QVector<QPointF> stuff;

    QList<DRW_Arc> *arcs;
    QList<DRW_Circle> *circles;
    //QList<DRW_Line> *lines;
    //QList<DRW_Point> *points;

    QList<QLineF> *linesF;
    QList<QPointF> *pointsF;
};

#endif // DXFITEM_H
