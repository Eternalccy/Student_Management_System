#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include <stdlib.h>
#include<windows.h>
#include<vector>

#include "CCourse.h"

using namespace std;

class Student:public Course
{
private:
	string StudentID; //定义学生学号
	string StudentName; //定义学生姓名
	string gender_; //定义学生姓名
	string age_;
	int age;
	//vector <Course> CourseVector;
	Course CourseVector[50];
	float StudentSum;  //定义成绩总和
	float StudentAver; //定义个人平均成绩

	static int StudentCount;

public :
	Student();
	Student(string id, string name);

	void SetStudent(string id, string name,string duo, string duo2);
	void FillCourse(vector <Course> coursevector);
	string GetStudentName();
	string GetStudentID();
	string GetStudentDUO();
	string GetStudentDUO2();
	Course GetCourse(int i);
	void SetCourseName(int i, string name);
	void SetCourseMark(int i, float val);
	float GetStudentSum();
	void SetStudentSum(float val);
	float GetStudentAver();
	void SetStudentAver(float val);

	static void SetStudentCount(int val);
	static int GetStudentCount();

};
