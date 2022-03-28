// WAP to check whether a singly linked list is a palindrome or not .

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node
{
    char data;
    struct node *next;
};

bool isPalindrome(struct node *head, int count)
{
    struct node *front, *rear;
    int i = 0;

    while (i != count / 2)
    {
        front = rear = head;
        for (int j = 0; j < i; j++)
            front = front->next;
        for (int j = 0; j < count - (i + 1); j++)
            rear = rear->next;
        if (front->data != rear->data)
            return false;
        else
            i++;
    }
    return true;
}

void getData(struct node **head_ref, char new_data)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    struct node *head = NULL;
    char str[] = "kanak";
    int count = (sizeof(str) / sizeof(str[0])) - 1;

    for (int i = 0; str[i] != '\0'; i++)
    {
        getData(&head, str[i]);
    }
    isPalindrome(head, count) ? printf("Is Palindrome\n") : printf("Not Palindrome\n");

    return 0;
}