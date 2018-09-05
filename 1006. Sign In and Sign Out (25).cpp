#include "iostream"
#include "climits"
#include "string"
#define INF 0x3f3f3f3f
using namespace std;

int main(int argc, char const *argv[])
{
	int M, time_in_max = INF,time_out_max = 0;
	cin>>M;
	string first_person,last_person;
	for (int i = 0; i < M; ++i)
	{
		int h1,h2,m1,m2,s1,s2;
		string s;
		cin>>s;
		scanf("%d:%d:%d %d:%d:%d:",&h1,&m1,&s1,&h2,&m2,&s2);
		if (h1*3600+m1*60+s1<time_in_max)
		{
			first_person = s;
			time_in_max = h1*3600+m1*60+s1;
		}
		if (h2*3600+m2*60+s2>time_out_max)
		{
			last_person = s;
			time_out_max = h2*3600+m2*60+s2;
		}
	}

	cout<<first_person<<' '<<last_person;


	return 0;
}
