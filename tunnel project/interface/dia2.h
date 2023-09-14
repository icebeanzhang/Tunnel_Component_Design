#ifndef DIA2_H
#define DIA2_H

#include <QWidget>

namespace Ui {
	class dia2;
}

class dia2 : public QWidget
{
	Q_OBJECT

public:
	explicit dia2(QWidget *parent = nullptr);
	~dia2();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

private:
	Ui::dia2 *ui;
};

#endif // DIA2_H
