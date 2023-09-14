#include "dia14.h"
#include "ui_dia14.h"
#include <QDialog>
#include "mainwindow.h"

dia14::dia14(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia14)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par14()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn14_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn14_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia14::~dia14()
{
	delete ui;
}

void dia14::btn_verify_clicked()
{
	//传输数据
}

void dia14::btn_cancel_clicked()
{
	close();//关闭窗口
}

