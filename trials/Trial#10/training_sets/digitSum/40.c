//#include<stdio.h>
void main()
{
	long int r,a,s=0;
	printf("enter the no");
	scanf(" %ld",&a);
	label:
	while(a>0)
	{
		r=a%10;
		s=s+r;
		a=a/10;
	}
	if(s>9)
	{
		a=s;
		s=0;
		goto label;
	}
	else
		printf(" %ld",s);
}
