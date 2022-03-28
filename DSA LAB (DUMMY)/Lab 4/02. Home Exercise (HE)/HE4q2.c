// WAP to represent a sparse matrix in 3 - tuple format by using linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row;
    int column;
    int val;
    struct node *next;
};

void create(struct node **h, int arr, int r, int c)
{
    struct node *ptr, *current;
    ptr = *h;
    if (ptr == NULL)
    {
        ptr = malloc(sizeof(struct node));
        ptr->val = arr;
        ptr->row = r;
        ptr->column = c;
        ptr->next = NULL;
        *h = ptr;
    }
    else
    {
        while (ptr->next != NULL)
            ptr = ptr->next;
        current = malloc(sizeof(struct node));
        current->val = arr;
        current->row = r;
        current->column = c;
        current->next = NULL;
        ptr->next = current;
    }
}

void display(struct node *head)
{
    struct node *current = head;
    printf("Row Column Value\n");
    while (current != NULL)
    {
        printf("%d\t%d\t  %d", current->row, current->column, current->val);
        current = current->next;
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int row, column;
    printf("Enter the row & columns of the source matrix: ");
    scanf("%d%d", &row, &column);

    int arr[row][column];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    struct node *head = NULL;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            if (arr[i][j] != 0)
                create(&head, arr[i][j], i, j);
        }
    }

    display(head);

    return 0;
}