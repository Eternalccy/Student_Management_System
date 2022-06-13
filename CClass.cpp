#include "CClass.h"
#include <stdlib.h>
#include <QtWidgets/qpushbutton.h>
#include<mysql.h>
using namespace std;
/*班级数静态变量初始化*/
int Class::ClassCount = 0;
extern int bef_now;
/*构造函数*/
Class::Class()
{
}

/*构造函数*/
Class::Class(string id, string name)
{
	ClassID = id;
	ClassName = name;
}

/*填充班级中全部学生*/
void Class::FillStudent(vector <Student> studentvector, int ii)
{
	unsigned int i;

	for (i = 0; i < studentvector.size(); i++)
	{
		if(i==ii)
			StudentVector.insert(StudentVector.end(), studentvector[i]);
		//StudentVector[i].SetStudent(studentvector[i].GetStudentID(), studentvector[i].GetS);
	}
}

/*返回密码*/
string Class::GetPassword()
{
	return Password;
}

/*清空学生*/
void Class::ClearRecord()
{
	StudentVector.clear();
}

/*计算累加和*/
void Class::AddSum()
{
	int i, j;
	int StudentItems, CourseItems;
	float sumVal;
	StudentItems = Class::GetStudentCount();
	CourseItems = Class::GetCourseCount();
	//cout << StudentItems<<" "<< CourseItems << endl;
	for (i = 0; i < StudentItems; i++)
	{
		//cout << "ii"<<i << endl;
		sumVal=0;
		for (j = 0; j < CourseItems; j++)
		{
			sumVal += StudentVector[i].GetCourse (j).GetCourseMark() ;
			//cout << sumVal << endl;
		}
		StudentVector[i].SetStudentSum(sumVal);
		StudentVector[i].SetStudentAver(sumVal/ CourseItems);
		//cout << sumVal << "  " << sumVal / CourseItems << endl;
	}
}
extern string ber_stu_m_id[4];
/*通过学号返回数组下标*/
int Class::SearchByID(string id)
{
	int i;
	int StudentItems;

	StudentItems = StudentVector.size();

	for (i = 0; i <StudentItems; i++)
	{
		if (id == StudentVector[i].GetStudentID())
		{
			ber_stu_m_id[0] = StudentVector[i].GetStudentName();
			ber_stu_m_id[1] = StudentVector[i].GetStudentID();
			ber_stu_m_id[2] = StudentVector[i].GetStudentDUO();
			ber_stu_m_id[3] = StudentVector[i].GetStudentDUO2();
			return i;
		}
	}
	return -1;
}

/*成绩录入*/
void Class::InforInset(int StudentItems, string id, string name, vector <Course> coursevector, string duo, string duo2)	//第StudentItems个的成绩录入
{
	int i, j;
	int CourseItems = Class::GetCourseCount();
	vector <Student> MyStudentVector(StudentItems);
	MyStudentVector[StudentItems - 1].SetStudent(id, name, duo, duo2);//学生信息录入
	MyStudentVector[StudentItems-1].FillCourse(coursevector);//设置学生的全部课程信息
	FillStudent(MyStudentVector, StudentItems - 1);//填充班级中全部学生
}

extern string show_xx[100];
extern string course_nameee[10];
/*成绩显示*/
void Class::ScoreShow()//显示数据
{
	int i, j;
	float aa[10];
	int StudentItems, CourseItems;
	StudentItems = Class::GetStudentCount();
	CourseItems = Class::GetCourseCount();
	cout << StudentItems << endl;
	if(bef_now) show_xx[0] = "  姓名\t      学号\t年龄\t性别";//排头信息
	else show_xx[0] = "  姓名\t      学号\t";//排头信息
	for (i = 0; i < CourseItems; i++)
	{
		aa[i] = 0;
		show_xx[0] += "\t"+ course_nameee[i];
		cout << course_nameee[i] << endl;
		//course_nameee[i] = StudentVector[0].GetCourse(i).GetCourseName();
	}
	show_xx[0] += "\t平均分\t总分";
	AddSum();
	for (i = 0; i < StudentItems; i++)//显示学生课程信息
	{
		if(bef_now)
			show_xx[i + 1] = "  " + StudentVector[i].GetStudentName() + "\t" + StudentVector[i].GetStudentID()+"\t"+StudentVector[i].GetStudentDUO() + "     " + "\t" + StudentVector[i].GetStudentDUO2() + "     ";
		else
			show_xx[i + 1] = "  " + StudentVector[i].GetStudentName() + "\t" + StudentVector[i].GetStudentID() + "     ";
		for (j = 0; j < CourseItems; j++)
		{
			aa[j] += StudentVector[i].GetCourse(j).GetCourseMark();
			QString xx=QString::number(StudentVector[i].GetCourse(j).GetCourseMark());
			show_xx[i + 1] += "\t" + xx.toStdString();
		}
		show_xx[i + 1] += "\t"+ QString::number(StudentVector[i].GetStudentAver()).toStdString()//平均和总
			+ "\t" + QString::number(StudentVector[i].GetStudentSum()).toStdString()+"\n";
	}
	show_xx[StudentItems + 1] = "";
	for (j = 0; j < CourseItems; j++)
	{
		show_xx[StudentItems + 1] += course_nameee[j] + "平均分：" +//各科目的平均最底部
			QString::number((aa[j] / StudentItems)).toStdString() + "\t\t";
		//show_xx[StudentItems + 1] += StudentVector[0].GetCourse(j).GetCourseName()+"平均分：" +//各科目的平均最底部
		//	QString::number((aa[j] / StudentItems)).toStdString() + "\t\t";
	}	
}

/*成绩修改*/
void Class::Modify(int returnnum, string xh, string xm, vector <Course> coursevector, string duo,string duo2)
{
	int CourseItems, h, j;
	CourseItems = StudentVector[0].GetCourseCount();
	StudentVector[returnnum].SetStudent(xh, xm, duo, duo2);
	for (j = 0; j < CourseItems; j++)
	{
		StudentVector[returnnum].SetCourseMark(j, coursevector[j].GetCourseMark());
	}
}

/*成绩删除*/
void Class::deleteRecord(int returnnum)
{
	string xh, pass;
	int StudentItems,CourseItems, i, j, flag;
	StudentItems = StudentVector.size();
	CourseItems = StudentVector[0].GetCourseCount();
	for (i = returnnum; i < StudentItems - 1; i++)
	{
		
		string id = StudentVector[i + 1].GetStudentID();
		string name = StudentVector[i + 1].GetStudentName();
		string duo = StudentVector[i + 1].GetStudentDUO();
		string duo2 = StudentVector[i + 1].GetStudentDUO2();
		StudentVector[i].SetStudent(id, name,duo, duo2);
		for (j = 0; j < CourseItems; j++)
		{
			string course = StudentVector[i + 1].GetCourse(j).GetCourseName();
			float mark = StudentVector[i + 1].GetCourse(j).GetCourseMark();
			StudentVector[i].SetCourseName(j, course);
			StudentVector[i].SetCourseMark(j, mark);
		}
	}
	//StudentVector[i].SetStudentSum(StudentItems - 1);
	//StudentVector.pop_back();		
}

extern string show_gao[10], show_di[10], show_ave[10], show_all[100];
extern int show_all_num[10];
/*成绩统计*/
void Class::Statis(int xx, float di, float gao)
{
	int StudentItems = StudentVector[0].GetStudentCount();
	int CourseItems = StudentVector[0].GetCourseCount();
	switch (xx)
	{case 1://1 各课程最高成绩学生统计
	{
		show_gao[0] = "      各科最高分人信息";
		int max , flag, flag1, flag2;
		string km, kf, xm, xh;
		for (int i = 0; i < CourseItems; i++)
		{
			max = 0;
			for (int j = 0; j < StudentItems; j++)
			{
				if (StudentVector[j].GetCourse(i).GetCourseMark() > max)
				{
					max = StudentVector[j].GetCourse(i).GetCourseMark();
					flag = j;
					flag1 = i;
					km= course_nameee[i];
					//km = StudentVector[0].GetCourse(i).GetCourseName();
					xh = StudentVector[flag].GetStudentID();
					xm = StudentVector[flag].GetStudentName();
					kf = QString::number(StudentVector[flag].GetCourse(flag1).GetCourseMark()).toStdString();
				}
			}
			show_gao[i + 1] = km + "   " + xm + "   " + xh + "   " + kf;
		}
	}break;
	case 2://2 各课程最低成绩学生统计  
	{
		show_di[0] = "      各科最低分人信息";
		int min , flag, flag1, flag2;
		string km, kf, xm, xh;
		for (int i = 0; i < CourseItems; i++)
		{
			min = 200;
			for (int j = 0; j < StudentItems; j++)
			{
				if (StudentVector[j].GetCourse(i).GetCourseMark() < min)
				{
					min = StudentVector[j].GetCourse(i).GetCourseMark();
					flag = j;
					flag1 = i;
					km = course_nameee[i];
					//km = StudentVector[0].GetCourse(i).GetCourseName();
					xh = StudentVector[flag].GetStudentID();
					xm = StudentVector[flag].GetStudentName();
					kf = QString::number(StudentVector[flag].GetCourse(flag1).GetCourseMark()).toStdString();
				}
			}
			show_di[i + 1] = km + "   " + xm + "   " + xh + "   "+ kf;
		}
	}break;
	case 3://  3 个课程平均分 
	{
		for (int i = 0; i < CourseItems; i++)
		{
			float sum = 0;
			for (int j = 0; j < StudentItems; j++)
			{
				sum += StudentVector[j].GetCourse(i).GetCourseMark();
			}
			StudentVector[0].GetCourse(i).SetCourseAver(sum / StudentItems); 
			show_ave[i] = course_nameee[i] + "平均分：" + QString::number(StudentVector[0].GetCourse(i).GetCourseAver()).toStdString();
			//show_ave[i] = StudentVector[0].GetCourse(i).GetCourseName() + "平均分：" + QString::number(StudentVector[0].GetCourse(i).GetCourseAver()).toStdString();
		}
	}break;
	case 4:case 5:case 6://  4 超过平均分   5 不及格  6各分数段
	{
		int ss = 0, ff_s = 0;
		string km, kf, xm, xh,nl,xb;
		for (int i = 0; i < CourseItems; i++)
		{
			int flag2 = 0;
			float sum = 0;
			for (int j = 0; j < StudentItems; j++)
				sum += StudentVector[j].GetCourse(i).GetCourseMark();
			StudentVector[0].GetCourse(i).SetCourseAver(sum / StudentItems);//录入平均分
			for (int j = 0; j < StudentItems; j++)
			{
				if (xx == 4 && (StudentVector[j].GetCourse(i).GetCourseMark() > StudentVector[0].GetCourse(i).GetCourseAver())) ff_s = 1;
				if (xx == 5 && (StudentVector[j].GetCourse(i).GetCourseMark() < 60)) ff_s = 1;
				if (xx == 6 && ((StudentVector[j].GetCourse(i).GetCourseMark() <= gao) && (StudentVector[j].GetCourse(i).GetCourseMark() >= di))) ff_s = 1;
				if (ff_s)
				{
					km = course_nameee[i];
					//km = StudentVector[0].GetCourse(i).GetCourseName();
					xh = StudentVector[j].GetStudentID();
					xm = StudentVector[j].GetStudentName();
					kf = QString::number(StudentVector[j].GetCourse(i).GetCourseMark()).toStdString();
					nl = StudentVector[j].GetStudentDUO();
					xb = StudentVector[j].GetStudentDUO2();
					if (bef_now) show_all[ss] = km + "\t" + xm + "\t" + xh + "\t" + nl + "\t" + xb + "\t" + kf;
					else show_all[ss] = km + "\t" + xm + "\t" + xh + "\t" + kf;
					flag2++;
					ss++;
				}
				ff_s = 0;
			}
			show_all_num[i] = flag2;
			show_all[ss++] = "\t\t\t\t\t\t人数："+ QString::number(show_all_num[i]).toStdString() + "\n";
		}
	}break;
	default:break;
	}
}

/*成绩排序*/
void Class::InforSort(int sheng_jiang)//1、2总分升   3、4平均分  5--课程
{
	int i, j, f = 0;
	Student temp;

	int StudentItems = StudentVector[0].GetStudentCount();
	//cout << StudentVector[0].GetCourseAver() << endl;
	AddSum();
	for (i = 0; i < StudentItems - 1; i++)
	{
		for (j = 0; j < StudentItems - 1 - i; j++)
		{
			f = 0;
			switch (sheng_jiang)//排序选择
			{
			case 1:if (StudentVector[j].GetStudentSum() > StudentVector[j + 1].GetStudentSum())  f = 1; break;
			case 2:if (StudentVector[j].GetStudentSum() < StudentVector[j + 1].GetStudentSum())  f = 1; break;
			case 3:if (StudentVector[j].GetStudentAver() > StudentVector[j + 1].GetStudentAver())  f = 1; break;
			case 4:if (StudentVector[j].GetStudentAver() < StudentVector[j + 1].GetStudentAver())  f = 1; break;
			//case 5:break;
			case 5:if (StudentVector[j].GetCourse(0).GetCourseMark() > StudentVector[j + 1].GetCourse(0).GetCourseMark())  f = 1; break;//各科成绩升降
			case 6:if (StudentVector[j].GetCourse(0).GetCourseMark() < StudentVector[j + 1].GetCourse(0).GetCourseMark())  f = 1; break;
			case 7:if (StudentVector[j].GetCourse(1).GetCourseMark() > StudentVector[j + 1].GetCourse(1).GetCourseMark())  f = 1; break;
			case 8:if (StudentVector[j].GetCourse(1).GetCourseMark() < StudentVector[j + 1].GetCourse(1).GetCourseMark())  f = 1; break;
			case 9:if (StudentVector[j].GetCourse(2).GetCourseMark() > StudentVector[j + 1].GetCourse(2).GetCourseMark())  f = 1; break;
			case 10:if (StudentVector[j].GetCourse(2).GetCourseMark() < StudentVector[j + 1].GetCourse(2).GetCourseMark())  f = 1; break;
			case 11:if (StudentVector[j].GetCourse(3).GetCourseMark() > StudentVector[j + 1].GetCourse(3).GetCourseMark())  f = 1; break;
			case 12:if (StudentVector[j].GetCourse(3).GetCourseMark() < StudentVector[j + 1].GetCourse(3).GetCourseMark())  f = 1; break;
			}
			if (f)
			{
				temp = StudentVector[j];
				StudentVector[j] = StudentVector[j+1];
				StudentVector[j+1] = temp;
			}
		}
	}
	if(bef_now) show_xx[0] = "  姓名\t      学号\t年龄\t性别 ";//格式显示、赋值show_xx
	else show_xx[0] = "  姓名\t      学号\t ";//格式显示、赋值show_xx
	for (i = 0; i < StudentVector[0].GetCourseCount(); i++)
	{
		show_xx[0] += "\t" + course_nameee[i];
		//show_xx[0] += "\t" + StudentVector[0].GetCourse(i).GetCourseName();
	}
	int zzz[2], zzf=0;
	if (StudentItems % 2 == 1)
	{
		zzf = 1;
		zzz[0] = (StudentItems + 1) / 2 - 1;//下标
	}
	else
	{
		zzf = 0;
		zzz[0] = StudentItems / 2 - 1;
		zzz[1] = (StudentItems + 2) / 2 - 1;
	}
	show_xx[StudentItems + 2] = "";
	show_xx[0] += "\t平均分\t总分";
	for (i = 0; i < StudentItems ; i++)//格式显示、赋值show_xx
	{
		if (bef_now) 
			show_xx[i + 1] = "  " + StudentVector[i].GetStudentName() + "\t" + StudentVector[i].GetStudentID() + "     " + StudentVector[i].GetStudentDUO() + "\t" + StudentVector[i].GetStudentDUO2() + "     ";
		else 
			show_xx[i + 1] = "  " + StudentVector[i].GetStudentName() + "\t" + StudentVector[i].GetStudentID() + "     " ;
		for (j = 0; j < StudentVector[i].GetCourseCount(); j++)//格式显示、赋值show_xx
		{
			show_xx[i + 1] += "\t" + QString::number(StudentVector[i].GetCourse(j).GetCourseMark()).toStdString();
			if ( zzz[0] == i && sheng_jiang ==9&&j==2)//aa
			{
				if (zzf)
					show_xx[StudentItems + 2] += StudentVector[i].GetCourse(j).GetCourseName() + "中值：" +
					QString::number(StudentVector[i].GetCourse(j).GetCourseMark()).toStdString() + "\t\t";
				else
				{
					float zzzx = StudentVector[i].GetCourse(j).GetCourseMark() + StudentVector[i+1].GetCourse(j).GetCourseMark();
					show_xx[StudentItems + 2] += StudentVector[i].GetCourse(j).GetCourseName() + "中值：" +
						QString::number(zzzx/2).toStdString() + "\t\t";
				}
			}
		
		}
		show_xx[i + 1] += "\t" + QString::number(StudentVector[i].GetStudentAver()).toStdString()//平均和总
			+ "\t" + QString::number(StudentVector[i].GetStudentSum()).toStdString() + "\n";
	}
	
	//ScoreShow();
}

/*输出文件*/
void Class::SavaDate_MySQL()
{
	const int SQL_MAX = 1024;		//指定最长SQL指令长度
	char sqlStr[SQL_MAX];			// 存储sql语句
	char sqlStr_head[SQL_MAX];		// 存储sql语句
	int i, j;
	int ReturnFlag = 0;
	MYSQL mysql;//数据库句柄
	MYSQL_RES* res;//查询结果集
	MYSQL_ROW row;//记录结构体
				  //初始化数据库

	mysql_init(&mysql);
	//设置字符编码
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	//连接数据库
	if (mysql_real_connect(&mysql, "localhost", "root", "2016222016", "stu_man", 3307, NULL, 0) == NULL)
	{
		printf("错误原因:%s\n", mysql_error(&mysql));
		printf("连接失败!\n");
		exit(-1);
	}

	//删除原记录表
	snprintf(sqlStr, SQL_MAX, "drop table test;");
	//printf("\n删除记录表sql语句：%s\n", sqlStr);
	ReturnFlag = mysql_query(&mysql, sqlStr);
	//printf("执行删除记录表语句，删除返回结果：%d\n", ReturnFlag);
	if (ReturnFlag) {
		printf("删除记录表失败！失败原因：%s\n", mysql_error(&mysql));
		//		return false;
	}
	else
		printf("删除记录表成功！\n");

	//生成新记录表
	int StudentItems = StudentVector.size();
	int CourseItems = StudentVector[0].GetCourseCount();
	if(bef_now)
	   snprintf(sqlStr, SQL_MAX, "create table if not exists test (id varchar(255) ,name varchar(255) ,defen varchar(255) ,xueyuan varchar(255) ,");
	else 
		snprintf(sqlStr, SQL_MAX, "create table if not exists test (id varchar(255) ,name varchar(255) ,");
	for (i = 0; i < CourseItems; i++)
	{
		snprintf(sqlStr, SQL_MAX, "%s %s float,", sqlStr, StudentVector[0].GetCourse(i).GetCourseName().c_str());
	}
	snprintf(sqlStr, SQL_MAX, "%s %s;", sqlStr, "primary key(id))");
	//printf("\n创建记录表sql语句：%s\n", sqlStr);
	ReturnFlag = mysql_query(&mysql, sqlStr);
	//printf("执行创建记录表语句，创建返回结果：%d\n", ReturnFlag);
	if (ReturnFlag) {
		printf("创建记录表失败！失败原因：%s\n", mysql_error(&mysql));
		//		return false;
	}
	else
		printf("创建记录表成功！\n");

	// 插入记录
	//printf("向新建数据表填充所有记录：\n");
	if(bef_now)
	    snprintf(sqlStr_head, SQL_MAX, "insert into test (id ,name,defen,xueyuan ");
	else
		snprintf(sqlStr_head, SQL_MAX, "insert into test (id ,name ");
	for (i = 0; i < CourseItems; i++)
	{
		snprintf(sqlStr_head, SQL_MAX, "%s ,%s", sqlStr_head, StudentVector[0].GetCourse(i).GetCourseName().c_str());
	}
	cout << StudentItems << endl;
	snprintf(sqlStr_head, SQL_MAX, "%s %s ", sqlStr_head, ") values(");
	for (i = 0; i < StudentItems; i++)
	{
		if(bef_now)
		  snprintf(sqlStr, SQL_MAX, "%s '%s', '%s', '%s', '%s' ", sqlStr_head, StudentVector[i].GetStudentID().c_str(), StudentVector[i].GetStudentName().c_str(), StudentVector[i].GetStudentDUO().c_str(), StudentVector[i].GetStudentDUO2().c_str());
		else
			snprintf(sqlStr, SQL_MAX, "%s '%s', '%s' ", sqlStr_head, StudentVector[i].GetStudentID().c_str(), StudentVector[i].GetStudentName().c_str());
		for (j = 0; j < CourseItems; j++)
		{
			snprintf(sqlStr, SQL_MAX, "%s ,%f ", sqlStr, StudentVector[i].GetCourse(j).GetCourseMark());
		}
		snprintf(sqlStr, SQL_MAX, "%s %s", sqlStr, ");");
		//printf("插入sql语句：%s\n", sqlStr);
		ReturnFlag = mysql_real_query(&mysql, sqlStr, (unsigned long)strlen(sqlStr));
		//printf("执行插入语句，插入返回结果：%d\n", ReturnFlag);
		if (ReturnFlag) {
			printf("插入表数据失败！失败原因：%s\n", mysql_error(&mysql));
			//		return false;
		}
		//printf("插入表项：id=%s，成功！\n", StudentVector[i].GetStudentID().c_str());
	}
	//关闭数据库
	cout << "数据向MySql导出完成！" << endl << endl;
	mysql_close(&mysql);
}

extern string course_nameee[10];
void Class::InforRead_MySQL()//从MySQL导入
{
	const int SQL_MAX = 1024;		//指定最长SQL指令长度
	char sqlStr[SQL_MAX];			// 存储sql语句
	char sqlStr_head[SQL_MAX];		// 存储sql语句
	int i, j, index = 0;
	int ReturnFlag = 0;
	MYSQL mysql;//数据库句柄
	MYSQL_RES* res;//查询结果集
	MYSQL_ROW row;//记录结构体
				  //初始化数据库

	mysql_init(&mysql);
	//设置字符编码
	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
	//连接数据库
	if (mysql_real_connect(&mysql, "localhost", "root", "2016222016", "stu_man", 3307, NULL, 0) == NULL)
	{
		printf("错误原因:%s\n", mysql_error(&mysql));
		printf("连接ppp失败!\n");
		exit(-1);
	}
	vector <Student> MyStudentVector;
	vector <Course> MyCourseVector;
	Student MyStudent;
	Course MyCourse;
	int StudentItems = 0;
	int CourseItems = 0;
	float  aa[10];

	//查询记录字段名
	snprintf(sqlStr, SQL_MAX, "show full fields from test;");
	printf("\n查询记录字段名sql语句：%s\n", sqlStr);
	ReturnFlag = mysql_query(&mysql, sqlStr);
	printf("执行查询记录字段名语句，查询返回结果：%d\n", ReturnFlag);
	res = mysql_store_result(&mysql);
	//cout << mysql_fetch_row(res) << endl;
	if (bef_now) show_xx[0] = "  姓名\t      学号\t年龄\t性别";//排头信息
	else  show_xx[0] = "  姓名\t      学号\t";//排头信息
	while (row = mysql_fetch_row(res))
	{
		if (bef_now)
		{
			if (index >= 4)
			{
				aa[CourseItems] = 0;
				MyCourse.SetCourse(std::to_string(CourseItems), row[0], 0);
				MyCourseVector.push_back(MyCourse);
				course_nameee[CourseItems] = MyCourse.GetCourseName();//存储课程名字
				show_xx[0] += "\t" + MyCourse.GetCourseName();
				cout << course_nameee[CourseItems] << endl;
				CourseItems++;
			}
			index++;
			cout << CourseItems << endl;
		}
		else
		{
			if (index >= 2)
			{
				aa[CourseItems] = 0;
				MyCourse.SetCourse(std::to_string(CourseItems), row[0], 0);
				MyCourseVector.push_back(MyCourse);
				course_nameee[CourseItems] = MyCourse.GetCourseName();//存储课程名字
				show_xx[0] += "\t" + MyCourse.GetCourseName();
				CourseItems++;
			}
			index++;
		}
	}
	show_xx[0] += "\t平均分\t总分";
	//MyStudentVector[0].FillCourse(MyCourseVector);
	mysql_free_result(res);
	printf("\n查询记录字段名成功！\n");
	MyStudent.FillCourse(MyCourseVector);

	//查询记录
	snprintf(sqlStr, SQL_MAX, "select * from test;");
	//printf("\n查询sql语句：%s\n", sqlStr);
	ReturnFlag = mysql_query(&mysql, sqlStr);
	//printf("执行查询语句，查询返回结果：%d\n\n", ReturnFlag);
	//获取结果集
	res = mysql_store_result(&mysql);
	while (row = mysql_fetch_row(res))
	{
		float sum = 0;
		if (bef_now)
		{
			MyStudent.SetStudent(row[0], row[1], row[2], row[3]);
			show_xx[StudentItems + 1] = "  " + MyStudent.GetStudentName() + "\t" + MyStudent.GetStudentID() + "     " + MyStudent.GetStudentDUO() + "\t" + MyStudent.GetStudentDUO2() + "     ";
		}
		else
		{
			MyStudent.SetStudent(row[0], row[1], "", "");
			show_xx[StudentItems + 1] = "  " + MyStudent.GetStudentName() + "\t" + MyStudent.GetStudentID() +"     ";
		}
		for (i = 0; i < CourseItems; i++)
		{
			MyStudent.SetCourseMark(i, atof(row[i + 4]));
			sum += MyStudent.GetCourse(i).GetCourseMark();
			aa[i] += MyStudent.GetCourse(i).GetCourseMark();
			show_xx[StudentItems + 1] += "\t" + QString::number(MyStudent.GetCourse(i).GetCourseMark()).toStdString();
			//show_xx[StudentItems + 1] += MyCourseVector[j].GetCourseName() + "平均分：" +//各科目的平均最底部
			//	QString::number((aa[j] / StudentItems)).toStdString() + "\t\t";
		}
		show_xx[StudentItems + 1] += "\t" + QString::number(sum / CourseItems).toStdString()//平均和总
			+ "\t" + QString::number(sum).toStdString() + "\n";
		MyStudentVector.push_back(MyStudent);
		FillStudent(MyStudentVector, StudentItems);
		StudentItems++;
		MyStudent.SetStudentCount(10);//改变学生人数
	}
	cout << "  ren " << StudentItems << endl;

	show_xx[StudentItems + 1] = "";
	for (int j = 0; j < CourseItems; j++)
	{
		show_xx[StudentItems + 1] += MyCourseVector[j].GetCourseName() + "平均分：" +//各科目的平均最底部
			QString::number((aa[j] / StudentItems)).toStdString() + "\t\t";
	}
	//	cout << endl;
	printf("查询记录内容成功！\n");

	//释放结果集
	mysql_free_result(res);
	//关闭数据库
	cout << "数据自MySql导入完成！" << endl << endl;
	mysql_close(&mysql);
	Class::SetCourseCount(CourseItems);
	AddSum();
}

extern string show_cc[100];
extern int tiao_jian[5];
extern int shan_num;
void Class::SearchShow(string nn, string ii, string gg, string aa)
{
	//int StudentItems = StudentVector.size();
	int StudentItems = shan_num;
	int CourseItems = StudentVector[0].GetCourseCount();
	if(bef_now) show_cc[0] = "  姓名\t      学号\t年龄\t性别";//排头信息
	else  show_cc[0] = "  姓名\t      学号\t";//排头信息
	for (int i = 0; i < CourseItems; i++)
	{
		show_cc[0] += "\t" + course_nameee[i];
		//StudentVector[0].GetCourse(i).GetCourseName();
	}
		//show_cc[0] += "\t" + StudentVector[0].GetCourse(i).GetCourseName();
	show_cc[0] += "\t平均分\t总分";
	int j = 1, a, b;
	a = tiao_jian[0] + tiao_jian[1] + tiao_jian[2] + tiao_jian[3];
	string  xm, xh,xb,nl;
	for (int i = 0; i < StudentItems; i++)
	{
		xm = StudentVector[i].GetStudentName();
		xh= StudentVector[i].GetStudentID();
		if (bef_now)
		{
			xb = StudentVector[i].GetStudentDUO2();
			nl = StudentVector[i].GetStudentDUO();
		}
		b = 0;
		int idx, idx2, idx3=1, idx4=1;
		xm == nn ? idx = 0 : idx = 1;
		xh == ii ? idx2 = 0 : idx2 = 1;
		if (bef_now)
		{
			xb == gg ? idx3 = 0 : idx3 = 1;
			nl == aa ? idx4 = 0 : idx4 = 1;
		}
		if (tiao_jian[0] == 1 && idx == 0) b++;
		if (tiao_jian[1] == 1 && idx2 == 0) b++;
		if (bef_now)
		{
			if (tiao_jian[2] == 1 && idx3 == 0) b++;
			if (tiao_jian[3] == 1 && idx4 == 0) b++;
		}
		if (a == b)
		{
			AddSum();
			if (bef_now) show_cc[j] = "  " + xm + "\t" + xh + "\t" + nl + "\t" + xb + "     ";
			else  show_cc[j] = "  " + xm + "\t" + xh +"     ";
			for (int k = 0; k < CourseItems; k++)
			{
				QString xx = QString::number(StudentVector[i].GetCourse(k).GetCourseMark());
				show_cc[j] += "\t" + xx.toStdString();
			}
			show_cc[j++ ] += "\t" + QString::number(StudentVector[i].GetStudentAver()).toStdString()//平均和总
					+ "\t" + QString::number(StudentVector[i].GetStudentSum()).toStdString() + "\n";
		}
	}
	tiao_jian[4] = j;
}
