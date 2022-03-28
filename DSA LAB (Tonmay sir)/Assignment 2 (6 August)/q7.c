// You are given an array of 0s and1 s in random order.Segregate 0s on left side and 1s on right side of the array.Traverse array only once.

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n], count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            count++;
    }

    for (int i = 0; i < n; i++)
    {
        if (i < count)
            arr[i] = 0;
        else
            arr[i] = 1;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}