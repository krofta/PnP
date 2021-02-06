#ifndef CUSTOMTABLEWIDGETITEM_H
#define CUSTOMTABLEWIDGETITEM_H

#include <QTableWidgetItem>
#include "pcb_part.h"

class CustomTableWidgetItem : public QTableWidgetItem
{
public:
    CustomTableWidgetItem(PCB_PartKind *pcb_part_kind);
    PCB_PartKind *pcb_part_kind = nullptr;
};

#endif // CUSTOMTABLEWIDGETITEM_H
