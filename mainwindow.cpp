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
    //ui->setupUi(this);
    ui->treeWidget->setColumnCount(3);
    ui->treeWidget->setHeaderLabels(QStringList() << "Bauteilart" << "x-Koord" << "y-Koord");

    QStringList lines =  data.split('\n');

    for( const QString line : lines){
        QStringList lineStrings = line.split(';', QString::SkipEmptyParts);
        if(lineStrings.count() == 2)
            addTreeRoot(lineStrings[0], lineStrings[1].replace(" ", ""));
    }


    // Ab hier Test Stuff

//    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
//    ui->setupUi(this);

//    // Set the number of columns in the tree
//    ui->treeWidget->setColumnCount(3);

//    // Add root nodes
//    addTreeRoot("A", "");
//    addTreeRoot("B", "");
//    addTreeRoot("C", "");



}

void MainWindow::addTreeRoot(QString name, QString bauteile)
{
//    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);
    treeItem->setText(0, name);

//    const QStringList lineStrings = name.split(';', QString::SkipEmptyParts);
//     if(lineStrings.count() == 2){
//        treeItem->setText(0, lineStrings[0]);

    const QStringList teile = bauteile.split(',', QString::SkipEmptyParts);
    for(const QString &teil : teile){
        //treeItem->setText(0, lineStrings[0]);
        addTreeChild(treeItem, teil);

    }



     // AB hier test stuff


    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
//    QTreeWidgetItem *treeItem = new QTreeWidgetItem(ui->treeWidget);

//    // QTreeWidgetItem::setText(int column, const QString & text)
//    treeItem->setText(0, name);
//    //treeItem->setText(1, description);
//    addTreeChild(treeItem, name + "A" );
//    addTreeChild(treeItem, name + "B");



}


void MainWindow::addTreeChild(QTreeWidgetItem *parent,
                  QString name)
{
//    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
//    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

//    // QTreeWidgetItem::setText(int column, const QString & text)
//    treeItem->setText(0, name);
//    //treeItem->setText(1, description);

//    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
//    parent->addChild(treeItem);


    // Ab hier Test Stuff


    // QTreeWidgetItem(QTreeWidget * parent, int type = Type)
    QTreeWidgetItem *treeItem = new QTreeWidgetItem();

    // QTreeWidgetItem::setText(int column, const QString & text)
    treeItem->setText(0, name);
//    treeItem->setText(1, "test");
//    treeItem->setText(2, "test2");

    // QTreeWidgetItem::addChild(QTreeWidgetItem * child)
    parent->addChild(treeItem);

}

void MainWindow::on_rptButton_clicked(){

}

