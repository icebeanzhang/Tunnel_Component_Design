#include "dia12_1.h"
#include "ui_dia12_1.h"
#include <QDialog>
#include "mainwindow.h"

dia12_1::dia12_1(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia12_1)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par12_1()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn12_1_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn12_1_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia12_1::~dia12_1()
{
	delete ui;
}

void dia12_1::btn_verify_clicked()
{
	//传输数据
}

void dia12_1::btn_cancel_clicked()
{
	close();//关闭窗口
}

