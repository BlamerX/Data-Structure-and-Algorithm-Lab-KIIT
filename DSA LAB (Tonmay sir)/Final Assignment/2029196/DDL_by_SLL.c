// WAP to implement a doubly linked list by using singly linked.

struct node211
{
    int data;
    struct node211 *next;
} *head211 = NULL;

void create211(int val)
{
    struct node211 *temp, *rear;

    temp = (struct node211 *)malloc(sizeof(struct node211));
    temp->data = val;
    temp->next = NULL;
    if (head211 == NULL)
    {
        head211 = temp;
    }
    else
    {
        rear->next = temp;
    }
    rear = temp;
}

void display211()
{
    while (head211 != NULL)
    {
        printf("%d ", head211->data);
        head211 = head211->next;
    }
    printf("\n");
}

int DLLbySLL()
{
    create211(2);
    create211(0);
    create211(2);
    create211(9);
    create211(1);
    create211(9);
    create211(6);

    printf("Displaying list:\n");
    display211();

    return 0;
}