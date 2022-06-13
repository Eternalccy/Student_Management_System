#include "Cha_zhao.h"
#include <iostream>
#include <QStandardItemModel>
#include "CClass.h"
using namespace std;
extern Class MyClass;
extern string show_xx[100];
extern int bef_now;
Cha_zhao::Cha_zhao(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowTitle("成绩管理");
	ui.label_9->setPixmap(QPixmap("lvlv.jpeg"));
	ui.label_9->setScaledContents(true);
    bool f_s;
    if (bef_now == 1) f_s = true;
    else f_s = false;
    ui.xx_gender->setVisible(f_s);
    ui.xx_age->setVisible(f_s);
    ui.gender_2->setVisible(f_s);
    ui.age_2->setVisible(f_s);
    ui.label_13->setVisible(f_s);
    ui.label_12->setVisible(f_s);

}

int Cha_zhao::xx_1()//判断选框是否可用
{
    if (ui.xx_name->isChecked() == true)
    {
        ui.name_2->setEnabled(true);
        return 1;
    }
    else
    {
        ui.name_2->setDisabled(true);
        ui.name_2->setText("");
        return 0;
    }
}

int Cha_zhao::xx_2()
{
    if (ui.xx_id->isChecked() == true)
    {
        ui.id_2->setEnabled(true);
        return 1;
    }
    else
    {
        ui.id_2->setDisabled(true);
        ui.id_2->setText("");
        return 0;
    }
}

int Cha_zhao::xx_3()
{
    if (ui.xx_gender->isChecked() == true)
    {
        ui.gender_2->setEnabled(true);
        return 1;
    }
    else
    {
        ui.gender_2->setDisabled(true);
        ui.gender_2->setText("");
        return 0;
    }
}

int Cha_zhao::xx_4()
{
    if (ui.xx_age->isChecked() == true)
    {
        ui.age_2->setEnabled(true);
        return 1;
    }
    else
    {
        ui.age_2->setDisabled(true);
        ui.age_2->setText("");
        return 0;
    }
}

int tiao_jian[5];//存放单个学生
string show_cc[100];
void Cha_zhao::sou_sou()
{
    //ui.ti_ti34->setText("");
    string aa, bb, cc,dd;
    int f, age;
    aa = ui.name_2->text().toStdString();
    bb = ui.id_2->text().toStdString();
    cc = ui.gender_2->text().toStdString();
    dd= ui.age_2->text().toStdString();
    tiao_jian[0] = xx_1();//条件用于判断复选框的判断个数
    tiao_jian[1] = xx_2();
    tiao_jian[2] = xx_3();
    tiao_jian[3] = xx_4();
    MyClass.SearchShow(aa,bb,cc,dd);
    QStandardItemModel* model = new QStandardItemModel(this);
    QStandardItem* item = new QStandardItem();
    ui.student_ti->setEditTriggers(QAbstractItemView::NoEditTriggers);//只读
    for (int i = 0; i < tiao_jian[4]; i++)
        model->appendRow(new QStandardItem(QString::fromStdString(show_cc[i])));
    ui.student_ti->setWordWrap(true);//自动换行
    ui.student_ti->setModel(model);
}
