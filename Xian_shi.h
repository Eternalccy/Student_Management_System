#pragma once

#include <QWidget>
#include "ui_Xian_shi.h"
#include <QListView>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>

class Xian_shi : public QWidget
{
	Q_OBJECT

public:
	Xian_shi(QWidget *parent = Q_NULLPTR);
    QListView* xian_cheng;
    QLabel* label_11;
    QPushButton* ru_ru;
    QPushButton* chu_chu;
    QLabel* label_12;
    QLabel* label_13;
    QPushButton* ru_ru_2;
    QPushButton* chu_chu_2;
private slots:
    void dao_ru_2();
    void dao_chu_2();
private:
    void xian_ccc();

private:
	Ui::Xian_shi ui;
};
