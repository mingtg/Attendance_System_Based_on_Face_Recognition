/********************************************************************************
** Form generated from reading UI file 'registervim.ui'
**
** Created by: Qt User Interface Compiler version 5.15.13
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERVIM_H
#define UI_REGISTERVIM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_RegisterVim
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_8;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QRadioButton *mrb;
    QRadioButton *wrb;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDateEdit *birthdayEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *addressEdit;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_5;
    QLineEdit *phoneEdit;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *registerBt;
    QPushButton *resetBt;
    QVBoxLayout *verticalLayout_2;
    QLabel *headpicLb;
    QLineEdit *picFileEdit;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *addpicBt;
    QPushButton *videoswitchBt;
    QPushButton *cameraBt;

    void setupUi(QWidget *RegisterVim)
    {
        if (RegisterVim->objectName().isEmpty())
            RegisterVim->setObjectName(QString::fromUtf8("RegisterVim"));
        RegisterVim->resize(923, 626);
        layoutWidget = new QWidget(RegisterVim);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(11, 20, 901, 591));
        horizontalLayout_8 = new QHBoxLayout(layoutWidget);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(15);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        nameEdit = new QLineEdit(layoutWidget);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy);
        nameEdit->setFont(font);

        horizontalLayout->addWidget(nameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_2->addWidget(label_2);

        mrb = new QRadioButton(layoutWidget);
        mrb->setObjectName(QString::fromUtf8("mrb"));
        mrb->setFont(font);

        horizontalLayout_2->addWidget(mrb);

        wrb = new QRadioButton(layoutWidget);
        wrb->setObjectName(QString::fromUtf8("wrb"));
        wrb->setFont(font);

        horizontalLayout_2->addWidget(wrb);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        birthdayEdit = new QDateEdit(layoutWidget);
        birthdayEdit->setObjectName(QString::fromUtf8("birthdayEdit"));
        sizePolicy.setHeightForWidth(birthdayEdit->sizePolicy().hasHeightForWidth());
        birthdayEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(birthdayEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        horizontalLayout_4->addWidget(label_4);

        addressEdit = new QLineEdit(layoutWidget);
        addressEdit->setObjectName(QString::fromUtf8("addressEdit"));
        sizePolicy.setHeightForWidth(addressEdit->sizePolicy().hasHeightForWidth());
        addressEdit->setSizePolicy(sizePolicy);
        addressEdit->setFont(font);

        horizontalLayout_4->addWidget(addressEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        horizontalLayout_5->addWidget(label_5);

        phoneEdit = new QLineEdit(layoutWidget);
        phoneEdit->setObjectName(QString::fromUtf8("phoneEdit"));
        sizePolicy.setHeightForWidth(phoneEdit->sizePolicy().hasHeightForWidth());
        phoneEdit->setSizePolicy(sizePolicy);
        phoneEdit->setFont(font);

        horizontalLayout_5->addWidget(phoneEdit);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        registerBt = new QPushButton(layoutWidget);
        registerBt->setObjectName(QString::fromUtf8("registerBt"));
        registerBt->setFont(font);

        horizontalLayout_6->addWidget(registerBt);

        resetBt = new QPushButton(layoutWidget);
        resetBt->setObjectName(QString::fromUtf8("resetBt"));
        resetBt->setFont(font);

        horizontalLayout_6->addWidget(resetBt);


        verticalLayout->addLayout(horizontalLayout_6);


        horizontalLayout_8->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        headpicLb = new QLabel(layoutWidget);
        headpicLb->setObjectName(QString::fromUtf8("headpicLb"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(headpicLb->sizePolicy().hasHeightForWidth());
        headpicLb->setSizePolicy(sizePolicy1);
        headpicLb->setStyleSheet(QString::fromUtf8("background-color: rgb(220, 138, 221);"));

        verticalLayout_2->addWidget(headpicLb);

        picFileEdit = new QLineEdit(layoutWidget);
        picFileEdit->setObjectName(QString::fromUtf8("picFileEdit"));

        verticalLayout_2->addWidget(picFileEdit);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        addpicBt = new QPushButton(layoutWidget);
        addpicBt->setObjectName(QString::fromUtf8("addpicBt"));
        addpicBt->setFont(font);

        horizontalLayout_7->addWidget(addpicBt);

        videoswitchBt = new QPushButton(layoutWidget);
        videoswitchBt->setObjectName(QString::fromUtf8("videoswitchBt"));
        videoswitchBt->setFont(font);

        horizontalLayout_7->addWidget(videoswitchBt);

        cameraBt = new QPushButton(layoutWidget);
        cameraBt->setObjectName(QString::fromUtf8("cameraBt"));
        cameraBt->setFont(font);

        horizontalLayout_7->addWidget(cameraBt);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);

        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout_2->setStretch(0, 3);

        horizontalLayout_8->addLayout(verticalLayout_2);


        retranslateUi(RegisterVim);

        QMetaObject::connectSlotsByName(RegisterVim);
    } // setupUi

    void retranslateUi(QWidget *RegisterVim)
    {
        RegisterVim->setWindowTitle(QCoreApplication::translate("RegisterVim", "Form", nullptr));
        label->setText(QCoreApplication::translate("RegisterVim", "\345\247\223\345\220\215\357\274\232", nullptr));
        label_2->setText(QCoreApplication::translate("RegisterVim", "\346\200\247\345\210\253\357\274\232", nullptr));
        mrb->setText(QCoreApplication::translate("RegisterVim", "\347\224\267", nullptr));
        wrb->setText(QCoreApplication::translate("RegisterVim", "\345\245\263", nullptr));
        label_3->setText(QCoreApplication::translate("RegisterVim", "\347\224\237\346\227\245\357\274\232", nullptr));
        label_4->setText(QCoreApplication::translate("RegisterVim", "\345\234\260\345\235\200\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("RegisterVim", "\347\224\265\350\257\235\357\274\232", nullptr));
        registerBt->setText(QCoreApplication::translate("RegisterVim", "\346\263\250\345\206\214", nullptr));
        resetBt->setText(QCoreApplication::translate("RegisterVim", "\351\207\215\347\275\256", nullptr));
        headpicLb->setText(QString());
        addpicBt->setText(QCoreApplication::translate("RegisterVim", "\346\267\273\345\212\240\345\244\264\345\203\217", nullptr));
        videoswitchBt->setText(QCoreApplication::translate("RegisterVim", "\346\211\223\345\274\200\346\221\204\345\203\217\345\244\264", nullptr));
        cameraBt->setText(QCoreApplication::translate("RegisterVim", "\346\213\215\347\205\247", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterVim: public Ui_RegisterVim {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERVIM_H
