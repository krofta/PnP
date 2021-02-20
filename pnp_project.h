#ifndef PNP_PROJECT_H
#define PNP_PROJECT_H

#include <QList>
#include <QSettings>
#include <QColor>
#include <QObject>
#include "pcb_part.h"

enum CAD_type{
    KiCAD,
    OrCAD
};


class pnp_project : public QObject
{
    Q_OBJECT
public:
    pnp_project(QObject *parent = 0);

public:
    QString project_file;
    QList<QString> dxf_files;
    QString BillOfMaterialFile;
    QString PickAndPlaceFile;

    QColor dot_color;
    double dot_size;

    enum CAD_type cad;

    QList<PCB_PartKind> pcb_partkinds;
    void new_project();
    void load_project(QString file);
    void save_project(QString file);

signals:
    void send_new_project(QString file);
};

#endif // PNP_PROJECT_H
