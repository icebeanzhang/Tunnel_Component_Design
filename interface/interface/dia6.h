#ifndef DIA6_H
#define DIA6_H

#include <QWidget>

namespace Ui {
	class dia6;
}

class dia6 : public QWidget
{
	Q_OBJECT

public:
	explicit dia6(QWidget *parent = nullptr);
	~dia6();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

private:
	Ui::dia6 *ui;
};

#endif // DIA6_H
