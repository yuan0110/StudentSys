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

//成绩单_01，将同一个课程的成绩放在cnoGrade中
cnoIndex* load_grade(cnoIndex *head);

//归并排序cnoGrade
cnoGrade *list_split(cnoGrade *head);//实现链表的归并排序之拆分链表,返回后面半段
cnoGrade* merge(cnoGrade *h1, cnoGrade *h2);//合并两个链表
cnoGrade* sort_cnoGrade(cnoGrade *head);//按照学号归并排序，先分，后并


//归并排序cnoIndex
cnoIndex *list_split(cnoIndex *head);//实现链表的归并排序之拆分链表,返回后面半段
cnoIndex* merge(cnoIndex *h1, cnoIndex *h2);//合并两个链表
cnoIndex* sort_cnoIndex(cnoIndex *head);//按照学号归并排序，先分，后并
//创建成绩单_02，按照课程链接表格
cnoIndex* load_cno(cnoIndex *p);
//删除导入数据的重复
void nocopy_cs(cnoIndex* h);

//判断课程号是否存在
bool judge_cno(cnoIndex *head, int cno);


void txt_grade_now(cnoIndex *h);
void txt_cno_now(cnoIndex *head);

//6打印单科成绩到文件夹
void txt_cno(cnoIndex *h);

//5统计单个课程分数
void groupby(cnoIndex *head);

//统计课程成绩
void txt_groupby(cnoIndex *head);

//2-2-2删除学生成绩cs
void delete_sno_grade(cnoIndex *head, int sno);

//3-2-2删除课程号以及成绩
void delete_cno(cnoIndex *head);

//3-1添加课程
void insert_cno(cnoIndex *head);
