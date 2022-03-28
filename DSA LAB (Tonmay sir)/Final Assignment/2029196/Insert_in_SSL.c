// Create a single linked list and perform the following operations :
// (a)Insert the new list at any position.
// (b)Insert the new list in front.
// (c)Insert the new list at the end.

struct node12
{
    int data;
    struct node12 *next;
};

struct node12 *head12 = NULL;

void displayList1();

void insertAtBegining()
{
    int newData;
    printf("Enter the data: ");
    scanf("%d", &newData);

    struct node12 *newNode = (struct node12 *)malloc(sizeof(struct node12));

    // Insert the data
    newNode->data = newData;
    newNode->next = head12;
    head12 = newNode;
}

void insertAtIndex()
{

    int newData, position;
    printf("Enter the data: ");
    scanf("%d", &newData);
    printf("Enter the index: ");
    scanf("%d", &position);

    struct node12 *ptr = malloc(sizeof(struct node12)), *temp = head12;

    ptr->data = newData;
    int i;
    if (position == 1)
    {
        ptr->next = temp;
        head12 = ptr;
        return;
    }

    for (i = 1; i < position - 1; i++)
    {
        temp = temp->next;
    }

    ptr->next = temp->next;
    temp->next = ptr;
}

void insertAtEnd()
{
    int newData;
    printf("Enter the data: ");
    scanf("%d", &newData);

    struct node12 *newNode = malloc(sizeof(struct node12));
    struct node12 *last = head12;

    newNode->data = newData;
    newNode->next = NULL;

    if (head12 == NULL)
    {
        head12 = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    return;
}

void insert12()
{
    int ch;
    printf("\n");
    printf("1. Insert a node at beginning\n");
    printf("2. Insert a node at any position\n");
    printf("3. Insert a node at end\n");
    printf("Enter your choice: ");
    scanf("%d", &ch);
    if (ch == 1)
        insertAtBegining();
    else if (ch == 2)
        insertAtIndex();
    else if (ch == 3)
        insertAtEnd();
    else
        printf("Invalid argument");

    displayList1();
    printf("\n");
}

void displayList1()
{
    struct node12 *current = malloc(sizeof(struct node12));
    current = head12;
    printf("\nThe node is:\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    free(current);
    printf("\n");
}

int SSLInsertion()
{
    int n;

    printf("Enter the number of nodes you want to enter: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        insert12();

    return 0;
}