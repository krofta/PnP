#ifndef PCB_PART_H
#define PCB_PART_H

#include <QString>
#include <QList>
#include "libdxfrw/src/libdxfrw.h"
class PCB_Part
{
public:
    PCB_Part();
    ~PCB_Part();
    PCB_Part(QString name, QString x = "0", QString y = "0");
    void set_name(QString name);
    bool set_sx(QString x);
    bool set_sy(QString y);
    void set_dx(double x);
    void set_dy(double y);
    void set_visible(int val);
    void set_color(int color);
    void refreshCircle();

    QString get_name();
    QString get_sx();
    QString get_sy();
    double get_dx();
    double get_dy();
    int get_visible();
    int get_color();
    DRW_Circle* getCircle();
    QGraphicsEllipseItem *ellipse;
    DRW_Circle circle;

private:
    QString name;
    QString sx;
    QString sy;
    double dx;
    double dy;
    int visible;
    int color;



};


class PCB_PartKind
{
public:
    PCB_PartKind();
    PCB_PartKind(QString name);
    ~PCB_PartKind();
    QList<PCB_Part> parts;
    void set_name(QString name);
    QString get_name();

private:
    QString name;

};

#endif // PCB_PART_H
