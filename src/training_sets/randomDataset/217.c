//#include<stdio.h>
 
int main() {
   int amount, rate, time, si;
 
   printf("\nEnter Principal Amount : ");
   scanf("%d", &amount);
 
   printf("\nEnter Rate of Interest : ");
   scanf("%d", &rate);
 
   printf("\nEnter Period of Time   : ");
   scanf("%d", &time);
 
   si = (amount * rate * time) / 100;
   printf("\nSimple Interest : %d", si);
 
   return(0);
}
