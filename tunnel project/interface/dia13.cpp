#include "dia13.h"
#include "ui_dia13.h"
#include <QDialog>
#include "mainwindow.h"

dia13::dia13(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia13)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par13()), this, SLOT(show()));
	//����ȷ����ȡ��
	connect(ui->btn13_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn13_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia13::~dia13()
{
	delete ui;
}

void dia13::btn_verify_clicked()
{
	//��������
}

void dia13::btn_cancel_clicked()
{
	close();//�رմ���
}

