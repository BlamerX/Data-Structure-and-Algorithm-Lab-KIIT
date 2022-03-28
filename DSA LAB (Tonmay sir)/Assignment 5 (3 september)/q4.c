// WAP to create a single circular double linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.

#include <stdio.h>
#include <stdlib.h>

struct nodeSCLL
{
    int data;
    struct nodeSCLL *next;
    struct nodeSCLL *prev;
} *head = NULL;

void insert(int newData)
{
    struct nodeSCLL *newNode = malloc(sizeof(struct nodeSCLL));
    struct nodeSCLL *last = head;

    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
    return;
}

void printList()
{
    struct nodeSCLL *ptr = head;

    printf("The Data in the List is: ");
    if (head != NULL)
    {
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head);
    }
}

int main()
{
    insert(2);
    insert(0);
    insert(2);
    insert(9);
    insert(1);
    insert(9);
    insert(6);

    printList();

    return 0;
}