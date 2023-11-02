#ifndef OCCWIDGET_H
#define OCCWIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <AIS_InteractiveContext.hxx>

namespace Ui {
class OCCWidget;
}

class OCCWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OCCWidget(QWidget *parent = nullptr);
    ~OCCWidget();

	const Handle(AIS_InteractiveContext)& getContext() const;

private:
    Ui::OCCWidget *ui;
	OCCWidget* myOccWidget;

	//! the occ context.
	Handle(AIS_InteractiveContext) myContext;

	void makeLine();
};

#endif // OCCWIDGET_H
