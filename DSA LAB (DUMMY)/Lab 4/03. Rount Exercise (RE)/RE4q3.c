// WAP to create a linked list that represents a polynomial expression with double variables (e.g. :4x2y3-3xy+x-5y+7) and display the polynomial by using user defined functions for creation and display.

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
    struct node *ptr = *A;
    int temp = 0;
    for (; ptr != NULL; ptr = ptr->next)
    {
        temp = ptr->row;
        ptr->row = ptr->column;
        ptr->column = temp;
    }
    *A = ptr;
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

    create(&A);
    transpose(&A);
    display(A);

    return 0;
}