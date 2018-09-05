#include<stdio.h>
main()
{
	int n;
	scanf("%d",&n);
	int result;
	result = Fib(n);
	printf("%d",result);
	return 0;
}
int Fib(int n)
{
	int count = 1;
	if(n == 0||n == 1)
		count = 1;
	else if(n >= 3)
	{
		count = Fib(n-1)+Fib(n-2);
	}
	return count; 
} 
