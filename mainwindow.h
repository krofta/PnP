#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QList>
#include <QSettings>
#include <QtWidgets>
#include "src/dxfinterface.h"
#include "libdxfrw/src/libdxfrw.h"
#include <src/dxfsceneview.h>

#include "pcb_part.h"
#include "csv_parser.h"
#include "pnp_project.h"

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QLabel;
class QMenu;
QT_END_NAMESPACE

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

    QString lastFilePath;
    QList<QString> last_projects;
    DXFInterface dxf;
    QMessageBox msgBox;
    // Liste von Objekte um Informationen über Position und Name zu Speichern

    // Objekt zum parsen der scv und rpt dateien
    CSV_Parser file_parser;
    pnp_project *project;
    int dxf_initialised;
    int csv_initialised;
    int rpt_initialised;

    //TODO: in klasse pnp_projekt verschieben
    QColor dot_color;
    double dot_size;
    QList<PCB_PartKind> pcb_partkinds;
    QString dxf_filename;
    QString BillOfMaterialFile;
    QString PickAndPlaceFile;

    QAction *recentFileActs[10];

protected:
    void showEvent(QShowEvent *ev);

private slots:
    void on_dxfButton_clicked();

    void on_csvButton_clicked();
    
    void on_rptButton_clicked();
    
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_toggleButton_clicked();

public slots:
    void receive_new_project(QString project);


private Q_SLOTS:
    void onTextColorSelected(QColor color);

    void on_reloadButton_clicked();

    void on_horizontalSlider_sliderMoved(int position);

    void on_rbOrCAD_toggled(bool checked);

    void on_rbKiCAD_toggled(bool checked);

    
    void on_btnFranzisStuekcliste_clicked();

    void on_clearButton_clicked();

private:
    Ui::MainWindow *ui;
    void showEventHelper();
    void addActions();
    void createRecentFileMenu();

    void openRecentFile();


    void loadSettings();
    void saveSettings();

    void add_dxf_file();
    void open_BOM_file(bool KiCAD);
    void open_pos_file(bool KiCAD);
    void open_franzisStueckliste();

    void reload_files();
    void clear_files();

    void toggle_parts();


};

#endif // MAINWINDOW_H
