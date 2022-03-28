// WAP to remove the duplicates in a sorted double linked list.

#include <stdio.h>
#include <stdlib.h>

struct node11
{
    int data;
    struct node11 *previous;
    struct node11 *next;
};

struct node11 *head11, *tail11 = NULL;

void addnode11(int data)
{
    struct node11 *newnode11 = malloc(sizeof(struct node11));
    newnode11->data = data;

    if (head11 == NULL)
    {
        head11 = tail11 = newnode11;
        head11->previous = NULL;
        tail11->next = NULL;
    }
    else
    {
        tail11->next = newnode11;
        newnode11->previous = tail11;
        tail11 = newnode11;
        tail11->next = NULL;
    }
}

void sortList()
{
    struct node11 *current = NULL, *index = NULL;
    int temp;
    if (head11 == NULL)
        return;
    else
    {
        for (current = head11; current->next != NULL; current = current->next)
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

void removeDuplicatenode11()
{
    struct node11 *current, *index, *temp;

    if (head11 == NULL)
        return;
    else
    {
        for (current = head11; current != NULL; current = current->next)
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
    struct node11 *current = head11;
    if (head11 == NULL)
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

int DuplicateRemovalInDLL()
{
    addnode11(2);
    addnode11(0);
    addnode11(2);
    addnode11(9);
    addnode11(1);
    addnode11(9);
    addnode11(6);

    printf("Originals list: ");
    display();
    printf("List aftersorting: ");
    sortList();
    display();
    printf("List after removing duplicates: ");
    removeDuplicatenode11();
    display();

    return 0;
}