//#include<stdio.h>
void main()
{
	int a;
	printf("enter a number");
	scanf("%d",&a);
	int sum=0,  t, temp=a;
	while(n>0)
	{
		while(temp!=0)
		{
			t=temp%10;
			sum+=t;
			temp=temp/10;
		}
		temp=sum;
		sum=0;
	}
	printf("%d",sum);
}
	
	
