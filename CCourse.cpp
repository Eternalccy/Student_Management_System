#include "CCourse.h"
#include <stdlib.h>
/*课程数静态变量初始化*/
int Course::CourseCount = 0;
/*课程平均分静态变量初始化*/
float Course::CourseAver = 0;

/*构造函数*/
Course::Course()
{
	CourseID = "";
	CourseName = "";
	CourseMark = 0;
}

/*构造函数*/
Course::Course(string id, string name, float mark)
{
	CourseID = id;
	CourseName = name;
	CourseMark = mark;
}

/*设置课程*/
void Course::SetCourse(string id, string name, float mark)
{
	CourseID = id;
	CourseName = name;
	CourseMark = mark;
}

/*设置课程分数*/
void Course::SetCourseMark(float mark)
{
	CourseMark = mark;
}

/*设置课程名*/
void Course::SetCourseName(string name)
{
	CourseName = name;
}

/*设置课程总分数*/
void Course::SetCourseAver(float val)
{
	CourseAver = val;
}

/*取得课程ID*/
string Course::GetCourseID()
{
	return CourseID;
}

/*取得课程名*/
string Course::GetCourseName()
{
	return CourseName;
}

/*取得课程分数*/
float Course::GetCourseMark()
{
	return CourseMark;
}

/*取得课程总分数*/
float Course::GetCourseAver()
{
	return CourseAver;
}

/*显示本课程*/
void Course::Course_Disp()
{
	cout << "ID=" << CourseID << "," << "Name=" << CourseName << ",""<<Mark=" << CourseMark << endl;
}

/*设置课程计数*/
void Course::SetCourseCount(int val)
{
	CourseCount = val;
}

/*取得课程计数*/
int Course::GetCourseCount()
{
	return CourseCount;
}

