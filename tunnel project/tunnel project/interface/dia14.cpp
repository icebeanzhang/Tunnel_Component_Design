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
	//����ȷ����ȡ��
	connect(ui->btn14_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn14_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia14::~dia14()
{
	delete ui;
}

void dia14::btn_verify_clicked()
{
	//��������
}

void dia14::btn_cancel_clicked()
{
	close();//�رմ���
}

