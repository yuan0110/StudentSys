//student2


struct cnoGrade
{
	int cno;
	int sno;
	int grade;
	cnoGrade *next;
};
struct cnoIndex
{
	int cno;
	string cname;
	double credit;
	cnoGrade *head;
	cnoIndex *next;
};


int min(int a, int b);
int max(int a, int b);

//�ɼ���_01����ͬһ���γ̵ĳɼ�����cnoGrade��
cnoIndex* load_grade(cnoIndex *head);

//�鲢����cnoGrade
cnoGrade *list_split(cnoGrade *head);//ʵ������Ĺ鲢����֮�������,���غ�����
cnoGrade* merge(cnoGrade *h1, cnoGrade *h2);//�ϲ���������
cnoGrade* sort_cnoGrade(cnoGrade *head);//����ѧ�Ź鲢�����ȷ֣���


//�鲢����cnoIndex
cnoIndex *list_split(cnoIndex *head);//ʵ������Ĺ鲢����֮�������,���غ�����
cnoIndex* merge(cnoIndex *h1, cnoIndex *h2);//�ϲ���������
cnoIndex* sort_cnoIndex(cnoIndex *head);//����ѧ�Ź鲢�����ȷ֣���
//�����ɼ���_02�����տγ����ӱ��
cnoIndex* load_cno(cnoIndex *p);
//ɾ���������ݵ��ظ�
void nocopy_cs(cnoIndex* h);

//�жϿγ̺��Ƿ����
bool judge_cno(cnoIndex *head, int cno);


void txt_grade_now(cnoIndex *h);
void txt_cno_now(cnoIndex *head);

//6��ӡ���Ƴɼ����ļ���
void txt_cno(cnoIndex *h);

//5ͳ�Ƶ����γ̷���
void groupby(cnoIndex *head);

//ͳ�ƿγ̳ɼ�
void txt_groupby(cnoIndex *head);

//2-2-2ɾ��ѧ���ɼ�cs
void delete_sno_grade(cnoIndex *head, int sno);

//3-2-2ɾ���γ̺��Լ��ɼ�
void delete_cno(cnoIndex *head);

//3-1��ӿγ�
void insert_cno(cnoIndex *head);
