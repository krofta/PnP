#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>

#include "customitem.h"
#include "src/dxfinterface.h"
#include "libdxfrw/src/libdxfrw.h"
#include <src/dxfsceneview.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showEvent(QShowEvent *ev)
{
    QMainWindow::showEvent(ev);
    showEventHelper();
}

void MainWindow::showEventHelper()
{
    // your code placed here
    //ui->setupUi(this);
    ui->treeWidget->setColumnCount(3);
    ui->treeWidget->setHeaderLabels(QStringList() << "Bauteilart" << "x-Koord" << "y-Koord");
    ui->treeWidget->setColumnWidth (0, 180 );
    ui->treeWidget->setAttribute(Qt::WA_DeleteOnClose);
}



void MainWindow::on_dxfButton_clicked()
{
    this->filename = QFileDialog::getOpenFileName(0, "Open DXF", QString(), "DXF Files (*.dxf)");
    if(filename.isEmpty())
    {
        return;
    }
    this->ui->statusBar->showMessage(this->filename);
    dxf.iniDXF(this->filename);
    this->ui->graphicsView->setScene(dxf.scene());
    this->ui->graphicsView->fitInView(dxf.scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
    this->ui->graphicsView->show();

}


void MainWindow::on_csvButton_clicked(){
    QString s = QFileDialog::getOpenFileName(0, "Open CSV", QString(), "CSV Files (*.csv)");
    if(s.isEmpty())
    {
        return;
    }
    //this->msgBox.setText("Filepath csv:" + s);
    //this->msgBox.exec();

    this->file_parser = CSV_Parser();
    this->file_parser.parse_csv_partlist(s, &this->pcb_partkinds);
    this->file_parser.partKindsToTreeView(this->pcb_partkinds, this->ui->treeWidget);
}


void MainWindow::on_rptButton_clicked(){

    QString s = QFileDialog::getOpenFileName(0, "Open RPT", QString(), "RPT Files (*.rpt)");
    if(s.isEmpty())
    {
        return;
    }

    this->file_parser = CSV_Parser();
    this->ui->treeWidget->clear();
    this->file_parser.parse_rpt_datei(s, this->pcb_partkinds);
    this->file_parser.partKindsToTreeView(this->pcb_partkinds, this->ui->treeWidget);


}




void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    PCB_Part *part;
    double x = 0;
    double y = 0;
//    QVariant var;
//    for(int i = 0; i < item->childCount(); i++){
//        items = item->child(i);
//        for(int j = 0; j < items->columnCount(); j++)
//             var = items->data(j,0);
//    }
    CustomItem *c_item;// = CustomItem();

    if(item->parent() != nullptr/*this->ui->treeWidget*/){
        c_item = (CustomItem*)item;
        if(c_item->part != nullptr){
            part = c_item->part;
            x = part->get_dx();
            y = part->get_dx();
            this->dxf.addCircle(*part->getCircle());
            //this->dxf.
        }
    }
    else{

    }



    QBrush brush_red(Qt::red);
    //twitem = ui->treeWidget->currentItem();
    QModelIndex index = ui->treeWidget->currentIndex();
    //index = twitem->indexOfChild(twitem);
    //twitem->setBackground(0, brush_red);
    QBrush brush_green(Qt::green);
    ui->treeWidget->currentItem()->setBackground(1, brush_green);
}
