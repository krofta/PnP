#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QTreeWidgetItem>
#include "pcb_part.h"

class CustomItem : public QTreeWidgetItem
{
public:
    CustomItem(PCB_Part *part);
    PCB_Part *part;

};

#endif // CUSTOMITEM_H
