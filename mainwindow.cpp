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
    this->dxf_initialised = 0;
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
    this->dxf_initialised = 1;

}


void MainWindow::on_csvButton_clicked(){
    // Noch keine Szene initialisiert? Dann zurück
    if(this->dxf_initialised == 0)
        return;
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
    if(this->dxf_initialised == 0)
        return;
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
    CustomItem *c_item;

    if(item->parent() != nullptr/*this->ui->treeWidget*/){
        c_item = (CustomItem*)item;
        if(c_item->part != nullptr){
            part = c_item->part;
            if(part->get_visible() == 0){
                part->set_visible(1);
                //part->circle.color24 = (0xFFFFFF);
                part->circle.colorName = "green";
                //part->circle.
                part->ellipse = this->dxf.addCircle(*part->getCircle());
                QBrush brush_green(Qt::green);
                ui->treeWidget->currentItem()->setBackground(1, brush_green);
            }
            else
            {
                part->set_visible(0);

                this->dxf.mScene.removeItem(part->ellipse);
                QBrush brush_white(Qt::white);
                ui->treeWidget->currentItem()->setBackground(1, brush_white);
            }

        }
    }
    else{

    }



//    QBrush brush_red(Qt::red);
//    //twitem = ui->treeWidget->currentItem();
//    QModelIndex index = ui->treeWidget->currentIndex();
//    //index = twitem->indexOfChild(twitem);
//    //twitem->setBackground(0, brush_red);
//    QBrush brush_green(Qt::green);
//    ui->treeWidget->currentItem()->setBackground(1, brush_green);
}
