#include "iostream"
#include "string"
#include "sstream"
using namespace std;

int main(int argc, char const *argv[])
{
	string English_Digit[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
	string number;
	getline(cin,number); 
	int sum = 0;
	string::iterator it;
	for (it = number.begin(); it !=  number.end(); it++)
	{
		sum = sum + (*it-'0');
	}
	
	stringstream temp;
	temp<<sum;
	string data = temp.str();
	
	for (it = data.begin(); it != data.end(); it++)
	{
		cout<<English_Digit[*it-'0'];
		if((it+1)!= data.end())
		{
			cout<<' ';
		}
	}
	return 0;
}
