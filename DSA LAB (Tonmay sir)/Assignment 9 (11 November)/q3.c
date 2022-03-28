// A matrix m × n that has relatively few non - zero entries is called sparse matrix.It may be represented in much less than m × n space.An m × n matrix with k non - zero entries is sparse if k << m × n.It may be faster to represent the matrix compactly as a list of the non - zero indexes and associated entries.WAP to represent a sparse matrix in 3 - tuple format by using array.

// Sample Output
// Sparse Matrix Using Array
// Enter the row &columns of the source matrix : 3 4
// Elements of the source matrix :
// 2 0 1 0
// 0 0 3 4
// 0 6 0 0
// Elements of sparse matrix in 3 - tuple format :
//  Row Column Element
//   0    0      2
//   0    2      1
//   1    2      3
//   1    3      4
//   2    1      6

#include <stdio.h>
#define size 20

void getData(int a[size][size], int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void create(int a[size][size], int row, int column, int b[size][3])
{
    int k = 0;
    b[0][0] = row;
    b[0][1] = column;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (a[i][j] != 0)
            {
                b[k][0] = i;
                b[k][1] = j;
                b[k][2] = a[i][j];
                k++;
            }
        }
        b[0][2] = k;
    }
}

void display(int b[size][3])
{
    int column = b[0][2];
    printf("Row Column   Value\n");
    for (int i = 0; i < column; i++)
    {
        printf("%d\t%d\t%d\n", b[i][0], b[i][1], b[i][2]);
    }
}

int main()
{
    int row, column;
    printf("Enter the row & columns of the source matrix: ");
    scanf("%d%d", &row, &column);

    int arr[row][column], arr2[size][3];

    getData(arr, row, column);
    create(arr, row, column, arr2);
    display(arr2);

    return 0;
}