//#include <stdio.h>
 
int main()
{
	int num, count, temp = 0;
    	printf("\nEnter a Number:\t");
    	scanf("%d", &num);
    	for(count = 2; count <= num/2; count++)
    	{
        	if(num%count == 0)
        	{
            		temp = 1;
            		break;
        	}
    	}
    	if(temp == 0)
        {
		printf("\n%d is a Prime Number\n", num);
	}
    	else
	{
        	printf("\n%d is Not a Prime Number\n", num);
	}
    	return 0;
}
