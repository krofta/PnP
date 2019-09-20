#include "pcb_part.h"

// -----------------------------KONSTRUKTOREN

PCB_Part::PCB_Part()
{


}

PCB_Part::~PCB_Part(){

}

PCB_Part::PCB_Part(QString name, QString x, QString y){
    this->set_name(name);
    this->set_sx(x);
    this->set_sy(y);
    this->color = 0xFF0000;
    this->visible = 1;

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
    return this->visible;
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




