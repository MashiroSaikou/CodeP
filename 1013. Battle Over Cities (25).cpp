#include "iostream"
#include "cstdio"

using namespace std;
int *father = new int[1001]();
int *sz = new int[1001];
int road[500001][2];

void iniSet(int n)
{
	for (int i = 0; i <= n; ++i)
	{
		father[i] = i;
		sz[i] = 1;
	}
}

int findFather(int x)
{
	if (x != father[x])
	{
		father[x] = findFather(father[x]);
	}
	return father[x];
}

void union_find(int x,int y)
{
	int x_father = findFather(x);
	int y_father = findFather(y);
	if(x_father == y_father)
		return;
	if(sz[x_father]<sz[y_father])
	{
		father[x_father] = y_father;
		sz[y_father] += sz[x_father];
	}
	else 
	{
		father[y_father] = x_father;
		sz[x_father] += sz[y_father];
	}
}
int main(int argc, char const *argv[])
{
	int n,m,k;
	int point_city;
	while(cin>>n>>m>>k)
	{
		for (int i = 0; i < m; ++i)
		{
			int a,b;
			cin>>road[i][0]>>road[i][1];
		}
		for (int i = 0; i < k; ++i)
		{
			iniSet(n);
			cin>>point_city;
			for (int i = 0; i < m; ++i)
			{
				if (point_city!=road[i][0]&&point_city!=road[i][1])
				{
					union_find(road[i][0],road[i][1]);
				}
			}

			int cnt = 0;
			for (int i = 1; i <= n; ++i)
			{
				if (father[i] == i)
				{
					cnt ++;
				}
			}

			cout<<cnt-2<<endl;
		}
	}
	return 0;
}
