// WAP to determine whether the given matrix is a sparse matrix or not .

#include <stdio.h>

void q5()
{
    int matrix[10][10];
    int i, j, m, n, sparseCounter = 0;

    printf("Enter the order of the matix \n");
    scanf("%d %d", &m, &n);
    printf("Enter the elements of the matix \n");
    for (i = 0; i < m; ++i)
    {
        for (j = 0; j < n; ++j)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] == 0)
                ++sparseCounter;
        }
    }
    if (sparseCounter > ((m * n) / 2))
        printf("The given matrix is Sparse Matrix !!! \n");
    else
        printf("The given matrix is not a Sparse Matrix \n");
    printf("There are %d number of Zeros.", sparseCounter);
}
