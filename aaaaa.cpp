#include "iostream"
#include "string"

using namespace std;
int main(int argc, char const *argv[])
{
	string p;
	getline(cin, p);
	int count = p.length();
	int n = 0;
	for (int i = 0; i < count; ++i)
	{
		if(p[i] > 'a'&&p[i] < 'z')
		{
			n += ((int)(p[i] - 'a')+1);
		}
		else if(p[i] > 'A'&&p[i] < 'Z')
		{
			n += ((int)(p[i] - 'A')+1);
		}

	}
	int a = 0,b = 0;
	for (; n > 0; n/=2)
	{
		if(n%2 == 0)
		{
			a++;
		}
		else if(n%2 == 1)
		{
			b++;
		}
	}
	cout<<a<<' '<<b;
	return 0;
}
