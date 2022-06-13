#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Kao_he.h"
#include <QLabel>
#include <QPushButton>
#include "Lu_ru.h"
#include "Xian_shi.h"
#include "Pai_xu.h"
#include "Geng_gai.h"
#include "Tong_ji.h"
#include "Cha_zhao.h"
//#include "G3_31.h"

class Kao_he : public QMainWindow
{
    Q_OBJECT

public:
    Kao_he(QWidget *parent = Q_NULLPTR);
    QLabel* label;
    QLabel* haoyun;
    QPushButton* chou_2;
    QPushButton* chou_3;
    QPushButton* chou_4;
    QPushButton* chou_5;
    QPushButton* chou_7;
    QPushButton* chou_8;
    QPushButton* chou_9;
    QPushButton* chou_6;
    QPushButton* chou_10;
    QPushButton* chou_11;
    QPushButton* chou_12;
    QPushButton* chou_13;
    QPushButton* chou_14;
private slots:    
    void lu_lu2();
    void xian_xian2();
    void pai_pai2();
    void gai_gai2();
    void tong_tong2();
    void cha_cha2();
    //QString Get_name();///得到控件名字
    //void Change_name(QString thing);///对控件内容更改
    //void Change_color(int x);///对控件内容更改

private:
    Ui::Kao_heClass ui;
};
