// WAP to create a double linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.

#include <stdio.h>
#include <stdlib.h>

struct nodeDLL
{
    int data;
    struct nodeDLL *prev;
    struct nodeDLL *next;
} *head = NULL, *tail = NULL;

void createDLL(int n)
{
    int i, data;
    struct nodeDLL *newNode;

    if (n >= 1)
    {
        head = malloc(sizeof(struct nodeDLL));

        if (head != NULL)
        {
            printf("Enter data of 1 node: ");
            scanf("%d", &data);

            head->data = data;
            head->prev = NULL;
            head->next = NULL;

            tail = head;
            for (i = 2; i <= n; i++)
            {
                newNode = malloc(sizeof(struct nodeDLL));
                if (newNode != NULL)
                {
                    printf("Enter data of %d node: ", i);
                    scanf("%d", &data);

                    newNode->data = data;
                    newNode->prev = tail;
                    newNode->next = NULL;

                    tail->next = newNode;
                    tail = newNode;
                }
                else
                    break;
            }
        }
    }
}

void displayDLL()
{
    struct nodeDLL *temp;

    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        printf("\n\nDATA IN THE LIST:\n");

        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    createDLL(7);
    displayDLL();

    return 0;
}