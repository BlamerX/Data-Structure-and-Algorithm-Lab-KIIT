// WAP to swap all the elements in the 1st column with all the corresponding elements in the last column, and 2nd column with the second last column and 3rd with 3rd last etc.of a 2 - D array.Dsiplay the matrix.

#include <stdio.h>
int main()
{
    int n, m, temp = 0;
    scanf("%d %d", &n, &m);

    int arr[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // Swapping of columns
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m / 2; j++)
        {
            temp = arr[i][j];
            arr[i][j] = arr[i][m - j - 1];
            arr[i][m - j - 1] = temp;
        }
    }

    printf("The new array is: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return 0;
}