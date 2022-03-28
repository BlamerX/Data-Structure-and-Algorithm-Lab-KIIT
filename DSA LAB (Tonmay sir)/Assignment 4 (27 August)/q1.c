// Create a single linked list and perform the following operations :
// (a)Insert the new list at any position.
// (b)Insert the new list in front.
// (c)Insert the new list at the end.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void displayList();

void insertAtBegining()
{
    int newData;
    printf("Enter the data: ");
    scanf("%d", &newData);

    struct node *newNode = (struct node *)malloc(sizeof(struct node));

    // Insert the data
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

void insertAtIndex()
{

    int newData, position;
    printf("Enter the data: ");
    scanf("%d", &newData);
    printf("Enter the index: ");
    scanf("%d", &position);

    struct node *ptr = malloc(sizeof(struct node)), *temp = head;

    ptr->data = newData;
    int i;
    if (position == 1)
    {
        ptr->next = temp;
        head = ptr;
        return;
    }

    for (i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }

    ptr->next = temp->next;
    temp->next = ptr;
}

void insertAtEnd()
{
    int newData;
    printf("Enter the data: ");
    scanf("%d", &newData);

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

void insert()
{
    int ch;
    printf("\n");
    printf("1. Insert a node at beginning\n");
    printf("2. Insert a node at any position\n");
    printf("3. Insert a node at end\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    if (ch == 1)
        insertAtBegining();
    else if (ch == 2)
        insertAtIndex();
    else if (ch == 3)
        insertAtEnd();
    else
        printf("Invalid argument");

    displayList();
    printf("\n");
}

void displayList()
{
    struct node *current = malloc(sizeof(struct node));
    current = head;
    printf("\nThe node is:\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    free(current);
    printf("\n");
}

int main()
{
    int n;

    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        insert();

    return 0;
}