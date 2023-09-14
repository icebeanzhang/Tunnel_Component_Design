/********************************************************************************
** Form generated from reading UI file 'CenterGroove.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CENTERGROOVE_H
#define UI_CENTERGROOVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CenterGroove
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn2_1_1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn2_1_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *P1_O1_Ydistance;
    QLabel *label_2;
    QTextEdit *centercover_Xlength;
    QLabel *label_6;
    QTextEdit *centercover_Ylength;
    QLabel *label_8;
    QTextEdit *centergroove_Xlength;
    QLabel *label_9;
    QTextEdit *centergroove_Ylength;
    QLabel *label_3;
    QTextEdit *centerconcrete_Xlength;
    QLabel *label_7;
    QTextEdit *centerconcrete_Ylength;
    QLabel *label_4;

    void setupUi(QWidget *CenterGroove)
    {
        if (CenterGroove->objectName().isEmpty())
            CenterGroove->setObjectName(QString::fromUtf8("CenterGroove"));
        CenterGroove->resize(922, 413);
        horizontalLayoutWidget = new QWidget(CenterGroove);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 340, 921, 61));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn2_1_1 = new QPushButton(horizontalLayoutWidget);
        btn2_1_1->setObjectName(QString::fromUtf8("btn2_1_1"));

        horizontalLayout->addWidget(btn2_1_1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn2_1_2 = new QPushButton(horizontalLayoutWidget);
        btn2_1_2->setObjectName(QString::fromUtf8("btn2_1_2"));

        horizontalLayout->addWidget(btn2_1_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(CenterGroove);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 381, 321));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(216, 0));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        P1_O1_Ydistance = new QTextEdit(widget);
        P1_O1_Ydistance->setObjectName(QString::fromUtf8("P1_O1_Ydistance"));
        P1_O1_Ydistance->setMaximumSize(QSize(229, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, P1_O1_Ydistance);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        centercover_Xlength = new QTextEdit(widget);
        centercover_Xlength->setObjectName(QString::fromUtf8("centercover_Xlength"));

        formLayout->setWidget(1, QFormLayout::FieldRole, centercover_Xlength);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        centercover_Ylength = new QTextEdit(widget);
        centercover_Ylength->setObjectName(QString::fromUtf8("centercover_Ylength"));

        formLayout->setWidget(2, QFormLayout::FieldRole, centercover_Ylength);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        centergroove_Xlength = new QTextEdit(widget);
        centergroove_Xlength->setObjectName(QString::fromUtf8("centergroove_Xlength"));

        formLayout->setWidget(4, QFormLayout::FieldRole, centergroove_Xlength);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_9);

        centergroove_Ylength = new QTextEdit(widget);
        centergroove_Ylength->setObjectName(QString::fromUtf8("centergroove_Ylength"));

        formLayout->setWidget(5, QFormLayout::FieldRole, centergroove_Ylength);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_3);

        centerconcrete_Xlength = new QTextEdit(widget);
        centerconcrete_Xlength->setObjectName(QString::fromUtf8("centerconcrete_Xlength"));

        formLayout->setWidget(8, QFormLayout::FieldRole, centerconcrete_Xlength);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_7);

        centerconcrete_Ylength = new QTextEdit(widget);
        centerconcrete_Ylength->setObjectName(QString::fromUtf8("centerconcrete_Ylength"));

        formLayout->setWidget(10, QFormLayout::FieldRole, centerconcrete_Ylength);

        label_4 = new QLabel(CenterGroove);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(420, 30, 451, 281));
        label_4->setStyleSheet(QString::fromUtf8("border-image: url(:/CenterGroove.png);"));

        retranslateUi(CenterGroove);

        QMetaObject::connectSlotsByName(CenterGroove);
    } // setupUi

    void retranslateUi(QWidget *CenterGroove)
    {
        CenterGroove->setWindowTitle(QCoreApplication::translate("CenterGroove", "\344\270\255\345\277\203\346\262\237\345\217\202\346\225\260", nullptr));
        btn2_1_1->setText(QCoreApplication::translate("CenterGroove", "\347\241\256\350\256\244", nullptr));
        btn2_1_2->setText(QCoreApplication::translate("CenterGroove", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("CenterGroove", "\345\206\205\350\275\256\345\273\223\344\270\255\345\277\203\347\202\271\345\222\214\344\270\255\345\277\203\347\233\226\346\235\277\351\225\277\350\276\271\350\267\235\347\246\273\357\274\210cm\357\274\211", nullptr));
        P1_O1_Ydistance->setHtml(QCoreApplication::translate("CenterGroove", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">298.5</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("CenterGroove", "\344\270\255\345\277\203\347\233\226\346\235\277\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        centercover_Xlength->setHtml(QCoreApplication::translate("CenterGroove", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">70</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("CenterGroove", "\344\270\255\345\277\203\347\233\226\346\235\277\345\260\272\345\257\270Y\357\274\210cm\357\274\211", nullptr));
        centercover_Ylength->setHtml(QCoreApplication::translate("CenterGroove", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">8</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("CenterGroove", "\344\270\255\345\277\203\346\262\237\346\247\275\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        centergroove_Xlength->setHtml(QCoreApplication::translate("CenterGroove", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">60</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("CenterGroove", "\344\270\255\345\277\203\346\262\237\346\247\275\345\260\272\345\257\270Y\357\274\210cm\357\274\211", nullptr));
        centergroove_Ylength->setHtml(QCoreApplication::translate("CenterGroove", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">80</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("CenterGroove", "\344\270\255\345\277\203\346\262\237\346\247\275\346\267\267\345\207\235\345\234\237\345\261\202\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        centerconcrete_Xlength->setHtml(QCoreApplication::translate("CenterGroove", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">100</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("CenterGroove", "\344\270\255\345\277\203\346\262\237\346\247\275\346\267\267\345\207\235\345\234\237\345\261\202\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        centerconcrete_Ylength->setHtml(QCoreApplication::translate("CenterGroove", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">113</p></body></html>", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class CenterGroove: public Ui_CenterGroove {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CENTERGROOVE_H
