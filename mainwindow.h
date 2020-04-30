#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QList>
#include <QSettings>
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
    QString dxf_filename;
    QString csv_filename;
    QString rpt_filename;
    DXFInterface dxf;
    QMessageBox msgBox;
    // Liste von Objekte um Informationen über Position und Name zu Speichern
    QList<PCB_PartKind> pcb_partkinds;
    // Objekt zum parsen der scv und rpt dateien
    CSV_Parser file_parser;
    int dxf_initialised;
    int csv_initialised;
    int rpt_initialised;
    QColor dot_color;
    double dot_size;

protected:
    void showEvent(QShowEvent *ev);

private slots:
    void on_dxfButton_clicked();

    void on_csvButton_clicked();
    
    void on_rptButton_clicked();
    
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_toggleButton_clicked();

private Q_SLOTS:
    void onTextColorSelected(QColor color);

    void on_reloadButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_rbOrCAD_toggled(bool checked);

    void on_rbKiCAD_toggled(bool checked);


private:
    Ui::MainWindow *ui;
    void showEventHelper();
    void loadSettings();
    void saveSettings();


};

#endif // MAINWINDOW_H
