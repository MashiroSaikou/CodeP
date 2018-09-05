#include<stdio.h>
main()
{
	int f[]={0,1};
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=2;i<=n;++i)
	{
		f[i] = f[i-2] + f[i-1];
		printf("%d",f[i]);
	}
	return 0;
}
