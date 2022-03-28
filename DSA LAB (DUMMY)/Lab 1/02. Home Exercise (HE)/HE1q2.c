// WAP to arrange the elements of an array such that all even numbers are followed by all odd numbers.

#include <stdio.h>
int main()
{
    int n, count = 0, temp = 0;
    scanf("%d", &n);

    int arr[n], arr1[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        if (arr[i] % 2 == 1)
            count++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    int k = 0, j = n - count;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 0)
        {
            if (k < n - count)
                arr1[k++] = arr[i];
        }
        else
        {
            if (j < n)
                arr1[j++] = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr1[i]);
    }

    return 0;
}