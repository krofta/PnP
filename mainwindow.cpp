#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>


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
    //->iniD = DXFInterface(this->filename);
    this->ui->graphicsView->setScene(dxf.scene());
    //this->ui->graphicsView->resize(800, 600);
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



    // Funktionierndes Beispiel
//    for( const QString line : lines){
//        QStringList lineStrings = line.split(';', QString::SkipEmptyParts);
//        if(lineStrings.count() == 2)
//            addTreeRoot(lineStrings[0], lineStrings[1].replace(" ", ""));
//    }




}

void MainWindow::addTreeRoot(QString name, QString bauteile)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);
    treeItem->setText(0, name);

    const QStringList teile = bauteile.split(',', QString::SkipEmptyParts);
    for(const QString &teil : teile){
        addTreeChild(treeItem, teil);

    }
}


void MainWindow::addTreeChild(QTreeWidgetItem *parent,
                  QString name)
{
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();
    treeItem->setText(0, name);
    parent->addChild(treeItem);

}

void MainWindow::on_rptButton_clicked(){

}

