//#include<stdio.h>
 main()
{
	int a=2,b=2,e=0,f=0;
	e=(++a + ++a + ++a);
	f=(b++ + b++ + b++);
	printf("%d %d",e,f);
}
