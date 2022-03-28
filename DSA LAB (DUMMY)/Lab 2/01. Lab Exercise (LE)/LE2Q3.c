// WAP to create a linear linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void getData(struct node **current, int n)
{
    for (int i = 0; i < n; i++)
    {
        *current = malloc(sizeof(struct node));
        scanf("%d", &(*current)->data);
        (*current)->next = NULL;
        if (head == NULL)
        {
            head = tail = *current;
        }
        else
        {
            tail->next = *current;
            tail = *current;
        }
    }
}

void displayList(struct node **current)
{
    *current = head;
    while (*current != NULL)
    {
        printf("%d ", (*current)->data);
        *current = (*current)->next;
    }
    printf("\n");
}

int main()
{
    int num;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &num);

    struct node *c;

    getData(&c, num);
    displayList(&c);

    return 0;
}