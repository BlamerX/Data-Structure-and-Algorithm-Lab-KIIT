// WAP to find out the kth smallest and kth largest element stored in a dynamic array of n integers, where k < n.

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

    int k, max = arr[0], min = arr[0];
    scanf("%d", &k);

    for (int i = 0; i < k; i++)
    {

        if (max < arr[i])
            max = arr[i];
        else if (min > arr[i])
            min = arr[i];
    }

    printf("The minimum element is: %d\nThe maximum element is: %d", min, max);

    return 0;
}