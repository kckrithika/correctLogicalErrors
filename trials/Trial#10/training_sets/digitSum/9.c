//#include <stdio.h>
int main()
{
    long number;
    int sum=0;
    int digit;

    printf("Enter the number\n");
    scanf("%ld",&number);

    while(number>0)
    {
        sum=0;
        while(number>0)
        {
            digit=number%10;
            number=number/10;
            sum=sum+digit;
        }
        if(sum>9)
        {
            number=sum;
        }
    }

    printf("The sum is %d",sum);

    return 0;
}
