#include "Xian_shi.h"
#include <iostream>
#include <QStandardItemModel>
#include "CClass.h"
#include "Lu_ru.h"
using namespace std;
extern Class MyClass;
extern vector <Course> MyCourseVector(100);
extern string course_nameee[10];
static int ffx = 0;
string show_xx[100];

Xian_shi::Xian_shi(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("成绩管理");
	ui.label_13->setPixmap(QPixmap("lvlv.jpeg"));
	ui.label_13->setScaledContents(true);
	xian_ccc();
}

void Xian_shi::xian_ccc()
{
	if(ffx==0)  MyClass.ScoreShow();
	QStandardItemModel* model = new QStandardItemModel(this);
	QStandardItem* item = new QStandardItem();
	ui.xian_cheng->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
	for (int i = 0; i < Class::GetStudentCount() + 2; i++)
		model->appendRow(new QStandardItem(QString::fromStdString(show_xx[i])));
	ui.xian_cheng->setWordWrap(true);//自动换行
	ui.xian_cheng->setModel(model);
	ffx = 0;
}

void Xian_shi::dao_ru_2()
{
	ffx = 1;
	MyClass.ClearRecord();
	MyClass.InforRead_MySQL();
	xian_ccc();
}

void Xian_shi::dao_chu_2()
{
	MyClass.SavaDate_MySQL();
}



