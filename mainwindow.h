#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTreeWidgetItem>
#include <QGraphicsScene>
#include <QList>
#include <QSettings>
#include <QtWidgets>
#include "src/dxfinterface.h"
#include "libdxfrw/src/libdxfrw.h"
#include <src/dxfsceneview.h>

#include "pcb_part.h"
#include "csv_parser.h"
#include "svgview.h"
#include "pnp_project.h"

QT_BEGIN_NAMESPACE
class QAction;
class QActionGroup;
class QGraphicsView;
class QGraphicsScene;
class QGraphicsRectItem;
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

    SvgView *m_svgview;
    CSV_Parser file_parser;
    pnp_project *project;
    int graphic_initialised;
    int csv_initialised;
    int rpt_initialised;

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
    void receive_dot_size(double size);
    void setRenderer(int renderMode);


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
    //bool open_svg_file();
    void open_franzisStueckliste();

    void open_files_from_project();
    void reload_files();
    int  partKindsToTreeView(QList<PCB_PartKind> &part_kinds, QTreeWidget *tree);
    int  partKindstoTableView(QList<PCB_PartKind> &part_kinds, QTableWidget *table);
    int  chipsToScene(QList<PCB_PartKind> &part_kinds, QGraphicsScene *scene);

    void clear_files();

    void toggle_parts();

    QAction *m_nativeAction;
    QAction *m_glAction;
    QAction *m_imageAction;
    QAction *m_antialiasingAction;
    QAction *m_backgroundAction;
    QAction *m_outlineAction;

    QGraphicsScene *m_scene;

};

#endif // MAINWINDOW_H
