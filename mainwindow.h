#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QList>
#include "src/dxfinterface.h"
#include "libdxfrw/src/libdxfrw.h"
#include <src/dxfsceneview.h>

#include "pcb_part.h"
#include "csv_parser.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    static void openFilePicker();
    void addTreeRoot(QString name, QString bauteile);
    void addTreeChild(QTreeWidgetItem *parent, QString name);
    QString filename;
    DXFInterface dxf;
    QMessageBox msgBox;
    // Liste von Objekte um Informationen über Position und Name zu Speichern
    QList<PCB_PartKind> pcb_partkinds;
    // Objekt zum parsen der scv und rpt dateien
    CSV_Parser file_parser;
    int dxf_initialised;

protected:
    void showEvent(QShowEvent *ev);

private slots:
    void on_dxfButton_clicked();

    void on_csvButton_clicked();
    
    void on_rptButton_clicked();
    
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::MainWindow *ui;
    void showEventHelper();


};

#endif // MAINWINDOW_H
