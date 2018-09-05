#include "iostream"
#include "string"
#include "iomanip"
#include "math.h" 
using namespace std;

int main(int argc, char const *argv[])
{
	int a,b,sum;
	cin>>a>>b;
	sum = a + b;
	if(abs(sum)>=1000000)
	{
		cout<<(sum/1000000)<<','<<setw(3)<<setfill('0')<<abs((sum/1000)%1000)<<','<<setw(3)<<setfill('0')<<abs(sum%1000);
	}
	else if(abs(sum)>=1000)
	{
		cout<<sum/1000<<','<<setw(3)<<setfill('0')<<abs(sum%1000);
	}
	else if(abs(sum)<1000)
	{
		cout<<sum;
	}
	return 0;
}
