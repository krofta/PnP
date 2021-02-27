#ifndef PNP_PROJECT_H
#define PNP_PROJECT_H

#include <QList>
#include <QSettings>
#include <QColor>
#include <QObject>
#include "pcb_part.h"

enum CAD_TYPE{
    CAD_TYPE_UNDEF,
    KiCAD,
    OrCAD,
    Franzi
};
Q_DECLARE_METATYPE(CAD_TYPE)

enum GRAPIC_TYPE{
    GRAPIC_TYPE_UNDEF,
    DXF,
    SVG
};
Q_DECLARE_METATYPE(GRAPIC_TYPE)

class pnp_project : public QObject
{
    Q_OBJECT
public:
    pnp_project(QObject *parent = 0);

public:
    QString project_file;
    QList<QString> dxf_files;
    QString svg_file;
    QString BillOfMaterialFile;
    QString PickAndPlaceFile;

    QColor dot_color;
    double dot_size;

    enum CAD_TYPE bom_type;
    enum CAD_TYPE pos_type;
    enum GRAPIC_TYPE graphic_type;

    QList<PCB_PartKind> pcb_partkinds;
    int create_file(QString last_path);
    int select_file(QString last_path);
    void new_project();
    void load_project();
    void save_project();

signals:
    void send_new_project(QString file);
    void send_dot_size(double size);
};

#endif // PNP_PROJECT_H
