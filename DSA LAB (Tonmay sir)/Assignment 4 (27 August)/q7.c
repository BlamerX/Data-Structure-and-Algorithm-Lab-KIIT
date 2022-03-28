// WAP to remove duplicates from a linked list of n nodes.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create(int newData)
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

void display()
{
    struct node *current = head;
    printf("The node is:\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    free(current);
    printf("\n");
}

void removeDuplicates()
{
    struct node *current = head, *temp, *duplicate;

    while (current != NULL && current->next != NULL)
    {
        temp = current;
        while (temp->next != NULL)
        {
            if (current->data == temp->next->data)
            {
                duplicate = temp->next;
                temp->next = temp->next->next;
                free(duplicate);
            }
            else
                temp = temp->next;
        }
        current = current->next;
    }
}

int main()
{

    create(2);
    create(0);
    create(2);
    create(9);
    create(1);
    create(9);
    create(6);

    display();

    printf("After the removal of duplicates\n");
    removeDuplicates();
    display();

    return 0;
}