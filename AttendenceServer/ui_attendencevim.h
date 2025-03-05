/********************************************************************************
** Form generated from reading UI file 'attendencevim.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTENDENCEVIM_H
#define UI_ATTENDENCEVIM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <registervim.h>
#include <selectvim.h>

QT_BEGIN_NAMESPACE

class Ui_AttendenceVim
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *showWidget;
    QLabel *picLb;
    RegisterVim *registerWidget;
    SelectVim *selectWidget;

    void setupUi(QMainWindow *AttendenceVim)
    {
        if (AttendenceVim->objectName().isEmpty())
            AttendenceVim->setObjectName(QString::fromUtf8("AttendenceVim"));
        AttendenceVim->resize(1000, 900);
        centralwidget = new QWidget(AttendenceVim);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(0, 20, 1000, 900));
        showWidget = new QWidget();
        showWidget->setObjectName(QString::fromUtf8("showWidget"));
        picLb = new QLabel(showWidget);
        picLb->setObjectName(QString::fromUtf8("picLb"));
        picLb->setGeometry(QRect(10, 10, 441, 581));
        picLb->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 138, 221);"));
        tabWidget->addTab(showWidget, QString());
        registerWidget = new RegisterVim();
        registerWidget->setObjectName(QString::fromUtf8("registerWidget"));
        tabWidget->addTab(registerWidget, QString());
        selectWidget = new SelectVim();
        selectWidget->setObjectName(QString::fromUtf8("selectWidget"));
        tabWidget->addTab(selectWidget, QString());
        AttendenceVim->setCentralWidget(centralwidget);

        retranslateUi(AttendenceVim);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AttendenceVim);
    } // setupUi

    void retranslateUi(QMainWindow *AttendenceVim)
    {
        AttendenceVim->setWindowTitle(QCoreApplication::translate("AttendenceVim", "AttendenceVim", nullptr));
        picLb->setText(QCoreApplication::translate("AttendenceVim", "\350\200\203\345\213\244\345\233\276\345\203\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(showWidget), QCoreApplication::translate("AttendenceVim", "\350\200\203\345\213\244\345\233\276\345\203\217", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(registerWidget), QCoreApplication::translate("AttendenceVim", "\346\263\250\345\206\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(selectWidget), QCoreApplication::translate("AttendenceVim", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AttendenceVim: public Ui_AttendenceVim {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTENDENCEVIM_H
