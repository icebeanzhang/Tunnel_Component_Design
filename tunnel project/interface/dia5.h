#ifndef DIA5_H
#define DIA5_H

#include <QWidget>

namespace Ui {
	class dia5;
}

class dia5 : public QWidget
{
	Q_OBJECT

public:
	explicit dia5(QWidget *parent = nullptr);
	~dia5();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

private:
	Ui::dia5 *ui;
};

#endif // DIA5_H
