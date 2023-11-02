#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include "dialog.h"
#include "dia2.h"
#include "EC.h"
#include "dia4.h"
#include "dia5.h"
#include "dia6.h"
#include "dia11.h"
#include "dia12.h"
#include "dia13.h"
#include "dia14.h"
#include "InvertedBrim.h"
#include "CenterGroove.h"
#include "SideGroove.h"
#pragma execution_character_set("UTF-8")
#include "FirstSuppSprayMix.h"
#include "dia4_2.h"
#include "dia12_1.h"
#include "dia12_2.h"
#include <QFormLayout>
#include "occview.h"
namespace Ui {
	class MainWindow;
}

class CompositeLining {//复合衬砌类
public:
	class InnerContour {//内轮廓类
	public:
		void setValue(int value) {

		}

		int getValue() const {

		}

	private:
	};
	class Trench {//沟槽类
	public:
		void setValue(int value) {
			innerValue = value;
		}

		int getValue() const {
			return innerValue;
		}

		void printValue() {
			std::cout << "Inner value: " << innerValue << std::endl;
		}

	private:
		int innerValue;
	};
	class SecondaryLining {//二衬类
	public:
		void setValue(double value1, double value2, double value3, double value4, double value5, double value6, double value7, double value8,
			double value9, double value10, double value11, double value12, double value13, double value14, double value15, double value16,
			double value17, double value18, double value19, double value20, double value21,
			double value22, double value23, double value24, double value25, double value26,
			double value27, double value28, double value29) {
			R2_NLK = value1;
			radius5 = value2;
			CUT_O6_05X = value3;
			CUT_O6_05Y = value4;
			CUT_O6_05Z = value5;
			alpha = value6;
			radius6 = value7;
			CUT_O4_01X = value8;
			CUT_O4_01Y = value9;
			CUT_O4_01Z = value10;
			CUT_O4_03X = value11;
			CUT_O4_03Y = value12;
			CUT_O4_03Z = value13;
			CUT_O7_01X = value14;
			CUT_O7_01Y = value15;
			CUT_O7_01Z = value16;
			CUT_O7_03X = value17;
			CUT_O7_03Y = value18;
			CUT_O7_03Z = value19;
			radius4 = value20;
			point_P3Y = value21;
			R1_NLK = value22;
			radius3 = value23;
			R1_R2_HD = value24;
			R3_R5_HD = value25;
			R3_TC = value26;
			GoucaoKuandu = value27;
			GoucaoGaocha = value28;
			JibenKuandu = value29;
		}

		double getValue(int index) const {
			switch (index) {
			case 0: return R2_NLK;
			case 1: return radius5;
			case 2: return CUT_O6_05X;
			case 3: return CUT_O6_05Y;
			case 4: return CUT_O6_05Z;
			case 5: return alpha;
			case 6: return radius6;
			case 7: return CUT_O4_01X;
			case 8: return CUT_O4_01Y;
			case 9: return CUT_O4_01Z;
			case 10: return CUT_O4_03X;
			case 11: return CUT_O4_03Y;
			case 12: return CUT_O4_03Z;
			case 13: return CUT_O7_01X;
			case 14: return CUT_O7_01Y;
			case 15: return CUT_O7_01Z;
			case 16: return CUT_O7_03X;
			case 17: return CUT_O7_03Y;
			case 18: return CUT_O7_03Z;
			case 19: return radius4;
			case 20: return point_P3Y;
			case 21: return CUT_O4_03Y;
			case 22: return R1_NLK;
			case 23: return radius3;
			case 24: return R1_R2_HD;
			case 25: return R3_R5_HD;
			case 26: return R3_TC;
			case 27: return GoucaoKuandu;
			case 28: return GoucaoGaocha;
			case 29: return JibenKuandu;
			default: return 0.0; // Handle out-of-range index
			}
		}

	private:
		double R2_NLK;
		double radius5;
		double CUT_O6_05X;
		double CUT_O6_05Y;
		double CUT_O6_05Z;
		double alpha;
		double radius6;
		double CUT_O4_01X;
		double CUT_O4_01Y;
		double CUT_O4_01Z;
		double CUT_O4_03X;
		double CUT_O4_03Y;
		double CUT_O4_03Z;
		double CUT_O7_01X;
		double CUT_O7_01Y;
		double CUT_O7_01Z;
		double CUT_O7_03X;
		double CUT_O7_03Y;
		double CUT_O7_03Z;
		double radius4;
		double point_P3Y;
		double  R1_NLK;
		double  radius3;
		double  R1_R2_HD;
		double  R3_R5_HD;
		double  R3_TC;
		double  GoucaoKuandu;
		double  GoucaoGaocha;
		double  JibenKuandu;

	};
	class BackfillingAndStepping {//回填与踏步类
	public:
		void setValue(int value) {
		}

		int getValue() const {
		}

	private:
	};
	class InitialExpenditure {//初支类
	public:
		void setValue(int value) {

		}

		int getValue() const {
		}

	private:
	};
	class WaterproofingAndDrainage {//防排水类
	public:
		void setValue(int value) {
		}

		int getValue() const {
		}

	private:
	};
};

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();
signals:
	/*void par1();
	void par2();
	void par2_1();
	void par2_2();
	void par3();
	void par4();
	void par4_1();
	void par4_2();
	void par5();
	void par6();
	void par11();
	void par12();
	void par12_1();
	void par12_2();
	void par13();
	void par14();
	void par15();*/
	void par1();
	void par2();
	void par2_1();
	void par2_2();
	void par3();
	void par3_1();
	void par3_2();
	void par4();
	void par5();
	void par6();
	void par11();
	void par12();
	void par12_1();
	void par12_2();
	void par13();
	void par14();
	void par15();
	private slots:
	void onTreeWidgetItemClicked1(QTreeWidgetItem *item, int column);
	void onTreeWidgetItemClicked2(QTreeWidgetItem *item, int column);
private:
	Ui::MainWindow *ui;
	dialog *dia_1;
	dia2 *dia_2;
	EC *dia_3;
	dia4 *dia_4;
	dia5 *dia_5;
	dia6 *dia_6;
	dia11 *dia_11;
	dia12 *dia_12;
	dia13 *dia_13;
	dia14 *dia_14;
	InvertedBrim *dia_15;
	CenterGroove *CenterGroove_1;
	SideGroove *SideGroove_1;
	FirstSuppSprayMix *dia_4_1;
	dia4_2 *dia_4_2;
	dia12_1 *dia_12_1;
	dia12_2 *dia_12_2;

	OccView* myOccView;
	CompositeLining::SecondaryLining secondaryLiningObj;

	TopoDS_Shape draw_cone(double radius_top, double radius_bottom, double height);
	/*TopoDS_Shape cone_shape;
	TopoDS_Shape cone_shape1;
	TopoDS_Shape cone_shape2;
	TopoDS_Shape result_shape; // 声明在类的私有成员中*/
	
private slots:
	void makeLine(const CenterGrooveCoordinates& coords);
	void makeTabu(const SquareCoordinates& coords);

	void handleSquareCoordinates(const SquareCoordinates& coords);
	void handleCenterGrooveCoordinates(const CenterGrooveCoordinates& coords);

	void makeFirstSurpport(const SquareCoordinates2& coords);
	void showFirstSurpport(const SquareCoordinates2& coords);

	void handleErchen(const Erchen& centercoords);
	void makeErchen(const Erchen& centercoords);

	void showInvertedBrim(const InvertedBrim2& coords);
	void makeInvertedBrim(const InvertedBrim2& coords);
	void makeInvertedBrim2(const InvertedBrim2& coords);
	void makeInvertedBrim3(const InvertedBrim2& coords);
};

#endif // MAINWINDOW_H

