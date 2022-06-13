#pragma once

#include <QWidget>
#include "ui_Lu_ru.h"
#include <QtWidgets/qapplication.h>
#include <QListView>
#include <QtWidgets/qtextedit.h>

class Lu_ru : public QWidget
{
	Q_OBJECT

public:
	Lu_ru(QWidget *parent = Q_NULLPTR);
    QLabel* label;
    QLabel* label_2;
    QPushButton* pushButton;
    QLineEdit* name_1;
    QLineEdit* id_1;
    QLabel* label_3;
    QLineEdit* score_1;
    QLineEdit* score_4;
    QLabel* label_4;
    QLineEdit* score_2;
    QLabel* label_5;
    QLineEdit* score_3;
    QLabel* label_6;
    QLabel* label_7;
    QLineEdit* score_5;
    QLineEdit* score_6;
    QLabel* label_8;
    QLineEdit* score_7;
    QLabel* label_9;
    QLineEdit* score_8;
    QLabel* label_10;
    QLabel* label_12;
    QLineEdit* course_8;
    QLabel* label_13;
    QLineEdit* course_5;
    QLabel* label_14;
    QLineEdit* course_6;
    QLabel* label_15;
    QLabel* label_16;
    QLineEdit* course_1;
    QLineEdit* course_2;
    QLabel* label_17;
    QLineEdit* course_3;
    QLineEdit* course_7;
    QLabel* label_18;
    QLineEdit* course_4;
    QLabel* label_19;
    QPushButton* tian_jia_2;
    QLabel* label_20;
    QListView* student_ti;
    QLabel* label_21;
    QLabel* label_22;
    QLabel* label_23;
    QLabel* label_24;
    QLabel* label_25;
    QLabel* label_26;
    QLabel* label_27;
    QLineEdit* gender_1;
    QLabel* label_28;
    QLineEdit* age_1;
    QTextEdit* textEdit;

private slots:
    void que_course();
    void lu_score();
private:
    void Change_name(QString thing);
    void Xian_ti_shi();

private:
	Ui::Lu_ru ui;
};
