#include<iostream>
using namespace std;
#include<string>
#include<algorithm>
#include<iomanip>
#include<fstream>
#include"student.h"

stuIndex* create_stuIndex(stuIndex *head, int n)
{
	stuIndex *p, *q;
	p = head;
	for (int i = 0; i < n; i++)
	{
		q = new stuIndex();
		q->key = i;
		q->head = new student();
		q->head->next = NULL;
		q->next = p->next;
		p->next = q;
		p = q;
	}
	return head;
}

stuIndex* loadStu(stuIndex *head)
{
	stuIndex *p;
	student *q;
	q = new student();
	ifstream instuf("E:\\����ҵԭʼ����\\ѧ����Ϣ\\0.txt", ios::in);
	while (instuf >> q->sno >> q->sname >> q->pnumber)
	{
		//p = new stuIndex();
		p = find(head, q->sno );
		int c = judge_sno(p->head, q->sno);
		if (!c)
		{
			q->next = p->head->next;
			p->head->next = q;
		}
		q = new student();
	}
	return head;
}


stuIndex* find(stuIndex *head, int sno)
{
	int n = sno % 100;
	stuIndex *p;
	p = head->next;
	while (n--)
		p = p->next;
	return p;
}

bool judge_sno(student *head, int sno)
{
	student *p;
	p = head;
	while (p->next)
	{
		if (p->next->sno == sno)
			return 1;
		p = p->next;
	}
	return 0;
}

void insert_sno(stuIndex *head)
{
	cout << "��������ѧ�ţ��������绰" << endl;
	student *q;
	q = new student();
	cin >> q->sno >> q->sname >> q->pnumber;
	stuIndex *p;
	p = find(head, q->sno % 100);
	int c = judge_sno(p->head, q->sno);
	if (c)
	{
		cout << "�������ѧ���Ѿ����ڣ����ѧ��ʧ�ܣ�" << endl;
		return;
	}
	q->next = p->head->next;
	p->head->next = q;
	cout << "���ѧ���ɹ���" << endl;
	return;
}

void delete_sno(stuIndex *head, int sno)
{
	stuIndex *p = find(head, sno % 100);
	student *q;
	q = p->head;
	while (q->next)
	{
		if (q->next->sno == sno)
		{
			student *temp = q->next;
			q->next = q->next->next;
			delete temp;
			return;
		}
		q = q->next;
	}
}

void txt_phone(stuIndex *head)
{
	stuIndex *p;
	p = head;
	while (p->next)
	{
		ofstream outstuf("D:\\ѧ���ɼ�����ϵͳ\\ͨѶ¼\\\\"+to_string(p->next->key)+".txt", ios::out);
		student *q = p->next->head;
		while (q->next)
		{
			outstuf << q->next->sname << "    " << q->next->pnumber <<endl;
			q = q->next;
		}
		outstuf.close();
		p = p->next;
	}
}

void txt_stu_now(stuIndex *head)
{
	stuIndex *p;
	p = head;
	while (p->next)
	{
		ofstream outstuf;
		outstuf.open("D:\\ѧ���ɼ�����ϵͳ\\ʵʱ����\\ѧ����Ϣ\\\\" + to_string(p->next->key) + ".txt", ios::out);
		outstuf << setprecision(14) << "    ѧ��                  ����                    �绰" << endl;
		student *q;
		q = p->next->head;
		while (q->next)
		{
			outstuf << setprecision(14) << q->next->sno<<"  " << q->next->sname<<"  " << q->next->pnumber << endl;
			q = q->next;
		}
		outstuf.close();
		p = p->next;
	}
}