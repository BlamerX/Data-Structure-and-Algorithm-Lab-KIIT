// WAP to remove duplicates from a linked list of n nodes.

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

    struct node *current = malloc(sizeof(struct node));

    // Insert the data
    current->data = newData;
    current->next = head;
    head = current;
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
        printf("3. Remove duplicates from the list\n");
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
            removeDuplicates();
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