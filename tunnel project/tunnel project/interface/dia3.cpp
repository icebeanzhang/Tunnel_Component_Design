#include "dia3.h"
#include "ui_dia3.h"
#include <QDialog>
#include "mainwindow.h"

dia3::dia3(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dia3)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par3()), this, SLOT(show()));
	//����ȷ����ȡ��
	connect(ui->btn3_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn3_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dia3::~dia3()
{
	delete ui;
}

void dia3::btn_verify_clicked()
{
	//��������
}

void dia3::btn_cancel_clicked()
{
	close();//�رմ���
}

