//#include <stdio.h>
//#include <math.h>
void main()
{
long int num;
 
 printf("Enter the decimal number : ");
 scanf("%ld",&num);
 
while(num>0)
   {
      rem[i]=num%16;
      num=num/16;
      i++;
      length++;
   }
 
printf("Hexadecimal number : ");
for(i=length-1;i>=0;i--)
  {
    switch(rem[i])
    {
      case 10:
          printf("A");
          break;
      case 11:
          printf("B");
          break;
      case 12:
          printf("C");
          break;
      case 13:
          printf("D");
          break;
      case 14:
          printf("E");
          break;
      case 15:
          printf("F");
          break;
      default :
         printf("%ld",rem[i]);
    }
  }
}
