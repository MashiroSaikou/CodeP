#include "iostream"
#include "iomanip"

using namespace std;

int main(int argc, char const *argv[])
{
	float *line = new float[1001]();
	int n, index;
	float data;
	for (int i = 0; i < 2; ++i)
	{
		cin>>n;
		for (int j = 0; j < n; ++j)
		{
			cin>>index>>data;
			line[index] += data;
		}
	}

	int num = 0;
	for (int i = 0; i < 1001; ++i)
	{
		if (line[i] != 0)
		{
			num++;
		}
	}
	cout<<num;
	for (int i = 1000; i >= 0; --i)
	{
		if (line[i] != 0.0)
		{
			cout<<' '<<i<<' '<<line[i];
		}
	}


	return 0;
}
