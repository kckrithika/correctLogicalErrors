//#include<stdio.h>

void main()
{
    int num,i,j;
    printf("Enter the value of N:");
    scanf("%d",&num);
 
    for(i=num;i>1;i--)   //Outer Loop for number of rows
    {
        for(j=num;j>i;j--)  // First blamk pyramid
            printf(" ");
 
        for(j=1;j<=i;j++)   //second pyramid
            printf("%d",j);
 
        printf("\n");        // for new line
    }
}
