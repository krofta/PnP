#ifndef CSV_PARSER_H
#define CSV_PARSER_H
#include <QString>
#include <QList>
#include <QTreeWidget>
#include "pcb_part.h"
#include "src/dxfinterface.h"
#include "libdxfrw/src/libdxfrw.h"
#include <src/dxfsceneview.h>

class CSV_Parser
{
public:
    CSV_Parser();
    // scv Datei (Stückliste) von Franzi einlesen
    int parse_csv_partlist(QString path, QList<PCB_PartKind> * part_kinds);
    int parse_csv_partlist(QString path, QList<PCB_PartKind> * part_kinds, bool KiCad);
    int parse_BOM_partlist(QString path, QList<PCB_PartKind> * part_kinds);
    int partKindsToTreeView(QList<PCB_PartKind> &part_kinds, QTreeWidget *tree);

    // rpt Datei (Place Daten aus Allegro) einlesen und zu der Stückliste matchen
    int parse_rpt_datei(QString path, QList<PCB_PartKind> &part_kinds/*, DXFInterface &dxf*/);
    int parse_pos_datei(QString path, QList<PCB_PartKind> &part_kinds/*, DXFInterface &dxf*/);

    // Daten in Treeview einfügen
    void addTreeRoot(QTreeWidget *tree, PCB_PartKind kind);
    void addTreeChild(QTreeWidgetItem *parent, PCB_Part part);


    ProcessParameters defaultPrameters;


};

#endif // CSV_PARSER_H
