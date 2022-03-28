// Write a menu driven program to perform the following operations in a double linked list by
// using suitable user defined functions for each case.
// a) Traverse the list forward
// b) Traverse the list backward
// c) Check if the list is empty
// d) Insert a node at the certain position (at beginning/end/any position)
// e) Delete a node at the certain position (at beginning/end/any position)
// f) Delete a node for the given key
// g) Count the total number of nodes
// h) Search for an element in the linked list
// Verify & validate each function from main method.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodeDLL
{
    int data;
    struct nodeDLL *next;
    struct nodeDLL *prev;
} *head = NULL;

void printListForwardDLL();

void insertAtBegining(int newData)
{
    struct nodeDLL *newNode = malloc(sizeof(struct nodeDLL));

    newNode->data = newData;
    newNode->next = head;
    newNode->prev = NULL;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
}

void insertAtEnd(int newData)
{

    struct nodeDLL *newNode = malloc(sizeof(struct nodeDLL));
    struct nodeDLL *last = head;

    newNode->data = newData;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
    return;
}

void insertAtIndex(int newData)
{

    int position;
    printf("Enter the index: ");
    scanf("%d", &position);

    struct nodeDLL *newNode, *ptr;

    if (head == NULL)
        printf("Error, List is Empty\n");
    else
    {
        ptr = head;
        int i = 1;
        while (i < position - 1 && ptr != NULL)
        {
            ptr = ptr->next;
            i++;
        }
        if (position == 1)
            insertAtBegining(newData);
        else if (ptr != NULL)
        {
            newNode = malloc(sizeof(struct nodeDLL));
            newNode->data = newData;
            newNode->next = ptr->next;
            newNode->prev = ptr;

            if (ptr->next != NULL)
                ptr->next->prev = newNode;
            ptr->next = newNode;
        }
        else
            insertAtEnd(newData);
    }
}

void insertInDLL()
{
    int ch, Data;
    printf("\n");
    printf("1. Insert a node at beginning\n");
    printf("2. Insert a node at any position\n");
    printf("3. Insert a node at end\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    printf("Enter the Data: ");
    scanf("%d", &Data);
    if (ch == 1)
        insertAtBegining(Data);
    else if (ch == 2)
        insertAtIndex(Data);
    else if (ch == 3)
        insertAtEnd(Data);
    else
        printf("Invalid argument");

    printListForwardDLL();

    printf("\n");
}

void checkDLLForEmpty()
{
    if (head == NULL)
        printf("The List is empty\n\n");
    else
        printf("The List is Not empty\n\n");
}

void deleteAtBegining()
{
    struct nodeDLL *current;
    if (head == NULL)
        printf("List is empty ERROR Deleting");
    else
    {
        current = head;
        head = head->next;
        head->prev == NULL;
        free(current);
    }
}

void deleteAtIndex()
{
    int position;
    printf("Enter the index to delete: ");
    scanf("%d", &position);

    struct nodeDLL *temp = head;

    for (int i = 0; i < position && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp != NULL)
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    else
        printf("\nInvalid position!\n");
}

void deleteAtEnd()
{
    struct nodeDLL *current;
    if (head == NULL)
        printf("List is empty ERROR Deleting");
    else
    {
        current = head;
        while (current->next != 0)
        {
            current->prev = current;
            current = current->next;
        }
        free(current);
        current->prev->next = 0;
    }
}

void deleteInDLL()
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

    printListForwardDLL();

    printf("\n");
}

void printListForwardDLL()
{
    struct nodeDLL *node = head, *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }
}

void printListBackwardDLL()
{
    struct nodeDLL *node = head, *last;
    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

void deleteByKeyInDLL()
{
    int key;
    printf("Enter the key: ");
    scanf("%d", &key);

    struct nodeDLL *temp = head;
    if (head->data == key)
    {
        head = head->next;
        head->prev = NULL;
        temp->next = temp->prev = NULL;
        free(temp);
    }
    else
    {
        while (temp->next->data != key)
            temp = temp->next;
        struct nodeDLL *temp2 = temp->next;
        temp->next = temp2->next;
        temp2->next->prev = temp;
    }

    printListForwardDLL();
    printf("\n");
}

void countNodeInDLL()
{
    int count = 1;
    while (head->next != NULL)
    {
        head = head->next;
        count++;
    }
    printf("Total number of Nodes are %d\n", count);
}

bool search(int n)
{
    struct nodeDLL *current = head;
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

void searchListDLL()
{
    int num;
    printf("Enter the value you want to search: ");
    scanf("%d", &num);

    search(num) ? printf("\nThe value is present\n") : printf("\nThe value is not present\n");
}

int main()
{
    int ch;
    while (1)
    {
        printf("\n---LINKED LIST PROGRAMS---\n");
        printf("1. Traverse the list forward\n");
        printf("2. Traverse the list backward\n");
        printf("3. Check if the list is empty\n");
        printf("4. Insert a node at the certain position (at beginning/end/any position)\n");
        printf("5. Delete a node at the certain position (at beginning/end/any position)\n");
        printf("6. Delete a node for the given key\n");
        printf("7. Count the total number of nodes\n");
        printf("8. Search for an element in the linked list\n");
        printf("9. EXIT\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printListForwardDLL();
            break;
        case 2:
            printListBackwardDLL();
            break;
        case 3:
            checkDLLForEmpty();
            break;
        case 4:
            insertInDLL();
            break;
        case 5:
            deleteInDLL();
            break;
        case 6:
            deleteByKeyInDLL();
            break;
        case 7:
            countNodeInDLL();
        case 8:
            searchListDLL();
            break;
        case 9:
            exit(1);
            break;
        default:
            printf("INVALID CHOICE!!");
            break;
        }
    }

    return 0;
}