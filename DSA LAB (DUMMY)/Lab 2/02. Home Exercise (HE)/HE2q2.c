// WAP to count the number of occurrences of an element in a linked list of n nodes.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

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

void traversalList()
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

void nodeSizeIs()
{
    struct node *current = head;
    int nodeSize = 0;

    while (current != NULL)
    {
        nodeSize++;
        current = current->next;
    }
    traversalList();
    printf("The node size is: %d\n\n", nodeSize);
}

int main()
{
    int ch;
    while (1)
    {
        printf("1. Insert a node\n");
        printf("2. Traversal of the list\n");
        printf("3. Count the total number of nodes\n");
        printf("4. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert();
            break;
        case 2:
            traversalList();
            break;
        case 3:
            nodeSizeIs();
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