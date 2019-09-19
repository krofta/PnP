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

    this->treeModel.csv_to_treemodel(s);
    this->ui->treeView->setModel(&treeModel);
    this->ui->treeView->show();
    //this->ui->treeWidget->set
            //>setModel(this->treeModel);
}

void MainWindow::on_rptButton_clicked(){

}

