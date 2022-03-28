// WAP to remove duplicates from a linked list of n node21s.

struct node21
{
    int data;
    struct node21 *next;
};

struct node21 *head21 = NULL;

void create21(int newData)
{
    struct node21 *newnode21 = malloc(sizeof(struct node21));
    struct node21 *last = head21;

    newnode21->data = newData;
    newnode21->next = NULL;

    if (head21 == NULL)
    {
        head21 = newnode21;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newnode21;
    return;
}

void display21()
{
    struct node21 *current = head21;
    printf("The node21 is:\n");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    free(current);
    printf("\n");
}

void removeDuplicates()
{
    struct node21 *current = head21, *temp, *duplicate;

    while (current != NULL && current->next != NULL)
    {
        temp = current;
        while (temp->next != NULL)
        {
            if (current->data == temp->next->data)
            {
                duplicate = temp->next;
                temp->next = temp->next->next;
                free(duplicate);
            }
            else
                temp = temp->next;
        }
        current = current->next;
    }
}

int RemovalOfDuplicatesInSSL()
{

    create21(2);
    create21(0);
    create21(2);
    create21(9);
    create21(1);
    create21(9);
    create21(6);

    display21();

    printf("After the removal of duplicates\n");
    removeDuplicates();
    display21();

    return 0;
}