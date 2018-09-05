#include "iostream"
#include "cstdio"
#include "math.h"

using namespace std;

bool isPrimeData(int data)
{
	for (int i = 2; i <= sqrt(data); ++i)
	{
		if (data%i == 0)
		{
			return false;
		}
	}
	if(data == 1)
	{
		return false;
	}
	return true;
}

int reverseData(int data, int radix)
{
	int count = 1;
	int _data = 0;
	for (; data > 0; data /= radix)
	{
		_data = _data*radix + data%radix;
	}
	return _data;
}
int main(int argc, char const *argv[])
{
	int data, radix;
	while(cin>>data>>radix)
	{
		//Trans(data,radix);
		if(isPrimeData(data))
		{
			data = reverseData(data,radix);
			if (isPrimeData(data))
			{
				cout<<"Yes"<<endl;
				continue;
			}
		}
		cout<<"No"<<endl;
	}
	return 0;
}
