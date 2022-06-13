#include "Lu_ru.h"
#include <iostream>
#include <QStandardItemModel>
#include "CClass.h"
string course_nameee[10];
using namespace std;
static QLineEdit* now;
static int cc_x[8];
Class MyClass;
static Student MyStudent;
QString student_tii_shi[50];
static vector <Course> MyCourseVector(100);
int ff = 0;
static int kk = 0;
extern int bef_now;
Lu_ru::Lu_ru(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("成绩管理");
	ui.label_21->setPixmap(QPixmap("lvlv.jpeg"));
	ui.label_21->setScaledContents(true);
	ff = 0;
	kk = 0;
	ui.textEdit->setVisible(false);
	bool f_n;
	if (bef_now == 1) f_n = true;
	else f_n = false;
	ui.label_27->setVisible(f_n);//性别
	ui.gender_1->setVisible(f_n);
	ui.label_28->setVisible(f_n);//年龄
	ui.age_1->setVisible(f_n);
}

void Lu_ru::que_course()//确认课程数量和名称
{
	MyClass.ClearRecord();//清空学生信息
	Student::SetStudentCount(0);//学生数量清零
	int s = 0;
	for (int i = 1; i <= 8; i++)  cc_x[i - 1] = 0;
	//cout << "course start" << endl;
	for (int i = 1; i <= 8; i++)
	{
		string thing;
		thing = "course_" + to_string(i);
		Change_name(QString::fromStdString(thing));
		if (now->text() != "") cc_x[i - 1] = 1;
		else cc_x[i - 1] = 0;
		s += cc_x[i - 1];
		now->setEnabled(false);
	}
	//cout << "score en start" << endl;
	for (int i = 1; i <= 8; i++)
	{
		if (cc_x[i - 1] == 1)
		{
			string thing;
			thing = "score_" + to_string(i);
			Change_name(QString::fromStdString(thing));
			now->setEnabled(true);
		}
	}
	//cout << "course cun start" << endl;
	if (s != 0)
	{
		ff = s;
		Class::SetCourseCount(s);//存入课程数量
		ui.pushButton->setEnabled(false);
		ui.tian_jia_2->setEnabled(true);
	}
}
void Lu_ru::lu_score()
{
	vector <Course> MyCourseVect(Class::GetCourseCount());//存入课程名字
	for (int i = 0; i < Class::GetCourseCount(); i++)
	{
		string thing;
		thing = "course_" + to_string(i + 1);
		Change_name(QString::fromStdString(thing));
		course_nameee[i] = now->text().toStdString();
		MyCourseVect[i].SetCourse(to_string(i), now->text().toStdString(), 0);
		//cout << MyCourseVector[i].GetCourseName() << endl;
	}
	Student::SetStudentCount(1);//下一位学生
	int StudentItems= Student::GetStudentCount();
	string id, name;
	float score_8[8] = {0};
	name = ui.name_1->text().toStdString();
	id = ui.id_1->text().toStdString();
	for (int i = 0; i < Class::GetCourseCount(); i++)
	{
		string thing;
		thing = "score_" + to_string(i + 1);
		Change_name(QString::fromStdString(thing));
		score_8[i] = now->text().toFloat();
		MyCourseVect[i].SetCourseMark(score_8[i]);//录入此时学生成绩
	}
	//cout << StudentItems << endl;
	if (bef_now)
		MyClass.InforInset(StudentItems, id, name, MyCourseVect,
			ui.age_1->text().toStdString(), ui.gender_1->text().toStdString());//信息录入（收尾工作）
	else MyClass.InforInset(StudentItems, id, name, MyCourseVect, "", "");
	student_tii_shi[Student::GetStudentCount() - 1] = "第" + QString::number(StudentItems) + "位：" + ui.name_1->text() + "  成绩录入成功！\n";
	Xian_ti_shi();
	ui.label_26->setText(QString::number(StudentItems));
	//MyClass.SavaDate();
}


void Lu_ru::Change_name(QString thing)
{
	QString objectNameBtn = thing;
	now = this->findChild<QLineEdit*>(objectNameBtn);
}

void Lu_ru::Xian_ti_shi()//显示录入成功提示
{
	QStandardItemModel* model = new QStandardItemModel(this);
	QStandardItem* item = new QStandardItem();
	ui.student_ti->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
	for (int i = 0; i < Class::GetStudentCount(); i++)
		model->appendRow(new QStandardItem(student_tii_shi[i]));
	ui.student_ti->setWordWrap(true);//自动换行
	ui.student_ti->setModel(model);
}
