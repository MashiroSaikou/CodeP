#include<iostream>
#include<stdlib.h>
using namespace std;
#define MAX_VERTEX_NUM 20
typedef enum{ FALSE,TRUE} Boolean;
Boolean visited[MAX_VERTEX_NUM];
//
typedef struct ArcNode{
	int adjvex;
	struct ArcNode *nextarc;
}ArcNode;

typedef struct VNode{
	char data;
	ArcNode *firstarc;
}VNode,AdjList[MAX_VERTEX_NUM];

typedef struct{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

typedef enum STATUS
{
	OK,
	ERROR,
	OVERFLOW,
}Status;

Status Create(ALGraph &G);
Status Exist_Path(ALGraph G,char v1,char v2,int k);
int LocateVex(ALGraph &G,char v); 
char GetVex(ALGraph &G,int i);

int main()
{
	
	ALGraph G;
	Create(G);
	string path;
	for(int i=0;i<G.vexnum;i++)
	visited[i] = FALSE;
	char v1,v2;
	cin >> v1 >> v2;
	/*int i,j;
	i = LocateVex(G,v1);
	j = LocateVex(G,v2);*/
	int k;
	cin >> k;
	if(Exist_Path(G,v2,v2,k))
	cout << "存在";
	else
	cout << "不存在";
	cout << path;
} 

char GetVex(ALGraph &G,int i)
{
	return G.vertices[i].data;
}

int LocateVex(ALGraph &G,char v)
{
	int i = 0;
	while(G.vertices[i].data != v && i<G.vexnum)
	i++;
	if(G.vertices[i].data == v) return i;
	else return -1;
} 
Status Exist_Path(ALGraph G,char v1,char v2,int k)
{
	int i;
	ArcNode *p;
	if(v1==v2&&k==0)
	{
		return OK;
	} 
	else {
		i = LocateVex(G,v1);
		visited[i] = TRUE;
		for(p=G.vertices[i].firstarc;p;p=p->nextarc)
		{
			int t = p->adjvex;
			if(visited[t]==FALSE)
			{
				if(Exist_Path(G,G.vertices[t].data,v2,k-1))
				return OK;
			}
		}
		visited[i] = FALSE;
	}
}

Status Create(ALGraph &G)
{
	int n,e,k,i,j;
	cout << "请输入顶点数:";
	cin >> n;
	cout << "请输入边数:";
	cin >> e;
	G.vexnum = n;
	G.arcnum = e;
	for(k=0;k<=G.vexnum-1;k++)
	{
		cin >> G.vertices[k].data;
		G.vertices[k].firstarc = NULL;
	}
	char v1,v2;
	ArcNode *p,*q;
	int count=0;
	//cout << "-------";
	for(k=0;k<G.arcnum;k++)
	{
		cin >> v1 >> v2;
		i = LocateVex(G,v1);
		if(i<0 || i>G.vexnum-1) return ERROR;
		j = LocateVex(G,v2);
		if(j<0 || j>G.vexnum-1) return ERROR;
		if(i==j) return ERROR;
		p = new ArcNode;
		if(!p) return ERROR;
		p->adjvex = j;
		p->nextarc = NULL;
		q = G.vertices[i].firstarc;
		if(!q) G.vertices[i].firstarc = p;
		else{
			while(q->nextarc) q = q->nextarc;
			q->nextarc = p;
		} 
	}
	return OK;	
}
