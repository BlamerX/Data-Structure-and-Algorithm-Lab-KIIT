// WAP to display the contents of a linked list in reverse order.

struct node15
{
    int data;
    struct node15 *next;
};

struct node15 *head15 = NULL, *tail15 = NULL;

void getData15(struct node15 **current, int n)
{
    printf("Enter the list: ");
    for (int i = 0; i < n; i++)
    {
        *current = malloc(sizeof(struct node15));
        scanf("%d", &(*current)->data);
        (*current)->next = NULL;
        if (head15 == NULL)
        {
            head15 = tail15 = *current;
        }
        else
        {
            tail15->next = *current;
            tail15 = *current;
        }
    }
}

void reverseList15(struct node15 **current)
{

    struct node15 *previous = NULL;
    struct node15 *next = NULL;
    *current = head15;

    while ((*current) != NULL)
    {
        next = (*current)->next;
        (*current)->next = previous;
        previous = (*current);
        (*current) = next;
    }
    head15 = previous;
}

void displayList15(struct node15 **current)
{
    *current = head15;
    while (*current != NULL)
    {
        printf("%d ", (*current)->data);
        *current = (*current)->next;
    }
    printf("\n");
}

int ReverseContentInSSL()
{
    int num;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &num);

    struct node15 *c;

    getData15(&c, num);
    printf("The forward display is: ");
    displayList15(&c);
    printf("The reverse display is: ");
    reverseList15(&c);
    displayList15(&c);

    return 0;
}