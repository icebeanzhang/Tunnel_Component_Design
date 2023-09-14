#include "dia12_2.h"
#include "ui_dia12_2.h"
#include <QDialog>
#include "mainwindow.h"

dia12_2::dia12_2(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia12_2)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par12_2()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn12_2_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn12_2_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia12_2::~dia12_2()
{
	delete ui;
}

void dia12_2::btn_verify_clicked()
{
	//传输数据
}

void dia12_2::btn_cancel_clicked()
{
	close();//关闭窗口
}

