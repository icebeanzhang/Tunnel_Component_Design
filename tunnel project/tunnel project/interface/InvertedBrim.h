#pragma execution_character_set("UTF-8")
#ifndef InvertedBrim_H
#define InvertedBrim_H

#include <QWidget>

namespace Ui {
	class InvertedBrim;
}
struct InvertedBrim2 {
	double P1_x;

	double P2_x;

	double P3_x;

	double P4_x;
	double P5_x;

};
class InvertedBrim : public QWidget
{
	Q_OBJECT

public:
	explicit InvertedBrim(QWidget *parent = nullptr);
	~InvertedBrim();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

private:
	Ui::InvertedBrim *ui;
signals:
	void sendInvertedBrimCoordinatesf(const InvertedBrim2& coords);
};

#endif // InvertedBrim_H
