#ifndef DIA4_2_H
#define DIA4_2_H

#include <QWidget>

namespace Ui {
	class dia4_2;
}

class dia4_2 : public QWidget
{
	Q_OBJECT

public:
	explicit dia4_2(QWidget *parent = nullptr);
	~dia4_2();

	public slots:
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

private:
	Ui::dia4_2 *ui;
};

#endif // DIA4_2_H
