// WAP by modifying LE4.1 to add two polynomials with single variable. Use the same function in LE4.1 written for creation & display operations and write a new function for addition operations.

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
        if (current != NULL && current->coeff >= 0)
            printf(" + ");
        else
            printf(" ");
    }
    printf("\n");
}

void join(struct node **h1, struct node *h2)
{
    struct node *ptr;
    if (*h1 == NULL)
        *h1 = h2;
    else
    {
        for (ptr = *h1; ptr->next != NULL; ptr = ptr->next)
            ;
        ptr->next = h2;
    }
}

void addition(struct node **h)
{
    struct node *ptr, *ptr1, *prev;

    for (ptr = *h; ptr != NULL; ptr = ptr->next)
    {
        prev = ptr;
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr1->exp == ptr->exp)
            {
                ptr->coeff = ptr->coeff + ptr1->coeff;
                prev->next = ptr1->next;
                free(ptr1);
                ptr1 = prev;
            }
            prev = ptr1;
            ptr1 = ptr1->next;
        }
    }
}

int main()
{
    struct node *h1 = NULL, *h2 = NULL;

    printf("Creation of Polynomial p\n");
    create(&h1);
    printf("Creation of Polynomial q\n");
    create(&h2);

    printf("The polynomial p = ");
    display(h1);
    printf("The polynomial q = ");
    display(h2);

    printf("The polynomial p + q is r = ");
    join(&h1, h2);
    addition(&h1);
    display(h1);

    return 0;
}