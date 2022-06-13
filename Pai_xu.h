#pragma once

#include <QWidget>
#include "ui_Pai_xu.h"

class Pai_xu : public QWidget
{
	Q_OBJECT

public:
	Pai_xu(QWidget *parent = Q_NULLPTR);
	QListView* pai_pai;
	QComboBox* pai_tiao;
	QTextEdit* textEdit;
	QLabel* label;
private slots:
	void pai_xuxu();
private:
	void tiao_xu_pai();

private:
	Ui::Pai_xu ui;
};
