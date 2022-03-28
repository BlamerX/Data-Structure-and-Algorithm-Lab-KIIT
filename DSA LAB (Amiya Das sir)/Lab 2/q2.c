// Write a c program to copy all elements from an array to another array.

#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr1[n], arr2[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
        arr1[i] = arr2[i];
    }

    printf("Elements stored in another array are\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}