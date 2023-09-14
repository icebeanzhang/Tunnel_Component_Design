#include "dialog.h"
#include "ui_dialog.h"
#include <QDialog>
#include "mainwindow.h"
#include <qmessagebox.h>
#include <qtextcodec.h>
#include <QLineEdit>

dialog::dialog(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dialog)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par1()), this, SLOT(show()));

	//链接确认与取消
	connect(ui->btn1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dialog::~dialog()
{
	delete ui;
}

void dialog::btn_verify_clicked()
{
	// 获取文本编辑框中的输入
	QString text1 = ui->textEdit_3->toPlainText();
	QString text2 = ui->textEdit_4->toPlainText();

	// 将文本转换为数值类型进行计算
	bool ok1, ok2;
	double P1_x = text1.toDouble(&ok1);
	double P1_y = text2.toDouble(&ok2);

	if (ok1 && ok2) {
		// 进行计算
		double P2_x = P1_x;
		double P2_y = P1_y + 50;
		double P3_x = P1_x + 50;
		double P3_y = P2_y;
		double P4_x = P3_x;
		double P4_y = P1_y;

		// 构造输出字符串
		QString output1 = QString("P2坐标：(%1, %2)").arg(P2_x).arg(P2_y);
		QString output2 = QString("P3坐标：(%1, %2)").arg(P3_x).arg(P3_y);
		QString output3 = QString("P4坐标：(%1, %2)").arg(P4_x).arg(P4_y);

		QString finalOutput = output1 + "\n" + output2 + "\n" + output3;

		// 显示计算结果
		QMessageBox::information(this, "计算结果", finalOutput, QMessageBox::Ok);
		SquareCoordinates coords;
		coords.P1_x = P1_x;
		coords.P1_y = P1_y;
		coords.P2_x = P2_x;
		coords.P2_y = P2_y;
		coords.P3_x = P3_x;
		coords.P3_y = P3_y;
		coords.P4_x = P4_x;
		coords.P4_y = P4_y;

		// 发射信号，将自定义结构作为参数传递给槽函数
		emit sendSquareCoordinates(coords);
		close();
	}
	else {
		// 文本转换失败
		QMessageBox::warning(this, "错误", "请输入有效的数值！", QMessageBox::Ok);
	}
}

void dialog::btn_cancel_clicked()
{
	close();//关闭窗口
}
