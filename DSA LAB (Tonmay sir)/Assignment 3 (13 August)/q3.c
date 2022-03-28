// Write a menu driven program to perform the following operations in a single linked list by using suitable user defined functions for each case.
// a) Create a list and display the list.
// b) Check if the list is empty

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

void reverseList(struct node **current)
{
    *current = head;
    int temp = head;
    head = tail;
    tail = temp;
    while (*current != NULL)
    {
        printf("%d ", (*current)->data);
        *current = (*current)->next;
    }
    printf("\n");
}

int check(struct node **current)
{
    *current = head;
    if ((*current)->next == NULL)
        printf("The List is empty");
    else
        printf("The list is not empty");
}

int main()
{
    int num;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &num);

    struct node *c;

    getData(&c, num);
    displayList(&c);
    check(&c);

    return 0;
}