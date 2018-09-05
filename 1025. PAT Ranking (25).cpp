#include "iostream"
#include "string"
#include "vector"
#include "algorithm"
#include "cstdio" 
using namespace std;
typedef struct _info
{
	string registration_number;
	int goal;
	int final_rank;
	int local_rank;
	int location;
}info;
std::vector<info> v;

bool less_PAT(const info&a, const info&b){
	if(a.goal > b.goal){
		return 1;
	}
	else if(a.goal == b.goal){
		if(a.registration_number < b.registration_number){
			return 1;			
		}
		else{
			return 0;
		}
	}
	else{
		return 0;
	}
}
int main(int argc, char const *argv[])
{
	int location_N;//N 块区域1-N
	int count_teese = 0;;
	cin>>location_N;
//	std::vector<info>::iterator it;
	for(int i = 1; i <= location_N; i++){
		int testee_K;//k每个区域K个人员
		cin>>testee_K;
		count_teese += testee_K;
		for(int j = 0; j < testee_K; j++){
			string _registration_number;
			int _goal;
			info v_info;
			cin>>_registration_number>>_goal;
			v_info.registration_number = _registration_number;
			v_info.goal = _goal;
			v_info.location = i;
			v.push_back(v_info);
//			if(j == 0) it = v.begin();		
		}
		sort(v.end()-testee_K,v.end(),less_PAT);
		int _local_rank = 1;
		int rank = 2;
		(v.end()-testee_K)->local_rank = 1;
		for(vector<info>::iterator it = v.end()-testee_K+1;it!=v.end();it++){
			if(it->goal == (it-1)->goal) it->local_rank = _local_rank;
			else it->local_rank = rank;
			rank ++;
			_local_rank = it->local_rank;
		}
//		sort(v.begin(),v.end(),less_PAT);
	}
	sort(v.begin(),v.end(),less_PAT);
	int _final_rank = 1;
	v.begin()->final_rank = 1;
	int rank = 2;
	for(vector<info>::iterator it = v.begin()+1;it != v.end();it ++){
		if(it->goal == (it-1)->goal) it->final_rank = _final_rank;
		else it->final_rank = rank;
		rank ++;
		_final_rank = it->final_rank;
	}
	cout<<count_teese<<endl;
	for(int i = 0;i < v.size();i++){
		cout<<v[i].registration_number;
		cout<<' ';
		cout<<v[i].final_rank;
		cout<<' ';
		cout<<v[i].location;
		cout<<' ';
		cout<<v[i].local_rank<<endl;
	}
	return 0;
}
