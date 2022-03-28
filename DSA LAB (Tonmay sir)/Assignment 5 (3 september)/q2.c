// WAP to reverse the sequence elements in a double linked list.

#include <stdio.h>
#include <stdlib.h>

struct NodeDLL
{
    int data;
    struct NodeDLL *next;
    struct NodeDLL *prev;
} *tail = NULL, *head = NULL;

void createDLL()
{
    int n, data;
    struct NodeDLL *newNode;

    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);

    head = malloc(sizeof(struct NodeDLL));
    scanf("%d", &data);
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
    for (int i = 2; i <= n; i++)
    {
        newNode = malloc(sizeof(struct NodeDLL));
        scanf("%d", &data);
        newNode->data = data;
        newNode->prev = tail;
        newNode->next = NULL;
        tail->next = newNode;
        tail = newNode;
    }
}

void printListDLL()
{
    struct NodeDLL *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void Reverse()
{
    struct NodeDLL *current, *temp;

    current = head;
    while (current != NULL)
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    temp = head;
    head = tail;
    tail = temp;
}

int main()
{

    createDLL();

    printf("Traversal in forward direction \n");
    printListDLL();
    printf("Traversal in reverse direction \n");
    Reverse();
    printListDLL();
}