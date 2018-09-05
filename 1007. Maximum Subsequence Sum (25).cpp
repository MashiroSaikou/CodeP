#include "iostream"
#include "climits"
using namespace std;

int main(int argc, char const *argv[])
{
	int n,first,end,sum = -1, fake_sum = 0,left = 0;
	cin>>n;
	int *p = new int[n];
	bool benegative = true;
	for (int i = 0; i < n; ++i)
	{
		cin>>p[i];
		if (p[i]>=0)
			benegative = false;
		fake_sum = fake_sum + p[i];
		if (sum < fake_sum)
		{
			sum = fake_sum;
			first = p[left];
			end = p[i];
		}
		else if (fake_sum < 0)
		{
			fake_sum = 0;
			left = i + 1;
		}
	}
	if (benegative == false)
	{
		cout<<sum<<' '<<first<<' '<<end;
	}
	else if (benegative == true)
	{
		cout<<0<<' '<<p[0]<<' '<<p[n-1];
	}
	
	return 0;
}
