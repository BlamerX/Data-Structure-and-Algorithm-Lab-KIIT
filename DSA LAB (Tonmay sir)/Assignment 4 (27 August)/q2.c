// Create a single linked list and perform the following operations :

// (a)Delete the list from any position.
// (b)Delete the list from the front.
// (c)Delete the list from the end.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insert(int newData)
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
    struct node *current = malloc(sizeof(struct node));
    current = head;
    printf("\nThe node is:\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    free(current);
    printf("\n\n");
}

void deleteAtBegining()
{
    struct node *current;
    if (head == NULL)
        printf("List is empty ERROR Deleting");
    else
    {
        current = head;
        head = head->next;
        free(current);
    }
}

void deleteAtIndex()
{
    int position;
    printf("Enter the index to delete: ");
    scanf("%d", &position);

    struct node *temp = head;

    if (position == 0)
    {
        head = temp->next;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL || temp->next == NULL)
        return;

    struct node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void deleteAtEnd()
{
    struct node *current, *previous;
    if (head == NULL)
        printf("List is empty ERROR Deleting");
    else
    {
        current = head;
        while (current->next != 0)
        {
            previous = current;
            current = current->next;
        }
        free(current);
        previous->next = 0;
    }
}

void delete ()
{
    int ch;
    printf("\n");
    printf("1. Delete a node at beginning\n");
    printf("2. Delete a node at any position\n");
    printf("3. Delete a node at end\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    if (ch == 1)
        deleteAtBegining();
    else if (ch == 2)
        deleteAtIndex();
    else if (ch == 3)
        deleteAtEnd();
    else
        printf("Invalid argument");

    displayList();
    printf("\n");
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

    displayList();
    delete ();
}