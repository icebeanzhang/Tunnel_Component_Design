#pragma execution_character_set("UTF-8")
#ifndef DIA12_1_H
#define DIA12_1_H

#include <QWidget>

namespace Ui {
	class dia12_1;
}

class dia12_1 : public QWidget
{
	Q_OBJECT

public:
	explicit dia12_1(QWidget *parent = nullptr);
	~dia12_1();

	public slots:
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

private:
	Ui::dia12_1 *ui;
};

#endif // DIA12_1_H
