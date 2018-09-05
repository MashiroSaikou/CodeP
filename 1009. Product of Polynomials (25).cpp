#include "iostream"
#include "cstdio"
#include "map"
#define max_n 1000000
using namespace std;

int main(int argc, char const *argv[])
{
	int K;
	map<int,double> map_1,map_2,map_p;
	cin>>K;
	for (int i = 0; i < K; ++i)
	{
		int e;double c;
		cin>>e>>c;
		map_1[e] = c;
	}
	cin>>K;
	for (int i = 0; i < K; ++i)
	{
		int e;double c;
		cin>>e>>c;
		map_2[e] = c;
	}

	map<int,double>::iterator it_1,it_2,it_p;
	for (it_1 = map_1.begin();it_1 != map_1.end();it_1++)
	{
		for (it_2 = map_2.begin();it_2 != map_2.end();it_2++)
		{
			int key = it_1->first + it_2->first;
			double data = it_1->second * it_2->second;
			it_p = map_p.find(key);
			if (it_p == map_p.end() )
			{
				map_p[key] = data;
			}
			else
			{
				it_p->second += data;
			}
		}
	}

	for (it_p = map_p.begin();it_p != map_p.end();it_p++)
	{
		if (it_p->second == 0.0)
		{
			map_p.erase(it_p);
		}
	}
	cout<<map_p.size();
	map<int,double>::reverse_iterator rit;
	for (rit = map_p.rbegin(); rit != map_p.rend();rit++)
	{
		printf(" %d %.1f",rit->first,rit->second);
	}
	return 0;
}
