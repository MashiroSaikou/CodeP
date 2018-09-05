#include "iostream"
#include "vector"

using namespace std;

int main(int argc, char const *argv[])
{
	int n, base;
	cin>>n>>base;
	std::vector<int> v;
	do{
		v.push_back(n%base);
		n /= base;
	}while(n > 0);
	bool isPal = true;
	for (int i = 0; i < v.size()/2; ++i)
	{
		if(v[i] != v[v.size()-1-i]){
			isPal = false;
			break;
		}
	}
	if(isPal == true)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
	for (int i = v.size()-1; i > -1; i--)
	{
		if(i == 0)
			cout<<v[i];
		else
			cout<<v[i]<<' ';
	}
	return 0;
}
