#include "EC.h"
#include "ui_EC.h"
#include <QDialog>
#include "mainwindow.h"
#include <qmessagebox.h>
#include <qtextcodec.h>
#include <QLineEdit>


EC::EC(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::EC)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par3()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn3_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn3_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

EC::~EC()
{
	delete ui;
}

void EC::btn_verify_clicked()
{
	//传输数据
	QString text1 = ui->E1->toPlainText();
	QString text2 = ui->E2->toPlainText();
	QString text3 = ui->E3->toPlainText();
	QString text4 = ui->E4->toPlainText();
	QString text5 = ui->E5->toPlainText();
	QString text6 = ui->E6->toPlainText();
	QString text7 = ui->E7->toPlainText();
	QString text8 = ui->E8->toPlainText();


	// 将文本转换为数值类型进行计算
	bool ok1, ok2, ok3, ok4, ok5, ok6, ok7, ok8;
	double R1_NLK = text1.toDouble(&ok1);
	double radius3 = text2.toDouble(&ok2);
	double R1_R2_HD = text3.toDouble(&ok3);
	double R3_R5_HD = text4.toDouble(&ok4);
	double R3_TC = text5.toDouble(&ok5);
	double GoucaoKuandu = text6.toDouble(&ok6);
	double GoucaoGaocha = text7.toDouble(&ok7);
	double JibenKuandu = text8.toDouble(&ok8);
	if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8) {
		// 进行计算
		Erchen centercoords;
		centercoords.E1 = R1_NLK;
		centercoords.E2 = radius3;
		centercoords.E3 = R1_R2_HD;
		centercoords.E4 = R3_R5_HD;
		centercoords.E5 = R3_TC;
		centercoords.E6 = GoucaoKuandu;
		centercoords.E7 = GoucaoGaocha;
		centercoords.E8 = JibenKuandu;
		// 发射信号，将自定义结构作为参数传递给槽函数
		emit sendErchen(centercoords);
		close();
	}
	else {
		// 文本转换失败
		QMessageBox::warning(this, "错误", "请输入有效的数值！", QMessageBox::Ok);
	}
}

void EC::btn_cancel_clicked()
{
	close();//关闭窗口
}

