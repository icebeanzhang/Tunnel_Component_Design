#include "FirstSuppSprayMix.h"
#include "ui_FirstSuppSprayMix.h"
#include <QDialog>
#include <qmessagebox.h>
#include "mainwindow.h"
#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Pln.hxx>
#include <gp_Ax3.hxx>
#include <Geom2d_Circle.hxx>
#include <gp_Lin2d.hxx>
#include <gp_XYZ.hxx>
#include <Geom_Circle.hxx>
#include <GC_MakeArcOfCircle.hxx>
#include <Geom_ConicalSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_Line.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <GeomAPI_IntCS.hxx>
#include <Geom_SurfaceOfLinearExtrusion.hxx>
#include <Geom2dAPI_InterCurveCurve.hxx>
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
#include <BRepOffsetAPI_MakeThickSolid.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <BRepPrimAPI_MakePrism.hxx>
#include <BRepPrimAPI_MakeRevol.hxx>
#include <BRepAlgoAPI_Cut.hxx>
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
#include <AIS_Circle.hxx>
FirstSuppSprayMix::FirstSuppSprayMix(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::FirstSuppSprayMix)
{
	ui->setupUi(this);
	connect(parent, SIGNAL(par4_1()), this, SLOT(show()));
	//����ȷ����ȡ��
	connect(ui->btn4_1_1, SIGNAL(clicked()), this, SLOT(btn_verify_clicked()));
	connect(ui->btn4_1_2, SIGNAL(clicked()), this, SLOT(btn_cancel_clicked()));

}

FirstSuppSprayMix::~FirstSuppSprayMix()
{
	delete ui;
}

void FirstSuppSprayMix::btn_verify_clicked()
{
	//��������
	QString text1 = ui->firstSurppWall_Thick->toPlainText();
	QString text2 = ui->invertedArch_Thick->toPlainText();
	QString text3 = ui->line1AndCent_Distance->toPlainText();
	QString text4 = ui->line1AndLine2_Distance->toPlainText();
	QString text5 = ui->cirConnn_Thick->toPlainText();
	QString text6 = ui->arch_Angle->toPlainText();
	QString text7 = ui->archAnch_Distance->toPlainText();
	QString text8 = ui->wallAnch_Distance->toPlainText();
	// ���ı�ת��Ϊ��ֵ���ͽ��м���
	bool ok1, ok2,ok3,ok4,ok5, ok6, ok7, ok8;
	double firstSurppWall_Thick = text1.toDouble(&ok1);
	double invertedArch_Thick = text2.toDouble(&ok2);
	double line1AndCent_Distance = text3.toDouble(&ok3);
	double line1AndLine2_Distance = text4.toDouble(&ok4);
	double cirConnn_Thick = text5.toDouble(&ok5);
	double arch_Angle = text6.toDouble(&ok6);
	double archAnch_Distance = text7.toDouble(&ok7);
	double wallAnch_Distance = text8.toDouble(&ok8);


	if (ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8) {
		// ���м���
		//������������Լ��뾶����coords�У������ź���ʽ����ȥ
		SquareCoordinates2 coords;
		coords.P1_x = firstSurppWall_Thick;
		coords.P1_y = 0;
		coords.P2_x = invertedArch_Thick;
		coords.P2_y = 0;
		coords.P3_x = line1AndCent_Distance;
		coords.P3_y = 0;//��ǽ������
		coords.P4_x = line1AndLine2_Distance;
		coords.P4_y = 0;
		coords.P5_x = cirConnn_Thick;
		coords.P5_y = 0;//�Ҳ����߶�
		coords.P6_x = arch_Angle;
		coords.P6_y = 0;
		coords.P7_x = archAnch_Distance;
		coords.P7_y = 0;//������߶�
		coords.P8_x = wallAnch_Distance;
		coords.P8_y = 0;
		//�Ҳ�����Բ
		// �����źţ����Զ���ṹ��Ϊ�������ݸ��ۺ���
		emit sendSquareCoordinatesf(coords);
		close();
	}
	else {
		// �ı�ת��ʧ��
		QMessageBox::warning(this, "����", "��������Ч����ֵ��", QMessageBox::Ok);
	}
}

void FirstSuppSprayMix::btn_cancel_clicked()
{
	close();//�رմ���
}

