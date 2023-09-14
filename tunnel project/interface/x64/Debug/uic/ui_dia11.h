/********************************************************************************
** Form generated from reading UI file 'dia11.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIA11_H
#define UI_DIA11_H

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

class Ui_dia11
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btn11_1;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *btn11_2;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QFormLayout *formLayout;
    QLabel *label;
    QTextEdit *textEdit_3;
    QLabel *label_2;
    QTextEdit *textEdit_4;
    QLabel *label_3;
    QTextEdit *textEdit;
    QLabel *label_4;
    QTextEdit *textEdit_2;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label_5;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QWidget *dia11)
    {
        if (dia11->objectName().isEmpty())
            dia11->setObjectName(QString::fromUtf8("dia11"));
        dia11->resize(400, 300);
        horizontalLayoutWidget = new QWidget(dia11);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 250, 401, 51));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(50);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        btn11_1 = new QPushButton(horizontalLayoutWidget);
        btn11_1->setObjectName(QString::fromUtf8("btn11_1"));

        horizontalLayout->addWidget(btn11_1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        btn11_2 = new QPushButton(horizontalLayoutWidget);
        btn11_2->setObjectName(QString::fromUtf8("btn11_2"));

        horizontalLayout->addWidget(btn11_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widget = new QWidget(dia11);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 60, 361, 191));
        formLayout = new QFormLayout(widget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        textEdit_3 = new QTextEdit(widget);
        textEdit_3->setObjectName(QString::fromUtf8("textEdit_3"));

        formLayout->setWidget(0, QFormLayout::FieldRole, textEdit_3);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        textEdit_4 = new QTextEdit(widget);
        textEdit_4->setObjectName(QString::fromUtf8("textEdit_4"));

        formLayout->setWidget(1, QFormLayout::FieldRole, textEdit_4);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        textEdit = new QTextEdit(widget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, textEdit);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_4);

        textEdit_2 = new QTextEdit(widget);
        textEdit_2->setObjectName(QString::fromUtf8("textEdit_2"));

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit_2);

        widget_2 = new QWidget(dia11);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(0, 0, 401, 55));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_5 = new QSpacerItem(112, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        label_5 = new QLabel(widget_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        horizontalLayout_2->addWidget(label_5);

        horizontalSpacer_4 = new QSpacerItem(111, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        retranslateUi(dia11);

        QMetaObject::connectSlotsByName(dia11);
    } // setupUi

    void retranslateUi(QWidget *dia11)
    {
        dia11->setWindowTitle(QCoreApplication::translate("dia11", "Form", nullptr));
        btn11_1->setText(QCoreApplication::translate("dia11", "\347\241\256\350\256\244", nullptr));
        btn11_2->setText(QCoreApplication::translate("dia11", "\345\217\226\346\266\210", nullptr));
        label->setText(QCoreApplication::translate("dia11", "\346\213\261\345\242\231\345\234\206\345\274\247\345\215\212\345\276\204\357\274\210cm\357\274\211", nullptr));
        label_2->setText(QCoreApplication::translate("dia11", "\345\237\272\346\234\254\345\256\275\345\272\246\357\274\210cm\357\274\211", nullptr));
        label_3->setText(QCoreApplication::translate("dia11", "\346\262\237\346\247\275\345\256\275\345\272\246\357\274\210cm\357\274\211", nullptr));
        label_4->setText(QCoreApplication::translate("dia11", "\346\262\237\346\247\275\351\241\266\351\235\242\351\253\230\345\267\256\357\274\210cm\357\274\211", nullptr));
        label_5->setText(QCoreApplication::translate("dia11", "\345\200\222\345\210\207\345\274\217\346\264\236\351\227\250\345\206\205\350\275\256\345\273\223\345\217\202\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dia11: public Ui_dia11 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIA11_H
