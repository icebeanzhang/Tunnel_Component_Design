#include "SideGroove.h"
#include "ui_sidegroove.h"
#include <QDialog>
#include "mainwindow.h"
#include <qmessagebox.h>
#include <qtextcodec.h>
#include <QLineEdit>

SideGroove::SideGroove(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::SideGroove)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par2_2()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn2_2_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn2_2_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

SideGroove::~SideGroove()
{
	delete ui;
}

void SideGroove::btn_verify_clicked()
{
	// 获取文本编辑框中的输入
	QString text1 = ui->innercontour_trench_distance->toPlainText();
	QString text2 = ui->trenchcover_gap->toPlainText();
	QString text3 = ui->trenchcover_Xlength->toPlainText();
	QString text4 = ui->trenchcover_Ylength->toPlainText();
	QString text5 = ui->powercable_Xlength->toPlainText();
	QString text6 = ui->powercable_Ylength->toPlainText();
	QString text7 = ui->sidegroove_Xlength->toPlainText();
	QString text8 = ui->sidegroove_Ylength->toPlainText();
	QString text9 = ui->communcable_Xlength->toPlainText();
	QString text10 = ui->communcable_Ylength->toPlainText();
	QString text11 = ui->trench_Overlength->toPlainText();

	// 将文本转换为数值类型进行计算
	bool ok1, ok2, ok3, ok4, ok5, ok6, ok7, ok8, ok9, ok10, ok11;
	double innercontour_trench_distance = text1.toDouble(&ok1);
	double trenchcover_gap = text2.toDouble(&ok2);
	double trenchcover_Xlength = text3.toDouble(&ok3);
	double trenchcover_Ylength = text4.toDouble(&ok4);
	double powercable_Xlength = text5.toDouble(&ok5);
	double powercable_Ylength = text6.toDouble(&ok6);
	double sidegroove_Xlength = text7.toDouble(&ok7);
	double sidegroove_Ylength = text8.toDouble(&ok8);
	double communcable_Xlength = text9.toDouble(&ok9);
	double communcable_Ylength = text10.toDouble(&ok10);
	double trench_Overlength = text11.toDouble(&ok11);

	if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11) {
		// 进行计算

		SideGrooveCoordinates sidecoords;
		sidecoords.P1 = innercontour_trench_distance;
		sidecoords.P2 = trenchcover_gap;
		sidecoords.P3_x = trenchcover_Xlength;
		sidecoords.P3_y = trenchcover_Ylength;
		sidecoords.P4_x = powercable_Xlength;
		sidecoords.P4_y = powercable_Ylength;
		sidecoords.P5_x = sidegroove_Xlength;
		sidecoords.P5_y = sidegroove_Ylength;
		sidecoords.P6_x = communcable_Xlength;
		sidecoords.P6_y = communcable_Ylength;
		sidecoords.P7 = trench_Overlength;

		// 发射信号，将自定义结构作为参数传递给槽函数
		emit sendSideGrooveCoordinates(sidecoords);
		close();
	}
	else {
		// 文本转换失败
		QMessageBox::warning(this, "错误", "请输入有效的数值！", QMessageBox::Ok);
	}
}

void SideGroove::btn_cancel_clicked()
{
	close();//关闭窗口
}

