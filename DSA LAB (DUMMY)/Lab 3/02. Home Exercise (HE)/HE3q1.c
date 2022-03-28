// WAP to create a double circular double linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.

#include <stdio.h>
#include <stdlib.h>

struct nodeDCLL
{
    int data;
    struct nodeDCLL *next;
    struct nodeDCLL *prev;
} *head = NULL;

void createDCLL(int n)
{
    struct nodeDCLL *ptr, *temp;
    int item;
    ptr = malloc(sizeof(struct nodeDCLL));
    if (ptr == NULL)
    {
        return;
    }
    else
    {
        ptr->data = n;
        if (head == NULL)
        {
            head = ptr;
            ptr->next = head;
            ptr->prev = head;
        }
        else
        {
            temp = head;
            while (temp->next != head)
            {
                temp = temp->next;
            }
            temp->next = ptr;
            ptr->prev = temp;
            head->prev = ptr;
            ptr->next = head;
        }
    }
}

void displayDCLL()
{
    struct nodeDCLL *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("\nnothing to print");
    }
    else
    {
        printf("Node are: ");

        while (ptr->next != head)
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        }
        printf("%d ", ptr->data);
    }
}

int main()
{

    createDCLL(7);
    createDCLL(23);
    createDCLL(45);
    createDCLL(78);
    createDCLL(62);

    displayDCLL();

    return 0;
}