// Write a program to count total number of negative elements in an array.

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, count = 0;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
            count++;
    }

    printf("Total number of negative elements are: %d", count);

    free(arr);

    return 0;
}