// WAP to create a single circular double linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.

#include <stdio.h>
#include <stdlib.h>

struct nodeSCLL
{
    int data;
    struct nodeSCLL *next;
} *head = NULL;

void insert(int pos, int newData)
{
    struct nodeSCLL *current = malloc(sizeof(struct nodeSCLL)), *ptr;

    current->data = newData;
    current->next = NULL;
    if (head == NULL)
    {
        head = current;
        current->next = current;
    }
    else if (pos == 0)
    {
        struct nodeSCLL *temp;
        for (temp = head; temp->next != head; temp = temp->next)
        {
            current->next = head;
            head = current;
            temp->next = current;
        }
    }
    else
    {
        int i = 0;
        for (ptr = head; i < pos - 1; i++, ptr = ptr->next)
            ;
        i = 0;
        ptr = head;
        while (i < pos - 1)
        {
            i++;
            ptr = ptr->next;
        }
        current->next = ptr->next;
        ptr->next = current;
    }
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
    insert(1, 23);
    insert(2, 45);
    insert(4, 68);

    printList();

    return 0;
}