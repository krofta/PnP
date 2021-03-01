#include "pcb_part.h"
#include <stdlib.h>

#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QStyleOptionGraphicsItem>

// -----------------------------KONSTRUKTOREN


PCB_Part::PCB_Part()// : QGraphicsItem()
{
    this->ellipse = nullptr;

}


PCB_Part::~PCB_Part(){
    this->circle = DRW_Circle();
    this->circle.color = 0x00FF00;
    this->circle.basePoint = DRW_Coord(0.0, 0.0, 0.0);
    this->circle.radious = 0.5;
    this->circle.visible = false;
    this->ellipse = nullptr;

}

PCB_Part::PCB_Part(QString name, QString x, QString y)// : QGraphicsItem()
{
    this->ellipse = nullptr;
    this->set_name(name);
    this->set_sx(x);
    this->set_sy(y);
    //this->color = 0x00FFFF;
    this->visible = 0;
    this->circle = DRW_Circle();
    this->circle.color = 0x00FF00;
    this->circle.basePoint = DRW_Coord(0.0, 0.0, 0.0);
    this->circle.radious = 0.5;
    this->circle.visible = false;
}

// ------------------------------SETTER METHODEN

void PCB_Part::set_name(QString name){
    this->name = name;
}

bool PCB_Part::set_sx(QString x) {
    bool ok = false;
    double dingdong = x.toDouble(&ok);
    if(ok){
        this->sx = x;
        this->dx = dingdong;
    }
    return ok;
}
bool PCB_Part::set_sx(QString x, int invert) {
    bool ok = false;
    double dingdong = x.toDouble(&ok);
    if(ok){
        this->sx = x;
        this->dx = dingdong * (invert ? -1 : 1);
    }
    return ok;
}
bool PCB_Part::set_sy(QString y){
    bool ok = false;
    double dingdong = y.toDouble(&ok);
    if(ok){
        this->sy = y;
        this->dy = dingdong;
    }
    return ok;
}

bool PCB_Part::set_srotation(QString rot)
{
    bool ok = false;
    double dingdong = rot.toDouble(&ok);
    if(ok){
        this->srotation = rot;
        this->drotation = dingdong;
    }
    return ok;
}

void PCB_Part::set_layer(QString layer)
{
    this->layer = layer;
}

void PCB_Part::set_dx(double x){
    this->dx = x;
    this->sx = QString::number(x);
}

void PCB_Part::set_dy(double y){
    this->dy = y;
    this->sy = QString::number(y);
}

void PCB_Part::set_drotation(double rot)
{
    this->drotation = rot;
    this->srotation = QString::number(rot);
}


void PCB_Part::set_visible(int val){
    this->visible = val > 0 ? 1 : 0;
    this->circle.visible = val > 0 ? true : false;
}

void PCB_Part::set_color(int color){
    //this->color = color;
}

// ------------------------------GETTER METHODEN

QString PCB_Part::get_name(){
    return this->name;
}

QString PCB_Part::get_sx(){
    return this->sx;
}

QString PCB_Part::get_sy(){
    return this->sy;
}

QString PCB_Part::get_srotation()
{
    return this->srotation;
}

QString PCB_Part::get_layer()
{
    return this->layer;
}

double PCB_Part::get_dx(){
    return this->dx;
}

double PCB_Part::get_dy(){
    return this->dy;
}

double PCB_Part::get_drotation()
{
    return this->drotation;
}

QColor PCB_Part::get_color(){
    //return this->color;
}

int PCB_Part::get_visible(){
    //this->circle.visible
    return this->circle.visible;
}

DRW_Circle* PCB_Part::getCircle(){
    return &this->circle;
}

void PCB_Part::refreshCircle(){
    this->circle.basePoint.x = this->dx;
    this->circle.basePoint.y = this->dy;
}


/*
QRectF PCB_Part::boundingRect() const
{
    return QRectF(0, 0, 50, 50);
}

QPainterPath PCB_Part::shape() const
{
    QPainterPath path;
    path.addRect(14, 14, 10, 10);
    return path;
}

void PCB_Part::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);

    QColor fillColor = (option->state & QStyle::State_Selected) ? color.darker(150) : color;
    if (option->state & QStyle::State_MouseOver)
        fillColor = fillColor.lighter(125);

    const qreal lod = option->levelOfDetailFromTransform(painter->worldTransform());
    if (lod < 0.2) {
        if (lod < 0.125) {
            painter->fillRect(QRectF(0, 0, 50, 50), fillColor);
            return;
        }

        QBrush b = painter->brush();
        painter->setBrush(fillColor);
        painter->drawRect(13, 13, 10, 10);
        painter->setBrush(b);
        return;
    }

    QPen oldPen = painter->pen();
    QPen pen = oldPen;
    int width = 0;
    if (option->state & QStyle::State_Selected)
        width += 2;

    pen.setWidth(width);
    QBrush b = painter->brush();
    painter->setBrush(QBrush(fillColor.darker(option->state & QStyle::State_Sunken ? 120 : 100)));

    painter->drawRect(QRect(14, 14, 15, 15));
    painter->setBrush(b);



    // Draw text
    if (lod >= 2) {
        QFont font("Times", 10);
        font.setStyleStrategy(QFont::ForceOutline);
        painter->setFont(font);
        painter->save();
        painter->scale(0.1, 0.1);
        painter->drawText(170, 180, QString("%1").arg(this->name));
        painter->restore();
    }

}

void PCB_Part::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mousePressEvent(event);
    update();
}

void PCB_Part::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->modifiers() & Qt::ShiftModifier) {
        stuff << event->pos();
        update();
        return;
    }
    QGraphicsItem::mouseMoveEvent(event);
}

void PCB_Part::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseReleaseEvent(event);
    update();
}
*/




// Klasse die die Bauteilart speichert und eine Liste aller entsprechenden teile enthält

PCB_PartKind::PCB_PartKind(){

}
PCB_PartKind::~PCB_PartKind(){
    //delete parts;
}
#include <string.h>
PCB_PartKind::PCB_PartKind(QString name, ProcessParameters *p){
    this->set_name(name);
    memcpy(&this->parameters, p, sizeof(this->parameters));
}
void PCB_PartKind::set_name(QString name){
    this->sName = name;
}

QString PCB_PartKind::get_name(){
    return this->sName;
}




