#include "iostream"
#include "string"
#include "math.h"
#define move_up 6
#define move_down 4
#define move_stay 5
using namespace std;

int main(int argc, char const *argv[])
{
	int N,floor_now = 0,floor_number,p = 0;
	cin>>N;
	//int *floor_number = new int[N]();
	for (int i = 0; i < N; ++i)
	{
		cin>>floor_number;
		if (floor_number > floor_now)
		{
			p = p + move_up*(abs(floor_number-floor_now)) + move_stay;
			floor_now = floor_number;
		}
	}
	cout<<p;
	return 0;
}