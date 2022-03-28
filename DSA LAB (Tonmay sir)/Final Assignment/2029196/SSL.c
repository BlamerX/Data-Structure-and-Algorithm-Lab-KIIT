// Write a menu driven program to perform the following operations in a single linked list by using suitable user defined functions for each case.
// a) Create a list and display the list.
// b) Check if the list is empty

struct node1
{
    int data;
    struct node1 *next;
} *head1 = NULL, *tail1 = NULL;

void getData1(struct node1 **current, int n)
{
    for (int i = 0; i < n; i++)
    {
        *current = malloc(sizeof(struct node1));
        scanf("%d", &(*current)->data);
        (*current)->next = NULL;
        if (head1 == NULL)
        {
            head1 = tail1 = *current;
        }
        else
        {
            tail1->next = *current;
            tail1 = *current;
        }
    }
}

void displayList(struct node1 **current)
{
    *current = head1;
    while (*current != NULL)
    {
        printf("%d ", (*current)->data);
        *current = (*current)->next;
    }
    printf("\n");
}

void reverseList(struct node1 **current)
{
    *current = head1;
    int temp = head1;
    head1 = tail1;
    tail1 = temp;
    while (*current != NULL)
    {
        printf("%d ", (*current)->data);
        *current = (*current)->next;
    }
    printf("\n");
}

int check(struct node1 **current)
{
    *current = head1;
    if ((*current)->next == NULL)
        printf("The List is empty");
    else
        printf("The list is not empty");
}

int SingleLinkedList()
{
    int num;
    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &num);

    struct node1 *c;

    getData1(&c, num);
    displayList(&c);
    check(&c);

    printf("\n");

    return 0;
}