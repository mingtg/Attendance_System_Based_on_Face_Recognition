/********************************************************************************
** Form generated from reading UI file 'faceattendence.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FACEATTENDENCE_H
#define UI_FACEATTENDENCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FaceAttendence
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QLabel *head;
    QWidget *widgetLb;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QTextBrowser *textBrowser;
    QSpacerItem *horizontalSpacer_2;
    QLabel *videoLb;
    QWidget *widget_3;
    QLabel *titlelb;
    QLabel *headLb;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *numberEdit;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *nameEdit;
    QWidget *widget_6;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_7;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *departmentEdit;
    QWidget *widget_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *timeEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *FaceAttendence)
    {
        if (FaceAttendence->objectName().isEmpty())
            FaceAttendence->setObjectName(QString::fromUtf8("FaceAttendence"));
        FaceAttendence->resize(800, 555);
        centralwidget = new QWidget(FaceAttendence);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 0, 480, 480));
        widget->setStyleSheet(QString::fromUtf8(""));
        head = new QLabel(widget);
        head->setObjectName(QString::fromUtf8("head"));
        head->setGeometry(QRect(100, 60, 266, 266));
        head->setMinimumSize(QSize(266, 266));
        head->setMaximumSize(QSize(266, 266));
        head->setStyleSheet(QString::fromUtf8("border-image: url(:/crc.png);"));
        widgetLb = new QWidget(widget);
        widgetLb->setObjectName(QString::fromUtf8("widgetLb"));
        widgetLb->setEnabled(false);
        widgetLb->setGeometry(QRect(90, 380, 260, 50));
        widgetLb->setMinimumSize(QSize(260, 50));
        widgetLb->setMaximumSize(QSize(260, 50));
        widgetLb->setStyleSheet(QString::fromUtf8("background-color: rgba(49, 50, 54, 69);\n"
"border-radius:10px;"));
        horizontalLayout = new QHBoxLayout(widgetLb);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(widgetLb);
        label->setObjectName(QString::fromUtf8("label"));
        label->setEnabled(false);
        label->setMinimumSize(QSize(31, 21));
        label->setMaximumSize(QSize(31, 21));
        label->setStyleSheet(QString::fromUtf8("border-image: url(:/yes.png);"));

        horizontalLayout->addWidget(label);

        textBrowser = new QTextBrowser(widgetLb);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        textBrowser->setMinimumSize(QSize(0, 50));
        textBrowser->setMaximumSize(QSize(120, 50));
        textBrowser->setStyleSheet(QString::fromUtf8("font:25 24pt \"Ubuntu Sans\";\n"
"border:none;\n"
"color: rgb(255, 255, 255);\n"
"background-color: rgba(49, 50, 54, 0);"));

        horizontalLayout->addWidget(textBrowser);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        videoLb = new QLabel(widget);
        videoLb->setObjectName(QString::fromUtf8("videoLb"));
        videoLb->setGeometry(QRect(0, 0, 480, 480));
        videoLb->raise();
        head->raise();
        widgetLb->raise();
        widget_3 = new QWidget(centralwidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        widget_3->setGeometry(QRect(479, 0, 321, 480));
        widget_3->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	background-color: rgba(37, 40, 49, 0.9);\n"
"}\n"
"QWidget#titlelb{\n"
"	\n"
"	font: 80 16pt \"Ubuntu Sans\";\n"
"	color: rgb(255, 255, 255);\n"
"}\n"
"QWidget#heablb{\n"
"	border-radius:75px;\n"
"}"));
        titlelb = new QLabel(widget_3);
        titlelb->setObjectName(QString::fromUtf8("titlelb"));
        titlelb->setGeometry(QRect(0, 0, 320, 51));
        titlelb->setAlignment(Qt::AlignCenter);
        headLb = new QLabel(widget_3);
        headLb->setObjectName(QString::fromUtf8("headLb"));
        headLb->setGeometry(QRect(90, 60, 150, 150));
        headLb->setStyleSheet(QString::fromUtf8(""));
        layoutWidget = new QWidget(widget_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 210, 321, 271));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        widget_4 = new QWidget(layoutWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        widget_4->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	background-color: rgba(37, 40, 49, 0.9);\n"
"}\n"
"QLabel{\n"
"	border:none;\n"
"	color:rgb(255,255,255);\n"
"	font: 16pt \"Ubuntu Sans\";\n"
"}\n"
"QLineEdit{\n"
"	border:none;\n"
"	color:rgb(255,255,255);\n"
"	font: 16pt \"Ubuntu Sans\";\n"
"}"));
        horizontalLayout_2 = new QHBoxLayout(widget_4);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_5 = new QLabel(widget_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        numberEdit = new QLineEdit(widget_4);
        numberEdit->setObjectName(QString::fromUtf8("numberEdit"));
        numberEdit->setEnabled(false);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(numberEdit->sizePolicy().hasHeightForWidth());
        numberEdit->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(numberEdit);


        verticalLayout->addWidget(widget_4);

        widget_5 = new QWidget(layoutWidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        widget_5->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	background-color: rgba(37, 40, 49, 0.9);\n"
"}\n"
"QLabel{\n"
"	border:none;\n"
"	color:rgb(255,255,255);\n"
"	font: 16pt \"Ubuntu Sans\";\n"
"}\n"
"QLineEdit{\n"
"	border:none;\n"
"	color:rgb(255,255,255);\n"
"	font: 16pt \"Ubuntu Sans\";\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget_5);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_6 = new QLabel(widget_5);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        nameEdit = new QLineEdit(widget_5);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(nameEdit->sizePolicy().hasHeightForWidth());
        nameEdit->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(nameEdit);


        verticalLayout->addWidget(widget_5);

        widget_6 = new QWidget(layoutWidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        widget_6->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	background-color: rgba(37, 40, 49, 0.9);\n"
"}\n"
"QLabel{\n"
"	border:none;\n"
"	color:rgb(255,255,255);\n"
"	font: 16pt \"Ubuntu Sans\";\n"
"}\n"
"QLineEdit{\n"
"	border:none;\n"
"	color:rgb(255,255,255);\n"
"	font: 16pt \"Ubuntu Sans\";\n"
"}"));
        horizontalLayout_4 = new QHBoxLayout(widget_6);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(widget_6);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        horizontalLayout_4->addWidget(label_7);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        departmentEdit = new QLineEdit(widget_6);
        departmentEdit->setObjectName(QString::fromUtf8("departmentEdit"));
        departmentEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(departmentEdit->sizePolicy().hasHeightForWidth());
        departmentEdit->setSizePolicy(sizePolicy);

        horizontalLayout_4->addWidget(departmentEdit);


        verticalLayout->addWidget(widget_6);

        widget_7 = new QWidget(layoutWidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        widget_7->setStyleSheet(QString::fromUtf8("QWidget{\n"
"	border:1px solid #313236;\n"
"	border-radius:4px;\n"
"	background-color: rgba(37, 40, 49, 0.9);\n"
"}\n"
"QLabel{\n"
"	border:none;\n"
"	color:rgb(255,255,255);\n"
"	font: 16pt \"Ubuntu Sans\";\n"
"}\n"
"QLineEdit{\n"
"	border:none;\n"
"	color:rgb(255,255,255);\n"
"	font: 16pt \"Ubuntu Sans\";\n"
"}"));
        horizontalLayout_5 = new QHBoxLayout(widget_7);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(widget_7);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        timeEdit = new QLineEdit(widget_7);
        timeEdit->setObjectName(QString::fromUtf8("timeEdit"));
        timeEdit->setEnabled(false);
        sizePolicy.setHeightForWidth(timeEdit->sizePolicy().hasHeightForWidth());
        timeEdit->setSizePolicy(sizePolicy);

        horizontalLayout_5->addWidget(timeEdit);


        verticalLayout->addWidget(widget_7);

        FaceAttendence->setCentralWidget(centralwidget);
        menubar = new QMenuBar(FaceAttendence);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 38));
        FaceAttendence->setMenuBar(menubar);
        statusbar = new QStatusBar(FaceAttendence);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        FaceAttendence->setStatusBar(statusbar);

        retranslateUi(FaceAttendence);

        QMetaObject::connectSlotsByName(FaceAttendence);
    } // setupUi

    void retranslateUi(QMainWindow *FaceAttendence)
    {
        FaceAttendence->setWindowTitle(QCoreApplication::translate("FaceAttendence", "FaceAttendence", nullptr));
        head->setText(QString());
        label->setText(QString());
        textBrowser->setHtml(QCoreApplication::translate("FaceAttendence", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu Sans'; font-size:24pt; font-weight:24; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:400;\">\350\256\244\350\257\201\346\210\220\345\212\237</span></p></body></html>", nullptr));
        videoLb->setText(QString());
        titlelb->setText(QCoreApplication::translate("FaceAttendence", "\344\272\272\350\204\270\350\257\206\345\210\253\350\200\203\345\213\244\347\263\273\347\273\237", nullptr));
        headLb->setText(QCoreApplication::translate("FaceAttendence", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("FaceAttendence", "\345\267\245\345\217\267", nullptr));
        numberEdit->setText(QCoreApplication::translate("FaceAttendence", "001", nullptr));
        label_6->setText(QCoreApplication::translate("FaceAttendence", "\345\247\223\345\220\215", nullptr));
        nameEdit->setText(QCoreApplication::translate("FaceAttendence", "001", nullptr));
        label_7->setText(QCoreApplication::translate("FaceAttendence", "\351\203\250\351\227\250", nullptr));
        departmentEdit->setText(QCoreApplication::translate("FaceAttendence", "001", nullptr));
        label_8->setText(QCoreApplication::translate("FaceAttendence", "\346\227\266\351\227\264", nullptr));
        timeEdit->setText(QCoreApplication::translate("FaceAttendence", "001", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FaceAttendence: public Ui_FaceAttendence {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FACEATTENDENCE_H
