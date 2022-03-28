// WAP to determine whether the given matrix is a lower triangular or upper triangular or tri - diagonal matrix.

#include <stdio.h>

int q6()
{

    int mat[10][10], n;

    printf("\n Enter dimension of square matrix: ");
    scanf("%d", &n);

    printf("\n Enter the elements for the matrix: ");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("\n Element for positon : [%d,%d] :", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
    int flag1 = 0, flg2 = 0, flg3 = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                if (mat[i][j] == 0)
                {
                    flag1 = 1;
                    break;
                }

            if (i != j)
            {
                if (mat[i][j] != 0)
                {
                    flag1 = 1;
                    break;
                }
                else if (mat[i] > mat[j] && mat[i][j] == 0)
                {
                    flg2 = flg2 + 1;
                }
                else if ((mat[i] < mat[j]) && (mat[i][j] == 0))
                {
                    flg3 = flg3 + 1;
                }
            }
        }

    if (flag1 == 0)
        printf("\n A Diagonal Matrix .");
    else if (flg3 == 3)
        printf("\n Lower Triangular Matrix.");
    else if (flg2 == 3)
        printf("\n Upper Triangular matrix.");

    printf("\n\n Matrix :\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }

    return 0;
}