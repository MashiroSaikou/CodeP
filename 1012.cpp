#include "iostream"
#include "string"

using namesapce std;
class every_stu
{
public:
	every_stu();
	~every_stu();
	getData(string _stu_name,int _Cscore,int _Mscore,int _Escore, );
	//int Cscore, Mscore, Escore, Ascore;
	std::map<char, int> score;
	string stu_name;
	char best_subject;
	int best_rank = 1;
	getBestSubject();
	
};
every_stu::getData(string _stu_name,int _Cscore,int _Mscore,int _Escore, )
{
	stu_name = _stu_name;
	score[C] = _Cscore;
	score[M] = _Mscore;
	score[E] = _Escore;
	score[A] = (Cscore + Mscore + Escore)/3;	
}

every_stu::getBestSubject()
{
	best_rank = 'A';
	if (score[best_rank]<score[C])
	{
		best_rank = 'C';
	}
	if (score[best_rank]<score[M])
	{
		best_rank = 'M';
	}
	if (score[best_rank]<score[E])
	{
		best_rank = 'E';
	}
}
int main(int argc, char const *argv[])
{
	int N, M;
	cin>>N>>M;
	/every_stu *student = new every_stu[N];
	std::map<string, every_stu> studentMap;
	for (int i = 0; i < N; ++i)
	{
		int C, M, E;
		string id;
		cin>>id>>C>>M>>E;
		student[i].getData(id,C,M,E);
		student[i].getBestSubject();
		studentMap[id] = student[i];
		for (int j = 0; j < i; ++j)
		{
			if (student[i].score[best_subject] < student[j].score[best_subject])
			{
				student[i].best_rank ++;
			}
			else if (student[i].score[best_subject] > student[j].score[best_subject])
			{
				if (student[i].best_subject == student[j].best_subject)
				{
					student[j].best_rank --;
				}
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		string name;
		cin>>name;
		map<string, every_stu>::iterator it  = studentMap.find(name);
		if (it != studentMap.end())
		{
			cout<<it->best_rank<<' '<<it->best_subject;
		}
		else
		{
			cout<<"N/A";
		}
	}
	return 0;
}