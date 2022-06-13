#include "Pai_xu.h"
#include <iostream>
#include <QStandardItemModel>
#include "CClass.h"
using namespace std;
extern Class MyClass;
extern string show_xx[100];
extern string course_nameee[10];
//extern vector <Course> MyCourseVector(100);

Pai_xu::Pai_xu(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	//ui.pai_tiao->removeItem(Class::GetCourseCount() * 2 + 4);//最多显示
	this->setWindowTitle("成绩管理");
	ui.label->setPixmap(QPixmap("lvlv.jpeg"));
	ui.label->setScaledContents(true);
	ui.pai_tiao->clear();
	tiao_xu_pai();//更新下拉内容文本
	for (int i = 0; i < Class::GetCourseCount(); i++)
	{
		string xx, xx2;
		xx = course_nameee[i] + "升序";
		xx2 = course_nameee[i] + "降序";
		ui.pai_tiao->addItem(QString::fromStdString(xx));
		ui.pai_tiao->addItem(QString::fromStdString(xx2));
	}
	pai_xuxu();
}

void Pai_xu::tiao_xu_pai()
{
	ui.pai_tiao->addItem("总分升序");
	ui.pai_tiao->addItem("总分降序");
	ui.pai_tiao->addItem("平均分升序");
	ui.pai_tiao->addItem("平均分降序");
	//ui.pai_tiao->addItem("hhh");
}

void Pai_xu::pai_xuxu()
{
	ui.pai_tiao->removeItem(Class::GetCourseCount() * 2 + 4);
	MyClass.InforSort(ui.pai_tiao->currentIndex() + 1);//排序
	QStandardItemModel* model = new QStandardItemModel(this);
	QStandardItem* item = new QStandardItem();
	ui.pai_pai->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
	for (int i = 0; i < Class::GetStudentCount() + 3; i++)//中止+3 不+2
		model->appendRow(new QStandardItem(QString::fromStdString(show_xx[i])));
	ui.pai_pai->setWordWrap(true);//自动换行
	ui.pai_pai->setModel(model);
}

