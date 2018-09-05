#include "iostream"
#include "string"
#include "vector"
using namespace std;
int main(int argc, char const *argv[])
{
	string U, bottom;
	std::vector<char> vertical;
	cin>>U;
	int count = (U.length()+2)/3;
	int rest = U.length()+2-count*2;
	for (int i = 0; i < count-1; ++i){
		vertical.push_back(U[i]);
		vertical.push_back(U[U.length()-1-i]);
	}
	bottom = U.substr(count-1,rest);
	for (int i = 0; i < vertical.size(); i+=2){
		cout<<vertical[i];
		for (int j = 0; j < rest-2; j++)
			cout<<' ';
		cout<<vertical[i+1]<<'\n';
	}
	cout<<bottom; 
	return 0;
}
