
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
	cout << "����������γ̺ţ�ѧ�ţ��ɼ���" << endl;
	cin >> c1->cno >> c1->sno >> c1->grade;
	stuIndex *p = new stuIndex();
	p = find(stuhead, c1->sno % 100);
	int c = judge_sno(p->head, c1->sno);
	if (c == 0)
	{
		cout << "�������ѧ�Ų����ڣ�" << endl;
		return;
	}
	else
	{
		if (judge_cno(cnohead, c1->cno))//�жϿγ̺��Ƿ����
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
				cout << "��ӳɹ�" << endl;
				return;
			}
			while (q->next && (q->next->sno <= c1->sno))
				q = q->next;
			if (!q)
			{
				c1->next = q->next;
				q->next = c1;
				cout << "��ӳɹ�" << endl;
				return;
			}
			if (q->sno == c1->sno)
			{
				cout << "����ӵĿγ̳ɼ��Ѵ��ڣ��Ƿ��滻������0���滻������1�滻" << endl;
				int i;
				cin >> i;
				if (i)
				{
					q->grade = c1->grade;
					cout << "�ɼ��滻�ɹ���" << endl;
					return;
				}
				else
				{
					cout << "�ɼ�û���滻��" << endl;
					return;
				}
			}
			c1->next = q->next;
			q->next = c1;
			cout << "��ӳɹ�" << endl;
			return;
		}
		else
		{
			cout << "������Ŀγ̺Ų����ڣ�" << endl;
		}
	}
}

void delete_stu(cnoIndex *cnohead, stuIndex *stuhead)
{
	cout << "������Ҫɾ����ѧ��:" << endl;
	int sno;
	cin >> sno;
	stuIndex *p = find(stuhead, sno % 100);
	int c = judge_sno(p->head, sno);
	if (!c)
	{
		cout << "�������ѧ�Ų����ڣ�ɾ��ʧ�ܣ�" << endl;
		return;
	}
	delete_sno(stuhead, sno);
	delete_sno_grade(cnohead, sno);
}

void txt_grade(cnoIndex *cnohead, stuIndex *stuhead)
{
	int sno;
	cout << "����Ҫ��ӡ��ѧ���ţ�";
	cin >> sno;
	stuIndex *temp = find(stuhead, sno % 100);
	if (judge_sno(temp->head, sno))
	{
		ofstream outstuf;
		outstuf.open("D:\\ѧ���ɼ�����ϵͳ\\����ѧ���ɼ���Ϣ\\\\" + to_string(sno) + ".txt", ios::out);
		outstuf << "������" << sno << "ͬѧ�ĳɼ�����" << endl;
		outstuf << "�γ̺�     �γ���       �ɼ�      ѧ�� " << endl;
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
		cout << "��ӡѧ���ɼ����ɹ�" << endl;
	}
	else
	{
		cout << "�������ѧ���Ų�����" << endl;
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
	cnohead = load_cno(cnohead);//����γ���Ϣ
	cnohead = load_grade(cnohead);//����ɼ�
	nocopy_cs(cnohead);//���ظ��Ŀγ̺ź�ѧ��ˤ��


	//int sno;
/*
			0���ѧ��
			1ɾ��ѧ��
			2��ӹ���
			3ɾ������
			4����ѧ��ĳ�Ź��γɼ�
			5ͳ�Ʒ���
			6�����й��ε�ѧ���ɼ����ɱ�����txt
			7����ͨѶ¼
			8ĳ��ͬѧ�ĳɼ������ 
			9ͳ�Ƴɼ����ĵ�
			10�γ���Ϣ
			11�ɼ���Ϣ
			12ѧ����Ϣ
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


