#include<stdio.h>
#include<conio.h>
void main()
{
	int n,i=0,b[100],j;
	printf("Enter decimal number: ");
	scanf("%d",&n);
	while (n>0)
	{
		b[i]=n%2;
		n=n/2;
		i++;
	}
	printf("Binary is: ");
	j=i-1;
	for (i=j;j>=0;j--)
	{
		printf("%d", b[j]);
	}
}
