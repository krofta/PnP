#include "customtablewidgetitem.h"
#define COLUMN_COLOR 0x2F,0x4F,0x4F
CustomTableWidgetItem::CustomTableWidgetItem(PCB_PartKind *pcb_part_kind, processParameter p)
{
    this->p = p;
    this->pcb_part_kind = pcb_part_kind;
    switch(p){
    case processParameter::name:
        this->setText(pcb_part_kind->get_name());
        break;
    case processParameter::barcode:
        this->setText(QString(pcb_part_kind->parameters.sBarcode));
        break;
    case processParameter::accrot:
        this->setText(QString::number(pcb_part_kind->parameters.dAccRot));
        break;
    case processParameter::accx:
        this->setText(QString::number(pcb_part_kind->parameters.dAccX));
        break;
    case processParameter::accy:
        this->setText(QString::number(pcb_part_kind->parameters.dAccY));
        break;
    case processParameter::accz:
        this->setText(QString::number(pcb_part_kind->parameters.dAccZ));
        break;
    case processParameter::cv:
        //this->setText(QString::number(pcb_part_kind->parameters.iCV));
        this->setCheckState(pcb_part_kind->parameters.iCV ? Qt::Checked : Qt::Unchecked);
        this->setBackground(QBrush(QColor(COLUMN_COLOR)));//QColor(0x2F,0x4F,0x4F));
        break;
    case processParameter::fiducial:
        this->setCheckState(pcb_part_kind->parameters.iFiducial ? Qt::Checked : Qt::Unchecked);
        this->setBackground(QBrush(QColor(COLUMN_COLOR)));
        //this->setText(QString::number(pcb_part_kind->parameters.iFiducial));
        break;
    case processParameter::height:
        this->setText(QString::number(pcb_part_kind->parameters.dHeight));
        break;
    case processParameter::ignore:
        //this->setText(QString::number(pcb_part_kind->parameters.iIgnore));
        this->setCheckState(pcb_part_kind->parameters.iIgnore ? Qt::Checked : Qt::Unchecked);
        this->setBackground(QBrush(QColor(COLUMN_COLOR)));
        break;
    case processParameter::matched:
        break;
    case processParameter::nozzle:
        this->setText(QString::number(pcb_part_kind->parameters.iNozzle));
        break;
    case processParameter::offsetrot:
        this->setText(QString::number(pcb_part_kind->parameters.dOffsetRot));
        break;
    case processParameter::offsetx:
        this->setText(QString::number(pcb_part_kind->parameters.dOffsetX));
        break;
    case processParameter::offsety:
        this->setText(QString::number(pcb_part_kind->parameters.dOffsetY));
        break;
    case processParameter::velrot:
        this->setText(QString::number(pcb_part_kind->parameters.dVelRot));
        break;
    case processParameter::velx:
        this->setText(QString::number(pcb_part_kind->parameters.dVelX));
        break;
    case processParameter::vely:
        this->setText(QString::number(pcb_part_kind->parameters.dVelY));
        break;
    case processParameter::velz:
        this->setText(QString::number(pcb_part_kind->parameters.dVelZ));
        break;

    }
}

