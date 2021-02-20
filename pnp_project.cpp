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
    QSettings projectFile(file, QSettings::IniFormat);
    projectFile.beginGroup("Files");
    this->dxf_files= projectFile.value("dxf_files").value<QList<QString>>();
    projectFile.endGroup();

    foreach(QString s, this->dxf_files){
        qDebug() << s;
    }
}

void pnp_project::save_project(QString file)
{
    qRegisterMetaTypeStreamOperators<QList<QString>>("Stuff");

    QSettings projectFile(file, QSettings::IniFormat);
    projectFile.beginGroup("Files");
    projectFile.setValue("dxf_files", QVariant::fromValue(this->dxf_files));
    projectFile.setValue("bom_file", this->BillOfMaterialFile);
    projectFile.setValue("pos_file", this->PickAndPlaceFile);
    projectFile.setValue("dot_size", this->dot_size);
    projectFile.setValue("dot_brush_red",this->dot_color.red());
    projectFile.setValue("dot_brush_green",this->dot_color.green());
    projectFile.setValue("dot_brush_blue",this->dot_color.blue());

    projectFile.endGroup();



}
