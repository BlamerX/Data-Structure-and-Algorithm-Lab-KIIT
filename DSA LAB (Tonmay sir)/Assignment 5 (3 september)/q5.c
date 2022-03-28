// WAP to remove the duplicates in a sorted double linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
};

struct node *head, *tail = NULL;

void addNode(int data)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;

    if (head == NULL)
    {
        head = tail = newNode;
        head->previous = NULL;
        tail->next = NULL;
    }
    else
    {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
        tail->next = NULL;
    }
}

void sortList()
{
    struct node *current = NULL, *index = NULL;
    int temp;
    if (head == NULL)
        return;
    else
    {
        for (current = head; current->next != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data > index->data)
                {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }
            }
        }
    }
}

void removeDuplicateNode()
{
    struct node *current, *index, *temp;

    if (head == NULL)
        return;
    else
    {
        for (current = head; current != NULL; current = current->next)
        {
            for (index = current->next; index != NULL; index = index->next)
            {
                if (current->data == index->data)
                {
                    temp = index;
                    index->previous->next = index->next;
                    if (index->next != NULL)
                        index->next->previous = index->previous;
                    temp = NULL;
                }
            }
        }
    }
}

void display()
{
    struct node *current = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    addNode(2);
    addNode(0);
    addNode(2);
    addNode(9);
    addNode(1);
    addNode(9);
    addNode(6);

    printf("Originals list: ");
    display();
    printf("List aftersorting: ");
    sortList();
    display();
    printf("List after removing duplicates: ");
    removeDuplicateNode();
    display();

    return 0;
}