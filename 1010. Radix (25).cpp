#include "iostream"
#include "cstdio"
#include "string"

using namespace std;


long long to_Dec(string p,long long radix)
{
	long long sum = 0,a = 1;
	for (int i = p.length()-1; i >= 0; i--)
	{
		if (p[i]>='0'&&p[i]<='9')
		{
			sum += a*((long long)(p[i]-'0'));
		}
		else if (p[i]>='a'&&p[i]<='z')
		{
			sum += a*((long long)(p[i]-'a')+10);
		}
		a *= radix;
	}
	return sum;
}


long long find_max_digit(string p)
{
	long long max = 0, temp;
	for (int i = 0; i < p.length(); ++i)
	{
		if (p[i]>='0'&&p[i]<='9')
		{
			temp = ((long long)(p[i]-'0'));
		}
		else if (p[i]>='a'&&p[i]<='z')
		{
			temp = ((long long)(p[i]-'a')+10);
		}
		if (max<temp)
		{
			max = temp;
		}
	}
	return max + 1;
}


long long max_N1_dec_and_left(long long a,long long b )
{
	return a>b?a+1:b+1;
}


long long compare(long long target,string p,long long radix)
{
	long long sum = 0,a = 1;
	for (int i = p.length()-1; i >= 0; i--)
	{
		if (p[i]>='0'&&p[i]<='9')
		{
			sum += a*((long long)(p[i]-'0'));
		}
		else if (p[i]>='a'&&p[i]<='z')
		{
			sum += a*((long long)(p[i]-'a')+10);
		}
		a *= radix;
		if(target < sum)
		{
			return -1;
		 } 

	}
	if (target > sum)
	{
		return 1;
	}
	else if (target < sum)
	{
		return -1;
	}
	else
	{
		return 0;
	}
}


long long binarysearch(long long target,string p,long long left, long long right)
{
	long long mid = (left + right)/2;
	while(right >= left)
	{
		long long res = compare(target, p, mid);
		if (res > 0)
		{
			left = mid + 1;
		}
		else if (res < 0)
		{
			right = mid - 1;
		}
		else
		{
			return mid;
		}
		mid = (left + right)/2;
	}
	return -1;
}


int main(int argc, char const *argv[])
{
	string N1,N2;
	long long num, radix, left, right, result, N_dec;
	cin>>N1>>N2>>num>>radix;
	if (num == 1)
	{
		N_dec = to_Dec(N1,radix);
		left = find_max_digit(N2);
		right = max_N1_dec_and_left(N_dec,left);
		result = binarysearch(N_dec,N2,left,right);
	}
	else if (num == 2)
	{
		N_dec = to_Dec(N2,radix);
		left = find_max_digit(N1);
		right = max_N1_dec_and_left(N_dec,left);
		result = binarysearch(N_dec,N1,left,right);
	}
	if (result == -1)
	{
		cout<<"Impossible";
	}
	else
	{
		cout<<result;
	}
	return 0;
}
