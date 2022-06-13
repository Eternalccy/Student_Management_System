#include "Geng_gai.h"
#include <iostream>
#include <QStandardItemModel>
#include "CClass.h"
using namespace std;
extern Class MyClass;
extern string course_nameee[10];
extern QString student_tii_shi[50];
static QLineEdit* now;
static int is_cha_stu = 0, xx = 0;
string ber_stu_m_id[4];
static int hh = 0;
extern int bef_now;
Geng_gai::Geng_gai(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("成绩管理");
	ui.label_21->setPixmap(QPixmap("lvlv.jpeg"));
	ui.label_21->setScaledContents(true);
	for (int i = 0; i < Class::GetCourseCount(); i++)//权限开放
	{
		string thing;
		thing = "course_" + to_string(i+1);
		Change_name2(QString::fromStdString(thing));
		now->setText(QString::fromStdString(course_nameee[i]));
	}
	if (bef_now == 0)
	{
		ui.label_11->setVisible(false);
		ui.label_27->setVisible(false);
		ui.gender_1->setVisible(false);
		ui.age_1->setVisible(false);
	}
	Xian_ti_shi2();
}

void Geng_gai::Change_name2(QString thing)
{
	QString objectNameBtn = thing;
	now = this->findChild<QLineEdit*>(objectNameBtn);
}

void Geng_gai::chu_shi_nosee()
{
	for (int i = 0; i < 8; i++)//权限开放
	{
		string thing;
		thing = "course_" + to_string(i+1);
		Change_name2(QString::fromStdString(thing));
		now->setEnabled(false);
		thing = "score_" + to_string(i+1);
		Change_name2(QString::fromStdString(thing));
		now->setText("0");
		now->setEnabled(false);
	}
	ui.tian_jia_2->setEnabled(false);
	ui.tian_jia_3->setEnabled(true);
	ui.id_2->setEnabled(true);
	ui.id_1->setEnabled(false);
	ui.name_1->setEnabled(false);
	ui.age_1->setEnabled(false);
	ui.gender_1->setEnabled(false);
	ui.id_1->setText("");
	ui.name_1->setText("");
	ui.gender_1->setText("");
	ui.age_1->setText("");

}

void Geng_gai::cha_stu()//查找学生
{
	if (hh % 2 == 0)
	{
		is_cha_stu = MyClass.SearchByID(ui.id_2->text().toStdString());
		if (is_cha_stu >= 0)
		{
			ui.id_2->setEnabled(false);
			ui.name_1->setEnabled(true);
			ui.age_1->setEnabled(true);
			ui.gender_1->setEnabled(true);
			ui.id_1->setEnabled(true);
			ui.tian_jia_2->setEnabled(true);
			ui.tian_jia_3->setEnabled(false);
			ui.name_1->setText(QString::fromStdString(ber_stu_m_id[0]));//天上原本信息
			ui.id_1->setText(QString::fromStdString(ber_stu_m_id[1]));
			ui.age_1->setText(QString::fromStdString(ber_stu_m_id[2]));
			ui.gender_1->setText(QString::fromStdString(ber_stu_m_id[3]));
			for (int i = 0; i < Class::GetCourseCount(); i++)//权限开放
			{
				string thing;
				thing = "score_" + to_string(i + 1);
				Change_name2(QString::fromStdString(thing));
				now->setEnabled(true);
			}
		}
	}
	else
	{
		is_cha_stu = MyClass.SearchByID(ui.id_2->text().toStdString());
		if (is_cha_stu >= 0) ui.id_1->setText(ui.id_2->text());
		else ui.id_1->setText("不存在~");
	}

}

void Geng_gai::qie_qie()
{
	hh++;
	if (hh % 2 == 1)
	{
		ui.tian_jia_2->setText("删  除  学  生  成  绩");
		chu_shi_nosee();
		ui.tian_jia_2->setEnabled(true);
	}
	else
	{
		chu_shi_nosee();
		ui.tian_jia_2->setText("成  绩  更  改  完  成");
	}

}

void Geng_gai::geng_gai()//更改信息
{
	if (hh % 2 == 0)
	{
		string xh, xm, nl, n2;
		xh = ui.id_1->text().toStdString();
		xm = ui.name_1->text().toStdString();
		nl = ui.age_1->text().toStdString();
		n2 = ui.gender_1->text().toStdString();
		vector <Course> MyCourseVect(Class::GetCourseCount());
		float score_8[8] = { 0 };
		for (int i = 0; i < Class::GetCourseCount(); i++)
		{
			string thing;
			thing = "score_" + to_string(i + 1);
			Change_name2(QString::fromStdString(thing));
			score_8[i] = now->text().toFloat();
			MyCourseVect[i].SetCourseMark(score_8[i]);
		}
		MyClass.Modify(is_cha_stu, xh, xm, MyCourseVect, nl, n2);//更改此时学生成绩
		chu_shi_nosee();
		student_tii_shi[xx++] = QString::fromStdString("原：" + ber_stu_m_id[0] + "  " + ber_stu_m_id[1] + "\n");
		student_tii_shi[xx++] = QString::fromStdString("现：" + xm + "  " + xh + "\n\n\t        信息更改成功！\n");
		student_tii_shi[xx++] = QString::fromStdString("—————————————————\n");
	}
	else
	{
		MyClass.deleteRecord(is_cha_stu);
		MyClass.SetStudentCount(-100);
		student_tii_shi[xx++] = QString::fromStdString(ui.id_2->text().toStdString() + "删除成功！\n");
		student_tii_shi[xx++] = QString::fromStdString("—————————————————\n");
		chu_shi_nosee();
	}
	Xian_ti_shi2();
}

void Geng_gai::Xian_ti_shi2()//显示录入成功提示
{
	QStandardItemModel* model = new QStandardItemModel(this);
	QStandardItem* item = new QStandardItem();
	ui.student_ti->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
	for (int i = 0; i < xx; i++)
		model->appendRow(new QStandardItem(student_tii_shi[i]));
	ui.student_ti->setWordWrap(true);//自动换行
	ui.student_ti->setModel(model);
}



