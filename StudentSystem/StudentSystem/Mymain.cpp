
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include"CS_grade.h"
#include"student.h"
#include"UI.h"

void insert_grade(cnoIndex *cnohead, stuIndex *stuhead)
{
	cnoGrade *c1;
	c1 = new cnoGrade();
	cout << "请依次输入课程号，学号，成绩：" << endl;
	cin >> c1->cno >> c1->sno >> c1->grade;
	stuIndex *p = new stuIndex();
	p = find(stuhead, c1->sno % 100);
	int c = judge_sno(p->head, c1->sno);
	if (c == 0)
	{
		cout << "你输入的学号不存在！" << endl;
		return;
	}
	else
	{
		if (judge_cno(cnohead, c1->cno))//判断课程号是否存在
		{
			cnoIndex *p;
			p = cnohead->next;
			while (p->cno != c1->cno)
				p = p->next;
			cnoGrade *q;
			q = p->head;
			if (!q->next)
			{
				c1->next = q->next;
				q->next = c1;
				cout << "添加成功" << endl;
				return;
			}
			while (q->next && (q->next->sno <= c1->sno))
				q = q->next;
			if (!q)
			{
				c1->next = q->next;
				q->next = c1;
				cout << "添加成功" << endl;
				return;
			}
			if (q->sno == c1->sno)
			{
				cout << "你添加的课程成绩已存在，是否替换？输入0不替换，输入1替换" << endl;
				int i;
				cin >> i;
				if (i)
				{
					q->grade = c1->grade;
					cout << "成绩替换成功！" << endl;
					return;
				}
				else
				{
					cout << "成绩没有替换！" << endl;
					return;
				}
			}
			c1->next = q->next;
			q->next = c1;
			cout << "添加成功" << endl;
			return;
		}
		else
		{
			cout << "你输入的课程号不存在！" << endl;
		}
	}
}

void delete_stu(cnoIndex *cnohead, stuIndex *stuhead)
{
	cout << "请输入要删除的学号:" << endl;
	int sno;
	cin >> sno;
	stuIndex *p = find(stuhead, sno % 100);
	int c = judge_sno(p->head, sno);
	if (!c)
	{
		cout << "你输入的学号不存在，删除失败！" << endl;
		return;
	}
	delete_sno(stuhead, sno);
	delete_sno_grade(cnohead, sno);
}

void txt_grade(cnoIndex *cnohead, stuIndex *stuhead)
{
	int sno;
	cout << "输入要打印的学生号：";
	cin >> sno;
	stuIndex *temp = find(stuhead, sno % 100);
	if (judge_sno(temp->head, sno))
	{
		ofstream outstuf;
		outstuf.open("D:\\学生成绩管理系统\\单个学生成绩信息\\\\" + to_string(sno) + ".txt", ios::out);
		outstuf << "这里是" << sno << "同学的成绩单：" << endl;
		outstuf << "课程号     课程名       成绩      学分 " << endl;
		cnoIndex *cnop;
		cnoGrade *q;
		cnop = cnohead;
		while (cnop->next)
		{
			q = cnop->next->head;
			while (q->next)
			{
				if (q->next->sno == sno)
				{
					outstuf << cnop->next->cno << "     "<<cnop->next->cname<<"      " << q->next->grade<<"        "<<cnop->next->credit << endl;
					break;
				}
				q = q->next;
			}
			cnop = cnop->next;
		}
		cout << "打印学生成绩单成功" << endl;
	}
	else
	{
		cout << "你输入的学生号不存在" << endl;
	}
}



int main()
{
	stuIndex *stuhead;
	stuhead = new stuIndex();
	stuhead->head = NULL;
	stuhead->next = NULL;
	int n = 100;
	stuhead = create_stuIndex(stuhead, n);
	stuhead = loadStu(stuhead);

	cnoIndex *cnohead;
	cnohead = new cnoIndex();
	cnohead->head = NULL;
	cnohead->next = NULL;
	cnohead = load_cno(cnohead);//导入课程信息
	cnohead = load_grade(cnohead);//导入成绩
	nocopy_cs(cnohead);//将重复的课程号和学号摔掉


	//int sno;
/*
			0添加学生
			1删除学生
			2添加功课
			3删除功课
			4输入学生某门功课成绩
			5统计分数
			6将所有功课的学生成绩做成表格输出txt
			7生成通讯录
			8某个同学的成绩单输出 
			9统计成绩的文档
			10课程信息
			11成绩信息
			12学生信息
			*/
	int i;
	while (1)
	{
		UI();
		cin >> i;
		switch (i)
		{
			
		case 0:
			insert_sno(stuhead);
			break;
		case 1:
			delete_stu(cnohead,stuhead);
			break;
		case 2:
			insert_cno(cnohead);
			break;
		case 3:
			delete_cno(cnohead);
			break;
		case 4:
			insert_grade(cnohead, stuhead);
			break;
		case 5:
			groupby(cnohead);
			break;
		case 6:
			txt_cno(cnohead);
			break;
		case 7:
			txt_phone(stuhead);
			break;
		case 8:
			txt_grade(cnohead,stuhead);
			break;
		case 9:
			txt_groupby(cnohead);
			break;
		case 10:
			txt_cno_now(cnohead);
			break;
		case 11:
			txt_grade_now(cnohead);
			break;
		case 12:
			txt_stu_now(stuhead);
			break;
		default:
			break;
		}
		system("pause");
	}
}


