// Given a singly linked list, rotate the linked list counter - clockwise by k nodes.Where k is a given positive integer.For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in the linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int newData)
{
    struct node *newNode = malloc(sizeof(struct node));
    struct node *last = head;

    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    return;
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
    struct node *current = head, *temp = current;

    if (k == 0)
        return;
    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;

    while (current->next != NULL)
        current = current->next;

    current->next = head;
    head = temp->next;
    temp->next = NULL;

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
}