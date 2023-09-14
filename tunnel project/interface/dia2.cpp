#include "dia2.h"
#include "ui_dia2.h"
#include <QDialog>
#include "mainwindow.h"

dia2::dia2(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia2)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par2()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn2_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn2_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia2::~dia2()
{
	delete ui;
}

void dia2::btn_verify_clicked()
{
	//传输数据
}

void dia2::btn_cancel_clicked()
{
	close();//关闭窗口
}

