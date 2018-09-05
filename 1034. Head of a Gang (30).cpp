#include "iostream"
#include "cstdio"
#include "string"
#include "vector"
#include "map"
#include "string.h"
#include "algorithm"
#define INF 0x3f3f3f3f
#define nameMax 2010
using namespace std;
//defination of member
typedef struct{
	string name;
	int weight;
}_member;
//defination of a gang
typedef struct _gang{
	int member_count;
	int weight;
	string max_weight_name;
}gang;
//record the given info;
_member member[nameMax];
std::map<string, int> names;
//graph
bool graphPhone[nameMax][nameMax];
bool isVisited[nameMax];
int total_mem = 1;	//	total member 
std::vector<gang> gangs;
void dfs(int point,gang &Gang){
//	cout<<member[point].name<<endl;
	Gang.member_count++;
	Gang.weight += member[point].weight;
	if(member[names[Gang.max_weight_name]].weight < member[point].weight){
		Gang.max_weight_name = member[point].name;
	}
	isVisited[point] = true;
	for(int i = 0; i < total_mem; i++){
		if(graphPhone[point][i] == true&&isVisited[i] == false){
		//	cout<<member[i].name<<endl;
			dfs(i,Gang);
		}
	}
}

bool myLess(const gang&a,const gang&b){
	return a.max_weight_name < b.max_weight_name;
}
int main(int argc, char const *argv[])
{
	int N, K;
	scanf("%d %d",&N,&K);
	memset(isVisited,false,nameMax);
	memset(graphPhone,false,nameMax*nameMax);
	/*get information*/
	string _name1, _name2;
	int _time;

	for(int i = 0; i < N; i++){
		cin>>_name1>>_name2>>_time;
		if(!names[_name1])	
			names[_name1] = total_mem++;
		if(!names[_name2])	
			names[_name2] = total_mem++;

		graphPhone[names[_name1]][names[_name2]] = true;
		member[names[_name1]].name = _name1;	member[names[_name1]].weight += _time;
		member[names[_name2]].name = _name2;	member[names[_name2]].weight += _time;
	}
	int total_gang = 0;
	for(int i = 0; i < total_mem; i++){
		if(isVisited[i] == false){

			gang Gang;	Gang.member_count = 0;	Gang.weight = 0;
			Gang.max_weight_name = member[i].name;
			dfs(i,Gang);
			if(Gang.weight/2 > K&&Gang.member_count > 2){
				total_gang ++;
				gangs.push_back(Gang);
			}
		}
	}
	sort(gangs.begin(), gangs.end(),myLess);
	cout<<total_gang<<endl;
	for(int i = 0; i < gangs.size(); i++){
		cout<<gangs[i].max_weight_name<<' '<<gangs[i].member_count<<endl;
	}
	return 0;
}
