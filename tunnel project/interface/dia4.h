#ifndef DIA4_H
#define DIA4_H

#include <QWidget>

namespace Ui {
	class dia4;
}

class dia4 : public QWidget
{
	Q_OBJECT

public:
	explicit dia4(QWidget *parent = nullptr);
	~dia4();

	public slots:
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

private:
	Ui::dia4 *ui;
};

#endif // DIA4_H
