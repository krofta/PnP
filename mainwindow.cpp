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

    //this->treeModel.csv_to_treemodel(s);
    //QString path = "/home/aljosha/Schreibtisch/QtTest/Stückliste_Test.csv";
    QFile file(s);
    file.open(QIODevice::ReadOnly);
    //this->treeModel();
    const QString data = file.readAll();
    file.close();

    ui->treeWidget->setColumnCount(3);
    ui->treeWidget->setHeaderLabels(QStringList() << "Bauteilart" << "x-Koord" << "y-Koord");

    const QStringList lines =  data.split('\n');

    for( const QString line : lines){
        addTreeRoot(line, "");
    }



}

void MainWindow::addTreeRoot(QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

    const QStringList lineStrings = name.split(';', QString::SkipEmptyParts);
     if(lineStrings.count() == 2){
        treeItem->setText(0, lineStrings[0]);

        const QStringList bauteile = lineStrings[1].split(',', QString::SkipEmptyParts);
        //if(bauteile.count() > 1)
            for(const QString &teil : bauteile){
                treeItem->setText(0, lineStrings[0]);
                addTreeChild(treeItem, teil , "Child_first");

            }

    }




    // QTreeWidgetItem::setText(int column, const QString & text)
    //int counter = 0;

    //treeItem->setText(0, name);
    //treeItem->setText(1, description);
    //addTreeChild(treeItem, name + "A", "Child_first");
    //addTreeChild(treeItem, name + "B", "Child_second");
}


void MainWindow::addTreeChild(QTreeWidgetItem *parent,
                  QString name, QString description)
{
    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
    treeItem->setText(1, description);

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);
}

void MainWindow::on_rptButton_clicked(){

}

