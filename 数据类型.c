#include<stdio.h>
main()
{
	char a;
	short b;
	int c;
	long d;
	long long e;
	float f;
	double g;
	scanf("%c",&a);
	scanf("%hd",&b);
	scanf("%d",&c);
	scanf("%ld",&d);
	scanf("%lld",&e);
	scanf("%f",&f);
	scanf("%lf",&g);
	printf("The result is:\n");
	printf("The 'char' variable is %c, it takes %d byte.\n",a,sizeof(char));
	printf("The 'short' variable is %hd, it takes %d byte.\n",b,sizeof(short));
	printf("The 'int' variable is %d, it takes %d byte.\n",c,sizeof(int));
	printf("The 'long' variable is %ld, it takes %d byte.\n",d,sizeof(long));
	printf("The 'long long' variable is %lld, it takes %d byte.\n",e,sizeof(long long));
	printf("The 'float' variable is %f, it takes %d byte.\n",f,sizeof(float));
	printf("The 'double' variable is %lf, it takes %d byte.\n",g,sizeof(double));
	return 0;
	
}
