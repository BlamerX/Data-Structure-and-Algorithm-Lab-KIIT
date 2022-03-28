//Given an array, WAP to print the next greater element (NGE) for every element. The Next greater
//Element for an element x is the first greater element on the right side of x in array. Elements for which
//no greater element exist, consider next greater element as -1.
//Sample Input & Output
//For the input array [2, 5, 3, 9, 7}, the next greater elements for each element are as follows.
// Element NGE
//    2     5
//    5     9
//    3     9
//    7     -1

#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int arr[n], arr1[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
            arr1[i] = arr[i + 1];
        else
            arr1[i] = -1;
    }

    printf("Element NGE\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\n", arr[i], arr1[i]);
    }

    return 0;
}