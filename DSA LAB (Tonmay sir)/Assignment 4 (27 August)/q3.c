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

void insert(int newData)
{
    struct node *newNode = malloc(sizeof(struct node));

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
    insertAtBegining(key);
}

void insertAtBegining(int newData)
{
    struct node *newNode = malloc(sizeof(struct node));

    newNode->data = newData;
    newNode->next = head;
    head = newNode;
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
    printf("\nThe node is:\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    free(head);
    printf("\n\n");
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
    operationOnList();
    displayList();

    return 0;
}