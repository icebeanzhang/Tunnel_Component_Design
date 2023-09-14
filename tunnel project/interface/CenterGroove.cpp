#include "CenterGroove.h"
#include "ui_centergroove.h"
#include <QDialog>
#include "mainwindow.h"
#include <qmessagebox.h>
#include <qtextcodec.h>
#include <QLineEdit>

CenterGroove::CenterGroove(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::CenterGroove)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par2_1()), this, SLOT(show()));

	//链接确认与取消
	connect(ui->btn2_1_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn2_1_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

CenterGroove::~CenterGroove()
{
	delete ui;
}

void CenterGroove::btn_verify_clicked()
{
	// 获取文本编辑框中的输入
	QString text1 = ui->P1_O1_Ydistance->toPlainText();
	QString text2 = ui->centercover_Xlength->toPlainText();
	QString text3 = ui->centercover_Ylength->toPlainText();
	QString text4 = ui->centergroove_Xlength->toPlainText();
	QString text5 = ui->centergroove_Ylength->toPlainText();
	QString text6 = ui->centerconcrete_Xlength->toPlainText();
	QString text7 = ui->centerconcrete_Ylength->toPlainText();
	

	// 将文本转换为数值类型进行计算
	bool ok1, ok2, ok3, ok4, ok5, ok6, ok7;
	double P1_O1_Ydistance = text1.toDouble(&ok1);
	double centercover_Xlength = text2.toDouble(&ok2);
	double centercover_Ylength = text3.toDouble(&ok3);
	double centergroove_Xlength = text4.toDouble(&ok4);
	double centergroove_Ylength = text5.toDouble(&ok5);
	double centerconcrete_Xlength = text6.toDouble(&ok6);
	double centerconcrete_Ylength = text7.toDouble(&ok7);
	
	if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7) {
		// 进行计算
		

		CenterGrooveCoordinates centercoords;
		centercoords.P1 = P1_O1_Ydistance;
		centercoords.P2_x = centercover_Xlength;
		centercoords.P2_y = centercover_Ylength;
		centercoords.P3_x = centergroove_Xlength;
		centercoords.P3_y = centergroove_Ylength;
		centercoords.P4_x = centerconcrete_Xlength;
		centercoords.P4_y = centerconcrete_Ylength;

		// 发射信号，将自定义结构作为参数传递给槽函数
		emit sendCenterGrooveCoordinates(centercoords);
		close();
	}
	else {
		// 文本转换失败
		QMessageBox::warning(this, "错误", "请输入有效的数值！", QMessageBox::Ok);
	}

}

void CenterGroove::btn_cancel_clicked()
{
	close();//关闭窗口
}

