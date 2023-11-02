#pragma execution_character_set("UTF-8")
#ifndef DIALOG_H
#define DIALOG_H

#include <QWidget>

namespace Ui {
	class dialog;
}

struct SquareCoordinates {
	double P1_x;
	double P1_y;
	double P2_x;
	double P2_y;
	double P3_x;
	double P3_y;
	double P4_x;
	double P4_y;
};

class dialog : public QWidget
{
	Q_OBJECT

public:
	explicit dialog(QWidget *parent = nullptr);
	~dialog();

	public slots:
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

signals:
	void par_view1();
	// ������� SquareCoordinates �������ź�
	void sendSquareCoordinates(const SquareCoordinates& coords);

private:
	Ui::dialog *ui;

};

#endif // DIALOG_H
