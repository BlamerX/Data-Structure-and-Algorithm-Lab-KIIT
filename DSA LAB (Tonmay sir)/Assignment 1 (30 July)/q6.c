// WAP to exchange the biggest and smallest element into the array of n intergers.

#include <stdio.h>
int main()
{

    int n, temp;
    scanf("%d", &n);
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int min = arr[0], max = arr[0], minat, maxat;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            maxat = i;
        }
        if (arr[i] < min)
        {
            min = arr[i];
            minat = i;
        }
    }

    temp = arr[minat];
    arr[minat] = arr[maxat];
    arr[maxat] = temp;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}