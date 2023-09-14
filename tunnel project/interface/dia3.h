#ifndef DIA3_H
#define DIA3_H

#include <QWidget>

namespace Ui {
	class dia3;
}

class dia3 : public QWidget
{
	Q_OBJECT

public:
	explicit dia3(QWidget *parent = nullptr);
	~dia3();

	public slots:
	void btn_verify_clicked(); //重置按钮按下后触发的事件
	void btn_cancel_clicked(); //登录按钮按下后触发的事件

private:
	Ui::dia3 *ui;
};

#endif // DIA3_H
