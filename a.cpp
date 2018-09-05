#include "iostream"
#include "vector"
#include "algorithm" 
using namespace std;

int main(int argc, char const *argv[])
{
	int arrayNum;
	cin>>arrayNum;
	int array1[arrayNum];
	int array2[arrayNum];

	for (int i = 0; i < arrayNum; ++i)
	{
		cin>>array1[i];
	}
	//getchar(); 
	for (int i = 0; i < arrayNum; ++i)
	{
		cin>>array2[i];
	}

	int insertPin;
	bool isInsertion = 1;
	for (int i = arrayNum-1; i >= 0; --i)
	{
		if (array1[i]!=array2[i])
		{
			insertPin = i;
			break;
		}
	}

	for (int i = 0; i < insertPin; ++i)
	{
		if(array2[i]>array2[i+1])
		{
			isInsertion = 0;
			break;
		}
	}
	int n = 2;
	if (isInsertion == 1)
	{
		sort(array1,array1+insertPin+2);	
	}
	else if (isInsertion == 0)
	{
		bool isEqual = true;
		while(isEqual == true)
		{
			isEqual = false;
			if(equal(array1,array1+arrayNum,array2) == false)
			{
				isEqual = true;
			}
			for (int i = 0; i < arrayNum-n; i+=n)
			{
				sort(array1+i,array1+i+n);
			}
			sort(array1+arrayNum-arrayNum%n,array1+arrayNum);
			n *=2;
		}
	}
	if (isInsertion == 1)
	{
		cout<<"Insertion Sort\n";
	}
	else
	{
		cout<<"Merge Sort"<<endl;
	}
	
	for (int i = 0; i < arrayNum; ++i)
	{
		cout<<array1[i];
		if(i != arrayNum-1)
		{
			cout<<' ';
		}
	}

	return 0;
}
