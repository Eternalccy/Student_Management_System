#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<windows.h>

using namespace std;

class Course
{
private:
	string CourseID; //定义课程编号
	string CourseName; //定义课程名
	float CourseMark; //定义课程成绩
	static int CourseCount;//课程数量
	static float CourseAver;	//课程平均分

public :
	Course();
	Course(string id, string name, float mark);
	void SetCourse(string id, string name, float mark);
	void SetCourseName(string name);
	void SetCourseMark(float mark);
	string GetCourseID();
	string GetCourseName();
	float GetCourseMark();
	void Course_Disp();
	static void SetCourseCount(int val);
	static int GetCourseCount();
	static void SetCourseAver(float val);
	static float GetCourseAver();
};
