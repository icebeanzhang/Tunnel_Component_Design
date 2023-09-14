#ifndef SIDEGROOVE_H
#define SIDEGROOVE_H

#include <QWidget>

namespace Ui {
	class SideGroove;
}

struct SideGrooveCoordinates {
	double P1;
	double P2;
	double P3_x;
	double P3_y;
	double P4_x;
	double P4_y;
	double P5_x;
	double P5_y;
	double P6_x;
	double P6_y;
	double P7;

};

class SideGroove : public QWidget
{
	Q_OBJECT

public:
	explicit SideGroove(QWidget *parent = nullptr);
	~SideGroove();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

signals:
	void par_view_sidegroove();
	// 发射带有 SquareCoordinates 参数的信号
	void sendSideGrooveCoordinates(const SideGrooveCoordinates& coords);

private:
	Ui::SideGroove *ui;
};

#endif // DIA2_2_H
