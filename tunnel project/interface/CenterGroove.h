#ifndef CENTERGROOVE_H
#define CENTERGROOVE_H

#include <QWidget>

namespace Ui {
	class CenterGroove;
}

struct CenterGrooveCoordinates {
	double P1;
	double P2_x;
	double P2_y;
	double P3_x;
	double P3_y;
	double P4_x;
	double P4_y;

};

class CenterGroove : public QWidget
{
	Q_OBJECT

public:
	explicit CenterGroove(QWidget *parent = nullptr);
	~CenterGroove();

	public slots:
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

signals:
	void par_view_CenterGroove();
	// ������� SquareCoordinates �������ź�
	void sendCenterGrooveCoordinates(const CenterGrooveCoordinates& coords);

private:
	Ui::CenterGroove *ui;
};

#endif // DIA2_1_H
