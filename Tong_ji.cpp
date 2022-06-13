#include "Tong_ji.h"
#include <iostream>
#include <QStandardItemModel>
#include "CClass.h"
extern Class MyClass;
extern string course_nameee[10];
extern int bef_now;
string show_gao[10], show_di[10], show_ave[10], show_all[100];
int show_all_num[10];
Tong_ji::Tong_ji(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("成绩管理");
	ui.label_13->setPixmap(QPixmap("lvlv.jpeg"));
	ui.label_13->setScaledContents(true);
	is_see(false);
	MyClass.Statis(1, -5, -5);
	MyClass.Statis(2, -5, -5);
	MyClass.Statis(3, -5, -5);//平均
	string aa, bb, cc = "";
	aa = show_gao[0]+"\n"; bb = show_di[0] + "\n";
	for (int i = 0; i < Class::GetCourseCount(); i++)
	{
		aa = aa + show_gao[i+1] + "\n";
		bb = bb + show_di[i+1] + "\n";
		cc = cc + show_ave[i] + "\n";
	}
	ui.tong_top->setText(QString::fromStdString(aa));
	ui.tong_bottom->setText(QString::fromStdString(bb));
	ui.tong_ave->setText(QString::fromStdString(cc));
	MyClass.Statis(4, -5, -5);
	xian_xian22();
	ui.ti_shi_zz->setText("");
}

void Tong_ji::xian_xian22()
{
	int sum = 0;
	QStandardItemModel* model = new QStandardItemModel(this);
	QStandardItem* item = new QStandardItem();
	ui.tong_xian->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
	for (int i = 0; i < Class::GetCourseCount(); i++)
		sum += show_all_num[i];
	sum += Class::GetCourseCount();
	if(bef_now) model->appendRow(new QStandardItem(" 课程\t姓名\t学号\t年龄\t性别\t分数"));
	else model->appendRow(new QStandardItem(" 课程\t姓名\t学号\t分数"));
	for (int i = 0; i < sum; i++)
		model->appendRow(new QStandardItem(QString::fromStdString(show_all[i])));
	ui.tong_xian->setWordWrap(true);//自动换行
	ui.tong_xian->setModel(model);
	ui.tong_num->setText("");
	//ui.tong_num->setText("人数："+QString::number(sum - Class::GetCourseCount()));
}

void Tong_ji::is_see(bool a)
{
	ui.score_1->setVisible(a);
	ui.score_2->setVisible(a);
	ui.score_3->setVisible(a);
	ui.score_4->setVisible(a);
}

static int ff1 = 0, ff2 = 0;
void Tong_ji::di()
{
	ff1 = 1;
	tong_tong();
}

void Tong_ji::gao()
{
	ff2 = 2;
	tong_tong();
}
static int zzxs = 0;
void Tong_ji::tong_tong()
{
	ui.ti_shi_zz->setText("");
	if (ui.tong_tiao->currentIndex() == 0) { is_see(false); MyClass.Statis(4, -5, -5); }
	else if (ui.tong_tiao->currentIndex() == 1) { is_see(false); MyClass.Statis(5, -5, -5); }
	else
	{
		if (zzxs == 0) { ff1 = 1; ff2 = 2; }
		zzxs++;
		is_see(true);
		if ((ff1 + ff2) == 3)
		{
			if (ui.score_1->text().toFloat() <= ui.score_3->text().toFloat())
			{
				MyClass.Statis(6, ui.score_1->text().toFloat(), ui.score_3->text().toFloat());
			}
			else ui.ti_shi_zz->setText("请正确填写分数段~");
		}
		else ui.ti_shi_zz->setText("请填写分数段~");
	}
	xian_xian22();
}

