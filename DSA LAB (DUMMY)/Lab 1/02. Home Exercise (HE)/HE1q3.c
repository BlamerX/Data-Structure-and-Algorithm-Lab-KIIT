// Write a program to replace every element in the array with the next greatest element present in the same array.

#include <stdio.h>

void replaceWithNextGreatest(int arr[], int n)
{
    int max = arr[n - 1];
    arr[n - 1] = 0; // last element is always replace with zero

    // Replace all other elements with the next greatest
    for (int i = n - 2; i >= 0; i--)
    {
        int temp = arr[i];
        arr[i] = max;

        // Update the greatest element, if needed
        if (max < temp)
            max = temp;
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    replaceWithNextGreatest(arr, n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}