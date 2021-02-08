/********************************************************************************
** Form generated from reading UI file 'pnp_options.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PNP_OPTIONS_H
#define UI_PNP_OPTIONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_pnp_options
{
public:
    QTableView *tableViewPNPOptions;

    void setupUi(QWidget *pnp_options)
    {
        if (pnp_options->objectName().isEmpty())
            pnp_options->setObjectName(QString::fromUtf8("pnp_options"));
        pnp_options->resize(640, 480);
        tableViewPNPOptions = new QTableView(pnp_options);
        tableViewPNPOptions->setObjectName(QString::fromUtf8("tableViewPNPOptions"));
        tableViewPNPOptions->setGeometry(QRect(0, 0, 641, 481));

        retranslateUi(pnp_options);

        QMetaObject::connectSlotsByName(pnp_options);
    } // setupUi

    void retranslateUi(QWidget *pnp_options)
    {
        pnp_options->setWindowTitle(QCoreApplication::translate("pnp_options", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pnp_options: public Ui_pnp_options {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PNP_OPTIONS_H
