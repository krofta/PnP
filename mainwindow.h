#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "src/dxfinterface.h"
#include "libdxfrw/src/libdxfrw.h"
#include <src/dxfsceneview.h>

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
    QString filename;
    DXFInterface dxf;

private slots:
    void on_dxfButton_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
