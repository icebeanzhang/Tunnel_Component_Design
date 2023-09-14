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
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

signals:
	void par_view_CenterGroove();
	// 发射带有 SquareCoordinates 参数的信号
	void sendCenterGrooveCoordinates(const CenterGrooveCoordinates& coords);

private:
	Ui::CenterGroove *ui;
};

#endif // DIA2_1_H
