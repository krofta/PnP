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
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "ColorPickerToolButton.h"
#include "src/dxfsceneview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBox_5;
    QToolButton *dxfButton;
    QGroupBox *groupBox_3;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QRadioButton *rbOrCAD;
    QRadioButton *rbKiCAD;
    QGroupBox *groupBox_4;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QToolButton *csvButton;
    QPushButton *btnFranzisStueckliste;
    QGroupBox *groupBox_2;
    QWidget *verticalLayoutWidget_4;
    QVBoxLayout *verticalLayout_3;
    QToolButton *rptButton;
    QVBoxLayout *verticalLayout_6;
    QPushButton *clearButton;
    QPushButton *reloadButton;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QSlider *horizontalSlider;
    ColorPickerToolButton *toolButton;
    QPushButton *toggleButton;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1096, 669);
        MainWindow->setContextMenuPolicy(Qt::NoContextMenu);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        dxfButton = new QToolButton(groupBox_5);
        dxfButton->setObjectName(QString::fromUtf8("dxfButton"));
        dxfButton->setGeometry(QRect(0, 30, 86, 22));
        dxfButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_7->addWidget(groupBox_5);


        horizontalLayout_2->addLayout(verticalLayout_7);

        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayoutWidget_2 = new QWidget(groupBox_3);
        verticalLayoutWidget_2->setObjectName(QString::fromUtf8("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 20, 160, 80));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        rbOrCAD = new QRadioButton(verticalLayoutWidget_2);
        rbOrCAD->setObjectName(QString::fromUtf8("rbOrCAD"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(rbOrCAD->sizePolicy().hasHeightForWidth());
        rbOrCAD->setSizePolicy(sizePolicy);
        rbOrCAD->setChecked(true);

        verticalLayout_5->addWidget(rbOrCAD);

        rbKiCAD = new QRadioButton(verticalLayoutWidget_2);
        rbKiCAD->setObjectName(QString::fromUtf8("rbKiCAD"));
        sizePolicy.setHeightForWidth(rbKiCAD->sizePolicy().hasHeightForWidth());
        rbKiCAD->setSizePolicy(sizePolicy);

        verticalLayout_5->addWidget(rbKiCAD);


        horizontalLayout_2->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayoutWidget_3 = new QWidget(groupBox_4);
        verticalLayoutWidget_3->setObjectName(QString::fromUtf8("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 20, 160, 80));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        csvButton = new QToolButton(verticalLayoutWidget_3);
        csvButton->setObjectName(QString::fromUtf8("csvButton"));
        csvButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_2->addWidget(csvButton);

        btnFranzisStueckliste = new QPushButton(verticalLayoutWidget_3);
        btnFranzisStueckliste->setObjectName(QString::fromUtf8("btnFranzisStueckliste"));
        sizePolicy.setHeightForWidth(btnFranzisStueckliste->sizePolicy().hasHeightForWidth());
        btnFranzisStueckliste->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnFranzisStueckliste);


        horizontalLayout_2->addWidget(groupBox_4);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayoutWidget_4 = new QWidget(groupBox_2);
        verticalLayoutWidget_4->setObjectName(QString::fromUtf8("verticalLayoutWidget_4"));
        verticalLayoutWidget_4->setGeometry(QRect(0, 20, 160, 80));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_4);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        rptButton = new QToolButton(verticalLayoutWidget_4);
        rptButton->setObjectName(QString::fromUtf8("rptButton"));
        rptButton->setFocusPolicy(Qt::NoFocus);

        verticalLayout_3->addWidget(rptButton);


        horizontalLayout_2->addWidget(groupBox_2);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        sizePolicy.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(clearButton);

        reloadButton = new QPushButton(centralWidget);
        reloadButton->setObjectName(QString::fromUtf8("reloadButton"));
        sizePolicy.setHeightForWidth(reloadButton->sizePolicy().hasHeightForWidth());
        reloadButton->setSizePolicy(sizePolicy);

        verticalLayout_6->addWidget(reloadButton);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalSlider = new QSlider(groupBox);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        sizePolicy.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_8->addWidget(horizontalSlider);

        toolButton = new ColorPickerToolButton(groupBox);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/color_wheel.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon);

        verticalLayout_8->addWidget(toolButton);

        toggleButton = new QPushButton(groupBox);
        toggleButton->setObjectName(QString::fromUtf8("toggleButton"));
        sizePolicy.setHeightForWidth(toggleButton->sizePolicy().hasHeightForWidth());
        toggleButton->setSizePolicy(sizePolicy);

        verticalLayout_8->addWidget(toggleButton);


        verticalLayout_4->addWidget(groupBox);


        horizontalLayout_2->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horizontalLayout_2);

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
        tabWidget->setMaximumSize(QSize(1000, 1000));
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

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "K\303\244fer Futter f\303\274r die H\303\274hners", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("MainWindow", "Graphics", nullptr));
        dxfButton->setText(QCoreApplication::translate("MainWindow", "Add dxf-File", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "CAD Format", nullptr));
        rbOrCAD->setText(QCoreApplication::translate("MainWindow", "OrCAD", nullptr));
        rbKiCAD->setText(QCoreApplication::translate("MainWindow", "KiCAD", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "Bill of Material", nullptr));
        csvButton->setText(QCoreApplication::translate("MainWindow", "Open BOM-File", nullptr));
        btnFranzisStueckliste->setText(QCoreApplication::translate("MainWindow", "Franzis St\303\274ckliste", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "Position of Parts", nullptr));
        rptButton->setText(QCoreApplication::translate("MainWindow", "Open rpt-File", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "Clear all", nullptr));
        reloadButton->setText(QCoreApplication::translate("MainWindow", "Reload Files", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "P\303\274nktchen", nullptr));
        toolButton->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        toggleButton->setText(QCoreApplication::translate("MainWindow", "Toggle alle", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabComponents), QCoreApplication::translate("MainWindow", "Components", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabComponentPara), QCoreApplication::translate("MainWindow", "Process Parameter", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
