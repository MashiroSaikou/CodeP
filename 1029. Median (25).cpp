//选择合适的排序方式考虑时间复杂度真的很重要
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;
int main(int argc, char const *argv[])
{
	vector<long> v;
	int N1,N2;
	cin>>N1;
	long int data;
	for (int i = 0; i < N1; ++i){
		cin>>data;
		v.push_back(data);
	}
	std::vector<long int> p;
	cin>>N2;
	for (int i = 0; i < N2; ++i){
		cin>>data;
		p.push_back(data);
	}
	vector<long int>final;
	int vCount = 0, pCount = 0;
	while(vCount<v.size()&&pCount<p.size()){
		long int temp = v[vCount]<p[pCount]?v[vCount++]:p[pCount++];
		final.push_back(temp);
	}
	while(vCount<v.size()){
		final.push_back(v[vCount++]);
	}
	while(pCount<p.size()){
		final.push_back(p[pCount++]);
	}	
	cout<<final[(final.size()-1)/2];
	return 0;
}
