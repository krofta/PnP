#include "csv_parser.h"
#include "customitem.h"
#include "customtablewidgetitem.h"
#include <QFile>
#include <QSettings>



CSV_Parser::CSV_Parser(){
    this->loadSettings();
}
CSV_Parser::~CSV_Parser(){
    this->saveSettings();
}

int CSV_Parser::parse_csv_partlist(QString path, QList<PCB_PartKind> *part_kinds){

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return 1;
    QString data = file.readAll();
    file.close();
    part_kinds->clear();
    QStringList lines =  data.split('\n');
    for(QString line : lines){
        QStringList lineStrings = line.split(';', QString::SkipEmptyParts);
        if(lineStrings.count() == 2){
            PCB_PartKind kind = PCB_PartKind(lineStrings[0], &this->defaultPrameters);
            QStringList parts = lineStrings[1].replace(" ", "").replace("\r","").split(',');
            for(QString part : parts){
                kind.parts.append(PCB_Part(part));
            }
            part_kinds->append(kind);
        }
    }
    return 0;
}

int CSV_Parser::parse_csv_partlist(QString path, QList<PCB_PartKind> * part_kinds, bool KiCad){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return 1;
    QString data = file.readAll();
    file.close();
    part_kinds->clear();
    QStringList lines =  data.split('\n');
    bool first = true;
    for(QString line : lines){
        QStringList lineStrings = line.split(';', QString::KeepEmptyParts);
        if(first){
            first = false;
            continue;
        }
        // Zusammengefasste Bauteile mit "R101,R202" usw
        if(lineStrings.count() > 6){

            PCB_PartKind kind = PCB_PartKind(lineStrings[4].replace("\"", ""), &this->defaultPrameters);
            QStringList subLineStrings = lineStrings[1].replace("\"", "").split(',',QString::SkipEmptyParts);
            for (QString x : subLineStrings){
                kind.parts.append(PCB_Part(x));
            }
            part_kinds->append(kind);
        }
    }
    return 0;
}


int CSV_Parser::parse_BOM_partlist(QString path, QList<PCB_PartKind> * part_kinds){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return 1;
    QString data = file.readAll();
    file.close();
    part_kinds->clear();
    QStringList lines =  data.split('\n');
    int cnt = 0;
    for(QString line : lines){

        if(cnt < 14){
            cnt++;
            continue;
        }
        QStringList lineStrings = line.split('\t', QString::SkipEmptyParts);
        if(lineStrings.count() == 5){

            PCB_PartKind kind = PCB_PartKind(lineStrings[3], &this->defaultPrameters);
            QStringList subLineStrings = lineStrings[2].split(',',QString::SkipEmptyParts);
            for (QString x : subLineStrings){
                kind.parts.append(PCB_Part(x));
            }
            part_kinds->append(kind);
        }
        else if(lineStrings.count() == 1){
            QStringList subLineStrings = lineStrings[0].replace('\r',"").split(',',QString::SkipEmptyParts);
            for (QString x : subLineStrings){
                if(x == "")
                    continue;
                part_kinds->last().parts.append(x);
            }
        }
    }
    return 0;
}

int CSV_Parser::partKindsToTreeView(QList<PCB_PartKind> &part_kinds, QTreeWidget *tree){
    tree->clear();
    for(int i = 0; i < part_kinds.count(); i++){
        QTreeWidgetItem *treeItemRoot = new QTreeWidgetItem(tree);
        treeItemRoot->setText(0, part_kinds[i].get_name());
        for(int j = 0; j < part_kinds[i].parts.count(); j++){
            CustomItem *treeItemChild = new CustomItem(&part_kinds[i].parts[j]);
            treeItemChild->setText(0, part_kinds[i].parts[j].get_name());
            treeItemChild->setText(1, part_kinds[i].parts[j].get_sx());
            treeItemChild->setText(2, part_kinds[i].parts[j].get_sy());
            treeItemChild->setText(3, part_kinds[i].parts[j].get_srotation());
            treeItemChild->setText(4, part_kinds[i].parts[j].get_layer());
            treeItemRoot->addChild(treeItemChild);
        }
    }
    return 0;
}

int CSV_Parser::partKindstoTableView(QList<PCB_PartKind> &part_kinds, QTableWidget *table)
{
    table->clear();
    table->setHorizontalHeaderLabels(QStringList() << "Name"
        << "Barcode"
        << "Ignore"
        << "Fiducial"
        << "Caera Vision"
        << "Nozzle"
        << "Speed X"
        << "Acc. X"
        << "Speed Y"
        << "Acc. Y"
        << "Speed Z"
        << "Acc. Z"
        << "Speed rot."
        << "Acc. rot."
        << "Height"
        << "Offset X"
        << "Offset Y"
        << "Offset rot."
        );
    table->setRowCount(part_kinds.count());
    for(int i = 0, column = 0; i < part_kinds.count(); i++){
        column = 0;
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::name));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::barcode));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::ignore));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::fiducial));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::cv));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::nozzle));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::velx));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::accx));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::vely));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::accy));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::velz));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::accz));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::velrot));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::accrot));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::height));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::offsetx));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::offsety));
        table->setItem(i, column++, new CustomTableWidgetItem(&part_kinds[i], processParameter::offsetrot));
    }
    return 0;
}

void CSV_Parser::addTreeRoot(QTreeWidget *tree, PCB_PartKind kind)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(tree);
    treeItem->setText(0, kind.get_name());

    for(int i = 0; i < kind.parts.count(); i++){
        addTreeChild(treeItem, kind.parts[i]);

    }
}


void CSV_Parser::addTreeChild(QTreeWidgetItem *parent, PCB_Part part)
{
    CustomItem *treeItem = new CustomItem(&part);
    treeItem->setText(0, part.get_name());
    treeItem->setText(1, part.get_sx());
    treeItem->setText(2, part.get_sy());
    parent->addChild(treeItem);

}

void CSV_Parser::loadSettings()
{
    QSettings setting("kPlacer","CSV_ParserSettings");
    setting.beginGroup("Default_Process_Parameters");

    strcpy(this->defaultPrameters.sBarcode, "");// = "";
    this->defaultPrameters.iIgnore      = setting.value("Ignore", 0).toInt();
    this->defaultPrameters.iFiducial    = setting.value("Fiducial", 0).toInt();
    this->defaultPrameters.iCV          = setting.value("Computer_Vision", 0).toInt();
    this->defaultPrameters.iMatched = 0;
    this->defaultPrameters.iNozzle      = setting.value("Nozzle", 0).toInt();
    this->defaultPrameters.dVelX        = setting.value("Velocity_X",100.0).toDouble();
    this->defaultPrameters.dAccX        = setting.value("Acceleration_X",1000.0).toDouble();
    this->defaultPrameters.dVelY        = setting.value("Velocity_Y",100.0).toDouble();
    this->defaultPrameters.dAccY        = setting.value("Acceleration_Y",1000.0).toDouble();
    this->defaultPrameters.dVelZ        = setting.value("Velocity_Z",100.0).toDouble();
    this->defaultPrameters.dAccZ        = setting.value("Acceleration_Z",1000.0).toDouble();
    this->defaultPrameters.dVelRot      = setting.value("Velocity_Rot",100.0).toDouble();
    this->defaultPrameters.dAccRot      = setting.value("Acceleration_Rot",1000.0).toDouble();
    this->defaultPrameters.dHeight      = setting.value("Height",1.0).toDouble();
    this->defaultPrameters.dOffsetX     = setting.value("Offset_X",0.0).toDouble();
    this->defaultPrameters.dOffsetY     = setting.value("Offset_Y",0.0).toDouble();
    this->defaultPrameters.dOffsetRot   = setting.value("Offset_Rot",0.0).toDouble();
    setting.endGroup();

}

void CSV_Parser::saveSettings()
{
    QSettings setting("kPlacer","CSV_ParserSettings");
    setting.beginGroup("Default_Process_Parameters");
    setting.setValue("Ignore", this->defaultPrameters.iIgnore );
    setting.setValue("Fiducial", this->defaultPrameters.iFiducial);
    setting.setValue("Computer_Vision", this->defaultPrameters.iCV);
    setting.setValue("Nozzle", this->defaultPrameters.iNozzle);
    setting.setValue("Velocity_X", this->defaultPrameters.dVelX);
    setting.setValue("Acceleration_X", this->defaultPrameters.dAccX);
    setting.setValue("Velocity_Y", this->defaultPrameters.dVelY);
    setting.setValue("Acceleration_Y", this->defaultPrameters.dAccY);
    setting.setValue("Velocity_Z",      this->defaultPrameters.dVelZ);
    setting.setValue("Acceleration_Z",  this->defaultPrameters.dAccZ);
    setting.setValue("Velocity_Rot", this->defaultPrameters.dVelRot);
    setting.setValue("Acceleration_Rot", this->defaultPrameters.dAccRot);
    setting.setValue("Height", this->defaultPrameters.dHeight);
    setting.setValue("Offset_X", this->defaultPrameters.dOffsetX);
    setting.setValue("Offset_Y", this->defaultPrameters.dOffsetY);
    setting.setValue("Offset_Rot",this->defaultPrameters.dOffsetRot);
    setting.endGroup();
}

int CSV_Parser::parse_rpt_datei(QString path, QList<PCB_PartKind> &part_kinds/*, DXFInterface &dxf*/){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return 1;
    QString data = file.readAll();
    file.close();

    QStringList lines =  data.split('\n');
    int count = 0;
    for(QString line : lines){
        count++;
        if( count < 5 )continue;    // Die ersten 5 Zeilen ignorieren
        QStringList lineStrings = line.split(',', QString::SkipEmptyParts);
        if(lineStrings.count() == 8){   // 9 Spalten
            for(int i = 0; i < part_kinds.count(); i++){

                for(int j = 0; j < part_kinds[i].parts.count(); j++){
                    if(lineStrings[0] == part_kinds[i].parts[j].get_name() ){
                        part_kinds[i].parts[j].set_sx(lineStrings[4]);
                        part_kinds[i].parts[j].set_sy(lineStrings[5]);
                        part_kinds[i].parts[j].refreshCircle();
                    }
                }
            }
        }
    }
    return 0;
}

int CSV_Parser::parse_pos_datei(QString path, QList<PCB_PartKind> &part_kinds/*, DXFInterface &dxf*/){
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return 1;
    QString data = file.readAll();
    file.close();
    QStringList lines =  data.split('\n');
    int count = 0;
    for(QString line : lines){
        count++;
        if( count < 5 )continue;    // Die ersten 5 Zeilen ignorieren
        QStringList lineStrings = line.split(' ', QString::SkipEmptyParts);
        if(lineStrings.count() == 7){   // 7 Spalten
            for(int i = 0; i < part_kinds.count(); i++){

                for(int j = 0; j < part_kinds[i].parts.count(); j++){
                    if(lineStrings[0] == part_kinds[i].parts[j].get_name() ){
                        if(lineStrings[6] == "bottom"){
                            part_kinds[i].parts[j].set_sx(lineStrings[3],true);
                        }
                        else{
                            part_kinds[i].parts[j].set_sx(lineStrings[3]);
                        }
                        part_kinds[i].parts[j].set_sy(lineStrings[4]);
                        part_kinds[i].parts[j].set_srotation(lineStrings[5]);
                        part_kinds[i].parts[j].set_layer(lineStrings[6]);
                        part_kinds[i].parts[j].refreshCircle();
                    }
                }
            }
        }
    }
    return 0;
}

