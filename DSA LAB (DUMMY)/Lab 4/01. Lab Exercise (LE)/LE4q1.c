// WAP to create a linked list that represents a polynomial expression with single variable (i.e.5x7-3x5+x2+9) and display the polynomial by using user defined functions for creation and display.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

void create(struct node **head)
{
    int noOfTerms;
    printf("Enter how many terms: ");
    scanf("%d", &noOfTerms);

    struct node *ptr, *current;

    for (int i = 0; i < noOfTerms; i++)
    {
        current = malloc(sizeof(struct node));
        current->next = NULL;
        printf("Enter the coefficient and exponent of polynomial x = ");
        scanf("%d%d", &current->coeff, &current->exp);
        if (*head == NULL)
        {
            *head = current;
            ptr = current;
        }
        else
        {
            ptr->next = current;
            ptr = current;
        }
    }
}

void display(struct node *head)
{
    struct node *current = head;
    while (current != NULL)
    {
        printf("%dx^%d", current->coeff, current->exp);
        current = current->next;
        if (current->coeff >= 0)
        {
            if (current != NULL)
                printf(" + ");
        }
        else
            printf(" ");
    }
}

int main()
{
    struct node *h1;
    h1 = NULL;

    create(&h1);
    display(h1);

    return 0;
}