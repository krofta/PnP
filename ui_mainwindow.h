/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ColorPickerToolButton.h"
#include "src/dxfsceneview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionNew;
    QAction *actionAdd_dxf_file;
    QAction *actionKiCAD_BOM;
    QAction *actionOrCAD_BOM;
    QAction *actionKiCAD_position_file;
    QAction *actionOrCAD_position_file;
    QAction *actionReload_files;
    QAction *actionRemove_all;
    QAction *actionFranzis_BOM;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *toggleButton;
    ColorPickerToolButton *toolButton;
    QSlider *horizontalSlider;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QTabWidget *tabWidget;
    QWidget *tabComponents;
    QVBoxLayout *verticalLayout_9;
    QLabel *label;
    QTreeWidget *treeWidget;
    QWidget *tabComponentPara;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *tableWidget;
    DXFSceneView *graphicsView;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOpen_BOM_file;
    QMenu *menuOpen_pos_file;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1096, 669);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        actionAdd_dxf_file = new QAction(MainWindow);
        actionAdd_dxf_file->setObjectName(QString::fromUtf8("actionAdd_dxf_file"));
        actionKiCAD_BOM = new QAction(MainWindow);
        actionKiCAD_BOM->setObjectName(QString::fromUtf8("actionKiCAD_BOM"));
        actionOrCAD_BOM = new QAction(MainWindow);
        actionOrCAD_BOM->setObjectName(QString::fromUtf8("actionOrCAD_BOM"));
        actionKiCAD_position_file = new QAction(MainWindow);
        actionKiCAD_position_file->setObjectName(QString::fromUtf8("actionKiCAD_position_file"));
        actionOrCAD_position_file = new QAction(MainWindow);
        actionOrCAD_position_file->setObjectName(QString::fromUtf8("actionOrCAD_position_file"));
        actionReload_files = new QAction(MainWindow);
        actionReload_files->setObjectName(QString::fromUtf8("actionReload_files"));
        actionRemove_all = new QAction(MainWindow);
        actionRemove_all->setObjectName(QString::fromUtf8("actionRemove_all"));
        actionFranzis_BOM = new QAction(MainWindow);
        actionFranzis_BOM->setObjectName(QString::fromUtf8("actionFranzis_BOM"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toggleButton = new QPushButton(groupBox);
        toggleButton->setObjectName(QString::fromUtf8("toggleButton"));
        sizePolicy.setHeightForWidth(toggleButton->sizePolicy().hasHeightForWidth());
        toggleButton->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(toggleButton);

        toolButton = new ColorPickerToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/color_wheel.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        horizontalLayout_3->addWidget(toolButton);

        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(horizontalSlider);


        horizontalLayout->addWidget(groupBox);


        verticalLayout->addLayout(horizontalLayout);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        splitter = new QSplitter(centralWidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        tabWidget = new QTabWidget(splitter);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMaximumSize(QSize(10000, 10000));
        tabComponents = new QWidget();
        tabComponents->setObjectName(QString::fromUtf8("tabComponents"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabComponents->sizePolicy().hasHeightForWidth());
        tabComponents->setSizePolicy(sizePolicy2);
        verticalLayout_9 = new QVBoxLayout(tabComponents);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        label = new QLabel(tabComponents);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_9->addWidget(label);

        treeWidget = new QTreeWidget(tabComponents);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(1);
        sizePolicy3.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy3);

        verticalLayout_9->addWidget(treeWidget);

        tabWidget->addTab(tabComponents, QString());
        tabComponentPara = new QWidget();
        tabComponentPara->setObjectName(QString::fromUtf8("tabComponentPara"));
        verticalLayout_10 = new QVBoxLayout(tabComponentPara);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        tableWidget = new QTableWidget(tabComponentPara);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout_10->addWidget(tableWidget);

        tabWidget->addTab(tabComponentPara, QString());
        splitter->addWidget(tabWidget);
        graphicsView = new DXFSceneView(splitter);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        sizePolicy1.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy1);
        splitter->addWidget(graphicsView);

        gridLayout->addWidget(splitter, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1096, 20));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOpen_BOM_file = new QMenu(menuFile);
        menuOpen_BOM_file->setObjectName(QString::fromUtf8("menuOpen_BOM_file"));
        menuOpen_pos_file = new QMenu(menuFile);
        menuOpen_pos_file->setObjectName(QString::fromUtf8("menuOpen_pos_file"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addSeparator();
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionNew);
        menuFile->addAction(actionAdd_dxf_file);
        menuFile->addAction(menuOpen_BOM_file->menuAction());
        menuFile->addAction(menuOpen_pos_file->menuAction());
        menuFile->addAction(actionReload_files);
        menuFile->addAction(actionRemove_all);
        menuOpen_BOM_file->addAction(actionKiCAD_BOM);
        menuOpen_BOM_file->addAction(actionOrCAD_BOM);
        menuOpen_BOM_file->addAction(actionFranzis_BOM);
        menuOpen_pos_file->addAction(actionKiCAD_position_file);
        menuOpen_pos_file->addAction(actionOrCAD_position_file);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "K\303\244fer Futter f\303\274r die H\303\274hners", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open project", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "New project", nullptr));
        actionAdd_dxf_file->setText(QCoreApplication::translate("MainWindow", "Add dxf file", nullptr));
        actionKiCAD_BOM->setText(QCoreApplication::translate("MainWindow", "KiCAD BOM", nullptr));
        actionOrCAD_BOM->setText(QCoreApplication::translate("MainWindow", "OrCAD BOM", nullptr));
        actionKiCAD_position_file->setText(QCoreApplication::translate("MainWindow", "KiCAD position file", nullptr));
        actionOrCAD_position_file->setText(QCoreApplication::translate("MainWindow", "OrCAD position file", nullptr));
        actionReload_files->setText(QCoreApplication::translate("MainWindow", "Reload files", nullptr));
        actionRemove_all->setText(QCoreApplication::translate("MainWindow", "Remove all", nullptr));
        actionFranzis_BOM->setText(QCoreApplication::translate("MainWindow", "Franzis BOM", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "P\303\274nktchen", nullptr));
        toggleButton->setText(QCoreApplication::translate("MainWindow", "Toggle alle", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabComponents), QCoreApplication::translate("MainWindow", "Components", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabComponentPara), QCoreApplication::translate("MainWindow", "Process Parameter", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
        menuOpen_BOM_file->setTitle(QCoreApplication::translate("MainWindow", "Open BOM file", nullptr));
        menuOpen_pos_file->setTitle(QCoreApplication::translate("MainWindow", "Open pos file", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
