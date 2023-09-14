#ifndef FirstSuppSprayMix_H
#define FirstSuppSprayMix_H

#include <QWidget>

namespace Ui {
	class FirstSuppSprayMix;
}
struct SquareCoordinates2 {
	double P1_x;
	double P1_y;
	double P2_x;
	double P2_y;
	double P3_x;
	double P3_y;
	double P4_x;
	double P4_y;
	double P5_x;
	double P5_y;
	double P6_x;
	double P6_y;
	double P7_x;
	double P7_y;
	double P8_x;
	double P8_y;
	double P9_x;
	double P9_y;
	double P10_x;
	double P10_y;
	double P11_x;
	double P11_y;
	double P12_x;
	double P12_y;
	double P13_x;
	double P13_y;
	double P14_x;
	double P14_y;
	double P15_x;
	double P15_y;
	double P16_x;
	double P16_y;
};
class FirstSuppSprayMix : public QWidget
{
	Q_OBJECT

public:
	explicit FirstSuppSprayMix(QWidget *parent = nullptr);
	~FirstSuppSprayMix();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件
signals:
	void par_view1();
	// 发射带有 SquareCoordinates 参数的信号
	void sendSquareCoordinatesf(  const SquareCoordinates2& coords);

private:
	Ui::FirstSuppSprayMix *ui;
};

#endif // FirstSuppSprayMix_H
