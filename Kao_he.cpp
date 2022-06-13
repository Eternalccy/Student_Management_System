#include "Kao_he.h"
#include <QMovie>
#include <iostream>
#include "Lu_ru.h"
#include "Xian_shi.h"
#include "Pai_xu.h"
#include "Geng_gai.h"
#include "Tong_ji.h"
#include "Cha_zhao.h"
#include "MI_MA.h"
//#include "G3_31.h"
using namespace std;
int mima_zz ;
int bef_now = 0;
//#pragma execution_character_set("utf-8")
Kao_he::Kao_he(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	this->setWindowTitle("成绩管理");
    ui.haoyun->setPixmap(QPixmap("lvlv.jpeg"));
    ui.haoyun->setScaledContents(true); 
	//ui.chou_9->setVisible(false);
}

void Kao_he::lu_lu2()
{
	bef_now = 1;
	Lu_ru* configWindow = new Lu_ru; configWindow->show();
}

void Kao_he::xian_xian2()
{
	bef_now = 1;
	Xian_shi* configWindow = new Xian_shi; configWindow->show();
}

void Kao_he::pai_pai2()
{
	bef_now = 1;
	Pai_xu* configWindow = new Pai_xu; configWindow->show();
}

void Kao_he::gai_gai2()//4
{
	bef_now = 1;
	mima_zz = 4;
	MI_MA* configWindow = new MI_MA; configWindow->show();
	//Geng_gai* configWindow = new Geng_gai; configWindow->show(); 
}

void Kao_he::tong_tong2()
{
	bef_now = 1;
	Tong_ji* configWindow = new Tong_ji; configWindow->show();
}

void Kao_he::cha_cha2()
{
	bef_now = 1;
	Cha_zhao* configWindow = new Cha_zhao; configWindow->show();
}
