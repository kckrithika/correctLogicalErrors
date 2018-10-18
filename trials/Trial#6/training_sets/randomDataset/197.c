//#include <stdio.h>
//#include <math.h>
int main()
{
    long long binaryNumber,x;
int octalNumber = 0, decimalNumber = 0, i = 0;

    printf("Enter a binary number: ");
    scanf("%lld", &x);
binaryNumber = x;
while(binaryNumber != 0)
    {
        decimalNumber += (binaryNumber%10) * pow(2,i);
        ++i;
        binaryNumber/=10;
    }

    i = 1;

    while (decimalNumber != 0)
    {
        octalNumber += (decimalNumber % 8) * i;
        decimalNumber /= 8;
        i *= 10;
    }

    printf("%lld in binary = %d in octal", x, octalNumber);

    return 0;
}
