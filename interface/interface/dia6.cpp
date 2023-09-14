#include "dia6.h"
#include "ui_dia6.h"
#include <QDialog>
#include "mainwindow.h"

dia6::dia6(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia6)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par6()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn6_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn6_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia6::~dia6()
{
	delete ui;
}

void dia6::btn_verify_clicked()
{
	//传输数据
}

void dia6::btn_cancel_clicked()
{
	close();//关闭窗口
}

