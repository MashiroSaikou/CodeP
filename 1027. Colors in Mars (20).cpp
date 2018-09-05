#include "iostream"
#include "cstdio"
using namespace std;
int main(int argc, char const *argv[])
{
	char *earthColor = new char[6];
	char *marsColor = new char[7];
	marsColor[0] = '#';
	for (int i = 0; i < 3; ++i){
		int color, number;
		cin>>color;
		number = color/13;
		if(number < 10){
			marsColor[i*2+1] = '0'+number;
		}
		else if(number < 12&&number > 9){
			marsColor[i*2+1] = 'A'+number-10;
		}
		number = color%13; 
		if(number < 10){
			marsColor[i*2+2] = '0'+number;
		}
		else if(number < 13&&number > 9){
			marsColor[i*2+2] = 'A'+number-10;
		}		
	}
	for (int i = 0; i < 7; ++i){
		cout<<marsColor[i];
	}
	cout<<endl;
	return 0;
}
