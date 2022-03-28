// WAP to add two distances (in km-meter) by passing structure to a function.

#include <stdio.h>
#include <stdlib.h>

struct distance
{
    float km;
};

float sum(float *num1, float *num2)
{
    float sum, meter;
    sum = *num1 + *num2;
    return sum;
}

int main()
{
    int n = 2;
    struct distance *dis;

    dis = malloc(n * sizeof(struct distance));

    printf("Enter the distance in KM: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &(dis + i)->km);
    }

    float meter;
    meter = sum(&(dis)->km, &(dis + 1)->km) * 1000;
    printf("The total distance is %0.2f meter", meter);
    return 0;
}