//#include<stdio.h>
void main()
{
	long int num;
	int sum,n1,n;
	sum=0;
    printf("\nenter_a_number");
    scanf("%ld",&num);
   	start:
    while(num>0)
    {
    	n1=num%10;
    	sum=sum+n1;
    	num=num/10;
    }
   	if(sum>9)
   	{
   		num=sum;
   		sum=0;
   		goto start;
   	}
   	printf("\nsum_is_%d",sum);
}      
