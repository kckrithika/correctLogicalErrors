//#include <stdio.h>
//#include <math.h>

int main()
{
    int i;
    float data[10];
float sum = 0.0, mean, standardDeviation = 0.0;
    int i;
    printf("Enter 10 elements: ");
    for(i=0; i < 10; ++i)
        scanf("%f", &data[i]);
for(i=0; i<10; ++i)
    {
        sum += data[i];
    }

    mean = sum/10;

    for(i=0; i<10; ++i)
        standardDeviation += pow(data[i] - mean, 2);
standardDeviation = sqrt(standardDeviation/10);
    printf("\nStandard Deviation = %.6f", standardDeviation);

    return 0;
}
