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
    bool set_sx(QString x, int invert);
    bool set_sy(QString y);
    bool set_srotation(QString rot);
    void set_layer(QString layer);
    void set_dx(double x);
    void set_dy(double y);
    void set_drotation(double rot);
    void set_visible(int val);
    void set_color(int color);
    void refreshCircle();

    QString get_name();
    QString get_sx();
    QString get_sy();
    QString get_srotation();
    QString get_layer();
    double get_dx();
    double get_dy();
    double get_drotation();
    int get_visible();
    int get_color();
    DRW_Circle* getCircle();
    QGraphicsEllipseItem *ellipse;

    DRW_Circle circle;

private:
    QString name;
    QString sx;
    QString sy;
    QString srotation;
    QString layer;  // top or bottom
    double dx;
    double dy;
    double drotation;
    int visible;
    int color;



};

typedef struct{
    char sBarcode[100];
    int iIgnore;        // Flag: this parts will be ignored
    int iFiducial;      // Flag: this component is a fiducial
    int iCV;            // Flag: use CV for this component
    int iMatched;       // Flag: this part is matched with a feeder
    int iNozzle;        // Nozzle to pick this part

    double dVelX;       // process velocity in x
    double dAccX;       // process acceleration in x
    double dVelY;       // process velocity in y
    double dAccY;       // process acceleration in y
    double dVelZ;       // process velocity in z
    double dAccZ;       // process acceleration in z
    double dVelRot;     // process velocity during rotation
    double dAccRot;     // process acceleration during rotation

    double dHeight;     // heigth of the component if needed
    double dOffsetX;    // x offset if footprint is not centered
    double dOffsetY;    // y offset if footprint is not centered
    double dOffsetRot;  // rotation offset if footprint is not centered
}ProcessParameters;

enum processParameter {
    name,
    barcode,
    ignore,
    fiducial,
    cv,
    matched,
    nozzle,
    velx,
    accx,
    vely,
    accy,
    velz,
    accz,
    velrot,
    accrot,
    height,
    offsetx,
    offsety,
    offsetrot
};


class PCB_PartKind
{
public:
    PCB_PartKind();
    PCB_PartKind(QString name, ProcessParameters *p);
    ~PCB_PartKind();
    QList<PCB_Part> parts;
    void set_name(QString name);
    QString get_name();
    ProcessParameters parameters;
    enum processParameter p;
private:
    QString sName = "";


};

#endif // PCB_PART_H
