#include<iostream>
#include<stdlib.h>
#include<vector>
using namespace std;
#define N 11
#define MAXSIZE 20
#define STACK_INIT_SIZE 100
#define STACKINCREMENT  10
typedef int KeyType;
typedef struct{
	KeyType key;
}RedType;

typedef struct{
	RedType r[MAXSIZE+1];
	int length;
}SqList;

typedef struct{
	int *base;
	int *top;
	int stacksize;
}SqStack;

typedef enum STATUS
{
	OK,
	ERROR,
	OVERFLOW,
}Status;


Status InitStack(SqStack &S);
bool StackEmpty(SqStack S);
Status GetTop(SqStack S,int &e);
Status Push(SqStack &S,int e);
Status Pop(SqStack &S,int &e);
bool Prior(int c1,int c2);
int StackLength(SqStack &S);

int Partition(SqList &L,int low,int high);
void QSort(SqList &L,int low,int high,SqStack &S);

int main()
{
	SqList L;
	for(int i=1;i<=N;i++)
	{
		cin >> L.r[i].key;
	}
	SqStack S;
	InitStack(S);
	QSort(L,1,N,S);
	for(int i=1;i<=N;i++)
	{
		cout << L.r[i].key << " ";
	}
	return 0;
}

int Partition(SqList &L,int low,int high)
{
	L.r[0] = L.r[low];
	int pivotkey = L.r[low].key;
	while(low<high)
	{
		while(low<high&&L.r[high].key>=pivotkey)
		high--;
		L.r[low] = L.r[high];
		while(low<high&&L.r[low].key<=pivotkey)
		low++;
		L.r[high] = L.r[low];
	}
	L.r[low] = L.r[0];
	return low;
}

void QSort(SqList &L,int low,int high,SqStack &S)
{
	int pivotkey;
	Push(S,low);
	Push(S,high);

	while(!StackEmpty(S))
	{
		int left,right;
		Pop(S,right);
		Pop(S,left);
		pivotkey = Partition(L,left,right);
		
		if(pivotkey-1>left)
		{
			Push(S,left);
			Push(S,pivotkey-1);
		}
		if(pivotkey+1<right)
		{
			Push(S,pivotkey+1);
			Push(S,right);
		}

	}	

} 

bool StackEmpty(SqStack S){
	if(S.base == S.top)
	return true;
	else
	return false;
}

Status InitStack(SqStack &S){
	S.base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = STACK_INIT_SIZE;
	return OK;
}

Status GetTop(SqStack S,int &e){
	if(S.top == S.base) return ERROR;
	e = *(S.top-1);
	return OK;
}

Status Push(SqStack &S,int e){
	if(S.top - S.base >= S.stacksize){
		S.base = (int *)realloc(S.base,(S.stacksize+STACKINCREMENT) * sizeof(int));
	if(!S.base) exit(OVERFLOW);
	S.top = S.base + S.stacksize;
	S.stacksize += STACKINCREMENT;
	}
	*S.top++ = e;
	return OK;
}

Status Pop(SqStack &S,int &e){
	if(S.top == S.base) return ERROR;
	e = *--S.top;
	return OK;
}

int StackLength(SqStack &S)
{
	int length=0;
	SqStack T;
	InitStack(T);
	int e;
	while(!StackEmpty(S))
	{
		Pop(S,e);
		Push(T,e);
		length++;
	}
	while(!StackEmpty(T))
	{
		Pop(T,e);
		Push(S,e);
	}
	return length;
}

