#include "InvertedBrim.h"
#include "ui_InvertedBrim.h"
#include <QDialog>
#include "mainwindow.h"
#include <QMessageBox>


InvertedBrim::InvertedBrim(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::InvertedBrim)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par15()), this, SLOT(show()));
	//����ȷ����ȡ��
	connect(ui->btn15_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn15_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

InvertedBrim::~InvertedBrim()
{
	delete ui;
}

void InvertedBrim::btn_verify_clicked()
{
	//��������

	//��������
	QString text1 = ui->textEdit_1->toPlainText();
	QString text2 = ui->textEdit_2->toPlainText();
	QString text3 = ui->textEdit_3->toPlainText();
	QString text4 = ui->textEdit_4->toPlainText();
	QString text5 = ui->textEdit_5->toPlainText();


	// ���ı�ת��Ϊ��ֵ���ͽ��м���
	bool ok1, ok2, ok3, ok4, ok5;
	double firstSurppWall_Thick = text1.toDouble(&ok1);
	double invertedArch_Thick = text2.toDouble(&ok2);
	double line1AndCent_Distance = text3.toDouble(&ok3);
	double line1AndLine2_Distance = text4.toDouble(&ok4);
	double cirConnn_Thick = text5.toDouble(&ok5);



	if (ok1 && ok2 && ok3 && ok4 && ok5) {
		// ���м���
		//������������Լ��뾶����coords�У������ź���ʽ����ȥ
		InvertedBrim2 coords;
		coords.P1_x = firstSurppWall_Thick;
		coords.P2_x = invertedArch_Thick;

		coords.P3_x = line1AndCent_Distance;

		coords.P4_x = line1AndLine2_Distance;
		coords.P5_x = cirConnn_Thick;


		//�Ҳ�����Բ
		// �����źţ����Զ���ṹ��Ϊ�������ݸ��ۺ���
		emit sendInvertedBrimCoordinatesf(coords);
		close();
	}
	else {
		// �ı�ת��ʧ��
		QMessageBox::warning(this, "����", "��������Ч����ֵ��", QMessageBox::Ok);
	}


}

void InvertedBrim::btn_cancel_clicked()
{
	close();//�رմ���
}

