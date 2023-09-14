/********************************************************************************
** Form generated from reading UI file 'occview.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OCCVIEW_H
#define UI_OCCVIEW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OccView
{
public:

    void setupUi(QWidget *OccView)
    {
        if (OccView->objectName().isEmpty())
            OccView->setObjectName(QString::fromUtf8("OccView"));
        OccView->resize(400, 300);

        retranslateUi(OccView);

        QMetaObject::connectSlotsByName(OccView);
    } // setupUi

    void retranslateUi(QWidget *OccView)
    {
        OccView->setWindowTitle(QCoreApplication::translate("OccView", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OccView: public Ui_OccView {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OCCVIEW_H
