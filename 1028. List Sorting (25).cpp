#include "iostream"
#include "string"
#include "algorithm"
using namespace std;

typedef struct stdRecord{
	string idNumber;
	string stdName;
	int grade;
};
bool cmpid(const stdRecord&a,const stdRecord&b){
	return a.idNumber<b.idNumber;
}
bool cmpname(const stdRecord&a,const stdRecord&b){
	if(a.stdName == b.stdName)
		return a.idNumber<b.idNumber;
	else 
		return a.stdName<b.stdName;
}
bool cmpgrade(const stdRecord&a,const stdRecord&b){
	if(a.grade == b.grade)
		return a.idNumber < b.idNumber;
	else
		return a.grade<b.grade;
}
int main(int argc, char const *argv[])
{
	int N,C;
	cin>>N>>C;
	stdRecord *data = new stdRecord[N];
	for (int i = 0; i < N; ++i){
		cin>>data[i].idNumber>>data[i].stdName>>data[i].grade;
	}
	switch(C){
		case 1:sort(data,data + 100,cmpid);break;
		case 2:sort(data,data + N,cmpname);break;
		case 3:sort(data,data + N,cmpgrade);break;
	}
	for (int i = 0; i < N; ++i){
		cout<<data[i].idNumber<<' '<<data[i].stdName<<' '<<data[i].grade<<endl;
	}
	return 0;
}
