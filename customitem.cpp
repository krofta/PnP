#include "customitem.h"


CustomItem::CustomItem():QTreeWidgetItem(){

}

CustomItem::CustomItem( PCB_Part *part): QTreeWidgetItem()
{
    this->part = part;
}

