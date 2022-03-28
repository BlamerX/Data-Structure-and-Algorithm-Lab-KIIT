// WAP to modify the linked list such that all even databers appear before all the odd databers in the modified linked list.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void getdata()
{
    struct node *current;
    for (int i = 0; i < 6; i++)
    {
        current = malloc(sizeof(struct node));
        current->data = rand() % 100;
        current->next = head;
        head = current;
    }
    // current = head;
}

void modify()
{
    struct node *even = NULL, *odd = NULL, *temp, *current = head, *reven, *rodd;

    while (current != NULL)
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->data = current->data;
        temp->next = NULL;
        if (current->data % 2 == 0)
        {
            if (even == NULL)
                even = temp;
            else
                reven->next = temp;
            reven = temp;
        }
        else
        {
            if (odd == NULL)
                odd = temp;
            else
                rodd->next = temp;
            rodd = temp;
        }
        current = current->next;
    }
    reven->next = odd;
    head = even;
}

void display()
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    getdata();
    display();

    modify();
    display();

    return 0;
}