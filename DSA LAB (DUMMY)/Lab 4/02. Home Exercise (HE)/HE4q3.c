// WAP to find out the transpose of a sparse matrix.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int row;
    int column;
    int val;
    struct node *next;
};

void create(struct node **head)
{
    struct node *ptr, *current;
    *head = malloc(sizeof(struct node));
    (*head)->next = NULL;
    printf("Enter the row,column and no of values of matrix: ");
    scanf("%d%d%d", &(*head)->row, &(*head)->column, &(*head)->val);
    ptr = *head;
    for (int i = 0; i < (*head)->val; i++)
    {
        current = malloc(sizeof(struct node));
        current->next = NULL;
        printf("Enter row, column and value: ");
        scanf("%d%d%d", &current->row, &current->column, &current->val);
        ptr->next = current;
        ptr = current;
    }
}

void transpose(struct node **A)
{
    struct node *ptr;
    int temp;

    for (ptr = *A; ptr != NULL; ptr = ptr->next)
    {
        temp = ptr->row;
        ptr->row = ptr->column;
        ptr->column = temp;
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
    free(current);
    printf("\n");
}

int main()
{
    struct node *A;
    A = NULL;

    create(&A);
    transpose(&A);
    display(A);

    return 0;
}