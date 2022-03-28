// WAP to multiply two sparse matrix.

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

void multiplication(struct node *A, struct node *B, struct node **C)
{
    struct node *ptr, *ptr1, *current, *prev;
    if (A->column != B->row)
        return;
    *C = malloc(sizeof(struct node));
    (*C)->row = A->row;
    (*C)->column = A->column;
    (*C)->val = 0;
    (*C)->next = NULL;
    ptr = *C;
    for (ptr = A->next; ptr != NULL; ptr = ptr->next)
    {
        for (ptr1 = B->next; ptr1 != NULL; ptr1 = ptr1->next)
        {
            if (ptr->column == ptr1->row)
            {
                current = malloc(sizeof(struct node));
                current->row = ptr->row;
                current->column = ptr1->column;
                current->val = ptr->val * ptr1->val;
                current->next = NULL;
                ptr->next = current;
                ptr = current;
                (*C)->val++;
            }
        }
    }
    for (ptr = (*C)->next->next; ptr != NULL; ptr = ptr->next)
    {
        prev = ptr;
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr->row == ptr1->row && ptr->column == ptr1->column)
            {
                ptr->val = ptr->val + ptr1->val;
                prev->next = ptr1->next;
                free(ptr);
                ptr1 = prev;
                (*C)->val--;
            }
            prev = ptr1;
            ptr1 = ptr1->next;
        }
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
    struct node *A, *B, *C;
    A = B = C = NULL;

    create(&A);
    create(&B);

    multiplication(A, B, &C);
    display(C);

    return 0;
}