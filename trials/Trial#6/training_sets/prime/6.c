#include<stdio.h>
#include<conio.h>
void main()
{
    char ch;
    do{
        int a,b,flag=0;

        clrscr();

        printf("\tEnter a no (1-2000):");
        scanf("%d",&a);


        if(a<1 && a>2000)
        {
            exit(0);
          }
            for(b=2;b<a;b++)
            {
                if(a%b==0 )
                {

                flag=1;
                 break;
                   }
            }


    if(flag==0)
      printf("\n\t<%d> is a prime no\n",a);
    else
    printf("\n\t<%d>  is not a prime no\n",a);

    printf("\n\tContinue(y/n):");
    ch=getch();
      }while(ch=='y'||ch=='Y');



}

