#include "dia5.h"
#include "ui_dia5.h"
#include <QDialog>
#include "mainwindow.h"

dia5::dia5(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia5)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par5()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn5_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn5_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia5::~dia5()
{
	delete ui;
}

void dia5::btn_verify_clicked()
{
	//传输数据
}

void dia5::btn_cancel_clicked()
{
	close();//关闭窗口
}

