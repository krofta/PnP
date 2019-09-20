#ifndef CSV_PARSER_H
#define CSV_PARSER_H
#include <QString>
#include <QList>
#include <QTreeWidget>
#include "pcb_part.h"

class CSV_Parser
{
public:
    CSV_Parser();
    int parse_csv_partlist(QString path, QList<PCB_PartKind> * part_kinds);
    int partKindsToTreeView(QList<PCB_PartKind> part_kinds, QTreeWidget *tree);
    void addTreeRoot(QTreeWidget *tree, PCB_PartKind kind);
    void addTreeChild(QTreeWidgetItem *parent, PCB_Part part);


};

#endif // CSV_PARSER_H
