#ifndef DIA12_H
#define DIA12_H

#include <QWidget>

namespace Ui {
	class dia12;
}

class dia12 : public QWidget
{
	Q_OBJECT

public:
	explicit dia12(QWidget *parent = nullptr);
	~dia12();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

private:
	Ui::dia12 *ui;
};

#endif // DIA12_H
