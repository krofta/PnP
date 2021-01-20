#include "csv_parser.h"
#include "customitem.h"
#include <QFile>



CSV_Parser::CSV_Parser(){
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
            PCB_PartKind kind = PCB_PartKind(lineStrings[0]);
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

            PCB_PartKind kind = PCB_PartKind(lineStrings[4].replace("\"", ""));
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

            PCB_PartKind kind = PCB_PartKind(lineStrings[3]);
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
            treeItemRoot->addChild(treeItemChild);
        }
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
                        part_kinds[i].parts[j].refreshCircle();
                    }
                }
            }
        }
    }
    return 0;
}

