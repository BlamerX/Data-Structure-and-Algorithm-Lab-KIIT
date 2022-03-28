// WAP by modifying LE4.1 to add two polynomials with single variable. Use the same function in LE4.1 written for creation & display operations and write a new function for addition operations.

struct node92
{
    int coeff92;
    int exp92;
    struct node92 *next;
};

void create92(struct node92 **head)
{
    int noOfTerms;
    printf("Enter how many terms: ");
    scanf("%d", &noOfTerms);

    struct node92 *ptr, *current;

    for (int i = 0; i < noOfTerms; i++)
    {
        current = malloc(sizeof(struct node92));
        current->next = NULL;
        printf("Enter the coeff92icient and exp92onent of polynomial x = ");
        scanf("%d%d", &current->coeff92, &current->exp92);
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

void display92(struct node92 *head)
{
    struct node92 *current = head;
    while (current != NULL)
    {
        printf("%dx^%d", current->coeff92, current->exp92);
        current = current->next;
        if (current != NULL && current->coeff92 >= 0)
            printf(" + ");
        else
            printf(" ");
    }
    printf("\n");
}

void join92(struct node92 **h1, struct node92 *h2)
{
    struct node92 *ptr;
    if (*h1 == NULL)
        *h1 = h2;
    else
    {
        for (ptr = *h1; ptr->next != NULL; ptr = ptr->next)
            ;
        ptr->next = h2;
    }
}

void addition92(struct node92 **h)
{
    struct node92 *ptr, *ptr1, *prev;

    for (ptr = *h; ptr != NULL; ptr = ptr->next)
    {
        prev = ptr;
        ptr1 = ptr->next;
        while (ptr1 != NULL)
        {
            if (ptr1->exp92 == ptr->exp92)
            {
                ptr->coeff92 = ptr->coeff92 + ptr1->coeff92;
                prev->next = ptr1->next;
                free(ptr1);
                ptr1 = prev;
            }
            prev = ptr1;
            ptr1 = ptr1->next;
        }
    }
}

int Addition()
{
    struct node92 *h1 = NULL, *h2 = NULL;

    printf("Creation of Polynomial p\n");
    create92(&h1);
    printf("Creation of Polynomial q\n");
    create92(&h2);

    printf("The polynomial p = ");
    display92(h1);
    printf("The polynomial q = ");
    display92(h2);

    printf("The polynomial p + q is r = ");
    join92(&h1, h2);
    addition92(&h1);
    display92(h1);

    return 0;
}