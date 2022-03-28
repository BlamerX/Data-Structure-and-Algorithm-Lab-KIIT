// WAP to sort rows of a matrix having m rows and n columns in ascending & columns in descendng order.

#include <stdio.h>
int main()
{
    int m, n, temp = 0;
    scanf("%d %d", &m, &n);

    int arr1[m][n], arr2[m][n];

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &arr1[i][j]);
            arr2[i][j] = arr1[i][j];
        }
    }
    printf("The given matrix is \n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf(" %d", arr1[i][j]);
        }
        printf("\n");
    }
    printf("After arranging rows in ascending order\n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            for (int k = (j + 1); k < n; ++k)
            {
                if (arr1[i][j] > arr1[i][k])
                {
                    temp = arr1[i][j];
                    arr1[i][j] = arr1[i][k];
                    arr1[i][k] = temp;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf(" %d", arr1[i][j]);
        }
        printf("\n");
    }
    printf("After arranging the columns in descending order \n");
    for (int j = 0; j < n; ++j)
    {
        for (int i = 0; i < m; ++i)
        {
            for (int k = i + 1; k < m; ++k)
            {
                if (arr2[i][j] < arr2[k][j])
                {
                    temp = arr2[i][j];
                    arr2[i][j] = arr2[k][j];
                    arr2[k][j] = temp;
                }
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf(" %d", arr2[i][j]);
        }
        printf("\n");
    }

    return 0;
}