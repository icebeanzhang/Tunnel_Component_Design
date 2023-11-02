/********************************************************************************
** Form generated from reading UI file 'dia2_1.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIA2_1_H
#define UI_DIA2_1_H

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

class Ui_dia2_1
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
    QLabel *label_3;
    QTextEdit *centerconcrete_Xlength;
    QLabel *label_4;
    QTextEdit *trackbed_rightdistance;
    QLabel *label_5;
    QTextEdit *trackbed_slope;
    QLabel *label_6;
    QTextEdit *centercover_Ylength;
    QLabel *label_7;
    QTextEdit *centerconcrete_Ylength;
    QLabel *label_8;
    QLabel *label_9;
    QTextEdit *centergroove_Xlength;
    QTextEdit *centergroove_Ylength;

    void setupUi(QWidget *dia2_1)
    {
        if (dia2_1->objectName().isEmpty())
            dia2_1->setObjectName(QString::fromUtf8("dia2_1"));
        dia2_1->resize(824, 424);
        horizontalLayoutWidget = new QWidget(dia2_1);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 340, 821, 61));
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

        widget = new QWidget(dia2_1);
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

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_3);

        centerconcrete_Xlength = new QTextEdit(widget);
        centerconcrete_Xlength->setObjectName(QString::fromUtf8("centerconcrete_Xlength"));

        formLayout->setWidget(8, QFormLayout::FieldRole, centerconcrete_Xlength);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(12, QFormLayout::LabelRole, label_4);

        trackbed_rightdistance = new QTextEdit(widget);
        trackbed_rightdistance->setObjectName(QString::fromUtf8("trackbed_rightdistance"));

        formLayout->setWidget(12, QFormLayout::FieldRole, trackbed_rightdistance);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(13, QFormLayout::LabelRole, label_5);

        trackbed_slope = new QTextEdit(widget);
        trackbed_slope->setObjectName(QString::fromUtf8("trackbed_slope"));

        formLayout->setWidget(13, QFormLayout::FieldRole, trackbed_slope);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        centercover_Ylength = new QTextEdit(widget);
        centercover_Ylength->setObjectName(QString::fromUtf8("centercover_Ylength"));

        formLayout->setWidget(2, QFormLayout::FieldRole, centercover_Ylength);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_7);

        centerconcrete_Ylength = new QTextEdit(widget);
        centerconcrete_Ylength->setObjectName(QString::fromUtf8("centerconcrete_Ylength"));

        formLayout->setWidget(10, QFormLayout::FieldRole, centerconcrete_Ylength);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_9);

        centergroove_Xlength = new QTextEdit(widget);
        centergroove_Xlength->setObjectName(QString::fromUtf8("centergroove_Xlength"));

        formLayout->setWidget(4, QFormLayout::FieldRole, centergroove_Xlength);

        centergroove_Ylength = new QTextEdit(widget);
        centergroove_Ylength->setObjectName(QString::fromUtf8("centergroove_Ylength"));

        formLayout->setWidget(5, QFormLayout::FieldRole, centergroove_Ylength);


        retranslateUi(dia2_1);

        QMetaObject::connectSlotsByName(dia2_1);
    } // setupUi

    void retranslateUi(QWidget *dia2_1)
    {
        dia2_1->setWindowTitle(QCoreApplication::translate("dia2_1", "Form", nullptr));
        btn2_1_1->setText(QCoreApplication::translate("dia2_1", "\347\241\256\350\256\244", nullptr));
        btn2_1_2->setText(QCoreApplication::translate("dia2_1", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("dia2_1", "\345\206\205\350\275\256\345\273\223\344\270\255\345\277\203\347\202\271\345\222\214\344\270\255\345\277\203\347\233\226\346\235\277\351\225\277\350\276\271\350\267\235\347\246\273\357\274\210cm\357\274\211", nullptr));
        label_2->setText(QCoreApplication::translate("dia2_1", "\344\270\255\345\277\203\347\233\226\346\235\277\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        label_3->setText(QCoreApplication::translate("dia2_1", "\344\270\255\345\277\203\346\262\237\346\247\275\346\267\267\345\207\235\345\234\237\345\261\202\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        label_4->setText(QCoreApplication::translate("dia2_1", "\344\270\255\345\277\203\346\262\237\346\247\275\346\267\267\345\207\235\345\234\237\345\261\202\345\267\246\344\276\247\350\276\271\344\270\216\345\267\246\344\276\247\347\272\277\350\267\257\344\270\255\347\272\277\347\232\204\350\267\235\347\246\273\357\274\210cm\357\274\211", nullptr));
        label_5->setText(QCoreApplication::translate("dia2_1", "\351\201\223\345\272\212\345\272\225\351\235\242\345\235\241\345\272\246\357\274\210\302\260\357\274\211", nullptr));
        label_6->setText(QCoreApplication::translate("dia2_1", "\344\270\255\345\277\203\347\233\226\346\235\277\345\260\272\345\257\270Y\357\274\210cm\357\274\211", nullptr));
        label_7->setText(QCoreApplication::translate("dia2_1", "\344\270\255\345\277\203\346\262\237\346\247\275\346\267\267\345\207\235\345\234\237\345\261\202\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        label_8->setText(QCoreApplication::translate("dia2_1", "\344\270\255\345\277\203\346\262\237\346\247\275\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        label_9->setText(QCoreApplication::translate("dia2_1", "\344\270\255\345\277\203\346\262\237\346\247\275\345\260\272\345\257\270Y\357\274\210cm\357\274\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dia2_1: public Ui_dia2_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIA2_1_H
