// WAP to reverse the first m elements of a linked list of n nodes.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void create()
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

void reverse()
{
    int m;
    printf("Enter the mth element: ");
    scanf("%d", &m);

    struct node *temp = head;
    int count = 1;

    while (count < m)
    {
        temp = temp->next;
        count++;
    }

    struct node *jointPoint = temp->next;
    temp->next = NULL;

    struct node *previous = NULL, *current = head, *next;

    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    head = previous;
    current = head;
    while (current->next != NULL)
        current = current->next;

    current->next = jointPoint;
}

void display()
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
        printf("1. Insert a node\n");
        printf("2. Traversal of the list\n");
        printf("3. Reversing elements before mth element\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            reverse();
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