/********************************************************************************
** Form generated from reading UI file 'InvertedBrim.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INVERTEDBRIM_H
#define UI_INVERTEDBRIM_H

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

class Ui_InvertedBrim
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn15_1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn15_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *textEdit_1;
    QLabel *label_2;
    QTextEdit *textEdit_2;
    QLabel *label_3;
    QTextEdit *textEdit_5;
    QLabel *label_4;
    QTextEdit *textEdit_3;
    QLabel *label_5;
    QTextEdit *textEdit_4;
    QWidget *widget_2;

    void setupUi(QWidget *InvertedBrim)
    {
        if (InvertedBrim->objectName().isEmpty())
            InvertedBrim->setObjectName(QString::fromUtf8("InvertedBrim"));
        InvertedBrim->resize(829, 471);
        horizontalLayoutWidget = new QWidget(InvertedBrim);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 400, 821, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn15_1 = new QPushButton(horizontalLayoutWidget);
        btn15_1->setObjectName(QString::fromUtf8("btn15_1"));

        horizontalLayout->addWidget(btn15_1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn15_2 = new QPushButton(horizontalLayoutWidget);
        btn15_2->setObjectName(QString::fromUtf8("btn15_2"));

        horizontalLayout->addWidget(btn15_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(InvertedBrim);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 80, 221, 231));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textEdit_1 = new QTextEdit(widget);
        textEdit_1->setObjectName(QString::fromUtf8("textEdit_1"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEdit_1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        textEdit_2 = new QTextEdit(widget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_3);

        textEdit_5 = new QTextEdit(widget);
        textEdit_5->setObjectName(QString::fromUtf8("textEdit_5"));

        formLayout->setWidget(7, QFormLayout::FieldRole, textEdit_5);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        textEdit_3 = new QTextEdit(widget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));

        formLayout->setWidget(3, QFormLayout::FieldRole, textEdit_3);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        textEdit_4 = new QTextEdit(widget);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));

        formLayout->setWidget(5, QFormLayout::FieldRole, textEdit_4);

        widget_2 = new QWidget(InvertedBrim);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(310, 30, 491, 351));
        widget_2->setStyleSheet(QString::fromUtf8("border-image: url(:/\345\200\222\345\210\207\345\274\217\351\227\250\346\264\236-2.png);"));

        retranslateUi(InvertedBrim);

        QMetaObject::connectSlotsByName(InvertedBrim);
    } // setupUi

    void retranslateUi(QWidget *InvertedBrim)
    {
        InvertedBrim->setWindowTitle(QCoreApplication::translate("InvertedBrim", "\345\200\222\345\210\207\345\274\217\345\270\275\346\252\220\345\217\202\346\225\260", nullptr));
        btn15_1->setText(QCoreApplication::translate("InvertedBrim", "\347\241\256\350\256\244", nullptr));
        btn15_2->setText(QCoreApplication::translate("InvertedBrim", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("InvertedBrim", "\347\254\254\344\270\200\345\234\206\345\217\260\351\241\266\351\203\250\345\215\212\345\276\204\357\274\210cm\357\274\211", nullptr));
        textEdit_1->setHtml(QCoreApplication::translate("InvertedBrim", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">735</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("InvertedBrim", "\347\254\254\344\270\200\345\234\206\345\217\260\345\272\225\351\203\250\345\215\212\345\276\204\357\274\210cm\357\274\211", nullptr));
        textEdit_2->setHtml(QCoreApplication::translate("InvertedBrim", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">835</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("InvertedBrim", "\347\254\254\344\270\200\345\234\206\345\217\260\351\253\230\345\272\246\357\274\210cm\357\274\211", nullptr));
        textEdit_5->setHtml(QCoreApplication::translate("InvertedBrim", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">600</p></body></html>", nullptr));
        label_4->setText(QCoreApplication::translate("InvertedBrim", "\347\254\254\344\272\214\345\234\206\345\217\260\351\241\266\351\203\250\345\215\212\345\276\204\357\274\210cm\357\274\211", nullptr));
        textEdit_3->setHtml(QCoreApplication::translate("InvertedBrim", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">665</p></body></html>", nullptr));
        label_5->setText(QCoreApplication::translate("InvertedBrim", "\347\254\254\344\272\214\345\234\206\345\217\260\351\241\266\351\203\250\345\215\212\345\276\204\357\274\210cm\357\274\211", nullptr));
        textEdit_4->setHtml(QCoreApplication::translate("InvertedBrim", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">765</p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InvertedBrim: public Ui_InvertedBrim {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INVERTEDBRIM_H
