#pragma once

#include <QWidget>
#include "ui_Cha_zhao.h"
#include <QCheckBox>

class Cha_zhao : public QWidget
{
	Q_OBJECT

public:
	Cha_zhao(QWidget *parent = Q_NULLPTR);
    QLabel* label_7;
    QLabel* label_8;
    QLabel* label_12;
    QLabel* label_13;
    QLineEdit* age_2;
    QLineEdit* gender_2;
    QPushButton* sou_suo;
    QCheckBox* xx_gender;
    QLineEdit* name_2;
    QCheckBox* xx_id;
    QCheckBox* xx_age;
    QLabel* label_11;
    QLineEdit* id_2;
    QCheckBox* xx_name;
    QListView* student_ti;
    QLabel* label_9;
    QLabel* ti_ti34;
private slots:
    void sou_sou();
    int xx_1();
    int xx_2();
    int xx_3();
    int xx_4();

private:
	Ui::Cha_zhao ui;
};
