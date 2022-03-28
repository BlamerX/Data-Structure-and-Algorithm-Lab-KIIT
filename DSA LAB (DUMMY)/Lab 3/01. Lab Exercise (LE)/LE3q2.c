// WAP to reverse the sequence elements in a double linked list.

#include <stdio.h>
#include <stdlib.h>

struct NodeDLL
{
    int data;
    struct NodeDLL *next;
    struct NodeDLL *prev;
};

void createDLL(struct NodeDLL **head, int newData)
{
    struct NodeDLL *current = malloc(sizeof(struct NodeDLL)), *tail = *head;

    current->data = newData;
    current->next = NULL;

    if ((*head) == NULL)
    {
        current->prev = NULL;
        (*head) = current;
        return;
    }

    while (tail->next != NULL)
        tail = tail->next;
    tail->next = current;
    current->prev = tail;
}

void printListDLL(struct NodeDLL *node)
{
    struct NodeDLL *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

int main()
{
    struct NodeDLL *head = NULL;

    createDLL(&head, 2);
    createDLL(&head, 4);
    createDLL(&head, 8);
    createDLL(&head, 10);

    printListDLL(head);
}