#include "Kao_he.h"
#include <iostream>
#include <QtWidgets/QApplication>
using namespace std;
int main(int argc, char *argv[])
{
    cout << "start" << endl;
    QApplication a(argc, argv);
    Kao_he w;
    w.setWindowTitle("成绩管理");
    w.show();
    return a.exec();
}
