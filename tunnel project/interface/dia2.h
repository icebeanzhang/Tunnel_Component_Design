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
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

private:
	Ui::dia2 *ui;
};

#endif // DIA2_H
