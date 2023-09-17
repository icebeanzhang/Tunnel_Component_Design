#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStandardItemModel>
#include "dialog.h"
#include "CenterGroove.h"
#include "FirstSuppSprayMix.h"
#include "SideGroove.h"
#include <QTreeWidgetItem>
#include <QMessageBox>
#include <QDialog>
#include <QDebug>
#include <QFormLayout>
#include <Standard.hxx>

#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Pln.hxx>
#include <gp_Ax3.hxx>

#include <gp_Lin2d.hxx>

#include <Geom_ConicalSurface.hxx>
#include <Geom_ToroidalSurface.hxx>
#include <Geom_CylindricalSurface.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_Circle.hxx>
#include <GeomAPI_IntCS.hxx>
#include <Geom_Curve.hxx>

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
#include <BRepBuilderAPI_GTransform.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>
#include <BRepAlgoAPI_Section.hxx>

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
#include <BRep_Tool.hxx>
#include <BRepAdaptor_Curve.hxx>

#include <AIS_Shape.hxx>
#include <AIS_TextLabel.hxx>
#include <AIS_ColoredShape.hxx>
#include <math.h>

#include <Geom_Line.hxx>



MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//���οؼ�����
	/*QTreeWidgetItem *parentItem1 = new QTreeWidgetItem(ui->tr2);
	parentItem1->setText(0, QString("������"));
	QTreeWidgetItem *parentItem2 = new QTreeWidgetItem(ui->tr2);
	parentItem2->setText(0, QString("����"));
	QTreeWidgetItem *parentItem3 = new QTreeWidgetItem(ui->tr2);
	parentItem3->setText(0, QString("����"));
	QTreeWidgetItem *parentItem4 = new QTreeWidgetItem(ui->tr2);
	parentItem4->setText(0, QString("������̤��"));
	QTreeWidgetItem *parentItem5 = new QTreeWidgetItem(ui->tr2);
	parentItem5->setText(0, QString("��֧"));
	QTreeWidgetItem *parentItem6 = new QTreeWidgetItem(ui->tr2);
	parentItem6->setText(0, QString("����ˮ"));*/
	QTreeWidgetItem *parentItem1 = new QTreeWidgetItem(ui->tr2);
	parentItem1->setText(0, QString("������������"));
	QTreeWidgetItem *parentItem2 = new QTreeWidgetItem(ui->tr2);
	parentItem2->setText(0, QString("��֧"));
	QTreeWidgetItem *parentItem3 = new QTreeWidgetItem(ui->tr2);
	parentItem3->setText(0, QString("����̤��������"));
	QTreeWidgetItem *parentItem4 = new QTreeWidgetItem(ui->tr2);
	parentItem4->setText(0, QString("����ˮ"));
	

	/*QTreeWidgetItem *childItem1 = new QTreeWidgetItem(parentItem3);
	childItem1->setText(0, QString("���Ĺ�"));
	QTreeWidgetItem *childItem2 = new QTreeWidgetItem(parentItem3);
	childItem2->setText(0, QString("�๵"));
	QTreeWidgetItem *childItem4_1 = new QTreeWidgetItem(parentItem5);
	childItem4_1->setText(0, QString("��֧���"));
	QTreeWidgetItem *childItem4_2 = new QTreeWidgetItem(parentItem5);
	childItem4_2->setText(0, QString("�͸ָּ�"));*/

	/*QTreeWidgetItem *childItem1 = new QTreeWidgetItem(parentItem3);
	childItem1->setText(0, QString("���Ĺ�"));
	QTreeWidgetItem *childItem2 = new QTreeWidgetItem(parentItem3);
	childItem2->setText(0, QString("�๵"));
	QTreeWidgetItem *childItem4_1 = new QTreeWidgetItem(parentItem2);
	childItem4_1->setText(0, QString("��֧���"));
	QTreeWidgetItem *childItem4_2 = new QTreeWidgetItem(parentItem2);
	childItem4_2->setText(0, QString("�͸ָּ�"));*/

	QTreeWidgetItem *childItem3_1 = new QTreeWidgetItem(parentItem3);
	childItem3_1->setText(0, QString("���Ĺ�"));
	QTreeWidgetItem *childItem3_2 = new QTreeWidgetItem(parentItem3);
	childItem3_2->setText(0, QString("�๵"));
	QTreeWidgetItem *childItem2_1 = new QTreeWidgetItem(parentItem2);
	childItem2_1->setText(0, QString("��֧���"));
	QTreeWidgetItem *childItem2_2 = new QTreeWidgetItem(parentItem2);
	childItem2_2->setText(0, QString("�͸ָּ�"));

	QTreeWidgetItem *parentItem11 = new QTreeWidgetItem(ui->tr1);
	parentItem11->setText(0, QString("������"));
	QTreeWidgetItem *parentItem12 = new QTreeWidgetItem(ui->tr1);
	parentItem12->setText(0, QString("����"));
	QTreeWidgetItem *parentItem13 = new QTreeWidgetItem(ui->tr1);
	parentItem13->setText(0, QString("����"));
	QTreeWidgetItem *parentItem14 = new QTreeWidgetItem(ui->tr1);
	parentItem14->setText(0, QString("������̤��"));
	QTreeWidgetItem *parentItem15 = new QTreeWidgetItem(ui->tr1);
	parentItem15->setText(0, QString("����ʽñ��"));
	

	QTreeWidgetItem *childItem12_1 = new QTreeWidgetItem(parentItem12);
	childItem12_1->setText(0, QString("���Ĺ�"));
	QTreeWidgetItem *childItem12_2 = new QTreeWidgetItem(parentItem12);
	childItem12_2->setText(0, QString("�๵"));


	dia_1 = new dialog();
	dia_2 = new dia2();
	dia_3 = new EC();
	dia_4 = new dia4();
	dia_5 = new dia5();
	dia_6 = new dia6();
	CenterGroove_1 = new CenterGroove();
	SideGroove_1 = new SideGroove();
	dia_4_1 = new FirstSuppSprayMix();
	dia_4_2 = new dia4_2();

	dia_11 = new dia11();
	dia_12 = new dia12();
	dia_13 = new dia13();
	dia_14 = new dia14();
	dia_15 = new dia15();
	dia_12_1 = new dia12_1();
	dia_12_2 = new dia12_2();

	//�������οؼ����·������Ĳ���
	connect(ui->tr1, &QTreeWidget::itemClicked, this, &MainWindow::onTreeWidgetItemClicked1);
	connect(ui->tr2, &QTreeWidget::itemClicked, this, &MainWindow::onTreeWidgetItemClicked2);

	////�����źź�dia����
	//connect(this, SIGNAL(par1()), dia_1, SLOT(show()));
	//connect(this, SIGNAL(par2()), dia_2, SLOT(show()));
	//connect(this, SIGNAL(par3()), dia_3, SLOT(show()));
	//connect(this, SIGNAL(par4()), dia_4, SLOT(show()));
	//connect(this, SIGNAL(par5()), dia_5, SLOT(show()));
	//connect(this, SIGNAL(par6()), dia_6, SLOT(show()));
	//connect(this, SIGNAL(par2_1()), CenterGroove_1, SLOT(show()));
	//connect(this, SIGNAL(par2_2()), SideGroove_1, SLOT(show()));
	//connect(this, SIGNAL(par4_1()), dia_4_1, SLOT(show()));
	//connect(this, SIGNAL(par4_2()), dia_4_2, SLOT(show()));

	//�����źź�dia����
	connect(this, SIGNAL(par1()), dia_3, SLOT(show()));
	connect(this, SIGNAL(par2()), dia_4, SLOT(show()));
	connect(this, SIGNAL(par3()), dia_2, SLOT(show()));
	connect(this, SIGNAL(par4()), dia_5, SLOT(show()));
	connect(this, SIGNAL(par3_1()), CenterGroove_1, SLOT(show()));
	connect(this, SIGNAL(par3_2()), SideGroove_1, SLOT(show()));
	connect(this, SIGNAL(par2_1()), dia_4_1, SLOT(show()));
	connect(this, SIGNAL(par2_2()), dia_4_2, SLOT(show()));


	connect(this, SIGNAL(par11()), dia_11, SLOT(show()));
	connect(this, SIGNAL(par12()), dia_12, SLOT(show()));
	connect(this, SIGNAL(par13()), dia_13, SLOT(show()));
	connect(this, SIGNAL(par14()), dia_14, SLOT(show()));
	connect(this, SIGNAL(par15()), dia_15, SLOT(show()));
	connect(this, SIGNAL(par12_1()), dia_12_1, SLOT(show()));
	connect(this, SIGNAL(par12_2()), dia_12_2, SLOT(show()));


	myOccView = ui->OCCWid;
	//��occ��ʾ�������ڵײ����⸲�����οؼ�
	ui->tabWidget->raise();
	ui->OCCWid->lower();
	ui->OCCWid->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui->OCCWid->installEventFilter(ui->OCCWid);

	//��dia�е��ź����·���������
	//connect(dia_11, SIGNAL(par_view11()), this, SLOT(makeLine()));
	//connect(CenterGroove_1, SIGNAL(par_view_centergroove()), this, SLOT(makecentergroove()));
	//connect(sidegroove_1, SIGNAL(par_view_sidegroove()), this, SLOT(makesidegroove()));
	// ���� dialog ������ź��뵱ǰ��Ĳۺ���
	connect(dia_1, SIGNAL(sendSquareCoordinates(const SquareCoordinates&)),
		this, SLOT(handleSquareCoordinates(const SquareCoordinates&)));
	connect(CenterGroove_1, SIGNAL(sendCenterGrooveCoordinates(const CenterGrooveCoordinates&)),
		this, SLOT(handleCenterGrooveCoordinates(const CenterGrooveCoordinates&)));
	connect(dia_4_1, SIGNAL(sendSquareCoordinatesf(const SquareCoordinates2&)),
		this, SLOT(showFirstSurpport(const SquareCoordinates2&)));
	//connect(SideGroove_1, SIGNAL(sendSideGrooveCoordinates(const SideGrooveCoordinates&)),
		//this, SLOT(handleSideGrooveCoordinates(const SideGrooveCoordinates&)));
	connect(dia_3, SIGNAL(sendErchen(const Erchen&)),
		this, SLOT(handleErchen(const Erchen&)));


	CompositeLining::SecondaryLining secondaryLiningObj;
}

MainWindow::~MainWindow()
{
	delete ui;
}
TopoDS_Shape CopyAndTranslateShape(const TopoDS_Shape& shape, const gp_Vec& translation)
{
	gp_Trsf translationTransform;
	translationTransform.SetTranslation(translation);

	BRepBuilderAPI_Transform transformMaker(shape, translationTransform);
	return transformMaker.Shape();
}

void MainWindow::handleCenterGrooveCoordinates(const CenterGrooveCoordinates& coords)
{
	// ���� makeTabu() ������������ SquareCoordinates �ṹ���������
	makeLine(coords);
}

void MainWindow::makeLine(const CenterGrooveCoordinates& coords)
{
	// ����Բ��Ϊ���Ĵ����ԳƱ任
	gp_Trsf mirrorTransform_GC;
	mirrorTransform_GC.SetMirror(gp_Ax2(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(1.0, 0.0, 0.0))); // �� Y ��Գ�

	gp_Ax2 anAxis_GC; // ��ʾ����ϵ���࣬���Զ�������ϵ��ԭ��ͷ���
	anAxis_GC.SetLocation(gp_Pnt(0.0, 0.0, 0.0)); // ��������ϵ��ԭ�㣬���ｫԭ����������ά�ռ�� (0, 0, 0) 

												  // ������������
	gp_Pnt P2_GC(-250, -294.5, 0); // ���ĸǰ��ϱ��е� P2_GC
	gp_Pnt P2_GC_m(250, -294.5, 0); // ���ĸǰ��ϱ��е� P2_GC

	Standard_Real trackbed_leftdistance = 210.0; // �������浽��ˮ�۾���
												 //Standard_Real trackbed_slope = 0.02; // ���������¶�
	Standard_Real trackbed_slope = 0.02; // ���������¶�
	gp_Vec leftDirection_track_bed_GC(-trackbed_leftdistance, -trackbed_leftdistance * trackbed_slope, 0.0); // ����߶εķ�������
	gp_Pnt P3_GC = P2_GC.Translated(leftDirection_track_bed_GC); // ���������͵�
	gp_Pnt P3_GC_m(-P3_GC.X(), P3_GC.Y(), P3_GC.Z());

	Standard_Real trackbed_rightdistance = 200.0; // �������浽���ĸǰ��Ҳ����
												  // Standard_Real slope_track_bed_GC = 0.02; // ����������¶�
	gp_Vec rightDirection_track_bed_GC(trackbed_rightdistance, -trackbed_rightdistance*trackbed_slope, 0.0);  //�Ҳ��߶εķ�������
	gp_Pnt P4_GC = P2_GC.Translated(rightDirection_track_bed_GC); // �����Ҳ���͵�
	gp_Pnt P4_GC_m(-P4_GC.X(), P4_GC.Y(), P4_GC.Z());

																  // ����������������߶�
	TopoDS_Edge leftEdge_track_bed_GC = BRepBuilderAPI_MakeEdge(P2_GC, P3_GC);
	Handle(AIS_Shape) AisleftEdge_track_bed_GC = new AIS_Shape(leftEdge_track_bed_GC);

	// �������������Ҳ��߶�
	TopoDS_Edge rightEdge_track_bed_GC = BRepBuilderAPI_MakeEdge(P2_GC, P4_GC);
	Handle(AIS_Shape) AisrightEdge_track_bed_GC = new AIS_Shape(rightEdge_track_bed_GC);

	//Standard_Real P1_O1_Ydistance = P4_GC.Y(); // P1 �� P4 ����������ͬ

	Standard_Real P1_O1_Ydistance = coords.P1; // P1 �� P4 ����������ͬ


											   // �������Ĺ��ǰ�
	gp_Pnt P1_GC(0, -P1_O1_Ydistance, 0); //���Ĺ��ǰ���ϱ��е�

										 //Standard_Real centercover_Xlength = 70.0;  // ���Ĺ��ǰ�ĳ���
										 //Standard_Real centercover_Ylength = 8.0;    // ���Ĺ��ǰ�Ŀ��

	Standard_Real centercover_Xlength = coords.P2_x;  // ���Ĺ��ǰ�ĳ���
	Standard_Real centercover_Ylength = coords.P2_y;    // ���Ĺ��ǰ�Ŀ��

														// �������Ĺ��ǰ��ĸ��ǵ������
	gp_Pnt upperLeftPoint_center_cover_GC(P1_GC.X() - centercover_Xlength / 2.0, P1_GC.Y(), 0);
	gp_Pnt upperRightPoint_center_cover_GC(P1_GC.X() + centercover_Xlength / 2.0, P1_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_center_cover_GC(P1_GC.X() - centercover_Xlength / 2.0, P1_GC.Y() - centercover_Ylength, 0);
	gp_Pnt lowerRightPoint_center_cover_GC(P1_GC.X() + centercover_Xlength / 2.0, P1_GC.Y() - centercover_Ylength, 0);

	// �������Ĺ��ǰ��������
	BRepBuilderAPI_MakeWire wireMaker_center_cover_GC;
	wireMaker_center_cover_GC.Add(BRepBuilderAPI_MakeEdge(upperLeftPoint_center_cover_GC, upperRightPoint_center_cover_GC));
	wireMaker_center_cover_GC.Add(BRepBuilderAPI_MakeEdge(upperRightPoint_center_cover_GC, lowerRightPoint_center_cover_GC));
	wireMaker_center_cover_GC.Add(BRepBuilderAPI_MakeEdge(lowerRightPoint_center_cover_GC, lowerLeftPoint_center_cover_GC));
	wireMaker_center_cover_GC.Add(BRepBuilderAPI_MakeEdge(lowerLeftPoint_center_cover_GC, upperLeftPoint_center_cover_GC));
	wireMaker_center_cover_GC.Build();

	// �������Ĺ��ǰ�������
	BRepPrimAPI_MakeBox box_center_cover_GC(upperLeftPoint_center_cover_GC, centercover_Xlength, -centercover_Ylength, -70.0);

	// ��ȡ���Ĺ��ǰ�������
	TopoDS_Shape cubeShape_center_cover_GC = box_center_cover_GC.Shape();
	TopoDS_Solid cube_center_cover_GC = TopoDS::Solid(cubeShape_center_cover_GC);
	Handle(AIS_Shape) Aiscube_center_cover_GC = new AIS_Shape(cube_center_cover_GC);

	// ����Բ����ˮ��
	Standard_Real Drainage_radius = 5.0; // ��ˮ�۵İ뾶
	gp_Pnt leftpoint_Drainage_GC(P3_GC.X() - 2 * Drainage_radius, P3_GC.Y(), 0.0); // ��ˮ������
	gp_Pnt leftpoint_Drainage_GC_m(-P3_GC.X() + 2 * Drainage_radius, P3_GC.Y(), 0.0);
	gp_Pnt centerPoint_Drainage_GC(P3_GC.X() - Drainage_radius, P3_GC.Y(), 0.0); // ��ˮ��Բ��
	gp_Pnt centerPoint_Drainage_GC_m(-P3_GC.X() + Drainage_radius, P3_GC.Y(), 0.0);

	Standard_Real startAngle_Drainage_GC = M_PI;  // �°�Բ����ʼ�Ƕȣ�������
	Standard_Real endAngle_Drainage_GC = 2 * M_PI;  // �°�Բ�Ľ����Ƕȣ�������

	gp_Ax2 circleAxis_Drainage_GC(centerPoint_Drainage_GC, gp_Dir(0, 0, 1)); // ������ˮ�۵�����
	gp_Ax2 circleAxis_Drainage_GC_m(centerPoint_Drainage_GC_m, gp_Dir(0, 0, 1));
	gp_Circ circle_Drainage_GC(circleAxis_Drainage_GC, Drainage_radius); // ʹ�ö�������ߺͰ뾶����һ����ˮԲ
	gp_Circ circle_Drainage_GC_m(circleAxis_Drainage_GC_m, Drainage_radius);

	TopoDS_Edge arcEdge_Drainage_GC = BRepBuilderAPI_MakeEdge(circle_Drainage_GC, startAngle_Drainage_GC, endAngle_Drainage_GC); // ������ˮԲ���°�Բ��
	TopoDS_Edge arcEdge_Drainage_GC_m = BRepBuilderAPI_MakeEdge(circle_Drainage_GC_m, startAngle_Drainage_GC, endAngle_Drainage_GC); // ������ˮԲ���°�Բ��
	TopoDS_Edge Edge_Drainage_GC = BRepBuilderAPI_MakeEdge(P3_GC, leftpoint_Drainage_GC); // ������ˮԲ���㵽�Ҳ����߶�

	//������Բ���ıպ���
	BRepBuilderAPI_MakeWire makeWire_Drainage_GC; // ������Բ���ıպ��߶�
	makeWire_Drainage_GC.Add(arcEdge_Drainage_GC); // ���°�Բ����Ե��ӵ��պ��߶�
	makeWire_Drainage_GC.Add(Edge_Drainage_GC); // ����Բ���㵽�Ҳ����߶���ӵ��պ��߶�
	TopoDS_Wire sectorWire_Drainage_GC = makeWire_Drainage_GC.Wire(); // ��ȡ�պ��߶���Ϊ��Բ���ıպ���
	BRepBuilderAPI_MakeFace Round_Drainage_GC(sectorWire_Drainage_GC); // ���պ��߶�ת��Ϊ��Բ���պ���
	TopoDS_Face sectorRound_Drainage_GC = Round_Drainage_GC.Face(); // ��ȡ��Բ���պ���

	gp_Vec extrusionVec_Drainage_GC(0, 0, -70.0); // ���� Z �᷽������ 70 ����λ
	BRepPrimAPI_MakePrism makeRound_Drainage_GC(sectorRound_Drainage_GC, extrusionVec_Drainage_GC); // ʹ�ð�Բ���պ���������죬������ˮ��������
	TopoDS_Shape RoundShape_Drainage_GC = makeRound_Drainage_GC.Shape(); // ��ȡ��ˮ�����������״
	TopoDS_Solid Round_solid_Drainage_GC = TopoDS::Solid(RoundShape_Drainage_GC); // ����ˮ��������ת��Ϊʵ��
	Handle(AIS_Shape) AisRound_Drainage_GC = new AIS_Shape(Round_solid_Drainage_GC); // ����һ�����ӻ���������ʾ��ˮ��������

	////������������ཻ
	//gp_Pnt leftPoint(P3.X() - 2 * radius, P3.Y(), 0.0);
	//gp_Vec direction2(0.0, -1.0, 0.0);
	//gp_Lin line(leftPoint, direction2);
	////Handle(gp_Lin) linegp = new gp_Lin(line);

	//// ����Բ����
	//gp_Circ circle2(gp_Ax2(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(0.0, 0.0, 1.0)), 1.0);

	//// ����ֱ����Բ�Ľ���
	//GeomAPI_IntCS intersection(line, circle2);
	//if (intersection.IsDone() && intersection.NbPoints() > 0) {
	//	for (int i = 1; i <= intersection.NbPoints(); i++) {
	//		gp_Pnt intersectionPoint = intersection.Point(i);
	//		// ������
	//		// ...
	//	}
	//}

	// �������Ĺ���
	gp_Pnt P6_GC(0, -P1_O1_Ydistance - centercover_Ylength, 0); // ���Ĺ����ϱߵ��е�
															   //Standard_Real centergroove_Xlength = 60.0;  // ���Ĺ��۵ĳ���
															   //Standard_Real centergroove_Ylength = 80.0;   // ���Ĺ��۵Ŀ��

	Standard_Real centergroove_Xlength = coords.P3_x;  // ���Ĺ��۵ĳ���
	Standard_Real centergroove_Ylength = coords.P3_y;   // ���Ĺ��۵Ŀ��

														// �������Ĺ����ĸ��ǵ������
	gp_Pnt upperLeftPoint_center_GC(P6_GC.X() - centergroove_Xlength / 2.0, P6_GC.Y(), 0);
	gp_Pnt upperRightPoint_center_GC(P6_GC.X() + centergroove_Xlength / 2.0, P6_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_center_GC(P6_GC.X() - centergroove_Xlength / 2.0, P6_GC.Y() - centergroove_Ylength, 0);
	gp_Pnt lowerRightPoint_center_GC(P6_GC.X() + centergroove_Xlength / 2.0, P6_GC.Y() - centergroove_Ylength, 0);

	// �������Ĺ��۵������߶�
	BRepBuilderAPI_MakeWire wireMaker_center_GC;
	wireMaker_center_GC.Add(BRepBuilderAPI_MakeEdge(upperLeftPoint_center_GC, upperRightPoint_center_GC));
	wireMaker_center_GC.Add(BRepBuilderAPI_MakeEdge(upperRightPoint_center_GC, lowerRightPoint_center_GC));
	wireMaker_center_GC.Add(BRepBuilderAPI_MakeEdge(lowerRightPoint_center_GC, lowerLeftPoint_center_GC));
	wireMaker_center_GC.Add(BRepBuilderAPI_MakeEdge(lowerLeftPoint_center_GC, upperLeftPoint_center_GC));
	wireMaker_center_GC.Build();

	// �������Ĺ��۵ıպ���
	TopoDS_Wire rectangleWire_center_GC = wireMaker_center_GC.Wire(); // ת��Ϊ���Ĺ��۵ıպ���
	BRepBuilderAPI_MakeFace rectangle_center_GC(rectangleWire_center_GC);
	TopoDS_Face rectangleFace_center_GC = rectangle_center_GC.Face(); // ��ȡ���Ĺ��۱պ���
																	  //Handle(AIS_Shape) Aisrectangle_center_GC = new AIS_Shape(rectangleFace_center_GC);

																	  // �������Ĺ��۵�������
	gp_Vec extrusionVec_center_GC(0, 0, -70.0); // ���� Z �᷽������ 70 ����λ
	BRepPrimAPI_MakePrism makecube_center_GC(rectangleFace_center_GC, extrusionVec_center_GC);
	TopoDS_Shape cubeShape_center_GC = makecube_center_GC.Shape();
	TopoDS_Solid cube_center_GC = TopoDS::Solid(cubeShape_center_GC);
	Handle(AIS_Shape) Aiscube_center_GC = new AIS_Shape(cube_center_GC);

	//�������Ĺ��ۻ�������
	Standard_Real concrete_layer = 20;
	//Standard_Real centerconcrete_Xlength = centergroove_Xlength + 2 * concrete_layer;  // ���Ĺ��ۻ�������ĳ���
	//Standard_Real centerconcrete_Ylength = centergroove_Ylength + concrete_layer + centercover_Ylength + 5.0;   // ���Ĺ��ۻ�������Ŀ��

	Standard_Real centerconcrete_Xlength = coords.P4_x;  // ���Ĺ��ۻ�������ĳ���
	Standard_Real centerconcrete_Ylength = coords.P4_y;   // ���Ĺ��ۻ�������Ŀ��

														  // �������Ĺ��ۻ��������ĸ��ǵ������
	gp_Pnt upperLeftPoint_center_concrete_GC(P1_GC.X() - centerconcrete_Xlength / 2.0, P1_GC.Y(), 0);
	gp_Pnt upperRightPoint_center_concrete_GC(P1_GC.X() + centerconcrete_Xlength / 2.0, P1_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_center_concrete_GC(P1_GC.X() - centerconcrete_Xlength / 2.0, P1_GC.Y() - centerconcrete_Ylength, 0);
	gp_Pnt lowerRightPoint_center_concrete_GC(P1_GC.X() + centerconcrete_Xlength / 2.0, P1_GC.Y() - centerconcrete_Ylength, 0);

	// ���Ĺ��ۻ��������������
	BRepBuilderAPI_MakeWire wireMaker_center_concrete_GC;
	wireMaker_center_concrete_GC.Add(BRepBuilderAPI_MakeEdge(upperRightPoint_center_concrete_GC, lowerRightPoint_center_concrete_GC));
	wireMaker_center_concrete_GC.Add(BRepBuilderAPI_MakeEdge(lowerRightPoint_center_concrete_GC, lowerLeftPoint_center_concrete_GC));
	wireMaker_center_concrete_GC.Add(BRepBuilderAPI_MakeEdge(lowerLeftPoint_center_concrete_GC, upperLeftPoint_center_concrete_GC));
	wireMaker_center_concrete_GC.Add(BRepBuilderAPI_MakeEdge(upperLeftPoint_center_concrete_GC, upperRightPoint_center_concrete_GC));
	wireMaker_center_concrete_GC.Build();

	// �������Ĺ��ۻ�������ıպ���
	TopoDS_Wire rectangleWire_center_concrete_GC = wireMaker_center_concrete_GC.Wire();
	BRepBuilderAPI_MakeFace rectangle_center_concrete_GC(rectangleWire_center_concrete_GC);
	TopoDS_Face rectangleFace_center_concrete_GC = rectangle_center_concrete_GC.Face();
	//Handle(AIS_Shape) Aisrectangle_center_concrete_GC = new AIS_Shape(rectangleFace_center_concrete_GC);

	// �������Ĺ��ۻ��������������
	gp_Vec extrusionVec_center_concrete_GC(0, 0, -70.0); // ���� Z �᷽������ 70 ����λ
	BRepPrimAPI_MakePrism makecube_center_concrete_GC(rectangleFace_center_concrete_GC, extrusionVec_center_concrete_GC); //�������Ĺ��ۻ�������������
	TopoDS_Shape cubeShape_center_concrete_GC = makecube_center_concrete_GC.Shape();
	TopoDS_Solid cube_center_concrete_GC = TopoDS::Solid(cubeShape_center_concrete_GC);
	Handle(AIS_Shape) Aiscube_center_concrete_GC = new AIS_Shape(cube_center_concrete_GC);


	// ���Ĺ��ǰ�+��϶
	Standard_Real length_gover_gap_GC = centercover_Xlength + 2.0;  // ���Ĺ��ǰ�+��϶�ĳ���
	Standard_Real width_gover_gap_GC = centercover_Ylength;   // ���Ĺ��ǰ�+��϶�Ŀ��

	// �������Ĺ��ǰ�+��϶�ĸ��ǵ������
	gp_Pnt upperLeftPoint_gover_gap_GC(P1_GC.X() - length_gover_gap_GC / 2.0, P1_GC.Y(), 0);
	gp_Pnt upperRightPoint_gover_gap_GC(P1_GC.X() + length_gover_gap_GC / 2.0, P1_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_gover_gap_GC(P1_GC.X() - length_gover_gap_GC / 2.0, P1_GC.Y() - width_gover_gap_GC, 0);
	gp_Pnt lowerRightPoint_gover_gap_GC(P1_GC.X() + length_gover_gap_GC / 2.0, P1_GC.Y() - width_gover_gap_GC, 0);

	// �������Ĺ��ǰ�+��϶������
	BRepPrimAPI_MakeBox box_gover_gap_GC(upperLeftPoint_gover_gap_GC, length_gover_gap_GC, -width_gover_gap_GC, -70.0);

	// ��ȡ���������Ĺ��ǰ�+��϶������
	TopoDS_Shape cubeShape_gover_gap_GC = box_gover_gap_GC.Shape();
	TopoDS_Solid cube_gover_gap_GC = TopoDS::Solid(cubeShape_gover_gap_GC);
	Handle(AIS_Shape) Aiscube_gover_gap_GC = new AIS_Shape(cube_gover_gap_GC);


	//ʹ�ò�������õ����Ĺ��Ļ�������
	BRepAlgoAPI_Cut cut1_center_concrete_GC(cubeShape_center_concrete_GC, cubeShape_center_GC);
	TopoDS_Shape cubeShape1_center_concrete_GC = cut1_center_concrete_GC.Shape();
	BRepAlgoAPI_Cut cut2_center_concrete_GC(cubeShape1_center_concrete_GC, cubeShape_gover_gap_GC);
	cut2_center_concrete_GC.Build();
	Handle(AIS_Shape) Aiscut_center_concrete_GC = new AIS_Shape(cut2_center_concrete_GC);
	Aiscut_center_concrete_GC->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(Aiscut_center_concrete_GC, Standard_True);


	//// �������������ֵ�һЩ��
	//Standard_Real degrees_nlk = 18.0;   // �ǶȵĶȲ���
	//Standard_Real minutes_nlk = 40.0;   // �Ƕȵķֲ���
	//Standard_Real seconds_nlk = 18.0;   // �Ƕȵ��벿��
	Standard_Real trench_Overlength = 160.0;
	Standard_Real innercontour_trench_distance = 14.0;
	Standard_Real trenchcover_gap = 1.0;
	////Standard_Real trench_Overlength = 160.0;
	//Standard_Real angle_nlk = degrees_nlk + (minutes_nlk / 60.0) + (seconds_nlk / 3600.0);  // ���Ƕ�ת��Ϊ������ʾ
	//Standard_Real radians_nlk = angle_nlk * M_PI / 180.0;   // ���Ƕ�ת��Ϊ����

	Standard_Real alpha = secondaryLiningObj.getValue(5);
	Standard_Real radius6_N = secondaryLiningObj.getValue(6);
	Standard_Real CUT_O4_01X = secondaryLiningObj.getValue(7);
	Standard_Real CUT_O4_01Y = secondaryLiningObj.getValue(8);
	Standard_Real CUT_O4_01Z = secondaryLiningObj.getValue(9);
	Standard_Real CUT_O4_03X = secondaryLiningObj.getValue(10);
	Standard_Real CUT_O4_03Y = secondaryLiningObj.getValue(11);
	Standard_Real CUT_O4_03Z = secondaryLiningObj.getValue(12);
	Standard_Real CUT_O7_01X = secondaryLiningObj.getValue(13);
	Standard_Real CUT_O7_01Y = secondaryLiningObj.getValue(14);
	Standard_Real CUT_O7_01Z = secondaryLiningObj.getValue(15);
	Standard_Real CUT_O7_03X = secondaryLiningObj.getValue(16);
	Standard_Real CUT_O7_03Y = secondaryLiningObj.getValue(17);
	Standard_Real CUT_O7_03Z = secondaryLiningObj.getValue(18);
	Standard_Real radius4_N = secondaryLiningObj.getValue(19);
	Standard_Real point_P3Y = secondaryLiningObj.getValue(20);
	Standard_Real R1_NLK = secondaryLiningObj.getValue(22);
	Standard_Real radius3_N = secondaryLiningObj.getValue(23);


	//Standard_Real radians_nlk = asin(CUT_O4_01Y / CUT_O4_01X);

	//Standard_Real result_nlk = tan(radians_nlk);   // ���� tan ����
	//gp_Pnt P7_nlk(-630.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt P7m_nlk(630.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt P8_nlk(-615.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt s1_nlk(-616.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt s2_nlk(-470.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt s2_y_nlk(0.0, -630.0 * result_nlk, 0.0); // ��s2_nlk��x��ƽ������y���ϵĽ���
	//gp_Pnt s2_nlk_symmetry(470.0, -630.0 * result_nlk, 0.0); //s2_nlk����y��ԳƵ�


	gp_Pnt P7_nlk(CUT_O4_01X, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt P7m_nlk(-CUT_O4_01X, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt P8_nlk(CUT_O4_01X + innercontour_trench_distance + trenchcover_gap, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt s1_nlk(CUT_O4_01X + innercontour_trench_distance, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt s2_nlk(CUT_O4_01X + trench_Overlength, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt s2_y_nlk(0, CUT_O4_01Y, CUT_O4_01Z); // ��s2_nlk��x��ƽ������y���ϵĽ���
	gp_Pnt s2_nlk_symmetry(-CUT_O4_01X - trench_Overlength, CUT_O4_01Y, CUT_O4_01Z); //s2_nlk����y��ԳƵ�


																			  // ����һЩ��
	TopoDS_Edge Edge1_nlk = BRepBuilderAPI_MakeEdge(P7_nlk, s1_nlk);
	Handle(AIS_Shape) AisEdge1_nlk = new AIS_Shape(Edge1_nlk);
	TopoDS_Edge Edge2_nlk = BRepBuilderAPI_MakeEdge(s2_nlk, leftpoint_Drainage_GC);
	Handle(AIS_Shape) AisEdge2_nlk = new AIS_Shape(Edge2_nlk);

	//// ����������
	//gp_Pnt center_nlk(0, 0, 0); // Բ������
	//Standard_Real radius_nlk = sqrt(pow(630, 2) + pow(-CUT_O4_01Y, 2)); // Բ�İ뾶

	//// ������ʼ�ǶȺ���ֹ�Ƕȣ��Ի���Ϊ��λ��
	//Standard_Real startAngle_nlk = M_PI + radians_nlk;
	//Standard_Real endAngle_nlk = 2 * M_PI - radians_nlk;

	//gp_Ax2 circleAxis_nlk(center_nlk, gp_Dir(0, 0, 1));
	//gp_Circ circle_nlk(circleAxis_nlk, radius_nlk);

	//TopoDS_Edge arcEdge1_nlk = BRepBuilderAPI_MakeEdge(circle_nlk, startAngle_nlk, endAngle_nlk);
	//TopoDS_Edge arcEdge2_nlk = BRepBuilderAPI_MakeEdge(P7_nlk, P7m_nlk);
	/*TopoDS_Edge arcEdge3_nlk = BRepBuilderAPI_MakeEdge(P7m_nlk, center_nlk);
	BRepBuilderAPI_MakeWire arcmakeWire_nlk;
	arcmakeWire_nlk.Add(arcEdge1_nlk);
	arcmakeWire_nlk.Add(arcEdge2_nlk);*/

	// ����������
	gp_Pnt centerO4(-sin(alpha) * (R1_NLK - radius4_N), -cos(alpha) * (R1_NLK - radius4_N), 0.0);
	gp_Pnt centerO7(sin(alpha) * (R1_NLK - radius4_N), -cos(alpha) * (R1_NLK - radius4_N), 0.0);
	gp_Pnt CUT_O4_01(CUT_O4_01X, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt CUT_O4_03(CUT_O4_03X, CUT_O4_03Y, CUT_O4_03Z);
	gp_Pnt CUT_O7_01(CUT_O7_01X, CUT_O7_01Y, CUT_O7_01Z);
	gp_Pnt CUT_O7_03(CUT_O7_03X, CUT_O7_03Y, CUT_O7_03Z);
	gp_Pnt point_P3(0.0, point_P3Y, 0.0);
	//gp_Pnt point_P3(0.0, radius3 - R3_TC - GoucaoGaocha - height, 0.0);


	gp_Ax2 axis04_N(centerO4, gp_Vec(0.0, 0.0, 1.0));
	gp_Ax2 axis07_N(centerO7, gp_Vec(0.0, 0.0, 1.0));
	gp_Ax2 axisP3_N(point_P3, gp_Vec(0.0, 0.0, 1.0));
	gp_Ax2 axis01_N(gp_Pnt(0.0, 0.0, 0.0), gp_Vec(0.0, 0.0, 1.0));
	//gp_Ax2 axis03(pointP3, gp_Vec(0.0, 0.0, 1.0));
	gp_Circ Circle_O4_EC(axis04_N, radius4_N);
	gp_Circ Circle_O7_EC(axis07_N, radius4_N);
	gp_Circ Circle_P3_EC(axisP3_N, radius3_N);
	gp_Circ Circle_01_EC(axis01_N, R1_NLK);

	Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O4_EC, CUT_O4_01, CUT_O4_03, false);//�����������Բ��
	TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	Handle(Geom_TrimmedCurve) arcCurve_02 = GC_MakeArcOfCircle(Circle_O7_EC, CUT_O7_03, CUT_O7_01, false);//�����������Բ��
	TopoDS_Edge TarcCurve_02 = BRepBuilderAPI_MakeEdge(arcCurve_02);
	Handle(Geom_TrimmedCurve) arcCurve_03 = GC_MakeArcOfCircle(Circle_P3_EC, CUT_O4_03, CUT_O7_03, false);//�����������Բ��
	TopoDS_Edge TarcCurve_03 = BRepBuilderAPI_MakeEdge(arcCurve_03);
	/*Handle(AIS_Shape) AisTarcCurve_03 = new AIS_Shape(TarcCurve_03);
	AisTarcCurve_03->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(AisTarcCurve_03, Standard_True);*/
	

	TopoDS_Edge aEdge2_nlk = BRepBuilderAPI_MakeEdge(CUT_O4_01, CUT_O7_01);
	/*Handle(AIS_Shape) AisarcEdge2_nlk = new AIS_Shape(arcEdge2_nlk);
	AisarcEdge2_nlk->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(AisarcEdge2_nlk, Standard_True);*/
	//TopoDS_Edge arcEdge2_nlk = BRepBuilderAPI_MakeEdge(P7_nlk, P7m_nlk);
	//TopoDS_Edge arcEdge3_nlk = BRepBuilderAPI_MakeEdge(P7_nlk, CUT_O4_01);
	//TopoDS_Edge arcEdge4_nlk = BRepBuilderAPI_MakeEdge(CUT_O7_01, P7m_nlk);




	BRepBuilderAPI_MakeWire arcmakeWire_nlk;
	arcmakeWire_nlk.Add(TarcCurve_01);
	arcmakeWire_nlk.Add(TarcCurve_02);
	arcmakeWire_nlk.Add(TarcCurve_03);
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P7_nlk, s2_nlk));
	arcmakeWire_nlk.Add(Edge2_nlk);
	arcmakeWire_nlk.Add(arcEdge_Drainage_GC);
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P3_GC, P2_GC));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P2_GC, P4_GC));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P4_GC, P1_GC));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P1_GC, P4_GC_m));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P4_GC_m, P2_GC_m));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P2_GC_m, P3_GC_m));
	arcmakeWire_nlk.Add(arcEdge_Drainage_GC_m);
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(s2_nlk_symmetry, leftpoint_Drainage_GC_m));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P7m_nlk, s2_nlk_symmetry));

	//arcmakeWire_nlk.Add(arcEdge2_nlk);
	//arcmakeWire_nlk.Build();

	//BRepBuilderAPI_MakeFace arcmakeFace_nlk(arcmakeWire_nlk);
	TopoDS_Wire arc_sectorWire_nlk = arcmakeWire_nlk.Wire();
	BRepBuilderAPI_MakeFace arcmakeFace_nlk(arc_sectorWire_nlk);
	TopoDS_Face arc_sectorFace_nlk = arcmakeFace_nlk.Face();
	Handle(AIS_Shape) Aisarc_sectorFace_nlk = new AIS_Shape(arc_sectorFace_nlk);
	gp_Vec extrusionVec_nlk(0, 0, -70.0); // ���� Z �᷽������ 70 ����λ
	BRepPrimAPI_MakePrism arcmake_nlk(arc_sectorFace_nlk, extrusionVec_nlk);
	TopoDS_Shape arcShape_nlk = arcmake_nlk.Shape();
	//TopoDS_Solid arcbody_nlk = TopoDS::Solid(arcShape_nlk);

	//TopoDS_Wire arc_sectorWire_nlk = arcmakeWire_nlk.Wire();
	//BRepBuilderAPI_MakeFace arcmakeFace_nlk(arc_sectorWire_nlk);
	//TopoDS_Face arc_sectorFace_nlk = arcmakeFace_nlk.Face();
	//gp_Vec extrusionVec_nlk(0, 0, -70.0); // ���� Z �᷽������ 70 ����λ
	//BRepPrimAPI_MakePrism arcmake_nlk(arc_sectorFace_nlk, extrusionVec_nlk);
	//TopoDS_Shape arcShape_nlk = arcmake_nlk.Shape();
	//TopoDS_Solid arcbody_nlk = TopoDS::Solid(arcShape_nlk);
	//Handle(AIS_Shape) Aisarcbody_nlk = new AIS_Shape(arcbody_nlk);

	//// ���������������ȥ�ռ��������
	//BRepBuilderAPI_MakeWire wireMaker_empty_volume;
	//wireMaker_empty_volume.Add(Edge2_nlk);
	//wireMaker_empty_volume.Add(arcEdge_Drainage_GC);
	//wireMaker_empty_volume.Add(BRepBuilderAPI_MakeEdge(P3_GC, P2_GC));
	//wireMaker_empty_volume.Add(BRepBuilderAPI_MakeEdge(P2_GC, P4_GC));
	//wireMaker_empty_volume.Add(BRepBuilderAPI_MakeEdge(P4_GC, P1_GC));
	//wireMaker_empty_volume.Add(BRepBuilderAPI_MakeEdge(P1_GC, s2_y_nlk));
	//wireMaker_empty_volume.Add(BRepBuilderAPI_MakeEdge(s2_y_nlk, s2_nlk));
	//wireMaker_empty_volume.Build();
	//TopoDS_Wire sectorwireMaker_empty_volume = wireMaker_empty_volume.Wire();
	//BRepBuilderAPI_MakeFace makeFace_empty_volume(sectorwireMaker_empty_volume);
	//TopoDS_Face sectorFace_empty_volume = makeFace_empty_volume.Face();
	//gp_Vec extrusionVec_empty_volume(0, 0, -70.0); // ���� Z �᷽������ 70 ����λ
	//BRepPrimAPI_MakePrism make_empty_volume(sectorFace_empty_volume, extrusionVec_empty_volume);
	//TopoDS_Shape Shape_empty_volume = make_empty_volume.Shape();
	////TopoDS_Solid body_empty_volume = TopoDS::Solid(Shape_empty_volume);


	// ������y��ĶԳ�Ӧ�õ��ڵ��Ŀռ䣨������ԭ��λ�õ��ڵ��Ŀռ䣩
	/*BRepBuilderAPI_Transform transform_empty_volume(Shape_empty_volume, mirrorTransform_GC);
	transform_empty_volume.Build();
	TopoDS_Shape transformedShape_empty_volume = transform_empty_volume.Shape();*/
	/*BRepBuilderAPI_Transform transform_empty_volume(body_empty_volume, mirrorTransform_GC);
	transform_empty_volume.Build();*/
	//Handle(AIS_Shape) Aistransform_empty_volume = new AIS_Shape(transform_empty_volume);
	//TopoDS_Shape transformedShape_empty_volume = transform_empty_volume.Shape();



	//�����๵�ǰ�
	Standard_Real trenchcover_Xlength = 43.0;  // �๵�ǰ�ĳ���
	Standard_Real trenchcover_Ylength = 8.0;   // �๵�ǰ�Ŀ��
	Standard_Real height_trench_cover = 70.0;

	// �����๵�ǰ�������
	BRepPrimAPI_MakeBox makeBox_trench_cover(P8_nlk, trenchcover_Xlength, -trenchcover_Ylength, -height_trench_cover);
	TopoDS_Shape BoxShape_trench_cover = makeBox_trench_cover.Shape();
	//TopoDS_Solid Box_trench_cover = makeBox_trench_cover.Solid();


	//�����⹵�ǰ壨����ƫ�ƴ�����
	Standard_Real offsetDistance_trench_cover = trenchcover_Xlength + trenchcover_gap;

	gp_Vec translationVector2_trench_cover(offsetDistance_trench_cover, 0.0, 0.0);
	gp_Vec translationVector3_trench_cover(2 * offsetDistance_trench_cover, 0.0, 0.0);

	TopoDS_Shape offBoxShape2_trench_cover = CopyAndTranslateShape(BoxShape_trench_cover, translationVector2_trench_cover);
	//TopoDS_Solid Box2_trench_cover = TopoDS::Solid(offBoxShape2_trench_cover);
	TopoDS_Shape offBoxShape3_trench_cover = CopyAndTranslateShape(BoxShape_trench_cover, translationVector3_trench_cover);
	//TopoDS_Solid Box3_trench_cover = TopoDS::Solid(offBoxShape3_trench_cover);


	//������
	//�������²�
	gp_Pnt P9_GC(P8_nlk.X() + trenchcover_Xlength / 2.0, CUT_O4_01Y - trenchcover_Ylength, 0.0);
	Standard_Real powercable_Xlength = 30.0;  // �������²۵ĳ���
	Standard_Real powercable_Ylength = 30.0;   // �������²۵Ŀ��

	// ����������²��ĸ��ǵ������
	gp_Pnt upperLeftPoint_power_cable(P9_GC.X() - powercable_Xlength / 2.0, P9_GC.Y(), 0);
	gp_Pnt upperRightPoint_power_cable(P9_GC.X() + powercable_Xlength / 2.0, P9_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_power_cable(P9_GC.X() - powercable_Xlength / 2.0, P9_GC.Y() - powercable_Ylength, 0);
	gp_Pnt lowerRightPoint_power_cable(P9_GC.X() + powercable_Xlength / 2.0, P9_GC.Y() - powercable_Ylength, 0);

	BRepBuilderAPI_MakeWire wireMaker_power_cable;
	wireMaker_power_cable.Add(BRepBuilderAPI_MakeEdge(upperLeftPoint_power_cable, upperRightPoint_power_cable));
	wireMaker_power_cable.Add(BRepBuilderAPI_MakeEdge(upperRightPoint_power_cable, lowerRightPoint_power_cable));
	wireMaker_power_cable.Add(BRepBuilderAPI_MakeEdge(lowerRightPoint_power_cable, lowerLeftPoint_power_cable));
	wireMaker_power_cable.Add(BRepBuilderAPI_MakeEdge(lowerLeftPoint_power_cable, upperLeftPoint_power_cable));
	wireMaker_power_cable.Build();

	TopoDS_Wire wire_power_cable = wireMaker_power_cable.Wire();


	// �����������²۵�������
	BRepPrimAPI_MakeBox box_power_cable(upperLeftPoint_power_cable, powercable_Xlength, -powercable_Ylength, -70.0);

	// ��ȡ�����ĵ������²�
	TopoDS_Shape box_Shape_power_cable = box_power_cable.Shape();
	//TopoDS_Solid cube_power_cable = TopoDS::Solid(box_Shape_power_cable);


	//�����๵��
	gp_Pnt P10_GC(P9_GC.X() + 44, CUT_O4_01Y - trenchcover_Ylength, 0.0);
	Standard_Real sidegroove_Xlength = 30.0;  // �๵�۵ĳ���
	Standard_Real sidegroove_Ylength = 80.0;   // �๵�۵Ŀ��

	// ��������ĸ��ǵ������
	gp_Pnt upperLeftPoint_measuring_groove(P10_GC.X() - sidegroove_Xlength / 2.0, P10_GC.Y(), 0);
	gp_Pnt upperRightPoint_measuring_groove(P10_GC.X() + sidegroove_Xlength / 2.0, P10_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_measuring_groove(P10_GC.X() - sidegroove_Xlength / 2.0, P10_GC.Y() - sidegroove_Ylength, 0);
	gp_Pnt lowerRightPoint_measuring_groove(P10_GC.X() + sidegroove_Xlength / 2.0, P10_GC.Y() - sidegroove_Ylength, 0);

	BRepBuilderAPI_MakeWire wireMaker_measuring_groove;
	wireMaker_measuring_groove.Add(BRepBuilderAPI_MakeEdge(upperLeftPoint_measuring_groove, upperRightPoint_measuring_groove));
	wireMaker_measuring_groove.Add(BRepBuilderAPI_MakeEdge(upperRightPoint_measuring_groove, lowerRightPoint_measuring_groove));
	wireMaker_measuring_groove.Add(BRepBuilderAPI_MakeEdge(lowerRightPoint_measuring_groove, lowerLeftPoint_measuring_groove));
	wireMaker_measuring_groove.Add(BRepBuilderAPI_MakeEdge(lowerLeftPoint_measuring_groove, upperLeftPoint_measuring_groove));
	wireMaker_measuring_groove.Build();

	TopoDS_Wire wire_measuring_groove = wireMaker_measuring_groove.Wire();

	// �����๵��������
	BRepPrimAPI_MakeBox box_measuring_groove(upperLeftPoint_measuring_groove, sidegroove_Xlength, -sidegroove_Ylength, -70.0);

	// ��ȡ�����Ĳ๵��
	TopoDS_Shape box_Shape_measuring_groove = box_measuring_groove.Shape();
	//TopoDS_Solid cube_measuring_groove = TopoDS::Solid(box_Shape_measuring_groove);


	//����ͨ���źŵ��²�
	gp_Pnt P11_GC(P10_GC.X() + 44, CUT_O4_01Y - trenchcover_Ylength, 0.0);
	Standard_Real communcable_Xlength = 35.0;  // ͨ���źŵ��²۵ĳ���
	Standard_Real communcable_Ylength = 30.0;   // ͨ���źŵ��²۵Ŀ��

	// ����ͨ���źŵ��²��ĸ��ǵ������
	gp_Pnt upperLeftPoint_communication_cable(P11_GC.X() - communcable_Xlength / 2.0, P11_GC.Y(), 0);
	gp_Pnt upperRightPoint_communication_cable(P11_GC.X() + communcable_Xlength / 2.0, P11_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_communication_cable(P11_GC.X() - communcable_Xlength / 2.0, P11_GC.Y() - communcable_Ylength, 0);
	gp_Pnt lowerRightPoint_communication_cable(P11_GC.X() + communcable_Xlength / 2.0, P11_GC.Y() - communcable_Ylength, 0);

	BRepBuilderAPI_MakeWire wireMaker_communication_cable;
	wireMaker_communication_cable.Add(BRepBuilderAPI_MakeEdge(upperLeftPoint_communication_cable, upperRightPoint_communication_cable));
	wireMaker_communication_cable.Add(BRepBuilderAPI_MakeEdge(upperRightPoint_communication_cable, lowerRightPoint_communication_cable));
	wireMaker_communication_cable.Add(BRepBuilderAPI_MakeEdge(lowerRightPoint_communication_cable, lowerLeftPoint_communication_cable));
	wireMaker_communication_cable.Add(BRepBuilderAPI_MakeEdge(lowerLeftPoint_communication_cable, upperLeftPoint_communication_cable));
	wireMaker_communication_cable.Build();

	// ����ͨ���źŵ��²�������
	BRepPrimAPI_MakeBox box_communication_cable(upperLeftPoint_communication_cable, communcable_Xlength, -communcable_Ylength, -70.0);

	// ��ȡ������ͨ���źŵ��²�
	TopoDS_Shape boxShape_communication_cable = box_communication_cable.Shape();
	//TopoDS_Solid cube_communication_cable = TopoDS::Solid(boxShape_communication_cable);

	TopoDS_Wire wire_communication_cable = wireMaker_communication_cable.Wire();


	// ����������⹵�ǰ���������1��
	/*TopoDS_Compound compound1_s;
	BRep_Builder builder1_s;
	builder1_s.MakeCompound(compound1_s);
	builder1_s.Add(compound1_s, BoxShape_trench_cover);
	builder1_s.Add(compound1_s, offBoxShape2_trench_cover);
	builder1_s.Add(compound1_s, offBoxShape3_trench_cover);*/
	TopoDS_Compound compound1_s;
	BRep_Builder builder1_s;
	builder1_s.MakeCompound(compound1_s);
	builder1_s.Add(compound1_s, BoxShape_trench_cover);
	builder1_s.Add(compound1_s, offBoxShape2_trench_cover);
	builder1_s.Add(compound1_s, offBoxShape3_trench_cover);

	// ������������۷��������2��
	/*TopoDS_Compound compound2_s;
	BRep_Builder builder2_s;
	builder2_s.MakeCompound(compound2_s);
	builder2_s.Add(compound2_s, box_Shape_power_cable);
	builder2_s.Add(compound2_s, box_Shape_measuring_groove);
	builder2_s.Add(compound2_s, boxShape_communication_cable);*/
	TopoDS_Compound compound2_s;
	BRep_Builder builder2_s;
	builder2_s.MakeCompound(compound2_s);
	builder2_s.Add(compound2_s, box_Shape_power_cable);
	builder2_s.Add(compound2_s, box_Shape_measuring_groove);
	builder2_s.Add(compound2_s, boxShape_communication_cable);

	// �����������⹵�ǰ���������۷��������3��
	TopoDS_Compound compound3_s;
	BRep_Builder builder3_s;
	builder1_s.MakeCompound(compound3_s);
	builder1_s.Add(compound3_s, BoxShape_trench_cover);
	builder1_s.Add(compound3_s, offBoxShape2_trench_cover);
	builder1_s.Add(compound3_s, offBoxShape3_trench_cover);
	builder3_s.Add(compound3_s, box_Shape_power_cable);
	builder3_s.Add(compound3_s, box_Shape_measuring_groove);
	builder3_s.Add(compound3_s, boxShape_communication_cable);
	Handle(AIS_Shape) Aiscompound3 = new AIS_Shape(compound3_s);
	Aiscompound3->SetColor(Quantity_NOC_YELLOW);
	//Aiscompound3->SetTransparency(0.5);
	myOccView->getContext()->Display(Aiscompound3, Standard_True);

	// ������y��ĶԳ�Ӧ�õ������1��������ԭ��λ�õ�����壩
	BRepBuilderAPI_Transform transform1(compound1_s, mirrorTransform_GC);
	transform1.Build();
	TopoDS_Shape transformedShape1 = transform1.Shape();
	//TopoDS_Solid cube_transformedShape1 = TopoDS::Solid(transformedShape1);


	// ������y��ĶԳ�Ӧ�õ������2��������ԭ��λ�õ�����壩
	BRepBuilderAPI_Transform transform2(compound2_s, mirrorTransform_GC);
	transform2.Build();
	TopoDS_Shape transformedShape2 = transform2.Shape();
	//TopoDS_Solid cube_transformedShape2 = TopoDS::Solid(transformedShape2);


	// ������y��ĶԳ�Ӧ�õ������3��������ԭ��λ�õ�����壩
	BRepBuilderAPI_Transform transform3(compound3_s, mirrorTransform_GC);
	transform3.Build();
	TopoDS_Shape transformedShape3 = transform3.Shape();
	//TopoDS_Solid cube_transformedShape3 = TopoDS::Solid(transformedShape3);
	Handle(AIS_Shape) AistransformedShape3 = new AIS_Shape(transformedShape3);
	AistransformedShape3->SetColor(Quantity_NOC_YELLOW);
	//AistransformedShape3->SetTransparency(0.5);
	myOccView->getContext()->Display(AistransformedShape3, Standard_True);


	////һЩ�������
	//gp_Pnt s3_GC(-616, -630 * result_nlk - 8, 0.0);
	//gp_Pnt s4_GC(-615, -630 * result_nlk - 8, 0.0);
	//gp_Pnt s5_GC(-572, -630 * result_nlk - 8, 0.0);
	//gp_Pnt s6_GC(-571, -630 * result_nlk - 8, 0.0);
	//gp_Pnt s7_GC(-528, -630 * result_nlk - 8, 0.0);
	//gp_Pnt s8_GC(-527, -630 * result_nlk - 8, 0.0);
	//gp_Pnt s9_GC(-484, -630 * result_nlk - 8, 0.0);
	//gp_Pnt s10_GC(-483, -630 * result_nlk - 8, 0.0);
	//gp_Pnt s11_GC(-483, -630 * result_nlk, 0.0);
	//gp_Pnt s12_GC(-483, -630 * result_nlk, 0.0);
	//һЩ�������
	gp_Pnt s3_GC(-616, CUT_O4_01Y - 8, 0.0);
	gp_Pnt s4_GC(-615, CUT_O4_01Y - 8, 0.0);
	gp_Pnt s5_GC(-572, CUT_O4_01Y - 8, 0.0);
	gp_Pnt s6_GC(-571, CUT_O4_01Y - 8, 0.0);
	gp_Pnt s7_GC(-528, CUT_O4_01Y - 8, 0.0);
	gp_Pnt s8_GC(-527, CUT_O4_01Y - 8, 0.0);
	gp_Pnt s9_GC(-484, CUT_O4_01Y - 8, 0.0);
	gp_Pnt s10_GC(-483, CUT_O4_01Y - 8, 0.0);
	gp_Pnt s11_GC(-483, CUT_O4_01Y, 0.0);
	gp_Pnt s12_GC(-483, CUT_O4_01Y, 0.0);


	//����
	Standard_Real distance_catheter = 14.0;
	Standard_Real slope_catheter = 0.02;
	gp_Vec Direction_catheter(distance_catheter, -distance_catheter*slope_catheter, 0.0);
	gp_Pnt s13_catheter = lowerRightPoint_power_cable.Translated(Direction_catheter);

	TopoDS_Edge Edge_catheter = BRepBuilderAPI_MakeEdge(lowerRightPoint_power_cable, s13_catheter);
	Handle(AIS_Shape) AisEdge_catheter = new AIS_Shape(Edge_catheter);
	Standard_Real offsetDistance_catheter = 2.0;

	// ƫ��
	gp_Vec translationVector_catheter(0.0, offsetDistance_catheter, 0.0);
	TopoDS_Shape offsetShape_catheter = CopyAndTranslateShape(Edge_catheter, translationVector_catheter);
	Handle(AIS_Shape) AisoffsetShape_catheter = new AIS_Shape(offsetShape_catheter);


	// ʹ�ò���������ȥ�⹵�����Ĺ��ۣ���������������״
	BRepAlgoAPI_Cut cutOp1(arcShape_nlk, cubeShape_center_concrete_GC);
	arcShape_nlk = cutOp1.Shape();
	BRepAlgoAPI_Cut cutOp2(arcShape_nlk, BoxShape_trench_cover);
	arcShape_nlk = cutOp2.Shape();
	BRepAlgoAPI_Cut cutOp3(arcShape_nlk, offBoxShape2_trench_cover);
	arcShape_nlk = cutOp3.Shape();
	BRepAlgoAPI_Cut cutOp4(arcShape_nlk, offBoxShape3_trench_cover);
	arcShape_nlk = cutOp4.Shape();
	BRepAlgoAPI_Cut cutOp5(arcShape_nlk, box_Shape_power_cable);
	arcShape_nlk = cutOp5.Shape();
	BRepAlgoAPI_Cut cutOp6(arcShape_nlk, box_Shape_measuring_groove);
	arcShape_nlk = cutOp6.Shape();
	BRepAlgoAPI_Cut cutOp7(arcShape_nlk, boxShape_communication_cable);
	arcShape_nlk = cutOp7.Shape();
	BRepAlgoAPI_Cut cutOp8(arcShape_nlk, transformedShape1);
	arcShape_nlk = cutOp8.Shape();
	BRepAlgoAPI_Cut cutOp9(arcShape_nlk, transformedShape2);
	/*arcShape_nlk = cutOp9.Shape();*/
	/*BRepAlgoAPI_Cut cutOp10(arcShape_nlk, Shape_empty_volume);
	arcShape_nlk = cutOp10.Shape();
	BRepAlgoAPI_Cut cutOp11(arcShape_nlk, transformedShape_empty_volume);*/
	cutOp9.Build();
	Handle(AIS_Shape) AiscutOp9 = new AIS_Shape(cutOp9);
	AiscutOp9->SetColor(Quantity_NOC_BLUE);
	//AiscutOp11->SetTransparency(0.0);
	myOccView->getContext()->Display(AiscutOp9, Standard_True);


	// ���������5
	TopoDS_Compound compound5;
	BRep_Builder builder5;
	builder5.MakeCompound(compound5);
	/*builder5.Add(compound5, BoxShape_ce1);
	builder5.Add(compound5, offBoxShape_ce2);
	builder5.Add(compound5, offBoxShape_ce3);*/


	// ���������6
	TopoDS_Compound compound6;
	BRep_Builder builder6;
	builder6.MakeCompound(compound6);


	// �����Ĺ��ۺ����ĸǰ���������7
	TopoDS_Compound compound7;
	BRep_Builder builder7;
	builder7.MakeCompound(compound7);
	builder7.Add(compound7, cubeShape_center_cover_GC);
	builder7.Add(compound7, cubeShape_center_GC);
	Handle(AIS_Shape) Aiscompound7 = new AIS_Shape(compound7);
	Aiscompound7->SetColor(Quantity_NOC_YELLOW);
	//Aiscompound7->SetTransparency(0.5);
	myOccView->getContext()->Display(Aiscompound7, Standard_True);


	// ���������8
	TopoDS_Compound compound8;
	BRep_Builder builder8;
	builder8.MakeCompound(compound8);


	// ���������9
	TopoDS_Compound compound9;
	BRep_Builder builder9;
	builder9.MakeCompound(compound9);



	// ��Z�᷽���ƶ���������
	for (int i = 1; i < 10; i++)
	{
		Standard_Real offsetDistance_GC = 70.0*i;
		gp_Vec translationVector_GC(0.0, 0.0, -offsetDistance_GC);

		TopoDS_Shape offcompound3_1 = CopyAndTranslateShape(compound3_s, translationVector_GC);
		builder5.Add(compound5, offcompound3_1);
		TopoDS_Shape offcutOp11 = CopyAndTranslateShape(cutOp9, translationVector_GC);
		builder6.Add(compound6, offcutOp11);
		TopoDS_Shape offcompound7 = CopyAndTranslateShape(compound7, translationVector_GC);
		builder6.Add(compound8, offcompound7);
		TopoDS_Shape offcut_ceng2 = CopyAndTranslateShape(cut2_center_concrete_GC, translationVector_GC);
		builder6.Add(compound9, offcut_ceng2);
	}

	Handle(AIS_Shape) Aiscompound5 = new AIS_Shape(compound5);
	Aiscompound5->SetColor(Quantity_NOC_YELLOW);
	//Aiscompound5->SetTransparency(0.5);
	myOccView->getContext()->Display(Aiscompound5, Standard_True);

	BRepBuilderAPI_Transform transform5(compound5, mirrorTransform_GC);
	transform5.Build();
	TopoDS_Shape transformedShape5 = transform5.Shape();
	Handle(AIS_Shape) AistransformedShape5 = new AIS_Shape(transformedShape5);
	AistransformedShape5->SetColor(Quantity_NOC_YELLOW);
	//AistransformedShape5->SetTransparency(0.5);
	myOccView->getContext()->Display(AistransformedShape5, Standard_True);

	Handle(AIS_Shape) Aiscompound6 = new AIS_Shape(compound6);
	Aiscompound6->SetColor(Quantity_NOC_BLUE);
	//Aiscompound6->SetTransparency(0.5);
	myOccView->getContext()->Display(Aiscompound6, Standard_True);

	Handle(AIS_Shape) Aiscompound8 = new AIS_Shape(compound8);
	Aiscompound8->SetColor(Quantity_NOC_YELLOW);
	//Aiscompound8->SetTransparency(0.5);
	myOccView->getContext()->Display(Aiscompound8, Standard_True);

	Handle(AIS_Shape) Aiscompound9 = new AIS_Shape(compound9);
	Aiscompound9->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(Aiscompound9, Standard_True);

	//// ����ԭʼԲ���������
	//gp_Pnt location(0, 0, 0); // Բ����λ��
	//gp_Dir direction(1, 1, 0); // Բ���巽��
	//gp_Ax2 axis(location, direction);

	//// ����ԭʼԲ����
	//Standard_Real radius = 10.0; // Բ����뾶
	//Standard_Real height_ = 50.0; // Բ����߶�
	//BRepPrimAPI_MakeCylinder cylinderMaker(axis, radius, height_);
	//TopoDS_Shape originalCylinder = cylinderMaker.Shape();

	//// ����б�Ʊ任
	//gp_Trsf translation;
	//translation.SetTranslation(gp_Vec(10, 20, 30)); // ���� (10, 20, 30) ����б��

	//// ʹ�� BRepBuilderAPI_Transform ��Բ������б任���õ�бԲ����
	//BRepBuilderAPI_Transform transform(originalCylinder, translation);
	//TopoDS_Shape slantedCylinder = transform.ModifiedShape(originalCylinder);
	//Handle(AIS_Shape) AisslantedCylinder = new AIS_Shape(slantedCylinder);
	//AisslantedCylinder->SetColor(Quantity_NOC_BLUE);
	//myOccView->getContext()->Display(AisslantedCylinder, Standard_True);


	//�����๵�ǰ�ֽ�N4��N5
	gp_Pnt O1_N4_s(P8_nlk.X() + 4.5, P8_nlk.Y() - 8 + 4.1, -2.0);
	gp_Pnt O1_N5_s(P8_nlk.X() + 2.0, P8_nlk.Y() - 8 + 3.4, -4.5);
	gp_Dir normal_z_s(0, 0, 1);
	gp_Dir normal_x_s(1, 0, 0);
	gp_Dir normal_y_s(0, 1, 0);

	Standard_Real radius_N4_s = 0.3; // �ֽ�N4�뾶
	Standard_Real radius_N5_s = 0.4; // �ֽ�N5�뾶
	gp_Ax2 axis_N4_s(O1_N4_s, normal_z_s);
	gp_Ax2 axis_N5_s(O1_N5_s, normal_x_s);

	//����Բ����N4��N5
	Handle(Geom_Circle) circle_N4_s = new Geom_Circle(axis_N4_s, radius_N4_s);
	BRepBuilderAPI_MakeEdge edgeMaker_N4_s(circle_N4_s);
	TopoDS_Edge edge_N4_s = edgeMaker_N4_s.Edge();
	Handle(Geom_Circle) circle_N5_s = new Geom_Circle(axis_N5_s, radius_N5_s);
	BRepBuilderAPI_MakeEdge edgeMaker_N5_s(circle_N5_s);
	TopoDS_Edge edge_N5_s = edgeMaker_N5_s.Edge();

	// ������ȦN4��N5
	BRepBuilderAPI_MakeWire wireMaker_N4_s(edge_N4_s);
	TopoDS_Wire wire_N4_s = wireMaker_N4_s.Wire();
	BRepBuilderAPI_MakeWire wireMaker_N5_s(edge_N5_s);
	TopoDS_Wire wire_N5_s = wireMaker_N5_s.Wire();

	// ����Բ��
	BRepBuilderAPI_MakeFace faceMaker_N4_s(wire_N4_s);
	TopoDS_Face face_N4_s = faceMaker_N4_s.Face();
	gp_Vec extrusionVec_N4_s(0.0, 0.0, -66.0); // ���� Z �᷽������ 66 ����λ
	BRepPrimAPI_MakePrism make_N4_s(face_N4_s, extrusionVec_N4_s);
	TopoDS_Shape Shape_N4_s = make_N4_s.Shape();
	//TopoDS_Solid body_N4 = TopoDS::Solid(Shape_N4);
	BRepBuilderAPI_MakeFace faceMaker_N5_s(wire_N5_s);
	TopoDS_Face face_N5_s = faceMaker_N5_s.Face();
	gp_Vec extrusionVec_N5_s(39.0, 0.0, 0.0); // ���� X �᷽������ 39 ����λ
	BRepPrimAPI_MakePrism make_N5_s(face_N5_s, extrusionVec_N5_s);
	TopoDS_Shape Shape_N5_s = make_N5_s.Shape();
	//Handle(AIS_Shape) AisShape_N4 = new AIS_Shape(Shape_N4);

	Standard_Real offsetDistance_N4_1_s = 11.5;
	Standard_Real offsetDistance_N4_2_s = 11.0;
	Standard_Real offsetDistance_N5_1_s = 11.0;
	Standard_Real offsetDistance_N5_2_s = 10.0;

	gp_Vec translationVector_N4_1_s(offsetDistance_N4_1_s, 0.0, 0.0);
	gp_Vec translationVector_N4_2_s(offsetDistance_N4_1_s + offsetDistance_N4_2_s, 0.0, 0.0);
	gp_Vec translationVector_N4_3_s(2 * offsetDistance_N4_1_s + offsetDistance_N4_2_s, 0.0, 0.0);
	gp_Vec translationVector_N5_1_s(0.0, 0.0, -offsetDistance_N5_1_s);
	gp_Vec translationVector_N5_2_s(0.0, 0.0, -offsetDistance_N5_2_s - offsetDistance_N5_1_s);
	gp_Vec translationVector_N5_3_s(0.0, 0.0, -2 * offsetDistance_N5_2_s - offsetDistance_N5_2_s);
	gp_Vec translationVector_N5_4_s(0.0, 0.0, -3 * offsetDistance_N5_2_s - offsetDistance_N5_2_s);
	gp_Vec translationVector_N5_5_s(0.0, 0.0, -4 * offsetDistance_N5_2_s - offsetDistance_N5_2_s);
	gp_Vec translationVector_N5_6_s(0.0, 0.0, -5 * offsetDistance_N5_2_s - offsetDistance_N5_2_s);

	TopoDS_Shape offShape_N4_1_s = CopyAndTranslateShape(Shape_N4_s, translationVector_N4_1_s);
	//TopoDS_Solid offSolid_N4_1 = TopoDS::Solid(offShape_N4_1);
	TopoDS_Shape offShape_N4_2_s = CopyAndTranslateShape(Shape_N4_s, translationVector_N4_2_s);
	TopoDS_Shape offShape_N4_3_s = CopyAndTranslateShape(Shape_N4_s, translationVector_N4_3_s);
	TopoDS_Shape offShape_N5_1_s = CopyAndTranslateShape(Shape_N5_s, translationVector_N5_1_s);
	TopoDS_Shape offShape_N5_2_s = CopyAndTranslateShape(Shape_N5_s, translationVector_N5_2_s);
	TopoDS_Shape offShape_N5_3_s = CopyAndTranslateShape(Shape_N5_s, translationVector_N5_3_s);
	TopoDS_Shape offShape_N5_4_s = CopyAndTranslateShape(Shape_N5_s, translationVector_N5_4_s);
	TopoDS_Shape offShape_N5_5_s = CopyAndTranslateShape(Shape_N5_s, translationVector_N5_5_s);
	TopoDS_Shape offShape_N5_6_s = CopyAndTranslateShape(Shape_N5_s, translationVector_N5_6_s);

	// �����๴�ǰ�ֽ������1
	TopoDS_Compound compound_rebar1_s;
	BRep_Builder builder_rebar1_s;
	builder_rebar1_s.MakeCompound(compound_rebar1_s);
	builder_rebar1_s.Add(compound_rebar1_s, Shape_N4_s);
	builder_rebar1_s.Add(compound_rebar1_s, offShape_N4_1_s);
	builder_rebar1_s.Add(compound_rebar1_s, offShape_N4_2_s);
	builder_rebar1_s.Add(compound_rebar1_s, offShape_N4_3_s);
	builder_rebar1_s.Add(compound_rebar1_s, Shape_N5_s);
	builder_rebar1_s.Add(compound_rebar1_s, offShape_N5_1_s);
	builder_rebar1_s.Add(compound_rebar1_s, offShape_N5_2_s);
	builder_rebar1_s.Add(compound_rebar1_s, offShape_N5_3_s);
	builder_rebar1_s.Add(compound_rebar1_s, offShape_N5_4_s);
	builder_rebar1_s.Add(compound_rebar1_s, offShape_N5_5_s);
	builder_rebar1_s.Add(compound_rebar1_s, offShape_N5_6_s);

	// �����๴�ǰ�ֽ�
	Standard_Real offsetDistance_rebar1_s = 43.0;

	gp_Vec translationVector_rebar1_s(offsetDistance_rebar1_s, 0.0, 0.0);
	gp_Vec translationVector_rebar2_s(2 * offsetDistance_rebar1_s, 0.0, 0.0);

	TopoDS_Shape offShape_rebar1_s = CopyAndTranslateShape(compound_rebar1_s, translationVector_rebar1_s);
	TopoDS_Shape offShape_rebar2_s = CopyAndTranslateShape(compound_rebar1_s, translationVector_rebar2_s);

	// �����๴�ǰ������2
	TopoDS_Compound compound_rebar2_s;
	BRep_Builder builder_rebar2_s;
	builder_rebar1_s.MakeCompound(compound_rebar2_s);
	builder_rebar1_s.Add(compound_rebar2_s, compound_rebar1_s);
	builder_rebar1_s.Add(compound_rebar2_s, offShape_rebar1_s);
	builder_rebar1_s.Add(compound_rebar2_s, offShape_rebar2_s);

	BRepBuilderAPI_Transform transform_rebar2_s(compound_rebar2_s, mirrorTransform_GC);
	transform_rebar2_s.Build();
	TopoDS_Shape transformShape_rebar2_s = transform_rebar2_s.Shape();
	Handle(AIS_Shape) AistransformShape_rebar2_s = new AIS_Shape(transformShape_rebar2_s);
	Handle(AIS_Shape) Aiscompound_rebar2_s = new AIS_Shape(compound_rebar2_s);
	Aiscompound_rebar2_s->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(Aiscompound_rebar2_s, Standard_True);
	AistransformShape_rebar2_s->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AistransformShape_rebar2_s, Standard_True);


	// ���Ĺ��ǰ�ֽ�
	gp_Pnt O1_N4_c(-centercover_Xlength / 2 + 4.0, P1_GC.Y() - 8 + 4.1, -2.0);
	gp_Pnt O1_N7_c(-centercover_Xlength / 2 + 2.0, P1_GC.Y() - 8 + 3.4, -4.0);

	Standard_Real radius_N4_c = 0.3; // �ֽ�N4�뾶
	Standard_Real radius_N7_c = 0.4; // �ֽ�N5�뾶
	gp_Ax2 axis_N4_c(O1_N4_c, normal_z_s);
	gp_Ax2 axis_N7_c(O1_N7_c, normal_x_s);

	// ����Բ����N4��N5
	Handle(Geom_Circle) circle_N4_c = new Geom_Circle(axis_N4_c, radius_N4_c);
	BRepBuilderAPI_MakeEdge edgeMaker_N4_c(circle_N4_c);
	TopoDS_Edge edge_N4_c = edgeMaker_N4_c.Edge();
	Handle(Geom_Circle) circle_N7_c = new Geom_Circle(axis_N7_c, radius_N7_c);
	BRepBuilderAPI_MakeEdge edgeMaker_N7_c(circle_N7_c);
	TopoDS_Edge edge_N7_c = edgeMaker_N7_c.Edge();

	// ������ȦN4��N5
	BRepBuilderAPI_MakeWire wireMaker_N4_c(edge_N4_c);
	TopoDS_Wire wire_N4_c = wireMaker_N4_c.Wire();
	BRepBuilderAPI_MakeWire wireMaker_N7_c(edge_N7_c);
	TopoDS_Wire wire_N7_c = wireMaker_N7_c.Wire();

	// ����Բ��N4��N5
	BRepBuilderAPI_MakeFace faceMaker_N4_c(wire_N4_c);
	TopoDS_Face face_N4_c = faceMaker_N4_c.Face();
	gp_Vec extrusionVec_N4_c(0.0, 0.0, -36.0); // ���� Z �᷽������ 36 ����λ
	BRepPrimAPI_MakePrism make_N4_c(face_N4_c, extrusionVec_N4_c);
	TopoDS_Shape Shape_N4_c = make_N4_c.Shape();
	//TopoDS_Solid body_N4 = TopoDS::Solid(Shape_N4);
	BRepBuilderAPI_MakeFace faceMaker_N7_c(wire_N7_c);
	TopoDS_Face face_N7_c = faceMaker_N7_c.Face();
	gp_Vec extrusionVec_N7_c(66.0, 0.0, 0.0); // ���� X �᷽������ 66 ����λ
	BRepPrimAPI_MakePrism make_N7_c(face_N7_c, extrusionVec_N7_c);
	TopoDS_Shape Shape_N7_c = make_N7_c.Shape();

	Standard_Real offsetDistance_N4_1_c = 12.4;
	//Standard_Real offsetDistance_N4_2_c = 11.0;
	Standard_Real offsetDistance_N7_1_c = 11.0;
	Standard_Real offsetDistance_N7_2_c = 10.0;

	gp_Vec translationVector_N4_1_c(offsetDistance_N4_1_c, 0.0, 0.0);
	gp_Vec translationVector_N4_2_c(offsetDistance_N4_1_c * 2, 0.0, 0.0);
	gp_Vec translationVector_N4_3_c(offsetDistance_N4_1_c * 3, 0.0, 0.0);
	gp_Vec translationVector_N4_4_c(offsetDistance_N4_1_c * 4, 0.0, 0.0);
	gp_Vec translationVector_N4_5_c(offsetDistance_N4_1_c * 5, 0.0, 0.0);

	gp_Vec translationVector_N7_1_c(0.0, 0.0, -offsetDistance_N7_1_c);
	gp_Vec translationVector_N7_2_c(0.0, 0.0, -offsetDistance_N7_2_c - offsetDistance_N7_1_c);
	gp_Vec translationVector_N7_3_c(0.0, 0.0, -offsetDistance_N7_2_c - offsetDistance_N7_1_c * 2);

	TopoDS_Shape offShape_N4_1_c = CopyAndTranslateShape(Shape_N4_c, translationVector_N4_1_c);
	TopoDS_Shape offShape_N4_2_c = CopyAndTranslateShape(Shape_N4_c, translationVector_N4_2_c);
	TopoDS_Shape offShape_N4_3_c = CopyAndTranslateShape(Shape_N4_c, translationVector_N4_3_c);
	TopoDS_Shape offShape_N4_4_c = CopyAndTranslateShape(Shape_N4_c, translationVector_N4_4_c);
	TopoDS_Shape offShape_N4_5_c = CopyAndTranslateShape(Shape_N4_c, translationVector_N4_5_c);

	TopoDS_Shape offShape_N7_1_c = CopyAndTranslateShape(Shape_N7_c, translationVector_N7_1_c);
	TopoDS_Shape offShape_N7_2_c = CopyAndTranslateShape(Shape_N7_c, translationVector_N7_2_c);
	TopoDS_Shape offShape_N7_3_c = CopyAndTranslateShape(Shape_N7_c, translationVector_N7_3_c);

	// �������Ĺ��ǰ�ֽ������1
	TopoDS_Compound compound_rebar1_c;
	BRep_Builder builder_rebar1_c;
	builder_rebar1_c.MakeCompound(compound_rebar1_c);
	builder_rebar1_c.Add(compound_rebar1_c, Shape_N4_c);
	builder_rebar1_c.Add(compound_rebar1_c, offShape_N4_1_c);
	builder_rebar1_c.Add(compound_rebar1_c, offShape_N4_2_c);
	builder_rebar1_c.Add(compound_rebar1_c, offShape_N4_3_c);
	builder_rebar1_c.Add(compound_rebar1_c, offShape_N4_4_c);
	builder_rebar1_c.Add(compound_rebar1_c, offShape_N4_5_c);
	builder_rebar1_c.Add(compound_rebar1_c, Shape_N7_c);
	builder_rebar1_c.Add(compound_rebar1_c, offShape_N7_1_c);
	builder_rebar1_c.Add(compound_rebar1_c, offShape_N7_2_c);
	builder_rebar1_c.Add(compound_rebar1_c, offShape_N7_3_c);

	Handle(AIS_Shape) Aiscompound_rebar1_c = new AIS_Shape(compound_rebar1_c);
	Aiscompound_rebar1_c->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(Aiscompound_rebar1_c, Standard_True);

	// �������Ĺ��ǰ�ֽ������2
	TopoDS_Compound compound_rebar2_c;
	BRep_Builder builder_rebar2_c;
	builder_rebar2_c.MakeCompound(compound_rebar2_c);


	//// ��Z�᷽���ƶ����Ĺ��ǰ�ֽ�
	//for (int i = 1; i < 10; i++)
	//{
	//	Standard_Real offsetDistance_rebar_c = 70.0*i;
	//	gp_Vec translationVector_rebar_c(0.0, 0.0, -offsetDistance_rebar_c);

	//	TopoDS_Shape offcompound_rebar_c = CopyAndTranslateShape(compound_rebar1_c, translationVector_rebar_c);
	//	builder5.Add(compound_rebar2_c, offcompound_rebar_c);
	//}

	//Handle(AIS_Shape) Aiscompound_rebar2_c = new AIS_Shape(compound_rebar2_c);
	//Aiscompound_rebar2_c->SetColor(Quantity_NOC_RED);
	////Aiscompound5->SetTransparency(0.5);
	//myOccView->getContext()->Display(Aiscompound_rebar2_c, Standard_True);


	// �������Ĺ��������еĸֽ�N1
	Standard_Real long_horizontal_N1 = 90.0;
	Standard_Real protect1_layer_N1 = 5.0;
	Standard_Real protect2_layer_N1 = 4.2;
	Standard_Real long_vertical_N1 = centerconcrete_Ylength - protect1_layer_N1 - protect2_layer_N1 - width_gover_gap_GC;
	Standard_Real R2 = 12.0;
	Standard_Real radius_N1_cl = 0.6; // �ֽ�N1�뾶
	Standard_Real startAngle_N1_cl = 1.5 * M_PI; // ��ʼ�Ƕ�
	Standard_Real endAngle_N1_cl = 2.0 * M_PI; // ��ֹ�Ƕ�
	gp_Pnt one_N1_cl(-long_horizontal_N1 / 2.0, P1_GC.Y() - centerconcrete_Ylength + protect1_layer_N1, -protect1_layer_N1); // ѡȡ�ֽ�ĳ������
	gp_Pnt two_N1_cl(-long_horizontal_N1 / 2.0, P1_GC.Y() - width_gover_gap_GC - protect2_layer_N1, -protect1_layer_N1);
	//gp_Pnt two_N1_cl(-long_horizontal_N1 / 2.0 + 6 * radius_N1_cl, P1_GC.Y() - width_gover_gap_GC - protect2_layer_N1, -protect1_layer_N1);
	/*gp_Pnt center_N1_cl(-long_horizontal_N1 / 2.0 + 6 * radius_N1_cl, P1_GC.Y() - width_gover_gap_GC - protect2_layer_N1 - 6 * radius_N1_cl, -protect1_layer_N1);*/


	gp_Ax2 one_x_axis_N1_cl(one_N1_cl, normal_x_s);
	gp_Ax2 one_y_axis_N1_cl(one_N1_cl, normal_y_s);
	gp_Ax2 two_axis_N1_cl(two_N1_cl, normal_x_s);
	/*gp_Ax2 center_axis_N1_cl(center_N1_cl, normal_z_s);*/


	// ����Բ����N1
	Handle(Geom_Circle) one_x_circle_N1_cl = new Geom_Circle(one_x_axis_N1_cl, radius_N1_cl);
	BRepBuilderAPI_MakeEdge one_x_edgeMaker_N1_cl(one_x_circle_N1_cl);
	TopoDS_Edge one_x_edge_N1_cl = one_x_edgeMaker_N1_cl.Edge();
	Handle(Geom_Circle) one_y_circle_N1_cl = new Geom_Circle(one_y_axis_N1_cl, radius_N1_cl);
	BRepBuilderAPI_MakeEdge one_y_edgeMaker_N1_cl(one_y_circle_N1_cl);
	TopoDS_Edge one_y_edge_N1_cl = one_y_edgeMaker_N1_cl.Edge();
	Handle(Geom_Circle) two_circle_N1_cl = new Geom_Circle(two_axis_N1_cl, radius_N1_cl);
	BRepBuilderAPI_MakeEdge two_edgeMaker_N1_cl(two_circle_N1_cl);
	TopoDS_Edge two_edge_N1_cl = two_edgeMaker_N1_cl.Edge();


	// ������ȦN1
	BRepBuilderAPI_MakeWire one_x_wireMaker_N1_cl(one_x_edge_N1_cl);
	TopoDS_Wire one_x_wire_N1_cl = one_x_wireMaker_N1_cl.Wire();
	BRepBuilderAPI_MakeWire one_y_wireMaker_N1_cl(one_y_edge_N1_cl);
	TopoDS_Wire one_y_wire_N1_cl = one_y_wireMaker_N1_cl.Wire();
	BRepBuilderAPI_MakeWire two_wireMaker_N1_cl(two_edge_N1_cl);
	TopoDS_Wire two_wire_N1_cl = two_wireMaker_N1_cl.Wire();
	/*BRepBuilderAPI_MakeWire three_wireMaker_N1_cl(three_edge_N1_cl);
	TopoDS_Wire three_wire_N1_cl = three_wireMaker_N1_cl.Wire();*/


	////����Բ���εĸֽ�ε���������
	//TopoDS_Edge arcEdge_N1_cl = BRepBuilderAPI_MakeEdge(new Geom_Circle(center_axis_N1_cl, radius_N1_cl * 6), startAngle_N1_cl, endAngle_N1_cl);
	//BRepBuilderAPI_MakeWire wireBuilder_N1_cl;
	//wireBuilder_N1_cl.Add(arcEdge_N1_cl);
	//TopoDS_Wire wire_N1_cl = wireBuilder_N1_cl.Wire();


	// ����Բ��N1
	BRepBuilderAPI_MakeFace one_x_faceMaker_N1_cl(one_x_wire_N1_cl);
	TopoDS_Face one_x_face_N1_cl = one_x_faceMaker_N1_cl.Face();
	gp_Vec one_x_extrusionVec_N1_cl(45.0, 0.0, 0.0); // ���� X �᷽������ 45 ����λ
	BRepPrimAPI_MakePrism one_x_make_N1_cl(one_x_face_N1_cl, one_x_extrusionVec_N1_cl);
	TopoDS_Shape one_x_Shape_N1_cl = one_x_make_N1_cl.Shape();

	BRepBuilderAPI_MakeFace one_y_faceMaker_N1_cl(one_y_wire_N1_cl);
	TopoDS_Face one_y_face_N1_cl = one_y_faceMaker_N1_cl.Face();
	gp_Vec one_y_extrusionVec_N1_cl(0.0, two_N1_cl.Y() - one_N1_cl.Y(), 0.0);
	//gp_Vec one_y_extrusionVec_N1_cl(0.0, long_vertical_N1 - 6 * radius_N1_cl, 0.0); // ���� y �᷽������
	BRepPrimAPI_MakePrism one_y_make_N1_cl(one_y_face_N1_cl, one_y_extrusionVec_N1_cl);
	TopoDS_Shape one_y_Shape_N1_cl = one_y_make_N1_cl.Shape();

	BRepBuilderAPI_MakeFace two_faceMaker_N1_cl(two_wire_N1_cl);
	TopoDS_Face two_face_N1_cl = two_faceMaker_N1_cl.Face();
	//TopoDS_Shape two_arcshape_N1_cl = BRepOffsetAPI_MakePipe(wire_N1_cl, two_face_N1_cl).Shape();

	//gp_Vec two_extrusionVec_N1_cl(radius_N1_cl * 2 * R2, 0.0, 0.0); // ���� X �᷽������ 14.4 ����λ
	gp_Vec two_extrusionVec_N1_cl(5.0, 0.0, 0.0);
	BRepPrimAPI_MakePrism two_make_N1_cl(two_face_N1_cl, two_extrusionVec_N1_cl);
	TopoDS_Shape two_Shape_N1_cl = two_make_N1_cl.Shape();


	// �������Ĺ���������ֽ�N1����壨��ࣩ
	TopoDS_Compound compound_N1_cl;
	BRep_Builder builder_N1_cl;
	builder_N1_cl.MakeCompound(compound_N1_cl);
	builder_N1_cl.Add(compound_N1_cl, one_x_Shape_N1_cl);
	builder_N1_cl.Add(compound_N1_cl, one_y_Shape_N1_cl);
	//builder_N1_cl.Add(compound_N1_cl, two_arcshape_N1_cl);
	builder_N1_cl.Add(compound_N1_cl, two_Shape_N1_cl);
	Handle(AIS_Shape) Aiscompound_N1_cl = new AIS_Shape(compound_N1_cl);
	Aiscompound_N1_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(Aiscompound_N1_cl, Standard_True);


	// �������Ĺ���������ֽ�N1������y��Գ���
	BRepBuilderAPI_Transform transform_N1_cl(compound_N1_cl, mirrorTransform_GC);
	transform_N1_cl.Build();
	TopoDS_Shape transformedShape_N1_cl = transform_N1_cl.Shape();
	Handle(AIS_Shape) AistransformedShape_N1_cl = new AIS_Shape(transformedShape_N1_cl);
	AistransformedShape_N1_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AistransformedShape_N1_cl, Standard_True);


	// �������Ĺ��������еĸֽ�N2
	Standard_Real long_horizontal_N2 = 93.0;
	Standard_Real protect1_layer_N2 = 5.0;
	Standard_Real protect2_layer_N2 = 3.5;
	Standard_Real radius_N2_cl = 0.6; // �ֽ�N2�뾶
	gp_Pnt O1_N2_cl(-long_horizontal_N2 / 2.0, P1_GC.Y() - centergroove_Ylength - width_gover_gap_GC - protect1_layer_N2, -protect1_layer_N2); // ѡȡ�ֽ�ĳ������
	gp_Ax2 O1_axis_N2_cl(O1_N2_cl, normal_x_s);

	// ����Բ����N2
	Handle(Geom_Circle) O1_circle_N2_cl = new Geom_Circle(O1_axis_N2_cl, radius_N2_cl);
	BRepBuilderAPI_MakeEdge O1_edgeMaker_N2_cl(O1_circle_N2_cl);
	TopoDS_Edge O1_edge_N2_cl = O1_edgeMaker_N2_cl.Edge();

	// ������ȦN2
	BRepBuilderAPI_MakeWire O1_wireMaker_N2_cl(O1_edge_N2_cl);
	TopoDS_Wire O1_wire_N2_cl = O1_wireMaker_N2_cl.Wire();

	// ����Բ��N2
	BRepBuilderAPI_MakeFace O1_faceMaker_N2_cl(O1_wire_N2_cl);
	TopoDS_Face O1_face_N2_cl = O1_faceMaker_N2_cl.Face();
	gp_Vec O1_extrusionVec_N2_cl(93.0, 0.0, 0.0); // ���� X �᷽������ 93 ����λ
	BRepPrimAPI_MakePrism O1_make_N2_cl(O1_face_N2_cl, O1_extrusionVec_N2_cl);
	TopoDS_Shape O1_Shape_N2_cl = O1_make_N2_cl.Shape();
	Handle(AIS_Shape) AisO1_Shape_N2_cl = new AIS_Shape(O1_Shape_N2_cl);
	AisO1_Shape_N2_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AisO1_Shape_N2_cl, Standard_True);


	// �������Ĺ��������еĸֽ�N3
	Standard_Real protect1_layer_N3 = 4.2;
	Standard_Real protect2_layer_N3 = 3.5;
	Standard_Real protect3_layer_N3 = 5.0;
	//Standard_Real startAngle_N3_cl = 0.0 * M_PI; // ��ʼ�Ƕ�
	//Standard_Real endAngle_N3_cl = 0.5 * M_PI; // ��ֹ�Ƕ�
	Standard_Real long_vertical_N3 = centerconcrete_Ylength - width_gover_gap_GC - protect1_layer_N3 - protect2_layer_N3;
	Standard_Real radius_N3_cl = 0.6; // �ֽ�N3�뾶
	gp_Pnt one_N3_cl(-centergroove_Xlength / 2 - protect3_layer_N3, P1_GC.Y() - width_gover_gap_GC - protect1_layer_N3, -protect3_layer_N3);
	//gp_Pnt one_N3_cl(-centergroove_Xlength / 2 - protect3_layer_N3, P1_GC.Y() - width_gover_gap_GC - protect1_layer_N3 - 6 * radius_N3_cl, -protect3_layer_N3);
	//gp_Pnt two_N3_cl(-centergroove_Xlength / 2 - protect3_layer_N3 - 6 * radius_N3_cl, P1_GC.Y() - width_gover_gap_GC - protect1_layer_N3, -protect3_layer_N3);
	//gp_Pnt center_N3_cl(-centergroove_Xlength / 2 - protect3_layer_N3 - 6 * radius_N3_cl, P1_GC.Y() - width_gover_gap_GC - protect1_layer_N3 - 6 * radius_N3_cl, -protect3_layer_N3);

	gp_Ax2 one_yaxis_N3_cl(one_N3_cl, normal_y_s);
	gp_Ax2 one_xaxis_N3_cl(one_N3_cl, normal_x_s);
	//gp_Ax2 center_axis_N3_cl(center_N3_cl, normal_z_s);

	// ����Բ����N3
	Handle(Geom_Circle) one_ycircle_N3_cl = new Geom_Circle(one_yaxis_N3_cl, radius_N3_cl);
	BRepBuilderAPI_MakeEdge one_yedgeMaker_N3_cl(one_ycircle_N3_cl);
	TopoDS_Edge one_yedge_N3_cl = one_yedgeMaker_N3_cl.Edge();
	Handle(Geom_Circle) one_xcircle_N3_cl = new Geom_Circle(one_xaxis_N3_cl, radius_N3_cl);
	BRepBuilderAPI_MakeEdge one_xedgeMaker_N3_cl(one_xcircle_N3_cl);
	TopoDS_Edge one_xedge_N3_cl = one_xedgeMaker_N3_cl.Edge();

	// ������ȦN3
	BRepBuilderAPI_MakeWire one_ywireMaker_N3_cl(one_yedge_N3_cl);
	TopoDS_Wire one_ywire_N3_cl = one_ywireMaker_N3_cl.Wire();
	BRepBuilderAPI_MakeWire one_xwireMaker_N3_cl(one_xedge_N3_cl);
	TopoDS_Wire one_xwire_N3_cl = one_xwireMaker_N3_cl.Wire();

	////����Բ���εĸֽ�ε���������
	//TopoDS_Edge arcEdge_N3_cl = BRepBuilderAPI_MakeEdge(new Geom_Circle(center_axis_N3_cl, radius_N3_cl * 6), startAngle_N3_cl, endAngle_N3_cl);
	//BRepBuilderAPI_MakeWire wireBuilder_N3_cl;
	//wireBuilder_N3_cl.Add(arcEdge_N3_cl);
	//TopoDS_Wire wire_N3_cl = wireBuilder_N3_cl.Wire();

	// ����Բ��N3
	BRepBuilderAPI_MakeFace one_yfaceMaker_N3_cl(one_ywire_N3_cl);
	TopoDS_Face one_yface_N3_cl = one_yfaceMaker_N3_cl.Face();
	gp_Vec one_yextrusionVec_N3_cl(0.0, -long_vertical_N3, 0.0); // ���� y �᷽������
	BRepPrimAPI_MakePrism one_ymake_N3_cl(one_yface_N3_cl, one_yextrusionVec_N3_cl);
	TopoDS_Shape one_yShape_N3_cl = one_ymake_N3_cl.Shape();

	//TopoDS_Shape one_arcshape_N1_cl = BRepOffsetAPI_MakePipe(wire_N3_cl, one_face_N3_cl).Shape();

	BRepBuilderAPI_MakeFace one_xfaceMaker_N3_cl(one_xwire_N3_cl);
	TopoDS_Face one_xface_N3_cl = one_xfaceMaker_N3_cl.Face();
	//gp_Vec two_extrusionVec_N3_cl(-24 * radius_N3_cl, 0.0, 0.0); // ���� x �᷽������
	gp_Vec one_xextrusionVec_N3_cl(-5.0, 0.0, 0.0); // ���� x �᷽������
	BRepPrimAPI_MakePrism one_xmake_N3_cl(one_xface_N3_cl, one_xextrusionVec_N3_cl);
	TopoDS_Shape one_xShape_N3_cl = one_xmake_N3_cl.Shape();

	// �������Ĺ���������ֽ�N3����壨��ࣩ
	TopoDS_Compound compound_N3_cl;
	BRep_Builder builder_N3_cl;
	builder_N3_cl.MakeCompound(compound_N3_cl);
	builder_N3_cl.Add(compound_N3_cl, one_yShape_N3_cl);
	//builder_N3_cl.Add(compound_N3_cl, one_arcshape_N1_cl);
	builder_N3_cl.Add(compound_N3_cl, one_xShape_N3_cl);
	Handle(AIS_Shape) Aiscompound_N3_cl = new AIS_Shape(compound_N3_cl);
	Aiscompound_N3_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(Aiscompound_N3_cl, Standard_True);

	// �������Ĺ���������ֽ�N3������y��Գ���
	BRepBuilderAPI_Transform transform_N3_cl(compound_N3_cl, mirrorTransform_GC);
	transform_N3_cl.Build();
	TopoDS_Shape transformedShape_N3_cl = transform_N3_cl.Shape();
	Handle(AIS_Shape) AistransformedShape_N3_cl = new AIS_Shape(transformedShape_N3_cl);
	AistransformedShape_N3_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AistransformedShape_N3_cl, Standard_True);


	// �������Ĺ��������еĸֽ�N5
	Standard_Real protect1_layer_N5 = 3.5;
	Standard_Real protect2_layer_N5 = 5.0;
	Standard_Real long_vertical_N5 = 13.0;
	Standard_Real distance1_N5 = 6.15;
	Standard_Real radius_N5_cl = 0.4; // �ֽ�N5�뾶
	gp_Pnt O1_N5_cl(-centergroove_Xlength / 2.0 - protect1_layer_N5, P1_GC.Y() - centerconcrete_Ylength + distance1_N5, -protect2_layer_N5);
	gp_Ax2 O1_axis_N5_cl(O1_N5_cl, normal_x_s);

	// ����Բ����N5
	Handle(Geom_Circle) O1_circle_N5_cl = new Geom_Circle(O1_axis_N5_cl, radius_N5_cl);
	BRepBuilderAPI_MakeEdge O1_edgeMaker_N5_cl(O1_circle_N5_cl);
	TopoDS_Edge O1_edge_N5_cl = O1_edgeMaker_N5_cl.Edge();

	// ������ȦN5
	BRepBuilderAPI_MakeWire O1_wireMaker_N5_cl(O1_edge_N5_cl);
	TopoDS_Wire O1_wire_N5_cl = O1_wireMaker_N5_cl.Wire();

	// ����Բ��N5
	BRepBuilderAPI_MakeFace O1_faceMaker_N5_cl(O1_wire_N5_cl);
	TopoDS_Face O1_face_N5_cl = O1_faceMaker_N5_cl.Face();
	gp_Vec O1_extrusionVec_N5_cl(-long_vertical_N5, 0.0, 0.0); // ���� X �᷽������ 
	BRepPrimAPI_MakePrism O1_make_N5_cl(O1_face_N5_cl, O1_extrusionVec_N5_cl);
	TopoDS_Shape O1_Shape_N5_cl = O1_make_N5_cl.Shape();

	Standard_Real offsetDistance1_N5_cl = 16.67;
	Standard_Real offsetDistance2_N5_cl = 19.0;

	gp_Vec translationVector1_N5_cl(0.0, offsetDistance1_N5_cl, 0.0);
	gp_Vec translationVector2_N5_cl(0.0, offsetDistance1_N5_cl + offsetDistance2_N5_cl, 0.0);
	gp_Vec translationVector3_N5_cl(0.0, offsetDistance1_N5_cl + offsetDistance2_N5_cl * 2, 0.0);
	gp_Vec translationVector4_N5_cl(0.0, offsetDistance1_N5_cl + offsetDistance2_N5_cl * 3, 0.0);
	gp_Vec translationVector5_N5_cl(0.0, offsetDistance1_N5_cl + offsetDistance2_N5_cl * 4, 0.0);


	TopoDS_Shape offShape1_N5_cl = CopyAndTranslateShape(O1_Shape_N5_cl, translationVector1_N5_cl);
	TopoDS_Shape offShape2_N5_cl = CopyAndTranslateShape(O1_Shape_N5_cl, translationVector2_N5_cl);
	TopoDS_Shape offShape3_N5_cl = CopyAndTranslateShape(O1_Shape_N5_cl, translationVector3_N5_cl);
	TopoDS_Shape offShape4_N5_cl = CopyAndTranslateShape(O1_Shape_N5_cl, translationVector4_N5_cl);
	TopoDS_Shape offShape5_N5_cl = CopyAndTranslateShape(O1_Shape_N5_cl, translationVector5_N5_cl);

	// �������Ĺ���������ֽ�N5����壨��ࣩ
	TopoDS_Compound compound_N5_cl;
	BRep_Builder builder_N5_cl;
	builder_N5_cl.MakeCompound(compound_N5_cl);
	builder_N5_cl.Add(compound_N5_cl, O1_Shape_N5_cl);
	builder_N5_cl.Add(compound_N5_cl, offShape1_N5_cl);
	builder_N5_cl.Add(compound_N5_cl, offShape2_N5_cl);
	builder_N5_cl.Add(compound_N5_cl, offShape3_N5_cl);
	builder_N5_cl.Add(compound_N5_cl, offShape4_N5_cl);
	builder_N5_cl.Add(compound_N5_cl, offShape5_N5_cl);
	Handle(AIS_Shape) Aiscompound_N5_cl = new AIS_Shape(compound_N5_cl);
	Aiscompound_N5_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(Aiscompound_N5_cl, Standard_True);

	// �������Ĺ���������ֽ�N5������y��Գ���
	BRepBuilderAPI_Transform transform_N5_cl(compound_N5_cl, mirrorTransform_GC);
	transform_N5_cl.Build();
	TopoDS_Shape transformedShape_N5_cl = transform_N5_cl.Shape();
	Handle(AIS_Shape) AistransformedShape_N5_cl = new AIS_Shape(transformedShape_N5_cl);
	AistransformedShape_N5_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AistransformedShape_N5_cl, Standard_True);


	// �������Ĺ��������еĸֽ�N5a
	Standard_Real protect1_layer_N5a = 3.5;
	Standard_Real protect2_layer_N5a = 5.0;
	Standard_Real distance1_N5a = 20.0;
	Standard_Real long_vertical_N5a = 18.0;
	Standard_Real radius_N5a_cl = 0.4; // �ֽ�N5a�뾶
	gp_Pnt O1_N5a_cl(-distance1_N5a, P1_GC.Y() - centergroove_Ylength - width_gover_gap_GC - protect1_layer_N5a, -protect2_layer_N5a);
	gp_Ax2 O1_axis_N5a_cl(O1_N5a_cl, normal_y_s);

	// ����Բ����N5a
	Handle(Geom_Circle) O1_circle_N5a_cl = new Geom_Circle(O1_axis_N5a_cl, radius_N5a_cl);
	BRepBuilderAPI_MakeEdge O1_edgeMaker_N5a_cl(O1_circle_N5a_cl);
	TopoDS_Edge O1_edge_N5a_cl = O1_edgeMaker_N5a_cl.Edge();

	// ������ȦN5a
	BRepBuilderAPI_MakeWire O1_wireMaker_N5a_cl(O1_edge_N5a_cl);
	TopoDS_Wire O1_wire_N5a_cl = O1_wireMaker_N5a_cl.Wire();

	// ����Բ��N5a
	BRepBuilderAPI_MakeFace O1_faceMaker_N5a_cl(O1_wire_N5a_cl);
	TopoDS_Face O1_face_N5a_cl = O1_faceMaker_N5a_cl.Face();
	gp_Vec O1_extrusionVec_N5a_cl(0.0, -long_vertical_N5a, 0.0); // ���� y �᷽������ 
	BRepPrimAPI_MakePrism O1_make_N5a_cl(O1_face_N5a_cl, O1_extrusionVec_N5a_cl);
	TopoDS_Shape O1_Shape_N5a_cl = O1_make_N5a_cl.Shape();
	Handle(AIS_Shape) AisO1_Shape_N5a_cl = new AIS_Shape(O1_Shape_N5a_cl);
	AisO1_Shape_N5a_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AisO1_Shape_N5a_cl, Standard_True);

	// �������Ĺ���������ֽ�N5a������y��Գ���
	BRepBuilderAPI_Transform transform_N5a_cl(O1_Shape_N5a_cl, mirrorTransform_GC);
	transform_N5a_cl.Build();
	TopoDS_Shape transformedShape_N5a_cl = transform_N5a_cl.Shape();
	Handle(AIS_Shape) AistransformedShape_N5a_cl = new AIS_Shape(transformedShape_N5a_cl);
	AistransformedShape_N5a_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AistransformedShape_N5a_cl, Standard_True);

	// �������Ĺ��������еĸֽ�N4
	Standard_Real protect1_layer_N4 = 3.5;
	Standard_Real protect2_layer_N4 = 5.0;
	Standard_Real distance1_N4 = 20.0;
	Standard_Real long_vertical_N4 = 18.0;
	Standard_Real radius_N4_cl = 0.6; // �ֽ�N4�뾶
	gp_Pnt O1_N4_cl(-distance1_N4, P1_GC.Y() - centergroove_Ylength - width_gover_gap_GC - protect1_layer_N4, -protect2_layer_N4);
	gp_Ax2 O1_axis_N4_cl(O1_N4_cl, normal_z_s);

	// ����Բ����N4
	Handle(Geom_Circle) O1_circle_N4_cl = new Geom_Circle(O1_axis_N4_cl, radius_N4_cl);
	BRepBuilderAPI_MakeEdge O1_edgeMaker_N4_cl(O1_circle_N4_cl);
	TopoDS_Edge O1_edge_N4_cl = O1_edgeMaker_N4_cl.Edge();

	// ������ȦN4
	BRepBuilderAPI_MakeWire O1_wireMaker_N4_cl(O1_edge_N4_cl);
	TopoDS_Wire O1_wire_N4_cl = O1_wireMaker_N4_cl.Wire();

	// ����Բ��N4
	BRepBuilderAPI_MakeFace O1_faceMaker_N4_cl(O1_wire_N4_cl);
	TopoDS_Face O1_face_N4_cl = O1_faceMaker_N4_cl.Face();
	gp_Vec O1_extrusionVec_N4_cl(0.0, -long_vertical_N4, 0.0); // ���� y �᷽������ 
	BRepPrimAPI_MakePrism O1_make_N4_cl(O1_face_N4_cl, O1_extrusionVec_N4_cl);
	TopoDS_Shape O1_Shape_N4_cl = O1_make_N4_cl.Shape();
	Handle(AIS_Shape) AisO1_Shape_N4_cl = new AIS_Shape(O1_Shape_N4_cl);
	AisO1_Shape_N4_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AisO1_Shape_N4_cl, Standard_True);

	//// �������Ĺ���������ֽ�N4������y��Գ���
	//BRepBuilderAPI_Transform transform_N5a_cl(O1_Shape_N5a_cl, mirrorTransform_GC);
	//transform_N5a_cl.Build();
	//TopoDS_Shape transformedShape_N5a_cl = transform_N5a_cl.Shape();
	//Handle(AIS_Shape) AistransformedShape_N5a_cl = new AIS_Shape(transformedShape_N5a_cl);
	//AistransformedShape_N5a_cl->SetColor(Quantity_NOC_RED);
	//myOccView->getContext()->Display(AistransformedShape_N5a_cl, Standard_True);

}

void MainWindow::handleSquareCoordinates(const SquareCoordinates& coords)
{
	// ���� makeTabu() ������������ SquareCoordinates �ṹ���������
	makeTabu(coords);
}

void MainWindow::makeTabu(const SquareCoordinates& coords)
{
	// ��ջ�������
	myOccView->getContext()->EraseAll(Standard_True);  // ��Ӳ���������������ʾ����

	gp_Pnt p1(coords.P1_x, coords.P1_y, 0.0);
	gp_Pnt p2(coords.P2_x, coords.P2_y, 0.0);
	gp_Pnt p3(coords.P3_x, coords.P3_y, 0.0);
	gp_Pnt p4(coords.P4_x, coords.P4_y, 0.0);

	BRepBuilderAPI_MakePolygon polygonMaker;
	polygonMaker.Add(p1);
	polygonMaker.Add(p2);
	polygonMaker.Add(p3);
	polygonMaker.Add(p4);
	polygonMaker.Add(p1);  // �պ϶����

	TopoDS_Shape square = polygonMaker.Shape();
	Handle(AIS_Shape) anAisSquare = new AIS_Shape(square);
	anAisSquare->SetColor(Quantity_NOC_AZURE);

	myOccView->getContext()->Display(anAisSquare, Standard_True);

	// �������εĵ� P1 ����ʾ�����ǩ
	Handle_AIS_TextLabel anAisLabel = new AIS_TextLabel();
	QString coordText = QString("(%1, %2)").arg(p1.X()).arg(p1.Y());
	anAisLabel->SetText(coordText.toStdString().c_str());
	//anAisLabel->SetTextPosition(p1.X(), p1.Y(), p1.Z() + 1.0);  // ����ǩλ����΢̧��һЩ���������������ص�
	anAisLabel->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	myOccView->getContext()->Display(anAisLabel, Standard_True);
}


void MainWindow::onTreeWidgetItemClicked1(QTreeWidgetItem *item, int column)
{
	if (item && column == 0)
	{
		QString text = item->text(column);
		if (text == QString("������"))
		{
			emit par11();
		}
		if (text == QString("����"))
		{
			emit par12();
		}
		if (text == QString("����"))
		{
			emit par13();
		}
		if (text == QString("������̤��"))
		{
			emit par14();
		}
		if (text == QString("����ʽñ��"))
		{
			emit par15();
		}
		if (text == QString("���Ĺ�"))
		{
			emit par12_1();
		}
		if (text == QString("�๵"))
		{
			emit par12_2();
		}
	}
}

void MainWindow::onTreeWidgetItemClicked2(QTreeWidgetItem *item, int column)
{
	/*if (item && column == 0)
	{
		QString text = item->text(column);
		if (text == QString("������"))
		{
			emit par1();
		}
		if (text == QString("����"))
		{
			emit par2();
		}
		if (text == QString("����"))
		{
			emit par3();
		}
		if (text == QString("������̤��"))
		{
			emit par4();
		}
		if (text == QString("��֧"))
		{
			emit par5();
		}
		if (text == QString("����ˮ"))
		{
			emit par6();
		}
		if (text == QString("���Ĺ�"))
		{
			emit par2_1();
		}
		if (text == QString("�๵"))
		{
			emit par2_2();
		}
		if (text == QString("��֧���"))
		{
			emit par4_1();
		}
		if (text == QString("�͸ָּ�"))
		{
			emit par4_2();
		}
	}*/
	if (item && column == 0)
	{
		QString text = item->text(column);
		if (text == QString("������������"))
		{
			emit par1();
		}
		if (text == QString("��֧"))
		{
			emit par2();
		}
		if (text == QString("����̤��������"))
		{
			emit par3();
		}
		if (text == QString("����ˮ"))
		{
			emit par4();
		}
		if (text == QString("��֧"))
		{
			emit par5();
		}
		if (text == QString("����ˮ"))
		{
			emit par6();
		}
		if (text == QString("���Ĺ�"))
		{
			emit par3_1();
		}
		if (text == QString("�๵"))
		{
			emit par3_2();
		}
		if (text == QString("��֧���"))
		{
			emit par2_1();
		}
		if (text == QString("�͸ָּ�"))
		{
			emit par2_2();
		}
	}
}


void MainWindow::showFirstSurpport(const SquareCoordinates2& coords)
{
	makeFirstSurpport(coords);
};

void MainWindow::makeFirstSurpport(const SquareCoordinates2& coords) {
	// ��ջ�������
	//myOccView->getContext()->EraseAll(Standard_True);

	double firstSurppWall_Thick = coords.P1_x;
	double invertedArch_Thick = coords.P2_x;
	double line1AndCent_Distance = coords.P3_x;
	double line1AndLine2_Distance = coords.P4_x;
	double cirConnn_Thick = coords.P5_x;
	double arch_Angle = coords.P6_x;
	double archAnch_Distance = coords.P7_x;
	double wallAnch_Distance = coords.P8_x;



	/*****����*****/
	// ����Բ O1  �����ڲ࣬665�뾶 
	gp_Pnt P_CO1_NLK(0.0, 0.0, 0.0); // ԭ��ΪԲ��
	gp_Ax2 axis1(P_CO1_NLK, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	double R1_NLK = secondaryLiningObj.getValue(22); // ����Բ�İ뾶
	gp_Circ CO1_NLK(axis1, R1_NLK);
	Handle(Geom_Circle) geomCircle1_NLK = new Geom_Circle(CO1_NLK);
	TopoDS_Edge edge1_NLK = BRepBuilderAPI_MakeEdge(geomCircle1_NLK);

	// ����ԭ����д���
	BRepBuilderAPI_MakeEdge edge(gp_Pnt(0, -1000, 0), gp_Pnt(0, 1000, 0));
	TopoDS_Shape shape3 = edge.Shape();
	// ����Բ�ĵ��� P �ľ��� �ǰ�����߶�
	double radius = R1_NLK;
	double radius3 = secondaryLiningObj.getValue(23); // ԲO3�İ뾶
	Standard_Real JibenKuandu = secondaryLiningObj.getValue(29);
	Standard_Real GoucaoKuandu = secondaryLiningObj.getValue(27);
	double height = sqrt(pow(radius, 2) - pow((GoucaoKuandu + JibenKuandu / 2), 2));
	double distanceCenterToP = sqrt(pow(radius, 2) + pow(630, 2)) - radius;
	gp_Pnt pointP(0, -height, 0);

	//// ����Բ�ĵ��� P �ľ��� �ǰ�����߶�
	//Standard_Real R1_NLK = 665.0;
	//Standard_Real R3_NLK = 1720; // ԲO3�İ뾶
	//Standard_Real height = sqrt(pow(R1_NLK, 2) - pow(630, 2));
	//Standard_Real distanceCenterToP = sqrt(pow(R1_NLK, 2) + pow(630, 2)) - R1_NLK;
	//gp_Pnt pointP(0, -height, 0);

	// ȷ���µ�Բ�� P3  ����Բ��
	gp_Pnt pointP3(0, radius3 - secondaryLiningObj.getValue(26) - secondaryLiningObj.getValue(28) - height, 0);//180��30��ı䣡����


	double alpha = acos(-pointP.Y() / radius);
	////����Ƕ� alpha  ȷ�����ɶ�Բ�뾶�ò���
	//Standard_Real alpha = acos(-pointP.Y() / R1_NLK);
	// ����Բ�ĵ��� P ���߶�
	BRepBuilderAPI_MakeEdge edgeP(gp_Pnt(0, 0, 0), pointP);
	TopoDS_Shape shapeP = edgeP.Shape();

	// ����Բ O3  �����ڲ�Բ
	gp_Ax2 axis03(pointP3, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
												   //											   // ����Բ O3  �����ڲ�Բ
												   //gp_Ax2 axis03(P_CO3_NLK, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	double radius03 = secondaryLiningObj.getValue(23); // �뾶Ϊ 1720cm
	gp_Circ circle03(axis03, radius03);
	Handle(Geom_Circle) geomCircle03 = new Geom_Circle(circle03);
	TopoDS_Edge edge03 = BRepBuilderAPI_MakeEdge(geomCircle03);
	//Standard_Real R3_NLK = 1720.0; // �뾶Ϊ 1720cm
	//gp_Circ circle03(axis03, R3_NLK);
	//Handle(Geom_Circle) geomCO3_NLK = new Geom_Circle(CO3_NLK);
	//TopoDS_Edge edgeO3_NLK = BRepBuilderAPI_MakeEdge(geomCO3_NLK);

	//����radius4  �ڲ���ɶ�Բ�뾶
	double m = pow(radius3, 2) - pow(radius, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*height;
	double n = radius3 - radius - pointP3.Y() *height / radius;
	double radius4 = m / (2 * n);
	// ����Բ O4  ���ɶ��ڲ�Բ  ���
	gp_Pnt centerO4(-sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	gp_Circ circle4(axis4, radius4);
	Handle(Geom_Circle) geomCircle4 = new Geom_Circle(circle4);
	TopoDS_Edge edge4 = BRepBuilderAPI_MakeEdge(geomCircle4);

	////����radius4  �ڲ���ɶ�Բ�뾶
	//Standard_Real m = pow(R3_NLK, 2) - pow(R1_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*height;
	//Standard_Real n = R3_NLK - R1_NLK - P_CO3_NLK.Y() *height / R1_NLK;
	//Standard_Real R4_NLK = m / (2 * n);
	//// ����Բ O4  ���ɶ��ڲ�Բ  ���
	//gp_Pnt centerO4(-sin(alpha) * (R1_NLK - R4_NLK), -cos(alpha) * (R1_NLK - R4_NLK), 0);
	//gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	//gp_Circ CO4_NLK(axis4, R4_NLK);
	//Handle(Geom_Circle) geomCO4_NLK = new Geom_Circle(CO4_NLK);
	//TopoDS_Edge edgeO4_NLK= BRepBuilderAPI_MakeEdge(geomCO4_NLK);

	// ����Բ O7  ���ɶ��ڲ�Բ  �Ҳ�
	gp_Pnt centerO7(sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis7(centerO7, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	gp_Circ circle7(axis7, radius4);
	Handle(Geom_Circle) geomCircle7 = new Geom_Circle(circle7);
	TopoDS_Edge edge7 = BRepBuilderAPI_MakeEdge(geomCircle7);


	///���ƹ�ǽ�ڲ໡�ߣ���֪����Բ�ġ���㡢�뾶
	double R_O1 = R1_NLK;//�뾶
	gp_Circ Circle_O1_EC(axis1, R_O1);
	gp_Ax3 AxO1(axis1);
	gp_Cylinder Cylinder_O1(AxO1, R_O1);//��������Բ����

	Handle(Geom_CylindricalSurface) geoCylinder_O1 = new Geom_CylindricalSurface(Cylinder_O1);
	GeomAPI_IntCS ICC_O4_01(geomCircle4, geoCylinder_O1);//��Բ04��Բ����cylinder01����
	gp_Pnt CUT_O4_01 = ICC_O4_01.Point(1);

	GeomAPI_IntCS ICC_O7_01(geomCircle7, geoCylinder_O1);//��Բ07��Բ����cylinder01����
	gp_Pnt CUT_O7_01 = ICC_O7_01.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O1_EC, CUT_O7_01, CUT_O4_01, false);//�����������Բ��
	TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	Handle(AIS_Shape) aTarcCurve_01 = new AIS_Shape(TarcCurve_01);
	aTarcCurve_01->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_01, Standard_True);*/



	///���������ڲ໡�ߣ���֪����Բ�ġ���㡢�뾶
	double R_O3 = radius3;//�뾶
						  /////���������ڲ໡�ߣ���֪����Բ�ġ���㡢�뾶
						  //Standard_Real R_O3 = R3_NLK;//�뾶
	gp_Circ Circle_O3_EC(axis03, R_O3);
	gp_Ax3 AxO3(axis03);
	gp_Cylinder Cylinder_O3(AxO3, R_O3);//��������Բ����

	Handle(Geom_CylindricalSurface) geoCylinder_O3 = new Geom_CylindricalSurface(Cylinder_O3);
	GeomAPI_IntCS ICC_O4_03(geomCircle4, geoCylinder_O3);//��Բ04��Բ����cylinder01����
	gp_Pnt CUT_O4_03 = ICC_O4_03.Point(1);

	GeomAPI_IntCS ICC_O7_03(geomCircle7, geoCylinder_O3);//��Բ07��Բ����cylinder01����
	gp_Pnt CUT_O7_03 = ICC_O7_03.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_03 = GC_MakeArcOfCircle(Circle_O3_EC, CUT_O4_03, CUT_O7_03, false);//�����������Բ��
	TopoDS_Edge TarcCurve_03 = BRepBuilderAPI_MakeEdge(arcCurve_03);
	Handle(AIS_Shape) aTarcCurve_03 = new AIS_Shape(TarcCurve_03);
	aTarcCurve_03->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_03, Standard_True);*/

	///���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
	double R_O4 = radius4;//�뾶
						  /////���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
						  //Standard_Real R_O4 = R4_NLK;//�뾶
	gp_Circ Circle_O4_EC(axis4, R_O4);
	gp_Ax3 AxO4(axis4);
	gp_Cylinder Cylinder_O4(AxO4, R_O4);//��������Բ����

	Handle(Geom_TrimmedCurve) arcCurve_04 = GC_MakeArcOfCircle(Circle_O4_EC, CUT_O4_01, CUT_O4_03, false);//�����������Բ��
	TopoDS_Edge TarcCurve_04 = BRepBuilderAPI_MakeEdge(arcCurve_04);
	Handle(AIS_Shape) aTarcCurve_04 = new AIS_Shape(TarcCurve_04);
	aTarcCurve_04->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_04, Standard_True);*/

	///���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
	double R_O7 = radius4;//�뾶
						  // ///���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
						  //Standard_Real R_O7 = R4_NLK;//�뾶
	gp_Circ Circle_O7_EC(axis7, R_O7);
	gp_Ax3 AxO7(axis7);
	gp_Cylinder Cylinder_O7(AxO7, R_O7);//��������Բ����

	Handle(Geom_TrimmedCurve) arcCurve_07 = GC_MakeArcOfCircle(Circle_O7_EC, CUT_O7_03, CUT_O7_01, false);//�����������Բ��
	TopoDS_Edge TarcCurve_07 = BRepBuilderAPI_MakeEdge(arcCurve_07);
	Handle(AIS_Shape) aTarcCurve_07 = new AIS_Shape(TarcCurve_07);
	aTarcCurve_07->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_07, Standard_True);*/



	// ����Բ O2  ������࣬665+55�뾶
	gp_Pnt P_CO2_NLK(0.0, 0.0, 0.0); // ԭ��ΪԲ��
	gp_Ax2 axis2(P_CO2_NLK, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	double R2_NLK = R1_NLK+ secondaryLiningObj.getValue(24); // ����Բ�İ뾶
	gp_Circ CO2_NLK(axis2, R2_NLK);
	Handle(Geom_Circle) geomCircle2 = new Geom_Circle(CO2_NLK);
	TopoDS_Edge edge2 = BRepBuilderAPI_MakeEdge(geomCircle2);

	// ����Բ O5 �������Բ
	gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	double radius5 = radius3 + secondaryLiningObj.getValue(25); // �뾶Ϊ 1720cm+55cm
	gp_Circ circle5(axis5, radius5);
	Handle(Geom_Circle) geomCircle5 = new Geom_Circle(circle5);
	TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomCircle5);
	//// ����Բ O5 �������Բ
	//gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	//Standard_Real R5_NLK = R3_NLK + 65.0; // �뾶Ϊ 1720cm+55cm
	//gp_Circ circle5(axis5, R5_NLK);
	//Handle(Geom_Circle) geomC05_NLK = new Geom_Circle(C05_NLK);
	//TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomC05_NLK);

	//����radius6 �����ɶ�Բ�뾶
	//Standard_Real radius6 = solveForR4(alpha, radius, radius3, -pointP.Y());
	double s = pow(radius5, 2) - pow(R2_NLK, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*(height + secondaryLiningObj.getValue(24) * cos(alpha));
	double p = radius5 - R2_NLK - pointP3.Y() *(height + secondaryLiningObj.getValue(24) * cos(alpha)) / R2_NLK;
	double radius6 = s / (2 * p);
	////����radius6 �����ɶ�Բ�뾶
	////Standard_Real R6_NLK = solveForR4(alpha, R1_NLK, R3_NLK, -P_CO1_NLK());
	//Standard_Real s = pow(R5_NLK, 2) - pow(R2_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*(height+R2_NLK*alpha);
	//Standard_Real p = R5_NLK - R2_NLK - P_CO3_NLK.Y() *height / R2_NLK;
	//Standard_Real R6_NLK = s / (2 * p);


	// ����Բ O6  ���ɶ����Բ  ���
	gp_Pnt centerO6(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	gp_Circ circle6(axis6, radius6);
	Handle(Geom_Circle) geomCircle6 = new Geom_Circle(circle6);
	TopoDS_Edge edge6 = BRepBuilderAPI_MakeEdge(geomCircle6);
	//// ����Բ O6  ���ɶ����Բ  ���
	//gp_Pnt centerO6(-sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	//gp_Circ circle6(axis6, R6_NLK);
	//Handle(Geom_Circle) geomC06_NLK = new Geom_Circle(C06_NLK);
	//TopoDS_Edge edge6_NLK = BRepBuilderAPI_MakeEdge(geomC06_NLK);

	// ����Բ O8  ���ɶ����Բ  �Ҳ�
	gp_Pnt centerO8(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	gp_Circ circle8(axis8, radius6);
	Handle(Geom_Circle) geomCircle8 = new Geom_Circle(circle8);
	TopoDS_Edge edge8 = BRepBuilderAPI_MakeEdge(geomCircle8);
	//// ����Բ O8  ���ɶ����Բ  �Ҳ�
	//gp_Pnt centerO8(sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	//gp_Circ circle8(axis8, R6_NLK);
	//Handle(Geom_Circle) geomC08_NLK = new Geom_Circle(C08_NLK);
	//TopoDS_Edge edge8_NLK = BRepBuilderAPI_MakeEdge(geomC08_NLK);

	///���ƹ�ǽ��໡��
	double R_O2 = R2_NLK;//�뾶
	gp_Circ Circle_O2_EC(axis2, R_O2);
	gp_Ax3 AxO2(axis2);
	gp_Cylinder Cylinder_O2(AxO2, R_O2);//��������Բ����

	Handle(Geom_CylindricalSurface) geoCylinder_O2 = new Geom_CylindricalSurface(Cylinder_O2);

	// ����ֱ�ߵ������յ�
	gp_Pnt startPoint6_2(0, 0, 0);
	gp_Pnt endPoint6_2(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// ʹ�����ͷ��򴴽�ֱ��
	gp_Vec direction6_2(startPoint6_2, endPoint6_2);
	gp_Lin line6_2(startPoint6_2, direction6_2);
	// ����ֱ�ߵ��߶�
	TopoDS_Edge lineEdge6_2 = BRepBuilderAPI_MakeEdge(line6_2, startPoint6_2, endPoint6_2);
	Handle(Geom_Line) Geom_lineEdge6_2 = new Geom_Line(line6_2);
	// ����ֱ�ߺ�Բ����֮��Ľ���
	GeomAPI_IntCS ICC_O6_02(Geom_lineEdge6_2, geoCylinder_O2);//06 02����
	gp_Pnt CUT_O6_02_R1 = ICC_O6_02.Point(1);
	gp_Pnt CUT_O6_02_R2 = ICC_O6_02.Point(2);
	gp_Pnt CUT_O6_02;
	CUT_O6_02.SetX(CUT_O6_02_R1.X());
	CUT_O6_02.SetY(CUT_O6_02_R1.Y());
	if (CUT_O6_02_R1.X() > CUT_O6_02_R2.X()) {
		CUT_O6_02.SetX(CUT_O6_02_R2.X());
		CUT_O6_02.SetY(CUT_O6_02_R2.Y());
	}//��ù���Բ�������

	 // ����ֱ�ߵ������յ�
	gp_Pnt startPoint8_2(0, 0, 0);
	gp_Pnt endPoint8_2(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// ʹ�����ͷ��򴴽�ֱ��
	gp_Vec direction8_2(startPoint8_2, endPoint8_2);
	gp_Lin line8_2(startPoint8_2, direction8_2);
	// ����ֱ�ߵ��߶�
	TopoDS_Edge lineEdge8_2 = BRepBuilderAPI_MakeEdge(line8_2, startPoint8_2, endPoint8_2);
	Handle(Geom_Line) Geom_lineEdge8_2 = new Geom_Line(line8_2);
	// ����ֱ�ߺ�Բ����֮��Ľ���
	GeomAPI_IntCS ICC_O8_02(Geom_lineEdge8_2, geoCylinder_O2);//08 02����
	gp_Pnt CUT_O8_02_R1 = ICC_O8_02.Point(1);
	gp_Pnt CUT_O8_02_R2 = ICC_O8_02.Point(2);
	gp_Pnt CUT_O8_02;
	CUT_O8_02.SetX(CUT_O8_02_R1.X());
	CUT_O8_02.SetY(CUT_O8_02_R1.Y());
	if (CUT_O8_02_R1.X() < CUT_O8_02_R2.X()) {
		CUT_O8_02.SetX(CUT_O8_02_R2.X());
		CUT_O8_02.SetY(CUT_O8_02_R2.Y());
	}//��ù���Բ�������

	Handle(Geom_TrimmedCurve) arcCurve_02 = GC_MakeArcOfCircle(Circle_O2_EC, CUT_O8_02, CUT_O6_02, false);//�����������Բ��
	TopoDS_Edge TarcCurve_02 = BRepBuilderAPI_MakeEdge(arcCurve_02);
	Handle(AIS_Shape) aTarcCurve_02 = new AIS_Shape(TarcCurve_02);
	aTarcCurve_02->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_02, Standard_True);*/





	///����������໡��
	double R_O5 = radius5;//�뾶
	gp_Circ Circle_O5_EC(axis5, R_O5);
	gp_Ax3 AxO5(axis5);
	gp_Cylinder Cylinder_O5(AxO5, R_O5);//��������Բ����

	Handle(Geom_CylindricalSurface) geoCylinder_O5 = new Geom_CylindricalSurface(Cylinder_O5);

	// ����ֱ�ߵ������յ�
	gp_Pnt startPoint6_5(0, secondaryLiningObj.getValue(23) - secondaryLiningObj.getValue(26) - secondaryLiningObj.getValue(28) - height, 0);
	gp_Pnt endPoint6_5(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// ʹ�����ͷ��򴴽�ֱ��
	gp_Vec direction6_5(startPoint6_5, endPoint6_5);
	gp_Lin line6_5(startPoint6_5, direction6_5);
	// ����ֱ�ߵ��߶�
	TopoDS_Edge lineEdge6_5 = BRepBuilderAPI_MakeEdge(line6_5, startPoint6_5, endPoint6_5);
	Handle(Geom_Line) Geom_lineEdge6_5 = new Geom_Line(line6_5);
	// ����ֱ�ߺ�Բ����֮��Ľ���
	GeomAPI_IntCS ICC_O6_05(Geom_lineEdge6_5, geoCylinder_O5);//06 02����
	gp_Pnt CUT_O6_05_R1 = ICC_O6_05.Point(1);
	gp_Pnt CUT_O6_05_R2 = ICC_O6_05.Point(2);
	gp_Pnt CUT_O6_05;
	CUT_O6_05.SetX(CUT_O6_05_R1.X());
	CUT_O6_05.SetY(CUT_O6_05_R1.Y());
	if (CUT_O6_05_R1.X() > CUT_O6_05_R2.X()) {
		CUT_O6_05.SetX(CUT_O6_05_R2.X());
		CUT_O6_05.SetY(CUT_O6_05_R2.Y());
	}//��ù���Բ�������

	 // ����ֱ�ߵ������յ�
	gp_Pnt startPoint8_5(0, secondaryLiningObj.getValue(23) - secondaryLiningObj.getValue(26) - secondaryLiningObj.getValue(28) - height, 0);
	gp_Pnt endPoint8_5(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// ʹ�����ͷ��򴴽�ֱ��
	gp_Vec direction8_5(startPoint8_5, endPoint8_5);
	gp_Lin line8_5(startPoint8_5, direction8_5);
	// ����ֱ�ߵ��߶�
	TopoDS_Edge lineEdge8_5 = BRepBuilderAPI_MakeEdge(line8_5, startPoint8_5, endPoint8_5);
	Handle(Geom_Line) Geom_lineEdge8_5 = new Geom_Line(line8_5);
	// ����ֱ�ߺ�Բ����֮��Ľ���
	GeomAPI_IntCS ICC_O8_05(Geom_lineEdge8_5, geoCylinder_O5);//08 02����
	gp_Pnt CUT_O8_05_R1 = ICC_O8_05.Point(1);
	gp_Pnt CUT_O8_05_R2 = ICC_O8_05.Point(2);
	gp_Pnt CUT_O8_05;
	CUT_O8_05.SetX(CUT_O8_05_R1.X());
	CUT_O8_05.SetY(CUT_O8_05_R1.Y());
	if (CUT_O8_05_R1.X() < CUT_O8_05_R2.X()) {
		CUT_O8_05.SetX(CUT_O8_05_R2.X());
		CUT_O8_05.SetY(CUT_O8_05_R2.Y());
	}//��ù���Բ�������


	Handle(Geom_TrimmedCurve) arcCurve_05 = GC_MakeArcOfCircle(Circle_O5_EC, CUT_O6_05, CUT_O8_05, false);//�����������Բ��
	TopoDS_Edge TarcCurve_05 = BRepBuilderAPI_MakeEdge(arcCurve_05);
	Handle(AIS_Shape) aTarcCurve_05 = new AIS_Shape(TarcCurve_05);
	aTarcCurve_05->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_05, Standard_True);*/







	///���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
	double R_O6 = radius6;//�뾶
	gp_Circ Circle_O6_EC(axis6, R_O6);
	gp_Ax3 AxO6(axis6);
	gp_Cylinder Cylinder_O6(AxO6, R_O6);//��������Բ����

	Handle(Geom_TrimmedCurve) arcCurve_06 = GC_MakeArcOfCircle(Circle_O6_EC, CUT_O6_02, CUT_O6_05, false);//�����������Բ��
	TopoDS_Edge TarcCurve_06 = BRepBuilderAPI_MakeEdge(arcCurve_06);
	Handle(AIS_Shape) aTarcCurve_06 = new AIS_Shape(TarcCurve_06);
	aTarcCurve_06->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_06, Standard_True);*/




	///���ƹ��ɶ��Ҳ໡�ߣ���֪����Բ�ġ���㡢�뾶
	double R_O8 = radius6;//�뾶
	gp_Circ Circle_O8_EC(axis8, R_O8);
	gp_Ax3 AxO8(axis8);
	gp_Cylinder Cylinder_O8(AxO8, R_O8);//��������Բ����

	Handle(Geom_TrimmedCurve) arcCurve_08 = GC_MakeArcOfCircle(Circle_O8_EC, CUT_O8_05, CUT_O8_02, false);//�����������Բ��
	TopoDS_Edge TarcCurve_08 = BRepBuilderAPI_MakeEdge(arcCurve_08);
	Handle(AIS_Shape) aTarcCurve_08 = new AIS_Shape(TarcCurve_08);
	aTarcCurve_08->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_08, Standard_True);*/


	// ʹ�� BRepBuilderAPI_MakeWire �����պ�����
	BRepBuilderAPI_MakeWire EC_WAIwireBuilder;
	EC_WAIwireBuilder.Add(TarcCurve_02);
	EC_WAIwireBuilder.Add(TarcCurve_06);
	EC_WAIwireBuilder.Add(TarcCurve_05);
	EC_WAIwireBuilder.Add(TarcCurve_08);
	EC_WAIwireBuilder.Build();

	if (EC_WAIwireBuilder.IsDone()) {
		TopoDS_Wire EC_WAIclosedWire = EC_WAIwireBuilder.Wire();

		// ���� closedWire ���������ӳɱպϵ�������
	}
	else {
		// ������ʧ�ܵ����
	}

	//TopoDS_Wire sectorWirearc = makeWirearc.Wire();
	BRepBuilderAPI_MakeFace EC_WAIFacearc(EC_WAIwireBuilder);
	//TopoDS_Face EC_WAIFacearc = EC_WAIFacearc.Face();
	gp_Vec extrusionVecR1(0, 0, -1000.0); // ���� Z �᷽������ 1000 ����λ

	BRepPrimAPI_MakePrism EC_WAI_makearc1(EC_WAIFacearc, extrusionVecR1);
	TopoDS_Shape EC_WAI_arcShape1 = EC_WAI_makearc1.Shape();
	TopoDS_Solid EC_WAI_arcbody = TopoDS::Solid(EC_WAI_arcShape1);
	Handle(AIS_Shape) EC_WAI_Aisarcbody = new AIS_Shape(EC_WAI_arcbody);

	//EC_WAI_Aisarcbody->SetColor(Quantity_NOC_RED); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(EC_WAI_Aisarcbody, Standard_True); // �ڳ�������ʾ���ӻ�����

	// ʹ�� BRepBuilderAPI_MakeWire �����պ�����
	BRepBuilderAPI_MakeWire EC_NEIwireBuilder;
	EC_NEIwireBuilder.Add(TarcCurve_01);
	EC_NEIwireBuilder.Add(TarcCurve_04);
	EC_NEIwireBuilder.Add(TarcCurve_07);
	EC_NEIwireBuilder.Add(TarcCurve_03);
	EC_NEIwireBuilder.Build();

	if (EC_NEIwireBuilder.IsDone()) {
		TopoDS_Wire EC_NEIclosedWire = EC_NEIwireBuilder.Wire();

		// ���� closedWire ���������ӳɱպϵ�������
	}
	else {
		// ������ʧ�ܵ����
	}

	BRepBuilderAPI_MakeFace EC_NEIFacearc(EC_NEIwireBuilder);

	BRepPrimAPI_MakePrism EC_NEI_makearc1(EC_NEIFacearc, extrusionVecR1);
	TopoDS_Shape EC_NEI_arcShape1 = EC_NEI_makearc1.Shape();
	TopoDS_Solid EC_NEI_arcbody = TopoDS::Solid(EC_NEI_arcShape1);
	Handle(AIS_Shape) EC_NEI_Aisarcbody = new AIS_Shape(EC_NEI_arcbody);

	BRepAlgoAPI_Cut cutOp1(EC_WAI_arcShape1, EC_NEI_arcShape1);
	TopoDS_Shape EC_arcShape = cutOp1.Shape();

	Handle(AIS_Shape) EC_arcShape1 = new AIS_Shape(EC_arcShape);
	EC_arcShape1->SetColor(Quantity_NOC_YELLOW); // ������ɫΪ��ɫ
	/* myOccView->getContext()->Display(EC_arcShape1, Standard_True); */// �ڳ�������ʾ���ӻ�����


	 /******����******/
	 // ���Ĺ�ǽ������Բor���Ĺ�ǽ������Բ
	gp_Pnt center(0, 0, 0); // ������Բ��λ��
	double secondSurppWallOut_Rad = R2_NLK; //���Ĺ�ǽ�������뾶
	gp_Ax2 axis0(center, gp_Dir(0, 0, 1)); // Բ����
	gp_Circ secondSurppWallIn_Circ(axis0, secondSurppWallOut_Rad); // ���Ƴ�֧������Բ
	/*��ʾ*/
	/*TopoDS_Edge TC2_GQ = BRepBuilderAPI_MakeEdge(secondSurppWallIn_Circ);
    Handle(AIS_Shape) ATC2_GQ = new AIS_Shape(TC2_GQ);
    ATC2_GQ->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	myOccView->getContext()->Display(ATC2_GQ, Standard_True);*/


	//���Ĺ�ǽ������Բ
	double firstSurpportWallOuter_Rad = secondSurppWallOut_Rad + firstSurppWall_Thick;//��֧�������뾶
	gp_Ax2 axis(center, gp_Dir(0, 0, 1)); // Բ����
	gp_Circ firSurppOutCircle(axis, firstSurpportWallOuter_Rad); // ���Ƴ�֧������Բ
	//��ʾ
	/*TopoDS_Edge TC1_GQ = BRepBuilderAPI_MakeEdge(firSurppOutCircle);
    Handle(AIS_Shape) anAisEdgeP12 = new AIS_Shape(TC1_GQ);
	anAisEdgeP12->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
    myOccView->getContext()->Display(anAisEdgeP12, Standard_True);*/

	 //���ƽ���1
  // ������Ʋ���
	double line1_Length = 16000.0; // ֱ�߳���,���ڳ��Ĺ�ǽ������ֱ����ȷ���н���
	static const gp_Vec vector(1.0, 0.0, 0.0); // ƽ����X�������
	gp_Pnt StartPofLine1(-line1_Length / 2, 0 - line1AndCent_Distance, 0.0); // ��ʼ��
	gp_Dir dLine1(line1_Length, 0, 0);
	gp_Lin line1(StartPofLine1, dLine1);
	//����
	/*gp_Lin2d line1(gp_Pnt2d startPoint, gp_Pnt2d endPoint);*/
	/*Handle(Geom2d_TrimmedCurve) geomline1 = GCE2d_MakeSegment(startPoint, endPoint);*/
	/*TopoDS_Edge TLine1 = BRepBuilderAPI_MakeEdge(line1);
	Handle(AIS_Shape) aTLine1 = new AIS_Shape(TLine1);
	aTLine1->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	myOccView->getContext()->Display(aTLine1, Standard_True);*/


	//���ƽ���2
	// ������Ʋ���
	double line2_Length = 16000.0; // ֱ�߳���,���ڳ�������������ֱ����ȷ���н���
	static const gp_Vec vector2(1.0, 0.0, 0.0); // ƽ����X�������
												//double line1AndLine2_Distance = 200;//����1�����2����
	gp_Pnt startPofLine2(-line2_Length / 2, 0 - line1AndCent_Distance - line1AndLine2_Distance, 0); // ��ʼ��
	gp_Dir dLine2(line2_Length, 0, 0);
	//����
	gp_Lin line2(startPofLine2, dLine2);
	Handle(Geom_Line) geomLine2 = new Geom_Line(line2);
	/*Handle(Geom2d_TrimmedCurve) geomline2 = GCE2d_MakeSegment(startPoint2, endPoint2);*/
	/*TopoDS_Edge line = BRepBuilderAPI_MakeEdge(startPoint2, endPoint2);*/
	/*TopoDS_Edge TLine2 = BRepBuilderAPI_MakeEdge(line2);
	Handle(AIS_Shape) aTLine2 = new AIS_Shape(TLine2);
	aTLine2->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	myOccView->getContext()->Display(aTLine2, Standard_True);*/

	//�����1���������������
	// ��
	Handle(Geom_Line) geomLine1 = new Geom_Line(line1);
	gp_Ax3 aCylindSecSurppOut(axis0);
	gp_Cylinder cylindSecSurppOut(aCylindSecSurppOut, secondSurppWallOut_Rad);
	Handle(Geom_CylindricalSurface) geomCylindSecSurppOut = new Geom_CylindricalSurface(cylindSecSurppOut);//������������������Բ����
	GeomAPI_IntCS ICS_Line1AndCylindSecSurppOut(geomLine1, geomCylindSecSurppOut);//����1���������������������������
	gp_Pnt Inter1_Line1AndCylindSecSurppOut = ICS_Line1AndCylindSecSurppOut.Point(1);//��ȡ����1
	gp_Pnt Inter2_Line1AndCylindSecSurppOut = ICS_Line1AndCylindSecSurppOut.Point(2);//��ȡ����2
	gp_Pnt Inter_Line1AndCylindSecSurppOut;
	Inter_Line1AndCylindSecSurppOut.SetX(Inter1_Line1AndCylindSecSurppOut.X());
	Inter_Line1AndCylindSecSurppOut.SetY(Inter1_Line1AndCylindSecSurppOut.Y());
	if (Inter1_Line1AndCylindSecSurppOut.X() < Inter2_Line1AndCylindSecSurppOut.X()) {
		Inter_Line1AndCylindSecSurppOut.SetX(Inter2_Line1AndCylindSecSurppOut.X());
		Inter_Line1AndCylindSecSurppOut.SetY(Inter2_Line1AndCylindSecSurppOut.Y());
	}//��ȡ�����У�x����Ϊ���ĵ�

	 //��֧��������ǽ�˲��Ҳ����������˵�
	 //���
	gp_Dir Dir_LineTan1(Inter_Line1AndCylindSecSurppOut.XYZ());
	gp_Lin lineTan1(center, Dir_LineTan1);//Բ������������������
	/*TopoDS_Edge TLineTan1 = BRepBuilderAPI_MakeEdge(LineTan1);
    Handle(AIS_Shape) ATLineTan1 = new AIS_Shape(TLineTan1);
	ATLineTan1->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(ATLineTan1, Standard_True);*/
	Handle(Geom_Line) geomLineTan1 = new Geom_Line(lineTan1);//����Բ������������������
	//lineTan1��ʾ
	/*TopoDS_Edge TlineTan1 = BRepBuilderAPI_MakeEdge(lineTan1);
	Handle(AIS_Shape) aTlineTan1 = new AIS_Shape(TlineTan1);
	 aTlineTan1->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	myOccView->getContext()->Display(aTlineTan1, Standard_True);*/
	gp_Ax3 aCylindFirSurppOut(axis);
	gp_Cylinder cylindFirSurppOut(aCylindFirSurppOut, firstSurpportWallOuter_Rad);//��֧����������Բ����
	Handle(Geom_CylindricalSurface) geomCylindFirSurppOut = new Geom_CylindricalSurface(cylindFirSurppOut);
	GeomAPI_IntCS ICS_Line1AndCylindFirSurppOut(geomLineTan1, geomCylindFirSurppOut);//����LineTan1��Բ����cylinder2����
	gp_Pnt Inter1_Line1AndCylindFirSurppOut = ICS_Line1AndCylindFirSurppOut.Point(1);
	gp_Pnt Inter2_Line1AndCylindFirSurppOut = ICS_Line1AndCylindFirSurppOut.Point(2);
	gp_Pnt Inter_Line1AndCylindFirSurppOut;
	Inter_Line1AndCylindFirSurppOut.SetX(Inter1_Line1AndCylindFirSurppOut.X());
	Inter_Line1AndCylindFirSurppOut.SetY(Inter1_Line1AndCylindFirSurppOut.Y());
	if (Inter1_Line1AndCylindFirSurppOut.X() < Inter2_Line1AndCylindFirSurppOut.X()) {
		Inter_Line1AndCylindFirSurppOut.SetX(Inter2_Line1AndCylindFirSurppOut.X());
		Inter_Line1AndCylindFirSurppOut.SetY(Inter2_Line1AndCylindFirSurppOut.Y());
	}//������
	 //�����Ҳ����߶�
	gp_Pnt endPofTtanLineR(Inter_Line1AndCylindFirSurppOut.X() + (Inter_Line1AndCylindFirSurppOut.Y()*(line1AndCent_Distance + line1AndLine2_Distance + Inter_Line1AndCylindFirSurppOut.Y()) / Inter_Line1AndCylindFirSurppOut.X()), 0 - line1AndCent_Distance - line1AndLine2_Distance, 0);//���������2����
	TopoDS_Edge TtanLineR = BRepBuilderAPI_MakeEdge(Inter_Line1AndCylindFirSurppOut, endPofTtanLineR);//�����Ҳ����߶�
	Handle(AIS_Shape) aTtanLineR = new AIS_Shape(TtanLineR);
	aTtanLineR->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTtanLineR, Standard_True);*/
	//����������߶�
	gp_Pnt endPofTtanLineL(-endPofTtanLineR.X(), endPofTtanLineR.Y(), 0);
	gp_Pnt Inter_TtanLineLAndCylindFirSurppOutL(-Inter_Line1AndCylindFirSurppOut.X(), Inter_Line1AndCylindFirSurppOut.Y(), 0);
	TopoDS_Edge TtanLineL = BRepBuilderAPI_MakeEdge(Inter_TtanLineLAndCylindFirSurppOutL, endPofTtanLineL);
	Handle(AIS_Shape) aTtanLineL = new AIS_Shape(TtanLineL);
	aTtanLineL->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTtanLineL, Standard_True);*/

	//���Ƴ�������������
	//�����������������������յ�
	gp_Pnt invertedArch_Center(pointP3.X(), pointP3.Y(), pointP3.Z());//����Բ��
	gp_Dir dCut(invertedArch_Center.XYZ() - CUT_O6_05.XYZ());
	gp_Lin lCut(invertedArch_Center, dCut);//����Բ��������������߶˵�����ֱ��
	Handle(Geom_Line) geomLCut = new Geom_Line(lCut);
	//double invertedArch_Thick = 70;
	double invertedArch_Rad = R_O5 + invertedArch_Thick;//�����뾶,70Ϊ�����������
	gp_Ax2 Ax2_YG(invertedArch_Center, gp_Dir(0, 0, 1));
	//gp_Circ invertedArch_Circle(Ax2_YG, invertedArch_Rad);//��������Բ
	gp_Ax3 Ax3_YG(Ax2_YG);
	gp_Cylinder cylindInvArch(Ax3_YG, invertedArch_Rad);//��֧��������������Բ����
	Handle(Geom_CylindricalSurface) geomCylindInvArch = new Geom_CylindricalSurface(cylindInvArch);
	GeomAPI_IntCS ICS_LCutAndCylindInvArch(geomLCut, geomCylindInvArch);//����lCut��Բ����cylindInvArch����,�������������������˵�
	gp_Pnt Inter1_LCutAndCylindInvArch = ICS_LCutAndCylindInvArch.Point(1);
	gp_Pnt Inter2_LCutAndCylindInvArch = ICS_LCutAndCylindInvArch.Point(2);
	gp_Pnt Inter_LCutAndCylindInvArch;
	Inter_LCutAndCylindInvArch.SetX(Inter1_LCutAndCylindInvArch.X());
	Inter_LCutAndCylindInvArch.SetY(Inter1_LCutAndCylindInvArch.Y());
	if (Inter1_LCutAndCylindInvArch.Y() > 0) {
		Inter_LCutAndCylindInvArch.SetX(Inter2_LCutAndCylindInvArch.X());
		Inter_LCutAndCylindInvArch.SetY(Inter2_LCutAndCylindInvArch.Y());
	}//��ó����������������˵�
	gp_Pnt Pnt_YG_L(Inter_LCutAndCylindInvArch.XYZ());//�����������������˵�
	gp_Pnt Pnt_YG_R(-Pnt_YG_L.X(), Pnt_YG_L.Y(), Pnt_YG_L.Z());//���������������Ҳ�˵�
	gp_Circ invertedArch_Circle(Ax2_YG, invertedArch_Rad);//��������Բ
	Handle(Geom_TrimmedCurve) geomInvertedArch_Circle = GC_MakeArcOfCircle(invertedArch_Circle, Pnt_YG_L, Pnt_YG_R, false);//����������������Բ��
	TopoDS_Edge TInvertedArchArc = BRepBuilderAPI_MakeEdge(geomInvertedArch_Circle);
	Handle(AIS_Shape) aTInvertedArchArc = new AIS_Shape(TInvertedArchArc);
	aTInvertedArchArc->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTInvertedArchArc, Standard_True);*/

	//���Ƴ��Ĺ�ǽ������
	Handle(Geom_TrimmedCurve) geomFirSurppOutCircle = GC_MakeArcOfCircle(firSurppOutCircle, Inter_Line1AndCylindFirSurppOut, Inter_TtanLineLAndCylindFirSurppOutL, false);//��Բ��
	TopoDS_Edge TFirSurppOutCircle = BRepBuilderAPI_MakeEdge(geomFirSurppOutCircle);
	Handle(AIS_Shape) aTFirSurppOutCircle = new AIS_Shape(TFirSurppOutCircle);
	aTFirSurppOutCircle->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTFirSurppOutCircle, Standard_True);*/

	//���������빰ǽ���Ӷλ��ߣ���֪����Բ�ġ���㡢�뾶
	gp_Pnt center_CirConnL(centerO6.XYZ());//Բ��
										   //double cirConnn_Thick = 70;
	double cirConnn_Rad = radius6 + cirConnn_Thick;//70Ϊ���Ӵ��ĺ��
	gp_Ax2 Ax2_O4_EC(center_CirConnL, gp_Dir(0, 0, 1));
	gp_Circ Circle_Connection(Ax2_O4_EC, cirConnn_Rad);
	gp_Ax3 Ax3_O4_EC(Ax2_O4_EC);
	gp_Cylinder connCylind(Ax3_O4_EC, cirConnn_Rad);//��������Բ����
	Handle(Geom_CylindricalSurface) geomConnCylind = new Geom_CylindricalSurface(connCylind);
	GeomAPI_IntCS ICS_Line2AndConnCylind(geomLine2, geomConnCylind);//����LineTan1��Բ����cylinder2����
	gp_Pnt Inter1_Line2AndConnCylind = ICS_Line2AndConnCylind.Point(1);
	gp_Pnt Inter2_Line2AndConnCylind = ICS_Line2AndConnCylind.Point(2);
	gp_Pnt Inter_Line2AndConnCylind;
	Inter_Line2AndConnCylind.SetX(Inter1_Line2AndConnCylind.X());
	Inter_Line2AndConnCylind.SetY(Inter1_Line2AndConnCylind.Y());
	if (Inter1_Line2AndConnCylind.X() > Inter2_Line2AndConnCylind.X()) {
		Inter_Line2AndConnCylind.SetX(Inter2_Line2AndConnCylind.X());
		Inter_Line2AndConnCylind.SetY(Inter2_Line2AndConnCylind.Y());
	}//��ù���Բ�������
	Handle(Geom_TrimmedCurve) geomCircleConnection = GC_MakeArcOfCircle(Circle_Connection, Inter_Line2AndConnCylind, Pnt_YG_L, false);//�����������Բ��
	TopoDS_Edge TCircleConnection = BRepBuilderAPI_MakeEdge(geomCircleConnection);
	Handle(AIS_Shape) aTCircleConnection = new AIS_Shape(TCircleConnection);
	aTCircleConnection->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTCircleConnection, Standard_True);*/
	//�����Ҳ�����Բ��
	gp_Pnt center_CirConnR(centerO8.XYZ());//Բ��
	gp_Ax2 Ax2_O4_EC_R(center_CirConnR, gp_Dir(0, 0, 1));
	gp_Circ Circle_ConnectionR(Ax2_O4_EC_R, cirConnn_Rad);//�Ҳ�����Բ������Բ
	gp_Pnt endPofConnArchR(-Inter_Line2AndConnCylind.X(), Inter_Line2AndConnCylind.Y(), 0);//�Ҳ����ӻ����յ�
	Handle(Geom_TrimmedCurve) geomCircle_ConnectionR = GC_MakeArcOfCircle(Circle_ConnectionR, Pnt_YG_R, endPofConnArchR, false);//�����Ҳ�����Բ��
	TopoDS_Edge TCircle_ConnectionR = BRepBuilderAPI_MakeEdge(geomCircle_ConnectionR);
	Handle(AIS_Shape) aTCircle_ConnectionR = new AIS_Shape(TCircle_ConnectionR);
	aTCircle_ConnectionR->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTCircle_ConnectionR, Standard_True);*/

	//��������ֱ�߶�
	//�������ֱ�߶�
	TopoDS_Edge Tline_L = BRepBuilderAPI_MakeEdge(endPofTtanLineL, Inter_Line2AndConnCylind);
	Handle(AIS_Shape) aTline_L = new AIS_Shape(Tline_L);
	aTline_L->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTline_L, Standard_True);*/
	//�����Ҳ�ֱ�߶�
	TopoDS_Edge Tline_R = BRepBuilderAPI_MakeEdge(endPofTtanLineR, endPofConnArchR);
	Handle(AIS_Shape) aTline_R = new AIS_Shape(Tline_R);
	aTline_R->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTline_R, Standard_True);*/

	//���������ӳ��沢�������
	std::vector<TopoDS_Edge> edges;//���������������洢��edges��
	edges.push_back(TFirSurppOutCircle);//��֧��ǽ������
	edges.push_back(TtanLineR);//�Ҳ����߶�
	edges.push_back(Tline_R);//�Ҳ�ֱ�߶�
	edges.push_back(TCircle_ConnectionR);//�Ҳ�����Բ��
	edges.push_back(TInvertedArchArc);//��֧����������
	edges.push_back(TCircleConnection);//������ӻ���
	edges.push_back(Tline_L);//���ֱ�߶�
	edges.push_back(TtanLineL);//������߶�
	BRepBuilderAPI_MakeWire wireBuilder;// ����MakeWire����
										// ���ÿ���ߵ�MakeWire������
	for (const TopoDS_Edge& edge : edges)
	{
		wireBuilder.Add(edge);
	}
	// �������������
	wireBuilder.Build();
	BRepBuilderAPI_MakeFace faceMaker(wireBuilder.Wire());//������
	TopoDS_Face face = faceMaker.Face(); // ��ȡ���ɵ���
										 //�����������
	double thickness = -1000.0; // ָ��������
	gp_Pnt Pnt_thick(0, 0, thickness);
	gp_Vec Vec_thick(Pnt_thick.XYZ());//������������
	BRepPrimAPI_MakePrism prismMaker(face, Vec_thick);//ʹ��BRepPrimAPI_MakePrism�����������
	TopoDS_Shape prism_cz = prismMaker.Shape();
	TopoDS_Solid Solid_prism_cz = TopoDS::Solid(prismMaker.Shape());
	Handle(AIS_Shape) aprism_cz = new AIS_Shape(prism_cz);
	//aprism_cz->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	//myOccView->getContext()->Display(aprism_cz, Standard_True);
	BRepAlgoAPI_Cut CUT(Solid_prism_cz, EC_WAI_arcShape1);
	TopoDS_Shape Cut_Result = CUT.Shape();
	Handle(AIS_Shape) aprism_Cut_Result = new AIS_Shape(Cut_Result);
	aprism_Cut_Result->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aprism_Cut_Result, Standard_True);
	//double P1X = Inter_Line1AndCylindFirSurppOut.X();
	//double P1Y = Inter_Line1AndCylindFirSurppOut.Y();
	//������������Լ��뾶����coords�У������ź���ʽ����ȥ

	/******ê��******/

};


void MainWindow::handleErchen(const Erchen& centercoords)
{
	// ���� makeTabu() ������������ SquareCoordinates �ṹ���������
	makeErchen(centercoords);
}

void MainWindow::makeErchen(const Erchen& centercoords)
{
	// ����Բ O1  �����ڲ࣬665�뾶 
	gp_Pnt P_CO1_NLK(0.0, 0.0, 0.0); // ԭ��ΪԲ��
	gp_Ax2 axis1(P_CO1_NLK, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	Standard_Real R1_NLK = centercoords.E1; // ����Բ�İ뾶
											//Standard_Real R1_NLK = 665; // ����Բ�İ뾶

	gp_Circ CO1_NLK(axis1, R1_NLK);
	Handle(Geom_Circle) geomCircle1_NLK = new Geom_Circle(CO1_NLK);
	TopoDS_Edge edge1_NLK = BRepBuilderAPI_MakeEdge(geomCircle1_NLK);

	// ����ԭ����д���
	BRepBuilderAPI_MakeEdge edge(gp_Pnt(0, -1000, 0), gp_Pnt(0, 1000, 0));
	TopoDS_Shape shape3 = edge.Shape();
	// ����Բ�ĵ��� P �ľ��� �ǰ�����߶�
	Standard_Real radius = R1_NLK;
	//Standard_Real radius3 = 1720; // ԲO3�İ뾶
	Standard_Real radius3 = centercoords.E2; // ԲO3�İ뾶
	Standard_Real GoucaoKuandu = centercoords.E6;
	Standard_Real JibenKuandu = centercoords.E8;
	Standard_Real GoucaoGaocha = centercoords.E7;
	Standard_Real R3_TC = centercoords.E5;

	//Standard_Real height = sqrt(pow(radius, 2) - pow(630, 2));
	Standard_Real height = sqrt(pow(radius, 2) - pow((GoucaoKuandu + JibenKuandu / 2), 2));
	//Standard_Real distanceCenterToP = sqrt(pow(radius, 2) + pow(630, 2)) - radius;
	Standard_Real distanceCenterToP = sqrt(pow(radius, 2) + pow((GoucaoKuandu + JibenKuandu / 2), 2)) - radius;
	gp_Pnt pointP(0, -height, 0);

	//// ����Բ�ĵ��� P �ľ��� �ǰ�����߶�
	//Standard_Real R1_NLK = 665.0;
	//Standard_Real R3_NLK = 1720; // ԲO3�İ뾶
	//Standard_Real height = sqrt(pow(R1_NLK, 2) - pow(630, 2));
	//Standard_Real distanceCenterToP = sqrt(pow(R1_NLK, 2) + pow(630, 2)) - R1_NLK;
	//gp_Pnt pointP(0, -height, 0);

	// ȷ���µ�Բ�� P3  ����Բ��
	//gp_Pnt pointP3(0, radius3 - 180 - 30  - height , 0);//180��30��ı䣡����
	gp_Pnt pointP3(0, radius3 - R3_TC - GoucaoGaocha - height, 0);//180��30��ı䣡����

																  // // ȷ���µ�Բ�� P3  ����Բ��
																  //gp_Pnt P_CO3_NLK(0, 1720 - 180 - 30 - height, 0);//180��30��ı䣡����

																  //����Ƕ� alpha  ȷ�����ɶ�Բ�뾶�ò���
	Standard_Real alpha = acos(-pointP.Y() / radius);
	////����Ƕ� alpha  ȷ�����ɶ�Բ�뾶�ò���
	//Standard_Real alpha = acos(-pointP.Y() / R1_NLK);
	// ����Բ�ĵ��� P ���߶�
	BRepBuilderAPI_MakeEdge edgeP(gp_Pnt(0, 0, 0), pointP);
	TopoDS_Shape shapeP = edgeP.Shape();

	// ����Բ O3  �����ڲ�Բ
	gp_Ax2 axis03(pointP3, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
												   //											   // ����Բ O3  �����ڲ�Բ
												   //gp_Ax2 axis03(P_CO3_NLK, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	Standard_Real radius03 = radius3; // �뾶Ϊ 1720cm
	gp_Circ circle03(axis03, radius03);
	Handle(Geom_Circle) geomCircle03 = new Geom_Circle(circle03);
	TopoDS_Edge edge03 = BRepBuilderAPI_MakeEdge(geomCircle03);
	//Standard_Real R3_NLK = 1720.0; // �뾶Ϊ 1720cm
	//gp_Circ circle03(axis03, R3_NLK);
	//Handle(Geom_Circle) geomCO3_NLK = new Geom_Circle(CO3_NLK);
	//TopoDS_Edge edgeO3_NLK = BRepBuilderAPI_MakeEdge(geomCO3_NLK);

	//����radius4  �ڲ���ɶ�Բ�뾶
	Standard_Real m = pow(radius3, 2) - pow(radius, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*height;
	Standard_Real n = radius3 - radius - pointP3.Y() *height / radius;
	Standard_Real radius4 = m / (2 * n);
	// ����Բ O4  ���ɶ��ڲ�Բ  ���
	gp_Pnt centerO4(-sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	gp_Circ circle4(axis4, radius4);
	Handle(Geom_Circle) geomCircle4 = new Geom_Circle(circle4);
	TopoDS_Edge edge4 = BRepBuilderAPI_MakeEdge(geomCircle4);

	////����radius4  �ڲ���ɶ�Բ�뾶
	//Standard_Real m = pow(R3_NLK, 2) - pow(R1_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*height;
	//Standard_Real n = R3_NLK - R1_NLK - P_CO3_NLK.Y() *height / R1_NLK;
	//Standard_Real R4_NLK = m / (2 * n);
	//// ����Բ O4  ���ɶ��ڲ�Բ  ���
	//gp_Pnt centerO4(-sin(alpha) * (R1_NLK - R4_NLK), -cos(alpha) * (R1_NLK - R4_NLK), 0);
	//gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	//gp_Circ CO4_NLK(axis4, R4_NLK);
	//Handle(Geom_Circle) geomCO4_NLK = new Geom_Circle(CO4_NLK);
	//TopoDS_Edge edgeO4_NLK= BRepBuilderAPI_MakeEdge(geomCO4_NLK);

	// ����Բ O7  ���ɶ��ڲ�Բ  �Ҳ�
	gp_Pnt centerO7(sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis7(centerO7, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	gp_Circ circle7(axis7, radius4);
	Handle(Geom_Circle) geomCircle7 = new Geom_Circle(circle7);
	TopoDS_Edge edge7 = BRepBuilderAPI_MakeEdge(geomCircle7);


	///���ƹ�ǽ�ڲ໡�ߣ���֪����Բ�ġ���㡢�뾶
	Standard_Real R_O1 = R1_NLK;//�뾶
	gp_Circ Circle_O1_EC(axis1, R_O1);
	gp_Ax3 AxO1(axis1);
	gp_Cylinder Cylinder_O1(AxO1, R_O1);//��������Բ����

	Handle(Geom_CylindricalSurface) geoCylinder_O1 = new Geom_CylindricalSurface(Cylinder_O1);
	GeomAPI_IntCS ICC_O4_01(geomCircle4, geoCylinder_O1);//��Բ04��Բ����cylinder01����
	gp_Pnt CUT_O4_01 = ICC_O4_01.Point(1);

	GeomAPI_IntCS ICC_O7_01(geomCircle7, geoCylinder_O1);//��Բ07��Բ����cylinder01����
	gp_Pnt CUT_O7_01 = ICC_O7_01.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O1_EC, CUT_O7_01, CUT_O4_01, false);//�����������Բ��
	TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	Handle(AIS_Shape) aTarcCurve_01 = new AIS_Shape(TarcCurve_01);
	aTarcCurve_01->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_01, Standard_True);



	///���������ڲ໡�ߣ���֪����Բ�ġ���㡢�뾶
	Standard_Real R_O3 = radius3;//�뾶
								 /////���������ڲ໡�ߣ���֪����Բ�ġ���㡢�뾶
								 //Standard_Real R_O3 = R3_NLK;//�뾶
	gp_Circ Circle_O3_EC(axis03, R_O3);
	gp_Ax3 AxO3(axis03);
	gp_Cylinder Cylinder_O3(AxO3, R_O3);//��������Բ����

	Handle(Geom_CylindricalSurface) geoCylinder_O3 = new Geom_CylindricalSurface(Cylinder_O3);
	GeomAPI_IntCS ICC_O4_03(geomCircle4, geoCylinder_O3);//��Բ04��Բ����cylinder01����
	gp_Pnt CUT_O4_03 = ICC_O4_03.Point(1);

	GeomAPI_IntCS ICC_O7_03(geomCircle7, geoCylinder_O3);//��Բ07��Բ����cylinder01����
	gp_Pnt CUT_O7_03 = ICC_O7_03.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_03 = GC_MakeArcOfCircle(Circle_O3_EC, CUT_O4_03, CUT_O7_03, false);//�����������Բ��
	TopoDS_Edge TarcCurve_03 = BRepBuilderAPI_MakeEdge(arcCurve_03);
	Handle(AIS_Shape) aTarcCurve_03 = new AIS_Shape(TarcCurve_03);
	aTarcCurve_03->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_03, Standard_True);

	///���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
	Standard_Real R_O4 = radius4;//�뾶
								 /////���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
								 //Standard_Real R_O4 = R4_NLK;//�뾶
	gp_Circ Circle_O4_EC(axis4, R_O4);
	gp_Ax3 AxO4(axis4);
	gp_Cylinder Cylinder_O4(AxO4, R_O4);//��������Բ����

	Handle(Geom_TrimmedCurve) arcCurve_04 = GC_MakeArcOfCircle(Circle_O4_EC, CUT_O4_01, CUT_O4_03, false);//�����������Բ��
	TopoDS_Edge TarcCurve_04 = BRepBuilderAPI_MakeEdge(arcCurve_04);
	Handle(AIS_Shape) aTarcCurve_04 = new AIS_Shape(TarcCurve_04);
	aTarcCurve_04->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_04, Standard_True);

	///���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
	Standard_Real R_O7 = radius4;//�뾶
								 // ///���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
								 //Standard_Real R_O7 = R4_NLK;//�뾶
	gp_Circ Circle_O7_EC(axis7, R_O7);
	gp_Ax3 AxO7(axis7);
	gp_Cylinder Cylinder_O7(AxO7, R_O7);//��������Բ����

	Handle(Geom_TrimmedCurve) arcCurve_07 = GC_MakeArcOfCircle(Circle_O7_EC, CUT_O7_03, CUT_O7_01, false);//�����������Բ��
	TopoDS_Edge TarcCurve_07 = BRepBuilderAPI_MakeEdge(arcCurve_07);
	Handle(AIS_Shape) aTarcCurve_07 = new AIS_Shape(TarcCurve_07);
	aTarcCurve_07->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_07, Standard_True);



	// ����Բ O2  ������࣬665+55�뾶
	gp_Pnt P_CO2_NLK(0.0, 0.0, 0.0); // ԭ��ΪԲ��
	gp_Ax2 axis2(P_CO2_NLK, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
													//Standard_Real R2_NLK = 720.0; // ����Բ�İ뾶
	Standard_Real R1_R2_HD = centercoords.E3;
	Standard_Real R2_NLK = R1_NLK + R1_R2_HD; // ����Բ�İ뾶

	gp_Circ CO2_NLK(axis2, R2_NLK);
	Handle(Geom_Circle) geomCircle2 = new Geom_Circle(CO2_NLK);
	TopoDS_Edge edge2 = BRepBuilderAPI_MakeEdge(geomCircle2);

	// ����Բ O5 �������Բ
	gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	Standard_Real R3_R5_HD = centercoords.E4;
	Standard_Real radius5 = radius3 + R3_R5_HD; // �뾶Ϊ 1720cm+55cm
	gp_Circ circle5(axis5, radius5);
	Handle(Geom_Circle) geomCircle5 = new Geom_Circle(circle5);
	TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomCircle5);
	//// ����Բ O5 �������Բ
	//gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	//Standard_Real R5_NLK = R3_NLK + 65.0; // �뾶Ϊ 1720cm+55cm
	//gp_Circ circle5(axis5, R5_NLK);
	//Handle(Geom_Circle) geomC05_NLK = new Geom_Circle(C05_NLK);
	//TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomC05_NLK);

	//����radius6 �����ɶ�Բ�뾶
	//Standard_Real radius6 = solveForR4(alpha, radius, radius3, -pointP.Y());
	Standard_Real s = pow(radius5, 2) - pow(R2_NLK, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*(height + R1_R2_HD*cos(alpha));
	Standard_Real p = radius5 - R2_NLK - pointP3.Y() *(height + R1_R2_HD* cos(alpha)) / R2_NLK;
	Standard_Real radius6 = s / (2 * p);
	////����radius6 �����ɶ�Բ�뾶
	////Standard_Real R6_NLK = solveForR4(alpha, R1_NLK, R3_NLK, -P_CO1_NLK());
	//Standard_Real s = pow(R5_NLK, 2) - pow(R2_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*(height+R2_NLK*alpha);
	//Standard_Real p = R5_NLK - R2_NLK - P_CO3_NLK.Y() *height / R2_NLK;
	//Standard_Real R6_NLK = s / (2 * p);


	// ����Բ O6  ���ɶ����Բ  ���
	gp_Pnt centerO6(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	gp_Circ circle6(axis6, radius6);
	Handle(Geom_Circle) geomCircle6 = new Geom_Circle(circle6);
	TopoDS_Edge edge6 = BRepBuilderAPI_MakeEdge(geomCircle6);
	//// ����Բ O6  ���ɶ����Բ  ���
	//gp_Pnt centerO6(-sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	//gp_Circ circle6(axis6, R6_NLK);
	//Handle(Geom_Circle) geomC06_NLK = new Geom_Circle(C06_NLK);
	//TopoDS_Edge edge6_NLK = BRepBuilderAPI_MakeEdge(geomC06_NLK);

	// ����Բ O8  ���ɶ����Բ  �Ҳ�
	gp_Pnt centerO8(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	gp_Circ circle8(axis8, radius6);
	Handle(Geom_Circle) geomCircle8 = new Geom_Circle(circle8);
	TopoDS_Edge edge8 = BRepBuilderAPI_MakeEdge(geomCircle8);
	//// ����Բ O8  ���ɶ����Բ  �Ҳ�
	//gp_Pnt centerO8(sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // ԭ��ΪԲ�ģ�Z�᷽��Ϊ���߷���
	//gp_Circ circle8(axis8, R6_NLK);
	//Handle(Geom_Circle) geomC08_NLK = new Geom_Circle(C08_NLK);
	//TopoDS_Edge edge8_NLK = BRepBuilderAPI_MakeEdge(geomC08_NLK);

	///���ƹ�ǽ��໡��
	Standard_Real R_O2 = R2_NLK;//�뾶
	gp_Circ Circle_O2_EC(axis2, R_O2);
	gp_Ax3 AxO2(axis2);
	gp_Cylinder Cylinder_O2(AxO2, R_O2);//��������Բ����

	Handle(Geom_CylindricalSurface) geoCylinder_O2 = new Geom_CylindricalSurface(Cylinder_O2);

	// ����ֱ�ߵ������յ�
	gp_Pnt startPoint6_2(0, 0, 0);
	gp_Pnt endPoint6_2(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// ʹ�����ͷ��򴴽�ֱ��
	gp_Vec direction6_2(startPoint6_2, endPoint6_2);
	gp_Lin line6_2(startPoint6_2, direction6_2);
	// ����ֱ�ߵ��߶�
	TopoDS_Edge lineEdge6_2 = BRepBuilderAPI_MakeEdge(line6_2, startPoint6_2, endPoint6_2);
	Handle(Geom_Line) Geom_lineEdge6_2 = new Geom_Line(line6_2);
	// ����ֱ�ߺ�Բ����֮��Ľ���
	GeomAPI_IntCS ICC_O6_02(Geom_lineEdge6_2, geoCylinder_O2);//06 02����
	gp_Pnt CUT_O6_02_R1 = ICC_O6_02.Point(1);
	gp_Pnt CUT_O6_02_R2 = ICC_O6_02.Point(2);
	gp_Pnt CUT_O6_02;
	CUT_O6_02.SetX(CUT_O6_02_R1.X());
	CUT_O6_02.SetY(CUT_O6_02_R1.Y());
	if (CUT_O6_02_R1.X() > CUT_O6_02_R2.X()) {
		CUT_O6_02.SetX(CUT_O6_02_R2.X());
		CUT_O6_02.SetY(CUT_O6_02_R2.Y());
	}//��ù���Բ�������

	 // ����ֱ�ߵ������յ�
	gp_Pnt startPoint8_2(0, 0, 0);
	gp_Pnt endPoint8_2(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// ʹ�����ͷ��򴴽�ֱ��
	gp_Vec direction8_2(startPoint8_2, endPoint8_2);
	gp_Lin line8_2(startPoint8_2, direction8_2);
	// ����ֱ�ߵ��߶�
	TopoDS_Edge lineEdge8_2 = BRepBuilderAPI_MakeEdge(line8_2, startPoint8_2, endPoint8_2);
	Handle(Geom_Line) Geom_lineEdge8_2 = new Geom_Line(line8_2);
	// ����ֱ�ߺ�Բ����֮��Ľ���
	GeomAPI_IntCS ICC_O8_02(Geom_lineEdge8_2, geoCylinder_O2);//08 02����
	gp_Pnt CUT_O8_02_R1 = ICC_O8_02.Point(1);
	gp_Pnt CUT_O8_02_R2 = ICC_O8_02.Point(2);
	gp_Pnt CUT_O8_02;
	CUT_O8_02.SetX(CUT_O8_02_R1.X());
	CUT_O8_02.SetY(CUT_O8_02_R1.Y());
	if (CUT_O8_02_R1.X() < CUT_O8_02_R2.X()) {
		CUT_O8_02.SetX(CUT_O8_02_R2.X());
		CUT_O8_02.SetY(CUT_O8_02_R2.Y());
	}//��ù���Բ�������

	Handle(Geom_TrimmedCurve) arcCurve_02 = GC_MakeArcOfCircle(Circle_O2_EC, CUT_O8_02, CUT_O6_02, false);//�����������Բ��
	TopoDS_Edge TarcCurve_02 = BRepBuilderAPI_MakeEdge(arcCurve_02);
	Handle(AIS_Shape) aTarcCurve_02 = new AIS_Shape(TarcCurve_02);
	aTarcCurve_02->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_02, Standard_True);





	///����������໡��
	Standard_Real R_O5 = radius5;//�뾶
	gp_Circ Circle_O5_EC(axis5, R_O5);
	gp_Ax3 AxO5(axis5);
	gp_Cylinder Cylinder_O5(AxO5, R_O5);//��������Բ����

	Handle(Geom_CylindricalSurface) geoCylinder_O5 = new Geom_CylindricalSurface(Cylinder_O5);

	// ����ֱ�ߵ������յ�
	//gp_Pnt startPoint6_5(0, 1720 - 180 - 30 - height, 0);
	gp_Pnt startPoint6_5(0, radius3 - R3_TC - GoucaoGaocha - height, 0);
	gp_Pnt endPoint6_5(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// ʹ�����ͷ��򴴽�ֱ��
	gp_Vec direction6_5(startPoint6_5, endPoint6_5);
	gp_Lin line6_5(startPoint6_5, direction6_5);
	// ����ֱ�ߵ��߶�
	TopoDS_Edge lineEdge6_5 = BRepBuilderAPI_MakeEdge(line6_5, startPoint6_5, endPoint6_5);
	Handle(Geom_Line) Geom_lineEdge6_5 = new Geom_Line(line6_5);
	// ����ֱ�ߺ�Բ����֮��Ľ���
	GeomAPI_IntCS ICC_O6_05(Geom_lineEdge6_5, geoCylinder_O5);//06 02����
	gp_Pnt CUT_O6_05_R1 = ICC_O6_05.Point(1);
	gp_Pnt CUT_O6_05_R2 = ICC_O6_05.Point(2);
	gp_Pnt CUT_O6_05;
	CUT_O6_05.SetX(CUT_O6_05_R1.X());
	CUT_O6_05.SetY(CUT_O6_05_R1.Y());
	if (CUT_O6_05_R1.X() > CUT_O6_05_R2.X()) {
		CUT_O6_05.SetX(CUT_O6_05_R2.X());
		CUT_O6_05.SetY(CUT_O6_05_R2.Y());
	}//��ù���Բ�������

	 // ����ֱ�ߵ������յ�
	 //gp_Pnt startPoint8_5(0, 1720 - 180 - 30 - height, 0);
	gp_Pnt startPoint8_5(0, radius3 - R3_TC - GoucaoGaocha - height, 0);
	gp_Pnt endPoint8_5(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// ʹ�����ͷ��򴴽�ֱ��
	gp_Vec direction8_5(startPoint8_5, endPoint8_5);
	gp_Lin line8_5(startPoint8_5, direction8_5);
	// ����ֱ�ߵ��߶�
	TopoDS_Edge lineEdge8_5 = BRepBuilderAPI_MakeEdge(line8_5, startPoint8_5, endPoint8_5);
	Handle(Geom_Line) Geom_lineEdge8_5 = new Geom_Line(line8_5);
	// ����ֱ�ߺ�Բ����֮��Ľ���
	GeomAPI_IntCS ICC_O8_05(Geom_lineEdge8_5, geoCylinder_O5);//08 02����
	gp_Pnt CUT_O8_05_R1 = ICC_O8_05.Point(1);
	gp_Pnt CUT_O8_05_R2 = ICC_O8_05.Point(2);
	gp_Pnt CUT_O8_05;
	CUT_O8_05.SetX(CUT_O8_05_R1.X());
	CUT_O8_05.SetY(CUT_O8_05_R1.Y());
	if (CUT_O8_05_R1.X() < CUT_O8_05_R2.X()) {
		CUT_O8_05.SetX(CUT_O8_05_R2.X());
		CUT_O8_05.SetY(CUT_O8_05_R2.Y());
	}//��ù���Բ�������


	Handle(Geom_TrimmedCurve) arcCurve_05 = GC_MakeArcOfCircle(Circle_O5_EC, CUT_O6_05, CUT_O8_05, false);//�����������Բ��
	TopoDS_Edge TarcCurve_05 = BRepBuilderAPI_MakeEdge(arcCurve_05);
	Handle(AIS_Shape) aTarcCurve_05 = new AIS_Shape(TarcCurve_05);
	aTarcCurve_05->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_05, Standard_True);







	///���ƹ��ɶ���໡�ߣ���֪����Բ�ġ���㡢�뾶
	Standard_Real R_O6 = radius6;//�뾶
	gp_Circ Circle_O6_EC(axis6, R_O6);
	gp_Ax3 AxO6(axis6);
	gp_Cylinder Cylinder_O6(AxO6, R_O6);//��������Բ����

	Handle(Geom_TrimmedCurve) arcCurve_06 = GC_MakeArcOfCircle(Circle_O6_EC, CUT_O6_02, CUT_O6_05, false);//�����������Բ��
	TopoDS_Edge TarcCurve_06 = BRepBuilderAPI_MakeEdge(arcCurve_06);
	Handle(AIS_Shape) aTarcCurve_06 = new AIS_Shape(TarcCurve_06);
	aTarcCurve_06->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_06, Standard_True);




	///���ƹ��ɶ��Ҳ໡�ߣ���֪����Բ�ġ���㡢�뾶
	Standard_Real R_O8 = radius6;//�뾶
	gp_Circ Circle_O8_EC(axis8, R_O8);
	gp_Ax3 AxO8(axis8);
	gp_Cylinder Cylinder_O8(AxO8, R_O8);//��������Բ����

	Handle(Geom_TrimmedCurve) arcCurve_08 = GC_MakeArcOfCircle(Circle_O8_EC, CUT_O8_05, CUT_O8_02, false);//�����������Բ��
	TopoDS_Edge TarcCurve_08 = BRepBuilderAPI_MakeEdge(arcCurve_08);
	Handle(AIS_Shape) aTarcCurve_08 = new AIS_Shape(TarcCurve_08);
	aTarcCurve_08->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_08, Standard_True);


	//// ���� OCC ���ӻ�����Բ O1
	//Handle(AIS_Shape) aisShape1 = new AIS_Shape(edge1);
	//aisShape1->SetColor(Quantity_NOC_RED); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(aisShape1, Standard_True); // �ڳ�������ʾ���ӻ�����
	//// ���� OCC ���ӻ�����Բ O2
	//Handle(AIS_Shape) aisShape2 = new AIS_Shape(edge2);
	//aisShape2->SetColor(Quantity_NOC_GREEN); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(aisShape2, Standard_True); // �ڳ�������ʾ���ӻ�����
	//// ���� OCC ���ӻ����� OP�߶�
	//Handle(AIS_Shape) aisShapeP = new AIS_Shape(shapeP);
	//aisShapeP->SetColor(Quantity_Color(Quantity_NOC_ORANGE)); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(aisShapeP, Standard_True); // �ڳ�������ʾ���ӻ�����
	//// ���� OCC ���ӻ�����Բ O3
	//Handle(AIS_Shape) aisCircle03 = new AIS_Shape(edge03);
	//aisCircle03->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(aisCircle03, Standard_True); // �ڳ�������ʾֱ�� 
	//// ���� OCC ���ӻ�����Բ O4
	//Handle(AIS_Shape) aisCircle4 = new AIS_Shape(edge4);
	//aisCircle4->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(aisCircle4, Standard_True); // �ڳ�������ʾֱ�� // �ڳ�������ʾ���ӻ�����
	//// ���� OCC ���ӻ�����Բ O5
	//Handle(AIS_Shape) aisCircle5 = new AIS_Shape(edge5);
	//aisCircle5->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(aisCircle5, Standard_True); // �ڳ�������ʾֱ�� 
	//// ���� OCC ���ӻ�����Բ O6
	//Handle(AIS_Shape) aisCircle6 = new AIS_Shape(edge6);
	//aisCircle6->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(aisCircle6, Standard_True); // �ڳ�������ʾֱ�� // �ڳ�������ʾ���ӻ�����
	//// ���� OCC ���ӻ�����Բ O7
	//Handle(AIS_Shape) aisCircle7 = new AIS_Shape(edge7);
	//aisCircle7->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(aisCircle7, Standard_True); // �ڳ�������ʾֱ�� // �ڳ�������ʾ���ӻ�����
	//// ���� OCC ���ӻ�����Բ O8
	//Handle(AIS_Shape) aisCircle8 = new AIS_Shape(edge8);
	//aisCircle8->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(aisCircle8, Standard_True); // �ڳ�������ʾֱ�� // �ڳ�������ʾ���ӻ�����






	//����ý���ֱ��ȷ����ʹ���·���
	//gp_Pnt centerO7(sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	/////���ƹ�ǽ�ڲ໡�ߣ���֪����Բ�ġ���㡢�뾶
	//Standard_Real R_O1 = radius1;//�뾶
	//gp_Circ Circle_O1_EC(axis1, R_O1);
	//gp_Ax3 AxO1(axis1);
	//gp_Cylinder Cylinder_O1(AxO1, R_O1);//��������Բ����

	//Handle(Geom_CylindricalSurface) geoCylinder_O1 = new Geom_CylindricalSurface(Cylinder_O1);

	//gp_Pnt CUT_O4_01(-sin(alpha) * radius, -cos(alpha) * radius , 0);
	//gp_Pnt CUT_O7_01(sin(alpha) * radius, -cos(alpha) * radius, 0);

	//Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O1_EC, CUT_O7_01, CUT_O4_01, true);//�����������Բ��
	//TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	//Handle(AIS_Shape) aTarcCurve_01 = new AIS_Shape(TarcCurve_01);
	//aTarcCurve_01->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_01, Standard_True);


	//�ӳ��߷�������������
	//// ���������յ�
	//gp_Pnt startPoint6_3(0, 0, 0);
	//gp_Pnt endPoint6_3(-sin(alpha) * (radius2 - radius6), -cos(alpha) * (radius2 - radius6), 0);
	//gp_Vec direction6_3(-sin(alpha) * (radius2 - radius6), -cos(alpha) * (radius2 - radius6), 0);
	//// ʹ�������յ㴴��һ��ֱ��
	//gp_Lin line6_3(startPoint6_3, direction6_3);
	//Handle(Geom_Line) line6_3 = new Geom_Line(startPoint6_3, gp_Vec(startPoint6_3, endPoint6_3));
	//// ʹ��ֱ�ߴ���һ���߶Σ�����߶��������յ��޶�
	//TopoDS_Edge edge6_3 = BRepBuilderAPI_MakeEdge(line6_3, startPoint6_3, endPoint6_3);
	//// ָ���ӳ��ľ���
	//double extensionDistance = 50;  // �����ӳ�50
	//// �����ӳ�����յ�
	//gp_Pnt extendedEndPoint = endPoint6_3.Translated(gp_Vec(startPoint6_3, endPoint6_3).Normalized() * extensionDistance);
	//// ʹ���ӳ�����յ㴴��һ���ӳ�����߶�
	//TopoDS_Edge extendedEdge = BRepBuilderAPI_MakeEdge(line6_3, startPoint6_3, extendedEndPoint);

	// ʹ�� BRepBuilderAPI_MakeWire �����պ�����
	BRepBuilderAPI_MakeWire EC_WAIwireBuilder;
	EC_WAIwireBuilder.Add(TarcCurve_02);
	EC_WAIwireBuilder.Add(TarcCurve_06);
	EC_WAIwireBuilder.Add(TarcCurve_05);
	EC_WAIwireBuilder.Add(TarcCurve_08);
	EC_WAIwireBuilder.Build();

	if (EC_WAIwireBuilder.IsDone()) {
		TopoDS_Wire EC_WAIclosedWire = EC_WAIwireBuilder.Wire();

		// ���� closedWire ���������ӳɱպϵ�������
	}
	else {
		// ������ʧ�ܵ����
	}

	//TopoDS_Wire sectorWirearc = makeWirearc.Wire();
	BRepBuilderAPI_MakeFace EC_WAIFacearc(EC_WAIwireBuilder);
	//TopoDS_Face EC_WAIFacearc = EC_WAIFacearc.Face();
	gp_Vec extrusionVecR1(0, 0, -1000.0); // ���� Z �᷽������ 100 ����λ

	BRepPrimAPI_MakePrism EC_WAI_makearc1(EC_WAIFacearc, extrusionVecR1);
	TopoDS_Shape EC_WAI_arcShape1 = EC_WAI_makearc1.Shape();
	TopoDS_Solid EC_WAI_arcbody = TopoDS::Solid(EC_WAI_arcShape1);
	Handle(AIS_Shape) EC_WAI_Aisarcbody = new AIS_Shape(EC_WAI_arcbody);


	//EC_WAI_Aisarcbody->SetColor(Quantity_NOC_RED); // ������ɫΪ��ɫ
	//myOccView->getContext()->Display(EC_WAI_Aisarcbody, Standard_True); // �ڳ�������ʾ���ӻ�����

	// ʹ�� BRepBuilderAPI_MakeWire �����պ�����
	BRepBuilderAPI_MakeWire EC_NEIwireBuilder;
	EC_NEIwireBuilder.Add(TarcCurve_01);
	EC_NEIwireBuilder.Add(TarcCurve_04);
	EC_NEIwireBuilder.Add(TarcCurve_07);
	EC_NEIwireBuilder.Add(TarcCurve_03);
	EC_NEIwireBuilder.Build();

	if (EC_NEIwireBuilder.IsDone()) {
		TopoDS_Wire EC_NEIclosedWire = EC_NEIwireBuilder.Wire();

		// ���� closedWire ���������ӳɱպϵ�������
	}
	else {
		// ������ʧ�ܵ����
	}

	BRepBuilderAPI_MakeFace EC_NEIFacearc(EC_NEIwireBuilder);

	BRepPrimAPI_MakePrism EC_NEI_makearc1(EC_NEIFacearc, extrusionVecR1);
	TopoDS_Shape EC_NEI_arcShape1 = EC_NEI_makearc1.Shape();
	TopoDS_Solid EC_NEI_arcbody = TopoDS::Solid(EC_NEI_arcShape1);
	Handle(AIS_Shape) EC_NEI_Aisarcbody = new AIS_Shape(EC_NEI_arcbody);

	BRepAlgoAPI_Cut cutOp1(EC_WAI_arcShape1, EC_NEI_arcShape1);
	TopoDS_Shape EC_arcShape = cutOp1.Shape();

	Handle(AIS_Shape) EC_arcShape1 = new AIS_Shape(EC_arcShape);
	EC_arcShape1->SetColor(Quantity_NOC_YELLOW); // ������ɫΪ��ɫ
	myOccView->getContext()->Display(EC_arcShape1, Standard_True); // �ڳ�������ʾ���ӻ�����

	secondaryLiningObj.setValue(R2_NLK,radius5, CUT_O6_05.X(), CUT_O6_05.Y(), CUT_O6_05.Z(), alpha, radius6,
	CUT_O4_01.X(), CUT_O4_01.Y(), CUT_O4_01.Z(), CUT_O4_03.X(), CUT_O4_03.Y(), CUT_O4_03.Z(),
	CUT_O7_01.X(), CUT_O7_01.Y(), CUT_O7_01.Z(), CUT_O7_03.X(), CUT_O7_03.Y(), CUT_O7_03.Z(), radius4, pointP3.Y(), R1_NLK,radius3,
	R1_R2_HD,R3_R5_HD,R3_TC,GoucaoKuandu,GoucaoGaocha,JibenKuandu);
}