


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


//�鲢����֮��1
cnoGrade *list_split(cnoGrade *head)//ʵ������Ĺ鲢����֮�������,���غ�����
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
//�鲢����֮��2
cnoGrade* merge(cnoGrade *h1, cnoGrade *h2)//�ϲ���������
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
//�鲢�������
cnoGrade* sort_cnoGrade(cnoGrade *head)//����ѧ�Ź鲢�����ȷ֣���
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


//�鲢����֮��1
cnoIndex *list_split(cnoIndex *head)//ʵ������Ĺ鲢����֮�������,���غ�����
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
//�鲢����֮��2
cnoIndex* merge(cnoIndex *h1, cnoIndex *h2)//�ϲ���������
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
//�鲢�������
cnoIndex* sort_cnoIndex(cnoIndex *head)//����ѧ�Ź鲢�����ȷ֣���
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


//�γ̳ɼ�
cnoIndex* load_grade(cnoIndex *head)
{
	cnoIndex *p;
	cnoGrade *c1, *cc1;
	int n = 20;
	for (int i = 0; i < n; ++i)
	{
		ifstream instuf;
		instuf.open("E:\\����ҵԭʼ����\\�ɼ���Ϣ\\\\" + to_string(i) + ".txt", ios::in);
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

//�γ���Ϣ
cnoIndex* load_cno(cnoIndex* p)
{
	cnoIndex *temp1, *temp2;
	temp1 = p;
	ifstream instuf;
	instuf.open("E:\\����ҵԭʼ����\\�γ���Ϣ.txt", ios::in);
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

//ɾ���������ݵ��ظ�
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

//�жϿγ̺��Ƿ����
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
		outs.open("D:\\ѧ���ɼ�����ϵͳ\\ʵʱ����\\�ɼ���Ϣ\\\\" + to_string(CS2->cno) + ".txt", ios::out);
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
	outstuf.open("D:\\ѧ���ɼ�����ϵͳ\\ʵʱ����\\�γ���Ϣ\\�γ���Ϣ.txt", ios::out);
	outstuf << "�γ̺�     �γ���       ѧ��" << endl;
	while (p->next)
	{
		outstuf << p->next->cno << "      " << p->next->cname << "     " << p->next->credit << endl;
		p = p->next;
	}
	outstuf.close();

}

//6��ӡ���Ƴɼ����ļ���
void txt_cno(cnoIndex *h)
{
	cout << "�������ӡ�ɼ��Ŀγ̺ţ�" << endl;
	int cno;
	cin >> cno;
	if (judge_cno(h, cno))
	{
		cnoIndex *CS2;
		CS2 = h->next;
		while (CS2->cno != cno)
			CS2 = CS2->next;
		ofstream outstuf;
		outstuf.open("D:\\ѧ���ɼ�����ϵͳ\\�����γ̳ɼ���Ϣ\\\\" + to_string(cno) + ".txt", ios::out);
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
		cout << "������ĺŲ�����" << endl;
	}
}

//5ͳ�Ʒ���
void groupby(cnoIndex *head)
{
	int cno;
	cout<< "������Ҫͳ�ƵĿγ̺�:" << endl;
	cin >> cno;
	if (!judge_cno(head, cno))
	{
		cout << "������Ŀγ̲����ڣ�" << endl;
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
				cout << "������Ŀγ�û�гɼ���¼��" << endl;
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
			cout << p->cno << "ͳ�Ƶ����Ϊ��" << endl;
			cout << "������Ϊ��" << fixed << setprecision(2) << g60 << "%" << endl;
			cout << "ƽ����Ϊ��" << sum/n << endl;
			cout << "��߷�Ϊ��" << Max << endl;
			cout << "��ͷ�Ϊ��" << Min << endl;
			return;
		}
		p = p->next;
	}
}

//ͳ�����пγ̵ķ���
void txt_groupby(cnoIndex *head)
{
	cnoIndex *p;
	p = new cnoIndex();
	cnoGrade *c1;
	double sum, n, Avg, g60;
	int Max, Min;
	p = head->next;
	ofstream outstuf;
	outstuf.open("D:\\ѧ���ɼ�����ϵͳ\\ͳ�Ʒ���\\ͳ�����.txt", ios::out);
	outstuf << "�γ̺�    ������     ƽ����      ��߷�     ��ͷ�  " << endl;
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

//2-2-2ɾ��ѧ���ɼ�cs
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
				break;//ɾ��һ���γ̺Ŷ�Ӧһ���ɼ�������ѭ����
			}
			q = q->next;
		}
		p = p->next;
	}
	cout << "ѧ���ɼ�ɾ���ɹ���" << endl;
}

//3-1��ӿγ�
void insert_cno(cnoIndex *head)
{
	cnoIndex *q;
	q = new cnoIndex();
	cout << "������γ̺ţ��γ����֣�ѧ��" << endl;
	cin >> q->cno >> q->cname >> q->credit;
	if (judge_cno(head, q->cno))
	{
		cout << "�γ̺��Ѿ�����!" << endl;
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
		cout << "��ӳɹ���" << endl;
		return ;
	}
}

//3-2-2ɾ���γ̺ųɼ�
void delete_cno(cnoIndex *head)
{

	cout << "��������Ҫɾ���Ŀγ̺�cno��" << endl;
	int cno;
	cin >> cno;
	if (!judge_cno(head, cno))
	{
		cout << "�γ̺Ų����ڣ�" << endl;
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
				cout << "ɾ���ɹ�" << endl;
				return;
			}
			p = p->next;
		}
	}
}
