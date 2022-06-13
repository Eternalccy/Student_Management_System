#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>
#include<vector>
#include "CStudent.h"

using namespace std;

class Class:public Student
{
private:
	string ClassID; //定义班级号
	string ClassName; //定义班级名
	vector <Student> StudentVector;
	//Student StudentVector[50];
	string Password = "111"; //密码
	static int ClassCount;

public :
	Class();
	Class(string id, string name);

	string GetPassword();
	void FillStudent(vector <Student> studentvector, int ii);
	void ClearRecord();
	void AddSum();
	int SearchByID(string id);
	void InforInset(int StudentItems, string id, string name, vector <Course> coursevector,string duo, string duo2); //成绩录入
	void ScoreShow();	//成绩显示
	void Modify(int returnnum, string xh, string xm, vector <Course> coursevector, string duo,string duo2);	//成绩修改
	void deleteRecord(int returnnum);	//成绩删除
	void InforSort(int sheng_jiang);		//成绩排序
	void SavaDate();		//输出文件
	void InforRead();		//文件读取数据
	void SavaDate_MySQL();		//输出文件
	void InforRead_MySQL();		//文件读取数据
	void Statis(int xx, float di, float gao);	//成绩统计
	void SearchShow(string nn, string ii, string gg, string aa);
};
