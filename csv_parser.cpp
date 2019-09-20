#include "csv_parser.h"
#include <QFile>


CSV_Parser::CSV_Parser()
{

}

int CSV_Parser::parse_csv_partlist(QString path, QList<PCB_PartKind> *part_kinds){

    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
        return 1;
    QString data = file.readAll();
    file.close();

    QStringList lines =  data.split('\n');
    for(QString line : lines){
        QStringList lineStrings = line.split(';', QString::SkipEmptyParts);
        if(lineStrings.count() == 2){
            PCB_PartKind kind = PCB_PartKind(lineStrings[0]);
            QStringList parts = lineStrings[1].replace(" ", "").split(',');
            for(QString part : parts){
                kind.parts.append(PCB_Part(part));
                //PCB_Part pcb_part = ;
            }
            part_kinds->append(kind);
        }
    }
    return 0;
}

int CSV_Parser::partKindsToTreeView(QList<PCB_PartKind> part_kinds, QTreeWidget *tree){
 //   if( part_kinds == nullptr || tree == nullptr)
//        return 1;
    for(int i = 0; i < part_kinds.count(); i++){
        addTreeRoot(tree, part_kinds[i]);

    }
    return 0;
}

void CSV_Parser::addTreeRoot(QTreeWidget *tree, PCB_PartKind kind)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(tree);
    treeItem->setText(0, kind.get_name());
    for(PCB_Part part : kind.parts){
        addTreeChild(treeItem, part);

    }
}


void CSV_Parser::addTreeChild(QTreeWidgetItem *parent, PCB_Part part)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0, part.get_name());
    treeItem->setText(1, part.get_sx());
    treeItem->setText(2, part.get_sy());
    parent->addChild(treeItem);

}

