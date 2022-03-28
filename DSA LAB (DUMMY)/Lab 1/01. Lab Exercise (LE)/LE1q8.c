// Let A be n*n square matrix array. WAP by using appropriate user defined functions for the following:
// a) Find the number of nonzero elements in A
// b) Find the sum of the elements above the leading diagonal.
// c) Display the elements below the minor diagonal.
// d) Find the product of the diagonal elements.

#include <stdio.h>

int noOfZeros(int n, int arr[n][n])
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 0)
                count++;
        }
    }
    printf("The number of nonzero elements are: %d\n", count);

    return 0;
}

int sumAboveDiagonal(int n, int arr[n][n])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i)
                sum += arr[i][j];
        }
    }
    printf("The sum of elements above leading diagonal is: %d\n", sum);

    return 0;
}

int elementBelowDiagonal(int n, int arr[n][n])
{
    printf("The elements below the minor diagonal are\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
                printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int productOfDiagonal(int n, int arr[n][n])
{
    int product = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                product *= arr[i][j];
        }
    }
    printf("The product of diagonal elements is: %d", product);

    return 0;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // int n = 6;
    // int arr[6][6] = {{1, 2, 3, 4, 5, 6}, {0, 2, 5, 8, 4, 8}, {0, 1, 2, 3, 4, 5}, {1, 2, 3, 4, 5, 6}, {0, 2, 5, 8, 4, 8}, {0, 1, 2, 3, 4, 5}};

    noOfZeros(n, arr);
    sumAboveDiagonal(n, arr);
    elementBelowDiagonal(n, arr);
    productOfDiagonal(n, arr);

    return 0;
}