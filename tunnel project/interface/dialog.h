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
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

signals:
	void par_view1();
	// 发射带有 SquareCoordinates 参数的信号
	void sendSquareCoordinates(const SquareCoordinates& coords);

private:
	Ui::dialog *ui;

};

#endif // DIALOG_H
