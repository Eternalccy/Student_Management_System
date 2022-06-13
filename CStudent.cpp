#include "CStudent.h"
#include <stdlib.h>
/*学生数静态变量初始化*/
int Student::StudentCount = 0;

/*构造函数*/
Student::Student()
{
}

/*构造函数*/
Student::Student(string id, string name)
{
	StudentID = id;
	StudentName = name;
}

/*设置学生信息*/
void Student::SetStudent(string id, string name,string duo, string duo2)
{
	StudentID = id;
	StudentName = name;
	age_ = duo;
	gender_ = duo2;
}

extern int ff;
/*设置学生的全部课程信息*/
void Student::FillCourse(vector <Course> coursevector)//对应学生每一门课程成绩、信息
{
	unsigned int i;
	for (i = 0; i < ff; i++)
	{
		CourseVector[i].SetCourseMark(coursevector[i].GetCourseMark());
		CourseVector[i].SetCourseName(coursevector[i].GetCourseName());
	}
}

/*获得学生名*/
string Student::GetStudentName()
{
	return StudentName;

}

/*获得学生ID*/
string Student::GetStudentID()
{
	return StudentID;
}

string Student::GetStudentDUO()///急等更改
{
	return age_;
}

string Student::GetStudentDUO2()
{
	return gender_;
}

int shan_num = 0;
/*设置学生数清零或者++*/
void Student::SetStudentCount(int val)
{
	if (val == 0) StudentCount = val;
	else if (val == -100) { --StudentCount; shan_num = StudentCount; }
	else { ++StudentCount; shan_num = StudentCount;}
}

/*获得学生数*/
int Student::GetStudentCount()
{
	return StudentCount;
}

/*获得某学生第i门课程*/
Course Student::GetCourse(int i)
{
	return CourseVector[i];
}

/*设置学生第i门课程的成绩*/
void Student::SetCourseMark(int i,float val)
{
	CourseVector[i].SetCourseMark(val);
}

/*设置学生第i门课程名*/
void Student::SetCourseName(int i, string name)
{
	CourseVector[i].SetCourseName(name);
}

/*获得某学生总分*/
float Student::GetStudentSum()
{
	return StudentSum;
}

/*设置某学生总分*/
void Student::SetStudentSum(float val)
{
	StudentSum = val;
}

/*获得全部课程平均分*/
float Student::GetStudentAver()
{
	return StudentAver;
}

/*设置全部课程平均分*/
void Student::SetStudentAver(float val)
{
	StudentAver = val;
}
