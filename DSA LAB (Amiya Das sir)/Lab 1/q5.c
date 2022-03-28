// Write a program to find prime numbers in an array and store it in another array using dynamic memory allocation.

#include <stdio.h>
#include <stdlib.h>

int prime(int n)
{
    if (n <= 1)
        return 1;
    if (n == 2)
        return 0;
    if (n % 2 == 0)
        return 1;
    else
        return 0;
}

int main()
{
    int n;
    printf("Enter the length of the array: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("The prime numbers in the array are: ");
    for (int i = 0; i < n; i++)
    {
        if (prime(arr[i]) == 0)
            printf("%d ", arr[i]);
    }

    free(arr);

    return 0;
}