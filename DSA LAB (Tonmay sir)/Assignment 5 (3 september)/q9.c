// Given a double linked list, rotate the linked list counter - clockwise by k nodes.Where k is a given positive integer.For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
} *head = NULL;

void create(int newData)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = newData;
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

void displayList()
{
    printf("The node is: ");
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void modified(int k)
{
    if (k == 0)
        return;

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->prev = temp;

    int count = 1;
    while (count <= k)
    {
        head = head->next;
        temp = temp->next;
        count++;
    }

    temp->next = NULL;
    head->prev = NULL;

    displayList();
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

    displayList();
    int n;
    printf("Enter value of k: ");
    scanf("%d", &n);
    modified(n);

    return 0;
}