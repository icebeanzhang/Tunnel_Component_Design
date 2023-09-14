/********************************************************************************
** Form generated from reading UI file 'dia4_1.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIA4_1_H
#define UI_DIA4_1_H

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

class Ui_dia4_1
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn4_1_1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn4_1_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *firstSurppWall_Thick;
    QLabel *label_2;
    QTextEdit *line1AndCent_Distance;
    QLabel *label_3;
    QTextEdit *line1AndLine2_Distance;
    QLabel *label_4;
    QTextEdit *invertedArch_Thick;
    QLabel *label_5;
    QTextEdit *cirConnn_Thick;
    QLabel *label_6;
    QTextEdit *archAnch_Distance;
    QLabel *label_7;
    QTextEdit *wallAnch_Distance;
    QLabel *label_8;
    QTextEdit *arch_Angle;
    QLabel *label_9;

    void setupUi(QWidget *dia4_1)
    {
        if (dia4_1->objectName().isEmpty())
            dia4_1->setObjectName(QString::fromUtf8("dia4_1"));
        dia4_1->resize(822, 465);
        horizontalLayoutWidget = new QWidget(dia4_1);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 400, 821, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn4_1_1 = new QPushButton(horizontalLayoutWidget);
        btn4_1_1->setObjectName(QString::fromUtf8("btn4_1_1"));

        horizontalLayout->addWidget(btn4_1_1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn4_1_2 = new QPushButton(horizontalLayoutWidget);
        btn4_1_2->setObjectName(QString::fromUtf8("btn4_1_2"));

        horizontalLayout->addWidget(btn4_1_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(dia4_1);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(30, 40, 271, 321));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label);

        firstSurppWall_Thick = new QTextEdit(widget);
        firstSurppWall_Thick->setObjectName(QString::fromUtf8("firstSurppWall_Thick"));

        formLayout->setWidget(1, QFormLayout::FieldRole, firstSurppWall_Thick);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        line1AndCent_Distance = new QTextEdit(widget);
        line1AndCent_Distance->setObjectName(QString::fromUtf8("line1AndCent_Distance"));

        formLayout->setWidget(2, QFormLayout::FieldRole, line1AndCent_Distance);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_3);

        line1AndLine2_Distance = new QTextEdit(widget);
        line1AndLine2_Distance->setObjectName(QString::fromUtf8("line1AndLine2_Distance"));

        formLayout->setWidget(3, QFormLayout::FieldRole, line1AndLine2_Distance);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        invertedArch_Thick = new QTextEdit(widget);
        invertedArch_Thick->setObjectName(QString::fromUtf8("invertedArch_Thick"));

        formLayout->setWidget(5, QFormLayout::FieldRole, invertedArch_Thick);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        cirConnn_Thick = new QTextEdit(widget);
        cirConnn_Thick->setObjectName(QString::fromUtf8("cirConnn_Thick"));

        formLayout->setWidget(6, QFormLayout::FieldRole, cirConnn_Thick);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(7, QFormLayout::LabelRole, label_6);

        archAnch_Distance = new QTextEdit(widget);
        archAnch_Distance->setObjectName(QString::fromUtf8("archAnch_Distance"));

        formLayout->setWidget(7, QFormLayout::FieldRole, archAnch_Distance);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout->setWidget(8, QFormLayout::LabelRole, label_7);

        wallAnch_Distance = new QTextEdit(widget);
        wallAnch_Distance->setObjectName(QString::fromUtf8("wallAnch_Distance"));

        formLayout->setWidget(8, QFormLayout::FieldRole, wallAnch_Distance);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout->setWidget(9, QFormLayout::LabelRole, label_8);

        arch_Angle = new QTextEdit(widget);
        arch_Angle->setObjectName(QString::fromUtf8("arch_Angle"));

        formLayout->setWidget(9, QFormLayout::FieldRole, arch_Angle);

        label_9 = new QLabel(dia4_1);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(330, 10, 481, 381));
        label_9->setStyleSheet(QString::fromUtf8("border-image: url(:/new/prefix1/chuzhi.png);"));

        retranslateUi(dia4_1);

        QMetaObject::connectSlotsByName(dia4_1);
    } // setupUi

    void retranslateUi(QWidget *dia4_1)
    {
        dia4_1->setWindowTitle(QApplication::translate("dia4_1", "\345\210\235\346\224\257\345\226\267\346\267\267\345\217\202\346\225\260", nullptr));
        btn4_1_1->setText(QApplication::translate("dia4_1", "\347\241\256\350\256\244", nullptr));
        btn4_1_2->setText(QApplication::translate("dia4_1", "\345\217\226\346\266\210", nullptr));
        label->setText(QApplication::translate("dia4_1", "\345\210\235\346\224\257\346\213\261\345\242\231\345\216\232\345\272\246\357\274\210cm\357\274\211", nullptr));
        label_2->setText(QApplication::translate("dia4_1", "\345\210\207\347\272\277\347\202\271\351\253\230\345\272\246\357\274\210cm\357\274\211", nullptr));
        label_3->setText(QApplication::translate("dia4_1", "\345\210\207\347\272\277\347\202\271\351\253\230\345\267\256\357\274\210cm\357\274\211", nullptr));
        label_4->setText(QApplication::translate("dia4_1", "\345\210\235\350\241\254\344\273\260\346\213\261\345\216\232\345\272\246\357\274\210cm\357\274\211", nullptr));
        label_5->setText(QApplication::translate("dia4_1", "\345\210\235\350\241\254\346\213\261\345\242\231\344\270\216\344\273\260\346\213\261\350\277\236\346\216\245\345\234\206\345\216\232\345\272\246\357\274\210cm\357\274\211", nullptr));
        label_6->setText(QApplication::translate("dia4_1", "\346\213\261\351\203\250\351\224\232\346\235\206\345\210\206\345\270\203\351\227\264\350\267\235\357\274\210cm\357\274\211", nullptr));
        label_7->setText(QApplication::translate("dia4_1", "\350\276\271\345\242\231\351\224\232\346\235\206\345\210\206\345\270\203\351\227\264\350\267\235\357\274\210cm\357\274\211", nullptr));
        label_8->setText(QApplication::translate("dia4_1", "\345\210\235\346\224\257\345\226\267\346\267\267\346\213\261\351\203\250\345\234\206\345\277\203\350\247\222\357\274\210\302\260\357\274\211", nullptr));
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class dia4_1: public Ui_dia4_1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIA4_1_H
