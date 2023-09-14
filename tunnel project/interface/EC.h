#ifndef EC_H
#define EC_H

#include <QWidget>

namespace Ui {
	class EC;
}

struct Erchen {
	double E1;
	double E2;
	double E3;
	double E4;
	double E5;
	double E6;
	double E7;
	double E8;

};


class EC : public QWidget
{
	Q_OBJECT

public:
	explicit EC(QWidget *parent = nullptr);
	~EC();

	public slots:
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

signals:
	void par_view_Erchen();
	// ������� SquareCoordinates �������ź�
	void sendErchen(const Erchen& coords);



private:
	Ui::EC *ui;
};

#endif // DIA3_H
