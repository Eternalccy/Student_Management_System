#pragma once

#include <QWidget>
#include "ui_MI_MA.h"
#include <QtWidgets/qapplication.h>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qlineedit.h>

class MI_MA : public QWidget
{
	Q_OBJECT

public:
	MI_MA(QWidget *parent = Q_NULLPTR);
	QLineEdit* mima;
	QLabel* label_11;
	QLabel* label_12;
	QPushButton* pushButton;
	QLabel* label_13;
private slots:
	void ti_jiao();

private:
	Ui::MI_MA ui;
};
