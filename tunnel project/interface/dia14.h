#pragma execution_character_set("UTF-8")
#ifndef DIA14_H
#define DIA14_H

#include <QWidget>

namespace Ui {
	class dia14;
}

class dia14 : public QWidget
{
	Q_OBJECT

public:
	explicit dia14(QWidget *parent = nullptr);
	~dia14();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

private:
	Ui::dia14 *ui;
};

#endif // DIA14_H
