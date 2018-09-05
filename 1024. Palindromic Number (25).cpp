#include "iostream"
#include "string"
#include "algorithm"
using namespace std;
string p_Number;
int k_Step;
void addTwoNumber(string p){
	int rest = 0;
	for(int i = 0;i < p.length();i++){
		p_Number[i] = p_Number[i] + p[i] + rest - '0';
		rest = 0;
		if(p_Number[i]>'9'){
			p_Number[i]-=10;
			rest = 1;
		}
	}
	if(rest == 1)	p_Number+='1';
	reverse(p_Number.begin(), p_Number.end());
}
int main(int argc, char const *argv[])
{
	cin>>p_Number>>k_Step;
	int count;
	for( count = 0;count <= k_Step;count++){
		string _p_Number = p_Number;
		reverse(_p_Number.begin(), _p_Number.end());
		if(p_Number == _p_Number||count == k_Step)
			break;
		addTwoNumber(_p_Number);
	}
	cout<<p_Number<<endl<<count;
	return 0;
}
