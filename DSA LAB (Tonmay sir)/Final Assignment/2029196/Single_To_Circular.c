// WAP to convert a given singly linked list to a circular list.

struct node17
{
    int data;
    struct node17 *next;
} *head1716 = NULL;

void create17(int val)
{
    struct node17 *temp;

    temp = malloc(sizeof(struct node17));
    temp->data = val;
    temp->next = head1716;
    head1716 = temp;
}

void display17()
{
    struct node17 *temp = head1716;
    printf("Displaying the list elements\n");
    printf("%d ", temp->data);
    temp = temp->next;
    while (head1716 != temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("and back to %d %d %d.........\n", temp->data, temp->next->data, temp->next->next->data);
}

void tocircular()
{
    struct node17 *rear;

    rear = head1716;
    while (rear->next != NULL)
    {
        rear = rear->next;
    }
    rear->next = head1716;
}

int SingularToCircular()
{
    create17(6);
    create17(9);
    create17(1);
    create17(9);
    create17(2);
    create17(0);
    create17(2);

    tocircular();
    printf("Circular list generated\n");
    display17();

    return 0;
}