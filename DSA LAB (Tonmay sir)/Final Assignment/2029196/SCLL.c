// WAP to create a single circular double linked list of n nodes and display the linked list by using suitable user defined functions for create and display operations.

struct nodeSCLL
{
    int data;
    struct nodeSCLL *next;
    struct nodeSCLL *prev;
} *head25 = NULL;

void insert25(int newData)
{
    struct nodeSCLL *newNode = malloc(sizeof(struct nodeSCLL));
    struct nodeSCLL *last = head25;

    newNode->data = newData;
    newNode->next = NULL;

    if (head25 == NULL)
    {
        newNode->prev = NULL;
        head25 = newNode;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
    newNode->prev = last;
    return;
}

void printList25()
{
    struct nodeSCLL *ptr = head25;

    printf("The Data in the List is: ");
    if (head25 != NULL)
    {
        do
        {
            printf("%d ", ptr->data);
            ptr = ptr->next;
        } while (ptr != head25);
    }
}

int SCLL()
{
    insert25(2);
    insert25(0);
    insert25(2);
    insert25(9);
    insert25(1);
    insert25(9);
    insert25(6);

    printList25();

    return 0;
}