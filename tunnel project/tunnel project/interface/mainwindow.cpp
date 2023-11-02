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
#include <QAction>
#include <QFormLayout>
#include <Standard.hxx>
#include <qdockwidget.h>

#include <gp_Circ.hxx>
#include <gp_Elips.hxx>
#include <gp_Pln.hxx>
#include <gp_Ax3.hxx>
#include <gp_Pnt.hxx>
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
#include <BRep_Builder.hxx>

#include <BRepBuilderAPI_MakeEdge.hxx>
#include <TopoDS_Compound.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>
#include <AIS_Shape.hxx>
#include <AIS_InteractiveContext.hxx>

#include <GeomAPI_ProjectPointOnCurve.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <TopoDS_Edge.hxx>
#include <vector>
#include <string>
#include <ElCLib.hxx>
#include <TCollection_ExtendedString.hxx>
#include <STEPCAFControl_Writer.hxx>
#include <STEPCAFControl_Reader.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <TopoDS_Shape.hxx>
#include <TDocStd_Document.hxx>
#include <STEPControl_Writer.hxx>
#include <XSControl_WorkSession.hxx>
#include <BRep_Builder.hxx>
#include <BRepMesh_IncrementalMesh.hxx>
#include <RWGltf_CafWriter.hxx>
#include <StlAPI_Writer.hxx>
#include <TDocStd_Document.hxx>
#include <TDocStd_Application.hxx>
#include <TDataStd_Name.hxx>
#include <TDataXtd_Triangulation.hxx>
#include <LocOpe_Pipe.hxx>


BRep_Builder builder;



MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	//树形控件设置
	/*QTreeWidgetItem *parentItem1 = new QTreeWidgetItem(ui->tr2);
	parentItem1->setText(0, QString("内轮廓"));
	QTreeWidgetItem *parentItem2 = new QTreeWidgetItem(ui->tr2);
	parentItem2->setText(0, QString("沟槽"));
	QTreeWidgetItem *parentItem3 = new QTreeWidgetItem(ui->tr2);
	parentItem3->setText(0, QString("二衬"));
	QTreeWidgetItem *parentItem4 = new QTreeWidgetItem(ui->tr2);
	parentItem4->setText(0, QString("回填与踏步"));
	QTreeWidgetItem *parentItem5 = new QTreeWidgetItem(ui->tr2);
	parentItem5->setText(0, QString("初支"));
	QTreeWidgetItem *parentItem6 = new QTreeWidgetItem(ui->tr2);
	parentItem6->setText(0, QString("防排水"));*/

	QTreeWidgetItem *parentItem1 = new QTreeWidgetItem(ui->tr2);
	parentItem1->setText(0, QString("内轮廓及二衬"));
	QTreeWidgetItem *parentItem2 = new QTreeWidgetItem(ui->tr2);
	parentItem2->setText(0, QString("初支"));
	QTreeWidgetItem *parentItem3 = new QTreeWidgetItem(ui->tr2);
	parentItem3->setText(0, QString("回填踏步及沟槽"));
	QTreeWidgetItem *parentItem4 = new QTreeWidgetItem(ui->tr2);
	parentItem4->setText(0, QString("防排水"));


	/*QTreeWidgetItem *childItem1 = new QTreeWidgetItem(parentItem3);
	childItem1->setText(0, QString("中心沟"));
	QTreeWidgetItem *childItem2 = new QTreeWidgetItem(parentItem3);
	childItem2->setText(0, QString("侧沟"));
	QTreeWidgetItem *childItem4_1 = new QTreeWidgetItem(parentItem5);
	childItem4_1->setText(0, QString("初支喷混"));
	QTreeWidgetItem *childItem4_2 = new QTreeWidgetItem(parentItem5);
	childItem4_2->setText(0, QString("型钢钢架"));*/

	/*QTreeWidgetItem *childItem1 = new QTreeWidgetItem(parentItem3);
	childItem1->setText(0, QString("中心沟"));
	QTreeWidgetItem *childItem2 = new QTreeWidgetItem(parentItem3);
	childItem2->setText(0, QString("侧沟"));
	QTreeWidgetItem *childItem4_1 = new QTreeWidgetItem(parentItem2);
	childItem4_1->setText(0, QString("初支喷混"));
	QTreeWidgetItem *childItem4_2 = new QTreeWidgetItem(parentItem2);
	childItem4_2->setText(0, QString("型钢钢架"));*/

	QTreeWidgetItem *childItem3_1 = new QTreeWidgetItem(parentItem3);
	childItem3_1->setText(0, QString("中心沟"));
	QTreeWidgetItem *childItem3_2 = new QTreeWidgetItem(parentItem3);
	childItem3_2->setText(0, QString("侧沟"));
	QTreeWidgetItem *childItem2_1 = new QTreeWidgetItem(parentItem2);
	childItem2_1->setText(0, QString("初支喷混"));
	QTreeWidgetItem *childItem2_2 = new QTreeWidgetItem(parentItem2);
	childItem2_2->setText(0, QString("型钢钢架"));

	QTreeWidgetItem *parentItem11 = new QTreeWidgetItem(ui->tr1);
	parentItem11->setText(0, QString("内轮廓"));
	QTreeWidgetItem *parentItem12 = new QTreeWidgetItem(ui->tr1);
	parentItem12->setText(0, QString("沟槽"));
	QTreeWidgetItem *parentItem13 = new QTreeWidgetItem(ui->tr1);
	parentItem13->setText(0, QString("二衬"));
	QTreeWidgetItem *parentItem14 = new QTreeWidgetItem(ui->tr1);
	parentItem14->setText(0, QString("回填与踏步"));
	QTreeWidgetItem *parentItem15 = new QTreeWidgetItem(ui->tr1);
	parentItem15->setText(0, QString("倒切式帽檐"));


	QTreeWidgetItem *childItem12_1 = new QTreeWidgetItem(parentItem12);
	childItem12_1->setText(0, QString("中心沟"));
	QTreeWidgetItem *childItem12_2 = new QTreeWidgetItem(parentItem12);
	childItem12_2->setText(0, QString("侧沟"));


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
	dia_15 = new InvertedBrim();
	dia_12_1 = new dia12_1();
	dia_12_2 = new dia12_2();

	//连接树形控件和下方点击后的操作
	connect(ui->tr1, &QTreeWidget::itemClicked, this, &MainWindow::onTreeWidgetItemClicked1);
	connect(ui->tr2, &QTreeWidget::itemClicked, this, &MainWindow::onTreeWidgetItemClicked2);

	////连接信号和dia弹窗
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

	//连接信号和dia弹窗
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
	//将occ显示函数置于底层以免覆盖树形控件
	ui->tabWidget->raise();
	ui->OCCWid->lower();
	ui->OCCWid->setAttribute(Qt::WA_TransparentForMouseEvents);
	ui->OCCWid->installEventFilter(ui->OCCWid);

	//将dia中的信号与下方函数连接
	//connect(dia_11, SIGNAL(par_view11()), this, SLOT(makeLine()));
	//connect(CenterGroove_1, SIGNAL(par_view_centergroove()), this, SLOT(makecentergroove()));
	//connect(sidegroove_1, SIGNAL(par_view_sidegroove()), this, SLOT(makesidegroove()));
	// 连接 dialog 发射的信号与当前类的槽函数
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

	connect(dia_15, SIGNAL(sendInvertedBrimCoordinatesf(const InvertedBrim2&)),
		this, SLOT(showInvertedBrim(const InvertedBrim2&)));

	connect(ui->erchen_action, &QAction::triggered, this, [=]() {
		emit par1();
	});

	connect(ui->chuzhi_action, &QAction::triggered, this, [=]() {
		emit par2_1();
	});

	connect(ui->xinggang_action, &QAction::triggered, this, [=]() {
		emit par2_2();
	});

	connect(ui->zhongxingou_action, &QAction::triggered, this, [=]() {
		emit par3_1();
	});

	connect(ui->cegou_action, &QAction::triggered, this, [=]() {
		emit par3_2();
	});


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
	// 调用 makeTabu() 函数，并传递 SquareCoordinates 结构的坐标参数
	makeLine(coords);
}

void MainWindow::makeLine(const CenterGrooveCoordinates& coords)
{
	// 根据圆点为中心创建对称变换
	gp_Trsf mirrorTransform_GC;
	mirrorTransform_GC.SetMirror(gp_Ax2(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(1.0, 0.0, 0.0))); // 沿 Y 轴对称

	gp_Ax2 anAxis_GC; // 表示坐标系的类，可以定义坐标系的原点和方向
	anAxis_GC.SetLocation(gp_Pnt(0.0, 0.0, 0.0)); // 设置坐标系的原点，这里将原点设置在三维空间的 (0, 0, 0) 

												  // 创建道床底面
	gp_Pnt P2_GC(-250, -294.5, 0); // 中心盖板上边中点 P2_GC
	gp_Pnt P2_GC_m(250, -294.5, 0); // 中心盖板上边中点 P2_GC

	Standard_Real trackbed_leftdistance = 210.0; // 道床底面到排水槽距离
												 //Standard_Real trackbed_slope = 0.02; // 道床底面坡度
	Standard_Real trackbed_slope = 0.02; // 道床底面坡度
	gp_Vec leftDirection_track_bed_GC(-trackbed_leftdistance, -trackbed_leftdistance * trackbed_slope, 0.0); // 左侧线段的方向向量
	gp_Pnt P3_GC = P2_GC.Translated(leftDirection_track_bed_GC); // 道床左侧最低点
	gp_Pnt P3_GC_m(-P3_GC.X(), P3_GC.Y(), P3_GC.Z());

	Standard_Real trackbed_rightdistance = 200.0; // 道床底面到中心盖板右侧距离
												  // Standard_Real slope_track_bed_GC = 0.02; // 道床底面的坡度
	gp_Vec rightDirection_track_bed_GC(trackbed_rightdistance, -trackbed_rightdistance*trackbed_slope, 0.0);  //右侧线段的方向向量
	gp_Pnt P4_GC = P2_GC.Translated(rightDirection_track_bed_GC); // 道床右侧最低点
	gp_Pnt P4_GC_m(-P4_GC.X(), P4_GC.Y(), P4_GC.Z());

																  // 创建道床底面左侧线段
	TopoDS_Edge leftEdge_track_bed_GC = BRepBuilderAPI_MakeEdge(P2_GC, P3_GC);
	Handle(AIS_Shape) AisleftEdge_track_bed_GC = new AIS_Shape(leftEdge_track_bed_GC);

	// 创建道床底面右侧线段
	TopoDS_Edge rightEdge_track_bed_GC = BRepBuilderAPI_MakeEdge(P2_GC, P4_GC);
	Handle(AIS_Shape) AisrightEdge_track_bed_GC = new AIS_Shape(rightEdge_track_bed_GC);

	//Standard_Real P1_O1_Ydistance = P4_GC.Y(); // P1 和 P4 的纵坐标相同

	Standard_Real P1_O1_Ydistance = coords.P1; // P1 和 P4 的纵坐标相同


											   // 创建中心沟盖板
	gp_Pnt P1_GC(0, -P1_O1_Ydistance, 0); //中心沟盖板的上边中点

										 //Standard_Real centercover_Xlength = 70.0;  // 中心沟盖板的长度
										 //Standard_Real centercover_Ylength = 8.0;    // 中心沟盖板的宽度

	Standard_Real centercover_Xlength = coords.P2_x;  // 中心沟盖板的长度
	Standard_Real centercover_Ylength = coords.P2_y;    // 中心沟盖板的宽度

														// 计算中心沟盖板四个角点的坐标
	gp_Pnt upperLeftPoint_center_cover_GC(P1_GC.X() - centercover_Xlength / 2.0, P1_GC.Y(), 0);
	gp_Pnt upperRightPoint_center_cover_GC(P1_GC.X() + centercover_Xlength / 2.0, P1_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_center_cover_GC(P1_GC.X() - centercover_Xlength / 2.0, P1_GC.Y() - centercover_Ylength, 0);
	gp_Pnt lowerRightPoint_center_cover_GC(P1_GC.X() + centercover_Xlength / 2.0, P1_GC.Y() - centercover_Ylength, 0);

	// 创建中心沟盖板的四条边
	BRepBuilderAPI_MakeWire wireMaker_center_cover_GC;
	wireMaker_center_cover_GC.Add(BRepBuilderAPI_MakeEdge(upperLeftPoint_center_cover_GC, upperRightPoint_center_cover_GC));
	wireMaker_center_cover_GC.Add(BRepBuilderAPI_MakeEdge(upperRightPoint_center_cover_GC, lowerRightPoint_center_cover_GC));
	wireMaker_center_cover_GC.Add(BRepBuilderAPI_MakeEdge(lowerRightPoint_center_cover_GC, lowerLeftPoint_center_cover_GC));
	wireMaker_center_cover_GC.Add(BRepBuilderAPI_MakeEdge(lowerLeftPoint_center_cover_GC, upperLeftPoint_center_cover_GC));
	wireMaker_center_cover_GC.Build();

	// 创建中心沟盖板立方体
	BRepPrimAPI_MakeBox box_center_cover_GC(upperLeftPoint_center_cover_GC, centercover_Xlength, -centercover_Ylength, -70.0);

	// 获取中心沟盖板立方体
	TopoDS_Shape cubeShape_center_cover_GC = box_center_cover_GC.Shape();
	TopoDS_Solid cube_center_cover_GC = TopoDS::Solid(cubeShape_center_cover_GC);
	Handle(AIS_Shape) Aiscube_center_cover_GC = new AIS_Shape(cube_center_cover_GC);

	// 左侧半圆形排水槽
	Standard_Real Drainage_radius = 5.0; // 排水槽的半径
	gp_Pnt leftpoint_Drainage_GC(P3_GC.X() - 2 * Drainage_radius, P3_GC.Y(), 0.0); // 排水槽左侧点
	gp_Pnt leftpoint_Drainage_GC_m(-P3_GC.X() + 2 * Drainage_radius, P3_GC.Y(), 0.0);
	gp_Pnt centerPoint_Drainage_GC(P3_GC.X() - Drainage_radius, P3_GC.Y(), 0.0); // 排水槽圆点
	gp_Pnt centerPoint_Drainage_GC_m(-P3_GC.X() + Drainage_radius, P3_GC.Y(), 0.0);

	Standard_Real startAngle_Drainage_GC = M_PI;  // 下半圆的起始角度，弧度制
	Standard_Real endAngle_Drainage_GC = 2 * M_PI;  // 下半圆的结束角度，弧度制

	gp_Ax2 circleAxis_Drainage_GC(centerPoint_Drainage_GC, gp_Dir(0, 0, 1)); // 定义排水槽的轴线
	gp_Ax2 circleAxis_Drainage_GC_m(centerPoint_Drainage_GC_m, gp_Dir(0, 0, 1));
	gp_Circ circle_Drainage_GC(circleAxis_Drainage_GC, Drainage_radius); // 使用定义的轴线和半径创建一个排水圆
	gp_Circ circle_Drainage_GC_m(circleAxis_Drainage_GC_m, Drainage_radius);

	TopoDS_Edge arcEdge_Drainage_GC = BRepBuilderAPI_MakeEdge(circle_Drainage_GC, startAngle_Drainage_GC, endAngle_Drainage_GC); // 创建排水圆的下半圆弧
	TopoDS_Edge arcEdge_Drainage_GC_m = BRepBuilderAPI_MakeEdge(circle_Drainage_GC_m, startAngle_Drainage_GC, endAngle_Drainage_GC); // 创建排水圆的下半圆弧
	TopoDS_Edge Edge_Drainage_GC = BRepBuilderAPI_MakeEdge(P3_GC, leftpoint_Drainage_GC); // 创建排水圆左侧点到右侧点的线段

	//建立半圆弧的闭合面
	BRepBuilderAPI_MakeWire makeWire_Drainage_GC; // 建立半圆弧的闭合线段
	makeWire_Drainage_GC.Add(arcEdge_Drainage_GC); // 将下半圆弧边缘添加到闭合线段
	makeWire_Drainage_GC.Add(Edge_Drainage_GC); // 将从圆左侧点到右侧点的线段添加到闭合线段
	TopoDS_Wire sectorWire_Drainage_GC = makeWire_Drainage_GC.Wire(); // 获取闭合线段作为半圆弧的闭合面
	BRepBuilderAPI_MakeFace Round_Drainage_GC(sectorWire_Drainage_GC); // 将闭合线段转化为半圆弧闭合面
	TopoDS_Face sectorRound_Drainage_GC = Round_Drainage_GC.Face(); // 获取半圆弧闭合面

	gp_Vec extrusionVec_Drainage_GC(0, 0, -70.0); // 沿着 Z 轴方向拉伸 70 个单位
	BRepPrimAPI_MakePrism makeRound_Drainage_GC(sectorRound_Drainage_GC, extrusionVec_Drainage_GC); // 使用半圆弧闭合面进行拉伸，建立排水槽立方体
	TopoDS_Shape RoundShape_Drainage_GC = makeRound_Drainage_GC.Shape(); // 获取排水槽立方体的形状
	TopoDS_Solid Round_solid_Drainage_GC = TopoDS::Solid(RoundShape_Drainage_GC); // 将排水槽立方体转换为实体
	Handle(AIS_Shape) AisRound_Drainage_GC = new AIS_Shape(Round_solid_Drainage_GC); // 创建一个可视化对象来显示排水槽立方体

	////与隧道内轮廓相交
	//gp_Pnt leftPoint(P3.X() - 2 * radius, P3.Y(), 0.0);
	//gp_Vec direction2(0.0, -1.0, 0.0);
	//gp_Lin line(leftPoint, direction2);
	////Handle(gp_Lin) linegp = new gp_Lin(line);

	//// 构造圆对象
	//gp_Circ circle2(gp_Ax2(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(0.0, 0.0, 1.0)), 1.0);

	//// 计算直线与圆的交点
	//GeomAPI_IntCS intersection(line, circle2);
	//if (intersection.IsDone() && intersection.NbPoints() > 0) {
	//	for (int i = 1; i <= intersection.NbPoints(); i++) {
	//		gp_Pnt intersectionPoint = intersection.Point(i);
	//		// 处理交点
	//		// ...
	//	}
	//}

	// 创建中心沟槽
	gp_Pnt P6_GC(0, -P1_O1_Ydistance - centercover_Ylength, 0); // 中心沟槽上边的中点
															   //Standard_Real centergroove_Xlength = 60.0;  // 中心沟槽的长度
															   //Standard_Real centergroove_Ylength = 80.0;   // 中心沟槽的宽度

	Standard_Real centergroove_Xlength = coords.P3_x;  // 中心沟槽的长度
	Standard_Real centergroove_Ylength = coords.P3_y;   // 中心沟槽的宽度

														// 计算中心沟槽四个角点的坐标
	gp_Pnt upperLeftPoint_center_GC(P6_GC.X() - centergroove_Xlength / 2.0, P6_GC.Y(), 0);
	gp_Pnt upperRightPoint_center_GC(P6_GC.X() + centergroove_Xlength / 2.0, P6_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_center_GC(P6_GC.X() - centergroove_Xlength / 2.0, P6_GC.Y() - centergroove_Ylength, 0);
	gp_Pnt lowerRightPoint_center_GC(P6_GC.X() + centergroove_Xlength / 2.0, P6_GC.Y() - centergroove_Ylength, 0);

	// 创建中心沟槽的四条线段
	BRepBuilderAPI_MakeWire wireMaker_center_GC;
	wireMaker_center_GC.Add(BRepBuilderAPI_MakeEdge(upperLeftPoint_center_GC, upperRightPoint_center_GC));
	wireMaker_center_GC.Add(BRepBuilderAPI_MakeEdge(upperRightPoint_center_GC, lowerRightPoint_center_GC));
	wireMaker_center_GC.Add(BRepBuilderAPI_MakeEdge(lowerRightPoint_center_GC, lowerLeftPoint_center_GC));
	wireMaker_center_GC.Add(BRepBuilderAPI_MakeEdge(lowerLeftPoint_center_GC, upperLeftPoint_center_GC));
	wireMaker_center_GC.Build();

	// 创建中心沟槽的闭合面
	TopoDS_Wire rectangleWire_center_GC = wireMaker_center_GC.Wire(); // 转化为中心沟槽的闭合面
	BRepBuilderAPI_MakeFace rectangle_center_GC(rectangleWire_center_GC);
	TopoDS_Face rectangleFace_center_GC = rectangle_center_GC.Face(); // 获取中心沟槽闭合面
																	  //Handle(AIS_Shape) Aisrectangle_center_GC = new AIS_Shape(rectangleFace_center_GC);

																	  // 创建中心沟槽的立方体
	gp_Vec extrusionVec_center_GC(0, 0, -70.0); // 沿着 Z 轴方向拉伸 70 个单位
	BRepPrimAPI_MakePrism makecube_center_GC(rectangleFace_center_GC, extrusionVec_center_GC);
	TopoDS_Shape cubeShape_center_GC = makecube_center_GC.Shape();
	TopoDS_Solid cube_center_GC = TopoDS::Solid(cubeShape_center_GC);
	Handle(AIS_Shape) Aiscube_center_GC = new AIS_Shape(cube_center_GC);

	//创建中心沟槽混凝土层
	Standard_Real concrete_layer = 20;
	//Standard_Real centerconcrete_Xlength = centergroove_Xlength + 2 * concrete_layer;  // 中心沟槽混凝土层的长度
	//Standard_Real centerconcrete_Ylength = centergroove_Ylength + concrete_layer + centercover_Ylength + 5.0;   // 中心沟槽混凝土层的宽度

	Standard_Real centerconcrete_Xlength = coords.P4_x;  // 中心沟槽混凝土层的长度
	Standard_Real centerconcrete_Ylength = coords.P4_y;   // 中心沟槽混凝土层的宽度

														  // 计算中心沟槽混凝土层四个角点的坐标
	gp_Pnt upperLeftPoint_center_concrete_GC(P1_GC.X() - centerconcrete_Xlength / 2.0, P1_GC.Y(), 0);
	gp_Pnt upperRightPoint_center_concrete_GC(P1_GC.X() + centerconcrete_Xlength / 2.0, P1_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_center_concrete_GC(P1_GC.X() - centerconcrete_Xlength / 2.0, P1_GC.Y() - centerconcrete_Ylength, 0);
	gp_Pnt lowerRightPoint_center_concrete_GC(P1_GC.X() + centerconcrete_Xlength / 2.0, P1_GC.Y() - centerconcrete_Ylength, 0);

	// 中心沟槽混凝土层的四条边
	BRepBuilderAPI_MakeWire wireMaker_center_concrete_GC;
	wireMaker_center_concrete_GC.Add(BRepBuilderAPI_MakeEdge(upperRightPoint_center_concrete_GC, lowerRightPoint_center_concrete_GC));
	wireMaker_center_concrete_GC.Add(BRepBuilderAPI_MakeEdge(lowerRightPoint_center_concrete_GC, lowerLeftPoint_center_concrete_GC));
	wireMaker_center_concrete_GC.Add(BRepBuilderAPI_MakeEdge(lowerLeftPoint_center_concrete_GC, upperLeftPoint_center_concrete_GC));
	wireMaker_center_concrete_GC.Add(BRepBuilderAPI_MakeEdge(upperLeftPoint_center_concrete_GC, upperRightPoint_center_concrete_GC));
	wireMaker_center_concrete_GC.Build();

	// 创建中心沟槽混凝土层的闭合面
	TopoDS_Wire rectangleWire_center_concrete_GC = wireMaker_center_concrete_GC.Wire();
	BRepBuilderAPI_MakeFace rectangle_center_concrete_GC(rectangleWire_center_concrete_GC);
	TopoDS_Face rectangleFace_center_concrete_GC = rectangle_center_concrete_GC.Face();
	//Handle(AIS_Shape) Aisrectangle_center_concrete_GC = new AIS_Shape(rectangleFace_center_concrete_GC);

	// 创建中心沟槽混凝土层的立方体
	gp_Vec extrusionVec_center_concrete_GC(0, 0, -70.0); // 沿着 Z 轴方向拉伸 70 个单位
	BRepPrimAPI_MakePrism makecube_center_concrete_GC(rectangleFace_center_concrete_GC, extrusionVec_center_concrete_GC); //创建中心沟槽混凝土层立方体
	TopoDS_Shape cubeShape_center_concrete_GC = makecube_center_concrete_GC.Shape();
	TopoDS_Solid cube_center_concrete_GC = TopoDS::Solid(cubeShape_center_concrete_GC);
	Handle(AIS_Shape) Aiscube_center_concrete_GC = new AIS_Shape(cube_center_concrete_GC);


	// 中心沟盖板+缝隙
	Standard_Real length_gover_gap_GC = centercover_Xlength + 2.0;  // 中心沟盖板+缝隙的长度
	Standard_Real width_gover_gap_GC = centercover_Ylength;   // 中心沟盖板+缝隙的宽度

	// 计算中心沟盖板+缝隙四个角点的坐标
	gp_Pnt upperLeftPoint_gover_gap_GC(P1_GC.X() - length_gover_gap_GC / 2.0, P1_GC.Y(), 0);
	gp_Pnt upperRightPoint_gover_gap_GC(P1_GC.X() + length_gover_gap_GC / 2.0, P1_GC.Y(), 0);
	gp_Pnt lowerLeftPoint_gover_gap_GC(P1_GC.X() - length_gover_gap_GC / 2.0, P1_GC.Y() - width_gover_gap_GC, 0);
	gp_Pnt lowerRightPoint_gover_gap_GC(P1_GC.X() + length_gover_gap_GC / 2.0, P1_GC.Y() - width_gover_gap_GC, 0);

	// 创建中心沟盖板+缝隙立方体
	BRepPrimAPI_MakeBox box_gover_gap_GC(upperLeftPoint_gover_gap_GC, length_gover_gap_GC, -width_gover_gap_GC, -70.0);

	// 获取创建的中心沟盖板+缝隙立方体
	TopoDS_Shape cubeShape_gover_gap_GC = box_gover_gap_GC.Shape();
	TopoDS_Solid cube_gover_gap_GC = TopoDS::Solid(cubeShape_gover_gap_GC);
	Handle(AIS_Shape) Aiscube_gover_gap_GC = new AIS_Shape(cube_gover_gap_GC);


	//使用布尔运算得到中心沟的混凝土层
	BRepAlgoAPI_Cut cut1_center_concrete_GC(cubeShape_center_concrete_GC, cubeShape_center_GC);
	TopoDS_Shape cubeShape1_center_concrete_GC = cut1_center_concrete_GC.Shape();
	BRepAlgoAPI_Cut cut2_center_concrete_GC(cubeShape1_center_concrete_GC, cubeShape_gover_gap_GC);
	cut2_center_concrete_GC.Build();
	Handle(AIS_Shape) Aiscut_center_concrete_GC = new AIS_Shape(cut2_center_concrete_GC);
	Aiscut_center_concrete_GC->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(Aiscut_center_concrete_GC, Standard_True);


	//// 创建内轮廓部分的一些点
	//Standard_Real degrees_nlk = 18.0;   // 角度的度部分
	//Standard_Real minutes_nlk = 40.0;   // 角度的分部分
	//Standard_Real seconds_nlk = 18.0;   // 角度的秒部分
	Standard_Real trench_Overlength = 160.0;
	Standard_Real innercontour_trench_distance = 14.0;
	Standard_Real trenchcover_gap = 1.0;
	////Standard_Real trench_Overlength = 160.0;
	//Standard_Real angle_nlk = degrees_nlk + (minutes_nlk / 60.0) + (seconds_nlk / 3600.0);  // 将角度转换为度数表示
	//Standard_Real radians_nlk = angle_nlk * M_PI / 180.0;   // 将角度转换为弧度

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

	//Standard_Real result_nlk = tan(radians_nlk);   // 调用 tan 函数
	//gp_Pnt P7_nlk(-630.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt P7m_nlk(630.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt P8_nlk(-615.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt s1_nlk(-616.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt s2_nlk(-470.0, -630.0 * result_nlk, 0.0);
	//gp_Pnt s2_y_nlk(0.0, -630.0 * result_nlk, 0.0); // 过s2_nlk的x轴平行线在y轴上的交点
	//gp_Pnt s2_nlk_symmetry(470.0, -630.0 * result_nlk, 0.0); //s2_nlk关于y轴对称点


	gp_Pnt P7_nlk(CUT_O4_01X, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt P7m_nlk(-CUT_O4_01X, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt P8_nlk(CUT_O4_01X + innercontour_trench_distance + trenchcover_gap, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt s1_nlk(CUT_O4_01X + innercontour_trench_distance, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt s2_nlk(CUT_O4_01X + trench_Overlength, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt s2_y_nlk(0, CUT_O4_01Y, CUT_O4_01Z); // 过s2_nlk的x轴平行线在y轴上的交点
	gp_Pnt s2_nlk_symmetry(-CUT_O4_01X - trench_Overlength, CUT_O4_01Y, CUT_O4_01Z); //s2_nlk关于y轴对称点


																			  // 创建一些线
	TopoDS_Edge Edge1_nlk = BRepBuilderAPI_MakeEdge(P7_nlk, s1_nlk);
	Handle(AIS_Shape) AisEdge1_nlk = new AIS_Shape(Edge1_nlk);
	gp_Pnt leftpoint_Drainage_GC_nlk(s2_nlk.X(), P3_GC.Y(), CUT_O4_01Z); // 排水槽左侧点
	gp_Pnt leftpoint_Drainage_GC_nlk_m(-s2_nlk.X(), P3_GC.Y(), CUT_O4_01Z);
	TopoDS_Edge Edge2_nlk = BRepBuilderAPI_MakeEdge(s2_nlk, leftpoint_Drainage_GC_nlk);
	Handle(AIS_Shape) AisEdge2_nlk = new AIS_Shape(Edge2_nlk);
	gp_Pnt centerPoint_Drainage_GC_nlk(s2_nlk.X() + Drainage_radius, P3_GC.Y(), CUT_O4_01Z); // 排水槽圆点
	gp_Pnt centerPoint_Drainage_GC_nlk_m(-s2_nlk.X() - Drainage_radius, P3_GC.Y(), CUT_O4_01Z);
	gp_Ax2 circleAxis_Drainage_GC_nlk(centerPoint_Drainage_GC_nlk, gp_Dir(0, 0, 1)); // 定义排水槽的轴线
	gp_Circ circle_Drainage_GC_nlk(circleAxis_Drainage_GC_nlk, Drainage_radius); // 使用定义的轴线和半径创建一个排水圆

	gp_Ax2 circleAxis_Drainage_GC_nlk_m(centerPoint_Drainage_GC_nlk_m, gp_Dir(0, 0, 1));
	gp_Circ circle_Drainage_GC_nlk_m(circleAxis_Drainage_GC_nlk_m, Drainage_radius);

	TopoDS_Edge arcEdge_Drainage_GC_nlk = BRepBuilderAPI_MakeEdge(circle_Drainage_GC_nlk, startAngle_Drainage_GC, endAngle_Drainage_GC); // 创建排水圆的下半圆弧
	TopoDS_Edge arcEdge_Drainage_GC_nlk_m = BRepBuilderAPI_MakeEdge(circle_Drainage_GC_nlk_m, startAngle_Drainage_GC, endAngle_Drainage_GC); // 创建排水圆的下半圆弧
	


	//// 创建内轮廓
	//gp_Pnt center_nlk(0, 0, 0); // 圆心坐标
	//Standard_Real radius_nlk = sqrt(pow(630, 2) + pow(-CUT_O4_01Y, 2)); // 圆的半径

	//// 定义起始角度和终止角度（以弧度为单位）
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

	// 创建内轮廓
	gp_Pnt centerO4(-sin(alpha) * (R1_NLK - radius4_N), -cos(alpha) * (R1_NLK - radius4_N), 0.0);
	gp_Pnt centerO7(sin(alpha) * (R1_NLK - radius4_N), -cos(alpha) * (R1_NLK - radius4_N), 0.0);
	gp_Pnt CUT_O4_01(CUT_O4_01X, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt CUT_O4_03(CUT_O4_03X, CUT_O4_03Y, CUT_O4_03Z);
	gp_Pnt CUT_O7_01(-CUT_O4_01X, CUT_O4_01Y, CUT_O4_01Z);
	gp_Pnt CUT_O7_03(-CUT_O4_03X, CUT_O4_03Y, CUT_O4_03Z);
	/*gp_Pnt CUT_O7_01(CUT_O7_01X, CUT_O7_01Y, CUT_O7_01Z);
	gp_Pnt CUT_O7_03(CUT_O7_03X, CUT_O7_03Y, CUT_O7_03Z);*/
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

	Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O4_EC, CUT_O4_01, CUT_O4_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	Handle(Geom_TrimmedCurve) arcCurve_03 = GC_MakeArcOfCircle(Circle_P3_EC, CUT_O4_03, CUT_O7_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_03 = BRepBuilderAPI_MakeEdge(arcCurve_03);
	/*BRepBuilderAPI_Transform transform1_nlk(TarcCurve_01, mirrorTransform_GC);
	TopoDS_Edge TarcCurve_02 = TopoDS::Edge(transform1_nlk.Shape());*/
	Handle(Geom_TrimmedCurve) arcCurve_02 = GC_MakeArcOfCircle(Circle_O7_EC, CUT_O7_03, CUT_O7_01, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_02 = BRepBuilderAPI_MakeEdge(arcCurve_02);

	/*Handle(AIS_Shape) AisTarcCurve_03 = new AIS_Shape(TarcCurve_03);
	AisTarcCurve_03->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(AisTarcCurve_03, Standard_True);*/
	

	/*TopoDS_Edge aEdge2_nlk = BRepBuilderAPI_MakeEdge(CUT_O4_01, CUT_O7_01);
	Handle(AIS_Shape) AISaEdge2_nlk = new AIS_Shape(aEdge2_nlk);
	AISaEdge2_nlk->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(AISaEdge2_nlk, Standard_True);*/
	/*Handle(AIS_Shape) AisarcEdge2_nlk = new AIS_Shape(arcEdge2_nlk);
	AisarcEdge2_nlk->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(AisarcEdge2_nlk, Standard_True);*/
	//TopoDS_Edge arcEdge2_nlk = BRepBuilderAPI_MakeEdge(P7_nlk, P7m_nlk);
	//TopoDS_Edge arcEdge3_nlk = BRepBuilderAPI_MakeEdge(P7_nlk, CUT_O4_01);
	//TopoDS_Edge arcEdge4_nlk = BRepBuilderAPI_MakeEdge(CUT_O7_01, P7m_nlk);

	gp_Pnt P3_GC_nlk(s2_nlk.X() + 2 * Drainage_radius, P3_GC.Y(), CUT_O4_01Z);
	gp_Pnt P3_GC_nlk_m(-P3_GC_nlk.X(), P3_GC.Y(), CUT_O4_01Z);
	gp_Pnt P4_GC_nlk(P4_GC.X(), P4_GC.Y(), CUT_O4_01Z);
	gp_Pnt P4_GC_nlk_m(-P4_GC.X(), P4_GC.Y(), CUT_O4_01Z);
	gp_Pnt P1_GC_nlk(0, -P1_O1_Ydistance, CUT_O4_01Z);
	gp_Pnt P2_GC_nlk(-250, -294.5, CUT_O4_01Z); // 中心盖板上边中点 P2_GC
	gp_Pnt P2_GC_nlk_m(250, -294.5, CUT_O4_01Z); // 中心盖板上边中点 P2_GC


	//// 创建容器用于存储线段
	//std::vector<TopoDS_Edge> segments;
	//segments.push_back(TarcCurve_01);
	//segments.push_back(TarcCurve_02);
	//segments.push_back(TarcCurve_03);
	//segments.push_back(BRepBuilderAPI_MakeEdge(P7_nlk, s2_nlk));
	//segments.push_back(Edge2_nlk);
	//segments.push_back(arcEdge_Drainage_GC_nlk);
	//segments.push_back(BRepBuilderAPI_MakeEdge(P3_GC_nlk, P2_GC_nlk));
	//segments.push_back(BRepBuilderAPI_MakeEdge(P2_GC_nlk, P4_GC_nlk));
	//segments.push_back(BRepBuilderAPI_MakeEdge(P4_GC_nlk, P1_GC_nlk));
	//segments.push_back(BRepBuilderAPI_MakeEdge(P1_GC_nlk, P4_GC_nlk_m));
	//segments.push_back(BRepBuilderAPI_MakeEdge(P4_GC_nlk_m, P2_GC_nlk_m));
	//segments.push_back(BRepBuilderAPI_MakeEdge(P2_GC_nlk_m, P3_GC_nlk_m));
	//segments.push_back(arcEdge_Drainage_GC_nlk_m);
	//segments.push_back(BRepBuilderAPI_MakeEdge(leftpoint_Drainage_GC_nlk_m, s2_nlk_symmetry));
	//segments.push_back(BRepBuilderAPI_MakeEdge(s2_nlk_symmetry, P7m_nlk));


	//// 创建一个空的 TopoDS_Wire
	//TopoDS_Wire wire_1;
	//BRep_Builder wireBuilder;
	//wireBuilder.MakeWire(wire_1);

	//// 将所有的 TopoDS_Edge 添加到这个 TopoDS_Wire
	//for (const auto& segment : segments) {
	//	wireBuilder.Add(wire_1, segment);
	//}

	//// 将 TopoDS_Wire 添加到 BRepBuilderAPI_MakeFace
	//BRepBuilderAPI_MakeFace arcmakeFace_nlk(wire_1);



	BRepBuilderAPI_MakeWire arcmakeWire_nlk;
	arcmakeWire_nlk.Add(TarcCurve_01);
	arcmakeWire_nlk.Add(TarcCurve_02);
	arcmakeWire_nlk.Add(TarcCurve_03);
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P7_nlk, s2_nlk));
	arcmakeWire_nlk.Add(Edge2_nlk);
	arcmakeWire_nlk.Add(arcEdge_Drainage_GC_nlk);
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P3_GC_nlk, P2_GC_nlk));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P2_GC_nlk, P4_GC_nlk));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P4_GC_nlk, P1_GC_nlk));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P1_GC_nlk, P4_GC_nlk_m));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P4_GC_nlk_m, P2_GC_nlk_m));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(P2_GC_nlk_m, P3_GC_nlk_m));
	arcmakeWire_nlk.Add(arcEdge_Drainage_GC_nlk_m);
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(leftpoint_Drainage_GC_nlk_m, s2_nlk_symmetry));
	arcmakeWire_nlk.Add(BRepBuilderAPI_MakeEdge(s2_nlk_symmetry, P7m_nlk));


	//BRepBuilderAPI_MakeFace arcmakeFace_nlk(arcmakeWire_nlk);
	TopoDS_Wire arc_sectorWire_nlk = arcmakeWire_nlk.Wire();
	BRepBuilderAPI_MakeFace arcmakeFace_nlk(arc_sectorWire_nlk);
	TopoDS_Face arc_sectorFace_nlk = arcmakeFace_nlk.Face();
	//Handle(AIS_Shape) Aisarc_sectorFace_nlk = new AIS_Shape(arc_sectorFace_nlk);
	gp_Vec extrusionVec_nlk(0, 0, -70.0); // 沿着 Z 轴方向拉伸 70 个单位
	BRepPrimAPI_MakePrism arcmake_nlk(arc_sectorFace_nlk, extrusionVec_nlk);
	TopoDS_Shape arcShape_nlk = arcmake_nlk.Shape();
	//TopoDS_Solid arcbody_nlk = TopoDS::Solid(arcShape_nlk);
	/*Handle(AIS_Shape) AisarcShape_nlk = new AIS_Shape(arcShape_nlk);
	AisarcShape_nlk->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(AisarcShape_nlk, Standard_True);*/





	//// 创建道床底面的挖去空间的立方体
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
	//gp_Vec extrusionVec_empty_volume(0, 0, -70.0); // 沿着 Z 轴方向拉伸 70 个单位
	//BRepPrimAPI_MakePrism make_empty_volume(sectorFace_empty_volume, extrusionVec_empty_volume);
	//TopoDS_Shape Shape_empty_volume = make_empty_volume.Shape();
	////TopoDS_Solid body_empty_volume = TopoDS::Solid(Shape_empty_volume);


	// 将关于y轴的对称应用到挖掉的空间（并保留原来位置的挖掉的空间）
	/*BRepBuilderAPI_Transform transform_empty_volume(Shape_empty_volume, mirrorTransform_GC);
	transform_empty_volume.Build();
	TopoDS_Shape transformedShape_empty_volume = transform_empty_volume.Shape();*/
	/*BRepBuilderAPI_Transform transform_empty_volume(body_empty_volume, mirrorTransform_GC);
	transform_empty_volume.Build();*/
	//Handle(AIS_Shape) Aistransform_empty_volume = new AIS_Shape(transform_empty_volume);
	//TopoDS_Shape transformedShape_empty_volume = transform_empty_volume.Shape();



	//创建侧沟盖板
	Standard_Real trenchcover_Xlength = 43.0;  // 侧沟盖板的长度
	Standard_Real trenchcover_Ylength = 8.0;   // 侧沟盖板的宽度
	Standard_Real height_trench_cover = 70.0;

	// 创建侧沟盖板立方体
	BRepPrimAPI_MakeBox makeBox_trench_cover(P8_nlk, trenchcover_Xlength, -trenchcover_Ylength, -height_trench_cover);
	TopoDS_Shape BoxShape_trench_cover = makeBox_trench_cover.Shape();
	//TopoDS_Solid Box_trench_cover = makeBox_trench_cover.Solid();


	//其他测沟盖板（利用偏移创建）
	Standard_Real offsetDistance_trench_cover = trenchcover_Xlength + trenchcover_gap;

	gp_Vec translationVector2_trench_cover(offsetDistance_trench_cover, 0.0, 0.0);
	gp_Vec translationVector3_trench_cover(2 * offsetDistance_trench_cover, 0.0, 0.0);

	TopoDS_Shape offBoxShape2_trench_cover = CopyAndTranslateShape(BoxShape_trench_cover, translationVector2_trench_cover);
	//TopoDS_Solid Box2_trench_cover = TopoDS::Solid(offBoxShape2_trench_cover);
	TopoDS_Shape offBoxShape3_trench_cover = CopyAndTranslateShape(BoxShape_trench_cover, translationVector3_trench_cover);
	//TopoDS_Solid Box3_trench_cover = TopoDS::Solid(offBoxShape3_trench_cover);


	//三个槽
	//电力电缆槽
	gp_Pnt P9_GC(P8_nlk.X() + trenchcover_Xlength / 2.0, CUT_O4_01Y - trenchcover_Ylength, 0.0);
	Standard_Real powercable_Xlength = 30.0;  // 电力电缆槽的长度
	Standard_Real powercable_Ylength = 30.0;   // 电力电缆槽的宽度

	// 计算电力电缆槽四个角点的坐标
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


	// 创建电力电缆槽的立方体
	BRepPrimAPI_MakeBox box_power_cable(upperLeftPoint_power_cable, powercable_Xlength, -powercable_Ylength, -70.0);

	// 获取创建的电力电缆槽
	TopoDS_Shape box_Shape_power_cable = box_power_cable.Shape();
	//TopoDS_Solid cube_power_cable = TopoDS::Solid(box_Shape_power_cable);


	//创建侧沟槽
	gp_Pnt P10_GC(P9_GC.X() + 44, CUT_O4_01Y - trenchcover_Ylength, 0.0);
	Standard_Real sidegroove_Xlength = 30.0;  // 侧沟槽的长度
	Standard_Real sidegroove_Ylength = 80.0;   // 侧沟槽的宽度

	// 计算矩形四个角点的坐标
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

	// 创建侧沟槽立方体
	BRepPrimAPI_MakeBox box_measuring_groove(upperLeftPoint_measuring_groove, sidegroove_Xlength, -sidegroove_Ylength, -70.0);

	// 获取创建的侧沟槽
	TopoDS_Shape box_Shape_measuring_groove = box_measuring_groove.Shape();
	//TopoDS_Solid cube_measuring_groove = TopoDS::Solid(box_Shape_measuring_groove);


	//创建通信信号电缆槽
	gp_Pnt P11_GC(P10_GC.X() + 44, CUT_O4_01Y - trenchcover_Ylength, 0.0);
	Standard_Real communcable_Xlength = 35.0;  // 通信信号电缆槽的长度
	Standard_Real communcable_Ylength = 30.0;   // 通信信号电缆槽的宽度

	// 计算通信信号电缆槽四个角点的坐标
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

	// 创建通信信号电缆槽立方体
	BRepPrimAPI_MakeBox box_communication_cable(upperLeftPoint_communication_cable, communcable_Xlength, -communcable_Ylength, -70.0);

	// 获取创建的通信信号电缆槽
	TopoDS_Shape boxShape_communication_cable = box_communication_cable.Shape();
	//TopoDS_Solid cube_communication_cable = TopoDS::Solid(boxShape_communication_cable);

	TopoDS_Wire wire_communication_cable = wireMaker_communication_cable.Wire();


	// 将左侧三个测沟盖板放入组合体1中
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

	// 将左侧三个沟槽放在组合体2中
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

	// 将左侧的三个测沟盖板和三个沟槽放在组合体3中
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

	// 将关于y轴的对称应用到组合体1（并保留原来位置的组合体）
	BRepBuilderAPI_Transform transform1(compound1_s, mirrorTransform_GC);
	transform1.Build();
	TopoDS_Shape transformedShape1 = transform1.Shape();
	//TopoDS_Solid cube_transformedShape1 = TopoDS::Solid(transformedShape1);


	// 将关于y轴的对称应用到组合体2（并保留原来位置的组合体）
	BRepBuilderAPI_Transform transform2(compound2_s, mirrorTransform_GC);
	transform2.Build();
	TopoDS_Shape transformedShape2 = transform2.Shape();
	//TopoDS_Solid cube_transformedShape2 = TopoDS::Solid(transformedShape2);


	// 将关于y轴的对称应用到组合体3（并保留原来位置的组合体）
	BRepBuilderAPI_Transform transform3(compound3_s, mirrorTransform_GC);
	transform3.Build();
	TopoDS_Shape transformedShape3 = transform3.Shape();
	//TopoDS_Solid cube_transformedShape3 = TopoDS::Solid(transformedShape3);
	Handle(AIS_Shape) AistransformedShape3 = new AIS_Shape(transformedShape3);
	AistransformedShape3->SetColor(Quantity_NOC_YELLOW);
	//AistransformedShape3->SetTransparency(0.5);
	myOccView->getContext()->Display(AistransformedShape3, Standard_True);


	////一些点的坐标
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
	//一些点的坐标
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


	//导管
	Standard_Real distance_catheter = 14.0;
	Standard_Real slope_catheter = 0.02;
	gp_Vec Direction_catheter(distance_catheter, -distance_catheter*slope_catheter, 0.0);
	gp_Pnt s13_catheter = lowerRightPoint_power_cable.Translated(Direction_catheter);

	TopoDS_Edge Edge_catheter = BRepBuilderAPI_MakeEdge(lowerRightPoint_power_cable, s13_catheter);
	Handle(AIS_Shape) AisEdge_catheter = new AIS_Shape(Edge_catheter);
	Standard_Real offsetDistance_catheter = 2.0;

	// 偏移
	gp_Vec translationVector_catheter(0.0, offsetDistance_catheter, 0.0);
	TopoDS_Shape offsetShape_catheter = CopyAndTranslateShape(Edge_catheter, translationVector_catheter);
	Handle(AIS_Shape) AisoffsetShape_catheter = new AIS_Shape(offsetShape_catheter);


	// 使用布尔运算挖去测沟和中心沟槽，创建整个沟槽形状
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


	// 创建组合体5
	TopoDS_Compound compound5;
	BRep_Builder builder5;
	builder5.MakeCompound(compound5);
	/*builder5.Add(compound5, BoxShape_ce1);
	builder5.Add(compound5, offBoxShape_ce2);
	builder5.Add(compound5, offBoxShape_ce3);*/


	// 创建组合体6
	TopoDS_Compound compound6;
	BRep_Builder builder6;
	builder6.MakeCompound(compound6);


	// 将中心沟槽和中心盖板放入组合体7
	TopoDS_Compound compound7;
	BRep_Builder builder7;
	builder7.MakeCompound(compound7);
	builder7.Add(compound7, cubeShape_center_cover_GC);
	builder7.Add(compound7, cubeShape_center_GC);
	Handle(AIS_Shape) Aiscompound7 = new AIS_Shape(compound7);
	Aiscompound7->SetColor(Quantity_NOC_YELLOW);
	//Aiscompound7->SetTransparency(0.5);
	myOccView->getContext()->Display(Aiscompound7, Standard_True);


	// 创建组合体8
	TopoDS_Compound compound8;
	BRep_Builder builder8;
	builder8.MakeCompound(compound8);


	// 创建组合体9
	TopoDS_Compound compound9;
	BRep_Builder builder9;
	builder9.MakeCompound(compound9);



	//// 在Z轴方向移动整个沟槽
	//for (int i = 1; i < 10; i++)
	//{
	//	Standard_Real offsetDistance_GC = 70.0*i;
	//	gp_Vec translationVector_GC(0.0, 0.0, -offsetDistance_GC);

	//	TopoDS_Shape offcompound3_1 = CopyAndTranslateShape(compound3_s, translationVector_GC);
	//	builder5.Add(compound5, offcompound3_1);
	//	TopoDS_Shape offcutOp11 = CopyAndTranslateShape(cutOp9, translationVector_GC);
	//	builder6.Add(compound6, offcutOp11);
	//	TopoDS_Shape offcompound7 = CopyAndTranslateShape(compound7, translationVector_GC);
	//	builder6.Add(compound8, offcompound7);
	//	TopoDS_Shape offcut_ceng2 = CopyAndTranslateShape(cut2_center_concrete_GC, translationVector_GC);
	//	builder6.Add(compound9, offcut_ceng2);
	//}

	//Handle(AIS_Shape) Aiscompound5 = new AIS_Shape(compound5);
	//Aiscompound5->SetColor(Quantity_NOC_YELLOW);
	////Aiscompound5->SetTransparency(0.5);
	//myOccView->getContext()->Display(Aiscompound5, Standard_True);

	//BRepBuilderAPI_Transform transform5(compound5, mirrorTransform_GC);
	//transform5.Build();
	//TopoDS_Shape transformedShape5 = transform5.Shape();
	//Handle(AIS_Shape) AistransformedShape5 = new AIS_Shape(transformedShape5);
	//AistransformedShape5->SetColor(Quantity_NOC_YELLOW);
	////AistransformedShape5->SetTransparency(0.5);
	//myOccView->getContext()->Display(AistransformedShape5, Standard_True);

	//Handle(AIS_Shape) Aiscompound6 = new AIS_Shape(compound6);
	//Aiscompound6->SetColor(Quantity_NOC_BLUE);
	////Aiscompound6->SetTransparency(0.5);
	//myOccView->getContext()->Display(Aiscompound6, Standard_True);

	//Handle(AIS_Shape) Aiscompound8 = new AIS_Shape(compound8);
	//Aiscompound8->SetColor(Quantity_NOC_YELLOW);
	////Aiscompound8->SetTransparency(0.5);
	//myOccView->getContext()->Display(Aiscompound8, Standard_True);

	//Handle(AIS_Shape) Aiscompound9 = new AIS_Shape(compound9);
	//Aiscompound9->SetColor(Quantity_NOC_GREEN);
	//myOccView->getContext()->Display(Aiscompound9, Standard_True);

	//// 创建原始圆柱体的轴线
	//gp_Pnt location(0, 0, 0); // 圆柱体位置
	//gp_Dir direction(1, 1, 0); // 圆柱体方向
	//gp_Ax2 axis(location, direction);

	//// 创建原始圆柱体
	//Standard_Real radius = 10.0; // 圆柱体半径
	//Standard_Real height_ = 50.0; // 圆柱体高度
	//BRepPrimAPI_MakeCylinder cylinderMaker(axis, radius, height_);
	//TopoDS_Shape originalCylinder = cylinderMaker.Shape();

	//// 创建斜移变换
	//gp_Trsf translation;
	//translation.SetTranslation(gp_Vec(10, 20, 30)); // 沿着 (10, 20, 30) 方向斜移

	//// 使用 BRepBuilderAPI_Transform 对圆柱体进行变换，得到斜圆柱体
	//BRepBuilderAPI_Transform transform(originalCylinder, translation);
	//TopoDS_Shape slantedCylinder = transform.ModifiedShape(originalCylinder);
	//Handle(AIS_Shape) AisslantedCylinder = new AIS_Shape(slantedCylinder);
	//AisslantedCylinder->SetColor(Quantity_NOC_BLUE);
	//myOccView->getContext()->Display(AisslantedCylinder, Standard_True);


	//创建侧沟盖板钢筋N4和N5
	gp_Pnt O1_N4_s(P8_nlk.X() + 4.5, P8_nlk.Y() - 8 + 4.1, -2.0);
	gp_Pnt O1_N5_s(P8_nlk.X() + 2.0, P8_nlk.Y() - 8 + 3.4, -4.5);
	gp_Dir normal_z_s(0, 0, 1);
	gp_Dir normal_x_s(1, 0, 0);
	gp_Dir normal_y_s(0, 1, 0);

	Standard_Real radius_N4_s = 0.3; // 钢筋N4半径
	Standard_Real radius_N5_s = 0.4; // 钢筋N5半径
	gp_Ax2 axis_N4_s(O1_N4_s, normal_z_s);
	gp_Ax2 axis_N5_s(O1_N5_s, normal_x_s);

	//建立圆弧线N4和N5
	Handle(Geom_Circle) circle_N4_s = new Geom_Circle(axis_N4_s, radius_N4_s);
	BRepBuilderAPI_MakeEdge edgeMaker_N4_s(circle_N4_s);
	TopoDS_Edge edge_N4_s = edgeMaker_N4_s.Edge();
	Handle(Geom_Circle) circle_N5_s = new Geom_Circle(axis_N5_s, radius_N5_s);
	BRepBuilderAPI_MakeEdge edgeMaker_N5_s(circle_N5_s);
	TopoDS_Edge edge_N5_s = edgeMaker_N5_s.Edge();

	// 创建线圈N4和N5
	BRepBuilderAPI_MakeWire wireMaker_N4_s(edge_N4_s);
	TopoDS_Wire wire_N4_s = wireMaker_N4_s.Wire();
	BRepBuilderAPI_MakeWire wireMaker_N5_s(edge_N5_s);
	TopoDS_Wire wire_N5_s = wireMaker_N5_s.Wire();

	// 创建圆面
	BRepBuilderAPI_MakeFace faceMaker_N4_s(wire_N4_s);
	TopoDS_Face face_N4_s = faceMaker_N4_s.Face();
	gp_Vec extrusionVec_N4_s(0.0, 0.0, -66.0); // 沿着 Z 轴方向拉伸 66 个单位
	BRepPrimAPI_MakePrism make_N4_s(face_N4_s, extrusionVec_N4_s);
	TopoDS_Shape Shape_N4_s = make_N4_s.Shape();
	//TopoDS_Solid body_N4 = TopoDS::Solid(Shape_N4);
	BRepBuilderAPI_MakeFace faceMaker_N5_s(wire_N5_s);
	TopoDS_Face face_N5_s = faceMaker_N5_s.Face();
	gp_Vec extrusionVec_N5_s(39.0, 0.0, 0.0); // 沿着 X 轴方向拉伸 39 个单位
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

	// 创建侧勾盖板钢筋组合体1
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

	// 其他侧勾盖板钢筋
	Standard_Real offsetDistance_rebar1_s = 43.0;

	gp_Vec translationVector_rebar1_s(offsetDistance_rebar1_s, 0.0, 0.0);
	gp_Vec translationVector_rebar2_s(2 * offsetDistance_rebar1_s, 0.0, 0.0);

	TopoDS_Shape offShape_rebar1_s = CopyAndTranslateShape(compound_rebar1_s, translationVector_rebar1_s);
	TopoDS_Shape offShape_rebar2_s = CopyAndTranslateShape(compound_rebar1_s, translationVector_rebar2_s);

	// 创建侧勾盖板组合体2
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


	// 中心沟盖板钢筋
	gp_Pnt O1_N4_c(-centercover_Xlength / 2 + 4.0, P1_GC.Y() - 8 + 4.1, -2.0);
	gp_Pnt O1_N7_c(-centercover_Xlength / 2 + 2.0, P1_GC.Y() - 8 + 3.4, -4.0);

	Standard_Real radius_N4_c = 0.3; // 钢筋N4半径
	Standard_Real radius_N7_c = 0.4; // 钢筋N5半径
	gp_Ax2 axis_N4_c(O1_N4_c, normal_z_s);
	gp_Ax2 axis_N7_c(O1_N7_c, normal_x_s);

	// 建立圆弧线N4和N5
	Handle(Geom_Circle) circle_N4_c = new Geom_Circle(axis_N4_c, radius_N4_c);
	BRepBuilderAPI_MakeEdge edgeMaker_N4_c(circle_N4_c);
	TopoDS_Edge edge_N4_c = edgeMaker_N4_c.Edge();
	Handle(Geom_Circle) circle_N7_c = new Geom_Circle(axis_N7_c, radius_N7_c);
	BRepBuilderAPI_MakeEdge edgeMaker_N7_c(circle_N7_c);
	TopoDS_Edge edge_N7_c = edgeMaker_N7_c.Edge();

	// 创建线圈N4和N5
	BRepBuilderAPI_MakeWire wireMaker_N4_c(edge_N4_c);
	TopoDS_Wire wire_N4_c = wireMaker_N4_c.Wire();
	BRepBuilderAPI_MakeWire wireMaker_N7_c(edge_N7_c);
	TopoDS_Wire wire_N7_c = wireMaker_N7_c.Wire();

	// 创建圆面N4和N5
	BRepBuilderAPI_MakeFace faceMaker_N4_c(wire_N4_c);
	TopoDS_Face face_N4_c = faceMaker_N4_c.Face();
	gp_Vec extrusionVec_N4_c(0.0, 0.0, -36.0); // 沿着 Z 轴方向拉伸 36 个单位
	BRepPrimAPI_MakePrism make_N4_c(face_N4_c, extrusionVec_N4_c);
	TopoDS_Shape Shape_N4_c = make_N4_c.Shape();
	//TopoDS_Solid body_N4 = TopoDS::Solid(Shape_N4);
	BRepBuilderAPI_MakeFace faceMaker_N7_c(wire_N7_c);
	TopoDS_Face face_N7_c = faceMaker_N7_c.Face();
	gp_Vec extrusionVec_N7_c(66.0, 0.0, 0.0); // 沿着 X 轴方向拉伸 66 个单位
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

	// 创建中心沟盖板钢筋组合体1
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

	// 创建中心沟盖板钢筋组合体2
	TopoDS_Compound compound_rebar2_c;
	BRep_Builder builder_rebar2_c;
	builder_rebar2_c.MakeCompound(compound_rebar2_c);


	//// 在Z轴方向移动中心沟盖板钢筋
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


	// 创建中心沟混凝土中的钢筋N1
	Standard_Real long_horizontal_N1 = 90.0;
	Standard_Real protect1_layer_N1 = 5.0;
	Standard_Real protect2_layer_N1 = 4.2;
	Standard_Real long_vertical_N1 = centerconcrete_Ylength - protect1_layer_N1 - protect2_layer_N1 - width_gover_gap_GC;
	Standard_Real R2 = 12.0;
	Standard_Real radius_N1_cl = 0.6; // 钢筋N1半径
	Standard_Real startAngle_N1_cl = 1.5 * M_PI; // 起始角度
	Standard_Real endAngle_N1_cl = 2.0 * M_PI; // 终止角度
	gp_Pnt one_N1_cl(-long_horizontal_N1 / 2.0, P1_GC.Y() - centerconcrete_Ylength + protect1_layer_N1, -protect1_layer_N1); // 选取钢筋某处顶点
	gp_Pnt two_N1_cl(-long_horizontal_N1 / 2.0, P1_GC.Y() - width_gover_gap_GC - protect2_layer_N1, -protect1_layer_N1);
	//gp_Pnt two_N1_cl(-long_horizontal_N1 / 2.0 + 6 * radius_N1_cl, P1_GC.Y() - width_gover_gap_GC - protect2_layer_N1, -protect1_layer_N1);
	/*gp_Pnt center_N1_cl(-long_horizontal_N1 / 2.0 + 6 * radius_N1_cl, P1_GC.Y() - width_gover_gap_GC - protect2_layer_N1 - 6 * radius_N1_cl, -protect1_layer_N1);*/


	gp_Ax2 one_x_axis_N1_cl(one_N1_cl, normal_x_s);
	gp_Ax2 one_y_axis_N1_cl(one_N1_cl, normal_y_s);
	gp_Ax2 two_axis_N1_cl(two_N1_cl, normal_x_s);
	/*gp_Ax2 center_axis_N1_cl(center_N1_cl, normal_z_s);*/


	// 建立圆弧线N1
	Handle(Geom_Circle) one_x_circle_N1_cl = new Geom_Circle(one_x_axis_N1_cl, radius_N1_cl);
	BRepBuilderAPI_MakeEdge one_x_edgeMaker_N1_cl(one_x_circle_N1_cl);
	TopoDS_Edge one_x_edge_N1_cl = one_x_edgeMaker_N1_cl.Edge();
	Handle(Geom_Circle) one_y_circle_N1_cl = new Geom_Circle(one_y_axis_N1_cl, radius_N1_cl);
	BRepBuilderAPI_MakeEdge one_y_edgeMaker_N1_cl(one_y_circle_N1_cl);
	TopoDS_Edge one_y_edge_N1_cl = one_y_edgeMaker_N1_cl.Edge();
	Handle(Geom_Circle) two_circle_N1_cl = new Geom_Circle(two_axis_N1_cl, radius_N1_cl);
	BRepBuilderAPI_MakeEdge two_edgeMaker_N1_cl(two_circle_N1_cl);
	TopoDS_Edge two_edge_N1_cl = two_edgeMaker_N1_cl.Edge();


	// 创建线圈N1
	BRepBuilderAPI_MakeWire one_x_wireMaker_N1_cl(one_x_edge_N1_cl);
	TopoDS_Wire one_x_wire_N1_cl = one_x_wireMaker_N1_cl.Wire();
	BRepBuilderAPI_MakeWire one_y_wireMaker_N1_cl(one_y_edge_N1_cl);
	TopoDS_Wire one_y_wire_N1_cl = one_y_wireMaker_N1_cl.Wire();
	BRepBuilderAPI_MakeWire two_wireMaker_N1_cl(two_edge_N1_cl);
	TopoDS_Wire two_wire_N1_cl = two_wireMaker_N1_cl.Wire();
	/*BRepBuilderAPI_MakeWire three_wireMaker_N1_cl(three_edge_N1_cl);
	TopoDS_Wire three_wire_N1_cl = three_wireMaker_N1_cl.Wire();*/


	////创建圆弧形的钢筋段的拉伸曲线
	//TopoDS_Edge arcEdge_N1_cl = BRepBuilderAPI_MakeEdge(new Geom_Circle(center_axis_N1_cl, radius_N1_cl * 6), startAngle_N1_cl, endAngle_N1_cl);
	//BRepBuilderAPI_MakeWire wireBuilder_N1_cl;
	//wireBuilder_N1_cl.Add(arcEdge_N1_cl);
	//TopoDS_Wire wire_N1_cl = wireBuilder_N1_cl.Wire();


	// 创建圆面N1
	BRepBuilderAPI_MakeFace one_x_faceMaker_N1_cl(one_x_wire_N1_cl);
	TopoDS_Face one_x_face_N1_cl = one_x_faceMaker_N1_cl.Face();
	gp_Vec one_x_extrusionVec_N1_cl(45.0, 0.0, 0.0); // 沿着 X 轴方向拉伸 45 个单位
	BRepPrimAPI_MakePrism one_x_make_N1_cl(one_x_face_N1_cl, one_x_extrusionVec_N1_cl);
	TopoDS_Shape one_x_Shape_N1_cl = one_x_make_N1_cl.Shape();

	BRepBuilderAPI_MakeFace one_y_faceMaker_N1_cl(one_y_wire_N1_cl);
	TopoDS_Face one_y_face_N1_cl = one_y_faceMaker_N1_cl.Face();
	gp_Vec one_y_extrusionVec_N1_cl(0.0, two_N1_cl.Y() - one_N1_cl.Y(), 0.0);
	//gp_Vec one_y_extrusionVec_N1_cl(0.0, long_vertical_N1 - 6 * radius_N1_cl, 0.0); // 沿着 y 轴方向拉伸
	BRepPrimAPI_MakePrism one_y_make_N1_cl(one_y_face_N1_cl, one_y_extrusionVec_N1_cl);
	TopoDS_Shape one_y_Shape_N1_cl = one_y_make_N1_cl.Shape();

	BRepBuilderAPI_MakeFace two_faceMaker_N1_cl(two_wire_N1_cl);
	TopoDS_Face two_face_N1_cl = two_faceMaker_N1_cl.Face();
	//TopoDS_Shape two_arcshape_N1_cl = BRepOffsetAPI_MakePipe(wire_N1_cl, two_face_N1_cl).Shape();

	//gp_Vec two_extrusionVec_N1_cl(radius_N1_cl * 2 * R2, 0.0, 0.0); // 沿着 X 轴方向拉伸 14.4 个单位
	gp_Vec two_extrusionVec_N1_cl(5.0, 0.0, 0.0);
	BRepPrimAPI_MakePrism two_make_N1_cl(two_face_N1_cl, two_extrusionVec_N1_cl);
	TopoDS_Shape two_Shape_N1_cl = two_make_N1_cl.Shape();


	// 创建中心沟混凝土层钢筋N1组合体（左侧）
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


	// 创建中心沟混凝土层钢筋N1组合体的y轴对称体
	BRepBuilderAPI_Transform transform_N1_cl(compound_N1_cl, mirrorTransform_GC);
	transform_N1_cl.Build();
	TopoDS_Shape transformedShape_N1_cl = transform_N1_cl.Shape();
	Handle(AIS_Shape) AistransformedShape_N1_cl = new AIS_Shape(transformedShape_N1_cl);
	AistransformedShape_N1_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AistransformedShape_N1_cl, Standard_True);


	// 创建中心沟混凝土中的钢筋N2
	Standard_Real long_horizontal_N2 = 93.0;
	Standard_Real protect1_layer_N2 = 5.0;
	Standard_Real protect2_layer_N2 = 3.5;
	Standard_Real radius_N2_cl = 0.6; // 钢筋N2半径
	gp_Pnt O1_N2_cl(-long_horizontal_N2 / 2.0, P1_GC.Y() - centergroove_Ylength - width_gover_gap_GC - protect1_layer_N2, -protect1_layer_N2); // 选取钢筋某处顶点
	gp_Ax2 O1_axis_N2_cl(O1_N2_cl, normal_x_s);

	// 建立圆弧线N2
	Handle(Geom_Circle) O1_circle_N2_cl = new Geom_Circle(O1_axis_N2_cl, radius_N2_cl);
	BRepBuilderAPI_MakeEdge O1_edgeMaker_N2_cl(O1_circle_N2_cl);
	TopoDS_Edge O1_edge_N2_cl = O1_edgeMaker_N2_cl.Edge();

	// 创建线圈N2
	BRepBuilderAPI_MakeWire O1_wireMaker_N2_cl(O1_edge_N2_cl);
	TopoDS_Wire O1_wire_N2_cl = O1_wireMaker_N2_cl.Wire();

	// 创建圆面N2
	BRepBuilderAPI_MakeFace O1_faceMaker_N2_cl(O1_wire_N2_cl);
	TopoDS_Face O1_face_N2_cl = O1_faceMaker_N2_cl.Face();
	gp_Vec O1_extrusionVec_N2_cl(93.0, 0.0, 0.0); // 沿着 X 轴方向拉伸 93 个单位
	BRepPrimAPI_MakePrism O1_make_N2_cl(O1_face_N2_cl, O1_extrusionVec_N2_cl);
	TopoDS_Shape O1_Shape_N2_cl = O1_make_N2_cl.Shape();
	Handle(AIS_Shape) AisO1_Shape_N2_cl = new AIS_Shape(O1_Shape_N2_cl);
	AisO1_Shape_N2_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AisO1_Shape_N2_cl, Standard_True);


	// 创建中心沟混凝土中的钢筋N3
	Standard_Real protect1_layer_N3 = 4.2;
	Standard_Real protect2_layer_N3 = 3.5;
	Standard_Real protect3_layer_N3 = 5.0;
	//Standard_Real startAngle_N3_cl = 0.0 * M_PI; // 起始角度
	//Standard_Real endAngle_N3_cl = 0.5 * M_PI; // 终止角度
	Standard_Real long_vertical_N3 = centerconcrete_Ylength - width_gover_gap_GC - protect1_layer_N3 - protect2_layer_N3;
	Standard_Real radius_N3_cl = 0.6; // 钢筋N3半径
	gp_Pnt one_N3_cl(-centergroove_Xlength / 2 - protect3_layer_N3, P1_GC.Y() - width_gover_gap_GC - protect1_layer_N3, -protect3_layer_N3);
	//gp_Pnt one_N3_cl(-centergroove_Xlength / 2 - protect3_layer_N3, P1_GC.Y() - width_gover_gap_GC - protect1_layer_N3 - 6 * radius_N3_cl, -protect3_layer_N3);
	//gp_Pnt two_N3_cl(-centergroove_Xlength / 2 - protect3_layer_N3 - 6 * radius_N3_cl, P1_GC.Y() - width_gover_gap_GC - protect1_layer_N3, -protect3_layer_N3);
	//gp_Pnt center_N3_cl(-centergroove_Xlength / 2 - protect3_layer_N3 - 6 * radius_N3_cl, P1_GC.Y() - width_gover_gap_GC - protect1_layer_N3 - 6 * radius_N3_cl, -protect3_layer_N3);

	gp_Ax2 one_yaxis_N3_cl(one_N3_cl, normal_y_s);
	gp_Ax2 one_xaxis_N3_cl(one_N3_cl, normal_x_s);
	//gp_Ax2 center_axis_N3_cl(center_N3_cl, normal_z_s);

	// 建立圆弧线N3
	Handle(Geom_Circle) one_ycircle_N3_cl = new Geom_Circle(one_yaxis_N3_cl, radius_N3_cl);
	BRepBuilderAPI_MakeEdge one_yedgeMaker_N3_cl(one_ycircle_N3_cl);
	TopoDS_Edge one_yedge_N3_cl = one_yedgeMaker_N3_cl.Edge();
	Handle(Geom_Circle) one_xcircle_N3_cl = new Geom_Circle(one_xaxis_N3_cl, radius_N3_cl);
	BRepBuilderAPI_MakeEdge one_xedgeMaker_N3_cl(one_xcircle_N3_cl);
	TopoDS_Edge one_xedge_N3_cl = one_xedgeMaker_N3_cl.Edge();

	// 创建线圈N3
	BRepBuilderAPI_MakeWire one_ywireMaker_N3_cl(one_yedge_N3_cl);
	TopoDS_Wire one_ywire_N3_cl = one_ywireMaker_N3_cl.Wire();
	BRepBuilderAPI_MakeWire one_xwireMaker_N3_cl(one_xedge_N3_cl);
	TopoDS_Wire one_xwire_N3_cl = one_xwireMaker_N3_cl.Wire();

	////创建圆弧形的钢筋段的拉伸曲线
	//TopoDS_Edge arcEdge_N3_cl = BRepBuilderAPI_MakeEdge(new Geom_Circle(center_axis_N3_cl, radius_N3_cl * 6), startAngle_N3_cl, endAngle_N3_cl);
	//BRepBuilderAPI_MakeWire wireBuilder_N3_cl;
	//wireBuilder_N3_cl.Add(arcEdge_N3_cl);
	//TopoDS_Wire wire_N3_cl = wireBuilder_N3_cl.Wire();

	// 创建圆面N3
	BRepBuilderAPI_MakeFace one_yfaceMaker_N3_cl(one_ywire_N3_cl);
	TopoDS_Face one_yface_N3_cl = one_yfaceMaker_N3_cl.Face();
	gp_Vec one_yextrusionVec_N3_cl(0.0, -long_vertical_N3, 0.0); // 沿着 y 轴方向拉伸
	BRepPrimAPI_MakePrism one_ymake_N3_cl(one_yface_N3_cl, one_yextrusionVec_N3_cl);
	TopoDS_Shape one_yShape_N3_cl = one_ymake_N3_cl.Shape();

	//TopoDS_Shape one_arcshape_N1_cl = BRepOffsetAPI_MakePipe(wire_N3_cl, one_face_N3_cl).Shape();

	BRepBuilderAPI_MakeFace one_xfaceMaker_N3_cl(one_xwire_N3_cl);
	TopoDS_Face one_xface_N3_cl = one_xfaceMaker_N3_cl.Face();
	//gp_Vec two_extrusionVec_N3_cl(-24 * radius_N3_cl, 0.0, 0.0); // 沿着 x 轴方向拉伸
	gp_Vec one_xextrusionVec_N3_cl(-5.0, 0.0, 0.0); // 沿着 x 轴方向拉伸
	BRepPrimAPI_MakePrism one_xmake_N3_cl(one_xface_N3_cl, one_xextrusionVec_N3_cl);
	TopoDS_Shape one_xShape_N3_cl = one_xmake_N3_cl.Shape();

	// 创建中心沟混凝土层钢筋N3组合体（左侧）
	TopoDS_Compound compound_N3_cl;
	BRep_Builder builder_N3_cl;
	builder_N3_cl.MakeCompound(compound_N3_cl);
	builder_N3_cl.Add(compound_N3_cl, one_yShape_N3_cl);
	//builder_N3_cl.Add(compound_N3_cl, one_arcshape_N1_cl);
	builder_N3_cl.Add(compound_N3_cl, one_xShape_N3_cl);
	Handle(AIS_Shape) Aiscompound_N3_cl = new AIS_Shape(compound_N3_cl);
	Aiscompound_N3_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(Aiscompound_N3_cl, Standard_True);

	// 创建中心沟混凝土层钢筋N3组合体的y轴对称体
	BRepBuilderAPI_Transform transform_N3_cl(compound_N3_cl, mirrorTransform_GC);
	transform_N3_cl.Build();
	TopoDS_Shape transformedShape_N3_cl = transform_N3_cl.Shape();
	Handle(AIS_Shape) AistransformedShape_N3_cl = new AIS_Shape(transformedShape_N3_cl);
	AistransformedShape_N3_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AistransformedShape_N3_cl, Standard_True);


	// 创建中心沟混凝土中的钢筋N5
	Standard_Real protect1_layer_N5 = 3.5;
	Standard_Real protect2_layer_N5 = 5.0;
	Standard_Real long_vertical_N5 = 13.0;
	Standard_Real distance1_N5 = 6.15;
	Standard_Real radius_N5_cl = 0.4; // 钢筋N5半径
	gp_Pnt O1_N5_cl(-centergroove_Xlength / 2.0 - protect1_layer_N5, P1_GC.Y() - centerconcrete_Ylength + distance1_N5, -protect2_layer_N5);
	gp_Ax2 O1_axis_N5_cl(O1_N5_cl, normal_x_s);

	// 建立圆弧线N5
	Handle(Geom_Circle) O1_circle_N5_cl = new Geom_Circle(O1_axis_N5_cl, radius_N5_cl);
	BRepBuilderAPI_MakeEdge O1_edgeMaker_N5_cl(O1_circle_N5_cl);
	TopoDS_Edge O1_edge_N5_cl = O1_edgeMaker_N5_cl.Edge();

	// 创建线圈N5
	BRepBuilderAPI_MakeWire O1_wireMaker_N5_cl(O1_edge_N5_cl);
	TopoDS_Wire O1_wire_N5_cl = O1_wireMaker_N5_cl.Wire();

	// 创建圆面N5
	BRepBuilderAPI_MakeFace O1_faceMaker_N5_cl(O1_wire_N5_cl);
	TopoDS_Face O1_face_N5_cl = O1_faceMaker_N5_cl.Face();
	gp_Vec O1_extrusionVec_N5_cl(-long_vertical_N5, 0.0, 0.0); // 沿着 X 轴方向拉伸 
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

	// 创建中心沟混凝土层钢筋N5组合体（左侧）
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

	// 创建中心沟混凝土层钢筋N5组合体的y轴对称体
	BRepBuilderAPI_Transform transform_N5_cl(compound_N5_cl, mirrorTransform_GC);
	transform_N5_cl.Build();
	TopoDS_Shape transformedShape_N5_cl = transform_N5_cl.Shape();
	Handle(AIS_Shape) AistransformedShape_N5_cl = new AIS_Shape(transformedShape_N5_cl);
	AistransformedShape_N5_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AistransformedShape_N5_cl, Standard_True);


	// 创建中心沟混凝土中的钢筋N5a
	Standard_Real protect1_layer_N5a = 3.5;
	Standard_Real protect2_layer_N5a = 5.0;
	Standard_Real distance1_N5a = 20.0;
	Standard_Real long_vertical_N5a = 18.0;
	Standard_Real radius_N5a_cl = 0.4; // 钢筋N5a半径
	gp_Pnt O1_N5a_cl(-distance1_N5a, P1_GC.Y() - centergroove_Ylength - width_gover_gap_GC - protect1_layer_N5a, -protect2_layer_N5a);
	gp_Ax2 O1_axis_N5a_cl(O1_N5a_cl, normal_y_s);

	// 建立圆弧线N5a
	Handle(Geom_Circle) O1_circle_N5a_cl = new Geom_Circle(O1_axis_N5a_cl, radius_N5a_cl);
	BRepBuilderAPI_MakeEdge O1_edgeMaker_N5a_cl(O1_circle_N5a_cl);
	TopoDS_Edge O1_edge_N5a_cl = O1_edgeMaker_N5a_cl.Edge();

	// 创建线圈N5a
	BRepBuilderAPI_MakeWire O1_wireMaker_N5a_cl(O1_edge_N5a_cl);
	TopoDS_Wire O1_wire_N5a_cl = O1_wireMaker_N5a_cl.Wire();

	// 创建圆面N5a
	BRepBuilderAPI_MakeFace O1_faceMaker_N5a_cl(O1_wire_N5a_cl);
	TopoDS_Face O1_face_N5a_cl = O1_faceMaker_N5a_cl.Face();
	gp_Vec O1_extrusionVec_N5a_cl(0.0, -long_vertical_N5a, 0.0); // 沿着 y 轴方向拉伸 
	BRepPrimAPI_MakePrism O1_make_N5a_cl(O1_face_N5a_cl, O1_extrusionVec_N5a_cl);
	TopoDS_Shape O1_Shape_N5a_cl = O1_make_N5a_cl.Shape();
	Handle(AIS_Shape) AisO1_Shape_N5a_cl = new AIS_Shape(O1_Shape_N5a_cl);
	AisO1_Shape_N5a_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AisO1_Shape_N5a_cl, Standard_True);

	// 创建中心沟混凝土层钢筋N5a组合体的y轴对称体
	BRepBuilderAPI_Transform transform_N5a_cl(O1_Shape_N5a_cl, mirrorTransform_GC);
	transform_N5a_cl.Build();
	TopoDS_Shape transformedShape_N5a_cl = transform_N5a_cl.Shape();
	Handle(AIS_Shape) AistransformedShape_N5a_cl = new AIS_Shape(transformedShape_N5a_cl);
	AistransformedShape_N5a_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AistransformedShape_N5a_cl, Standard_True);

	// 创建中心沟混凝土中的钢筋N4
	Standard_Real protect1_layer_N4 = 3.5;
	Standard_Real protect2_layer_N4 = 5.0;
	Standard_Real distance1_N4 = 20.0;
	Standard_Real long_vertical_N4 = 18.0;
	Standard_Real radius_N4_cl = 0.6; // 钢筋N4半径
	gp_Pnt O1_N4_cl(-distance1_N4, P1_GC.Y() - centergroove_Ylength - width_gover_gap_GC - protect1_layer_N4, -protect2_layer_N4);
	gp_Ax2 O1_axis_N4_cl(O1_N4_cl, normal_z_s);

	// 建立圆弧线N4
	Handle(Geom_Circle) O1_circle_N4_cl = new Geom_Circle(O1_axis_N4_cl, radius_N4_cl);
	BRepBuilderAPI_MakeEdge O1_edgeMaker_N4_cl(O1_circle_N4_cl);
	TopoDS_Edge O1_edge_N4_cl = O1_edgeMaker_N4_cl.Edge();

	// 创建线圈N4
	BRepBuilderAPI_MakeWire O1_wireMaker_N4_cl(O1_edge_N4_cl);
	TopoDS_Wire O1_wire_N4_cl = O1_wireMaker_N4_cl.Wire();

	// 创建圆面N4
	BRepBuilderAPI_MakeFace O1_faceMaker_N4_cl(O1_wire_N4_cl);
	TopoDS_Face O1_face_N4_cl = O1_faceMaker_N4_cl.Face();
	gp_Vec O1_extrusionVec_N4_cl(0.0, -long_vertical_N4, 0.0); // 沿着 y 轴方向拉伸 
	BRepPrimAPI_MakePrism O1_make_N4_cl(O1_face_N4_cl, O1_extrusionVec_N4_cl);
	TopoDS_Shape O1_Shape_N4_cl = O1_make_N4_cl.Shape();
	Handle(AIS_Shape) AisO1_Shape_N4_cl = new AIS_Shape(O1_Shape_N4_cl);
	AisO1_Shape_N4_cl->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AisO1_Shape_N4_cl, Standard_True);

	//// 创建中心沟混凝土层钢筋N4组合体的y轴对称体
	//BRepBuilderAPI_Transform transform_N5a_cl(O1_Shape_N5a_cl, mirrorTransform_GC);
	//transform_N5a_cl.Build();
	//TopoDS_Shape transformedShape_N5a_cl = transform_N5a_cl.Shape();
	//Handle(AIS_Shape) AistransformedShape_N5a_cl = new AIS_Shape(transformedShape_N5a_cl);
	//AistransformedShape_N5a_cl->SetColor(Quantity_NOC_RED);
	//myOccView->getContext()->Display(AistransformedShape_N5a_cl, Standard_True);

}

void MainWindow::handleSquareCoordinates(const SquareCoordinates& coords)
{
	// 调用 makeTabu() 函数，并传递 SquareCoordinates 结构的坐标参数
	makeTabu(coords);
}

void MainWindow::makeTabu(const SquareCoordinates& coords)
{
	// 清空绘制区域
	myOccView->getContext()->EraseAll(Standard_True);  // 添加布尔参数来擦除显示对象

	gp_Pnt p1(coords.P1_x, coords.P1_y, 0.0);
	gp_Pnt p2(coords.P2_x, coords.P2_y, 0.0);
	gp_Pnt p3(coords.P3_x, coords.P3_y, 0.0);
	gp_Pnt p4(coords.P4_x, coords.P4_y, 0.0);

	BRepBuilderAPI_MakePolygon polygonMaker;
	polygonMaker.Add(p1);
	polygonMaker.Add(p2);
	polygonMaker.Add(p3);
	polygonMaker.Add(p4);
	polygonMaker.Add(p1);  // 闭合多边形

	TopoDS_Shape square = polygonMaker.Shape();
	Handle(AIS_Shape) anAisSquare = new AIS_Shape(square);
	anAisSquare->SetColor(Quantity_NOC_AZURE);

	myOccView->getContext()->Display(anAisSquare, Standard_True);

	// 在正方形的点 P1 处显示坐标标签
	Handle_AIS_TextLabel anAisLabel = new AIS_TextLabel();
	QString coordText = QString("(%1, %2)").arg(p1.X()).arg(p1.Y());
	anAisLabel->SetText(coordText.toStdString().c_str());
	//anAisLabel->SetTextPosition(p1.X(), p1.Y(), p1.Z() + 1.0);  // 将标签位置稍微抬高一些，避免与正方形重叠
	anAisLabel->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	myOccView->getContext()->Display(anAisLabel, Standard_True);
}


void MainWindow::onTreeWidgetItemClicked1(QTreeWidgetItem *item, int column)
{
	if (item && column == 0)
	{
		QString text = item->text(column);
		if (text == QString("内轮廓"))
		{
			emit par11();
		}
		if (text == QString("沟槽"))
		{
			emit par12();
		}
		if (text == QString("二衬"))
		{
			emit par13();
		}
		if (text == QString("回填与踏步"))
		{
			emit par14();
		}
		if (text == QString("倒切式帽檐"))
		{
			emit par15();
		}
		if (text == QString("中心沟"))
		{
			emit par12_1();
		}
		if (text == QString("侧沟"))
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
		if (text == QString("内轮廓"))
		{
			emit par1();
		}
		if (text == QString("沟槽"))
		{
			emit par2();
		}
		if (text == QString("二衬"))
		{
			emit par3();
		}
		if (text == QString("回填与踏步"))
		{
			emit par4();
		}
		if (text == QString("初支"))
		{
			emit par5();
		}
		if (text == QString("防排水"))
		{
			emit par6();
		}
		if (text == QString("中心沟"))
		{
			emit par2_1();
		}
		if (text == QString("侧沟"))
		{
			emit par2_2();
		}
		if (text == QString("初支喷混"))
		{
			emit par4_1();
		}
		if (text == QString("型钢钢架"))
		{
			emit par4_2();
		}
	}*/
	if (item && column == 0)
	{
		QString text = item->text(column);
		if (text == QString("内轮廓及二衬"))
		{
			emit par1();
		}
		if (text == QString("初支"))
		{
			emit par2();
		}
		if (text == QString("回填踏步及沟槽"))
		{
			emit par3();
		}
		if (text == QString("防排水"))
		{
			emit par4();
		}
		if (text == QString("初支"))
		{
			emit par5();
		}
		if (text == QString("防排水"))
		{
			emit par6();
		}
		if (text == QString("中心沟"))
		{
			emit par3_1();
		}
		if (text == QString("侧沟"))
		{
			emit par3_2();
		}
		if (text == QString("初支喷混"))
		{
			emit par2_1();
		}
		if (text == QString("型钢钢架"))
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
	// 清空绘制区域
	//myOccView->getContext()->EraseAll(Standard_True);

	double firstSurppWall_Thick = coords.P1_x;
	double invertedArch_Thick = coords.P2_x;
	double line1AndCent_Distance = coords.P3_x;
	double line1AndLine2_Distance = coords.P4_x;
	double cirConnn_Thick = coords.P5_x;
	double arch_Angle = coords.P6_x;//不超过180度
	double archAnch_Distance = coords.P7_x;
	double wallAnch_Distance = coords.P8_x;



	/*****二衬*****/
	// 创建圆 O1  拱部内侧，665半径 
	gp_Pnt P_CO1_NLK(0.0, 0.0, 0.0); // 原点为圆心
	gp_Ax2 axis1(P_CO1_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	double R1_NLK = secondaryLiningObj.getValue(22); // 定义圆的半径
	gp_Circ CO1_NLK(axis1, R1_NLK);
	Handle(Geom_Circle) geomCircle1_NLK = new Geom_Circle(CO1_NLK);
	TopoDS_Edge edge1_NLK = BRepBuilderAPI_MakeEdge(geomCircle1_NLK);

	// 创建原点的中垂线
	BRepBuilderAPI_MakeEdge edge(gp_Pnt(0, -1000, 0), gp_Pnt(0, 1000, 0));
	TopoDS_Shape shape3 = edge.Shape();
	// 计算圆心到点 P 的距离 盖板距离线段
	double radius = R1_NLK;
	double radius3 = secondaryLiningObj.getValue(23); // 圆O3的半径
	Standard_Real JibenKuandu = secondaryLiningObj.getValue(29);
	Standard_Real GoucaoKuandu = secondaryLiningObj.getValue(27);
	double height = sqrt(pow(radius, 2) - pow((GoucaoKuandu + JibenKuandu / 2), 2));
	double distanceCenterToP = sqrt(pow(radius, 2) + pow(630, 2)) - radius;
	gp_Pnt pointP(0, -height, 0);

	//// 计算圆心到点 P 的距离 盖板距离线段
	//Standard_Real R1_NLK = 665.0;
	//Standard_Real R3_NLK = 1720; // 圆O3的半径
	//Standard_Real height = sqrt(pow(R1_NLK, 2) - pow(630, 2));
	//Standard_Real distanceCenterToP = sqrt(pow(R1_NLK, 2) + pow(630, 2)) - R1_NLK;
	//gp_Pnt pointP(0, -height, 0);

	// 确定新的圆心 P3  仰拱圆心
	gp_Pnt pointP3(0, radius3 - secondaryLiningObj.getValue(26) - secondaryLiningObj.getValue(28) - height, 0);//180和30会改变！！！


	double alpha = acos(-pointP.Y() / radius);
	////计算角度 alpha  确定过渡段圆半径用参数
	//Standard_Real alpha = acos(-pointP.Y() / R1_NLK);
	// 创建圆心到点 P 的线段
	BRepBuilderAPI_MakeEdge edgeP(gp_Pnt(0, 0, 0), pointP);
	TopoDS_Shape shapeP = edgeP.Shape();

	// 创建圆 O3  仰拱内侧圆
	gp_Ax2 axis03(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
												   //											   // 创建圆 O3  仰拱内侧圆
												   //gp_Ax2 axis03(P_CO3_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	double radius03 = secondaryLiningObj.getValue(23); // 半径为 1720cm
	gp_Circ circle03(axis03, radius03);
	Handle(Geom_Circle) geomCircle03 = new Geom_Circle(circle03);
	TopoDS_Edge edge03 = BRepBuilderAPI_MakeEdge(geomCircle03);
	//Standard_Real R3_NLK = 1720.0; // 半径为 1720cm
	//gp_Circ circle03(axis03, R3_NLK);
	//Handle(Geom_Circle) geomCO3_NLK = new Geom_Circle(CO3_NLK);
	//TopoDS_Edge edgeO3_NLK = BRepBuilderAPI_MakeEdge(geomCO3_NLK);

	//计算radius4  内侧过渡段圆半径
	double m = pow(radius3, 2) - pow(radius, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*height;
	double n = radius3 - radius - pointP3.Y() *height / radius;
	double radius4 = m / (2 * n);
	// 创建圆 O4  过渡段内侧圆  左侧
	gp_Pnt centerO4(-sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle4(axis4, radius4);
	Handle(Geom_Circle) geomCircle4 = new Geom_Circle(circle4);
	TopoDS_Edge edge4 = BRepBuilderAPI_MakeEdge(geomCircle4);

	////计算radius4  内侧过渡段圆半径
	//Standard_Real m = pow(R3_NLK, 2) - pow(R1_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*height;
	//Standard_Real n = R3_NLK - R1_NLK - P_CO3_NLK.Y() *height / R1_NLK;
	//Standard_Real R4_NLK = m / (2 * n);
	//// 创建圆 O4  过渡段内侧圆  左侧
	//gp_Pnt centerO4(-sin(alpha) * (R1_NLK - R4_NLK), -cos(alpha) * (R1_NLK - R4_NLK), 0);
	//gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//gp_Circ CO4_NLK(axis4, R4_NLK);
	//Handle(Geom_Circle) geomCO4_NLK = new Geom_Circle(CO4_NLK);
	//TopoDS_Edge edgeO4_NLK= BRepBuilderAPI_MakeEdge(geomCO4_NLK);

	// 创建圆 O7  过渡段内侧圆  右侧
	gp_Pnt centerO7(sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis7(centerO7, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle7(axis7, radius4);
	Handle(Geom_Circle) geomCircle7 = new Geom_Circle(circle7);
	TopoDS_Edge edge7 = BRepBuilderAPI_MakeEdge(geomCircle7);


	///绘制拱墙内侧弧线，已知弧段圆心、起点、半径
	double R_O1 = R1_NLK;//半径
	gp_Circ Circle_O1_EC(axis1, R_O1);
	gp_Ax3 AxO1(axis1);
	gp_Cylinder Cylinder_O1(AxO1, R_O1);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O1 = new Geom_CylindricalSurface(Cylinder_O1);
	GeomAPI_IntCS ICC_O4_01(geomCircle4, geoCylinder_O1);//求圆04与圆柱面cylinder01交点
	gp_Pnt CUT_O4_01 = ICC_O4_01.Point(1);

	GeomAPI_IntCS ICC_O7_01(geomCircle7, geoCylinder_O1);//求圆07与圆柱面cylinder01交点
	gp_Pnt CUT_O7_01 = ICC_O7_01.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O1_EC, CUT_O7_01, CUT_O4_01, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	Handle(AIS_Shape) aTarcCurve_01 = new AIS_Shape(TarcCurve_01);
	aTarcCurve_01->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_01, Standard_True);*/



	///绘制仰拱内侧弧线，已知弧段圆心、起点、半径
	double R_O3 = radius3;//半径
						  /////绘制仰拱内侧弧线，已知弧段圆心、起点、半径
						  //Standard_Real R_O3 = R3_NLK;//半径
	gp_Circ Circle_O3_EC(axis03, R_O3);
	gp_Ax3 AxO3(axis03);
	gp_Cylinder Cylinder_O3(AxO3, R_O3);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O3 = new Geom_CylindricalSurface(Cylinder_O3);
	GeomAPI_IntCS ICC_O4_03(geomCircle4, geoCylinder_O3);//求圆04与圆柱面cylinder01交点
	gp_Pnt CUT_O4_03 = ICC_O4_03.Point(1);

	GeomAPI_IntCS ICC_O7_03(geomCircle7, geoCylinder_O3);//求圆07与圆柱面cylinder01交点
	gp_Pnt CUT_O7_03 = ICC_O7_03.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_03 = GC_MakeArcOfCircle(Circle_O3_EC, CUT_O4_03, CUT_O7_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_03 = BRepBuilderAPI_MakeEdge(arcCurve_03);
	Handle(AIS_Shape) aTarcCurve_03 = new AIS_Shape(TarcCurve_03);
	aTarcCurve_03->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_03, Standard_True);*/

	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	double R_O4 = radius4;//半径
						  /////绘制过渡段左侧弧线，已知弧段圆心、起点、半径
						  //Standard_Real R_O4 = R4_NLK;//半径
	gp_Circ Circle_O4_EC(axis4, R_O4);
	gp_Ax3 AxO4(axis4);
	gp_Cylinder Cylinder_O4(AxO4, R_O4);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_04 = GC_MakeArcOfCircle(Circle_O4_EC, CUT_O4_01, CUT_O4_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_04 = BRepBuilderAPI_MakeEdge(arcCurve_04);
	Handle(AIS_Shape) aTarcCurve_04 = new AIS_Shape(TarcCurve_04);
	aTarcCurve_04->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_04, Standard_True);*/

	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	double R_O7 = radius4;//半径
						  // ///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
						  //Standard_Real R_O7 = R4_NLK;//半径
	gp_Circ Circle_O7_EC(axis7, R_O7);
	gp_Ax3 AxO7(axis7);
	gp_Cylinder Cylinder_O7(AxO7, R_O7);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_07 = GC_MakeArcOfCircle(Circle_O7_EC, CUT_O7_03, CUT_O7_01, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_07 = BRepBuilderAPI_MakeEdge(arcCurve_07);
	Handle(AIS_Shape) aTarcCurve_07 = new AIS_Shape(TarcCurve_07);
	aTarcCurve_07->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_07, Standard_True);*/



	// 创建圆 O2  拱部外侧，665+55半径
	gp_Pnt P_CO2_NLK(0.0, 0.0, 0.0); // 原点为圆心
	gp_Ax2 axis2(P_CO2_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	double R2_NLK = R1_NLK + secondaryLiningObj.getValue(24); // 定义圆的半径
	gp_Circ CO2_NLK(axis2, R2_NLK);
	Handle(Geom_Circle) geomCircle2 = new Geom_Circle(CO2_NLK);
	TopoDS_Edge edge2 = BRepBuilderAPI_MakeEdge(geomCircle2);

	// 创建圆 O5 仰拱外侧圆
	gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	double radius5 = radius3 + secondaryLiningObj.getValue(25); // 半径为 1720cm+55cm
	gp_Circ circle5(axis5, radius5);
	Handle(Geom_Circle) geomCircle5 = new Geom_Circle(circle5);
	TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomCircle5);
	//// 创建圆 O5 仰拱外侧圆
	//gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//Standard_Real R5_NLK = R3_NLK + 65.0; // 半径为 1720cm+55cm
	//gp_Circ circle5(axis5, R5_NLK);
	//Handle(Geom_Circle) geomC05_NLK = new Geom_Circle(C05_NLK);
	//TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomC05_NLK);

	//计算radius6 外侧过渡段圆半径
	//Standard_Real radius6 = solveForR4(alpha, radius, radius3, -pointP.Y());
	double s = pow(radius5, 2) - pow(R2_NLK, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*(height + secondaryLiningObj.getValue(24) * cos(alpha));
	double p = radius5 - R2_NLK - pointP3.Y() *(height + secondaryLiningObj.getValue(24) * cos(alpha)) / R2_NLK;
	double radius6 = s / (2 * p);
	////计算radius6 外侧过渡段圆半径
	////Standard_Real R6_NLK = solveForR4(alpha, R1_NLK, R3_NLK, -P_CO1_NLK());
	//Standard_Real s = pow(R5_NLK, 2) - pow(R2_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*(height+R2_NLK*alpha);
	//Standard_Real p = R5_NLK - R2_NLK - P_CO3_NLK.Y() *height / R2_NLK;
	//Standard_Real R6_NLK = s / (2 * p);


	// 创建圆 O6  过渡段外侧圆  左侧
	gp_Pnt centerO6(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle6(axis6, radius6);
	Handle(Geom_Circle) geomCircle6 = new Geom_Circle(circle6);
	TopoDS_Edge edge6 = BRepBuilderAPI_MakeEdge(geomCircle6);
	//// 创建圆 O6  过渡段外侧圆  左侧
	//gp_Pnt centerO6(-sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//gp_Circ circle6(axis6, R6_NLK);
	//Handle(Geom_Circle) geomC06_NLK = new Geom_Circle(C06_NLK);
	//TopoDS_Edge edge6_NLK = BRepBuilderAPI_MakeEdge(geomC06_NLK);

	// 创建圆 O8  过渡段外侧圆  右侧
	gp_Pnt centerO8(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle8(axis8, radius6);
	Handle(Geom_Circle) geomCircle8 = new Geom_Circle(circle8);
	TopoDS_Edge edge8 = BRepBuilderAPI_MakeEdge(geomCircle8);
	//// 创建圆 O8  过渡段外侧圆  右侧
	//gp_Pnt centerO8(sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//gp_Circ circle8(axis8, R6_NLK);
	//Handle(Geom_Circle) geomC08_NLK = new Geom_Circle(C08_NLK);
	//TopoDS_Edge edge8_NLK = BRepBuilderAPI_MakeEdge(geomC08_NLK);

	///绘制拱墙外侧弧线
	double R_O2 = R2_NLK;//半径
	gp_Circ Circle_O2_EC(axis2, R_O2);
	gp_Ax3 AxO2(axis2);
	gp_Cylinder Cylinder_O2(AxO2, R_O2);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O2 = new Geom_CylindricalSurface(Cylinder_O2);

	// 定义直线的起点和终点
	gp_Pnt startPoint6_2(0, 0, 0);
	gp_Pnt endPoint6_2(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction6_2(startPoint6_2, endPoint6_2);
	gp_Lin line6_2(startPoint6_2, direction6_2);
	// 创建直线的线段
	TopoDS_Edge lineEdge6_2 = BRepBuilderAPI_MakeEdge(line6_2, startPoint6_2, endPoint6_2);
	Handle(Geom_Line) Geom_lineEdge6_2 = new Geom_Line(line6_2);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O6_02(Geom_lineEdge6_2, geoCylinder_O2);//06 02交点
	gp_Pnt CUT_O6_02_R1 = ICC_O6_02.Point(1);
	gp_Pnt CUT_O6_02_R2 = ICC_O6_02.Point(2);
	gp_Pnt CUT_O6_02;
	CUT_O6_02.SetX(CUT_O6_02_R1.X());
	CUT_O6_02.SetY(CUT_O6_02_R1.Y());
	if (CUT_O6_02_R1.X() > CUT_O6_02_R2.X()) {
		CUT_O6_02.SetX(CUT_O6_02_R2.X());
		CUT_O6_02.SetY(CUT_O6_02_R2.Y());
	}//求得过渡圆弧的起点

	 // 定义直线的起点和终点
	gp_Pnt startPoint8_2(0, 0, 0);
	gp_Pnt endPoint8_2(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction8_2(startPoint8_2, endPoint8_2);
	gp_Lin line8_2(startPoint8_2, direction8_2);
	// 创建直线的线段
	TopoDS_Edge lineEdge8_2 = BRepBuilderAPI_MakeEdge(line8_2, startPoint8_2, endPoint8_2);
	Handle(Geom_Line) Geom_lineEdge8_2 = new Geom_Line(line8_2);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O8_02(Geom_lineEdge8_2, geoCylinder_O2);//08 02交点
	gp_Pnt CUT_O8_02_R1 = ICC_O8_02.Point(1);
	gp_Pnt CUT_O8_02_R2 = ICC_O8_02.Point(2);
	gp_Pnt CUT_O8_02;
	CUT_O8_02.SetX(CUT_O8_02_R1.X());
	CUT_O8_02.SetY(CUT_O8_02_R1.Y());
	if (CUT_O8_02_R1.X() < CUT_O8_02_R2.X()) {
		CUT_O8_02.SetX(CUT_O8_02_R2.X());
		CUT_O8_02.SetY(CUT_O8_02_R2.Y());
	}//求得过渡圆弧的起点

	Handle(Geom_TrimmedCurve) arcCurve_02 = GC_MakeArcOfCircle(Circle_O2_EC, CUT_O8_02, CUT_O6_02, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_02 = BRepBuilderAPI_MakeEdge(arcCurve_02);
	Handle(AIS_Shape) aTarcCurve_02 = new AIS_Shape(TarcCurve_02);
	aTarcCurve_02->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_02, Standard_True);*/





	///绘制仰拱外侧弧线
	double R_O5 = radius5;//半径
	gp_Circ Circle_O5_EC(axis5, R_O5);
	gp_Ax3 AxO5(axis5);
	gp_Cylinder Cylinder_O5(AxO5, R_O5);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O5 = new Geom_CylindricalSurface(Cylinder_O5);

	// 定义直线的起点和终点
	gp_Pnt startPoint6_5(0, secondaryLiningObj.getValue(23) - secondaryLiningObj.getValue(26) - secondaryLiningObj.getValue(28) - height, 0);
	gp_Pnt endPoint6_5(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction6_5(startPoint6_5, endPoint6_5);
	gp_Lin line6_5(startPoint6_5, direction6_5);
	// 创建直线的线段
	TopoDS_Edge lineEdge6_5 = BRepBuilderAPI_MakeEdge(line6_5, startPoint6_5, endPoint6_5);
	Handle(Geom_Line) Geom_lineEdge6_5 = new Geom_Line(line6_5);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O6_05(Geom_lineEdge6_5, geoCylinder_O5);//06 02交点
	gp_Pnt CUT_O6_05_R1 = ICC_O6_05.Point(1);
	gp_Pnt CUT_O6_05_R2 = ICC_O6_05.Point(2);
	gp_Pnt CUT_O6_05;
	CUT_O6_05.SetX(CUT_O6_05_R1.X());
	CUT_O6_05.SetY(CUT_O6_05_R1.Y());
	if (CUT_O6_05_R1.X() > CUT_O6_05_R2.X()) {
		CUT_O6_05.SetX(CUT_O6_05_R2.X());
		CUT_O6_05.SetY(CUT_O6_05_R2.Y());
	}//求得过渡圆弧的起点

	 // 定义直线的起点和终点
	gp_Pnt startPoint8_5(0, secondaryLiningObj.getValue(23) - secondaryLiningObj.getValue(26) - secondaryLiningObj.getValue(28) - height, 0);
	gp_Pnt endPoint8_5(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction8_5(startPoint8_5, endPoint8_5);
	gp_Lin line8_5(startPoint8_5, direction8_5);
	// 创建直线的线段
	TopoDS_Edge lineEdge8_5 = BRepBuilderAPI_MakeEdge(line8_5, startPoint8_5, endPoint8_5);
	Handle(Geom_Line) Geom_lineEdge8_5 = new Geom_Line(line8_5);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O8_05(Geom_lineEdge8_5, geoCylinder_O5);//08 02交点
	gp_Pnt CUT_O8_05_R1 = ICC_O8_05.Point(1);
	gp_Pnt CUT_O8_05_R2 = ICC_O8_05.Point(2);
	gp_Pnt CUT_O8_05;
	CUT_O8_05.SetX(CUT_O8_05_R1.X());
	CUT_O8_05.SetY(CUT_O8_05_R1.Y());
	if (CUT_O8_05_R1.X() < CUT_O8_05_R2.X()) {
		CUT_O8_05.SetX(CUT_O8_05_R2.X());
		CUT_O8_05.SetY(CUT_O8_05_R2.Y());
	}//求得过渡圆弧的起点


	Handle(Geom_TrimmedCurve) arcCurve_05 = GC_MakeArcOfCircle(Circle_O5_EC, CUT_O6_05, CUT_O8_05, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_05 = BRepBuilderAPI_MakeEdge(arcCurve_05);
	Handle(AIS_Shape) aTarcCurve_05 = new AIS_Shape(TarcCurve_05);
	aTarcCurve_05->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_05, Standard_True);*/







	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	double R_O6 = radius6;//半径
	gp_Circ Circle_O6_EC(axis6, R_O6);
	gp_Ax3 AxO6(axis6);
	gp_Cylinder Cylinder_O6(AxO6, R_O6);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_06 = GC_MakeArcOfCircle(Circle_O6_EC, CUT_O6_02, CUT_O6_05, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_06 = BRepBuilderAPI_MakeEdge(arcCurve_06);
	Handle(AIS_Shape) aTarcCurve_06 = new AIS_Shape(TarcCurve_06);
	aTarcCurve_06->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_06, Standard_True);*/




	///绘制过渡段右侧弧线，已知弧段圆心、起点、半径
	double R_O8 = radius6;//半径
	gp_Circ Circle_O8_EC(axis8, R_O8);
	gp_Ax3 AxO8(axis8);
	gp_Cylinder Cylinder_O8(AxO8, R_O8);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_08 = GC_MakeArcOfCircle(Circle_O8_EC, CUT_O8_05, CUT_O8_02, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_08 = BRepBuilderAPI_MakeEdge(arcCurve_08);
	Handle(AIS_Shape) aTarcCurve_08 = new AIS_Shape(TarcCurve_08);
	aTarcCurve_08->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTarcCurve_08, Standard_True);*/


	// 使用 BRepBuilderAPI_MakeWire 创建闭合曲线
	BRepBuilderAPI_MakeWire EC_WAIwireBuilder;
	EC_WAIwireBuilder.Add(TarcCurve_02);
	EC_WAIwireBuilder.Add(TarcCurve_06);
	EC_WAIwireBuilder.Add(TarcCurve_05);
	EC_WAIwireBuilder.Add(TarcCurve_08);
	EC_WAIwireBuilder.Build();

	if (EC_WAIwireBuilder.IsDone()) {
		TopoDS_Wire EC_WAIclosedWire = EC_WAIwireBuilder.Wire();

		// 现在 closedWire 就是你连接成闭合的连续线
	}
	else {
		// 处理创建失败的情况
	}

	//TopoDS_Wire sectorWirearc = makeWirearc.Wire();
	BRepBuilderAPI_MakeFace EC_WAIFacearc(EC_WAIwireBuilder);
	//TopoDS_Face EC_WAIFacearc = EC_WAIFacearc.Face();
	gp_Vec extrusionVecR1(0, 0, -1000.0); // 沿着 Z 轴方向拉伸 1000 个单位

	BRepPrimAPI_MakePrism EC_WAI_makearc1(EC_WAIFacearc, extrusionVecR1);
	TopoDS_Shape EC_WAI_arcShape1 = EC_WAI_makearc1.Shape();
	TopoDS_Solid EC_WAI_arcbody = TopoDS::Solid(EC_WAI_arcShape1);
	Handle(AIS_Shape) EC_WAI_Aisarcbody = new AIS_Shape(EC_WAI_arcbody);

	//EC_WAI_Aisarcbody->SetColor(Quantity_NOC_RED); // 设置颜色为红色
	//myOccView->getContext()->Display(EC_WAI_Aisarcbody, Standard_True); // 在场景中显示可视化对象

	// 使用 BRepBuilderAPI_MakeWire 创建闭合曲线
	BRepBuilderAPI_MakeWire EC_NEIwireBuilder;
	EC_NEIwireBuilder.Add(TarcCurve_01);
	EC_NEIwireBuilder.Add(TarcCurve_04);
	EC_NEIwireBuilder.Add(TarcCurve_07);
	EC_NEIwireBuilder.Add(TarcCurve_03);
	EC_NEIwireBuilder.Build();

	if (EC_NEIwireBuilder.IsDone()) {
		TopoDS_Wire EC_NEIclosedWire = EC_NEIwireBuilder.Wire();

		// 现在 closedWire 就是你连接成闭合的连续线
	}
	else {
		// 处理创建失败的情况
	}

	BRepBuilderAPI_MakeFace EC_NEIFacearc(EC_NEIwireBuilder);

	BRepPrimAPI_MakePrism EC_NEI_makearc1(EC_NEIFacearc, extrusionVecR1);
	TopoDS_Shape EC_NEI_arcShape1 = EC_NEI_makearc1.Shape();
	TopoDS_Solid EC_NEI_arcbody = TopoDS::Solid(EC_NEI_arcShape1);
	Handle(AIS_Shape) EC_NEI_Aisarcbody = new AIS_Shape(EC_NEI_arcbody);

	BRepAlgoAPI_Cut cutOp1(EC_WAI_arcShape1, EC_NEI_arcShape1);
	TopoDS_Shape EC_arcShape = cutOp1.Shape();

	Handle(AIS_Shape) EC_arcShape1 = new AIS_Shape(EC_arcShape);
	EC_arcShape1->SetColor(Quantity_NOC_YELLOW); // 设置颜色为红色
												 /* myOccView->getContext()->Display(EC_arcShape1, Standard_True); */// 在场景中显示可视化对象


																													 /******初衬******/
																													 // 二衬拱墙外轮廓圆or初衬拱墙内轮廓圆
	gp_Pnt center(0, 0, 0); // 内轮廓圆心位置
	double secondSurppWallOut_Rad = R2_NLK; //二衬拱墙外轮廓半径
	gp_Ax2 axis0(center, gp_Dir(0, 0, 1)); // 圆的轴
	gp_Circ secondSurppWallIn_Circ(axis0, secondSurppWallOut_Rad); // 绘制初支外轮廓圆
																   /*显示*/
																   /*TopoDS_Edge TC2_GQ = BRepBuilderAPI_MakeEdge(secondSurppWallIn_Circ);
																   Handle(AIS_Shape) ATC2_GQ = new AIS_Shape(TC2_GQ);
																   ATC2_GQ->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
																   myOccView->getContext()->Display(ATC2_GQ, Standard_True);*/


																   //初衬拱墙外轮廓圆
	double firstSurpportWallOuter_Rad = secondSurppWallOut_Rad + firstSurppWall_Thick;//初支外轮廓半径
	gp_Ax2 axis(center, gp_Dir(0, 0, 1)); // 圆的轴
	gp_Circ firSurppOutCircle(axis, firstSurpportWallOuter_Rad); // 绘制初支外轮廓圆
																 //显示
																 /*TopoDS_Edge TC1_GQ = BRepBuilderAPI_MakeEdge(firSurppOutCircle);
																 Handle(AIS_Shape) anAisEdgeP12 = new AIS_Shape(TC1_GQ);
																 anAisEdgeP12->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
																 myOccView->getContext()->Display(anAisEdgeP12, Standard_True);*/

																 //绘制截线1
																 // 定义绘制参数
	double line1_Length = 16000.0; // 直线长度,大于初衬拱墙外轮廓直径，确保有交点
	static const gp_Vec vector(1.0, 0.0, 0.0); // 平行于X轴的向量
	gp_Pnt StartPofLine1(-line1_Length / 2, 0 - line1AndCent_Distance, 0.0); // 起始点
	gp_Dir dLine1(line1_Length, 0, 0);
	gp_Lin line1(StartPofLine1, dLine1);
	//画线
	/*gp_Lin2d line1(gp_Pnt2d startPoint, gp_Pnt2d endPoint);*/
	/*Handle(Geom2d_TrimmedCurve) geomline1 = GCE2d_MakeSegment(startPoint, endPoint);*/
	/*TopoDS_Edge TLine1 = BRepBuilderAPI_MakeEdge(line1);
	Handle(AIS_Shape) aTLine1 = new AIS_Shape(TLine1);
	aTLine1->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	myOccView->getContext()->Display(aTLine1, Standard_True);*/


	//绘制截线2
	// 定义绘制参数
	double line2_Length = 16000.0; // 直线长度,大于初衬仰拱外轮廓直径，确保有交点
	static const gp_Vec vector2(1.0, 0.0, 0.0); // 平行于X轴的向量
												//double line1AndLine2_Distance = 200;//截线1与截线2距离
	gp_Pnt startPofLine2(-line2_Length / 2, 0 - line1AndCent_Distance - line1AndLine2_Distance, 0); // 起始点
	gp_Dir dLine2(line2_Length, 0, 0);
	//画线
	gp_Lin line2(startPofLine2, dLine2);
	Handle(Geom_Line) geomLine2 = new Geom_Line(line2);
	/*Handle(Geom2d_TrimmedCurve) geomline2 = GCE2d_MakeSegment(startPoint2, endPoint2);*/
	/*TopoDS_Edge line = BRepBuilderAPI_MakeEdge(startPoint2, endPoint2);*/
	/*TopoDS_Edge TLine2 = BRepBuilderAPI_MakeEdge(line2);
	Handle(AIS_Shape) aTLine2 = new AIS_Shape(TLine2);
	aTLine2->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	myOccView->getContext()->Display(aTLine2, Standard_True);*/

	//求截线1与初衬内轮廓交点
	// 求交
	Handle(Geom_Line) geomLine1 = new Geom_Line(line1);
	gp_Ax3 aCylindSecSurppOut(axis0);
	gp_Cylinder cylindSecSurppOut(aCylindSecSurppOut, secondSurppWallOut_Rad);
	Handle(Geom_CylindricalSurface) geomCylindSecSurppOut = new Geom_CylindricalSurface(cylindSecSurppOut);//创建二衬外轮廓所在圆柱面
	GeomAPI_IntCS ICS_Line1AndCylindSecSurppOut(geomLine1, geomCylindSecSurppOut);//截线1与二衬外轮廓（初衬内轮廓）求交
	gp_Pnt Inter1_Line1AndCylindSecSurppOut = ICS_Line1AndCylindSecSurppOut.Point(1);//获取交点1
	gp_Pnt Inter2_Line1AndCylindSecSurppOut = ICS_Line1AndCylindSecSurppOut.Point(2);//获取交点2
	gp_Pnt Inter_Line1AndCylindSecSurppOut;
	Inter_Line1AndCylindSecSurppOut.SetX(Inter1_Line1AndCylindSecSurppOut.X());
	Inter_Line1AndCylindSecSurppOut.SetY(Inter1_Line1AndCylindSecSurppOut.Y());
	if (Inter1_Line1AndCylindSecSurppOut.X() < Inter2_Line1AndCylindSecSurppOut.X()) {
		Inter_Line1AndCylindSecSurppOut.SetX(Inter2_Line1AndCylindSecSurppOut.X());
		Inter_Line1AndCylindSecSurppOut.SetY(Inter2_Line1AndCylindSecSurppOut.Y());
	}//获取交点中，x坐标为正的点

	 //初支外轮廓拱墙端部右侧切线起点与端点
	 //起点
	gp_Dir Dir_LineTan1(Inter_Line1AndCylindSecSurppOut.XYZ());
	gp_Lin lineTan1(center, Dir_LineTan1);//圆心与外轮廓拱脚连线
										  /*TopoDS_Edge TLineTan1 = BRepBuilderAPI_MakeEdge(LineTan1);
										  Handle(AIS_Shape) ATLineTan1 = new AIS_Shape(TLineTan1);
										  ATLineTan1->SetColor(Quantity_Color(Quantity_NOC_RED));
										  myOccView->getContext()->Display(ATLineTan1, Standard_True);*/
	Handle(Geom_Line) geomLineTan1 = new Geom_Line(lineTan1);//绘制圆心与外轮廓拱脚连线
															 //lineTan1显示
															 /*TopoDS_Edge TlineTan1 = BRepBuilderAPI_MakeEdge(lineTan1);
															 Handle(AIS_Shape) aTlineTan1 = new AIS_Shape(TlineTan1);
															 aTlineTan1->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
															 myOccView->getContext()->Display(aTlineTan1, Standard_True);*/
	gp_Ax3 aCylindFirSurppOut(axis);
	gp_Cylinder cylindFirSurppOut(aCylindFirSurppOut, firstSurpportWallOuter_Rad);//初支外轮廓所在圆柱面
	Handle(Geom_CylindricalSurface) geomCylindFirSurppOut = new Geom_CylindricalSurface(cylindFirSurppOut);
	GeomAPI_IntCS ICS_Line1AndCylindFirSurppOut(geomLineTan1, geomCylindFirSurppOut);//求线LineTan1与圆柱面cylinder2交点
	gp_Pnt Inter1_Line1AndCylindFirSurppOut = ICS_Line1AndCylindFirSurppOut.Point(1);
	gp_Pnt Inter2_Line1AndCylindFirSurppOut = ICS_Line1AndCylindFirSurppOut.Point(2);
	gp_Pnt Inter_Line1AndCylindFirSurppOut;
	Inter_Line1AndCylindFirSurppOut.SetX(Inter1_Line1AndCylindFirSurppOut.X());
	Inter_Line1AndCylindFirSurppOut.SetY(Inter1_Line1AndCylindFirSurppOut.Y());
	if (Inter1_Line1AndCylindFirSurppOut.X() < Inter2_Line1AndCylindFirSurppOut.X()) {
		Inter_Line1AndCylindFirSurppOut.SetX(Inter2_Line1AndCylindFirSurppOut.X());
		Inter_Line1AndCylindFirSurppOut.SetY(Inter2_Line1AndCylindFirSurppOut.Y());
	}//求得起点
	 //绘制右侧切线段
	gp_Pnt endPofTtanLineR(Inter_Line1AndCylindFirSurppOut.X() + (Inter_Line1AndCylindFirSurppOut.Y()*(line1AndCent_Distance + line1AndLine2_Distance + Inter_Line1AndCylindFirSurppOut.Y()) / Inter_Line1AndCylindFirSurppOut.X()), 0 - line1AndCent_Distance - line1AndLine2_Distance, 0);//切线与截线2交点
	TopoDS_Edge TtanLineR = BRepBuilderAPI_MakeEdge(Inter_Line1AndCylindFirSurppOut, endPofTtanLineR);//绘制右侧切线段
	Handle(AIS_Shape) aTtanLineR = new AIS_Shape(TtanLineR);
	aTtanLineR->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTtanLineR, Standard_True);*/
	//绘制左侧切线段
	gp_Pnt endPofTtanLineL(-endPofTtanLineR.X(), endPofTtanLineR.Y(), 0);
	gp_Pnt Inter_TtanLineLAndCylindFirSurppOutL(-Inter_Line1AndCylindFirSurppOut.X(), Inter_Line1AndCylindFirSurppOut.Y(), 0);
	TopoDS_Edge TtanLineL = BRepBuilderAPI_MakeEdge(Inter_TtanLineLAndCylindFirSurppOutL, endPofTtanLineL);
	Handle(AIS_Shape) aTtanLineL = new AIS_Shape(TtanLineL);
	aTtanLineL->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTtanLineL, Standard_True);*/

	//绘制初衬仰拱外轮廓
	//求得仰拱外轮廓弧段起点与终点
	gp_Pnt invertedArch_Center(pointP3.X(), pointP3.Y(), pointP3.Z());//仰拱圆心
	gp_Dir dCut(invertedArch_Center.XYZ() - CUT_O6_05.XYZ());
	gp_Lin lCut(invertedArch_Center, dCut);//仰拱圆心与仰拱弧段左边端点所在直线
	Handle(Geom_Line) geomLCut = new Geom_Line(lCut);
	//double invertedArch_Thick = 70;
	double invertedArch_Rad = R_O5 + invertedArch_Thick;//仰拱半径,70为初衬仰拱厚度
	gp_Ax2 Ax2_YG(invertedArch_Center, gp_Dir(0, 0, 1));
	//gp_Circ invertedArch_Circle(Ax2_YG, invertedArch_Rad);//仰拱所在圆
	gp_Ax3 Ax3_YG(Ax2_YG);
	gp_Cylinder cylindInvArch(Ax3_YG, invertedArch_Rad);//初支仰拱外轮廓所在圆柱面
	Handle(Geom_CylindricalSurface) geomCylindInvArch = new Geom_CylindricalSurface(cylindInvArch);
	GeomAPI_IntCS ICS_LCutAndCylindInvArch(geomLCut, geomCylindInvArch);//求线lCut与圆柱面cylindInvArch交点,即初衬仰拱外轮廓左侧端点
	gp_Pnt Inter1_LCutAndCylindInvArch = ICS_LCutAndCylindInvArch.Point(1);
	gp_Pnt Inter2_LCutAndCylindInvArch = ICS_LCutAndCylindInvArch.Point(2);
	gp_Pnt Inter_LCutAndCylindInvArch;
	Inter_LCutAndCylindInvArch.SetX(Inter1_LCutAndCylindInvArch.X());
	Inter_LCutAndCylindInvArch.SetY(Inter1_LCutAndCylindInvArch.Y());
	if (Inter1_LCutAndCylindInvArch.Y() > 0) {
		Inter_LCutAndCylindInvArch.SetX(Inter2_LCutAndCylindInvArch.X());
		Inter_LCutAndCylindInvArch.SetY(Inter2_LCutAndCylindInvArch.Y());
	}//求得初衬仰拱外轮廓左侧端点
	gp_Pnt Pnt_YG_L(Inter_LCutAndCylindInvArch.XYZ());//初衬仰拱外轮廓左侧端点
	gp_Pnt Pnt_YG_R(-Pnt_YG_L.X(), Pnt_YG_L.Y(), Pnt_YG_L.Z());//初衬仰拱外轮廓右侧端点
	gp_Circ invertedArch_Circle(Ax2_YG, invertedArch_Rad);//仰拱所在圆
	Handle(Geom_TrimmedCurve) geomInvertedArch_Circle = GC_MakeArcOfCircle(invertedArch_Circle, Pnt_YG_L, Pnt_YG_R, false);//画初衬仰拱外轮廓圆弧
	TopoDS_Edge TInvertedArchArc = BRepBuilderAPI_MakeEdge(geomInvertedArch_Circle);
	Handle(AIS_Shape) aTInvertedArchArc = new AIS_Shape(TInvertedArchArc);
	aTInvertedArchArc->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTInvertedArchArc, Standard_True);*/

	//绘制初衬拱墙外轮廓
	Handle(Geom_TrimmedCurve) geomFirSurppOutCircle = GC_MakeArcOfCircle(firSurppOutCircle, Inter_Line1AndCylindFirSurppOut, Inter_TtanLineLAndCylindFirSurppOutL, false);//画圆弧
	TopoDS_Edge TFirSurppOutCircle = BRepBuilderAPI_MakeEdge(geomFirSurppOutCircle);
	Handle(AIS_Shape) aTFirSurppOutCircle = new AIS_Shape(TFirSurppOutCircle);
	aTFirSurppOutCircle->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTFirSurppOutCircle, Standard_True);*/

	//绘制仰拱与拱墙连接段弧线，已知弧段圆心、起点、半径
	gp_Pnt center_CirConnL(centerO6.XYZ());//圆心
										   //double cirConnn_Thick = 70;
	double cirConnn_Rad = radius6 + cirConnn_Thick;//70为连接处的厚度
	gp_Ax2 Ax2_O4_EC(center_CirConnL, gp_Dir(0, 0, 1));
	gp_Circ Circle_Connection(Ax2_O4_EC, cirConnn_Rad);
	gp_Ax3 Ax3_O4_EC(Ax2_O4_EC);
	gp_Cylinder connCylind(Ax3_O4_EC, cirConnn_Rad);//弧线所在圆柱面
	Handle(Geom_CylindricalSurface) geomConnCylind = new Geom_CylindricalSurface(connCylind);
	GeomAPI_IntCS ICS_Line2AndConnCylind(geomLine2, geomConnCylind);//求线LineTan1与圆柱面cylinder2交点
	gp_Pnt Inter1_Line2AndConnCylind = ICS_Line2AndConnCylind.Point(1);
	gp_Pnt Inter2_Line2AndConnCylind = ICS_Line2AndConnCylind.Point(2);
	gp_Pnt Inter_Line2AndConnCylind;
	Inter_Line2AndConnCylind.SetX(Inter1_Line2AndConnCylind.X());
	Inter_Line2AndConnCylind.SetY(Inter1_Line2AndConnCylind.Y());
	if (Inter1_Line2AndConnCylind.X() > Inter2_Line2AndConnCylind.X()) {
		Inter_Line2AndConnCylind.SetX(Inter2_Line2AndConnCylind.X());
		Inter_Line2AndConnCylind.SetY(Inter2_Line2AndConnCylind.Y());
	}//求得过渡圆弧的起点
	Handle(Geom_TrimmedCurve) geomCircleConnection = GC_MakeArcOfCircle(Circle_Connection, Inter_Line2AndConnCylind, Pnt_YG_L, false);//绘制左侧连接圆弧
	TopoDS_Edge TCircleConnection = BRepBuilderAPI_MakeEdge(geomCircleConnection);
	Handle(AIS_Shape) aTCircleConnection = new AIS_Shape(TCircleConnection);
	aTCircleConnection->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTCircleConnection, Standard_True);*/
	//绘制右侧连接圆弧
	gp_Pnt center_CirConnR(centerO8.XYZ());//圆心
	gp_Ax2 Ax2_O4_EC_R(center_CirConnR, gp_Dir(0, 0, 1));
	gp_Circ Circle_ConnectionR(Ax2_O4_EC_R, cirConnn_Rad);//右侧连接圆弧所在圆
	gp_Pnt endPofConnArchR(-Inter_Line2AndConnCylind.X(), Inter_Line2AndConnCylind.Y(), 0);//右侧连接弧段终点
	Handle(Geom_TrimmedCurve) geomCircle_ConnectionR = GC_MakeArcOfCircle(Circle_ConnectionR, Pnt_YG_R, endPofConnArchR, false);//绘制右侧连接圆弧
	TopoDS_Edge TCircle_ConnectionR = BRepBuilderAPI_MakeEdge(geomCircle_ConnectionR);
	Handle(AIS_Shape) aTCircle_ConnectionR = new AIS_Shape(TCircle_ConnectionR);
	aTCircle_ConnectionR->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTCircle_ConnectionR, Standard_True);*/

	//绘制连接直线段
	//绘制左侧直线段
	TopoDS_Edge Tline_L = BRepBuilderAPI_MakeEdge(endPofTtanLineL, Inter_Line2AndConnCylind);
	Handle(AIS_Shape) aTline_L = new AIS_Shape(Tline_L);
	aTline_L->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTline_L, Standard_True);*/
	//绘制右侧直线段
	TopoDS_Edge Tline_R = BRepBuilderAPI_MakeEdge(endPofTtanLineR, endPofConnArchR);
	Handle(AIS_Shape) aTline_R = new AIS_Shape(Tline_R);
	aTline_R->SetColor(Quantity_Color(Quantity_NOC_RED));
	/*myOccView->getContext()->Display(aTline_R, Standard_True);*/

	//将轮廓连接成面并拉伸成体
	std::vector<TopoDS_Edge> edges;//将各地曲线轮廓存储在edges中
	edges.push_back(TFirSurppOutCircle);//初支拱墙外轮廓
	edges.push_back(TtanLineR);//右侧切线段
	edges.push_back(Tline_R);//右侧直线段
	edges.push_back(TCircle_ConnectionR);//右侧连接圆弧
	edges.push_back(TInvertedArchArc);//初支仰拱外轮廓
	edges.push_back(TCircleConnection);//左侧连接弧段
	edges.push_back(Tline_L);//左侧直线段
	edges.push_back(TtanLineL);//左侧切线段
	BRepBuilderAPI_MakeWire wireBuilder;// 创建MakeWire对象
										// 添加每个边到MakeWire对象中
	for (const TopoDS_Edge& edge : edges)
	{
		wireBuilder.Add(edge);
	}
	// 封闭曲线生成面
	wireBuilder.Build();
	BRepBuilderAPI_MakeFace faceMaker(wireBuilder.Wire());//生成面
	TopoDS_Face face = faceMaker.Face(); // 获取生成的面
										 //将面拉伸成体
	double thickness = -1000.0; // 指定拉伸厚度
	gp_Pnt Pnt_thick(0, 0, thickness);
	gp_Vec Vec_thick(Pnt_thick.XYZ());//定义拉伸向量
	BRepPrimAPI_MakePrism prismMaker(face, Vec_thick);//使用BRepPrimAPI_MakePrism将面拉伸成体
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
	//将轮廓所需点以及半径存在coords中，并以信号形式发出去

	/******锚杆******/
	/**拱墙锚杆**/
	//double startAngle = (M_PI/2)-(arch_Angle * M_PI /180.0/2); // 起始角度
	double startAngle = M_PI / 2 + 1.0e-12; // 起始角度
	double endAngle = (M_PI / 2) + (arch_Angle * M_PI / 180.0 / 2); // 终止角度，转换成弧度
																	//double endAngle = M_PI / 2;
	double angleIncrement = archAnch_Distance / firstSurpportWallOuter_Rad; // 角度增量
																			//确定拱墙锚杆分布范围
	gp_Ax3 aCylindFirSurppOut2(axis0);
	gp_Cylinder cylindFirSurppOut2(aCylindFirSurppOut2, firstSurpportWallOuter_Rad);
	Handle(Geom_CylindricalSurface) geomCylindFirSurppOut2 = new Geom_CylindricalSurface(cylindFirSurppOut2);//创建初衬外轮廓所在圆柱面
	gp_Dir dLArcBolt(1, tan((M_PI / 2) - (arch_Angle * M_PI / 180.0 / 2)), 0);
	gp_Lin LArcBolt(center, dLArcBolt);
	Handle(Geom_Line) geomLArcBolt = new Geom_Line(LArcBolt);//弧段右侧端点与圆心所在直线LArcBolt
															 /*TopoDS_Edge TgeomLArcBolt = BRepBuilderAPI_MakeEdge(geomLArcBolt);
															 Handle(AIS_Shape) aTgeomLArcBolt = new AIS_Shape(TgeomLArcBolt);
															 aTgeomLArcBolt->SetColor(Quantity_Color(Quantity_NOC_RED));
															 myOccView->getContext()->Display(aTgeomLArcBolt, Standard_True);*///显示
	GeomAPI_IntCS ICS_ArcBolt(geomLArcBolt, geomCylindFirSurppOut2);//直线LArcBolt与初衬外轮廓所在圆柱面求交
	gp_Pnt Inter1_ArcBolt = ICS_ArcBolt.Point(1);//获取交点1
	gp_Pnt Inter2_ArcBolt = ICS_ArcBolt.Point(2);//获取交点2
	gp_Pnt Inter_ArcBolt;
	Inter_ArcBolt.SetX(Inter1_ArcBolt.X());
	Inter_ArcBolt.SetY(Inter1_ArcBolt.Y());
	if (Inter1_ArcBolt.Y() < Inter2_ArcBolt.Y()) {
		Inter_ArcBolt.SetX(Inter2_ArcBolt.X());
		Inter_ArcBolt.SetY(Inter2_ArcBolt.Y());
	}//获得右侧起点
	gp_Pnt Inter_ArcBoltL(-Inter_ArcBolt.X(), Inter_ArcBolt.Y(), 0);//左侧起点
	Handle(Geom_TrimmedCurve) geomCircle_ArcBolt = GC_MakeArcOfCircle(firSurppOutCircle, Inter_ArcBolt, Inter_ArcBoltL, false);//确定拱墙锚杆所在弧线
	TopoDS_Edge TgeomCircle_ArcBolt = BRepBuilderAPI_MakeEdge(geomCircle_ArcBolt);
	Handle(AIS_Shape) aTgeomCircle_ArcBolt = new AIS_Shape(TgeomCircle_ArcBolt);
	aTgeomCircle_ArcBolt->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTgeomCircle_ArcBolt, Standard_True);


	//均匀分布拱墙锚杆
	Standard_Integer numPoints = static_cast<Standard_Integer>((endAngle - startAngle) / angleIncrement) + 1;// 计算需要创建的点的数量
	TColgp_Array1OfPnt archAnchPoints(1, numPoints);// 创建数组以存储点
	Standard_Real currentAngle = startAngle;// 初始化参数
											// 在弧段 a 上均匀分布点并存储它们
											//std::vector<TopoDS_Edge> edges_Bolt;//存储锚杆
	TopoDS_Compound compound;// 创建一个数据结构来储存线段
	BRep_Builder builder;
	builder.MakeCompound(compound);
	for (Standard_Integer i = 1; i <= numPoints; ++i) {
		// 使用参数来计算点的位置
		gp_Dir dLArcBolti(1, tan(currentAngle), 0);
		gp_Lin LArcBolti(center, dLArcBolti);
		Handle(Geom_Line) geomLArcBolti = new Geom_Line(LArcBolti);//弧段锚杆起点与圆心所在直线LArcBolti

		GeomAPI_IntCS ICS_ArcBolti(geomLArcBolti, geomCylindFirSurppOut2);//直线LArcBolt与初衬外轮廓所在圆柱面求交
		gp_Pnt Inter1_ArcBolti = ICS_ArcBolti.Point(1);//获取交点1
		gp_Pnt Inter2_ArcBolti = ICS_ArcBolti.Point(2);//获取交点2
		gp_Pnt Inter_ArcBolti;
		Inter_ArcBolti.SetX(Inter1_ArcBolti.X());
		Inter_ArcBolt.SetY(Inter1_ArcBolt.Y());
		if (Inter1_ArcBolti.Y() < Inter2_ArcBolti.Y()) {
			Inter_ArcBolti.SetX(Inter2_ArcBolti.X());
			Inter_ArcBolti.SetY(Inter2_ArcBolti.Y());
		}//获得右侧起点
		archAnchPoints(i) = Inter_ArcBolti;
		// 绘制该点处的锚杆
		double lBolt = 400.0; // 锚杆长度
		gp_Vec VLineBolt(1.0, tan(currentAngle), 0.0); // 锚杆方向
		gp_Pnt EndPofLineBolt(archAnchPoints(i).X() + lBolt*cos(currentAngle), archAnchPoints(i).Y() + lBolt*sin(currentAngle), 0.0); // 端点
		TopoDS_Edge arcBolt = BRepBuilderAPI_MakeEdge(EndPofLineBolt, archAnchPoints(i));//得到锚杆轮廓

																						 //Handle(Geom_Line) geomLArcBolt = new Geom_Line(LArcBolt);//弧段右侧端点与圆心所在直线LArcBolt
																						 //TopoDS_Edge TgeomLArcBolt = BRepBuilderAPI_MakeEdge(geomLArcBolt);
																						 //edges_Bolt.push_back(arcBolt);//初支拱墙外轮廓
		builder.Add(compound, arcBolt);
		// 增加角度以移动到下一个点
		currentAngle += angleIncrement;
	}
	//TopoDS_Wire wire;
	//BRepBuilderAPI_MakeWire wireBuilder_arcBolt;
	//for (const TopoDS_Edge& edge : edges_Bolt)
	//{
	//	wireBuilder_arcBolt.Add(edges_Bolt);
	//}
	Handle(AIS_Shape) AiscompoundArcB = new AIS_Shape(compound);
	AiscompoundArcB->SetColor(Quantity_NOC_RED);
	//Aiscompound5->SetTransparency(0.5);
	myOccView->getContext()->Display(AiscompoundArcB, Standard_True);//绘制左侧拱墙锚杆
																	 // 对称获得右侧拱墙锚杆
	gp_Trsf symmetryTransform;
	symmetryTransform.SetMirror(gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(1, 0, 0))); // 以Y轴为镜像轴进行对称
	BRepBuilderAPI_Transform transformOp(compound, symmetryTransform); // 对线段进行对称变换
	transformOp.Build();
	TopoDS_Compound symmetricCompound = TopoDS::Compound(transformOp.Shape());
	Handle(AIS_Shape) AissymmetricCompound = new AIS_Shape(symmetricCompound);//显示右侧拱墙锚杆
	AissymmetricCompound->SetColor(Quantity_NOC_RED);
	myOccView->getContext()->Display(AissymmetricCompound, Standard_True);

	/**边墙锚杆**/
	//弧段
	Handle(Geom_TrimmedCurve) geomCircle_SideWallBolt = GC_MakeArcOfCircle(firSurppOutCircle, Inter_ArcBoltL, Inter_TtanLineLAndCylindFirSurppOutL, false);
	/*TopoDS_Edge TgeomCircle_SideWallBolt = BRepBuilderAPI_MakeEdge(geomCircle_SideWallBolt);
	Handle(AIS_Shape) aTgeomCircle_SideWallBolt = new AIS_Shape(TgeomCircle_SideWallBolt);
	aTgeomCircle_SideWallBolt->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	myOccView->getContext()->Display(aTgeomCircle_SideWallBolt, Standard_True);*/
	//求取左侧弧段弧度
	double Tri = sqrt((Inter_ArcBoltL.X() - Inter_TtanLineLAndCylindFirSurppOutL.X())*(Inter_ArcBoltL.X() - Inter_TtanLineLAndCylindFirSurppOutL.X()) + (Inter_ArcBoltL.Y() - Inter_TtanLineLAndCylindFirSurppOutL.Y())*(Inter_ArcBoltL.Y() - Inter_TtanLineLAndCylindFirSurppOutL.Y())) / 2;//左侧弧度所对弦长一半
	double aSideWallBoltL = 2 * asin(Tri / firstSurpportWallOuter_Rad);
	//double XLeftDown = acos(fabs(Inter_TtanLineLAndCylindFirSurppOutL.X() / firstSurpportWallOuter_Rad));
	//double XLeftUp= acos(fabs(Inter_ArcBoltL.X() / firstSurpportWallOuter_Rad));
	//double aSideWallBoltL;
	if (arch_Angle * M_PI / 180.0 < M_PI) {
		//aSideWallBoltL = XLeftDown + XLeftUp;
		double startAngleSW = M_PI / 2 + arch_Angle * M_PI / 180.0 / 2; // 起始角度
		double endAngleSW = startAngleSW + aSideWallBoltL; // 终止角度，转换成弧度
		double angleIncrementSW = wallAnch_Distance / firstSurpportWallOuter_Rad; // 角度增量
																				  //均匀分布
																				  //均匀分布拱墙锚杆
		Standard_Integer numPointsSW = static_cast<Standard_Integer>((endAngleSW - startAngleSW) / angleIncrementSW) + 1;// 计算需要创建的点的数量
		TColgp_Array1OfPnt archAnchPointsSW(1, numPointsSW);// 创建数组以存储点
		Standard_Real currentAngleSW = startAngleSW;// 初始化参数
													// 在弧段 a 上均匀分布点并存储它们
													//std::vector<TopoDS_Edge> edges_Bolt;//存储锚杆
		TopoDS_Compound compoundSW;// 创建一个数据结构来储存线段
		BRep_Builder builderSW;
		builderSW.MakeCompound(compoundSW);
		for (Standard_Integer i = 1; i <= numPointsSW; ++i) {
			// 使用参数来计算点的位置
			gp_Dir dLArcBoltiSW(1, tan(currentAngleSW), 0);
			gp_Lin LArcBoltiSW(center, dLArcBoltiSW);
			Handle(Geom_Line) geomLArcBoltiSW = new Geom_Line(LArcBoltiSW);//弧段锚杆起点与圆心所在直线LArcBolti

			GeomAPI_IntCS ICS_ArcBoltiSW(geomLArcBoltiSW, geomCylindFirSurppOut2);//直线LArcBolt与初衬外轮廓所在圆柱面求交
			gp_Pnt Inter1_ArcBoltiSW = ICS_ArcBoltiSW.Point(1);//获取交点1
			gp_Pnt Inter2_ArcBoltiSW = ICS_ArcBoltiSW.Point(2);//获取交点2
			gp_Pnt Inter_ArcBoltiSW;
			Inter_ArcBoltiSW.SetX(Inter1_ArcBoltiSW.X());
			Inter_ArcBoltiSW.SetY(Inter1_ArcBoltiSW.Y());
			if (Inter1_ArcBoltiSW.X()>0) {
				Inter_ArcBoltiSW.SetX(Inter2_ArcBoltiSW.X());
				Inter_ArcBoltiSW.SetY(Inter2_ArcBoltiSW.Y());
			}//获得右侧起点
			archAnchPointsSW(i) = Inter_ArcBoltiSW;
			// 绘制该点处的锚杆
			double lBolt = 400.0; // 锚杆长度
			gp_Vec VLineBoltSW(1.0, tan(currentAngleSW), 0.0); // 锚杆方向
			gp_Pnt EndPofLineBoltSW(archAnchPointsSW(i).X() + lBolt*cos(currentAngleSW), archAnchPointsSW(i).Y() + lBolt*sin(currentAngleSW), 0.0); // 端点
			TopoDS_Edge arcBoltSW = BRepBuilderAPI_MakeEdge(EndPofLineBoltSW, archAnchPointsSW(i));//得到锚杆轮廓

																								   //Handle(Geom_Line) geomLArcBolt = new Geom_Line(LArcBolt);//弧段右侧端点与圆心所在直线LArcBolt
																								   //TopoDS_Edge TgeomLArcBolt = BRepBuilderAPI_MakeEdge(geomLArcBolt);
																								   //edges_Bolt.push_back(arcBolt);//初支拱墙外轮廓
			builder.Add(compoundSW, arcBoltSW);
			// 增加角度以移动到下一个点
			currentAngleSW += angleIncrementSW;
		}
		Handle(AIS_Shape) AiscompoundSW = new AIS_Shape(compoundSW);
		AiscompoundSW->SetColor(Quantity_NOC_YELLOW);
		//Aiscompound5->SetTransparency(0.5);
		myOccView->getContext()->Display(AiscompoundSW, Standard_True);//绘制左侧拱墙锚杆

																	   // 对称获得右侧边墙锚杆
		gp_Trsf symmetryTransformSW;
		symmetryTransformSW.SetMirror(gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(1, 0, 0))); // 以Y轴为镜像轴进行对称
		BRepBuilderAPI_Transform transformOpSW(compoundSW, symmetryTransformSW); // 对线段进行对称变换
		transformOpSW.Build();
		TopoDS_Compound symmetricCompoundSW = TopoDS::Compound(transformOpSW.Shape());
		Handle(AIS_Shape) AissymmetricCompoundSW = new AIS_Shape(symmetricCompoundSW);//显示右侧边墙锚杆
		AissymmetricCompoundSW->SetColor(Quantity_NOC_YELLOW);
		myOccView->getContext()->Display(AissymmetricCompoundSW, Standard_True);
	}
	else
	{
		//aSideWallBoltL = fabs(XLeftDown - XLeftUp);
	}
	//切线段锚杆
	double Dis_TtanLineL = endPofTtanLineL.Distance(Inter_TtanLineLAndCylindFirSurppOutL);//左侧切线段长度
																						  //Standard_Integer numPointsL = static_cast<Standard_Integer>(Dis_TtanLineL / wallAnch_Distance) + 1;// 计算需要创建的点的数量
																						  //double TtanLineLX_Increament = (Inter_TtanLineLAndCylindFirSurppOutL.X() - endPofTtanLineL.X()) / numPointsL;//x方向增量
																						  //double TtanLineLY_Increament = (Inter_TtanLineLAndCylindFirSurppOutL.Y() - endPofTtanLineL.Y()) / numPointsL;//Y方向增量
																						  //TColgp_Array1OfPnt archAnchPointsT(1, numPointsL);// 创建数组以存储点
																						  //求锚杆方向向量
	double DiffeX = fabs(Inter_TtanLineLAndCylindFirSurppOutL.X() - endPofTtanLineL.X());
	double DiffeY = fabs(Inter_TtanLineLAndCylindFirSurppOutL.Y() - endPofTtanLineL.Y());
	double Angle_wallAnch = atan(DiffeY / DiffeX);//左侧切线段段与x轴夹角
	gp_Vec VLineBoltAnch(-sin(Angle_wallAnch), -cos(Angle_wallAnch), 0.0); // 切线段锚杆方向向量

	double TtanLineLX_Increament = wallAnch_Distance*cos(Angle_wallAnch);//x方向增量
	double TtanLineLY_Increament = wallAnch_Distance*sin(Angle_wallAnch);//Y方向增量
	TopoDS_Compound compoundWA;// 创建一个数据结构来储存线段
	BRep_Builder builderWA;
	builderWA.MakeCompound(compoundWA);
	//均匀分布锚杆
	double currentX = Inter_TtanLineLAndCylindFirSurppOutL.X() + TtanLineLX_Increament;
	double currentY = Inter_TtanLineLAndCylindFirSurppOutL.Y() - TtanLineLY_Increament;
	while (currentY >= endPofTtanLineL.Y())
	{
		/*currentX += TtanLineLX_Increament;
		currentY -= TtanLineLY_Increament;*/
		double lBolt = 400.0; // 锚杆长度
		gp_Pnt StarP_wallAnch;//锚杆起点
		StarP_wallAnch.SetX(currentX);
		StarP_wallAnch.SetY(currentY);
		gp_Pnt EndP_wallAnch = StarP_wallAnch.Translated(lBolt * VLineBoltAnch);//锚杆终点

		TopoDS_Edge arcBolt_wallAnch = BRepBuilderAPI_MakeEdge(StarP_wallAnch, EndP_wallAnch);//得到锚杆轮廓
		builder.Add(compoundWA, arcBolt_wallAnch);
		currentX += TtanLineLX_Increament;
		currentY -= TtanLineLY_Increament;
		builder.Add(compoundWA, arcBolt_wallAnch);
	}
	Handle(AIS_Shape) AiscompoundWA = new AIS_Shape(compoundWA);
	AiscompoundWA->SetColor(Quantity_NOC_YELLOW);//显示
												 //Aiscompound5->SetTransparency(0.5);
	myOccView->getContext()->Display(AiscompoundWA, Standard_True);//绘制左侧边墙直线段锚杆
																   // 对称获得右侧边墙直线段锚杆
	gp_Trsf symmetryTransformWA;
	symmetryTransformWA.SetMirror(gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(1, 0, 0))); // 以Y轴为镜像轴进行对称
	BRepBuilderAPI_Transform transformOpWA(compoundWA, symmetryTransformWA); // 对线段进行对称变换
	transformOpWA.Build();
	TopoDS_Compound symmetricCompoundWA = TopoDS::Compound(transformOpWA.Shape());
	Handle(AIS_Shape) AissymmetricCompoundWA = new AIS_Shape(symmetricCompoundWA);//显示右侧边墙锚杆
	AissymmetricCompoundWA->SetColor(Quantity_NOC_YELLOW);
	myOccView->getContext()->Display(AissymmetricCompoundWA, Standard_True);

	/*钢架*/
	//首先根据钢架角度确定钢架起点和终点，A、B钢架刚好组成一个半圆
	double angelA = 80 / 180 * M_PI;//30为A钢架圆心角
	double angelB = (M_PI - 3 * angelA) / 2;//B钢架圆心角

											//double firstSurpportWallOuter_Rad = secondSurppWallOut_Rad + firstSurppWall_Thick;//初支外轮廓半径
	double Cement_Thick = 10;//初喷混凝土厚度
	double Deformation = 40;//预留变形量
	double stellRadius = firstSurpportWallOuter_Rad - Cement_Thick;//A钢架中心距隧道中心距离
	gp_Ax2 Ax2_steel(center, gp_Dir(0, 0, 1));
	//gp_Circ Circle_Connection(Ax2_O4_EC, cirConnn_Rad);
	gp_Ax3 Ax3_steel(Ax2_steel);

	gp_Circ SteelCircle(Ax2_steel, stellRadius); // A钢架中心所在圆
	gp_Cylinder cylindSteel(Ax3_steel, stellRadius);//A钢架中心所在圆柱
	Handle(Geom_CylindricalSurface) geomCylindSteel = new Geom_CylindricalSurface(cylindSteel);


	double ceta = M_PI * 5 / 12;
	gp_Dir Dsteel(cos(ceta), sin(ceta), 0);
	gp_Lin Lsteel(center, Dsteel);//隧道中心与钢架右侧端点所在直线
	Handle(Geom_Line) geomLsteel = new Geom_Line(Lsteel);
	TopoDS_Edge TgeomLsteel = BRepBuilderAPI_MakeEdge(geomLsteel);
	Handle(AIS_Shape) aTgeomLsteel = new AIS_Shape(TgeomLsteel);
	aTgeomLsteel->SetColor(Quantity_Color(Quantity_NOC_BLUE));
	//myOccView->getContext()->Display(aTgeomLsteel, Standard_True);
	GeomAPI_IntCS ICS_SteelSurppOut2(geomLsteel, geomCylindSteel);//直线Lsteel与A钢架中心所在圆柱求交
	gp_Pnt Inter1_SteelSurppOut2 = ICS_SteelSurppOut2.Point(1);//获取交点1
	gp_Pnt Inter2_SteelSurppOut2 = ICS_SteelSurppOut2.Point(2);//获取交点2
	gp_Pnt Inter_SteelSurppOut2;
	Inter_SteelSurppOut2.SetX(Inter1_SteelSurppOut2.X());
	Inter_SteelSurppOut2.SetY(Inter1_SteelSurppOut2.Y());
	if (Inter1_SteelSurppOut2.Y() < Inter2_SteelSurppOut2.Y()) {
		Inter_SteelSurppOut2.SetX(Inter2_SteelSurppOut2.X());
		Inter_SteelSurppOut2.SetY(Inter2_SteelSurppOut2.Y());
	}//获得A钢架右侧起点
	gp_Pnt Inter_SteelSurppOut2L(-Inter_SteelSurppOut2.X(), Inter_SteelSurppOut2.Y(), 0);//获得A钢架左侧起点
	Handle(Geom_TrimmedCurve) geomCircle_ASteel = GC_MakeArcOfCircle(SteelCircle, Inter_SteelSurppOut2, Inter_SteelSurppOut2L, false);//获取A段钢架弧度
	TopoDS_Edge edgeSteelLaw = BRepBuilderAPI_MakeEdge(geomCircle_ASteel);
	TopoDS_Wire wireSteelLaw = BRepBuilderAPI_MakeWire(TopoDS::Edge(edgeSteelLaw));
	BRepBuilderAPI_MakeEdge edgeCircle_ASteel(geomCircle_ASteel);

	TopoDS_Shape shapeCircle_ASteel = edgeCircle_ASteel.Edge();
	//TopoDS_Edge TgeomCircle_ASteel = BRepBuilderAPI_MakeEdge(geomCircle_ASteel);
	//Handle(AIS_Shape) aTgeomCircle_ASteel = new AIS_Shape(TgeomCircle_ASteel);
	//aTgeomCircle_ASteel->SetColor(Quantity_Color(Quantity_NOC_BLUE));
	//myOccView->getContext()->Display(aTgeomCircle_ASteel, Standard_True);

	//工字钢截面(示意）
	gp_Dir DSteel(-cos(ceta), 1 / sin(ceta) - sin(ceta), 0);//工字钢截面法向向量
	gp_Ax2 Ax2_test(Inter_SteelSurppOut2, DSteel);
	gp_Circ SteelCircle_test(Ax2_test, 30);//假设为圆
	TopoDS_Edge edgeSteel = BRepBuilderAPI_MakeEdge(SteelCircle_test);
	TopoDS_Wire wireSteel = BRepBuilderAPI_MakeWire(TopoDS::Edge(edgeSteel));

	gp_Dir DSteelL(cos(ceta), 1 / sin(ceta) - sin(ceta), 0);//工字钢截面法向向量
	gp_Ax2 Ax2_testL(Inter_SteelSurppOut2L, DSteelL);
	gp_Circ SteelCircle_testL(Ax2_testL, 30);//假设为圆
	Geom_Circle SteelGCircleL(SteelCircle_testL);
	Handle(Geom_Curve) GSteelGCircleL = new Geom_Circle(SteelGCircleL);
	TopoDS_Edge edgeSteelL = BRepBuilderAPI_MakeEdge(SteelCircle_testL);
	TopoDS_Wire wireSteelL = BRepBuilderAPI_MakeWire(TopoDS::Edge(edgeSteelL));

	//工字钢工型截面
	double steelH = 22;//工字钢高度220
	double steelD = 22;//工字钢宽度110
	double steelS = 0.75;//工字钢翼板横向长度7.5
	double steelV = 0.4;//工字钢翼板直线段高度4
	double steelVH = 1.23;//工字钢翼板高度一半12.3
	double steelVL = 2.5625;//工字钢翼板宽度一半25.625
	double steelC1 = 0.48;//小圆半径4.8
	double steelC2 = 0.95;//小圆半径9.5
	gp_Pnt Psteel_A(0, stellRadius + steelH / 2, -steelD / 2);//截面左上部分所有控制点的坐标
	gp_Pnt Psteel_A1(0, stellRadius + steelH / 2, 0);
	gp_Pnt Psteel_B(0, stellRadius + steelH / 2 - steelV, -steelD / 2);
	gp_Pnt Psteel_F(0, stellRadius, -steelS / 2);
	gp_Pnt Psteel_E(0, stellRadius + steelH / 2 - steelVH * 2, -steelS / 2);
	double C = steelVH * 2 - steelV;
	double M = steelC1 + steelC2 - (steelD - steelS) / 2;

	double Angle_SectionSteel;//圆弧圆心角
	double SectionSteel_X;//斜段水平长度
	double SectionSteel_X1;
	double SectionSteel_X2;
	/*double d = 40.7 + Psteel_F.Z();
	double a = 37 / 36;
	double b = -2 * d - 20.6 / 3;
	double c = d*d + 20.6*20.6 - 14.3*14.3;*/
	double a = 37 / 36;
	double b = 2 * M - C / 3;
	double c = C*C + M*M - (steelC1 + steelC2)*(steelC1 + steelC2);
	double disc = b*b - 4 * a*c;
	if (disc>0)
	{
		//if((-b - sqrt(disc)) / (2 * a)<=0){
		//	SectionSteel_X = (-b + sqrt(disc)) / (2 * a);
		//}
		//else
		//{
		//	SectionSteel_X = (-b - sqrt(disc)) / (2 * a);
		//}
		SectionSteel_X1 = (-b + sqrt(disc)) / (2 * a);
		SectionSteel_X2 = (-b - sqrt(disc)) / (2 * a);

	}
	else if (disc == 0)
	{
		SectionSteel_X = -b / (2 * a);
	}
	else {

	}
	double W = 1 / (steelC1 + steelC2)*(C - SectionSteel_X1 / 6);
	if (W<1)
	{
		SectionSteel_X = SectionSteel_X1;

	}
	else
	{
		SectionSteel_X = SectionSteel_X2;
	}
	Angle_SectionSteel = asin((1 / (steelC1 + steelC2)*(C - SectionSteel_X / 6)));

	gp_Pnt Psteel_C(0, stellRadius + steelH / 2 - steelV - steelC1*sin(Angle_SectionSteel), -steelD / 2 + steelC1*(1 - cos(Angle_SectionSteel)));
	gp_Pnt Psteel_D(0, stellRadius + steelH / 2 - steelV - steelC1* sin(Angle_SectionSteel) - SectionSteel_X / 6, -steelD / 2 + steelC1*(1 - cos(Angle_SectionSteel)) + SectionSteel_X);
	gp_Pnt Psteel_OB(0, stellRadius + steelH / 2 - steelV, -steelD / 2 + steelC1);//点B所在圆弧圆心
	gp_Pnt Psteel_OE(0, stellRadius + steelH / 2 - steelVH * 2, -steelS / 2 - steelC2);//点E所在圆弧圆心

	TopoDS_Edge Tline_AA1 = BRepBuilderAPI_MakeEdge(Psteel_A, Psteel_A1);
	Handle(AIS_Shape) ATline_AA1 = new AIS_Shape(Tline_AA1);//显示右侧边墙锚杆
	ATline_AA1->SetColor(Quantity_NOC_YELLOW);
	myOccView->getContext()->Display(ATline_AA1, Standard_True);

	TopoDS_Edge Tline_AB = BRepBuilderAPI_MakeEdge(Psteel_A, Psteel_B);
	Handle(AIS_Shape) ATline_AB = new AIS_Shape(Tline_AB);//显示右侧边墙锚杆
	ATline_AB->SetColor(Quantity_NOC_YELLOW);
	myOccView->getContext()->Display(ATline_AB, Standard_True);

	TopoDS_Edge Tline_CD = BRepBuilderAPI_MakeEdge(Psteel_C, Psteel_D);
	Handle(AIS_Shape) ATline_CD = new AIS_Shape(Tline_CD);//显示右侧边墙锚杆
	ATline_CD->SetColor(Quantity_NOC_YELLOW);
	myOccView->getContext()->Display(ATline_CD, Standard_True);

	TopoDS_Edge Tline_EF = BRepBuilderAPI_MakeEdge(Psteel_E, Psteel_F);
	Handle(AIS_Shape) ATline_EF = new AIS_Shape(Tline_EF);//显示右侧边墙锚杆
	ATline_EF->SetColor(Quantity_NOC_YELLOW);
	myOccView->getContext()->Display(ATline_EF, Standard_True);

	//绘制圆弧段
	gp_Dir DSteel_Section(1, 0, 0);
	gp_Ax2 Ax2_OB(Psteel_OB, DSteel_Section);
	gp_Circ SteelCircle_OB(Ax2_OB, steelC1);
	Handle(Geom_TrimmedCurve) geomCircle_OB = GC_MakeArcOfCircle(SteelCircle_OB, Psteel_C, Psteel_B, false);//弧段BC
	TopoDS_Edge TgeomCircle_OB = BRepBuilderAPI_MakeEdge(geomCircle_OB);
	//Handle(AIS_Shape) ATgeomCircle_OB = new AIS_Shape(TgeomCircle_OB);
	//ATgeomCircle_OB->SetColor(Quantity_NOC_YELLOW);
	//myOccView->getContext()->Display(ATgeomCircle_OB, Standard_True);

	gp_Ax2 Ax2_OE(Psteel_OE, DSteel_Section);
	gp_Circ SteelCircle_OE(Ax2_OE, steelC2);
	Handle(Geom_TrimmedCurve) geomCircle_OE = GC_MakeArcOfCircle(SteelCircle_OE, Psteel_D, Psteel_E, false);//弧段DE
	TopoDS_Edge TgeomCircle_OE = BRepBuilderAPI_MakeEdge(geomCircle_OE);
	//Handle(AIS_Shape) ATgeomCircle_OE = new AIS_Shape(TgeomCircle_OE);
	//ATgeomCircle_OE->SetColor(Quantity_NOC_YELLOW);
	//myOccView->getContext()->Display(ATgeomCircle_OE, Standard_True);

	TopoDS_Compound compoundSteelSection;// 创建一个数据结构来储存线段1/4截面
	BRep_Builder builderSteelSection;
	builderSteelSection.MakeCompound(compoundSteelSection);

	builderSteelSection.Add(compoundSteelSection, Tline_AA1);
	builderSteelSection.Add(compoundSteelSection, Tline_AB);
	builderSteelSection.Add(compoundSteelSection, Tline_CD);
	builderSteelSection.Add(compoundSteelSection, Tline_EF);
	builderSteelSection.Add(compoundSteelSection, TgeomCircle_OB);
	builderSteelSection.Add(compoundSteelSection, TgeomCircle_OE);

	gp_Trsf symmetryTransformSection;//对称获得2/4截面
	symmetryTransformSection.SetMirror(gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(0, 0, 1))); // 
	BRepBuilderAPI_Transform transformOpSection(compoundSteelSection, symmetryTransformSection); // 对线段进行对称变换
	transformOpSection.Build();
	TopoDS_Compound symmetricCompoundSection = TopoDS::Compound(transformOpSection.Shape());
	//Handle(AIS_Shape) AissymmetricCompoundSection = new AIS_Shape(symmetricCompoundSection);//
	//AissymmetricCompoundSection->SetColor(Quantity_NOC_YELLOW);
	//myOccView->getContext()->Display(AissymmetricCompoundSection, Standard_True);

	gp_Trsf symmetryTransformSection2;//对称获得3/4截面
	symmetryTransformSection2.SetMirror(gp_Ax2(gp_Pnt(0, stellRadius, 0), gp_Dir(0, stellRadius - 1, 0))); // 
	BRepBuilderAPI_Transform transformOpSection2(compoundSteelSection, symmetryTransformSection2); // 对线段进行对称变换
	transformOpSection2.Build();
	TopoDS_Compound symmetricCompoundSection2 = TopoDS::Compound(transformOpSection2.Shape());

	gp_Trsf symmetryTransformSection3;//对称获得4/4截面
	symmetryTransformSection3.SetMirror(gp_Ax2(gp_Pnt(0, stellRadius, 0), gp_Dir(0, stellRadius - 1, 0))); // 
	BRepBuilderAPI_Transform transformOpSection3(symmetricCompoundSection, symmetryTransformSection3); // 对线段进行对称变换
	transformOpSection3.Build();
	TopoDS_Compound symmetricCompoundSection3 = TopoDS::Compound(transformOpSection3.Shape());

	TopoDS_Compound compoundSteelSectionAll;// 创建一个数据结构来储存所有截面的组成部分
	BRep_Builder builderSteelSectionAll;
	builderSteelSectionAll.MakeCompound(compoundSteelSectionAll);
	builderSteelSectionAll.Add(compoundSteelSectionAll, compoundSteelSection);
	builderSteelSectionAll.Add(compoundSteelSectionAll, symmetricCompoundSection);
	builderSteelSectionAll.Add(compoundSteelSectionAll, symmetricCompoundSection2);
	builderSteelSectionAll.Add(compoundSteelSectionAll, symmetricCompoundSection3);
	Handle(AIS_Shape) AiscompoundSteelSectionAll = new AIS_Shape(compoundSteelSectionAll);//
	AiscompoundSteelSectionAll->SetColor(Quantity_NOC_YELLOW);
	myOccView->getContext()->Display(AiscompoundSteelSectionAll, Standard_True);


	gp_Trsf rotationTransform;
	//Standard_Real angle = M_PI / 4.0; // 旋转角度（弧度）
	gp_Ax1 rotationAxis(gp_Pnt(0, 0, 0), gp_Dir(0, 0, 1)); // 旋转轴（以原点为中心）
	rotationTransform.SetRotation(rotationAxis, ceta - M_PI / 2);
	BRepBuilderAPI_Transform transformBuilder(compoundSteelSectionAll, rotationTransform);
	transformBuilder.Build();
	transformBuilder.Perform(compoundSteelSectionAll);
	//transformBuilder.Perform();
	TopoDS_Compound rotatedCompound = TopoDS::Compound(transformBuilder.Shape());//A起始截面
	TopExp_Explorer explorer(rotatedCompound, TopAbs_SOLID);
	//Handle(AIS_Shape) AisrotatedCompound = new AIS_Shape(rotatedCompound);//
	//AisrotatedCompound->SetColor(Quantity_NOC_YELLOW);
	//myOccView->getContext()->Display(AisrotatedCompound, Standard_True);


	LocOpe_Pipe SteelPipe(wireSteelLaw, rotatedCompound);
	TopoDS_Shape ShapeSteelPipe = SteelPipe.Shape();
	Handle(AIS_Shape) AisShapeSteelPipe = new AIS_Shape(ShapeSteelPipe);//A段钢架
	AisShapeSteelPipe->SetColor(Quantity_NOC_YELLOW);
	myOccView->getContext()->Display(AisShapeSteelPipe, Standard_True);


	//旋转得到B钢架的起始断面
	gp_Trsf rotationTransform2;
	//Standard_Real angle = M_PI / 4.0; // 旋转角度（弧度）
	//gp_Ax1 rotationAxis(gp_Pnt(0, 0, 0), gp_Dir(0, 0, 1)); // 旋转轴（以原点为中心）
	rotationTransform2.SetRotation(rotationAxis, ceta - M_PI / 2);
	BRepBuilderAPI_Transform transformBuilder2(compoundSteelSectionAll, rotationTransform2);
	transformBuilder2.Build();
	transformBuilder2.Perform(compoundSteelSectionAll);
	//transformBuilder.Perform();
	TopoDS_Compound rotatedCompoundB = TopoDS::Compound(transformBuilder2.Shape());
	TopExp_Explorer explorer2(rotatedCompoundB, TopAbs_SOLID);
	//Handle(AIS_Shape) AisrotatedCompoundB = new AIS_Shape(rotatedCompoundB);//
	//AisrotatedCompoundB->SetColor(Quantity_NOC_YELLOW);
	//myOccView->getContext()->Display(AisrotatedCompoundB, Standard_True);
	//B钢架轨迹
	gp_Pnt SteelB(stellRadius, 0, 0);
	Handle(Geom_TrimmedCurve) geomCircle_ASteelB = GC_MakeArcOfCircle(SteelCircle, SteelB, Inter_SteelSurppOut2, false);//获取B段钢架中心轨迹
	TopoDS_Edge edgeSteelLawB = BRepBuilderAPI_MakeEdge(geomCircle_ASteelB);
	TopoDS_Wire wireSteelLawB = BRepBuilderAPI_MakeWire(TopoDS::Edge(edgeSteelLawB));
	//拉伸B钢架
	LocOpe_Pipe SteelPipeB(wireSteelLawB, rotatedCompoundB);
	TopoDS_Shape ShapeSteelPipeB = SteelPipeB.Shape();
	Handle(AIS_Shape) AisShapeSteelPipeB = new AIS_Shape(ShapeSteelPipeB);//A段钢架
	AisShapeSteelPipeB->SetColor(Quantity_NOC_BLUE);
	myOccView->getContext()->Display(AisShapeSteelPipeB, Standard_True);
	//B钢架沿着yoz平面对称
	gp_Trsf symmetryTransformSectionB;//对称获得2/4截面
	symmetryTransformSectionB.SetMirror(gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(1, 0, 0))); // 
	BRepBuilderAPI_Transform transformOpSectionB(ShapeSteelPipeB, symmetryTransformSectionB); // 对线段进行对称变换
	transformOpSectionB.Build();
	TopoDS_Compound symmetricCompoundSectionB = TopoDS::Compound(transformOpSectionB.Shape());
	Handle(AIS_Shape) AisShapeSteelPipeBL = new AIS_Shape(symmetricCompoundSectionB);//B段钢架左段
	AisShapeSteelPipeBL->SetColor(Quantity_NOC_BLUE);
	myOccView->getContext()->Display(AisShapeSteelPipeBL, Standard_True);


	////拉伸
	/*Handle(Geom2d_Curve) SteelPath = GeomProjLib::Curve2d(geomCircle_ASteel, geomCylindSteel);
	GeomFill_Pipe PipeSteel(SteelPath, geomCylindSteel, GSteelGCircleL);*/
	//PipeSteel.Perform();
	//// 检查拉伸操作是否成功完成
	//if (PipeSteel.IsDone()) {
	//	// 获取拉伸结果
	//	Handle(Geom_Surface) PipeSteel_result = PipeSteel.Surface();

	//	// 构建拉伸后的实体
	//	BRepBuilderAPI_MakeFace makeFace_Steel(PipeSteel_result, Precision::Confusion());
	//	TopoDS_Face face_Steel = makeFace_Steel.Face();
	//	TopoDS_Shell shell_Steel;
	//	BRep_Builder builder_Steel;
	//	builder_Steel.MakeShell(shell_Steel);
	//	builder.Add(shell_Steel, face_Steel);
	//	//TopoDS_Solid Solid_Stell=
	//	BRepBuilderAPI_MakeSolid makeSolid;
	//	makeSolid.Add(shell_Steel);
	//	TopoDS_Solid solid_Steel = makeSolid.Solid();
	//	Handle(AIS_Shape) aPipe_Steel = new AIS_Shape(solid_Steel);
	//	aPipe_Steel->SetColor(Quantity_Color(Quantity_NOC_YELLOW));
	//	myOccView->getContext()->Display(aPipe_Steel, Standard_True);

	//	//BRepPrimAPI_MakePrism makePrism(face_Steel, curve);
	//	//TopoDS_Shape shape = makePrism.Shape();

	//	//// 将实体添加到可视化器中
	//	//V3d_Viewer viewer;
	//	//AIS_InteractiveContext context(viewer);
	//	//AIS_Shape aisShape(shape);
	//	//context.Display(aisShape);
	//}
	//else {
	//	// 拉伸操作失败，处理错误
	//}


};


void MainWindow::handleErchen(const Erchen& centercoords)
{
	// 调用 makeTabu() 函数，并传递 SquareCoordinates 结构的坐标参数
	makeErchen(centercoords);
}

void MainWindow::makeErchen(const Erchen& centercoords)
{
	// 创建圆 O1  拱部内侧，665半径 
	gp_Pnt P_CO1_NLK(0.0, 0.0, 0.0); // 原点为圆心
	gp_Ax2 axis1(P_CO1_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real R1_NLK = centercoords.E1; // 定义圆的半径
											//Standard_Real R1_NLK = 665; // 定义圆的半径

	gp_Circ CO1_NLK(axis1, R1_NLK);
	Handle(Geom_Circle) geomCircle1_NLK = new Geom_Circle(CO1_NLK);
	TopoDS_Edge edge1_NLK = BRepBuilderAPI_MakeEdge(geomCircle1_NLK);

	// 创建原点的中垂线
	BRepBuilderAPI_MakeEdge edge(gp_Pnt(0, -1000, 0), gp_Pnt(0, 1000, 0));
	TopoDS_Shape shape3 = edge.Shape();
	// 计算圆心到点 P 的距离 盖板距离线段
	Standard_Real radius = R1_NLK;
	//Standard_Real radius3 = 1720; // 圆O3的半径
	Standard_Real radius3 = centercoords.E2; // 圆O3的半径
	Standard_Real GoucaoKuandu = centercoords.E6;
	Standard_Real JibenKuandu = centercoords.E8;
	Standard_Real GoucaoGaocha = centercoords.E7;
	Standard_Real R3_TC = centercoords.E5;

	//Standard_Real height = sqrt(pow(radius, 2) - pow(630, 2));
	Standard_Real height = sqrt(pow(radius, 2) - pow((GoucaoKuandu + JibenKuandu / 2), 2));
	//Standard_Real distanceCenterToP = sqrt(pow(radius, 2) + pow(630, 2)) - radius;
	Standard_Real distanceCenterToP = sqrt(pow(radius, 2) + pow((GoucaoKuandu + JibenKuandu / 2), 2)) - radius;
	gp_Pnt pointP(0, -height, 0);

	//// 计算圆心到点 P 的距离 盖板距离线段
	//Standard_Real R1_NLK = 665.0;
	//Standard_Real R3_NLK = 1720; // 圆O3的半径
	//Standard_Real height = sqrt(pow(R1_NLK, 2) - pow(630, 2));
	//Standard_Real distanceCenterToP = sqrt(pow(R1_NLK, 2) + pow(630, 2)) - R1_NLK;
	//gp_Pnt pointP(0, -height, 0);

	// 确定新的圆心 P3  仰拱圆心
	//gp_Pnt pointP3(0, radius3 - 180 - 30  - height , 0);//180和30会改变！！！
	gp_Pnt pointP3(0, radius3 - R3_TC - GoucaoGaocha - height, 0);//180和30会改变！！！

																  // // 确定新的圆心 P3  仰拱圆心
																  //gp_Pnt P_CO3_NLK(0, 1720 - 180 - 30 - height, 0);//180和30会改变！！！

																  //计算角度 alpha  确定过渡段圆半径用参数
	Standard_Real alpha = acos(-pointP.Y() / radius);
	////计算角度 alpha  确定过渡段圆半径用参数
	//Standard_Real alpha = acos(-pointP.Y() / R1_NLK);
	// 创建圆心到点 P 的线段
	BRepBuilderAPI_MakeEdge edgeP(gp_Pnt(0, 0, 0), pointP);
	TopoDS_Shape shapeP = edgeP.Shape();

	// 创建圆 O3  仰拱内侧圆
	gp_Ax2 axis03(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
												   //											   // 创建圆 O3  仰拱内侧圆
												   //gp_Ax2 axis03(P_CO3_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real radius03 = radius3; // 半径为 1720cm
	gp_Circ circle03(axis03, radius03);
	Handle(Geom_Circle) geomCircle03 = new Geom_Circle(circle03);
	TopoDS_Edge edge03 = BRepBuilderAPI_MakeEdge(geomCircle03);
	//Standard_Real R3_NLK = 1720.0; // 半径为 1720cm
	//gp_Circ circle03(axis03, R3_NLK);
	//Handle(Geom_Circle) geomCO3_NLK = new Geom_Circle(CO3_NLK);
	//TopoDS_Edge edgeO3_NLK = BRepBuilderAPI_MakeEdge(geomCO3_NLK);

	//计算radius4  内侧过渡段圆半径
	Standard_Real m = pow(radius3, 2) - pow(radius, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*height;
	Standard_Real n = radius3 - radius - pointP3.Y() *height / radius;
	Standard_Real radius4 = m / (2 * n);
	// 创建圆 O4  过渡段内侧圆  左侧
	gp_Pnt centerO4(-sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle4(axis4, radius4);
	Handle(Geom_Circle) geomCircle4 = new Geom_Circle(circle4);
	TopoDS_Edge edge4 = BRepBuilderAPI_MakeEdge(geomCircle4);

	////计算radius4  内侧过渡段圆半径
	//Standard_Real m = pow(R3_NLK, 2) - pow(R1_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*height;
	//Standard_Real n = R3_NLK - R1_NLK - P_CO3_NLK.Y() *height / R1_NLK;
	//Standard_Real R4_NLK = m / (2 * n);
	//// 创建圆 O4  过渡段内侧圆  左侧
	//gp_Pnt centerO4(-sin(alpha) * (R1_NLK - R4_NLK), -cos(alpha) * (R1_NLK - R4_NLK), 0);
	//gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//gp_Circ CO4_NLK(axis4, R4_NLK);
	//Handle(Geom_Circle) geomCO4_NLK = new Geom_Circle(CO4_NLK);
	//TopoDS_Edge edgeO4_NLK= BRepBuilderAPI_MakeEdge(geomCO4_NLK);

	// 创建圆 O7  过渡段内侧圆  右侧
	gp_Pnt centerO7(sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis7(centerO7, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle7(axis7, radius4);
	Handle(Geom_Circle) geomCircle7 = new Geom_Circle(circle7);
	TopoDS_Edge edge7 = BRepBuilderAPI_MakeEdge(geomCircle7);


	///绘制拱墙内侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O1 = R1_NLK;//半径
	gp_Circ Circle_O1_EC(axis1, R_O1);
	gp_Ax3 AxO1(axis1);
	gp_Cylinder Cylinder_O1(AxO1, R_O1);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O1 = new Geom_CylindricalSurface(Cylinder_O1);
	GeomAPI_IntCS ICC_O4_01(geomCircle4, geoCylinder_O1);//求圆04与圆柱面cylinder01交点
	gp_Pnt CUT_O4_01 = ICC_O4_01.Point(1);

	GeomAPI_IntCS ICC_O7_01(geomCircle7, geoCylinder_O1);//求圆07与圆柱面cylinder01交点
	gp_Pnt CUT_O7_01 = ICC_O7_01.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O1_EC, CUT_O7_01, CUT_O4_01, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	Handle(AIS_Shape) aTarcCurve_01 = new AIS_Shape(TarcCurve_01);
	aTarcCurve_01->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_01, Standard_True);



	///绘制仰拱内侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O3 = radius3;//半径
								 /////绘制仰拱内侧弧线，已知弧段圆心、起点、半径
								 //Standard_Real R_O3 = R3_NLK;//半径
	gp_Circ Circle_O3_EC(axis03, R_O3);
	gp_Ax3 AxO3(axis03);
	gp_Cylinder Cylinder_O3(AxO3, R_O3);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O3 = new Geom_CylindricalSurface(Cylinder_O3);
	GeomAPI_IntCS ICC_O4_03(geomCircle4, geoCylinder_O3);//求圆04与圆柱面cylinder01交点
	gp_Pnt CUT_O4_03 = ICC_O4_03.Point(1);

	GeomAPI_IntCS ICC_O7_03(geomCircle7, geoCylinder_O3);//求圆07与圆柱面cylinder01交点
	gp_Pnt CUT_O7_03 = ICC_O7_03.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_03 = GC_MakeArcOfCircle(Circle_O3_EC, CUT_O4_03, CUT_O7_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_03 = BRepBuilderAPI_MakeEdge(arcCurve_03);
	Handle(AIS_Shape) aTarcCurve_03 = new AIS_Shape(TarcCurve_03);
	aTarcCurve_03->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_03, Standard_True);

	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O4 = radius4;//半径
								 /////绘制过渡段左侧弧线，已知弧段圆心、起点、半径
								 //Standard_Real R_O4 = R4_NLK;//半径
	gp_Circ Circle_O4_EC(axis4, R_O4);
	gp_Ax3 AxO4(axis4);
	gp_Cylinder Cylinder_O4(AxO4, R_O4);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_04 = GC_MakeArcOfCircle(Circle_O4_EC, CUT_O4_01, CUT_O4_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_04 = BRepBuilderAPI_MakeEdge(arcCurve_04);
	Handle(AIS_Shape) aTarcCurve_04 = new AIS_Shape(TarcCurve_04);
	aTarcCurve_04->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_04, Standard_True);

	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O7 = radius4;//半径
								 // ///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
								 //Standard_Real R_O7 = R4_NLK;//半径
	gp_Circ Circle_O7_EC(axis7, R_O7);
	gp_Ax3 AxO7(axis7);
	gp_Cylinder Cylinder_O7(AxO7, R_O7);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_07 = GC_MakeArcOfCircle(Circle_O7_EC, CUT_O7_03, CUT_O7_01, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_07 = BRepBuilderAPI_MakeEdge(arcCurve_07);
	Handle(AIS_Shape) aTarcCurve_07 = new AIS_Shape(TarcCurve_07);
	aTarcCurve_07->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_07, Standard_True);



	// 创建圆 O2  拱部外侧，665+55半径
	gp_Pnt P_CO2_NLK(0.0, 0.0, 0.0); // 原点为圆心
	gp_Ax2 axis2(P_CO2_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
													//Standard_Real R2_NLK = 720.0; // 定义圆的半径
	Standard_Real R1_R2_HD = centercoords.E3;
	Standard_Real R2_NLK = R1_NLK + R1_R2_HD; // 定义圆的半径

	gp_Circ CO2_NLK(axis2, R2_NLK);
	Handle(Geom_Circle) geomCircle2 = new Geom_Circle(CO2_NLK);
	TopoDS_Edge edge2 = BRepBuilderAPI_MakeEdge(geomCircle2);

	// 创建圆 O5 仰拱外侧圆
	gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real R3_R5_HD = centercoords.E4;
	Standard_Real radius5 = radius3 + R3_R5_HD; // 半径为 1720cm+55cm
	gp_Circ circle5(axis5, radius5);
	Handle(Geom_Circle) geomCircle5 = new Geom_Circle(circle5);
	TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomCircle5);
	//// 创建圆 O5 仰拱外侧圆
	//gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//Standard_Real R5_NLK = R3_NLK + 65.0; // 半径为 1720cm+55cm
	//gp_Circ circle5(axis5, R5_NLK);
	//Handle(Geom_Circle) geomC05_NLK = new Geom_Circle(C05_NLK);
	//TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomC05_NLK);

	//计算radius6 外侧过渡段圆半径
	//Standard_Real radius6 = solveForR4(alpha, radius, radius3, -pointP.Y());
	Standard_Real s = pow(radius5, 2) - pow(R2_NLK, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*(height + R1_R2_HD*cos(alpha));
	Standard_Real p = radius5 - R2_NLK - pointP3.Y() *(height + R1_R2_HD* cos(alpha)) / R2_NLK;
	Standard_Real radius6 = s / (2 * p);
	////计算radius6 外侧过渡段圆半径
	////Standard_Real R6_NLK = solveForR4(alpha, R1_NLK, R3_NLK, -P_CO1_NLK());
	//Standard_Real s = pow(R5_NLK, 2) - pow(R2_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*(height+R2_NLK*alpha);
	//Standard_Real p = R5_NLK - R2_NLK - P_CO3_NLK.Y() *height / R2_NLK;
	//Standard_Real R6_NLK = s / (2 * p);


	// 创建圆 O6  过渡段外侧圆  左侧
	gp_Pnt centerO6(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle6(axis6, radius6);
	Handle(Geom_Circle) geomCircle6 = new Geom_Circle(circle6);
	TopoDS_Edge edge6 = BRepBuilderAPI_MakeEdge(geomCircle6);
	//// 创建圆 O6  过渡段外侧圆  左侧
	//gp_Pnt centerO6(-sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//gp_Circ circle6(axis6, R6_NLK);
	//Handle(Geom_Circle) geomC06_NLK = new Geom_Circle(C06_NLK);
	//TopoDS_Edge edge6_NLK = BRepBuilderAPI_MakeEdge(geomC06_NLK);

	// 创建圆 O8  过渡段外侧圆  右侧
	gp_Pnt centerO8(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle8(axis8, radius6);
	Handle(Geom_Circle) geomCircle8 = new Geom_Circle(circle8);
	TopoDS_Edge edge8 = BRepBuilderAPI_MakeEdge(geomCircle8);
	//// 创建圆 O8  过渡段外侧圆  右侧
	//gp_Pnt centerO8(sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//gp_Circ circle8(axis8, R6_NLK);
	//Handle(Geom_Circle) geomC08_NLK = new Geom_Circle(C08_NLK);
	//TopoDS_Edge edge8_NLK = BRepBuilderAPI_MakeEdge(geomC08_NLK);

	///绘制拱墙外侧弧线
	Standard_Real R_O2 = R2_NLK;//半径
	gp_Circ Circle_O2_EC(axis2, R_O2);
	gp_Ax3 AxO2(axis2);
	gp_Cylinder Cylinder_O2(AxO2, R_O2);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O2 = new Geom_CylindricalSurface(Cylinder_O2);

	// 定义直线的起点和终点
	gp_Pnt startPoint6_2(0, 0, 0);
	gp_Pnt endPoint6_2(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction6_2(startPoint6_2, endPoint6_2);
	gp_Lin line6_2(startPoint6_2, direction6_2);
	// 创建直线的线段
	TopoDS_Edge lineEdge6_2 = BRepBuilderAPI_MakeEdge(line6_2, startPoint6_2, endPoint6_2);
	Handle(Geom_Line) Geom_lineEdge6_2 = new Geom_Line(line6_2);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O6_02(Geom_lineEdge6_2, geoCylinder_O2);//06 02交点
	gp_Pnt CUT_O6_02_R1 = ICC_O6_02.Point(1);
	gp_Pnt CUT_O6_02_R2 = ICC_O6_02.Point(2);
	gp_Pnt CUT_O6_02;
	CUT_O6_02.SetX(CUT_O6_02_R1.X());
	CUT_O6_02.SetY(CUT_O6_02_R1.Y());
	if (CUT_O6_02_R1.X() > CUT_O6_02_R2.X()) {
		CUT_O6_02.SetX(CUT_O6_02_R2.X());
		CUT_O6_02.SetY(CUT_O6_02_R2.Y());
	}//求得过渡圆弧的起点

	 // 定义直线的起点和终点
	gp_Pnt startPoint8_2(0, 0, 0);
	gp_Pnt endPoint8_2(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction8_2(startPoint8_2, endPoint8_2);
	gp_Lin line8_2(startPoint8_2, direction8_2);
	// 创建直线的线段
	TopoDS_Edge lineEdge8_2 = BRepBuilderAPI_MakeEdge(line8_2, startPoint8_2, endPoint8_2);
	Handle(Geom_Line) Geom_lineEdge8_2 = new Geom_Line(line8_2);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O8_02(Geom_lineEdge8_2, geoCylinder_O2);//08 02交点
	gp_Pnt CUT_O8_02_R1 = ICC_O8_02.Point(1);
	gp_Pnt CUT_O8_02_R2 = ICC_O8_02.Point(2);
	gp_Pnt CUT_O8_02;
	CUT_O8_02.SetX(CUT_O8_02_R1.X());
	CUT_O8_02.SetY(CUT_O8_02_R1.Y());
	if (CUT_O8_02_R1.X() < CUT_O8_02_R2.X()) {
		CUT_O8_02.SetX(CUT_O8_02_R2.X());
		CUT_O8_02.SetY(CUT_O8_02_R2.Y());
	}//求得过渡圆弧的起点

	Handle(Geom_TrimmedCurve) arcCurve_02 = GC_MakeArcOfCircle(Circle_O2_EC, CUT_O8_02, CUT_O6_02, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_02 = BRepBuilderAPI_MakeEdge(arcCurve_02);
	Handle(AIS_Shape) aTarcCurve_02 = new AIS_Shape(TarcCurve_02);
	aTarcCurve_02->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_02, Standard_True);





	///绘制仰拱外侧弧线
	Standard_Real R_O5 = radius5;//半径
	gp_Circ Circle_O5_EC(axis5, R_O5);
	gp_Ax3 AxO5(axis5);
	gp_Cylinder Cylinder_O5(AxO5, R_O5);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O5 = new Geom_CylindricalSurface(Cylinder_O5);

	// 定义直线的起点和终点
	//gp_Pnt startPoint6_5(0, 1720 - 180 - 30 - height, 0);
	gp_Pnt startPoint6_5(0, radius3 - R3_TC - GoucaoGaocha - height, 0);
	gp_Pnt endPoint6_5(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction6_5(startPoint6_5, endPoint6_5);
	gp_Lin line6_5(startPoint6_5, direction6_5);
	// 创建直线的线段
	TopoDS_Edge lineEdge6_5 = BRepBuilderAPI_MakeEdge(line6_5, startPoint6_5, endPoint6_5);
	Handle(Geom_Line) Geom_lineEdge6_5 = new Geom_Line(line6_5);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O6_05(Geom_lineEdge6_5, geoCylinder_O5);//06 02交点
	gp_Pnt CUT_O6_05_R1 = ICC_O6_05.Point(1);
	gp_Pnt CUT_O6_05_R2 = ICC_O6_05.Point(2);
	gp_Pnt CUT_O6_05;
	CUT_O6_05.SetX(CUT_O6_05_R1.X());
	CUT_O6_05.SetY(CUT_O6_05_R1.Y());
	if (CUT_O6_05_R1.X() > CUT_O6_05_R2.X()) {
		CUT_O6_05.SetX(CUT_O6_05_R2.X());
		CUT_O6_05.SetY(CUT_O6_05_R2.Y());
	}//求得过渡圆弧的起点

	 // 定义直线的起点和终点
	 //gp_Pnt startPoint8_5(0, 1720 - 180 - 30 - height, 0);
	gp_Pnt startPoint8_5(0, radius3 - R3_TC - GoucaoGaocha - height, 0);
	gp_Pnt endPoint8_5(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction8_5(startPoint8_5, endPoint8_5);
	gp_Lin line8_5(startPoint8_5, direction8_5);
	// 创建直线的线段
	TopoDS_Edge lineEdge8_5 = BRepBuilderAPI_MakeEdge(line8_5, startPoint8_5, endPoint8_5);
	Handle(Geom_Line) Geom_lineEdge8_5 = new Geom_Line(line8_5);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O8_05(Geom_lineEdge8_5, geoCylinder_O5);//08 02交点
	gp_Pnt CUT_O8_05_R1 = ICC_O8_05.Point(1);
	gp_Pnt CUT_O8_05_R2 = ICC_O8_05.Point(2);
	gp_Pnt CUT_O8_05;
	CUT_O8_05.SetX(CUT_O8_05_R1.X());
	CUT_O8_05.SetY(CUT_O8_05_R1.Y());
	if (CUT_O8_05_R1.X() < CUT_O8_05_R2.X()) {
		CUT_O8_05.SetX(CUT_O8_05_R2.X());
		CUT_O8_05.SetY(CUT_O8_05_R2.Y());
	}//求得过渡圆弧的起点


	Handle(Geom_TrimmedCurve) arcCurve_05 = GC_MakeArcOfCircle(Circle_O5_EC, CUT_O6_05, CUT_O8_05, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_05 = BRepBuilderAPI_MakeEdge(arcCurve_05);
	Handle(AIS_Shape) aTarcCurve_05 = new AIS_Shape(TarcCurve_05);
	aTarcCurve_05->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_05, Standard_True);







	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O6 = radius6;//半径
	gp_Circ Circle_O6_EC(axis6, R_O6);
	gp_Ax3 AxO6(axis6);
	gp_Cylinder Cylinder_O6(AxO6, R_O6);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_06 = GC_MakeArcOfCircle(Circle_O6_EC, CUT_O6_02, CUT_O6_05, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_06 = BRepBuilderAPI_MakeEdge(arcCurve_06);
	Handle(AIS_Shape) aTarcCurve_06 = new AIS_Shape(TarcCurve_06);
	aTarcCurve_06->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_06, Standard_True);




	///绘制过渡段右侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O8 = radius6;//半径
	gp_Circ Circle_O8_EC(axis8, R_O8);
	gp_Ax3 AxO8(axis8);
	gp_Cylinder Cylinder_O8(AxO8, R_O8);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_08 = GC_MakeArcOfCircle(Circle_O8_EC, CUT_O8_05, CUT_O8_02, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_08 = BRepBuilderAPI_MakeEdge(arcCurve_08);
	Handle(AIS_Shape) aTarcCurve_08 = new AIS_Shape(TarcCurve_08);
	aTarcCurve_08->SetColor(Quantity_Color(Quantity_NOC_RED));
	myOccView->getContext()->Display(aTarcCurve_08, Standard_True);


	//// 创建 OCC 可视化对象圆 O1
	//Handle(AIS_Shape) aisShape1 = new AIS_Shape(edge1);
	//aisShape1->SetColor(Quantity_NOC_RED); // 设置颜色为红色
	//myOccView->getContext()->Display(aisShape1, Standard_True); // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O2
	//Handle(AIS_Shape) aisShape2 = new AIS_Shape(edge2);
	//aisShape2->SetColor(Quantity_NOC_GREEN); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisShape2, Standard_True); // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象 OP线段
	//Handle(AIS_Shape) aisShapeP = new AIS_Shape(shapeP);
	//aisShapeP->SetColor(Quantity_Color(Quantity_NOC_ORANGE)); // 设置颜色为橙色
	//myOccView->getContext()->Display(aisShapeP, Standard_True); // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O3
	//Handle(AIS_Shape) aisCircle03 = new AIS_Shape(edge03);
	//aisCircle03->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle03, Standard_True); // 在场景中显示直线 
	//// 创建 OCC 可视化对象圆 O4
	//Handle(AIS_Shape) aisCircle4 = new AIS_Shape(edge4);
	//aisCircle4->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle4, Standard_True); // 在场景中显示直线 // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O5
	//Handle(AIS_Shape) aisCircle5 = new AIS_Shape(edge5);
	//aisCircle5->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle5, Standard_True); // 在场景中显示直线 
	//// 创建 OCC 可视化对象圆 O6
	//Handle(AIS_Shape) aisCircle6 = new AIS_Shape(edge6);
	//aisCircle6->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle6, Standard_True); // 在场景中显示直线 // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O7
	//Handle(AIS_Shape) aisCircle7 = new AIS_Shape(edge7);
	//aisCircle7->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle7, Standard_True); // 在场景中显示直线 // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O8
	//Handle(AIS_Shape) aisCircle8 = new AIS_Shape(edge8);
	//aisCircle8->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle8, Standard_True); // 在场景中显示直线 // 在场景中显示可视化对象






	//如果用交点直接确定可使用下方法
	//gp_Pnt centerO7(sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	/////绘制拱墙内侧弧线，已知弧段圆心、起点、半径
	//Standard_Real R_O1 = radius1;//半径
	//gp_Circ Circle_O1_EC(axis1, R_O1);
	//gp_Ax3 AxO1(axis1);
	//gp_Cylinder Cylinder_O1(AxO1, R_O1);//弧线所在圆柱面

	//Handle(Geom_CylindricalSurface) geoCylinder_O1 = new Geom_CylindricalSurface(Cylinder_O1);

	//gp_Pnt CUT_O4_01(-sin(alpha) * radius, -cos(alpha) * radius , 0);
	//gp_Pnt CUT_O7_01(sin(alpha) * radius, -cos(alpha) * radius, 0);

	//Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O1_EC, CUT_O7_01, CUT_O4_01, true);//绘制左侧连接圆弧
	//TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	//Handle(AIS_Shape) aTarcCurve_01 = new AIS_Shape(TarcCurve_01);
	//aTarcCurve_01->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_01, Standard_True);


	//延长线方法——有问题
	//// 定义起点和终点
	//gp_Pnt startPoint6_3(0, 0, 0);
	//gp_Pnt endPoint6_3(-sin(alpha) * (radius2 - radius6), -cos(alpha) * (radius2 - radius6), 0);
	//gp_Vec direction6_3(-sin(alpha) * (radius2 - radius6), -cos(alpha) * (radius2 - radius6), 0);
	//// 使用起点和终点创建一个直线
	//gp_Lin line6_3(startPoint6_3, direction6_3);
	//Handle(Geom_Line) line6_3 = new Geom_Line(startPoint6_3, gp_Vec(startPoint6_3, endPoint6_3));
	//// 使用直线创建一个线段，这个线段由起点和终点限定
	//TopoDS_Edge edge6_3 = BRepBuilderAPI_MakeEdge(line6_3, startPoint6_3, endPoint6_3);
	//// 指定延长的距离
	//double extensionDistance = 50;  // 假设延长50
	//// 计算延长后的终点
	//gp_Pnt extendedEndPoint = endPoint6_3.Translated(gp_Vec(startPoint6_3, endPoint6_3).Normalized() * extensionDistance);
	//// 使用延长后的终点创建一个延长后的线段
	//TopoDS_Edge extendedEdge = BRepBuilderAPI_MakeEdge(line6_3, startPoint6_3, extendedEndPoint);

	// 使用 BRepBuilderAPI_MakeWire 创建闭合曲线
	BRepBuilderAPI_MakeWire EC_WAIwireBuilder;
	EC_WAIwireBuilder.Add(TarcCurve_02);
	EC_WAIwireBuilder.Add(TarcCurve_06);
	EC_WAIwireBuilder.Add(TarcCurve_05);
	EC_WAIwireBuilder.Add(TarcCurve_08);
	EC_WAIwireBuilder.Build();

	if (EC_WAIwireBuilder.IsDone()) {
		TopoDS_Wire EC_WAIclosedWire = EC_WAIwireBuilder.Wire();

		// 现在 closedWire 就是你连接成闭合的连续线
	}
	else {
		// 处理创建失败的情况
	}

	//TopoDS_Wire sectorWirearc = makeWirearc.Wire();
	BRepBuilderAPI_MakeFace EC_WAIFacearc(EC_WAIwireBuilder);
	//TopoDS_Face EC_WAIFacearc = EC_WAIFacearc.Face();
	gp_Vec extrusionVecR1(0, 0, -1000.0); // 沿着 Z 轴方向拉伸 100 个单位

	BRepPrimAPI_MakePrism EC_WAI_makearc1(EC_WAIFacearc, extrusionVecR1);
	TopoDS_Shape EC_WAI_arcShape1 = EC_WAI_makearc1.Shape();
	TopoDS_Solid EC_WAI_arcbody = TopoDS::Solid(EC_WAI_arcShape1);
	Handle(AIS_Shape) EC_WAI_Aisarcbody = new AIS_Shape(EC_WAI_arcbody);


	//EC_WAI_Aisarcbody->SetColor(Quantity_NOC_RED); // 设置颜色为红色
	//myOccView->getContext()->Display(EC_WAI_Aisarcbody, Standard_True); // 在场景中显示可视化对象

	// 使用 BRepBuilderAPI_MakeWire 创建闭合曲线
	BRepBuilderAPI_MakeWire EC_NEIwireBuilder;
	EC_NEIwireBuilder.Add(TarcCurve_01);
	EC_NEIwireBuilder.Add(TarcCurve_04);
	EC_NEIwireBuilder.Add(TarcCurve_07);
	EC_NEIwireBuilder.Add(TarcCurve_03);
	EC_NEIwireBuilder.Build();

	if (EC_NEIwireBuilder.IsDone()) {
		TopoDS_Wire EC_NEIclosedWire = EC_NEIwireBuilder.Wire();

		// 现在 closedWire 就是你连接成闭合的连续线
	}
	else {
		// 处理创建失败的情况
	}

	BRepBuilderAPI_MakeFace EC_NEIFacearc(EC_NEIwireBuilder);

	BRepPrimAPI_MakePrism EC_NEI_makearc1(EC_NEIFacearc, extrusionVecR1);
	TopoDS_Shape EC_NEI_arcShape1 = EC_NEI_makearc1.Shape();
	TopoDS_Solid EC_NEI_arcbody = TopoDS::Solid(EC_NEI_arcShape1);
	Handle(AIS_Shape) EC_NEI_Aisarcbody = new AIS_Shape(EC_NEI_arcbody);

	BRepAlgoAPI_Cut cutOp1(EC_WAI_arcShape1, EC_NEI_arcShape1);
	TopoDS_Shape EC_arcShape = cutOp1.Shape();

	Handle(AIS_Shape) EC_arcShape1 = new AIS_Shape(EC_arcShape);
	EC_arcShape1->SetColor(Quantity_NOC_YELLOW); // 设置颜色为红色
	myOccView->getContext()->Display(EC_arcShape1, Standard_True); // 在场景中显示可视化对象

	secondaryLiningObj.setValue(R2_NLK, radius5, CUT_O6_05.X(), CUT_O6_05.Y(), CUT_O6_05.Z(), alpha, radius6,
		CUT_O4_01.X(), CUT_O4_01.Y(), CUT_O4_01.Z(), CUT_O4_03.X(), CUT_O4_03.Y(), CUT_O4_03.Z(),
		CUT_O7_01.X(), CUT_O7_01.Y(), CUT_O7_01.Z(), CUT_O7_03.X(), CUT_O7_03.Y(), CUT_O7_03.Z(), radius4, pointP3.Y(), R1_NLK, radius3,
		R1_R2_HD, R3_R5_HD, R3_TC, GoucaoKuandu, GoucaoGaocha, JibenKuandu);

	Standard_Real radius_N1_s = 1.1; // 钢筋N1半径
	Standard_Real radius_N2_s = 1.1; // 钢筋N2半径



									 // 确定缩放中心
	gp_Pnt center01_N2(0.0, 0.0, 0.0); // 请替换为实际的中心点

									   // 等比例缩放因子
	Standard_Real scaleFactor01_N2 = (665 + 8.8) / 665; // 扩大

														// 构建缩放变换
	gp_Trsf scaleTransform01_N2;
	scaleTransform01_N2.SetScale(center01_N2, scaleFactor01_N2);
	// 对闭合线圈进行变换
	BRepBuilderAPI_Transform transform01_N2(TarcCurve_01, scaleTransform01_N2, true);
	Handle(AIS_Shape) transform_arcShape01_N2 = new AIS_Shape(transform01_N2);
	transform_arcShape01_N2->SetColor(Quantity_NOC_BLUE); // 设置颜色为红色
	myOccView->getContext()->Display(transform_arcShape01_N2, Standard_True); // 在场景中显示可视化对象





																			  // 构建缩放变换
	gp_Trsf scaleTransform03_N2;
	Standard_Real scaleFactor03_N2 = (1720 + 8.8) / 1720; // 扩大
	scaleTransform03_N2.SetScale(pointP3, scaleFactor03_N2);
	// 对闭合线圈进行变换
	BRepBuilderAPI_Transform transform03_N2(TarcCurve_03, scaleTransform03_N2, true);
	Handle(AIS_Shape) transform_arcShape03_N2 = new AIS_Shape(transform03_N2);
	transform_arcShape03_N2->SetColor(Quantity_NOC_BLUE); // 设置颜色为红色
	myOccView->getContext()->Display(transform_arcShape03_N2, Standard_True); // 在场景中显示可视化对象

																			  // 构建缩放变换
	gp_Trsf scaleTransform04_N2;
	Standard_Real scaleFactor04_N2 = (R_O4 + 8.8) / R_O4; // 扩大
	scaleTransform04_N2.SetScale(centerO4, scaleFactor04_N2);
	// 对闭合线圈进行变换
	BRepBuilderAPI_Transform transform04_N2(TarcCurve_04, scaleTransform04_N2, true);
	Handle(AIS_Shape) transform_arcShape04_N2 = new AIS_Shape(transform04_N2);
	transform_arcShape04_N2->SetColor(Quantity_NOC_BLUE); // 设置颜色为红色
	myOccView->getContext()->Display(transform_arcShape04_N2, Standard_True); // 在场景中显示可视化对象

	gp_Trsf scaleTransform07_N2;
	scaleTransform07_N2.SetScale(centerO7, scaleFactor04_N2);
	// 对闭合线圈进行变换
	BRepBuilderAPI_Transform transform07_N2(TarcCurve_07, scaleTransform07_N2, true);
	Handle(AIS_Shape) transform_arcShape07_N2 = new AIS_Shape(transform07_N2);
	transform_arcShape07_N2->SetColor(Quantity_NOC_BLUE); // 设置颜色为红色
	myOccView->getContext()->Display(transform_arcShape07_N2, Standard_True); // 在场景中显示可视化对象





																			  // 确定缩放中心
	gp_Pnt center02_N1(0.0, 0.0, 0.0); // 请替换为实际的中心点

									   // 等比例缩放因子
	Standard_Real scaleFactor02_N1 = (665 + 55 - 8.8) / (665 + 55); // 扩大

																	// 构建缩放变换
	gp_Trsf scaleTransform02_N1;
	scaleTransform02_N1.SetScale(center02_N1, scaleFactor02_N1);
	// 对闭合线圈进行变换
	BRepBuilderAPI_Transform transform02_N1(TarcCurve_02, scaleTransform02_N1, true);
	Handle(AIS_Shape) transform_arcShape02_N1 = new AIS_Shape(transform02_N1);
	transform_arcShape02_N1->SetColor(Quantity_NOC_BLUE); // 设置颜色为红色
	myOccView->getContext()->Display(transform_arcShape02_N1, Standard_True); // 在场景中显示可视化对象

																			  // 构建缩放变换
	gp_Trsf scaleTransform05_N1;
	Standard_Real scaleFactor05_N1 = (1720 + 65 - 8.8) / (1720 + 65); // 扩大
	scaleTransform05_N1.SetScale(pointP3, scaleFactor05_N1);
	// 对闭合线圈进行变换
	BRepBuilderAPI_Transform transform05_N1(TarcCurve_05, scaleTransform05_N1, true);
	Handle(AIS_Shape) transform_arcShape05_N1 = new AIS_Shape(transform05_N1);
	transform_arcShape05_N1->SetColor(Quantity_NOC_BLUE); // 设置颜色为红色
	myOccView->getContext()->Display(transform_arcShape05_N1, Standard_True); // 在场景中显示可视化对象

																			  // 构建缩放变换
	gp_Trsf scaleTransform06_N1;
	Standard_Real scaleFactor06_N1 = (R_O6 - 8.8) / R_O6;
	scaleTransform06_N1.SetScale(centerO6, scaleFactor06_N1);
	// 对闭合线圈进行变换
	BRepBuilderAPI_Transform transform06_N1(TarcCurve_06, scaleTransform06_N1, true);
	Handle(AIS_Shape) transform_arcShape06_N1 = new AIS_Shape(transform06_N1);
	transform_arcShape06_N1->SetColor(Quantity_NOC_BLUE); // 设置颜色为红色
	myOccView->getContext()->Display(transform_arcShape06_N1, Standard_True); // 在场景中显示可视化对象

	gp_Trsf scaleTransform08_N1;
	scaleTransform08_N1.SetScale(centerO8, scaleFactor06_N1);
	// 对闭合线圈进行变换
	BRepBuilderAPI_Transform transform08_N1(TarcCurve_08, scaleTransform08_N1, true);
	Handle(AIS_Shape) transform_arcShape08_N1 = new AIS_Shape(transform08_N1);
	transform_arcShape08_N1->SetColor(Quantity_NOC_BLUE); // 设置颜色为红色
	myOccView->getContext()->Display(transform_arcShape08_N1, Standard_True); // 在场景中显示可视化对象





																			  //配筋
	gp_Pnt O1_N3_s(0, R1_NLK + 9.9, 0);
	gp_Pnt O2_N3_s(0, R2_NLK - 9.9, 0);
	gp_Dir normal1_s(0, 0, 1);


	Standard_Real radius_N3_s = 0.7; // 钢筋N3半径


	gp_Ax2 axis_N3_1(O1_N3_s, normal1_s);
	gp_Ax2 axis_N3_2(O2_N3_s, normal1_s);

	//建立圆弧线N1和N2
	Handle(Geom_Circle) circle_N3_1 = new Geom_Circle(axis_N3_1, radius_N3_s);
	BRepBuilderAPI_MakeEdge edgeMaker_N3_1(circle_N3_1);
	TopoDS_Edge edge_N3_1 = edgeMaker_N3_1.Edge();
	Handle(Geom_Circle) circle_N3_2 = new Geom_Circle(axis_N3_2, radius_N3_s);
	BRepBuilderAPI_MakeEdge edgeMaker_N3_2(circle_N3_2);
	TopoDS_Edge edge_N3_2 = edgeMaker_N3_2.Edge();

	// 创建线圈N1和N2
	BRepBuilderAPI_MakeWire wireMaker_N3_1(edge_N3_1);
	TopoDS_Wire wire_N3_1 = wireMaker_N3_1.Wire();
	BRepBuilderAPI_MakeWire wireMaker_N3_2(edge_N3_2);
	TopoDS_Wire wire_N3_2 = wireMaker_N3_2.Wire();

	// 创建圆面
	BRepBuilderAPI_MakeFace faceMaker_N3_1(wire_N3_1);
	TopoDS_Face face_N3_1 = faceMaker_N3_1.Face();
	gp_Vec extrusionVec_N3_1(0.0, 0.0, 50); // 沿着 Z 轴方向拉伸 66 个单位
	BRepPrimAPI_MakePrism make_N3_1(face_N3_1, extrusionVec_N3_1);
	TopoDS_Shape Shape_N3_1 = make_N3_1.Shape();

	Handle(AIS_Shape) Shape_N3_11 = new AIS_Shape(Shape_N3_1);
	Shape_N3_11->SetColor(Quantity_NOC_BLUE); // 设置颜色为蓝色
	myOccView->getContext()->Display(Shape_N3_11, Standard_True); // 在场景中显示可视化对象


	// 创建圆面
	BRepBuilderAPI_MakeFace faceMaker_N3_2(wire_N3_2);
	TopoDS_Face face_N3_2 = faceMaker_N3_2.Face();
	gp_Vec extrusionVec_N3_2(0.0, 0.0, 50); // 沿着 Z 轴方向拉伸 66 个单位
	BRepPrimAPI_MakePrism make_N3_2(face_N3_2, extrusionVec_N3_2);
	TopoDS_Shape Shape_N3_2 = make_N3_2.Shape();







	gp_Ax1 arcAxis(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(0.0, 0.0, 1.0)); // 圆弧的轴线
	gp_Pnt arcCenter(0.0, 0.0, 0.0); // 圆弧的中心点
	Standard_Real startAngleDeg = -108; // 起始角度
	Standard_Real endAngleDeg = 108.0; // 结束角度
	Standard_Real angleIncrementDeg = 15.0; // 角度间隔





											// 确定缩放中心
	gp_Pnt center01_N3(0.0, 0.0, 0.0); // 请替换为实际的中心点

									   // 等比例缩放因子
	Standard_Real scaleFactor01_N3 = (665 + 9.9) / 665; // 扩大
														// 构建缩放变换
	gp_Trsf scaleTransform01_N3;
	scaleTransform01_N3.SetScale(center01_N3, scaleFactor01_N3);
	// 对闭合线圈进行变换
	BRepBuilderAPI_Transform transform01_N3(TarcCurve_01, scaleTransform01_N3, true);
	//Handle(AIS_Shape) transform_arcShape01_N3 = new AIS_Shape(transform01_N3);
	TopoDS_Shape arcShape01_N3 = transform01_N3.Shape();



	//求取左侧弧段弧度
	double hudu_N4 = M_PI - (alpha*M_PI / 180);
	double startAngleSW = M_PI / 2 + 1e-12; // 起始角度
	double endAngleSW = startAngleSW + hudu_N4; // 终止角度，转换成弧度
	double angleIncrementSW = R1_R2_HD / (R1_NLK + 9.9 + R1_R2_HD / 2); // 角度增量
																		//均匀分布
																		//均匀分布拱墙锚杆
	Standard_Integer numPointsSW = static_cast<Standard_Integer>((endAngleSW - startAngleSW) / angleIncrementSW) + 1;// 计算需要创建的点的数量
	TColgp_Array1OfPnt archAnchPointsSW(1, numPointsSW);// 创建数组以存储点
	Standard_Real currentAngleSW = startAngleSW;// 初始化参数
												// 在弧段 a 上均匀分布点并存储它们
												//std::vector<TopoDS_Edge> edges_Bolt;//存储锚杆
	TopoDS_Compound compoundSW;// 创建一个数据结构来储存线段
	BRep_Builder builderSW;
	builderSW.MakeCompound(compoundSW);
	//for (Standard_Integer i = 1; i <= numPointsSW; ++i) {
	for (Standard_Integer i = 1; i <= 25; ++i) {
		// 使用参数来计算点的位置
		gp_Dir dLArcBoltiSW(1, tan(currentAngleSW), 0);
		gp_Lin LArcBoltiSW(P_CO1_NLK, dLArcBoltiSW);
		Handle(Geom_Line) geomLArcBoltiSW = new Geom_Line(LArcBoltiSW);//弧段锚杆起点与圆心所在直线LArcBolti

		GeomAPI_IntCS ICS_ArcBoltiSW(geomLArcBoltiSW, geoCylinder_O1);//直线LArcBolt与初衬外轮廓所在圆柱面求交
		gp_Pnt Inter1_ArcBoltiSW = ICS_ArcBoltiSW.Point(1);//获取交点1
		gp_Pnt Inter2_ArcBoltiSW = ICS_ArcBoltiSW.Point(2);//获取交点2
		gp_Pnt Inter_ArcBoltiSW;
		Inter_ArcBoltiSW.SetX(Inter1_ArcBoltiSW.X());
		Inter_ArcBoltiSW.SetY(Inter1_ArcBoltiSW.Y());
		if (Inter1_ArcBoltiSW.X()>0) {
			Inter_ArcBoltiSW.SetX(Inter2_ArcBoltiSW.X());
			Inter_ArcBoltiSW.SetY(Inter2_ArcBoltiSW.Y());
		}//获得右侧起点
		archAnchPointsSW(i) = Inter_ArcBoltiSW;
		// 绘制该点处的锚杆
		double lBolt = R1_R2_HD; // 锚杆长度
		gp_Vec VLineBoltSW(1.0, tan(currentAngleSW), 0.0); // 锚杆方向
		gp_Pnt EndPofLineBoltSW(archAnchPointsSW(i).X() + lBolt*cos(currentAngleSW), archAnchPointsSW(i).Y() + lBolt*sin(currentAngleSW), 0.0); // 端点
		TopoDS_Edge arcBoltSW = BRepBuilderAPI_MakeEdge(EndPofLineBoltSW, archAnchPointsSW(i));//得到锚杆轮廓


		builder.Add(compoundSW, arcBoltSW);
		// 增加角度以移动到下一个点
		currentAngleSW += angleIncrementSW;
	}
	Handle(AIS_Shape) AiscompoundSW = new AIS_Shape(compoundSW);
	AiscompoundSW->SetColor(Quantity_NOC_YELLOW);
	//Aiscompound5->SetTransparency(0.5);
	myOccView->getContext()->Display(AiscompoundSW, Standard_True);//绘制左侧拱墙锚杆

																   // 对称获得右侧边墙锚杆
	gp_Trsf symmetryTransformSW;
	symmetryTransformSW.SetMirror(gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(1, 0, 0))); // 以Y轴为镜像轴进行对称
	BRepBuilderAPI_Transform transformOpSW(compoundSW, symmetryTransformSW); // 对线段进行对称变换
	transformOpSW.Build();
	TopoDS_Compound symmetricCompoundSW = TopoDS::Compound(transformOpSW.Shape());
	Handle(AIS_Shape) AissymmetricCompoundSW = new AIS_Shape(symmetricCompoundSW);//显示右侧边墙锚杆
	AissymmetricCompoundSW->SetColor(Quantity_NOC_YELLOW);
	myOccView->getContext()->Display(AissymmetricCompoundSW, Standard_True);





	gp_Pnt startPointN6_3(0, -R3_TC - GoucaoGaocha - height - 9.9, 0);
	gp_Pnt startPointN6_5(0, -R3_TC - GoucaoGaocha - height - 9.9 - R3_R5_HD, 0);
	// 使用起点和方向创建直线
	gp_Vec directionN6(startPointN6_3, startPointN6_5);
	gp_Lin lineN6(startPointN6_3, directionN6);
	// 创建直线的线段
	TopoDS_Edge lineEdgeN6 = BRepBuilderAPI_MakeEdge(lineN6, startPointN6_3, startPointN6_5);
	Handle(Geom_Line) Geom_lineEdgeN6 = new Geom_Line(lineN6);
	Handle(AIS_Shape) aisShapeN6 = new AIS_Shape(lineEdgeN6);
	aisShapeN6->SetColor(Quantity_NOC_YELLOW); // 设置颜色为红色
	myOccView->getContext()->Display(aisShapeN6, Standard_True); // 在场景中显示可视化对象


																 //double hudu_N6 = atan((sin(alpha)*radius)/ (radius3 - R3_TC - GoucaoGaocha) )*M_PI / 180;
																 //double hudu_N6 = 0.5;
	double startAngleSW_N6 = -(M_PI / 2) - 1e-12; // 起始角度
												  //double endAngleSW_N6 = startAngleSW_N6 - hudu_N6; // 终止角度，转换成弧度
	double endAngleSW_N6 = -M_PI - 0.6*M_PI; // 终止角度，转换成弧度
	double angleIncrementSW_N6 = R3_R5_HD / (radius3 + 9.9 + R3_R5_HD / 2); // 角度增量
																			//均匀分布
																			//均匀分布拱墙锚杆
	Standard_Integer numPointsSW_N6 = static_cast<Standard_Integer>((-endAngleSW_N6 + startAngleSW_N6) / angleIncrementSW_N6) + 1;// 计算需要创建的点的数量
	TColgp_Array1OfPnt archAnchPointsSW_N6(1, numPointsSW_N6);// 创建数组以存储点
	Standard_Real currentAngleSW_N6 = startAngleSW_N6;// 初始化参数
													  // 在弧段 a 上均匀分布点并存储它们
													  //std::vector<TopoDS_Edge> edges_Bolt;//存储锚杆
	TopoDS_Compound compoundSW_N6;// 创建一个数据结构来储存线段
	BRep_Builder builderSW_N6;
	builderSW.MakeCompound(compoundSW_N6);
	//for (Standard_Integer i = 1; i <= numPointsSW_N6; ++i) {
	for (Standard_Integer i = 1; i <= 8; ++i) {
		// 使用参数来计算点的位置
		gp_Dir dLArcBoltiSW_N6(1, tan(currentAngleSW_N6), 0);
		gp_Lin LArcBoltiSW_N6(pointP3, dLArcBoltiSW_N6);
		Handle(Geom_Line) geomLArcBoltiSW_N6 = new Geom_Line(LArcBoltiSW_N6);//弧段锚杆起点与圆心所在直线LArcBolti

		GeomAPI_IntCS ICS_ArcBoltiSW_N6(geomLArcBoltiSW_N6, geoCylinder_O3);//直线LArcBolt与初衬外轮廓所在圆柱面求交
		gp_Pnt Inter1_ArcBoltiSW_N6 = ICS_ArcBoltiSW_N6.Point(1);//获取交点1
		gp_Pnt Inter2_ArcBoltiSW_N6 = ICS_ArcBoltiSW_N6.Point(2);//获取交点2
		gp_Pnt Inter_ArcBoltiSW_N6;
		Inter_ArcBoltiSW_N6.SetX(Inter1_ArcBoltiSW_N6.X());
		Inter_ArcBoltiSW_N6.SetY(Inter1_ArcBoltiSW_N6.Y());
		if (Inter1_ArcBoltiSW_N6.X()<0) {
			Inter_ArcBoltiSW_N6.SetX(Inter2_ArcBoltiSW_N6.X());
			Inter_ArcBoltiSW_N6.SetY(Inter2_ArcBoltiSW_N6.Y());
		}//获得右侧起点
		archAnchPointsSW_N6(i) = Inter_ArcBoltiSW_N6;
		// 绘制该点处的锚杆
		double lBolt = R3_R5_HD; // 锚杆长度
		gp_Vec VLineBoltSW_N6(1.0, tan(currentAngleSW_N6), 0.0); // 锚杆方向
		gp_Pnt EndPofLineBoltSW_N6(archAnchPointsSW_N6(i).X() + lBolt*cos(currentAngleSW_N6), archAnchPointsSW_N6(i).Y() + lBolt*sin(currentAngleSW_N6), 0.0); // 端点
		TopoDS_Edge arcBoltSW_N6 = BRepBuilderAPI_MakeEdge(EndPofLineBoltSW_N6, archAnchPointsSW_N6(i));//得到锚杆轮廓


		builder.Add(compoundSW_N6, arcBoltSW_N6);
		// 增加角度以移动到下一个点
		currentAngleSW_N6 += angleIncrementSW_N6;
	}
	Handle(AIS_Shape) AiscompoundSW_N6 = new AIS_Shape(compoundSW_N6);
	AiscompoundSW_N6->SetColor(Quantity_NOC_YELLOW);
	//Aiscompound5->SetTransparency(0.5);
	myOccView->getContext()->Display(AiscompoundSW_N6, Standard_True);//绘制左侧拱墙锚杆

																	  // 对称获得右侧边墙锚杆
	gp_Trsf symmetryTransformSW_N6;
	symmetryTransformSW_N6.SetMirror(gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(1, 0, 0))); // 以Y轴为镜像轴进行对称
	BRepBuilderAPI_Transform transformOpSW_N6(compoundSW_N6, symmetryTransformSW_N6); // 对线段进行对称变换
	transformOpSW_N6.Build();
	TopoDS_Compound symmetricCompoundSW_N6 = TopoDS::Compound(transformOpSW_N6.Shape());
	Handle(AIS_Shape) AissymmetricCompoundSW_N6 = new AIS_Shape(symmetricCompoundSW_N6);//显示右侧边墙锚杆
	AissymmetricCompoundSW_N6->SetColor(Quantity_NOC_YELLOW);
	myOccView->getContext()->Display(AissymmetricCompoundSW_N6, Standard_True);








	gp_Vec startVector71(centerO4, CUT_O4_01);
	gp_Vec endVector71(centerO4, CUT_O4_03);
	Standard_Real startAngle71 = startVector71.Angle(endVector71);
	Standard_Real endAngle71 = 0.0; // 终止角度从0度开始



	Standard_Real XianLength71 = Sqrt(pow(CUT_O4_01.X() - CUT_O4_03.X(), 2) + pow(CUT_O4_03.Y() - CUT_O4_01.Y(), 2));
	Standard_Real XianLength71_shang = Sqrt(pow(centerO4.X() - radius4 - CUT_O4_01.X(), 2) + pow(CUT_O4_01.Y() - centerO4.Y(), 2));
	Standard_Real XianLength71_xia = Sqrt(pow(CUT_O4_03.X() - centerO4.X(), 2) + pow(centerO4.Y() - radius4 - CUT_O4_03.Y(), 2));

	// 计算圆弧圆心角
	Standard_Real Yuanxinjiao71 = 2 * asin(XianLength71 / (2 * radius4));
	Standard_Real Yuanxinjiao71_shang = 2 * asin(XianLength71_shang / (2 * radius4));
	Standard_Real Yuanxinjiao71_xia = 2 * asin(XianLength71_xia / (2 * radius4));
	// 计算圆弧的总弧长
	//Standard_Real arcLength71 = radius4 * (startAngle71 - endAngle71);
	Standard_Real arcLength71 = Yuanxinjiao71*radius4;

	// 指定弧长间隔
	Standard_Real arcLengthInterval71 = 48; // 假设弧长间隔为5.0

	Standard_Real Yuanxinjiao71_jiange = 2 * asin(arcLengthInterval71 / (2 * radius4));


	// 计算点的数量
	Standard_Integer numPoints71 = static_cast<Standard_Integer>(arcLength71 / arcLengthInterval71) + 1;
	//Standard_Integer numPoints71 = static_cast<Standard_Integer>(Yuanxinjiao71 / Yuanxinjiao71_jiange) + 1;

	// 存储点的数组
	std::vector<gp_Pnt> points_N71;


	// 生成点并存储到数组中
	for (Standard_Integer i = 0; i < numPoints71; ++i) {
		Standard_Real currentArcAngle71 = i * Yuanxinjiao71_jiange;
		Standard_Real currentAngle71_1 = Yuanxinjiao71_shang + i * Yuanxinjiao71_jiange;
		Standard_Real currentAngle71 = currentAngle71_1 / 2;
		Standard_Real x071_1 = sin(currentAngle71);
		Standard_Real x071_2 = cos(currentAngle71);
		//Standard_Real currentAngle71 = startAngle71 - arcLengthInterval71 / radius4;
		//gp_Pnt point(centerO4.X() - radius4 * cos(currentAngle71), centerO4.Y() - radius4 * sin(currentAngle71), centerO4.Z());
		gp_Pnt point(centerO4.X() - radius4 + (2 * radius4*x071_1*x071_1), centerO4.Y() - (2 * radius4*x071_1*x071_2), centerO4.Z());
		points_N71.push_back(point);
	}




	// 打印点的名称和坐标
	for (Standard_Integer i = 0; i < numPoints71; ++i) {
		std::string pointName = "N71_" + std::to_string(i + 1);
		gp_Pnt point = points_N71[i];
		std::cout << pointName << ": (" << point.X() << ", " << point.Y() << ", " << point.Z() << ")" << std::endl;
	}







	gp_Vec startVector72(centerO6, CUT_O6_02);
	gp_Vec endVector72(centerO6, CUT_O6_05);
	Standard_Real startAngle72 = startVector72.Angle(endVector72);
	Standard_Real endAngle72 = 0.0; // 终止角度从0度开始

									//								// 计算圆弧的总弧长
									//Standard_Real arcLength72 = radius6 * (startAngle72 - endAngle72);
									//
									//// 指定弧长间隔
									//Standard_Real arcLengthInterval72 = 60; // 假设弧长间隔为5.0
									//
									//										// 计算点的数量
									//Standard_Integer numPoints72 = static_cast<Standard_Integer>(arcLength72 / arcLengthInterval72) + 1;





	Standard_Real XianLength72 = Sqrt(pow(CUT_O6_02.X() - CUT_O6_05.X(), 2) + pow(CUT_O6_05.Y() - CUT_O6_02.Y(), 2));
	Standard_Real XianLength72_shang = Sqrt(pow(centerO6.X() - radius6 - CUT_O6_02.X(), 2) + pow(CUT_O6_02.Y() - centerO6.Y(), 2));
	Standard_Real XianLength72_xia = Sqrt(pow(CUT_O6_05.X() - centerO6.X(), 2) + pow(centerO6.Y() - radius6 - CUT_O6_05.Y(), 2));

	// 计算圆弧圆心角
	Standard_Real Yuanxinjiao72 = 2 * asin(XianLength72 / (2 * radius6));
	Standard_Real Yuanxinjiao72_shang = 2 * asin(XianLength72_shang / (2 * radius6));
	Standard_Real Yuanxinjiao72_xia = 2 * asin(XianLength72_xia / (2 * radius6));
	// 计算圆弧的总弧长
	//Standard_Real arcLength71 = radius4 * (startAngle71 - endAngle71);
	//Standard_Real arcLength72 = PI * Yuanxinjiao72*radius6 / 180;
	Standard_Real arcLength72 = Yuanxinjiao72*radius6;
	// 指定弧长间隔
	Standard_Real arcLengthInterval72 = 60; // 假设弧长间隔为5.0

	Standard_Real Yuanxinjiao72_jiange = 2 * asin(arcLengthInterval72 / (2 * radius6));


	// 计算点的数量
	Standard_Integer numPoints72 = static_cast<Standard_Integer>(arcLength72 / arcLengthInterval72) + 1;
	//Standard_Integer numPoints72 = static_cast<Standard_Integer>(Yuanxinjiao72 / Yuanxinjiao72_jiange) + 1;

	// 存储点的数组
	std::vector<gp_Pnt> points_N72;

	//// 生成点并存储到数组中
	//for (Standard_Integer i = 0; i < numPoints72; ++i) {
	//	Standard_Real currentArcLength72 = i * arcLengthInterval72;
	//	Standard_Real currentAngle72 = startAngle72 - currentArcLength72 / radius6;
	//	gp_Pnt point(centerO6.X() - radius6 * cos(currentAngle72), centerO6.Y() - radius6 * sin(currentAngle72), centerO6.Z());
	//	points_N72.push_back(point);
	//}
	// 生成点并存储到数组中
	for (Standard_Integer i = 0; i < numPoints72; ++i) {
		Standard_Real currentArcAngle72 = i * Yuanxinjiao72_jiange;
		Standard_Real currentAngle72_1 = Yuanxinjiao72_shang + currentArcAngle72;
		////Standard_Real currentAngle71 = startAngle71 - arcLengthInterval71 / radius4;
		////gp_Pnt point(centerO4.X() - radius4 * cos(currentAngle71), centerO4.Y() - radius4 * sin(currentAngle71), centerO4.Z());
		//gp_Pnt point(centerO6.X() - radius6 + (2 * radius6*sin(currentAngle72/2)*sin(currentAngle72 / 2)), centerO6.Y() - (2 * radius6*sin(currentAngle72 / 2)*cos(currentAngle72 / 2)), centerO6.Z());
		//points_N72.push_back(point);

		Standard_Real currentAngle72 = currentAngle72_1 / 2;
		Standard_Real x072_1 = sin(currentAngle72);
		Standard_Real x072_2 = cos(currentAngle72);
		//Standard_Real currentAngle71 = startAngle71 - arcLengthInterval71 / radius4;
		//gp_Pnt point(centerO4.X() - radius4 * cos(currentAngle71), centerO4.Y() - radius4 * sin(currentAngle71), centerO4.Z());
		gp_Pnt point(centerO6.X() - radius6 + (2 * radius6*x072_1*x072_1), centerO6.Y() - (2 * radius6*x072_1*x072_2), centerO4.Z());
		points_N72.push_back(point);
	}






	// 打印点的名称和坐标
	for (Standard_Integer i = 0; i < numPoints72; ++i) {
		std::string pointName = "N72_" + std::to_string(i + 1);
		gp_Pnt point = points_N72[i];
		std::cout << pointName << ": (" << point.X() << ", " << point.Y() << ", " << point.Z() << ")" << std::endl;
	}


	// 创建线段集合
	TopoDS_Compound lineSegmentCompound;
	BRep_Builder lineSegmentBuilder;
	lineSegmentBuilder.MakeCompound(lineSegmentCompound);

	// 假设两个数组的大小相同
	if (points_N71.size() == points_N72.size()) {
		for (size_t i = 0; i < points_N71.size(); ++i) {
			// 创建线段
			TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(points_N71[i], points_N72[i]);

			// 将线段添加到线段集合中
			lineSegmentBuilder.Add(lineSegmentCompound, edge);
		}
	}

	// 创建一个AIS_Shape用于显示线段集合
	Handle(AIS_Shape) lineSegmentShape = new AIS_Shape(lineSegmentCompound);
	lineSegmentShape->SetColor(Quantity_NOC_GREEN); // 设置线段颜色

													// 获取AIS上下文
	Handle(AIS_InteractiveContext) context = myOccView->getContext(); // 假设已有myOccView

																	  // 显示线段集合
	context->Display(lineSegmentShape, Standard_True);


	gp_Trsf symmetryTransformSW_N7;
	symmetryTransformSW_N7.SetMirror(gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(1, 0, 0))); // 以Y轴为镜像轴进行对称
	BRepBuilderAPI_Transform transformOpSW_N7(lineSegmentCompound, symmetryTransformSW_N7); // 对线段进行对称变换
	transformOpSW_N7.Build();
	TopoDS_Compound symmetricCompoundSW_N7 = TopoDS::Compound(transformOpSW_N7.Shape());
	Handle(AIS_Shape) AissymmetricCompoundSW_N7 = new AIS_Shape(symmetricCompoundSW_N7);//显示右侧边墙锚杆
	AissymmetricCompoundSW_N7->SetColor(Quantity_NOC_GREEN);
	myOccView->getContext()->Display(AissymmetricCompoundSW_N7, Standard_True);

}

void MainWindow::showInvertedBrim(const InvertedBrim2& coords)
{
	makeInvertedBrim2(coords);
	makeInvertedBrim3(coords);
};

TopoDS_Shape MainWindow::draw_cone(double radius_top, double radius_bottom, double height)
{
	// 绘制圆台
	gp_Pnt top_center(0, 0, height);
	gp_Pnt bottom_center(0, 0, 0);

	gp_Ax2 top_axis(top_center, gp::DZ());
	gp_Ax2 bottom_axis(bottom_center, gp::DZ());

	gp_Circ top_circle(top_axis, radius_top);
	gp_Circ bottom_circle(bottom_axis, radius_bottom);

	BRepPrimAPI_MakeCone cone_maker(radius_bottom, radius_top, height);
	cone_maker.Build();

	TopoDS_Shape cone_shape = cone_maker.Shape();

	return cone_shape;
}

void MainWindow::makeInvertedBrim(const InvertedBrim2& coords) {
	// 绘制第一个圆台
	double radius_top_1 = 735;
	double radius_bottom_1 = 835;
	double height_1 = 600;

	TopoDS_Shape cone_shape_1 = draw_cone(radius_top_1, radius_bottom_1, height_1);

	// 绘制第二个圆台
	double radius_top_2 = 665;
	double radius_bottom_2 = 765;
	double height_2 = 600;

	TopoDS_Shape cone_shape_2 = draw_cone(radius_top_2, radius_bottom_2, height_2);

	// 使用 BRepAlgoAPI_Cut 函数将两个圆台的重叠部分移除
	BRepAlgoAPI_Cut cut_operator(cone_shape_1, cone_shape_2);
	cut_operator.Build();

	TopoDS_Shape result_shape = cut_operator.Shape();

	// 定义四个点
	gp_Pnt p0(835, -213, 0);
	gp_Pnt p1(-835, -213, 0);
	gp_Pnt p2(-835, -213, 600);
	gp_Pnt p3(835, -213, 600);

	// 创建四边形面
	TopoDS_Vertex v0 = BRepBuilderAPI_MakeVertex(p0);
	TopoDS_Vertex v1 = BRepBuilderAPI_MakeVertex(p1);
	TopoDS_Vertex v2 = BRepBuilderAPI_MakeVertex(p2);
	TopoDS_Vertex v3 = BRepBuilderAPI_MakeVertex(p3);

	TopoDS_Wire wire = BRepBuilderAPI_MakePolygon(v0, v1, v2, v3, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				  // 创建面
	BRepBuilderAPI_MakeFace face(wire);

	// 定义拉伸向量
	gp_Vec heightVec(0, -900, 0);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker(face.Shape(), heightVec);
	TopoDS_Shape prismShape = prismMaker.Shape();


	// 使用 BRepAlgoAPI_Cut 进行裁剪操作
	BRepAlgoAPI_Cut cut_operator2(result_shape, prismShape);
	cut_operator2.Build();
	TopoDS_Shape final_shape1 = cut_operator2.Shape();

	//// 将结果显示在视图中
	//myOccView->getContext()->Display(new AIS_Shape(final_shape1), Standard_True);


	// 定义四个顶点
	gp_Pnt p7(-835, -213, 300);
	gp_Pnt p4(835, -213, 300);
	gp_Pnt p5(835, 835, 0);
	gp_Pnt p6(-835, 835, 0);

	// 创建四边形面
	TopoDS_Vertex v7 = BRepBuilderAPI_MakeVertex(p7);
	TopoDS_Vertex v4 = BRepBuilderAPI_MakeVertex(p4);
	TopoDS_Vertex v5 = BRepBuilderAPI_MakeVertex(p5);
	TopoDS_Vertex v6 = BRepBuilderAPI_MakeVertex(p6);

	TopoDS_Wire wire1 = BRepBuilderAPI_MakePolygon(v7, v4, v5, v6, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				   // 创建面
	BRepBuilderAPI_MakeFace face1(wire1);

	// 定义拉伸向量
	gp_Vec heightVec1(0, 0, -600);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker1(face1.Shape(), heightVec1);
	TopoDS_Shape prismShape1 = prismMaker1.Shape();

	//使用 BRepAlgoAPI_Cut 进行裁剪操作
	BRepAlgoAPI_Cut cut_operator3(final_shape1, prismShape1);
	cut_operator3.Build();
	TopoDS_Shape final_shape2 = cut_operator3.Shape();

	//将结果显示在视图中
	myOccView->getContext()->Display(new AIS_Shape(final_shape2), Standard_True);




	// 定义4个顶点
	gp_Pnt pA(-640, -213, 600);
	gp_Pnt pB(-700, -213, 600);
	gp_Pnt pC(-700, -413, 600);
	gp_Pnt pD(-508, -413, 600);


	// 创建四边形面ABCD
	TopoDS_Vertex vA = BRepBuilderAPI_MakeVertex(pA);
	TopoDS_Vertex vB = BRepBuilderAPI_MakeVertex(pB);
	TopoDS_Vertex vC = BRepBuilderAPI_MakeVertex(pC);
	TopoDS_Vertex vD = BRepBuilderAPI_MakeVertex(pD);

	TopoDS_Wire wire2 = BRepBuilderAPI_MakePolygon(vA, vB, vC, vD, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形
																				   // 创建面
	BRepBuilderAPI_MakeFace face2(wire2);

	// 定义拉伸向量
	gp_Vec heightVec2(0, 0, -300);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker2(face2.Shape(), heightVec2);
	TopoDS_Shape prismShape2 = prismMaker2.Shape();

	//将结果显示在视图中
	myOccView->getContext()->Display(new AIS_Shape(prismShape2), Standard_True);


	// 定义3个顶点
	gp_Pnt pB1(-700, -213, 600);
	gp_Pnt pE(-700, -213, 300);
	gp_Pnt pF(-750, -213, 300);

	// 创建三角形面B1EF
	TopoDS_Vertex vB1 = BRepBuilderAPI_MakeVertex(pB1);
	TopoDS_Vertex vE = BRepBuilderAPI_MakeVertex(pE);
	TopoDS_Vertex vF = BRepBuilderAPI_MakeVertex(pF);

	TopoDS_Wire wire3 = BRepBuilderAPI_MakePolygon(vB1, vE, vF, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				// 创建面
	BRepBuilderAPI_MakeFace face3(wire3);

	// 定义拉伸向量
	gp_Vec heightVec3(0, -200, 0);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker3(face3.Shape(), heightVec3);
	TopoDS_Shape prismShape3 = prismMaker3.Shape();

	//将结果显示在视图中
	myOccView->getContext()->Display(new AIS_Shape(prismShape3), Standard_True);




	//// 定义4个顶点
	gp_Pnt pa(640, -213, 600);
	gp_Pnt pb(700, -213, 600);
	gp_Pnt pc(700, -413, 600);
	gp_Pnt pd(508, -413, 600);


	// 创建四边形面ABCD
	TopoDS_Vertex va = BRepBuilderAPI_MakeVertex(pa);
	TopoDS_Vertex vb = BRepBuilderAPI_MakeVertex(pb);
	TopoDS_Vertex vc = BRepBuilderAPI_MakeVertex(pc);
	TopoDS_Vertex vd = BRepBuilderAPI_MakeVertex(pd);

	TopoDS_Wire wire4 = BRepBuilderAPI_MakePolygon(va, vb, vc, vd, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				   // 创建面
	BRepBuilderAPI_MakeFace face4(wire4);

	// 定义拉伸向量
	gp_Vec heightVec4(0, 0, -300);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker4(face4.Shape(), heightVec4);
	TopoDS_Shape prismShape4 = prismMaker4.Shape();

	//将结果显示在视图中
	myOccView->getContext()->Display(new AIS_Shape(prismShape4), Standard_True);


	//// 定义3个顶点
	gp_Pnt pb1(700, -213, 600);
	gp_Pnt pe(700, -213, 300);
	gp_Pnt pf(750, -213, 300);

	// 创建三角形面B1EF
	TopoDS_Vertex vb1 = BRepBuilderAPI_MakeVertex(pb1);
	TopoDS_Vertex ve = BRepBuilderAPI_MakeVertex(pe);
	TopoDS_Vertex vf = BRepBuilderAPI_MakeVertex(pf);

	TopoDS_Wire wire5 = BRepBuilderAPI_MakePolygon(vb1, ve, vf, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				// 创建面
	BRepBuilderAPI_MakeFace face5(wire5);

	// 定义拉伸向量
	gp_Vec heightVec5(0, -200, 0);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker5(face5.Shape(), heightVec5);
	TopoDS_Shape prismShape5 = prismMaker5.Shape();
	//将结果显示在视图中
	myOccView->getContext()->Display(new AIS_Shape(prismShape5), Standard_True);
}



gp_Vec GetUnitDirectionVector(const gp_Pnt& startPoint, const gp_Pnt& endPoint) {
	// 计算方向向量
	gp_Vec directionVector(startPoint, endPoint);

	// 单位化方向向量
	directionVector.Normalize();

	return directionVector;
}

TopoDS_Edge MoveLineInPolarCoordinates(const gp_Pnt& originalstaertPoint, Standard_Real angleIncrementDeg, Standard_Real radius)
{

	gp_Pnt P_1_NLK(0.0, 0.0, 600.0); // 原点为圆心
	gp_Ax2 axis_1(P_1_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向

												   // 已知固定长度
	Standard_Real extensionDistance = 600.0; // 延长的距离


	gp_Dir direction = GetUnitDirectionVector(P_1_NLK, originalstaertPoint);

	// 当前角度（假设原始直线方向与 X 轴的夹角）
	Standard_Real currentAngleRad = atan2(direction.Y(), direction.X());

	Standard_Real newAngleRad = currentAngleRad + angleIncrementDeg;

	// 计算新的方向向量
	gp_Dir newDirection(cos(newAngleRad), sin(newAngleRad), 0.0);


	// 计算新的终点
	gp_Pnt newendPoint = newDirection.XYZ() * radius;


	gp_Vec extensionVector(0.0, 0.0, extensionDistance);

	// 创建新的点
	gp_Pnt extendedPoint = newendPoint.Translated(extensionVector);

	BRepBuilderAPI_MakeEdge edgeBuilder(newendPoint, extendedPoint);
	TopoDS_Edge extendedEdge = edgeBuilder.Edge();

	return extendedEdge;
}



void MainWindow::makeInvertedBrim3(const InvertedBrim2& coords)
{
	// 创建圆 O1  拱部内侧，665半径 
	gp_Pnt P_CO1_NLK(0.0, 0.0, 0.0); // 原点为圆心
	gp_Ax2 axis1(P_CO1_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real R1_NLK = 665.0; // 定义圆的半径
	gp_Circ CO1_NLK(axis1, R1_NLK);
	Handle(Geom_Circle) geomCircle1_NLK = new Geom_Circle(CO1_NLK);
	TopoDS_Edge edge1_NLK = BRepBuilderAPI_MakeEdge(geomCircle1_NLK);

	// 创建原点的中垂线
	BRepBuilderAPI_MakeEdge edge(gp_Pnt(0, -1000, 0), gp_Pnt(0, 1000, 0));
	TopoDS_Shape shape3 = edge.Shape();
	// 计算圆心到点 P 的距离 盖板距离线段
	Standard_Real radius = 665.0;
	Standard_Real radius3 = 1720; // 圆O3的半径
	Standard_Real height = sqrt(pow(radius, 2) - pow(630, 2));
	Standard_Real distanceCenterToP = sqrt(pow(radius, 2) + pow(630, 2)) - radius;
	gp_Pnt pointP(0, -height, 0);

	//// 计算圆心到点 P 的距离 盖板距离线段
	//Standard_Real R1_NLK = 665.0;
	//Standard_Real R3_NLK = 1720; // 圆O3的半径
	//Standard_Real height = sqrt(pow(R1_NLK, 2) - pow(630, 2));
	//Standard_Real distanceCenterToP = sqrt(pow(R1_NLK, 2) + pow(630, 2)) - R1_NLK;
	//gp_Pnt pointP(0, -height, 0);

	// 确定新的圆心 P3  仰拱圆心
	gp_Pnt pointP3(0, 1720 - 180 - 30 - height, 0);//180和30会改变！！！

												   // // 确定新的圆心 P3  仰拱圆心
												   //gp_Pnt P_CO3_NLK(0, 1720 - 180 - 30 - height, 0);//180和30会改变！！！

												   //计算角度 alpha  确定过渡段圆半径用参数
	Standard_Real alpha = acos(-pointP.Y() / radius);
	////计算角度 alpha  确定过渡段圆半径用参数
	//Standard_Real alpha = acos(-pointP.Y() / R1_NLK);
	// 创建圆心到点 P 的线段
	BRepBuilderAPI_MakeEdge edgeP(gp_Pnt(0, 0, 0), pointP);
	TopoDS_Shape shapeP = edgeP.Shape();

	// 创建圆 O3  仰拱内侧圆
	gp_Ax2 axis03(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
												   //											   // 创建圆 O3  仰拱内侧圆
												   //gp_Ax2 axis03(P_CO3_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real radius03 = 1720.0; // 半径为 1720cm
	gp_Circ circle03(axis03, radius03);
	Handle(Geom_Circle) geomCircle03 = new Geom_Circle(circle03);
	TopoDS_Edge edge03 = BRepBuilderAPI_MakeEdge(geomCircle03);
	//Standard_Real R3_NLK = 1720.0; // 半径为 1720cm
	//gp_Circ circle03(axis03, R3_NLK);
	//Handle(Geom_Circle) geomCO3_NLK = new Geom_Circle(CO3_NLK);
	//TopoDS_Edge edgeO3_NLK = BRepBuilderAPI_MakeEdge(geomCO3_NLK);

	//计算radius4  内侧过渡段圆半径
	Standard_Real m = pow(radius3, 2) - pow(radius, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*height;
	Standard_Real n = radius3 - radius - pointP3.Y() *height / radius;
	Standard_Real radius4 = m / (2 * n);
	// 创建圆 O4  过渡段内侧圆  左侧
	gp_Pnt centerO4(-sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle4(axis4, radius4);
	Handle(Geom_Circle) geomCircle4 = new Geom_Circle(circle4);
	TopoDS_Edge edge4 = BRepBuilderAPI_MakeEdge(geomCircle4);

	////计算radius4  内侧过渡段圆半径
	//Standard_Real m = pow(R3_NLK, 2) - pow(R1_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*height;
	//Standard_Real n = R3_NLK - R1_NLK - P_CO3_NLK.Y() *height / R1_NLK;
	//Standard_Real R4_NLK = m / (2 * n);
	//// 创建圆 O4  过渡段内侧圆  左侧
	//gp_Pnt centerO4(-sin(alpha) * (R1_NLK - R4_NLK), -cos(alpha) * (R1_NLK - R4_NLK), 0);
	//gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//gp_Circ CO4_NLK(axis4, R4_NLK);
	//Handle(Geom_Circle) geomCO4_NLK = new Geom_Circle(CO4_NLK);
	//TopoDS_Edge edgeO4_NLK= BRepBuilderAPI_MakeEdge(geomCO4_NLK);

	// 创建圆 O7  过渡段内侧圆  右侧
	gp_Pnt centerO7(sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis7(centerO7, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle7(axis7, radius4);
	Handle(Geom_Circle) geomCircle7 = new Geom_Circle(circle7);
	TopoDS_Edge edge7 = BRepBuilderAPI_MakeEdge(geomCircle7);


	///绘制拱墙内侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O1 = R1_NLK;//半径
	gp_Circ Circle_O1_EC(axis1, R_O1);
	gp_Ax3 AxO1(axis1);
	gp_Cylinder Cylinder_O1(AxO1, R_O1);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O1 = new Geom_CylindricalSurface(Cylinder_O1);
	GeomAPI_IntCS ICC_O4_01(geomCircle4, geoCylinder_O1);//求圆04与圆柱面cylinder01交点
	gp_Pnt CUT_O4_01 = ICC_O4_01.Point(1);

	GeomAPI_IntCS ICC_O7_01(geomCircle7, geoCylinder_O1);//求圆07与圆柱面cylinder01交点
	gp_Pnt CUT_O7_01 = ICC_O7_01.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O1_EC, CUT_O7_01, CUT_O4_01, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	Handle(AIS_Shape) aTarcCurve_01 = new AIS_Shape(TarcCurve_01);
	aTarcCurve_01->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_01, Standard_True);



	///绘制仰拱内侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O3 = radius3;//半径
								 /////绘制仰拱内侧弧线，已知弧段圆心、起点、半径
								 //Standard_Real R_O3 = R3_NLK;//半径
	gp_Circ Circle_O3_EC(axis03, R_O3);
	gp_Ax3 AxO3(axis03);
	gp_Cylinder Cylinder_O3(AxO3, R_O3);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O3 = new Geom_CylindricalSurface(Cylinder_O3);
	GeomAPI_IntCS ICC_O4_03(geomCircle4, geoCylinder_O3);//求圆04与圆柱面cylinder01交点
	gp_Pnt CUT_O4_03 = ICC_O4_03.Point(1);

	GeomAPI_IntCS ICC_O7_03(geomCircle7, geoCylinder_O3);//求圆07与圆柱面cylinder01交点
	gp_Pnt CUT_O7_03 = ICC_O7_03.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_03 = GC_MakeArcOfCircle(Circle_O3_EC, CUT_O4_03, CUT_O7_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_03 = BRepBuilderAPI_MakeEdge(arcCurve_03);
	Handle(AIS_Shape) aTarcCurve_03 = new AIS_Shape(TarcCurve_03);
	aTarcCurve_03->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_03, Standard_True);

	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O4 = radius4;//半径
								 /////绘制过渡段左侧弧线，已知弧段圆心、起点、半径
								 //Standard_Real R_O4 = R4_NLK;//半径
	gp_Circ Circle_O4_EC(axis4, R_O4);
	gp_Ax3 AxO4(axis4);
	gp_Cylinder Cylinder_O4(AxO4, R_O4);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_04 = GC_MakeArcOfCircle(Circle_O4_EC, CUT_O4_01, CUT_O4_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_04 = BRepBuilderAPI_MakeEdge(arcCurve_04);
	Handle(AIS_Shape) aTarcCurve_04 = new AIS_Shape(TarcCurve_04);
	aTarcCurve_04->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_04, Standard_True);

	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O7 = radius4;//半径
								 // ///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
								 //Standard_Real R_O7 = R4_NLK;//半径
	gp_Circ Circle_O7_EC(axis7, R_O7);
	gp_Ax3 AxO7(axis7);
	gp_Cylinder Cylinder_O7(AxO7, R_O7);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_07 = GC_MakeArcOfCircle(Circle_O7_EC, CUT_O7_03, CUT_O7_01, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_07 = BRepBuilderAPI_MakeEdge(arcCurve_07);
	Handle(AIS_Shape) aTarcCurve_07 = new AIS_Shape(TarcCurve_07);
	aTarcCurve_07->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_07, Standard_True);



	// 创建圆 O2  拱部外侧，665+55半径
	gp_Pnt P_CO2_NLK(0.0, 0.0, 0.0); // 原点为圆心
	gp_Ax2 axis2(P_CO2_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real R2_NLK = 720.0; // 定义圆的半径
	gp_Circ CO2_NLK(axis2, R2_NLK);
	Handle(Geom_Circle) geomCircle2 = new Geom_Circle(CO2_NLK);
	TopoDS_Edge edge2 = BRepBuilderAPI_MakeEdge(geomCircle2);

	// 创建圆 O5 仰拱外侧圆
	gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real radius5 = radius3 + 65.0; // 半径为 1720cm+55cm
	gp_Circ circle5(axis5, radius5);
	Handle(Geom_Circle) geomCircle5 = new Geom_Circle(circle5);
	TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomCircle5);
	//// 创建圆 O5 仰拱外侧圆
	//gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//Standard_Real R5_NLK = R3_NLK + 65.0; // 半径为 1720cm+55cm
	//gp_Circ circle5(axis5, R5_NLK);
	//Handle(Geom_Circle) geomC05_NLK = new Geom_Circle(C05_NLK);
	//TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomC05_NLK);

	//计算radius6 外侧过渡段圆半径
	//Standard_Real radius6 = solveForR4(alpha, radius, radius3, -pointP.Y());
	Standard_Real s = pow(radius5, 2) - pow(R2_NLK, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*(height + 55 * cos(alpha));
	Standard_Real p = radius5 - R2_NLK - pointP3.Y() *(height + 55 * cos(alpha)) / R2_NLK;
	Standard_Real radius6 = s / (2 * p);
	////计算radius6 外侧过渡段圆半径
	////Standard_Real R6_NLK = solveForR4(alpha, R1_NLK, R3_NLK, -P_CO1_NLK());
	//Standard_Real s = pow(R5_NLK, 2) - pow(R2_NLK, 2) - pow(P_CO3_NLK.Y(), 2) - 2 * P_CO3_NLK.Y()*(height+R2_NLK*alpha);
	//Standard_Real p = R5_NLK - R2_NLK - P_CO3_NLK.Y() *height / R2_NLK;
	//Standard_Real R6_NLK = s / (2 * p);


	// 创建圆 O6  过渡段外侧圆  左侧
	gp_Pnt centerO6(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle6(axis6, radius6);
	Handle(Geom_Circle) geomCircle6 = new Geom_Circle(circle6);
	TopoDS_Edge edge6 = BRepBuilderAPI_MakeEdge(geomCircle6);
	//// 创建圆 O6  过渡段外侧圆  左侧
	//gp_Pnt centerO6(-sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//gp_Circ circle6(axis6, R6_NLK);
	//Handle(Geom_Circle) geomC06_NLK = new Geom_Circle(C06_NLK);
	//TopoDS_Edge edge6_NLK = BRepBuilderAPI_MakeEdge(geomC06_NLK);

	// 创建圆 O8  过渡段外侧圆  右侧
	gp_Pnt centerO8(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle8(axis8, radius6);
	Handle(Geom_Circle) geomCircle8 = new Geom_Circle(circle8);
	TopoDS_Edge edge8 = BRepBuilderAPI_MakeEdge(geomCircle8);
	//// 创建圆 O8  过渡段外侧圆  右侧
	//gp_Pnt centerO8(sin(alpha) * (R2_NLK - R6_NLK), -cos(alpha) * (R2_NLK - R6_NLK), 0);
	//gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	//gp_Circ circle8(axis8, R6_NLK);
	//Handle(Geom_Circle) geomC08_NLK = new Geom_Circle(C08_NLK);
	//TopoDS_Edge edge8_NLK = BRepBuilderAPI_MakeEdge(geomC08_NLK);

	///绘制拱墙外侧弧线
	Standard_Real R_O2 = R2_NLK;//半径
	gp_Circ Circle_O2_EC(axis2, R_O2);
	gp_Ax3 AxO2(axis2);
	gp_Cylinder Cylinder_O2(AxO2, R_O2);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O2 = new Geom_CylindricalSurface(Cylinder_O2);

	// 定义直线的起点和终点
	gp_Pnt startPoint6_2(0, 0, 0);
	gp_Pnt endPoint6_2(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction6_2(startPoint6_2, endPoint6_2);
	gp_Lin line6_2(startPoint6_2, direction6_2);
	// 创建直线的线段
	TopoDS_Edge lineEdge6_2 = BRepBuilderAPI_MakeEdge(line6_2, startPoint6_2, endPoint6_2);
	Handle(Geom_Line) Geom_lineEdge6_2 = new Geom_Line(line6_2);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O6_02(Geom_lineEdge6_2, geoCylinder_O2);//06 02交点
	gp_Pnt CUT_O6_02_R1 = ICC_O6_02.Point(1);
	gp_Pnt CUT_O6_02_R2 = ICC_O6_02.Point(2);
	gp_Pnt CUT_O6_02;
	CUT_O6_02.SetX(CUT_O6_02_R1.X());
	CUT_O6_02.SetY(CUT_O6_02_R1.Y());
	if (CUT_O6_02_R1.X() > CUT_O6_02_R2.X()) {
		CUT_O6_02.SetX(CUT_O6_02_R2.X());
		CUT_O6_02.SetY(CUT_O6_02_R2.Y());
	}//求得过渡圆弧的起点

	 // 定义直线的起点和终点
	gp_Pnt startPoint8_2(0, 0, 0);
	gp_Pnt endPoint8_2(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction8_2(startPoint8_2, endPoint8_2);
	gp_Lin line8_2(startPoint8_2, direction8_2);
	// 创建直线的线段
	TopoDS_Edge lineEdge8_2 = BRepBuilderAPI_MakeEdge(line8_2, startPoint8_2, endPoint8_2);
	Handle(Geom_Line) Geom_lineEdge8_2 = new Geom_Line(line8_2);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O8_02(Geom_lineEdge8_2, geoCylinder_O2);//08 02交点
	gp_Pnt CUT_O8_02_R1 = ICC_O8_02.Point(1);
	gp_Pnt CUT_O8_02_R2 = ICC_O8_02.Point(2);
	gp_Pnt CUT_O8_02;
	CUT_O8_02.SetX(CUT_O8_02_R1.X());
	CUT_O8_02.SetY(CUT_O8_02_R1.Y());
	if (CUT_O8_02_R1.X() < CUT_O8_02_R2.X()) {
		CUT_O8_02.SetX(CUT_O8_02_R2.X());
		CUT_O8_02.SetY(CUT_O8_02_R2.Y());
	}//求得过渡圆弧的起点

	Handle(Geom_TrimmedCurve) arcCurve_02 = GC_MakeArcOfCircle(Circle_O2_EC, CUT_O8_02, CUT_O6_02, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_02 = BRepBuilderAPI_MakeEdge(arcCurve_02);
	Handle(AIS_Shape) aTarcCurve_02 = new AIS_Shape(TarcCurve_02);
	aTarcCurve_02->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_02, Standard_True);





	///绘制仰拱外侧弧线
	Standard_Real R_O5 = radius5;//半径
	gp_Circ Circle_O5_EC(axis5, R_O5);
	gp_Ax3 AxO5(axis5);
	gp_Cylinder Cylinder_O5(AxO5, R_O5);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O5 = new Geom_CylindricalSurface(Cylinder_O5);

	// 定义直线的起点和终点
	gp_Pnt startPoint6_5(0, 1720 - 180 - 30 - height, 0);
	gp_Pnt endPoint6_5(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction6_5(startPoint6_5, endPoint6_5);
	gp_Lin line6_5(startPoint6_5, direction6_5);
	// 创建直线的线段
	TopoDS_Edge lineEdge6_5 = BRepBuilderAPI_MakeEdge(line6_5, startPoint6_5, endPoint6_5);
	Handle(Geom_Line) Geom_lineEdge6_5 = new Geom_Line(line6_5);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O6_05(Geom_lineEdge6_5, geoCylinder_O5);//06 02交点
	gp_Pnt CUT_O6_05_R1 = ICC_O6_05.Point(1);
	gp_Pnt CUT_O6_05_R2 = ICC_O6_05.Point(2);
	gp_Pnt CUT_O6_05;
	CUT_O6_05.SetX(CUT_O6_05_R1.X());
	CUT_O6_05.SetY(CUT_O6_05_R1.Y());
	if (CUT_O6_05_R1.X() > CUT_O6_05_R2.X()) {
		CUT_O6_05.SetX(CUT_O6_05_R2.X());
		CUT_O6_05.SetY(CUT_O6_05_R2.Y());
	}//求得过渡圆弧的起点

	 // 定义直线的起点和终点
	gp_Pnt startPoint8_5(0, 1720 - 180 - 30 - height, 0);
	gp_Pnt endPoint8_5(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction8_5(startPoint8_5, endPoint8_5);
	gp_Lin line8_5(startPoint8_5, direction8_5);
	// 创建直线的线段
	TopoDS_Edge lineEdge8_5 = BRepBuilderAPI_MakeEdge(line8_5, startPoint8_5, endPoint8_5);
	Handle(Geom_Line) Geom_lineEdge8_5 = new Geom_Line(line8_5);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O8_05(Geom_lineEdge8_5, geoCylinder_O5);//08 02交点
	gp_Pnt CUT_O8_05_R1 = ICC_O8_05.Point(1);
	gp_Pnt CUT_O8_05_R2 = ICC_O8_05.Point(2);
	gp_Pnt CUT_O8_05;
	CUT_O8_05.SetX(CUT_O8_05_R1.X());
	CUT_O8_05.SetY(CUT_O8_05_R1.Y());
	if (CUT_O8_05_R1.X() < CUT_O8_05_R2.X()) {
		CUT_O8_05.SetX(CUT_O8_05_R2.X());
		CUT_O8_05.SetY(CUT_O8_05_R2.Y());
	}//求得过渡圆弧的起点


	Handle(Geom_TrimmedCurve) arcCurve_05 = GC_MakeArcOfCircle(Circle_O5_EC, CUT_O6_05, CUT_O8_05, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_05 = BRepBuilderAPI_MakeEdge(arcCurve_05);
	Handle(AIS_Shape) aTarcCurve_05 = new AIS_Shape(TarcCurve_05);
	aTarcCurve_05->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_05, Standard_True);







	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O6 = radius6;//半径
	gp_Circ Circle_O6_EC(axis6, R_O6);
	gp_Ax3 AxO6(axis6);
	gp_Cylinder Cylinder_O6(AxO6, R_O6);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_06 = GC_MakeArcOfCircle(Circle_O6_EC, CUT_O6_02, CUT_O6_05, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_06 = BRepBuilderAPI_MakeEdge(arcCurve_06);
	Handle(AIS_Shape) aTarcCurve_06 = new AIS_Shape(TarcCurve_06);
	aTarcCurve_06->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_06, Standard_True);




	///绘制过渡段右侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O8 = radius6;//半径
	gp_Circ Circle_O8_EC(axis8, R_O8);
	gp_Ax3 AxO8(axis8);
	gp_Cylinder Cylinder_O8(AxO8, R_O8);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_08 = GC_MakeArcOfCircle(Circle_O8_EC, CUT_O8_05, CUT_O8_02, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_08 = BRepBuilderAPI_MakeEdge(arcCurve_08);
	Handle(AIS_Shape) aTarcCurve_08 = new AIS_Shape(TarcCurve_08);
	aTarcCurve_08->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_08, Standard_True);


	//// 创建 OCC 可视化对象圆 O1
	//Handle(AIS_Shape) aisShape1 = new AIS_Shape(edge1);
	//aisShape1->SetColor(Quantity_NOC_RED); // 设置颜色为红色
	//myOccView->getContext()->Display(aisShape1, Standard_True); // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O2
	//Handle(AIS_Shape) aisShape2 = new AIS_Shape(edge2);
	//aisShape2->SetColor(Quantity_NOC_GREEN); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisShape2, Standard_True); // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象 OP线段
	//Handle(AIS_Shape) aisShapeP = new AIS_Shape(shapeP);
	//aisShapeP->SetColor(Quantity_Color(Quantity_NOC_ORANGE)); // 设置颜色为橙色
	//myOccView->getContext()->Display(aisShapeP, Standard_True); // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O3
	//Handle(AIS_Shape) aisCircle03 = new AIS_Shape(edge03);
	//aisCircle03->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle03, Standard_True); // 在场景中显示直线 
	//// 创建 OCC 可视化对象圆 O4
	//Handle(AIS_Shape) aisCircle4 = new AIS_Shape(edge4);
	//aisCircle4->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle4, Standard_True); // 在场景中显示直线 // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O5
	//Handle(AIS_Shape) aisCircle5 = new AIS_Shape(edge5);
	//aisCircle5->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle5, Standard_True); // 在场景中显示直线 
	//// 创建 OCC 可视化对象圆 O6
	//Handle(AIS_Shape) aisCircle6 = new AIS_Shape(edge6);
	//aisCircle6->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle6, Standard_True); // 在场景中显示直线 // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O7
	//Handle(AIS_Shape) aisCircle7 = new AIS_Shape(edge7);
	//aisCircle7->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle7, Standard_True); // 在场景中显示直线 // 在场景中显示可视化对象
	//// 创建 OCC 可视化对象圆 O8
	//Handle(AIS_Shape) aisCircle8 = new AIS_Shape(edge8);
	//aisCircle8->SetColor(Quantity_Color(Quantity_NOC_GREEN)); // 设置颜色为绿色
	//myOccView->getContext()->Display(aisCircle8, Standard_True); // 在场景中显示直线 // 在场景中显示可视化对象






	//如果用交点直接确定可使用下方法
	//gp_Pnt centerO7(sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	/////绘制拱墙内侧弧线，已知弧段圆心、起点、半径
	//Standard_Real R_O1 = radius1;//半径
	//gp_Circ Circle_O1_EC(axis1, R_O1);
	//gp_Ax3 AxO1(axis1);
	//gp_Cylinder Cylinder_O1(AxO1, R_O1);//弧线所在圆柱面

	//Handle(Geom_CylindricalSurface) geoCylinder_O1 = new Geom_CylindricalSurface(Cylinder_O1);

	//gp_Pnt CUT_O4_01(-sin(alpha) * radius, -cos(alpha) * radius , 0);
	//gp_Pnt CUT_O7_01(sin(alpha) * radius, -cos(alpha) * radius, 0);

	//Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O1_EC, CUT_O7_01, CUT_O4_01, true);//绘制左侧连接圆弧
	//TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	//Handle(AIS_Shape) aTarcCurve_01 = new AIS_Shape(TarcCurve_01);
	//aTarcCurve_01->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_01, Standard_True);


	//延长线方法——有问题
	//// 定义起点和终点
	//gp_Pnt startPoint6_3(0, 0, 0);
	//gp_Pnt endPoint6_3(-sin(alpha) * (radius2 - radius6), -cos(alpha) * (radius2 - radius6), 0);
	//gp_Vec direction6_3(-sin(alpha) * (radius2 - radius6), -cos(alpha) * (radius2 - radius6), 0);
	//// 使用起点和终点创建一个直线
	//gp_Lin line6_3(startPoint6_3, direction6_3);
	//Handle(Geom_Line) line6_3 = new Geom_Line(startPoint6_3, gp_Vec(startPoint6_3, endPoint6_3));
	//// 使用直线创建一个线段，这个线段由起点和终点限定
	//TopoDS_Edge edge6_3 = BRepBuilderAPI_MakeEdge(line6_3, startPoint6_3, endPoint6_3);
	//// 指定延长的距离
	//double extensionDistance = 50;  // 假设延长50
	//// 计算延长后的终点
	//gp_Pnt extendedEndPoint = endPoint6_3.Translated(gp_Vec(startPoint6_3, endPoint6_3).Normalized() * extensionDistance);
	//// 使用延长后的终点创建一个延长后的线段
	//TopoDS_Edge extendedEdge = BRepBuilderAPI_MakeEdge(line6_3, startPoint6_3, extendedEndPoint);

	// 使用 BRepBuilderAPI_MakeWire 创建闭合曲线
	BRepBuilderAPI_MakeWire EC_WAIwireBuilder;
	EC_WAIwireBuilder.Add(TarcCurve_02);
	EC_WAIwireBuilder.Add(TarcCurve_06);
	EC_WAIwireBuilder.Add(TarcCurve_05);
	EC_WAIwireBuilder.Add(TarcCurve_08);
	EC_WAIwireBuilder.Build();

	if (EC_WAIwireBuilder.IsDone()) {
		TopoDS_Wire EC_WAIclosedWire = EC_WAIwireBuilder.Wire();// 现在 closedWire 就是你连接成闭合的连续线
																//和倒切式洞门连接处的外部钢筋
		gp_Trsf translation1;
		translation1.SetTranslation(gp_Vec(0.0, 0.0, 600.0));  // 平移600个单位沿Z轴
															   // 应用平移变换到线
		BRepBuilderAPI_Transform transform1(EC_WAIclosedWire, translation1);
		TopoDS_Wire translatedLine1 = TopoDS::Wire(transform1.Shape());
		myOccView->getContext()->Display(new AIS_Shape(translatedLine1), Standard_True);

		//外部钢筋
		// 保存平移后的线的集合
		std::vector<TopoDS_Wire> translatedLines;

		// 初始平移量
		double translationDistance = 20.0;

		// 循环平移
		for (int i = 0; i < 30; ++i) {
			// 创建平移变换
			gp_Trsf translation;
			translation.SetTranslation(gp_Vec(0.0, 0.0, (i + 1) * translationDistance));  // 每次平移20个单位沿Z轴

																						  // 应用平移变换到线
			BRepBuilderAPI_Transform transform(translatedLine1, translation);
			TopoDS_Wire translatedLine = TopoDS::Wire(transform.Shape());

			// 保存平移后的线
			translatedLines.push_back(translatedLine);

			// 将线显示在myOccView中
			myOccView->getContext()->Display(new AIS_Shape(translatedLine), Standard_True);
		}
		// 现在 translatedLines 中包含了一系列平移后的线

	}
	else {
		// 处理创建失败的情况
	}

	//TopoDS_Wire sectorWirearc = makeWirearc.Wire();
	BRepBuilderAPI_MakeFace EC_WAIFacearc(EC_WAIwireBuilder);
	//TopoDS_Face EC_WAIFacearc = EC_WAIFacearc.Face();
	gp_Vec extrusionVecR1(0, 0, 1200.0); // 沿着 Z 轴方向拉伸 1200 个单位

	BRepPrimAPI_MakePrism EC_WAI_makearc1(EC_WAIFacearc, extrusionVecR1);
	TopoDS_Shape EC_WAI_arcShape1 = EC_WAI_makearc1.Shape();
	TopoDS_Solid EC_WAI_arcbody = TopoDS::Solid(EC_WAI_arcShape1);
	Handle(AIS_Shape) EC_WAI_Aisarcbody = new AIS_Shape(EC_WAI_arcbody);


	//EC_WAI_Aisarcbody->SetColor(Quantity_NOC_RED); // 设置颜色为红色
	//myOccView->getContext()->Display(EC_WAI_Aisarcbody, Standard_True); // 在场景中显示可视化对象

	// 使用 BRepBuilderAPI_MakeWire 创建闭合曲线
	BRepBuilderAPI_MakeWire EC_NEIwireBuilder;
	EC_NEIwireBuilder.Add(TarcCurve_01);
	EC_NEIwireBuilder.Add(TarcCurve_04);
	EC_NEIwireBuilder.Add(TarcCurve_07);
	EC_NEIwireBuilder.Add(TarcCurve_03);
	EC_NEIwireBuilder.Build();

	if (EC_NEIwireBuilder.IsDone()) {
		TopoDS_Wire EC_NEIclosedWire = EC_NEIwireBuilder.Wire();// 现在 closedWire 就是你连接成闭合的连续线

																//和倒切式洞门连接处的外部钢筋
		gp_Trsf translation1;
		translation1.SetTranslation(gp_Vec(0.0, 0.0, 600.0));  // 平移600个单位沿Z轴
															   // 应用平移变换到线
		BRepBuilderAPI_Transform transform1(EC_NEIclosedWire, translation1);
		TopoDS_Wire translatedLine1 = TopoDS::Wire(transform1.Shape());
		myOccView->getContext()->Display(new AIS_Shape(translatedLine1), Standard_True);

		//外部钢筋
		// 保存平移后的线的集合
		std::vector<TopoDS_Wire> translatedLines;

		// 初始平移量
		double translationDistance = 20.0;

		// 循环平移
		for (int i = 0; i < 30; ++i) {
			// 创建平移变换
			gp_Trsf translation;
			translation.SetTranslation(gp_Vec(0.0, 0.0, (i + 1) * translationDistance));  // 每次平移20个单位沿Z轴

																						  // 应用平移变换到线
			BRepBuilderAPI_Transform transform(translatedLine1, translation);
			TopoDS_Wire translatedLine = TopoDS::Wire(transform.Shape());

			// 保存平移后的线
			translatedLines.push_back(translatedLine);

			// 将线显示在myOccView中
			myOccView->getContext()->Display(new AIS_Shape(translatedLine), Standard_True);
		}
		// 现在 translatedLines 中包含了一系列平移后的线


		Standard_Real cosn = 630 / 665;
		gp_Pnt P_2(0, R2_NLK, 600.0);
		gp_Pnt P_2_start(720, 0, 600.0);
		gp_Pnt P_1(0, R1_NLK, 600.0);
		gp_Pnt P_1_start(665.0, 0, 600.0);
		gp_Pnt P_0(0, 0, 600.0);
		Standard_Real rebar_spacing = 25;  //钢筋间距

										   // 创建组合体10
		TopoDS_Compound compound10;
		BRep_Builder builder10;
		builder10.MakeCompound(compound10);
		gp_Trsf translation_regar;
		translation_regar.SetTranslation(gp_Vec(0.0, 0.0, 600.0));  // 平移600个单位沿Z轴

																	// 在Z轴方向移动钢筋
		for (int i = 0; i < 91; i++)
		{
			Standard_Real sinValue = rebar_spacing / R2_NLK;  // 假设这是你的sin值
			Standard_Real radians = asin(sinValue);  // 使用asin函数来将sin值转化为弧度
			Standard_Real angleIncrementDeg = radians * i;
			TopoDS_Edge edge2 = MoveLineInPolarCoordinates(P_2_start, angleIncrementDeg, 720);
			TopoDS_Edge edge1 = MoveLineInPolarCoordinates(P_1_start, angleIncrementDeg, 665);

			builder10.Add(compound10, edge1);
			builder10.Add(compound10, edge2);


		}

		// 应用变换到组合体
		BRepBuilderAPI_Transform transform(compound10, translation_regar);

		// 获取变换后的组合体
		TopoDS_Shape transformedCompound10 = transform.Shape();

		Handle(AIS_Shape) AistransformedCompound10 = new AIS_Shape(transformedCompound10);
		AistransformedCompound10->SetColor(Quantity_NOC_RED);
		myOccView->getContext()->Display(AistransformedCompound10, Standard_True);

		// 创建组合体11
		TopoDS_Compound compound11;
		BRep_Builder builder11;
		builder11.MakeCompound(compound11);

		gp_Dir xAxisDirection(-1, 0, 0);

		for (int yCoordinate0 = 25; yCoordinate0 < 17 * 25; yCoordinate0 += 25)
		{
			gp_Pnt PointLine(720.0, -yCoordinate0, 600.0);

			Standard_Real xCoordinate0 = sqrt(pow(665, 2) - pow(yCoordinate0, 2));
			gp_Pnt Pointline1(xCoordinate0, -yCoordinate0, 600.0);
			BRepBuilderAPI_MakeEdge edgeBuilder(PointLine, Pointline1);
			TopoDS_Edge extendedEdge = edgeBuilder.Edge();

			builder11.Add(compound11, extendedEdge);

			// 创建新的点并进行平移
			Standard_Real extensionDistance = 600.0; // 延长的距离
			gp_Vec extensionVector(0.0, 0.0, extensionDistance);

			// 创建新的点并进行平移
			gp_Pnt extendedPoint = Pointline1.Translated(extensionVector);

			// 创建新边
			BRepBuilderAPI_MakeEdge edgeBuilder2(Pointline1, extendedPoint);
			TopoDS_Edge extendedEdge2 = edgeBuilder2.Edge();
			builder11.Add(compound11, extendedEdge2);
		}

		// 显示组合体
		Handle(AIS_Shape) Aiscompound11 = new AIS_Shape(compound11);
		Aiscompound11->SetColor(Quantity_NOC_RED);
		myOccView->getContext()->Display(Aiscompound11, Standard_True);



	}
	else {
		// 处理创建失败的情况
	}

	BRepBuilderAPI_MakeFace EC_NEIFacearc(EC_NEIwireBuilder);

	BRepPrimAPI_MakePrism EC_NEI_makearc1(EC_NEIFacearc, extrusionVecR1);
	TopoDS_Shape EC_NEI_arcShape1 = EC_NEI_makearc1.Shape();
	TopoDS_Solid EC_NEI_arcbody = TopoDS::Solid(EC_NEI_arcShape1);
	Handle(AIS_Shape) EC_NEI_Aisarcbody = new AIS_Shape(EC_NEI_arcbody);

	BRepAlgoAPI_Cut cutOp1(EC_WAI_arcShape1, EC_NEI_arcShape1);
	TopoDS_Shape EC_arcShape = cutOp1.Shape();

	//Handle(AIS_Shape) EC_arcShape1 = new AIS_Shape(EC_arcShape);
	//EC_arcShape1->SetColor(Quantity_NOC_RED); // 设置颜色为红色
	//myOccView->getContext()->Display(EC_arcShape1, Standard_True); // 在场景中显示可视化对象


	// 定义四个点
	gp_Pnt p10(-835, -835, 600);
	gp_Pnt p11(835, -835, 600);
	gp_Pnt p12(835, 835, 600);
	gp_Pnt p13(-835, 835, 600);

	// 创建四边形面
	TopoDS_Vertex v10 = BRepBuilderAPI_MakeVertex(p10);
	TopoDS_Vertex v11 = BRepBuilderAPI_MakeVertex(p11);
	TopoDS_Vertex v12 = BRepBuilderAPI_MakeVertex(p12);
	TopoDS_Vertex v13 = BRepBuilderAPI_MakeVertex(p13);

	TopoDS_Wire wire7 = BRepBuilderAPI_MakePolygon(v10, v11, v12, v13, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																					   // 创建面
	BRepBuilderAPI_MakeFace face7(wire7);

	// 定义拉伸向量
	gp_Vec heightVec7(0, 0, -600);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker7(face7.Shape(), heightVec7);
	TopoDS_Shape prismShape7 = prismMaker7.Shape();


	// 使用 BRepAlgoAPI_Cut 进行裁剪操作
	BRepAlgoAPI_Cut cut_operator5(EC_arcShape, prismShape7);
	cut_operator5.Build();
	TopoDS_Shape final_shape5 = cut_operator5.Shape();

	// 将结果显示在视图中
	//Handle(AIS_Shape) final_shape6 = new AIS_Shape(final_shape5);
	//final_shape6->SetColor(Quantity_NOC_RED); // 设置颜色为红色
	//myOccView->getContext()->Display(final_shape6, Standard_True); // 在场景中显示可视化对象

	myOccView->getContext()->Display(new AIS_Shape(final_shape5), Standard_True);
}


void MainWindow::makeInvertedBrim2(const InvertedBrim2& coords)
{
	// 根据圆点为中心创建对称变换
	gp_Trsf mirrorTransform_GC;
	mirrorTransform_GC.SetMirror(gp_Ax2(gp_Pnt(0.0, 0.0, 0.0), gp_Dir(1.0, 0.0, 0.0))); // 沿 Y 轴对称
	
	// 绘制第一个圆台
	double radius_top_1 = 720;
	double radius_bottom_1 = 820;
	double height_1 = 600;

	TopoDS_Shape cone_shape_1 = draw_cone(radius_top_1, radius_bottom_1, height_1);

	// 绘制第二个圆台
	double radius_top_2 = 665;
	double radius_bottom_2 = 765;
	double height_2 = 600;

	TopoDS_Shape cone_shape_2 = draw_cone(radius_top_2, radius_bottom_2, height_2);

	// 使用 BRepAlgoAPI_Cut 函数将两个圆台的重叠部分移除
	BRepAlgoAPI_Cut cut_operator(cone_shape_1, cone_shape_2);
	cut_operator.Build();

	TopoDS_Shape result_shape = cut_operator.Shape();


	//绘制钢筋
	// 生成一系列平面，计算交线并显示
	const int numPlanes = 31; // 平面的数量
	const double offset = 20.0; // 平面间的间隔
	const double minY = -213.0; // 平面的最小Y坐标
	for (int i = 0; i < numPlanes; ++i) {
		// 创建平面，确保Y坐标不低于minY，并沿Z轴平移
		gp_Vec translationVector(0.0, 0.0, i * offset);
		gp_Pnt origin(0.0, std::max(minY, i * offset), 0.0);
		gp_Pnt translatedPoint = origin.Translated(translationVector);
		gp_Ax3 axis(translatedPoint, gp_Dir(0, 0, 1));  // Create an axis with origin at translatedPoint and direction along Z axis
		gp_Pln plane(axis);  // Construct the plane using the axis

							 // 计算平面与三维实体的交线
		BRepAlgoAPI_Section sectionOp(result_shape, plane, Standard_True);
		sectionOp.Build();

		if (sectionOp.IsDone()) {
			// 获取交线
			TopoDS_Shape intersectionShape = sectionOp.Shape();

			// 显示交线
			//Handle(AIS_Shape) aisIntersectionShape = new AIS_Shape(intersectionShape);
			//aisIntersectionShape->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
			//myOccView->getContext()->Display(aisIntersectionShape, Standard_True);

			// 定义四个点
			gp_Pnt p0(835, -213, 0);
			gp_Pnt p1(-835, -213, 0);
			gp_Pnt p2(-835, -213, 600);
			gp_Pnt p3(835, -213, 600);

			// 创建四边形面
			TopoDS_Vertex v0 = BRepBuilderAPI_MakeVertex(p0);
			TopoDS_Vertex v1 = BRepBuilderAPI_MakeVertex(p1);
			TopoDS_Vertex v2 = BRepBuilderAPI_MakeVertex(p2);
			TopoDS_Vertex v3 = BRepBuilderAPI_MakeVertex(p3);

			TopoDS_Wire wire = BRepBuilderAPI_MakePolygon(v0, v1, v2, v3, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																						  // 创建面
			BRepBuilderAPI_MakeFace face(wire);

			// 定义拉伸向量
			gp_Vec heightVec(0, -900, 0);

			// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
			BRepPrimAPI_MakePrism prismMaker(face.Shape(), heightVec);
			TopoDS_Shape prismShape = prismMaker.Shape();


			// 使用 BRepAlgoAPI_Cut 进行裁剪操作
			BRepAlgoAPI_Cut cut_operator2(intersectionShape, prismShape);
			cut_operator2.Build();
			TopoDS_Shape final_shape1 = cut_operator2.Shape();

			//// 将结果显示在视图中
			//myOccView->getContext()->Display(new AIS_Shape(final_shape1), Standard_True);


			// 定义四个顶点
			gp_Pnt p7(-835, -213, 300);
			gp_Pnt p4(835, -213, 300);
			gp_Pnt p5(835, 835, 0);
			gp_Pnt p6(-835, 835, 0);

			// 创建四边形面
			TopoDS_Vertex v7 = BRepBuilderAPI_MakeVertex(p7);
			TopoDS_Vertex v4 = BRepBuilderAPI_MakeVertex(p4);
			TopoDS_Vertex v5 = BRepBuilderAPI_MakeVertex(p5);
			TopoDS_Vertex v6 = BRepBuilderAPI_MakeVertex(p6);

			TopoDS_Wire wire1 = BRepBuilderAPI_MakePolygon(v7, v4, v5, v6, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																						   // 创建面
			BRepBuilderAPI_MakeFace face1(wire1);

			// 定义拉伸向量
			gp_Vec heightVec1(0, 0, -600);

			// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
			BRepPrimAPI_MakePrism prismMaker1(face1.Shape(), heightVec1);
			TopoDS_Shape prismShape1 = prismMaker1.Shape();

			//使用 BRepAlgoAPI_Cut 进行裁剪操作
			BRepAlgoAPI_Cut cut_operator3(final_shape1, prismShape1);
			cut_operator3.Build();
			TopoDS_Shape final_shape2 = cut_operator3.Shape();

			//将结果显示在视图中
			Handle(AIS_Shape) aisIntersectionShape = new AIS_Shape(final_shape2);
			aisIntersectionShape->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
			myOccView->getContext()->Display(aisIntersectionShape, Standard_True);

			// 计算平面与三维实体的交线
			BRepAlgoAPI_Section sectionOp(result_shape, face1, Standard_True);
			sectionOp.Build();

			TopoDS_Shape intersectionShape1 = sectionOp.Shape();

			//将结果显示在视图中
			Handle(AIS_Shape) aisIntersectionShape1 = new AIS_Shape(intersectionShape1);
			aisIntersectionShape1->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
			myOccView->getContext()->Display(aisIntersectionShape1, Standard_True);



		}
	}

	//绘制脚座
	// 定义四个点
	gp_Pnt p0(835, -213, 0);
	gp_Pnt p1(-835, -213, 0);
	gp_Pnt p2(-835, -213, 600);
	gp_Pnt p3(835, -213, 600);

	// 创建四边形面
	TopoDS_Vertex v0 = BRepBuilderAPI_MakeVertex(p0);
	TopoDS_Vertex v1 = BRepBuilderAPI_MakeVertex(p1);
	TopoDS_Vertex v2 = BRepBuilderAPI_MakeVertex(p2);
	TopoDS_Vertex v3 = BRepBuilderAPI_MakeVertex(p3);

	TopoDS_Wire wire = BRepBuilderAPI_MakePolygon(v0, v1, v2, v3, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				  // 创建面
	BRepBuilderAPI_MakeFace face(wire);

	// 定义拉伸向量
	gp_Vec heightVec(0, -900, 0);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker(face.Shape(), heightVec);
	TopoDS_Shape prismShape = prismMaker.Shape();


	// 使用 BRepAlgoAPI_Cut 进行裁剪操作
	BRepAlgoAPI_Cut cut_operator2(result_shape, prismShape);
	cut_operator2.Build();
	TopoDS_Shape final_shape1 = cut_operator2.Shape();

	//// 将结果显示在视图中
	//myOccView->getContext()->Display(new AIS_Shape(final_shape1), Standard_True);


	// 定义四个顶点
	gp_Pnt p7(-835, -213, 300);
	gp_Pnt p4(835, -213, 300);
	gp_Pnt p5(835, 835, 0);
	gp_Pnt p6(-835, 835, 0);

	// 创建四边形面
	TopoDS_Vertex v7 = BRepBuilderAPI_MakeVertex(p7);
	TopoDS_Vertex v4 = BRepBuilderAPI_MakeVertex(p4);
	TopoDS_Vertex v5 = BRepBuilderAPI_MakeVertex(p5);
	TopoDS_Vertex v6 = BRepBuilderAPI_MakeVertex(p6);

	TopoDS_Wire wire1 = BRepBuilderAPI_MakePolygon(v7, v4, v5, v6, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				   // 创建面
	BRepBuilderAPI_MakeFace face1(wire1);

	// 定义拉伸向量
	gp_Vec heightVec1(0, 0, -600);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker1(face1.Shape(), heightVec1);
	TopoDS_Shape prismShape1 = prismMaker1.Shape();

	//使用 BRepAlgoAPI_Cut 进行裁剪操作
	BRepAlgoAPI_Cut cut_operator3(final_shape1, prismShape1);
	cut_operator3.Build();
	TopoDS_Shape final_shape2 = cut_operator3.Shape();

	//将结果显示在视图中
	//myOccView->getContext()->Display(new AIS_Shape(final_shape2), Standard_True);




	// 定义4个顶点
	gp_Pnt pA(-640, -213, 600);
	gp_Pnt pB(-700, -213, 600);
	gp_Pnt pC(-700, -413, 600);
	gp_Pnt pD(-508, -413, 600);


	// 创建四边形面ABCD
	TopoDS_Vertex vA = BRepBuilderAPI_MakeVertex(pA);
	TopoDS_Vertex vB = BRepBuilderAPI_MakeVertex(pB);
	TopoDS_Vertex vC = BRepBuilderAPI_MakeVertex(pC);
	TopoDS_Vertex vD = BRepBuilderAPI_MakeVertex(pD);

	TopoDS_Wire wire2 = BRepBuilderAPI_MakePolygon(vA, vB, vC, vD, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形
																				   // 创建面
	BRepBuilderAPI_MakeFace face2(wire2);

	// 定义拉伸向量
	gp_Vec heightVec2(0, 0, -300);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker2(face2.Shape(), heightVec2);
	TopoDS_Shape prismShape2 = prismMaker2.Shape();

	//将结果显示在视图中
	//myOccView->getContext()->Display(new AIS_Shape(prismShape2), Standard_True);


	// 定义3个顶点
	gp_Pnt pB1(-700, -213, 600);
	gp_Pnt pE(-700, -213, 300);
	gp_Pnt pF(-750, -213, 300);

	// 创建三角形面B1EF
	TopoDS_Vertex vB1 = BRepBuilderAPI_MakeVertex(pB1);
	TopoDS_Vertex vE = BRepBuilderAPI_MakeVertex(pE);
	TopoDS_Vertex vF = BRepBuilderAPI_MakeVertex(pF);

	TopoDS_Wire wire3 = BRepBuilderAPI_MakePolygon(vB1, vE, vF, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				// 创建面
	BRepBuilderAPI_MakeFace face3(wire3);

	// 定义拉伸向量
	gp_Vec heightVec3(0, -200, 0);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker3(face3.Shape(), heightVec3);
	TopoDS_Shape prismShape3 = prismMaker3.Shape();

	//将结果显示在视图中
	//myOccView->getContext()->Display(new AIS_Shape(prismShape3), Standard_True);




	//// 定义4个顶点
	gp_Pnt pa(640, -213, 600);
	gp_Pnt pb(700, -213, 600);
	gp_Pnt pc(700, -413, 600);
	gp_Pnt pd(508, -413, 600);


	// 创建四边形面ABCD
	TopoDS_Vertex va = BRepBuilderAPI_MakeVertex(pa);
	TopoDS_Vertex vb = BRepBuilderAPI_MakeVertex(pb);
	TopoDS_Vertex vc = BRepBuilderAPI_MakeVertex(pc);
	TopoDS_Vertex vd = BRepBuilderAPI_MakeVertex(pd);

	TopoDS_Wire wire4 = BRepBuilderAPI_MakePolygon(va, vb, vc, vd, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				   // 创建面
	BRepBuilderAPI_MakeFace face4(wire4);

	// 定义拉伸向量
	gp_Vec heightVec4(0, 0, -300);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker4(face4.Shape(), heightVec4);
	TopoDS_Shape prismShape4 = prismMaker4.Shape();

	//将结果显示在视图中
	//myOccView->getContext()->Display(new AIS_Shape(prismShape4), Standard_True);


	//// 定义3个顶点
	gp_Pnt pb1(700, -213, 600);
	gp_Pnt pe(700, -213, 300);
	gp_Pnt pf(750, -213, 300);

	// 创建三角形面B1EF
	TopoDS_Vertex vb1 = BRepBuilderAPI_MakeVertex(pb1);
	TopoDS_Vertex ve = BRepBuilderAPI_MakeVertex(pe);
	TopoDS_Vertex vf = BRepBuilderAPI_MakeVertex(pf);

	TopoDS_Wire wire5 = BRepBuilderAPI_MakePolygon(vb1, ve, vf, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																				// 创建面
	BRepBuilderAPI_MakeFace face5(wire5);

	// 定义拉伸向量
	gp_Vec heightVec5(0, -200, 0);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker5(face5.Shape(), heightVec5);
	TopoDS_Shape prismShape5 = prismMaker5.Shape();
	//将结果显示在视图中
	//myOccView->getContext()->Display(new AIS_Shape(prismShape5), Standard_True);



	// 创建圆 O1  拱部内侧，665半径 
	gp_Pnt P_CO1_NLK(0.0, 0.0, 0.0); // 原点为圆心
	gp_Ax2 axis1(P_CO1_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real R1_NLK = 665.0; // 定义圆的半径
	gp_Circ CO1_NLK(axis1, R1_NLK);
	Handle(Geom_Circle) geomCircle1_NLK = new Geom_Circle(CO1_NLK);
	TopoDS_Edge edge1_NLK = BRepBuilderAPI_MakeEdge(geomCircle1_NLK);

	// 创建原点的中垂线
	BRepBuilderAPI_MakeEdge edge(gp_Pnt(0, -1000, 0), gp_Pnt(0, 1000, 0));
	TopoDS_Shape shape3 = edge.Shape();
	// 计算圆心到点 P 的距离 盖板距离线段
	Standard_Real radius = 665.0;
	Standard_Real radius3 = 1720; // 圆O3的半径
	Standard_Real height = sqrt(pow(radius, 2) - pow(630, 2));
	Standard_Real distanceCenterToP = sqrt(pow(radius, 2) + pow(630, 2)) - radius;
	gp_Pnt pointP(0, -height, 0);


	gp_Pnt pointP3(0, 1720 - 180 - 30 - height, 0);//180和30会改变！！！

												   // // 确定新的圆心 P3  仰拱圆心
												   //gp_Pnt P_CO3_NLK(0, 1720 - 180 - 30 - height, 0);//180和30会改变！！！

												   //计算角度 alpha  确定过渡段圆半径用参数
	Standard_Real alpha = acos(-pointP.Y() / radius);
	////计算角度 alpha  确定过渡段圆半径用参数
	//Standard_Real alpha = acos(-pointP.Y() / R1_NLK);
	// 创建圆心到点 P 的线段
	BRepBuilderAPI_MakeEdge edgeP(gp_Pnt(0, 0, 0), pointP);
	TopoDS_Shape shapeP = edgeP.Shape();

	// 创建圆 O3  仰拱内侧圆
	gp_Ax2 axis03(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
												   //											   // 创建圆 O3  仰拱内侧圆
												   //gp_Ax2 axis03(P_CO3_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real radius03 = 1720.0; // 半径为 1720cm
	gp_Circ circle03(axis03, radius03);
	Handle(Geom_Circle) geomCircle03 = new Geom_Circle(circle03);
	TopoDS_Edge edge03 = BRepBuilderAPI_MakeEdge(geomCircle03);


	//计算radius4  内侧过渡段圆半径
	Standard_Real m = pow(radius3, 2) - pow(radius, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*height;
	Standard_Real n = radius3 - radius - pointP3.Y() *height / radius;
	Standard_Real radius4 = m / (2 * n);
	// 创建圆 O4  过渡段内侧圆  左侧
	gp_Pnt centerO4(-sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis4(centerO4, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle4(axis4, radius4);
	Handle(Geom_Circle) geomCircle4 = new Geom_Circle(circle4);
	TopoDS_Edge edge4 = BRepBuilderAPI_MakeEdge(geomCircle4);


	// 创建圆 O7  过渡段内侧圆  右侧
	gp_Pnt centerO7(sin(alpha) * (radius - radius4), -cos(alpha) * (radius - radius4), 0);
	gp_Ax2 axis7(centerO7, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle7(axis7, radius4);
	Handle(Geom_Circle) geomCircle7 = new Geom_Circle(circle7);
	TopoDS_Edge edge7 = BRepBuilderAPI_MakeEdge(geomCircle7);


	///绘制拱墙内侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O1 = R1_NLK;//半径
	gp_Circ Circle_O1_EC(axis1, R_O1);
	gp_Ax3 AxO1(axis1);
	gp_Cylinder Cylinder_O1(AxO1, R_O1);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O1 = new Geom_CylindricalSurface(Cylinder_O1);
	GeomAPI_IntCS ICC_O4_01(geomCircle4, geoCylinder_O1);//求圆04与圆柱面cylinder01交点
	gp_Pnt CUT_O4_01 = ICC_O4_01.Point(1);

	GeomAPI_IntCS ICC_O7_01(geomCircle7, geoCylinder_O1);//求圆07与圆柱面cylinder01交点
	gp_Pnt CUT_O7_01 = ICC_O7_01.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_01 = GC_MakeArcOfCircle(Circle_O1_EC, CUT_O7_01, CUT_O4_01, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_01 = BRepBuilderAPI_MakeEdge(arcCurve_01);
	Handle(AIS_Shape) aTarcCurve_01 = new AIS_Shape(TarcCurve_01);
	aTarcCurve_01->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_01, Standard_True);


	///绘制仰拱内侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O3 = radius3;//半径
								 /////绘制仰拱内侧弧线，已知弧段圆心、起点、半径
								 //Standard_Real R_O3 = R3_NLK;//半径
	gp_Circ Circle_O3_EC(axis03, R_O3);
	gp_Ax3 AxO3(axis03);
	gp_Cylinder Cylinder_O3(AxO3, R_O3);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O3 = new Geom_CylindricalSurface(Cylinder_O3);
	GeomAPI_IntCS ICC_O4_03(geomCircle4, geoCylinder_O3);//求圆04与圆柱面cylinder01交点
	gp_Pnt CUT_O4_03 = ICC_O4_03.Point(1);

	GeomAPI_IntCS ICC_O7_03(geomCircle7, geoCylinder_O3);//求圆07与圆柱面cylinder01交点
	gp_Pnt CUT_O7_03 = ICC_O7_03.Point(2);

	Handle(Geom_TrimmedCurve) arcCurve_03 = GC_MakeArcOfCircle(Circle_O3_EC, CUT_O4_03, CUT_O7_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_03 = BRepBuilderAPI_MakeEdge(arcCurve_03);
	Handle(AIS_Shape) aTarcCurve_03 = new AIS_Shape(TarcCurve_03);
	aTarcCurve_03->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_03, Standard_True);

	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O4 = radius4;//半径
								 /////绘制过渡段左侧弧线，已知弧段圆心、起点、半径
								 //Standard_Real R_O4 = R4_NLK;//半径
	gp_Circ Circle_O4_EC(axis4, R_O4);
	gp_Ax3 AxO4(axis4);
	gp_Cylinder Cylinder_O4(AxO4, R_O4);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_04 = GC_MakeArcOfCircle(Circle_O4_EC, CUT_O4_01, CUT_O4_03, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_04 = BRepBuilderAPI_MakeEdge(arcCurve_04);
	Handle(AIS_Shape) aTarcCurve_04 = new AIS_Shape(TarcCurve_04);
	aTarcCurve_04->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_04, Standard_True);

	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O7 = radius4;//半径
								 // ///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
								 //Standard_Real R_O7 = R4_NLK;//半径
	gp_Circ Circle_O7_EC(axis7, R_O7);
	gp_Ax3 AxO7(axis7);
	gp_Cylinder Cylinder_O7(AxO7, R_O7);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_07 = GC_MakeArcOfCircle(Circle_O7_EC, CUT_O7_03, CUT_O7_01, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_07 = BRepBuilderAPI_MakeEdge(arcCurve_07);
	Handle(AIS_Shape) aTarcCurve_07 = new AIS_Shape(TarcCurve_07);
	aTarcCurve_07->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_07, Standard_True);


	// 创建圆 O2  拱部外侧，665+55半径
	gp_Pnt P_CO2_NLK(0.0, 0.0, 0.0); // 原点为圆心
	gp_Ax2 axis2(P_CO2_NLK, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real R2_NLK = 720.0; // 定义圆的半径
	gp_Circ CO2_NLK(axis2, R2_NLK);
	Handle(Geom_Circle) geomCircle2 = new Geom_Circle(CO2_NLK);
	TopoDS_Edge edge2 = BRepBuilderAPI_MakeEdge(geomCircle2);

	// 创建圆 O5 仰拱外侧圆
	gp_Ax2 axis5(pointP3, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	Standard_Real radius5 = radius3 + 65.0; // 半径为 1720cm+55cm
	gp_Circ circle5(axis5, radius5);
	Handle(Geom_Circle) geomCircle5 = new Geom_Circle(circle5);
	TopoDS_Edge edge5 = BRepBuilderAPI_MakeEdge(geomCircle5);


	//计算radius6 外侧过渡段圆半径
	//Standard_Real radius6 = solveForR4(alpha, radius, radius3, -pointP.Y());
	Standard_Real s = pow(radius5, 2) - pow(R2_NLK, 2) - pow(pointP3.Y(), 2) - 2 * pointP3.Y()*(height + 55 * cos(alpha));
	Standard_Real p = radius5 - R2_NLK - pointP3.Y() *(height + 55 * cos(alpha)) / R2_NLK;
	Standard_Real radius6 = s / (2 * p);

	// 创建圆 O6  过渡段外侧圆  左侧
	gp_Pnt centerO6(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis6(centerO6, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle6(axis6, radius6);
	Handle(Geom_Circle) geomCircle6 = new Geom_Circle(circle6);
	TopoDS_Edge edge6 = BRepBuilderAPI_MakeEdge(geomCircle6);


	// 创建圆 O8  过渡段外侧圆  右侧
	gp_Pnt centerO8(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	gp_Ax2 axis8(centerO8, gp_Vec(0.0, 0.0, 1.0)); // 原点为圆心，Z轴方向为法线方向
	gp_Circ circle8(axis8, radius6);
	Handle(Geom_Circle) geomCircle8 = new Geom_Circle(circle8);
	TopoDS_Edge edge8 = BRepBuilderAPI_MakeEdge(geomCircle8);


	///绘制拱墙外侧弧线
	Standard_Real R_O2 = R2_NLK;//半径
	gp_Circ Circle_O2_EC(axis2, R_O2);
	gp_Ax3 AxO2(axis2);
	gp_Cylinder Cylinder_O2(AxO2, R_O2);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O2 = new Geom_CylindricalSurface(Cylinder_O2);

	// 定义直线的起点和终点
	gp_Pnt startPoint6_2(0, 0, 0);
	gp_Pnt endPoint6_2(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction6_2(startPoint6_2, endPoint6_2);
	gp_Lin line6_2(startPoint6_2, direction6_2);
	// 创建直线的线段
	TopoDS_Edge lineEdge6_2 = BRepBuilderAPI_MakeEdge(line6_2, startPoint6_2, endPoint6_2);
	Handle(Geom_Line) Geom_lineEdge6_2 = new Geom_Line(line6_2);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O6_02(Geom_lineEdge6_2, geoCylinder_O2);//06 02交点
	gp_Pnt CUT_O6_02_R1 = ICC_O6_02.Point(1);
	gp_Pnt CUT_O6_02_R2 = ICC_O6_02.Point(2);
	gp_Pnt CUT_O6_02;
	CUT_O6_02.SetX(CUT_O6_02_R1.X());
	CUT_O6_02.SetY(CUT_O6_02_R1.Y());
	if (CUT_O6_02_R1.X() > CUT_O6_02_R2.X()) {
		CUT_O6_02.SetX(CUT_O6_02_R2.X());
		CUT_O6_02.SetY(CUT_O6_02_R2.Y());
	}//求得过渡圆弧的起点

	 // 定义直线的起点和终点
	gp_Pnt startPoint8_2(0, 0, 0);
	gp_Pnt endPoint8_2(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction8_2(startPoint8_2, endPoint8_2);
	gp_Lin line8_2(startPoint8_2, direction8_2);
	// 创建直线的线段
	TopoDS_Edge lineEdge8_2 = BRepBuilderAPI_MakeEdge(line8_2, startPoint8_2, endPoint8_2);
	Handle(Geom_Line) Geom_lineEdge8_2 = new Geom_Line(line8_2);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O8_02(Geom_lineEdge8_2, geoCylinder_O2);//08 02交点
	gp_Pnt CUT_O8_02_R1 = ICC_O8_02.Point(1);
	gp_Pnt CUT_O8_02_R2 = ICC_O8_02.Point(2);
	gp_Pnt CUT_O8_02;
	CUT_O8_02.SetX(CUT_O8_02_R1.X());
	CUT_O8_02.SetY(CUT_O8_02_R1.Y());
	if (CUT_O8_02_R1.X() < CUT_O8_02_R2.X()) {
		CUT_O8_02.SetX(CUT_O8_02_R2.X());
		CUT_O8_02.SetY(CUT_O8_02_R2.Y());
	}//求得过渡圆弧的起点

	Handle(Geom_TrimmedCurve) arcCurve_02 = GC_MakeArcOfCircle(Circle_O2_EC, CUT_O8_02, CUT_O6_02, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_02 = BRepBuilderAPI_MakeEdge(arcCurve_02);
	Handle(AIS_Shape) aTarcCurve_02 = new AIS_Shape(TarcCurve_02);
	aTarcCurve_02->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_02, Standard_True);

	///绘制仰拱外侧弧线
	Standard_Real R_O5 = radius5;//半径
	gp_Circ Circle_O5_EC(axis5, R_O5);
	gp_Ax3 AxO5(axis5);
	gp_Cylinder Cylinder_O5(AxO5, R_O5);//弧线所在圆柱面

	Handle(Geom_CylindricalSurface) geoCylinder_O5 = new Geom_CylindricalSurface(Cylinder_O5);

	// 定义直线的起点和终点
	gp_Pnt startPoint6_5(0, 1720 - 180 - 30 - height, 0);
	gp_Pnt endPoint6_5(-sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction6_5(startPoint6_5, endPoint6_5);
	gp_Lin line6_5(startPoint6_5, direction6_5);
	// 创建直线的线段
	TopoDS_Edge lineEdge6_5 = BRepBuilderAPI_MakeEdge(line6_5, startPoint6_5, endPoint6_5);
	Handle(Geom_Line) Geom_lineEdge6_5 = new Geom_Line(line6_5);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O6_05(Geom_lineEdge6_5, geoCylinder_O5);//06 02交点
	gp_Pnt CUT_O6_05_R1 = ICC_O6_05.Point(1);
	gp_Pnt CUT_O6_05_R2 = ICC_O6_05.Point(2);
	gp_Pnt CUT_O6_05;
	CUT_O6_05.SetX(CUT_O6_05_R1.X());
	CUT_O6_05.SetY(CUT_O6_05_R1.Y());
	if (CUT_O6_05_R1.X() > CUT_O6_05_R2.X()) {
		CUT_O6_05.SetX(CUT_O6_05_R2.X());
		CUT_O6_05.SetY(CUT_O6_05_R2.Y());
	}//求得过渡圆弧的起点

	 // 定义直线的起点和终点
	gp_Pnt startPoint8_5(0, 1720 - 180 - 30 - height, 0);
	gp_Pnt endPoint8_5(sin(alpha) * (R2_NLK - radius6), -cos(alpha) * (R2_NLK - radius6), 0);
	// 使用起点和方向创建直线
	gp_Vec direction8_5(startPoint8_5, endPoint8_5);
	gp_Lin line8_5(startPoint8_5, direction8_5);
	// 创建直线的线段
	TopoDS_Edge lineEdge8_5 = BRepBuilderAPI_MakeEdge(line8_5, startPoint8_5, endPoint8_5);
	Handle(Geom_Line) Geom_lineEdge8_5 = new Geom_Line(line8_5);
	// 计算直线和圆柱面之间的交点
	GeomAPI_IntCS ICC_O8_05(Geom_lineEdge8_5, geoCylinder_O5);//08 02交点
	gp_Pnt CUT_O8_05_R1 = ICC_O8_05.Point(1);
	gp_Pnt CUT_O8_05_R2 = ICC_O8_05.Point(2);
	gp_Pnt CUT_O8_05;
	CUT_O8_05.SetX(CUT_O8_05_R1.X());
	CUT_O8_05.SetY(CUT_O8_05_R1.Y());
	if (CUT_O8_05_R1.X() < CUT_O8_05_R2.X()) {
		CUT_O8_05.SetX(CUT_O8_05_R2.X());
		CUT_O8_05.SetY(CUT_O8_05_R2.Y());
	}//求得过渡圆弧的起点

	Handle(Geom_TrimmedCurve) arcCurve_05 = GC_MakeArcOfCircle(Circle_O5_EC, CUT_O6_05, CUT_O8_05, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_05 = BRepBuilderAPI_MakeEdge(arcCurve_05);
	Handle(AIS_Shape) aTarcCurve_05 = new AIS_Shape(TarcCurve_05);
	aTarcCurve_05->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_05, Standard_True);

	///绘制过渡段左侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O6 = radius6;//半径
	gp_Circ Circle_O6_EC(axis6, R_O6);
	gp_Ax3 AxO6(axis6);
	gp_Cylinder Cylinder_O6(AxO6, R_O6);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_06 = GC_MakeArcOfCircle(Circle_O6_EC, CUT_O6_02, CUT_O6_05, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_06 = BRepBuilderAPI_MakeEdge(arcCurve_06);
	Handle(AIS_Shape) aTarcCurve_06 = new AIS_Shape(TarcCurve_06);
	aTarcCurve_06->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_06, Standard_True);




	///绘制过渡段右侧弧线，已知弧段圆心、起点、半径
	Standard_Real R_O8 = radius6;//半径
	gp_Circ Circle_O8_EC(axis8, R_O8);
	gp_Ax3 AxO8(axis8);
	gp_Cylinder Cylinder_O8(AxO8, R_O8);//弧线所在圆柱面

	Handle(Geom_TrimmedCurve) arcCurve_08 = GC_MakeArcOfCircle(Circle_O8_EC, CUT_O8_05, CUT_O8_02, false);//绘制左侧连接圆弧
	TopoDS_Edge TarcCurve_08 = BRepBuilderAPI_MakeEdge(arcCurve_08);
	Handle(AIS_Shape) aTarcCurve_08 = new AIS_Shape(TarcCurve_08);
	aTarcCurve_08->SetColor(Quantity_Color(Quantity_NOC_RED));
	//myOccView->getContext()->Display(aTarcCurve_08, Standard_True);


	// 使用 BRepBuilderAPI_MakeWire 创建闭合曲线
	BRepBuilderAPI_MakeWire EC_WAIwireBuilder;
	EC_WAIwireBuilder.Add(TarcCurve_02);
	EC_WAIwireBuilder.Add(TarcCurve_06);
	EC_WAIwireBuilder.Add(TarcCurve_05);
	EC_WAIwireBuilder.Add(TarcCurve_08);
	EC_WAIwireBuilder.Build();

	if (EC_WAIwireBuilder.IsDone()) {
		TopoDS_Wire EC_WAIclosedWire = EC_WAIwireBuilder.Wire();

		// 现在 closedWire 就是你连接成闭合的连续线
	}
	else {
		// 处理创建失败的情况
	}

	//TopoDS_Wire sectorWirearc = makeWirearc.Wire();
	BRepBuilderAPI_MakeFace EC_WAIFacearc(EC_WAIwireBuilder);
	//TopoDS_Face EC_WAIFacearc = EC_WAIFacearc.Face();
	gp_Vec extrusionVecR1(0, 0, 600.0); // 沿着 Z 轴方向拉伸 600 个单位

	BRepPrimAPI_MakePrism EC_WAI_makearc1(EC_WAIFacearc, extrusionVecR1);
	TopoDS_Shape EC_WAI_arcShape1 = EC_WAI_makearc1.Shape();
	//TopoDS_Solid EC_WAI_arcbody = TopoDS::Solid(EC_WAI_arcShape1);
	//Handle(AIS_Shape) EC_WAI_Aisarcbody = new AIS_Shape(EC_WAI_arcbody);


	// 使用 BRepBuilderAPI_MakeWire 创建闭合曲线
	BRepBuilderAPI_MakeWire EC_NEIwireBuilder;
	EC_NEIwireBuilder.Add(TarcCurve_01);
	EC_NEIwireBuilder.Add(TarcCurve_04);
	EC_NEIwireBuilder.Add(TarcCurve_07);
	EC_NEIwireBuilder.Add(TarcCurve_03);
	EC_NEIwireBuilder.Build();

	if (EC_NEIwireBuilder.IsDone()) {
		TopoDS_Wire EC_NEIclosedWire = EC_NEIwireBuilder.Wire();

		// 现在 closedWire 就是你连接成闭合的连续线
	}
	else {
		// 处理创建失败的情况
	}

	BRepBuilderAPI_MakeFace EC_NEIFacearc(EC_NEIwireBuilder);

	BRepPrimAPI_MakePrism EC_NEI_makearc1(EC_NEIFacearc, extrusionVecR1);
	TopoDS_Shape EC_NEI_arcShape1 = EC_NEI_makearc1.Shape();
	TopoDS_Solid EC_NEI_arcbody = TopoDS::Solid(EC_NEI_arcShape1);
	Handle(AIS_Shape) EC_NEI_Aisarcbody = new AIS_Shape(EC_NEI_arcbody);

	BRepAlgoAPI_Cut cutOp1(EC_WAI_arcShape1, EC_NEI_arcShape1);
	TopoDS_Shape EC_arcShape = cutOp1.Shape();

	//Handle(AIS_Shape) EC_arcShape1 = new AIS_Shape(EC_arcShape);
	//EC_arcShape1->SetColor(Quantity_NOC_RED); // 设置颜色为红色
	//myOccView->getContext()->Display(EC_arcShape1, Standard_True); // 在场景中显示可视化对象


	// 定义四个点
	gp_Pnt p00(835, -213, 0);
	gp_Pnt p01(-835, -213, 0);
	gp_Pnt p02(-835, -213, 600);
	gp_Pnt p03(835, -213, 600);

	// 创建四边形面
	TopoDS_Vertex v00 = BRepBuilderAPI_MakeVertex(p00);
	TopoDS_Vertex v01 = BRepBuilderAPI_MakeVertex(p01);
	TopoDS_Vertex v02 = BRepBuilderAPI_MakeVertex(p02);
	TopoDS_Vertex v03 = BRepBuilderAPI_MakeVertex(p03);

	TopoDS_Wire wire6 = BRepBuilderAPI_MakePolygon(v00, v01, v02, v03, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																					   // 创建面
	BRepBuilderAPI_MakeFace face6(wire6);

	// 定义拉伸向量
	gp_Vec heightVec6(0, 1500, 0);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker6(face6.Shape(), heightVec6);
	TopoDS_Shape prismShape6 = prismMaker6.Shape();


	// 使用 BRepAlgoAPI_Cut 进行裁剪操作
	BRepAlgoAPI_Cut cut_operator4(EC_arcShape, prismShape6);
	cut_operator4.Build();
	TopoDS_Shape final_shape4 = cut_operator4.Shape();

	//// 将结果显示在视图中
	//myOccView->getContext()->Display(new AIS_Shape(final_shape4), Standard_True);


	// 定义四个点
	gp_Pnt p10(-835, -835, 300);
	gp_Pnt p11(835, -835, 300);
	gp_Pnt p12(835, 835, 300);
	gp_Pnt p13(-835, 835, 300);

	// 创建四边形面
	TopoDS_Vertex v10 = BRepBuilderAPI_MakeVertex(p10);
	TopoDS_Vertex v11 = BRepBuilderAPI_MakeVertex(p11);
	TopoDS_Vertex v12 = BRepBuilderAPI_MakeVertex(p12);
	TopoDS_Vertex v13 = BRepBuilderAPI_MakeVertex(p13);

	TopoDS_Wire wire7 = BRepBuilderAPI_MakePolygon(v10, v11, v12, v13, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																					   // 创建面
	BRepBuilderAPI_MakeFace face7(wire7);

	// 定义拉伸向量
	gp_Vec heightVec7(0, 0, -600);

	// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
	BRepPrimAPI_MakePrism prismMaker7(face7.Shape(), heightVec7);
	TopoDS_Shape prismShape7 = prismMaker7.Shape();


	// 使用 BRepAlgoAPI_Cut 进行裁剪操作
	BRepAlgoAPI_Cut cut_operator5(final_shape4, prismShape7);
	cut_operator5.Build();
	TopoDS_Shape final_shape5 = cut_operator5.Shape();

	// 将结果显示在视图中
	//Handle(AIS_Shape) final_shape6 = new AIS_Shape(final_shape5);
	//final_shape6->SetColor(Quantity_NOC_RED); // 设置颜色为红色
	//myOccView->getContext()->Display(final_shape6, Standard_True); // 在场景中显示可视化对象
	//myOccView->getContext()->Display(new AIS_Shape(final_shape5), Standard_True);





	// 创建一个组合
	TopoDS_Compound compound;
	BRep_Builder builder;
	builder.MakeCompound(compound);

	// 将实体添加到组合
	builder.Add(compound, final_shape2);
	builder.Add(compound, prismShape2);
	builder.Add(compound, prismShape3);
	builder.Add(compound, prismShape4);
	builder.Add(compound, prismShape5);
	builder.Add(compound, final_shape5);

	// 使用布尔操作进行并集
	BRepAlgoAPI_Fuse fuseOp(compound, compound);
	fuseOp.Build();

	if (fuseOp.IsDone()) {
		// 获取合并后的几何实体
		TopoDS_Shape mergedShape = fuseOp.Shape();
		myOccView->getContext()->Display(new AIS_Shape(mergedShape), Standard_True);
		// 现在 mergedShape 包含了合并后的整体


	}
	//绘制仰拱内侧外侧钢筋
	// 创建一个圆，圆心在（0, 1297, 300），半径为1725
	gp_Pnt center(0, 1297, 300);
	Standard_Real radius1 = 1725.0;
	Standard_Real radius2 = 1785.0;
	gp_Ax2 circleAxis(center, gp::DZ());
	Handle(Geom_Circle) circleGeom1 = new Geom_Circle(circleAxis, radius1);
	Handle(Geom_Circle) circleGeom2 = new Geom_Circle(circleAxis, radius2);



	// 初始平移量
	double translationDistance = 20.0;

	// 保存平移后的圆的集合
	std::vector<TopoDS_Shape> translatedCircles;

	// 循环平移
	for (int i = 0; i < 16; ++i) {
		// 创建平移变换
		gp_Trsf translation;
		translation.SetTranslation(gp_Vec(0.0, 0.0, (i + 0) * translationDistance));  // 每次平移20个单位沿Z轴

																					  // 将圆转换为边
		BRepBuilderAPI_MakeEdge edgeBuilder1(circleGeom1);
		TopoDS_Shape edgeShape1 = edgeBuilder1.Shape();

		BRepBuilderAPI_MakeEdge edgeBuilder2(circleGeom2);
		TopoDS_Shape edgeShape2 = edgeBuilder2.Shape();

		// 应用平移变换到第一个圆的边
		BRepBuilderAPI_Transform transform1(edgeShape1, translation);
		TopoDS_Shape translatedCircle1 = transform1.Shape();
		translatedCircles.push_back(translatedCircle1);

		// 应用平移变换到第二个圆的边
		BRepBuilderAPI_Transform transform2(edgeShape2, translation);
		TopoDS_Shape translatedCircle2 = transform2.Shape();
		translatedCircles.push_back(translatedCircle2);


		//裁剪左侧
		// 定义四个点
		gp_Pnt p14(-688, -17250, 17250);
		gp_Pnt p15(-688, 17250, 17250);
		gp_Pnt p16(-688, 17250, -17250);
		gp_Pnt p17(-688, -17250, -17250);

		// 创建四边形面
		TopoDS_Vertex v14 = BRepBuilderAPI_MakeVertex(p14);
		TopoDS_Vertex v15 = BRepBuilderAPI_MakeVertex(p15);
		TopoDS_Vertex v16 = BRepBuilderAPI_MakeVertex(p16);
		TopoDS_Vertex v17 = BRepBuilderAPI_MakeVertex(p17);

		TopoDS_Wire wire8 = BRepBuilderAPI_MakePolygon(v14, v15, v16, v17, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																						   // 创建面
		BRepBuilderAPI_MakeFace face8(wire8);

		// 定义拉伸向量
		gp_Vec heightVec8(-1785, 0, 0);

		// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
		BRepPrimAPI_MakePrism prismMaker8(face8.Shape(), heightVec8);
		TopoDS_Shape prismShape8 = prismMaker8.Shape();


		// 使用 BRepAlgoAPI_Cut 进行裁剪操作
		BRepAlgoAPI_Cut cut_operator6(translatedCircle1, prismShape8);
		cut_operator6.Build();
		TopoDS_Shape final_shape6 = cut_operator6.Shape();
		// 使用 BRepAlgoAPI_Cut 进行裁剪操作
		BRepAlgoAPI_Cut cut_operator7(translatedCircle2, prismShape8);
		cut_operator7.Build();
		TopoDS_Shape final_shape7 = cut_operator7.Shape();

		////显示仰拱钢筋
		//Handle(AIS_Shape) final_shape8 = new AIS_Shape(final_shape6);
		//final_shape8->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		//myOccView->getContext()->Display(final_shape8, Standard_True);
		////显示仰拱钢筋
		//Handle(AIS_Shape) final_shape9 = new AIS_Shape(final_shape7);
		//final_shape9->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		//myOccView->getContext()->Display(final_shape9, Standard_True);

		//裁剪右侧
		// 定义四个点
		gp_Pnt p18(688, -17250, 17250);
		gp_Pnt p19(688, 17250, 17250);
		gp_Pnt p20(688, 17250, -17250);
		gp_Pnt p21(688, -17250, -17250);

		// 创建四边形面
		TopoDS_Vertex v18 = BRepBuilderAPI_MakeVertex(p18);
		TopoDS_Vertex v19 = BRepBuilderAPI_MakeVertex(p19);
		TopoDS_Vertex v20 = BRepBuilderAPI_MakeVertex(p20);
		TopoDS_Vertex v21 = BRepBuilderAPI_MakeVertex(p21);

		TopoDS_Wire wire9 = BRepBuilderAPI_MakePolygon(v18, v19, v20, v21, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																						   // 创建面
		BRepBuilderAPI_MakeFace face9(wire9);

		// 定义拉伸向量
		gp_Vec heightVec9(1785, 0, 0);

		// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
		BRepPrimAPI_MakePrism prismMaker9(face9.Shape(), heightVec9);
		TopoDS_Shape prismShape9 = prismMaker9.Shape();


		// 使用 BRepAlgoAPI_Cut 进行裁剪操作
		BRepAlgoAPI_Cut cut_operator8(final_shape6, prismShape9);
		cut_operator8.Build();
		TopoDS_Shape final_shape8 = cut_operator8.Shape();
		// 使用 BRepAlgoAPI_Cut 进行裁剪操作
		BRepAlgoAPI_Cut cut_operator9(final_shape7, prismShape9);
		cut_operator9.Build();
		TopoDS_Shape final_shape9 = cut_operator9.Shape();

		////显示仰拱钢筋
		//Handle(AIS_Shape) final_shape10 = new AIS_Shape(final_shape8);
		//final_shape10->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		//myOccView->getContext()->Display(final_shape10, Standard_True);

		////显示仰拱钢筋
		//Handle(AIS_Shape) final_shape11 = new AIS_Shape(final_shape9);
		//final_shape11->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		//myOccView->getContext()->Display(final_shape11, Standard_True);

		//裁剪上侧
		// 定义四个点
		gp_Pnt p22(-10000, 1300, -10000);
		gp_Pnt p23(10000, 1300, -10000);
		gp_Pnt p24(10000, 1300, 10000);
		gp_Pnt p25(-10000, 1300, 10000);

		// 创建四边形面
		TopoDS_Vertex v22 = BRepBuilderAPI_MakeVertex(p22);
		TopoDS_Vertex v23 = BRepBuilderAPI_MakeVertex(p23);
		TopoDS_Vertex v24 = BRepBuilderAPI_MakeVertex(p24);
		TopoDS_Vertex v25 = BRepBuilderAPI_MakeVertex(p25);

		TopoDS_Wire wire10 = BRepBuilderAPI_MakePolygon(v22, v23, v24, v25, Standard_True); // 注意：最后一个参数是True，表示创建闭合的多边形

																							// 创建面
		BRepBuilderAPI_MakeFace face10(wire10);

		// 定义拉伸向量
		gp_Vec heightVec10(0, 1785, 0);

		// 使用 BRepPrimAPI_MakePrism 进行拉伸操作
		BRepPrimAPI_MakePrism prismMaker10(face10.Shape(), heightVec10);
		TopoDS_Shape prismShape10 = prismMaker10.Shape();


		// 使用 BRepAlgoAPI_Cut 进行裁剪操作
		BRepAlgoAPI_Cut cut_operator10(final_shape8, prismShape10);
		cut_operator10.Build();
		TopoDS_Shape final_shape10 = cut_operator10.Shape();
		// 使用 BRepAlgoAPI_Cut 进行裁剪操作
		BRepAlgoAPI_Cut cut_operator11(final_shape9, prismShape10);
		cut_operator11.Build();
		TopoDS_Shape final_shape11 = cut_operator11.Shape();

		//显示仰拱钢筋
		Handle(AIS_Shape) final_shape12 = new AIS_Shape(final_shape10);
		final_shape12->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		myOccView->getContext()->Display(final_shape12, Standard_True);

		//显示仰拱钢筋
		Handle(AIS_Shape) final_shape13 = new AIS_Shape(final_shape11);
		final_shape13->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		myOccView->getContext()->Display(final_shape13, Standard_True);


		//绘制左下角外侧钢筋
		// 定义两个点
		gp_Pnt p26(-688, -213, 600);
		gp_Pnt p27(-688, -413, 600);
		TopoDS_Edge anEdgeP2627 = BRepBuilderAPI_MakeEdge(p26, p27);

		//Handle(AIS_Shape) anAisEdgeP2627 = new AIS_Shape(anEdgeP2627);
		//anAisEdgeP2627->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		//myOccView->getContext()->Display(anAisEdgeP2627, Standard_True);

		// 定义两个点
		gp_Pnt p28(-738, -213, 300);
		gp_Pnt p29(-738, -413, 300);
		TopoDS_Edge anEdgeP2829 = BRepBuilderAPI_MakeEdge(p28, p29);

		Handle(AIS_Shape) anAisEdgeP2829 = new AIS_Shape(anEdgeP2829);
		anAisEdgeP2829->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		myOccView->getContext()->Display(anAisEdgeP2829, Standard_True);

		TopoDS_Edge anEdgeP2628 = BRepBuilderAPI_MakeEdge(p26, p28);

		// 计算平移步长向量
		gp_Vec directionVector(p26.X() - p28.X(), p26.Y() - p28.Y(), p26.Z() - p28.Z());

		gp_Vec stepVector = directionVector / 15;

		// 初始化起始点
		gp_Pnt currentPoint1 = p28;
		gp_Pnt currentPoint2 = p29;

		// 循环进行平移并显示每个线段
		for (int i = 2; i <= 16; i++)
		{
			// 平移当前点
			currentPoint1.Translate(stepVector);
			currentPoint2.Translate(stepVector);
			if (currentPoint1.Z() > p26.Z())
			{
				currentPoint1.SetZ(p26.Z());
				currentPoint2.SetZ(p26.Z());
			}

			// 创建沿路径平移的线段
			TopoDS_Edge translatedEdge = BRepBuilderAPI_MakeEdge(currentPoint1, currentPoint2);

			Handle(AIS_Shape) translatedEdge1 = new AIS_Shape(translatedEdge);
			translatedEdge1->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
			myOccView->getContext()->Display(translatedEdge1, Standard_True);

			// 如果已经到达目标点p26，则退出循环
			if (i == 16)
			{
				break;
			}

			// 在这里显示当前点
		}


		//绘制右下角外侧钢筋
		// 定义两个点
		gp_Pnt p30(688, -213, 600);
		gp_Pnt p31(688, -413, 600);
		TopoDS_Edge anEdgeP3031 = BRepBuilderAPI_MakeEdge(p30, p31);

		// 定义两个点
		gp_Pnt p32(738, -213, 300);
		gp_Pnt p33(738, -413, 300);
		TopoDS_Edge anEdgeP3233 = BRepBuilderAPI_MakeEdge(p32, p33);

		Handle(AIS_Shape) anAisEdgeP3233 = new AIS_Shape(anEdgeP3233);
		anAisEdgeP3233->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		myOccView->getContext()->Display(anAisEdgeP3233, Standard_True);

		TopoDS_Edge anEdgeP3032 = BRepBuilderAPI_MakeEdge(p30, p32);

		// 计算平移步长向量
		gp_Vec directionVector1(p30.X() - p32.X(), p30.Y() - p32.Y(), p30.Z() - p32.Z());

		gp_Vec stepVector1 = directionVector1 / 15;

		// 初始化起始点
		gp_Pnt currentPoint3 = p32;
		gp_Pnt currentPoint4 = p33;

		// 循环进行平移并显示每个线段
		for (int i = 2; i <= 16; i++)
		{
			// 平移当前点
			currentPoint3.Translate(stepVector1);
			currentPoint4.Translate(stepVector1);
			if (currentPoint3.Z() > p30.Z())
			{
				currentPoint3.SetZ(p30.Z());
				currentPoint4.SetZ(p30.Z());
			}

			// 创建沿路径平移的线段
			TopoDS_Edge translatedEdge = BRepBuilderAPI_MakeEdge(currentPoint3, currentPoint4);

			Handle(AIS_Shape) translatedEdge2 = new AIS_Shape(translatedEdge);
			translatedEdge2->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
			myOccView->getContext()->Display(translatedEdge2, Standard_True);

			// 如果已经到达目标点p30，则退出循环
			if (i == 16)
			{
				break;
			}

			// 在这里显示当前点
		}


		//绘制左下角内侧钢筋
		// 定义两个点
		gp_Pnt p34(-630, -213, 600);
		gp_Pnt p35(-580, -413, 600);
		TopoDS_Edge anEdgeP3435 = BRepBuilderAPI_MakeEdge(p34, p35);
		//Handle(AIS_Shape) anAisEdgeP3435 = new AIS_Shape(anEdgeP3435);
		//anAisEdgeP3435->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		//myOccView->getContext()->Display(anAisEdgeP3435, Standard_True);

		// 定义两个点
		gp_Pnt p36(-680, -213, 300);
		gp_Pnt p37(-630, -413, 300);
		TopoDS_Edge anEdgeP3637 = BRepBuilderAPI_MakeEdge(p36, p37);

		Handle(AIS_Shape) anAisEdgeP3637 = new AIS_Shape(anEdgeP3637);
		anAisEdgeP3637->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		myOccView->getContext()->Display(anAisEdgeP3637, Standard_True);

		TopoDS_Edge anEdgeP3436 = BRepBuilderAPI_MakeEdge(p34, p36);

		// 计算平移步长向量
		gp_Vec directionVector2(p34.X() - p36.X(), p34.Y() - p36.Y(), p34.Z() - p36.Z());

		gp_Vec stepVector2 = directionVector2 / 15;

		// 初始化起始点
		gp_Pnt currentPoint5 = p36;
		gp_Pnt currentPoint6 = p37;

		// 循环进行平移并显示每个线段
		for (int i = 2; i <= 16; i++)
		{
			// 平移当前点
			currentPoint5.Translate(stepVector2);
			currentPoint6.Translate(stepVector2);
			if (currentPoint5.Z() > p34.Z())
			{
				currentPoint5.SetZ(p34.Z());
				currentPoint6.SetZ(p34.Z());
			}

			// 创建沿路径平移的线段
			TopoDS_Edge translatedEdge = BRepBuilderAPI_MakeEdge(currentPoint5, currentPoint6);

			Handle(AIS_Shape) translatedEdge3 = new AIS_Shape(translatedEdge);
			translatedEdge3->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
			myOccView->getContext()->Display(translatedEdge3, Standard_True);

			// 如果已经到达目标点p34，则退出循环
			if (i == 16)
			{
				break;
			}

			// 在这里显示当前点
		}

		//绘制右下角内侧钢筋
		// 定义两个点
		gp_Pnt p38(630, -213, 600);
		gp_Pnt p39(580, -413, 600);
		TopoDS_Edge anEdgeP3839 = BRepBuilderAPI_MakeEdge(p38, p39);


		// 定义两个点
		gp_Pnt p40(680, -213, 300);
		gp_Pnt p41(630, -413, 300);
		TopoDS_Edge anEdgeP4041 = BRepBuilderAPI_MakeEdge(p40, p41);

		Handle(AIS_Shape) anAisEdgeP4041 = new AIS_Shape(anEdgeP4041);
		anAisEdgeP4041->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
		myOccView->getContext()->Display(anAisEdgeP4041, Standard_True);

		TopoDS_Edge anEdgeP3840 = BRepBuilderAPI_MakeEdge(p38, p40);

		// 计算平移步长向量
		gp_Vec directionVector3(p38.X() - p40.X(), p38.Y() - p40.Y(), p38.Z() - p40.Z());

		gp_Vec stepVector3 = directionVector3 / 15;

		// 初始化起始点
		gp_Pnt currentPoint7 = p40;
		gp_Pnt currentPoint8 = p41;

		// 循环进行平移并显示每个线段
		for (int i = 2; i <= 16; i++)
		{
			// 平移当前点
			currentPoint7.Translate(stepVector3);
			currentPoint8.Translate(stepVector3);
			if (currentPoint7.Z() > p38.Z())
			{
				currentPoint7.SetZ(p38.Z());
				currentPoint8.SetZ(p38.Z());
			}

			// 创建沿路径平移的线段
			TopoDS_Edge translatedEdge = BRepBuilderAPI_MakeEdge(currentPoint7, currentPoint8);

			Handle(AIS_Shape) translatedEdge4 = new AIS_Shape(translatedEdge);
			translatedEdge4->SetColor(Quantity_NOC_RED);  // 设置颜色为红色
			myOccView->getContext()->Display(translatedEdge4, Standard_True);

			// 如果已经到达目标点p38，则退出循环
			if (i == 16)
			{
				break;
			}

			// 在这里显示当前点
		}
	}
}