// WAP to convert a given singly linked list to a circular list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *head = NULL;

void create(int val)
{
    struct node *temp;

    temp = malloc(sizeof(struct node));
    temp->data = val;
    temp->next = head;
    head = temp;
}

void display()
{
    struct node *temp = head;
    printf("Displaying the list elements\n");
    printf("%d ", temp->data);
    temp = temp->next;
    while (head != temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("and back to %d %d %d.........\n", temp->data, temp->next->data, temp->next->next->data);
}

void tocircular()
{
    struct node *rear;

    rear = head;
    while (rear->next != NULL)
    {
        rear = rear->next;
    }
    rear->next = head;
}

int main()
{
    create(6);
    create(9);
    create(1);
    create(9);
    create(2);
    create(0);
    create(2);

    tocircular();
    printf("Circular list generated\n");
    display();

    return 0;
}