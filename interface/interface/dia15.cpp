#include "dia15.h"
#include "ui_dia15.h"
#include <QDialog>
#include "mainwindow.h"

dia15::dia15(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia15)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par15()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn15_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn15_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia15::~dia15()
{
	delete ui;
}

void dia15::btn_verify_clicked()
{
	//传输数据
}

void dia15::btn_cancel_clicked()
{
	close();//关闭窗口
}

