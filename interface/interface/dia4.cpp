#include "dia4.h"
#include "ui_dia4.h"
#include <QDialog>
#include "mainwindow.h"

dia4::dia4(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia4)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par4()), this, SLOT(show()));
	//����ȷ����ȡ��
	connect(ui->btn4_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn4_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia4::~dia4()
{
	delete ui;
}

void dia4::btn_verify_clicked()
{
	//��������
}

void dia4::btn_cancel_clicked()
{
	close();//�رմ���
}

