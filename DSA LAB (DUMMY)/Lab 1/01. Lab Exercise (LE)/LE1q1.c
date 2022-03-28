// WAP to find out the smallest and largest element stored in an array of n integers.

#include <stdio.h>
int main()
{

    int n;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max = arr[0], min = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }

    printf("min = %d,max = %d", min, max);

    return 0;
}