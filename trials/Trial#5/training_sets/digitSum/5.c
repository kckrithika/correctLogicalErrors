//#include<stdio.h>
void main()
{
	int n,c=0,r,i;
	printf("enter no.");
	scanf("%d",&n);
	while(n>0)
	{
		while(n>0)
		{
			r=n%10;
			c=c+r;
			n=n/10;
		}
		if(c>9)
		{
			n=c;
			c=0;
		}
	}
	printf("%d",c);
}
