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
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

private:
	Ui::dia12 *ui;
};

#endif // DIA12_H
