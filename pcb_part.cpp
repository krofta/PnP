#include "pcb_part.h"
#include <stdlib.h>

// -----------------------------KONSTRUKTOREN

PCB_Part::PCB_Part()
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

PCB_Part::PCB_Part(QString name, QString x, QString y){
    this->ellipse = nullptr;
    this->set_name(name);
    this->set_sx(x);
    this->set_sy(y);
    this->color = 0x00FFFF;
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
    this->color = color;
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

int PCB_Part::get_color(){
    return this->color;
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

// Klasse die die Bauteilart speichert und eine Liste aller entsprechenden teile enthält

PCB_PartKind::PCB_PartKind(){

}
PCB_PartKind::~PCB_PartKind(){
    //delete parts;
}
#include <string.h> // memcpy
PCB_PartKind::PCB_PartKind(QString name, ProcessParameters *p){
    this->set_name(name);
    memcpy(&this->parameters, p, sizeof(ProcessParameters));

}
void PCB_PartKind::set_name(QString name){
    this->sName = name;
}

QString PCB_PartKind::get_name(){
    return this->sName;
}




