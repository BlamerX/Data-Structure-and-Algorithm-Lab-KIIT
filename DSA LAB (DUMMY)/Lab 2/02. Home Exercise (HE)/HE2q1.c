// WAP to search an element in a simple linked list, if found delete that node node and insert that node at beginning.Otherwise display an appropriate message.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL, *tail = NULL;

void insertAtBegining(int newData)
{
    struct node *newNode = malloc(sizeof(struct node));

    // Insert the data
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}

void insert()
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

void deletionAtKey(int key)
{
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

void operationOnList()
{
    int num;
    printf("Enter the value you want to search: ");
    scanf("%d", &num);

    search(num) ? deletionAtKey(num) : printf("The value is not present\n\n");

    insertAtBegining(num);
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

int main()
{
    int ch;
    while (1)
    {
        printf("1. Display of the list\n");
        printf("2. Insert a node\n");
        printf("3. Operation (search an element in a simple linked list, if found delete that node node and insert that node at beginning)\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            displayList();
            break;
        case 2:
            insert();
            break;
        case 3:
            operationOnList();
            break;
        case 4:
            exit(1);
            break;
        default:
            printf("INVALID CHOICE!!");
            break;
        }
    }

    return 0;
}