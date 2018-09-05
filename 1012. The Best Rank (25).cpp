#include "iostream"
#include "string"
#include "map" 

using namespace std;
class every_stu
{
public:
	every_stu();
	void getData(string _stu_name,int _Cscore,int _Mscore,int _Escore);
	void getBestSubject();
	//int Cscore, Mscore, Escore, Ascore;
	std::map<char, int> score;
	string stu_name;
	char best_subject;
	int best_rank;
	
};

every_stu::every_stu()
{
	this->best_rank = 1;
}
void every_stu::getData(string _stu_name,int _Cscore,int _Mscore,int _Escore)
{
	stu_name = _stu_name;
	score['C'] = _Cscore;
	score['M'] = _Mscore;
	score['E'] = _Escore;
	score['A'] = (_Cscore + _Mscore + _Escore)/3;	
}

void every_stu::getBestSubject()
{
	best_subject = 'A';
	if (score[best_subject]<score['C'])
	{
		best_subject = 'C';
	}
	if (score[best_subject]<score['M'])
	{
		best_subject = 'M';
	}
	if (score[best_subject]<score['E'])
	{
		best_subject = 'E';
	}
}
int main(int argc, char const *argv[])
{
	int N, M_stu;
	cin>>N>>M_stu;
	every_stu *student = new every_stu[N];
	std::map<string,every_stu> studentMap;
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
			if (student[i].score[student[i].best_subject] < student[j].score[student[i].best_subject])
			{
				student[i].best_rank ++;
			}
			else if (student[i].score[student[i].best_subject] > student[j].score[student[i].best_subject])
			{
				if (student[i].best_subject == student[j].best_subject)
				{
					student[j].best_rank --;
				}
			}
			else if(student[i].score[student[i].best_subject] == student[j].score[student[i].best_subject])
			{
				student[i].best_rank = student[j].best_rank;
			}
		}
	}

	for (int i = 0; i < M_stu; ++i)
	{
		string name;
		cin>>name;
		map<string, every_stu>::iterator it  = studentMap.find(name);
		if (it != studentMap.end())
		{
			//cout<<it->second.best_rank<<' '<<it->second.best_subject;
			printf("%d %c\n",it->second.best_rank,it->second.best_subject);
		}
		else
		{
			//cout<<"N/A";
			printf("N/A\n");
		}
	}
	return 0;
}
