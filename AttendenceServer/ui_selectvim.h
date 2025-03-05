/********************************************************************************
** Form generated from reading UI file 'selectvim.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTVIM_H
#define UI_SELECTVIM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SelectVim
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QRadioButton *empRb;
    QRadioButton *attRb;
    QPushButton *selectBt;
    QTableView *tableView;

    void setupUi(QWidget *SelectVim)
    {
        if (SelectVim->objectName().isEmpty())
            SelectVim->setObjectName(QString::fromUtf8("SelectVim"));
        SelectVim->resize(1000, 900);
        layoutWidget = new QWidget(SelectVim);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 80, 931, 631));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        empRb = new QRadioButton(layoutWidget);
        empRb->setObjectName(QString::fromUtf8("empRb"));

        horizontalLayout->addWidget(empRb);

        attRb = new QRadioButton(layoutWidget);
        attRb->setObjectName(QString::fromUtf8("attRb"));

        horizontalLayout->addWidget(attRb);

        selectBt = new QPushButton(layoutWidget);
        selectBt->setObjectName(QString::fromUtf8("selectBt"));

        horizontalLayout->addWidget(selectBt);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(layoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);


        retranslateUi(SelectVim);

        QMetaObject::connectSlotsByName(SelectVim);
    } // setupUi

    void retranslateUi(QWidget *SelectVim)
    {
        SelectVim->setWindowTitle(QCoreApplication::translate("SelectVim", "Form", nullptr));
        empRb->setText(QCoreApplication::translate("SelectVim", "\345\221\230\345\267\245", nullptr));
        attRb->setText(QCoreApplication::translate("SelectVim", "\350\200\203\345\213\244", nullptr));
        selectBt->setText(QCoreApplication::translate("SelectVim", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectVim: public Ui_SelectVim {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTVIM_H
