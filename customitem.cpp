#include "customitem.h"

CustomItem::CustomItem( PCB_Part *part): QTreeWidgetItem()
{
    this->part = part;
}

