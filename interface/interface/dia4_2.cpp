#include "dia4_2.h"
#include "ui_dia4_2.h"
#include <QDialog>
#include "mainwindow.h"

dia4_2::dia4_2(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia4_2)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par4_2()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn4_2_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn4_2_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia4_2::~dia4_2()
{
	delete ui;
}

void dia4_2::btn_verify_clicked()
{
	//传输数据
}

void dia4_2::btn_cancel_clicked()
{
	close();//关闭窗口
}

