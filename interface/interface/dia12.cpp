#include "dia12.h"
#include "ui_dia12.h"
#include <QDialog>
#include "mainwindow.h"

dia12::dia12(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia12)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par12()), this, SLOT(show()));
	//����ȷ����ȡ��
	connect(ui->btn12_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn12_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia12::~dia12()
{
	delete ui;
}

void dia12::btn_verify_clicked()
{
	//��������
}

void dia12::btn_cancel_clicked()
{
	close();//�رմ���
}

