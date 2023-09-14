#include "dia11.h"
#include "ui_dia11.h"
#include <QDialog>
#include "mainwindow.h"

dia11::dia11(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia11)
{
	ui->setupUi(this);

	connect(parent, SIGNAL(par11()), this, SLOT(show()));
	//链接确认与取消
	connect(ui->btn11_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn11_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

	//connect(this, SIGNAL(par_view11()), parent, SLOT(makeLine()));
}

dia11::~dia11()
{
	delete ui;
}

void dia11::btn_verify_clicked()
{
	//传输数据
	emit par_view11();
	close();
}

void dia11::btn_cancel_clicked()
{
	close();//关闭窗口
}

