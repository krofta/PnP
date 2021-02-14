#ifndef CUSTOMTABLEWIDGETITEM_H
#define CUSTOMTABLEWIDGETITEM_H

#include <QTableWidgetItem>
#include "pcb_part.h"

// just a comment

class CustomTableWidgetItem : public QTableWidgetItem
{
public:
    CustomTableWidgetItem(PCB_PartKind *pcb_part_kind, processParameter p);
    PCB_PartKind *pcb_part_kind = nullptr;
    processParameter p;
};

#endif // CUSTOMTABLEWIDGETITEM_H
