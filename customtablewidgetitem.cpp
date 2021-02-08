#include "customtablewidgetitem.h"

CustomTableWidgetItem::CustomTableWidgetItem(PCB_PartKind *pcb_part_kind)
{
    this->pcb_part_kind = pcb_part_kind;
    this->setText(pcb_part_kind->get_name());
}

