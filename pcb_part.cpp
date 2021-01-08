#include "pcb_part.h"

// -----------------------------KONSTRUKTOREN

PCB_Part::PCB_Part()
{


}

PCB_Part::~PCB_Part(){
    this->circle = DRW_Circle();
    this->circle.color = 0x00FF00;
    this->circle.basePoint = DRW_Coord(0.0, 0.0, 0.0);
    this->circle.radious = 0.5;
    this->circle.visible = false;

}

PCB_Part::PCB_Part(QString name, QString x, QString y){
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

void PCB_Part::set_dx(double x){
    this->dx = x;
    this->sx = QString::number(x);
}

void PCB_Part::set_dy(double y){
    this->dy = y;
    this->sy = QString::number(y);
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

double PCB_Part::get_dx(){
    return this->dx;
}

double PCB_Part::get_dy(){
    return this->dy;
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
PCB_PartKind::PCB_PartKind(QString name){
    this->set_name(name);

}
void PCB_PartKind::set_name(QString name){
    this->name = name;
}

QString PCB_PartKind::get_name(){
    return this->name;
}




