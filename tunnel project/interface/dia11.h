#ifndef DIA11_H
#define DIA11_H

#include <QWidget>

namespace Ui {
	class dia11;
}

class dia11 : public QWidget
{
	Q_OBJECT

public:
	explicit dia11(QWidget *parent = nullptr);
	~dia11();

public slots:
	void btn_verify_clicked(); //���ð�ť���º󴥷����¼�
	void btn_cancel_clicked(); //��¼��ť���º󴥷����¼�

signals:
	void par_view11();

private:
	Ui::dia11 *ui;
};

#endif // DIA11_H
