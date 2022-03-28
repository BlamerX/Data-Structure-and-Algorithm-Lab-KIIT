// WAP to implement a doubly linked list by using singly linked.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int val)
{
    struct node *temp, *rear;

    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        rear->next = temp;
    }
    rear = temp;
}

void display()
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    create(2);
    create(0);
    create(2);
    create(9);
    create(1);
    create(9);
    create(6);

    printf("Displaying list:\n");
    display();

    return 0;
}