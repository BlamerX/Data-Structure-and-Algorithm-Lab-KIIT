// Given a singly linked list, rotate the linked list counter - clockwise by k nodes.Where k is a given positive integer.For example, if the given linked list is 10->20->30->40->50->60 and k is 4, the list should be modified to 50->60->10->20->30->40. Assume that k is smaller than the count of nodes in the linked list.

struct node16
{
    int data;
    struct node16 *next;
};

struct node16 *head16 = NULL;

void create16(int newData)
{
    struct node16 *newNode = malloc(sizeof(struct node16));
    struct node16 *last = head16;

    newNode->data = newData;
    newNode->next = NULL;

    if (head16 == NULL)
    {
        head16 = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    return;
}

void displayList16()
{
    printf("The node is: ");
    struct node16 *current = head16;
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void modified(int k)
{
    struct node16 *current = head16, *temp = current;

    if (k == 0)
        return;
    int count = 1;
    while (count < k && current != NULL)
    {
        current = current->next;
        count++;
    }
    if (current == NULL)
        return;

    while (current->next != NULL)
        current = current->next;

    current->next = head16;
    head16 = temp->next;
    temp->next = NULL;

    displayList16();
}

int ClockwiseRotationInSSL()
{
    create16(2);
    create16(0);
    create16(2);
    create16(9);
    create16(1);
    create16(9);
    create16(6);

    displayList16();
    int n;
    printf("Enter value of k: ");
    scanf("%d", &n);

    modified(n);
}