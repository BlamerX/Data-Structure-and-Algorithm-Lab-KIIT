// WAP to print the middle of a double linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

void create(int val)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = val;
    if (head == NULL)
    {
        head = temp;
        temp->prev = NULL;
        temp->next = NULL;
    }
    else
    {
        struct node *temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp->prev = temp1;
        temp1->next = temp;
        temp->next = NULL;
    }
}

void display()
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void middle()
{
    struct node *temp = head;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    temp = head;
    int p = 1;
    if (c % 2 == 0)
    {
        int mid = c / 2;
        while (temp != NULL)
        {
            if (p == mid)
                break;
            p++;
            temp = temp->next;
        }
        printf("%d\n", temp->next->data);
    }
    else
    {
        int mid = (c + 1) / 2;
        while (temp != NULL)
        {
            if (p == mid)
                break;
            p++;
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
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

    printf("The List is: ");
    display();
    printf("The Middle node is: ");
    middle();

    return 0;
}