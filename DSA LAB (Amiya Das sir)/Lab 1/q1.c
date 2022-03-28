// WAP to find the largest number and counts the occurrence of the largest number in an array of n integers using a single loop.

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

    int max = arr[0], count = 0;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == max)
        {
            count++;
        }
    }

    printf("max number is: %d\nTotal num of occurrence is: %d", max, count);

    return 0;
}