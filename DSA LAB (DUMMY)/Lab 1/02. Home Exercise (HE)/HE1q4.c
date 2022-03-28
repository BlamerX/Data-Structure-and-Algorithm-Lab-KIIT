// WAP to replace every array element by multiplication of previous and next of an n element.

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n], mul[n], multi = 1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        multi *= arr[i];
        mul[i] = multi;
    }

    for (int i = 0; i < n; i++)
    {
        printf("%d ", mul[i]);
    }

    return 0;
}