//#include<stdio.h>
void  main()
{
	long int p;
	int x,sum=0,a,b,sum1=0;
	printf("enter a four digit no\n");
	scanf("%ld",&p);
	while(p>0)
	{
    	a=p%10;
    	p=p/10;
    	sum=sum+a;
  	}
  	printf("%ld",sum);
  	again:
  	for( ;sum>10; )
 	{
   		b=sum%10;
   		sum=sum/10;
   		sum1=sum1+b+sum;
  	}
  	if(sum1>10)
  	{
    	goto again;
  	}
   	else
   	{
    	printf("\nthe final sum is %d",sum1);
   	}
}
