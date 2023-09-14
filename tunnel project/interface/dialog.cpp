#include "dialog.h"
#include "ui_dialog.h"
#include <QDialog>
#include "mainwindow.h"
#include <qmessagebox.h>
#include <qtextcodec.h>
#include <QLineEdit>

dialog::dialog(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::dialog)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par1()), this, SLOT(show()));

	//����ȷ����ȡ��
	connect(ui->btn1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

dialog::~dialog()
{
	delete ui;
}

void dialog::btn_verify_clicked()
{
	// ��ȡ�ı��༭���е�����
	QString text1 = ui->textEdit_3->toPlainText();
	QString text2 = ui->textEdit_4->toPlainText();

	// ���ı�ת��Ϊ��ֵ���ͽ��м���
	bool ok1, ok2;
	double P1_x = text1.toDouble(&ok1);
	double P1_y = text2.toDouble(&ok2);

	if (ok1 && ok2) {
		// ���м���
		double P2_x = P1_x;
		double P2_y = P1_y + 50;
		double P3_x = P1_x + 50;
		double P3_y = P2_y;
		double P4_x = P3_x;
		double P4_y = P1_y;

		// ��������ַ���
		QString output1 = QString("P2���꣺(%1, %2)").arg(P2_x).arg(P2_y);
		QString output2 = QString("P3���꣺(%1, %2)").arg(P3_x).arg(P3_y);
		QString output3 = QString("P4���꣺(%1, %2)").arg(P4_x).arg(P4_y);

		QString finalOutput = output1 + "\n" + output2 + "\n" + output3;

		// ��ʾ������
		QMessageBox::information(this, "������", finalOutput, QMessageBox::Ok);
		SquareCoordinates coords;
		coords.P1_x = P1_x;
		coords.P1_y = P1_y;
		coords.P2_x = P2_x;
		coords.P2_y = P2_y;
		coords.P3_x = P3_x;
		coords.P3_y = P3_y;
		coords.P4_x = P4_x;
		coords.P4_y = P4_y;

		// �����źţ����Զ���ṹ��Ϊ�������ݸ��ۺ���
		emit sendSquareCoordinates(coords);
		close();
	}
	else {
		// �ı�ת��ʧ��
		QMessageBox::warning(this, "����", "��������Ч����ֵ��", QMessageBox::Ok);
	}
}

void dialog::btn_cancel_clicked()
{
	close();//�رմ���
}
