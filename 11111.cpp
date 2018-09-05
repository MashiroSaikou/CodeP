#include "iostream"
#include "string"

using namespace std;

int main(int argc, char const *argv[])
{
	string PAT;
	cin>>PAT;
	int zero_A = 0;
	int first_A = PAT.find_first_of('A',0);
	int number_P = 0,number_T = 0,number_A = 0;
	int number_PA = 0,number_PAT = 0;
	int sum = 0;
	for (int i = 0; i < PAT.length(); ++i)
	{
		if (PAT[i] == 'P')
		{
			number_P ++;
		}
		if (PAT[i] == 'A')
		{
			number_PA = (number_P + number_PA)%1000000007;
		}
		if(PAT[i] == 'T')
		{
			number_PAT = (number_PA + number_PAT)%1000000007;
		}
	}
	
	cout<<(number_PAT);
/*	for (int i = 0; i < number_A ; ++i)
	{
		for (int i = zero_A; i < first_A; ++i)
		{
			if(PAT[i] == 'P')
			{
				number_P ++;
			}
			if(PAT[i] == 'T')
			{
				number_T --;
			}
		}
		sum = sum + number_T*number_P;
		zero_A = first_A;
		first_A = PAT.find_first_of('A',zero_A+1);
	}

	cout<<(sum%1000000007);
*/
	return 0;
}
