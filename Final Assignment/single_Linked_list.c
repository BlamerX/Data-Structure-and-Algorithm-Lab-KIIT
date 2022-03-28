// Write a menu driven program to perform the following operations in a single linked list by
// using suitable user defined functions for each case.
// a) Traversal of the list
// b) Check if the list is empty
// c) Insert a node at the certain position (at beginning/end/any position)
// d) Delete a node at the certain position (at beginning/end/any position)
// e) Delete a node for the given key
// f) Count the total number of nodes
// g) Search for an element in the linked list
// Verify & validate each function from main method.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtBegining()
{
    int newData;
    printf("Enter the data: ");
    scanf("%d", &newData);

    struct node *newNode = malloc(sizeof(struct node));

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

    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = newData;
    int i;
    struct node *temp = head;
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

    // If head needs to be removed
    if (position == 0)
    {
        head = temp->next;
        free(temp);
        return;
    }

    // Find previous node of the node to be deleted
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

    printf("\n\n");
}

void deleteAtKey()
{
    int key;
    printf("Enter the Key: ");
    scanf("%d", &key);

    struct node *current = head, *previous;

    if (current != NULL && current->data == key)
    {
        head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != key)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    previous->next = current->next;
    free(current);
}

bool search(int n)
{
    struct node *current = head;
    while (current != NULL)
    {
        if (current->data == n)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void searchList()
{
    int num;
    printf("Enter the value you want to search: ");
    scanf("%d", &num);

    search(num) ? printf("The value is present\n\n") : printf("The value is not present\n\n");
}

void traversalList()
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

void checkList()
{
    if (head == NULL)
        printf("The List is empty\n\n");
    else
        printf("The List is Not empty\n\n");
}

void nodeSizeIs()
{
    struct node *current = head;
    int nodeSize = 0;

    while (current != NULL)
    {
        nodeSize++;
        current = current->next;
    }
    printf("The node size is: %d\n\n", nodeSize);
}

int main()
{
    int ch;
    while (1)
    {
        printf("---LINKED LIST PROGRAMS---\n");
        printf("1. Traversal of the list\n");
        printf("2. Check if the List is empty\n");
        printf("3. Insert a node at the certain position (at beginning/end/any position)\n");
        printf("4. Delete a node at the certain position (at beginning/end/any position)\n");
        printf("5. Delete a node for the given key\n");
        printf("6. Count the total number of nodes\n");
        printf("7. Search for an element in the linked list\n");
        printf("8. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            traversalList();
            break;
        case 2:
            checkList();
            break;
        case 3:
            insert();
            break;
        case 4:
            delete ();
            break;
        case 5:
            deleteAtKey();
            break;
        case 6:
            nodeSizeIs();
            break;
        case 7:
            searchList();
            break;
        case 8:
            exit(1);
            break;
        default:
            printf("INVALID CHOICE!!");
            break;
        }
    }

    return 0;
}