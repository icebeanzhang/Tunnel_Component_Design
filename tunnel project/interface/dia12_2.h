#pragma execution_character_set("UTF-8")
#ifndef DIA12_2_H
#define DIA12_2_H

#include <QWidget>

namespace Ui {
	class dia12_2;
}

class dia12_2 : public QWidget
{
	Q_OBJECT

public:
	explicit dia12_2(QWidget *parent = nullptr);
	~dia12_2();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

private:
	Ui::dia12_2 *ui;
};

#endif // DIA12_2_H
