#include "occwidget.h"
#include "ui_occwidget.h"
#include "occview.h"
#include <qwidget.h>

#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Pln.hxx>
#include <gp_Ax3.hxx>

#include <gp_Lin2d.hxx>

#include <Geom_ConicalSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_TrimmedCurve.hxx>

#include <GCE2d_MakeSegment.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <GC_MakeSegment.hxx>

#include <TopoDS.hxx>
#include <TopExp.hxx>
#include <TopExp_Explorer.hxx>
#include <TColgp_Array1OfPnt2d.hxx>

#include <BRepLib.hxx>

#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_Transform.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>

#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>

#include <BRepFilletAPI_MakeFillet.hxx>
#include <BRepFilletAPI_MakeChamfer.hxx>

#include <BRepOffsetAPI_MakePipe.hxx>
#include <BRepOffsetAPI_ThruSections.hxx>

#include <BRepAlgoAPI_Cut.hxx>
#include <BRepAlgoAPI_Fuse.hxx>
#include <BRepAlgoAPI_Common.hxx>

#include <AIS_Shape.hxx>
#include <AIS_TextLabel.hxx>
#include <AIS_ColoredShape.hxx>

#include <QHBoxLayout>

OCCWidget::OCCWidget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::OCCWidget)
{
	ui->setupUi(this);

	

}

OCCWidget::~OCCWidget()
{
    delete ui;
}

void OCCWidget::makeLine()
{
	gp_Ax2 anAxis;
	anAxis.SetLocation(gp_Pnt(0.0, 0.0, 0.0));

	// »­Ïß
	gp_Pnt aPnt1(0, 100, 0);
	gp_Pnt aPnt2(100, 100, 0);

	TopoDS_Edge anEdgeP12 = BRepBuilderAPI_MakeEdge(aPnt1, aPnt2);
	Handle(AIS_Shape) anAisEdgeP12 = new AIS_Shape(anEdgeP12);

	myOccWidget->getContext()->Display(anAisEdgeP12, Standard_True);

	Handle(AIS_TextLabel) anAisEdgeP12Label = new AIS_TextLabel();
	anAisEdgeP12Label->SetText("Edge between two points");
	anAisEdgeP12Label->SetPosition(0.5 * (aPnt1.XYZ() + aPnt2.XYZ()));
	anAisEdgeP12Label->SetColor(Quantity_Color(Quantity_NOC_YELLOW));

	myOccWidget->getContext()->Display(anAisEdgeP12Label, Standard_True);
}

const Handle(AIS_InteractiveContext)& OCCWidget::getContext() const
{
	return myContext;
}