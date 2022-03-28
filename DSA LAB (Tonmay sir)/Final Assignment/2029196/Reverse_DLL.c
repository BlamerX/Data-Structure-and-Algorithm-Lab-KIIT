// WAP to reverse the sequence elements in a double linked list.

#include <stdio.h>
#include <stdlib.h>

struct NodeDLL23
{
    int data;
    struct NodeDLL23 *next;
    struct NodeDLL23 *prev;
} *tail23 = NULL, *head23 = NULL;

void createDLL23()
{
    int n, data;
    struct NodeDLL23 *newNode;

    printf("Enter the total number of nodes in list: ");
    scanf("%d", &n);

    head23 = malloc(sizeof(struct NodeDLL23));
    scanf("%d", &data);
    head23->data = data;
    head23->prev = NULL;
    head23->next = NULL;
    tail23 = head23;
    for (int i = 2; i <= n; i++)
    {
        newNode = malloc(sizeof(struct NodeDLL23));
        scanf("%d", &data);
        newNode->data = data;
        newNode->prev = tail23;
        newNode->next = NULL;
        tail23->next = newNode;
        tail23 = newNode;
    }
}

void printListDLL()
{
    struct NodeDLL23 *current = head23;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void Reverse()
{
    struct NodeDLL23 *current, *temp;

    current = head23;
    while (current != NULL)
    {
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        current = temp;
    }
    temp = head23;
    head23 = tail23;
    tail23 = temp;
}

int ReverseDisplayOfDLL()
{

    createDLL23();

    printf("Traversal in forward direction \n");
    printListDLL();
    printf("Traversal in reverse direction \n");
    Reverse();
    printListDLL();
}