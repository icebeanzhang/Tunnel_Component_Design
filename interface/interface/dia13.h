#pragma execution_character_set("UTF-8")
#ifndef DIA13_H
#define DIA13_H

#include <QWidget>

namespace Ui {
	class dia13;
}

class dia13 : public QWidget
{
	Q_OBJECT

public:
	explicit dia13(QWidget *parent = nullptr);
	~dia13();

	public slots:
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

private:
	Ui::dia13 *ui;
};

#endif // DIA13_H
