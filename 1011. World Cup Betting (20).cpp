#include "iostream"
#include "cstdio"
#include "vector"
#include "iomanip"
using namespace std;

int main(int argc, char const *argv[])
{
	char *game = new char[3];
	double profit = 1.0;
	for (int i = 0; i < 3; ++i)
	{
		double max = 0.0;
		for (int j = 0; j < 3; ++j)
		{
			double v;
			cin>>v;
			if (v >= max)
			{
				max = v;
				if (j == 0)
					game[i] = 'W';
				else if(j == 1)
					game[i] = 'T';
				else if(j == 2)
					game[i] = 'L'; 				
			}
		}
		profit *= max;
	}
	cout<<game[0]<<' '<<game[1]<<' '<<game[2]<<' ';
	printf("%.2f",(profit*0.65-1)*2);
	return 0;
}
