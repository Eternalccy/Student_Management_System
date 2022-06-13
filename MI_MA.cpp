#include "MI_MA.h"
#include "Geng_gai.h"
#include <iostream>
#include "Lu_ru.h"
using namespace std;
extern int mima_zz;
extern int bef_now;
static int ii = 0;
MI_MA::MI_MA(QWidget *parent)
	: QWidget(parent)
{
	ii = 0;
	ui.setupUi(this);
	this->setWindowTitle("成绩管理");
	ui.mima->setEchoMode(QLineEdit::Password);
	//Xian_shi* configWindow = new Xian_shi; configWindow->show();
}

void MI_MA::ti_jiao()
{
	ui.label_11->setText("");
	ii++;
	if (ui.mima->text() == "111")
	{
		
		this->close();
		switch (mima_zz)
		{
		case 1: {Lu_ru* configWindow = new Lu_ru; configWindow->show(); }break;
		case 4: {Geng_gai* configWindow = new Geng_gai; configWindow->show(); }break;
		default:break;
		}
	}
	else
	{
		if (3 - ii == 0)
		{
			ui.pushButton->setEnabled(false);
			ui.mima->setEnabled(false);
			ui.label_11->setText("来人！给朕拿下！");
		}
		else
		{
			mima_zz = 0;
			ui.mima->setText("");
			ui.label_11->setText("你还有 "+ QString::number(3 - ii) + " 次输入密码的机会~");
		}
	}
}

