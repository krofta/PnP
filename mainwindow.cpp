#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QPushButton>
#include <QFileInfo>
#include "ColorPickerToolButton.h"
#include <QAction>

#include "customitem.h"
#include "src/dxfinterface.h"
#include "libdxfrw/src/libdxfrw.h"
#include <src/dxfsceneview.h>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->csv_initialised = this->rpt_initialised = this->dxf_initialised = 0;
    this->ui->splitter->setStretchFactor(1,3);
    this->project = new pnp_project();
    addActions();

    connect(this->project, &pnp_project::send_new_project, this, &MainWindow::receive_new_project);
}

MainWindow::~MainWindow()
{
    saveSettings();
    delete ui;
}

void MainWindow::showEvent(QShowEvent *ev)
{
    QMainWindow::showEvent(ev);
    showEventHelper();
    QObject::connect(ui->toolButton, SIGNAL(colorSelected(QColor)),
                     this, SLOT(onTextColorSelected(QColor)));
}

void MainWindow::showEventHelper()
{
    ui->treeWidget->setColumnCount(5);
    ui->treeWidget->setHeaderLabels(QStringList() << "Bauteilart" << "X" << "Y"<< "Rotation" << "Layer");
    ui->treeWidget->setColumnWidth (0, 120 );
    ui->treeWidget->setColumnWidth (1, 80 );
    ui->treeWidget->setColumnWidth (2, 80 );
    ui->treeWidget->setColumnWidth (3, 80 );
    ui->treeWidget->setColumnWidth (3, 60 );
    ui->treeWidget->setAttribute(Qt::WA_DeleteOnClose);

    ui->tableWidget->setColumnCount(18);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList() << "Name"
        << "Barcode"
        << "Ignore"
        << "Fiducial"
        << "Caera Vision"
        << "Nozzle"
        << "Speed X"
        << "Acc. X"
        << "Speed Y"
        << "Acc. Y"
        << "Speed Z"
        << "Acc. Z"
        << "Speed rot."
        << "Acc. rot."
        << "Height"
        << "Offset X"
        << "Offset Y"
        << "Offset rot."
        );

    this->loadSettings();
}

void MainWindow::openRecentFile()
{
    QAction *action = qobject_cast<QAction *>(sender());
    if (action)
        qDebug() << action->data().toString();
}

void MainWindow::addActions()
{

    for (int i = 0; i < 10; ++i) {
        recentFileActs[i] = new QAction(this);
        recentFileActs[i]->setVisible(false);
        connect(this->recentFileActs[i], &QAction::triggered,
                this, &MainWindow::openRecentFile);
    }

    // File-----------------------------------

    /*this->ui->actionOpenProject->setStatusTip("Opens an existing project");
    connect(this->ui->actionOpenProject, &QAction::triggered, this,
        [this]{
            this->project->load_project(this->last_projects.first());
        }
    );
    */

    this->ui->actionNewProject->setStatusTip("Creates a new project");
    connect(this->ui->actionNewProject, &QAction::triggered, this,
        [this]{
            this->project->new_project();
        }
    );

    // Adds a dxf graphic to the scene view
    this->ui->actionAdd_dxf_file->setStatusTip("Adds a dxf file to graphics scene");
    connect(this->ui->actionAdd_dxf_file, &QAction::triggered, this, &MainWindow::add_dxf_file);
    // open BOM file KiCAD
    this->ui->actionKiCAD_BOM->setStatusTip("Loads all kinds of parts of the pcb to the tree view");
    connect(this->ui->actionKiCAD_BOM, &QAction::triggered, this,
        [this]{
            open_BOM_file(true);
        }
    );
    // Open position file KiCAD
    this->ui->actionKiCAD_position_file->setStatusTip("Loads the coordinates of all parts");
    connect(this->ui->actionKiCAD_position_file, &QAction::triggered, this,
        [this]{
            this->open_pos_file(true);
        }
    );
    // Open BOM file OrCAD
    this->ui->actionOrCAD_BOM->setStatusTip("Loads all kinds of parts of the pcb to the tree view");
    connect(this->ui->actionOrCAD_BOM, &QAction::triggered, this,
        [this]{
            open_BOM_file(false);
        }
    );
    // Open position file OrCAD
    this->ui->actionOrCAD_position_file->setStatusTip("Loads the coordinates of all parts");
    connect(this->ui->actionOrCAD_position_file, &QAction::triggered, this,
        [this]{
            this->open_pos_file(false);
        }
    );
    // Open franzis Stückliste
    this->ui->actionFranzis_BOM->setStatusTip("Loads all kinds of parts of the pcb to the tree view");
    connect(this->ui->actionFranzis_BOM, &QAction::triggered, this, &MainWindow::open_franzisStueckliste);

    //newAct->setShortcuts(QKeySequence::New);
    // Reload all files of the specific project
    this->ui->actionReload_files->setStatusTip("Reload all project specific files");
    connect(this->ui->actionReload_files, &QAction::triggered, this, &MainWindow::reload_files);
    // set program to default state
    this->ui->actionRemove_all->setStatusTip("Sets program to default state");
    connect(this->ui->actionRemove_all, &QAction::triggered, this, &MainWindow::clear_files);


    // Tools-------------------------------
    this->ui->actionToggle_all_parts->setStatusTip("Toggles position dot of all existing parts");
    connect(this->ui->actionToggle_all_parts, &QAction::triggered, this, &MainWindow::toggle_parts);

}

void MainWindow::createRecentFileMenu()
{
    for (int i = 0; i < 10; ++i)
        this->ui->menuOpen_project->addAction(recentFileActs[i]);
            //menuOpen_project->addAction(recentFileActs[i]);
}
void MainWindow::onTextColorSelected(QColor color)
{
    //ui->textEdit->setTextColor(color);
    this->dot_color = color;
}



void MainWindow::on_dxfButton_clicked(){
    this->add_dxf_file();
}


void MainWindow::on_csvButton_clicked(){
}

void MainWindow::on_btnFranzisStuekcliste_clicked(){
    this->open_franzisStueckliste();
}



void MainWindow::on_rptButton_clicked(){
}




void MainWindow::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    PCB_Part *part;
    CustomItem *c_item;

    if(item->parent() != nullptr){
        c_item = (CustomItem*)item;
        if(c_item->part != nullptr){
            part = c_item->part;
            if(part->get_visible() == 0){
                part->set_visible(1);
                part->circle.colorName = "green";
                part->ellipse = this->dxf.mScene.addEllipse(part->circle.basePoint.x-this->dot_size, part->circle.basePoint.y-this->dot_size,
                                            2*this->dot_size,2*this->dot_size,QPen(this->dot_color),QBrush(this->dot_color));
                QBrush brush_green(this->dot_color);
                ui->treeWidget->currentItem()->setBackground(1, brush_green);
            }
            else
            {
                part->set_visible(0);
                if(part->ellipse != nullptr)
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
                if(citem->part->ellipse != nullptr)
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

                citem->part->ellipse = this->dxf.mScene.addEllipse(citem->part->circle.basePoint.x-this->dot_size, citem->part->circle.basePoint.y-this->dot_size,
                                            2*this->dot_size,2*this->dot_size,QPen(this->dot_color),QBrush(this->dot_color));
                //part->ellipse = this->dxf.addCircle(*part->getCircle());
                QBrush brush_green(this->dot_color);
                citem->setBackground(1, brush_green);

            }
    }

}

// Alle Bauteile ein- oder ausschalten
void MainWindow::on_toggleButton_clicked(){
    this->toggle_parts();
}

void MainWindow::receive_new_project(QString project)
{
    if(project != ""){
        this->last_projects.insert(0,project);
        if(this->last_projects.count()>10)
            this->last_projects.removeLast();
    }
}

void MainWindow::loadSettings(){
    QSettings setting("kPlacer","MainWindowSettings");
    setting.beginGroup("MainWindow");
    this->last_projects= setting.value("recent_projects").value<QList<QString>>();
    QRect myRect = setting.value("position", QRect(100,100,800,600)).toRect();
    setGeometry(myRect);
    this->dot_color  = QColor(
                setting.value("dot_brush_red","0").toInt(),
                setting.value("dot_brush_green",255).toInt(),
                setting.value("dot_brush_blue",0).toInt()
                );
    this->dxf_filename = setting.value("dxf_path", "").toString();
    this->BillOfMaterialFile = setting.value("csv_path", "").toString();
    this->PickAndPlaceFile = setting.value("rpt_path", "").toString();
    this->lastFilePath = setting.value("last_file_path", QDir::currentPath()).toString();
    this->dot_size = setting.value("dot_size", 0.5).toDouble();
    this->ui->horizontalSlider->setValue((int)(this->dot_size * 100));

    setting.endGroup();

}

void MainWindow::saveSettings(){
    qRegisterMetaTypeStreamOperators<QList<QString>>("Stuff");
    QSettings setting("kPlacer","MainWindowSettings");
    setting.beginGroup("MainWindow");
    setting.setValue("recent_projects", QVariant::fromValue(this->last_projects));
    setting.setValue("position", this->geometry());
    setting.setValue("dot_brush_red",this->dot_color.red());
    setting.setValue("dot_brush_green",this->dot_color.green());
    setting.setValue("dot_brush_blue",this->dot_color.blue());
    setting.setValue("dxf_path", this->dxf_filename);
    setting.setValue("csv_path", this->BillOfMaterialFile);
    setting.setValue("rpt_path", this->PickAndPlaceFile);
    setting.setValue("last_file_path", this->lastFilePath);
    setting.setValue("dot_size", this->dot_size);

    setting.endGroup();
}

void MainWindow::add_dxf_file()
{
    this->dxf_filename = QFileDialog::getOpenFileName(this, "Open DXF", this->lastFilePath, "DXF Files (*.dxf)");
    if(dxf_filename.isEmpty())
    {
        return;
    }
    QFileInfo fi(this->dxf_filename);
    this->lastFilePath = fi.path();
    this->ui->statusBar->showMessage(this->dxf_filename);
    dxf.iniDXF(this->dxf_filename);
    this->ui->graphicsView->setScene(dxf.scene());
    this->ui->graphicsView->fitInView(dxf.scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
    this->ui->graphicsView->show();
    this->dxf_initialised = 1;
}

void MainWindow::open_BOM_file(bool KiCad)
{
    // Noch keine Szene initialisiert? Dann zurück
    if(this->dxf_initialised == 0){
        this->msgBox.setText("Erst mal 'ne DXF-Datei importieren, min Jung!");
        this->msgBox.exec();
        return;
    }
    this->BillOfMaterialFile = QFileDialog::getOpenFileName(this, "Open CSV", this->lastFilePath,KiCad?"csv Files (*.csv)" :"BOM Files (*.BOM)");
    if(this->BillOfMaterialFile.isEmpty())
    {
        return;
    }

    this->file_parser = CSV_Parser();
    int res = 0;
    res= KiCad ?
                this->file_parser.parse_csv_partlist(this->BillOfMaterialFile, &this->pcb_partkinds, true) :
                this->file_parser.parse_BOM_partlist(this->BillOfMaterialFile, &this->pcb_partkinds);
    if(!res){
        this->file_parser.partKindsToTreeView(this->pcb_partkinds, this->ui->treeWidget);
        this->file_parser.partKindstoTableView(this->pcb_partkinds, this->ui->tableWidget);
        this->csv_initialised = 1;
    }
    else{
        this->msgBox.setText("csv - Datei existiert nicht.");
        this->msgBox.exec();
    }
}

void MainWindow::open_pos_file(bool KiCAD)
{
    if(this->dxf_initialised == 0 || this->csv_initialised == 0){
        this->msgBox.setText("Erst mal 'ne DXF- und CSV-Datei importieren, min Jung!");
        this->msgBox.exec();
        return;
    }
    this->PickAndPlaceFile = QFileDialog::getOpenFileName(this, "Open RPT",  this->lastFilePath, KiCAD?"POS Files (*.pos)" :"RPT Files (*.rpt)");
    if(this->PickAndPlaceFile.isEmpty())
    {
        return;
    }
    this->file_parser = CSV_Parser();
    int res = 0;
    res= KiCAD ?
                this->file_parser.parse_pos_datei(this->PickAndPlaceFile, this->pcb_partkinds) :
                this->file_parser.parse_rpt_datei(this->PickAndPlaceFile, this->pcb_partkinds) ;
    this->ui->treeWidget->clear();
    if(!res){
        this->file_parser.partKindsToTreeView(this->pcb_partkinds, this->ui->treeWidget);
        this->file_parser.partKindstoTableView(this->pcb_partkinds, this->ui->tableWidget);
        this->rpt_initialised = 1;
    }
    else
    {
        this->msgBox.setText("rpt - Datei existiert nicht.");
        this->msgBox.exec();
    }
}

void MainWindow::open_franzisStueckliste()
{
    // Noch keine Szene initialisiert? Dann zurück
    if(this->dxf_initialised == 0){
        this->msgBox.setText("Erst mal 'ne DXF-Datei importieren, min Jung!");
        this->msgBox.exec();
        return;
    }
    this->BillOfMaterialFile = QFileDialog::getOpenFileName(this, "Open CSV",  this->lastFilePath, "CSV Files (*.csv)");
    if(this->BillOfMaterialFile.isEmpty())
    {
        return;
    }

    this->file_parser = CSV_Parser();
    int res = 0;
    res= this->file_parser.parse_csv_partlist(this->BillOfMaterialFile, &this->pcb_partkinds);

    if(!res){
        this->file_parser.partKindsToTreeView(this->pcb_partkinds, this->ui->treeWidget);
        this->file_parser.partKindstoTableView(this->pcb_partkinds, this->ui->tableWidget);
        this->csv_initialised = 1;
    }
    else{
        this->msgBox.setText("csv - Datei existiert nicht.");
        this->msgBox.exec();
    }
}

void MainWindow::reload_files()
{
    this->ui->treeWidget->clear();
    this->pcb_partkinds.clear();
   this->dxf.mScene.clear();
    if(this->dxf_filename == "" || this->BillOfMaterialFile == "" || this->PickAndPlaceFile == ""){
        this->msgBox.setText("Einer der letzten Dateipfade ist leer");
        this->msgBox.exec();
        return;
    }
    QFileInfo check_dxf(this->dxf_filename);
    if(!check_dxf.exists() || !check_dxf.isFile()){
        this->msgBox.setText("dxf - Datei existiert nicht.");
        this->msgBox.exec();
        return;
    }
    QFileInfo check_csv(this->BillOfMaterialFile);
    if(!check_csv.exists() || !check_csv.isFile()){
        this->msgBox.setText("csv - Datei existiert nicht.");
        this->msgBox.exec();
        return;
    }
    QFileInfo check_rpt(this->PickAndPlaceFile);
    if(!check_rpt.exists() || !check_rpt.isFile()){
        this->msgBox.setText("rpt - Datei existiert nicht.");
        this->msgBox.exec();
        return;
    }
    // dxf einlesen und anzeigen

    this->ui->statusBar->showMessage(this->dxf_filename);
    dxf.iniDXF(this->dxf_filename);
    this->ui->graphicsView->setScene(dxf.scene());
    this->ui->graphicsView->fitInView(dxf.scene()->itemsBoundingRect(), Qt::KeepAspectRatio);
    this->ui->graphicsView->show();
    this->dxf_initialised = 1;
    // csv Datei einlesen und anzeigen
    this->file_parser = CSV_Parser();
    int res= 0;
    //TODO: check project settings if kicad is checked
    res= true ?
                this->file_parser.parse_csv_partlist(this->BillOfMaterialFile, &this->pcb_partkinds, true) :
                this->file_parser.parse_BOM_partlist(this->BillOfMaterialFile, &this->pcb_partkinds);
    if(!res){
        this->file_parser.partKindsToTreeView(this->pcb_partkinds, this->ui->treeWidget);
        this->file_parser.partKindstoTableView(this->pcb_partkinds, this->ui->tableWidget);
        this->csv_initialised = 1;
    }
    // rpt Datei einlesen und zu den csv Daten matchen
    this->file_parser = CSV_Parser();
    //TODO: check project settings if kicad is checked
    res= true ?
                this->file_parser.parse_pos_datei(this->PickAndPlaceFile, this->pcb_partkinds) :
                this->file_parser.parse_rpt_datei(this->PickAndPlaceFile, this->pcb_partkinds) ;
    this->ui->treeWidget->clear();
    if(!res){
        this->file_parser.partKindsToTreeView(this->pcb_partkinds, this->ui->treeWidget);
        this->file_parser.partKindstoTableView(this->pcb_partkinds, this->ui->tableWidget);
        this->rpt_initialised = 1;
    }

}

void MainWindow::clear_files()
{
    this->ui->treeWidget->clear();
    this->ui->tableWidget->clear();
    this->pcb_partkinds.clear();
    this->dxf.mScene.clear();
}

void MainWindow::toggle_parts()
{
    int itemsCount = this->ui->treeWidget->topLevelItemCount();
    int visible = 0;
    // checken ob items aktiviert sind
    for(int i = 0; i < itemsCount; i++){
        QTreeWidgetItem *item = (QTreeWidgetItem *)this->ui->treeWidget->topLevelItem(i);
        for(int j = 0; j < item->childCount(); j++){
            CustomItem *citem = (CustomItem*)item->child(j);
            if(citem->part->get_visible()){
                visible = 1;
            }
        }
    }
    if(visible){
        for(int i = 0; i < itemsCount; i++){
            QTreeWidgetItem *item = (QTreeWidgetItem *)this->ui->treeWidget->topLevelItem(i);
            for(int j = 0; j < item->childCount(); j++){
                CustomItem *citem = (CustomItem*)item->child(j);
                citem->part->set_visible(0);
                if(citem->part->ellipse != nullptr)
                    this->dxf.mScene.removeItem(citem->part->ellipse);
                QBrush brush_white(Qt::white);
                citem->setBackground(1, brush_white);
            }
        }
    }
    else{
        for(int i = 0; i < itemsCount; i++){
            QTreeWidgetItem *item = (QTreeWidgetItem *)this->ui->treeWidget->topLevelItem(i);
            for(int j = 0; j < item->childCount(); j++){
                CustomItem *citem = (CustomItem*)item->child(j);
                citem->part->set_visible(1);
                citem->part->circle.colorName = "green";
                citem->part->ellipse = this->dxf.mScene.addEllipse(citem->part->circle.basePoint.x-this->dot_size, citem->part->circle.basePoint.y-this->dot_size,
                                            2*this->dot_size,2*this->dot_size,QPen(this->dot_color),QBrush(this->dot_color));
                QBrush brush_green(this->dot_color);
                citem->setBackground(1, brush_green);
            }
        }
    }

}

void MainWindow::on_reloadButton_clicked(){
    this->reload_files();
}

void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
   this->dot_size = ((double)position) / 100.0;
}

void MainWindow::on_rbOrCAD_toggled(bool checked)
{
    /*
    this->ui->rptButton->setText(checked ? "Open rpt-File" : "Open pos-File");
    this->ui->btnFranzisStueckliste->setVisible(checked);
    this->ui->csvButton->setText(checked ? "Open BOM-File" : "Open csv-File");
    */
}

void MainWindow::on_rbKiCAD_toggled(bool checked)
{

}

void MainWindow::on_clearButton_clicked()
{
    this->clear_files();
}
