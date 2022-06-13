#pragma once

#include <QWidget>
#include "ui_Geng_gai.h"

class Geng_gai : public QWidget
{
	Q_OBJECT

public:
	Geng_gai(QWidget *parent = Q_NULLPTR);
    QLineEdit* score_4;
    QLabel* label_15;
    QLineEdit* name_1;
    QLineEdit* score_5;
    QLabel* label_4;
    QLabel* label_8;
    QLabel* label_17;
    QLabel* label_5;
    QLineEdit* id_1;
    QLabel* label_22;
    QLineEdit* course_3;
    QLineEdit* score_6;
    QLabel* label_18;
    QLineEdit* course_6;
    QLabel* label_6;
    QLabel* label_7;
    QLineEdit* score_8;
    QLabel* label;
    QListView* student_ti;
    QLabel* label_3;
    QLabel* label_10;
    QLineEdit* score_2;
    QLineEdit* course_2;
    QLineEdit* course_5;
    QLineEdit* course_4;
    QLabel* label_12;
    QLabel* label_19;
    QLineEdit* score_3;
    QLabel* label_13;
    QLineEdit* course_8;
    QLabel* label_9;
    QLineEdit* course_1;
    QLineEdit* score_7;
    QLabel* label_20;
    QPushButton* tian_jia_2;
    QLabel* label_16;
    QLineEdit* course_7;
    QLabel* label_24;
    QLabel* label_23;
    QLineEdit* score_1;
    QLabel* label_14;
    QLabel* label_2;
    QLabel* label_21;
    QLineEdit* id_2;
    QLabel* label_25;
    QPushButton* tian_jia_3;
    QLabel* label_26;
    QPushButton* qie_mo;
    QLineEdit* age_1;
    QLabel* label_11;
    QLineEdit* gender_1;
    QLabel* label_27;
private slots:
    void geng_gai();
    void cha_stu();
    void qie_qie();
private:
    void Change_name2(QString thing);
    void chu_shi_nosee();
    void Xian_ti_shi2();

private:
	Ui::Geng_gai ui;
};
