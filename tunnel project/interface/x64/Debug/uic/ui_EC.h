/********************************************************************************
** Form generated from reading UI file 'EC.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EC_H
#define UI_EC_H

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

class Ui_EC
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn3_1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn3_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *E1;
    QLabel *label_2;
    QTextEdit *E2;
    QLabel *label_3;
    QLabel *label_4;
    QTextEdit *E4;
    QLabel *label_6;
    QTextEdit *E5;
    QLabel *label_7;
    QTextEdit *E6;
    QLabel *label_8;
    QTextEdit *E7;
    QLabel *label_9;
    QTextEdit *E8;
    QTextEdit *E3;
    QLabel *label_5;

    void setupUi(QWidget *EC)
    {
        if (EC->objectName().isEmpty())
            EC->setObjectName(QString::fromUtf8("EC"));
        EC->resize(856, 500);
        horizontalLayoutWidget = new QWidget(EC);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 460, 851, 25));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn3_1 = new QPushButton(horizontalLayoutWidget);
        btn3_1->setObjectName(QString::fromUtf8("btn3_1"));

        horizontalLayout->addWidget(btn3_1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn3_2 = new QPushButton(horizontalLayoutWidget);
        btn3_2->setObjectName(QString::fromUtf8("btn3_2"));

        horizontalLayout->addWidget(btn3_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(EC);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(50, 70, 201, 321));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        E1 = new QTextEdit(widget);
        E1->setObjectName(QString::fromUtf8("E1"));
        E1->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, E1);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        E2 = new QTextEdit(widget);
        E2->setObjectName(QString::fromUtf8("E2"));
        E2->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(1, QFormLayout::FieldRole, E2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        E4 = new QTextEdit(widget);
        E4->setObjectName(QString::fromUtf8("E4"));
        E4->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(4, QFormLayout::FieldRole, E4);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        E5 = new QTextEdit(widget);
        E5->setObjectName(QString::fromUtf8("E5"));
        E5->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(5, QFormLayout::FieldRole, E5);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        E6 = new QTextEdit(widget);
        E6->setObjectName(QString::fromUtf8("E6"));
        E6->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(6, QFormLayout::FieldRole, E6);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        E7 = new QTextEdit(widget);
        E7->setObjectName(QString::fromUtf8("E7"));
        E7->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(7, QFormLayout::FieldRole, E7);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        E8 = new QTextEdit(widget);
        E8->setObjectName(QString::fromUtf8("E8"));
        E8->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(8, QFormLayout::FieldRole, E8);

        E3 = new QTextEdit(widget);
        E3->setObjectName(QString::fromUtf8("E3"));
        E3->setMaximumSize(QSize(50, 16777215));

        formLayout->setWidget(2, QFormLayout::FieldRole, E3);

        label_5 = new QLabel(EC);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(280, 20, 561, 421));
        label_5->setStyleSheet(QString::fromUtf8("border-image: url(:/EC.bmp);"));

        retranslateUi(EC);

        QMetaObject::connectSlotsByName(EC);
    } // setupUi

    void retranslateUi(QWidget *EC)
    {
        EC->setWindowTitle(QCoreApplication::translate("EC", "\344\272\214\350\241\254\345\217\202\346\225\260", nullptr));
        btn3_1->setText(QCoreApplication::translate("EC", "\347\241\256\350\256\244", nullptr));
        btn3_2->setText(QCoreApplication::translate("EC", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("EC", "\346\213\261\345\242\231\345\234\206\345\274\247\345\215\212\345\276\204\357\274\210cm\357\274\211", nullptr));
        E1->setHtml(QCoreApplication::translate("EC", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">665</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("EC", "\344\273\260\346\213\261\345\215\212\345\276\204\357\274\210cm\357\274\211", nullptr));
        E2->setHtml(QCoreApplication::translate("EC", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">1720</p></body></html>", nullptr));
        label_3->setText(QCoreApplication::translate("EC", "\346\213\261\345\242\231\345\216\232\345\272\246\357\274\210cm\357\274\211", nullptr));
        label_4->setText(QCoreApplication::translate("EC", "\344\273\260\346\213\261\345\216\232\345\272\246\357\274\210cm\357\274\211", nullptr));
        E4->setHtml(QCoreApplication::translate("EC", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">65</p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("EC", "\344\273\260\346\213\261\345\205\205\345\241\253\345\216\232\345\272\246\357\274\210cm\357\274\211", nullptr));
        E5->setHtml(QCoreApplication::translate("EC", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">180</p></body></html>", nullptr));
        label_7->setText(QCoreApplication::translate("EC", "\346\262\237\346\247\275\345\256\275\345\272\246\357\274\210cm\357\274\211", nullptr));
        E6->setHtml(QCoreApplication::translate("EC", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">160</p></body></html>", nullptr));
        label_8->setText(QCoreApplication::translate("EC", "\346\262\237\346\247\275\351\241\266\351\235\242\351\253\230\345\267\256\357\274\210cm\357\274\211", nullptr));
        E7->setHtml(QCoreApplication::translate("EC", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">30</p></body></html>", nullptr));
        label_9->setText(QCoreApplication::translate("EC", "\345\237\272\346\234\254\345\256\275\345\272\246\357\274\210cm\357\274\211", nullptr));
        E8->setHtml(QCoreApplication::translate("EC", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">940</p></body></html>", nullptr));
        E3->setHtml(QCoreApplication::translate("EC", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">55</p></body></html>", nullptr));
        label_5->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class EC: public Ui_EC {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EC_H
