/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "occview.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionOutput;
    QAction *actiondian;
    QAction *actionzhixian;
    QAction *actionquxian;
    QAction *actionfangxing;
    QAction *actionyuan;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab_4;
    QTreeWidget *tr2;
    QWidget *tab_3;
    QTreeWidget *tr1;
    OccView *OCCWid;
    QListView *listView;
    QMenuBar *menuBar;
    QMenu *wenjian;
    QMenu *jianmo;
    QMenu *shitu;
    QMenu *gongju;
    QMenu *chuangkou;
    QMenu *bangzhu;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1047, 826);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/tubiao.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QString::fromUtf8("actionNew"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/xinjian.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon1);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/dakai.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon2);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/baocun.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon3);
        actionOutput = new QAction(MainWindow);
        actionOutput->setObjectName(QString::fromUtf8("actionOutput"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/daochu.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOutput->setIcon(icon4);
        actiondian = new QAction(MainWindow);
        actiondian->setObjectName(QString::fromUtf8("actiondian"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/dian.png"), QSize(), QIcon::Normal, QIcon::Off);
        actiondian->setIcon(icon5);
        actionzhixian = new QAction(MainWindow);
        actionzhixian->setObjectName(QString::fromUtf8("actionzhixian"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/zhixian.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionzhixian->setIcon(icon6);
        actionquxian = new QAction(MainWindow);
        actionquxian->setObjectName(QString::fromUtf8("actionquxian"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/quxian.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionquxian->setIcon(icon7);
        actionfangxing = new QAction(MainWindow);
        actionfangxing->setObjectName(QString::fromUtf8("actionfangxing"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/fangxing.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionfangxing->setIcon(icon8);
        actionyuan = new QAction(MainWindow);
        actionyuan->setObjectName(QString::fromUtf8("actionyuan"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/new/prefix1/ziyuan/yuan.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionyuan->setIcon(icon9);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(widget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy2);
        tabWidget->setMovable(true);
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        tr2 = new QTreeWidget(tab_4);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        tr2->setHeaderItem(__qtreewidgetitem);
        tr2->setObjectName(QString::fromUtf8("tr2"));
        tr2->setGeometry(QRect(0, 0, 171, 511));
        sizePolicy2.setHeightForWidth(tr2->sizePolicy().hasHeightForWidth());
        tr2->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(14);
        tr2->setFont(font);
        tr2->header()->setVisible(false);
        tabWidget->addTab(tab_4, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tr1 = new QTreeWidget(tab_3);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem();
        __qtreewidgetitem1->setText(0, QString::fromUtf8("1"));
        tr1->setHeaderItem(__qtreewidgetitem1);
        tr1->setObjectName(QString::fromUtf8("tr1"));
        tr1->setGeometry(QRect(0, 0, 171, 511));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(tr1->sizePolicy().hasHeightForWidth());
        tr1->setSizePolicy(sizePolicy3);
        tr1->setFont(font);
        tr1->header()->setVisible(false);
        tabWidget->addTab(tab_3, QString());

        horizontalLayout_2->addWidget(tabWidget);

        OCCWid = new OccView(widget);
        OCCWid->setObjectName(QString::fromUtf8("OCCWid"));
        sizePolicy.setHeightForWidth(OCCWid->sizePolicy().hasHeightForWidth());
        OCCWid->setSizePolicy(sizePolicy);

        horizontalLayout_2->addWidget(OCCWid);


        verticalLayout->addWidget(widget);

        listView = new QListView(centralWidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        listView->setEnabled(true);
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy4);
        listView->setMinimumSize(QSize(0, 0));
        listView->setMaximumSize(QSize(16777207, 16777215));
        listView->setMovement(QListView::Static);
        listView->setFlow(QListView::TopToBottom);
        listView->setResizeMode(QListView::Fixed);

        verticalLayout->addWidget(listView);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1047, 23));
        wenjian = new QMenu(menuBar);
        wenjian->setObjectName(QString::fromUtf8("wenjian"));
        jianmo = new QMenu(menuBar);
        jianmo->setObjectName(QString::fromUtf8("jianmo"));
        shitu = new QMenu(menuBar);
        shitu->setObjectName(QString::fromUtf8("shitu"));
        gongju = new QMenu(menuBar);
        gongju->setObjectName(QString::fromUtf8("gongju"));
        chuangkou = new QMenu(menuBar);
        chuangkou->setObjectName(QString::fromUtf8("chuangkou"));
        bangzhu = new QMenu(menuBar);
        bangzhu->setObjectName(QString::fromUtf8("bangzhu"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(wenjian->menuAction());
        menuBar->addAction(jianmo->menuAction());
        menuBar->addAction(shitu->menuAction());
        menuBar->addAction(gongju->menuAction());
        menuBar->addAction(chuangkou->menuAction());
        menuBar->addAction(bangzhu->menuAction());
        wenjian->addAction(actionNew);
        wenjian->addAction(actionOpen);
        wenjian->addAction(actionSave);
        wenjian->addAction(actionOutput);
        mainToolBar->addAction(actiondian);
        mainToolBar->addAction(actionzhixian);
        mainToolBar->addAction(actionquxian);
        mainToolBar->addAction(actionfangxing);
        mainToolBar->addAction(actionyuan);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\351\223\201\350\267\257\351\232\247\351\201\223\345\205\270\345\236\213\346\236\204\344\273\266\346\225\260\345\255\227\345\214\226\350\256\276\350\256\241\350\275\257\344\273\266", nullptr));
        actionNew->setText(QCoreApplication::translate("MainWindow", "new", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "open", nullptr));
        actionSave->setText(QCoreApplication::translate("MainWindow", "save", nullptr));
        actionOutput->setText(QCoreApplication::translate("MainWindow", "output", nullptr));
        actiondian->setText(QCoreApplication::translate("MainWindow", "dian", nullptr));
        actionzhixian->setText(QCoreApplication::translate("MainWindow", "zhixian", nullptr));
        actionquxian->setText(QCoreApplication::translate("MainWindow", "quxian", nullptr));
        actionfangxing->setText(QCoreApplication::translate("MainWindow", "fangxing", nullptr));
        actionyuan->setText(QCoreApplication::translate("MainWindow", "yuan", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("MainWindow", "\345\244\215\345\220\210\345\274\217\350\241\254\347\240\214", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("MainWindow", "\345\200\222\345\210\207\345\274\217\346\264\236\351\227\250", nullptr));
        wenjian->setTitle(QCoreApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        jianmo->setTitle(QCoreApplication::translate("MainWindow", "\345\273\272\346\250\241", nullptr));
        shitu->setTitle(QCoreApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        gongju->setTitle(QCoreApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        chuangkou->setTitle(QCoreApplication::translate("MainWindow", "\347\252\227\345\217\243", nullptr));
        bangzhu->setTitle(QCoreApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
