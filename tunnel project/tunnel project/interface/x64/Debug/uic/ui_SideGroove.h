/********************************************************************************
** Form generated from reading UI file 'SideGroove.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SIDEGROOVE_H
#define UI_SIDEGROOVE_H

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

class Ui_SideGroove
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn2_2_1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn2_2_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *innercontour_trench_distance;
    QLabel *label_2;
    QTextEdit *trenchcover_gap;
    QLabel *label_3;
    QTextEdit *trenchcover_Xlength;
    QLabel *label_4;
    QTextEdit *trenchcover_Ylength;
    QLabel *label_5;
    QTextEdit *powercable_Xlength;
    QLabel *label_6;
    QTextEdit *powercable_Ylength;
    QLabel *label_7;
    QTextEdit *sidegroove_Xlength;
    QLabel *label_8;
    QTextEdit *sidegroove_Ylength;
    QLabel *label_11;
    QTextEdit *communcable_Xlength;
    QLabel *label_10;
    QTextEdit *communcable_Ylength;
    QLabel *label_13;
    QTextEdit *trench_Overlength;
    QLabel *label_9;

    void setupUi(QWidget *SideGroove)
    {
        if (SideGroove->objectName().isEmpty())
            SideGroove->setObjectName(QString::fromUtf8("SideGroove"));
        SideGroove->resize(749, 513);
        horizontalLayoutWidget = new QWidget(SideGroove);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 450, 731, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn2_2_1 = new QPushButton(horizontalLayoutWidget);
        btn2_2_1->setObjectName(QString::fromUtf8("btn2_2_1"));

        horizontalLayout->addWidget(btn2_2_1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn2_2_2 = new QPushButton(horizontalLayoutWidget);
        btn2_2_2->setObjectName(QString::fromUtf8("btn2_2_2"));

        horizontalLayout->addWidget(btn2_2_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(SideGroove);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 311, 431));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        innercontour_trench_distance = new QTextEdit(widget);
        innercontour_trench_distance->setObjectName(QString::fromUtf8("innercontour_trench_distance"));

        formLayout->setWidget(0, QFormLayout::FieldRole, innercontour_trench_distance);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        trenchcover_gap = new QTextEdit(widget);
        trenchcover_gap->setObjectName(QString::fromUtf8("trenchcover_gap"));

        formLayout->setWidget(1, QFormLayout::FieldRole, trenchcover_gap);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        trenchcover_Xlength = new QTextEdit(widget);
        trenchcover_Xlength->setObjectName(QString::fromUtf8("trenchcover_Xlength"));

        formLayout->setWidget(2, QFormLayout::FieldRole, trenchcover_Xlength);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        trenchcover_Ylength = new QTextEdit(widget);
        trenchcover_Ylength->setObjectName(QString::fromUtf8("trenchcover_Ylength"));

        formLayout->setWidget(4, QFormLayout::FieldRole, trenchcover_Ylength);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_5);

        powercable_Xlength = new QTextEdit(widget);
        powercable_Xlength->setObjectName(QString::fromUtf8("powercable_Xlength"));

        formLayout->setWidget(5, QFormLayout::FieldRole, powercable_Xlength);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_6);

        powercable_Ylength = new QTextEdit(widget);
        powercable_Ylength->setObjectName(QString::fromUtf8("powercable_Ylength"));

        formLayout->setWidget(6, QFormLayout::FieldRole, powercable_Ylength);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_7);

        sidegroove_Xlength = new QTextEdit(widget);
        sidegroove_Xlength->setObjectName(QString::fromUtf8("sidegroove_Xlength"));

        formLayout->setWidget(7, QFormLayout::FieldRole, sidegroove_Xlength);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_8);

        sidegroove_Ylength = new QTextEdit(widget);
        sidegroove_Ylength->setObjectName(QString::fromUtf8("sidegroove_Ylength"));

        formLayout->setWidget(8, QFormLayout::FieldRole, sidegroove_Ylength);

        label_11 = new QLabel(widget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_11);

        communcable_Xlength = new QTextEdit(widget);
        communcable_Xlength->setObjectName(QString::fromUtf8("communcable_Xlength"));

        formLayout->setWidget(9, QFormLayout::FieldRole, communcable_Xlength);

        label_10 = new QLabel(widget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        formLayout->setWidget(10, QFormLayout::LabelRole, label_10);

        communcable_Ylength = new QTextEdit(widget);
        communcable_Ylength->setObjectName(QString::fromUtf8("communcable_Ylength"));

        formLayout->setWidget(10, QFormLayout::FieldRole, communcable_Ylength);

        label_13 = new QLabel(widget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout->setWidget(12, QFormLayout::LabelRole, label_13);

        trench_Overlength = new QTextEdit(widget);
        trench_Overlength->setObjectName(QString::fromUtf8("trench_Overlength"));

        formLayout->setWidget(12, QFormLayout::FieldRole, trench_Overlength);

        label_9 = new QLabel(SideGroove);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(350, 60, 391, 341));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/SideGroove.png);"));

        retranslateUi(SideGroove);

        QMetaObject::connectSlotsByName(SideGroove);
    } // setupUi

    void retranslateUi(QWidget *SideGroove)
    {
        SideGroove->setWindowTitle(QCoreApplication::translate("SideGroove", "\344\276\247\346\262\237\345\217\202\346\225\260", nullptr));
        btn2_2_1->setText(QCoreApplication::translate("SideGroove", "\347\241\256\350\256\244", nullptr));
        btn2_2_2->setText(QCoreApplication::translate("SideGroove", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("SideGroove", "\346\234\200\345\267\246\344\276\247\347\233\226\346\235\277\350\267\235\347\246\273\345\206\205\350\275\256\345\273\223\344\272\244\347\202\271\347\232\204\350\267\235\347\246\273\357\274\210cm\357\274\211", nullptr));
        label_2->setText(QCoreApplication::translate("SideGroove", "\344\276\247\346\262\237\347\233\226\346\235\277\344\271\213\351\227\264\347\232\204\351\227\264\350\267\235\357\274\210cm\357\274\211", nullptr));
        label_3->setText(QCoreApplication::translate("SideGroove", "\344\276\247\346\262\237\347\233\226\346\235\277\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        label_4->setText(QCoreApplication::translate("SideGroove", "\344\276\247\346\262\237\347\233\226\346\235\277\345\260\272\345\257\270Y\357\274\210cm\357\274\211", nullptr));
        label_5->setText(QCoreApplication::translate("SideGroove", "\347\224\265\345\212\233\347\224\265\347\274\206\346\247\275\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        label_6->setText(QCoreApplication::translate("SideGroove", "\347\224\265\345\212\233\347\224\265\347\274\206\346\247\275\345\260\272\345\257\270Y\357\274\210cm\357\274\211", nullptr));
        label_7->setText(QCoreApplication::translate("SideGroove", "\344\276\247\346\262\237\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        label_8->setText(QCoreApplication::translate("SideGroove", "\344\276\247\346\262\237\345\260\272\345\257\270Y\357\274\210cm\357\274\211", nullptr));
        label_11->setText(QCoreApplication::translate("SideGroove", "\351\200\232\344\277\241\344\277\241\345\217\267\347\224\265\347\274\206\346\247\275\345\260\272\345\257\270X\357\274\210cm\357\274\211", nullptr));
        label_10->setText(QCoreApplication::translate("SideGroove", "\351\200\232\344\277\241\344\277\241\345\217\267\347\224\265\347\274\206\346\247\275\345\260\272\345\257\270Y\357\274\210cm\357\274\211", nullptr));
        label_13->setText(QCoreApplication::translate("SideGroove", "\344\276\247\346\262\237\346\225\264\344\275\223\351\225\277\345\272\246\357\274\210cm\357\274\211", nullptr));
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SideGroove: public Ui_SideGroove {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SIDEGROOVE_H
