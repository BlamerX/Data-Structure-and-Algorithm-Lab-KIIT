// WAP to create a linked list that represents a polynomial expression with single variable (i.e.5x7-3x5+x2+9) and display the polynomial by using user defined functions for creation and display.

struct node91
{
    int coeff;
    int exp;
    struct node91 *next;
};

void create91(struct node91 **head)
{
    int noOfTerms;
    printf("Enter how many terms: ");
    scanf("%d", &noOfTerms);

    struct node91 *ptr, *current;

    for (int i = 0; i < noOfTerms; i++)
    {
        current = malloc(sizeof(struct node91));
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

void display91(struct node91 *head)
{
    struct node91 *current = head;
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

int Polynomial()
{
    struct node91 *h1;
    h1 = NULL;

    create91(&h1);
    display91(h1);

    return 0;
}