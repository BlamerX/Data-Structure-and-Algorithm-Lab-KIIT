// Given a linked list which is sorted, WAP to insert an element into the linked list in sorted way.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node *create(int newData)
{
    struct node *current = malloc(sizeof(struct node));

    // Insert the data
    current->data = newData;
    current->next = head;
    head = current;

    return current;
}

void sortedInsetData(struct node *new_node)
{
    struct node *current;

    if (head == NULL || head->data >= new_node->data)
    {
        new_node->next = head;
        head = new_node;
    }
    else
    {
        current = head;
        while (current->next != NULL && current->next->data < new_node->data)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;
    }
}

void displayList()
{
    struct node *current;
    current = head;
    printf("\nThe node is:\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    struct node *new_node = create(5);
    sortedInsetData(new_node);
    new_node = create(10);
    sortedInsetData(new_node);
    new_node = create(23);
    sortedInsetData(new_node);
    new_node = create(67);
    sortedInsetData(new_node);
    new_node = create(45);
    sortedInsetData(new_node);

    displayList();
    return 0;
}
