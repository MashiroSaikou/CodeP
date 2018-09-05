#include "iostream"
#include "string"
#include "math.h"
#include "iomanip"
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	double p = 0;
	for (int i = 0; i < n; ++i)
	{
		int a, b;
		cin>>a>>b;
		p =  p > sqrt(a*a+b*b)?p:sqrt(a*a + b*b);
	}
	cout.setf(ios::fixed);
	cout<<setprecision(2)<<p;
	return 0;
}
