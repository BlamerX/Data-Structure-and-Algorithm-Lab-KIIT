// WAP to display the contents of a linked list in reverse order

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

void reverseList(struct node **current)
{

    struct node *previous = NULL;
    struct node *next = NULL;
    *current = head;

    while ((*current) != NULL)
    {
        next = (*current)->next;
        (*current)->next = previous;
        previous = (*current);
        (*current) = next;
    }

    head = previous;
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
    printf("The reverse order is: ");
    reverseList(&c);
    displayList(&c);

    return 0;
}