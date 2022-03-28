// WAP by modifying LE4.1 to multiply polynomials with single variable. Use the same function in LE4.1 written for creation & display operations and write a new function for addition operations.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int coeff;
    int exp;
    struct node *next;
};

void display(struct node *head);

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
    printf("\n");
}

void multiplication(struct node **h, struct node *h1, struct node *h2)
{
    struct node *ptr1, *ptr2, *current, *ptr;

    for (ptr1 = h1; ptr1 != NULL; ptr1 = ptr1->next)
    {
        for (ptr2 = h2; ptr2 != NULL; ptr2 = ptr2->next)
        {
            current = malloc(sizeof(struct node));
            current->next = NULL;
            current->coeff = ptr1->coeff * ptr2->coeff;
            current->exp = ptr1->exp + ptr2->exp;
            if (*h == NULL)
            {
                *h = current;
                ptr = current;
            }
            else
            {
                ptr->next = current;
                ptr = current;
            }
        }
    }
}

int main()
{
    struct node *h1 = NULL, *h2 = NULL, *h3 = NULL;

    printf("Creation of Polynomial p\n");
    create(&h1);
    printf("Creation of Polynomial q\n");
    create(&h2);

    printf("The polynomial p * q is r = ");
    multiplication(&h3, h1, h2);
    display(h3);

    return 0;
}