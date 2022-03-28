// WAP to find number of occurences of all elements in a linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct nodeOccur
{
    int data;
    int times;
    struct nodeOccur *next;
};

struct node *head = NULL;
struct nodeOccur *result = NULL;

void getData()
{
    // int newData;
    // printf("Enter the Data: ");
    // scanf("%d", &newData);

    // struct node *current = malloc(sizeof(struct node));
    // current->data = newData;
    // current->next = head;
    // head = current;

    struct node *current;
    for (int i = 0; i < 20; i++)
    {
        current = malloc(sizeof(struct node));
        current->data = rand() % 10;
        current->next = head;
        head = current;
    }
}

void count()
{
    struct node *current = head;
    struct nodeOccur *temp, *prev;

    while (current != NULL)
    {
        temp = result;
        while (temp != NULL && temp->data != current->data)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == NULL)
        {
            temp = malloc(sizeof(struct nodeOccur));
            temp->data = current->data;
            temp->times = 1;
            temp->next = NULL;
            if (result != NULL)
                prev->next = temp;
            else
                result = temp;
        }
        else
            temp->times += 1;
        current = current->next;
    }
}

void displayOccur()
{
    struct nodeOccur *current = result;
    while (current != NULL)
    {
        printf("%d\t%d\n", current->data, current->times);
        current = current->next;
    }
}

void display()
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
}

int main()
{
    getData();

    count();
    printf("The node is: ");
    display();
    printf("\nThe occurence of each element is:\n");
    displayOccur();

    return 0;
}