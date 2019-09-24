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
    if(this->dxf_initialised == 0){
        this->msgBox.setText("Erst mal 'ne DXF-Datei importieren, min Jung!");
        this->msgBox.exec();
        return;
    }
    QString s = QFileDialog::getOpenFileName(0, "Open CSV", QString(), "CSV Files (*.csv)");
    if(s.isEmpty())
    {
        return;
    }

    this->file_parser = CSV_Parser();
    this->file_parser.parse_csv_partlist(s, &this->pcb_partkinds);
    this->file_parser.partKindsToTreeView(this->pcb_partkinds, this->ui->treeWidget);

}


void MainWindow::on_rptButton_clicked(){
    if(this->dxf_initialised == 0){
        this->msgBox.setText("Erst mal 'ne DXF- und CSV-Datei importieren, min Jung!");
        this->msgBox.exec();
        return;
    }
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
                //data.basePoint.x-data.radious, data.basePoint.y-data.radious, 2*data.radious, 2*data.radious, attributesToPen(&data)

                part->ellipse = this->dxf.mScene.addEllipse(part->circle.basePoint.x-part->circle.radious, part->circle.basePoint.y-part->circle.radious,
                                            2*part->circle.radious,2*part->circle.radious,QPen(Qt::green),QBrush(Qt::green));
                //part->ellipse = this->dxf.addCircle(*part->getCircle());
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
        int visible = 0;
        // Checken ob irgendwelche Bauteile aktiviert
        for(int i = 0; i < item->childCount(); i++){
            CustomItem* citem = (CustomItem*)item->child(i);
            if(citem->part->get_visible())
                visible = 1;
        }
        // Wenn Bauteile aktiviert -> Alle deaktivieren
        if(visible)
            for(int i = 0; i < item->childCount(); i++){
                CustomItem* citem = (CustomItem*)item->child(i);
                citem->part->set_visible(0);

                this->dxf.mScene.removeItem(citem->part->ellipse);
                QBrush brush_white(Qt::white);
                citem->setBackground(1, brush_white);

            }
        // Wenn keine Bauteile aktiviert -> Alle aktivieren
        else
            for(int i = 0; i < item->childCount(); i++){
                CustomItem* citem = (CustomItem*)item->child(i);
                citem->part->set_visible(1);
                //part->circle.color24 = (0xFFFFFF);
                citem->part->circle.colorName = "green";

                citem->part->ellipse = this->dxf.mScene.addEllipse(citem->part->circle.basePoint.x-citem->part->circle.radious, citem->part->circle.basePoint.y-citem->part->circle.radious,
                                            2*citem->part->circle.radious,2*citem->part->circle.radious,QPen(Qt::green),QBrush(Qt::green));
                //part->ellipse = this->dxf.addCircle(*part->getCircle());
                QBrush brush_green(Qt::green);
                citem->setBackground(1, brush_green);

            }
    }

}
