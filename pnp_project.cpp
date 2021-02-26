#include "pnp_project.h"

#include <QFileDialog>
#include <QDebug>

pnp_project::pnp_project(QObject *parent) :
    QObject(parent)
{

}

void pnp_project::new_project()
{
    qDebug() << Q_FUNC_INFO;
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setLabelText(QFileDialog::Accept, "Save");
    dialog.setLabelText(QFileDialog::Reject, "NOOOOPE");
    this->project_file = dialog.getSaveFileName(NULL, "Create New Project File","","");
    qDebug()<<this->project_file;
    if(this->project_file.isEmpty())
    {
        return;
    }
    QFile file(this->project_file);
    file.open(QIODevice::WriteOnly);
    file.close();

    this->save_project(this->project_file);
    emit send_new_project(this->project_file);
}

void pnp_project::load_project(QString file)
{
    qRegisterMetaTypeStreamOperators<QList<QString>>("Stuff");
    qRegisterMetaTypeStreamOperators<CAD_TYPE>("CAD_TYPE");
    qRegisterMetaTypeStreamOperators<GRAPIC_TYPE>("GRAPIC_TYPE");

    QSettings projectFile(file, QSettings::IniFormat);
    projectFile.beginGroup("Files");
    this->dxf_files= projectFile.value("dxf_files").value<QList<QString>>();
    this->svg_file = projectFile.value("svg_file", "").toString();
    this->graphic_type = projectFile.value("graphic_type", GRAPIC_TYPE::GRAPIC_TYPE_UNDEF).value<GRAPIC_TYPE>();
    this->BillOfMaterialFile = projectFile.value("bom_file", "").toString();
    this->bom_type = projectFile.value("bom_type", CAD_TYPE::CAD_TYPE_UNDEF).value<CAD_TYPE>();
    this->PickAndPlaceFile = projectFile.value("pos_file", "").toString();
    this->pos_type = projectFile.value("pos_type", CAD_TYPE::CAD_TYPE_UNDEF).value<CAD_TYPE>();
    this->dot_size = projectFile.value("dot_size", 0.5).toDouble();
    this->dot_color  = QColor(
                projectFile.value("dot_brush_red","0").toInt(),
                projectFile.value("dot_brush_green",255).toInt(),
                projectFile.value("dot_brush_blue",0).toInt()
                );
    projectFile.endGroup();

    foreach(QString s, this->dxf_files){
        qDebug() << s;
    }
}

void pnp_project::save_project(QString file)
{
    qRegisterMetaTypeStreamOperators<QList<QString>>("Stuff");
    qRegisterMetaTypeStreamOperators<CAD_TYPE>("CAD_TYPE");
    qRegisterMetaTypeStreamOperators<GRAPIC_TYPE>("GRAPIC_TYPE");

    QSettings projectFile(file, QSettings::IniFormat);
    projectFile.beginGroup("Files");

    projectFile.setValue("dxf_files", QVariant::fromValue(this->dxf_files));
    projectFile.setValue("svg_file", this->svg_file);
    projectFile.setValue("graphic_type", this->graphic_type);
    projectFile.setValue("bom_file", this->BillOfMaterialFile);
    projectFile.setValue("bom_type", this->bom_type);
    projectFile.setValue("pos_file", this->PickAndPlaceFile);
    projectFile.setValue("pos_type", this->pos_type);
    projectFile.setValue("dot_size", this->dot_size);
    projectFile.setValue("dot_brush_red",this->dot_color.red());
    projectFile.setValue("dot_brush_green",this->dot_color.green());
    projectFile.setValue("dot_brush_blue",this->dot_color.blue());

    projectFile.endGroup();

}
