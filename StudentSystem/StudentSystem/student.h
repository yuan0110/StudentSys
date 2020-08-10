//student.vs πÈ≤¢≈≈
//#include<string>
//using namespace std;

struct student
{
	long int sno;
	string sname;
	string pnumber;
	student *next;
};
struct stuIndex
{
	int key;
	student *head;
	stuIndex *next;
};


stuIndex* create_stuIndex(stuIndex *head, int n);

stuIndex* loadStu(stuIndex *head);

stuIndex* find(stuIndex *head, int sno);

bool judge_sno(student *head, int sno);

void insert_sno(stuIndex *head);

void delete_sno(stuIndex *head, int sno);

void txt_phone(stuIndex *head);

void txt_stu_now(stuIndex *head);