#include<iostream>
#include<stdlib.h> 
using namespace std;
#define LEN 11
#define MAXSIZE 20
typedef struct{
	string ID;
	string name;
	int grade;
}ElemType;

typedef struct DulNode{
	ElemType data;
	struct DulNode *prior;
	struct DulNode *next;
}DulNode,*DuLinkList;

typedef struct{
	ElemType Elem[MAXSIZE+1];
	int length;
}SqList;

typedef enum STATUS
{
	OK,
	ERROR,
	OVERFLOW,
}Status;

Status InitList(DuLinkList &L);
Status CreateList(DuLinkList &L);
DuLinkList Partition(DuLinkList &L,DuLinkList low,DuLinkList high);
void QSort(DuLinkList &L,DuLinkList low,DuLinkList high);
int BinarySearch(SqList sl,int x);

int main()
{
	DuLinkList L;
	InitList(L);
	CreateList(L);
	DuLinkList low,high,s;
	low = L->next;
	s = L;
	while(s->next!=NULL)
	s = s->next;
	high = s;
	QSort(L,low,high);
	L = L->next;
	SqList sl;
	sl.length = LEN;
	int i=1;
	while(L)
	{
		sl.Elem[i] = L->data;
		//cout <<L->data.ID <<" "<<L->data.name << " "<<L->data.grade<<endl;
		L = L->next;
		i++;
	}
	cout <<"\n\n快速排序:\n";
	for(int i=1;i<=LEN;i++)
	cout << sl.Elem[i].ID<<" "<<sl.Elem[i].name<<" "<<sl.Elem[i].grade<<endl;
	int first = BinarySearch(sl,78);
	int second = BinarySearch(sl,89);
	cout<<"\n\n寻找78:\n";
	if(first==-1)
	cout << "没有找到78!\n";
	else
	{
		cout << sl.Elem[first].ID<<" "<<sl.Elem[first].name<<" "<<sl.Elem[first].grade<< endl;
	}
	cout<<"\n\n寻找89:\n";
	if(second==-1)
	cout << "没有找到89!";
	else
	{
		cout << sl.Elem[second].ID<<" "<<sl.Elem[second].name<<" "<<sl.Elem[second].grade;
	}
	return 0;
}

int BinarySearch(SqList sl,int x)
{
	int n = sl.length;
	int left=1,right=n;
	while(left <= right){
		int middle = (left+right)/2;
		if(x == sl.Elem[middle].grade) return middle;
		if(x > sl.Elem[middle].grade) left = middle+1;
		else if(x < sl.Elem[middle].grade) right = middle-1;
	}
	return -1;
}

Status InitList(DuLinkList &L)
{
	L = (DulNode*)malloc(sizeof(DulNode));
	L->next = NULL;
	L->prior= NULL;
	if(!L) 
	exit(OVERFLOW);
	return OK;
}

Status CreateList(DuLinkList &L)
{
	DuLinkList p,s;
	p = L;
	for(int i=LEN;i>0;i--)
	{
		s = new DulNode;//(DulNode*)malloc(sizeof(DulNode));
		cin >> s->data.ID;
		//puts(s->data.name);
		cin >> s->data.name;
		cin >> s->data.grade;
		p->next = s;
		s->prior = p;
		p = s; 
	}
	p->next = NULL;
}

DuLinkList Partition(DuLinkList &L,DuLinkList low,DuLinkList high)
{
	DuLinkList pivotkey = new DulNode;

	pivotkey->data = low->data;
	while(low!=high)
	{
		while(low!=high&&high->data.grade>=pivotkey->data.grade)
		high = high->prior;
		low->data = high->data;
		while(low!=high&&low->data.grade<=pivotkey->data.grade)
		low = low->next;
		high->data = low->data;
	}
	//cout << low->data.grade << endl;
	low->data = pivotkey->data ;
	return low;
}

void QSort(DuLinkList &L,DuLinkList low,DuLinkList high)
{
	if(low!=high)
	{
		DuLinkList pivotkey = new DulNode;
		pivotkey = Partition(L,low,high);
		if(pivotkey!=low)
		QSort(L,low,pivotkey->prior);
		if(pivotkey!=high)
		QSort(L,pivotkey->next,high);
	}
}

