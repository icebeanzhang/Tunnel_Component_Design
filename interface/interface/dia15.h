#pragma execution_character_set("UTF-8")
#ifndef DIA15_H
#define DIA15_H

#include <QWidget>

namespace Ui {
	class dia15;
}

class dia15 : public QWidget
{
	Q_OBJECT

public:
	explicit dia15(QWidget *parent = nullptr);
	~dia15();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

private:
	Ui::dia15 *ui;
};

#endif // DIA15_H
