/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the demonstration applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "chip.h"

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

Chip::Chip(const QColor &color,QString name, double x, double y, double rot)
{
    this->m_name = name;
    m_pressed = 0;
    this->x = x;
    this->y = y;
    this->color = color;
    this->rot = rot;
    setZValue(10);
    setPos(x,y);
    setRotation(rot);

    setFlags(ItemIsSelectable);// | ItemIsMovable);
    setAcceptHoverEvents(true);
}

QRectF Chip::boundingRect() const
{
    return QRectF(-0.5, -0.5, 1, 1);
}

QPainterPath Chip::shape() const
{
    QPainterPath path;
    path.addRect(-0.5, -0.5, 1, 1);
    return path;
}

void Chip::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);


    QRectF rect = boundingRect();

    if(m_pressed)
    {
        QPen pen(this->color.lighter(125), 0.2);
        painter->setPen(pen);
        painter->drawEllipse(rect);
    }
    else
    {
        QPen pen(this->color, 0.2);
        painter->setPen(pen);
        painter->drawLine(QLineF(-0.5,-0.5, -0.2, -0.5) );
        painter->drawLine(QLineF(0.5,-0.5, 0.2, -0.5) );
        painter->drawLine(QLineF(-0.5,-0.5, -0.5, 0.5) );
        painter->drawLine(QLineF(0.5,-0.5, 0.5, 0.5) );
        painter->drawLine(QLineF(-0.5,0.5, 0.5, 0.5) );

        //painter->drawRect(rect);
    }
    /*
    QColor fillColor = (option->state & QStyle::State_Selected) ? color.darker(150) : color;
    if (option->state & QStyle::State_MouseOver)
        fillColor = fillColor.lighter(125);

    const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
    //painter->fillRect(QRectF(-0.5, -0.5, 0.5, 0.5), fillColor);
    QBrush b = painter->brush();
    painter->setBrush(fillColor);
    painter->drawRect(QRectF(-0.5, -0.5, 0.5, 0.5));
    painter->setPen(QPen(b, 0.2));
    //painter->drawEllipse(QRectF(-0.5,-0.5,0.8,0.8));
    //painter->drawLine(QPointF(-0.5,0),QPointF(0.5,0));
    painter->drawLine(QPointF(0,-0.5),QPointF(0,0.8));
    */

}

void Chip::setName(QString name)
{
    this->m_name = name;
}

void Chip::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    m_pressed=1;
    update();
    QGraphicsItem::mousePressEvent(event);

}

void Chip::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void Chip::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    m_pressed=0;
    update();
    QGraphicsItem::mouseReleaseEvent(event);

}

void Chip::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
/*
    QString str = QString("testToolTip");
    if (toolTip() != str){
        setToolTip(str);
    }
    */
    QPoint p = event->screenPos();
    //QPoint point = QPoint((int)this->x, (int)this->y);
    QString txt = this->m_name;// + "\nX:" + QString::number(this->x) +  "\nY:" + QString::number(this->y);
    QToolTip::showText(p,txt);//this,QRect(p,QSize(50,50)),10000);
    //map
    QGraphicsItem::hoverEnterEvent(event);
}

void Chip::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    QToolTip::hideText();
}

void Chip::changeColor(QColor c)
{
    this->color = c;
}
