


#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

#include"CS_grade.h"


int min(int a, int b)
{
	if (a > b)return b;
	return a;
}
int max(int a, int b)
{
	if (a > b)return a;
	return b;
}


//归并排序之分1
cnoGrade *list_split(cnoGrade *head)//实现链表的归并排序之拆分链表,返回后面半段
{
	if (head == NULL)
	{
		return NULL;
	}
	cnoGrade *temp = head;
	cnoGrade *fast = head;
	cnoGrade *slow = head;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
		}

		if (fast == NULL)
			break;
		slow = slow->next;
	}
	temp = slow;
	slow = slow->next;
	temp->next = NULL;
	return slow;
}
//归并排序之合2
cnoGrade* merge(cnoGrade *h1, cnoGrade *h2)//合并两个链表
{
	if (h1 == NULL)return h2;
	if (h2 == NULL)return h1;

	cnoGrade head;
	head.next = NULL;
	cnoGrade *p = &head;

	while (h1&&h2)
	{
		if (h1->sno > h2->sno)
		{
			p->next = h2;
			h2 = h2->next;
		}
		else
		{
			p->next = h1;
			h1 = h1->next;
		}
		p = p->next;
	}
	if (h1)
	{
		p->next = h1;
	}
	if (h2)
	{
		p->next = h2;
	}
	return head.next;

}
//归并排序入口
cnoGrade* sort_cnoGrade(cnoGrade *head)//按照学号归并排序，先分，后并
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	cnoGrade *h1 = head;
	cnoGrade *h2 = list_split(head);
	h1 = sort_cnoGrade(h1);
	h2 = sort_cnoGrade(h2);
	return merge(h1, h2);
}


//归并排序之分1
cnoIndex *list_split(cnoIndex *head)//实现链表的归并排序之拆分链表,返回后面半段
{
	if (head == NULL)
	{
		return NULL;
	}
	cnoIndex *temp = head;
	cnoIndex *fast = head;
	cnoIndex *slow = head;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
		}

		if (fast == NULL)
			break;
		slow = slow->next;
	}
	temp = slow;
	slow = slow->next;
	temp->next = NULL;
	return slow;
}
//归并排序之合2
cnoIndex* merge(cnoIndex *h1, cnoIndex *h2)//合并两个链表
{
	if (h1 == NULL)return h2;
	if (h2 == NULL)return h1;

	cnoIndex head;
	head.next = NULL;
	cnoIndex *p = &head;

	while (h1&&h2)
	{
		if (h1->cno > h2->cno)
		{
			p->next = h2;
			h2 = h2->next;
		}
		else
		{
			p->next = h1;
			h1 = h1->next;
		}
		p = p->next;
	}
	if (h1)
	{
		p->next = h1;
	}
	if (h2)
	{
		p->next = h2;
	}
	return head.next;

}
//归并排序入口
cnoIndex* sort_cnoIndex(cnoIndex *head)//按照学号归并排序，先分，后并
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	cnoIndex *h1 = head;
	cnoIndex *h2 = list_split(head);
	h1 = sort_cnoIndex(h1);
	h2 = sort_cnoIndex(h2);
	return merge(h1, h2);
}


//课程成绩
cnoIndex* load_grade(cnoIndex *head)
{
	cnoIndex *p;
	cnoGrade *c1, *cc1;
	int n = 20;
	for (int i = 0; i < n; ++i)
	{
		ifstream instuf;
		instuf.open("E:\\大作业原始数据\\成绩信息\\\\" + to_string(i) + ".txt", ios::in);
		cc1 = new cnoGrade();
		while (instuf >> cc1->cno >> cc1->sno >> cc1->grade)
		{
			p = new cnoIndex();
			p = head->next;
			while (p)
			{
				if (p->cno == cc1->cno)
				{
					c1 = new cnoGrade();
					c1 = p->head;
					cc1->next = c1->next;
					c1->next = cc1;
					cc1 = new cnoGrade();
					break;
				}
				p = p->next;
			}
		}
		instuf.close();
	}
	p = new cnoIndex();
	p = head->next;
	while (p)
	{
		p->head->next = sort_cnoGrade(p->head->next);
		p = p->next;
	}
	return head;
}

//课程信息
cnoIndex* load_cno(cnoIndex* p)
{
	cnoIndex *temp1, *temp2;
	temp1 = p;
	ifstream instuf;
	instuf.open("E:\\大作业原始数据\\课程信息.txt", ios::in);
	temp2 = new cnoIndex();
	while (instuf >> temp2->cno >> temp2->cname >> temp2->credit)
	{
		temp2->head = new cnoGrade();
		temp2->head->next = NULL;
		temp2->next = temp1->next;
		temp1->next = temp2;
		temp2 = new cnoIndex();
	}
	p->next = sort_cnoIndex(p->next);
	return p;
}

//删除导入数据的重复
void nocopy_cs(cnoIndex *h)
{
	cnoIndex *CS2, *temp2;
	cnoGrade *CS1, *temp1;
	CS2 = h;
	while (CS2->next)
	{
		temp2 = new cnoIndex();
		temp2 = CS2->next->next;
		while (temp2 && (CS2->next->cno == temp2->cno))
		{
			cnoIndex *c;
			c = temp2;

			CS2->next->next = temp2->next;
			temp2 = CS2->next->next;
			delete c;

		}
		CS1 = CS2->next->head;
		while (CS1->next)
		{
			temp1 = new cnoGrade();
			temp1 = CS1->next->next;
			while (temp1 && (CS1->next->sno == temp1->sno))
			{
				cnoGrade *c;
				c = temp1;
				CS1->next->next = temp1->next;
				temp1 = CS1->next->next;
				delete c;
			}
			CS1 = CS1->next;
		}
		CS2 = CS2->next;
	}
	return;
}

//判断课程号是否存在
bool judge_cno(cnoIndex *h, int cno)
{
	cnoIndex *p;
	p = h;
	if (!p->next) return false;
	while (p->next&&p->next->cno <= cno)
	{
		p = p->next;
	}
	if (!p) return false;
	if (p->cno == cno)return true;
	else return false;
}

void txt_grade_now(cnoIndex *h)
{
	cnoIndex *CS2;
	cnoGrade *CS1;
	CS2 = h->next;
	while (CS2)
	{
		CS1 = CS2->head->next;
		ofstream outs;
		outs.open("D:\\学生成绩管理系统\\实时数据\\成绩信息\\\\" + to_string(CS2->cno) + ".txt", ios::out);
		while (CS1)
		{
			outs << CS1->sno << "    " << CS1->grade << endl;
			CS1 = CS1->next;
		}
		outs.close();
		CS2 = CS2->next;
	}
}

void txt_cno_now(cnoIndex *head)
{
	cnoIndex *p;
	p = head;
	ofstream outstuf;
	outstuf.open("D:\\学生成绩管理系统\\实时数据\\课程信息\\课程信息.txt", ios::out);
	outstuf << "课程号     课程名       学分" << endl;
	while (p->next)
	{
		outstuf << p->next->cno << "      " << p->next->cname << "     " << p->next->credit << endl;
		p = p->next;
	}
	outstuf.close();

}

//6打印单科成绩到文件夹
void txt_cno(cnoIndex *h)
{
	cout << "请输入打印成绩的课程号：" << endl;
	int cno;
	cin >> cno;
	if (judge_cno(h, cno))
	{
		cnoIndex *CS2;
		CS2 = h->next;
		while (CS2->cno != cno)
			CS2 = CS2->next;
		ofstream outstuf;
		outstuf.open("D:\\学生成绩管理系统\\单个课程成绩信息\\\\" + to_string(cno) + ".txt", ios::out);
		cnoGrade *CS1;
		CS1 = CS2->head->next;
		while (CS1)
		{
			outstuf << CS1->sno << "   " << CS1->grade << endl;
			CS1 = CS1->next;
		}
		outstuf.close();
	}
	else
	{
		cout << "你输入的号不存在" << endl;
	}
}

//5统计分数
void groupby(cnoIndex *head)
{
	int cno;
	cout<< "请输入要统计的课程号:" << endl;
	cin >> cno;
	if (!judge_cno(head, cno))
	{
		cout << "你输入的课程不存在！" << endl;
		return;
	}
	cnoIndex *p;
	p = head->next;
	while (p)
	{
		if (p->cno == cno)
		{
			cnoGrade *q;
			q = p->head;
			if (!q->next)
			{
				cout << "你输入的课程没有成绩记录！" << endl;
				return;
			}
			double sum = 0;
			double n = 0;
			double g60 = 0;
			int Max = q->next->grade;
			int Min = q->next->grade;
			while (q->next)
			{
				n++;
				sum += q->next->grade;
				Max = max(Max, q->next->grade);
				Min = min(Min, q->next->grade);
				if (q->next->grade >= 60)
					g60++;
				q = q->next;
			}
			g60 = g60*100 / n;
			cout << p->cno << "统计的情况为：" << endl;
			cout << "及格率为：" << fixed << setprecision(2) << g60 << "%" << endl;
			cout << "平均分为：" << sum/n << endl;
			cout << "最高分为：" << Max << endl;
			cout << "最低分为：" << Min << endl;
			return;
		}
		p = p->next;
	}
}

//统计所有课程的分数
void txt_groupby(cnoIndex *head)
{
	cnoIndex *p;
	p = new cnoIndex();
	cnoGrade *c1;
	double sum, n, Avg, g60;
	int Max, Min;
	p = head->next;
	ofstream outstuf;
	outstuf.open("D:\\学生成绩管理系统\\统计分数\\统计情况.txt", ios::out);
	outstuf << "课程号    及格率     平均分      最高分     最低分  " << endl;
	while (p)
	{
		c1 = new cnoGrade();
		c1 = p->head->next;
		n = 0;
		g60 = 0;
		sum = 0;
		Avg = 0;
		Min = Max = 0;
		if (p->head->next)
		{
			Min = Max = c1->grade;
			while (c1)
			{
				if (c1->grade >= 60)
					g60++;
				n++;
				sum += c1->grade;
				Min = min(Min, c1->grade);
				Max = max(Max, c1->grade);
				c1 = c1->next;
			}
			Avg = sum / n;
			g60 = g60 * 100 / n;
		}
		outstuf << p->cno << "      " <<fixed<<setprecision(2)<< g60 << "%     " << Avg << "      " << Max << "           " << Min << endl;
		p = p->next;
	}
	outstuf.close();
}

//2-2-2删除学生成绩cs
void delete_sno_grade(cnoIndex *head, int sno)
{
	cnoIndex *p;
	cnoGrade *q;
	p = head;
	while (p->next)
	{
		q = p->next->head;
		while (q->next)
		{
			if (q->next->sno == sno)
			{
				cnoGrade *temp;
				temp = q->next;
				q->next = q->next->next;
				delete temp;
				break;//删除一个课程号对应一个成绩，跳出循环；
			}
			q = q->next;
		}
		p = p->next;
	}
	cout << "学生成绩删除成功！" << endl;
}

//3-1添加课程
void insert_cno(cnoIndex *head)
{
	cnoIndex *q;
	q = new cnoIndex();
	cout << "请输入课程号，课程名字，学分" << endl;
	cin >> q->cno >> q->cname >> q->credit;
	if (judge_cno(head, q->cno))
	{
		cout << "课程号已经存在!" << endl;
		return;
	}
	else
	{
		cnoIndex *p;
		p = head;
		while (p->next&&p->next->cno < q->cno)
			p = p->next;
		q->head = new cnoGrade();
		q->head->next = NULL;
		q->next = p->next;
		p->next = q;
		cout << "添加成功！" << endl;
		return ;
	}
}

//3-2-2删除课程号成绩
void delete_cno(cnoIndex *head)
{

	cout << "请输入你要删除的课程号cno：" << endl;
	int cno;
	cin >> cno;
	if (!judge_cno(head, cno))
	{
		cout << "课程号不存在！" << endl;
		return;
	}
	else{
		cnoIndex *p;
		p = head;
		while (p->next)
		{
			if (p->next->cno == cno)
			{
				cnoGrade *q;
				q = p->next->head;
				while (q->next)
				{
					cnoGrade *p1;
					p1 = q->next;
					q->next = q->next->next;
					delete p1;
				}
				cnoIndex *temp2;
				temp2 = p->next;
				p->next = p->next->next;
				delete temp2;
				cout << "删除成功" << endl;
				return;
			}
			p = p->next;
		}
	}
}
