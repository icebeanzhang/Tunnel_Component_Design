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
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

private:
	Ui::dia14 *ui;
};

#endif // DIA14_H
