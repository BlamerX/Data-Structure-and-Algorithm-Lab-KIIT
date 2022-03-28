// WAP to find out the second smallest and second largest element stored in an array.

#include <stdio.h>
int main()
{
    int n, temp = 0;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i + 1; j++)
        {
            if (arr[j] >= arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Secound smallest is: %d\nSecound largest is: %d", arr[1], arr[n - 2]);

    return 0;
}