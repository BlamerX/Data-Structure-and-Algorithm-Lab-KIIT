// WAP to print the middle of a double linked list.

struct node221
{
    int data;
    struct node221 *next;
    struct node221 *prev;
} *head221 = NULL;

void create221(int val)
{
    struct node221 *temp = malloc(sizeof(struct node221));
    temp->data = val;
    if (head221 == NULL)
    {
        head221 = temp;
        temp->prev = NULL;
        temp->next = NULL;
    }
    else
    {
        struct node221 *temp1 = head221;
        while (temp1->next != NULL)
        {
            temp1 = temp1->next;
        }
        temp->prev = temp1;
        temp1->next = temp;
        temp->next = NULL;
    }
}

void display221()
{
    struct node221 *temp = head221;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void middle()
{
    struct node221 *temp = head221;
    int c = 0;
    while (temp != NULL)
    {
        c++;
        temp = temp->next;
    }

    temp = head221;
    int p = 1;
    if (c % 2 == 0)
    {
        int mid = c / 2;
        while (temp != NULL)
        {
            if (p == mid)
                break;
            p++;
            temp = temp->next;
        }
        printf("%d\n", temp->next->data);
    }
    else
    {
        int mid = (c + 1) / 2;
        while (temp != NULL)
        {
            if (p == mid)
                break;
            p++;
            temp = temp->next;
        }
        printf("%d\n", temp->data);
    }
}

int MiddleOfDLL()
{
    create221(2);
    create221(0);
    create221(2);
    create221(9);
    create221(1);
    create221(9);
    create221(6);

    printf("The List is: ");
    display221();
    printf("The Middle node221 is: ");
    middle();

    return 0;
}