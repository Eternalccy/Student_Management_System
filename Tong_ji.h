#pragma once

#include <QWidget>
#include "ui_Tong_ji.h"

class Tong_ji : public QWidget
{
	Q_OBJECT

public:
	Tong_ji(QWidget *parent = Q_NULLPTR);
    QListView* tong_xian;
    QLabel* tong_num;
    QTextEdit* tong_ave;
    QTextEdit* tong_top;
    QTextEdit* tong_bottom;
    QComboBox* tong_tiao;
    QLineEdit* score_1;
    QLabel* score_4;
    QLineEdit* score_3;
    QLabel* score_2;
    QLabel* label_13;
    QLabel* ti_shi_zz;
private slots:
    void tong_tong();
    void di();
    void gao();
private:
    void xian_xian22();
    void is_see(bool a);

private:
	Ui::Tong_ji ui;
};
